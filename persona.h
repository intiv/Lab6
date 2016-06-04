#pragma once
#include<string>

using std::string;
class persona{
	string colorCabello, colorPiel, colorOjos,genCabello,genOjos,genPiel;
	bool genero, fertil;
 private:
	string nombre;
	persona();
	persona(string,bool,string,string,string,bool);
	string toString();
};
const persona& operator+(const persona&,const persona&);
const persona& operator*(const persona&,const persona&);
