#pragma once
#include "CObject.h"
class Monster :
    public CObject
{
private:
    float       fSpeed;
    float       fMaxDistance;
    Vec2        vCenterPos;
    int         iDir; // 1, -1

public:
    float       GetSpeed() { return fSpeed; }
    void        SetSpeed(float _f) { fSpeed = _f; }
    void        SetMoveDistance(float _f) { fMaxDistance = _f; }

    void        SetCenterPos(Vec2 _vPos) { vCenterPos = _vPos; }

public:
    virtual void Update();

public:
    Monster();
    ~Monster();
};