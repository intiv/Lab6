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
	this->nombre = "";
}

persona::persona(string nombre, bool genero, string colorCabello, string colorPiel, string colorOjos, bool fertil):
				 nombre(nombre),genero(genero),colorCabello(colorCabello),colorPiel(colorPiel),colorOjos(colorOjos),fertil(fertil){
	if (this -> colorCabello == "oscuro" || this -> colorOjos == "oscuros" || this -> colorPiel == "blanca"){
		this -> genCabello = "AA";
		this -> genOjos = "AA";
		this -> genPiel = "AA";
	} else if (this -> colorCabello == "rubio" || this -> colorOjos == "verdes" || this -> colorPiel == "oscura"){	
		this -> genCabello = "aa";
		this -> genOjos = "aa";
		this -> genPiel = "aa";
	} else if (this -> colorCabello == "pelirrojo" || this -> colorOjos == "azules"){
		this -> genCabello = "bb";
		this -> genOjos = "bb";
	}
}

const persona operator+(persona& humano1, persona& humano2){
	persona nuevoHumano;
	if (humano1.fertil && humano2.fertil){
		if((humano1.genero && !humano2.genero) || (!humano1.genero && humano2.genero)){
			int esMami = (1 + rand() % 100);
			if (esMami < 22){
				if (humano1.genCabello == humano2.genCabello){
					if(humano1.genCabello == "AA" && humano2.genCabello == "AA"){
						nuevoHumano.colorCabello = "oscuro";
						nuevoHumano.genCabello = "AA";
					}
					else if (humano1.genCabello == "aa" && humano2.genCabello == "aa"){
						nuevoHumano.colorCabello = "rubio";
						nuevoHumano.genCabello = "aa";
					}
					else if (humano1.genCabello == "bb" && humano2.genCabello == "bb"){
						nuevoHumano.colorCabello = "pelirrojo";
						nuevoHumano.genCabello = "bb";
					}
				} else {
					if (humano1.genCabello == "AA" && humano2.genCabello == "aa"){
						nuevoHumano.colorCabello = "oscuro"; 
						nuevoHumano.genCabello = "Aa";
					} else if (humano1.genCabello == "AA" && humano2.genCabello == "bb"){
						nuevoHumano.colorCabello = "oscuro"; 
						nuevoHumano.genCabello = "Ab";
					} else if ((humano1.genCabello == "aa" && humano2.genCabello == "bb") || (humano1.genCabello == "bb" && humano2.genCabello == "aa")){
						int cabelloRandom = (rand() % 2);
						if (cabelloRandom == 0){
							nuevoHumano.colorCabello = "rubio";
							nuevoHumano.genCabello = "ab";
						} else {
							nuevoHumano.colorCabello = "pelirrojo";
							nuevoHumano.genCabello = "ab";
						}
					}
				}

				if (humano1.genOjos == humano2.genOjos){
					if(humano1.genOjos == "AA" && humano2.genOjos == "AA"){
						nuevoHumano.colorOjos = "oscuros";
						nuevoHumano.genOjos = "AA";
					}
					else if (humano1.genOjos == "aa" && humano2.genOjos == "aa"){
						nuevoHumano.colorOjos = "verdes";
						nuevoHumano.genOjos = "aa";
					}
					else if (humano1.genOjos == "bb" && humano2.genOjos == "bb"){
						nuevoHumano.colorOjos = "azules";
						nuevoHumano.genOjos = "bb";
					}
				} else {
					if ((humano1.genOjos == "AA" && humano2.genOjos == "aa") || (humano1.genOjos == "aa" && humano2.genOjos == "AA")){
						nuevoHumano.colorOjos = "oscuro"; 
						nuevoHumano.genOjos = "Aa";
					} else if ((humano1.genOjos == "AA" && humano2.genOjos == "bb") || (humano1.genOjos == "bb" && humano2.genOjos == "AA")){
						nuevoHumano.colorOjos = "oscuro"; 
						nuevoHumano.genOjos = "Ab";
					} else if ((humano1.genOjos == "aa" && humano2.genOjos == "bb") || (humano1.genOjos == "bb" && humano2.genOjos == "aa")){
						int ojosRandom = (rand() % 2);
						if (ojosRandom == 0){
							nuevoHumano.colorOjos = "rubio";
							nuevoHumano.genOjos = "ab";
						} else {
							nuevoHumano.colorOjos = "pelirrojo";
							nuevoHumano.genOjos = "ab";
						}
					}
				}

				if (humano1.genPiel == humano2.genPiel){
					if(humano1.genPiel == "AA" && humano2.genPiel == "AA"){
						nuevoHumano.colorPiel = "blanca";
						nuevoHumano.genPiel = "AA";
					}
					else if (humano1.genPiel == "aa" && humano2.genPiel == "aa"){
						nuevoHumano.colorPiel = "oscura";
						nuevoHumano.genPiel = "aa";
					}
				} else {
					if ((humano1.genPiel == "AA" && humano2.genPiel == "aa") || (humano1.genPiel == "aa" && humano2.genPiel == "AA")){
						nuevoHumano.colorPiel = "oscuro"; 
						nuevoHumano.genPiel = "Aa";
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
			if(esMami == 1){
				int esMamita = (1 + rand() % 100);
				if (esMamita<22){
					
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
	ss << "Persona -> Nombre: " << this -> nombre << ", Cabello " << this -> colorCabello << ", Color de ojos " << this -> colorOjos << ", Color de piel " << this -> colorPiel;
	return ss.str();
}
