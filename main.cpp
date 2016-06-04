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
		cout<<"***************************"<<endl;;
		cout<<"* 1. Agregar persona      *"
	      <<endl<<"* 2. Sexo sin proteccion  *"
	      <<endl<<"* 3. Durex contra el muro *"
	      <<endl<<"* 4. Eliminar Personas	  *"
	      <<endl<<"* 5. Salir		  *"<<
	       endl <<"***************************"
		<<endl<<endl;
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
			cin.ignore();	
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
			cout<<persona(name,gender,haircolor,skincolor,eyecolor,fertile).toString()<<endl;
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
					}else{
						cout<<endl<<"SE SALVARON, NO TUVIERON HIJOS ESOS 2 LECHEROS"<<endl;
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
					if(hijo.colorCabello!=""){
						Personas.push_back(hijo);
						cout<<"NACIO "<<hijo.toString()<<", FELICIDADES AHORA VALIERON PIJA Y SE TIENEN QUE CASAR"<<endl;
					}else{
						cout<<endl<<"SE SALVARON, NO QUEDO PRENIADA"<<endl;
					}
				}else{
					cout<<"GOD SHALL DELIVER HIS HOLY JUDGEMENT UPON THE FAGS"<<endl;
				}
			}else{
				cout<<"No hay suficientes personas para tener sexo salvaje del duro, agregue mas personas"<<endl;
			}
		}else if(op==4){
			if(Personas.size()>0){
				printHumans(Personas);
				int pos;
				cout<<"Ingrese posicion de persona a eliminar. Ingrese "<<Personas.size()<<" para eliminarlos todos"<<endl;
				cin>>pos;
				if(pos==Personas.size()){
					Personas.clear();
				}else{
					Personas.erase(Personas.begin()+pos);
				}
			}else{
				cout<<"No hay personas para eliminar."<<endl;
			}
		}else if(op==5){
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
