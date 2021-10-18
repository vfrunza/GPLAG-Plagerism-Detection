/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno,BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno,Dolje,DoljeLijevo,Lijevo};
enum class Status{ NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande{PomjeriJednoMjesto,PomjeriDalje,Blokiraj,Deblokiraj,PrikaziOkolinu,ZavrsiIgru,KreirajIgru};
typedef std::vector<std::vector<Polje>> Tabla;
Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
std::vector<std::vector<Polje>> tabla;
tabla.resize(n,std::vector<Polje> (n));
	for(int i=0; i<mine.size();i++){
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		for(int j=0;j<mine[0].size();j++){
			if(mine[i][j]>n) throw std::domain_error("Ilegalne pozicije mina");
		}
		
	}
	
	for(int i=0; i<tabla.size();i++)
	   for(int j=0;j<tabla[0].size();j++) tabla[i][j]=Polje::Prazno;
	int x, y;
	for(int i=0; i<mine.size(); i++){
	
			x=mine[i][0];
			y=mine[i][1];
			tabla[x][y]=Polje::Mina;
		
	}
	return tabla;
	   
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	std::vector<std::vector<int>> matrica(3,std::vector<int>(3));
	int vel=polja.size();
	if(x>vel || y>vel) throw std::domain_error("Polje (x,y) ne postoji");
	return matrica;
}
void BlokirajPolje(Tabla &polja, int x, int y){
	if(x>polja.size() || y>polja.size()) throw std::domain_error("Polje (x,y) ne postoji");
	for(int i=0; i<polja.size();i++){
		for(int j=0; j<polja[i].size();j++){
			if(i==x && j==y){
				if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
				else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
				else if(polja[x][y]==Polje::Mina) polja[x][y]=Polje::BlokiranoMina;
			
			}
		}
	}
	
}
void DeblokirajPolje(Tabla &polja, int x, int y){
		if(x>polja.size() || y>polja.size()) throw std::domain_error("Polje (x,y) ne postoji");
	for(int i=0; i<polja.size();i++){
		for(int j=0; j<polja[i].size();j++){
			if(i==x && j==y){
				if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
				else if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
				else if(polja[x][y]==Polje::BlokiranoMina) polja[x][y]=Polje::Mina;
			
			}
		}
	}
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	polja[x][y]=Polje::Posjeceno;
	if(smjer==Smjerovi::GoreLijevo){
		if(x-1<0 || y-1<0) throw std::out_of_range("Izlazak van igrace table");
		if(polja[x-1][y-1]==Polje::BlokiranoPrazno || polja[x-1][y-1]==Polje::BlokiranoPosjeceno || polja[x-1][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		x=x-1;y=y-1;
	}
	else if(smjer==Smjerovi::Gore){
		if(x-1<0)throw std::out_of_range("Izlazak van igrace table");
		if(polja[x-1][y]==Polje::BlokiranoPrazno || polja[x-1][y]==Polje::BlokiranoPosjeceno || polja[x-1][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		x=x-1;
	}
	else if(smjer==Smjerovi::GoreDesno){
		if(x-1<0 || y+1>polja.size())throw std::out_of_range("Izlazak van igrace table");
		if(polja[x-1][y+1]==Polje::BlokiranoPrazno || polja[x-1][y+1]==Polje::BlokiranoPosjeceno || polja[x-1][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		x=x-1; y=y+1;
	}
	else if(smjer==Smjerovi::Desno){
		if(y+1>polja.size())throw std::out_of_range("Izlazak van igrace table");
		if(polja[x][y+1]==Polje::BlokiranoPrazno || polja[x][y+1]==Polje::BlokiranoPosjeceno || polja[x][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		y=y+1;
	}
	else if(smjer==Smjerovi::DoljeDesno){
		if(x+1>polja.size() || y+1>polja.size())throw std::out_of_range("Izlazak van igrace table");
		if(polja[x+1][y+1]==Polje::BlokiranoPrazno || polja[x+1][y+1]==Polje::BlokiranoPosjeceno || polja[x+1][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		x=x+1;y=y+1;
	}
	else if(smjer==Smjerovi::Dolje){
		if(x+1>polja.size())throw std::out_of_range("Izlazak van igrace table");
		if(polja[x+1][y]==Polje::BlokiranoPrazno || polja[x+1][y]==Polje::BlokiranoPosjeceno || polja[x+1][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		x=x+1;
	}
	else if(smjer==Smjerovi::DoljeLijevo){
		if(x+1>polja.size() || y-1<0) throw std::out_of_range("Izlazak van igrace table");
		if(polja[x+1][y-1]==Polje::BlokiranoPrazno || polja[x+1][y-1]==Polje::BlokiranoPosjeceno || polja[x+1][y-1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		x=x+1;y=y-1;
	}
	else if(smjer==Smjerovi::Lijevo){
		if(y+1>polja.size()) throw std::out_of_range("Izlazak van igrace table");
		if(polja[x][y+1]==Polje::BlokiranoPrazno || polja[x][y+1]==Polje::BlokiranoPosjeceno || polja[x][y+1]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		y=y+1;
	}
		int i=0;
	for(i=0; i<polja.size(); i++){
		for(int j=0; j<polja[0].size(); j++){
			if(polja[i][j]==Polje::Prazno) return Status::NijeKraj;
		}
	}
	if(i==polja.size()-1)return Status::KrajPobjeda;
	
	
	return Status::NijeKraj;
	
	
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	polja[x][y]=Polje::Posjeceno;
	if(novi_x>polja.size() || novi_y>polja.size()) throw std::out_of_range("Izlazak van igrace table");
	if(polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	x=novi_x;
	y=novi_y;
	if(polja[x][y]==Polje::Mina){
	for(int i=0; i<polja.size();i++)
	   for(int j=0;j<polja.size();j++) polja[i][j]=Polje::Prazno;
		return Status::KrajPoraz;
	} 
	int i=0;
	for(i=0; i<polja.size(); i++){
		for(int j=0; j<polja[0].size(); j++){
			if(polja[i][j]==Polje::Prazno) return Status::NijeKraj;
		}
	}
	if(i==polja.size()-1)return Status::KrajPobjeda;
	
	
	return Status::NijeKraj;
	
	
	
}
void PrijaviGresku(KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda) {
		std::cout<<"Nerazumljiva komanda!";
		return;
	}
	else if(greska==KodoviGresaka::NedostajeParametar) {
		std::cout<<"Komanda trazi parametar koji nije naveden!";
		return;
		
	}
	else if(greska==KodoviGresaka::NeispravanParametar){
		std::cout<<"Parametar komande nije ispravan!";
		return;
	}
	else if(greska==KodoviGresaka::SuvisanParametar){
		std::cout<<"Zadan je suvisan parametar nakon komande!";
		return;
	}
	
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
/*	if(komanda=="P1" || komanda==" P1" || komanda=="P1 " || komanda==" P1 ") komanda=Komande::PomjeriJednoMjesto;
	else if(komanda=="P>" || komanda==" P>" || komanda=="P> " || komanda==" P> ") komanda=Komande::PomjeriDalje;
	else if(komanda=="B" || komanda==" B" || komanda=="B "|| komanda==" B ") komanda=Komande::Blokiraj;
	else if(komanda=="D" || komanda==" D" || komanda=="D " || komanda==" D ") komanda=Komande::Deblokiraj;
	else if(komanda=="PO" || komanda==" PO" || komanda=="PO " || komanda==" PO ") komanda=Komande::PrikaziOkolinu;
	else if(komanda=="Z" || komanda==" Z" || komanda=="Z " || komanda==" Z ") komanda=Komande::ZavrsiIgru;
	else if(komanda=="K" || komanda==" K" || komanda=="K " || komanda==" K ") komanda=Komande::KreirajIgru;*/
	return true;
}
void IzvrsiKomanu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0){
	if(komanda==Komande::PomjeriJednoMjesto){ 
		Status s=Idi(polja,x,y,p_smjer);
		std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")";
		if(s==Status::KrajPobjeda) std::cout<<"Bravo, obisli ste sva sigurna polja";
		else if(s==Status::KrajPoraz) {std::cout<<"Nagazili ste na minu"; return;}
	}
	else if(komanda==Komande::PomjeriDalje) {
		Status s=Idi(polja,x,y,p_x,p_y);
			std::cout<<"Tekuca pozicija igraca je ("<<x<<","<<y<<")";
		if(s==Status::KrajPobjeda) std::cout<<"Bravo, obisli ste sva sigurna polja";
		else if(s==Status::KrajPoraz) {std::cout<<"Nagazili ste na minu"; return;}
	
	}
	else if(komanda==Komande::Blokiraj) BlokirajPolje(polja,x,y);
	else if(komanda==Komande::Deblokiraj) DeblokirajPolje(polja,x,y);
	else if(komanda==Komande::PrikaziOkolinu) {
		std::vector<std::vector<int>> mat=PrikaziOkolinu(polja,x,y);
		for(int i=0; i<mat.size(); i++)
		for(int j=0; j<mat[i].size();j++)
		std::cout<<mat[i][j];
		std::cout<<std::endl;
	}
	else if(komanda==Komande::ZavrsiIgru) {
		for(int i=0; i<polja.size();i++)
	   for(int j=0;j<polja[0].size();j++) polja[i][j]=Polje::Prazno;
	   throw std::runtime_error("Igra zavrsena");
	} 
	else if(komanda==Komande::KreirajIgru) {
		std::cout<<"Unesite broj polja :";
		int n;
		std::cin>>n;
		std::string p; 
		std::vector<std::string> mine;
		std::cout<<"Unesite pozicije mina: ";
		for(;;){
			std::cin>>p;
			if(p==".")break;
			//break;
			mine.push_back(p);
		}
	}
}

int main ()
{
	return 0;
}