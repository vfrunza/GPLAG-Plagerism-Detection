#include<iostream>
#include<vector>

enum class Polje{ Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina };
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine){
	
}

void BlokirajPolje (Tabla &polja, int x, int y){
	
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	
}

std::vector<std::vector<int>> Prikazi Okolinu(const Tabla &polja, int x, int y){
	
}

int main ()
{
	
	return 0;
}