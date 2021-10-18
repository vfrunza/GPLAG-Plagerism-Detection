/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
#include <algorithm>
#include <iomanip>

using std::cout;
using std::cin;

int suma(int n){
	int sumacif=0;
	while(n!=0){
		sumacif+=(n%10);
		n/=10;
	}
	return sumacif;
}

int SumaDjelilaca(long long int x){
	int suma(0);
	if(x<0) x=-x;
	for(int i=1; i<=x; i++){
		if(x%i==0) suma+=i;
	}
	return suma;
}

bool Prost(int x){
	for(int i=2; i<x; i++){
		if(x%i==0) return false;
	}
	return true;
}

int BrojProstihFaktora(long long int x){
	int br(0);
	if(x<0) x=-x;
	for(int i=2; i<x; i++){
		if(x%i==0 and (Prost(i) or i==2)){ 
			br++;
			int y(x/i);
			while(y%i==0){ 
				br++;
				y/=i;
			}
		}
	}
	if(Prost(x)) br++;
	return br;
}
	
int BrojSavrsenihDjelilaca (long long int x){
	int br(0);
	for(int i=2; i<=x; i++){
		if(x%i==0 and SumaDjelilaca(i)-i==i) br++;
	}
	return br;
}

template <typename tippok1, typename tippok2, typename tipfun, typename tipparam>
auto UvrnutiPresjek (tippok1 p1, tippok1 p2, tippok2 q1, tippok2 q2, tipfun fun(tipparam)) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> matrica;
	for(int i=0; i<std::distance(p1, p2); i++){
		for(int j=0; j<std::distance(q1, q2); j++){
			std::vector<typename std::remove_reference<decltype(*p1)>::type> vektor;
			if(fun(*(p1+i))==fun(*(q1+j))){
				vektor.push_back(*(p1+i));
				vektor.push_back(*(q1+j));
				vektor.push_back(fun(*(p1+i)));
				matrica.push_back(vektor);
			}
		}
	}
	std::sort(matrica.begin(), matrica.end(), [](std::vector<typename std::remove_reference<decltype(*p1)>::type> a, std::vector <typename std::remove_reference<decltype(*p1)>::type>b){ 
		if(a[2]==b[2]){
			if(a[0]==b[0]) return a[1]<b[1];
			return a[0]<b[0];
		}
		return a[2]<b[2];
	});
	return matrica;
	
}

template <typename tippok1, typename tippok2>
auto UvrnutiPresjek (tippok1 p1, tippok1 p2, tippok2 q1, tippok2 q2) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> matrica;
	for(int i=0; i<std::distance(p1,p2); i++){
		for(int j=0; j<std::distance(q1, q2); j++){
			std::vector<typename std::remove_reference<decltype(*p1)>::type> vektor;
			if(*(p1+i)==*(q1+j)){
				vektor.push_back(*(p1+i));
				vektor.push_back(0);
				vektor.push_back(0);
				matrica.push_back(vektor);
			}
		}
	}
	std::sort(matrica.begin(), matrica.end(), [](std::vector<typename std::remove_reference<decltype(*p1)>::type> a, std::vector <typename std::remove_reference<decltype(*p1)>::type>b){ 
		return a[0]<b[0];});
	return matrica;
}


template <typename tippok1, typename tippok2, typename tipfun, typename tipparam>
auto UvrnutaRazlika (tippok1 p1, tippok1 p2, tippok2 q1, tippok2 q2, tipfun fun(tipparam)) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> matrica;
	for(int i=0; i<std::distance(p1, p2); i++){
		bool ubaciti(true);
		std::vector<typename std::remove_reference<decltype(*p1)>::type> vektor;
		for(int j=0; j<std::distance(q1, q2); j++){
			if(fun(*(p1+i))==fun(*(q1+j))){
				ubaciti=false;
				break;
			} 
		}
		if(ubaciti){
		vektor.push_back(*(p1+i));
		vektor.push_back(fun(*(p1+i)));
		matrica.push_back(vektor);
		}
	}
	for(int i=0; i<std::distance(q1, q2); i++){
		bool ubaciti(true);
		std::vector<typename std::remove_reference<decltype(*p1)>::type> vektor;
		for(int j=0; j<std::distance(p1, p2); j++){
			if(fun(*(p1+j))==fun(*(q1+i))) ubaciti=false;
		}
		if(ubaciti){
		vektor.push_back(*(q1+i));
		vektor.push_back(fun(*(q1+i)));
		matrica.push_back(vektor);
		}
	}
	std::sort(matrica.begin(), matrica.end(), [](std::vector<typename std::remove_reference<decltype(*p1)>::type> a, std::vector <typename std::remove_reference<decltype(*p1)>::type>b){if (a[0]==b[0]) return a[1]>b[1]; return a[0]>b[0] ;});
	return matrica;
}

template <typename tippok1, typename tippok2>
auto UvrnutaRazlika (tippok1 p1, tippok1 p2, tippok2 q1, tippok2 q2) -> std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>{
	std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> matrica;
	for(int i=0; i<std::distance(p1, p2); i++){
		bool ubaciti(true);
		std::vector<typename std::remove_reference<decltype(*p1)>::type> vektor;
		for(int j=0; j<std::distance(q1, q2); j++){
			if(*(p1+i)==*(q1+j)) ubaciti=false;
		}
		if(ubaciti){
			vektor.push_back(*(p1+i));
			vektor.push_back(0);
			matrica.push_back(vektor);
		}
	}
	for(int i=0; i<std::distance(q1, q2); i++){
		bool ubaciti(true);
		std::vector<typename std::remove_reference<decltype(*p1)>::type> vektor;
		for(int j=0; j<std::distance(p1, p2); j++){
			if(*(q1+i)==*(p1+j)) ubaciti=false;
		}
		if(ubaciti){
			vektor.push_back(*(q1+i));
			vektor.push_back(0);
			matrica.push_back(vektor);
		}
	}
	std::sort(matrica.begin(), matrica.end(), [](std::vector<typename std::remove_reference<decltype(*p1)>::type> a, std::vector <typename std::remove_reference<decltype(*p1)>::type>b){ 
		return a[0]>b[0];});
	return matrica;
}


int main ()
{
	cout << "Unesite broj elemenata prvog kontejnera: ";
	int n1;
	cin >> n1;
	std::deque<long long int> dek1;
	cout << "Unesite elemente prvog kontejnera: ";
	for(int i=0; i<n1; i++){
		long long int a;
		cin >> a;
		int j;
		int x(0);
		bool nijeisti(true);
		for(j=0; j<i; j++){
			if(dek1[j]==a){
				x=1;
				nijeisti=false;
			} 
		}
		if(nijeisti)
			dek1.push_back(a);
		i-=x;
	}
	cout << "Unesite broj elemenata drugog kontejnera: ";
	int n2;
	cin >> n2;
	std::deque<long long int> dek2;
	cout << "Unesite elemente drugog kontejnera: ";
	for(int i=0; i<n2; i++){
		long long int a;
		cin >> a;
		int j;
		int x(0);
		bool nijeisti(true);
		for(j=0; j<i; j++){
			if(dek2[j]==a){
				x=1;
				nijeisti=false;
			} 
		}
		if(nijeisti)
			dek2.push_back(a);
		i-=x;
	}
	
	
	std::vector<std::vector<long long int>> mat(UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), suma));
	cout << "Uvrnuti presjek kontejnera: "<< std::endl;
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat[i].size(); j++){
			cout << std::setw(6) << mat[i][j] << " ";
		}
		cout<< std::endl;
	}
	mat=UvrnutaRazlika (dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), BrojProstihFaktora);
	cout << "Uvrnuta razlika kontejnera: "<< std::endl;
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat[i].size(); j++){
			cout << std::setw(6) << mat[i][j] << " ";
		}
		cout<< std::endl;
	}
	cout << "Dovidjenja!";
	return 0;
}