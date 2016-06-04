#include "persona.h"
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

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
	int random;
	if (humano1.fertil && humano2.fertil){
		if((humano1.genero && !humano2.genero) || (!humano1.genero && humano2.genero)){
			random = (rand() % 2);
			if(random == 0)
				nuevoHumano.genero = true;
			else
				nuevoHumano.genero = false;
			if(random == 0)
				nuevoHumano.fertil = false;
			else
				nuevoHumano.fertil = true;
			if(nuevoHumano.genero && humano1.genero)
				nuevoHumano.nombre = humano1.nombre;
			else if (!nuevoHumano.genero && !humano1.genero)
				nuevoHumano.nombre = humano2.nombre;
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
					if ((humano1.genCabello == "AA" && humano2.genCabello == "aa") || (humano1.genCabello == "aa" && humano2.genCabello == "AA")){
						nuevoHumano.colorCabello = "oscuro"; 
						nuevoHumano.genCabello = "Aa";
					} else if ((humano1.genCabello == "AA" && humano2.genCabello == "bb") || (humano1.genCabello == "bb" && humano2.genCabello == "AA")){
						nuevoHumano.colorCabello = "oscuro"; 
						nuevoHumano.genCabello = "Ab";
					} else if ((humano1.genCabello == "aa" && humano2.genCabello == "bb") || (humano1.genCabello == "bb" && humano2.genCabello == "aa")){
						random = (rand() % 2);
						if (random == 0){
							nuevoHumano.colorCabello = "rubio";
							nuevoHumano.genCabello = "ab";
						} else {
							nuevoHumano.colorCabello = "pelirrojo";
							nuevoHumano.genCabello = "ab";
						}
					} else if ((humano1.genCabello == "Aa" && humano2.genCabello == "AA") || (humano1.genCabello == "AA" && humano2.genCabello == "Aa")){
						random = (rand() % 2);
						if(random == 0){
							nuevoHumano.colorCabello = "oscuro"; 
							nuevoHumano.genCabello = "AA";
						} else {
							nuevoHumano.colorCabello = "oscuro";
							nuevoHumano.genCabello = "Aa";
						}
					} else if ((humano1.genCabello == "Ab" && humano2.genCabello == "AA") || (humano1.genCabello == "AA" && humano2.genCabello == "Ab")){
						random = (rand() % 2);
						if(random == 0){
							nuevoHumano.colorCabello = "oscuro"; 
							nuevoHumano.genCabello = "AA";
						} else {
							nuevoHumano.colorCabello = "oscuro"; 
							nuevoHumano.genCabello = "Ab";
						}
					} else if (humano1.genCabello == "Aa" && humano2.genCabello == "Aa"){
						random = (rand() % 3);
						if(random == 0){
							nuevoHumano.colorCabello = "oscuro"; 
							nuevoHumano.genCabello = "AA";
						} else if (random == 1){
							nuevoHumano.colorCabello = "oscuro"; 
							nuevoHumano.genCabello = "Aa";
						} else {
							nuevoHumano.colorCabello = "rubio";
							nuevoHumano.genCabello = "aa";
						}
					} else if (humano1.genCabello == "Ab" && humano2.genCabello == "Ab"){
						random = (rand() % 3);
						if(random == 0){
							nuevoHumano.colorCabello = "oscuro"; 
							nuevoHumano.genCabello = "AA";
						} else if (random == 1){
							nuevoHumano.colorCabello = "oscuro"; 
							nuevoHumano.genCabello = "Ab";
						} else {
							nuevoHumano.colorCabello = "pelirrojo";
							nuevoHumano.genCabello = "bb";
						}
					} else if ((humano1.genCabello == "Aa" && humano2.genCabello == "Ab") && (humano1.genCabello == "Ab" && humano2.genCabello == "Aa")){
						random = (rand() % 4);
						if(random == 0){
							nuevoHumano.colorCabello = "oscuro"; 
							nuevoHumano.genCabello = "AA";
						} else if (random == 1){
							nuevoHumano.colorCabello = "oscuro"; 
							nuevoHumano.genCabello = "Ab";
						} else if (random == 2){
							nuevoHumano.colorCabello = "oscuro";
							nuevoHumano.genCabello = "Aa";
						} else {
							random = (rand() % 2);
							if (random == 0){
								nuevoHumano.colorCabello = "pelirrojo";
								nuevoHumano.genCabello = "ab";	
							} else {
								nuevoHumano.colorCabello = "rubio";
								nuevoHumano.genCabello = "ab";	
							}
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
						random = (rand() % 2);
						if (random == 0){
							nuevoHumano.colorOjos = "verdes";
							nuevoHumano.genOjos = "ab";
						} else {
							nuevoHumano.colorOjos = "azules";
							nuevoHumano.genOjos = "ab";
						}
					} else if ((humano1.genOjos == "Aa" && humano2.genOjos == "AA") || (humano1.genOjos == "AA" && humano2.genOjos == "Aa")){
						random = (rand() % 2);
						if(random == 0){
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "AA";
						} else {
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "Aa";
						}
					} else if ((humano1.genOjos == "Ab" && humano2.genOjos == "AA") || (humano1.genOjos == "AA" && humano2.genOjos == "Ab")){
						random = (rand() % 2);
						if(random == 0){
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "AA";
						} else {
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "Ab";
						}
					} else if (humano1.genOjos == "Aa" && humano2.genOjos == "Aa"){
						random = (rand() % 3);
						if(random == 0){
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "AA";
						} else if (random == 1){
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "Aa";
						} else {
							nuevoHumano.colorOjos = "verdes";
							nuevoHumano.genOjos = "aa";
						}
					} else if (humano1.genOjos == "Ab" && humano2.genOjos == "Ab"){
						random = (rand() % 3);
						if(random == 0){
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "AA";
						} else if (random == 1){
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "Ab";
						} else {
							nuevoHumano.colorOjos = "azules";
							nuevoHumano.genOjos = "bb";
						}
					} else if ((humano1.genOjos == "Aa" && humano2.genOjos == "Ab") && (humano1.genOjos == "Ab" && humano2.genOjos == "Aa")){
						random = (rand() % 4);
						if(random == 0){
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "AA";
						} else if (random == 1){
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "Ab";
						} else if (random == 2){
							nuevoHumano.colorOjos = "oscuro";
							nuevoHumano.genOjos = "Aa";
						} else {
							random = (rand() % 2);
							if (random == 0){
								nuevoHumano.colorOjos = "azules";
								nuevoHumano.genOjos = "ab";	
							} else {
								nuevoHumano.colorOjos = "verdes";
								nuevoHumano.genOjos = "ab";	
							}
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
						nuevoHumano.colorPiel = "oscura"; 
						nuevoHumano.genPiel = "Aa";
					} else if((humano1.genPiel == "Aa" && humano2.genPiel == "AA") || (humano1.genPiel == "AA" && humano2.genPiel == "Aa")){
						random = (rand() % 2);
						if(random == 0){
							nuevoHumano.colorPiel = "oscura"; 
							nuevoHumano.genPiel = "AA";
						} else {
							nuevoHumano.colorPiel = "oscura"; 
							nuevoHumano.genPiel = "Aa";
						}
					} else if (humano1.genPiel == "Aa" && humano2.genPiel == "Aa"){
						random = (rand() % 3);
						if(random == 0){
							nuevoHumano.colorPiel = "blanca"; 
							nuevoHumano.genPiel = "AA";
						} else if (random == 1){
							nuevoHumano.colorPiel = "blanca"; 
							nuevoHumano.genPiel = "Aa";
						} else {
							nuevoHumano.colorPiel = "oscura";
							nuevoHumano.genPiel = "aa";
						}
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
	int random;
	persona nuevoHumano;
	if (humano1.fertil && humano2.fertil){
		if((humano1.genero && !humano2.genero) || (!humano1.genero && humano2.genero)){
			int esMami = (rand() % 101);
			if(esMami == 1){
				int esMamita = (1 + rand() % 100);
				if (esMamita<22){
					random = (rand() % 2);
					if(random == 0)
						nuevoHumano.genero = true;
					else
						nuevoHumano.genero = false;
					if(random == 0)
						nuevoHumano.fertil = false;
					else
						nuevoHumano.fertil = true;
					if(nuevoHumano.genero && humano1.genero)
						nuevoHumano.nombre = humano1.nombre;
					else if (!nuevoHumano.genero && !humano1.genero)
						nuevoHumano.nombre = humano2.nombre;
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
						if ((humano1.genCabello == "AA" && humano2.genCabello == "aa") || (humano1.genCabello == "aa" && humano2.genCabello == "AA")){
							nuevoHumano.colorCabello = "oscuro"; 
							nuevoHumano.genCabello = "Aa";
						} else if ((humano1.genCabello == "AA" && humano2.genCabello == "bb") || (humano1.genCabello == "bb" && humano2.genCabello == "AA")){
							nuevoHumano.colorCabello = "oscuro"; 
							nuevoHumano.genCabello = "Ab";
						} else if ((humano1.genCabello == "aa" && humano2.genCabello == "bb") || (humano1.genCabello == "bb" && humano2.genCabello == "aa")){
							random = (rand() % 2);
							if (random == 0){
								nuevoHumano.colorCabello = "rubio";
								nuevoHumano.genCabello = "ab";
							} else {
								nuevoHumano.colorCabello = "pelirrojo";
								nuevoHumano.genCabello = "ab";
							}
						} else if ((humano1.genCabello == "Aa" && humano2.genCabello == "AA") || (humano1.genCabello == "AA" && humano2.genCabello == "Aa")){
							random = (rand() % 2);
							if(random == 0){
								nuevoHumano.colorCabello = "oscuro"; 
								nuevoHumano.genCabello = "AA";
							} else {
								nuevoHumano.colorCabello = "oscuro";
								nuevoHumano.genCabello = "Aa";
							}
						} else if ((humano1.genCabello == "Ab" && humano2.genCabello == "AA") || (humano1.genCabello == "AA" && humano2.genCabello == "Ab")){
							random = (rand() % 2);
							if(random == 0){
								nuevoHumano.colorCabello = "oscuro"; 
								nuevoHumano.genCabello = "AA";
							} else {
								nuevoHumano.colorCabello = "oscuro"; 
								nuevoHumano.genCabello = "Ab";
							}
						} else if (humano1.genCabello == "Aa" && humano2.genCabello == "Aa"){
							random = (rand() % 3);
							if(random == 0){
								nuevoHumano.colorCabello = "oscuro"; 
								nuevoHumano.genCabello = "AA";
							} else if (random == 1){
								nuevoHumano.colorCabello = "oscuro"; 
								nuevoHumano.genCabello = "Aa";
							} else {
								nuevoHumano.colorCabello = "rubio";
								nuevoHumano.genCabello = "aa";
							}
						} else if (humano1.genCabello == "Ab" && humano2.genCabello == "Ab"){
							random = (rand() % 3);
							if(random == 0){
								nuevoHumano.colorCabello = "oscuro"; 
								nuevoHumano.genCabello = "AA";
							} else if (random == 1){
								nuevoHumano.colorCabello = "oscuro"; 
								nuevoHumano.genCabello = "Ab";
							} else {
								nuevoHumano.colorCabello = "peirrojo";
								nuevoHumano.genCabello = "bb";
							}
						} else if ((humano1.genCabello == "Aa" && humano2.genCabello == "Ab") && (humano1.genCabello == "Ab" && humano2.genCabello == "Aa")){
						random = (rand() % 4);
						if(random == 0){
							nuevoHumano.colorCabello = "oscuro"; 
							nuevoHumano.genCabello = "AA";
						} else if (random == 1){
							nuevoHumano.colorCabello = "oscuro"; 
							nuevoHumano.genCabello = "Ab";
						} else if (random == 2){
							nuevoHumano.colorCabello = "oscuro";
							nuevoHumano.genCabello = "Aa";
						} else {
							random = (rand() % 2);
							if (random == 0){
								nuevoHumano.colorCabello = "pelirrojo";
								nuevoHumano.genCabello = "ab";	
							} else {
								nuevoHumano.colorCabello = "rubio";
								nuevoHumano.genCabello = "ab";	
							}
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
						random = (rand() % 2);
						if (random == 0){
							nuevoHumano.colorOjos = "verdes";
							nuevoHumano.genOjos = "ab";
						} else {
							nuevoHumano.colorOjos = "azules";
							nuevoHumano.genOjos = "ab";
						}
					} else if ((humano1.genOjos == "Aa" && humano2.genOjos == "AA") || (humano1.genOjos == "AA" && humano2.genOjos == "Aa")){
						random = (rand() % 2);
						if(random == 0){
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "AA";
						} else {
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "Aa";
						}
					} else if ((humano1.genOjos == "Ab" && humano2.genOjos == "AA") || (humano1.genOjos == "AA" && humano2.genOjos == "Ab")){
						random = (rand() % 2);
						if(random == 0){
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "AA";
						} else {
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "Ab";
						}
					} else if (humano1.genOjos == "Aa" && humano2.genOjos == "Aa"){
						random = (rand() % 3);
						if(random == 0){
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "AA";
						} else if (random == 1){
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "Aa";
						} else {
							nuevoHumano.colorOjos = "verdes";
							nuevoHumano.genOjos = "aa";
						}
					} else if (humano1.genOjos == "Ab" && humano2.genOjos == "Ab"){
						random = (rand() % 3);
						if(random == 0){
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "AA";
						} else if (random == 1){
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "Ab";
						} else {
							nuevoHumano.colorOjos = "azules";
							nuevoHumano.genOjos = "bb";
						}
					} else if ((humano1.genOjos == "Aa" && humano2.genOjos == "Ab") && (humano1.genOjos == "Ab" && humano2.genOjos == "Aa")){
						random = (rand() % 4);
						if(random == 0){
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "AA";
						} else if (random == 1){
							nuevoHumano.colorOjos = "oscuro"; 
							nuevoHumano.genOjos = "Ab";
						} else if (random == 2){
							nuevoHumano.colorOjos = "oscuro";
							nuevoHumano.genOjos = "Aa";
						} else {
							random = (rand() % 2);
							if (random == 0){
								nuevoHumano.colorOjos = "verdes";
								nuevoHumano.genOjos = "ab";	
							} else {
								nuevoHumano.colorOjos = "azules";
								nuevoHumano.genOjos = "ab";	
							}
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
						nuevoHumano.colorPiel = "oscura"; 
						nuevoHumano.genPiel = "Aa";
					} else if((humano1.genPiel == "Aa" && humano2.genPiel == "AA") || (humano1.genPiel == "AA" && humano2.genPiel == "Aa")){
						random = (rand() % 2);
						if(random == 0){
							nuevoHumano.colorPiel = "oscura"; 
							nuevoHumano.genPiel = "AA";
						} else {
							nuevoHumano.colorPiel = "oscura"; 
							nuevoHumano.genPiel = "Aa";
						}
					} else if (humano1.genPiel == "Aa" && humano2.genPiel == "Aa"){
						random = (rand() % 3);
						if(random == 0){
							nuevoHumano.colorPiel = "blanca"; 
							nuevoHumano.genPiel = "AA";
						} else if (random == 1){
							nuevoHumano.colorPiel = "blanca"; 
							nuevoHumano.genPiel = "Aa";
						} else {
							nuevoHumano.colorPiel = "oscura";
							nuevoHumano.genPiel = "aa";
						}
					}
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
	ss << "Persona -> Nombre: " << this -> nombre << ", Cabello " << this -> colorCabello << ", Color de ojos " << this -> colorOjos << ", Color de piel " << this -> colorPiel;
	return ss.str();
}