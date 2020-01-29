  #ifndef MERGERESOURCESINHOUSE_H_
#define MERGERESOURCESINHOUSE_H_

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/managers/resource/ResourceManager.h"
#include "engine/core/ManagedReference.h"

class MergeResourcesInHouseCommand : public QueueCommand {
public:

	MergeResourcesInHouseCommand(const String& name, ZoneProcessServer* server)
		: QueueCommand(name, server) {

	}

	/**
	 * this function will look into player inventory and merge resource with same name together
	 */
	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {

		if (!checkStateMask(creature))
			return INVALIDSTATE;

		if (!checkInvalidLocomotions(creature))
			return INVALIDLOCOMOTION;

		if ( creature->getParent() == NULL) {
			creature->sendSystemMessage("You cannot run this command from outside");
			return GENERALERROR;
		}

		ManagedReference<SceneObject* > house = creature->getParent();

		if( house->isCellObject() )
			house = house->getParent();

		if ( !house ) {
			creature->sendSystemMessage("Unsupported type of building: " + house->getLoggingName() );
			return GENERALERROR;
		}

		if( !house->isBuildingObject() ){
			creature->sendSystemMessage("You need to run this command from inside a building" + house->getLoggingName());
			return GENERALERROR;
		}

		ManagedReference<BuildingObject* > buildingObject = house->asBuildingObject();

		if( !buildingObject->isOnAdminList(creature) ){
			creature->sendSystemMessage("You need to be administrator of this building to run this command");
			return GENERALERROR;
		}


		int countIgnoredContainers = 0;
		int countIgnoredFullResContainers = 0;
		VectorMap<String, ManagedReference<ResourceContainer*> > resourceMap;
		ArrayList<ManagedReference<ResourceContainer*>> resourceMapLowCount;

		//
		// priority goes to resources in containers, we need to look for resources with highest counts there
		//
		for (uint32 i = 1; i <= buildingObject->getTotalCellNumber(); ++i) {
			ManagedReference<CellObject*> cell = buildingObject->getCell(i);
			int objectsInCell = cell->getContainerObjectsSize();

			// We need to parse each cells for its objects
			for (int j = 0; j < objectsInCell; ++j) {
				ManagedReference<SceneObject*> childObject = cell->getContainerObject(j);

				if( childObject->isContainerObject() )
				{
					UnicodeString containerName = childObject->getCustomObjectName();

					// Ignore that container if it has NOMERGE keyword in it
					if( containerName.indexOf("NOMERGE") >= 0 ){
						countIgnoredContainers++;
						continue;
					}

					for (int k = 0; k < childObject->getContainerObjectsSize(); ++k) {
						ManagedReference<SceneObject*> itemSceno = childObject->getContainerObject(k);
						if( itemSceno->isResourceContainer() ) {
							ManagedReference<ResourceContainer* > res = itemSceno.castTo<ResourceContainer*>();

							if( res->getQuantity() == ResourceContainer::MAXSIZE ){
								countIgnoredFullResContainers++;
								continue;
							}

							// get resource name for later usage
							String resourceName = res->getSpawnName();

							int positionInList = resourceMap.find(resourceName);

							// if resource was already known seen we need to it's high count
							if( positionInList > -1 ){
								ManagedReference<ResourceContainer*> highResCount = resourceMap.get(positionInList);

								if( highResCount->getQuantity() < res->getQuantity() ) {
									resourceMapLowCount.add(highResCount);
									resourceMap.drop(resourceName);
									resourceMap.put(resourceName, res);
								}
								else {
									resourceMapLowCount.add(res);
								}
							}
							// it was never seen so we just add it
							else {
								resourceMap.put(resourceName, res);
							}
						}
					}
				}
			}
		}


		//
		// we do the same for resources outside of containers (on the floor)
		//
		for (uint32 i = 1; i <= buildingObject->getTotalCellNumber(); ++i) {
			ManagedReference<CellObject*> cell = buildingObject->getCell(i);
			int objectsInCell = cell->getContainerObjectsSize();

			// We need to parse each cells for its objects
			for (int j = 0; j < objectsInCell; ++j) {
				ManagedReference<SceneObject*> childObject = cell->getContainerObject(j);

				if( childObject->isResourceContainer() ) {
					ManagedReference<ResourceContainer* > res = childObject.castTo<ResourceContainer*>();

					if( res->getQuantity() == ResourceContainer::MAXSIZE ){
						countIgnoredFullResContainers++;
						continue;
					}

					// get resource name for later usage
					String resourceName = res->getSpawnName();

					int positionInList = resourceMap.find(resourceName);

					if( positionInList > -1 )
						resourceMapLowCount.add(res);
					else
						resourceMap.put(resourceName, res);
				}

			}
		}



		creature->sendSystemMessage("Found " + String::valueOf(resourceMap.size()+resourceMapLowCount.size()+countIgnoredFullResContainers) +
			" resources container(s) in the building with potentially " + String::valueOf(resourceMapLowCount.size()) +
			" mergeable ones and " + countIgnoredContainers + " chest(s) were ignored");

		if( resourceMapLowCount.size() > 0 ){
			creature->sendSystemMessage("Proceeding with the merge of " + String::valueOf(resourceMapLowCount.size()) + " resource container(s)");

			for(int i=0; i<resourceMapLowCount.size(); i++ ){
				ManagedReference<ResourceContainer*> &lowCountRes = resourceMapLowCount.get(i);
				String resSpawnName = lowCountRes->getSpawnName();
				ManagedReference<ResourceContainer*> &highCountRes = resourceMap.get(resSpawnName);

				if( !highCountRes ){
					resourceMap.put(resSpawnName, lowCountRes);
					continue;
				}

				highCountRes->combine(lowCountRes);

				// if that container is full , we get the next one in resourceMap
				if( highCountRes->getQuantity() == ResourceContainer::MAXSIZE  ){
					resourceMap.drop(resSpawnName);
					if( !lowCountRes->isDestroyed() && lowCountRes->getQuantity() > 0 )
						resourceMap.put(resSpawnName, lowCountRes);
				}
			}
		}
		else
			creature->sendSystemMessage("No potential merges found!");

		return SUCCESS;
	}

};

#endif //MERGERESOURCESINHOUSE_H_
