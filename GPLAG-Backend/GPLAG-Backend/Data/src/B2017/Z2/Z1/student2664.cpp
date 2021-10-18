/*B 2017/2018, Zadaća 2, Zadatak 1*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string> 
#include <sstream>
#include <cstring>

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};
enum class PBD {pomjeri, blokiraj, deblokiraj};
using std::vector; 
using std::domain_error; 
using std::out_of_range;
using std::logic_error;
using std::runtime_error;
using std::string;
using std::cout;
using std::cin;
using std::getline;
using std::strcmp;
using std::endl;
typedef vector<vector<Polje>> Tabla;


bool TacnoDva(const vector<vector<int>> &mine){
	for(const vector<int> &red : mine) if(red.size() != 2) return false;
	return true;
}
bool PoljeIzvanTable(int n, int x, int y){
	if(x >= n || x < 0 || y >= n || y < 0) return true;
	return false;
}
template <typename Tip> 
	string PretvoriUString(Tip x){
		std::ostringstream s;
		s << x;
		return s.str();
	}
int BrojMinaIzOkoline(const Tabla &polja, int x, int y){
	int br(0);
	for(int i=x-1; i<=x+1; i++){
		for(int j=y-1; j<=y+1; j++){
			if(PoljeIzvanTable(polja.size(), i, j) || (i == x && j == y)) continue;
			if(polja[i][j] == Polje::Mina) br++;
		}
	}
	return br;
}
bool ImaJednoPrazno(const Tabla &polja){
	int br(0);
	for(auto red : polja){
		for(auto x : red){
			if(x == Polje::Prazno) br++;
			if(br>1) return false;
		}
	}
	return true;
}
void IspisiGresku(){
	cout << "Greska, unesite ponovo!\n";
}
void Popravi(){
	IspisiGresku();
	cin.clear();
	cin.ignore(10000, '\n');
}
void PojediRazmake(){
	while(cin.peek() == ' ') cin.get();
}
void PojediRed(){
	while(cin.peek() != '\n') cin.get();
	cin.get();
}
bool Cifra(char c){
	return (c >= '0' && c <= '9');
}
bool UnosKoordinata(Komande &komanda, int &x, int &y, KodoviGresaka &greska, PBD pbd){ //pbd = pomjeri/blokiraj/deblokiraj, pretpostavka je da je pomjeri
	if(cin.peek() == ' ') PojediRazmake();
	if(cin.peek() == '\n') greska = KodoviGresaka::NedostajeParametar;
	else if(Cifra(cin.peek())){
		int a;
		cin >> a;
		if(cin.peek() == ' ') {
			PojediRazmake();
			if(Cifra(cin.peek())){
				int b;
				cin >> b;
				if(cin.peek() != ' ' && cin.peek() != '\n') greska = KodoviGresaka::NeispravanParametar;
				else if(cin.peek() == ' ' || cin.peek() == '\n'){
					PojediRazmake();
					if(cin.peek() == '\n'){
						cin.get();
						x=a;
						y=b;
						komanda = Komande::PomjeriDalje;
						if(pbd == PBD::blokiraj) komanda = Komande::Blokiraj;
						else if(pbd == PBD::deblokiraj) komanda = Komande::Deblokiraj;
						return true;
					}
					else greska = KodoviGresaka::SuvisanParametar;
				}
				//else if(cin.peek() == '\n') greska = KodoviGresaka::NedostajeParametar;
			}
			else if(cin.peek() == '\n') greska = KodoviGresaka::NedostajeParametar;
			else greska = KodoviGresaka::NeispravanParametar;
		}
		else greska = KodoviGresaka::NeispravanParametar;
	}
	else greska = KodoviGresaka::NeispravanParametar;
	
	PojediRed();
	
	return false;
}
bool UnesiStringSmjer(string &s){
	char c;
	do{
		c = cin.get();
		if(c == '\n') return true;
		else if(c == ' ') {
			PojediRazmake();
			if(cin.peek() != '\n') {
				PojediRed();
				return false;
			}
		}
		else s.push_back(c);
	}while(1);
	return true;
}
template <typename Tip>
	void IspisiGen(const vector<vector<Tip>> polja){
	for(int i=0; i<polja.size(); i++){
		for(int j=0; j<polja[i].size(); j++)
			cout << int(polja[i][j]) << " ";
		cout << endl;
	}
}

Tabla KreirajIgru(int n, const vector<vector<int>> &mine){
	Tabla tabla(n, vector<Polje> (n, Polje::Prazno));
	if(n<=0) throw domain_error("Ilegalna velicina");
	else if(!TacnoDva(mine)) throw domain_error("Ilegalan format zadavanja mina");
	
	for(int i=0; i<mine.size(); i++){
		int x(mine[i][0]), y(mine[i][1]);
		if(PoljeIzvanTable(n, x, y)) throw domain_error("Ilegalne pozicije mina");
		tabla[x][y] = Polje::Mina;
	}
	
	return tabla;
	
}
vector<vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	if(PoljeIzvanTable(polja.size(), x, y)) throw domain_error("Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji");
	vector<vector<int>> matrica(3, vector<int>(3, 0));
	
	for(int i=x-1, ii=0; ii<3; ii++, i++)
		for(int j=y-1, jj=0; jj<3; jj++, j++)	matrica[ii][jj] = BrojMinaIzOkoline(polja, i, j);
		
	return matrica;
}
void BlokirajPolje(Tabla &polja, int x, int y){
	if(PoljeIzvanTable(polja.size(), x, y)) throw domain_error("Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji");
	
	
	switch(polja[x][y]){
		case Polje::Prazno :
			polja[x][y] = Polje::BlokiranoPrazno;
			break;
		case Polje::Posjeceno :
			polja[x][y] = Polje::BlokiranoPosjeceno;
			break;
		case Polje::Mina :
			polja[x][y] = Polje::BlokiranoMina;
		default : break; //samo da ne bi bilo upozorenja
	}
	
	
}
void DeblokirajPolje(Tabla &polja, int x, int y){
	if(PoljeIzvanTable(polja.size(), x, y)) throw domain_error("Polje (" + PretvoriUString(x) + "," + PretvoriUString(y) + ") ne postoji");
	
	Polje &ref(polja[x][y]);
	
	switch(ref){
		case Polje::BlokiranoPrazno : 
			ref = Polje::Prazno;
			break;
		case Polje::BlokiranoPosjeceno : 
			ref = Polje::Posjeceno;
			break;
		case Polje::BlokiranoMina :
			ref = Polje::Mina;
		default : break;
	}

}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
		
	polja[x][y] = Polje::Posjeceno;
	if(PoljeIzvanTable(polja.size(), novi_x, novi_y)) throw out_of_range("Izlazak van igrace table");
	if(int(polja[novi_x][novi_y]) >= 3) throw logic_error("Blokirano polje"); 
	
	x = novi_x;
	y = novi_y;
	
	if(polja[x][y] == Polje::Mina) {
		Tabla t(polja.size(), vector<Polje> (polja.size(), Polje::Prazno));
		polja = t;
		return Status::KrajPoraz;
	}
	
	if(ImaJednoPrazno(polja)) return Status::KrajPobjeda;
	
	return Status::NijeKraj;
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int novi_x(x), novi_y(y);
	//int s(int(smjer)) bude neki pointer, zasto ??
	if(int(smjer) <= 2) novi_x--;
	else if(int(smjer) >= 4 && int(smjer) <= 6) novi_x++;
	if(int(smjer) >= 6 || int(smjer) == 0) novi_y--;
	else if(int(smjer) >= 2 && int(smjer) <= 4) novi_y++;	
	
	return Idi(polja, x, y, novi_x, novi_y);
}
void PrijaviGresku(KodoviGresaka greska){
	if(int(greska) == 0) cout << "Nerazumljiva komanda!\n";
	else if(int(greska) == 1) cout << "Komanda trazi parametar koji nije naveden!\n";
	else if(int(greska) == 2) cout << "Zadan je suvisan parametar nakon komande!\n";
	else if(int(greska) == 3) cout << "Parametar komande nije ispravan!\n";
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	char c;
	c = cin.get();
	if(c == ' ') {
		PojediRazmake();
		c = cin.get();
	}
	if(c == 'P'){
		c = cin.get();
		if(c == '1') {
			string s("");
			PojediRazmake();
			if(cin.peek() == '\n') {
				cin.get();
				greska = KodoviGresaka::NedostajeParametar;
				return false;
			}
			if(UnesiStringSmjer(s) == 0){ //znači nije dobar parametar jer poslije niza slova je neki belaj
				greska = KodoviGresaka::NeispravanParametar; //*?
				return false;
			}
			const char niz[8][4]{{"GL"}, {"G"}, {"GD"}, {"D"}, {"DoD"}, {"Do"}, {"DoL"}, {"L"}};
			Smjerovi niz_smjerova[]{Smjerovi::GoreLijevo, Smjerovi::Gore, Smjerovi::GoreDesno, Smjerovi::Desno, Smjerovi::DoljeDesno, Smjerovi::Dolje, Smjerovi::DoljeLijevo, Smjerovi::Lijevo};
			int i;
			for(i=0; i<8; i++)
				if(strcmp(niz[i], s.c_str()) == 0) {
					smjer = niz_smjerova[i];
					komanda = Komande::PomjeriJednoMjesto;
					return true;
				}
			
			if(i==8) {
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
		}
		else if(c == '>'){
			PBD pbd(PBD::pomjeri);
			return UnosKoordinata(komanda, x, y, greska, pbd);
		}
		else if(c == 'O'){
			if(cin.peek() == ' ') PojediRazmake();
			if(cin.peek() == '\n') {
				cin.get();
				komanda = Komande::PrikaziOkolinu;
				return true;
			}
			else greska = KodoviGresaka::PogresnaKomanda; //*?
		}
		else greska = KodoviGresaka::PogresnaKomanda;
	}
	else if(c == 'B'){
		PBD pbd(PBD::blokiraj);
		return UnosKoordinata(komanda, x, y, greska, pbd);
	}
	else if(c == 'D'){
		PBD pbd(PBD::deblokiraj);
		return UnosKoordinata(komanda, x, y, greska, pbd);
	}
	else if(c == 'Z'){
		PojediRazmake();
		if(cin.peek() == '\n'){
			komanda = Komande::ZavrsiIgru;
			cin.get();
			return true;
		}
		else greska = KodoviGresaka::SuvisanParametar;
	}
	else if(c == 'K'){
		PojediRazmake();
		if(cin.peek() == '\n') {
			komanda = Komande::KreirajIgru;
			cin.get(); 
			return true;
		}
		else greska = KodoviGresaka::SuvisanParametar;
	}
	else {
		greska = KodoviGresaka::PogresnaKomanda;
	}

	//zbog zaostalog smeća :
	PojediRed();
	
	return false;
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, 
	Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
		
		try{
			if(int(komanda) <= 1){
				Status st;
				if(komanda == Komande::PomjeriDalje) st = Idi(polja, x, y, p_x, p_y);
				else st = Idi(polja, x, y, p_smjer);
				
				if(st == Status::NijeKraj)	cout << "Tekuca pozicija igraca je (" << x << ","<< y << ")\n";
				if(st == Status::KrajPobjeda) {
					cout << "Bravo, obisli ste sva sigurna polja\n";
					komanda = Komande::ZavrsiIgru;
				}
				else if(st == Status::KrajPoraz) {
					cout << "Nagazili ste na minu\n";
					komanda = Komande::ZavrsiIgru;
				}
			}
			else if(komanda == Komande::PrikaziOkolinu)
				IspisiGen(PrikaziOkolinu(polja, x, y));
			else if(komanda == Komande::Blokiraj)
				BlokirajPolje(polja, p_x, p_y);
			else if(komanda == Komande::Deblokiraj)
				DeblokirajPolje(polja, p_x, p_y);
			else if(komanda == Komande::KreirajIgru){
				int n;
				do{
					cout << "Unesite broj polja: ";
					cin >> n;
					if(!cin || n <= 0) Popravi();
					else break;
				}while(1);
				vector<vector<int>> vec;
				PojediRed();
				cout << "Unesite pozicije mina: ";
				do{
					int a, b;
					PojediRazmake();
					if(cin.peek() == '.') break;
					if(cin.get() != '(') {Popravi(); continue;}
					PojediRazmake();
					if(Cifra(cin.peek())) cin >> a;
					else {Popravi(); continue;}
					PojediRazmake();
					if(cin.get() != ',') {Popravi(); continue;}
					PojediRazmake();
					if(Cifra(cin.peek())) cin >> b;
					else {Popravi(); continue;}
					PojediRazmake();
					if(cin.get() != ')') {Popravi(); continue;}
					PojediRazmake();
					if(cin.get() != '\n') {Popravi(); continue;} //*
					if(PoljeIzvanTable(n, a, b)) {IspisiGresku(); continue;}
					if(a == 0 && b == 0) {IspisiGresku(); continue;} //* na 0 0 ne smije biti mina*?
					vec.push_back({a,b});
				}while(1);
				PojediRed();
				polja = KreirajIgru(n, vec);
			}	
			
			if(komanda == Komande::ZavrsiIgru){
				Tabla m(polja.size(), vector<Polje>(polja.size(), Polje::Prazno));
				polja = m;
				throw runtime_error("Igra zavrsena\n");

			}
		}
		catch(domain_error er){
			cout << er.what() << endl;
		}
		catch(out_of_range er){
			cout << er.what() << endl;
		}
		catch(logic_error er){
			cout << er.what() << endl;
		}
		catch(runtime_error){
			throw;
		}
		
	}


int main(){
	KodoviGresaka greska;
	Komande komanda;
	Tabla polja;
	int x(0), y(0), p_x(0), p_y(0);
	Smjerovi smjer;
	
	try{
		do{
			cout << "Unesite komandu: ";
			if(UnosKomande(komanda, smjer, x, y, greska)) 
				IzvrsiKomandu(komanda, polja, p_x, p_y, smjer, x, y);
			else PrijaviGresku(greska);
		}while(1);
	}
	catch(runtime_error){
		cout << "Dovidjenja!"; 
	}
	
	return 0;
}
