/*
 *	server/zone/objects/creature/Creature.cpp generated by engine3 IDL compiler 0.55
 */

#include "Creature.h"

#include "CreatureImplementation.h"

#include "../../managers/creature/CreatureManagerImplementation.h"

#include "../../Zone.h"

#include "../player/Player.h"

#include "../tangible/wearables/Armor.h"

#include "../tangible/lair/LairObject.h"

#include "CreatureObject.h"

#include "CreatureGroup.h"

/*
 *	CreatureStub
 */

Creature::Creature(unsigned long long oid, CreatureGroup* group) : CreatureObject(DummyConstructorParameter::instance()) {
	_impl = new CreatureImplementation(oid, group);
	_impl->_setStub(this);
}

Creature::Creature(DummyConstructorParameter* param) : CreatureObject(param) {
}

Creature::~Creature() {
}

void Creature::init() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->init();
}

void Creature::unload() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->unload();
}

void Creature::insertToZone(Zone* zone) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(zone);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->insertToZone(zone);
}

void Creature::updateZone() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->updateZone();
}

void Creature::removeFromZone(bool doLock) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addBooleanParameter(doLock);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->removeFromZone(doLock);
}

void Creature::loadItems() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->loadItems();
}

bool Creature::activate() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);

		return method.executeWithBooleanReturn();
	} else
		return ((CreatureImplementation*) _impl)->activate();
}

bool Creature::isActive() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);

		return method.executeWithBooleanReturn();
	} else
		return ((CreatureImplementation*) _impl)->isActive();
}

void Creature::removeFromQueue() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->removeFromQueue();
}

bool Creature::doMovement() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 15);

		return method.executeWithBooleanReturn();
	} else
		return ((CreatureImplementation*) _impl)->doMovement();
}

void Creature::doIncapacitate() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 16);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->doIncapacitate();
}

void Creature::doStandUp() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 17);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->doStandUp();
}

void Creature::doAttack(CreatureObject* target, int damage) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 18);
		method.addObjectParameter(target);
		method.addSignedIntParameter(damage);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->doAttack(target, damage);
}

bool Creature::attack(CreatureObject* target) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 19);
		method.addObjectParameter(target);

		return method.executeWithBooleanReturn();
	} else
		return ((CreatureImplementation*) _impl)->attack(target);
}

void Creature::activateRecovery() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 20);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->activateRecovery();
}

bool Creature::doRecovery() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 21);

		return method.executeWithBooleanReturn();
	} else
		return ((CreatureImplementation*) _impl)->doRecovery();
}

void Creature::doStatesRecovery() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 22);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->doStatesRecovery();
}

void Creature::queueRespawn() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 23);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->queueRespawn();
}

void Creature::addPatrolPoint(float x, float y, bool doLock) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 24);
		method.addFloatParameter(x);
		method.addFloatParameter(y);
		method.addBooleanParameter(doLock);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->addPatrolPoint(x, y, doLock);
}

void Creature::resetPatrolPoints(bool doLock) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 25);
		method.addBooleanParameter(doLock);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->resetPatrolPoints(doLock);
}

void Creature::setSpawnPosition(float posX, float posZ, float posY, unsigned long long cellid) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 26);
		method.addFloatParameter(posX);
		method.addFloatParameter(posZ);
		method.addFloatParameter(posY);
		method.addUnsignedLongParameter(cellid);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->setSpawnPosition(posX, posZ, posY, cellid);
}

int Creature::compareTo(Creature* creature) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 27);
		method.addObjectParameter(creature);

		return method.executeWithSignedIntReturn();
	} else
		return ((CreatureImplementation*) _impl)->compareTo(creature);
}

int Creature::getType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 28);

		return method.executeWithSignedIntReturn();
	} else
		return ((CreatureImplementation*) _impl)->getType();
}

bool Creature::isTrainer() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 29);

		return method.executeWithBooleanReturn();
	} else
		return ((CreatureImplementation*) _impl)->isTrainer();
}

bool Creature::isRecruiter() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 30);

		return method.executeWithBooleanReturn();
	} else
		return ((CreatureImplementation*) _impl)->isRecruiter();
}

bool Creature::isMount() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 31);

		return method.executeWithBooleanReturn();
	} else
		return ((CreatureImplementation*) _impl)->isMount();
}

string& Creature::getName() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 32);

		method.executeWithAsciiReturn(_return_getName);
		return _return_getName;
	} else
		return ((CreatureImplementation*) _impl)->getName();
}

int Creature::getZoneIndex() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 33);

		return method.executeWithSignedIntReturn();
	} else
		return ((CreatureImplementation*) _impl)->getZoneIndex();
}

Zone* Creature::getZone() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 34);

		return (Zone*) method.executeWithObjectReturn();
	} else
		return ((CreatureImplementation*) _impl)->getZone();
}

unsigned long long Creature::getNewItemID() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 35);

		return method.executeWithUnsignedLongReturn();
	} else
		return ((CreatureImplementation*) _impl)->getNewItemID();
}

unsigned int Creature::getRespawnTimer() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 36);

		return method.executeWithUnsignedIntReturn();
	} else
		return ((CreatureImplementation*) _impl)->getRespawnTimer();
}

LairObject* Creature::getLair() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 37);

		return (LairObject*) method.executeWithObjectReturn();
	} else
		return ((CreatureImplementation*) _impl)->getLair();
}

bool Creature::hasLootCreated() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 38);

		return method.executeWithBooleanReturn();
	} else
		return ((CreatureImplementation*) _impl)->hasLootCreated();
}

void Creature::setCreatureManager(CreatureManagerImplementation* manager) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((CreatureImplementation*) _impl)->setCreatureManager(manager);
}

void Creature::setLair(LairObject* Lair) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 39);
		method.addObjectParameter(Lair);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->setLair(Lair);
}

void Creature::setCreatureGroup(CreatureGroup* group) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 40);
		method.addObjectParameter(group);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->setCreatureGroup(group);
}

void Creature::setObjectFileName(const string& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 41);
		method.addAsciiParameter(name);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->setObjectFileName(name);
}

void Creature::setType(int tp) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 42);
		method.addSignedIntParameter(tp);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->setType(tp);
}

void Creature::setRespawnTimer(unsigned int seconds) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 43);
		method.addUnsignedIntParameter(seconds);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->setRespawnTimer(seconds);
}

void Creature::setLootCreated(bool value) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 44);
		method.addBooleanParameter(value);

		method.executeWithVoidReturn();
	} else
		((CreatureImplementation*) _impl)->setLootCreated(value);
}

/*
 *	CreatureAdapter
 */

CreatureAdapter::CreatureAdapter(CreatureImplementation* obj) : CreatureObjectAdapter(obj) {
}

Packet* CreatureAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		init();
		break;
	case 7:
		unload();
		break;
	case 8:
		insertToZone((Zone*) inv->getObjectParameter());
		break;
	case 9:
		updateZone();
		break;
	case 10:
		removeFromZone(inv->getBooleanParameter());
		break;
	case 11:
		loadItems();
		break;
	case 12:
		resp->insertBoolean(activate());
		break;
	case 13:
		resp->insertBoolean(isActive());
		break;
	case 14:
		removeFromQueue();
		break;
	case 15:
		resp->insertBoolean(doMovement());
		break;
	case 16:
		doIncapacitate();
		break;
	case 17:
		doStandUp();
		break;
	case 18:
		doAttack((CreatureObject*) inv->getObjectParameter(), inv->getSignedIntParameter());
		break;
	case 19:
		resp->insertBoolean(attack((CreatureObject*) inv->getObjectParameter()));
		break;
	case 20:
		activateRecovery();
		break;
	case 21:
		resp->insertBoolean(doRecovery());
		break;
	case 22:
		doStatesRecovery();
		break;
	case 23:
		queueRespawn();
		break;
	case 24:
		addPatrolPoint(inv->getFloatParameter(), inv->getFloatParameter(), inv->getBooleanParameter());
		break;
	case 25:
		resetPatrolPoints(inv->getBooleanParameter());
		break;
	case 26:
		setSpawnPosition(inv->getFloatParameter(), inv->getFloatParameter(), inv->getFloatParameter(), inv->getUnsignedLongParameter());
		break;
	case 27:
		resp->insertSignedInt(compareTo((Creature*) inv->getObjectParameter()));
		break;
	case 28:
		resp->insertSignedInt(getType());
		break;
	case 29:
		resp->insertBoolean(isTrainer());
		break;
	case 30:
		resp->insertBoolean(isRecruiter());
		break;
	case 31:
		resp->insertBoolean(isMount());
		break;
	case 32:
		resp->insertAscii(getName());
		break;
	case 33:
		resp->insertSignedInt(getZoneIndex());
		break;
	case 34:
		resp->insertLong(getZone()->_getObjectID());
		break;
	case 35:
		resp->insertLong(getNewItemID());
		break;
	case 36:
		resp->insertInt(getRespawnTimer());
		break;
	case 37:
		resp->insertLong(getLair()->_getObjectID());
		break;
	case 38:
		resp->insertBoolean(hasLootCreated());
		break;
	case 39:
		setLair((LairObject*) inv->getObjectParameter());
		break;
	case 40:
		setCreatureGroup((CreatureGroup*) inv->getObjectParameter());
		break;
	case 41:
		setObjectFileName(inv->getAsciiParameter(_param0_setObjectFileName__string_));
		break;
	case 42:
		setType(inv->getSignedIntParameter());
		break;
	case 43:
		setRespawnTimer(inv->getUnsignedIntParameter());
		break;
	case 44:
		setLootCreated(inv->getBooleanParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void CreatureAdapter::init() {
	return ((CreatureImplementation*) impl)->init();
}

void CreatureAdapter::unload() {
	return ((CreatureImplementation*) impl)->unload();
}

void CreatureAdapter::insertToZone(Zone* zone) {
	return ((CreatureImplementation*) impl)->insertToZone(zone);
}

void CreatureAdapter::updateZone() {
	return ((CreatureImplementation*) impl)->updateZone();
}

void CreatureAdapter::removeFromZone(bool doLock) {
	return ((CreatureImplementation*) impl)->removeFromZone(doLock);
}

void CreatureAdapter::loadItems() {
	return ((CreatureImplementation*) impl)->loadItems();
}

bool CreatureAdapter::activate() {
	return ((CreatureImplementation*) impl)->activate();
}

bool CreatureAdapter::isActive() {
	return ((CreatureImplementation*) impl)->isActive();
}

void CreatureAdapter::removeFromQueue() {
	return ((CreatureImplementation*) impl)->removeFromQueue();
}

bool CreatureAdapter::doMovement() {
	return ((CreatureImplementation*) impl)->doMovement();
}

void CreatureAdapter::doIncapacitate() {
	return ((CreatureImplementation*) impl)->doIncapacitate();
}

void CreatureAdapter::doStandUp() {
	return ((CreatureImplementation*) impl)->doStandUp();
}

void CreatureAdapter::doAttack(CreatureObject* target, int damage) {
	return ((CreatureImplementation*) impl)->doAttack(target, damage);
}

bool CreatureAdapter::attack(CreatureObject* target) {
	return ((CreatureImplementation*) impl)->attack(target);
}

void CreatureAdapter::activateRecovery() {
	return ((CreatureImplementation*) impl)->activateRecovery();
}

bool CreatureAdapter::doRecovery() {
	return ((CreatureImplementation*) impl)->doRecovery();
}

void CreatureAdapter::doStatesRecovery() {
	return ((CreatureImplementation*) impl)->doStatesRecovery();
}

void CreatureAdapter::queueRespawn() {
	return ((CreatureImplementation*) impl)->queueRespawn();
}

void CreatureAdapter::addPatrolPoint(float x, float y, bool doLock) {
	return ((CreatureImplementation*) impl)->addPatrolPoint(x, y, doLock);
}

void CreatureAdapter::resetPatrolPoints(bool doLock) {
	return ((CreatureImplementation*) impl)->resetPatrolPoints(doLock);
}

void CreatureAdapter::setSpawnPosition(float posX, float posZ, float posY, unsigned long long cellid) {
	return ((CreatureImplementation*) impl)->setSpawnPosition(posX, posZ, posY, cellid);
}

int CreatureAdapter::compareTo(Creature* creature) {
	return ((CreatureImplementation*) impl)->compareTo(creature);
}

int CreatureAdapter::getType() {
	return ((CreatureImplementation*) impl)->getType();
}

bool CreatureAdapter::isTrainer() {
	return ((CreatureImplementation*) impl)->isTrainer();
}

bool CreatureAdapter::isRecruiter() {
	return ((CreatureImplementation*) impl)->isRecruiter();
}

bool CreatureAdapter::isMount() {
	return ((CreatureImplementation*) impl)->isMount();
}

string& CreatureAdapter::getName() {
	return ((CreatureImplementation*) impl)->getName();
}

int CreatureAdapter::getZoneIndex() {
	return ((CreatureImplementation*) impl)->getZoneIndex();
}

Zone* CreatureAdapter::getZone() {
	return ((CreatureImplementation*) impl)->getZone();
}

unsigned long long CreatureAdapter::getNewItemID() {
	return ((CreatureImplementation*) impl)->getNewItemID();
}

unsigned int CreatureAdapter::getRespawnTimer() {
	return ((CreatureImplementation*) impl)->getRespawnTimer();
}

LairObject* CreatureAdapter::getLair() {
	return ((CreatureImplementation*) impl)->getLair();
}

bool CreatureAdapter::hasLootCreated() {
	return ((CreatureImplementation*) impl)->hasLootCreated();
}

void CreatureAdapter::setLair(LairObject* Lair) {
	return ((CreatureImplementation*) impl)->setLair(Lair);
}

void CreatureAdapter::setCreatureGroup(CreatureGroup* group) {
	return ((CreatureImplementation*) impl)->setCreatureGroup(group);
}

void CreatureAdapter::setObjectFileName(const string& name) {
	return ((CreatureImplementation*) impl)->setObjectFileName(name);
}

void CreatureAdapter::setType(int tp) {
	return ((CreatureImplementation*) impl)->setType(tp);
}

void CreatureAdapter::setRespawnTimer(unsigned int seconds) {
	return ((CreatureImplementation*) impl)->setRespawnTimer(seconds);
}

void CreatureAdapter::setLootCreated(bool value) {
	return ((CreatureImplementation*) impl)->setLootCreated(value);
}

/*
 *	CreatureHelper
 */

CreatureHelper* CreatureHelper::staticInitializer = CreatureHelper::instance();

CreatureHelper::CreatureHelper() {
	className = "Creature";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void CreatureHelper::finalizeHelper() {
	CreatureHelper::finalize();
}

DistributedObject* CreatureHelper::instantiateObject() {
	return new Creature(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* CreatureHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CreatureAdapter((CreatureImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	CreatureServant
 */

CreatureServant::CreatureServant(unsigned long long oid) : CreatureObjectImplementation(oid) {
	_classHelper = CreatureHelper::instance();
}

CreatureServant::~CreatureServant() {
}

void CreatureServant::_setStub(DistributedObjectStub* stub) {
	_this = (Creature*) stub;
	CreatureObjectServant::_setStub(stub);
}

DistributedObjectStub* CreatureServant::_getStub() {
	return _this;
}

