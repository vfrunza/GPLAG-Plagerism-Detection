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
#include<algorithm>
#include<vector>

bool DaLiJeProst(int n){
	if(n<=1) return false;
	for(int i(2); i<n; i++){
		if(n%i==0) return false;
	}
	return true;
}


template<typename Tip>
bool kriterij(Tip prvi,Tip drugi){
	int broj_prostih_prvi(0),broj_prostih_drugi(0);
	for(int i(2);i<prvi;i++){
		if(prvi%i==0){
			if(DaLiJeProst(i)==true) {
				broj_prostih_prvi++;
				prvi /= i;
				i--;
			}
		}
	}
	
	for(int j(2);j<drugi;j++){
		if(drugi%j==0){
		if(DaLiJeProst(j)==true) {
			broj_prostih_drugi++;
			drugi /= j;
			j--;
		}
	}
	}
	if(broj_prostih_prvi == broj_prostih_drugi) {
		if(prvi > drugi) return true;
		return false;
	}
	if(broj_prostih_prvi>broj_prostih_drugi) return true;
	
	return false;
}

template<typename Tip1,typename Tip2,typename Tip3>

void SortirajPodrucjeVrijednosti(Tip1 pocetak,Tip1 kraj,Tip2 pocetakDrugog,Tip3 pocetakTreceg,
typename std::remove_reference<decltype(*pocetakTreceg)>::type f(typename std::remove_reference<decltype(*pocetak)>::type,
typename std::remove_reference<decltype(*pocetak)>::type),bool kriterij(typename std::remove_reference<decltype(*pocetak)>::type,
typename std::remove_reference<decltype(*pocetak)>::type)){
	int duzinaBlokova=int(kraj-pocetak);
	std::sort(pocetak,kraj,kriterij);
	std::sort(pocetakDrugog,pocetakDrugog+duzinaBlokova,kriterij);
	for(int i(0);i<duzinaBlokova;i++){
	auto rezultat=f(*(pocetak+i),*(pocetakDrugog+i));
	bool postoji(false);
	for(auto j(pocetakTreceg);j!=pocetakTreceg+duzinaBlokova; j++){
		if (rezultat==*j){
			postoji=true;
			auto temp=*j;
			*j=*(pocetakTreceg+i);
			*(pocetakTreceg+i)=temp;
			break;
		}
		
	}
	
	if(postoji==false) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
}
}

template <typename Tip>
Tip f(Tip x, Tip y){
	Tip z;
	z=-2*x+y;
	return z;
}



int main ()
{
	std::vector<int>prvi,drugi,treci;
	int n,elementi;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>n;
	std::cout<<"Unesite elemente prvog vektora: ";
	for(int i(0);i<n;i++){
	
	std::cin>>elementi;
	bool postoji = false;
	for(int j(0); j<prvi.size();j++) {
		if(elementi == prvi[j]) postoji = true; 
	}
	if(!postoji) prvi.push_back(elementi);
	else i--;
	}
	std::cout<<"Unesite elemente drugog vektora: ";
	for(int j(0);j<n;j++){
	
	std::cin>>elementi;
	bool postoji = false;
	for(int k(0); k < drugi.size(); k++) {
		if(elementi == drugi[k]) postoji = true;
	}
	if(!postoji) drugi.push_back(elementi);
	else j--;
	}
	std::cout<<"Unesite elemente treceg vektora: ";
	for(int k(0);k<n;k++){
		std::cin>>elementi;
		bool postoji = false;
		for(int l(0);l<treci.size();l++) {
			if(treci[l] == elementi) postoji = true;
		}
		if(!postoji) treci.push_back(elementi);
		else k--;
	}
	
	try{

	
	SortirajPodrucjeVrijednosti(prvi.begin(),prvi.end(),drugi.begin(),treci.begin(),f,kriterij);
	std::cout<<std::endl;
	
	std::cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:" << std::endl;
	for(int i(0);i<n;i++){
		std::cout<<"f("<<prvi[i]<<", "<<drugi[i]<<") = "<<treci[i]<<std::endl;
	
	}
	}
	
	catch(std::logic_error tekst)
	{
	std::cout<<"\nIzuzetak: "<<tekst.what();
	}
	
	return 0;
	
}
