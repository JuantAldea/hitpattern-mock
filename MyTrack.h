#pragma once
#include "MyHitPattern.h"

class MyTrack
{
public:
    MyTrack(){
        for (int i = 0; i < 25; i++){
            p.setHit(i, i);
        }
    }
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

