EXEC = minesweeper

CC = g++

CFLAGS = -std=c++20 -Wall -g

SRC = $(wildcard *.cc)

OBJECTS = $(SRC:.cc=.o)

${EXEC}: ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} -o ${EXEC}

grid.cc.gch: grid.cc grid.h info.h textdisplay.h observer.h
	${CC} ${CFLAGS} -c grid.cc

cell.cc.gch: cell.cc cell.h info.h
	${CC} ${CFLAGS} -c cell.cc

textdisplay.cc.gch: textdisplay.cc textdisplay.h info.h subject.h
	${CC} ${CFLAGS} -c textdisplay.cc

info.cc.gch: info.h state.h
	${CC} ${CFLAGS} -c info.h

state.cc.gch: state.h
	${CC} ${CFLAGS} -c state.h

main.cc.gch: grid.h state.h
	${CC} ${CFLAGS} -c main.cc