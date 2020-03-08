//
// Created by Chris on 08-Mar-20.
//

#include "SRResourceHelper.h"


namespace server{ namespace SRResourceHelper {

    bool count_resources_in_container(SceneObject *container, int &count_res, int &count_res_containers) {
        if (!container->isContainerObject())
            return false;

        count_res = 0;
        count_res_containers = 0;

        for (int j = 0; j < container->getContainerObjectsSize(); ++j) {
            ManagedReference<SceneObject *> subSceno = container->getContainerObject(j);
            if (subSceno->isResourceContainer()) {
                ResourceContainer *res = subSceno.castTo<ResourceContainer *>();
                count_res += res->getQuantity();
                count_res_containers++;
            }
        }

        return true;
    }


    bool count_resources_in_player_inventory(CreatureObject *creature, int &count_res,
                                                                       int &count_res_container) {

        count_res = 0;
        count_res_container = 0;

        ManagedReference<SceneObject *> inventory = creature->getSlottedObject("inventory");
        if (!inventory) {
            creature->sendSystemMessage("Player inventory not found");
            return false;
        }
        for (int i = 0; i < inventory->getContainerObjectsSize(); ++i) {
            ManagedReference<SceneObject *> scen_o = inventory->getContainerObject(i);
            if (scen_o->isResourceContainer()) {
                ResourceContainer *res = scen_o.castTo<ResourceContainer *>();
                count_res += res->getQuantity();
                count_res_container++;
            }
                // or may be it is a container/bag
            else if (scen_o->isContainerObject()) {
                int local_count_res, local_count_res_container;
                if (!count_resources_in_container(scen_o, local_count_res, local_count_res_container)) {
                    return false;
                }
                count_res += local_count_res;
                count_res_container += local_count_res_container;
            }
        }
        return true;
    }

    bool count_resources_in_house(BuildingObject *building, int &count_resources,
                                                    int &count_resource_containers) {
        count_resources = 0;
        count_resource_containers = 0;

        for (uint32 i = 1; i <= building->getTotalCellNumber(); ++i) {
            ManagedReference<CellObject *> cell = building->getCell(i);
            int objectsInCell = cell->getContainerObjectsSize();
            // We need to parse each cells for its objects
            for (int j = 0; j < objectsInCell; ++j) {
                ManagedReference<SceneObject *> cell_child_object = cell->getContainerObject(j);
                if (cell_child_object->isCreatureObject()) // ignore if it is a player
                    continue;
                else if (cell_child_object->isContainerObject()) {
                    int local_count_resources, local_count_resource_containers;
                    if (!count_resources_in_container(cell_child_object, local_count_resources,
                                                      local_count_resource_containers))
                        return false;
                    count_resources += local_count_resources;
                    count_resource_containers += local_count_resource_containers;
                } else if (cell_child_object->isResourceContainer()) {
                    ResourceContainer *res = cell_child_object.castTo<ResourceContainer *>();
                    count_resources += res->getQuantity();
                    count_resource_containers++;
                }
            }
        }
        return true;
    }

    bool get_resources_containers_from_player_inventory() {
        return true;
    }

}}