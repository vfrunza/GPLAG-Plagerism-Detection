/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include<iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

bool DaLiJeProst (long long int n){
	for(int i=2; i<n; i++)
		if(n%i==0) return 0;
	return 1;
}

int SumaDjelilaca (long long int n){
	int suma(0);
	for(int i=1; i<=n; i++)
		if(n%i==0) suma+=i;
	
	return suma;
}
//faktor sinonim za djelilac aman amaan

int BrojProstihFaktora(long long int n){
	int brojac(0);
	while(n%2==0) {
		brojac++;
		n=n/2;
	}
	for(int i=3; i<=sqrt(n); i=i+2){
		while(n%i==0){
			brojac++;
			n=n/i;
		}
	}
	
	if(n>2)	brojac++;
		return brojac;
	}
	
	
	

bool DaLiJeSavrsen (long long int n){
	
		int suma(0), brojac(0);
	for(int i=1; i<n; i++){
		if(n%i==0) {
			suma+=i;
			brojac++;
			
		}
	}
	if(suma==n) return 1;
	return 0;
	
}

int BrojSavrsenihDjelilaca (long long int n){
	int  brojac(0);
	for(int i=1; i<=n; i++){
	 if(DaLiJeSavrsen(i)) {
	 	if(n%i==0)
	 
			brojac++;
			
		}}
	
return brojac;
}

void IspisDeka (deque<int> &a){
	cout<<"ispis deka: "<<endl;
	//deque<int>::iterator it;
	for(int i=0; i<a.size();  i++)
	cout<<a[i]<<" ";
	cout<<endl;
}

int f (long long int n){
	int suma(0), x;
	while(n!=0){
		x=n%10;
		suma+=x;
		n/=10;
	}
	return suma;
}


template<typename tip1, typename tip2>
vector<vector<int>>	
UvrnutiPresjek (tip1 poc1, tip1 kraj1, tip2 poc2, tip2 kraj2, int f (long long int)) {
	int n=kraj1-poc1; //n je br cl prvog kontejnera
		vector<vector<int>> matrica (0, vector<int>(3,0));
	int x=kraj2-poc2;
		
		int k(0);
		for(int i=0; i<n; i++){
			for(int j=0; j<x; j++) {
				if(f(poc1[i])==f(poc2[j])){
					matrica.resize(k+1);
					matrica[k].push_back(poc1[i]);
					matrica[k].push_back(poc2[j]);
					matrica[k].push_back(f(poc1[i]));
					k++;
				}
			}
			
		}
		sort(begin(matrica), end(matrica), [] (vector<int> x, vector<int> y)->bool {
			
		if(x[2] == y[2]){
			if(x[0] == y[0])  {
				if(x[1]==y[1]) return false;
				else return x[1]<y[1];
			}
			else return x[0] < y[0];
		}
			
	
		return x[2] < y[2];});

		
		return matrica;
	}






template<typename tip1, typename tip2>
auto UvrnutiPresjek (tip1 poc1, tip1 kraj1, tip2 poc2, tip2 kraj2)-> vector<vector<decltype(*poc1+0)>>{
	int n=kraj1-poc1; //n je br cl prvog kontejnera
		vector<vector<decltype(*poc1+0)>> matrica (0, vector<decltype(*poc1+0)>(3,0));
	int x=kraj2-poc2;
		
		int k(0);
		for(int i=0; i<n; i++){
			for(int j=0; j<x; j++) {
				if(poc1[i]==poc2[j]){
					matrica.resize(k+1);
					matrica[k].push_back(poc1[i]);
					matrica[k].push_back(0);
					matrica[k].push_back(0);
					k++;;
				}
			}
			
		}
		

	sort(begin(matrica), end(matrica), [] (vector<decltype(*poc1+0)> x, vector<decltype(*poc1+0)> y)->bool {
			
	if(x[0]==y[0]) return false;
		 return (x[0]<y[0]);
	});
				
			
		
		
		return matrica;
	}


template<typename tip1, typename tip2>
vector<vector<int>>	
UvrnutaRazlika (tip1 poc1, tip1 kraj1, tip2 poc2, tip2 kraj2, int r (long long int)) {
	int n=kraj1-poc1; //n je br cl prvog kontejnera
		vector<vector<int>> matrica (0, vector<int>(2,0));
	int x=kraj2-poc2;
		
		int k(0), test(1);
		for(int i=0; i<n; i++){
			for(int j=0; j<x; j++) {
				if(r(poc1[i])==r(poc2[j])) {test=0; break;}
			}
			if(test==1){
				matrica.resize(k+1);
				matrica[k].push_back(poc1[i]);
				matrica[k].push_back(r(poc1[i]));
				k++;
			}
			test=1;
			
		}
		test=1;
		for(int i=0; i<x; i++){
			for(int j=0; j<n; j++) {
				if(r(poc2[i])==r(poc1[j])) {test=0; break;}
			}
			if(test==1){
				matrica.resize(k+1);
				matrica[k].push_back(poc2[i]);
				matrica[k].push_back(r(poc2[i]));
				k++;
			}
			test=1;
			
		}
			sort(begin(matrica), end(matrica), [] (vector<int> x, vector<int> y)->bool {
			
		if(x[0] == y[0]){
			if(x[1] == y[1])  return false;
			 return x[1]>y[1];
			}
			 return x[0] > y[0];
		
			
	});
		
		
		return matrica;
	}

template<typename tip1, typename tip2>

auto UvrnutaRazlika (tip1 poc1, tip1 kraj1, tip2 poc2, tip2 kraj2) -> vector<vector<decltype(*poc1+0)>>{
	int n=kraj1-poc1; //n je br cl prvog kontejnera
		vector<vector<decltype(*poc1+0)>> matrica (0, vector<decltype(*poc1+0)>(2,0));
	int x=kraj2-poc2;
		
		int k(0), test(1);
		for(int i=0; i<n; i++){
			for(int j=0; j<x; j++) {
				if(poc1[i]==poc2[j]) {test=0; break;}
			}
			if(test==1){
				matrica.resize(k+1);
				matrica[k].push_back(poc1[i]);
				matrica[k].push_back(0);
				k++;
			}
			test=1;
			
		}
		test=1;
		for(int i=0; i<x; i++){
			for(int j=0; j<n; j++) {
				if(poc2[i]==poc1[j]) {test=0; break;}
			}
			if(test==1){
				matrica.resize(k+1);
				matrica[k].push_back(poc2[i]);
				matrica[k].push_back(0);
				k++;
			}
			test=1;
			
		}
			sort(begin(matrica), end(matrica), [] (vector<decltype(*poc1+0)> x, vector<decltype(*poc1+0)> y)->bool {
			
	if(x[0]==y[0]) return false;
		 return (x[0]>y[0]);
	});
		
	
				
			
		
		
		return matrica;
	}



int main ()
{
	cout<<endl<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	cin>>n;
	deque<int> a;
	deque<int> b;
	int z, testna(0);
	
	cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0; i<n; i++){
		cin>>z;
		if(i>0)
		for(int j=0; j<i; j++){
			if(a[j]==z) {
				i--;
				testna=1;
				break;
			}
		}
		if(testna==0) a.push_back(z);
		testna=0;
	}
	testna=0;
	
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	int x;
	cin>>x;
	cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0; i<x; i++){
		cin>>z;
		if(i>0)
		for(int j=0; j<i; j++){
			if(b[j]==z) {
				i--;
				testna=1;
				break;
			}
		}
		if(testna==0) b.push_back(z);
		testna=0;
	}

	vector<vector<int>> u;
	cout<<"Uvrnuti presjek kontejnera:"<<endl;
	u=UvrnutiPresjek(begin(a), end(a), begin(b), end(b), f);
	for(int i=0; i<u.size(); i++){
		for(int j=0; j<u[i].size(); j++) {
		 cout<<setw(6)<<u[i][j]<<" ";
		}
		cout<<endl;
	}
	
	vector<vector<int>>neki;

	cout<<"Uvrnuta razlika kontejnera:"<<endl;
		vector<vector<int>> g;

	g=UvrnutaRazlika(begin(a), end(a), begin(b), end(b), BrojProstihFaktora);
	for(int i=0; i<g.size(); i++){
		for(int j=0; j<g[i].size(); j++) {

		cout<<setw(6)<<g[i][j]<<" ";
	
		}
		cout<<endl;
	}
	
	cout<<"Dovidjenja!";
	
	return 0;
}