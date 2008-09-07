/*
 *	server/zone/objects/player/sui/transferbox/SuiTransferBox.h generated by engine3 IDL compiler 0.55
 */

#ifndef SUITRANSFERBOX_H_
#define SUITRANSFERBOX_H_

#include "engine/orb/DistributedObjectBroker.h"

class SuiBox;

class Player;

#include "engine/service/proto/BaseMessage.h"

#include "../SuiBox.h"

class SuiTransferBox : public SuiBox {
public:
	SuiTransferBox(Player* player, unsigned int boxtype);

	BaseMessage* generateMessage();

	BaseMessage* getMessage();

	void addOption(const string& itemText, const string& lblType, const string& itemType);

	void addFrom(const string& from, const string& startingFrom, const string& inputFrom, const string& rFrom);

	void addTo(const string& to, const string& startingTo, const string& inputTo, const string& rTo);

protected:
	SuiTransferBox(DummyConstructorParameter* param);

	virtual ~SuiTransferBox();

	friend class SuiTransferBoxHelper;
};

class SuiTransferBoxImplementation;

class SuiTransferBoxAdapter : public SuiBoxAdapter {
public:
	SuiTransferBoxAdapter(SuiTransferBoxImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	BaseMessage* generateMessage();

	BaseMessage* getMessage();

	void addOption(const string& itemText, const string& lblType, const string& itemType);

	void addFrom(const string& from, const string& startingFrom, const string& inputFrom, const string& rFrom);

	void addTo(const string& to, const string& startingTo, const string& inputTo, const string& rTo);

protected:
	string _param0_addOption__string_string_string_;
	string _param1_addOption__string_string_string_;
	string _param2_addOption__string_string_string_;
	string _param0_addFrom__string_string_string_string_;
	string _param1_addFrom__string_string_string_string_;
	string _param2_addFrom__string_string_string_string_;
	string _param3_addFrom__string_string_string_string_;
	string _param0_addTo__string_string_string_string_;
	string _param1_addTo__string_string_string_string_;
	string _param2_addTo__string_string_string_string_;
	string _param3_addTo__string_string_string_string_;
};

class SuiTransferBoxHelper : public DistributedObjectClassHelper, public Singleton<SuiTransferBoxHelper> {
	static SuiTransferBoxHelper* staticInitializer;

public:
	SuiTransferBoxHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<SuiTransferBoxHelper>;
};

#include "../SuiBoxImplementation.h"

class SuiTransferBoxServant : public SuiBoxImplementation {
public:
	SuiTransferBox* _this;

public:
	SuiTransferBoxServant(Player* player, unsigned int boxtype, unsigned int typeId);
	virtual ~SuiTransferBoxServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*SUITRANSFERBOX_H_*/
