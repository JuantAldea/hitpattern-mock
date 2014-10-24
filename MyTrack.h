#pragma once
#include "MyHitPattern.h"
class MyTrack
{

public:

    MyTrack()
    {
        for (int i = 0; i < 20; i++) {
            hitPattern.setHit(i);
        }
    }
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

