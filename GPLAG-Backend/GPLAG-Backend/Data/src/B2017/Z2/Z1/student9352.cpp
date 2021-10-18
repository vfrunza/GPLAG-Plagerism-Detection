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
#include <complex>
#include <stdexcept>

enum class Polje {Prazno,Posjeceno,Mina,BlokiranoPrazno,BlokiranoPosjeceno,BlokiranoMina};
enum class Smjerovi {GoreLijevo,Gore,GoreDesno,Desno,DoljeDesno,Dolje,DoljeLijevo,Lijevo};
enum class Status {NijeKraj,KrajPoraz,KrajPobjeda};
enum class KodoviGresaka {PogresnaKomanda,NedostajeParametar,SuvisanParametar,NeispravanParametar};
enum class Komande {PomjeriJednoMjesto,PomjeriDalje,Blokiraj,Deblokiraj,PrikaziOkolinu,ZavrsiOkolinu,KreirajIgru};

typedef std::vector<std::vector<Polje>> Tabla;
typedef std::vector<std::vector<int>> Matrica;

Tabla KreirajIgru(int n,const Matrica &mine)
{

	if(n<1) throw std::domain_error("Ilegalna velicina");

	Tabla Minesweeper(n,std::vector<Polje> (n,Polje::Prazno));

	for(int i=0; i<mine.size(); i++)
		for(int j=0; j<mine.at(i).size(); j++) {
			if(mine.at(0).size()!=mine.at(i).size() || mine.at(i).size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
			if(mine.at(i).at(j)>n-1 || mine.at(i).at(j)<0) throw std::domain_error("Ilegalne pozicije mine");
		}

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<mine.size(); k++)
				if(mine.at(k).at(0)==i && mine.at(k).at(1)==j) {
					Minesweeper.at(i).at(j)=Polje::Mina;
					break;
				}

	return Minesweeper;
}

Tabla ProsiriMinesweeper(Tabla &Minesweeper)
{
	Minesweeper.insert(std::begin(Minesweeper),std::vector<Polje> (Minesweeper.at(0).size(),Polje::Prazno));
	Minesweeper.push_back(std::vector<Polje> (Minesweeper.at(0).size(),Polje::Prazno));
	for(int i=0; i<Minesweeper.size(); i++)
		for(int j=0; j<Minesweeper.at(i).size(); j++)
			if(j==0) Minesweeper.at(i).insert(std::begin(Minesweeper.at(i))+0,Polje::Prazno);

	for(int i=0; i<Minesweeper.size(); i++)
		for(int j=0; j<Minesweeper.at(i).size(); j++)
			if(j==Minesweeper.at(i).size()-1) {
				Minesweeper.at(i).push_back(Polje::Prazno);
				break;
			}

	return Minesweeper;
}

Matrica PrikaziOkolinu(const Tabla &polja,int x,int y)
{

	if(x<0 || y<0 || x>polja.size()-1 || y>polja.at(0).size()-1) {
		std::string Izuzetak("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
		throw std::domain_error(Izuzetak);
	}

	Tabla KopijaMinesweeper(polja);

	if(x==0 || y==0 || x==polja.size() || y==polja.at(0).size()) {
		KopijaMinesweeper=ProsiriMinesweeper(KopijaMinesweeper);
		KopijaMinesweeper=ProsiriMinesweeper(KopijaMinesweeper);
		x=x+2;
		y=y+2;
	}

	if((x==1 && y>0 && y<polja.at(0).size()-1)||(y==1 && x>0 && x<polja.size()-1)||(x==polja.size()-2 && y>0 && y<polja.at(0).size()-1)||(y==polja.at(0).size()-2 && x>0 && x<polja.size()-1)) {
		KopijaMinesweeper=ProsiriMinesweeper(KopijaMinesweeper);
		x=x+1;
		y=y+1;
	}

	Matrica IntKopijaMineSweeper;
	IntKopijaMineSweeper.resize(KopijaMinesweeper.size());

	for(int i=0; i<KopijaMinesweeper.size(); i++)
		for(int j=0; j<KopijaMinesweeper.at(i).size(); j++) IntKopijaMineSweeper.at(i).push_back(int(KopijaMinesweeper.at(i).at(j)));

	Matrica PronalazakOkoline;
	PronalazakOkoline.resize(5);
	for(int i=x-2; i<=x+2; i++)
		for(int j=y-2; j<=y+2; j++) PronalazakOkoline.at(i).push_back(IntKopijaMineSweeper.at(i).at(j));

	Matrica OkolineElemenata;
	OkolineElemenata.resize(3);
	int BrojacRedova=0;
	int brojac=0;

	for(int i=x-2; i<=x+2; i++) {
		if(i==x-2 || i==x+2) continue;
		for(int j=y-2; j<=y+2; j++) {
			if(j==y-2 || j==y+2) continue;
			brojac=0;
			for(int k=i-1; k<=i+1; k++)
				for(int l=j-1; l<=j+1; l++) {
					if(k==i && l==j) continue;
					if(PronalazakOkoline.at(k).at(l)==int(Polje::Mina)) brojac++;
				}
			OkolineElemenata.at(BrojacRedova).push_back(brojac);
		}
		BrojacRedova++;
	}

	return OkolineElemenata;

}

void BlokirajPolje(Tabla &polja,int x,int y)
{
	if(x<0 || y<0 || x>polja.size()-1 || y>polja.at(0).size()-1) {
		std::string Izuzetak("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
		throw std::domain_error(Izuzetak);
	}

	for(int i=0; i<polja.size(); i++)
		for(int j=0; j<polja.at(i).size(); j++) {
			if(i==x && j==y && polja.at(i).at(j)==Polje::Prazno) polja.at(i).at(j)=Polje::BlokiranoPrazno;
			if(i==x && j==y && polja.at(i).at(j)==Polje::Posjeceno) polja.at(i).at(j)=Polje::BlokiranoPosjeceno;
			if(i==x && j==y && polja.at(i).at(j)==Polje::Mina) polja.at(i).at(j)=Polje::BlokiranoMina;
		}
}

void DeblokirajPolje(Tabla &polja,int x,int y)
{

	if(x<0 || y<0 || x>polja.size()-1 || y>polja.at(0).size()-1) {
		std::string Izuzetak("Polje ("+std::to_string(x)+","+std::to_string(y)+") ne postoji");
		throw std::domain_error(Izuzetak);
	}

	for(int i=0; i<polja.size(); i++)
		for(int j=0; j<polja.at(i).size(); j++) {
			if(i==x && j==y && polja.at(i).at(j)==Polje::BlokiranoPrazno) polja.at(i).at(j)=Polje::Prazno;
			if(i==x && j==y && polja.at(i).at(j)==Polje::BlokiranoPosjeceno) polja.at(i).at(j)=Polje::Posjeceno;
			if(i==x && j==y && polja.at(i).at(j)==Polje::BlokiranoMina) polja.at(i).at(j)=Polje::Mina;

		}
}

Status Idi(Tabla &polja,int &x,int &y,Smjerovi smjer)
{

	//Provjeravanje da li cemo nakon pomjeranja izaci iz tabele.

	if(x==0 && y==0 && (smjer==Smjerovi::Lijevo || smjer==Smjerovi::GoreLijevo || smjer==Smjerovi::Gore || smjer==Smjerovi::DoljeLijevo || smjer==Smjerovi::GoreDesno)) throw std::out_of_range("Izlazak van igrace table");

	if(x==polja.size()-1 && y==0 && (smjer==Smjerovi::Lijevo || smjer==Smjerovi::DoljeLijevo || smjer==Smjerovi::Dolje || smjer==Smjerovi::GoreLijevo || smjer==Smjerovi::DoljeDesno)) throw std::out_of_range("Izlazak van igrace table");

	if(x==0 && y==polja.at(0).size()-1 && (smjer==Smjerovi::Gore || smjer==Smjerovi::GoreDesno || smjer==Smjerovi::Desno || smjer==Smjerovi::GoreLijevo || smjer==Smjerovi::DoljeDesno)) throw std::out_of_range("Izlazak van igrace table");

	if(x==polja.size()-1 && y==polja.at(0).size()-1 && (smjer==Smjerovi::Dolje || smjer==Smjerovi::DoljeDesno || smjer==Smjerovi::Desno || smjer==Smjerovi::DoljeLijevo || smjer==Smjerovi::GoreDesno)) throw std::out_of_range("Izlazak van igrace table");

	if(x==0 && y>0 && y<polja.at(0).size()-1 && (smjer==Smjerovi::GoreLijevo || smjer==Smjerovi::Gore || smjer==Smjerovi::GoreDesno)) throw std::out_of_range("Izlazak van igrace table");

	if(x==polja.size()-1 && y>0 && y<polja.at(0).size()-1 && (smjer==Smjerovi::DoljeLijevo || smjer==Smjerovi::Dolje || smjer==Smjerovi::DoljeDesno)) throw std::out_of_range("Izlazak van igrace table");

	if(y==0 && x>0 && x<polja.size()-1 && (smjer==Smjerovi::GoreLijevo || smjer==Smjerovi::Lijevo || smjer==Smjerovi::DoljeLijevo)) throw std::out_of_range("Izlazak van igrace table");

	if(y==polja.at(0).size()-1 && x>0 && x<polja.size()-1 && (smjer==Smjerovi::GoreDesno || smjer==Smjerovi::Desno || smjer==Smjerovi::DoljeDesno)) throw std::out_of_range("Izlazak van igrace table");



	//Pomjeranje robota-igraca na zeljeno polje.
	if(smjer==Smjerovi::Gore) {
		if(polja.at(x-1).at(y)==Polje::BlokiranoPrazno || polja.at(x-1).at(y)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else x=x-1;
	}

	if(smjer==Smjerovi::Desno) {
		if(polja.at(x).at(y-1)==Polje::BlokiranoPrazno || polja.at(x).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x).at(y-1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else y=y-1;
	}

	if(smjer==Smjerovi::Dolje) {
		if(polja.at(x+1).at(y)==Polje::BlokiranoPrazno || polja.at(x+1).at(y)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else x=x+1;
	}
	if(smjer==Smjerovi::Lijevo) {
		if(polja.at(x).at(y-1)==Polje::BlokiranoPrazno || polja.at(x).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x).at(y-1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else y=y-1;
	}
	if(smjer==Smjerovi::GoreLijevo) {
		if(polja.at(x-1).at(y-1)==Polje::BlokiranoPrazno || polja.at(x-1).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y-1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else {
			x=x-1;
			y=y-1;
		}
	}
	if(smjer==Smjerovi::GoreDesno) {
		if(polja.at(x-1).at(y+1)==Polje::BlokiranoPrazno || polja.at(x-1).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x-1).at(y+1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else {
			x=x-1;
			y=y+1;
		}
	}
	if(smjer==Smjerovi::DoljeLijevo) {
		if(polja.at(x+1).at(y-1)==Polje::BlokiranoPrazno || polja.at(x+1).at(y-1)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y-1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else {
			x=x+1;
			y=y-1;
		}
	}
	if(smjer==Smjerovi::DoljeDesno) {
		if(polja.at(x+1).at(y+1)==Polje::BlokiranoPrazno || polja.at(x+1).at(y+1)==Polje::BlokiranoPosjeceno || polja.at(x+1).at(y+1)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");
		else {
			x=x+1;
			y=y+1;
		}
	}



	//Uspjesno smo pomjerili igraca na polje koje je ili prazno ili vec posjeceno ili se na tom polju nalazi mina. Proverimo kako ce se dalje odvijati tok igre.
	if(polja.at(x).at(y)==Polje::Mina) return Status::KrajPoraz;

	polja.at(x).at(y)=Polje::Posjeceno;

	for(int i=0; i<polja.size(); i++)
		for(int j=0; j<polja.at(i).size(); j++) if(polja.at(i).at(j)==Polje::Prazno) return Status::NijeKraj;

	return Status::KrajPobjeda;

}

Status Idi(Tabla &polja,int &x,int &y,int novi_x,int novi_y)
{

	//Provjeravamo da li smo stali na legalno polje,unutar igrace table.
	if(novi_x<0 || novi_y<0 || novi_x>polja.size()-1 || novi_y>polja.at(0).size()-1) throw std::out_of_range("Izlazak van igrace table");

	//Provjeravamo da li smo stali na polje je blokirano.
	if(polja.at(novi_x).at(novi_y)==Polje::BlokiranoPrazno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoPosjeceno || polja.at(novi_x).at(novi_y)==Polje::BlokiranoMina) throw std::logic_error("Blokirano polje");

	//Uspjesno smo pomjerili robota-igraca, sada trebamo vidjeti kako ce se dalje odvijati igra.
	x=novi_x;
	y=novi_y;

	if(polja.at(x).at(y)==Polje::Mina) return Status::KrajPoraz;

	polja.at(x).at(y)=Polje::Posjeceno;

	for(int i=0; i<polja.size(); i++)
		for(int j=0; j<polja.at(0).size(); j++) if(polja.at(i).at(j)==Polje::Prazno) return Status::NijeKraj;

	return Status::KrajPobjeda;

}

int main ()
{
	 std::vector<std::vector<int>> mine = {{0,1}, {0,4}, {1,3}, {1,4}, {2,0}, {2,1}, {2,3}} ;
    std::vector<std::vector<Polje>> tabla = KreirajIgru(5, mine);
    std::vector<std::vector<int>> okolina = PrikaziOkolinu(tabla, 0, 0);
    for(int i = 0; i < okolina.size(); i++)
    {
      for(int j = 0; j < okolina[i].size(); j++) std::cout << okolina[i][j] << " ";
      std::cout << std::endl;
    }
	return 0;
}