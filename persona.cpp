#include "persona.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using std::cout;
using std::string;

persona::persona(){
	this->nombre = "";
}

persona::persona(string nombre, bool genero, string colorCabello, string colorPiel, string colorOjos, bool fertil):
				 nombre(nombre),genero(genero),colorCabello(colorCabello),colorPiel(colorPiel),colorOjos(colorOjos),fertil(fertil){
}

const persona& persona::operator+(const persona& humano1, const persona humano2){
	persona nuevoHumano;
	if (humano1.fertil && this -> fertil){
		if((humano1.genero && !this -> genero) || (!humano1.genero && this -> genero)){
			int preñada = (rand() % 101);
			if (preñada < 22){
				if (humano1.colorCabello == "oscuro" || humano1.colorOjos == "oscuros" || humano1.colorPiel == "blanca"){
					humano1.genCabello = "AA";
					humano1.genOjos = "AA";
					humano1.genPiel = "AA";
				} else if (humano1.colorCabello == "rubio" || humano1.colorOjos == "verdes" || humano1.colorPiel == "oscura"){	
					humano1.genCabello = "aa";
					humano1.genOjos = "aa";
					humano1.genPiel = "aa";
				} else if (humano1.colorCabello == "pelirrojo" || humano1.colorOjos == "azules"){
					humano1.genCabello = "bb";
					humano1.genOjos = "bb";
				} else if(humano2.colorCabello == "oscuro" || humano2.colorOjos == "oscuros" || humano2.colorPiel == "blanca"){
					humano2.genCabello = "AA";
					humano2.genOjos = "AA";
					humano2.genPiel = "AA";
				} else if(humano2.colorCabello == "rubio" || humano2.colorOjos == "verdes" || humano2.colorPiel == "oscura"){
					humano2.genCabello = "aa";
					humano2.genOjos = "aa";
					humano2.genPiel = "aa";
				} else if(humano2.colorCabello == "pelirrojo" || humano2.colorOjos == "azules"){
					humano2.genCabello = "bb";
					humano2.genOjos = "bb";
				}
				if (humano1.genCabello == humano2.genCabello){
					if(humano1.genCabello == "AA" || humano2.genCabello == "AA")
						nuevoHumano.colorCabello = "oscuro"; 
				} else {
					if (humano1.genCabello == "AA" && humano2.genCabello != "AA"){
						int cabelloRandom = (rand() % 2);
						if (cabelloRandom == 0){
							nuevoHumano.colorCabello = "rubio";
						} else {
							nuevoHumano.colorCabello = "pelirrojo";
						}
					}
				}
			}
		} else {
			exit(1);
		}
	} else {
		exit(1);
	}
}

const persona& persona::operator*(const persona& humano){
	
}

string persona::toString() const{

}