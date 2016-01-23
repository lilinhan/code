CC = clang++ -std=c++11
CGLAGS = -Wall -g
LDFLAGS = -pthread

log:main.o
	${CC} -o log main.o ${LDFLAGS}
main.o:main.cpp
	${CC} -c main.cpp

.PHONY:clean
clean:
	rm *.o
