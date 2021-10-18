/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <type_traits>
#include <algorithm>
#include <deque>
#include <cmath>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//valjda je suma nula ako je a negativan
int SumaDjelilaca(long long int a){
	int suma = 0;
	for (int i = 1; i <= a; i++) {
		if(a%i==0)suma+=i;
	}
	return suma;
}
bool savrsen_broj(long long int broj){
	long long int suma=0;
	for (int i = 1; i < broj; i++) {
		if(broj%i==0)suma+=i;
	}
	return (suma==broj);
}
int BrojSavrsenihDjelilaca(long long int a){
	int broj=0;
	for (int i = 1; i <= a; i++) {
		if(a%i==0 && savrsen_broj(i))broj++;
	}
	return broj;
}
bool prost(long long int a){
	if(a<2)return false;
	for (int i = 2; i <= std::sqrt(a); i++) {
		if(a%i==0)return false;
	}
	return true;
}
int BrojProstihFaktora(long long int a){
	int c=0;
	for (int i = 1; i <= a; i++) {
		if(a%i==0)if(prost(i)){
			c++;
			a/=i;
			i=1;
		}
	}
	return c;
}
int SumaCifara(long long int a){
	int suma = 0;
	while (a!=0) {
		if(a<0)suma+=a%-10;
		else suma+=a%10;
		a/=10;
	}
	if(suma<0)suma*=-1;
	return suma;
}
template <typename Ipok,typename IIpok,typename TipF=int,typename TipP=int>
auto UvrnutiPresjek(Ipok a, Ipok b, IIpok c, IIpok d, TipF F(TipP)=nullptr )->std::vector<std::vector<typename std::remove_reference<decltype (*a)>::type>>{
	typedef typename std::remove_reference<decltype (*a)>::type tipvar;
	typedef std::vector<tipvar> Red;
	std::vector<Red>  izlaz;
	Ipok p=a;
	IIpok q=c;
	while (p!=b) {
		q=c;
		tipvar rez;
		if(F!=nullptr)rez=F(*p);
		else rez=0;
		while (q!=d) {
		Red red;
			if(F!=nullptr){
			if(rez==F(*q)){
				red.push_back(*p);
				red.push_back(*q);
				red.push_back(rez);
				izlaz.push_back(red);
			}}else{
				if(*q==*p)izlaz.push_back(Red{*q,0,0});
			}
			q++;
		}
		p++;
	}
	std::sort(izlaz.begin(),izlaz.end(),[](Red ulaz, Red ulaz2){
		if(ulaz.at(2)==ulaz2.at(2)){
			if(ulaz.at(0)==ulaz2.at(0)){
				return (ulaz.at(1)<ulaz2.at(1));}
			else return (ulaz.at(0)<ulaz2.at(0));}
		else return (ulaz.at(2)<ulaz2.at(2));});
	return izlaz;
}

template <typename Ipok,typename IIpok,typename TipF=int,typename TipP=int>
auto UvrnutaRazlika(Ipok a, Ipok b, IIpok c, IIpok d, TipF F(TipP)=nullptr )->std::vector<std::vector<typename std::remove_reference<decltype (*a)>::type>>{
	typedef typename std::remove_reference<decltype (*a)>::type tipvar;
	typedef std::vector<tipvar> Red;
	std::vector<Red>  izlaz;
	Ipok q=a;
	IIpok p=c;
	int poz=0;
	while (q!=b) {
		tipvar rez;
		if(F!=nullptr)rez= F(*q);
		else rez=0;
		p=c;
		bool imapar = false;
		while (p!=d) {
			if(F!=nullptr){
			if(rez==F(*p))imapar=true;}
			else {
				if(*p==*q){imapar=true;break;}
			}
			p++;
		}
		if(!imapar)izlaz.push_back(Red{*q,rez});
		q++;
	}
	q=a;
	p=c;
	while (p!=d) {
		tipvar rez;
		if(F!=nullptr)rez = F(*p);
		else rez=0;
		q=a;
		bool imapar=false;
		while (q!=b) {
			if(F!=nullptr){
			if(rez==F(*q))imapar=true;}
			else {
				if(*q==*p){imapar=true;break;}
			}
			q++;
		}
		if(!imapar)izlaz.push_back(Red{*p,rez});
		p++;
	}
	std::sort(izlaz.begin(),izlaz.end(),[](Red l,Red r){
	if(l.at(0)==r.at(0))return (l.at(1)>r.at(1));
	return (l.at(0)>r.at(0));
	});
	return izlaz;
}

template<typename tip>
void printaj(std::vector<std::vector<tip>> a){
	for(auto e : a){
		for(auto i : e){
			cout<<std::setw(6)<<i<<" ";
		}
		cout<<endl;
	}
}
int main ()
{
	std::deque<int> a,b;
	int n;
	cout<<"Unesite broj elemenata prvog kontejnera: ";
	cin>>n;
	cout<<"Unesite elemente prvog kontejnera: ";
	for (int i = 0; i <n; i++) {
		int t;
		cin>>t;
		bool vecima= false;
		for (int j = 0; j < a.size(); j++) {
			if(t==a.at(j)){i--;vecima=true;break;}
		}
		if(!vecima)a.push_back(t);
	}
	cout<<"Unesite broj elemenata drugog kontejnera: ";
	cin>>n;
	cout<<"Unesite elemente drugog kontejnera: ";
	for (int i = 0; i < n; i++) {
		int t;
		cin>>t;
		bool vecima= false;
		for (int j = 0; j < b.size(); j++) {
			if(t==b.at(j)){i--;vecima=true;break;}
		}
		if(!vecima)b.push_back(t);
	}
	cout<<"Uvrnuti presjek kontejnera:\n";
	std::vector<std::vector<int>> rez = UvrnutiPresjek(a.begin(),a.end(),b.begin(),b.end(),SumaCifara);
	printaj(rez);
	cout<<"Uvrnuta razlika kontejnera: \n";
	rez = UvrnutaRazlika(a.begin(),a.end(),b.begin(),b.end(),BrojProstihFaktora);
	printaj(rez);
	cout<<"Dovidjenja!";
	return 0;
}