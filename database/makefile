COMPILE=g++
CFLAGS= -c -fpermissive
#fpermissive:ignore some nonformat code, put some errors into warnings.

LIB=-L./mysql/lib
INC=-I./ -I./mysql/include
LIB=-lmysqlclient

OBJS=


%.o:%.cpp
	$(COMPILE) $(FLAGS) $^ $(INC)

.PHONY:clean
clean:
	rm -rf *.o
