/*B 2017/2018, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/
#include <iostream>
#include <deque>
#include <vector>
#include <cmath>

typedef std::deque<std::vector<int>> Matrica;
enum Smjer {Rastuci=1,Opadajuci} Izbor;

bool DaLiJeStepenDvojke(int n)
{
	int stepen(0),i(0);
	while(stepen<=n) {
		stepen=pow(2,i);
		if(stepen==n) {
			return true;
		}
		i++;
	}
	return false;
}

std::vector<int> VelicineDekova(std::vector<int> v,int a)
{
	std::vector<int> velicine;
	int velicina(1);
	for(int i(1) ; i<v.size() ; i++) {
		if(DaLiJeStepenDvojke(v.at(i)) && DaLiJeStepenDvojke(v.at(i-1))) {
			if (a==1) {
				if(v.at(i)>=v.at(i-1)) {
					velicina++;
					if(i!=v.size()-1) {
						continue;
					}
				}
			} else if(a==2) {
				if(v.at(i)<=v.at(i-1)) {
					velicina++;
					if(i!=v.size()-1) {
						continue;
					}
				}
			}

		}
		if(velicina>1) {
			velicine.push_back(velicina);
			velicina=1;
		}
	}
	return velicine;
}

Matrica KreirajMatricu(std::vector<int> velicine)
{
	Matrica M(velicine.size());
	for(int i(0) ; i<velicine.size() ; i++) {
		M.at(i).resize(velicine.at(i));
	}
	return M;
}

Matrica PronadjiIStavi(Matrica M,int element)
{
	Matrica A(M);
	bool upisan(false);
	for(int i(0) ; i<A.size() ; i++) {
		if(upisan) break;
		for(int j(0) ; j<A.at(i).size() ; j++) {
			if(A.at(i).at(j)==0) {
				A.at(i).at(j)=element;
				upisan=true;
				break;
			}
		}
	}
	return A;
}

Matrica PopuniMatricu(Matrica M,std::vector<int> v,int a)
{
	Matrica X(M);
	bool imamo_podniz(false),prvi(true);
	for(int k(0) ; k<v.size() ; k++) {
		//rastuci
		if(a==1) {
			if(DaLiJeStepenDvojke(v.at(k))) {
				if(k==v.size()-1) {
					if(DaLiJeStepenDvojke(v.at(k-1))) {
						if(v.at(k)>=v.at(k-1)) {
							X=PronadjiIStavi(X,v.at(k));
							//posljednji
							break;
						}
					}
				}
				if(DaLiJeStepenDvojke(v.at(k+1))) {
					if(v.at(k)<=v.at(k+1)) {
						X=PronadjiIStavi(X,v.at(k));
						prvi=false;
						imamo_podniz=true;
					} else {
						if((imamo_podniz==true) && (prvi==false)) {
							X=PronadjiIStavi(X,v.at(k));
							prvi=true;
							imamo_podniz=false;
						}
					}
				} else {
					if((imamo_podniz==true) && (prvi==false)) {
						X=PronadjiIStavi(X,v.at(k));
						prvi=true;
						imamo_podniz=false;
					}
				}
			}
		}
		// opadajuci
		else if(a==2) {
			if(DaLiJeStepenDvojke(v.at(k))) {
				if(k==v.size()-1) {
					if(DaLiJeStepenDvojke(v.at(k-1))) {
						if(v.at(k)<=v.at(k-1)) {
							X=PronadjiIStavi(X,v.at(k));
							//posljednji
							break;
						}
					}
				}
				if(DaLiJeStepenDvojke(v.at(k+1))) {
					if(v.at(k)>=v.at(k+1)) {
						X=PronadjiIStavi(X,v.at(k));
						prvi=false;
						imamo_podniz=true;
					} else {
						if((imamo_podniz==true) && (prvi==false)) {
							X=PronadjiIStavi(X,v.at(k));
							prvi=true;
							imamo_podniz=false;
						}
					}

				} else {
					if((imamo_podniz==true) && (prvi==false)) {
						X=PronadjiIStavi(X,v.at(k));
						prvi=true;
						imamo_podniz=false;
					}
				}
			}
		}
	}
	return X;
}
Matrica MaksimalniPodnizoviStepenaDvojke(std::vector<int> v,enum Smjer Izbor)
{
	std::vector<int> velicine;
	if(Izbor==Rastuci) {
		velicine=VelicineDekova(v,1);
	} else {
		velicine=VelicineDekova(v,2);
	}
	Matrica M(KreirajMatricu(velicine));
	M=PopuniMatricu(M,v,Izbor);
	return M;
}

void Ispis(Matrica M)
{
	for(int i(0) ; i<M.size() ; i++) {
		for(int j(0) ; j<M.at(i).size() ; j++) {
			std::cout << M.at(i).at(j) << " ";
		}
		std::cout << std::endl;
	}
}

int main ()
{

	std::cout << "Unesite broj elemenata vektora: ";
	int br_el(0);
	std::cin >> br_el;
	std::cout << "Unesite elemente vektora: ";
	std::vector<int> v;
	for(int i(0) ; i<br_el ; i++) {
		int element(0);
		std::cin >> element;
		v.push_back(element);
	}

	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int opcija(0);
	std::cin >> opcija;
	if(opcija==1) {
		Izbor=Rastuci;
		auto M(MaksimalniPodnizoviStepenaDvojke(v,Izbor));
		std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
		Ispis(M);
	} else if (opcija==2) {
		Izbor=Opadajuci;
		auto M(MaksimalniPodnizoviStepenaDvojke(v,Izbor));
		std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
		Ispis(M);
	}
	return 0;
}