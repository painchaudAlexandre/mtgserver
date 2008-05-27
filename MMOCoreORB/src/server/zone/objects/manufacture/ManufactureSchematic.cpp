/*
 *	server/zone/objects/manufacture/ManufactureSchematic.cpp generated by engine3 IDL compiler 0.55
 */

#include "ManufactureSchematic.h"

#include "ManufactureSchematicImplementation.h"

#include "../scene/SceneObject.h"

/*
 *	ManufactureSchematicStub
 */

ManufactureSchematic::ManufactureSchematic(unsigned long long oid) : SceneObject(DummyConstructorParameter::instance()) {
	_impl = new ManufactureSchematicImplementation(oid);
	_impl->_setStub(this);
}

ManufactureSchematic::ManufactureSchematic(DummyConstructorParameter* param) : SceneObject(param) {
}

ManufactureSchematic::~ManufactureSchematic() {
}

/*
 *	ManufactureSchematicAdapter
 */

ManufactureSchematicAdapter::ManufactureSchematicAdapter(ManufactureSchematicImplementation* obj) : SceneObjectAdapter(obj) {
}

Packet* ManufactureSchematicAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	default:
		return NULL;
	}

	return resp;
}

/*
 *	ManufactureSchematicHelper
 */

ManufactureSchematicHelper* ManufactureSchematicHelper::staticInitializer = ManufactureSchematicHelper::instance();

ManufactureSchematicHelper::ManufactureSchematicHelper() {
	className = "ManufactureSchematic";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ManufactureSchematicHelper::finalizeHelper() {
	ManufactureSchematicHelper::finalize();
}

DistributedObject* ManufactureSchematicHelper::instantiateObject() {
	return new ManufactureSchematic(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ManufactureSchematicHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ManufactureSchematicAdapter((ManufactureSchematicImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	ManufactureSchematicServant
 */

ManufactureSchematicServant::ManufactureSchematicServant(unsigned long long oid) : SceneObjectImplementation(oid) {
	_classHelper = ManufactureSchematicHelper::instance();
}

ManufactureSchematicServant::~ManufactureSchematicServant() {
}

void ManufactureSchematicServant::_setStub(DistributedObjectStub* stub) {
	_this = (ManufactureSchematic*) stub;
	SceneObjectServant::_setStub(stub);
}

DistributedObjectStub* ManufactureSchematicServant::_getStub() {
	return _this;
}

