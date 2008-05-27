/*
 *	server/zone/objects/tangible/weapons/ranged/RifleRangedWeapon.h generated by engine3 IDL compiler 0.55
 */

#ifndef RIFLERANGEDWEAPON_H_
#define RIFLERANGEDWEAPON_H_

#include "engine/orb/DistributedObjectBroker.h"

class CreatureObject;

class RangedWeapon;

#include "../RangedWeapon.h"

class RifleRangedWeapon : public RangedWeapon {
public:
	RifleRangedWeapon(unsigned long long oid, unsigned int tempCRC, const unicode& n, const string& tempn, bool eqp = false);

	RifleRangedWeapon(CreatureObject* creature, const string& temp, const unicode& n, const string& tempn, bool eqp = false);

protected:
	RifleRangedWeapon(DummyConstructorParameter* param);

	virtual ~RifleRangedWeapon();

	friend class RifleRangedWeaponHelper;
};

class RifleRangedWeaponImplementation;

class RifleRangedWeaponAdapter : public RangedWeaponAdapter {
public:
	RifleRangedWeaponAdapter(RifleRangedWeaponImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

};

class RifleRangedWeaponHelper : public DistributedObjectClassHelper, public Singleton<RifleRangedWeaponHelper> {
	static RifleRangedWeaponHelper* staticInitializer;

public:
	RifleRangedWeaponHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<RifleRangedWeaponHelper>;
};

#include "../RangedWeaponImplementation.h"

class RifleRangedWeaponServant : public RangedWeaponImplementation {
public:
	RifleRangedWeapon* _this;

public:
	RifleRangedWeaponServant(unsigned long long oid, unsigned int tempCRC, const unicode& n, const string& tempn, int tp, bool eqp);
	RifleRangedWeaponServant(CreatureObject* creature, const string& temp, const unicode& n, const string& tempn, int tp, bool eqp);
	virtual ~RifleRangedWeaponServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*RIFLERANGEDWEAPON_H_*/
