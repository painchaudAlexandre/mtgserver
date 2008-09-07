/*
 *	server/zone/managers/item/ItemManager.h generated by engine3 IDL compiler 0.55
 */

#ifndef ITEMMANAGER_H_
#define ITEMMANAGER_H_

#include "engine/orb/DistributedObjectBroker.h"

class ZoneServer;

class TangibleObject;

class Weapon;

class Armor;

class DeedObject;

class BlueFrogVector;

class Player;

class ItemManager : public DistributedObjectStub {
public:
	ItemManager(ZoneServer* server);

	void loadStaticWorldObjects();

	TangibleObject* getPlayerItem(Player* player, long long objectid);

	void loadPlayerItems(Player* player);

	void loadDefaultPlayerItems(Player* player);

	void loadDefaultPlayerDatapadItems(Player* player);

	void unloadPlayerItems(Player* player);

	void createPlayerItem(Player* player, TangibleObject* item);

	TangibleObject* initializeTangibleForCrafting(int objecttype, unsigned long long objectid, unsigned long long objectcrc, string& objectn, string& objecttemp, bool equipped);

	void savePlayerItem(Player* player, TangibleObject* item);

	void deletePlayerItem(Player* player, TangibleObject* item, bool notify);

	void showDbStats(Player* player);

	void showDbDeleted(Player* player);

	void purgeDbDeleted(Player* player);

	unsigned long long getNextStaticObjectID();

	BlueFrogVector* getBFItemList();

	BlueFrogVector* getBFProfList(string& group);

	string& getBFProf(string& key);

	void giveBFItemSet(Player* player, string& set);

protected:
	ItemManager(DummyConstructorParameter* param);

	virtual ~ItemManager();

	string _return_getBFProf;

	friend class ItemManagerHelper;
};

class ItemManagerImplementation;

class ItemManagerAdapter : public DistributedObjectAdapter {
public:
	ItemManagerAdapter(ItemManagerImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void loadStaticWorldObjects();

	TangibleObject* getPlayerItem(Player* player, long long objectid);

	void loadPlayerItems(Player* player);

	void loadDefaultPlayerItems(Player* player);

	void loadDefaultPlayerDatapadItems(Player* player);

	void unloadPlayerItems(Player* player);

	void createPlayerItem(Player* player, TangibleObject* item);

	TangibleObject* initializeTangibleForCrafting(int objecttype, unsigned long long objectid, unsigned long long objectcrc, string& objectn, string& objecttemp, bool equipped);

	void savePlayerItem(Player* player, TangibleObject* item);

	void deletePlayerItem(Player* player, TangibleObject* item, bool notify);

	void showDbStats(Player* player);

	void showDbDeleted(Player* player);

	void purgeDbDeleted(Player* player);

	unsigned long long getNextStaticObjectID();

	BlueFrogVector* getBFItemList();

	BlueFrogVector* getBFProfList(string& group);

	string& getBFProf(string& key);

	void giveBFItemSet(Player* player, string& set);

protected:
	string _param3_initializeTangibleForCrafting__int_long_long_string_string_bool_;
	string _param4_initializeTangibleForCrafting__int_long_long_string_string_bool_;
	string _param0_getBFProfList__string_;
	string _param0_getBFProf__string_;
	string _param1_giveBFItemSet__Player_string_;
};

class ItemManagerHelper : public DistributedObjectClassHelper, public Singleton<ItemManagerHelper> {
	static ItemManagerHelper* staticInitializer;

public:
	ItemManagerHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<ItemManagerHelper>;
};

class ItemManagerServant : public DistributedObjectServant {
public:
	ItemManager* _this;

public:
	ItemManagerServant();
	virtual ~ItemManagerServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*ITEMMANAGER_H_*/
