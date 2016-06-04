#pragma once
#include<string>

using std::string;
class persona{
	string nombre, colorCabello, colorPiel, colorOjos,gen;
	bool genero, fertil;
 private:
	persona();
	persona(string,bool,string,string,string,bool,string);
	bool operator+(const persona&);
	bool operator*(const persona&);
	


};
