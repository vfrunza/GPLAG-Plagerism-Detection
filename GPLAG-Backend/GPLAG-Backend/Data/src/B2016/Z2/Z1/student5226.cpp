/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/
#include <iostream>
#include<vector>
#include<stdexcept>
#include <string>
enum class Polje {Prazno, Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj,KrajPoraz, KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar,NeispravanParametar};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu,ZavrsiIgru,KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;


Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	Tabla igra;
	int i,j,i1,j1;
	igra.resize(n);
	for(i=0;i<n;i++){
		igra[i].resize(n);
		for(j=0;j<n;j++)
		igra[i][j]=Polje::Prazno;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			
			for(int k=0;k<mine.size();k++)
			{
				if(mine[k].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
				
					if(mine[k][0]>=n || mine[k][1]>=n) throw std::domain_error("Ilegalne pozicije mina");
					if(mine[k][0]==i && mine[k][1]==j) {
					i1=mine[k][0];
					j1=mine[k][1];
					}
						
			}			
		 igra[i1][j1]=Polje::Mina;
	}
    
	}
		
	
	return igra;
}

std::vector<std::vector<int>> PrikaziOkolinu (const Tabla &polja, int x, int y)
{
	std::vector<std::vector<int>> Okolina;
	int broj_polja=0,n=polja.size(),i,j;
	for(i=0;i<polja.size();i++){
		for(j=0;j<polja[i].size();j++){
		if(x!=0 && (i==x || i==x-1 || i==x+1)){
			if(y!=0 && (j==y || j==y-1 || j==y+1))
			{
				if(polja[i][j+1]==Polje::Mina) broj_polja++;
				if(polja[i][j-1]==Polje::Mina) broj_polja++;
				if(polja[i+1][j]==Polje::Mina) broj_polja++;
				if(polja[i-1][j]==Polje::Mina) broj_polja++;
				if(polja[i-1][j-1]==Polje::Mina) broj_polja++;
				if(polja[i+1][j+1]==Polje::Mina) broj_polja++;
				if(polja[i+1][j-1]==Polje::Mina) broj_polja++;
				if(polja[i-1][j+1]==Polje::Mina) broj_polja++;
			}
			else if(y==0 && j==y)
			{
				if(polja[i-1][j]==Polje::Mina) broj_polja++;
				if(polja[i-1][j+1]==Polje::Mina) broj_polja++;
				if(polja[i][j+1]==Polje::Mina) broj_polja++;
				if(polja[i+1][j]==Polje::Mina) broj_polja++;
				if(polja[i+1][j+1]==Polje::Mina) broj_polja++;
			}
			else if(y==n-1 && j==y){
				if(polja[i-1][j]==Polje::Mina) broj_polja++;
				if(polja[i-1][j-1]==Polje::Mina) broj_polja++;
				if(polja[i][j-1]==Polje::Mina) broj_polja++;
				if(polja[i+1][j]==Polje::Mina) broj_polja++;
				if(polja [i+1][j+1]==Polje::Mina) broj_polja++;
			}
		}
			else if(x==n-1 && i==x){
				if(y==n-1 && j==y){
					if(polja[i-1][j]==Polje::Mina) broj_polja++;
					if(polja[i-1][j-1]==Polje::Mina) broj_polja++;
					if(polja[i][j-1]==Polje::Mina) broj_polja++;
				}
				else if(y==0 && j==y){
					if(polja[i-1][j]==Polje::Mina) broj_polja++;
					if(polja[i-1][j+1]==Polje::Mina) broj_polja++;
					if(polja[i][j+1]==Polje::Mina) broj_polja++;
				}
				else if(y!=n-1 && y!=0 && (j==y || j==y-1 || y==y+1)){
					if(polja[i-1][j]==Polje::Mina) broj_polja++;
					if(polja[i-1][j+1]==Polje::Mina) broj_polja++;
					if(polja[i-1][j+1]==Polje::Mina) broj_polja++;
					if(polja[i][j+1]==Polje::Mina) broj_polja++;
					if(polja[i][j-1]==Polje::Mina) broj_polja++;
				}
			}
		
		else if(x==0 && i==x){
			if(y==0 && j==y){
				if(polja[i][j+1]==Polje::Mina) broj_polja++;
				if(polja[i+1][j]==Polje::Mina) broj_polja++;
				if(polja[i+1][j+1]==Polje::Mina) broj_polja++;
			}
			else if(y!=0 && y!=n-1 && (j==y|| j==y+1 || j==y-1)){
				if(polja[i][j-1]==Polje::Mina) broj_polja++;
				if(polja[i][j+1]==Polje::Mina) broj_polja++;
				if(polja[i+1][j-1]==Polje::Mina) broj_polja++;
				if(polja[i+1][j]==Polje::Mina) broj_polja++;
				if(polja[i+1][j+1]==Polje::Mina) broj_polja++;
				
			}
			else if(y==n-1 && j==y){
				if(polja[i][j-1]==Polje::Mina) broj_polja++;
				if(polja [i+1][j]==Polje::Mina) broj_polja++;
				if(polja[i+1][j-1]==Polje::Mina) broj_polja++;
			}
		}
		}
		Okolina[i-x][j-y]=broj_polja;
		broj_polja=0;
		}
	
	return Okolina;
	
}


void BlokirajPolje (Tabla &polja, int x, int y){
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja[i].size();j++){
			if(i==x && j==y){
				if(polja[i][j]==Polje::Mina) polja[i][j]=Polje::BlokiranoMina;
				else if(polja[i][j]==Polje::Posjeceno) polja[i][j]=Polje::BlokiranoPosjeceno;
				else if(polja[i][j]==Polje::Prazno) polja[i][j]=Polje::BlokiranoPrazno;
			}
		}
	}
}
void DeblokirajPolje(Tabla &polja, int x,int y)
{
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja[i].size();j++){
			if(i==x && j==y){
				if(polja[i][j]==Polje::BlokiranoMina) polja[i][j]=Polje::Mina;
				else if(polja[i][j]==Polje::BlokiranoPrazno) polja[i][j]=Polje::Prazno;
				else if(polja[i][j]==Polje::BlokiranoPosjeceno) polja[i][j]=Polje::Posjeceno;
			}
		}
	}
}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int brojposjeceno(0),brojmina(0);
	for(int i=0;i<polja.size();i++) {
		for(int j=0;j<polja[i].size();j++){
			if(polja[i][j]==Polje::Posjeceno) brojposjeceno++;
			if(polja[i][j]==Polje::Mina) brojmina++;
			if(i==x && j==y){
				polja [i][j]=Polje::Posjeceno;
				if(smjer==Smjerovi::Gore) {
					x=x-1;
				
				}
				else if(smjer==Smjerovi::GoreDesno){
					x=x-1;
					y=y+1;
				}
				else if(smjer==Smjerovi::GoreLijevo){
					x=x-1;
					y=y-1;
				}
				else if(smjer==Smjerovi::Lijevo){
				
					y=y-1;
					
				}
				else if(smjer==Smjerovi::Dolje){
					x=x+1;
					
				}
				else if(smjer==Smjerovi::DoljeLijevo){
					x=x+1;
					y=y-1;
				}
				else if(smjer==Smjerovi::DoljeDesno){
					x=x+1;
					y=y+1;
				}
				else if(smjer==Smjerovi::Desno){
				
					y=y+1;
				}
			}
		}
	}
	if(polja[x][y]==Polje::Mina) return Status::KrajPoraz;
	else if(polja[x][y]==Polje::Posjeceno && brojmina+brojposjeceno==polja.size()*polja[0].size()) return Status::KrajPobjeda;
	else return Status::NijeKraj;
}
Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	int brojposjeceno(0),brojmina(0);
	int i(0);
	if(novi_x>polja.size()-1 || novi_y>polja[i].size()-1) throw std::out_of_range("Izlazak van igrace tabele");
	for(i=0;i<polja.size();i++){
		for(int j=0;j<polja[i].size();j++){
			if(polja[i][j]==Polje::Posjeceno) brojposjeceno++;
			if(polja[i][j]==Polje::Mina) brojmina++;
		
			if(i==x && j==y){
				polja[i][j]=Polje::Posjeceno;
				brojposjeceno++;
				x=novi_y;
				y=novi_y;
			}
			if(polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		} }
		if(polja[x][y]==Polje::Mina) return Status::KrajPoraz;
		else if(polja[x][y]==Polje::Posjeceno && brojposjeceno+brojmina==polja.size()*polja[i].size()) return Status::KrajPobjeda;
		else return Status::NijeKraj;
	
}
void PrijaviGresku(KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!";
	else if(greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!";
	else if(greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!";
	else if(greska==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!";
}

bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string kom,smj,nasa_komanda;
	std::getline(std::cin,nasa_komanda);
	if(nasa_komanda=="P1"){
		
		std::getline(std::cin,kom);
		if(kom=="G") smjer=Smjerovi::Gore;
		else if(kom=="GL") smjer=Smjerovi::GoreLijevo;
		else if(kom=="GD") smjer=Smjerovi::GoreDesno;
		else if(kom=="Do") smjer=Smjerovi::Dolje;
		else if(kom=="DoD") smjer=Smjerovi::DoljeDesno;
		else if(kom=="DoL") smjer=Smjerovi::DoljeLijevo;
		else if(kom=="L") smjer=Smjerovi::Lijevo;
		else if(kom=="D") smjer=Smjerovi::Desno;
		else {
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		komanda=Komande::PomjeriJednoMjesto;
	}
	else if(nasa_komanda=="P>"){
		
		std::cin>>x;
		std::cin>>y;
		if(x<0 || y<0) {greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		komanda=Komande::PomjeriDalje;
	}
	else if(nasa_komanda=="B"){
		
		std::cin>>x>>y;
		if(x<0 || y<0) {greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		komanda=Komande::Blokiraj;
		
		
	}
	else if(nasa_komanda=="D"){
		
		std::cin>>x>>y;
		if(x<0 || y<0){
			greska=KodoviGresaka::NeispravanParametar;
			return false;
		}
		komanda=Komande::Deblokiraj;
		
	}
	else if(nasa_komanda=="K"){
		komanda=Komande::KreirajIgru;
		
	}
	else if(nasa_komanda=="PO"){
		komanda=Komande::PrikaziOkolinu;
	}
	else if(nasa_komanda=="Z"){
		komanda=Komande::ZavrsiIgru;
	}
	else if(nasa_komanda!="P1" && nasa_komanda!="P>" && nasa_komanda!="B" && nasa_komanda!="D" && nasa_komanda!="Z" && nasa_komanda!="K" && nasa_komanda!="PO"){
		greska=KodoviGresaka::PogresnaKomanda;
		return false;
	}
	return true;
	
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y,Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0 ){
	int broj_polja;
	if(komanda==Komande::PomjeriJednoMjesto){
		if(Idi(polja, x,y,p_smjer)==Status::KrajPobjeda){
			std::cout<<"Bravo, obisli ste sva sigurna polja";
			for(int i=0;i<polja.size();i++){
				for(int j=0;j<polja[i].size();j++) polja[i][j]=Polje::Prazno;
			}
			throw std::runtime_error("Igra zavrsena");
		}
		else if(Idi(polja,x,y,p_smjer)==Status::KrajPoraz){
			std::cout<<"Nagazili ste na minu";
			for(int i=0;i<polja.size();i++){
				for(int j=0;j<polja[i].size();j++) polja[i][j]=Polje::Prazno;
			}
			throw std::runtime_error("Igra zavrsena");
		}
	}
	else if(komanda==Komande::ZavrsiIgru){
		for(int i=0;i<polja.size();i++){
			for(int j=0;j<polja[i].size();j++){
				polja[i][j]=Polje::Prazno;
			}
		}
		throw std::runtime_error("Igra zavrsena");
	}
	else if(komanda==Komande::Blokiraj){
		BlokirajPolje(polja,x,y);
	}
	else if(komanda==Komande::Deblokiraj){
		DeblokirajPolje(polja,x,y);
	}
	else if(komanda==Komande::PrikaziOkolinu){
		std::vector<std::vector<int>> okolina;
		okolina=PrikaziOkolinu(polja,x,y);
		
	}
	else if(komanda==Komande::KreirajIgru){
		int a;
		std::cout<<"Unesite broj polja: ";
		std::cin>>broj_polja;
		polja.resize(broj_polja);
		for(int i=0;i<polja.size();i++){
			polja[i].resize(broj_polja);
		}
		std::vector<std::vector<int>> mine;
		std::cout<<"Unesite pozicije mina: ";
		int i=0;
		while(mine[i][0]!='.'){
			for(int j=0;j<2;j++){
				if(j==0) {
					std::cout<<"(";
					std::cin>>mine[i][j];
					if(mine[i][j]>=broj_polja) {
						a=1;
						break;
					}
					std::cout<<", ";
				}
				else{
					std::cin>>mine[i][j];
					if(mine[i][j]>=broj_polja){
						a=1;
						break;
					}
					std::cout<<")";
				}
				
			}
			i++;
			if(a==1){
				std::cout<<"Greska, unesite ponovo!";
				i--;
			}
			
		   Tabla igra=KreirajIgru(broj_polja,mine);
			
		}
		
	}
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y);
int main ()
{
	Komande komanda1;
	Smjerovi smjer1;
	int x1,y1,px(0),py(0);
	Status status1(Status::NijeKraj);
	KodoviGresaka greska1;
	std::vector<std::vector<int>> mine;
	Tabla polja;
	for(;;){
		try{
			std::cout<<"Unesite komandu: ";
		if(UnosKomande(komanda1,smjer1,x1,y1,greska1)==true){
			IzvrsiKomandu(komanda1,polja,x1,y1,smjer1, px,py);
			if(status1==Status::KrajPoraz || status1==Status::KrajPobjeda) break;
		}
		else if(UnosKomande(komanda1,smjer1,x1,y1,greska1)==false){
			PrijaviGresku(greska1);
		}
		}
		catch(std::domain_error e1){
			std::cout<<e1.what();
		}
		catch(std::out_of_range e2){
			std::cout<<e2.what();
		}
		catch(std::runtime_error e3){
			std::cout<<e3.what();
		}
		
	}
	
	return 0;
}