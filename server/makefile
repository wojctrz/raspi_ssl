LDIR=-L/usr/local/ssl/lib
LIB=-lssl -lcrypto -lwiringPi
INC=-I/usr/local/ssl/include

LINK_TARGET = main

OBJS = server.o raspiutilsobserver.o main.o

REBUILDABLES = $(OBJS) $(LINK_TARGET)

default : all

clean :
	rm -f $(REBUILDABLES)
	echo Clean done

all : $(LINK_TARGET)
	echo All done

$(LINK_TARGET) : $(OBJS)
	g++ -g -o $@ $^ $(INC) $(LDIR) $(LIB)
	chmod 744 $(LINK_TARGET)

%.o : %.cpp
	g++ -g -o $@ -c $< $(INC) $(LDIR) $(LIB)

# Dependencies
main.o : server.hpp raspiutilsobserver.hpp
server.cpp : server.hpp observer.hpp
raspiutilsobserver.cpp : raspiutilsobserver.hpp observer.hpp
