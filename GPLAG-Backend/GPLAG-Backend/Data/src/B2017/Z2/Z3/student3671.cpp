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
#include <iomanip>
#include <type_traits>
using namespace std;

template<typename Tip>
int TestPerioda(vector<Tip>v,int p)
{
	if(p<1 || v.size()<1 || p>=v.size())
		return 0;
	for(int i=0; i<v.size()-p; i++) {
		if(v[i]!=v[i+p])
			return false;
	}
	return true;
}

template<typename Tip>
int OdrediOsnovniPeriod(vector<Tip>h)
{
	for(int i=0; i<h.size(); i++) {
		if(TestPerioda(h,i))
			return i;
	}
	return 0;
}

template<typename T>
void Parametri(const vector<T>&v,int &koliko_puta,int &period)
{
	period=OdrediOsnovniPeriod(v);
	if(period==0) {
		koliko_puta=2;
		period=v.size();
	}
	koliko_puta=v.size()/period;
	if(v.size()%koliko_puta!=0 || koliko_puta==1) {
		if(koliko_puta==1) {
			koliko_puta=2;
		} else koliko_puta++;
	}
}

//template<typename Tip>
//int** AlocirajFragmentirano(const vector<int>&v,int &koliko_puta)
/*typename remove_const<typename remove_reference<decltype(v[0])>::type>::type** */
//{
/* typedef typename remove_const<typename remove_reference<decltype(v[0])>::type>::type tip; */
/*	if(v.size()==0) {
		throw range_error("Prazan vektor!");
	}
	for(int i=0; i<v.size(); i++) {
		if(v[i]<0) throw domain_error("Neispravan vektor!");
	}
	int period;
	Parametri(v,koliko_puta,period);
	try {
		int **p=new int*[period*koliko_puta];
		for(int i=0; i<v.size(); i++) {
			p[i]=nullptr;
		}
		try {
			for(int i=0; i<period*koliko_puta; i++) {
				p[i]=new int[v[i%v.size()]];
			}
			int max=*max_element(v.begin(),v.end());
			for(int i=0; i<period*koliko_puta; i++) {
				int l=max-v[i%period]+1;
				for(int j=0; j<v[i%period]; j++) {
					p[i][j]=l++;
				}
			}
			return p;
		} catch(bad_alloc) {
			for(int i=0; i<(period*koliko_puta); i++) delete[] p[i];
			delete[] p;
			throw;
		}
	} catch(...) {
		throw;
	}

	return 0;
}*/


int **AlocirajFragmentirano(const vector<int>&v,int &koliko_puta)
{
	int period=OdrediOsnovniPeriod(v);
	cout<<"period: "<<period<<endl;
	if(period==0) {
		period=v.size();
		cout<<"period: "<<period<<endl;
		int i=0;
		while(i<6) {
			cout<<"i%period: "<<i%period<<endl;
			i++;
		}
		koliko_puta=2;
		try {
			int **p=new int*[period*koliko_puta];
			for(int i=0; i<v.size(); i++) {
				p[i]=nullptr;
			}
			try {
				for(int i=0; i<period*koliko_puta; i++) {
					p[i]=new int[int(v[i%period])];
				}
				int max=*max_element(v.begin(),v.end());
				for(int i=0; i<period*koliko_puta; i++) {
					int l=max-v[i%period]+1;
					for(int j=0; j<v[i%period]; j++) {
						p[i][j]=l++;
					}
				}
				return p;
			} catch(bad_alloc) {
				for(int i=0; i<(period*koliko_puta); i++) delete[] p[i];
				delete[] p;
				throw;
			}
		} catch(...) {
			throw;
		}
	}
	return 0;
}


template<typename t>
int BrElemenata(const vector<t>&v,int koliko_puta,int period)
{
	int n(0);
	for(int i=0; i<koliko_puta*period; i++) {
		n+=v[i%period];
	}
	return n;
}

//template<typename Tip>
int** AlocirajKontinualno(const vector<int>&v,int &koliko_puta)
/*typename remove_const<typename remove_reference<decltype(v[0])>::type>::type** */
{
	/* typedef typename remove_const<typename remove_reference<decltype(v[0])>::type>::type tip1; */
	if(v.size()==0) {
		throw range_error("Prazan vektor!");
	}
	for(int i=0; i<v.size(); i++) {
		if(v[i]<0) throw domain_error("Neispravan vektor!");
	}
	int period;
	Parametri(v,koliko_puta,period);
	try {
		int **p=new int*[period*koliko_puta];
		try {
			p[0]=new int[BrElemenata(v,koliko_puta,period)];
			for(int i=0; i<period*koliko_puta; i++) {
				p[i+1]=p[i]+v[i%period];
			}
			int l=0;
			for(int i=0; i<period*koliko_puta; i++) {
				l=v[i%period];
				for(int j=0; j<v[i%period]; j++) {
					p[i][j]=l--;
				}
			}
			return p;
		} catch(bad_alloc) {
			delete[] p;
			throw;
		}
	} catch(...) {
		throw;
	}
	return 0;
}

int main ()
{
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	vector<int>v;
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		int element;
		cin>>element;
		v.push_back(element);
	}
	int odabir;
	cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	cin>>odabir;
	int period=OdrediOsnovniPeriod(v);
	try {
		if(odabir==1) {
			int k=0;
			//Parametri(v,k,period);
			int **p=AlocirajFragmentirano(v,k);
			cout<<"Dinamicki alocirana matrica: "<<endl;
			for(int i=0; i<period*k; i++) {
				for(int j=0; j<v[i%period]; j++) {
					cout<<left<<setw(3)<<p[i][j];
				}
				cout<<endl;
			}
			for(int i=0; i<period*k; i++) delete[] p[i];
			delete[] p;
		}
		if(odabir==0) {
			int k=0;
			int **p=AlocirajKontinualno(v,k);
			cout<<"Dinamicki alocirana matrica: "<<endl;
			for(int i=0; i<period*k; i++) {
				for(int j=0; j<v[i%period]; j++) {
					cout<<left<<setw(3)<<p[i][j];
				}
				cout<<endl;
			}
			delete[] p[0];
			delete[] p;
		}
	} catch(domain_error x) {
		cout<<"Izuzetak: "<<x.what();
	} catch(range_error h) {
		cout<<"Izuzetak: "<<h.what();
	}
	return 0;
}
