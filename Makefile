CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD
EXEC = vm
OBJECTS = main.o Model/State/Action/BasicAction.o Model/State/Buffer/Buffer.o \
Controller/Controller.o View/EditorView.o Model/State/Mode/InsertMode.o Model/State/Action/InsertModeAction.o \
Model/State/Mode/Mode.o Model/Model.o Model/State/Mode/NormalMode.o Model/State/Action/NormalModeAction.o \
Model/State/State.o Model/State/Buffer/StringBuffer.o Model/VM.o Controller/VmKeyboard.o View/BarView.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${OBJECTS} -o ${EXEC} -lncurses

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}