/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

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
enum class Komande {
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,
 ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<std::vector<int>> Matrica;

bool PostojiPolje(const Tabla &polja, int x, int y) {
	std::string izuzetak;
	for(int i=0; i<polja.size(); i++)
		if(x<0 || y<0 || x>=polja.size() || y>=polja[i].size()) {
			return false;
		}
	return true;
}

int Prebroji(const Tabla &polja, int tx, int ty) {
	int brojac(0);
	for(int i=tx-1; i<tx+2; i++)
		for(int j=ty-1; j<ty+2; j++)
			if(i>=0 && j>=0 &&  i<polja.size() && j<polja.size() && (i != tx || j != ty) &&  (polja[i][j] == Polje::Mina || polja[i][j] == Polje::BlokiranoMina))
				brojac++;
	return brojac;
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	for(int i=0; i<mine.size(); i++)
		if(mine[i].size() != 2)
			throw std::domain_error("Ilegalan format zadavanja mina");
	for(int i=0; i<mine.size(); i++)
		for(int j=0; j<2; j++)
			if(mine[i][j] <0 || mine[i][j] >= n)
				throw std::domain_error("Ilegalne pozicije mina");
	Tabla blok(n,std::vector<Polje>(n, Polje::Prazno));
	for(int i=0; i<mine.size(); i++) 
		blok[mine[i][0]] [mine[i][1]] = Polje::Mina;
	return blok;
}

Matrica PrikaziOkolinu (const Tabla &polja,int x, int y) {
	if(polja.size() == 0 || !PostojiPolje(polja, x, y)) {
		std::string izuzetak;
		izuzetak = "Polje (";
		izuzetak+=std::to_string(x);
		izuzetak+=",";
		izuzetak+=std::to_string(y);
		izuzetak+=") ne postoji";
		throw std::domain_error(izuzetak);
	}
	Matrica okolina;
	std::vector<int> red1;
	red1.push_back(Prebroji(polja, x-1, y-1));
	red1.push_back(Prebroji(polja, x-1, y));
	red1.push_back(Prebroji(polja, x-1, y+1));
	okolina.push_back(red1);
	
	std::vector<int> red2;
	red2.push_back(Prebroji(polja, x, y-1));
	red2.push_back(Prebroji(polja, x, y));
	red2.push_back(Prebroji(polja, x, y+1));
	okolina.push_back(red2);
	
	std::vector<int> red3;
	red3.push_back(Prebroji(polja, x+1, y-1));
	red3.push_back(Prebroji(polja, x+1, y));
	red3.push_back(Prebroji(polja, x+1, y+1));
	okolina.push_back(red3);
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if(polja.size() == 0 || !PostojiPolje(polja, x, y)) {
		std::string izuzetak;
		izuzetak = "Polje (";
		izuzetak+=std::to_string(x);
		izuzetak+=",";
		izuzetak+=std::to_string(y);
		izuzetak+=") ne postoji";
		throw std::domain_error(izuzetak);
	}
	if(polja[x][y] == Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;
	if(polja[x][y] == Polje::Posjeceno) polja[x][y] = Polje::BlokiranoPosjeceno;
	if(polja[x][y] == Polje::Mina) polja[x][y] = Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	if(polja.size() == 0 || !PostojiPolje(polja, x, y)) {
		std::string izuzetak;
		izuzetak = "Polje (";
		izuzetak+=std::to_string(x);
		izuzetak+=",";
		izuzetak+=std::to_string(y);
		izuzetak+=") ne postoji";
		throw std::domain_error(izuzetak);
	}
	if(polja[x][y] == Polje::BlokiranoPrazno) polja[x][y] = Polje::Prazno;
	if(polja[x][y] == Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;
	if(polja[x][y] == Polje::BlokiranoMina) polja[x][y] = Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	int tx(x), ty(y);
	if(smjer == Smjerovi::GoreLijevo) {tx--; ty--;}
	if(smjer == Smjerovi::Gore) {tx--;}
	if(smjer == Smjerovi::GoreDesno) {tx--; ty++;}
	if(smjer == Smjerovi::Desno) {ty++;}
	if(smjer == Smjerovi::DoljeDesno) {tx++; ty++;}
	if(smjer == Smjerovi::Dolje) {tx++;}
	if(smjer == Smjerovi::DoljeLijevo) {tx++; ty++;}
	if(smjer == Smjerovi::Lijevo) {ty--;}
	
	if(polja.size() == 0 || !PostojiPolje(polja, tx, ty))
		throw std::out_of_range("Izlazak van igrace table");
	if(polja[tx][ty] == Polje::BlokiranoMina || polja[tx][ty] == Polje::BlokiranoPrazno || polja[tx][ty] == Polje::BlokiranoPosjeceno)
		throw std::logic_error("Blokirano polje");
	polja[x][y] = Polje::Posjeceno;
	x = tx;
	y = ty;
	if(polja[x][y] == Polje::Mina) {
		for(int i=0; i<polja.size(); i++) 
			for(int j=0; j<polja[i].size(); j++)
				polja[i][j] = Polje::Prazno;
		return Status::KrajPoraz;
	}
	bool kraj(true);
	for(int i=0; i<polja.size(); i++)
		for(int j=0; j<polja[i].size(); j++)
			if(polja[i][j] == Polje::Prazno || polja[i][j] == Polje::BlokiranoPrazno) {
				kraj = false;
				i=polja.size();
				break;
			}
	if(kraj) return Status::KrajPobjeda;
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if(polja.size() == 0 || !PostojiPolje(polja, novi_x, novi_y))
		throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y] == Polje::BlokiranoMina || polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno)
		throw std::logic_error("Blokirano polje");
	if(polja[novi_x][novi_y] == Polje::Mina) {
		for(int i=0; i<polja.size(); i++) 
			for(int j=0; j<polja[i].size(); j++)
				polja[i][j] = Polje::Prazno;
		return Status::KrajPoraz;
	}
	x = novi_x;
	y = novi_y;
	polja[x][y] = Polje::Posjeceno;
	
	bool kraj(true);
	for(int i=0; i<polja.size(); i++)
		for(int j=0; j<polja[i].size(); j++)
			if(polja[i][j] == Polje::Prazno || polja[i][j] == Polje::BlokiranoPrazno) {
				kraj = false;
				i=polja.size();
				break;
			}
	if(kraj) return Status::KrajPobjeda;
	return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka greska) {
	if(greska == KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!\n";
	if(greska == KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!\n";
	if(greska == KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!\n";
	if(greska == KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!\n";
}

bool Cifra(char c) {
	return(c>='0' && c<='9');
}

bool DvaCijelaBroja(int i, std::string unos, int &a, int &b, KodoviGresaka &kod_greske) {
	while(i<unos.length() && unos[i] == ' ')
				i++;
	if(i>= unos.length()) {
		kod_greske = KodoviGresaka::NedostajeParametar;
		return false;
	}
	if(Cifra(unos[i])) {
		int j(i+1);
		while(j < unos.length() && Cifra(unos[j]))
			j++;
		int tmp1 = stoi(unos.substr(i, j-i));
		i=j+1;
		if(!(Cifra(unos[i]))) {
			kod_greske = KodoviGresaka::NeispravanParametar;
				return false;
			}
		int k(i+1);
		while(k < unos.length() && Cifra(unos[k]))
			k++;
		int tmp2 = stoi(unos.substr(i, k-i));
		i=k;
		while(i<unos.length()) {
			if(unos[i] != ' ') {
				kod_greske = KodoviGresaka::SuvisanParametar;
					return false;
			}
			i++;
		}
		a = tmp1;
		b = tmp2;
		return true;
	}
	return false;
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &kod_greske) {
	std::string unos;
	std::getline(std::cin, unos);
	for(int i=0; i<unos.length(); i++) {
		while(i<unos.length() && unos[i] == ' ')
			i++;
		if(unos.substr(i,2) == "P1") {
			i+=2;
			while(i<unos.length() && unos[i] == ' ')
				i++;
			if(i>=unos.length()) {
				kod_greske = KodoviGresaka::NedostajeParametar;
				return false;
			}
			if(unos.substr(i,3) == "DoD" || unos.substr(i,3) == "DoL") {
				int j(i+3);
				while(j<unos.length()) {
					if(unos[j] != ' ') {
						kod_greske = KodoviGresaka::SuvisanParametar;
						i=unos.length();
						break;	
					}
					j++;
				}
				if(unos.substr(i,3) == "DoD") smjer = Smjerovi::DoljeDesno;
				if(unos.substr(i,3) == "DoL") smjer = Smjerovi::DoljeLijevo;
				komanda = Komande::PomjeriJednoMjesto;
				return true;
			}
			else if(unos.substr(i,2) == "GL" || unos.substr(i,2) == "GD" || unos.substr(i,2) == "Do") {
				int j(i+2);
				while(j<unos.length()) {
					if(unos[j] != ' ') {
						kod_greske = KodoviGresaka::SuvisanParametar;
						i=unos.length();
						break;	
					}
					j++;
				}
				if(unos.substr(i,2) == "GL") smjer = Smjerovi::GoreLijevo;
			    if(unos.substr(i,2) == "GD") smjer = Smjerovi::GoreDesno;
			    if(unos.substr(i,2) == "Do") smjer = Smjerovi::Dolje;
			    komanda = Komande::PomjeriJednoMjesto;
			    return true;
			}
			else if(unos[i] == 'G' || unos[i] == 'D' || unos[i] == 'L') {
				int j(i+1);
				while(j<unos.length()) {
					if(unos[j] != ' ') {
						kod_greske = KodoviGresaka::SuvisanParametar;
						return false;
					}
					j++;
				}
				if(unos[i] == 'G') smjer = Smjerovi::Gore;
				if(unos[i] == 'D') smjer = Smjerovi::Desno;
				if(unos[i] == 'L') smjer = Smjerovi::Lijevo;
				komanda = Komande::PomjeriJednoMjesto;
				return true;
			}
			else {
				kod_greske = KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		else if (unos.substr(i,2) == "P>") {
			i+=2;
			while(i<unos.length() && unos[i] == ' ')
				i++;
			if(i>=unos.length()) {
				kod_greske = KodoviGresaka::NedostajeParametar;
				return false;
			}
			if(Cifra(unos[i])) {
				int j(i+1);
				while(j < unos.length() && Cifra(unos[j]))
					j++;
				int tmp1 = stoi(unos.substr(i, j-i));
				i=j+1;
				if(!(Cifra(unos[i]))) {
					kod_greske = KodoviGresaka::NeispravanParametar;
					return false;
				}
				int k(i+1);
				while(k < unos.length() && Cifra(unos[k]))
					k++;
				int tmp2 = stoi(unos.substr(i, k-i));
				i=k;
				while(i<unos.length()) {
					if(unos[i] != ' ') {
						kod_greske = KodoviGresaka::SuvisanParametar;
						return false;
					}
					i++;
				}
				komanda = Komande::PomjeriDalje;
				x = tmp1;
				y = tmp2;
				return true;
			}
			else {
				kod_greske = KodoviGresaka::NeispravanParametar;
				return false;
			}
			break;
		}
		else if(unos[i] == 'B') {
			i++;
			while(i<unos.length() && unos[i] == ' ')
				i++;
			if(i >= unos.length()) {
				kod_greske = KodoviGresaka::NedostajeParametar;
				return false;
			}
			if(Cifra(unos[i])) {
				int j(i+1);
				while(j < unos.length() && Cifra(unos[j]))
					j++;
				int tmp1 = stoi(unos.substr(i, j-i));
				i=j+1;
				if(!(Cifra(unos[i]))) {
					kod_greske = KodoviGresaka::NeispravanParametar;
					return false;
				}
				int k(i+1);
				while(k < unos.length() && Cifra(unos[k]))
					k++;
				int tmp2 = stoi(unos.substr(i, k-i));
				i=k;
				while(i<unos.length()) {
					if(unos[i] != ' ') {
						kod_greske = KodoviGresaka::SuvisanParametar;
						return false;
					}
					i++;
				}
				x = tmp1;
				y = tmp2;
				komanda = Komande::Blokiraj;
				return true;
			}
			break;
		}
		else if(unos[i] == 'D') {
			i++;
			int a, b;
			bool UspjesnoOdradjeno(DvaCijelaBroja(i, unos, a, b, kod_greske));
			if(UspjesnoOdradjeno) {
				x = a;
				y = b;
				komanda = Komande::Deblokiraj;
				return true;
			}
			return false;
			break;
		}
		else if(unos.substr(i,2) == "PO") {
			i+=2;
			while(i<unos.length()) {
				if(unos[i] != ' ') {
					kod_greske = KodoviGresaka::SuvisanParametar;
					return false;
				}
				i++;
			}
			komanda = Komande::PrikaziOkolinu;
			return true;
		}
		else if(unos[i] == 'Z') {
			i++;
			while(i<unos.length()) {
				if(unos[i] != ' ') {
					kod_greske = KodoviGresaka::SuvisanParametar;
					return false;
				}
				i++;
			}
			komanda = Komande::ZavrsiIgru;
			return true;
		}
		else if(unos[i] == 'K') {
			i++;
			while(i<unos.length()) {
				if(unos[i] != ' ') {
					kod_greske = KodoviGresaka::SuvisanParametar;
					return false;
				}
				i++;
			}
			komanda = Komande::KreirajIgru;
			return true;
		}
	}
	kod_greske = KodoviGresaka::PogresnaKomanda;
	return false;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0) {
	try{
		if(komanda == Komande::PomjeriJednoMjesto) {
			Status trenutni_status(Idi(polja, x, y, p_smjer));
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			if(trenutni_status == Status::KrajPobjeda) {
				std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
				IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y);
			}
			if(trenutni_status == Status::KrajPoraz) {
				std::cout<<"Nagazili ste na minu\n";
				IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y);
			}
		}
		if(komanda == Komande::PomjeriDalje) {
			Status trenutni_status(Idi(polja, p_x, p_y, x, y));
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
			if(trenutni_status == Status::KrajPobjeda) {
				std::cout<<"Bravo, obisli ste sva sigurna polja"<<std::endl;
				IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y);}
			if(trenutni_status == Status::KrajPoraz) {
				std::cout<<"Nagazili ste na minu\n";
				IzvrsiKomandu(Komande::ZavrsiIgru, polja, x, y);
			}
		}
		if(komanda == Komande::Blokiraj) BlokirajPolje(polja, x, y);
		if(komanda == Komande::Deblokiraj) DeblokirajPolje(polja, x, y);
		if(komanda == Komande::PrikaziOkolinu) {
			auto tmp(PrikaziOkolinu(polja, x, y));
			for(int i=0; i<tmp.size(); i++) {
				for(int j=0; j<tmp[i].size(); j++)
					std::cout<<tmp[i][j]<<" ";
				std::cout<<std::endl;
			}
		}
		if(komanda == Komande::ZavrsiIgru) {
			for(int i=0; i<polja.size(); i++) 
				for(int j=0; j<polja.size(); j++)
					polja[i][j] = Polje::Prazno;
			throw std::runtime_error("Igra zavrsena");
		}
		if(komanda == Komande::KreirajIgru) {
			std::cout<<"Unesite broj polja: ";
			int n;
			std::cin>>n;
			std::cin.ignore();
			std::cout<<"Unesite pozicije mina: ";
			std::vector<std::vector<int>> mine;
			for(;;){
				bool ZavrsetakUnosa(false);
				int brojac(0);
				std::string unos;
				getline(std::cin, unos);
				if(unos == ".")
					break;
				for(int i=0; i<unos.length(); i++) {
					if(unos[i] != '(' || !Cifra(unos[i+1])) {
						std::cout<<"Greska, unesite ponovo!"<<std::endl;
						break;	
					}
					i++;
					int j(i);
					while(Cifra(unos[j]))
						j++;
					if(j>=unos.length() || unos[j] != ',') {
						std::cout<<"Greska, unesite ponovo!"<<std::endl;
						break;	
					}
					int tmp1(stoi(unos.substr(i, j-i)));
					j++;
					i=j;
					if(i>=unos.length() || !Cifra(unos[i])) {
						std::cout<<"Greska, unesite ponovo!"<<std::endl;
						break;	
					}
					while(Cifra(unos[j]))
						j++;
					if(j>=unos.length() || unos[j] != ')') {
						std::cout<<"Greska, unesite ponovo!"<<std::endl;
					break;	
					}
					int tmp2(stoi(unos.substr(i, j-i)));
					j++;
					while(j != unos.length()) {
						if(unos[j] != ' ') {
							std::cout<<"Greska, unesite ponovo!"<<std::endl;
							break;	
						}
						j++;
					}
					if(tmp1 <0 || tmp2<0 || tmp1>=n || tmp2>=n || (tmp1 == 0 && tmp2==0)) {
						std::cout<<"Greska, unesite ponovo!"<<std::endl;
						break;
					}
					mine.push_back(std::vector<int>{tmp1, tmp2});
					break;
				}
			
			}
		polja = KreirajIgru(n, mine);
		}
	}
	catch(std::domain_error e) {
		std::cout<<e.what()<<std::endl;
	}
	catch(std::out_of_range e) {
		std::cout<<e.what()<<std::endl;
	}
	catch(std::logic_error e) {
		std::cout<<e.what()<<std::endl;
	}
}


int main ()
{
	try{
		Komande komanda;
	 	Smjerovi smjer;
		KodoviGresaka kod_greske;
		Tabla polja;
		int x=0, y=0;
		for(;;) {
			std::cout<<"Unesite komandu: ";
			bool UspjesanUnos(UnosKomande(komanda, smjer, x, y, kod_greske));
			if(UspjesanUnos)
				IzvrsiKomandu(komanda, polja, x, y, smjer);
			else PrijaviGresku(kod_greske);
		}
	}
	catch(std::runtime_error e) {
		std::cout<<"Dovidjenja!";
	}
	
	return 0;
}