/*B 2017/2018, Zadaća 2, Zadatak 4
	
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
#include <algorithm>
#include <cmath>

template<typename Tip>
bool DaLiJeProst(Tip broj){
	
	for(int i(2); i < std::sqrt((double)broj); i++){
		if(broj % i == 0) return false;
	}
	return true;
}

template<typename Tip>
int BrojProstih(Tip broj){
	int brojac(0);
	if(broj <= 1) return brojac;
	for(int i(2); i < broj || broj == 1; i++){
		if(DaLiJeProst(i)){
			if(broj % i == 0){
			broj /= i;
			i--;
			brojac++;
			}
		}
	}
	
	return brojac;
}

template<typename tip>
bool f6(tip p, tip q){
	
	int ProstiP(BrojProstih(p));
	int ProstiQ(BrojProstih(q));
	if(ProstiP == ProstiQ && p > q) return true;
	if(ProstiP == ProstiQ && p < q) return false;
	
	return ProstiP > ProstiQ;
}

template<typename Povratni, typename Parametri>
Povratni f(Parametri x, Parametri y){
	Povratni rezultat(y-2*x);
	return rezultat;
}

template<typename IterTip1, typename IterTip2, typename IterTip3>
void SortirajPodrucjeVrijednosti(IterTip1 s1Pocetak, IterTip1 s1IzaKraja, IterTip2 s2, IterTip3 s3,  decltype(0+*s3) f(decltype(0+*s1Pocetak) x, decltype(0+*s1Pocetak) y), bool f6(decltype(0+*s1Pocetak) a, decltype(0+*s1Pocetak) b)){
	
	int VelicinaBlokova(s1IzaKraja-s1Pocetak);
	
	std::sort(s1Pocetak, s1IzaKraja, f6);
	std::sort(s2, s2+VelicinaBlokova, f6);
	IterTip1 p1(s1Pocetak);
	IterTip2 p2(s2);
	decltype(0+*s3) rez;
	IterTip3 p3(s3);
	for(int i(0); i < VelicinaBlokova; i++){
		rez = f(*p1,*p2);
		p1++;
		p2++;
		p3 = s3;
		int indexI(i);
		int broja(0);
		int indexJ(0);
		for(int j(0); j < VelicinaBlokova; j++){
			if(rez == *p3){
				 indexJ = j;
				 break;
			}
			broja++;
			p3++;
		}
		if(broja == VelicinaBlokova) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		IterTip3 pomocniPok(s3);
		decltype(0+*s3) pomocna(pomocniPok[indexI]);
		pomocniPok[indexI] = pomocniPok[indexJ];
		pomocniPok[indexJ] = pomocna;
	}
	
}

void UnesiElementeVektora(std::vector<int> &v, int velicina){
	int broj;
	int TrenutniBrojElemenata(0);
	bool isti(false);
	for(int i(0); i < velicina; i++){
		std::cin>>broj;
		for(int j(0); j < TrenutniBrojElemenata; j++){
			if(broj == v.at(j)){
				i--;
				isti = true;
				break;
			}
			isti = false;
		}
		if(!isti){
		v.push_back(broj);
		TrenutniBrojElemenata++;
		}
		
	}
			
}

int main ()
{
	int BrElemenata;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>BrElemenata;
	std::vector<int> v1;
	std::vector<int> v2;
	std::vector<int> v3;
	std::cout<<"Unesite elemente prvog vektora: ";
	UnesiElementeVektora(v1,BrElemenata);
	std::cout<<"Unesite elemente drugog vektora: ";
	UnesiElementeVektora(v2,BrElemenata);
	std::cout<<"Unesite elemente treceg vektora: ";
	UnesiElementeVektora(v3,BrElemenata);
	std::cout<<std::endl;
	try{
	SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),f,f6);
	std::cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<std::endl;
	for(int i(0); i < BrElemenata; i++){
		std::cout<<"f("<<v1.at(i)<<", "<<v2.at(i)<<") = "<<v3.at(i)<<std::endl;
	}
	}
	catch(std::logic_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	return 0;
}