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

const persona& persona::operator+(const persona& humano){
	if (humano.fertil && this -> fertil){
		if (humano.colorCabello == "oscuro" || humano.colorOjos == "oscuros" || humano.colorPiel == "blanca"){
			this -> genCabello = "AA";
			humano.genCabello = "AA";
			this -> genOjos = "AA";
			humano.genOjos = "AA";
			this -> genPiel = "AA";
			humano.genPiel = "AA";
		}
		if (humano.colorCabello == "rubio" || humano.colorOjos == "verdes" || humano.colorPiel == "oscura"){
			this -> genCabello = "aa";
			humano.genCabello = "aa";
			this -> genOjos = "aa";
				humano.genOjos = "aa";
			this -> genPiel = "aa";
			humano.genPiel = "aa";
		}
		if (humano.colorCabello == "pelirrojo" || humano.colorOjos == "azules"){
			this -> genCabello = "bb";
			humano.genCabello = "bb";
			this -> genOjos = "bb";
			humano.genOjos = "bb";
		}
	} else {
		exit(1);
	}
}

const persona& persona::operator*(const persona& humano){
	
}
