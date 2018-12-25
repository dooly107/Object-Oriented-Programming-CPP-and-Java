#ECE 30862 CPP project
cc = g++ -g

cpp_project: Main.cpp Zork.o Item.o Room.o Creature.o ConditionHas.o ConditionStatus.o Trigger.o Command.o Container.o
	$(cc) -o cpp_proj Main.cpp Zork.o Item.o Room.o Creature.o ConditionHas.o ConditionStatus.o Trigger.o Command.o Container.o

Zork.o: Zork.cpp
	$(cc) -c Zork.cpp

Item.o: Item.cpp
	$(cc) -c Item.cpp

Room.o: Room.cpp
	$(cc) -c Room.cpp

Creature.o: Creature.cpp
	$(cc) -c Creature.cpp

ConditionHas.o: ConditionHas.cpp
	$(cc) -c ConditionHas.cpp

ConditionStatus.o: ConditionStatus.cpp
	$(cc) -c ConditionStatus.cpp

Trigger.o: Trigger.cpp
	$(cc) -c Trigger.cpp

Command.o: Command.cpp
	$(cc) -c Command.cpp

Container.o: Container.cpp
	$(cc) -c Container.cpp