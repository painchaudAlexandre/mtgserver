/*
 * ConsumableTemplate.h
 *
 *  Created on: 15/08/2010
 *      Author: victor
 */

#ifndef CONSUMABLETEMPLATE_H_
#define CONSUMABLETEMPLATE_H_

#include "../SharedTangibleObjectTemplate.h"

class ConsumableTemplate : public SharedTangibleObjectTemplate {
	int duration;
	int filling;
	int nutrition;

	int effectType;

	int stackable;

	int fillingMin;
	int fillingMax;
	int flavorMin;
	int flavorMax;
	int nutritionMin;
	int nutritionMax;
	int quantityMin;
	int quantityMax;

	VectorMap<String, float> modifiers;
	String buffName;
	uint32 buffCRC;

	String speciesRestriction;

	int consumableType;

public:
	ConsumableTemplate() {

	}

	~ConsumableTemplate() {

	}

	void readObject(LuaObject* templateData) {
		SharedTangibleObjectTemplate::readObject(templateData);

		duration = templateData->getIntField("duration");
		filling = templateData->getIntField("filling");
		nutrition = templateData->getIntField("nutrition");

		effectType = templateData->getIntField("effectType");

		stackable = templateData->getIntField("stackable");

		fillingMin = templateData->getIntField("fillingMin");
		fillingMax = templateData->getIntField("fillingMax");

		flavorMin = templateData->getIntField("flavorMin");
		flavorMax = templateData->getIntField("flavorMax");
		nutritionMin = templateData->getIntField("nutritionMin");
		nutritionMax = templateData->getIntField("nutritionMax");
		quantityMin = templateData->getIntField("quantityMin");;
		quantityMax = templateData->getIntField("quantityMax");

		LuaObject mods = templateData->getObjectField("modifiers");

		for (int i = 1; i <= mods.getTableSize(); i += 2) {
			String attribute = mods.getStringAt(i);
			float value = mods.getFloatAt(i + 1);

			modifiers.put(attribute, value);
		}

		mods.pop();

		buffName = templateData->getStringField("buffName");
		buffCRC = templateData->getIntField("buffCRC");

		speciesRestriction = templateData->getStringField("speciesRestriction");
		//consumableType = templateData->getIntField("consumableType");
    }

    inline uint32 getBuffCRC() const {
		return buffCRC;
	}

    inline String& getBuffName() {
		return buffName;
	}

    inline int getConsumableType() const {
		return consumableType;
	}

    inline int getDuration() const {
		return duration;
	}

    inline int getEffectType() const {
		return effectType;
	}

    inline int getStackable() const {
    	return stackable;
    }

    inline int getFilling() const {
		return filling;
	}

    inline int getFillingMax() const {
		return fillingMax;
	}

    inline int getFillingMin() const {
		return fillingMin;
	}

    inline int getFlavorMax() const {
		return flavorMax;
	}

    inline int getFlavorMin() const {
		return flavorMin;
	}

	VectorMap<String, float>* getModifiers() {
		return &modifiers;
	}

	inline int getNutrition() const {
		return nutrition;
	}

	inline int getNutritionMax() const {
		return nutritionMax;
	}

	inline int getNutritionMin() const {
		return nutritionMin;
	}

	inline int getQuantityMax() const {
		return quantityMax;
	}

	inline int getQuantityMin() const {
		return quantityMin;
	}

	inline String& getSpeciesRestriction() {
		return speciesRestriction;
	}

};


#endif /* CONSUMABLETEMPLATE_H_ */
