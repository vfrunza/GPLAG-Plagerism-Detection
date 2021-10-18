/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string> //zbog to_string??

using std::domain_error;
using std::cout; using std::cin; using std::ws; using std::endl; using std::to_string;
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

void Brisi(Tabla &polja){
	for(int i{}; i < polja.size(); i++){
		for(int j{}; j < polja.size(); j++){
			polja[i][j] = Polje::Prazno;
		}
	}
}
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	Tabla T(n, std::vector<Polje>(n));
	//inicijalizujem vrijednosti u cijeloj tabli na "Prazno"
	for(int i{}; i < n; i++){
		for(int j{}; j < n; j++){
			T[i][j] = Polje::Prazno;
		}
	}
	
	for( int j{}; j < mine.size(); j++){
		if (mine[j].size() != 2) throw domain_error("Ilegalan format zadavanja mina");
		
			int vrV(mine[j][1]), vrH(mine[j][0]); //vrijednosti (vertikalne i horizontalne koordinate)
			
			for( int k{}; k < n; k++){
				for( int l{}; l < n; l++){
					if(vrH == k && vrV == l) T[vrH][vrV] = Polje::Mina;	
				}
			}
			//pošto se na 0,0 ne smije nalaziti mina
			T[0][0] = Polje::Prazno;
			if (vrV >= n || vrH >=n) throw domain_error("Ilegalne pozicije mina");	
		
	}
	return T;
}


std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	std::vector<std::vector<int>> mat(3, std::vector<int> (3, 0));
	if(x >= polja.size() || y >= polja.size()) {
		throw domain_error("Polje (" + to_string(x) + "," + to_string(y) +") ne postoji");
		
	}
	int br; //brojač
	for(int i{x-1}; i < x; i++){
		for(int j{y-1}; j < y; j++){
			br = 0;
			if(i > 0 && j > 0 && i < polja.size() && j < polja.size()){
				if (polja[i-1][j-1] == Polje::Mina) br++;
				if (polja[i][j-1] == Polje::Mina) br++;
				if (polja[i+1][j-1] == Polje::Mina) br++;
				if (polja[i+1][j] == Polje::Mina) br++;
				if (polja[i-1][j] == Polje::Mina) br++;
				if (polja[i][j+1] == Polje::Mina) br++;
				if (polja[i-1][j+1] == Polje::Mina) br++;
				if (polja[i+1][j+1] == Polje::Mina) br++;
			}
			
		}
		mat[i].push_back(br);
	}
	
	return mat;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	if(x >= polja.size() || y >= polja.size() || x < 0 || y < 0/*??*/) {
		throw domain_error("Polje (" + to_string(x) + "," + to_string(y) + ") ne postoji");
	}
	if (polja[x][y] == Polje::Mina) polja[x][y] = Polje::BlokiranoMina;
	else if(polja[x][y] == Polje::Posjeceno) polja[x][y] = Polje::BlokiranoPosjeceno; 
	else if (polja[x][y] == Polje::Prazno) polja[x][y] = Polje::BlokiranoPrazno;
}
void DeblokirajPolje(Tabla &polja, int x, int y){
	if (x >= polja.size() || y >= polja.size()) {
		throw domain_error("Polje (" + to_string(x) + "," + to_string(y) +") ne postoji");
		
	}
	if(polja[x][y] == Polje::BlokiranoMina) polja[x][y] = Polje::Mina;
	else if(polja[x][y] == Polje::BlokiranoPosjeceno) polja[x][y] = Polje::Posjeceno;
	else if(polja[x][y] == Polje::BlokiranoPrazno) polja[x][y] = Polje::Prazno;
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	polja[x][y] = Polje::Posjeceno;
	int p(polja.size());
	if( ((y+1 >= p) && (smjer == Smjerovi::Desno || smjer == Smjerovi::GoreDesno || smjer == Smjerovi::GoreLijevo))
	 || ((y-1 < 0) && (smjer == Smjerovi::Lijevo || smjer == Smjerovi::GoreLijevo || smjer == Smjerovi::GoreLijevo))
	 || ((x+1 >= p) && (smjer == Smjerovi::Dolje || smjer == Smjerovi::DoljeDesno || smjer == Smjerovi::DoljeLijevo))
	 || ((x-1 < 0) && (smjer == Smjerovi::Gore || smjer == Smjerovi::GoreDesno || smjer == Smjerovi::GoreLijevo)) )
	 throw std::out_of_range("Izlazak van igrace table");
	 if( ((smjer == Smjerovi::Desno) && (polja[x][y+1] == Polje::BlokiranoPrazno || polja[x][y+1] == Polje::BlokiranoMina || polja[x][y+1] == Polje::BlokiranoPosjeceno))
	 || (smjer == Smjerovi::Lijevo && (polja[x][y-1] == Polje::BlokiranoPrazno || polja[x][y-1] == Polje::BlokiranoMina || polja[x][y-1] == Polje::BlokiranoPosjeceno))
	 || (smjer == Smjerovi::Gore && (polja[x-1][y] == Polje::BlokiranoPrazno || polja[x-1][y] == Polje::BlokiranoMina || polja[x-1][y] == Polje::BlokiranoPosjeceno))
	 || (smjer == Smjerovi::Dolje && (polja[x+1][y] == Polje::BlokiranoPrazno || polja[x+1][y] == Polje::BlokiranoMina || polja[x+1][y] == Polje::BlokiranoPosjeceno))
	 || (smjer == Smjerovi::GoreDesno && (polja[x-1][y+1] == Polje::BlokiranoPrazno || polja[x-1][y+1] == Polje::BlokiranoMina || polja[x-1][y+1] == Polje::BlokiranoPosjeceno))
	 || (smjer == Smjerovi::GoreLijevo && (polja[x-1][y-1] == Polje::BlokiranoPrazno || polja[x-1][y-1] == Polje::BlokiranoMina || polja[x-1][y-1] == Polje::BlokiranoPosjeceno))
	 || (smjer == Smjerovi::DoljeDesno && (polja[x+1][y+1] == Polje::BlokiranoPrazno || polja[x+1][y+1] == Polje::BlokiranoMina || polja[x+1][y+1] == Polje::BlokiranoPosjeceno))
	 || (smjer == Smjerovi::DoljeLijevo && (polja[x+1][y-1] == Polje::BlokiranoPrazno || polja[x+1][y-1] == Polje::BlokiranoMina || polja[x+1][y-1] == Polje::BlokiranoPosjeceno)) )
	 throw std::logic_error("Blokirano polje");
	 
	switch (smjer){
		case Smjerovi::Desno : y++; break;
		case Smjerovi::Lijevo : y--; break;
		case Smjerovi::Gore : x--; break;
		case Smjerovi::Dolje : x++; break;
		case Smjerovi::DoljeDesno : {x++; y++; break;}
		case Smjerovi::DoljeLijevo : {x++; y--; break;}
		case Smjerovi::GoreDesno : {x--; y++; break;}
		case Smjerovi::GoreLijevo : {x--; y--;}
	}
	
	if (polja[x][y] == Polje::Mina) {
		Brisi(polja); 
		return Status::KrajPoraz;
	}//..
	
	bool kraj_igre(true);
	for(int i{}; i < polja.size(); i++){
		for(int j{}; j < polja.size(); j++){
			if(polja[i][j] != Polje::Mina || polja[i][j] != Polje::Posjeceno ) {kraj_igre = false; break;}
		}
	}
	if (kraj_igre == true) return Status::KrajPobjeda; // ?? ??
	
	return Status::NijeKraj;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){

	if(novi_x < 0 || novi_x >= polja.size() || novi_y < 0 || novi_y >= polja.size()) throw std::out_of_range("Izlazak van igrace table");
	
	if (polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno || polja[novi_x][novi_y] == Polje::BlokiranoPrazno || polja[novi_x][novi_y] == Polje::BlokiranoMina) throw std::logic_error("Blokirano polje"); //?? ??
	if (polja[novi_x][novi_y] == Polje::Mina) { 
		Brisi(polja); 
		return Status::KrajPoraz;
	} //..
	x = novi_x;
	y = novi_y;
	bool kraj_igre(true);
	for(int i{}; i < polja.size(); i++){
		for(int j{}; j < polja.size(); j++){
			if(polja[i][j] != Polje::Mina || polja[i][j] != Polje::Posjeceno ) {kraj_igre = false; break;}
		}
	}
	if (kraj_igre == true) return Status::KrajPobjeda;
	return Status::NijeKraj;
}
void PrijaviGresku(KodoviGresaka greska){
	switch(greska){
		case KodoviGresaka::PogresnaKomanda : cout << "Nerazumljiva komanda!\n"; break;
		case KodoviGresaka::NedostajeParametar : cout << "Komanda trazi parametar koji nije naveden!\n"; break;
		case KodoviGresaka::NeispravanParametar : cout << "Parametar komande nije ispravan!\n"; break;
		case KodoviGresaka::SuvisanParametar : cout << "Zadan je suvisan parametar nakon komande!\n"; break;
	}
}
bool UnosKomande (Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	cin >> ws;
	char znak(cin.get());
//	cin >> ws;
	if (!cin) greska = KodoviGresaka::PogresnaKomanda;
	if (znak == 'P') {
		char znak2 ( cin.get());
		if (znak2 == '1') komanda = Komande::PomjeriJednoMjesto;
		else if (znak2 == '>') komanda = Komande::PomjeriDalje;
		else if (znak2 == 'O') komanda = Komande::PrikaziOkolinu;
		else {greska = KodoviGresaka::PogresnaKomanda; cin.ignore(10000, '\n'); return false;}
	}
	else if(znak == 'B') komanda = Komande::Blokiraj;
	else if(znak == 'D') komanda = Komande::Deblokiraj;
	else if(znak == 'Z') komanda = Komande::ZavrsiIgru;
	else if(znak == 'K') komanda = Komande::KreirajIgru;
	else {cin.ignore(10000, '\n'); greska = KodoviGresaka::PogresnaKomanda; return false;}
	
	if (komanda == Komande::PomjeriJednoMjesto) {
		cin >> ws;
		znak = cin.get();
		if (znak == '\n') {greska = KodoviGresaka::NedostajeParametar; /*???*/ return false;} //IZMIJENI
		else if (znak == 'L')  {
			 if (cin.peek() == ' '|| cin.peek()=='\n')  smjer = Smjerovi::Lijevo;
			 else {greska = KodoviGresaka::SuvisanParametar; return false;}
		}
		else if (znak == 'G' && cin.peek() == 'L') {
			cin.get(); //kupim slovo da bih mogla peek-ovati
			if (cin.peek() == ' ' || cin.peek() == '\n') smjer = Smjerovi::GoreLijevo;
			else {greska = KodoviGresaka::SuvisanParametar; return false;}
		}
		else if (znak == 'G' && cin.peek() == 'D') {
			cin.get(); //kupim slovo da bih mogla peek-ovati
			if (cin.peek() != ' '|| cin.peek()=='\n') smjer = Smjerovi::GoreDesno;
			else {greska = KodoviGresaka::SuvisanParametar; return false;}
		}
		else if (znak == 'G') {
			if (cin.peek() == ' ' || cin.peek() == '\n')  {smjer = Smjerovi::Gore; cin.get();}
			else {greska = KodoviGresaka::SuvisanParametar; return false;}
		}
		else if (znak == 'D' && cin.peek() == 'o'){
			cin.get(); 
			if (cin.peek() == 'D'){
				cin.get();
				if(cin.peek() == ' ' || cin.peek() == '\n')  {smjer = Smjerovi::DoljeDesno; /*char znak3 = ??*/cin.get();}
				else {greska = KodoviGresaka::SuvisanParametar; return false;}
			}
			else if (cin.peek() == 'L') {
				cin.get(); //kupim slovo da bih mogla peek-ovati
				if (cin.peek() == ' ' || cin.peek() == '\n')  {smjer = Smjerovi::DoljeLijevo; /*char znak3 = ??*/cin.get();}
				else {greska = KodoviGresaka::SuvisanParametar; return false;}
			}
			else if (cin.peek() == ' ' || cin.peek() == '\n') {
				cin.get(); //kupim slovo da bih mogla peek-ovati
				smjer = Smjerovi::Dolje;
			}
			else {greska = KodoviGresaka::NeispravanParametar; return false;}
		}
		else if (znak == 'D' && (cin.peek() == ' ' || cin.peek() == '\n')/*??*/) smjer = Smjerovi::Desno;
		else {greska = KodoviGresaka::NeispravanParametar; /*?? */ return false;}
	}
			
	else if (komanda == Komande::PomjeriDalje || komanda == Komande::Blokiraj /*??*/ || komanda == Komande::Deblokiraj /*??*/) {
		bool ind(true); //indikator za petlju
		do{
			
			//cin >> ws;
			double broj;
			cin >> broj;
			
			if ( !cin || broj != int(broj) || cin.peek() != ' ' || cin.peek() != '\n'/*??zbog y*/) {greska = KodoviGresaka::PogresnaKomanda; /*?? return false;*/}
			else if (ind == false) {y = int(broj); ind = true;}
			else {x = int(broj); ind = false;}
		} while(greska != KodoviGresaka::NedostajeParametar && ind); //logička greška moguća.. ??
		/*	pretp da je ind true
			(u petlju se uđe svakako-do while je)
			petlja se vrti sve dok 
				ili unos ne bude pogresan ili 
				dok indikator ne kaze da je i y uneseno (tj ind postavljen na true [pa ako je ind true prekida se petlja])
		*/
		
	}
			
	else if ((komanda == Komande::PrikaziOkolinu || komanda == Komande::ZavrsiIgru || komanda == Komande::KreirajIgru) && ( cin.peek() != '\n') ) {
		greska = KodoviGresaka::SuvisanParametar;
		PrijaviGresku(greska);
	}
	
	else if (greska == KodoviGresaka::PogresnaKomanda || greska == KodoviGresaka::NedostajeParametar || greska == KodoviGresaka::SuvisanParametar || greska == KodoviGresaka::NeispravanParametar ) return false;
	else greska = KodoviGresaka::PogresnaKomanda; //??recimo
	//}while( /*cin.peek() == ' ' /*|| cin.get() == ' */ ); 
	return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){ // početni .. :P
		try {
			if (komanda == Komande::PomjeriJednoMjesto)
			if (komanda == Komande::PomjeriDalje) {
				if (Status::KrajPobjeda == Idi(polja, x, y, p_smjer))  cout << "Tekuca pozicija igraca je (" + to_string(x) + "," + to_string(y) + ")\n" << "Bravo, obisli ste sva sigurna polja\n";
				else if (Status::KrajPoraz == Idi(polja, x, y, p_smjer)) {cout <<  "Tekuca pozicija igraca je (" + to_string(x) + "," + to_string(y) + ")\n" << "Nagazili ste minu\n"; komanda = Komande::ZavrsiIgru;}
				else if (Status::KrajPobjeda == Idi(polja, x, y, p_x, p_y))  cout << "Bravo, obisli ste sva sigurna polja";
				else if (Status::KrajPoraz == Idi(polja, x, y, p_x, p_y)) cout << "Nagazili ste minu";
				
			}
			if (komanda == Komande::Blokiraj) BlokirajPolje(polja, x, y);
			if (komanda == Komande::Deblokiraj) DeblokirajPolje(polja, x, y);
			if (komanda == Komande::PrikaziOkolinu){
				std::vector<std::vector<int>> v(PrikaziOkolinu(polja, x, y));
				for (int i{}; i < polja.size(); i++){
					for (int j{}; j < polja.size(); j++){
						cout << v[i][j] << " ";
					}
					cout << endl;
				}
			}
			if (komanda == Komande::ZavrsiIgru) {Brisi(polja); throw std::runtime_error("Igra zavrsena");}
			if (komanda == Komande::KreirajIgru) {
				
				cout << "Unesite broj polja";
				int n;
				cin >> n;
				cout << endl;
					/*	da ne komplikujem ako nema potrebe
				do{
					cout << "Unesite broj polja: ";
					cin.ignore(10000, '\n');
				} while (cin << n, !cin); //možda greška potencijalna ??
			*/	
				cout << "Unesite pozicije mina: ";
				int p1,p2; //pozicije 1 i 2
				while(true){
					int unos;
					unos = cin.get();
					bool ind(false); //indikator za grešku
					
					if (unos != '(') ind = true;
					if (!ind) cin >> p1;
					if (!cin) ind = true;
					if (!ind) unos = cin.get(); //zarez
					if (unos != ',') ind = true;
					if (!ind) cin >> p2;
					if (!cin) ind = true;
					if (!ind) unos = cin.get();
					if (unos != ')') ind = true;
						
					
					
					if (ind == true) {
						cout << "Greska, unesite ponovo!"; 
						cin.ignore(10000, '\n');
					}
					else break;
				};
				const std::vector<std::vector<int>> mine;
				KreirajIgru(n, mine); //???
				
			}
		}
		catch (domain_error de1){
			cout << de1.what() << endl;
		}
		catch (std::out_of_range our1){
			cout << our1.what() << endl;
		}
		catch (std::logic_error le1){
			cout << le1.what() << endl;
		}
		
	}


int main (){

//AT2 (c9) - funkcija Okolina primjer iz postavke
    std::vector<std::vector<int>> mine = {{0,1}, {0,4}, {1,3}, {1,4}, {2,0}, {2,1}, {2,3}} ;
    std::vector<std::vector<Polje>> tabla = KreirajIgru(5, mine);
    std::vector<std::vector<int>> okolina = PrikaziOkolinu(tabla, 1, 1);
    for(int i = 0; i < okolina.size(); i++)
    {
      for(int j = 0; j < okolina[i].size(); j++) std::cout << okolina[i][j] << " ";
      std::cout << std::endl;
    }

/*	Komande KI(Komande::KreirajIgru);
	Smjerovi SMJER(Smjerovi::Desno);
	KodoviGresaka KODOVI_GRESAKA;
	int x(0), y(0);
 	bool qw = UnosKomande (KI, SMJER, x, y, KODOVI_GRESAKA);*/
/*	while (true){
	//	Polje POLJE(Polje::Prazno); //inicijalizacija varijable POLJE tipa Polje na vr Polje::Prazno
		std::vector<std::vector<int>> mine = {{0,2}, {1,3}, {1,5}, {4,2}, {5,1}, {5,5}} ;
	
		Smjerovi SMJER(Smjerovi::Desno);
		Status STATUS;
	;
		 p1(Komande::PomjeriJednoMjesto), PD(Komande::PomjeriDalje), B(Komande::Blokiraj), D(Komande::Deblokiraj), PO(Komande::PrikaziOkolinu), Z(Komande::ZavrsiIgru)*/;
	//	typedef std::vector<std::vector<Polje>> Tabla;
	/*	Tabla TABLA;
		int x(2), y(3), px(0), py(0);
		try{
			cout << "Unesite komandu: ";
		
			if ((UnosKomande(K, SMJER, x, y, KODOVI_GRESAKA)) == true)	IzvrsiKomandu(K, TABLA, x, y, SMJER, px, py);
			else PrijaviGresku(KODOVI_GRESAKA);
		}
		catch(...){
			cout << "HEHE";
		}
	}
	cout << "Dovidjenja!";
	return 0;
	*/


return 0;
	
}

