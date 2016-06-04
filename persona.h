#pragma once
#include<string>

using std::string;
class persona{
	string nombre, colorCabello, colorPiel, colorOjos,genCabello,genOjos,genPiel;
	bool genero, fertil;
 private:
	persona();
	persona(string,bool,string,string,string,bool);
	const persona& operator+(const persona&);
	const persona& operator*(const persona&);
};
