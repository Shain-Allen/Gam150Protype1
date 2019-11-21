//------------------------------------------------------------------------------
//
// File Name: GameObjecs.cpp
// Author(s): Shain Allen
// Project: BetaHighLevelTemplate
// Course: wanic GP2
//
// Copyright © 2018 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------
#include "stdafx.h"
#include "GameObjecs.h"

using namespace Beta;

Beta::GameObject* Archtypes::CreatePlayer()
{
	GameObject* player = new GameObject("Player");

	Transform* transfrom = new Transform(0.0f, 0.0f);
	transfrom->SetRotation(0.0f);
	transfrom->SetScale(Vector2D(0.5f, 0.5f));
	player->AddComponent(transfrom);

	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(ResourceGetSpriteSource("Player"));
	player->AddComponent(sprite);

	EngineGetModule(GameObjectFactory)->SaveObjectToFile(player);

	return player;
}

Beta::GameObject* Archtypes::CreateMaskDisplay()
{
	GameObject* MaskDisplay = new GameObject("Player");

	Transform* transfrom = new Transform(0.0f, 0.0f);
	transfrom->SetRotation(0.0f);
	transfrom->SetScale(Vector2D(0.5f, 0.5f));
	MaskDisplay->AddComponent(transfrom);

	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(ResourceGetSpriteSource("Masks"));
	MaskDisplay->AddComponent(sprite);

	EngineGetModule(GameObjectFactory)->SaveObjectToFile(MaskDisplay);

	return ;
}

Beta::GameObject* Archtypes::MakeDoor()
{
	GameObject* door = new GameObject("Door");

	Transform* transform = new Transform(0.0f, 0.0f);
	transform->SetRotation(0.0f);
	transform->SetScale(Vector2D(0.5, 0.5));
	door->AddComponent(transform);

	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(ResourceGetSpriteSource("Door"));
	door->AddComponent(sprite);

	EngineGetModule(GameObjectFactory)->SaveObjectToFile(door);

	return door;
}

Beta::Archetype Archtypes::CreateMonster()
{
	GameObject* Monster = new GameObject("Monster");

	Transform* transfrom = new Transform(0.0f, 0.0f);
	transfrom->SetRotation(0.0f);
	transfrom->SetScale(Vector2D(0.5f, 0.5f));
	Monster->AddComponent(transfrom);

	Sprite* sprite = new Sprite;
	sprite->SetSpriteSource(ResourceGetSpriteSource("Monsters"));
	Monster->AddComponent(sprite);

	EngineGetModule(GameObjectFactory)->SaveObjectToFile(Monster);

	return Archetype(Monster);
}
