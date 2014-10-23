#pragma once
#include "MyHitPattern.h"

class MyTrack
{
public:
    uint32_t getHitPattern(size_t index)
    {
        return p.getHit(index);
    }

    void setHitPattern(uint16_t hit, size_t index)
    {
        p.setHit(hit, index);
    }

private:
    MyHitPattern p;
};

