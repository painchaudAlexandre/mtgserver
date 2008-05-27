/*
Copyright (C) 2007 <SWGEmu>
 
This File is part of Core3.
 
This program is free software; you can redistribute 
it and/or modify it under the terms of the GNU Lesser 
General Public License as published by the Free Software
Foundation; either version 2 of the License, 
or (at your option) any later version.
 
This program is distributed in the hope that it will be useful, 
but WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
See the GNU Lesser General Public License for
more details.
 
You should have received a copy of the GNU Lesser General 
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 
Linking Engine3 statically or dynamically with other modules 
is making a combined work based on Engine3. 
Thus, the terms and conditions of the GNU Lesser General Public License 
cover the whole combination.
 
In addition, as a special exception, the copyright holders of Engine3 
give you permission to combine Engine3 program with free software 
programs or libraries that are released under the GNU LGPL and with 
code included in the standard release of Core3 under the GNU LGPL 
license (or modified versions of such code, with unchanged license). 
You may copy and distribute such a system following the terms of the 
GNU LGPL for Engine3 and the licenses of the other code concerned, 
provided that you include the source code of that other code when 
and as the GNU LGPL requires distribution of source code.
 
Note that people who make modified versions of Engine3 are not obligated 
to grant this special exception for their modified versions; 
it is their choice whether to do so. The GNU Lesser General Public License 
gives permission to release a modified version without this exception; 
this exception also makes it possible to release a modified version 
which carries forward this exception.
*/

#include "SuiManager.h"

#include "../../objects.h"
#include "../../objects/player/sui/colorpicker/SuiColorPicker.h"

#include "../../ZoneProcessServerImplementation.h"

SuiManager::SuiManager(ZoneProcessServerImplementation* serv) : Logger("SuiManager") {
	server = serv;
	
	setGlobalLogging(true);
	setLogging(false);
}

void SuiManager::handleSuiEventNotification(uint32 boxID, Player* player, uint32 cancel, const string& value, const string& value2) {
	uint16 type = (uint16) boxID;
	
	int range;
	
	switch (type) {
	case 0x5553:
		handleStartMusic(boxID, player, cancel, value.c_str(), false);
		break;
	case 0x414E:
		handleStartDancing(boxID, player, cancel, value.c_str(), false);
		break;
	case 0x5A53: // changemusic
		handleStartMusic(boxID, player, cancel, value.c_str(), true);
		break;
	case 0x4B4E: // changedance
		handleStartDancing(boxID, player, cancel, value.c_str(), true);
		break;
	case 0x7259:
		range = (atoi(value.c_str()) * 64) + 64;
		handleSurveyToolRange(boxID, player, cancel, range);
		break;
	case 0xAAAA:	// slice weapon
		handleSliceWeapon(boxID, player, cancel, atoi(value.c_str()));
		break;
	case 0xAABA:	// slice armor
		handleSliceArmor(boxID, player, cancel, atoi(value.c_str()));
		break;
	case 0xAACA:	// repair weapon
		handleRepairWeapon(boxID, player, cancel, atoi(value.c_str()));
		break;
	case 0xAADA:	// repair armor
		handleRepairArmor(boxID, player, cancel, atoi(value.c_str()));
		break;
	case 0xDAAD:
		handleTicketPurchaseMessageBox(boxID, player);
		break;
	case 0xAFAF:
		handleTicketCollectorRespones(boxID, player, cancel, atoi(value.c_str()));
		break;
	case 0xBABE:
		handleColorPicker(boxID, player, cancel, value);
		break;
	case 0xD65E:
		handleBankTransfer(boxID, player, atoi(value.c_str()), atoi(value2.c_str()));
		break;
	default:
		//error("Unknown SuiBoxNotification opcode");
		break;
	}
}

void SuiManager::handleStartMusic(uint32 boxID, Player* player, uint32 cancel, const string& song, bool change) {
	try {
		player->wlock();
		
		if (!player->hasSuiBox(boxID)) {
			player->unlock();
			return;
		}
		
		SuiBox* sui = player->getSuiBox(boxID);
		
		if (cancel != 1)
			player->startPlayingMusic(song, change);
		
		player->removeSuiBox(boxID);
		
		sui->finalize();
		
		player->unlock();
	} catch (Exception& e) {
		stringstream msg;
		msg << "Exception in SuiManager::handleStartMusic " << e.getMessage();
		error(msg.str());
		
		player->unlock();
	} catch (...) {
		error("Unreported exception caught in SuiManager::handleStartMusic(Player* player, const string& music)");
		player->unlock();
	}
}

void SuiManager::handleStartDancing(uint32 boxID, Player* player, uint32 cancel, const string& dance, bool change) {
	try {
		player->wlock();
		
		if (!player->hasSuiBox(boxID)) {
			player->unlock();
			return;
		}
		
		SuiBox* sui = player->getSuiBox(boxID);
		
		if (cancel != 1)
			player->startDancing(dance, change);
		
		player->removeSuiBox(boxID);
		
		sui->finalize();
		
		player->unlock();
	} catch (Exception& e) {
		stringstream msg;
		msg << "Exception in SuiManager::handleStartDancing " << e.getMessage();
		error(msg.str());
		
		player->unlock();
	} catch (...) {
		error("Unreported exception caught in SuiManager::handleStartDancing(Player* player, const string& music)");
		player->unlock();
	}
}

void SuiManager::handleSurveyToolRange(uint32 boxID, Player* player, uint32 cancel, int range) {
	try {
		player->wlock();
		
		if (!player->hasSuiBox(boxID)) {
			player->unlock();
			return;
		}
		
		SuiBox* sui = player->getSuiBox(boxID);

		if (cancel != 1) {
			SurveyTool* surveyTool =  player->getSurveyTool();

			if (surveyTool != NULL)
				surveyTool->setSurveyToolRange(range);
			else
				player->sendSystemMessage("Error, invalid tool.");
		}
		
		player->removeSuiBox(boxID);
		
		sui->finalize();
		
		player->unlock();
	} catch (Exception& e) {
		stringstream msg;
		msg << "Exception in SuiManager::handleSurveyToolRange " << e.getMessage();
		error(msg.str());
		
		player->unlock();
	} catch (...) {
		error("Unreported exception caught in SuiManager::handleSurveyToolRange(uint32 boxID, Player* player, int range)");
		player->unlock();
	}
}

void SuiManager::handleSliceWeapon(uint32 boxID, Player* player, uint32 cancel, int itemindex) {
	try {
		player->wlock();

		if (!player->hasSuiBox(boxID)) {
			player->unlock();
			return;
		}
		
		SuiBox* sui = player->getSuiBox(boxID);
		
		if (cancel != 1) {
			Inventory* inventory = player->getInventory(); 

			int weaponCount = 0;

			for (int i = 0; i < inventory->objectsSize(); i++) {
				TangibleObject* item = (TangibleObject*) inventory->getObject(i);

				if (item->isWeapon()) {
					Weapon* weapon = (Weapon*) item;

					if (!weapon->isSliced()) {
						if (weaponCount == itemindex)
							weapon->sliceWeapon(player);

						weaponCount++;
					}
				}
			}
		}

		player->removeSuiBox(boxID);
		
		sui->finalize();

		player->unlock();
	} catch (Exception& e) {
		stringstream msg;
		msg << "Exception in SuiManager::handleSliceWeapon " << e.getMessage();
		error(msg.str());
		
		player->unlock();
	} catch (...) {
		error("Unreported exception caught in SuiManager::handleSliceWeapon(uint32 boxID, Player* player, int itemindex)");
		player->unlock();
	}
}

void SuiManager::handleSliceArmor(uint32 boxID, Player* player, uint32 cancel, int itemindex) {
	try {
		player->wlock();

		if (!player->hasSuiBox(boxID)) {
			player->unlock();
			return;
		}
		
		SuiBox* sui = player->getSuiBox(boxID);
		
		if (cancel != 1) {
			Inventory* inventory = player->getInventory(); 

			int armorCount = 0;

			for (int i = 0; i < inventory->objectsSize(); i++) {
				TangibleObject* item = (TangibleObject*) inventory->getObject(i);

				if (item->isArmor()) {
					Armor* armor = (Armor*) item;

					if (!armor->isSliced()) {
						if (armorCount == itemindex)
							armor->sliceArmor(player);

						armorCount++;
					}
				}
			}
		}

		player->removeSuiBox(boxID);
		
		sui->finalize();

		player->unlock();
	} catch (Exception& e) {
		stringstream msg;
		msg << "Exception in SuiManager::handleSliceArmor " << e.getMessage();
		error(msg.str());
		
		player->unlock();
	} catch (...) {
		error("Unreported exception caught in SuiManager::handleSliceArmor(uint32 boxID, Player* player, int itemindex)");
		player->unlock();
	}
}

void SuiManager::handleRepairWeapon(uint32 boxID, Player* player, uint32 cancel, int itemindex) {
	try {
		player->wlock();

		if (!player->hasSuiBox(boxID)) {
			player->unlock();
			return;
		}
		
		SuiBox* sui = player->getSuiBox(boxID);
		
		if (cancel != 1) {
			Inventory* inventory = player->getInventory(); 

			int weaponCount = 0;

			for (int i = 0; i < inventory->objectsSize(); i++) {
				TangibleObject* item = (TangibleObject*) inventory->getObject(i);

				if (item->isWeapon()) {
					Weapon* weapon = (Weapon*) item;

					if (weaponCount == itemindex)
						weapon->repairWeapon(player);

					weaponCount++;
				}
			}
		}

		player->removeSuiBox(boxID);
		
		sui->finalize();

		player->unlock();
	} catch (Exception& e) {
		stringstream msg;
		msg << "Exception in SuiManager::handleRepairWeapon " << e.getMessage();
		error(msg.str());
		
		player->unlock();
	} catch (...) {
		error("Unreported exception caught in SuiManager::handleRepairWeapon(uint32 boxID, Player* player, int itemindex)");
		player->unlock();
	}
}

void SuiManager::handleRepairArmor(uint32 boxID, Player* player, uint32 cancel, int itemindex) {
	try {
		player->wlock();

		if (!player->hasSuiBox(boxID)) {
			player->unlock();
			return;
		}
		
		SuiBox* sui = player->getSuiBox(boxID);
		
		if (cancel != 1) {
			Inventory* inventory = player->getInventory(); 

			int armorCount = 0;

			for (int i = 0; i < inventory->objectsSize(); i++) {
				TangibleObject* item = (TangibleObject*) inventory->getObject(i);

				if (item->isArmor()) {
					Armor* armor = (Armor*) item;

					if (armorCount == itemindex)
						armor->repairArmor(player);

					armorCount++;
				}
			}
		}

		player->removeSuiBox(boxID);
		
		sui->finalize();

		player->unlock();
	} catch (Exception& e) {
		stringstream msg;
		msg << "Exception in SuiManager::handleRepairArmor " << e.getMessage();
		error(msg.str());
		
		player->unlock();
	} catch (...) {
		error("Unreported exception caught in SuiManager::handleRepairArmor(uint32 boxID, Player* player, int itemindex)");
		player->unlock();
	}
}

void SuiManager::handleTicketPurchaseMessageBox(uint32 boxID, Player* player) {
	try {
		player->wlock();

		if (!player->hasSuiBox(boxID)) {
			player->unlock();
			return;
		}

		SuiBox* sui = player->getSuiBox(boxID);

		player->removeSuiBox(boxID);
		
		sui->finalize();

		player->unlock();
	} catch (Exception& e) {
		stringstream msg;
		msg << "Exception in SuiManager::handleTicketPurchaseMessageBox " << e.getMessage();
		error(msg.str());
		
		player->unlock();
	} catch (...) {
		error("Unreported exception caught in SuiManager::handleTicketPurchaseMessageBox");
		player->unlock();
	}
}

void SuiManager::handleTicketCollectorRespones(uint32 boxID, Player* player, uint32 cancel, int ticketIndex) {
	try {
		player->wlock();

		if (!player->hasSuiBox(boxID)) {
			player->unlock();
			return;
		}

		SuiBox* sui = player->getSuiBox(boxID);
		
		if (sui->isListBox() && cancel != 1) {
			SuiListBox* listBox = (SuiListBox*)sui;
			
			uint64 ticketObjectID = listBox->getMenuObjectID(ticketIndex);
			
			if (ticketObjectID != 0) {
				TangibleObject* object = (TangibleObject*) player->getInventoryItem(ticketObjectID);
				
				if (object != NULL && object->isTicket()) {
					Ticket* ticket = (Ticket*) object;
				
					ticket->useObject(player);
				}
			}
		} 

		player->removeSuiBox(boxID);
		
		sui->finalize();

		player->unlock();
	} catch (Exception& e) {
		error("Exception in SuiManager::handleTicketCollectorRespones ");
		e.printStackTrace();
		
		player->unlock();
	} catch (...) {
		error("Unreported exception caught in SuiManager::handleTicketCollectorRespones");
		player->unlock();
	}
}

void SuiManager::handleColorPicker(uint32 boxID, Player* player, uint32 cancel, const string& value) {
	try {
		player->wlock();

		if (!player->hasSuiBox(boxID)) {
			player->unlock();
			return;
		}

		SuiBox* sui = player->getSuiBox(boxID);
		
		if (sui->isColorPicker()) {
			SuiColorPicker* colorPicker = (SuiColorPicker*) sui;
			
			int val = atoi(value.c_str());
			
			if (val >= 0 && val < 144) {
				uint64 oID = colorPicker->getObjectID();
				
				SceneObject* obj = player->getInventoryItem(oID);
				
				if (obj != NULL && obj->isTangible()) {
					TangibleObject* tano = (TangibleObject*) obj;

					tano->setCustomizationVariable(2, val);
					tano->setUpdated(true);

					TangibleObjectDeltaMessage3* delta = new TangibleObjectDeltaMessage3(tano);
					delta->updateCustomizationString();
					delta->close();

					player->broadcastMessage(delta);

				}
			}
		}

		player->removeSuiBox(boxID);
		
		sui->finalize();

		player->unlock();
	} catch (Exception& e) {
		stringstream msg;
		msg << "Exception in SuiManager::handleColorPicker" << e.getMessage();
		error(msg.str());

		player->unlock();
	} catch (...) {
		error("Unreported exception caught in SuiManager::handleColorPicker");
		player->unlock();
	}
}

void SuiManager::handleBankTransfer(uint32 boxID, Player* player, int cash, int bank) {
	try {
		player->wlock();

		if (!player->hasSuiBox(boxID)) {
			player->unlock();
			return;
		}
		
		SuiBox* sui = player->getSuiBox(boxID);
		
		player->removeSuiBox(boxID);
		
		sui->finalize();
		
		uint32 currentCash = player->getCashCredits();
		uint32 currentBank = player->getBankCredits();
		
		if ((currentCash + currentBank) == ((uint32)cash + (uint32)bank)) {
			player->updateCashCredits(cash);
			player->updateBankCredits(bank);
		}
		
		player->unlock();
	} catch (Exception& e) {
		stringstream msg;
		msg << "Exception in SuiManager::handleBankTransfer" << e.getMessage();
		error(msg.str());

		player->unlock();
	} catch (...) {
		error("Unreported exception caught in SuiManager::handleBankTransfer");
		player->unlock();
	}
}
