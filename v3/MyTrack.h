#pragma once
#include "MyHitPattern.h"
class MyTrack
{
public:

    uint16_t getHitPattern(size_t index) const
    {
        return hitPattern.getHit(index);
    }

    void setHitPattern(uint16_t hit)
    {
        hitPattern.setHit(hit);
    }
   
    uint8_t getHitCount() const
    {
        return hitPattern.getCount();
    }

private:
    MyHitPattern hitPattern;
};

