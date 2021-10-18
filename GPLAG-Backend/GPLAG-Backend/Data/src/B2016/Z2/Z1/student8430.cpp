/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/

#include <vector>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

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
 PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,ZavrsiIgru, KreirajIgru
};

typedef vector<vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	
	for(int i = 0 ; i < mine.size() ; i++){
		if(mine[i].size() != 2){
			throw domain_error("Ilegalan format zadavanja mina");
		}
	}
	
	Tabla t(n, vector<Polje>(n,Polje::Prazno));
	
	if(n == 0){
		return t;
	} 
	
	
	for(int i = 0 ; i < mine.size() ; i++) {
		
		if(mine[i][0] > n - 1 || mine[i][0] < 0 || mine[i][1] > n - 1 || mine[i][1] < 0){
			throw domain_error("Ilegalne pozicije mina");
		}
		
		t[mine[i][0]][mine[i][1]] = Polje::Mina;
	}
	
	/*for(int i = 0 ; i < t.size() ; i++){
		for(int j = 0 ; j < t[0].size() ; j++){
			
			if(t[i][j] == Polje::Prazno){
				cout << "0  ";
			}
			else {
				cout << "1  ";
			}
			
		}
		cout << endl;
	}*/
	
	return t;
}

vector<vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	
	if(x > polja.size() - 1 || y > polja.size() - 1){
		string broj1 = to_string(x);
		string broj2 = to_string(y);
		string s = "Polje (" + broj1 + "," + broj2 + ") ne postoji";
		throw domain_error(s);
	}
	
	vector<vector<int>> v(3);
	int k = 0;
	for(int i = x - 1 ; i <= x + 1 ; i++){
		for(int j = y - 1 ; j <= y + 1 ; j++){

			if(i < 0 || j < 0 || i > polja.size() - 1 || j > polja.size() - 1){
				v[k / 3].push_back(0); 
				k++;
				continue;
			}
			
			int brojac = 0;
			
			for(int i2 = i - 1 ; i2 <= i + 1 ; i2++){
				for(int j2 = j - 1 ; j2 <= j + 1 ; j2++){
				
				if(i2 == i && j2 == j){
					continue;
				}	
					
				if(i2 < 0 || j2 < 0 || i2 > polja.size() - 1 || j2 > polja.size() - 1){
					continue;
				}
				
				if(polja[i2][j2] == Polje::Mina){
					brojac++;
				}
					
				}
			}
			v[k / 3].push_back(brojac);
			k++;
			
		}
	}
	
	return v;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	
	if(x > polja.size() - 1 || y > polja.size() - 1){
		string broj1 = to_string(x);
		string broj2 = to_string(y);
		string s = "Polje (" + broj1 + "," + broj2 + ") ne postoji";
		throw domain_error(s);
	}
	
	if(polja[x][y] == Polje::Prazno){
		polja[x][y] = Polje::BlokiranoPrazno;
	}
	
	if(polja[x][y] == Polje::Posjeceno){
		polja[x][y] = Polje::BlokiranoPosjeceno;
	}
	
	if(polja[x][y] == Polje::Mina){
		polja[x][y] = Polje::BlokiranoMina;
	}
	
}

void DeblokirajPolje(Tabla &polja, int x, int y){
	
	if(x > polja.size() - 1 || y > polja.size() - 1){
		string broj1 = to_string(x);
		string broj2 = to_string(y);
		string s = "Polje (" + broj1 + "," + broj2 + ") ne postoji";
		throw domain_error(s);
	}
	
	if(polja[x][y] == Polje::BlokiranoPrazno){
		polja[x][y] = Polje::Prazno;
	}
	
	if(polja[x][y] == Polje::BlokiranoPosjeceno){
		polja[x][y] = Polje::Posjeceno;
	}
	
	if(polja[x][y] == Polje::BlokiranoMina){
		polja[x][y] = Polje::Mina;
	}
	
}

void provjeraPolja(Tabla &polja , int x , int y){
	
	if(x < 0 || y < 0 || x > polja.size() - 1 || y > polja.size() - 1){
		throw out_of_range("Izlazak van igrace table");
	}
	
}

void provjeraBlokiranostiPolja(Tabla &polja , int x , int y){
	
	if(polja[x][y] == Polje::BlokiranoPosjeceno || polja[x][y] == Polje::BlokiranoPrazno || polja[x][y] == Polje::BlokiranoMina){
		throw domain_error("Blokirano polje");
	}
	
}

bool provjeraMina(Tabla &polja , int x , int y){
	
	if(polja[x][y] == Polje::Mina){
		return true;
	}
	
	return false;
}

void ocistiMatricu(Tabla &polja){
	
	for(int i = 0 ; i < polja.size() ; i++){
		for(int j = 0 ; j < polja.size() ; j++){
			polja[i][j] = Polje::Prazno;
		}
	}
	
}

bool provjeraKraja(Tabla &polja){
	
	for(int i = 0 ; i < polja.size() ; i++){
		for(int j = 0 ; j < polja.size() ; j++){
			
			if(polja[i][j] == Polje::Prazno){
				return false;
			}
			
		}
	}
	
	return true;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	
	if(provjeraMina(polja , x , y)){
		ocistiMatricu(polja);
		return Status::KrajPoraz;
	}
	
		if(smjer == Smjerovi::GoreLijevo){
			provjeraPolja(polja , x - 1 , y - 1);
			provjeraBlokiranostiPolja(polja , x - 1 , y - 1);
			polja[x][y] = Polje::Posjeceno;
			x--; y--;
		}
		else if(smjer == Smjerovi::Gore){
			provjeraPolja(polja , x - 1 , y);
			provjeraBlokiranostiPolja(polja , x - 1 , y);
			polja[x][y] = Polje::Posjeceno;
			x--;
		}
		else if(smjer == Smjerovi::GoreDesno){
			provjeraPolja(polja , x - 1 , y + 1);
			provjeraBlokiranostiPolja(polja , x - 1 , y + 1);
			polja[x][y] = Polje::Posjeceno;
			x--; y++;
		}
		else if(smjer == Smjerovi::Lijevo){
			provjeraPolja(polja , x , y - 1);
			provjeraBlokiranostiPolja(polja , x , y - 1);
			polja[x][y] = Polje::Posjeceno;
			y--;
		}
		else if(smjer == Smjerovi::Desno){
			provjeraPolja(polja , x , y + 1);
			provjeraBlokiranostiPolja(polja , x , y + 1);
			polja[x][y] = Polje::Posjeceno;
			y++;
		}
		else if(smjer == Smjerovi::DoljeLijevo){
			provjeraPolja(polja , x + 1 , y - 1);
			provjeraBlokiranostiPolja(polja , x + 1 , y - 1);
			polja[x][y] = Polje::Posjeceno;
			x++; y--;
		}
		else if(smjer == Smjerovi::Dolje){
			provjeraPolja(polja , x + 1 , y);
			provjeraBlokiranostiPolja(polja , x + 1 , y);
			polja[x][y] = Polje::Posjeceno;
			x++;
		}
		else if(smjer == Smjerovi::DoljeDesno){
			provjeraPolja(polja , x + 1 , y + 1);
			provjeraBlokiranostiPolja(polja , x + 1 , y + 1);
			polja[x][y] = Polje::Posjeceno;
			x++; y++;
		}
	
	
	if(provjeraKraja(polja)){
		return Status::KrajPobjeda;
	}
	
	return Status::NijeKraj;
	
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	
	if(provjeraMina(polja , x , y)){
		ocistiMatricu(polja);
		return Status::KrajPoraz;
	}
	
	provjeraPolja(polja , novi_x , novi_y);
	provjeraBlokiranostiPolja(polja , novi_x , novi_y);
	polja[x][y] = Polje::Posjeceno;
	x = novi_x; 
	y = novi_y;
	
	
	if(provjeraKraja(polja)){
		return Status::KrajPobjeda;
	}
	
	return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka kod){
	
	if(kod == KodoviGresaka::PogresnaKomanda){
		cout << "Nerazumljiva komanda!" << endl;
	}
	else if(kod == KodoviGresaka::NedostajeParametar){
		cout << "Komanda trazi parametar koji nije naveden!" << endl;
	}
	else if(kod == KodoviGresaka::NeispravanParametar){
		cout << "Parametar komande nije ispravan!" << endl;
	}
	else if(kod == KodoviGresaka::SuvisanParametar){
		cout << "Zadan je suvisan parametar nakon komande!" << endl;
	}
	
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	
	string s;
	getline(cin,s);
	s = "  " + s + "  ";
	
	int i = 0;
	while(s[i] == ' '){
		i++;
	}
	
	if(i == s.length()){
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
	}

	if(s[i] == 'P' && s[i + 1] == '1'){
		
		i = i + 2;
		while(s[i] == ' '){
			i++;
		}

		if(i == s.length()){
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		
		Smjerovi pSmjer;
		if(s[i] == 'G' && s[i + 1] == 'L'){
			pSmjer = Smjerovi::GoreLijevo;
			i = i + 2;
		}
		else if(s[i] == 'G' && s[i + 1] == 'D'){
			pSmjer = Smjerovi::GoreDesno;
			i = i + 2;
		}
		else if(s[i] == 'G'){
			pSmjer = Smjerovi::Gore;
			i++;
		}
		else if(s[i] == 'D' && s[i + 1] == 'o' && s[i + 2] == 'L'){
			pSmjer = Smjerovi::DoljeLijevo;
			i = i + 3;
		}
		else if(s[i] == 'D' && s[i + 1] == 'o' && s[i + 2] == 'D'){
			pSmjer = Smjerovi::DoljeDesno;
			i = i + 3;
		}
		else if(s[i] == 'D' && s[i + 1] == 'o'){
			pSmjer = Smjerovi::Dolje;
			i = i + 2;
		}
		else if(s[i] == 'D'){
			pSmjer = Smjerovi::Desno;
			i++;
		}
		else if(s[i] == 'L'){
			pSmjer = Smjerovi::Lijevo; 
			i++;
		}
		else {
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
		
		while(s[i] == ' '){
			i++;
		}
		
		if(i == s.length()){
			smjer = pSmjer;
			komanda = Komande::PomjeriJednoMjesto;
			return true;
		}
		else{
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		
		
	}
	else if(s[i] == 'P' && s[i + 1] == '>'){
		
		int broj1, broj2;
		i = i + 2;
		string pom = "";
		while(s[i] == ' '){
		i++;
	 	}
	 	
	 	if(i == s.length()){
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		
		while(s[i] != ' '){
			if(s[i] < '0' || s[i] > '9'){
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
			pom = pom + s[i];
			i++;
		}
		
		broj1 = stoi(pom);
		pom = "";
		
		while(s[i] == ' '){
		i++;
	 	}
	 	
	 	if(i == s.length()){
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		
		while(s[i] != ' '){
			if(s[i] < '0' || s[i] > '9'){
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
			pom = pom + s[i];
			i++;
		}
		
		broj2 = stoi(pom);
		
		while(s[i] == ' '){
		i++;
	 	}
	 	
	 	if(i == s.length()){
	 		x = broj1;
	 		y = broj2;
	 		komanda = Komande::PomjeriDalje;
			return true;
		}
		else{
			greska = KodoviGresaka::NeispravanParametar;
			return false;
		}
	 	
		
	}
	else if(s[i] == 'B'){
		
		int broj1, broj2;
		i = i + 1;
		string pom = "";
		while(s[i] == ' '){
		i++;
	 	}
	 	
	 	if(i == s.length()){
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		
		while(s[i] != ' '){
			if(s[i] < '0' || s[i] > '9'){
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
			pom = pom + s[i];
			i++;
		}
		
		broj1 = stoi(pom);
		pom = "";
		
		while(s[i] == ' '){
		i++;
	 	}
	 	
	 	if(i == s.length()){
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		
		while(s[i] != ' '){
			if(s[i] < '0' || s[i] > '9'){
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
			pom = pom + s[i];
			i++;
		}
		
		broj2 = stoi(pom);
		
		while(s[i] == ' '){
		i++;
	 	}
	 	
	 	if(i == s.length()){
	 		x = broj1;
	 		y = broj2;
	 		komanda = Komande::Blokiraj;
			return true;
		}
		else{
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		
	}
	else if(s[i] == 'D'){
		
		int broj1, broj2;
		i = i + 1;
		string pom = "";
		while(s[i] == ' '){
		i++;
	 	}
	 	
	 	if(i == s.length()){
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		
		while(s[i] != ' '){
			if(s[i] < '0' || s[i] > '9'){
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
			pom = pom + s[i];
			i++;
		}
		
		broj1 = stoi(pom);
		pom = "";
		
		while(s[i] == ' '){
		i++;
	 	}
	 	
	 	if(i == s.length()){
			greska = KodoviGresaka::NedostajeParametar;
			return false;
		}
		
		while(s[i] != ' '){
			if(s[i] < '0' || s[i] > '9'){
				greska = KodoviGresaka::NeispravanParametar;
				return false;
			}
			pom = pom + s[i];
			i++;
		}
		
		broj2 = stoi(pom);
		
		while(s[i] == ' '){
		i++;
	 	}
	 	
	 	if(i == s.length()){
	 		x = broj1;
	 		y = broj2;
	 		komanda = Komande::Deblokiraj;
			return true;
		}
		else{
			greska = KodoviGresaka::SuvisanParametar;
			return false;
		}
		
	}
	else if(s[i] == 'P' && s[i + 1] == 'O'){
	
		i = i + 2;
		while(s[i] == ' '){
		i++;
	 	}
	 	
	 	if(i == s.length()){
		 		komanda = Komande::PrikaziOkolinu;
		 		return true;
		}
		else{
		 	greska = KodoviGresaka::SuvisanParametar;
		 	return false;
		}
		
	}
	else if(s[i] == 'Z'){
		
		i = i + 1;
		while(s[i] == ' '){
		i++;
	 	}
	 	
	 	if(i == s.length()){
		 		komanda = Komande::ZavrsiIgru;
		 		return true;
		}
		else{
		 	greska = KodoviGresaka::SuvisanParametar;
		 	return false;
		}
		
	}
	else if(s[i] == 'K'){
		 	
		 	i = i + 1;
		 	while(s[i] == ' '){
		 		i++;
		 	}
		 	
		 	if(i == s.length()){
		 		komanda = Komande::KreirajIgru;
		 		return true;
		 	}
		 	else{
		 		greska = KodoviGresaka::SuvisanParametar;
		 		return false;
		 	}
	}
	else {
		
		greska = KodoviGresaka::PogresnaKomanda;
		return false;
			
	}
	
	return true;
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	
	if(komanda == Komande::PomjeriJednoMjesto){
		
		try{
			Status s = Idi(polja , x , y , p_smjer);
			cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << endl;
			if(s == Status::KrajPoraz){
				cout << "Nagazili ste na minu" << endl;
			}
			if(s == Status::KrajPobjeda){
				cout << "Bravo, obisli ste sva sigurna polja" << endl;
			}
		}
		catch(out_of_range o){
			cout << o.what() << endl;
		}
		catch(domain_error e){
			cout << e.what() << endl;
		}
		
		
	}
	else if(komanda == Komande::PomjeriDalje){
		
		try{
			Status s = Idi(polja , x , y , p_x , p_y);
			cout << "Tekuca pozicija igraca je (" << x << "," << y << ")" << endl;
			if(s == Status::KrajPoraz){
				cout << "Nagazili ste na minu" << endl;
			}
			if(s == Status::KrajPobjeda){
				cout << "Bravo, obisli ste sva sigurna polja" << endl;
			}
		}
		catch(out_of_range o){
			cout << o.what() << endl;
		}
		catch(domain_error e){
			cout << e.what() << endl;
		}
		
	}
	else if(komanda == Komande::Blokiraj){
		
		try{
			BlokirajPolje(polja , p_x , p_y);
			return;
		}
		catch(exception e){
			cout << e.what() << endl;
		}
		
	}
	else if(komanda == Komande::Deblokiraj){
		
		try{
			DeblokirajPolje(polja , p_x , p_y);
			return;
		}
		catch(exception e){
			cout << e.what() << endl;
		}
		
	}
	else if(komanda == Komande::PrikaziOkolinu){
		
		vector<vector<int>> v = PrikaziOkolinu(polja , x , y);
		for(int i = 0 ; i < v.size() ; i++){
			for(int j = 0 ; j < v[i].size() ; j++){
				cout << v[i][j] << " ";
			}
			cout << endl;
		}
		
	}
	else if(komanda == Komande::ZavrsiIgru){
		ocistiMatricu(polja);
		throw runtime_error("Igra zavrsena");
	}
	else if(komanda == Komande::KreirajIgru){
		cout << "Unesite broj polja: ";
		string brojPolja;
		int broj_polja;
		getline(cin,brojPolja);
		broj_polja = stoi(brojPolja);
		
	 	int brojMina = 0;
		vector<vector<int>> mine;
		bool kraj = false;
		cout << "Unesite pozicije mina: ";
		while(!kraj){
			
			try{
				string s;
				getline(cin , s);
				
				if(s.length() == 1 && s[0] == '.'){
					kraj = true;
					continue;
				}
				
				int i = 0;
				while(s[i] == ' '){
					i++;
				}
				
				if(s[i] != '('){
					throw domain_error ("Greska");
				}
		
				int broj1, broj2;
				string pom = "";
				i = i + 1;
				while(s[i] != ','){
					if(s[i] < '0' || s[i] > '9'){
						throw domain_error ("Greska");
					}
					pom = pom + s[i];
					i++;
				}
				
				broj1 = stoi(pom);
				pom = "";

				i = i + 1;
				while(s[i] != ')'){
					if(s[i] < '0' || s[i] > '9'){
						throw domain_error ("Greska");
					}
					pom = pom + s[i];
					i++;
				}
				
				broj2 = stoi(pom);
			
				if(broj1 < 0 || broj2 < 0 || broj1 > broj_polja - 1 || broj2 > broj_polja - 1){
					throw domain_error ("Greska");
				}
				
				if(broj1 == 0 && broj2 == 0){
					throw domain_error ("Greska");
				}
				
				if(i == s.length() - 1){
					brojMina++;
					mine.resize(brojMina);
					mine[brojMina - 1].push_back(broj1);
					mine[brojMina - 1].push_back(broj2);
				}
				
			}
			catch(exception e){
				cout << "Greska, unesite ponovo!" << endl;
			}
			
		}
		
		polja =KreirajIgru(broj_polja , mine);
		
	}
	
}

int main ()
{
	  
	Komande komanda;
	Smjerovi smjer;
	int x = 0 ,y = 0 , broj1 , broj2;
	KodoviGresaka greska;
	Tabla polja; 
	
	int f = 0;
	
	while(1){
		
		try{
			cout << "Unesite komandu: ";
			if(UnosKomande(komanda , smjer , broj1 , broj2 , greska	)){
				IzvrsiKomandu(komanda , polja , x , y , smjer , broj1 , broj2);
				f++;
			}
			else {
				PrijaviGresku(greska);
			}
		}
		catch(runtime_error e){
			cout << "Dovidjenja!" << endl;
			return 0;
		}
		
	}
	
	return 0;
}