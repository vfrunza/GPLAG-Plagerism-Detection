/*B 16/17, Zadaća 2, Zadatak 1
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
	
*/

#include <iostream>
#include <stdexcept>
#include <vector>


enum class Polje{Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina};
typedef std::vector<std::vector<Polje>> Tabla;
enum class Smjerovi{GoreLijevo,Gore,GoreDesno,Desno,DoljeDesno,Dolje,DoljeLijevo,Lijevo};
enum class Status{NijeKraj,KrajPoraz,KrajPobjeda};
enum class KodoviGresaka{PogresnaKomanda,NedostajeParametar,SuvisanParametar,NeispravanParametar};
enum class Komande{PomjeriJednoMjesto,PomjeriDalje,Blokiraj,Deblokiraj,PrikaziOkolinu,ZavrsiIgru,KreirajIgru};



Tabla KreirajIgru(int n,const std::vector<std::vector<int>> &mine){
	for(int i=0;i<mine.size();i++){
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	}
	for(int i=0;i<mine.size();i++){
		for(int j=0;j<2;j++){
			if(mine[i][j]>n) throw std::domain_error("Ilegalne pozicije mina");
			
		}
	}
	
	Tabla tabla(n,std::vector<Polje>(n,Polje::Prazno));
			for(int k=0;k<mine.size();k++){
				for(int l=0;l<2;l++){
					tabla[mine[k][1][mine[k][2]]=Polje::Mina;
				}
			}
			
			return tabla;
}


int IzbrojMineUOkolini(const Tabla &polja,int x,int y){
	int brojac(0);
	int n(polja.size());
				if(x==0 && y==0){
					(polja[x][y+1]==Polje::Mina) brojac++;
					if(polja[x+1][y]==Polje::Mina) brojac++;
					if(polja[x+1][y+1]==Polje::Mina) brojac++;
				}
				else if(x==0){
					if(polja[x][y-1]==Polje::Mina) brojac++;
				if(polja[x][y+1]==Polje::Mina) brojac++;
				if(polja[x+1][y-1]==Polje::Mina) brojac++;
				if(polja[x+1][y]==Polje::Mina) brojac++;
				if(polja[x+1][y+1]==Polje::Mina) brojac++;
				}
				else if(y==0){
					if(polja[x-1][y]==Polje::Mina) brojac++;
					if(polja[x-1][y+1]==Polje::Mina) brojac++;
					if(polja[x][y+1]==Polje::Mina) brojac++;
					if(polja[x+1][y]==Polje::Mina) brojac++;
					if(polja[x+1][y+1]==Polje::Mina) brojac++;
				}
				else if(x==n && y==0){
					if(polja[x-1][y]==Polje::Mina) brojac++;
				if(polja[x-1][y+1]==Polje::Mina) brojac++;
					if(polja[x][y+1]==Polje::Mina) brojac++;
				}
				else if(x==n && y==n){
						if(polja[x-1][y-1]==Polje::Mina) brojac++;
						if(polja[x-1][y]==Polje::Mina) brojac++;
						if(polja[x][y-1]==Polje::Mina) brojac++;
				}
				else if(x==0 && y==n){
					if(polja[x][y-1]==Polje::Mina) brojac++;
					if(polja[x+1][y-1]==Polje::Mina) brojac++;
					if(polja[x+1][y]==Polje::Mina) brojac++;
				}
				else if(y==n){
						if(polja[x-1][y-1]==Polje::Mina) brojac++;
						if(polja[x-1][y]==Polje::Mina) brojac++;
						if(polja[x][y-1]==Polje::Mina) brojac++;
						if(polja[x+1][y-1]==Polje::Mina) brojac++;
						if(polja[x+1][y]==Polje::Mina) brojac++;
				}
				else if(x==n){
					if(polja[x-1][y-1]==Polje::Mina) brojac++;
				if(polja[x-1][y]==Polje::Mina) brojac++;
				if(polja[x-1][y+1]==Polje::Mina) brojac++;
				if(polja[x][y-1]==Polje::Mina) brojac++;
				if(polja[x][y+1]==Polje::Mina) brojac++;
				}
				else{
				if(polja[x-1][y-1]==Polje::Mina) brojac++;
				if(polja[x-1][y]==Polje::Mina) brojac++;
				if(polja[x-1][y+1]==Polje::Mina) brojac++;
				if(polja[x][y-1]==Polje::Mina) brojac++;
				if(polja[x][y+1]==Polje::Mina) brojac++;
				if(polja[x+1][y-1]==Polje::Mina) brojac++;
				if(polja[x+1][y]==Polje::Mina) brojac++;
				if(polja[x+1][y+1]==Polje::Mina) brojac++;
				}
				return brojac;
}

void OcistiMatricu(Tabla &polja){
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja.size();j++)
		polja[i][j]=Polje::Prazno;
	}
	
}

bool JesuLiSvaPosjecena(const Tabla &polja){
	bool sva_posjecena(true);
	for(int i=0;i<polja.size();i++){
		for(int j=0;j<polja.size();j++){
			if(polja[i][j]!=Polje::Posjeceno) sva_posjecena=false;
			
		}
		
	}
	
	return sva_posjecena;
}
std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja,int x,int y){
	std::vector<std::vector<int>> okolina(3,std::vector<int>(3));
	int brojac1(1);
	int brojac2(1);
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(x==0)
				okolina[i][j]=IzbrojMineUOkolini(polja,x-brojac1,y-brojac2);
			
			}
		}
	
	
	
}



void BlokirajPolje(Tabla &polja,int x,int y){
	if(x>polja.size() || y>polja.size()) throw std::domain_error("Polje ("<<x<<","<<y<<") ne postoji");
	
	if(polja[x][y]==Polje::Prazno) polja[x][y]=Polje::BlokiranoPrazno;
	else if(polja[x][y]==Polje::Posjeceno) polja[x][y]=Polje::BlokiranoPosjeceno;
	else polja[x][y]=Polje::BlokiranoMina;
}


void DeblokirajPolje(Tabla &polja,int x,int y){
	if(x>polja.size() || y>polja.size()) throw std::domain_error("Polje ("<<x<<","<<y<<") ne postoji");
	if(polja[x][y]==Polje::BlokiranoPrazno) polja[x][y]=Polje::Prazno;
	else if(polja[x][y]==Polje::BlokiranoPosjeceno) polja[x][y]=Polje::Posjeceno;
	else polja[x][y]=Polje::Mina;
}

Status Idi(Tabla &polja,int &x,int &y,Smjerovi smjer){
	
	if(smjer==Smjerovi::GoreLijevo && ( x==0 || y==0) ) throw std::out_of_range("Izlazak van igrace table");
	if(smjer==Smjerovi::Gore && x==0) throw std::out_of_range("Izlazak van igrace table");
	if(smjer==Smjerovi::GoreDesno && (x==0 && y==polja.size())) throw std::out_of_range("Izlazak van igrace table");
	if(smjer==Smjerovi::Desno && y==polja.size())) throw std::out_of_range("Izlazak van igrace table");	
	if(smjer==Smjerovi::DoljeDesno && (x==polja.size() || y==polja.size())) throw std::out_of_range("Izlazak van igrace table");
	if(smjer==Smjerovi::Dolje && x==polja.size()) throw std::out_of_range("Izlazak van igrace table");
	if(smjer==Smjerovi::DoljeLijevo && (x==polja.size() || y==0)) throw std::out_of_range("Izlazak van igrace table");
	if(smjer==Smjerovi::Lijevo  && y==0) throw std::out_of_range("Izlazak van igrace table");
	std::vector<Polje> v(BlokiranoPosjeceno,BlokiranoPrazno,BlokiranoMina);
	
	polja[x][y]=Polje::Posjeceno;
	if(smjer==Smjerovi::GoreLijevo){ 
		if(polja[x-1][y-1]==BlokiranoPosjeceno || polja[x-1][y-1]==BlokiranoMina  || polja[x-1][y-1]==BlokiranoPrazno)
		throw std::logic_error("Blokirano polje");
		x=x-1;y=y-1;
		if(polja[x-1][y-1]==Polje::Mina){
			OcistiMatricu(polja);
			return Status::KrajPoraz;
		}
		else if(JesuLiSvaPosjecena(polja)){
			return Status::KrajPobjeda;
		}
		
	}
	if(smjer==Smjerovi::Gore){
		if(polja[x-1][y]==BlokiranoPosjeceno || polja[x-1][y]==BlokiranoMina  || polja[x-1][y]==BlokiranoPrazno)
		throw std::logic_error("Blokirano polje");
		x=x-1;
		if(polja[x-1][y]==Polje::Mina){
			OcistiMatricu(polja);
			return Status::KrajPoraz;
		}
		else if(JesuLiSvaPosjecena(polja)){
			return Status::KrajPobjeda;
		}
	}
	if(smjer==Smjerovi::GoreDesno){
		if(polja[x-1][y+1]==BlokiranoPosjeceno || polja[x-1][y+1]==BlokiranoMina  || polja[x-1][y+1]==BlokiranoPrazno)
		throw std::logic_error("Blokirano polje");
		x=x-1;y=y+1;
		if(polja[x-1][y+1]==Polje::Mina){
			OcistiMatricu(polja);
			return Status::KrajPoraz;
		}
		else if(JesuLiSvaPosjecena(polja)){
			return Status::KrajPobjeda;
		}
	}
	if(smjer==Smjerovi::Desno) {
		if(polja[x][y+1]==BlokiranoPosjeceno || polja[x][y+1]==BlokiranoMina  || polja[x][y+1]==BlokiranoPrazno)
		throw std::logic_error("Blokirano polje");
		y=y+1;
		if(polja[x][y+1]==Polje::Mina){
			OcistiMatricu(polja);
			return Status::KrajPoraz;
		}
		else if(JesuLiSvaPosjecena(polja)){
			return Status::KrajPobjeda;
		}
	}
	if(smjer==Smjerovi::DoljeDesno){
		if(polja[x+1][y+1]==BlokiranoPosjeceno || polja[x+1][y+1]==BlokiranoMina  || polja[x+1][y+1]==BlokiranoPrazno)
		throw std::logic_error("Blokirano polje");
		x=x+1; y=y+1;
		if(polja[x+1][y+1]==Polje::Mina){
			OcistiMatricu(polja);
			return Status::KrajPoraz;
		}
		else if(JesuLiSvaPosjecena(polja)){
			return Status::KrajPobjeda;
		}
	}
	if(smjer==Smjerovi::Dolje){
		if(polja[x+1][y]==BlokiranoPosjeceno || polja[x+1][y]==BlokiranoMina  || polja[x+1][y]==BlokiranoPrazno)
		throw std::logic_error("Blokirano polje");
		x=x+1;
		if(polja[x+1][y]==Polje::Mina){
			OcistiMatricu(polja);
			return Status::KrajPoraz;
		}
		else if(JesuLiSvaPosjecena(polja)){
			return Status::KrajPobjeda;
		}
	}
	if(smjer==Smjerovi::DoljeLijevo){
		if(polja[x+1][y-1]==BlokiranoPosjeceno || polja[x+1][y-1]==BlokiranoMina  || polja[x+1][y-1]==BlokiranoPrazno)
		throw std::logic_error("Blokirano polje");
		x=x+1;y=y-1;
		if(polja[x+1][y-1]==Polje::Mina){
			OcistiMatricu(polja);
			return Status::KrajPoraz;
		}
		else if(JesuLiSvaPosjecena(polja)){
			return Status::KrajPobjeda;
		}
	}
	if(smjer==Smjerovi::Lijevo){
		if(polja[x][y-1]==BlokiranoPosjeceno || polja[x][y-1]==BlokiranoMina  || polja[x][y-1]==BlokiranoPrazno)
		throw std::logic_error("Blokirano polje");
		y=y-1;
		if(polja[x][y-1]==Polje::Mina){
			OcistiMatricu(polja);
			return Status::KrajPoraz;
		}
		else if(JesuLiSvaPosjecena(polja)){
			return Status::KrajPobjeda;
		}
	}
	

	return Status::NijeKraj;
	
}


void KojaJeGreska(KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!";
	else if(greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!";
	else if(greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije ispravan!";
	else if(greska==KodoviGresaka::SuvisanParametar ) std::cout<<"Zadan je suvisan parametar nakon komande!";
	
}
 bool UnosKomande(Komande &komanda,Smjerovi &smjer,int &x,int &y,KodoviGresaka &greska){
 	
 	
 }





int main ()
{
	return 0;
}