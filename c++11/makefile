cc=g++ -std=c++11
LIBS=-pthread
FLAGS= -g

mutex:mutex.o mutex
	 $(cc) mutex mutex.o ${LIBS}

mutex.o:mutex.cpp
	$(cc) -c mutex.cpp

.PHONY:clean
clean:
	rm *.o
