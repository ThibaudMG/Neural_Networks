Include_Path = C:/Users/mthib/Documents/M2IF/C++/Neural_Networks/include
#INCLUDES = -I $(ProjectHOME)include
INCLUDES = -I ${Include_Path}
CC = g++

all: executable

executable : main.o iris.o image.o
	${CC} ${INCLUDES} -o executable main.o iris.o image.o

input.o : ${Include_Path}/input.h

iris.o : iris.cpp ${Include_Path}/iris.h input.o
	${CC} -c iris.cpp ${INCLUDES} 

image.o : image.cpp ${Include_Path}/image.h input.o
	${CC} -c image.cpp ${INCLUDES} 

main.o : main.cpp ${Include_Path}/iris.h ${Include_Path}/image.h
	${CC} -c main.cpp ${INCLUDES}

clean:
	rm *.o executable
