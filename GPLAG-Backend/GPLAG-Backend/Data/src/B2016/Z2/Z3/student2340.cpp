/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

#include <iostream>
#include <deque>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>

long long int SumaDjelilaca(int n){
	int suma(0);
		for(int i=1; i<=n; i++){
			if(n%i==0) suma+=i;
		}
	return suma;
}

long long int SumaDjelilacaBezPosljednjeg(int n){
	int suma(0);
		for(int i=1; i<n; i++){
			if(n%i==0) suma+=i;
		}
	return suma;
}

bool Prost(int n){
	int brojac(0);
	for(int i=2; i<n; i++){
		if((n%i)==0) 
			brojac++;
	}
		if(brojac==0) return true;
	return false;
}

long long int BrojProstihFaktora(int n){
	int broj(0);
		for(int i=2; i<=n; i++){
			while(n%i==0){
				n/=i;
				broj++;
			}
		}
	return broj;
}

bool Savrsen(int n){
	if(SumaDjelilacaBezPosljednjeg(n)==n) return true;
	return false;
}

long long int BrojSavrsenihDjelilaca(int n){
	int brojac(0);
		for(int i=2; i<n; i++){
			if(n%i==0){
				if(Savrsen(i)==true)
					brojac++;
			}
		}
	return brojac;
}

int SumaCifara(int n){
	int suma(0);
	int ostatak;
	do{
		ostatak=n%10;
		suma+=ostatak;
		n/=10;
	} while(n!=0);

	return suma;
}

template <typename Tip1, typename Tip2>
bool DaLiSuJednaki(Tip1 n, Tip1 m, Tip2 *f(Tip2)){
	if(f(n)!=f(m)) return false;
return true;
}

template <typename NekiTip1,typename NekiTip2,typename NekiTip3, typename NekiTip4>
	std::deque<std::deque<NekiTip3>> UvrnutiPresjek(NekiTip1 pok1,NekiTip1 pok2,NekiTip2 pok3,NekiTip2 pok4, NekiTip3 (*f)(NekiTip4)){

	std::deque<std::deque<NekiTip3>> matrica(0);

	for(auto i=pok1; i!=pok2; i++){
		for(auto j=pok3; j!=pok4; j++){
			if (f(*i)==f(*j)) {
				std::deque<NekiTip3> v({*i, *j, f(*i)});
				matrica.push_back(v);
			}
		}
	}
	
	sort(matrica.begin(),matrica.end(), [](const std::deque<int> &v1, const std::deque<int> &v2)-> bool {
		if(v1[2]<v2[2]) return true;
		else if(v1[2]==v2[2])	
			if(v1[0]<v2[0]) return true;
			else if(v1[0]==v2[0])  return v1[1]<v2[1];
		});
return matrica;
}

template <typename NekiTip1,typename NekiTip2,typename NekiTip3,typename NekiTip4>
	std::deque<std::deque<NekiTip3>> UvrnutaRazlika (NekiTip1 pok1, NekiTip1 pok2, NekiTip2 pok3, NekiTip2 pok4, NekiTip3 (*f)(NekiTip4)){
		
		std::deque<std::deque<NekiTip3>> matrica(0);
		
		for(auto i=pok1; i!=pok2; i++){
			bool NalaziSe=false;
			for(auto j=pok3; j != pok4; j++){
				if(f(*i)==f(*j)) {
					NalaziSe=true;
					break;
				}
			}
			if(NalaziSe==false){
				std::deque<NekiTip3> v({*i, f(*i)});
				matrica.push_back(v);
			}
		}
		
		for(auto i=pok3; i!=pok4; i++){
			bool NalaziSe=false;
			for(auto j=pok1; j != pok2; j++){
				if(f(*i)==f(*j)) {
					NalaziSe=true;
					break;
				}
			}
			if(NalaziSe==false){
				std::deque<NekiTip3> v({*i, f(*i)});
				matrica.push_back(v);
			}
		}
	
	return matrica;		
}

int main (){
	
	std::set<int> v,d;
	int n,m;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>n;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for (int i=0; v.size()!=n; i++){
		int a;
		std::cin>>a;
		v.insert(a);
	}
	
	
//	std::cin.clear();
//	std::cin.ignore(1000,'\n');
	
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>m;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int j=0; d.size()!=m; j++){
		int b;
		std::cin>>b;
		d.insert(b);
	}
	
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	
	auto a(UvrnutiPresjek(v.begin(),v.end(),d.begin(),d.end(), SumaCifara));
	
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<a[i].size(); j++){
			std::cout<<std::setw(6)<<a[i][j]<<" ";
		}
	std::cout<<std::endl;
	}
	
	auto b( UvrnutaRazlika (v.begin(),v.end(),d.begin(),d.end(), BrojProstihFaktora));
	
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;

	for(int i=0; i<b.size(); i++){
		for(int j=0; j<b[i].size(); j++){
			std::cout<<std::setw(6)<<b[i][j]<<" ";
		}
	std::cout<<std::endl;
	}

	std::cout<<"Dovidjenja!";

	return 0;
	
	
}