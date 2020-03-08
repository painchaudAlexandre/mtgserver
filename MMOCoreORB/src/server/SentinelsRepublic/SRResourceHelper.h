//
// Created by Chris on 08-Mar-20.
//

#ifndef CORE3_SRRESOURCEHELPER_H
#define CORE3_SRRESOURCEHELPER_H

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/managers/resource/ResourceManager.h"
#include "engine/core/ManagedReference.h"
#include "server/zone/objects/creature/commands/QueueCommand.h"
#include "server/zone/objects/building/BuildingObject.h"


using namespace server::zone::objects::building;
using namespace server::zone::objects::creature;

namespace server {
    namespace SRResourceHelper {

        bool count_resources_in_container(SceneObject *container, int &count_res, int &count_res_containers);

/**
 * This is not Reference safe! Ensure you ref player creature first
 * @param creature player's creature object you need to inspect inventory.
 * @param count_res to count resource quantities
 * @param count_res_container to count resource containers
 * @return false if an issue happened
 */
        bool count_resources_in_player_inventory(CreatureObject *creature, int &count_res, int &count_res_container);

        bool count_resources_in_house(BuildingObject *building, int &count_resources, int &count_resource_containers);

        bool get_resources_containers_from_player_inventory();

    } // end of namespace

}


#endif //CORE3_SRRESOURCEHELPER_H
