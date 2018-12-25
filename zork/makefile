#ECE 30862 CPP project
cc = g++ -g

cpp_project: Main.cpp Zork.o Item.o Room.o Creature.o Trigger.o Container.o Attack.o
	$(cc) -o cpp_proj Main.cpp Zork.o Item.o Room.o Creature.o Trigger.o Container.o Attack.o

Zork.o: Zork.cpp
	$(cc) -c Zork.cpp

Item.o: Item.cpp
	$(cc) -c Item.cpp

Room.o: Room.cpp
	$(cc) -c Room.cpp

Creature.o: Creature.cpp
	$(cc) -c Creature.cpp

Trigger.o: Trigger.cpp
	$(cc) -c Trigger.cpp

Container.o: Container.cpp
	$(cc) -c Container.cpp

Attack.o: Attack.cpp
	$(cc) -c Attack.cpp