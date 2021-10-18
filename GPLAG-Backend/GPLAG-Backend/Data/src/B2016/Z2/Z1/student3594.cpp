
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>


enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

enum class Smjerovi {
 GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status {
 NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka {
 PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};



typedef std::vector<std::vector<Polje>> Tabla;

void PrijaviGresku(KodoviGresaka greska){
	if(greska == KodoviGresaka::PogresnaKomanda)
		std::cout << "Nerazumljiva komanda!"<<std::endl;
	if(greska == KodoviGresaka::NedostajeParametar)
		std::cout << "Komanda trazi parametar koji nije naveden!"<<std::endl;
	if(greska == KodoviGresaka::NeispravanParametar)
		std::cout << "Parametar komande nije ispravan!"<<std::endl;
	if(greska == KodoviGresaka::SuvisanParametar)
		std::cout << "Zadan je suvisan parametar nakon komande!"<<std::endl;
}

Tabla KreirajIgru (int n, const std::vector<std::vector<int>> &mine){

	
	for(int i=0; i<mine.size(); i++){
		int brojac(0);
		
		for(int j=0; j<mine[i].size(); j++){
			brojac++;
			if(mine[i][j] >= n){
				throw std::domain_error ("Ilegalne pozicije mina");
			}
		}
		
		if(brojac != 2 ){
			throw std::domain_error ("Ilegalan format zadavanja mina");
		}
	}


	Tabla a;
	a.resize(n);

	for(int i=0; i<n; i++){
		a[i].resize(n);
		for(int j=0; j<n; j++){
			a[i][j]=(Polje::Prazno);						
		}
	}
	int prvi, drugi;
	
	for(int i=0; i<mine.size(); i++){
			prvi = mine[i][0];
			drugi = mine[i][1] ;
			a[prvi][drugi] = Polje::Mina;
	}
	
	return a;
}

int IspitajOkolinu(Tabla polja, int x, int y){
	int brojac(0);
	std::vector<std::vector<int>> smijer{ {-1,-1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}; 
	
	for(int k=0; k<smijer.size(); k++){
		int i = x + smijer[k][0];
		int j = y + smijer[k][1];
		
		if(i >= 0 && i < polja.size()-1 && j >= 0 && j < polja[i].size()-1){
			if(polja[i][j] == Polje::Mina)
				brojac++;
		}
	}
	return brojac;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
		
	if(x >= polja.size() || y >= polja[0].size() || y < 0 || x < 0){
	std::string greska1("Polje ("), greska2(","), greska3(") ne postoji"), greska_x(std::to_string(x)), greska_y(std::to_string(y));
	std::string greska = greska1 + greska_x + greska2 + greska_y + greska3;
		throw std::domain_error(greska);
	}
	Tabla polja_kopija = polja;
	std::vector<std::vector<int>> Okolina ;
	std::vector<std::vector<int>> smijer{ {-1,-1}, {-1, 0}, {-1, 1}, {0, -1}, {0,0},  {0, 1}, {1, -1}, {1, 0}, {1, 1}};
	std::vector<int> temp;
	
			
			for(int k=0; k<smijer.size(); k++){
						int a = x + smijer[k][0];
						int b = y + smijer[k][1];
						int brojac = IspitajOkolinu(polja_kopija, a, b);
						temp.push_back(brojac);
						if(temp.size() == 3){
							Okolina.push_back(temp);
							temp.clear();
						}
			}
	
	return Okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	
	if(x >= polja.size() || y >= polja[0].size() || y < 0 || x < 0){
	std::string greska1("Polje ("), greska2(","), greska3(") ne postoji"), greska_x(std::to_string(x)), greska_y(std::to_string(y));
	std::string greska = greska1 + greska_x + greska2 + greska_y + greska3;
		throw std::domain_error(greska);
	}
	
	if(polja[x][y] == Polje::Prazno)
		polja[x][y] = Polje::BlokiranoPrazno;
	if(polja[x][y] == Polje::Posjeceno)
		polja[x][y] = Polje::BlokiranoPosjeceno;
	if(polja[x][y] == Polje::Mina)
		polja[x][y] = Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	
	if(x >= polja.size() || y >= polja[0].size() || y < 0 || x < 0){
	std::string greska1("Polje ("), greska2(","), greska3(") ne postoji"), greska_x(std::to_string(x)), greska_y(std::to_string(y));
	std::string greska = greska1 + greska_x + greska2 + greska_y + greska3;
		throw std::domain_error(greska);
	}
	
	if(polja[x][y] == Polje::BlokiranoPrazno)
		polja[x][y] = Polje::Prazno;
	if(polja[x][y] == Polje::BlokiranoPosjeceno)
		polja[x][y] = Polje::Posjeceno;
	if(polja[x][y] == Polje::BlokiranoMina)
		polja[x][y] = Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	
	if(x+1 >= polja.size() || y+1 >= polja.size() || x < 0 || y < 0 )
		throw std::out_of_range("Izlazak van igrace table");
	
	if (x == 0 && y == 0 && (smjer != Smjerovi::Desno && smjer != Smjerovi::Dolje && smjer != Smjerovi::DoljeDesno))
		throw std::out_of_range("Izlazak van igrace table");
		
	if(smjer == Smjerovi::Gore){
		if(polja[x-1][y] == Polje::BlokiranoPrazno || polja[x-1][y] == Polje::BlokiranoMina || polja[x-1][y] == Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		x = x-1;
	}
	if(smjer == Smjerovi::Desno){
		if(polja[x][y+1] == Polje::BlokiranoPrazno || polja[x][y+1] == Polje::BlokiranoMina || polja[x][y+1] == Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		y = y+1;
	}
	if(smjer == Smjerovi::Dolje){
		if(polja[x+1][y] == Polje::BlokiranoPrazno || polja[x+1][y] == Polje::BlokiranoMina || polja[x+1][y] == Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		x = x+1;
	}
	if(smjer == Smjerovi::Lijevo){
		if(polja[x][y-1] == Polje::BlokiranoPrazno || polja[x][y-1] == Polje::BlokiranoMina || polja[x][y-1] == Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		y = y-1;
	}
	if(smjer == Smjerovi::GoreLijevo){
		if(polja[x-1][y-1] == Polje::BlokiranoPrazno || polja[x-1][y-1] == Polje::BlokiranoMina || polja[x-1][y-1] == Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		x = x-1;
		y = y-1;
	}
	if(smjer == Smjerovi::GoreDesno){
		if(polja[x-1][y+1] == Polje::BlokiranoPrazno || polja[x-1][y+1] == Polje::BlokiranoMina || polja[x-1][y+1] == Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		x = x-1;
		y = y+1;
	}
	if(smjer == Smjerovi::DoljeDesno){
		if(polja[x+1][y+1] == Polje::BlokiranoPrazno || polja[x+1][y+1] == Polje::BlokiranoMina || polja[x+1][y+1] == Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		x = x+1;
		y = y+1;
	}
	if(smjer == Smjerovi::DoljeLijevo){
		if(polja[x+1][y-1] == Polje::BlokiranoPrazno || polja[x+1][y-1] == Polje::BlokiranoMina || polja[x+1][y-1] == Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		x = x+1;
		y = y-1;
	}
	
	polja[x][y] = Polje::Posjeceno;

	int status(0);	
	if(polja[x][y] == Polje::Mina) status = -1;
	if(polja[x][y] == Polje::Posjeceno) status = 1;
	
	if(status == 0)
		return Status::NijeKraj;
	if(status == -1){
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[i].size(); j++){
				polja[i][j] = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	else{
	bool Kraj(true);
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[i].size(); j++){
				if(polja[i][j] != Polje::Posjeceno){
					Kraj = false;
					break;
				}
			}
		}
	if(Kraj) return Status::KrajPobjeda;
	else return Status::NijeKraj;
	}
}



Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x >= polja.size() || novi_y >= polja[0].size() || novi_x < 0 || novi_y < 0)
		throw std::out_of_range("Izlazak van igrace table");
		
	if(polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno || polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoMina)
		throw std::logic_error("Blokirano polje");
		
	x = novi_x;
	y = novi_y;
	polja[x][y] = Polje::Posjeceno;
	
	
	
	int status(0);	
	if(polja[x][y] == Polje::Mina) status = -1;
	if(polja[x][y] == Polje::Posjeceno) status = 1;
	
	if(status == 0)
		return Status::NijeKraj;
	if(status == -1){
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[i].size(); j++){
				polja[i][j] = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	else{
	bool Kraj(true);
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[i].size(); j++){
				if(polja[i][j] != Polje::Posjeceno){
					Kraj = false;
					break;
				}
			}
		}
	if(Kraj) return Status::KrajPobjeda;
	else return Status::NijeKraj;
	}
}

enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	
	bool kraj (false);
	
	if(komanda == Komande::Blokiraj)
		BlokirajPolje(polja, p_x, p_y);
		
	if(komanda == Komande::Deblokiraj)
		DeblokirajPolje(polja, p_x, p_y);
		
	if(komanda == Komande::PomjeriJednoMjesto){
		Status stat;
		stat = Idi(polja, x, y, p_smjer);
		std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
		if(stat == Status::KrajPobjeda){
			std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			kraj = true;
		}
		if(stat == Status::KrajPoraz){
			std::cout << "Nagazili ste na minu" << std::endl;
			kraj = true;
		}
	}
	
	if(komanda == Komande::PomjeriDalje){
		Status stat;
		stat = Idi(polja, x, y, p_x, p_y);
		std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << std::endl;
		if(stat == Status::KrajPobjeda){
			std::cout << "Bravo, obisli ste sva sigurna polja" << std::endl;
			kraj = true;
		}
		if(stat == Status::KrajPoraz){
			std::cout << "Nagazili ste na minu" << std::endl;
			kraj = true;
		}
	}
	
	if(komanda == Komande::ZavrsiIgru)
		kraj = true;
	
	if(komanda == Komande::PrikaziOkolinu){
		std::vector<std::vector<int>> okolina;
		okolina = PrikaziOkolinu(polja, p_x, p_y);
		for(int i=0; i<okolina.size(); i++){
			for(int j=0; j<okolina[i].size(); j++){
				std::cout << okolina[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	
	if(komanda == Komande::KreirajIgru){
		int n;
		std::cout << "Unesite broj polja: ";
		std::cin >> n;
		std::vector<std::vector<int>> mine (n, std::vector<int> (2,0));
		std::vector<int> temp;
		
		std::cout << "Unesite pozicije mina: ";
		int broj1, broj2;
		char zagrada1, zagrada2, zarez, enter;
		
		std::cin >> zagrada1 >> broj1 >> zarez >> broj2 >> zagrada2;
		std::cin >> enter;
		
		temp.push_back(broj1);
		temp.push_back(broj2);
		mine.push_back(temp);
		temp.clear();
		while(enter != '.'){
			std::cin >> zagrada1 >> broj1 >> zarez >> broj2 >> zagrada2;
			std::cin >> enter;
			temp.push_back(broj1);
			temp.push_back(broj2);
			mine.push_back(temp);
			temp.clear();
		}
		
	
	}
	
	if(kraj == true){
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[i].size(); j++){
				polja[i][j] = Polje::Prazno;
			}
		}
		throw std::runtime_error ("Igra zavrsena");
	}
	
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	
}


int main ()
{	
	/*
	std::cout << "Unesite komandu: ";
	char Komanda;
	std::cin >> Komanda;
	*/
	try{

	}
	catch(const std::exception& e){
		std::cout << e.what();
	}
	
	return 0;
}
