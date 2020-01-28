#ifndef MERGERESOURCES_H_
#define MERGERESOURCES_H_

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/managers/resource/ResourceManager.h"
#include "engine/core/ManagedReference.h"

class MergeResourcesInInventoryCommand : public QueueCommand {
public:

	MergeResourcesInInventoryCommand(const String& name, ZoneProcessServer* server)
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

		creature->sendSystemMessage("Requested inventory resources merge");

		ManagedReference<SceneObject*> inventory = creature->getSlottedObject("inventory");

		if (inventory == NULL) {
			creature->sendSystemMessage("Player inventory not found");
			return GENERALERROR;;
		}

		VectorMap<String, Vector<ManagedReference<ResourceContainer*>> > resourceMap;

		// goes after each item in inventory to see if they are a resource container
		for (int i = 0; i < inventory->getContainerObjectsSize(); ++i) {

			ManagedReference<SceneObject*> sceno = inventory->getContainerObject(i);

			// is it a resource container?
			if( sceno->isResourceContainer() ) {
				ManagedReference<ResourceContainer* > res = sceno.castTo<ResourceContainer*>();

				String resourceName = res->getSpawnName();
				int positionInList = resourceMap.find(resourceName);

				if( positionInList > -1 ){
					Vector<ManagedReference<ResourceContainer*>> &list = resourceMap.get(positionInList);
					list.add(res);
				}
				else {
					Vector<ManagedReference<ResourceContainer*>> vector;
					vector.add(res);
					resourceMap.put(resourceName, vector);
				}
			}
			// or may be it is a container/bag
			else if( sceno->isContainerObject() ){
				// then we do the same : go after each object and see if it's a resource container
				for( int j=0; j< sceno->getContainerObjectsSize(); ++j){
					ManagedReference<SceneObject*> subSceno = sceno->getContainerObject(j);
					if( subSceno->isResourceContainer() ) {
									ManagedReference<ResourceContainer*> res = subSceno.castTo<ResourceContainer*>();

									// look for resource name to see if it exists in resourceMap already
									String resourceName = res->getSpawnName();
									int positionInList = resourceMap.find(resourceName);

									if( positionInList > -1 ){
										// it exists already to we get the Vector and our this Res Container to it
										Vector<ManagedReference<ResourceContainer*>> &list = resourceMap.get(positionInList);
										list.add(res);
									}
									else {
										Vector<ManagedReference<ResourceContainer*>> vector;
										vector.add(res);
										resourceMap.put(resourceName, vector);
									}
								}
				}
			}
		}

		for( int i=0; i<resourceMap.size(); i++)
		{
			VectorMapEntry< String, Vector<ManagedReference<ResourceContainer*>>> entry = resourceMap.elementAt(i);
			Vector<ManagedReference<ResourceContainer*>> &duplicateResources =  entry.getValue();

			creature->sendSystemMessage("Found resource " + entry.getKey() + " with "+ duplicateResources.size() + " containers");

			if( duplicateResources.size() > 1 )
			{
				creature->sendSystemMessage("Now merging them together...");
				ManagedReference<ResourceContainer*> firstResource = NULL;

				for( int j=0; j<duplicateResources.size(); j++){

					if( firstResource == NULL ){
						firstResource = duplicateResources.get(j);
						if( firstResource->getQuantity() == ResourceContainer::MAXSIZE )
							firstResource = NULL;
					}
					else {
						ManagedReference<ResourceContainer*> resToMerge = duplicateResources.get(j);

						if( resToMerge->getQuantity() == ResourceContainer::MAXSIZE )
							continue;

						int postMergeCount = resToMerge->getQuantity() + firstResource->getQuantity();

						firstResource->combine( resToMerge );

						if( firstResource->getQuantity() == ResourceContainer::MAXSIZE ){
							firstResource = NULL;
							if( !resToMerge->isDestroyed() && resToMerge->getQuantity() > 0 )
								firstResource = resToMerge;
						}
					}
				}


				creature->sendSystemMessage("Merging done!");
			}
		}
		return SUCCESS;
	}

};

#endif //MERGERESOURCES_H_
