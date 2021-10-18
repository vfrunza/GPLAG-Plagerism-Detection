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
#include <type_traits>
#include <stdexcept>
#include <new>
//Nije uradjen citav zadatak, pokusaj...
template <typename NekiTip>
bool TestPerioda(std::vector<NekiTip> v, int p){
	if(p>=v.size() || p<1) return 0;
	bool periodican(true);
	for(int i=0; i<v.size()-p; i++){
		if(v.at(i)!=v.at(i+p)){
			periodican=false;
			break;
		}
	}
	return periodican;
}
template <typename NekiTip>
int OsnovniPeriod(std::vector<NekiTip> v){
	for(int i=0; i<v.size(); i++)
	if(TestPerioda(v,i)) return i;
	return 0;
}
template <typename NekiTip>
int OdrediKolikoPuta(const std::vector<NekiTip> &v){
	int period=OsnovniPeriod(v);
	int KolikoPuta;
	if(period!=0){
		int test;
		test=v.size()%period;
		if(test!=0){
			int i=0;
			while(test!=0){
				i++;
				test=(v.size()+i)%period;
			}
			KolikoPuta=period+1;
		}
	}else{
		KolikoPuta=2;
	}
	return KolikoPuta;
}
template <typename NekiTip>
auto AlocirajFragmentirano(const std::vector<NekiTip> &v, int &koliko_puta)
->NekiTip**{
	if(v.size()<=0) throw std::domain_error("Prazan vektor!");
	for(int i=0; i<v.size(); i++)
	if(v[i]<0) throw std::domain_error("Neispravan vektor!");
	koliko_puta=OdrediKolikoPuta(v);
	int br_elemenata=0;
	if(OsnovniPeriod(v)!=0) br_elemenata=koliko_puta*OsnovniPeriod(v);
	else br_elemenata=v.size()*koliko_puta;
	int period=OsnovniPeriod(v);
	if(period==0) period=v.size();
	NekiTip **a=nullptr;
	a= new NekiTip*[koliko_puta];
	for(int i=0; i<br_elemenata; i++) a[i]=nullptr;
	try{
		for(int i=0; i<period; i++){
			a[i]=new NekiTip[i+1];
		}/*
		for(int i=0; i<koliko_puta; i++){
			for(int j=0; j<period; j++){
				a[i][j]=1;
			}
		}*/
	} catch(std::bad_alloc){
		throw;
		for(int i=0; i<koliko_puta; i++) delete[] a[i];
		delete[] a;
		a=nullptr;
	}
	return a;
}
template <typename NekiTip>
auto AlocirajKontinualno(const std::vector<NekiTip> &v, int &koliko_puta) 
->NekiTip**{
	if(v.size()==0) throw std::domain_error("Prazan vektor!");
	for(int i=0; i<v.size(); i++)
	if(v[i]<0) throw std::domain_error("Neispravan vektor!"); 
	koliko_puta=OdrediKolikoPuta(v);
	
	
}
template <typename NekiTip>
void Ispisi(NekiTip **a, int koliko_puta){
	for(int i=0; i<koliko_puta; i++){
		for(int j=0; j<i+1; j++) std::cout<<a[i][j]<<" ";
		std::cout<<std::endl;
	}
}
int main ()
{
	try{
		int n;
		std::cout<<"Unesite broj elemenata vektora: ";
		std::cin>>n;
		std::vector<int> v(n);
		std::cout<<"Unesite elemente vektora: ";
		for(int i=0; i<v.size(); i++)
		std::cin>>v[i];
	    int alokacija;
	    std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	    std::cin>>alokacija;
	    if(alokacija){
			int koliko_puta;
			auto a=AlocirajFragmentirano<int>(v,koliko_puta);
			std::cout<<"Dinamicki alocirana matrica:\n";
			Ispisi(a,koliko_puta);
			for(int i=0; i<koliko_puta; i++) delete [] a[i];
			delete [] a;
		} else{
			int koliko_puta;
		    auto a=AlocirajKontinualno<int>(v,koliko_puta);	
		    std::cout<<"Dinamicki alocirana matrica:\n";
		    Ispisi(a,koliko_puta);
		}
	}catch(std::domain_error izuzetak){
			std::cout<<"Izuzetak: "<<izuzetak.what();
		}
	return 0;
}