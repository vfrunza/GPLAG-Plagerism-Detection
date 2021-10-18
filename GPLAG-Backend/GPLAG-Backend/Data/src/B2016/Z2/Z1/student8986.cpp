#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

enum class Polje {
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Lijevo, Desno=5, DoljeLijevo, Dolje, DoljeDesno
};

enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka{
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokira, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

int brojac_praznih;

typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<std::vector<int>> Matrica;

//n>=0 uslov treba dodat
Tabla KreirajIgru(int n, const Matrica &mine) {
	for(int i(0); i<mine.size(); i++) {
		if(mine[i].size()!=2)
			throw std::domain_error ("Ilegalan format zadavanja mina");
			
	}
	
	Tabla T;
	T.resize(n);
	for(int i(0); i<T.size(); i++)
		T[i].resize(n);
		
	for(int i(0); i<T.size(); i++) {
		for(int j(0); j<T[0].size(); j++)
			T[i][j]=Polje::Prazno;
	}
	for(int i=0; i<mine.size(); i++) {
		if(mine[i][0]>=n || mine[i][0]<0 || mine[i][1]>=n || mine[i][1]<0)
			throw std::domain_error ("Ilegalne pozicije mina");
		else
			T[mine[i][0]][mine[i][1]]=Polje::Mina;
	}
	brojac_praznih=n*n-int(mine.size());
	return T;
}

Matrica PrikaziOkolinu(const Tabla &polja, int x, int y) {
	if(x>=polja.size() || x<0 || y>polja.size() || y<0) {
		std::string s("Polje (");
		s+=std::to_string(x);
		s+=",";
		s+=std::to_string(y);
		s+=") ne postoji";
		throw std::domain_error (s);
	}
	Matrica m(3, std::vector<int> (3,0));
	
	int R(0), K(0);
	for(int i=x-1; i<=x+1; i++) {
		for(int j=y-1; j<=y+1; j++) {
			int brojac(0);
			for(int a=i-1; a<=i+1; a++) {
				for(int b=j-1; b<=j+1; b++) {
					try {
						if(polja.at(a).at(b)==Polje::Mina)
							brojac++;
					}
					catch(...) {
						continue;
					}
				}
			}try {
			if(polja.at(i).at(j)==Polje::Mina)
				brojac--;
			m.at(R).at(K)=brojac; }
			catch(...) {}
			K++;
			if(K==3) {
				R++;
				K=0;
			}
		}
	}
	
	return m;
	
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	try {
	for(int i=0; i<3; i++) {
		if(int(polja.at(x).at(y))==i)
			polja.at(x).at(y)=Polje(i+3);
	}
	}
	catch(...) {
		std::string s("Polje (");
		s+=std::to_string(x);
		s+=",";
		s+=std::to_string(y);
		s+=") ne postoji";
		throw std::domain_error (s);
	}
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	try {
	for(int i=3; i<6; i++) {
		if(int(polja.at(x).at(y))==i)
			polja.at(x).at(y)=Polje(i-3);
	}
	}
	catch(...) {
		std::string s("Polje (");
		s+=std::to_string(x);
		s+=",";
		s+=std::to_string(y);
		s+=") ne postoji";
		throw std::domain_error (s);
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	int pomx=x-1, pomy=y-1;
	for(int i=0; i<3; i++) {
		
		for(int j=0; j<3; j++) {
			if(int(smjer)==i*3+j) {
				if(pomx>=polja.size() || pomx<0 || pomy<0 || pomy>=polja.size())
					throw std::out_of_range ("Izlazak van igrace table");
				if(polja.at(pomx).at(pomy)==Polje::BlokiranoPosjeceno || polja.at(pomx).at(pomy)==Polje::BlokiranoPrazno || polja.at(pomx).at(pomy)==Polje::BlokiranoMina)
					throw std::logic_error ("Blokirano polje");
				if(polja.at(pomx).at(pomy)==Polje::Mina) {
					polja=Tabla(polja.size(), std::vector<Polje> (polja.size(), Polje::Prazno));
					return Status::KrajPoraz;
				}
				polja.at(x).at(y)=Polje::Posjeceno;
				
				x=pomx;
				y=pomy;
				brojac_praznih--;
				break;
			}
			pomy++;
			if(j==2) {
				pomx++;
				pomy=y-1;
			}
			
		}
	}
	if(brojac_praznih==1)
		return Status::KrajPobjeda;
	
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if(novi_x>=polja.size() || novi_x<0 || novi_y<0 || novi_y>=polja.size())
		throw std::out_of_range ("Izlazak van igrace table");
	if(polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina)
		throw std::logic_error ("Blokirano polje");
	if(polja.at(novi_x).at(novi_y)==Polje::Mina) {
		polja=Tabla(polja.size(), std::vector<Polje> (polja.size(), Polje::Prazno));
		return Status::KrajPoraz;
	}
	polja.at(x).at(y)=Polje::Posjeceno;
				
	x=novi_x;
	y=novi_y;
	brojac_praznih--;
	if(brojac_praznih==1)
		return Status::KrajPobjeda;
	
	return Status::NijeKraj;
	
}

void PrijaviGresku(KodoviGresaka kod) {
	std::vector<std::string> prijave { {"Nerazumljiva komanda!"}, {"Komanda trazi parametar koji nije naveden!"}, {"Zadan je suvisan parametar nakon komande!"}, {"Parametar komande nije ispravan!"} };
	
	for(int i=0; i<prijave.size(); i++) {
		if(int(kod)==i)
			std::cout<<prijave[i]<<std::endl;
	}
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::vector<std::string> komande { {"P1"}, {"P>"}, {"B"}, {"D"}, {"PO"}, {"Z"}, {"K"} };
	std::vector<std::string> parametri { {"GL"}, {"G"}, {"GD"}, {"L"}, {""}, {"D"}, {"DoL"}, {"Do"}, {"DoD"} };
	std::string k, unos, p;
	std::getline(std::cin, unos);
	int i;
	for(i=0; i<unos.length(); i++) {
		if(unos[i]==' ') continue;
		k+=unos[i];
		for(int j=0; j<komande.size(); j++) {
			if(k==komande[j]) {
				komanda=Komande(j);
				break;
			}
		}
		
	}
	if(i==unos.length()) {
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	if(int(komanda)>3)
		return true;
	else {
		if(int(komanda)==0) {
			for(;i<unos.length(); i++) {
				if(unos[i]==' ') continue;
				p+=unos[i];
				for(int j=0; j<parametri.size(); j++) {
					if(j==4) continue;
					if(p==parametri[j]) {
						smjer=Smjerovi(j);
						break;
					}
				}
			}
		}
	}
	return true;
	
}


int main ()
{
int n(4);	
Tabla T;
Matrica mine{{0,0}, {0,2},{1,3} };
try{
	
T=KreirajIgru(n, mine);
BlokirajPolje(T, 0,1);

int x(2), y(2);
Status nesto;
nesto=Idi(T, x,y, Smjerovi::Gore);
std::cout<<x<<" "<<y<<std::endl;
for(int i=0; i<n; i++) {
	for(int j=0; j<n; j++)
		std::cout<<int(T[i][j])<<" ";
	std::cout<<std::endl;
}
Matrica m(PrikaziOkolinu(T,0,1));
for(int i=0; i<3; i++) {
		for(int j=0; j<3; j++)
			std::cout<<m[i][j]<<" ";
		std::cout<<std::endl;
	}
PrijaviGresku(KodoviGresaka::NedostajeParametar);

}
catch(std::domain_error greska) {
	std::cout<<greska.what();
}
catch(std::out_of_range greska) {
	std::cout<<greska.what();
}
catch(std::logic_error greska) {
	std::cout<<greska.what();
}

	return 0;
}