#pragma once
#include "MyHitPattern.h"
class MyTrack
{
public:
    uint16_t getHitPattern(size_t index)
    {
        return hitPattern1.getHit(index);
    }

    void setHitPattern(uint16_t hit, size_t index)
    {
        hitPattern1.setHit(hit, index);
    }

private:
    MyHitPattern hitPattern1;
    MyHitPattern hitPattern2;
};

