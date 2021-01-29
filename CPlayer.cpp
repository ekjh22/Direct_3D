#include "DXUT.h"
#include "CPlayer.h"

void CPlayer::Init()
{
	DEBUG_LOG("플레이어 소환");

	CAMERA->player = this;

	collider = new Collider();
	collider->fRadius = 10;
	collider->parent = this;
	COLLISION->Register(collider);

	pos = Vector3(0, 0, 0);

	CAMERA->at = Vector3(0, 150, 0);
	CAMERA->at += pos;

	playerMesh[(int)State::IDLE] = IMAGE->GetVecMesh(L"IDLE", L"./resource/Player/Model/Idle/Idle (%d).obj", 41);

	isUseQuaAllRot = true;
	isGround = true;

	frame.SetFrame(0, 40, 50); // 1000 1초
	sche = new Schedule();
	jumpSche = new Schedule();

	playerState = State::IDLE;
}

void CPlayer::Update()
{
	if (!isDead)
		frame.Update();
	if (isDead && frame.curF != 35)
		frame.Update();

	jumpSche->Update();
	sche->Update();

	if (!isDead)
	{
		while (sche->qSchedule.size())
			sche->qSchedule.pop();

		Move();
		Jump();
	}
}

void CPlayer::Render()
{
	D3DXMATRIXA16 mWorldView = matWorld;
	D3DXMatrixMultiply(&mWorldView, &mWorldView, &CAMERA->matView);

	gDevice->SetTransform(D3DTS_WORLD, &matWorld);
	for (int i = 0; i < playerMesh[(int)playerState][frame.curF]->GetNumMaterials(); ++i)
	{
		gDevice->SetTexture(0, playerMesh[(int)playerState][frame.curF]->GetMaterial(i)->pTexture);
		playerMesh[(int)playerState][frame.curF]->GetMesh()->DrawSubset(i);
	}
}

void CPlayer::Destroy()
{
}

void CPlayer::OnCollision(Collider* col)
{
}

void CPlayer::ObjectDead()
{
}

void CPlayer::Move()
{
	Vector3 moveDir = Vector3(0, 0, 0), mDir = Vector3(0, 0, 0), lookDir = Vector3(0, 0, 0);

	Matrix yMat;
	if (KEYPRESS('W'))
	{
		mDir = Vector3(0, 0, 1);
		D3DXMatrixRotationY(&yMat, D3DXToRadian(CAMERA->cameraRot.x));
		D3DXVec3TransformNormal(&mDir, &mDir, &yMat);
	}
	if (KEYPRESS('S'))
	{
		mDir = Vector3(0, 0, -1);
		D3DXMatrixRotationY(&yMat, D3DXToRadian(CAMERA->cameraRot.x));
		D3DXVec3TransformNormal(&mDir, &mDir, &yMat);
	}
	if (KEYPRESS('A'))
	{
		mDir = Vector3(-1, 0, 0);
		D3DXMatrixRotationY(&yMat, D3DXToRadian(CAMERA->cameraRot.x));
		D3DXVec3TransformNormal(&mDir, &mDir, &yMat);
	}
	if (KEYPRESS('D'))
	{
		mDir = Vector3(1, 0, 0);
		D3DXMatrixRotationY(&yMat, D3DXToRadian(CAMERA->cameraRot.x));
		D3DXVec3TransformNormal(&mDir, &mDir, &yMat);
	}
	pos += mDir * GAME->playerMoveSpeed * DeltaTime;
	moveDir += mDir * GAME->playerMoveSpeed * DeltaTime;

	if (lookDir != moveDir)
	{
		D3DXVec3Normalize(&lookDir, &moveDir);
		rot.y = D3DXToDegree(atan2f(moveDir.x, moveDir.z));
		/*CAMERA->cameraPos += moveDir;
		CAMERA->at += moveDir;*/
	}
}

void CPlayer::Jump()
{
	if (isJump)
	{
		pos.y += jumpDir.y * GAME->playerMoveSpeed * GLOBALGRAVITY * DeltaTime;
		if (pos.y >= 200)
		{
			isJump = false;
			jumpDir.y = -1;
		}
	}
	else if (!isJump && !isGround)
	{
		pos.y += jumpDir.y * GAME->playerMoveSpeed * GLOBALGRAVITY * DeltaTime;
		if (pos.y <= BASEFLOOR)
		{
			isGround = true;
			jumpDir.y = 0;
		}
	}

	if (KEYDOWN(VK_SPACE) && isGround)
	{
		isGround = false;
		isJump = true;

		jumpDir.y = 1;
	}
}
