#ifndef RASPIUTILSOBSERVER_HPP
#define RASPIUTILSOBSERVER_HPP

#define LED_BYTE 1

#define LED_OFF 0
#define LED_ON 1
#define LED_BLINK 2

#include "observer.hpp"
#include <iostream>

class RaspiUtilsObserver : public Observer
{
public:

    virtual void update(uint8_t buff[], int size);

private:
    uint8_t recv_buff[1024];
    
    int buff_size;
    
    void process_data();

    void led_flash(uint8_t mode);

};

#endif  // RASPIUTILSOBSERVER_HPP