#include "persona.h"
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

void printHumans(vector<persona>&);

int main(int argc,char* argv[]){
	vector<persona> Personas;
	srand(time(NULL));
	bool continuar=true;
	while(continuar){
		cout<<"1. Agregar persona"<<endl<<"2. Sexo sin proteccion"<<endl<<"3. Durex contra el muro"<<endl<<"4. Salir"<<endl;
		int op;
		cin>>op;
		string name="", haircolor="",skincolor="",eyecolor="";
		bool gender=true, fertile=true;
		int fert, sex;
		if(op==1){
			cout<<"Ingrese genero: 1 = Hombre, 2 = Mujer"<<endl;
			cin>>sex;
			if(sex==1){
				gender=true;
			}else{
				gender=false;
			}	
			cout<<"Ingrese nombre:"<<endl;
			getline(cin,name);
			cout<<"Ingrese color de cabello:"<<endl;
			getline(cin,haircolor);
			cout<<"Ingrese color de piel:"<<endl;
			getline(cin,skincolor);
			cout<<"Ingrese color de ojos:"<<endl;
			getline(cin,eyecolor);
			cout<<"Es fertil? [1 = Si/2 = No]"<<endl;
			cin>>fert;
			if(fert==1){
				fertile=true;
			}else{
				fertile=false;
			}
			Personas.push_back(persona(name,gender,haircolor,skincolor,eyecolor,fertile));
		}else if(op==2){ 
			if(Personas.size()>=2){
				int first,second;
				printHumans(Personas);
				cout<<"Ingrese posicion en la base de datos de la primera persona a tener setso setsi salvaje:"<<endl;
				cin>>first;
				printHumans(Personas);
				cout<<"Ingrese posicion en la base de datos de la segunda persona a tener setso setsi salvaje:"<<endl;
				cin>>second;
				if((Personas.at(first).genero&&!Personas.at(second).genero)||(!Personas.at(first).genero&&Personas.at(second).genero)){
					persona hijo=(Personas.at(first)+Personas.at(second));
					if(hijo.colorCabello!=""){		
						Personas.push_back(hijo);
						cout<<"Nacio "<<hijo.toString()<<", Felicidades ahora se tienen que casar y vivir infelizmente juntos por siempre"<<endl;
					}
				}else{
					cout<<"GOD SHALL DELIVER HIS HOLY JUDGEMENT UPON THE FAGS"<<endl;
				}
			}else{
				cout<<"No hay suficientes personas para tener sexo salvaje del duro, agregue mas personas"<<endl;
			}			 
		}else if(op==3){
			if(Personas.size()>=2){
				int first,second;
				printHumans(Personas);
				cout<<"Ingrese posicion en la base de datos de la primera persona a tener setso setsi salvaje:"<<endl;
				cin>>first;
				printHumans(Personas);
				cout<<"Ingrese posicion en la base de datos de la segunda persona a tener setso setsi salvaje:"<<endl;
				cin>>second;
				if((Personas.at(first).genero&&!Personas.at(second).genero)||(!Personas.at(first).genero&&Personas.at(second).genero)){
					persona hijo=(Personas.at(first)*Personas.at(second));
					Personas.push_back(hijo);
				}else{
					cout<<"GOD SHALL DELIVER HIS HOLY JUDGEMENT UPON THE FAGS"<<endl;
				}
			}else{
				cout<<"No hay suficientes personas para tener sexo salvaje del duro, agregue mas personas"<<endl;
			}
		}else if(op==4){
			continuar=false;
		}

	}
	return 0;
}


void printHumans( vector<persona>& Personas){
	for(int i=0;i<Personas.size();i++){
		cout<<i<<" - "<<Personas.at(i).toString()<<endl;	
	}

}
