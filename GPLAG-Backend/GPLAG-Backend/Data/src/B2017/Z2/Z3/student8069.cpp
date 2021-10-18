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
#include <new>
#include <stdexcept>
#include <vector>
#include <iomanip>

using std::cin;
using std::cout;

template <typename tip>
int Periodican(std::vector<tip> v) {
	int i(0), period(0);
	while(1) {
	for(int k=1; k<(v.size()/2); k++) {
		while(v[i]==v[i+k]) {
			i++;
			if(i==v.size()/2) {
				period=k;
				break;
			}
		}
	}
	if(period==0) break;
	}
	return period;
}

template <typename tip>
tip NadjiMaksimum(std::vector<tip> v) {
	tip max(v[0]);
	for(int i=1; i<v.size(); i++) 
		if(v[i]>max) max=v[i];
	return max;
}


template <typename tip>
auto AlocirajFragmentirano(const std::vector<tip> &v, int &koliko_puta)-> decltype(v[0]+v[0])** {
	if(v.size()==0) throw "Prazan vektor!";
	for(int i=0; i<v.size(); i++) if(v[i]<=0) throw std::domain_error("Neispravan vektor!");
	int period(Periodican(v));
	int k(0), broj_redova(0), duzina(0);
	
	decltype(v[0]+v[0])** p(nullptr);
	if(period!=0) {
	while((v.size()+k)%period!=0) k++;
	int nova_duzina(v.size()+k);
	koliko_puta=nova_duzina/period;
	
	//alokacija matrice
		decltype(v[0]+v[0])** p(nullptr);
		duzina=period*koliko_puta;
		try {
		
		p=new decltype(v[0]+v[0])*[duzina];
		for(int i=0; i<koliko_puta; i++) {
			for(int j=0; j<period; j++) p[j]=new decltype(v[0]+v[0])[int(v[j])];
		}
		broj_redova=period;
		}
		
		catch(std::bad_alloc) {
			if(p!=nullptr) for(int i=0; i<duzina; i++) delete[] p[i];
			delete[] p;
		}
	}
	
	else {
	koliko_puta=2;
	
	decltype(v[0]+v[0])** p(nullptr);
	duzina=v.size()*2;
	try {
	p=new decltype(v[0]+v[0])*[duzina];
	for(int i=0; i<koliko_puta; i++) {
		for(int j=0; j<v.size(); j++) p[j]=new decltype(v[0]+v[0])[int(v[j])];
	}
		
	broj_redova=v.size();	
	}
	
	catch(std::bad_alloc) {
		if(p!=nullptr) for(int i=0; i<duzina; i++) delete[] p[i];
		delete[] p;
	}
	}
	//popunjavanje matrice; 
	tip max(NadjiMaksimum(v));
	for(int i=0; i<koliko_puta; i++) {
		for(int j=0; j<broj_redova; j++) {
			int vel(v[j]);
			p[j][vel]=max;
			for(int k=vel-1; k>0; k--)
		//	if(k==vel) 	p[j][k]=max;
		//	else
			p[j][k]=p[j][k+1]-1;
		}
	}

	
	return p;
}

template <typename tip>
auto AlocirajKontinualno(const std::vector<tip> &v, int &koliko_puta)-> decltype(v[0]+v[0])** {
	if(v.size()==0) throw "Prazan vektor!";
	for(int i=0; i<v.size(); i++) {
		if(v[i]<=0) throw std::domain_error("Neispravan vektor!");
	}
	
	int period(Periodican(v));
	int k(0);
	decltype(v[0]+v[0])** p(nullptr);
	
	if(period!=0) {
		while ((v.size()+k)%period!=0) k++;
		int nova_duzina(v.size()+k);
		koliko_puta=nova_duzina/period;
		
	int duzina(0);
	for(int i=0; i<period; i++) duzina+=v[i];
	duzina*=koliko_puta;
		
			decltype (v[0]+v[0])** p(nullptr);
			try {
			p=new decltype(v[0]+v[0])* [koliko_puta*period];
			p[0]=new decltype(v[0]+v[0])[duzina];
			for(int j=1; j<period; j++) p[j]=p[j-1]+int(v[j]);
			}
			
			catch(std::bad_alloc) {
				if(p!=nullptr) delete[] p[0];
				delete[] p;
			}
		}
		
	else{
		koliko_puta=2;
		decltype(v[0]+v[0])** p(nullptr);
		int duzina(0);
		for(int i=0; i<v.size(); i++) duzina+=v[i];
		duzina*=2;
		try {
		p=new decltype(v[0]+v[0])*[2*v.size()];
		p[0]=new decltype(v[0]+v[0])[duzina];
		for(int j=1; j<v.size(); j++) p[j]=p[j-1]+int(v[j]);
		}
		catch(std::bad_alloc) {
			if(p!=nullptr) delete[] p[0];
			delete[] p;
		}
	}
	
	for(int i=0; i<koliko_puta; i++) {
		for(int j=0; j<v.size(); j++) {
		int vel(v[j]);
			for(int k=vel; k>0; k--) {
				if(k==vel) p[j][k]=1;
				else p[j][k]=p[j][k+1]+1;
			}
		}
	}
	return p;	
}




int main ()
{
	try {
	std::vector<double> v;
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	double broj;
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		cin>>broj;
		v.push_back(broj);
	}
	int f;
	cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	cin>>f;
	int br(0);
	double **p=nullptr;
	if(f==1) p=AlocirajFragmentirano(v,br);
	
	else auto p=AlocirajKontinualno(v,br);
	
	for(int i=0; i<br; i++) {
		for(int j=0; j<br; j++)
		cout<<std::setw(3)<<std::left<<p[i][j]<<" ";
		cout<<std::endl;
	}
	if(f==1) {
		for(int i=0; i<v.size(); i++) delete[] p[i];
		delete[] p;
	}
	else if(f==0){
		delete[] p[0];
		delete[] p;
	}
	}
	catch(std::domain_error izuzetak) {
		cout<<"Izuzetak: "<<izuzetak.what();
	}
	catch(const char poruka[]) {
		cout<<"Izuzetak: "<<poruka;
	}
	return 0;
}