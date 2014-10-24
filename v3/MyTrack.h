#pragma once
#include "MyHitPattern.h"
class MyTrack
{
public:

    uint16_t getHitPattern(size_t index)
    {
        return hitPattern.getHit(index);
    }

    void setHitPattern(uint16_t hit)
    {
        hitPattern.setHit(hit);
    }

private:
    MyHitPattern hitPattern;
};

