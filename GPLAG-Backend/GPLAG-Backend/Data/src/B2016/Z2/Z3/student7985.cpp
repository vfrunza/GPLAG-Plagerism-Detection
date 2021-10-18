/*B 16/17, Zadaća 2, Zadatak 3*/

#include <cmath>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <type_traits>
#include <iomanip>

using std::cout; using std::cin;
typedef std::vector<std::vector<int>> Matrica;
	
int SumaC (int n){
	if (n == 0) return 0;
	return fabs(n%10) + SumaC(n/10);
}
 
bool Kriterij (int x, int y){
	if(SumaC(x) == SumaC(y)) return x < y;
	return SumaC(x) < SumaC(y);
} 

int SumaDjelilaca(long long int n){
	int suma{};
	for(long long int i{n}; i >= 0; i--){
		if(abs(n) % i == 0) suma += i;
	}
	return suma;
}

int DaLiJeProst (long long int n){
	bool prost(true);
	if(n <= 1){
		prost = false;
		return prost;
	}
	float m(std::sqrt(float(n)));
	for(int i(2); i <= m; i++){
		if(n % i == 0){
			prost = false; break;
		}
	}
	return prost;
}

int BrojProstihFaktora(long long int n){
	n = abs(n);
	int br{};
	if(n == 1) return 1;
	else if (n == 0) return 0;
	while (n%2 == 0){
		br++;
		n /= 2;
	}
	for (long long int i{3}; i <= n; i += 2){
		while (n%2 == 0){
			br++;
			n /= i;
			
		}
	}
	br++;
	return br;
}

bool DaLiJeSavrsen(long long int n){
	long long int suma{};
	for(long long int i{}; i < n; i++){
		if (n % i == 0) suma += i;
	}
	if (suma == n) return true;
	return false;
}

int BrojSavrsenihDjelilaca(long long int n){
	int br{};
	for(long long int i{}; i < n; i++){
		if (DaLiJeSavrsen(i)) br++;
	}
	return br;
}


template <typename ItTip1, typename ItTip2, typename TipParam, typename TipPovratni>
	std::vector<std::vector<TipParam>> UvrnutiPresjek(ItTip1 p, ItTip1 q, ItTip2 pp, ItTip2 qq, TipPovratni fun (TipParam n)) {

	int redovi{};//služi samo da vidim koliko je n tj broj redova u matrici
	for(ItTip1 i(p); i != q; i++){
		for (ItTip2 j(pp); j != qq; j++){
			if(fun(*i) == fun(*j)) redovi++;
		}
	}
	
	
	std::vector<std::vector<TipParam>> mat(redovi, std::vector<TipParam> ());
	while(true){
		int k{}; //označava indeks reda matrice
		for(ItTip1 i(p); i != q; i++){
	
			//IterTip2 nazvan jot inicijaliziran sa IterTip2 pp 
			for (ItTip2 j(pp); j != qq ; j++){
				if(fun(*i) == fun(*j)) {
						mat[k].push_back(*i); 
						mat[k].push_back(*j); 
						mat[k].push_back(fun(*i));
						k++;
				}
				
			}
			
		}
		if(k == redovi) break;
				
	}

	
		std::sort(mat.begin(), mat.end(), 
		[]( std::vector<TipParam> vec1,  std::vector<TipParam> vec2) {
			if (vec1[2] != vec2[2]) {
				return vec1[2] < vec2[2];
			}
			else {
				if(vec1[0] != vec2[0])	return vec1[0] < vec2[0];
			}	
			return vec1[1] < vec2[1];
			
			});
	
		return mat;
	}


template <typename ItTip1, typename ItTip2>
	auto UvrnutiPresjek(ItTip1 p, ItTip1 q, ItTip2 pp, ItTip2 qq) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*p)>::type>> {
	
		int redovi{};//služi samo da vidim koliko je n tj broj redova u matrici
		for(ItTip1 i(p); i != q; i++){
			for (ItTip2 j(pp); j != qq; j++){
				if((*i) == (*j)) redovi++;
			}
		}
		
		typename std::vector<std::vector<typename std::remove_reference< decltype(*p)>::type>> mat(redovi,  std::vector<typename std::remove_reference<decltype(*p)>::type> ()); //prazna matrica, prazni vektori u njoj
		while(true){
			int k{}; //označava indeks reda matrice
			for(ItTip1 i(p); i != q; i++){
		
				//IterTip2 nazvan jot inicijaliziran sa IterTip2 pp 
				for (ItTip2 j(pp); j != qq ; j++){
					if((*i) == (*j)) {
							mat[k].push_back(*i);
							mat[k].push_back(0); 
							mat[k].push_back(0);
							k++;
					}
				}
				
			}
			if(k == redovi) break;
		} 
		
		std::sort(mat.begin(), mat.end(), 
			[]( std::vector<typename std::remove_reference<decltype(*p)>::type> vec1,  std::vector<typename std::remove_reference<decltype(*p)>::type> vec2) {return vec1[0] < vec2[0];} );
		return mat;
	}

template <typename ItTip1, typename ItTip2, typename TipParam, typename TipPovratni>
	std::vector<std::vector<TipParam>> UvrnutaRazlika(ItTip1 p, ItTip1 q, ItTip2 pp, ItTip2 qq, TipPovratni fun (TipParam n)){
		
		std::vector<std::vector<TipParam>> mat;
		
		for(ItTip1 i(p); i != q; i++){
			bool jednakost(false);
			//IterTip2 nazvan jot inicijaliziran sa IterTip2 pp 
			for (ItTip2 j(pp); j != qq ; j++){
				if(fun(*i) == fun(*j)) {
					jednakost = true;
					break;
				}
				if (jednakost == false) { 
					std::vector<TipParam> v;
					v.push_back(*i);
					v.push_back(fun(*i));
					mat.push_back(v);
				}	
			}	
		}
		
		for (ItTip2 j(pp); j != qq; j++){
			bool jednakost(false);
			for(ItTip1 i(p); i != q; i++){
				if (fun(*i) == fun(*j)){
					jednakost = true;
					break;
				}
				if (jednakost == false){
					std::vector<TipParam> v;
					v.push_back(*j); v.push_back(fun(*j));
					mat.push_back(v);
				}
			}
		}
		
		std::sort(mat.begin(), mat.end(), [] (std::vector<TipParam> vec1, std::vector<TipParam> vec2){
			if (vec1[0] == vec2[0]) return vec1[1] > vec2[1];
			return vec1[0] > vec2[0]; //opadajući poredak
		});
		
		return mat;
		
	}

bool ImaLiGaxD(std::deque<int> dek, int n){
	for(int i{}; i<dek.size(); i++){
		if (dek[i] == n) return true;
	}
	return false;
}

template <typename TipE>
	void Ispis(std::vector<std::vector<TipE>> uvr){
		for (int i{}; i < uvr.size(); i++){
			for(int j{}; j < uvr[i].size(); j++){
				cout << std::right << std::setw(6) << uvr[i][j] << " ";
			}
			cout << std::endl;
		}
	}
	

int main (){
	cout << "Unesite broj elemenata prvog kontejnera: ";
	int vel;
	cin >> vel;
	std::deque<int> dek;
	cout << "Unesite elemente prvog kontejnera: ";
	for(int i{}; i<vel; i++) {
		int n;
		cin >> n;
		
		if ((ImaLiGaxD(dek, n)) == false) dek.push_back(n);
		else i--; //??
	}
	
	cout << "Unesite broj elemenata drugog kontejnera: ";
	cin >> vel;
	std::deque<int> dek2;
	cout << "Unesite elemente drugog kontejnera: ";
	for(int i{}; i<vel; i++) {
		int n;
		cin >> n;
		
		if (ImaLiGaxD(dek2, n) == false) dek2.push_back(n);
		else i--; //??
	}
	cout << "Uvrnuti presjek kontejnera:\n";
 	Matrica uvr_presjek(UvrnutiPresjek(dek.begin(), dek.end(), dek2.begin(), dek2.end(), SumaC));
	
	/*for (int i{}; i < uvr_presjek.size(); i++){
		for(int j{}; j < uvr_presjek[i].size(); j++){
			cout << std::right << std::setw(6) << uvr_presjek[i][j] << " ";
		}
		cout << std::endl;
	}*/
	Ispis(uvr_presjek);
	
	
	std::vector<std::vector<long long int>> uvr_razlika(UvrnutaRazlika(dek.begin(), dek.end(), dek2.begin(), dek2.end(), BrojProstihFaktora));

	
	cout << "Uvrnuta razlika kontejnera:\n";
	Ispis(uvr_razlika);
	cout << "Dovidjenja!";
	
	return 0;
}










