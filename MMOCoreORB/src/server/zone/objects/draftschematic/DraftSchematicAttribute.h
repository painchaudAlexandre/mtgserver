/*
 *	server/zone/objects/draftschematic/DraftSchematicAttribute.h generated by engine3 IDL compiler 0.55
 */

#ifndef DRAFTSCHEMATICATTRIBUTE_H_
#define DRAFTSCHEMATICATTRIBUTE_H_

#include "engine/orb/DistributedObjectBroker.h"

class DraftSchematicAttribute : public DistributedObjectStub {
public:
	DraftSchematicAttribute(const string& attribute, float minVal, float maxVal, const string& attributeExpProp);

	void setAttributeName(const string& attribute);

	void setMinValue(float minVal);

	void setMaxValue(float maxVal);

	void setAttributeExperimentalProperty(const string& attributeExpProp);

	string& getAttributeName();

	float getMinValue();

	float getMaxValue();

	float getRange();

	string& getAttributeExperimentalProperty();

protected:
	DraftSchematicAttribute(DummyConstructorParameter* param);

	virtual ~DraftSchematicAttribute();

	string _return_getAttributeExperimentalProperty;
	string _return_getAttributeName;

	friend class DraftSchematicAttributeHelper;
};

class DraftSchematicAttributeImplementation;

class DraftSchematicAttributeAdapter : public DistributedObjectAdapter {
public:
	DraftSchematicAttributeAdapter(DraftSchematicAttributeImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void setAttributeName(const string& attribute);

	void setMinValue(float minVal);

	void setMaxValue(float maxVal);

	void setAttributeExperimentalProperty(const string& attributeExpProp);

	string& getAttributeName();

	float getMinValue();

	float getMaxValue();

	float getRange();

	string& getAttributeExperimentalProperty();

protected:
	string _param0_setAttributeName__string_;
	string _param0_setAttributeExperimentalProperty__string_;
};

class DraftSchematicAttributeHelper : public DistributedObjectClassHelper, public Singleton<DraftSchematicAttributeHelper> {
	static DraftSchematicAttributeHelper* staticInitializer;

public:
	DraftSchematicAttributeHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<DraftSchematicAttributeHelper>;
};

class DraftSchematicAttributeServant : public DistributedObjectServant {
public:
	DraftSchematicAttribute* _this;

public:
	DraftSchematicAttributeServant();
	virtual ~DraftSchematicAttributeServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*DRAFTSCHEMATICATTRIBUTE_H_*/
