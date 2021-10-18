#include <iostream>
#include <vector>
#include <stdexcept>

enum class Polje
{
    Prazno, Posjeceno, Mina, BlokiranoPrazno, BlokiranoPosjeceno, BlokiranoMina
};
typedef std::vector<std::vector<Polje>> Tabla;

enum class Smjerovi 
{
GoreLijevo, Gore, GoreDesno, Desno, DoljeDesno, Dolje, DoljeLijevo, Lijevo
};

typedef std::vector<std::vector<int>> Matrica;
Matrica KreirajMatricu(int a, int b)
{
	return Matrica(a, std::vector<int> (b));
}

Tabla KreirajIgru(int n, const std::vector<std::vector<int>> &mine)
{
	if(n<=0) throw std::domain_error ("Ilegalna velicina");
	Tabla a(n, std::vector<Polje> (n));
	for(auto e:mine) {
		if(e.size()!=2) throw std::domain_error("Ilegalan format zadavanja mina");
		for(auto a:e) if(a>n || a<0) throw std::domain_error ("Ilegalne pozicije mina");
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			a[i][j]=Polje::Prazno;
			for(int k=0; k<mine.size(); k++) {
				for(int l=0; l<mine[i].size(); l++) {
					a[mine[k][l]][mine[k][++l]]=Polje::Mina;
				}
			}
		}
	}
	return a;
}

std::vector<std::vector<int>> PrikaziOkolinu(const Tabla &polja, int x, int y)
{
	auto m(KreirajMatricu(3,3));
	if(x>polja.size() || y<polja.size()) throw std::domain_error ("Polje (x,y) ne postoji");

	return m;
}

void BlokirajPolje(Tabla &polja, int x, int y)
{
	if(x>polja.size() || y<polja.size()) throw std::domain_error ("Polje (x,y) ne postoji");
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja[i].size(); j++) {
			if(i==x && j==y) {
				if (polja[i][j]==Polje::Prazno) polja[i][j]=Polje::BlokiranoPrazno;
				else if (polja[i][j]==Polje::Posjeceno) polja[i][j]=Polje::BlokiranoPosjeceno;
				else if (polja[i][j]==Polje::Mina) polja[i][j]=Polje::BlokiranoMina;
			}
		}
	}
}

void DeblokirajPolje(Tabla &polja, int x, int y)
{
	if(x>polja.size() || y<polja.size()) throw std::domain_error ("Polje (x,y) ne postoji");
	for(int i=0; i<polja.size(); i++) {
		for(int j=0; j<polja[i].size(); j++) {
			if(i==x && j==y) {
				if (polja[i][j]==Polje::BlokiranoPrazno) polja[i][j]=Polje::Prazno;
				else if (polja[i][j]==Polje::BlokiranoPosjeceno) polja[i][j]=Polje::Posjeceno;
				else if (polja[i][j]==Polje::BlokiranoMina) polja[i][j]=Polje::Mina;
			}
		}
	}
}

Status Idi(Tabla &polja, int &x, int &y, Smjerovi smjer)
{
	for (int i = 0; i < polja.size(); i++) {
		for(int j=0; j<polja[i].size();j++){
			if(i==x && j==y) {x=i; y=j;}
		}
	}
}

Status Idi(Tabla &polja, int &x, int &y, int novi_x, int novi_y)
{
	for (int i = 0; i < polje.size(); i++) {
		for(int j=0; j<polja[i].size();j++){
			if(i==x && j==y) {x=novi_x; y=novi_y}
		}
	}
}

int main()
{
	std::cout<<"Unesite broj polja: ";
	int n;
	std::cin>>n;
	std::cout<<"Unesite pozicije mina: ";


	return 0;
}
