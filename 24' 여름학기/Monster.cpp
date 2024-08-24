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

    // ���� �������� �ð��� fSpeed ��ŭ �̵�
    vCurPos.x += fDT * fSpeed * iDir;

    float fDist = abs(vCenterPos.x - vCurPos.x) - fMaxDistance;

    // ��ȸ �Ÿ� ���ط��� �Ѿ���� Ȯ��
   
    if (0.f < fDist)
    {
        // ���� ����
        iDir *= -1;
        vCurPos.x += fDist * iDir;
    }

    SetPos(vCurPos);
}