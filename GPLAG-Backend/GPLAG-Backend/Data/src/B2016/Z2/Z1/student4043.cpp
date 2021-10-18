/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina };
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo };
enum class Status { NijeKraj, KrajPoraz, KrajPobjeda };
enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar };
enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	Tabla tabla(n, std::vector<Polje> (n,Polje::Prazno));
	for(int i(0);i<mine.size();i++) {
		if(mine[i].size()!=2) throw std::domain_error ("Ilegalan format zadavanja mina");
		for(int j(0);j<mine[i].size();j++) {
			if(mine[i][j]<0 || mine[i][j]>=n) throw std::domain_error ("Ilegalne pozicije mina");
		}
	}
	for(int i(0);i<n;i++) {
		for(int j(0);j<n;j++) {
			for(int k(0);k<mine.size();k++) {
				if(mine[k][0]==i && mine[k][1]==j) tabla[i][j]=Polje::Mina;
			}
		}
	}
	return tabla;
}

//PRIKAZI OKOLINU

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	if(x<0 || x>=polja.size() || y<0 || y>=polja[0].size()) throw std::domain_error ("Polje (x,y) ne postoji");
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if(x<0 || x>=polja.size() || y<0 || y>=polja[0].size()) throw std::domain_error ("Polje (x,y) ne postoji");
	for(int i(0);i<polja.size();i++) {
		for(int j(0);j<polja[i].size();j++) {
			if(i==x && y==j) {
				if(polja[i][j]==Polje::Prazno) polja[i][j]=Polje::BlokiranoPrazno;
				if(polja[i][j]==Polje::Posjeceno) polja[i][j]=Polje::BlokiranoPosjeceno;
				if(polja[i][j]==Polje::Mina) polja[i][j]=Polje::BlokiranoMina;
			}
		}
	}
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	if(x<0 || x>=polja.size() || y<0 || y>=polja[0].size()) throw std::domain_error ("Polje (x,y) ne postoji");
	for(int i(0);i<polja.size();i++) {
		for(int j(0);j<polja[i].size();j++) {
			if(i==x && j==y) {
				if(polja[i][j]==Polje::BlokiranoPosjeceno) polja[i][j]=Polje::Posjeceno;
				if(polja[i][j]==Polje::BlokiranoPrazno) polja[i][j]=Polje::Prazno;
				if(polja[i][j]==Polje::BlokiranoMina) polja[i][j]=Polje::Mina;
			}
		}
	}
}

//IDI I IDI

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	Status status=Status::NijeKraj;
	polja[x][y]=Polje::Posjeceno;
	if(smjer==Smjerovi::GoreLijevo) { x-=1; y-=1; }
	if(smjer==Smjerovi::Gore) x-=1;
	if(smjer==Smjerovi::GoreDesno) { x-=1; y+=1; }
	if(smjer==Smjerovi::Desno) y+=1;
	if(smjer==Smjerovi::DoljeDesno) { x+=1; y+=1; }
	if(smjer==Smjerovi::Dolje) x+=1;
	if(smjer==Smjerovi::DoljeLijevo) { x+=1; y-=1; }
	if(smjer==Smjerovi::Lijevo) y-=1;
	if(polja[x][y]==Polje::Mina) {
		status=Status::KrajPoraz;
		for(int i(0);i<polja.size();i++) {
			for(int j(0);j<polja[i].size();j++) {
				polja[i][j]=Polje::Prazno;
			}
		}
	}
	else {
		bool pobjeda=true;
		for(int i(0);i<polja.size();i++) {
			for(int j(0);j<polja[i].size();j++) {
				if(polja[i][j]==Polje::Prazno) {
					pobjeda=false;
					break;
				}
			}
		}
		if(pobjeda) status=Status::KrajPobjeda;
	}
	return status;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	Status status=Status::NijeKraj;
	if(novi_x>=polja.size() || novi_y>=polja[0].size() || novi_x<0 || novi_y<0) throw std::out_of_range ("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
	polja[x][y]=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if(polja[x][y]==Polje::Mina) {
		status=Status::KrajPoraz;
		for(int i(0);i<polja.size();i++) {
			for(int j(0);j<polja[i].size();j++) {
				polja[i][j]=Polje::Prazno;
			}
		}
	}
	else {
		bool pobjeda=true;
		for(int i(0);i<polja.size();i++) {
			for(int j(0);j<polja[i].size();j++) {
				if(polja[i][j]==Polje::Prazno) {
					pobjeda=false;
					break;
				}
			}
		}
		if(pobjeda) status=Status::KrajPobjeda;
	}
	return status;
}
void PrijaviGresku(KodoviGresaka &greska) {
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	if(greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	if(greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	if(greska==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::vector<std::string> komande{"P1","1","P>",">","B","D","PO","Z","K"};
	std::string kom;
	std::getline(std::cin,kom);
	for(int i(0);i<kom.size();i++) {
		for(int j(0);j<komande.size();j++) {
			int k(0);
			std::string temp;
			while(i<kom.size() && k<komande[j].size() && kom[i]==komande[j][k]) {				//napraviti funkciju za preskakanje razmaka
				temp.push_back(kom[i]);
				k++;		
				i++;
			}
			if(temp==komande[j]) {
				switch(j) {
					case 0:
						komanda=Komande::PomjeriJednoMjesto;
						std::vector<std::string> pravci{"GL","G","GD","D","DoD","Do","DoL","L"};
						//za jedno mjesto se pomjeriti
						break;
					case 1:
						komanda=Komande::PomjeriJednoMjesto;
						
						//isto tako
						break;
					case 2:
						komanda=Komande::PomjeriDalje;
						int kor1,kor2;
						//pomjeriti na zadano polje
						break;
					case 3:
						komanda=Komande::PomjeriDalje;
						int kor1,kor2;
						//isto to
						break;
					case 4:
						komanda=Komande::Blokiraj;
						int kor1,kor2;
						//blokiraj polje
						break;
					case 5:
						komanda=Komande::Deblokiraj;
						int kor1,kor2;
						//deblokiraj polje
						break;
					case 6:
						komanda=Komande::PrikaziOkolinu;
						//prikaz okoline
						break;
					case 7:
						komanda=Komande::ZavrsiIgru;
						//zavrsi igru
						break;
					case 8:
						komanda=Komande::KreirajIgru;
						//kreiraj igru
						break;
				}
			}
		}
	}
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0) {
	try {
		
	}
	catch(std::out_of_range izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
	catch(std::logic_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
}
int main ()
{
	try {
		
	}
	catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}

	return 0;
}