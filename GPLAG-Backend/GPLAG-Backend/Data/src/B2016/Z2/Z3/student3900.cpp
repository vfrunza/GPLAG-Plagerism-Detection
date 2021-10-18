/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <deque>
#include <iterator>
#include <type_traits>
#include <algorithm>
#include <vector>
using namespace std;
int SumaDjelilaca(long long int a){
	int suma=0; 
	for(int i=1; i<a; i++){
		if(a%i==0) suma+=i;
	}
return suma;
}
bool Prosti(int a){
	for(int i=2; i<a; i++){
		if(a%i==0) return true;
	}
	return false;
}
int BrojProstihFaktora(long long int a){
	int b=0; 
	for(int i=2; i<a; i++){
		if(a%i==0 && (!Prosti(i))) b++;
	}
	return b;
}
bool Savrseni(long long int a){
	int suma=0;
	for(int i=1; i<a; i++){
		if(a%i==0) suma+=i;
	}
	if(suma==a) return true;
	return false;
}

int BrojSavrsenihDjelilaca(long long int b){
	int br=0;
	for(int i=2; i<b; i++){
		if(b%i==0 && Savrseni(i)) br++;
	}
	return br;
}

int pf(long long int a){
	int i;
	int  suma=0;
	while(a!=0){
		i=a%10;
		suma+=i;
		a/=10;
	}
	return suma;
}

template <typename t1, typename t2, typename t3, typename t4>
vector<vector<int>>UvrnutiPresjek(t1 p1, t1 p2, t2 p3, t2 p4,t3 pf(t4)){
	vector<int>v;
	vector<vector<int>>mat;
	auto a=p3;
	while(p1!=p2){
		while(p3!=p4){
			if(pf(*p1)==pf(*p3)){
			v.push_back(*p1);
			v.push_back(*p3);
			v.push_back(pf(*p1));
			mat.push_back(v);
			//v.clear();		
			}
			v.clear();
			p3++;
		}
		p3=a;
		p1++;
	}
	return mat;
}

template <typename t1, typename t2, typename t3, typename t4>
vector<vector<int>>UvrnutaRazlika(t1 p1, t1 p2, t2 p3, t2 p4,t3 pf(t4)){
	
	vector<int>v;
	vector<vector<int>>mat;
	auto a=p3;
	while(p1!=p2){
		while(p3!=p4){
			if(pf(*p1)==pf(*p3)){
			v.push_back(*p1);
			v.push_back(pf(*p1));
			mat.push_back(v);	
			}
			v.clear();
			p3++;
		}
		p3=a;
		p1++;
	}
	return mat;
}

int main (){
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	cin>>n;
	cout<<"Unesite elemente prvog kontejnera: ";
	deque<int>d1;
	int b=0, i=0;
	d1.resize(n);
	for(int i=0; i<d1.size(); i++){
		cin>>d1[i];
	}
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	int n1;
	cin>>n1;
	cout<<"Unesite elemente drugog kontejnera: ";
	deque<int>d2;
	d2.resize(n1);
	for(int i=0; i<d2.size(); i++){
		cin>>d2[i];
		
	}
	vector<vector<int>>a=UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), pf);
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<a[i].size(); j++){
			cout<<a[i][j]<<"    ";
		}
		cout<<endl;
	}
	vector<vector<int>>h=UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), pf);
	for(int i=0; i<h.size(); i++){
		for(int j=0; j<h[i].size(); j++){
			cout<<h[i][j]<<"    ";
		}
		cout<<endl;
	}
	return 0;
}