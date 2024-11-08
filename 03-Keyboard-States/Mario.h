#pragma once
#include "GameObject.h"

#include "Animation.h"
#include "Animations.h"

#include "debug.h"

#define JASON_WALKING_SPEED		0.1f
#define JASON_RUNNING_SPEED		0.2f

#define JASON_ACCEL_WALK_X	0.0005f
#define JASON_ACCEL_RUN_X	0.0007f

#define JASON_JUMP_SPEED_Y		0.5f
#define JASON_JUMP_RUN_SPEED_Y	0.6f

#define JASON_GRAVITY			0.002f

#define JASON_STATE_IDLE			0
#define JASON_STATE_WALKING_RIGHT	100
#define JASON_STATE_WALKING_LEFT	200

#define JASON_STATE_UP			300
#define JASON_STATE_RELEASE_UP    301

#define JASON_STATE_RUNNING_RIGHT	400
#define JASON_STATE_RUNNING_LEFT	500

#define JASON_STATE_DOWN			600
#define JASON_STATE_DOWN_RELEASE	601


#pragma region ANIMATION_ID

#define ID_ANI_JASON_IDLE_RIGHT 400
#define ID_ANI_JASON_IDLE_LEFT 401

#define ID_ANI_JASON_WALKING_RIGHT 500
#define ID_ANI_JASON_WALKING_LEFT 501

#define ID_ANI_JASON_RUNNING_RIGHT 600
#define ID_ANI_JASON_RUNNING_LEFT 601



#pragma endregion




#define GROUND_Y 160.0f

#define JASON_SIT_HEIGHT_ADJUST 4.0f

class CMario : public CGameObject
{
	BOOLEAN isSitting;
	float maxVx;
	float maxVy;
	float ax;// acceleration on x 
	float ay;
public: 
	CMario(float x, float y) : CGameObject(x, y) 
	{
		isSitting = false;
		maxVx = 0.0f;
		ax = 0.0f;
		maxVy = 0.0f;
		ay = 0.0f;
	}
	void Update(DWORD dt);
	void Render();
	void SetState(int state);
};