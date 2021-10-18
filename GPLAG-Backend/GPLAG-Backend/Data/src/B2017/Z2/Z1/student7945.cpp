//B 2017/2018, Zadaća 2, Zadatak 1
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

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

typedef std::vector<std::vector<int>> Matrica;
typedef std::vector<std::vector<Polje>> Tabla;

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0){
	try {
		
		
		
		
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	catch(std::out_of_range izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	catch(std::logic_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
}


bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string s;

}


void Prijavigresku(KodoviGresaka greska){
	switch (greska) {
		case KodoviGresaka::PogresnaKomanda : std::cout<<"Nerazumljiva komanda!"; break;
		case KodoviGresaka::NedostajeParametar : std::cout<<"Komanda trazi parametar koji nije naveden!"; break;
		case KodoviGresaka::NeispravanParametar : std::cout<<"Parametar komande nije ispravan!"; break;
		case KodoviGresaka::SuvisanParametar : std::cout<<"Zadan je suvisan parametar nakon komande!"; break;
	}
}

Tabla KreirajIgru(int n, const Matrica &mine){
	Tabla kreirana_tabla(0);
	if(n<=0){
		throw std::domain_error ("Ilegalna velicina");
		return kreirana_tabla;
	}
	if(mine.at(0).size()!=2){
		throw std::domain_error ("Ilegalan format zadavanja mina");
	}
	for(int i=0; i<mine.size(); i++){
		for(int j=0; j<mine.at(i).size(); j++){
			if(mine.at(i).at(j)>n || mine.at(i).at(j)<0){
				throw std::domain_error ("Ilegalne pozicije mina");
			}
		}
	}
	//Postavljamo tablu na prazna polja
	kreirana_tabla.resize(n);
	for(int i=0; i<n; i++){
		kreirana_tabla.at(i).resize(n);
		for(int j=0; j<n; j++){
			kreirana_tabla.at(i).at(j)=Polje::Prazno;
		}
	}
	//Postavljamo mine u tablu
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<mine.size(); k++){
				if(i==mine.at(k).at(0) && j==mine.at(k).at(1)){
					kreirana_tabla.at(i).at(j)=Polje::Mina;
				}
			}
		}
	}
	return kreirana_tabla;
}

int OkolinaTacke(const Tabla &polja, int x, int y){
	int br_mina(0);
	int vel(polja.size());
	if(x-1>=0 && x-1<=vel && y-1>=0 && y-1<=vel && polja.at(x-1).at(y-1)==Polje::Mina) br_mina++;
	if(x-1>=0 && x-1<=vel && y>=0 && y<=vel && polja.at(x-1).at(y)==Polje::Mina) br_mina++;
	if(x-1>=0 && x-1<=vel && y+1>=0 && y+1<=vel && polja.at(x-1).at(y+1)==Polje::Mina) br_mina++;
	if(x>=0 && x<=vel && y-1>=0 && y-1<=vel && polja.at(x).at(y-1)==Polje::Mina) br_mina++;
	if(x>=0 && x<=vel && y+1>=0 && y+1<=vel && polja.at(x).at(y+1)==Polje::Mina) br_mina++;
	if(x+1>=0 && x+1<=vel && y-1>=0 && y-1<=vel && polja.at(x+1).at(y-1)==Polje::Mina) br_mina++;
	if(x+1>=0 && x+1<=vel && y>=0 && y<=vel && polja.at(x+1).at(y)==Polje::Mina) br_mina++;
	if(x+1>=0 && x+1<=vel && y+1>=0 && y+1<=vel && polja.at(x+1).at(y+1)==Polje::Mina) br_mina++;
	
	return br_mina;
}

Matrica PrikaziOkolinu(const Tabla &polja, int x, int y){
	if(x>polja.size() || y>polja.size() || x<0 || y<0 ){
		throw std::domain_error ("Polje (x,y) ne postoji");
	}
	Matrica okolina(3);
	for(int i=0; i<3; i++){
		okolina.at(i).resize(3);
	}
	int vel(polja.size());
	if(x-1>=0 && x-1<=vel && y-1>=0 && y-1<=vel) okolina.at(0).at(0)=OkolinaTacke(polja,x-1,y-1);
	else okolina.at(0).at(0)=0;
	if(x-1>=0 && x-1<=vel) okolina.at(0).at(1)=OkolinaTacke(polja,x-1,y);
	else okolina.at(0).at(1)=0;
	if(x-1>=0 && x-1<=vel && y+1>=0 && y+1<=vel) okolina.at(0).at(2)=OkolinaTacke(polja,x-1,y+1);
	else okolina.at(0).at(2)=0;
	if(y-1>=0 && y-1<=vel) okolina.at(1).at(0)=OkolinaTacke(polja,x,y-1);
	else okolina.at(1).at(0)=0;
	okolina.at(1).at(1)=OkolinaTacke(polja,x,y);
	if(y+1>=0 && y+1<=vel) okolina.at(1).at(2)=OkolinaTacke(polja,x,y+1);
	else okolina.at(1).at(2)=0;
	if(x+1>=0 && x+1<=vel && y-1>=0 && y-1<=vel) okolina.at(2).at(0)=OkolinaTacke(polja,x+1,y-1);
	else okolina.at(2).at(0)=0;
	if(x+1>=0 && x+1<=vel) okolina.at(2).at(1)=OkolinaTacke(polja,x+1,y);
	else okolina.at(2).at(1)=0;
	if(x+1>=0 && x+1<=vel && y+1>=0 && y+1<=vel) okolina.at(2).at(2)=OkolinaTacke(polja,x+1,y+1);
	else okolina.at(2).at(2)=0;
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y){
		if(x>polja.size() || y>polja.size() || x<0 || y<0 ){
		throw std::domain_error ("Polje (x,y) ne postoji");
	}
	if(polja.at(x).at(y)==Polje::Prazno){
		polja.at(x).at(y)=Polje::BlokiranoPrazno;
	}
	else if(polja.at(x).at(y)==Polje::Posjeceno){
		polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
	}	
	else if(polja.at(x).at(y)==Polje::Mina){
		polja.at(x).at(y)=Polje::BlokiranoMina;
	}
}
void DeblokirajPolje(Tabla &polja, int x, int y){
	if(x>polja.size() || y>polja.size() || x<0 || y<0 ){
		throw std::domain_error ("Polje (x,y) ne postoji");
	}
	if(polja.at(x).at(y)==Polje::BlokiranoPrazno){
		polja.at(x).at(y)=Polje::Prazno;
	}
	else if(polja.at(x).at(y)==Polje::BlokiranoPosjeceno){
		polja.at(x).at(y)=Polje::Posjeceno;
	}	
	else if(polja.at(x).at(y)==Polje::BlokiranoMina){
		polja.at(x).at(y)=Polje::Mina;
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	polja.at(x).at(y)=Polje::Posjeceno;
	int vel(polja.size());
	switch(smjer) {
		case Smjerovi::GoreLijevo : 
			if(x==0 || y==0) throw std::out_of_range ("Izlazak van igrace table");
			x=x-1; y=y-1; break;
		case Smjerovi::Gore : 
			if(x==0) throw std::out_of_range ("Izlazak van igrace table");
			x=x-1; break;
		case Smjerovi::GoreDesno : 
			if(x==0 || y==vel-1) throw std::out_of_range ("Izlazak van igrace table");
			x=x-1; y=y+1; break;
		case Smjerovi::Desno : 
			if(y==vel-1) throw std::out_of_range ("Izlazak van igrace table");
			y=y+1; break;
		case Smjerovi::DoljeDesno : 
			if(x==vel-1 || y==vel-1) throw std::out_of_range ("Izlazak van igrace table");
			x=x+1; y=y+1; break;
		case Smjerovi::Dolje : 
			if(x==vel-1) throw std::out_of_range ("Izlazak van igrace table");
			x=x+1; break;
		case Smjerovi::DoljeLijevo : 
			if(x==vel-1 || y==0) throw std::out_of_range ("Izlazak van igrace table");
			x=x+1; y=y-1; break;
		case Smjerovi::Lijevo : 
			if(y==0) throw std::out_of_range ("Izlazak van igrace table");
			y=y-1; break;
	} 
	if(polja.at(x).at(y)==Polje::BlokiranoPrazno || polja.at(x).at(y)==Polje::BlokiranoPosjeceno 
		|| polja.at(x).at(y)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
	
	//Provjera da li je krajporaz
	if(polja.at(x).at(y)==Polje::Mina) {
		for(int i=0; i<polja.size(); i++){
			for(int j=0; j<polja.at(i).size(); j++){
				polja.at(i).at(j)=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	//Provjera da li je krajpobjeda
	int br_polja(vel*vel);
	int br_mina(0), br_posjeceno(0);
	for(int i=0; i<vel; i++){
		for(int j=0; j<vel; j++){
			if(polja.at(i).at(j)==Polje::Mina) br_mina++;
			else if(polja.at(i).at(j)==Polje::Posjeceno) br_posjeceno++;
		}
	}
	if(br_polja==br_mina+br_posjeceno) return Status::KrajPobjeda;

	return Status::NijeKraj;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	polja.at(x).at(y)=Polje::Posjeceno;
	int vel(polja.size());
	if(novi_x<0 || novi_x>vel-1 || novi_y<0 || novi_y>vel-1) throw std::out_of_range ("Izlazak van igrace table");
	if(polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno 
		|| polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina) throw std::logic_error ("Blokirano polje");
	if(polja.at(novi_x).at(novi_y)==Polje::Mina) return Status::KrajPoraz;
	x=novi_x; y=novi_y;
	
	//provjera za krajpobjeda
	
	return Status::NijeKraj;
}

int main ()
{
	
	return 0;
}