#include "pch.h"
#include "Player.h"

#include "CScene.h"
#include "SceneMgr.h"

#include "KeyMgr.h"
#include "TimeMgr.h"

#include "Missile.h"

void Player::Update()
{
	Vec2 vPos = GetPos();

	if (KeyMgr::Instance()->GetKeyState(KEY::W) == KEY_TYPE::HOLD) {
		vPos.y -= 200.f * DT;
	}
	if (KeyMgr::Instance()->GetKeyState(KEY::A) == KEY_TYPE::HOLD) {
		vPos.x -= 200.f * DT;
	}
	if (KeyMgr::Instance()->GetKeyState(KEY::S) == KEY_TYPE::HOLD) {
		vPos.y += 200.f * DT;
	}
	if (KeyMgr::Instance()->GetKeyState(KEY::D) == KEY_TYPE::HOLD) {
		vPos.x += 200.f * DT;
	}
	if (KeyMgr::Instance()->GetKeyState(KEY::SPACE) == KEY_TYPE::TAP) {
		CreateMissile();
	}

	SetPos(vPos);
}

void Player::CreateMissile()
{
	Vec2 vMissilePos = GetPos();
	vMissilePos.y -= GetScale().y / 2.f;

	// Missile Object
	Missile* pMissile = new Missile;

	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(Vec2(25.f, 25.f));
	pMissile->SetDir(true);

	CScene* pCurScene = SceneMgr::Instance()->GetCurScene();
	pCurScene->CScene::AddObject(pMissile, GROUP_TYPE::DEFAULT);
}