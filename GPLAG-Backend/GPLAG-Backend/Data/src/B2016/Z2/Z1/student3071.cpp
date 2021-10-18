#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

enum class Polje{Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi{GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status{NijeKraj, KrajPoraz, KrajPobjeda};
enum class KodoviGresaka{PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar};
enum class Komande{PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	Tabla tabla;
	tabla=std::vector<std::vector<Polje>>(n,std::vector<Polje>(n));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			tabla[i][j]=Polje::Prazno;
		}
	}
	try{
	for(int i=0; i<mine.size(); i++){
		if(mine[i].size()>2 || mine[i].size()<2) throw std::domain_error("Ilegalan format zadavanja mina");
	}
	for(int i=0; i<mine.size(); i++){
		for(int j=0; j<mine[0].size(); j++){
			if(mine[i][j]>n || mine[i][j]<0) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	for(int i=0; i<mine.size(); i++){
		for(int j=1; j<2; j++){
			tabla[mine[i][j-1]][mine[i][j]]=Polje::Mina;
		}
	}
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}

	return tabla;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	std::vector<std::vector<int>> minirano;
	std::string izuzetak("Polje (");
	izuzetak+=std::to_string(x)+","+std::to_string(y)+") ne postoji";
	int a(0),b(0);
	minirano=std::vector<std::vector<int>>(3,std::vector<int>(3));	
	if((x>polja.size()-1) || (y>polja.size()-1)) throw std::domain_error(izuzetak);
	try{
	if(x>0 && y>0){
	for(int i=x-1; i<x+2; i++){
		b=0;
		for(int j=y-1; j<y+2; j++){
			int brojac(0);
			if(i==0 && j==0){
				if(polja[i][j+1]==Polje::Mina) brojac++;
				if(polja[i+1][j]==Polje::Mina) brojac++;
				if(polja[i+1][j+1]==Polje::Mina) brojac++;
				minirano[a][b]=brojac; b++;
			} else if(i==0 && j>0){
				if(polja[i][j-1]==Polje::Mina) brojac++;
				if(polja[i][j+1]==Polje::Mina) brojac++;
				if(polja[i+1][j-1]==Polje::Mina) brojac++;
				if(polja[i+1][j]==Polje::Mina) brojac++;
				if(polja[i+1][j+1]==Polje::Mina) brojac++;
				minirano[a][b]=brojac; b++;
			} else if(i>0 && j==0){
				if(polja[i-1][j]==Polje::Mina) brojac++;
				if(polja[i+1][j]==Polje::Mina) brojac++;
				if(polja[i][j+1]==Polje::Mina) brojac++;
				if(polja[i-1][j+1]==Polje::Mina) brojac++;
				if(polja[i+1][j+1]==Polje::Mina) brojac++;
				minirano[a][b]=brojac; b++;
			}	
			else{
			if(polja[i-1][j-1]==Polje::Mina) brojac++;
			if(polja[i-1][j]==Polje::Mina) brojac++;
			if(polja[i-1][j+1]==Polje::Mina) brojac++;
			if(polja[i][j-1]==Polje::Mina) brojac++;
			if(polja[i][j+1]==Polje::Mina) brojac++;
			if(polja[i+1][j]==Polje::Mina) brojac++;
			if(polja[i+1][j+1]==Polje::Mina) brojac++;
			if(polja[i+1][j-1]==Polje::Mina) brojac++;
			minirano[a][b]=brojac; b++;
		}}
		a++;
	} 
		
	
	return minirano;
	}	
	}
	catch(std::domain_error e){
		std::cout<<e.what()<<std::endl;
	}
}

void BlokirajPolje(Tabla &polja, int x, int y){
		std::string izuzetak("Polje (");
		izuzetak+=std::to_string(x)+","+std::to_string(y)+") ne postoji";
		if((x>polja.size()-1) || (y>polja.size()-1)) throw std::domain_error(izuzetak);
		try{
		if(polja[x][y]==Polje::Prazno)
			polja[x][y]=Polje::BlokiranoPrazno;
		else if(polja[x][y]==Polje::Posjeceno)
			polja[x][y]=Polje::BlokiranoPosjeceno;
		else if(polja[x][y]==Polje::Mina)
			polja[x][y]=Polje::BlokiranoMina;
		}
		catch(std::domain_error e){
			std::cout<<e.what()<<std::endl;
		}
			
}

void DeblokirajPolje(Tabla &polja, int x, int y){
		std::string izuzetak("Polje (");
		izuzetak+=std::to_string(x)+","+std::to_string(y)+") ne postoji";
		if((x>polja.size()-1) || (y>polja.size()-1)) throw std::domain_error(izuzetak);
		try{
		if(polja[x][y]==Polje::BlokiranoPrazno)
			polja[x][y]=Polje::Prazno;
		else if(polja[x][y]==Polje::BlokiranoPosjeceno)
			polja[x][y]=Polje::Posjeceno;
		else if(polja[x][y]==Polje::BlokiranoMina)
			polja[x][y]=Polje::Mina;
		}
		catch(std::domain_error e){
			std::cout<<e.what()<<std::endl;
		}
}		

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	if(x>polja.size()-1 || y>polja.size()-1) throw std::out_of_range("Izlazak van igrace tabele");
	if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoMina) 
	throw std::logic_error("Blokirano polje");
	try{
	polja[x][y]=Polje::Posjeceno;
	if(smjer==Smjerovi::Gore) x--;
	if(smjer==Smjerovi::Dolje) x++;
	if(smjer==Smjerovi::Lijevo) y--;
	if(smjer==Smjerovi::Desno) y++;
	if(smjer==Smjerovi::GoreDesno){ x--; y++;}
	if(smjer==Smjerovi::GoreLijevo){ x--; y--;}
	if(smjer==Smjerovi::DoljeDesno){ x++; y++;}
	if(smjer==Smjerovi::DoljeLijevo){ x++; y--;}
	if(polja[x][y]==Polje::Mina){
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[0].size(); j++){
				polja[i][j]=Polje::Prazno;
			}
		} return Status::KrajPoraz;
	} else{
		int brojac(0);
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[0].size(); j++){
				if(polja[i][j]!=Polje::Prazno) brojac++;
			}
		}
		if(brojac==0) { 
			return Status::NijeKraj;
		} else{ return Status::KrajPobjeda; }
	}} catch(std::out_of_range e){
		std::cout<<e.what()<<std::endl;
	} catch(std::logic_error e1){
		std::cout<<e1.what()<<std::endl;
	}
}

Status Idi(Tabla &polja, int&x, int &y, int novi_x, int novi_y){
	if(novi_x>polja.size()-1 || novi_y>polja.size()-1) throw std::out_of_range("Izlazak van igrace tabele");
	if(polja[x][y]==Polje::BlokiranoPrazno || polja[x][y]==Polje::BlokiranoPosjeceno || polja[x][y]==Polje::BlokiranoMina) 
	throw std::logic_error("Blokirano polje");
	try{
	polja[x][y]=Polje::Posjeceno;
	x=novi_x; y=novi_y;
	if(polja[novi_x][novi_y]==Polje::Mina){
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[0].size(); j++){
				polja[i][j]=Polje::Prazno;
			}
		} return Status::KrajPoraz;
	} else{
		int brojac(0);
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja[0].size(); j++){
				if(polja[i][j]!=Polje::Prazno) brojac++;
			}
		}
		if(brojac==0){
			return Status::NijeKraj;
		} else{ return Status::KrajPobjeda;} 
	}
	} catch(std::out_of_range izuzetak1){
		std::cout<<izuzetak1.what()<<std::endl;
	} catch(std::logic_error izuzetak2){
		std::cout<<izuzetak2.what()<<std::endl;
	}
}

void PrijaviGresku(KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda){
		std::cout<<"Nerazumljiva komanda!"<<std::endl;
	}
	if(greska==KodoviGresaka::NedostajeParametar){
		std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	}
	if(greska==KodoviGresaka::NeispravanParametar){
		std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	}
	if(greska==KodoviGresaka::SuvisanParametar){
		std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
	}
}

int main (){
	


	return 0;
}