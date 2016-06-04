#include "persona.h"
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using std::cout;
using std::string;
using std::stringstream;

persona::persona(){
	this->colorCabello = "";
}

persona::persona(string nombre, bool genero, string colorCabello, string colorPiel, string colorOjos, bool fertil):
				 nombre(nombre),genero(genero),colorCabello(colorCabello),colorPiel(colorPiel),colorOjos(colorOjos),fertil(fertil){
}

const persona operator+(persona& humano1, persona& humano2){
	persona nuevoHumano;
	if (humano1.fertil && humano2.fertil){
		if((humano1.genero && !humano2.genero) || (!humano1.genero && humano2.genero)){
			int esMami = (rand() % 101);
			if (esMami < 22){
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
					if(humano1.genCabello == "AA" && humano2.genCabello == "AA")
						nuevoHumano.colorCabello = "oscuro";
					else if (humano1.genCabello == "aa" && humano2.genCabello == "aa")
						nuevoHumano.colorCabello = "rubio";
					else if (humano1.genCabello == "bb" && humano2.genCabello == "bb")
						nuevoHumano.colorCabello = "pelirrojo";
				} else {
					if (humano1.genCabello == "AA" && humano2.genCabello != "AA" || humano1.genCabello != "AA" && humano2.genCabello == "AA")
						nuevoHumano.colorCabello = "oscuro"; 
					else {
						int cabelloRandom = (rand() % 2);
						if (cabelloRandom == 0){
							nuevoHumano.colorCabello = "rubio";
						} else {
							nuevoHumano.colorCabello = "pelirrojo";
						}
					}
				}
				if (humano1.genOjos == humano2.genOjos){
					if(humano1.genOjos == "AA" && humano2.genOjos == "AA")
						nuevoHumano.colorOjos = "oscuros"; 
					else if (humano1.genCabello == "aa" && humano2.genCabello == "aa")
						nuevoHumano.colorOjos = "verdes";
					else if (humano1.genCabello == "bb" && humano2.genCabello == "bb")
						nuevoHumano.colorOjos = "azules";
				} else {
					if (humano1.genOjos == "AA" && humano2.genOjos != "AA" || humano1.genOjos != "AA" && humano2.genOjos == "AA")
						nuevoHumano.colorOjos = "oscuros"; 
					else {
						int ojosRandom = (rand() % 2);
						if (ojosRandom == 0){
							nuevoHumano.colorOjos = "verdes";
						} else {
							nuevoHumano.colorOjos = "azules";
						}
					}
				}
				if (humano1.genPiel == humano2.genPiel){
					if(humano1.genPiel == "AA" && humano2.genPiel == "AA")
						nuevoHumano.colorPiel = "blanca";
					else if (humano1.genPiel == "aa" && humano2.genPiel == "aa")
						nuevoHumano.colorPiel = "oscura";
				} else {
					if (humano1.genPiel == "AA" && humano2.genPiel != "AA" || humano1.genPiel != "AA" && humano2.genPiel == "AA")
						nuevoHumano.colorPiel = "blanca";
					else {
						nuevoHumano.colorPiel = "oscura";
					}
				}
			}
			return nuevoHumano;
		} else {
			return nuevoHumano;
		}
	} else {
		return nuevoHumano;
	}
}

const persona operator*(persona& humano1, persona& humano2){
	persona nuevoHumano;
	if (humano1.fertil && humano2.fertil){
		if((humano1.genero && !humano2.genero) || (!humano1.genero && humano2.genero)){
			int esMami = (rand() % 101);
			if (esMami < 22){
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
					if(humano1.genCabello == "AA" && humano2.genCabello == "AA")
						nuevoHumano.colorCabello = "oscuro";
					else if (humano1.genCabello == "aa" && humano2.genCabello == "aa")
						nuevoHumano.colorCabello = "rubio";
					else if (humano1.genCabello == "bb" && humano2.genCabello == "bb")
						nuevoHumano.colorCabello = "pelirrojo";
				} else {
					if (humano1.genCabello == "AA" && humano2.genCabello != "AA" || humano1.genCabello != "AA" && humano2.genCabello == "AA")
						nuevoHumano.colorCabello = "oscuro"; 
					else {
						int cabelloRandom = (rand() % 2);
						if (cabelloRandom == 0){
							nuevoHumano.colorCabello = "rubio";
						} else {
							nuevoHumano.colorCabello = "pelirrojo";
						}
					}
				}
				if (humano1.genOjos == humano2.genOjos){
					if(humano1.genOjos == "AA" && humano2.genOjos == "AA")
						nuevoHumano.colorOjos = "oscuros"; 
					else if (humano1.genCabello == "aa" && humano2.genCabello == "aa")
						nuevoHumano.colorOjos = "verdes";
					else if (humano1.genCabello == "bb" && humano2.genCabello == "bb")
						nuevoHumano.colorOjos = "azules";
				} else {
					if (humano1.genOjos == "AA" && humano2.genOjos != "AA" || humano1.genOjos != "AA" && humano2.genOjos == "AA")
						nuevoHumano.colorOjos = "oscuros"; 
					else {
						int ojosRandom = (rand() % 2);
						if (ojosRandom == 0){
							nuevoHumano.colorOjos = "verdes";
						} else {
							nuevoHumano.colorOjos = "azules";
						}
					}
				}
				if (humano1.genPiel == humano2.genPiel){
					if(humano1.genPiel == "AA" && humano2.genPiel == "AA")
						nuevoHumano.colorPiel = "blanca";
					else if (humano1.genPiel == "aa" && humano2.genPiel == "aa")
						nuevoHumano.colorPiel = "oscura";
				} else {
					if (humano1.genPiel == "AA" && humano2.genPiel != "AA" || humano1.genPiel != "AA" && humano2.genPiel == "AA")
						nuevoHumano.colorPiel = "blanca";
					else {
						nuevoHumano.colorPiel = "oscura";
					}
				}
			}
			return nuevoHumano;
		} else {
			return nuevoHumano;
		}
	} else {
		return nuevoHumano;
	}
}

string persona::toString() const{
	stringstream ss;
	ss << "Persona: " << this -> nombre << ", " << this -> colorCabello << ", " << this -> colorOjos << ", " << this -> colorPiel;
	return ss.str();
}
