#pragma once

#include <stdint.h>
#include <cstring>

class MyHitPattern
{
public:
    static const size_t MAX_HITS = 200;

    MyHitPattern()
    {
        memset(array, sizeof(uint16_t) * MAX_HITS, 0);
    };

    void setHit(uint16_t data, size_t index)
    {
        if (index >= MyHitPattern::MAX_HITS) {
            return;
        }
        array[index] = data;
    }

    uint16_t getHit(size_t index) const
    {
        if (index >= MyHitPattern::MAX_HITS) {
            return 0;
        }

        return array[index];
    }

    uint8_t getCount() const
    {
        uint8_t count;
        for (count = 0; count < MyHitPattern::MAX_HITS; count++){
            if (!getHit(count)){
                return count;
            }
            count++;
        }
    }

private:
    uint16_t array[MAX_HITS];
};
