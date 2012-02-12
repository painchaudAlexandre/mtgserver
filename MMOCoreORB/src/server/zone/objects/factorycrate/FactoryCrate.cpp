/*
 *	server/zone/objects/factorycrate/FactoryCrate.cpp generated by engine3 IDL compiler 0.60
 */

#include "FactoryCrate.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

#include "server/zone/packets/scene/AttributeListMessage.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/scene/variables/ContainerPermissions.h"

/*
 *	FactoryCrateStub
 */

enum {RPC_INITIALIZETRANSIENTMEMBERS__,RPC_SENDBASELINESTO__SCENEOBJECT_,RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_,RPC_ISFACTORYCRATE__,RPC_SETUSECOUNT__INT_BOOL_,RPC_GETPROTOTYPE__,RPC_GETCRAFTERSNAME__,RPC_GETCRAFTERSSERIAL__,RPC_EXTRACTOBJECTTOPARENT__,RPC_EXTRACTOBJECT__INT_,RPC_SPLIT__INT_};

FactoryCrate::FactoryCrate() : TangibleObject(DummyConstructorParameter::instance()) {
	FactoryCrateImplementation* _implementation = new FactoryCrateImplementation();
	_impl = _implementation;
	_impl->_setStub(this);
}

FactoryCrate::FactoryCrate(DummyConstructorParameter* param) : TangibleObject(param) {
}

FactoryCrate::~FactoryCrate() {
}



void FactoryCrate::loadTemplateData(SharedObjectTemplate* templateData) {
	FactoryCrateImplementation* _implementation = static_cast<FactoryCrateImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->loadTemplateData(templateData);
}

void FactoryCrate::initializeTransientMembers() {
	FactoryCrateImplementation* _implementation = static_cast<FactoryCrateImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZETRANSIENTMEMBERS__);

		method.executeWithVoidReturn();
	} else
		_implementation->initializeTransientMembers();
}

void FactoryCrate::sendBaselinesTo(SceneObject* player) {
	FactoryCrateImplementation* _implementation = static_cast<FactoryCrateImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDBASELINESTO__SCENEOBJECT_);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		_implementation->sendBaselinesTo(player);
}

void FactoryCrate::fillAttributeList(AttributeListMessage* msg, CreatureObject* object) {
	FactoryCrateImplementation* _implementation = static_cast<FactoryCrateImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillAttributeList(msg, object);
}

void FactoryCrate::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player) {
	FactoryCrateImplementation* _implementation = static_cast<FactoryCrateImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->fillObjectMenuResponse(menuResponse, player);
}

int FactoryCrate::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	FactoryCrateImplementation* _implementation = static_cast<FactoryCrateImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->handleObjectMenuSelect(player, selectedID);
}

bool FactoryCrate::isFactoryCrate() {
	FactoryCrateImplementation* _implementation = static_cast<FactoryCrateImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ISFACTORYCRATE__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->isFactoryCrate();
}

void FactoryCrate::setUseCount(unsigned int newUseCount, bool notifyClient) {
	FactoryCrateImplementation* _implementation = static_cast<FactoryCrateImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETUSECOUNT__INT_BOOL_);
		method.addUnsignedIntParameter(newUseCount);
		method.addBooleanParameter(notifyClient);

		method.executeWithVoidReturn();
	} else
		_implementation->setUseCount(newUseCount, notifyClient);
}

TangibleObject* FactoryCrate::getPrototype() {
	FactoryCrateImplementation* _implementation = static_cast<FactoryCrateImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETPROTOTYPE__);

		return static_cast<TangibleObject*>(method.executeWithObjectReturn());
	} else
		return _implementation->getPrototype();
}

String FactoryCrate::getCraftersName() {
	FactoryCrateImplementation* _implementation = static_cast<FactoryCrateImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETCRAFTERSNAME__);

		method.executeWithAsciiReturn(_return_getCraftersName);
		return _return_getCraftersName;
	} else
		return _implementation->getCraftersName();
}

String FactoryCrate::getCraftersSerial() {
	FactoryCrateImplementation* _implementation = static_cast<FactoryCrateImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETCRAFTERSSERIAL__);

		method.executeWithAsciiReturn(_return_getCraftersSerial);
		return _return_getCraftersSerial;
	} else
		return _implementation->getCraftersSerial();
}

bool FactoryCrate::extractObjectToParent() {
	FactoryCrateImplementation* _implementation = static_cast<FactoryCrateImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_EXTRACTOBJECTTOPARENT__);

		return method.executeWithBooleanReturn();
	} else
		return _implementation->extractObjectToParent();
}

TangibleObject* FactoryCrate::extractObject(int count) {
	FactoryCrateImplementation* _implementation = static_cast<FactoryCrateImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_EXTRACTOBJECT__INT_);
		method.addSignedIntParameter(count);

		return static_cast<TangibleObject*>(method.executeWithObjectReturn());
	} else
		return _implementation->extractObject(count);
}

void FactoryCrate::split(int newStackSize) {
	FactoryCrateImplementation* _implementation = static_cast<FactoryCrateImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SPLIT__INT_);
		method.addSignedIntParameter(newStackSize);

		method.executeWithVoidReturn();
	} else
		_implementation->split(newStackSize);
}

DistributedObjectServant* FactoryCrate::_getImplementation() {

	_updated = true;
	return _impl;
}

void FactoryCrate::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	FactoryCrateImplementation
 */

FactoryCrateImplementation::FactoryCrateImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}


FactoryCrateImplementation::~FactoryCrateImplementation() {
}


void FactoryCrateImplementation::finalize() {
}

void FactoryCrateImplementation::_initializeImplementation() {
	_setClassHelper(FactoryCrateHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void FactoryCrateImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<FactoryCrate*>(stub);
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* FactoryCrateImplementation::_getStub() {
	return _this;
}

FactoryCrateImplementation::operator const FactoryCrate*() {
	return _this;
}

void FactoryCrateImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void FactoryCrateImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void FactoryCrateImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void FactoryCrateImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void FactoryCrateImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void FactoryCrateImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void FactoryCrateImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void FactoryCrateImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("FactoryCrate");

}

void FactoryCrateImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(FactoryCrateImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool FactoryCrateImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (TangibleObjectImplementation::readObjectMember(stream, _name))
		return true;


	return false;
}

void FactoryCrateImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = FactoryCrateImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int FactoryCrateImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;

	return 0 + TangibleObjectImplementation::writeObjectMembers(stream);
}

FactoryCrateImplementation::FactoryCrateImplementation() {
	_initializeImplementation();
	// server/zone/objects/factorycrate/FactoryCrate.idl():  		Logger.setLoggingName("FactoryCrate");
	Logger::setLoggingName("FactoryCrate");
	// server/zone/objects/factorycrate/FactoryCrate.idl():  		super.setContainerInheritPermissionsFromParent(false);
	TangibleObjectImplementation::setContainerInheritPermissionsFromParent(false);
	// server/zone/objects/factorycrate/FactoryCrate.idl():  		super.setContainerDefaultDenyPermission(ContainerPermissions.OPEN);
	TangibleObjectImplementation::setContainerDefaultDenyPermission(ContainerPermissions::OPEN);
	// server/zone/objects/factorycrate/FactoryCrate.idl():  		super.setContainerDefaultDenyPermission(ContainerPermissions.MOVEIN);
	TangibleObjectImplementation::setContainerDefaultDenyPermission(ContainerPermissions::MOVEIN);
	// server/zone/objects/factorycrate/FactoryCrate.idl():  		super.setContainerDefaultDenyPermission(ContainerPermissions.MOVEOUT);
	TangibleObjectImplementation::setContainerDefaultDenyPermission(ContainerPermissions::MOVEOUT);
}

bool FactoryCrateImplementation::isFactoryCrate() {
	// server/zone/objects/factorycrate/FactoryCrate.idl():  		return true;
	return true;
}

/*
 *	FactoryCrateAdapter
 */

FactoryCrateAdapter::FactoryCrateAdapter(FactoryCrate* obj) : TangibleObjectAdapter(obj) {
}

Packet* FactoryCrateAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_INITIALIZETRANSIENTMEMBERS__:
		initializeTransientMembers();
		break;
	case RPC_SENDBASELINESTO__SCENEOBJECT_:
		sendBaselinesTo(static_cast<SceneObject*>(inv->getObjectParameter()));
		break;
	case RPC_HANDLEOBJECTMENUSELECT__CREATUREOBJECT_BYTE_:
		resp->insertSignedInt(handleObjectMenuSelect(static_cast<CreatureObject*>(inv->getObjectParameter()), inv->getByteParameter()));
		break;
	case RPC_ISFACTORYCRATE__:
		resp->insertBoolean(isFactoryCrate());
		break;
	case RPC_SETUSECOUNT__INT_BOOL_:
		setUseCount(inv->getUnsignedIntParameter(), inv->getBooleanParameter());
		break;
	case RPC_GETPROTOTYPE__:
		resp->insertLong(getPrototype()->_getObjectID());
		break;
	case RPC_GETCRAFTERSNAME__:
		resp->insertAscii(getCraftersName());
		break;
	case RPC_GETCRAFTERSSERIAL__:
		resp->insertAscii(getCraftersSerial());
		break;
	case RPC_EXTRACTOBJECTTOPARENT__:
		resp->insertBoolean(extractObjectToParent());
		break;
	case RPC_EXTRACTOBJECT__INT_:
		resp->insertLong(extractObject(inv->getSignedIntParameter())->_getObjectID());
		break;
	case RPC_SPLIT__INT_:
		split(inv->getSignedIntParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void FactoryCrateAdapter::initializeTransientMembers() {
	(static_cast<FactoryCrate*>(stub))->initializeTransientMembers();
}

void FactoryCrateAdapter::sendBaselinesTo(SceneObject* player) {
	(static_cast<FactoryCrate*>(stub))->sendBaselinesTo(player);
}

int FactoryCrateAdapter::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	return (static_cast<FactoryCrate*>(stub))->handleObjectMenuSelect(player, selectedID);
}

bool FactoryCrateAdapter::isFactoryCrate() {
	return (static_cast<FactoryCrate*>(stub))->isFactoryCrate();
}

void FactoryCrateAdapter::setUseCount(unsigned int newUseCount, bool notifyClient) {
	(static_cast<FactoryCrate*>(stub))->setUseCount(newUseCount, notifyClient);
}

TangibleObject* FactoryCrateAdapter::getPrototype() {
	return (static_cast<FactoryCrate*>(stub))->getPrototype();
}

String FactoryCrateAdapter::getCraftersName() {
	return (static_cast<FactoryCrate*>(stub))->getCraftersName();
}

String FactoryCrateAdapter::getCraftersSerial() {
	return (static_cast<FactoryCrate*>(stub))->getCraftersSerial();
}

bool FactoryCrateAdapter::extractObjectToParent() {
	return (static_cast<FactoryCrate*>(stub))->extractObjectToParent();
}

TangibleObject* FactoryCrateAdapter::extractObject(int count) {
	return (static_cast<FactoryCrate*>(stub))->extractObject(count);
}

void FactoryCrateAdapter::split(int newStackSize) {
	(static_cast<FactoryCrate*>(stub))->split(newStackSize);
}

/*
 *	FactoryCrateHelper
 */

FactoryCrateHelper* FactoryCrateHelper::staticInitializer = FactoryCrateHelper::instance();

FactoryCrateHelper::FactoryCrateHelper() {
	className = "FactoryCrate";

	Core::getObjectBroker()->registerClass(className, this);
}

void FactoryCrateHelper::finalizeHelper() {
	FactoryCrateHelper::finalize();
}

DistributedObject* FactoryCrateHelper::instantiateObject() {
	return new FactoryCrate(DummyConstructorParameter::instance());
}

DistributedObjectServant* FactoryCrateHelper::instantiateServant() {
	return new FactoryCrateImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* FactoryCrateHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new FactoryCrateAdapter(static_cast<FactoryCrate*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

