/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>
#include <algorithm>


using namespace std;


int neposjeceno(0);

enum class Polje {
    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};

typedef vector<vector<Polje>> Tabla;

enum class Smjerovi {
    GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

enum class Status {
    NijeKraj, KrajPoraz, KrajPobjeda
};

enum class KodoviGresaka {
    PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar
};

enum class Komande {
    PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru
};

Tabla KreirajIgru(int n, const vector<vector<int>> &mine){
	Tabla tabla(n, vector<Polje> (n, Polje::Prazno));
	if(mine.empty()) return tabla;
		for(auto red : mine){
			if((int)red.size() != 2) throw domain_error("Ilegalan format zadavanja mina");
			if(red.at(0) >= n || red.at(0) < 0 || red.at(1) >= n || red.at(1) < 0)
				throw domain_error("Ilegalne pozicije mina");
		}

	int brojacMina(0);
	for(auto red : mine){
		if(tabla.at(red.at(0)).at(red.at(1)) != Polje::Mina){
			tabla.at(red.at(0)).at(red.at(1)) = Polje::Mina;
			brojacMina++;
		}
	}
	neposjeceno = n * n - brojacMina;
	return tabla;
}

int BrojMinaUOkolini(const Tabla& polja, const int x, const int y){
	int rezultat = 0;
	int redPocetak, redKraj;
	int kolonaPocetak, kolonaKraj;
	redPocetak = (x - 1) < 0 ? x : x - 1;
	redKraj = (x + 1) > (int)polja.size() ? x : x + 1;
	
	kolonaPocetak = (y - 1) < 0 ? y : y - 1;
	kolonaKraj = (y + 1) > (int)polja.size() ? y : y + 1;
	
	for(int i(redPocetak); i <= redKraj; i++){
		for(int j(kolonaPocetak); j <= kolonaKraj; j++){
			if(polja[i][j] == Polje::Mina) rezultat++;
			if(x == i && y == j && polja[i][j] == Polje::Mina) rezultat--;
		}
	}
	return rezultat;
}

vector<vector<int>> PrikaziOkolinu(const Tabla& polja, int x, int y){
	if(x < 0 || y < 0 || x > (int)polja.size() || y > (int)polja.size()){
		stringstream ss;
		ss << "Polje (" << x << "," << y << ") ne postoji";
		throw domain_error(ss.str());
	}
	vector<vector<int>> rez;
	for(int i(x - 1); i <= x + 1; i++){
		vector<int> v;
		for(int j(y - 1); j <= y + 1; j++){
			if(i < 0 || j < 0 || i > (int)polja.size() || j > (int)polja.size())
				v.push_back(0);
			else v.push_back(BrojMinaUOkolini(polja, i, j));
		}
		rez.push_back(v);
	}
	return rez;
}

void BlokirajPolje(Tabla& polja, int x, int y){
	if(x < 0 || y < 0 || x > (int)polja.size() || y > (int)polja.size()){
		stringstream ss;
		ss << "Polje (" << x << "," << y << ") ne postoji";
		throw domain_error(ss.str());
	}
	switch(polja[x][y]){
		case Polje::Mina:
			polja[x][y] = Polje::BlokiranoMina;
			break;
		case Polje::Prazno:
			polja[x][y] = Polje::BlokiranoPrazno;
			break;
		case Polje::Posjeceno:
			polja[x][y] = Polje::BlokiranoPosjeceno;
			break;
		default: break;
	}
}

void DeblokirajPolje(Tabla& polja, int x, int y){
	if(x < 0 || y < 0 || x > (int)polja.size() || y > (int)polja.size()){
		stringstream ss;
		ss << "Polje (" << x << "," << y << ") ne postoji";
		throw domain_error(ss.str());
	}
	switch(polja[x][y]){
		case Polje::BlokiranoMina:
			polja[x][y] = Polje::Mina;
			break;
		case Polje::BlokiranoPrazno:
			polja[x][y] = Polje::Prazno;
			break;
		case Polje::BlokiranoPosjeceno:
			polja[x][y] = Polje::Posjeceno;
			break;
		default: break;
	}
}

Status Idi(Tabla& polja, int& x, int& y, Smjerovi smjer){
	int moguciX(x);
	int moguciY(y);
	switch(smjer){
		case Smjerovi::Desno:
			moguciY++; break;
		case Smjerovi::Lijevo:
			moguciY--; break;
		case Smjerovi::Gore:
			moguciX--; break;
		case Smjerovi::Dolje:
			moguciX++; break;
		case Smjerovi::DoljeDesno:
			moguciX++; moguciY++; break;
		case Smjerovi::DoljeLijevo:
			moguciX++; moguciY--; break;
		case Smjerovi::GoreDesno:
			moguciX--; moguciY++; break;
		case Smjerovi::GoreLijevo:
			moguciX--; moguciY--; break;
	}
	
	if(moguciX < 0 || moguciX == (int)polja.size() || moguciY < 0 || moguciY == (int)polja.size())
		throw out_of_range("Izlazak van igrace table");
	else if(polja[moguciX][moguciY] == Polje::BlokiranoPosjeceno ||
			polja[moguciX][moguciY] == Polje::BlokiranoPrazno ||
			polja[moguciX][moguciY] == Polje::BlokiranoMina)
			cout << "Blokirano polje" << endl;
	else {
		x = moguciX;
		y = moguciY;
		if(polja[x][y] == Polje::Mina){
			polja = KreirajIgru((int)polja.size(), {});
			return Status::KrajPoraz;
		}
		if(--neposjeceno == 0) return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}

Status Idi(Tabla& polja, int &x, int &y, int novi_x, int novi_y){
	int moguciX(novi_x), moguciY(novi_y);
	if(moguciX < 0 || moguciX == (int)polja.size() || moguciY < 0 || moguciY == (int)polja.size())
		throw out_of_range("Izlazak van igrace table");
	else if(polja[novi_x][novi_y] == Polje::BlokiranoPosjeceno ||
			polja[novi_x][novi_y] == Polje::BlokiranoPrazno ||
			polja[novi_x][novi_y] == Polje::BlokiranoMina)
			cout << "Blokirano polje" << endl;
	else {
		x = moguciX;
		y = moguciY;
		if(polja[x][y] == Polje::Mina){
			polja = KreirajIgru((int)polja.size(), {});
			return Status::KrajPoraz;
		}
		if(--neposjeceno == 0) return Status::KrajPobjeda;
	}
	return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka kodGreske){
	string poruka;
	switch(kodGreske){
		case KodoviGresaka::NedostajeParmetar:
			poruka = "Komanda trazi parametar koji nije naveden!";
			break;
		case KodoviGresaka::NeispravanParametar:
			poruka = "Parametar komande nije ispravan!";
			break;
		case KodoviGresaka::PogresnaKomanda:
			poruka = "Nerazumljiva komanda!";
			break;
		case KodoviGresaka::SuvisanParametar:
			poruka = "Zadan je suvisan parametar nakon komande!";
			break;
	}
	cout << poruka << endl;
}

void IzvrsiKomandu(Komande komanda, Tabla& polja, int& x, int& y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	auto ZavrsiIgru = [&polja](){
		polja = KreirajIgru(polja.size(), {});
		throw runtime_error("Igra zavrsena");
	};
	if(komanda == Komande::ZavrsiIgru) ZavrsiIgru();
		else if(komanda == Komande::Blokiraj){
			BlokirajPolje(polja, x, y);
		
		
		}
		else if(komanda == Komande::Deblokiraj)
			DeblokirajPolje(polja, x, y);
		else if(komanda == Komande::KreirajIgru){
			vector<vector<int>> mat;
			int n;
			cout << "Unesite broj polja: ";
			cin >> n;
			cout << "Unesite pozicije mina: ";
			cin.ignore(100, '\n'); cin.clear(); 
			while(1){
				string s;
				int tx, ty;

				getline(cin, s);
				{
					if(s == ".") break;
					stringstream ss(s);
					char c;
					ss >> c >> tx >> c >> ty >> c;
					if(tx < 0 || tx >= n || ty < 0 || ty >= n)
						cout << "Greska, unesite ponovo!" << endl;
					else mat.push_back({tx, ty});
				}
			}
			polja = KreirajIgru(n, mat);
		}
		else if(komanda == Komande::PomjeriDalje){
			Status status = Idi(polja, x, y, p_x, p_y);
			if(polja[x][y] == Polje::BlokiranoPosjeceno ||
				polja[x][y] == Polje::BlokiranoPrazno ||
				polja[x][y] == Polje::BlokiranoMina)
					cout << "Blokirano polje" << endl;
			else cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << endl;
			if(status == Status::KrajPoraz){
				cout << "Nagazili ste minu" << endl;
				ZavrsiIgru();
			}
			else if(status == Status::KrajPobjeda){
				cout << "Bravo, obisli ste sva sigurna polja" << endl;
				ZavrsiIgru();
			}
		}
		else if(komanda == Komande::PomjeriJednoMjesto){
			Status status = Idi(polja, x, y, p_smjer);
			cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << endl;
			if(status == Status::KrajPoraz){
				cout << "Nagazili ste minu" << endl;
				ZavrsiIgru();
			}
			else if(status == Status::KrajPobjeda){
				cout << "Bravo, obisli ste sva sigurna polja" << endl;
				ZavrsiIgru();
			}
		}
		else if(komanda == Komande::PrikaziOkolinu){
			vector<vector<int>> okolina = PrikaziOkolinu(polja, x, y);
			for(auto v : okolina){
				for(int x : v)
					cout << x << " ";
				cout << endl;
			}
		}
}

bool UnosKomande(Komande& komanda, Smjerovi& smjer, int& x, int& y, KodoviGresaka& greska){
	string unos, s;
	getline(cin, unos);

	unique_copy(unos.begin(), unos.end(), back_inserter(s), [](char a, char b) { return a == ' ' && b == ' ';});

    int i = s[0] == ' ' ? 1 : 0;
    if(s[i] == 'Z'){
    	komanda = Komande::ZavrsiIgru;
    }
    else if(s[i] == 'K'){
    	komanda = Komande::KreirajIgru;
    }
    else if(s[i] == 'B' || s[i] == 'D'){
    	char k = s[i];
    	if(s[++i] == ' ')
    		i++;
   		if(s[i] >= '0' && s[i] <= '9') x = s[i] - '0';
   		else {
   			greska = KodoviGresaka::NeispravanParametar;
   			return false;
   		}
   		if(s[++i] != ' '){
   			greska = KodoviGresaka::NeispravanParametar;
  			return false;
   		}
   		i++;
   		if(s[i] >= '0' && s[i] <= '9') y = s[i] - '0';
   		else {
   			greska = KodoviGresaka::NeispravanParametar;
   			return false;
   		}
   		k == 'B' ? komanda = Komande::Blokiraj : komanda = Komande::Deblokiraj;
    }
    else if(s[i] == 'P'){
    	
    	if(s[++i] == ' '){
    		greska = KodoviGresaka::PogresnaKomanda;
    		return false;
    	}
    	if(s[i] == '1'){
    		
    		i++;
    		if(s[i] == ' ') i++;
    		string podstring = s.substr(i);
    		if(*(podstring.end() - 1) == ' ') podstring.erase(podstring.end() - 1);
    		if(podstring == "GL"){
    			komanda = Komande::PomjeriJednoMjesto;
    			smjer = Smjerovi::GoreLijevo;
    		}
    		else if(podstring == "G"){
    			komanda = Komande::PomjeriJednoMjesto;
    			smjer = Smjerovi::Gore;
    		}
    		else if(podstring == "GD"){
    			komanda = Komande::PomjeriJednoMjesto;
    			smjer = Smjerovi::GoreDesno;
    		}
    		else if(podstring == "D"){
    			komanda = Komande::PomjeriJednoMjesto;
    			smjer = Smjerovi::Desno;
    		}
    		else if(podstring == "L"){
    			komanda = Komande::PomjeriJednoMjesto;
    			smjer = Smjerovi::Lijevo;
    		}
    		else if(podstring == "DoL"){
    			komanda = Komande::PomjeriJednoMjesto;
    			smjer = Smjerovi::DoljeLijevo;
    		}
    		else if(podstring == "DoD"){
    			komanda = Komande::PomjeriJednoMjesto;
    			smjer = Smjerovi::DoljeDesno;
    		}
    		else if(podstring == "Do"){
    			komanda = Komande::PomjeriJednoMjesto;
    			smjer = Smjerovi::Dolje;
    		}
    		else{
    			greska = KodoviGresaka::NeispravanParametar;
    			return false;
    		}
    	}
    	else if(s[i] == '>'){
    		
    		if(s[++i] == ' ') i++;
    		//pretpostavka da ce koord biti jednocifreni brojevi
	   		if(s[i] >= '0' && s[i] <= '9') x = s[i] - '0';
   			else {
   				greska = KodoviGresaka::NeispravanParametar;
   				return false;
   			}
   			if(s[++i] != ' '){
   				greska = KodoviGresaka::NeispravanParametar;
   				return false;
   			}
   			i++;
   			if(s[i] >= '0' && s[i] <= '9') y = s[i] - '0';
   			else {
	   			greska = KodoviGresaka::NeispravanParametar;
   				return false;
   			}
   			komanda = Komande::PomjeriDalje;
    	}
    	else if(s[i] == 'O'){
    		komanda = Komande::PrikaziOkolinu;
    	}
    }
    else {
    	greska = KodoviGresaka::PogresnaKomanda;
    	return false;
    }
    
    return true;
}

int main ()
{
	Tabla polja; 
    int x(0), y(0);
    while(1){
        try{
            Komande komanda;
            Smjerovi smjer;
            KodoviGresaka greska;
            int tx, ty;
            cout << "Unesite komandu: ";
            bool unos = UnosKomande(komanda, smjer, tx, ty, greska);
            unos ? IzvrsiKomandu(komanda, polja, x, y, smjer, tx, ty) : PrijaviGresku(greska);
        }catch(std::runtime_error e){
            
            std::cout << "Dovidjenja!" << std::endl;
            break;
        }catch(std::exception &e){
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}