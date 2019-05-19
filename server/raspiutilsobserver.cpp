#include "raspiutilsobserver.hpp"

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
}
