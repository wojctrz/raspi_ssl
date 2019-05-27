#include "raspiutilsobserver.hpp"

RaspiUtilsObserver::RaspiUtilsObserver()
{
    // setup GPIOs
    wiringPiSetup () ;
    pinMode (LED_PIN, OUTPUT) ;
}

void RaspiUtilsObserver::update(uint8_t buff[], int size)
{
    buff_size = size;
    for(int i = 0; i < buff_size; ++i)
    {
        this->recv_buff[i] = buff[i];
    }
    // folowing prints are temporary, for debugging purposes only
    std::cout << "Iam updated!\n";
    for(int i = 0; i < buff_size; ++i)
    {
        std::cout << static_cast<unsigned int>(buff[i]) << " ";
    }
    std::cout << std::endl;

    led_flash(recv_buff[LED_BYTE]);
}

void RaspiUtilsObserver::led_flash(uint8_t mode)
{
    switch(mode)
    {
        // TODO: do real things, not only print you're doing this
        case LED_OFF:
            // LED off
            std::cout << "Switching off my LED...\n";
            digitalWrite (LED_PIN, LOW) ;
            break;
        case LED_ON:
            // LED on
            std::cout << "Switching on my LED...\n";
            digitalWrite (LED_PIN, HIGH) ;
            break;
        default:
            // unsupported value
            std::cout << "value unsupported :(\n";
            break;

    }
}
