Include_Path = C:/Users/mthib/Documents/M2IF/C++/Neural_Networks/include
#INCLUDES = -I $(ProjectHOME)include
INCLUDES = -I ${Include_Path}
EXECUTABLES = iris.o image.o sigmoide.o tanh.o perceptron.o nn1.o
CC = g++

all: executable

executable : main.o ${EXECUTABLES}
	${CC} ${INCLUDES} -o executable main.o ${EXECUTABLES}


## Inputs
input.o : ${Include_Path}/input.h

iris.o : iris.cpp ${Include_Path}/iris.h input.o
	${CC} -c iris.cpp ${INCLUDES} 

image.o : image.cpp ${Include_Path}/image.h input.o
	${CC} -c image.cpp ${INCLUDES} 


## Fonctions activation
fonction_activation.o : ${Include_Path}/fonction_activation.h

sigmoide.o : sigmoide.cpp ${Include_Path}/sigmoide.h fonction_activation.o
	${CC} -c sigmoide.cpp ${INCLUDES} 

tanh.o : tanh.cpp ${Include_Path}/tanh.h fonction_activation.o
	${CC} -c tanh.cpp ${INCLUDES} 


## Neural Network
perceptron.o : perceptron.cpp ${Include_Path}/perceptron.h
	${CC} -c perceptron.cpp ${INCLUDES} 

nn1.o : nn1.cpp ${Include_Path}/nn1.h
	${CC} -c nn1.cpp ${INCLUDES}


## Main
main.o : main.cpp ${Include_Path}/iris.h ${Include_Path}/image.h
	${CC} -c main.cpp ${INCLUDES}

clean:
	rm *.o executable
