/*B 16/17, Zadaća 2, Zadatak 1

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba

*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <complex>


enum class Polje {
	Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina
};
enum class Smjerovi {
	GoreLijevo,Gore,GoreDesno,Desno,DoljeDesno,Dolje,DoljeLijevo,Lijevo
};
enum class Status {
	NijeKraj,KrajPoraz,KrajPobjeda
};
enum class KodoviGresaka {
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};
void PrijaviGresku(KodoviGresaka kodovi) {
	if(kodovi==KodoviGresaka::PogresnaKomanda)
	std::cout<<"Nerazumljiva komanda!"<<std::endl;
	else if(kodovi==KodoviGresaka::NedostajeParametar)
	std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	else if(kodovi==KodoviGresaka::NeispravanParametar)
	std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	else if(kodovi==KodoviGresaka::SuvisanParametar)
	std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}
enum class Komande {
	PomjeriJednoMjesto,PomjeriDalje,Blokiraj,Deblokiraj,PrikaziOkolinu,ZavrsiIgru,KreirajIgru
};
typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine);
void BlokirajPolje(Tabla &polja, int x, int y);
void DeblokirajPolje(Tabla &polja, int x,int y);
//Status Idi(Tabla &polja,int &x,int &y,Smjerovi smjer);
//Status Idi(Tabla &polja,int &x, int &y,int novi_x,int novi_y);
std::vector<std::vector<int>>PrikaziOkolinu(const Tabla &polja,int x,int y);
bool UnosKomande(Komande &komanda,Smjerovi &smjer,int &x, int &y,KodoviGresaka &greska);
void IzvrsiKomandu(Komande komanda,Tabla &polja, int &x, int &y,Smjerovi p_smjer=Smjerovi::Gore,int p_x=0,int p_y=0);
//void ispisiTablu(std::vector<std::vector<Polje>> polja);

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	Tabla igracaTabla(n, std::vector<Polje> (n));
	//ispisiTablu(igracaTabla);
	for(int i=0;i<n;i++)
	   for(int j=0;j<n;j++)
	   		igracaTabla[i][j]=Polje::Prazno;

	for(int i=0;i<mine.size();i++)
	{
		if(mine[i].size() != 2) {
			throw std::domain_error("Ilegalan format zadavanja mina");
		}
		if(mine[i][0]<0 || mine[i][0]>=n || mine[i][1]<0 || mine[i][1]>=n) {
			throw std::domain_error("Ilegalne pozicije mina");
		}
		igracaTabla[mine[i][0]][mine[i][1]]=Polje::Mina;
		//std::cout << mine[i][0] << " " << mine[i][1] << std::endl;
	}
	return igracaTabla;
}


int Max(int a, int b){
	if(a>b)
		return a;
	return b;
}

int Min(int a, int b){
	if(a<b)
		return a;
	return b;
}

int BrojMinaUOkolini(const Tabla &polja,int x, int y) {
	int brojac(0);
	for(int i=Max(x-1, 0);i<=Min(x+1, polja.size()-1);i++) {
		for(int j=Max(y-1, 0);j<=Min(y+1, polja.size()-1);j++) {
			//std::cout << "Polje: (" << i << ", " << j << ")" << std::endl;
			if(polja[i][j]==Polje::Mina && (i!=x || j!=y)) {
				//std::cout << "Brojim minu: (" << i << ", " << j << ")" << std::endl;
				brojac++;
			}
		}
	}

	return brojac;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y) {
	std::vector<std::vector<int>> matrica(3, (std::vector<int>(3)));
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size()) {
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");             //ovdje
	}

	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
				matrica[i][j]=BrojMinaUOkolini(polja,i,j);
		}
	}
	return matrica;
}
void BlokirajPolje(Tabla &polja, int x, int y) {
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size()) {
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");             //ovdje
	}
	if(polja[x][y]!=Polje::BlokiranoPrazno || polja[x][y]!=Polje::BlokiranoMina || polja[x][y]!=Polje::BlokiranoPosjeceno) {
		if(polja[x][y]==Polje::Prazno)
		polja[x][y]=Polje::BlokiranoPrazno;
		if(polja[x][y]==Polje::Posjeceno)
		polja[x][y]=Polje::BlokiranoPosjeceno;
		if(polja[x][y]==Polje::Mina)
		polja[x][y]=Polje::BlokiranoMina;
	}
}
void DeblokirajPolje(Tabla &polja, int x, int y) {
	if(x<0 || x>=polja.size() || y<0 || y>=polja.size()) {
		throw std::domain_error("Polje (" + std::to_string(x) + "," + std::to_string(y) + ") ne postoji");             //ovdje
	}
	if(polja[x][y]!=Polje::Prazno || polja[x][y]!=Polje::Posjeceno || polja[x][y]!=Polje::Mina) {
		if(polja[x][y]==Polje::BlokiranoPrazno)
		polja[x][y]=Polje::Prazno;
		if(polja[x][y]==Polje::BlokiranoPosjeceno)
		polja[x][y]=Polje::Posjeceno;
		if(polja[x][y]==Polje::BlokiranoMina)
		polja[x][y]=Polje::Mina;
	}
	//std::cout << x << " " << y << " " << (int) polja[x][y] << std::endl;
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	polja[x][y]=Polje::Posjeceno;
	if(smjer==Smjerovi::GoreLijevo) {
		if(x-1<0 || y-1<0)
			throw std::out_of_range("Izlazak van igrace table");

		x=x-1;
		y=y-1;
		if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPosjeceno)
			throw std::logic_error("Blokirano polje");
	}
	else if(smjer==Smjerovi::Gore) {
		if(x-1<0)
		throw std::out_of_range("Izlazak van igrace table");

		x=x-1;
		if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPosjeceno)
		throw std::logic_error("Blokirano polje");
	}
	else if(smjer==Smjerovi::GoreDesno) {
		if(x-1<0 || y+1>=polja.size())
		throw std::out_of_range("Izlazak van igrace table");

		x=x-1;
		y=y+1;
		if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPosjeceno)
		throw std::logic_error("Blokirano polje");
	}
	else if(smjer==Smjerovi::Desno) {
		if(y+1>=polja.size())
		throw std::out_of_range("Izlazak van igrace table");

		y=y+1;
		if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPosjeceno)
		throw std::logic_error("Blokirano polje");
	}
	else if(smjer==Smjerovi::DoljeDesno) {
		if(x+1>=polja.size() || y+1>=polja.size())
		throw std::out_of_range("Izlazak van igrace table");

		x=x+1;
		y=y+1;
		if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPosjeceno)
			throw std::logic_error("Blokirano polje");

	}
	else if(smjer==Smjerovi::Dolje) {
		if(x+1>=polja.size())
		throw std::out_of_range("Izlazak van igrace table");

		x=x+1;
		if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPosjeceno)
		throw std::logic_error("Blokirano polje");
	}
	else if(smjer==Smjerovi::DoljeLijevo) {
		if(x+1>=polja.size() || y-1<0)
		throw std::out_of_range("Izlazak van igrace table");

		x=x+1;
		y=y-1;
		if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPosjeceno)
		throw std::logic_error("Blokirano polje");
	}
	else {
		if(y-1<0)
		throw std::out_of_range("Izlazak van igrace table");

		y=y-1;
		if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPosjeceno)
		throw std::logic_error("Blokirano polje");
	}
	if(polja[x][y]==Polje::Mina) {
		for(int i=0;i<polja.size();i++) {
			for(int j=0;j<polja.size();j++) {
				polja[i][j]=Polje::Prazno;

			}
		}
		return Status::KrajPoraz;
	}
	else if(polja[x][y]==Polje::Posjeceno) {
		int brojPosjecenih(0),brojMina(0);
		for(int i=0;i<polja.size();i++) {
			for(int j=0;j<polja.size();j++) {
				if(polja[i][j]==Polje::Posjeceno) {
					brojPosjecenih++;
			}
			if(polja[i][j]==Polje::Mina) {
				brojMina++;
			}
		}
	}
	if(brojPosjecenih==polja.size()*polja.size()-brojMina)
	return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}
Status Idi(Tabla &polja,int &x, int &y,int novi_x,int novi_y) {
	if(novi_x<0 || novi_x>=polja.size() || novi_y<0 || novi_y>=polja.size())
	throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina || polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno)
	throw std::logic_error("Blokirano polje");
	//std::cout << x << " " << y << std::endl;
	polja[x][y]=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	if(polja[x][y]==Polje::Mina) {
		for(int i=0;i<polja.size();i++) {
			for(int j=0;j<polja.size();j++)
			polja[i][j]=Polje::Prazno;
		}
		return Status::KrajPoraz;
	}
	else if(polja[x][y]==Polje::Posjeceno) {
		int brojPosjecenih(0),brojMina(0);
		for(int i=0;i<polja.size();i++) {
			for(int j=0;j<polja.size();j++) {
				if(polja[i][j]==Polje::Posjeceno)
				brojPosjecenih++;
				if(polja[i][j]==Polje::Mina)
				brojMina++;
			}
		}
		if(brojPosjecenih==polja.size()*polja.size()-brojMina)
		return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}

void IspisiString(std::string s){
	for(int i=0; i<s.size(); i++)
	std::cout << s[i];
	std::cout << std::endl;
}

bool UnosKomande(Komande &komanda,Smjerovi &smjer,int &x, int &y,KodoviGresaka &greska) {
	std::string kom="";

	//std::cout << (int) komanda << std::endl;
	//std::cout<<"Unesite komandu: ";
	//std::cin.ignore();
	std::getline(std::cin, kom);
	//std::cin>>kom;
	std::istringstream iss(kom);
	std::string rijec="";
	while(iss>>rijec) { //dok ima rijeci u kom
		if(rijec=="P1") {
			if(iss>>rijec) {
				if(rijec=="GL")
				smjer=Smjerovi::GoreLijevo;
				else if(rijec=="G")
				smjer=Smjerovi::Gore;
				else if(rijec=="GD")
				smjer=Smjerovi::GoreDesno;
				else if(rijec=="Do")
				smjer=Smjerovi::Dolje;
				else if(rijec=="DoD")
				smjer=Smjerovi::DoljeDesno;
				else if(rijec=="DoL")
				smjer=Smjerovi::DoljeLijevo;
				else if(rijec=="L")
				smjer=Smjerovi::Lijevo;
				else if(rijec=="D")
				smjer=Smjerovi::Desno;
				else {
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
				komanda=Komande::PomjeriJednoMjesto;
				return true;
			}
			else {
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
		}
		else if(rijec=="P>") {
			if(iss>>rijec){
		//	IspisiString(rijec);
				if(rijec.size() == 1 && (int)rijec[rijec.size()-1]>=48){
					x = (int) rijec[rijec.size()-1]-48;
					if(iss>>rijec){
						if(rijec.size() == 1 && (int)rijec[rijec.size()-1]>=48){
							y = (int) rijec[rijec.size()-1]-48;
							komanda=Komande::PomjeriDalje;
							return true;
						}else{
							greska=KodoviGresaka::NeispravanParametar;
							return false;
						}
					}else{
						greska=KodoviGresaka::NedostajeParametar;
						return false;
					}
				}else{
					greska=KodoviGresaka::NeispravanParametar;
					return false;
				}
			}else{
				greska=KodoviGresaka::NedostajeParametar;;
					return false;
			}
		}
		else if(rijec=="B") {
			if(iss>>x && iss>>y) {
				komanda=Komande::Blokiraj;
				return true;
			}
			else {
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
		}
		else if(rijec=="D") {
			if(iss>>x && iss>>y) {
				komanda=Komande::Deblokiraj;
				return true;
			}
			else {
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
		}
		else if(rijec=="PO") {
			if(iss>>rijec) {
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			else {
				komanda=Komande::PrikaziOkolinu;
				return true;
			}
		}
		else if(rijec=="Z") {
			if(iss>>rijec) {
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			else {
				komanda=Komande::ZavrsiIgru;
				return true;
			}
		}
		else if(rijec=="K") {
			if(iss>>rijec) {
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			else {
				komanda=Komande::KreirajIgru;
				return true;
			}
		}
		else {
			greska=KodoviGresaka::PogresnaKomanda;
			return false;
		}
	}

}
void IzvrsiKomandu(Komande komanda,Tabla &polja, int &x, int &y,Smjerovi p_smjer, int p_x, int p_y) {
	Status status = Status::NijeKraj;
	try {
		if(komanda==Komande::PomjeriJednoMjesto) {
			status=Idi(polja,x,y,p_smjer);
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
		}
		else if(komanda==Komande::PomjeriDalje) {
			//std::cout << "Prije idi: " << x << " " << y << std::endl;
			status=Idi(polja,x,y,p_x,p_y);
			//std::cout << "Poslije idi: " << x << " " << y << std::endl;
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<std::endl;
		}
		else if(komanda==Komande::Blokiraj) {
			BlokirajPolje(polja,p_x,p_y);
		}
		else if(komanda==Komande::Deblokiraj) {
			DeblokirajPolje(polja,p_x,p_y);
		}
		else if(komanda==Komande::PrikaziOkolinu) {
			std::vector<std::vector<int>> prikazi=PrikaziOkolinu(polja,p_x,p_y);
			for(int i=0;i<prikazi.size();i++) {
				for(int j=0;j<prikazi.size();j++) {
					std::cout<<prikazi[i][j]<<" ";
				}
				std::cout<<std::endl;
			}
		}
		else if(komanda==Komande::ZavrsiIgru) {
			for(int i=0;i<polja.size();i++) {
				for(int j=0;j<polja.size();j++) {
					polja[i][j]=Polje::Prazno;
				}
			}
			throw std::runtime_error("Igra je zavrsena.");
		}
		else if(komanda==Komande::KreirajIgru) {
			int brojPolja(0);
			std::cout<<"Unesite broj polja: ";
			std::string linija="";
			std::getline(std::cin, linija);
			std::istringstream s(linija);
			s>>brojPolja;
			
			char prvaZagrada='(',zarez=',',drugaZagrada=')';
			int minaX(0),minaY(0);
			
			std::string unos="";
			std::vector<std::vector<int>> mine;
		
			std::cout<<"Unesite pozicije mina: ";
			//std::string linija;
			std::getline(std::cin, linija);
			std::istringstream s1(linija);
			s1>>unos;
			//std::cin>>unos;
			while(unos != "."){
				if(unos[0]==prvaZagrada && (int)(unos[1])-48<brojPolja && unos[2]==zarez && (int)(unos[3])-48<brojPolja && (int)(unos[3])-48>=0 && unos[4]==drugaZagrada) {
					minaX = (int)(unos[1])-48;
					minaY = (int)(unos[3])-48;
					
					mine.resize(mine.size()+1);
					mine[mine.size()-1].resize(2);
					
					mine[mine.size()-1][0] = minaX;
					mine[mine.size()-1][1] = minaY;
				}
				else {
					std::cout<<"Greska, unesite ponovo!"<<std::endl;
					//std::cin>>unos;
				}
				std::getline(std::cin, linija);
				std::istringstream s2(linija);
				s2>>unos;
				//std::cin>>unos;
			}

			polja=KreirajIgru(brojPolja, mine);
		}
		if(status==Status::KrajPobjeda) {
			std::cout<<"Bravo, obisli ste sva sigurna polja."<<std::endl;
			for(int i=0;i<polja.size();i++) {
				for(int j=0;j<polja.size();j++)
					polja[i][j]=Polje::Prazno;
			}
			throw std::runtime_error("Igra je zavrsena.");
		}
	}
	catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
	catch(std::logic_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
}
int main() {
	try {
		Tabla polja;
		Komande komanda = Komande::PomjeriJednoMjesto;
      		Smjerovi smjer = Smjerovi::GoreDesno;
      		int x = 0, y = 0;
      		KodoviGresaka greska = KodoviGresaka::SuvisanParametar;
		while(true) {

      		//UnosKomande(komanda, smjer, x, y, greska);
      		std::cout << "Unesite komandu: ";
      		//std::cout << (int) komanda << std::endl;
      		bool igra = UnosKomande(komanda,smjer,x,y,greska);
			if(igra) {
				//std::cout << (int) komanda << std::endl;
				//std::cout << x << " " << y << std::endl;
				IzvrsiKomandu(komanda,polja,x,y,smjer,x,y);

			}else if(komanda == Komande::ZavrsiIgru){
				std::cout<<"Dovidjenja!";
					break;
			}
		}
	}
	catch(std::runtime_error greska) {
		std::cout<<"Dovidjenja!";
	}
	return 0;
}




