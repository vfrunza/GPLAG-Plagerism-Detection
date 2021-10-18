#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
template <typename NekiTip>
bool Period( const std::vector<NekiTip>& a, int p)
{
	if(p<=0 || p>=a.size()) return false;
	for(int i=0; i<a.size()-p; i++) {
		if(a[i]!=a[i+p]) return false;
	}
	return true;
}
template <typename NekiTip>
int o_period( const std::vector<NekiTip>&a)
{
	for(int i=1; i<a.size(); i++) {
		if(Period(a,i)) return i;
	}
	return 0;
}

template <typename NekiTip>
int Modificiraj( const std::vector<NekiTip>& a, int&koliko_puta)
{
	if(a.size()==0) throw "Prazan vektor!";
	int p(o_period(a));
	NekiTip velicina(a.size());
	if(p) {
	
		while(velicina%p!=0 || velicina%3!=0) velicina++;
		koliko_puta=velicina/p;


	} else {
		koliko_puta=2;
		p=velicina;
	}

	return p;

}

template <typename NekiTip>

int**AlocirajFragmentirano(const std::vector<NekiTip>&a, int &koliko_puta)
{

	int p(Modificiraj(a,koliko_puta));


	int**pok(new int*[koliko_puta*p] {});
	try {
		for(int k=0; k<koliko_puta; k++) {
			for(int i=0; i<p; i++) {
				if(a[i]<=0) {
					for(int j=0; j<k*p+i; j++) delete[] pok[j];
					delete[] pok;
					throw std::domain_error("Neispravan vektor!");
				}
				pok[k*p+i]=new int[a[i]];
			}
		}
		NekiTip maksi(*(std::max_element(a.begin(),a.begin()+p))),kopija(maksi);
		for(int k=0; k<koliko_puta; k++) {
			for(int i=0; i<p; i++) {
				maksi=kopija;
				for(int j= a[i]-1; j>=0; j--) {
					pok[k*p+i][j]=maksi;
					maksi--;

				}
			}
		}

		return pok;
	} catch(std::bad_alloc) {
		for(int i=0; i<p*koliko_puta; i++) delete [] pok[i];
		delete pok;

	}


}
template <typename NekiTip>
int**AlocirajKontinualno(const std::vector<NekiTip> a, int&koliko_puta)
{

	int p(Modificiraj(a,koliko_puta));

	int** pok(new int* [p*koliko_puta] {});
	NekiTip suma(0);
	std::for_each(a.begin(),a.begin()+p,[&suma](int x)->void { suma+=x;});
	try {
		pok[0]=new int[suma*koliko_puta];
		for(int k=0; k<koliko_puta; k++) {
			for(int i=0; i<p; i++) {

				if(a[i]<=0) {
					delete [] pok[0];
					delete[] pok;
					throw std::domain_error("Neispravan vektor!");
				}
				if(k==0 && i==0) continue;
				else if(k!=0 && i==0) pok[k*p]=pok[k*p-1]+a[p-1];
				else pok[k*p+i]=pok[k*p+i-1] + a[i-1];

			}


		}
		for(int k=0; k<koliko_puta; k++) {
			for(int i=0; i<p; i++) {
				NekiTip duzina(a[i]);
				for(int j=0; j<a[i]; j++) {
					pok[k*p+i][j]=duzina;
					duzina--;
				}
			}
		}

		return pok;



	} catch(std::bad_alloc) {
		delete[] pok;
	}

}




int main ()
{
	
	
	int b,n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	try{
		
 std::vector<int> a(n);
	std::cout<<"Unesite elemente vektora: ";
for(int i=0;i<n;i++) std::cin>>a[i];
	std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	std::cin>>n;
	
int p(Modificiraj(a,b));
		int**pok(nullptr);
	if(n==1)	pok=AlocirajFragmentirano(a,b);
	else if(n==0) pok=AlocirajKontinualno(a,b);
	else return 0;
	
	std::cout<<"Dinamicki alocirana matrica: "<<std::endl;
		for(int k=0; k<b; k++) {
			for(int i=0; i<p; i++) {
				for(int j=0; j<a[i]; j++) std::cout<<std::left<<std::setw(3)<<pok[i][j];
				std::cout<<std::endl;
			}
		}
if(n==1) for(int i=0; i<p*b; i++) delete[] pok[i];
if(n==0) delete[] pok[0];
		delete[] pok;


	} catch(const char* recenica) {
		std::cout<<"Izuzetak: "<< recenica;
	} catch(std::domain_error izuzetak) {
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}

	catch(std::bad_alloc) {};
	return 0;
}