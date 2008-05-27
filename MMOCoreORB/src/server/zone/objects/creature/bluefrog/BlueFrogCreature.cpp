/*
 *	server/zone/objects/creature/bluefrog/BlueFrogCreature.cpp generated by engine3 IDL compiler 0.55
 */

#include "BlueFrogCreature.h"

#include "BlueFrogCreatureImplementation.h"

#include "../Creature.h"

#include "../../player/Player.h"

#include "../../scene/SceneObject.h"

/*
 *	BlueFrogCreatureStub
 */

BlueFrogCreature::BlueFrogCreature(unsigned long long oid) : Creature(DummyConstructorParameter::instance()) {
	_impl = new BlueFrogCreatureImplementation(oid);
	_impl->_setStub(this);
}

BlueFrogCreature::BlueFrogCreature(DummyConstructorParameter* param) : Creature(param) {
}

BlueFrogCreature::~BlueFrogCreature() {
}

/*
 *	BlueFrogCreatureAdapter
 */

BlueFrogCreatureAdapter::BlueFrogCreatureAdapter(BlueFrogCreatureImplementation* obj) : CreatureAdapter(obj) {
}

Packet* BlueFrogCreatureAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	default:
		return NULL;
	}

	return resp;
}

/*
 *	BlueFrogCreatureHelper
 */

BlueFrogCreatureHelper* BlueFrogCreatureHelper::staticInitializer = BlueFrogCreatureHelper::instance();

BlueFrogCreatureHelper::BlueFrogCreatureHelper() {
	className = "BlueFrogCreature";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void BlueFrogCreatureHelper::finalizeHelper() {
	BlueFrogCreatureHelper::finalize();
}

DistributedObject* BlueFrogCreatureHelper::instantiateObject() {
	return new BlueFrogCreature(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* BlueFrogCreatureHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new BlueFrogCreatureAdapter((BlueFrogCreatureImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	BlueFrogCreatureServant
 */

BlueFrogCreatureServant::BlueFrogCreatureServant(unsigned long long oid) : CreatureImplementation(oid) {
	_classHelper = BlueFrogCreatureHelper::instance();
}

BlueFrogCreatureServant::~BlueFrogCreatureServant() {
}

void BlueFrogCreatureServant::_setStub(DistributedObjectStub* stub) {
	_this = (BlueFrogCreature*) stub;
	CreatureServant::_setStub(stub);
}

DistributedObjectStub* BlueFrogCreatureServant::_getStub() {
	return _this;
}

