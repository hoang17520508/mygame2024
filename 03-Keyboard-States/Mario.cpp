#include "Mario.h"

void CMario::Update(DWORD dt)
{
	x += vx * dt;
	y += vy * dt; 

	vy += ay * dt;

	vx += ax * dt;

	if (abs(vx) > abs(maxVx)) vx = maxVx;
	if (abs(vy) > abs(maxVy)) vy = maxVy;

	DebugOutTitle(L"vx = %0.5f", this->vx);


	// BAD & sinful platform collision handling, see next sample for correct collision handling

	// simple screen edge collision!!!
	if (vx > 0 && x > 290) x = 290;
	if (vx < 0 && x < 0) x = 0;
	if (vy > 0 && y > 160) y = 160;
	if (vy < 0 && y < 0) y = 0;
}

void CMario::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	int aniId = -1;

	// Mario is still on air check, this will not work when Mario is just stand up

	if (vx == 0)
	{
		if (nx > 0) aniId = ID_ANI_JASON_IDLE_RIGHT;
		else aniId = ID_ANI_JASON_IDLE_LEFT;
	}
	else if (vx > 0)
	{
		if (ax < 0)
			aniId = ID_ANI_JASON_IDLE_RIGHT;
		else if (ax == JASON_ACCEL_RUN_X)
			aniId = ID_ANI_JASON_RUNNING_RIGHT;
		else if (ax == JASON_ACCEL_WALK_X)
			aniId = ID_ANI_JASON_WALKING_RIGHT;
	}
	else // vx < 0
	{
		if (ax > 0)
			aniId = ID_ANI_JASON_IDLE_LEFT;
		else if (ax == -JASON_ACCEL_RUN_X)
			aniId = ID_ANI_JASON_RUNNING_LEFT;
		else if (ax == -JASON_ACCEL_WALK_X)
			aniId = ID_ANI_JASON_WALKING_LEFT;
	}
	if (vy != 0)
	{
		if (ay > 0)
			aniId = ID_ANI_JASON_WALKING_DOWN;
		else 
			if (vx == 0)
			{
				aniId = ID_ANI_JASON_WALKING_UP;
			}
	}
	

	if (aniId == -1) aniId = ID_ANI_JASON_IDLE_RIGHT;


	animations->Get(aniId)->Render(x, y);
}

void CMario::SetState(int state)
{
	DebugOut(L"[INFO] State: %d\n", state);
	switch (state)
	{
	case JASON_STATE_WALKING_RIGHT:
		if (isSitting) break;
		maxVx = JASON_WALKING_SPEED;
		ax = JASON_ACCEL_WALK_X;
		nx = 1;
		break;
	case JASON_STATE_WALKING_LEFT:
		if (isSitting) break;
		maxVx = -JASON_WALKING_SPEED;
		ax = -JASON_ACCEL_WALK_X;
		nx = -1;
		break;

	case JASON_STATE_DOWN:
		maxVy = JASON_WALKING_SPEED;
		ay = JASON_ACCEL_WALK_X;
		ny = 1;
		break;
	case JASON_STATE_UP:
		maxVy = -JASON_WALKING_SPEED;
		ay = -JASON_ACCEL_WALK_X;
		ny = -1;
		break;

	case JASON_STATE_IDLE:
		ax = 0.0f;
		vx = 0.0f;
		ay = 0.0f;
		vy = 0.0f;
		break;
	}

	CGameObject::SetState(state);
}

