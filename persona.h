#pragma once
#include<string>

using std::string;
class persona{
 public:
	string colorCabello, colorPiel, colorOjos,genCabello,genOjos,genPiel;
	string nombre;
	bool genero, fertil;
	persona();
	persona(string,bool,string,string,string,bool);
	string toString()const;
};
const persona& operator+( persona&,persona&);
const persona& operator*(const persona&,const persona&);
