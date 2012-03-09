CC= g++ -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

OBJECTS= main.o Globals.o StateManager.o State.o Menu.o TextMenu.o ImageMenu.o InitialMenu.o MainMenu.o ChoicePersoMenu.o Gameplay.o

TARGET= songe

$(TARGET) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

main.o : main.cc states/StateManager.h
	$(CC) -o main.o -c main.cc

Globals.o : utils/Globals.cc utils/Globals.h utils/conf.h
	$(CC) -o Globals.o -c utils/Globals.cc

StateManager.o : states/StateManager.cc states/StateManager.h states/State.h states/MainMenu.h states/Gameplay.h
	$(CC) -o StateManager.o -c states/StateManager.cc

State.o : states/State.cc states/State.h utils/Globals.h
	$(CC) -o State.o -c states/State.cc

Menu.o : states/Menu.cc states/Menu.h states/State.h
	$(CC) -o Menu.o -c states/Menu.cc

TextMenu.o : states/TextMenu.cc states/TextMenu.h states/Menu.h
	$(CC) -o TextMenu.o -c states/TextMenu.cc

ImageMenu.o : states/ImageMenu.cc states/ImageMenu.h states/Menu.h
	$(CC) -o ImageMenu.o -c states/ImageMenu.cc

InitialMenu.o : states/InitialMenu.cc states/InitialMenu.h states/TextMenu.h states/StateManager.h
	$(CC) -o InitialMenu.o -c states/InitialMenu.cc

MainMenu.o : states/MainMenu.cc states/MainMenu.h states/TextMenu.h states/StateManager.h
	$(CC) -o MainMenu.o -c states/MainMenu.cc

ChoicePersoMenu.o : states/ChoicePersoMenu.cc states/ChoicePersoMenu.h states/ImageMenu.h states/StateManager.h
	$(CC) -o ChoicePersoMenu.o -c states/ChoicePersoMenu.cc

Gameplay.o : states/Gameplay.cc states/Gameplay.h states/StateManager.h
	$(CC) -o Gameplay.o -c states/Gameplay.cc

clean :
	rm -f *~ *.o $(TARGET)