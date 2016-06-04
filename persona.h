#pragma once
#include<string>

using std::string;
class persona{
	string nombre, colorCabello, colorPiel, colorOjos;
	bool genero, fertil;
 private:
	persona();
	persona(string,bool,string,string,string,bool);
	bool operator+(const persona&);
	bool operator*(const persona&);
	


};
