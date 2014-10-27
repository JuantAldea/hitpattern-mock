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
        count = 0;
    };

    void setHit(uint16_t data)
    {
        if (count >= MyHitPattern::MAX_HITS) {
            return;
        }
        array[count] = data;
        count++;
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
        return count;
    }

private:
    uint16_t array[MAX_HITS];
    uint8_t count;
};
