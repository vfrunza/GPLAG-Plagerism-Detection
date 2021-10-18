#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

using std::cin;
using std::cout;

typedef std::vector<double> Vector;
typedef std::vector<std::vector<double>> Matrica;

//Funkcija za kreiranje matrice
Matrica KreirajMatricu(int red, int kolona)
{
	return Matrica(red, std::vector<double>(kolona));
}

//Funkcija koja vraca broj redova matrice
int broj_redova(Matrica m)
{
	return m.size();
}

//Funkcija koja vraca broj kolona u nekom redu
int broj_kolona(Matrica m, int red)
{
	return m.at(red).size();
}

//Funkcija za provjeravanje da li je matrica Validna, tj. da li je grbava
bool ValidnaMatrica(Matrica m)
{

	int kolone(broj_kolona(m,0));
	for(int i(1); i<broj_redova(m); i++) {
		if(broj_kolona(m,i) != kolone) return false;
	}

	return true;
}

//Funkcija za prosiravanje matrice za n
Matrica ProsiriZaN (Matrica m, int prosirenje)
{
	m.resize(broj_redova(m) + prosirenje);
	int red(broj_redova(m));
	int kolona(broj_kolona(m,0));
	for(int i(0); i<red; i++) {
		m.at(i).resize(kolona + prosirenje);
	}

	return m;
}

//Trazi najveci element matrice, sto je ujedino i temelj za vrh matrice
int NajveciClanMatrice(Matrica m)
{

	int max(m.at(0).at(0));
	for(int i(0); i<broj_redova(m); i++) {
		for(int j(0); j<broj_kolona(m,i); j++) {
			if(m.at(i).at(j) > max) max = m.at(i).at(j);
		}
	}

	return max;
}

//Funkcija koja daje redni broj reda i kolone u kojoj se nalazi najveci clan
void BrojRedaKolone(Matrica m, int max, int &red, int &kolona)
{

	int breakaj(0);
	for(int i(0); i<broj_redova(m); i++) {
		for(int j(0); j<broj_kolona(m,i); j++) {
			if(m.at(i).at(j) == max) {
				red = i;
				kolona = j;
				breakaj = 1;
				break;
			}
		}
		if(breakaj) break;
	}
}

//Funkcija koja trazi najveci clan koji je okruzen kvadratom cifara od cije je sume veci
int NajveciValidniClan(Matrica m)
{
	int max(NajveciClanMatrice(m));
	int maxi(m.at(0).at(0));
	for(int i(0); i<broj_redova(m); i++) {
		for(int j(0); j<broj_kolona(m,i); j++) {
			if((i - 1 >= 0) && (i + 1 < broj_redova(m)) && (j - 1 >= 0) && (j + 1 <broj_kolona(m,i)) && (m.at(i).at(j)>=maxi)) maxi = m.at(i).at(j); //Ako je najveci clan okruzen koncentricnim kvadratom
		}
	}

	if (maxi == m.at(0).at(0)) return max;
	int red, kolona;
	BrojRedaKolone(m,maxi,red,kolona);
	int zbir1(0);
	for(int i(red-1); i<=red+1; i++) {
		for(int j(kolona-1); j<=kolona + 1 ; j++) {
			if(m.at(i).at(j) != max) zbir1+=m.at(i).at(j);
		}
	}
	if(zbir1 < maxi) return maxi;
	else return max;
}

//Funkcija iz zadatka
Matrica NajvecaPlaninaMatrice(Matrica m)
{
	//AKO IMAMO GRBAVU MATRICU FUNKCIJA BACA IZUZETAK
	if(!(ValidnaMatrica(m))) throw std::domain_error("Matrica nije korektna");

	Matrica mat;

	//Ukoliko oko vrha matrice nema koncentricnog kvadrata, vrh je najveci clan
	if(broj_redova(m) * broj_kolona(m,0) < 9) {
		mat = KreirajMatricu(1,1);
		mat.at(0).at(0) = NajveciValidniClan(m);
		return mat;
	}

	int zbir11(0);
	int zbir22(0);
	mat = KreirajMatricu(1,1);
	Matrica pomocna;
	pomocna = KreirajMatricu(1, 1);
	pomocna.at(0).at(0) = NajveciClanMatrice(m);
	mat = KreirajMatricu(1, 1);
	Matrica mat2(KreirajMatricu(1, 1));

	for(int RED(0); RED<broj_redova(m); RED++) {
		for(int KOLONA(0); KOLONA<broj_kolona(m,0); KOLONA++) {
			mat = mat2;
			if(RED == 0 || KOLONA == 0 || RED == broj_redova(m) - 1 || KOLONA == broj_kolona(m,0) -1) continue; //DA NE ISPITUJE OKVIR MATRICE

			//x je broj koncentricnog kruga
			for(int x(1); x<broj_redova(m); x++) {
				if(x==1) zbir11 = m.at(RED).at(KOLONA);
				int &zbir1(zbir11);
				int zbir2(0);
				if(RED + x < broj_redova(m) && KOLONA + x < broj_kolona(m,0) && RED - x >= 0 && KOLONA - x >= 0) { //Osiguranje da se ne izadje izvan opsega matrice

					for(int i(RED-x); i<=RED+x; i++) {
						for(int j(KOLONA-x); j<=KOLONA + x ; j++) {
							zbir2 += m.at(i).at(j);
						}
					}
					for(int i(RED-x+1); i<=RED+x-1; i++) {
						for(int j(KOLONA-x+1); j<=KOLONA+x-1; j++) {
							zbir2 -= m.at(i).at(j);
						}
					}

					if(zbir2 < zbir1) {
						int r(0), k(0);
						mat = ProsiriZaN(mat,2);
						for(int i(RED-x); i<=RED+x; i++) {
							for(int j(KOLONA-x); j<=KOLONA + x ; j++) {
								mat.at(r).at(k) = m.at(i).at(j);
								k++;
							}
							r++;
							k = 0;
						}

						if(broj_redova(mat) > broj_redova(pomocna) || ((NajveciClanMatrice(mat) > NajveciClanMatrice(pomocna)) && (broj_redova(mat) == broj_redova(pomocna) ))) {
							pomocna = mat; //Pomocna je sada najveca matrica ako je veca
						}
						zbir1 = zbir2;

					} else break;
				} else break;
			}
		}
	}

	return pomocna;
}

int main ()
{
	cout<<"Unesite dimenzije matrice (m i n): ";
	int red,kolona;
	cin>>red>>kolona;
	if(red<0 || kolona<0) {
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	cout<<"Unesite elemente matrice: ";
	Matrica mat(KreirajMatricu(red, kolona));
	double element;
	for(int i(0); i<red; i++) {
		for(int j(0); j<kolona; j++) {
			cin>>element;
			mat.at(i).at(j) = element;
		}
	}
	cout<<"\nNajveca planina unesene matrice je: \n";

	mat = NajvecaPlaninaMatrice(mat);
	for(int i(0); i<broj_redova(mat); i++) {
		for(int j(0); j<broj_kolona(mat,i); j++) {
			cout<<std::setw(6)<<mat.at(i).at(j);
		}
		cout<<std::endl;
	}

	return 0;
}