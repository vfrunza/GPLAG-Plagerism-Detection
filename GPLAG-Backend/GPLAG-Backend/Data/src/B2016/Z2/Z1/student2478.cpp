#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

enum class Polje{
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

enum class Smjerovi{
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status{
	NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka{
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Komande{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};


typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	
	Tabla T(n, std::vector<Polje>(n,Polje::Prazno));
	
	for(int i(0); i < mine.size(); i++)
		if(mine[i].size() != 2) throw std::domain_error ("Ilegalan format zadavanja mina");
		
		for(int i(0); i < mine.size(); i++){
			for(int j(0); j < mine[i].size(); j++){
				if(mine[i][j] > n) throw std::domain_error("Ilegalne pozicije mina");
			}
		}
		
		int indeks(0);
		
		for(int i(0); i < mine.size(); i++){
			T[mine[i][indeks]][mine[i][indeks+1]] = Polje::Mina;
		}
		T[0][0] = Polje::Prazno;
		
return T;
}

int bMina(const Tabla &polja, int x, int y){
	
	int Brojac_mina(0);
	
	for(int i(x-1); i < x+2; i++){
		for(int j(y-1); j < y+2; j++){
			if(i < 0 || i > polja.size() -1 || j < 0 || j > polja.size() -1)continue;
			if(i == x && j == y)continue;
			if(polja[i][j] == Polje::Mina) Brojac_mina++;
		}
	}
	return Brojac_mina;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	
	if(x < 0 || x >= polja.size() || y < 0 || y >= polja.size()){
		std::string s = "Polje (" + std::to_string(x) + "," + std::to_string(y) +") ne postoji";
	throw std::domain_error(s);
	}
	std::vector<std::vector<int>> Okolina;
	std::vector<int> red;
	
	for(int i(x-1); i < x+2; i++){
		red.resize(0);
		for(int j(y-1); j < y+2; j++){
			if(i >= 0 && i < polja.size() && j >= 0 && j < polja.size())
			red.push_back(bMina(polja,i,j));
			else if(i <0 || i >= polja.size() || j < 0 || j >=polja.size())
			red.push_back(0);
		}
		Okolina.push_back(red);
	}
	return Okolina;
}
void BlokirajPolje (Tabla &polja, int x, int y){
	
	if(x >=  polja.size() || x < 0 || y >= polja.size() || y < 0){
		std::string s = "Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji";
		throw std::domain_error(s);
	};
		
	if(polja[x][y] == Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;
	else if(polja[x][y] == Polje::Posjeceno) polja[x][y] = Polje::BlokiranoPosjeceno;
	else if(polja[x][y] == Polje::Mina) polja[x][y] = Polje::BlokiranoMina;
}



void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x >= polja.size() || x < 0 || y >= polja.size() || y < 0){
	std::string s = "Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji";
		throw std::domain_error(s);
	}
	
	if(polja[x][y] == Polje::BlokiranoPrazno) polja[x][y] = Polje::Prazno;
	else if(polja[x][y] == Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;
	else if(polja[x][y] == Polje::BlokiranoMina) polja[x][y] = Polje::Mina; 
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	
	std::vector<std::vector<int>> Kreci_se{{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
	
	polja[x][y] = Polje::Posjeceno;
	
	for(int i(0); i < 8; i++){
		if(int(smjer) == i){
			x += Kreci_se[i][0];
			y += Kreci_se[i][1];
			
			if(x < 0 || x >= polja.size() || y < 0 || y >= polja.size()) throw std::out_of_range("Izlazak van igrace table");
			
			if(polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina)
			throw std::logic_error("Blokirano polje");
			
			if(polja[x][y] == Polje::Mina){
				for(int i(0); i < polja.size(); i++){
					for(int j(0); j < polja.size(); j++){
						polja[i][j] = Polje::Prazno;
					}
				}
				return Status::KrajPoraz;
			}
		}
	}
			
			bool sve_posjeceno(true);
			
			for(int i(0); i < polja.size(); i++){
				for(int j(0); j < polja.size(); j++){
					if(polja[i][j] == Polje::Prazno){
						sve_posjeceno = false;
						break;
					}
					if(!sve_posjeceno)break;
				}
			}
		if(sve_posjeceno) return Status::KrajPobjeda;		
		return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	
	if (novi_x < 0 || novi_x >= polja.size() || novi_y < 0 || novi_y >= polja.size()) throw std::out_of_range("Izlazak van igrace table");
	
	if(polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno || polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoMina)
	throw std::logic_error("Blokirano polje");
	
	if(polja[novi_x][novi_y] == Polje::Mina){
		for(int i(0); i < polja.size(); i++){
			for(int j(0); j < polja.size(); j++){
				polja[i][j] = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	polja[x][y] = Polje::Posjeceno;
	
	bool Sve_posjeceno(true);
	
	for(int i(0); i < polja.size(); i++){
		for(int j(0); 	j < polja.size(); j++){
			if(polja[i][j] == Polje::Prazno){
				Sve_posjeceno = false;
				break;
			}
			if(!Sve_posjeceno)
			break;
		}
		
	}
	if(Sve_posjeceno)return Status::KrajPobjeda;
	
	x = novi_x;
	y = novi_y;
	
	return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka greska){

const char *MoguciIspis[4]{"Nerazumljiva komanda!","Komanda trazi parametar koji nije naveden!","Zadan je suvisan parametar nakon komande!","Parametar komande nije ispravan!"};

for(int i(0); i < 4; i++)
	if(int(greska) == i) std::cout << MoguciIspis[i] << std::endl;
}
/*
bool Provjeri_komandu()
bool UnosKomande(Komande komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::cout << "Unesite komandu: ";
	std::string s;
	std::getline(std::cin, s);
	
	bool istina;
	
	return true;
}*/
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,
Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	
		if(int(komanda) == 0){
			Status temp = Idi(polja, x, y, p_smjer);
			if(temp == Status::KrajPobjeda) std::cout << 
		else if(int(komanda) == 1) Idi(polja, x, y, p_x, p_y);
		else if(int(komanda) == 2) BlokirajPolje(polja, p_x, p_y);
		else if(int(komanda) == 3) DeblokirajPolje(polja, p_x, p_y);
		else if(int(komanda) == 4) PrikaziOkolinu(polja, p_x, p_y);
		else if(int(komanda) ==5) ZavrsiIgru;
		else if(int(komanda) == 6){
			std::cout << "Unesite broj polja: ";
			int broj;
			std::cin >> broj;
			std::complex<int> Poz_mine;
			std::vector<std::vector<int>> Mine;
			
			
		}

}
int main ()
{
	try{
		Tabla T(KreirajIgru(5, {{1,3},{0,2},{3,4},{0,4},{3,1}}));
		std::vector<std::vector<int>> A(PrikaziOkolinu(T,1,1));
		std::cout << std::endl;
	
	
		for(int i(0); i < A.size(); i++){
			for(int j(0); j < A.size(); j++){
				std::cout << A[i][j];
				}
			std::cout << std::endl;
			}
			int a(0), b(0);
			KodoviGresaka greska;
			Smjerovi smjer(Smjerovi::Gore);
			
			BlokirajPolje(T, 9, 4);
			
	}
	catch(std::domain_error izuzetak){
		std::cout << izuzetak.what() << std::endl;
	}
	
	catch(std::out_of_range izuzetak){
		std::cout << izuzetak.what() << std::endl;
	}
	catch(std::logic_error izuzetak){
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}