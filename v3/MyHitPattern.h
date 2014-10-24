#pragma once

#include <stdint.h>
#include <cstring>

class MyHitPattern
{
public:
    static const size_t MAX_HITS = 25;

    MyHitPattern()
    {
        memset(hitPattern, sizeof(uint16_t) * MAX_HITS, 0);
        count = 0;
    };

    void setHit(uint16_t data)
    {
        if (count == MyHitPattern::MAX_HITS) {
            return;
        }
        hitPattern[count] = data;
        count++;
    }

    uint16_t getHit(size_t index)
    {
        if (index >= MyHitPattern::MAX_HITS) {
            return 0;
        }

        return hitPattern[index];
    }


private:
    uint16_t hitPattern[MAX_HITS];
    uint8_t count;
};
