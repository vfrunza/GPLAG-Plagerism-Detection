/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <complex>



using namespace std;

enum class Polje { 
	Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina };

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine) {
	Tabla mat;
	mat.resize(n);
	for(int i(0); i<n; i++) mat[i].resize(n);
	for(int i(0); i<mine.size(); i++) {
		for(int j(0); j<mine[i].size(); j++) {
			if(mine[i].size() != 2) throw domain_error ("Ilegalan format zadavanja mina");
			else if(mine[i][j]>=n) throw domain_error ("Ilegalne pozicije mina");
			else if(j==1) {
				mat[mine[i][0]][mine[i][1]] = Polje::Mina;
			}
		}
	}
	return mat;
} 

std::vector<std::vector<int> > PrikaziOkolinu(const Tabla &polja, int y, int x) {
	for(int i(0);i<polja.size();i++) {
		if(x>=polja.size()) throw domain_error ("Polje ("+to_string(y)+","+to_string(x)+") ne postoji");
		if(y>=polja[i].size()) throw domain_error ("Polje ("+to_string(y)+","+to_string(x)+") ne postoji");
	}
	std::vector<std::vector<int> > Polja;
	Polja.resize(polja.size());
	for(int i(0);i<polja.size();i++) Polja[i].resize(polja[i].size());
	for(int i(0);i<polja.size();i++) {
		for(int j(0);j<polja[i].size();j++) {
			if(polja[i][j]==Polje::Mina) Polja[i][j]=1;
		}
	}
	std::vector<std::vector<int> > mat;
	mat.resize(3);
	for(int i(0);i<3;i++) mat[i].resize(3);
	for(int i(-1);i<2;i++) {
		for(int j(-1);j<2;j++) {
				for(int k(-1);k<2;k++) {
					for(int l(-1);l<2;l++) {
						if(k==0 && l==0) continue;
						if(k+x+i<0 || l+y+j<0 || l+y+j>=Polja[0].size() || k+x+i>=Polja.size()) continue;
						mat[i+1][j+1]+=Polja[k+x+i][l+y+j]; //sad vec malo valja :D
					}
				}
		}
	}
	return mat;
}

void BlokirajPolje(Tabla &polja, int x, int y) {
	if(x>=polja[0].size() || y>=polja.size()) throw domain_error ("Polje ("+to_string(x)+","+to_string(y)+") ne postoji");
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	else if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
	else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
}

void DeblokirajPolje(Tabla &polja, int x, int y) {
	if(x>=polja[0].size() || y>=polja.size()) throw domain_error ("Polje ("+to_string(x)+","+to_string(y)+") ne postoji");
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
	else if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
}

enum class Smjerovi {
	GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status {
	NijeKraj, KrajPoraz, KrajPobjeda
};

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer) {
	int pocx=x,pocy=y;
	if(smjer==Smjerovi::GoreLijevo) { 		polja[x][y] = Polje::Posjeceno; x--; y--;  	}
	else if(smjer==Smjerovi::Gore) { 		polja[x][y] = Polje::Posjeceno; x--; 		}
	else if(smjer==Smjerovi::GoreDesno) { 	polja[x][y] = Polje::Posjeceno; x--; y++;	}
	else if(smjer==Smjerovi::Desno) { 		polja[x][y] = Polje::Posjeceno; y++; 		}
	else if(smjer==Smjerovi::DoljeDesno) { 	polja[x][y] = Polje::Posjeceno; x++; y++; 	}
	else if(smjer==Smjerovi::Dolje) { 		polja[x][y] = Polje::Posjeceno; x++; 		}
	else if(smjer==Smjerovi::DoljeLijevo) { polja[x][y] = Polje::Posjeceno; x++; y--; 	}
	else if(smjer==Smjerovi::Lijevo) { 		polja[x][y] = Polje::Posjeceno; y--; 		}
	
	if(x<0 || y<0 || x>=polja.size() || y>polja.size()) {
		x=pocx;
		y=pocy;
		throw out_of_range ("Izlazak van igrace table");
	}
	
	if(polja[x][y]== Polje::BlokiranoMina || polja[x][y]== Polje::BlokiranoPosjeceno || polja[x][y]== Polje::BlokiranoPrazno) {
		x=pocx;
		y=pocy;
		throw logic_error ("Blokirano polje");
	}
	
	if(polja[x][y] == Polje::Mina) {
		for(int i(0); i<polja.size();i++) {
			for(int j(0);j<polja[i].size();j++) {
				polja[i][j] = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	if(polja[x][y] == Polje::Prazno) {
		bool ima=true;
		for(int i(0); i<polja.size();i++) {
			for(int j(0);j<polja[i].size();j++) {
				if(polja[i][j] == Polje::Prazno) ima=false;
			}
		}
		if(ima) return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y) {
	if(novi_x>=polja[0].size() || novi_x<0 || novi_y<0 || novi_y>=polja.size()) throw out_of_range ("Izlazak van igrace table");
	if(polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno || polja[novi_x][novi_y] == Polje::BlokiranoMina || polja[novi_x][novi_y] == Polje::BlokiranoPrazno) throw logic_error ("Blokirano polje");
	else {
		x=novi_x;
		y=novi_y;
	}
	if(polja[x][y] == Polje::Mina) {
		for(int i(0); i<polja.size();i++) {
			for(int j(0);j<polja[i].size();j++) {
				polja[i][j] = Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	if(polja[x][y] == Polje::Prazno) {
		bool ima=true;
		for(int i(0); i<polja.size();i++) {
			for(int j(0);j<polja[i].size();j++) {
				if(polja[i][j] == Polje::Prazno) ima=false;
			}
		}
		if(ima) return Status::KrajPobjeda;
		else return Status::NijeKraj;
	}
	return Status::NijeKraj;
}

enum class KodoviGresaka {
	PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar
};

void PrijaviGresku(KodoviGresaka greska) {
	if(greska == KodoviGresaka::PogresnaKomanda) 		cout << "Nerazumljiva komanda!\n";
	if(greska == KodoviGresaka::NedostajeParametar) 	cout << "Komanda trazi parametar koji nije naveden!\n";
	if(greska == KodoviGresaka::SuvisanParametar) 		cout << "Zadan je suvisan parametar nakon komande!\n";
	if(greska == KodoviGresaka::NeispravanParametar)	cout << "Parametar komande nije ispravan!\n";
}

enum class Komande {
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

void IzbRazmake(string &s) {
	int i=0;
	while(i<s.length() && (s[i]<'0' || s[i]>'9')) {
		if(s[i]>='0' && s[i]<= '9') break;
		if(s[i]==' ') {
			s.erase(s.begin()+i);
			i--;
		}
		i++;
	}
}

void UcitajParametre(string s, int &x, int &y) {
	int i=0;
	while(s[i]>='0' && s[i]<='9') i++;
	x=stoi(s.substr(0,i));
	s=s.substr(i,s.size()-i);
	IzbRazmake(s);
	y=stoi(s.substr(0));
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska) {
	string s;
	getline(cin, s);
	IzbRazmake(s);
	
	if(s.substr(0,2)=="P1") {
		komanda=Komande::PomjeriJednoMjesto;
		s=s.substr(2, s.length()-2);
		IzbRazmake(s);
		if(s.substr(0,s.length())=="GL") 		{smjer=Smjerovi::GoreLijevo; 	return true;}
		else if(s.substr(0,s.length())=="G") 	{smjer=Smjerovi::Gore;			return true;}
		else if(s.substr(0,s.length())=="GD") 	{smjer=Smjerovi::GoreDesno;		return true;}
		else if(s.substr(0,s.length())=="D") 	{smjer=Smjerovi::Desno;			return true;}
		else if(s.substr(0,s.length())=="DoD") 	{smjer=Smjerovi::DoljeDesno;	return true;}
		else if(s.substr(0,s.length())=="Do") 	{smjer=Smjerovi::Dolje;			return true;}
		else if(s.substr(0,s.length())=="DoL") 	{smjer=Smjerovi::DoljeLijevo;	return true;}
		else if(s.substr(0,s.length())=="L") 	{smjer=Smjerovi::Lijevo;		return true;}
		else { 
			if(s.length()==0) {
				greska=KodoviGresaka::NedostajeParametar;
				return false;
			}
			else {
				greska=KodoviGresaka::NeispravanParametar; 
				return false; 
			}
		}
		
	}
	else if(s.substr(0,2)=="P>") {
		s=s.substr(2,s.size()-2);
		int i=0;
		if(s.length()==0) {
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
	else {
		while(i<s.length()) {
			if(s[i]!=' ' && (s[i]<'0' || s[i]>'9')) {
				greska=KodoviGresaka::NeispravanParametar;
				return false;
			}
			i++;
		}		//provjera da li je dobar format parametara
	}
		komanda=Komande::PomjeriDalje;
		UcitajParametre(s,x,y);
		return true;
		
	}
	else if(s[0]=='B') {
		s=s.substr(1,s.size()-1);
		int i=0;
		if(s.length()==0) {
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		while(i<s.length()) {
			if(s[i]!=' ' && (s[i]<'0' || s[i]>'9')) {
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			i++;
		}		//provjera da li je dobar format parametara
		komanda=Komande::Blokiraj;
		UcitajParametre(s,x,y);
		return true;
	}
	else if(s[0]=='D') {
		s=s.substr(1,s.size()-1);
		int i=0;
		if(s.length()==0) {
			greska=KodoviGresaka::NedostajeParametar;
			return false;
		}
		while(i<s.length()) {
			if(s[i]!=' ' && (s[i]<'0' || s[i]>'9')) {
				greska=KodoviGresaka::SuvisanParametar;
				return false;
			}
			i++;
		}		//provjera da li je dobar format parametara
		komanda=Komande::Deblokiraj;
		UcitajParametre(s,x,y);
		return true;
	}
	else if(s.substr(0,2)=="PO") {
		komanda=Komande::PrikaziOkolinu;
		if(s.substr(0,s.length())!= "PO") {
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		return true;
	}
	else if(s[0]=='Z') {
		if(s.substr(0,s.length())!= "Z") {
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda=Komande::ZavrsiIgru;
		return true;
	}
	else if(s[0]=='K') {
		if(s.substr(0,s.length())!= "K") {
			greska=KodoviGresaka::SuvisanParametar;
			return false;
		}
		komanda=Komande::KreirajIgru;
		return true;
	}
	else{
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	return false;
}

void IzvrsiKomandu( Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0) {
	
	if(komanda==Komande::PomjeriJednoMjesto) {
		Status stat;
		try{
			stat=Idi(polja ,x ,y ,p_smjer);
		}
		catch(out_of_range e) 	{ cout << e.what(); }
		catch(logic_error e) 	{ cout << e.what(); }
		
		if(stat==Status::KrajPoraz) {
			cout << "Nagazili ste na minu";
			for(int i(0);i<polja.size();i++) {
				for(int j(0);i<polja[i].size();j++) {
					polja[i][j]=Polje::Prazno;
				}
			}
			throw runtime_error ("Igra zavrsena");
		}
		else if(stat==Status::KrajPobjeda) {
			cout << "Bravo, obisli ste sva sigurna polja";
			for(int i(0);i<polja.size();i++) {
				for(int j(0);i<polja[i].size();j++) {
					polja[i][j]=Polje::Prazno;
				}
			}
			throw runtime_error ("Igra zavrsena");
		}
		cout<< "Tekuca pozicija igraca je ("<<x<<","<<y<<")\n";	
	}
	
	else if(komanda==Komande::PomjeriDalje) {
		Status stat;
		try{
			stat=Idi(polja, p_x, p_y, x, y);
		x=p_x; y=p_y;
		
		if(stat==Status::KrajPoraz) {
			cout << "Nagazili ste na minu";
			for(int i(0);i<polja.size();i++) {
				for(int j(0);i<polja[i].size();j++) {
					polja[i][j]=Polje::Prazno;
				}
			}
			throw runtime_error ("Igra zavrsena");
		}
		else if(stat==Status::KrajPobjeda) {
			cout << "Bravo, obisli ste sva sigurna polja";
			for(int i(0);i<polja.size();i++) {
				for(int j(0);i<polja[i].size();j++) {
					polja[i][j]=Polje::Prazno;
				}
			}
			throw runtime_error ("Igra zavrsena");
		}
		cout<< "Tekuca pozicija igraca je ("<<x<<","<<y<<")\n";
		
		}
		catch(out_of_range e) 	{ cout << e.what()<< endl; }
		catch(logic_error e) 	{ cout << e.what()<< endl; }
	}
	
	else if(komanda==Komande::Blokiraj) {
		try{
			BlokirajPolje(polja, x, y);
		}
		catch(domain_error e) { cout << e.what(); }
	}
	
	else if(komanda==Komande::Deblokiraj) {
		try{
			DeblokirajPolje(polja,x,y);
		}
		catch(domain_error e) {cout << e.what();}
	}
	
	else if(komanda==Komande::PrikaziOkolinu) {
		vector<vector<int> > okolina;
		try{
			okolina=PrikaziOkolinu(polja,x,y);
			for(int i(0);i<okolina.size();i++) {
				for(int j(0);j<okolina[i].size();j++) {
					cout << okolina[i][j] << " ";
				}
				cout<< endl;
			}
		}
		catch(domain_error e) { cout<< e.what(); }
	}
	
	else if(komanda==Komande::ZavrsiIgru) {
		
		for(int i(0);i<polja.size();i++) {
			for(int j(0);j<polja[i].size();j++) {
				polja[i][j]=Polje::Prazno;
			}
		}
		throw runtime_error ("Igra zavrsena");
	}
	
	else if(komanda==Komande::KreirajIgru) {
		
		int n;
		cout<< "Unesite broj polja: ";
		cin>>n;
		cout<< "Unesite pozicije mina: ";
		vector<vector<int> > mine;
		complex<int> jedna;
		
		while(true) {
			cin.clear();
			cin.ignore(10000, '\n');
			cin>>jedna;
			if(!cin) {
				cin.clear();
				if(cin.peek()=='.') {
				
					cin.ignore(100000,'\n');
					break;
				}
				else {
					cout<< "Greska, unesite ponovo!"<<endl;
					continue;
				}
			}
			else if(jedna.real()<0 || jedna.imag()<0 || jedna.real()>=n || jedna.imag()>=n) {
				cout<< "Greska, unesite ponovo!"<<endl;
				
				continue;
			}
			mine.push_back({jedna.real(),jedna.imag()});
			
			x=0;
			y=0;
			
		}
		try{
			polja=KreirajIgru(n,mine);
		}
		catch(domain_error e) { cout<< e.what(); }
	}
}


int main ()
{

	Komande komanda;
	Smjerovi smjer;
	KodoviGresaka greska;
	Tabla tabla;
	int x=0,y=0,nx=0,ny=0;
	try {
		while(true) {
			cout<< "Unesite komandu: ";
			
			
			if(UnosKomande(komanda,smjer,x,y,greska)) {
				IzvrsiKomandu(komanda,tabla,x,y,smjer,nx,ny);
			}
			else PrijaviGresku(greska);
		}
	}
	catch(domain_error e) { cout<< e.what(); }
	catch(runtime_error e) { }
	catch(logic_error e) { cout<< e.what(); }
	catch(out_of_range e) { cout<< e.what(); }
	catch(...) {}
	
	cout<< "Dovidjenja!";
	return 0;
}