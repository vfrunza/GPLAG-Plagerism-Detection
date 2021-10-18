/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iomanip> 

int SumaDjelilaca  (long long int x){
	int suma(0);
	for (int i=2;i<x;i++){
		if (x%i==0)
			suma+=i;
	}
	suma=suma+1+x;
	return suma;
}

int BrojProstihFaktora (long long int x){
	int b;
	int brojac(0);
	int k=x%2;
	while (k==0){
		b=x/2;
		brojac++;
		x=b;
		k=x%2;
	}
	for (int j=3;j<=x;j+=2){
		int k=x%j;
		while (k==0){
			b=x/j;
			x=b;
			brojac++;
			k=x%j;
		}
	}
	return brojac;
}

int SumaCifara (int x){
	int suma(0);
	while (x!=0){
		int cifra;
		cifra=x%10;
		suma=suma+cifra;
		x=x/10;
	}
	return suma;
}

template <typename IterTip1,typename IterTip2, typename TipFje, typename TipParametra>
std::vector<std::vector<int>> UvrnutiPresjek (IterTip1 pocetak, IterTip1 kraj, IterTip2 pocetak2, IterTip2 kraj2, TipFje fun(TipParametra)){
	std::vector<std::vector<int>> mat;
	int pomocna;
	while (pocetak!=kraj){
		IterTip1 pom(pocetak2);
		while (pom!=kraj2){
			if (fun(*pocetak)==fun(*pom)){
				std::vector<int> pomocni_vekt(0);
				pomocna=fun(*pocetak);
				pomocni_vekt.push_back(*pocetak);
				pomocni_vekt.push_back(*pom);
				pomocni_vekt.push_back(fun(*pocetak));
				mat.push_back(pomocni_vekt);
			}
			pom++;
		}
		pocetak++;
		
	}
	sort(mat.begin(),mat.end(), [] (const std::vector<int> v1, const std::vector<int> v2) -> bool {
																							if (v1[2]!=v2[2]) return v1[2]<v2[2]; 
																							else if (v1[2]==v2[2]) return v1[0]<v2[0];
																							else  if (v1[2]==v2[2] && v1[0]==v2[0]) return v1[1]<v2[1]; });
	return mat;
	
}

template <typename IterTip1,typename IterTip2, typename TipFje, typename TipParametra>
std::vector<std::vector<int>> UvrnutaRazlika (IterTip1 pocetak, IterTip1 kraj, IterTip2 pocetak2, IterTip2 kraj2, TipFje fun(TipParametra)){
	
	bool ponavlja_se(false);
	std::vector<std::vector<int>> mat;
	while(pocetak != kraj){
		IterTip1 pom(pocetak2);
		while(pom != kraj2){
			if(fun(*pocetak) != fun(*pom)){
				ponavlja_se = false;
			} else {
				ponavlja_se = true;
				break;
			}
			pom++;
		}
		if (ponavlja_se==false){
			std::vector<int> pomocni_vekt(0);
			pomocni_vekt.push_back(*pocetak);
			pomocni_vekt.push_back(fun(*pocetak));
			mat.push_back(pomocni_vekt);
		}
		pocetak++;
	}
	sort(mat.begin(),mat.end(), [] (const std::vector<int> v1, const std::vector<int> v2) -> bool {
																							if (v1[0]!=v2[0]) return v1[0]>v2[0]; 
																							else  return v1[1]>v2[1];});
	return mat; 
}

int main ()
{
	std::cout << "Unesite broj elemenata prvog kontejnera: ";
	int br_el1;
	std::cin >> br_el1;
	std::deque <int> d1;
	int broj;
	std::cout << "Unesite elemente prvog kontejnera: ";
	for (int i=0;i<br_el1;i++){
		std::cin >> broj;
		if (i==0)
			d1.push_back(broj);
		bool istina(true);
		for (int i=0; i<d1.size();i++){
			if (broj==d1[i]){
				istina=false;
				break;
			}
		}
		if (istina==true && i>0)
			d1.push_back(broj);
	}
	std::cout << "Unesite broj elemenata drugog kontejnera: ";
	int br_el2;
	std::cin >> br_el2;
	std::deque<int> d2;
	int broj2;
	std::cout << "Unesite elemente drugog kontejnera: ";
	for (int i=0;i<br_el2;i++){
		std::cin >> broj2;
		if (i==0)
			d2.push_back(broj2);
		bool istina2(true);
		for (int i=0;i<d2.size();i++){
			if (broj2==d2[i]){
				istina2=false;
				break;
			}
		}
		if (istina2==true && i>0)
			d2.push_back(broj2);
	}
	std::cout << "Uvrnuti presjek kontejnera: " << std::endl;
	std::vector<std::vector<int>> Matrica;
	Matrica=UvrnutiPresjek(d1.begin(),d1.end(),d2.begin(),d2.end(), SumaCifara);
	for (int i=0;i<Matrica.size();i++){
		for (int j=0;j<Matrica[i].size();j++){
			std::cout << std::setw(6) << Matrica[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "Uvrnuta razlika kontejnera: " << std::endl;
	std::vector<std::vector<int>> Matrica1;
	Matrica1=UvrnutaRazlika(d1.begin(),d1.end(),d2.begin(),d2.end(), BrojProstihFaktora);
	for (int i=0;i<Matrica1.size();i++){
		for (int j=0;j<Matrica1[i].size();j++){
		std::cout << std::setw(6) << Matrica1[i][j] << " ";
			}
	std::cout << std::endl;
		}
	std::cout << "Dovidjenja!";
	return 0;
}