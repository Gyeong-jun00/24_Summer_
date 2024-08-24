#pragma once
#include "CObject.h"

class Missile :
    public CObject
{
private:
    float fDir;
    float theta;
    Vec2 dir;

public:
    void SetDir(bool _bUp)
    {
        if (_bUp)
            fDir = -1.f;
        else
            fDir = 1.f;
    }

public:
    virtual void Update();

public:
    Missile();
    ~Missile();

    void SetDir(float th) { theta = th; }
    void SetDir(Vec2 _dir)
    {
        dir = _dir;
        dir.Normalize();
    }
};

