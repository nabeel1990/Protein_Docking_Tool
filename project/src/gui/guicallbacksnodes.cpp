/*
 * guicallbacksnodes.cpp
 *
 *  Created on: Jun 10, 2010
 *      Author: ivan
 */

#include "vmolgui.h"
#include "../command/vmolcommand.h"

using namespace std;



void VmolGui::callbackNodesNodeTree(Fl_Widget *w, void *data)
{
	unsigned int i=0, currentNodeType=0, nodeType=0;
	string nodeName;
	VmolSceneNode *nodePointer=NULL;
	Fl_Tree_Item *item=NULL;

	item = (Fl_Tree_Item*) VmolGui::getInstance()->nodesNodeTree_->item_clicked();
	nodeName = item->label();

	if (nodeName == "ROOT")
		return;

	nodePointer = (VmolSceneNode *) VmolCommand::getInstance()->findVariable(COMMAND_VAR_NODE, nodeName);
	if (nodePointer == NULL)
		return;

	nodeType = nodePointer->getNodeType();

	VmolGui::getInstance()->nodesName_->value(nodePointer->getName().c_str());

	for (i=0; i<VmolGui::getInstance()->nodesType_->size(); i++)
	{
		currentNodeType = nodePointer->getNodeTypeFromString((string) VmolGui::getInstance()->nodesType_->text(i));
		if (currentNodeType == nodePointer->getNodeType())
		{
			VmolGui::getInstance()->nodesType_->value(i);
			VmolGui::getInstance()->nodesType_->do_callback();
			break;
		}
	}

	if (nodePointer->getParentName() == "")
	{
		VmolGui::getInstance()->nodesParent_->value(0);			// this is the element that defines the root node "(root)"
	}
	else
	{
		for (i=0; i<VmolGui::getInstance()->nodesParent_->size(); i++)
		{
			if (((string) VmolGui::getInstance()->nodesParent_->text(i)) == nodePointer->getParentName())
			{
				VmolGui::getInstance()->nodesParent_->value(i);
				break;
			}
		}
	}

	if (nodeType == VMOL_COLOR)
	{
		string dataName;
		Color *dataPointer=NULL;

		nodePointer->getColorParameters(&dataPointer);

		for (i=0; i<VmolCommand::getInstance()->getColorList().size(); i++)
		{
			if (&(VmolCommand::getInstance()->getColorList()[i].value) == dataPointer)
			{
				dataName = VmolCommand::getInstance()->getColorList()[i].name;
				break;
			}
		}

		for (i=0; i<VmolGui::getInstance()->nodesParameter1_->size(); i++)
		{
			if (((string) VmolGui::getInstance()->nodesParameter1_->text(i)) == dataName)
			{
				VmolGui::getInstance()->nodesParameter1_->value(i);
				break;
			}
		}
	}
	else if (nodeType == VMOL_TRANSLATION)
	{
		string dataName;
		Vector3 *dataPointer=NULL;

		nodePointer->getTranslationParameters(&dataPointer);

		for (i=0; i<VmolCommand::getInstance()->getVector3List().size(); i++)
		{
			if (&(VmolCommand::getInstance()->getVector3List()[i].value) == dataPointer)
			{
				dataName = VmolCommand::getInstance()->getVector3List()[i].name;
				break;
			}
		}

		for (i=0; i<VmolGui::getInstance()->nodesParameter1_->size(); i++)
		{
			if (((string) VmolGui::getInstance()->nodesParameter1_->text(i)) == dataName)
			{
				VmolGui::getInstance()->nodesParameter1_->value(i);
				break;
			}
		}
	}
	else if (nodeType==VMOL_ROTATION_CARTHESIAN_X || nodeType==VMOL_ROTATION_CARTHESIAN_Y || nodeType==VMOL_ROTATION_CARTHESIAN_Z)
	{
		string dataName;
		double *dataPointer=NULL;

		nodePointer->getRotationAngleParameters(&dataPointer);

		for (i=0; i<VmolCommand::getInstance()->getDoubleList().size(); i++)
		{
			if (&(VmolCommand::getInstance()->getDoubleList()[i].value) == dataPointer)
			{
				dataName = VmolCommand::getInstance()->getDoubleList()[i].name;
				break;
			}
		}

		for (i=0; i<VmolGui::getInstance()->nodesParameter1_->size(); i++)
		{
			if (((string) VmolGui::getInstance()->nodesParameter1_->text(i)) == dataName)
			{
				VmolGui::getInstance()->nodesParameter1_->value(i);
				break;
			}
		}
	}
	else if (nodeType == VMOL_ROTATION_EULER)
	{
		string dataName;
		EulerVector3 *dataPointer=NULL;

		nodePointer->getEulerRotationParameters(&dataPointer);

		for (i=0; i<VmolCommand::getInstance()->getEulerVector3List().size(); i++)
		{
			if (&(VmolCommand::getInstance()->getEulerVector3List()[i].value) == dataPointer)
			{
				dataName = VmolCommand::getInstance()->getEulerVector3List()[i].name;
				break;
			}
		}

		for (i=0; i<VmolGui::getInstance()->nodesParameter1_->size(); i++)
		{
			if (((string) VmolGui::getInstance()->nodesParameter1_->text(i)) == dataName)
			{
				VmolGui::getInstance()->nodesParameter1_->value(i);
				break;
			}
		}
	}
	else if (nodeType == VMOL_SCRIPT)
	{
		string dataName;
		string *dataPointer=NULL;

		nodePointer->getScriptParameters(&dataPointer);

		for (i=0; i<VmolCommand::getInstance()->getStringList().size(); i++)
		{
			if ((VmolCommand::getInstance()->getStringList()[i].value) == dataPointer)
			{
				dataName = VmolCommand::getInstance()->getStringList()[i].name;
				break;
			}
		}

		for (i=0; i<VmolGui::getInstance()->nodesParameter1_->size(); i++)
		{
			if (((string) VmolGui::getInstance()->nodesParameter1_->text(i)) == dataName)
			{
				VmolGui::getInstance()->nodesParameter1_->value(i);
				break;
			}
		}
	}
	else if (nodeType == VMOL_SCALE)
	{
		string dataName;
		Vector3 *dataPointer=NULL;

		nodePointer->getScaleParameters(&dataPointer);

		for (i=0; i<VmolCommand::getInstance()->getVector3List().size(); i++)
		{
			if (&(VmolCommand::getInstance()->getVector3List()[i].value) == dataPointer)
			{
				dataName = VmolCommand::getInstance()->getVector3List()[i].name;
				break;
			}
		}

		for (i=0; i<VmolGui::getInstance()->nodesParameter1_->size(); i++)
		{
			if (((string) VmolGui::getInstance()->nodesParameter1_->text(i)) == dataName)
			{
				VmolGui::getInstance()->nodesParameter1_->value(i);
				break;
			}
		}
	}
	else if (nodeType == VMOL_MESH)
	{
		string dataName1, dataName2;
		Mesh *dataPointer1=NULL;
		unsigned long long int *dataPointer2=NULL;

		nodePointer->getMeshParameters(&dataPointer1, &dataPointer2);

		for (i=0; i<VmolCommand::getInstance()->getMeshList().size(); i++)
		{
			if (VmolCommand::getInstance()->getMeshList()[i] == dataPointer1)
			{
				dataName1 = VmolCommand::getInstance()->getMeshList()[i]->getName();
				break;
			}
		}

		for (i=0; i<VmolCommand::getInstance()->getULongLongIntList().size(); i++)
		{
			if (&(VmolCommand::getInstance()->getULongLongIntList()[i].value) == dataPointer2)
			{
				dataName2 = VmolCommand::getInstance()->getULongLongIntList()[i].name;
				break;
			}
		}



		for (i=0; i<VmolGui::getInstance()->nodesParameter1_->size(); i++)
		{
			if (((string) VmolGui::getInstance()->nodesParameter1_->text(i)) == dataName1)
			{
				VmolGui::getInstance()->nodesParameter1_->value(i);
				break;
			}
		}

		for (i=0; i<VmolGui::getInstance()->nodesParameter2_->size(); i++)
		{
			if (((string) VmolGui::getInstance()->nodesParameter2_->text(i)) == dataName2)
			{
				VmolGui::getInstance()->nodesParameter2_->value(i);
				break;
			}
		}
	}
	else if (nodeType == VMOL_LOOK_AT)
	{
		string dataName1, dataName2, dataName3;
		Vector3 *dataPointer1=NULL, *dataPointer2=NULL, *dataPointer3=NULL;

		nodePointer->getViewParameters(&dataPointer1, &dataPointer2, &dataPointer3);

		for (i=0; i<VmolCommand::getInstance()->getVector3List().size(); i++)
		{
			if (&(VmolCommand::getInstance()->getVector3List()[i].value) == dataPointer1)
			{
				dataName1 = VmolCommand::getInstance()->getVector3List()[i].name;
			}

			if (&(VmolCommand::getInstance()->getVector3List()[i].value) == dataPointer2)
			{
				dataName2 = VmolCommand::getInstance()->getVector3List()[i].name;
			}

			if (&(VmolCommand::getInstance()->getVector3List()[i].value) == dataPointer3)
			{
				dataName3 = VmolCommand::getInstance()->getVector3List()[i].name;
			}
		}



		for (i=0; i<VmolGui::getInstance()->nodesParameter1_->size(); i++)
		{
			if (((string) VmolGui::getInstance()->nodesParameter1_->text(i)) == dataName1)
			{
				VmolGui::getInstance()->nodesParameter1_->value(i);
				break;
			}
		}

		for (i=0; i<VmolGui::getInstance()->nodesParameter2_->size(); i++)
		{
			if (((string) VmolGui::getInstance()->nodesParameter2_->text(i)) == dataName2)
			{
				VmolGui::getInstance()->nodesParameter2_->value(i);
				break;
			}
		}

		for (i=0; i<VmolGui::getInstance()->nodesParameter3_->size(); i++)
		{
			if (((string) VmolGui::getInstance()->nodesParameter3_->text(i)) == dataName3)
			{
				VmolGui::getInstance()->nodesParameter3_->value(i);
				break;
			}
		}
	}
	else if (nodeType == VMOL_PDB)
	{
		string dataName1, dataName2, dataName3, dataName4;
		PdbFile *dataPointer1=NULL;
		Mesh *dataPointer2=NULL, *dataPointer3=NULL;
		unsigned long long int *dataPointer4=NULL;

		nodePointer->getPdbParameters(&dataPointer1, &dataPointer2, &dataPointer3, &dataPointer4);

		for (i=0; i<VmolCommand::getInstance()->getPdbList().size(); i++)
		{
			if (VmolCommand::getInstance()->getPdbList()[i] == dataPointer1)
			{
				dataName1 = VmolCommand::getInstance()->getPdbList()[i]->getName();
				break;
			}
		}

		for (i=0; i<VmolCommand::getInstance()->getMeshList().size(); i++)
		{
			if (VmolCommand::getInstance()->getMeshList()[i] == dataPointer2)
			{
				dataName2 = VmolCommand::getInstance()->getMeshList()[i]->getName();
				break;
			}
		}

		for (i=0; i<VmolCommand::getInstance()->getMeshList().size(); i++)
		{
			if (VmolCommand::getInstance()->getMeshList()[i] == dataPointer3)
			{
				dataName3 = VmolCommand::getInstance()->getMeshList()[i]->getName();
				break;
			}
		}

		for (i=0; i<VmolCommand::getInstance()->getULongLongIntList().size(); i++)
		{
			if (&(VmolCommand::getInstance()->getULongLongIntList()[i].value) == dataPointer4)
			{
				dataName4 = VmolCommand::getInstance()->getULongLongIntList()[i].name;
				break;
			}
		}



		for (i=0; i<VmolGui::getInstance()->nodesParameter1_->size(); i++)
		{
			if (((string) VmolGui::getInstance()->nodesParameter1_->text(i)) == dataName1)
			{
				VmolGui::getInstance()->nodesParameter1_->value(i);
				break;
			}
		}

		for (i=0; i<VmolGui::getInstance()->nodesParameter2_->size(); i++)
		{
			if (((string) VmolGui::getInstance()->nodesParameter2_->text(i)) == dataName2)
			{
				VmolGui::getInstance()->nodesParameter2_->value(i);
				break;
			}
		}

		for (i=0; i<VmolGui::getInstance()->nodesParameter3_->size(); i++)
		{
			if (((string) VmolGui::getInstance()->nodesParameter3_->text(i)) == dataName3)
			{
				VmolGui::getInstance()->nodesParameter3_->value(i);
				break;
			}
		}

		for (i=0; i<VmolGui::getInstance()->nodesParameter4_->size(); i++)
		{
			if (((string) VmolGui::getInstance()->nodesParameter4_->text(i)) == dataName4)
			{
				VmolGui::getInstance()->nodesParameter4_->value(i);
				break;
			}
		}
	}
}

void VmolGui::callbackNodesType(Fl_Widget *w, void *data)
{
	unsigned int i=0, value1=0, value2=0, value3=0, value4=0;
	unsigned int nodeType=0;

	nodeType = VmolSceneNode::getNodeTypeFromString(VmolGui::getInstance()->nodesType_->text(VmolGui::getInstance()->nodesType_->value()));

	VmolGui::getInstance()->nodesParameter1_->clear();
	VmolGui::getInstance()->nodesParameter2_->clear();
	VmolGui::getInstance()->nodesParameter3_->clear();
	VmolGui::getInstance()->nodesParameter4_->clear();



	if (nodeType == VMOL_NOP)
	{
		VmolGui::getInstance()->nodesParameter1_->hide();
		VmolGui::getInstance()->nodesParameter2_->hide();
		VmolGui::getInstance()->nodesParameter3_->hide();
		VmolGui::getInstance()->nodesParameter4_->hide();
	}
	else if (	nodeType==VMOL_COLOR || nodeType==VMOL_TRANSLATION || nodeType==VMOL_ROTATION_CARTHESIAN_X ||
				nodeType==VMOL_ROTATION_CARTHESIAN_Y || nodeType==VMOL_ROTATION_CARTHESIAN_Z ||
				nodeType==VMOL_ROTATION_EULER || nodeType==VMOL_SCRIPT || nodeType==VMOL_SCALE)
	{
		VmolGui::getInstance()->nodesParameter1_->show();
		VmolGui::getInstance()->nodesParameter2_->hide();
		VmolGui::getInstance()->nodesParameter3_->hide();
		VmolGui::getInstance()->nodesParameter4_->hide();

		if (nodeType == VMOL_COLOR)
		{
			VmolGui::getInstance()->nodesParameter1_->label("Color name:");

			for (i=0; i<VmolCommand::getInstance()->getColorList().size(); i++)
			{
				VmolGui::getInstance()->nodesParameter1_->add(VmolCommand::getInstance()->getColorList()[i].name.c_str());
			}
		}
		else if (nodeType == VMOL_TRANSLATION)
		{
			VmolGui::getInstance()->nodesParameter1_->label("Transl. name:");

			for (i=0; i<VmolCommand::getInstance()->getVector3List().size(); i++)
			{
				VmolGui::getInstance()->nodesParameter1_->add(VmolCommand::getInstance()->getVector3List()[i].name.c_str());
			}
		}
		else if (nodeType==VMOL_ROTATION_CARTHESIAN_X || nodeType==VMOL_ROTATION_CARTHESIAN_Y || nodeType==VMOL_ROTATION_CARTHESIAN_Z)
		{
			VmolGui::getInstance()->nodesParameter1_->label("Rotation C.:");

			for (i=0; i<VmolCommand::getInstance()->getDoubleList().size(); i++)
			{
				VmolGui::getInstance()->nodesParameter1_->add(VmolCommand::getInstance()->getDoubleList()[i].name.c_str());
			}
		}
		else if (nodeType == VMOL_ROTATION_EULER)
		{
			VmolGui::getInstance()->nodesParameter1_->label("Rotation Euler:");

			for (i=0; i<VmolCommand::getInstance()->getEulerVector3List().size(); i++)
			{
				VmolGui::getInstance()->nodesParameter1_->add(VmolCommand::getInstance()->getEulerVector3List()[i].name.c_str());
			}
		}
		else if (nodeType == VMOL_SCRIPT)
		{
			VmolGui::getInstance()->nodesParameter1_->label("Script path:");

			for (i=0; i<VmolCommand::getInstance()->getStringList().size(); i++)
			{
				VmolGui::getInstance()->nodesParameter1_->add(VmolCommand::getInstance()->getStringList()[i].name.c_str());
			}
		}
		else if (nodeType == VMOL_SCALE)
		{
			VmolGui::getInstance()->nodesParameter1_->label("Scale name:");

			for (i=0; i<VmolCommand::getInstance()->getVector3List().size(); i++)
			{
				VmolGui::getInstance()->nodesParameter1_->add(VmolCommand::getInstance()->getVector3List()[i].name.c_str());
			}
		}
	}
	else if (nodeType == VMOL_MESH)
	{
		VmolGui::getInstance()->nodesParameter1_->show();
		VmolGui::getInstance()->nodesParameter2_->show();
		VmolGui::getInstance()->nodesParameter3_->hide();
		VmolGui::getInstance()->nodesParameter4_->hide();

		VmolGui::getInstance()->nodesParameter1_->label("Mesh name:");
		VmolGui::getInstance()->nodesParameter2_->label("Node mode:");

		for (i=0; i<VmolCommand::getInstance()->getMeshList().size(); i++)
		{
			VmolGui::getInstance()->nodesParameter1_->add(VmolCommand::getInstance()->getMeshList()[i]->getName().c_str());
		}

		for (i=0; i<VmolCommand::getInstance()->getULongLongIntList().size(); i++)
		{
			VmolGui::getInstance()->nodesParameter2_->add(VmolCommand::getInstance()->getULongLongIntList()[i].name.c_str());
		}
	}
	else if (nodeType == VMOL_LOOK_AT)
	{
		VmolGui::getInstance()->nodesParameter1_->show();
		VmolGui::getInstance()->nodesParameter2_->show();
		VmolGui::getInstance()->nodesParameter3_->show();
		VmolGui::getInstance()->nodesParameter4_->hide();

		VmolGui::getInstance()->nodesParameter1_->label("Position:");
		VmolGui::getInstance()->nodesParameter2_->label("Look vector:");
		VmolGui::getInstance()->nodesParameter3_->label("Up vector:");

		for (i=0; i<VmolCommand::getInstance()->getVector3List().size(); i++)
		{
			VmolGui::getInstance()->nodesParameter1_->add(VmolCommand::getInstance()->getVector3List()[i].name.c_str());
			VmolGui::getInstance()->nodesParameter2_->add(VmolCommand::getInstance()->getVector3List()[i].name.c_str());
			VmolGui::getInstance()->nodesParameter3_->add(VmolCommand::getInstance()->getVector3List()[i].name.c_str());
		}
	}
	else if (nodeType == VMOL_PDB)
	{
		VmolGui::getInstance()->nodesParameter1_->show();
		VmolGui::getInstance()->nodesParameter2_->show();
		VmolGui::getInstance()->nodesParameter3_->show();
		VmolGui::getInstance()->nodesParameter4_->show();

		VmolGui::getInstance()->nodesParameter1_->label("PDB name:");
		VmolGui::getInstance()->nodesParameter2_->label("Sphere mesh:");
		VmolGui::getInstance()->nodesParameter3_->label("Stick mesh:");
		VmolGui::getInstance()->nodesParameter4_->label("Node mode:");

		for (i=0; i<VmolCommand::getInstance()->getPdbList().size(); i++)
		{
			VmolGui::getInstance()->nodesParameter1_->add(VmolCommand::getInstance()->getPdbList()[i]->getName().c_str());
		}

		for (i=0; i<VmolCommand::getInstance()->getMeshList().size(); i++)
		{
			VmolGui::getInstance()->nodesParameter2_->add(VmolCommand::getInstance()->getMeshList()[i]->getName().c_str());
			if (VmolCommand::getInstance()->getMeshList()[i]->getName() == "sphere")
				value2 = i;
		}

		for (i=0; i<VmolCommand::getInstance()->getMeshList().size(); i++)
		{
			VmolGui::getInstance()->nodesParameter3_->add(VmolCommand::getInstance()->getMeshList()[i]->getName().c_str());

			if (VmolCommand::getInstance()->getMeshList()[i]->getName() == "stick")
				value3 = i;
		}

		for (i=0; i<VmolCommand::getInstance()->getULongLongIntList().size(); i++)
		{
			VmolGui::getInstance()->nodesParameter4_->add(VmolCommand::getInstance()->getULongLongIntList()[i].name.c_str());
		}
	}

	VmolGui::getInstance()->nodesParameter1_->value(value1);
	VmolGui::getInstance()->nodesParameter2_->value(value2);
	VmolGui::getInstance()->nodesParameter3_->value(value3);
	VmolGui::getInstance()->nodesParameter4_->value(value4);
}

void VmolGui::callbackNodesCreate(Fl_Widget *w, void *data)
{
	string selectedName, newName, newType, newParent, newParams;
	string commandString;
	Fl_Tree_Item *item=NULL;

	newName = VmolGui::getInstance()->nodesName_->value();
	newType = VmolGui::getInstance()->nodesType_->text(VmolGui::getInstance()->nodesType_->value());
	newParent = VmolGui::getInstance()->nodesParent_->text(VmolGui::getInstance()->nodesParent_->value());
	if (newParent == "(root)")
		newParent = "";

	if (VmolGui::getInstance()->nodesParameter1_->visible())
		newParams = ((string) VmolGui::getInstance()->nodesParameter1_->text(VmolGui::getInstance()->nodesParameter1_->value()));
	if (VmolGui::getInstance()->nodesParameter2_->visible())
		newParams = newParams + " " + ((string) VmolGui::getInstance()->nodesParameter2_->text(VmolGui::getInstance()->nodesParameter2_->value()));
	if (VmolGui::getInstance()->nodesParameter3_->visible())
		newParams = newParams + " " + ((string) VmolGui::getInstance()->nodesParameter3_->text(VmolGui::getInstance()->nodesParameter3_->value()));
	if (VmolGui::getInstance()->nodesParameter4_->visible())
		newParams = newParams + " " + ((string) VmolGui::getInstance()->nodesParameter4_->text(VmolGui::getInstance()->nodesParameter4_->value()));

	commandString = "create node name={" + newName + "} nodeType={" + newType + "} nodeParams={" + newParams + "} parent={" + newParent + "}";

	printf ("commandString = %s\n", commandString.c_str());

	VmolCommand::getInstance()->executeCommand(commandString);
	VmolGui::getInstance()->refreshGui();
}

void VmolGui::callbackNodesChange(Fl_Widget *w, void *data)
{
	string selectedName, newName, newType, newParent, newParams;
	string commandString;
	Fl_Tree_Item *item=NULL;

	if (VmolGui::getInstance()->nodesNodeTree_->item_clicked() == NULL)
	{
		return;
	}

	item = (Fl_Tree_Item*) VmolGui::getInstance()->nodesNodeTree_->item_clicked();
	selectedName = item->label();

	newName = VmolGui::getInstance()->nodesName_->value();
	newType = VmolGui::getInstance()->nodesType_->text(VmolGui::getInstance()->nodesType_->value());
	newParent = VmolGui::getInstance()->nodesParent_->text(VmolGui::getInstance()->nodesParent_->value());
	if (newParent == "(root)")
		newParent = "";

	if (VmolGui::getInstance()->nodesParameter1_->visible())
		newParams = ((string) VmolGui::getInstance()->nodesParameter1_->text(VmolGui::getInstance()->nodesParameter1_->value()));
	if (VmolGui::getInstance()->nodesParameter2_->visible())
		newParams = newParams + " " + ((string) VmolGui::getInstance()->nodesParameter2_->text(VmolGui::getInstance()->nodesParameter2_->value()));
	if (VmolGui::getInstance()->nodesParameter3_->visible())
		newParams = newParams + " " + ((string) VmolGui::getInstance()->nodesParameter3_->text(VmolGui::getInstance()->nodesParameter3_->value()));
	if (VmolGui::getInstance()->nodesParameter4_->visible())
		newParams = newParams + " " + ((string) VmolGui::getInstance()->nodesParameter4_->text(VmolGui::getInstance()->nodesParameter4_->value()));

	commandString = "change " + selectedName + " name={" + newName + "} nodeType={" + newType + "} nodeParams={" + newParams + "} parent={" + newParent + "}";

	printf ("commandString = %s\n", commandString.c_str());

	VmolCommand::getInstance()->executeCommand(commandString);
	VmolGui::getInstance()->refreshGui();
}

void VmolGui::callbackNodesRemove(Fl_Widget *w, void *data)
{
	string selectedName;
	string commandString;
	Fl_Tree_Item *item=NULL;

	if (VmolGui::getInstance()->nodesNodeTree_->item_clicked() == NULL)
	{
		return;
	}

	item = (Fl_Tree_Item*) VmolGui::getInstance()->nodesNodeTree_->item_clicked();
	selectedName = item->label();

	commandString = "remove " + selectedName;
	VmolCommand::getInstance()->executeCommand(commandString);
	VmolGui::getInstance()->refreshGui();
}

void VmolGui::callbackNodesOptionsNodeMode(Fl_Widget *w, void *data)
{
	char tempValue[100];
	string selectedName;
	unsigned long long int *nodeModePointer=NULL;

	if (VmolGui::getInstance()->nodesOptionsNodeMode_->size() == 0)
		return;

	selectedName = VmolGui::getInstance()->nodesOptionsNodeMode_->text(VmolGui::getInstance()->nodesOptionsNodeMode_->value());

	nodeModePointer = (unsigned long long int *) VmolCommand::getInstance()->findVariable(COMMAND_VAR_UNSIGNED_LONG_LONG, selectedName);





	VmolGui::getInstance()->nodesModeGeometry_->value((int) ((*nodeModePointer) & VMOL_MODE_GEOMETRY)!=0);
	VmolGui::getInstance()->nodesModeColors_->value((int) ((*nodeModePointer) & VMOL_MODE_COLORS)!=0);
	VmolGui::getInstance()->nodesModeNormals_->value((int) ((*nodeModePointer) & VMOL_MODE_NORMALS)!=0);
	VmolGui::getInstance()->nodesModeTextureCoords_->value((int) ((*nodeModePointer) & VMOL_MODE_TEXTURE_COORDS)!=0);

	VmolGui::getInstance()->nodesModeTextures_->value((int) ((*nodeModePointer) & VMOL_MODE_TEXTURES)!=0);
	VmolGui::getInstance()->nodesModeLighting_->value((int) ((*nodeModePointer) & VMOL_MODE_LIGHTING)!=0);
	VmolGui::getInstance()->nodesModeWireframe_->value((int) ((*nodeModePointer) & VMOL_MODE_WIREFRAME)!=0);
	VmolGui::getInstance()->nodesModeTransparent_->value((int) ((*nodeModePointer) & VMOL_MODE_TRANSPARENT)!=0);

	VmolGui::getInstance()->nodesModeCallote_->value((int) ((*nodeModePointer) & VMOL_MODE_PDB_CALLOTE)!=0);
	VmolGui::getInstance()->nodesModeSticks_->value((int) ((*nodeModePointer) & VMOL_MODE_PDB_STICKS)!=0);
	VmolGui::getInstance()->nodesModeSticksBalls_->value((int) ((*nodeModePointer) & VMOL_MODE_PDB_STICKS_BALLS)!=0);
	VmolGui::getInstance()->nodesModeWire_->value((int) ((*nodeModePointer) & VMOL_MODE_PDB_WIRE)!=0);

	VmolGui::getInstance()->nodesModeColorAtom_->value((int) ((*nodeModePointer) & VMOL_MODE_PDB_COLOR_ATOM)!=0);
	VmolGui::getInstance()->nodesModeColorAmino_->value((int) ((*nodeModePointer) & VMOL_MODE_PDB_COLOR_AMINO)!=0);
	VmolGui::getInstance()->nodesModeColorChain_->value((int) ((*nodeModePointer) & VMOL_MODE_PDB_COLOR_CHAIN)!=0);
	VmolGui::getInstance()->nodesModeColorUndefined1_->value((int) ((*nodeModePointer) & VMOL_MODE_UNDEFINED1)!=0);

	VmolGui::getInstance()->nodesModeObjectCenter_->value((int) ((*nodeModePointer) & VMOL_MODE_OBJECT_CENTER)!=0);
	VmolGui::getInstance()->nodesModeObjectBounds_->value((int) ((*nodeModePointer) & VMOL_MODE_OBJECT_BOUNDS)!=0);
	VmolGui::getInstance()->nodesModeObjectUndefined_->value((int) ((*nodeModePointer) & VMOL_MODE_UNDEFINED2)!=0);
	VmolGui::getInstance()->nodesModeUseDefault_->value((int) ((*nodeModePointer) & VMOL_MODE_USE_DEFAULT)!=0);

	sprintf (tempValue, "%u", ((short unsigned int) ((*nodeModePointer)>>48)));
	VmolGui::getInstance()->nodesModeModel_->value(tempValue);
}

void VmolGui::callbackNodesChecksNodeMode(Fl_Widget *w, void *data)
{
	char tempValue[200];
	string selectedName, commandString;
	unsigned long long int *nodeModePointer=NULL;

	selectedName = VmolGui::getInstance()->nodesOptionsNodeMode_->text(VmolGui::getInstance()->nodesOptionsNodeMode_->value());

	nodeModePointer = (unsigned long long int *) VmolCommand::getInstance()->findVariable(COMMAND_VAR_UNSIGNED_LONG_LONG, selectedName);

//	printf ("prije nodeModePointer = %llx\n", (*nodeModePointer));

	if (VmolGui::getInstance()->nodesModeGeometry_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_GEOMETRY;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_GEOMETRY));

//	printf ("posije nodeModePointer = %llx\n", (*nodeModePointer));

	if (VmolGui::getInstance()->nodesModeColors_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_COLORS;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_COLORS));

	if (VmolGui::getInstance()->nodesModeNormals_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_NORMALS;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_NORMALS));

	if (VmolGui::getInstance()->nodesModeTextureCoords_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_TEXTURE_COORDS;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_TEXTURE_COORDS));



	if (VmolGui::getInstance()->nodesModeTextures_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_TEXTURES;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_TEXTURES));

	if (VmolGui::getInstance()->nodesModeLighting_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_LIGHTING;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_LIGHTING));

	if (VmolGui::getInstance()->nodesModeWireframe_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_WIREFRAME;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_WIREFRAME));

	if (VmolGui::getInstance()->nodesModeTransparent_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_TRANSPARENT;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_TRANSPARENT));



	if (VmolGui::getInstance()->nodesModeCallote_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_PDB_CALLOTE;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_PDB_CALLOTE));

	if (VmolGui::getInstance()->nodesModeSticks_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_PDB_STICKS;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_PDB_STICKS));

	if (VmolGui::getInstance()->nodesModeSticksBalls_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_PDB_STICKS_BALLS;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_PDB_STICKS_BALLS));

	if (VmolGui::getInstance()->nodesModeWire_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_PDB_WIRE;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_PDB_WIRE));



	if (VmolGui::getInstance()->nodesModeColorAtom_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_PDB_COLOR_ATOM;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_PDB_COLOR_ATOM));

	if (VmolGui::getInstance()->nodesModeColorAmino_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_PDB_COLOR_AMINO;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_PDB_COLOR_AMINO));

	if (VmolGui::getInstance()->nodesModeColorChain_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_PDB_COLOR_CHAIN;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_PDB_COLOR_CHAIN));

	if (VmolGui::getInstance()->nodesModeColorUndefined1_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_UNDEFINED1;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_UNDEFINED1));



	if (VmolGui::getInstance()->nodesModeObjectCenter_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_OBJECT_CENTER;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_OBJECT_CENTER));

	if (VmolGui::getInstance()->nodesModeObjectBounds_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_OBJECT_BOUNDS;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_OBJECT_BOUNDS));

	if (VmolGui::getInstance()->nodesModeObjectUndefined_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_UNDEFINED2;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_UNDEFINED2));

	if (VmolGui::getInstance()->nodesModeUseDefault_->value() != 0)
		(*nodeModePointer) |= VMOL_MODE_USE_DEFAULT;
	else
		(*nodeModePointer) = (*nodeModePointer) & (~((unsigned long long int) VMOL_MODE_USE_DEFAULT));

//	printf ("test = %x\n", (~((unsigned int) 2)));

	sprintf (tempValue, "change %s value={0x%016llx}", selectedName.c_str(), (*nodeModePointer));

//	printf ("commandString = %s\n", tempValue);

	commandString = tempValue;

	VmolCommand::getInstance()->executeCommand(commandString);
	VmolGui::getInstance()->refreshGui();
}

void VmolGui::callbackNodesModeModelSet(Fl_Widget *w, void *data)
{
	char tempValue[200];
	unsigned long int i=0;
	unsigned long long int mask=0;
	unsigned long long int newModel=0;
	unsigned long long int *nodeModePointer=NULL;
	unsigned long int modelNumber=0;
	long int newModelIndex=0;
	string selectedName;
	string commandString;
	unsigned long long int *tempNodeModePointer;
	PdbFile *tempPdbData;
	Mesh *tempSphereMesh;
	Mesh *tempStickMesh;

	selectedName = VmolGui::getInstance()->nodesOptionsNodeMode_->text(VmolGui::getInstance()->nodesOptionsNodeMode_->value());
	nodeModePointer = (unsigned long long int *) VmolCommand::getInstance()->findVariable(COMMAND_VAR_UNSIGNED_LONG_LONG, selectedName);

	mask = 65535;
	mask = mask << 48;
	mask = ~mask;

	sscanf(VmolGui::getInstance()->nodesModeModel_->value(), "%u", &modelNumber);
	newModel = modelNumber;
	newModel = newModel & ((unsigned long long int) 65535);
	newModel = newModel << 48;

	*nodeModePointer = (*nodeModePointer) & mask;
	*nodeModePointer = (*nodeModePointer) | newModel;

	sprintf (tempValue, "change %s value={0x%016llx}", selectedName.c_str(), (*nodeModePointer));
//	printf ("tempValue = %s\n", tempValue);
	commandString = tempValue;

	// search for the PDB that this node mode refers to (so we can load the new model)
	for (i=0; i<VmolCommand::getInstance()->getNodeList().size(); i++)
	{
//		printf ("node = %s\n", VmolCommand::getInstance()->getNodeList()[i]->getName().c_str());

		if (VmolCommand::getInstance()->getNodeList()[i]->getNodeType() == VMOL_PDB)
		{
			VmolCommand::getInstance()->getNodeList()[i]->getPdbParameters(&tempPdbData, &tempSphereMesh, &tempStickMesh, &tempNodeModePointer);
//			printf ("%ld\n%ld\n\n", (unsigned long int) nodeModePointer, (unsigned long int) nodeModePointer);

			if (tempNodeModePointer == nodeModePointer)
			{
//				printf ("tempPdbData->getName() = %s\n", tempPdbData->getName().c_str());

				if (modelNumber == 0)
					newModelIndex = -2;
				else if (modelNumber == 65535)
					newModelIndex = -1;
				else
					newModelIndex = (unsigned long int) modelNumber-1;

				tempPdbData->importModel(newModelIndex, true);
				break;
			}
		}
	}

	VmolCommand::getInstance()->executeCommand(commandString);
	VmolGui::getInstance()->refreshGui();
}

void VmolGui::callbackNodesModeModelNone(Fl_Widget *w, void *data)
{
	VmolGui::getInstance()->nodesModeModel_->value("0");
	VmolGui::getInstance()->nodesModeModelSet_->do_callback();
}

void VmolGui::callbackNodesModeModelAll(Fl_Widget *w, void *data)
{
	VmolGui::getInstance()->nodesModeModel_->value("65535");
	VmolGui::getInstance()->nodesModeModelSet_->do_callback();
}

void VmolGui::callbackNodesModeModelNext(Fl_Widget *w, void *data)
{
	char tempValue[100];
	unsigned long int modelNumber=0;

	sscanf(VmolGui::getInstance()->nodesModeModel_->value(), "%u", &modelNumber);

	modelNumber += 1;

	if (modelNumber > 65535)
	{
		modelNumber = 65535;
	}

	sprintf (tempValue, "%u", modelNumber);

	VmolGui::getInstance()->nodesModeModel_->value(tempValue);
	VmolGui::getInstance()->nodesModeModelSet_->do_callback();
}

void VmolGui::callbackNodesModeModelPrevious(Fl_Widget *w, void *data)
{
	char tempValue[100];
	unsigned long int modelNumber=0;

	sscanf(VmolGui::getInstance()->nodesModeModel_->value(), "%u", &modelNumber);

	if (modelNumber > 0)
		modelNumber -= 1;

	sprintf (tempValue, "%u", modelNumber);

	VmolGui::getInstance()->nodesModeModel_->value(tempValue);
	VmolGui::getInstance()->nodesModeModelSet_->do_callback();
}