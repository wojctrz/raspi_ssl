#include "server.hpp"
#include "raspiutilsobserver.hpp"

int main()
{
    RaspiUtilsObserver observerinho;
    Server serverinho(4433);
    serverinho.attach(&observerinho);
    serverinho.start();

}