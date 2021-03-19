SOURCE = main.cpp
INCLUDE = ../../include
TARGET = project
MAKEFILE = makefile
CXX = g++
CXX_VERSION = -std=c++17
CXX_OPTION = -O

${TARGET}: ${SOURCE} ${MAKEFILE} ${INCLUDE}
	${CXX} ${CXX_VERSION} ${CXX_OPTION} -o ${TARGET} ${SOURCE}

run:
	./${TARGET}

clean:
	rm ${TARGET}
