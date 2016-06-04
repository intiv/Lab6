sexo:	main.o persona.o
	g++ main.o persona.o -o sexo
main.o:	main.cpp persona.h
	g++ -c main.cpp
persona.o:	persona.cpp persona.h
	g++ -c persona.cpp

