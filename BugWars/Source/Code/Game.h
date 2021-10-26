#pragma once
#include "GameBase/GameBase.h"
#include "Globals.h"

struct Tank;

struct Game : public GameBase
{
	Game();
	~Game();


	virtual void OnUpdate(float dt) override;
	virtual void OnRender() const override;
	virtual void AddObject(GameObject* object) override;

	virtual void OnBugsSpawned() override;

	std::vector<GameObject*> objects;
	std::vector<GameObject*> to_remove;
	std::vector<GameObject*> to_add;
};