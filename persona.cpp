#include "persona.h"
#include <string>
#include <iostream>

using std::cout;
using std::string;

persona::persona(){

}

persona::persona(string nombre, bool genero, string colorCabello, string colorPiel, string colorOjos, bool fertil):
				 nombre(nombre),genero(genero),colorCabello(colorCabello),colorPiel(colorPiel),colorOjos(colorOjos),fertil(fertil){

}

bool persona::operator+(const persona& humano){
	
}

bool persona::operator*(const persona& humano){
	
}