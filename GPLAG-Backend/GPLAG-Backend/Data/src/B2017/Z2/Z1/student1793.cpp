/*B 2017/2018, Zadaća 2, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include <complex>

using namespace std;

enum class Polje
{
    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

enum class Smjerovi
{
    GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum Status {
    NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka
{
    PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

enum class Komande
{
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};


typedef std::vector<std::vector<Polje>>Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	if(n<=0)throw("Ilegalna velicina");
	for(int i=0; i<mine.size(); i++) {
		if(mine[i].size()!=2) {
			throw domain_error("Ilegalan format zadavanja mina");
		}
		if(mine[i][0]<0 || mine[i][0]>=n || mine[i][1]<0 || mine[i][1]>=n) {
			throw domain_error("Ilegalane pozicije mina");
		}
	}
	Tabla tabla = vector<vector<Polje>>(n,vector<Polje>(n,Polje::Prazno));
	for(int i=0; i<mine.size(); i++) {
		tabla[ mine[i][0] ][ mine[i][1] ] = Polje::Mina;
	}
	return tabla;
}

string int2string(int broj)
{
	string rezultat;
	bool negativan=false;
	if (broj ==0) return "0";
	if(broj<0) {
		negativan = true;
		broj*=-1;
	}
	while(broj!=0) {
		int cifra = broj%10;
		rezultat.push_back(cifra+'0');
		broj/=10;
	}
	for(int i=0,j=rezultat.size()-1; i<j; i++,j--) {
		char temp = rezultat[i];
		rezultat[i] = rezultat[j];
		rezultat[j] = temp;
	}
	if(negativan) rezultat = "-" + rezultat;
	return rezultat;
}

bool ispravneKoordinate(const Tabla& polja,int x, int y)
{
	return x>=0&&x<polja.size()&&y>=0&&y<polja.size();
}

int brojSusjednihMina(const Tabla&polja,int x, int y)
{
	int brojMina=0;
	if(!ispravneKoordinate(polja,x,y)) return 0;

	vector<vector<int>> susjedi = {{x-1,y-1},{x-1,y},{x-1,y+1},{x,y-1},{x,y+1},{x+1,y-1},{x+1,y},{x+1,y+1}};

	for(int i=0; i<susjedi.size(); i++) {
		if(ispravneKoordinate(polja,susjedi[i][0],susjedi[i][1]) ) {
			if(polja[ susjedi[i][0] ][ susjedi[i][1] ] == Polje::Mina) {
				brojMina++;
			}
		}
	}
	return brojMina;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{

	if(!ispravneKoordinate(polja,x,y)) {
		throw domain_error("Polje ("+int2string(x)+","+int2string(y)+" ) ne postoji");
	}

	std::vector<std::vector<int>> okolina (3,std::vector<int>(3));

	vector<vector<int>> susjedi = {
		{x-1,y-1},
		{x-1,y},
		{x-1,y+1},
		{x,y-1},
		{x,y},
		{x,y+1},
		{x+1,y-1},
		{x+1,y},
		{x+1,y+1}
	};

	for(int i=0; i<okolina.size(); i++) {
		for(int j=0; j<okolina.size(); j++) {
			okolina[i][j] = brojSusjednihMina(polja,susjedi[i*3+j][0],susjedi[i*3+j][1]);
		}
	}
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(!ispravneKoordinate(polja,x,y)) {
		throw domain_error("Polje ( "+int2string(x)+","+int2string(y)+" ) ne postoji");
	}
	
	
	if(polja[x][y]==Polje::Prazno) {
		polja[x][y] = Polje::BlokiranoPrazno;
	} else if(polja[x][y]==Polje::Posjeceno) {
		polja[x][y] = Polje::BlokiranoPosjeceno;
	} else if(polja[x][y]==Polje::Mina) {
		polja[x][y] = Polje::BlokiranoMina;
	}
	
	/*cout<<"BLOKIRANJE"<<x<<","<<y<<endl;
	switch(polja[x][y] ) {
	case Polje::Prazno:
		cout<<"Prazno"<<endl;
		break;
	case Polje::Posjeceno:
		cout<<"Posjeceno"<<endl;
		break;
	case Polje::Mina:
		cout<<"Mina"<<endl;
		break;
	case Polje::BlokiranoPrazno:
		cout<<"BlokiranoPrazno"<<endl;
		break;
	case Polje::BlokiranoPosjeceno:
		cout<<"BlokiranoPosjeceno"<<endl;
		break;
	case Polje::BlokiranoMina:
		cout<<"BlokiranoMina"<<endl;
		break;

	}*/
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(!ispravneKoordinate(polja,x,y)) {
		throw domain_error("Polje ("+int2string(x)+","+int2string(y)+" ) ne postoji");
	}
	if(polja[x][y]==Polje::BlokiranoPrazno) {
		polja[x][y] = Polje::Prazno;
	} else if(polja[x][y]==Polje::BlokiranoPosjeceno) {
		polja[x][y] = Polje::Posjeceno;
	} else if(polja[x][y]==Polje::BlokiranoMina) {
		polja[x][y] = Polje::Mina;
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	int novoX=x,novoY=y;
	switch(smjer) {
	case Smjerovi::GoreLijevo :
		novoX--;
		novoY--;
		break;
	case Smjerovi::Gore :
		novoX--;
		break;
	case Smjerovi::GoreDesno :
		novoX--;
		novoY++;
		break;
	case Smjerovi::Lijevo :
		novoY--;
		break;
	case Smjerovi::Desno :
		novoY++;
		break;
	case Smjerovi::DoljeLijevo :
		novoX++;
		novoY--;
		break;
	case Smjerovi::Dolje :
		novoX++;
		break;
	case Smjerovi::DoljeDesno :
		novoX++;
		novoY++;
		break;
	}
	if(!ispravneKoordinate(polja,novoX,novoY)) {
		throw out_of_range("Izlazak van igrace table");
	}

	if(polja[novoX][novoY]==Polje::BlokiranoPosjeceno ||
	        polja[novoX][novoY]==Polje::BlokiranoPrazno ||
	        polja[novoX][novoY]==Polje::BlokiranoMina) {
		throw logic_error("Blokirano polje");
	}

	if(polja[novoX][novoY]==Polje::Mina) {
		for(int i=0; i<polja.size(); i++) {
			for(int j=0; j<polja[i].size(); j++) {
				polja[i][j] = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}

	polja[novoX][novoY]=Polje::Posjeceno;
	polja[x][y]=Polje::Posjeceno;
	x=novoX;
	y=novoY;

	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja[i].size(); j++) {
			if(polja[i][j] == Polje::Prazno)
				return Status::NijeKraj;
		}
	}
	return Status::KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	if(!ispravneKoordinate(polja,novi_x,novi_y)) {
		throw out_of_range("Izlazak van igrace table");
	}
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno ||
	        polja[novi_x][novi_y]==Polje::BlokiranoPrazno ||
	        polja[novi_x][novi_y]==Polje::BlokiranoMina) {
		throw logic_error("Blokirano polje");
	}

	if(polja[novi_x][novi_y]==Polje::Mina) {
		for(int i=0; i<polja.size(); i++) {
			for(int j=0; j<polja[i].size(); j++) {
				polja[i][j] = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}

	polja[novi_x][novi_y]=Polje::Posjeceno;
	polja[x][y]=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;

	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja[i].size(); j++) {
			if(polja[i][j] == Polje::Prazno)
				return Status::NijeKraj;
		}
	}

	return Status::KrajPobjeda;
}

void PrijaviGresku(KodoviGresaka kodGreske)
{
	if(kodGreske == KodoviGresaka::PogresnaKomanda) {
		cout<<"Nerazumljiva komanda!";
	} else if(kodGreske == KodoviGresaka::NedostajeParametar) {
		cout<<"Komanda trazi parametar koji nije naveden!";
	} else if(kodGreske == KodoviGresaka::NeispravanParametar) {
		cout<<"Parametar komande nije ispravan!";
	} else if(kodGreske == KodoviGresaka::SuvisanParametar) {
		cout<<"Zadan je suvisan parametar nakon komande!";
	}
}

int string2int(string s)
{
	for(auto z : s) {
		if(z<'0'||z>'9') throw invalid_argument("Neispravan Parametar");
	}
	int broj=0;
	for(auto z : s) {
		int cifra = z-'0';
		broj = broj*10+cifra;
	}
	return broj;
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y,KodoviGresaka &greska)
{
	string unos;
	string k,p1,p2,ostatak;

	getline(cin,unos);
	int i=0;
	while(unos[i]==' '&&i<unos.size())i++;
	while(unos[i]!=' '&&i<unos.size()) {
		k.push_back(unos[i]);
		i++;
	}
	while(unos[i]==' '&&i<unos.size())i++;
	while(unos[i]!=' '&&i<unos.size()) {
		p1.push_back(unos[i]);
		i++;
	}
	while(unos[i]==' '&&i<unos.size())i++;
	while(unos[i]!=' '&&i<unos.size()) {
		p2.push_back(unos[i]);
		i++;
	}
	while(unos[i]==' '&&i<unos.size())i++;
	while(unos[i]!=' '&&i<unos.size()) {
		ostatak.push_back(unos[i]);
		i++;
	}

	if(k=="P1") {
		if(p1=="GL") {
			smjer = Smjerovi::GoreLijevo;
		} else if(p1=="G") {
			smjer = Smjerovi::Gore;
		} else if(p1=="GD") {
			smjer = Smjerovi::GoreDesno;
		} else if(p1=="D") {
			smjer = Smjerovi::Desno;
		} else if(p1=="DoD") {
			smjer = Smjerovi::DoljeDesno;
		} else if(p1=="Do") {
			smjer = Smjerovi::Dolje;
		} else if(p1=="DoL") {
			smjer = Smjerovi::DoljeLijevo;
		} else if(p1=="L") {
			smjer = Smjerovi::Lijevo;
		} else {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		if(p2!="") {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda=Komande::PomjeriJednoMjesto;

	} else if(k=="P>") {
		if(p1==""||p2=="") {
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(ostatak!="") {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		try {
			int prvi = string2int(p1);
			int drugi = string2int(p2);
			x=prvi;
			y=drugi;

			komanda=Komande::PomjeriDalje;

		} catch(invalid_argument e) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
	} else if(k=="B") {

		if(p1==""||p2=="") {
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(ostatak!="") {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		try {
			int prvi = string2int(p1);
			int drugi = string2int(p2);
			x=prvi;
			y=drugi;
		} catch(invalid_argument e) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		komanda = Komande::Blokiraj;


	} else if(k=="D") {
		if(p1==""||p2=="") {
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		if(ostatak!="") {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		try {
			int prvi = string2int(p1);
			int drugi = string2int(p2);
			x=prvi;
			y=drugi;
		} catch(invalid_argument e) {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		komanda = Komande::Deblokiraj;

	} else if(k=="PO") {
		if(p1!="") {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::PrikaziOkolinu;
	} else if(k=="Z") {
		if(p1!="") {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::ZavrsiIgru;
	} else if(k=="K") {
		if(p1!="") {
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda = Komande::KreirajIgru;
	} else {
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}
	return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x=0, int p_y=0)
{
	try {
		Status s;
		vector<vector<int>> okolina;
		switch(komanda) {
		case Komande::PomjeriJednoMjesto :
			s = Idi(polja, x, y, p_smjer);
			if (s == Status::KrajPobjeda) {
				cout<<"Bravo, obisli ste sva sigurna polja"<<endl;
				IzvrsiKomandu(Komande::ZavrsiIgru,polja,x,y,p_smjer,p_x,p_y);
			} else if(s == Status::KrajPoraz) {
				cout<<"Nagazili ste na minu"<<endl;
				IzvrsiKomandu(Komande::ZavrsiIgru,polja,x,y,p_smjer,p_x,p_y);
			} else {
				cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<endl;
			}
			break;
		case Komande::PomjeriDalje :
			s = Idi(polja,x,y,p_x,p_y);
			if (s == Status::KrajPobjeda) {
				cout<<"Bravo, obisli ste sva sigurna polja"<<endl;
				IzvrsiKomandu(Komande::ZavrsiIgru,polja,x,y,p_smjer,p_x,p_y);
			} else if(s == Status::KrajPoraz) {
				cout<<"Nagazili ste na minu"<<endl;
				IzvrsiKomandu(Komande::ZavrsiIgru,polja,x,y,p_smjer,p_x,p_y);
			} else {
				cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")"<<endl;
			}
			break;
		case Komande::Blokiraj :
			BlokirajPolje(polja, p_x, p_y);
			break;
		case Komande::Deblokiraj :
			DeblokirajPolje(polja, p_x, p_y);
			break;
		case Komande::PrikaziOkolinu :
			okolina = PrikaziOkolinu(polja, x, y);
			for(int i=0; i<okolina.size(); i++) {
				for(int j=0; j<okolina[i].size(); j++) {
					cout<<okolina[i][j]<<" ";
				}
				cout<<endl;
			}
			break;
		case Komande::ZavrsiIgru :
			for(int i=0; i<polja.size(); i++) {
				for(int j=0; j<polja[i].size(); j++) {
					polja[i][j]=Polje::Prazno;
				}
			}
			throw runtime_error("Igra zavrsena");
			break;
		case Komande::KreirajIgru : {
			int broj_polja;
			string recenica;
			vector<vector<int>> mine;
			complex<int>pomocna;
			while(true) {
				cout<<"Unesite broj polja: ";
				cin>>broj_polja;
				if(!cin) {
					cout<<"Greska, unesite ponovo!"<<endl;
					cin.clear();
					cin.ignore(1000,'\n');
				} else if(broj_polja<=0) {
					cout<<"Greska, unesite ponovo!"<<endl;
				} else {
					break;
				}

			}

			cout<<"Unesite pozicije mina: ";
			while(true) {
				cin>>pomocna;
				if(!cin) {

					cin.clear();
					getline(cin,recenica);
					if(recenica[0]=='.')break;
					cout<<"Greska, unesite ponovo!"<<endl;
				} else {
					int x = pomocna.real();
					int y = pomocna.imag();
					if(x<0||x>=broj_polja||y<0||y>=broj_polja) {
						cout<<"Greska, unesite ponovo!"<<endl;
						continue;
					}
					vector<int> v;
					v.push_back(x);
					v.push_back(y);
					mine.push_back(v);
				}
			}

			polja = KreirajIgru(broj_polja,mine);
		}

		}
	} catch(domain_error e) {
		cout<<e.what()<<endl;
	} catch(out_of_range e) {
		cout<<e.what()<<endl;
	} catch(logic_error e) {
		cout<<e.what()<<endl;
	}
}

int main()
{
	try {
		Tabla polja;
		Komande komanda;
		Smjerovi smjer;
		int x=0,y=0,p_x,p_y;
		KodoviGresaka greska;
		while(true) {
			cout<<"Unesite komandu: ";
			if( UnosKomande(komanda,smjer,p_x,p_y,greska)) {
				IzvrsiKomandu(komanda, polja,x,y,smjer,p_x,p_y );
			} else {
				PrijaviGresku(greska);
			}
		}
	} catch(runtime_error e) {
		cout<<"Dovidjenja!"<<endl;
	}


	return 0;
}