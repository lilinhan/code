CC = clang++ -std=c++11
CGLAGS = -Wall -g
LDFLAGS = -pthread

log:log.o
	${CC} -o log log.o ${LDFLAGS}
log.o:log.h
	${CC} -c log.cpp

.PHONY:clean
clean:
	rm *.o
