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
	Bug* target = nullptr;
	float min_dist = std::numeric_limits<float>::max();
	for (auto& object : g_Game->objects)
	{
		if (object->GetRTTI() == Bug::s_RTTI)
		{
			if (object->disabled)
				continue;
			if (!object->visible)
				continue;

			float dist = position.Distance(object->position);
			if (dist < min_dist)
			{
				min_dist = dist;
				target = (Bug*)object;
			}
		}
	}

	return target;
}

Point Tank::CalcShootDirection(Point target_pos, Point target_dir, float target_vel, float bullet_vel) const
{
	Point diff = target_pos - position;
	float a = bullet_vel * bullet_vel - target_vel * target_vel;
	float b1 = diff.Dot(target_dir) * target_vel;
	float c = -diff.Dot(diff);
	float D1 = b1 * b1 - a * c;
	float t = std::max((b1 - sqrtf(D1)) / a, (b1 + sqrtf(D1)) / a);

	Point bullet_dir = (diff + target_dir * target_vel * t) / (bullet_vel * t);
	if (t < 0.0)
		return Point(0, 0);
	return bullet_dir;
}
