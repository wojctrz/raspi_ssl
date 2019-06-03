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

    display(recv_buff[DISP_BYTE]);
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

void RaspiUtilsObserver::display(uint8_t number)
{
	switch(number)
	{
		case 0:
			digitalWrite(DISP_A, LOW);
			digitalWrite(DISP_B, LOW);
			digitalWrite(DISP_C, LOW);
			digitalWrite(DISP_D, LOW);
			digitalWrite(DISP_E, LOW);
			digitalWrite(DISP_F, LOW);
			digitalWrite(DISP_G, HIGH);
			break;
		case 1:
			digitalWrite(DISP_A, HIGH);
			digitalWrite(DISP_B, LOW);
			digitalWrite(DISP_C, LOW);
			digitalWrite(DISP_D, HIGH);
			digitalWrite(DISP_E, HIGH);
			digitalWrite(DISP_F, HIGH);
			digitalWrite(DISP_G, HIGH);
			break;
		case 2:
			digitalWrite(DISP_A, LOW);
			digitalWrite(DISP_B, LOW);
			digitalWrite(DISP_C, HIGH);
			digitalWrite(DISP_D, LOW);
			digitalWrite(DISP_E, LOW);
			digitalWrite(DISP_F, HIGH);
			digitalWrite(DISP_G, LOW);
			break;
		case 3:
			digitalWrite(DISP_A, LOW);
			digitalWrite(DISP_B, LOW);
			digitalWrite(DISP_C, LOW);
			digitalWrite(DISP_D, LOW);
			digitalWrite(DISP_E, HIGH);
			digitalWrite(DISP_F, HIGH);
			digitalWrite(DISP_G, LOW);
			break;
		case 4:
			digitalWrite(DISP_A, HIGH);
			digitalWrite(DISP_B, LOW);
			digitalWrite(DISP_C, LOW);
			digitalWrite(DISP_D, HIGH);
			digitalWrite(DISP_E, HIGH);
			digitalWrite(DISP_F, LOW);
			digitalWrite(DISP_G, LOW);
			break;
		case 5:
			digitalWrite(DISP_A, LOW);
			digitalWrite(DISP_B, HIGH);
			digitalWrite(DISP_C, LOW);
			digitalWrite(DISP_D, LOW);
			digitalWrite(DISP_E, HIGH);
			digitalWrite(DISP_F, LOW);
			digitalWrite(DISP_G, LOW);
			break;
		case 6:
			digitalWrite(DISP_A, LOW);
			digitalWrite(DISP_B, HIGH);
			digitalWrite(DISP_C, LOW);
			digitalWrite(DISP_D, LOW);
			digitalWrite(DISP_E, LOW);
			digitalWrite(DISP_F, LOW);
			digitalWrite(DISP_G, LOW);
			break;
		case 7:
			digitalWrite(DISP_A, LOW);
			digitalWrite(DISP_B, LOW);
			digitalWrite(DISP_C, LOW);
			digitalWrite(DISP_D, HIGH);
			digitalWrite(DISP_E, HIGH);
			digitalWrite(DISP_F, HIGH);
			digitalWrite(DISP_G, HIGH);
			break;
		case 8:
			digitalWrite(DISP_A, LOW);
			digitalWrite(DISP_B, LOW);
			digitalWrite(DISP_C, LOW);
			digitalWrite(DISP_D, LOW);
			digitalWrite(DISP_E, LOW);
			digitalWrite(DISP_F, LOW);
			digitalWrite(DISP_G, LOW);
			break;
		case 9:
			digitalWrite(DISP_A, LOW);
			digitalWrite(DISP_B, LOW);
			digitalWrite(DISP_C, LOW);
			digitalWrite(DISP_D, LOW);
			digitalWrite(DISP_E, HIGH);
			digitalWrite(DISP_F, LOW);
			digitalWrite(DISP_G, LOW);
			break;
		default:
			digitalWrite(DISP_A, HIGH);
			digitalWrite(DISP_B, HIGH);
			digitalWrite(DISP_C, HIGH);
			digitalWrite(DISP_D, HIGH);
			digitalWrite(DISP_E, HIGH);
			digitalWrite(DISP_F, HIGH);
			digitalWrite(DISP_G, HIGH);
			break;
	

	}
			
}
