#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

typedef std::vector<std::vector<Polje>> Tabla;

enum class Polje {Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina};
enum class Smjerovi {GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo};
enum class Status {NijeKraj, KrajPoraz, KrajPobjeda};
enum class Komande {PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru};
enum class KodoviGresaka {PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar};


Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){                                              //   <-------------KREIRANJE TABELE
	Tabla T(n, std::vector<Polje> (n, Prazno));                                                                      //format je n, same pozcije idu od 0 do n-1
	for(int i(0);i<mine.size();i++){                                                                               //provjeravanje izuzetaka
	    if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	    if((mine[i][0]>=n)||(mine[i][1]>=n)) throw std::domain_error("Ilegalne pozicije mina");
	}
	for(int i(0);i<mine.size();i++){
	    T[mine[i][0]][mine[i][1]]=Mina;                                                                       //stavljanje mina, i kraj funkcije
	}
	return T;
	
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){                                   //   <-------------PRIKAZ OKOLINE
	std::vector<std::vector<int>> Okolina(3, std::vector<int>(3));
	
}

void BlokirajPolje(Tabla &polja, int x, int y){                                                                //<-------------BLOKIRANJE                                                
	if(x>=polja.size())||(y>=polja[0].size()) throw std::domain_error("Polje (x,y) ne postoji");
	if(polja[x][y]==Prazno) polja[x][y]=BlokiranoPrazno;
	else if(polja[x][y]==Posjeceno) polja[x][y]=BlokiranoPosjeceno;
	else if(polja[x][y]==Mina) polja[x][y]=BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x, int y){                                                  // <------------DEBLOKIRAJ                                                             
	if(x>=polja.size())||(y>=polja[0].size()) throw std::domain_error("Polje (x,y) ne postoji");
	if(polja[x][y]==BlokiranoPrazno) polja[x][y]=Prazno;
	else if(polja[x][y]==BlokiranoPosjeceno) polja[x][y]=Posjeceno;
	else if(polja[x][y]==BlokiranoMina) polja[x][y]=Mina;
}
bool Pobjeda(Tabla &polja){                                                                             //<--------------------PROVJERA POBJEDE
	for(int i(0);i<polja.size();i++){
		for(int j(0);j<polja[0].size();j++){
			if(polja[i][j]==Prazno) return false;
		}
	}
	return true;
}

void HardReset(Tabla &polja){                                                                     //<------------------RESET NAKON PORAZA
	for(int i(0);i<polja.size();i++){
		for(int j(0);j<polja[0].size();j++){
			polja[i][j]=Prazno;
		}
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){                              //  <--------IDI 1 KORAK
    int rx, ry;
    rx=polja.size()-1;
    ry=polja[0].size()-1;
	if((smjer==Gore)&&(x!=0)) {polja[x][y]=Posjeceno; x--;}                                     //<----------DOMAIN ERRORE NAPISATI SUTRA!!!!
	else if((smjer==GoreDesno)&&(x!=0)&&(y!=ry)) {polja[x][y]=Posjeceno; x--; y++;}
	else if((smjer==Desno)&&(y!=ry)) {polja[x][y]=Posjeceno; y++;}
	else if((smjer==DoljeDesno)&&(x!=rx)&&(y!=ry)) {polja[x][y]=Posjeceno; x++; y++;}
	else if((smjer==Dolje)&&(x!=rx)) {polja[x][y]=Posjeceno; x++;}
	else if((smjer==DoljeLijevo)&&(x!=rx)&&(y!=0)) {polja[x][y]=Posjeceno; x++; y--;}
	else if((smjer==Lijevo)&&(y!=0)) {polja[x][y]=Posjeceno; y--;}
	else if((smjer==GoreLijevo)&&(x!=0)&&(y!=0)) {polja[x][y]=Posjeceno; x--; y--;}
	
	else throw std:out_of_range("Izlazak van igrace table");
	
	Status stat;
	if(polja[x][y]==Mina) {stat=KrajPoraz; HardReset(polja); return stat;}
	else if(Pobjeda(polja)) {stat=KrajPobjeda; return stat;}
	else {stat=NijeKraj, return stat;}
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){                    //  <-------IDI NA POZICIJU
	
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){           // <-------- OKOLINA OPET, VALJDA IZBIRSATI TREBA???
	
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::string unos;
	std::getline(unos, 100);
	if(unos[0]=='P')
}

void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer = Smjerovi::Gore, int p_x = 0, int p_y = 0){
	
}

int main ()
{
	return 0;
}