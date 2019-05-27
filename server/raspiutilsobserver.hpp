#ifndef RASPIUTILSOBSERVER_HPP
#define RASPIUTILSOBSERVER_HPP

#define LED_BYTE 1

#define LED_PIN 0

#define LED_OFF 0
#define LED_ON 1

#include "observer.hpp"
#include <iostream>
#include <wiringPi.h>   // for manipulating GPIOs

class RaspiUtilsObserver : public Observer
{
public:

    RaspiUtilsObserver();

    virtual void update(uint8_t buff[], int size);

private:
    uint8_t recv_buff[1024];
    
    int buff_size;
    
    void process_data();

    void led_flash(uint8_t mode);

};

#endif  // RASPIUTILSOBSERVER_HPP