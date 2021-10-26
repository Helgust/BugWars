#include "pch.h"
#include "Tank.h"
#include "Globals.h"
#include "Game.h"
#include "Bullet.h"
#include "Bug.h"
#include "GameBase/Log.h"

IMPLEMENT_RTTI(Tank);

void Tank::OnUpdate(float dt)
{
}

BugBase* Tank::GetBugToShoot() const
{
	for (auto obj : g_Game->objects)
		if (auto bug = dynamic_cast<Bug*>(obj))
			return bug;

	return nullptr;
}

Point Tank::CalcShootDirection(Point target_pos, Point target_dir, float target_vel, float bullet_vel) const
{
	return { 1, 0 };
}
