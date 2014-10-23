#pragma once

#include <stdint.h>
#include <cstring>

class MyHitPattern
{
public:
    MyHitPattern()
    {
        memset(hitPattern, sizeof(hitPattern), 0);
    };

    void setHit(uint32_t data, size_t index)
    {
        // well known buffer offerflow
        hitPattern[index] = data;
    }

    uint32_t getHit(size_t index)
    {
        return hitPattern[index];
    }

private:
    uint32_t hitPattern[25];
};
