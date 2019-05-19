#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <cstdint>

class Observer
{
public:
    virtual void update(uint8_t buff[], int size) = 0;
};

#endif  // OBSERVER_HPP