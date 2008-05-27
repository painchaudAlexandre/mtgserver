--Copyright (C) 2007 <SWGEmu>
 
--This File is part of Core3.
 
--This program is free software; you can redistribute 
--it and/or modify it under the terms of the GNU Lesser 
--General Public License as published by the Free Software
--Foundation; either version 2 of the License, 
--or (at your option) any later version.
 
--This program is distributed in the hope that it will be useful, 
--but WITHOUT ANY WARRANTY; without even the implied warranty of 
--MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
--See the GNU Lesser General Public License for
--more details.
 
--You should have received a copy of the GNU Lesser General 
--Public License along with this program; if not, write to
--the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 
--Linking Engine3 statically or dynamically with other modules 
--is making a combined work based on Engine3. 
--Thus, the terms and conditions of the GNU Lesser General Public License 
--cover the whole combination.
 
--In addition, as a special exception, the copyright holders of Engine3 
--give you permission to combine Engine3 program with free software 
--programs or libraries that are released under the GNU LGPL and with 
--code included in the standard release of Core3 under the GNU LGPL 
--license (or modified versions of such code, with unchanged license). 
--You may copy and distribute such a system following the terms of the 
--GNU LGPL for Engine3 and the licenses of the other code concerned, 
--provided that you include the source code of that other code when 
--and as the GNU LGPL requires distribution of source code.
 
--Note that people who make modified versions of Engine3 are not obligated 
--to grant this special exception for their modified versions; 
--it is their choice whether to do so. The GNU Lesser General Public License 
--gives permission to release a modified version without this exception; 
--this exception also makes it possible to release a modified version 
--which carries forward this exception.

mst = {

	objectName = "Mineral Survey Tool",

	templateName = "survey_tool_mineral",

	objectCRC = 2862265132,

	objectType = SURVEYTOOL
}

sst = {
	
	objectName = "Solar Survey Tool",

	templateName = "survey_tool_solar",

	objectCRC = 2341848205,

	objectType = SURVEYTOOL
}


cst = {

	objectName = "Chemical Survey Tool",

	templateName = "survey_tool_chemical",

	objectCRC = 2242363434,

	objectType = SURVEYTOOL
}


fst = {	

	objectName = "Flora Survey Tool",

	templateName = "survey_tool_flora",

	objectCRC = 1329114448,

	objectType = SURVEYTOOL
}


gst = {	

	objectName = "Gas Survey Tool",

	templateName = "survey_tool_gas",

	objectCRC = 1059021891,

	objectType = SURVEYTOOL
}


watst = {
	
	objectName = "Water Survey Tool",

	templateName = "survey_tool_water",

	objectCRC = 2175673400,

	objectType = SURVEYTOOL
}


wndst = {

	objectName = "Wind Survey Tool",

	templateName = "survey_tool_wind",

	objectCRC = 566467536,

	objectType = SURVEYTOOL
}

crafting_tool = {
	
	objectName = "Generic Crafting Tool",

	templateName = "generic_tool",

	objectCRC = "1055200365",

	objectType = CRAFTINGTOOL,

	equipped = "0"
}


surveying_kit = {mst, sst, cst, fst, gst, watst, wndst, crafting_tool}

addBFItemSet("Crafting & Surveying Kit" , surveying_kit);