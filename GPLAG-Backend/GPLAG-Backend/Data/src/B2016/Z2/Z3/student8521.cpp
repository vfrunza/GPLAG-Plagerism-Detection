/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <type_traits>

using namespace std;

int SumaDjelilaca(long long int p){
	int suma(0);
	for(int i=1;i<=abs(p);i++){
		if(abs(p)%i==0)suma+=i;
	}
	return suma;
}
bool Prost(long long int n){
	if(n==1)return true;
	for(int i=2;i<n;i++){
		if(n%i==0)return false;
	}
	return true;
}

int BrojProstihFaktora(long long int x){
	int broj(0);
	for(int i=2;i<=x;i++){
		if(x%i==0 && Prost(i)){
			int h(i);
			while(x%h==0){
				broj++;
				h*=i;
			}
		}
	}
	return broj;
}

long long int sumadjel(long long int br){
	int suma(0);
	for(int i=1;i<br;i++){
		if(br%i==0)suma+=i;
	}
	return suma;
}
bool Savrsen(long long int broj){
	if(broj==sumadjel(broj))return true;
	return false;
}
int BrojSavrsenihDjelilaca(long long int broj){
	int izbroj(0);
	for(int i=1;i<=broj;i++){
		if(broj%i==0 && Savrsen(i))izbroj++;
	}
	return izbroj;
}

int SumaCifara(int n){
	int suma(0);
	while(n!=0){
		int cifra=abs(n%10);
		suma+=cifra;
		n/=10;
	}
	return suma;
}

template<typename IterTip1,typename IterTip2,typename TIP,typename tip>
vector<vector<tip>> UvrnutiPresjek(IterTip1 pocetak,IterTip1 iza_kraja,IterTip2 pocetak2,IterTip2 iza_kraja2,tip f(TIP)){
	int br_el(0);
	vector<vector<tip>>v;
	IterTip1 pomoc(pocetak);
	IterTip2 pomoc3(pocetak2),pok(pocetak2);
	while(pocetak!=iza_kraja){
		pocetak2=pok;
		while(pocetak2!=iza_kraja2){
			if(f(*pocetak)==f(*pocetak2)){br_el++;}
			pocetak2++;
		}pocetak++;
	}
	v.resize(br_el);
	int i(0);
	while(pomoc!=iza_kraja){
		pomoc3=pok;
		while(pomoc3!=iza_kraja2){
			if(f(*pomoc)==f(*pomoc3)){v[i].push_back(*pomoc);v[i].push_back(*pomoc3);v[i].push_back(f(*pomoc));i++;}
			pomoc3++;
		}pomoc++;
	}
	sort(v.begin(),v.end(),[=](vector<tip>v1,vector<tip>v2){
	if(f(v1[2])==f(v2[2]) && v1[0]==v2[0]){return v1[1]<v2[1];}	
	if(f(v1[2])==f(v2[2])){return v1[0]<v2[0];}
	return v1[2]<v2[2];
	});
	return v;
}

template<typename IterTip3,typename IterTip4,typename TIP2,typename TIP3>
vector<vector<TIP3>> UvrnutaRazlika(IterTip3 pocetak,IterTip3 iza_kraja,IterTip4 pocetak2,IterTip4 iza_kraja2,TIP3 f(TIP2)){
	int br_el(0);
	vector<vector<TIP3>>v;
	bool a;
	IterTip3 pomoc(pocetak),p(pocetak),pok2(pocetak),ubicuse(pocetak);
	IterTip4 pomoc3(pocetak2),pok(pocetak2),p1(pocetak2),ubicuse1(pocetak2);
	while(pocetak!=iza_kraja){
		pocetak2=pok;a=false;
		while(pocetak2!=iza_kraja2){
			if(f(*pocetak)==f(*pocetak2)){a=true;break;}
			pocetak2++;
		}
		if(a==false)br_el++;
		pocetak++;
	}
	while(p1!=iza_kraja2){
		p=pok2;a=false;
		while(p!=iza_kraja){
			if(f(*p1)==f(*p)){a=true;break;}
			p++;
		}
		if(a==false)br_el++;
		p1++;
	}
	v.resize(br_el);
	int i(0);
	while(pomoc!=iza_kraja){
		pomoc3=pok;a=false;
		while(pomoc3!=iza_kraja2){
			if(f(*pomoc)==f(*pomoc3)){a=true;break;}
			pomoc3++;
		}if(a==false){v[i].push_back(*pomoc);v[i].push_back(f(*pomoc));i++;}
		pomoc++;
	}
	while(ubicuse1!=iza_kraja2){
		ubicuse=pok2;a=false;
		while(ubicuse!=iza_kraja){
			if(f(*ubicuse1)==f(*ubicuse)){a=true;break;}
			ubicuse++;
		}if(a==false){v[i].push_back(*ubicuse1);v[i].push_back(f(*ubicuse1));i++;}
		ubicuse1++;
	}
	sort(v.begin(),v.end(),[=](vector<TIP3>v1,vector<TIP3>v2){
	if(v1[0]==v2[0]){return f(v1[1])>f(v2[1]);}	
	return v1[0]>v2[0];
	});
	return v;
	
}
template<typename IterTip1,typename IterTip2>
auto UvrnutiPresjek(IterTip1 pocetak,IterTip1 iza_kraja,IterTip2 pocetak2,IterTip2 iza_kraja2)->vector<vector<typename remove_reference<decltype(*pocetak)>::type>>{
	int br_el(0);
	vector<vector<typename remove_reference<decltype(*pocetak)>::type>>v;
	IterTip1 pomoc(pocetak),pomoc2(pocetak);
	IterTip2 pomoc1(pocetak2),pok(pocetak2),pomoc3(pocetak2);
	while(pocetak!=iza_kraja){
		pocetak2=pok;
		while(pocetak2!=iza_kraja2){
			if(*pocetak==*pocetak2)br_el++;
			pocetak2++;
		}
		pocetak++;
	}
	v.resize(br_el);
	int i(0);
	while(pomoc2!=iza_kraja){
		pomoc3=pok;
		while(pomoc3!=iza_kraja2){
			if(*pomoc2==*pomoc3){v[i].push_back(*pomoc2);v[i].push_back(0);v[i].push_back(0);i++;}
			pomoc3++;
		}
		pomoc2++;
	}
	sort(v.begin(),v.end(),[=](vector<typename remove_reference<decltype(*pocetak)>::type>v1,vector<typename remove_reference<decltype(*pocetak)>::type>v2){
	return v1[0]<v2[0];
	});
	return v;
}

template <typename IterTip3,typename IterTip4>
auto UvrnutaRazlika(IterTip3 pocetak,IterTip3 iza_kraja,IterTip4 pocetak2,IterTip4 iza_kraja2)->vector<vector<typename remove_reference<decltype(*pocetak)>::type>>{
	int br_el(0);
	vector<vector<typename remove_reference<decltype(*pocetak)>::type>>v;
	bool a;
	IterTip3 pomoc(pocetak),p(pocetak),pok2(pocetak),ubicuse(pocetak);
	IterTip4 pomoc3(pocetak2),pok(pocetak2),p1(pocetak2),ubicuse1(pocetak2);
	while(pocetak!=iza_kraja){
		pocetak2=pok;a=false;
		while(pocetak2!=iza_kraja2){
			if(*pocetak==*pocetak2){a=true;break;}
			pocetak2++;
		}
		if(a==false)br_el++;
		pocetak++;
	}
	while(p1!=iza_kraja2){
		p=pok2;a=false;
		while(p!=iza_kraja){
			if(*p1==*p){a=true;break;}
			p++;
		}
		if(a==false)br_el++;
		p1++;
	}
	v.resize(br_el);
	int i(0);
	while(pomoc!=iza_kraja){
		pomoc3=pok;a=false;
		while(pomoc3!=iza_kraja2){
			if(*pomoc==*pomoc3){a=true;break;}
			pomoc3++;
		}if(a==false){v[i].push_back(*pomoc);v[i].push_back(0);i++;}
		pomoc++;
	}
	while(ubicuse1!=iza_kraja2){
		ubicuse=pok2;a=false;
		while(ubicuse!=iza_kraja){
			if(*ubicuse1==*ubicuse){a=true;break;}
			ubicuse++;
		}if(a==false){v[i].push_back(*ubicuse1);v[i].push_back(0);i++;}
		ubicuse1++;
	}
	sort(v.begin(),v.end(),[=](vector<typename remove_reference <decltype(*pocetak)>::type>v1,vector<typename remove_reference<decltype(*pocetak)>::type>v2){
		return v1[0]>v2[0];
	});
	return v;
}

int main ()
{
	
	vector<int>v1,v2;
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;cin>>n;;
	cout<<"Unesite elemente prvog kontejnera: ";
	int brojac(0);bool a;
	while(brojac<n){
		int element;
		cin>>element;brojac++;a=false;
		for(vector<int>::iterator i=v1.begin();i!=v1.end();i++){
			if(*i==element){a=true;brojac--;break;}
		}
		if(a==false)v1.push_back(element);
	}
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	int m;cin>>m;
	cout<<"Unesite elemente drugog kontejnera: ";
	brojac=0;
	while(brojac<m){
		int element;
		cin>>element;brojac++;a=false;
		for(vector<int>::iterator i=v2.begin();i!=v2.end();i++){
			if(*i==element){a=true;brojac--;break;}
		}
		if(a==false)v2.push_back(element);
	}
	cout<<"Uvrnuti presjek kontejnera:"<<endl;
	vector<vector<int>>V;
	V=UvrnutiPresjek(v1.begin(),v1.end(),v2.begin(),v2.end(),SumaCifara);
	for(int i=0;i<V.size();i++){
		for(int j=0;j<V[i].size();j++)cout<<setw(6)<<V[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Uvrnuta razlika kontejnera:"<<endl;
	vector<vector<int>>w;
	w=UvrnutaRazlika(v1.begin(),v1.end(),v2.begin(),v2.end(),BrojProstihFaktora);
	for(int i=0;i<w.size();i++){
		for(int j=0;j<w[i].size();j++)cout<<setw(6)<<w[i][j]<<" ";
		cout<<endl;
	}
	cout<<"Dovidjenja!";
	
	return 0;
}