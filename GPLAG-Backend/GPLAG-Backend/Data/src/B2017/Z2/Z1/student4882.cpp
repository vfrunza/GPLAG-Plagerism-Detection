#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <limits>

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
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};



typedef std::vector<std::vector<Polje>> Tabla;


typedef std::vector<std::vector<int>> Matrica;



bool JeLiDobarUnos (std::string s) {
	int znakic(0), n=s.length();
	int index_otvorene, index_zatvorene, index_prvog_broja, index_zareza, index_drugog_broja, znak(0);
	for (int i=0; i<s.length(); i++) {
		if (s.at(i)==' ') {
			s.erase(std::begin(s)+i) ;
			i--;
		}
	}
	for (int i=0; i<s.length(); i++) {
		if (s.at(0)=='.') {
			znakic=1;
			break;
		}
		if (s.at(i)!='(' and s.at(i)!=')' and s.at(i)!=',' and !(s.at(i)<='9' and s.at(i)>='0') and s.at(i)!=' ') return false;
		
		if (s.at(i)=='(') index_otvorene=i;
		
		if (s.at(i)==')') index_zatvorene=i;
		
		if (s.at(i)==',') index_zareza=i;
		
		if (s.at(i)<='9' and s.at(i)>='0' and znak==2) return false;
		
		if (s.at(i)<='9' and s.at(i)>='0' and znak==1) {
			index_drugog_broja=i;
			int temp=i;
			while (s.at(i)<='9' and s.at(i)>='0') i++;
			znak=2;
			if (i!=temp) i--;
		}
		
		if (s.at(i)<='9' and s.at(i)>='0' and znak==0) {
			index_prvog_broja=i;
			int temp=i;
			while (s.at(i)<='9' and s.at(i)>='0') i++;
			znak=1;
			if (i!=temp) i--;
		}
		if (i==n-1) break;
	}
	if ((index_otvorene<index_prvog_broja and index_prvog_broja<index_zareza and index_zareza<index_drugog_broja and index_drugog_broja<index_zatvorene) or znakic==1) return true;
	else return false;
}


int PretvoriStringUBroj (std::string s) {
	int n=s.length(), broj(0), suma(0);
	for (int i=0; i<n; i++) {
		suma=suma*10;
		broj=s.at(i)-'0';
		suma+=broj;
		if (i==n-1) break;
	}
	return suma;
}


void Odvadi (std::string s, int &a, int &b) {
	int n=s.length(), znak(0);
	std::string prvi, drugi;
	if (JeLiDobarUnos(s)==0) return;
	if (s.at(0)=='.') return;
	for (int i=0; i<n; i++) {
		if (s.at(i)<='9' and s.at(i)>='0' and znak==1) {
			while (s.at(i)<='9' and s.at(i)>='0') {
				drugi.push_back(s.at(i));
				i++;
			}
			i--;
		}
		
		if (s.at(i)<='9' and s.at(i)>='0' and znak==0) {
			while (s.at(i)<='9' and s.at(i)>='0') {
				prvi.push_back(s.at(i));
				i++;
			}
			i--;
			znak=1;
		}
		if (i==n-1) break;
	}
	a=PretvoriStringUBroj(prvi);
	b=PretvoriStringUBroj(drugi);
}


Tabla KreirajIgru (int n, const Matrica &mine) {
	if (n<=0) throw std::domain_error("Ilegalna velicina");
	for (int i=0; i<mine.size(); i++) {
//		if (mine.at(i).size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		if (mine.at(i).at(0)<0 or mine.at(i).at(0)>=n or mine.at(i).at(1)<0 or mine.at(i).at(1)>=n) throw std::domain_error("Ilegalne pozicije mina");
	}
	Tabla kreiraj;
	kreiraj.resize(n);
	for (int i=0; i<n; i++) {
		kreiraj.at(i).resize(n);
		if (i==(n-1)) break;
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			kreiraj.at(i).at(j)=Polje::Prazno;
			if (j==(n-1)) break;
		}
		if (i==(n-1)) break;
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			for (int k=0; k<mine.size(); k++) {
				if (i==mine.at(k).at(0) and j==mine.at(k).at(1)) kreiraj.at(i).at(j)=Polje::Mina;
				if (k==(mine.size()-1)) break;
			}
			if (j==(n-1)) break;
		}
		if (i==(n-1)) break;
	}
	return kreiraj;
}


Matrica PrikaziOkolinu(const Tabla &polja, int x, int y) {
	Matrica okolis;
	okolis.resize(3);
	std::string jedan, dva;
	int n=polja.size();
	if (x<0 or y<0 or x>=n or y>=n) {
		jedan=std::to_string(x);
		dva=std::to_string(y);
		throw std::domain_error("Polje (" + jedan + "," + dva + ") ne postoji");
	}
	int p=0, q=0;
	for (int i=0; i<okolis.size(); i++) {
		okolis.at(i).resize(3);
	}
	for (int i=x-1; i<=x+1; i++) {
		for (int j=y-1; j<=y+1; j++) {
			int brojac(0), k, l;
			// sad dobijem neki element i moram njegovu okolinu sabrati
			for (k=i-1; k<=i+1; k++) {
				for (l=j-1; l<=j+1; l++) {
					if (k>=0 and l>=0 and k<n and l<n) {
							if (polja.at(k).at(l)==Polje::Mina) brojac++;
					}
				}
			}
			if (polja.at(i).at(j)==Polje::Mina) brojac--;
			okolis.at(p).at(q)=brojac;
			if (q==2) {
				p++;
				q=0;
			}
			else if (q<2) {
				q++;
			}
		}
	}
	return okolis;
}


void BlokirajPolje (Tabla &polja, int x, int y) {
	int n=polja.size();
	std::string jedan, dva;
	if (x<0 or y<0 or x>=n or y>=n) {
		jedan=std::to_string(x);
		dva=std::to_string(y);
		throw std::domain_error("Polje (" + jedan + "," + dva + ") ne postoji");
	}
	
	if (polja.at(x).at(y)==Polje::Posjeceno) polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
	
	if (polja.at(x).at(y)==Polje::Prazno) polja.at(x).at(y)=Polje::BlokiranoPrazno;
	
	if (polja.at(x).at(y)==Polje::Mina) polja.at(x).at(y)=Polje::BlokiranoMina;
}


void DeblokirajPolje (Tabla &polja, int x, int y) {
	int n=polja.size();
	std::string jedan, dva;
	if (x<0 or y<0 or x>=n or y>=n) {
		jedan=std::to_string(x);
		dva=std::to_string(y);
		throw std::domain_error("Polje (" + jedan + "," + dva + ") ne postoji");
	}
	
	if (polja.at(x).at(y)==Polje::BlokiranoPosjeceno) polja.at(x).at(y)=Polje::Posjeceno;
	
	if (polja.at(x).at(y)==Polje::BlokiranoPrazno) polja.at(x).at(y)=Polje::Prazno;
	
	if (polja.at(x).at(y)==Polje::BlokiranoMina) polja.at(x).at(y)=Polje::Mina; 
}


Status Idi (Tabla &polja, int &x, int &y, Smjerovi smjer) {
	int n=polja.size();
	if (smjer==Smjerovi::Gore) {
		if (x<1) throw std::out_of_range("Izlazak van igrace table");
		else if (polja.at(x-1).at(y)==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		else if (polja.at(x-1).at(y)==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");
		else if (polja.at(x-1).at(y)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else {
			polja.at(x).at(y)=Polje::Posjeceno;
			x--;
		}
	}
	
	if (smjer==Smjerovi::Dolje) {
		if (x>=n) throw std::out_of_range("Izlazak van igrace table");
		else if (polja.at(x+1).at(y)==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		else if (polja.at(x+1).at(y)==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");
		else if (polja.at(x+1).at(y)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else {
			polja.at(x).at(y)=Polje::Posjeceno;
			x++;
		}
	}
	
	if (smjer==Smjerovi::Desno) {
		if (y>=n) throw std::out_of_range("Izlazak van igrace table");
		else if (polja.at(x).at(y+1)==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		else if (polja.at(x).at(y+1)==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");
		else if (polja.at(x).at(y+1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else {
			polja.at(x).at(y)=Polje::Posjeceno;
			y++;
		}
	}
	
	if (smjer==Smjerovi::Lijevo) {
		if (y<1) throw std::out_of_range("Izlazak van igrace table");
		else if (polja.at(x).at(y-1)==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		else if (polja.at(x).at(y-1)==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");
		else if (polja.at(x).at(y-1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else {
			polja.at(x).at(y)=Polje::Posjeceno;
			y--;
		}
	}
	
	if (smjer==Smjerovi::GoreDesno) {
		if (y>=n or x<1) throw std::out_of_range("Izlazak van igrace table");
		else if (polja.at(x-1).at(y+1)==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		else if (polja.at(x-1).at(y+1)==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");
		else if (polja.at(x-1).at(y+1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else {
			polja.at(x).at(y)=Polje::Posjeceno;
			y++; 
			x--;
		}
	}
	
	if (smjer==Smjerovi::GoreLijevo) {
		if (y<1 or x<1) throw std::out_of_range("Izlazak van igrace table");
		else if (polja.at(x-1).at(y-1)==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		else if (polja.at(x-1).at(y-1)==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");
		else if (polja.at(x-1).at(y-1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else {
			polja.at(x).at(y)=Polje::Posjeceno;
			y--; 
			x--;
		}
	}
	
	if (smjer==Smjerovi::DoljeDesno) {
		if (y>=n or x>=n) throw std::out_of_range("Izlazak van igrace table");
		else if (polja.at(x+1).at(y+1)==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		else if (polja.at(x+1).at(y+1)==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");
		else if (polja.at(x+1).at(y+1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else {
			polja.at(x).at(y)=Polje::Posjeceno;
			y++; 
			x++;
		}
	}
	
	if (smjer==Smjerovi::DoljeLijevo) {
		if (y<1 or x>=n) throw std::out_of_range("Izlazak van igrace table");
		else if (polja.at(x+1).at(y-1)==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
		else if (polja.at(x+1).at(y-1)==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");
		else if (polja.at(x+1).at(y-1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else {
			polja.at(x).at(y)=Polje::Posjeceno;
			y--; 
			x++;
		}
	}
	int brojac(0);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (polja.at(i).at(j)==Polje::Posjeceno or polja.at(i).at(j)==Polje::Mina) brojac++;
		}
	}
	if (polja.at(x).at(y)==Polje::Mina) return Status::KrajPoraz;
	
	else if (brojac==(n*n)) return Status::KrajPobjeda;
	
	else return Status::NijeKraj;
}


Status Idi (Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	int n=polja.size();
	if (novi_x<0 or novi_x>=n or novi_y<0 or novi_y>=n) throw std::out_of_range("Izlazak van igrace table");
	
	if (polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno) throw std::logic_error("Blokirano polje");
	
	else if (polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno) throw std::logic_error("Blokirano polje");
	
	else if (polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	
	x=novi_x;
	y=novi_y;
	int brojac(0);
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (polja.at(i).at(j)==Polje::Posjeceno or polja.at(i).at(j)==Polje::Mina) brojac++;
		}
	}
	if (polja.at(x).at(y)==Polje::Mina) return Status::KrajPoraz;
	
	else if (brojac==(n*n)) return Status::KrajPobjeda;
	
	else return Status::NijeKraj;
}


void PrijaviGresku (KodoviGresaka greska) {
	if (greska==KodoviGresaka::PogresnaKomanda) std::cout << "Nerazumljiva komanda!" << std::endl;
	
	if (greska==KodoviGresaka::NedostajeParametar) std::cout << "Komanda trazi parametar koji nije naveden!" << std::endl;
	
	if (greska==KodoviGresaka::NeispravanParametar) std::cout << "Parametar komande nije ispravan!" << std::endl;
	
	if (greska==KodoviGresaka::SuvisanParametar) std::cout << "Zadan je suvisan parametar nakon komande!" << std::endl;
}


void IzvrsiKomandu (Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x=0, int p_y=0) {
	int n=polja.size();
	Status varijabla;
	
	if (komanda==Komande::PomjeriJednoMjesto) {
		varijabla=Idi(polja, x, y, p_smjer);
		if (varijabla==Status::KrajPoraz) {
			std::cout << "Nagazili ste na minu";
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			throw std::runtime_error("Igra zavrsena");
		}
		else if (varijabla==Status::KrajPobjeda) {
			std::cout << "Bravo, obisli ste sva sigurna polja";
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			throw std::runtime_error("Igra zavrsena");
		}
		else std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")";
	}
	
	if (komanda==Komande::PomjeriDalje) {
		varijabla=Idi(polja, x, y, p_x, p_y);
		if (varijabla==Status::KrajPoraz) {
			std::cout << "Nagazili ste na minu";
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			throw std::runtime_error("Igra zavrsena");
		}
		else if (varijabla==Status::KrajPobjeda) {
			std::cout << "Bravo, obisli ste sva sigurna polja";
			for (int i=0; i<n; i++) {
				for (int j=0; j<n; j++) {
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			throw std::runtime_error("Igra zavrsena");
		}
		else std::cout << "Tekuca pozicija igraca je (" << x << "," << y << ")";
	}
	
	if (komanda==Komande::Blokiraj) BlokirajPolje(polja, x, y);
	
	if (komanda==Komande::Deblokiraj) DeblokirajPolje(polja, x, y);
	
	if (komanda==Komande::PrikaziOkolinu) {
		Matrica moja_okolina=PrikaziOkolinu(polja, x, y);
		for (int i=0; i<3; i++) {
			for (int j=0; j<3; j++) {
				std::cout << moja_okolina.at(i).at(j) << " ";
			}
			std::cout << "\n";
		}
	}
	if (komanda==Komande::ZavrsiIgru) {
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				polja.at(i).at(j)=Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");
	}
	
	if (komanda==Komande::KreirajIgru) {
		int n;
		Matrica vekto;
		std::cout << "Unesite broj polja: ";
		std::cin >> n;
		std::cin.ignore(10000, '\n');
		vekto.resize(n);
		for (int i=0; i<n; i++) {
			vekto.at(i).resize(n);
		}
		std::cout << "Unesite pozicije mina: ";
		int a, b, i(0);
		std::string c;
		while (1) {
			std::getline(std::cin, c);
			if (c.at(0)=='.' and c.length()==1) break;
			Odvadi (c, a, b);
			if (JeLiDobarUnos(c)==0 or (a==0 and b==0) or a>=n or b>=n) {
				std::cout << "Greska, unesite ponovo!" << std::endl;
			}
			else {
				vekto.at(i).at(0)=a;
				vekto.at(i).at(1)=b;
				i++;
			}
		}
		const Matrica vektor=vekto;
		Tabla tabla=KreirajIgru(n, vektor);
	}
}


bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	std::string unos;
	std::getline(std::cin, unos);
	std::string t=unos;
	std::string podstring;
	Tabla polja;
	x=0;
	y=0;
	int brejkao=0, iks, ipsilon;
	int p=unos.length();
/*	for (int i=0; i<p; i++) {
		brejkao=0;
		if (t.at(i)==' ' or t.at(i)=='\n') continue;
		if (t.at(i)=='K') {
			for (int j=i+1; j<p; j++) {
				if (t.at(j)!=' ' or t.at(j)!='\n') {
					PrijaviGresku((KodoviGresaka::SuvisanParametar));
					brejkao=1;
					break;
				}
			}
			podstring=t.at(i);
		}
		else if (t.at(i)=='Z') {
			for (int j=i+1; j<p; j++) {
				if (t.at(j)!=' ' or t.at(j)!='\n') {
					PrijaviGresku(KodoviGresaka::SuvisanParametar);
					brejkao=1;
					break;
				}
			}
			podstring=t.at(i);
		}
		else if (t.at(i)=='P') {
			int temp=i;
			if (i==t.length()-1) break;
			else {
				if (t.at(i+1)=='O') continue;
				else break;
				for (int j=i+1; j<p; j++) {
					if (t.at(j)!=' ' or t.at(j)!='\n') {
						PrijaviGresku(KodoviGresaka::SuvisanParametar);
						brejkao=1;
						break;
					}
				}
			}
			for (int f=temp; f<temp+2; f++) {
				podstring.push_back(t.at(f));
			}
		}
		else if (t.at(i)=='B') {
			int temp=i;
			if (i==t.length()-1) break;
			else {
				while (t.at(temp)==' ')
				temp++;
			}
			if (t.at(temp)<='9' and t.at(temp)>='0') {
				std::string promjena;
				promjena.push_back(t.at(temp));
				iks=PretvoriStringUBroj(promjena);
			}
			if (temp==t.length()-1) greska=KodoviGresaka::NedostajeParametar;
			temp++;
			if (temp==t.length()-1) greska=KodoviGresaka::NedostajeParametar;
			if (t.at(temp)!=' ' and !(t.at(temp)<='9' and t.at(temp)>='0')) greska=KodoviGresaka::SuvisanParametar;
			while (t.at(temp)==' ') {
				temp++;
				if (temp==t.length()-1) greska=KodoviGresaka::NedostajeParametar;
			}
			if (t.at(temp)!=' ' and !(t.at(temp)<='9' and t.at(temp)>='0')) greska=KodoviGresaka::SuvisanParametar;
			if (t.at(temp)<='9' and t.at(temp)>='0') {
				std::string promjena;
				promjena.push_back(t.at(temp));
				ipsilon=PretvoriStringUBroj(promjena);
			}
			podstring=t.at(i);
			x=iks;
			y=ipsilon;
		}
		else if (t.at(i)=='D') {
			int temp=i;
			if (i==t.length()-1) break;
			else {
				while (t.at(temp)==' ')
				temp++;
			}
			if (t.at(temp)<='9' and t.at(temp)>='0') {
				std::string promjena;
				promjena.push_back(t.at(temp));
				iks=PretvoriStringUBroj(promjena);
			}
			if (temp==t.length()-1) greska=KodoviGresaka::NedostajeParametar;
			temp++;
			if (temp==t.length()-1) greska=KodoviGresaka::NedostajeParametar;
			if (t.at(temp)!=' ' and !(t.at(temp)<='9' and t.at(temp)>='0')) greska=KodoviGresaka::SuvisanParametar;
			while (t.at(temp)==' ') {
				temp++;
				if (temp==t.length()-1) greska=KodoviGresaka::NedostajeParametar;
			}
			if (t.at(temp)!=' ' and !(t.at(temp)<='9' and t.at(temp)>='0')) greska=KodoviGresaka::SuvisanParametar;
			if (t.at(temp)<='9' and t.at(temp)>='0') {
				std::string promjena;
				promjena.push_back(t.at(temp));
				ipsilon=PretvoriStringUBroj(promjena);
			}
			podstring=t.at(i);
			x=iks;
			y=ipsilon;
		}
		else greska=KodoviGresaka::PogresnaKomanda;
		if (brejkao==1) break;
	}*/
	for (int i=0; i<t.size(); i++) {
		if (t.at(i)==' ') {t.erase(std::begin(t)+i); i--;}
	}
	podstring=t;
	std::vector<std::string> komandos={ {"K"}, {"Z"}, {"PO"}, {"P<"}, {"P1"}, {"B"}, {"D"} };
	if (podstring==komandos.at(0)) {
		komanda=Komande::KreirajIgru;
		IzvrsiKomandu(komanda, polja, x, y);
		return true;
	}
	else if (podstring==komandos.at(1)) {
		komanda=Komande::ZavrsiIgru;
		IzvrsiKomandu(komanda, polja, x, y);
		return true;
	}
	else if (podstring==komandos.at(2)) {
		komanda=Komande::PrikaziOkolinu;
		IzvrsiKomandu(komanda, polja, x, y);
		return true;
	}
	else if (podstring==komandos.at(3)) {
		komanda=Komande::PomjeriDalje;
		IzvrsiKomandu(komanda, polja, x, y);
		return true;
	}
	else if (podstring==komandos.at(4)) {
		komanda=Komande::PomjeriJednoMjesto;
		IzvrsiKomandu(komanda, polja, x, y);
		return true;
	}
	else if (podstring==komandos.at(5)) {
		komanda=Komande::Blokiraj;
		IzvrsiKomandu(komanda, polja, x, y);
		return true;
	}
	else if (podstring==komandos.at(6)) {
		komanda=Komande::Deblokiraj;
		IzvrsiKomandu(komanda, polja, x, y);
		return true;
	}
	else return false;
}


int main ()
{
	int n, x, y;
	Smjerovi smjer;
	KodoviGresaka greska;
	Komande komanda;
	std::string k;
	try {
		for(;;) {
			std::cout << "Unesite komandu: ";
			UnosKomande(komanda, smjer, x, y, greska);
		}
	}
	catch (std::domain_error izuzetak1) {
		std::cout << izuzetak1.what() << std::endl;
	}
	catch (std::out_of_range izuzetak2) {
		std::cout << izuzetak2.what() << std::endl;
	}
	catch (std::logic_error izuzetak3) {
		std::cout << izuzetak3.what() << std::endl;
	}
	catch (std::runtime_error izuzetak4) {
		std::cout << izuzetak4.what() << std::endl;
	}
	return 0;
}
