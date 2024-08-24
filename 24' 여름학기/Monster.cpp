#include "pch.h"
#include "Monster.h"

#include "TimeMgr.h"

Monster::Monster()
    : fSpeed(100.f)
    , vCenterPos(Vec2(0.f, 0.f))
    , fMaxDistance(50.f)
    , iDir(1)
{
}

Monster::~Monster()
{
}

void Monster::Update()
{
    Vec2 vCurPos = GetPos();

    // 진행 방향으로 시간당 fSpeed 만큼 이동
    vCurPos.x += fDT * fSpeed * iDir;

    float fDist = abs(vCenterPos.x - vCurPos.x) - fMaxDistance;

    // 배회 거리 기준량을 넘어섰는지 확인
   
    if (0.f < fDist)
    {
        // 방향 변경
        iDir *= -1;
        vCurPos.x += fDist * iDir;
    }

    SetPos(vCurPos);
}