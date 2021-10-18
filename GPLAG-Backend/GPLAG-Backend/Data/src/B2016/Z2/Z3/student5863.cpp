/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <type_traits>
#include <iomanip>

bool Obicni = false;

int SumaCifara(long long int broj) {
	broj = std::labs(broj);
	int suma=0;
	while(broj){
		suma += broj%10;
		broj/=10;
	}
	
	return suma;
}


int SumaDjelilaca(long long int broj){
	broj = std::labs(broj);
	int suma = 0; //suma += broj <broj
	for(int i=1; i<= broj; i++)
	if(broj%i == 0) suma += i;
	
	return suma;
}


int BrojProstihFaktora(long long int broj) {
	broj = std::labs(broj);
	if(broj == 1) return 1;
	int prosti=0;
	
	for(int i=2; i<= broj; i++) {
		if( broj%i == 0 ) {prosti++; broj/=i; i=1; }
	}
	
	return prosti;
}

bool Savrsen(long long int broj) {
	if(broj == 1) return true;
	int suma=0;
	for(int i=1; i<broj; i++){
		if(broj%i == 0) suma+= i;
	}
	if(suma == broj) return true;
	return false;
	
}

int BrojSavrsenihDjelilaca(long long int broj) {
	broj = std::labs(broj);
	int savrseni=0;
	for(int i=2; i<=broj; i++) {
		if(broj%i == 0 && Savrsen(i)){ savrseni++; broj/=i; i=1; }
	}
		
		return savrseni;
	
}

int ObicniPresjek(long long int jest){
	Obicni = true;
	return jest;
}




template <typename tipPrvog, typename tipDrugog, typename tipUFunkciji=long long int, typename vracenTip=int>
auto UvrnutiPresjek(tipPrvog pocetakP, tipPrvog iza_krajaP, tipDrugog pocetakD, tipDrugog iza_krajaD, vracenTip (*fun)(tipUFunkciji) = ObicniPresjek) -> std::vector<std::vector< decltype(*pocetakP+*pocetakD)>>  {

 std::vector< decltype(*pocetakP+ *pocetakD)> vek;
 std::vector<std::vector< decltype(*pocetakP+*pocetakD)>> matrica;
tipDrugog pomocni = pocetakD;

 
 while(pocetakP != iza_krajaP){
 	pocetakD = pomocni;
 	while (pocetakD != iza_krajaD) {
 		vek.resize(0);
 		if(fun(*pocetakP) == fun(*pocetakD)){ 
 			vek.push_back(*pocetakP);
 			if(Obicni) 	vek.push_back(0);
 			else vek.push_back(*pocetakD);
 			if(Obicni) 	vek.push_back(0);
 			else vek.push_back(fun(*pocetakP));
 			matrica.push_back(vek);
 		
 		}
 		pocetakD++;
 	}
 	pocetakP++;
 }
 
 std::sort(matrica.begin(),matrica.end(), [](const std::vector<decltype(*pocetakP+*pocetakD)> &a, const std::vector<decltype(*pocetakP+*pocetakD)> &b)
 {  if(a[2] != b[2]) return a[2] < b[2];
 	else if(a[2] == b[2] && a[0] != b[0]) return a[0] < b[0];
 	 return a[1] < b[1];
 });

 
 return matrica;
}



template <typename tipPrvog, typename tipDrugog, typename tipUFunkciji=long long int, typename vracenTip=int>
auto UvrnutaRazlika(tipPrvog pocetakP, tipPrvog iza_krajaP, tipDrugog pocetakD, tipDrugog iza_krajaD, vracenTip (*fun)(tipUFunkciji) = ObicniPresjek) -> std::vector<std::vector<decltype(*pocetakP+ *pocetakD)>>  {
 int vel =0,vel1=0;
 tipDrugog po = pocetakD;
 tipPrvog l = pocetakP;
 while (l != iza_krajaP) {
 	vel1++;
 	l++;
 	
 }

 while (po != iza_krajaD) {
 	vel++;
 	po++;
 	
 } 
 std::vector<decltype(*pocetakP + *pocetakD)> vek;
 std::vector<std::vector<decltype(*pocetakP+ *pocetakD)>> matrica;
tipDrugog pomocni = pocetakD;
tipPrvog pom = pocetakP;

 int brojacRazlictih=0;
 while(pocetakP != iza_krajaP){
 	pocetakD = pomocni;
 	brojacRazlictih = 0;
 	while (pocetakD != iza_krajaD) {
 		vek.resize(0);
 		if(fun(*pocetakP) != fun(*pocetakD)){
 			brojacRazlictih++;
 			if(brojacRazlictih == vel){
 				vek.push_back(*pocetakP);
 				if(Obicni) vek.push_back(0);
 				else vek.push_back(fun(*pocetakP));
 				matrica.push_back(vek);
 			}
 		}
 		pocetakD++;
 	}
    pocetakP++;
 }
 pocetakD = pomocni;
 while(pocetakD != iza_krajaD){
 	pocetakP = pom;
 	brojacRazlictih = 0;
 	while (pocetakP != iza_krajaP) {
 		vek.resize(0);
 		if(fun(*pocetakD) != fun(*pocetakP)){
 			brojacRazlictih++;
 			if(brojacRazlictih == vel1){
 				vek.push_back(*pocetakD);
 				if(Obicni) vek.push_back(0);
 				else vek.push_back(fun(*pocetakD));
 				matrica.push_back(vek);
 			}
 		}
 		pocetakP++;
 	}
    pocetakD++;
 }
 
 
 
 std::sort(matrica.begin(),matrica.end(), [](const std::vector<decltype(*pocetakP+*pocetakD)> &a, const std::vector<decltype(*pocetakP+*pocetakD)> &b)//std::begin(matrica) da moze i niz primit
 {  if(a[0] != b[0]) return a[0] > b[0];
 	 return a[1] > b[1];
 });
 
 
 return matrica;
}

template<typename tip, typename uporedivT>
bool imalVec(tip kolekcija ,uporedivT element  ){
	for(int i=0; i<kolekcija.size(); i++){
		if(kolekcija.at(i) == element) return true;
	}
	return false;
}




int main () 
{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int el1,el2;
	int broj;
	std::vector<int> v1,v2;
	std::cin>>el1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	while (el1) {
		std::cin>>broj;
		if(!imalVec(v1,broj)){
		v1.push_back(broj);
		el1--;
		}
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>el2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	while(el2){
		std::cin>>broj;
		if(!imalVec(v2,broj)){
		v2.push_back(broj);
		el2--;
		}
	}
	
//	std::vector<std::vector<int>> matrica,mat;
     auto	matrica = UvrnutiPresjek(std::begin(v1), std::end(v1), std::begin(v2), std::end(v2),SumaCifara);
	std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
	for(int i=0; i< matrica.size(); i++){
		for(int j=0; j<matrica.at(0).size(); j++)
		std::cout<<std::setw(6)<<matrica.at(i).at(j)<<" ";
		std::cout<<std::endl;
	}
     auto mat = UvrnutaRazlika(std::begin(v1), std::end(v1), std::begin(v2), std::end(v2),BrojProstihFaktora);
	std::cout<<"Uvrnuta razlika kontejnera: "<<std::endl;
	for(int i=0; i< mat.size(); i++){
		for(int j=0; j<mat.at(0).size(); j++)
		std::cout<<std::setw(6)<<mat.at(i).at(j)<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";

	
	
	
	return 0;
}