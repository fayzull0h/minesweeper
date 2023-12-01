EXEC = minesweeper

CC = g++

CFLAGS = -std=c++20 -Wall -g

SRC = $(wildcard *.cc)

OBJECTS = $(SRC:.cc=.o)

${EXEC}: ${OBJECTS}
	${CC} ${CFLAGS} ${OBJECTS} -o ${EXEC}

grid.o: grid.cc grid.h info.h textdisplay.h observer.h
	${CC} ${CFLAGS} -c grid.cc

cell.o: cell.cc cell.h info.h
	${CC} ${CFLAGS} -c cell.cc

textdisplay.o: textdisplay.cc textdisplay.h info.h subject.h
	${CC} ${CFLAGS} -c textdisplay.cc

info.o: info.h state.h
	${CC} ${CFLAGS} -c info.h

state.o: state.h
	${CC} ${CFLAGS} -c state.h

main.o: grid.h state.h
	${CC} ${CFLAGS} -c main.cc