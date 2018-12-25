#ECE 30862 HW4 makefile
cc = g++ -g

hw4: main.cpp Base.o dPriv.o dProt.o dPublic.o PrivDerived.o ProtDerived.o PublicDerived.o
	$(cc) -o main main.cpp Base.o dPriv.o dProt.o dPublic.o PrivDerived.o ProtDerived.o PublicDerived.o

Base.o: Base.cpp
	$(cc) -c Base.cpp

dPriv.o: dPriv.cpp
	$(cc) -c dPriv.cpp

dProt.o: dProt.cpp
	$(cc) -c dProt.cpp

dPublic.o: dPublic.cpp
	$(cc) -c dPublic.cpp

PrivDerived.o: PrivDerived.cpp
	$(cc) -c PrivDerived.cpp

ProtDerived.o: ProtDerived.cpp
	$(cc) -c ProtDerived.cpp

PublicDerived.o: PublicDerived.cpp
	$(cc) -c PublicDerived.cpp