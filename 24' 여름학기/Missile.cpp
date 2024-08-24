#include "pch.h"
#include "Missile.h"
#define PI 3.14

#include "TimeMgr.h"

Missile::Missile()
	: theta(PI/4.f)
	, dir(Vec2(-1.f, -7.f))
{
	dir.Normalize();
}

Missile::~Missile()
{
}

void Missile::Update()
{
	Vec2 vPos = GetPos();

	//vPos.y += 500.f * fDT * (float)fDir;
	vPos.x += 600.f * dir.x * fDT;
	vPos.y += 600.f * dir.y * fDT;

	SetPos(vPos);
}