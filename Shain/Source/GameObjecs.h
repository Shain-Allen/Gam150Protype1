//------------------------------------------------------------------------------
//
// File Name: GameObjecs.h
// Author(s): Shain Allen
// Project: BetaHighLevelTemplate
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#pragma once

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Forward Declarations:
//------------------------------------------------------------------------------

namespace Beta
{
	class GameObject;
}

//------------------------------------------------------------------------------
// Public Structures:
//------------------------------------------------------------------------------

namespace OBJECTS
{
	//------------------------------------------------------------------------------
	// Public Functions:
	//------------------------------------------------------------------------------

	//A gameobject that uses the player texture
		//returns a pointer to the newly constructed player object
	Beta::GameObject* CreatePlayer();


	//a gameobject that uses the mask strip texture
		//returns a pointer to the new mask display object
	Beta::GameObject* CreateMaskDisplay();

	//A gameobject that uses the door texture
		//Return a pointer to the new mask display object
	Beta::GameObject* MakeDoor();

	//a archetype that uses the monsters texture
		//Returns a pointer to the new mask displayobject
	Beta::Archetype CreateMonster();
}