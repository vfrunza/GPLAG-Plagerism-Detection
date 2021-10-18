/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>


enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine){
	Tabla igra (n, std::vector<Polje> (n, Polje::Prazno));
	for(int i=0; i<mine.size(); i++) {
		if(mine[i].size() != 2) throw std::domain_error ("Ilegalan format zadavanja mina");
		else if(mine[i][0]<0 || mine[i][1]<0 || mine[i][0]>n-1 || mine[i][1]>n-1) throw std::domain_error ("Ilegalne pozicije mina");
	}
	
	for(int i=0; i<mine.size(); i++){
		igra[mine[i][0]][mine[i][1]]=Polje::Mina;
	}
	
	return igra;
	
}


std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	if(x<0 || y<0 || x>polja.size()-1 || y>polja.size()-1) {
		std::string s;
		s="Polje ("+std::to_string(2)+","+std::to_string(3)+") ne postoji";
		throw std::domain_error (s);
	}
	
	
}

int main ()
{
	/*std::string s;
	s="Polje ("+std::to_string(2)+","+std::to_string(3)+") ne postoji";
	try{
		throw std::domain_error(s);
	}
	catch(std::domain_error iz){
		std::cout<<iz.what()<<std::endl;
	}*/
	return 0;
}