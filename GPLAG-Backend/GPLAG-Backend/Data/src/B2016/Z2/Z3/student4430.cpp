/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <algorithm>
using namespace std; 

bool Savrsen(int broj){
	int suma=0;
	broj=abs(broj); 
            for(int i=1; i<broj; i++){
                if(broj%i==0) 
                    suma=suma+i;
            }
   	if(suma==broj) return true; 
   	return false;
}
int SumaCifara(long long int broj){
	int suma=0; 
	int cifra; 
	broj=abs(broj); 
	while(broj!=0){
		cifra=broj%10; 
		broj=broj/10; 
		suma=suma+cifra; 
	}
	return suma; 
}
int SumaDjelilaca(long long int broj){
	int suma=0; 
	broj=abs(broj); 
	for(int i=1; i<=broj; i++){
		if(broj%i==0) suma=suma+i; 
	}
	return suma; 
}
int BrojProstihFaktora(long long int broj){
	int brojac=0; 
	broj=abs(broj); 
	for(int i=2; i<=broj; i++){
		while(broj%i==0){
			broj=broj/i; 
			brojac++; 
		}
	}		
	return brojac; 
}
int BrojSavrsenihDjelilaca(long long int broj){
	int brojac=0; 
	broj=abs(broj); 
	for(int i=2; i<=broj; i++){
		if(broj%i==0){
			if(Savrsen(i))
				brojac++; 
		}
	}
	return brojac; 
}
//FUNKCIJA SA 5 PARAMETARA
template <typename Tip1, typename Tip2, typename Vraca, typename Prima>
auto UvrnutiPresjek(Tip1 pocetak1, Tip1 kraj1, Tip2 pocetak2, Tip2 kraj2, Vraca Funkcija(Prima)) ->vector<vector<decltype (*pocetak1+*pocetak2)>>{
	
	vector<vector<decltype (*pocetak1+*pocetak2)>> matrica; 
	vector<decltype (*pocetak1+*pocetak2)> pomocni; 
	
	for(auto i=pocetak1; i!=kraj1; i++){
		for(auto j=pocetak2; j!=kraj2; j++){
			if(Funkcija(*i)==Funkcija(*j)){
				pomocni.push_back(*i); 
				pomocni.push_back(*j); 
				pomocni.push_back(Funkcija(*i)); 
				matrica.push_back(pomocni); 
				pomocni.resize(0); 
			}
		}
	}
	sort(matrica.begin(), matrica.end(), [] (vector<decltype (*pocetak1+*pocetak2)> v1, vector<decltype (*pocetak1+*pocetak2)> v2) ->bool{
	if(v1[2]<v2[2]) return true; 
	if(v1[2]>v2[2]) return false; 
	if(v1[2]==v2[2]){
		if(v1[0]<v2[0]) return true; 
		if(v1[0]>v2[0]) return false; 
		if(v1[0]==v2[0]){
			if(v1[1]<v2[1]) return true; 
			if(v1[1]>v2[1]) return false; 
			if(v1[1]==v2[1]) return true; 
		}
	}
	}); 
	return matrica; 
}
//FUNCKIJA S 4 PARAMETRA
template <typename Tip1, typename Tip2>
auto UvrnutiPresjek(Tip1 pocetak1, Tip1 kraj1, Tip2 pocetak2, Tip2 kraj2) ->vector<vector<decltype (*pocetak1+*pocetak2)>>{
	
	vector<vector<decltype (*pocetak1+*pocetak2)>> matrica; 
	vector<decltype (*pocetak1+*pocetak2)> pomocni; 
	
	for(auto i=pocetak1; i!=kraj1; i++){
		for(auto j=pocetak2; j!=kraj2; j++){
			if((*i)==(*j)){
				pomocni.push_back(*i); 
				pomocni.push_back(0); 
				pomocni.push_back(0); 
				matrica.push_back(pomocni); 
				pomocni.resize(0); 
			}
		}
	}
	sort(matrica.begin(), matrica.end(), [] (vector<decltype (*pocetak1+*pocetak2)> v1, vector<decltype (*pocetak1+*pocetak2)> v2) ->bool{
	if(v1[2]<v2[2]) return true; 
	if(v1[2]>v2[2]) return false; 
	if(v1[2]==v2[2]){
		if(v1[0]<v2[0]) return true; 
		if(v1[0]>v2[0]) return false; 
		if(v1[0]==v2[0]){
			if(v1[1]<v2[1]) return true; 
			if(v1[1]>v2[1]) return false; 
			if(v1[1]==v2[1]) return true; 
		}
	}
	}); 
	return matrica; 
}
//FUNKCIJA SA 5 PARAMETARA
template <typename Tip1, typename Tip2, typename Prima, typename Vraca>
auto UvrnutaRazlika(Tip1 pocetak1, Tip1 kraj1, Tip2 pocetak2, Tip2 kraj2, Vraca Funkcija(Prima)) -> vector<vector<decltype (*pocetak1+*pocetak2)>>{
		
	vector<vector<decltype (*pocetak1+*pocetak2)>> matrica; 
	vector<decltype (*pocetak1+*pocetak2)> pomocni; 
	
	for(auto i=pocetak1; i!=kraj1; i++){
			bool sadrzi=false; 
		for(auto j=pocetak2; j!=kraj2; j++){
			if(Funkcija(*i)==Funkcija(*j)){
				sadrzi=true; 
				break; 
			}
		}
		if(!sadrzi){
			pomocni.push_back(*i); 
			pomocni.push_back(Funkcija(*i)); 
			matrica.push_back(pomocni); 
			pomocni.resize(0); 
		}
	}
	for(auto i=pocetak2; i!=kraj2; i++){
			bool sadrzi=false; 
		for(auto j=pocetak1; j!=kraj1; j++){
			if(Funkcija(*i)==Funkcija(*j)){
				sadrzi=true; 
				break; 
			}
		}
		if(!sadrzi){
			pomocni.push_back(*i); 
			pomocni.push_back(Funkcija(*i)); 
			matrica.push_back(pomocni); 
			pomocni.resize(0); 
		}
	}
	sort(matrica.begin(), matrica.end(), [](vector<decltype (*pocetak1+*pocetak2)> v1, vector <decltype (*pocetak1+*pocetak2)> v2) -> bool{
		if(v1[0]>v2[0]) return true;
		if(v1[0]<v2[0]) return false; 
		if(v1[0]==v2[0]){
			if(v1[1]>v2[1]) return true; 
			if(v1[1]<v2[1]) return false; 
			if(v1[1]==v2[1]) return true; 
		}
	}); 
	return matrica; 
}
//FUNKCIJA SA 4 PARAMETRA
template <typename Tip1, typename Tip2>
auto UvrnutaRazlika(Tip1 pocetak1, Tip1 kraj1, Tip2 pocetak2, Tip2 kraj2) -> vector<vector<decltype (*pocetak1+*pocetak2)>>{
		
	vector<vector<decltype (*pocetak1+*pocetak2)>> matrica; 
	vector<decltype (*pocetak1+*pocetak2)> pomocni; 
	
	for(auto i=pocetak1; i!=kraj1; i++){
			bool sadrzi=false; 
		for(auto j=pocetak2; j!=kraj2; j++){
			if((*i)==(*j)){
				sadrzi=true; 
				break; 
			}
		}
		if(!sadrzi){
			pomocni.push_back(*i); 
			pomocni.push_back(0); 
			matrica.push_back(pomocni); 
			pomocni.resize(0); 
		}
	}
	for(auto i=pocetak2; i!=kraj2; i++){
			bool sadrzi=false; 
		for(auto j=pocetak1; j!=kraj1; j++){
			if((*i)==(*j)){
				sadrzi=true; 
				break; 
			}
		}
		if(!sadrzi){
			pomocni.push_back(*i); 
			pomocni.push_back(0); 
			matrica.push_back(pomocni); 
			pomocni.resize(0); 
		}
	}
	sort(matrica.begin(), matrica.end(), [](vector<decltype (*pocetak1+*pocetak2)> v1, vector <decltype (*pocetak1+*pocetak2)> v2) -> bool{
		if(v1[0]>v2[0]) return true;
		if(v1[0]<v2[0]) return false; 
		if(v1[0]==v2[0]){
			if(v1[1]>v2[1]) return true; 
			if(v1[1]<v2[1]) return false; 
			if(v1[1]==v2[1]) return true; 
		}
	}); 
	return matrica; 
}

int main ()
{
	int unos; 
	 
	cout << "Unesite broj elemenata prvog kontejnera: "; 
	int broj_elemenata_prvog; 
	cin >> broj_elemenata_prvog; 
	
	cout << "Unesite elemente prvog kontejnera: "; 
	deque<int> dek1; 
	
	for(int i=0; i<broj_elemenata_prvog; i++){
		cin >> unos;
		auto sadrzi1=find(dek1.begin(), dek1.end(), unos); 
		if(sadrzi1==dek1.end()) dek1.push_back(unos); 
		else i--; 
	}
		 
		
	cout << "Unesite broj elemenata drugog kontejnera: "; 
	int broj_elemenata_drugog; 
	cin >> broj_elemenata_drugog; 

	cout << "Unesite elemente drugog kontejnera: "; 
	deque<int> dek2; 
	for(int i=0; i<broj_elemenata_drugog; i++){
		cin >> unos;
		auto sadrzi2=find(dek2.begin(), dek2.end(), unos); 
		if(sadrzi2==dek2.end()) dek2.push_back(unos); 
		else i--; 
	}
		 
		
	cout << "Uvrnuti presjek kontejnera:" << endl;
	auto matrica1=UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), SumaCifara); 
	for(int i=0; i<matrica1.size(); i++){
		for(int j=0; j<matrica1[i].size(); j++){
			cout << setw(6) << matrica1[i][j]<<" "; 
		}
		cout << endl; 
	}
	 
	cout << "Uvrnuta razlika kontejnera:" << endl; 
	auto matrica2=UvrnutaRazlika(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), BrojProstihFaktora); 
	for(int i=0; i<matrica2.size(); i++){
		for(int j=0; j<matrica2[i].size(); j++){
			cout << setw(6) << matrica2[i][j]<<" "; 
		}
		cout << endl; 
	}
	 
	cout << "Dovidjenja!"; 
	return 0;
}