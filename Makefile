CC= g++ -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio

OBJECTS= main.o Globals.o StateManager.o State.o Menu.o InitialMenu.o MainMenu.o Gameplay.o

TARGET= songe

$(TARGET) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

main.o : states/StateManager.h 
	$(CC) -o main.o -c main.cc

Globals.o : utils/Globals.h utils/conf.h
	$(CC) -o Globals.o -c utils/Globals.cc

StateManager.o : states/StateManager.h states/State.h states/MainMenu.h states/Gameplay.h 
	$(CC) -o StateManager.o -c states/StateManager.cc

State.o : states/State.h utils/Globals.h
	$(CC) -o State.o -c states/State.cc

Menu.o : states/Menu.h states/State.h 
	$(CC) -o Menu.o -c states/Menu.cc

InitialMenu.o : states/InitialMenu.h states/Menu.h states/StateManager.h
	$(CC) -o InitialMenu.o -c states/InitialMenu.cc

MainMenu.o : states/MainMenu.h states/Menu.h states/StateManager.h
	$(CC) -o MainMenu.o -c states/MainMenu.cc

Gameplay.o : states/Gameplay.h states/StateManager.h
	$(CC) -o Gameplay.o -c states/Gameplay.cc

clean :
	rm -f *~ *.o $(TARGET)