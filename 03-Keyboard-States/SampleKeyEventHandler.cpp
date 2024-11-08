#include "SampleKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "Mario.h"

extern CMario* mario;

void CSampleKeyHandler::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_UP:
		mario->SetState(JASON_STATE_UP);
		break;
	case DIK_DOWN:
		mario->SetState(JASON_STATE_DOWN);
		break;
	}
}

void CSampleKeyHandler::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_UP:
		mario->SetState(JASON_STATE_RELEASE_UP);
		break;
	case DIK_DOWN:
		mario->SetState(JASON_STATE_DOWN_RELEASE);
		break;
	}
}

void CSampleKeyHandler::KeyState(BYTE *states)
{
	CGame* game = CGame::GetInstance();

	if (game->IsKeyDown(DIK_RIGHT))
	{
		if (game->IsKeyDown(DIK_A))
			mario->SetState(JASON_STATE_RUNNING_RIGHT);
		else
			mario->SetState(JASON_STATE_WALKING_RIGHT);
	}
	else if (game->IsKeyDown(DIK_LEFT))
	{
		if (game->IsKeyDown(DIK_A))
			mario->SetState(JASON_STATE_RUNNING_LEFT);
		else
			mario->SetState(JASON_STATE_WALKING_LEFT);
	}
	else  if (game->IsKeyDown(DIK_UP)) {
		mario->SetState(JASON_STATE_UP);
	}
	else  if (game->IsKeyDown(DIK_DOWN)) {
		mario->SetState(JASON_STATE_DOWN);
	}
	else
		mario->SetState(JASON_STATE_IDLE);
	
	// Sitting state has higher priority 
	

}