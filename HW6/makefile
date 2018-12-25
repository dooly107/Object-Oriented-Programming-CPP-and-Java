#ECE 30862 HW6 makefile
cc = g++ -g

hw6_member: main.cpp set.o
	$(cc) -o main_member main.cpp set.o

set.o: set.cpp
	$(cc) -c set.cpp

hw6_nonmember: main_nonmember.cpp set_nonmember.o
	$(cc) -o main_nonmember main_nonmember.cpp set_nonmember.o

set_nonmember.o: set_nonmember.cpp
	$(cc) -c set_nonmember.cpp
