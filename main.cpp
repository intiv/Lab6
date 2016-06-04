#include "persona.h"
#include<vector>
#include<string>

using std::string;
using std::vector;

int main(int argc,char* argv[]){
	vector<persona> Personas;
	bool continuar=true;
	while(continuar){
		cout<<"1. Agregar persona"<<endl<<"2. Sexo sin proteccion"<<"3. Durex contra el muro"<<"4. Salir"<<endl;
		int op;
		cin>>op;
		string name="", haircolor="",skincolor="",eyecolor="";
		bool gender=true, fertile=true;
		int fert, sex;
		switch(op){
			1:
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
			 break;
			2: 
			 
			 break;
			3: break:
			4: break;


		}

	}
	return 0;
}
