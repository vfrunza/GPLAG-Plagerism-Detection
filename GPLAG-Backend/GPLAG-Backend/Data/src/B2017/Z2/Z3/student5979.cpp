/*B 2017/2018, Zadaća 2, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <new>
#include <stdexcept>
#include <algorithm>
template <typename Tip3>
int period(const std::vector<Tip3> &v1){
		bool period;
	int per;
	for (int p = v1.size(); p > 0; p--) {
		period=true;
		for (int i = 0; i <v1.size()-p ; i++) {
			if(v1.at(i)!=v1.at(p+i))
			period=false;
		}
		if(period=true)
		per=p;
	}
	return per;
}
template <typename Tip1>
auto  AlocirajFragmentirano(const std::vector<Tip1> &v1, int & koliko_puta) -> Tip1**{
	for (int i = 0; i < v1.size(); i++) {
		if(v1.at(i)<=0)
		throw std::domain_error("Neispravan vektor!");
	}
	if(v1.size()==0)
		throw "Prazan vektor";
		 int per=period(v1);
		if(per==v1.size()){
			koliko_puta=2;
		}else{
			koliko_puta=v1.size()/per;
			if(v1.size()%per!=0) koliko_puta++;
		}
		Tip1*pok[per*koliko_puta];
		for (int i = 0; i < per*koliko_puta; i++)
			pok[i]=nullptr;
		try{
		for (int i = 0; i < per*koliko_puta; i++) 
			pok[i]=new Tip1[v1.at(i%per)];
		
		
	
		for (int i = 0; i < per*koliko_puta; i++) {
			for (int j = 1; j <= v1.at(i%per); j++) {
				pok[i][j-1]=j;
			}
		}
		}catch{
			for (int i = 0; i < koliko_puta*per; i++) {
				delete[] pok[i];
				throw bad_alloc;
			}
		}
		return &pok[0];
}
template <typename Tip2>
auto AlocirajKontinualno(const std::vector<Tip2> v1,int koliko_puta)->Tip2{
	for (int i = 0; i < v1.size(); i++) 
		if(v1.at(i)<=0)	
			throw std::domain_error ("Neispravan vektor!");
	if(v1.size()==0)
		throw "Prazan vektor!";
	int per=period(v1);
		if(per==v1.size()){
			koliko_puta=2;
		}else{
			koliko_puta=v1.size()/per;
			if(v1.size()%per!=0) koliko_puta++;
		}
	Tip2 maximal=max(v1.begin(),v1.end());
	Tip2*pok[per*koliko_puta];
	for (int i = 0; i < per*koliko_puta; i++)
		pok[i]=nullptr;
	Tip2 velicina(0);
	for (int i = 0; i < per*koliko_puta; i++) {
		 velicina+=maximal-v1.at(i&per)+1;
	}
	pok[0]=new Tip2[velicina];
	for (int i = 1;i < pok*koliko_puta; i++) {
		pok[i]=pok[i-1]+maximal-*pok[i-1]+1;
	}
	for (int i = 0; i < pok*koliko_puta; i++) {
		for (int j =maximal-*pok[i]+1;j>0 ;j++) {
			pok[i][maximal-*pok[i]+1-j]=j;
		}
	}
	return &pok[0];
} 

int main ()
{
	int n;
	std::cin >> n;
	std::vector<int> v1 ;
	int a;
	try{
	for (int i = 0; i < n; i++) {
		std::cin >> a;
		v1.push_back(a);
	}
	int maximal=*std::max(v1.begin(),v1.end());
	std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int f;
	while(std::cin >> f,f!=0&&f!=1);
	int koliko_puta;
	int per=period(v1);
	auto pok=*f(v1,koliko_puta);
	if(f){
		for (int i = 0; i < koliko_puta*per; i++) {
			for (int j = 0; j <= *pok[i]; j++) {
				cout<<
			}
		}
		
		
		
		
		
	}
	}catch(std::bad_alloc izuzetak){
		
	}catch(std::domain_error izuzetak){
		std::cout << izuzetak.what() << std::endl;
	}catch(std::string s){
		std::cout << s;
	}
	
	return 0;
}