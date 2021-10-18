/*B 2017/2018, Zadaća 2, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>



enum class Polje { Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina } ;
enum class Smjerovi { GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo };
enum class Status { NijeKraj, KrajPobjeda, KrajPoraz };
enum class KodoviGresaka { PogresnaKomanda, NedostajeParametar, SuvisanParametar, NeispravanParametar };
enum class Komande { PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu, ZavrsiIgru, KreirajIgru };

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine){
	if(n<=0) throw std::domain_error("Ilegalna velicina");
	Tabla polja (n, std::vector<Polje>(n));
	for(int i(0);i<mine.size();i++){
		if(mine.at(i).size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	}
	for(int i(0);i<mine.size();i++){
		for(int j(0);j<mine.at(i).size();j++){
			if(mine.at(i).at(j)<0 || mine.at(i).at(j)>n) throw std::domain_error("Ilegalne pozicije mina");
		}
	}
	for(int i(0);i<mine.size();i++){
		polja.at(mine.at(i).at(0)).at(mine.at(i).at(1))=Polje::Mina;
	}
	return polja;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y){
	if(x<0 || x>polja.size() || y<0 || y>polja.size()) throw std::domain_error("Polje(x,y) ne postoji");
	std::vector<std::vector<int>> okolina(3,std::vector<int>(3));
	int ogrx1(x-1),ogrx2(x+1),ogry1(y-1),ogry2(y+1);
	if(ogrx1<0) ogrx1=0;
	if(ogry1<0) ogry1=0;
	if(ogrx2>polja.size()) ogrx2=polja.size();
	if(ogry2>polja.size()) ogry2=polja.size();
	int i(0),j(0);
	for(int k(ogrx1);k<=ogrx2;k++){
		for(int l(ogry1);l<=ogry2;l++){
			int ogrk1(k-1),ogrk2(k+1),ogrl1(l-1),ogrl2(l+1);
	 		if(ogrk1<0) ogrk1=0;
			if(ogrl1<0) ogrl1=0;
			if(ogrk2>polja.size()) ogrk2=polja.size();
			if(ogrl2>polja.size()) ogrl2=polja.size();
				for(int m(ogrk1);m<=ogrk2;m++){
					for(int n(ogrl1);n<=ogrl2;n++){
						if(!(k==m && l==n)) {
							if(polja.at(m).at(n)==Polje::Mina) okolina.at(i).at(j)++;
						}
					}
				
				}
				j++;
		}
		j=0;
		i++;
	}
	return okolina;
}

void BlokirajPolje(Tabla &polja, int x, int y){
	if(x<0 || y<0 || polja.size()<x || polja.size()<y) throw std::domain_error("Polje (x,y) ne postoji");
	if(polja.at(x).at(y)==Polje::Prazno) polja.at(x).at(y)=Polje::BlokiranoPrazno;
	if(polja.at(x).at(y)==Polje::Posjeceno) polja.at(x).at(y)=Polje::BlokiranoPosjeceno;
	if(polja.at(x).at(y)==Polje::Mina) polja.at(x).at(y)=Polje::BlokiranoMina;
}

void DeblokirajPolje(Tabla &polja, int x , int y){
	if(x<0 || y<0 || polja.size()<x || polja.size()<y) throw std::domain_error("Polje (x,y) ne postoji");
	if(polja.at(x).at(y)==Polje::BlokiranoPrazno) polja.at(x).at(y)=Polje::Prazno;
	if(polja.at(x).at(y)==Polje::BlokiranoPosjeceno) polja.at(x).at(y)=Polje::Posjeceno;
	if(polja.at(x).at(y)==Polje::BlokiranoMina) polja.at(x).at(y)=Polje::Mina;
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer){
	int pomx(x),pomy(y);
	if(smjer==Smjerovi::GoreLijevo){
		if(x-1<0 || y-1<0) throw std::out_of_range("Izlazak van igrace table");
		if(polja.at(x-1).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y-1)==Polje::BlokiranoPrazno || polja.at(x-1).at(y-1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		if(polja.at(x-1).at(y-1)==Polje::Mina){ 
			for(int i(0);i<polja.size();i++){
				for(int j(0);j<polja.at(i).size();j++){
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		x--;
		y--;
	}
	if(smjer==Smjerovi::Gore){
		if(x-1<0) throw std::out_of_range("Izlazak van igrace table");
		if(polja.at(x-1).at(y)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y)==Polje::BlokiranoPrazno || polja.at(x-1).at(y)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		if(polja.at(x-1).at(y)==Polje::Mina){ 
			for(int i(0);i<polja.size();i++){
				for(int j(0);j<polja.at(i).size();j++){
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		x--;
	}
	if(smjer==Smjerovi::GoreDesno){
		if(x-1<0 || y+1>polja.size()) throw std::out_of_range("Izlazak van igrace table");
		if(polja.at(x-1).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y+1)==Polje::BlokiranoPrazno || polja.at(x-1).at(y+1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		if(polja.at(x-1).at(y+1)==Polje::Mina){ 
			for(int i(0);i<polja.size();i++){
				for(int j(0);j<polja.at(i).size();j++){
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		x--;
		y++;
	}
	
	if(smjer==Smjerovi::Desno){
		if(y+1>polja.size()) throw std::out_of_range("Izlazak van igrace table");
		if(polja.at(x).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x).at(y+1)==Polje::BlokiranoPrazno || polja.at(x).at(y+1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		if(polja.at(x).at(y+1)==Polje::Mina){ 
			for(int i(0);i<polja.size();i++){
				for(int j(0);j<polja.at(i).size();j++){
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		y++;
	}
	if(smjer==Smjerovi::DoljeDesno){
		if(x+1>polja.size() || y+1>polja.size()) throw std::out_of_range("Izlazak van igrace table");
		if(polja.at(x+1).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y+1)==Polje::BlokiranoPrazno || polja.at(x+1).at(y+1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		if(polja.at(x+1).at(y+1)==Polje::Mina){ 
			for(int i(0);i<polja.size();i++){
				for(int j(0);j<polja.at(i).size();j++){
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		x++;
		y++;
	}
	
	if(smjer==Smjerovi::Dolje){
		if(x+1>polja.size()) throw std::out_of_range("Izlazak van igrace table");
		if(polja.at(x+1).at(y)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y)==Polje::BlokiranoPrazno || polja.at(x+1).at(y)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		if(polja.at(x+1).at(y)==Polje::Mina){ 
			for(int i(0);i<polja.size();i++){
				for(int j(0);j<polja.at(i).size();j++){
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		x++;
	}
	
	if(smjer==Smjerovi::DoljeLijevo){
		if(x+1>polja.size() || y-1<0) throw std::out_of_range("Izlazak van igrace table");
		if(polja.at(x+1).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y-1)==Polje::BlokiranoPrazno || polja.at(x+1).at(y-1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		if(polja.at(x+1).at(y-1)==Polje::Mina){ 
			for(int i(0);i<polja.size();i++){
				for(int j(0);j<polja.at(i).size();j++){
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
	}
	
	if(smjer==Smjerovi::Lijevo){
		if(y-1<0) throw std::out_of_range("Izlazak van igrace table");
		if(polja.at(x).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x).at(y-1)==Polje::BlokiranoPrazno || polja.at(x).at(y-1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		if(polja.at(x).at(y-1)==Polje::Mina){ 
			for(int i(0);i<polja.size();i++){
				for(int j(0);j<polja.at(i).size();j++){
					polja.at(i).at(j)=Polje::Prazno;
				}
			}
			return Status::KrajPoraz;
		}
		x++;
		y--;
	}
	polja.at(pomx).at(pomy)=Polje::Posjeceno;
	for(int i(0);i<polja.size();i++){
		for(int j(0);j<polja.size();j++){
			if(polja.at(i).at(j)==Polje::Prazno) return Status::NijeKraj; 
		}
	}
	return Status::KrajPobjeda;
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y){
	if(novi_x<0 || novi_y<0 || novi_x>polja.size() ||novi_y>polja.size()) throw std::out_of_range("Izlazak van igrace table");
	if(polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
	if(polja.at(novi_x).at(novi_y)==Polje::Mina) {
		for(int i(0);i<polja.size();i++){
			for(int j(0);j<polja.at(i).size();j++){
				polja.at(i).at(j)=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;
	}
	polja.at(x).at(y)=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;
	for(int i(0);i<polja.size();i++){
		for(int j(0);j<polja.size();j++){
			if(polja.at(i).at(j)==Polje::Prazno) return Status::NijeKraj; 
		}
	}
	return Status::KrajPobjeda;
}

void PrijaviGresku(KodoviGresaka greska){
	if(greska==KodoviGresaka::PogresnaKomanda) std::cout<<"Nerazumljiva komanda!"<<std::endl;
	if(greska==KodoviGresaka::NedostajeParametar) std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	if(greska==KodoviGresaka::NeispravanParametar) std::cout<<"Parametar komande nije spravan!"<<std::endl;
	if(greska==KodoviGresaka::SuvisanParametar) std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}

/*
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska){
	std::cout<<"Unesite komandu: ";
	std::string kom;
	std::cin>>kom;
	if(kom=="K") komanda=Komande::KreirajIgru;
	if(kom=="Z") komanda=Komande::ZavrsiIgru;
	if(kom=="PO") komanda=Komande::PrikaziOkolinu;
	if(kom=="P1 GL") {
		komanda=Komande::PomjeriJednoMjesto;
		smjer::Smjerovi::GoreLijevo;
	}
	if(kom=="P1 G"){
		komanda=Komande::PomjeriJednoMjesto;
		smjer=Smjerovi::Gore;
	}
	if(kom=="P1 GD"){
		komanda=Komande::PomjeriJednoMjesto;
		smjer=Smjerovi::GoreDesno;
	}
	if(kom=="P1 D"){
		komanda=Komande::PomjeriJednoMjesto;
		smjer=Smjerovi::Desno;
	}
	if(kom=="P1 DoD"){
		komanda=Komande::PomjeriJednoMjesto;
		smjer=Smjerovi::DoljeDesno;
	}
	if(kom=="P1 Do"){
		komanda=Komande::PomjeriJednoMjesto;
		smjer=Smjerovi::Dolje;
	}
	if(kom=="P1 DoL"){
		komanda=Komande::PomjeriJednoMjesto;
		smjer=Smjerovi::DoljeLijevo;
	}
	if(kom=="P1 L"){
		komanda=Komande::PomjeriJednoMjesto;
		smjer=Smjerovi::Lijevo;
	}
}
*/
void IzvrsiKomandu(Komande komanda, Tabla &polja, int &x, int &y, Smjerovi p_smjer=Smjerovi::Gore, int p_x=0, int p_y=0);




int main ()
{
	
	return 0;
}