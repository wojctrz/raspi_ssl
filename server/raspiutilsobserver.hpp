#ifndef RASPIUTILSOBSERVER_HPP
#define RASPIUTILSOBSERVER_HPP

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

};

#endif  // RASPIUTILSOBSERVER_HPP