#include <iostream>
#include <vector>
#include <stdexcept>

enum class Polje
{
    Prazno, Posjeceno, Mina,BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
enum class Smjerovi
{
    GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};
enum class Status
{
    NijeKraj, KrajPoraz, KrajPobjeda
};
enum class KodoviGresaka 
{
    PogresnaKomanda, NedostajeParmetar, SuvisanParametar, NeispravanParametar 
};
enum class Komande 
{
	PomjeriJednoMjesto, PomjeriDalje, Blokiraj, Deblokiraj, PrikaziOkolinu=, ZavrsiIgru, KreirajIgru
};

typedef std::vector<std::vector<Polje>> Tabla;

Tabla KreirajIgru(int n, const std::vector<std::vector<int>>& mine)
{
	if(n<=0) throw std::domain_error("Ilegalna velicina");

	for(int i=0; i<mine.size(); i++) {
		if(mine[i].size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
	}
	for(int i=0; i<mine.size(); i++) {
		for(int j=0; j<2; j++) {

			if(mine[i][j]>n-1)	throw std::domain_error("Ilegalne pozicije mina");

		}

	}
	Tabla mat(n,std::vector<Polje>(n,Polje::Prazno));

	for(int i=0; i<mine.size(); i++) {
		for(int j=0; j<1; j++) {
			mat[mine[i][j]][mine[i][j+1]]=Polje::Mina;

		}



	}

	return mat;
}





std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	if(x>polja.size() || x<0 || y>polja[0].size() || y<0) {
		throw std::domain_error("Polje (x, y) ne postoji");
	}

	std::vector<std::vector<int>> mat;
	std::vector<int> pomocni;
	int brojac(0);

	for(int i=x-1; i<=x+1; i++) {
		if(i>=0 && i<=polja.size()-1) {
			for(int j=y-1; j<=y+1; j++) {

				if(j>=0 && j<=polja[0].size()-1) {

					for(int k=i-1; k<=i+1; k++) {
						if( k>=0 && k<=polja.size()-1) {



							for(int m=j-1; m<=j+1; m++) {
								if(m>=0 && m<=polja[0].size()-1) {
									if(k==i && m==j) continue;
									if(polja[k][m]==Polje::Mina) brojac++;
								}
							}
						}

					}
				}
				pomocni.push_back(brojac);

				brojac=0;


			}
		}
		mat.push_back(pomocni);
		pomocni.resize(0);
	}



	return mat;
}



void BlokirajPolje(Tabla &polja, int x, int y)
{

	if(x>polja.size() || x<0 || y>polja[0].size() || y<0) {
		throw std::domain_error("Polje (x, y) ne postoji");
	}

	if(polja[x][y]==Polje::Prazno)	polja[x][y]=Polje::BlokiranoPrazno;
	else if (polja[x][y]==Polje::Posjeceno)	polja[x][y]=Polje::BlokiranoPosjeceno;
	else if (polja[x][y]==Polje::Mina)	polja[x][y]=Polje::BlokiranoMina;
}



void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(x>polja.size() || x<0 || y>polja[0].size() || y<0) {
		throw std::domain_error("Polje (x, y) ne postoji");
	}

	if(polja[x][y]==Polje::BlokiranoPrazno)	polja[x][y]=Polje::Prazno;
	else if (polja[x][y]==Polje::BlokiranoPosjeceno)	polja[x][y]=Polje::Posjeceno;
	else if (polja[x][y]==Polje::BlokiranoMina)	polja[x][y]=Polje::Mina;

}
Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{

	polja[x][y]=Polje::Posjeceno;
	if(smjer==Gore) x=x-1;
	else if(smjer==Smjerovi::GoreLijevo) {
		x=x-1;
		y=y-1;
	} else if(smjer==Smjerovi::GoreDesno) {
		x=x-1;
		y=y+1;
	} else if(smjer==Smjerovi::Desno) {
		y=y+1;
	} else if(smjer==Smjerovi::Lijevo) {
		y=y-1;
	} else if(smjer==Smjerovi::Dolje) {
		x=x+1;

	} else if(smjer==Smjerovi::DoljeDesno) {
		x=x+1;
		y=y+1;
	} else if(smjer==Smjerovi::DoljeLijevo) {
		x=x+1;
		y=y-1;
	}

	if(polja[x][y]==Polje::Mina) {
		for(int i=0; i<polja.size(); i++) {
			for(int j=0; j<polja[0].size(); j++) {
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;

	}

	int brojac(0);
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja[0].size(); j++) {

			if(polja[i][j]==Polje::Prazno) {
				brojac++;

			}

		}
	}

	if(brojac==1) return Status::KrajPobjeda;
	else return Status::NijeKraj;

}

Status Idi(Tabla &polja, int& x, int &y, int novi_x, int novi_y)
{
	if(novi_x>polja.size() || novi_x<0 || novi_y>polja[0].size() || novi_y<0) {
		throw std::out_of_range("Izlazak van igrace table");

	}
	if(polja[novi_x][novi_y]==Polje::BlokiranoPosjeceno || polja[novi_x][novi_y]==Polje::BlokiranoPrazno || polja[novi_x][novi_y]==Polje::BlokiranoMina) {
		throw std::logic_error("Blokirano polje");

	}
	polja[x][y]=Polje::Posjeceno;
	x=novi_x;
	y=novi_y;

	if(polja[x][y]==Polje::Mina) {
		for(int i=0; i<polja.size(); i++) {
			for(int j=0; j<polja[0].size(); j++) {
				polja[i][j]=Polje::Prazno;
			}
		}
		return Status::KrajPoraz;

	}

	int brojac(0);
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja[0].size(); j++) {

			if(polja[i][j]==Polje::Prazno) {
				brojac++;

			}

		}
	}

	if(brojac==1) return Status::KrajPobjeda;
	else return Status::NijeKraj;
}

void PrijaviGresku(KodoviGresaka kod)
{
	if(kod==KodoviGresaka::PogresnaKomanda)
	std::cout<<"Nerazumljiva komanda!"<<std::endl;
	else if(kod==KodoviGresaka::NedostajeParmetar)
	std::cout<<"Komanda trazi parametar koji nije naveden!"<<std::endl;
	else if(kod==KodoviGresaka::NeispravanParametar)
	std::cout<<"Parametar komande nije ispravan!"<<std::endl;
	else if(kod==KodoviGresaka::SuvisanParametar)
	std::cout<<"Zadan je suvisan parametar nakon komande!"<<std::endl;
}
bool UnosKomande(Komande &komanda, Smjerovi &smjer, int &x, int &y, KodoviGresaka &greska)
{
   	std::string
	
	
	
	
	
	
	
	
	
	
	
}





















int main()
{
std::vector<std::vector<int>> mat(3,std::vector<int>(4));	
for(int i=0;i<3;i++)
for(int j=0;j<4;j++)
std::cin>>mat[i][j];

mat=PrikaziOkolinu(mat,1,1);

for(int i=0;i<mat.size();i++)
{
for(int j=0;j<mat[0].size();j++)

std::cout<<mat[i][j];
std::cout<<std::endl;
}
return 0;
}


























