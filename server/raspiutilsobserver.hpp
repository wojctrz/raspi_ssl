#ifndef RASPIUTILSOBSERVER_HPP
#define RASPIUTILSOBSERVER_HPP

#define LED_BYTE 1
#define DISP_BYTE 2

#define LED_PIN 0

// define digital display pins
#define DISP_A 1
#define DISP_B 2
#define DISP_C 3
#define DISP_D 4
#define DISP_E 5
#define DISP_F 6
#define DISP_G 7

#define LED_OFF 0
#define LED_ON 1

// digital display us a common anode one, so it requires negative logic
#define DISP_OFF 1
#define DISP_ON 0

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

    void display(uint8_t number);

};

#endif  // RASPIUTILSOBSERVER_HPP
