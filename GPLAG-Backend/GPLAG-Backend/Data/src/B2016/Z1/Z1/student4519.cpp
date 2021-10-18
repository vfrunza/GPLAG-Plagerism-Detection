/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <cmath>
#include <vector>

int tri_na_stepen(int stepen){
	stepen = 3;
	//pow mi javlja gresku i zato pisem ovo rucno
	int broj = 1;
	for(int i = 1; i <= stepen; i++)
		broj *=3;
	return broj;
}


std:: vector<int> IzdvojiGadne(std::vector <int> v, bool log_promjenljiva){
	
	std::vector <int> vektor_gadnih;
	if (v.size() == 0) return vektor_gadnih;
	
	//'uzima' broj iz vektora
	for(int i = 0; i< v.size(); i++){
		int brojac_0(0), brojac_1(0), brojac_2(0);
		
		int x = v.at(i);
		int kopija(std::abs(x)),tenarni_broj(0);
		int stepen(0), cifra(0);
		
		//pronalazi najveci stepen broja 3 u broju
		for(;;){
			int kopija2(kopija);
			if ((kopija2 /tri_na_stepen(stepen)) > 0) stepen++;
			else break;
		}
		
		//pretvara broj u tenarni
		kopija = std::abs(x);
		while(stepen >= 0){
			cifra = kopija / tri_na_stepen(stepen);
			tenarni_broj = tenarni_broj*10 + cifra;
			kopija = kopija %  tri_na_stepen(stepen);
		}
		
		//rastavljana cifre i prebrojava ih	
		int kopija_tenarnog(tenarni_broj);
		while(kopija_tenarnog!= 0){
			cifra = kopija_tenarnog % 10;
			if (cifra == 0) brojac_0++;
			else if (cifra == 1) brojac_1++;
			else if (cifra == 2) brojac_2++;
			kopija_tenarnog /= 10;
		}
		
		//trazi gadne
		if(log_promjenljiva){
			if((brojac_0 % 2 == 0) && (brojac_1 % 2 == 0) && (brojac_2 % 2 == 0))
				vektor_gadnih.push_back(x);
		}
		else{
			if((brojac_0 % 2 != 0) && (brojac_1 % 2 != 0) && (brojac_2 % 2 != 0))
				vektor_gadnih.push_back(x);
		}
	}
	
	//brisanje duplikata
	for(int i = 0; i < vektor_gadnih.size()-2; i++){
		for(int j = i; j < vektor_gadnih.size()-1; j++){
			if(vektor_gadnih.at(i) == vektor_gadnih.at(j))
			vektor_gadnih.erase(vektor_gadnih.begin() + i);			
		}
	}
	return vektor_gadnih;
}


int main ()
{
	std::vector<int>v;
	int broj;
	std::cout << "Unesite brojeve (0 za prekid unosa):";
	while (true){
		std::cin >> broj;
	 	if (broj == 0) break;
		v.push_back(broj);
	}
	std::cout << "Opaki:";
	IzdvojiGadne (v, true);
	std::cout << "Odvratni:";
	IzdvojiGadne (v, false);
	return 0;
}