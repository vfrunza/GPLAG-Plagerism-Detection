/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std; 

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina}; 
typedef vector<vector<Polje>> Tabla; 
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};


Tabla KreirajIgru (int n, const vector<vector<int>> &mine){
	Tabla tabla (n); 
	for(int i=0; i<n; i++)									// formira tablu za igru nxn
		tabla[i].resize(n); 
		
	for(int i=0; i<mine.size(); i++){						// provjera da li svi vektori vektora imaju dva elementa
			if(mine[i].size()!=2) throw domain_error ("Ilegalan format zadavanja mina"); 
	}
	for(int i=0; i<mine.size(); i++){						// provjerava da li je neka pozicija, x ili y van formata table
		for(int j=0; j<mine[i].size(); j++){
			if(mine[i][j]>=n || mine[i][j]<0) throw domain_error ("Ilegalne pozicije mina"); 
		}
	}
	for(int i=0; i<n; i++){									//popunjava tablu na prazno
		for(int j=0; j<n; j++){
			tabla[i][j]=Polje::Prazno; 
		}
	}
	for(int i=0; i<n; i++){									// popunjava tablu sa minama, na pozicijama koje su date u vektoru 
		for(int j=0; j<n; j++){
			for(int k=0; k<mine.size(); k++){
					if(i==mine[k][0] && j==mine[k][1])
						tabla[i][j]=Polje::Mina; 
			}
		}
	}
	return tabla; 
}
int OkolinaBroja(const Tabla polja, int x, int y){
	int brojac=0; 
	int n=polja.size(); 
	for(int i=x-1; i<=x+1; i++){
		for(int j=y-1; j<=y+1; j++){
			if(i>=0 && i<n && j>=0 && j<n && polja[i][j]==Polje::Mina) brojac++; 
		}
	}
	return brojac; 
}

vector<vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	if(x>= polja.size() || y>= polja.size() || y<0 || x<0){
	string x1=to_string(x); 
	string y1=to_string(y); 
	string greska= "Polje ("+x1+","+y1+") ne postoji";
	throw domain_error (greska); 
	}
	
	vector<vector<int>> matrica (3); 
	int n=polja.size(); 
	vector<int> v; 
	for(int i=0; i<3; i++)									//kreira matricu 3x3 koja se vraća iz funkcije
		matrica[i].resize(3); 

	for(int i=x-1; i<=x+1; i++){
		for(int j=y-1; j<=y+1; j++){
			v.resize(0); 
			if(x-1>=0 && x+1<polja.size() && y-1>=0 && y+1<polja[i].size()){
			int brojac=OkolinaBroja(polja, i, j); 
			v.push_back(brojac); 
			}
		}
		matrica.push_back(v); 
	}
	
	
	return matrica; 
}
void BlokirajPolje(Tabla &polja, int x, int y){
	if(x>= polja.size() || y>= polja.size()){
	string x1=to_string(x); 
	string y1=to_string(y); 
	string greska= "Polje ("+x1+","+y1+") ne postoji";
	throw domain_error (greska); 
	}
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno; 
	else if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina; 
	else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno; 
}
void DeblokirajPolje(Tabla &polja, int x, int y){
	
	if(x>= polja.size() || y>= polja.size()){
	string x1=to_string(x); 
	string y1=to_string(y); 
	string greska= "Polje ("+x1+","+y1+") ne postoji";
	throw domain_error (greska); 
	}
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno; 
	else if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina; 
	else if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno; 
}
Status ProvjeraStatusa(Tabla polja){
	Status status=Status::KrajPobjeda; 
	for(int i=0; i<polja.size(); i++){
		for(int j=0; j<polja[i].size(); j++){
			if(polja[i][j]==Polje::Prazno || polja[i][j]==Polje::BlokiranoPrazno){
				status=Status::NijeKraj; 
				return status; 
			}
		}
	}
	return status; 
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	
	polja[x][y]=Polje::Posjeceno;
	Status status=ProvjeraStatusa(polja); 
	
	if(smjer==Smjerovi::GoreLijevo){
		x--; 
		y--; 
	}
	else if(smjer==Smjerovi::GoreDesno){
		x--; 
		y++; 
	}
	else if(smjer==Smjerovi::Gore){
		x--; 
	}
	else if(smjer==Smjerovi::Desno){
		y++; 
	}
	else if(smjer==Smjerovi::Lijevo){
		y--; 
	}
	else if(smjer==Smjerovi::DoljeDesno){
		x++;
		y++;
	}
	else if(smjer==Smjerovi::DoljeLijevo){
		x++;
		y--; 
	}
	else if(smjer==Smjerovi::Dolje){
		x++;
	}
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw out_of_range ("Izlazak van igrace table"); 
	if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPosjeceno) throw logic_error ("Blokirano polje"); 
	if(polja[x][y]==Polje::Mina) status=Status::KrajPoraz;
	
	return status; 
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	polja[x][y]=Polje::Posjeceno; 
	Status status=ProvjeraStatusa(polja); 
	x=novi_x; 
	y=novi_y; 
	if(x<0 || y<0 || x>=polja.size() || y>=polja.size()) throw out_of_range ("Izlazak van igrace table"); 
	if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina || polja[x][y]==Polje::BlokiranoPosjeceno) throw logic_error ("Blokirano polje"); 
	if(polja[x][y]==Polje::Mina) status=Status::KrajPoraz;
	
	return status;
}
void PrijaviGresku(KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda) cout << "Nerazumljiva komanda!" << endl; 
	else if(greska==KodoviGresaka::NedostajeParametar) cout << "Komanda trazi parametar koji nije naveden!" << endl; 
	else if(greska==KodoviGresaka::NeispravanParametar) cout << "Parametar komande nije ispravan!" << endl; 
	else if(greska==KodoviGresaka::SuvisanParametar) cout << "Zadan je suvisan parametar nakon komande!" << endl; 
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	string s; 
	s.resize(10); 
	getline(cin,s); 
	
	for(int i=0; i<10; i++){
		while(s[i]==' ') i++; 											// razmaci na početku komande
		
		if(s[i]=='K'){													// da li je komanda K 
			i++; 
			while(s[i]==' ') i++; 										
			if(s[i]=='\n'){
				komanda=Komande::KreirajIgru; 							// ako iza K nema ništa osim razmaka i entera, smjesti u komanda i izaći iz funkcije
				return true; 
			}
			else PrijaviGresku(KodoviGresaka::SuvisanParametar); 		// ako iza K ima bilo šta osim razmaka i entera prijavi gresku 
		}
		else if(s[i]=='Z'){												// da li je komanda Z 
			i++; 
			while(s[i]==' ') i++; 							
			if(s[i]=='\n'){
				komanda=Komande::ZavrsiIgru; 							
				return true; 
			}
			else PrijaviGresku(KodoviGresaka::SuvisanParametar); 		
		}
		else if(s[i]=='B'){												// da li je komanda B
			i++; 
			while(s[i]==' ') i++; 
			if(s[i]=='\n'){
				komanda=Komande::Blokiraj; 
				return true; 
			}
			else PrijaviGresku(KodoviGresaka::SuvisanParametar); 
		}
		else if(s[i]=='D'){
			i++; 
			while(s[i]==' ') i++; 
			if(s[i]=='\n'){
				komanda=Komande::Deblokiraj; 
			}
			else PrijaviGresku(KodoviGresaka::SuvisanParametar); 
		}
		else if(s[i]=='P' && s[i+1]=='O'){	
			i=i+2; 
			 while(s[i]==' ') i++; 
			 if(s[i]=='\n'){
			 	komanda=Komande::PrikaziOkolinu; 
			 	return true; 
			 }
			 else PrijaviGresku(KodoviGresaka::SuvisanParametar);
			}
		else if(s[i]=='P' && s[i+1]=='1'){
			i=i+2; 
			while(s[i]==' ') i++; 
			if(s[i]=='\n'){
				komanda=Komande::PomjeriJednoMjesto; 
				return true; 
			}
		}
		else if(s[i]=='P' && s[i+1]=='>'){
			
		}
		else PrijaviGresku(KodoviGresaka::PogresnaKomanda);
		
	}
	
	
	
}
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x=0, int p_y=0){
	if(komanda==Komande::KreirajIgru){
		
	}
	else if(komanda==Komande::ZavrsiIgru){
		
	}
	else if(komanda==Komande::Blokiraj){
		BlokirajPolje(polja, x, y);
	}
	else if(komanda==Komande::Deblokiraj){
		DeblokirajPolje(polja, x, y); 
	}
	else if(komanda==Komande::PrikaziOkolinu){
		
	}
	else if(komanda==Komande::PomjeriJednoMjesto){
		
	}
	else if(komanda==Komande::PomjeriDalje){
		
	}
}

int main ()
{
	try{
	Tabla tabla=KreirajIgru(5, {{0,1}, {0,4}, {1,3}, {1,4}, {2,0}, {2,1}, {2,3}});
	vector<vector<int>> matrica; 
	matrica=PrikaziOkolinu(tabla, 1,1); 
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout << matrica[i][j] << " "; 
		}
		cout << endl; 
	}
	}
	catch(domain_error poruka){
		cout << poruka.what(); 
	}
	
	
	
	
	return 0;
}