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
#include <iomanip>
using namespace std;

int p(vector<int>v){
	
	for(int i=2;i<v.size();i++){
		for(int j=0;j<v.size();j++){
			
			if(v.at(j)==v.at(j+i)){
				if(i+j==v.size()-1) return i;
			}else break;
			
		}
	}
	return -1;
}

int **AlocirajFragmentirano(vector<int> &v, int &koliko_puta){
	int period=p(v);
	if(v.size()%period==0)	koliko_puta=v.size()/period;
	else koliko_puta=int(v.size()/period)+1;
	int **pok=nullptr;
	try{
	pok=new int *[v.size()];
	int korisna_varijabla=koliko_puta*period;
	int mozda=0;
	for(int i=0;i<korisna_varijabla;i++){//alocirano
		if(mozda==period)mozda=0;
		pok[i]=new int[v.at(mozda)];
		mozda++;
	}
	mozda=0;
	for(int i=0;i<korisna_varijabla;i++){
		if(mozda==period)mozda=0;
		int k=0;
		for(int j=v.at(mozda)-1;j>=0;j--){
		pok[i][j]=period-k;
		k++;
		} 
		mozda++;
	}
	
	return pok;
	}catch(...){
			for(int i=0;i<period*koliko_puta;i++){
		delete[] pok[i];
	}
	delete[] pok;
		throw;
	}
	
}

int **AlocirajKontinualno(vector<int> &v, int &koliko_puta){
	int **pok=nullptr;
	try{
	int period=p(v);
	if(v.size()%period==0)	koliko_puta=v.size()/period;
	else koliko_puta=int(v.size()/period)+1;
	pok=(new int *[v.size()]);
	int korisna_varijabla=koliko_puta*period;
	
	pok[0]=new int[korisna_varijabla];
	
	int mozda=0;
	for(int i=0;i<korisna_varijabla;i++){
		if(mozda==period)mozda=0;
		int k=0;
		for(int j=v.at(mozda)-1;j>=0;j--){
		pok[i][j]=period-k;
		k++;
		} 
		mozda++;
	}
	
	return pok;
}catch(...){
	delete[] pok[0];
	
	delete[] pok;
		throw;
	}
}





int main (){
	int koliko_puta=0;
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	vector<int> v;
	int element;
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++){
		cin>>element;
		v.push_back(element);
	}
	cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int izbor;
	cin>>izbor;
	cout<<"Dinamicki alocirana matrica: "<<endl;
	if(izbor){
			int **pok=AlocirajFragmentirano(v,koliko_puta);
			int period=p(v);
			int molim_te=0;
			
			for(int i=0; i<period*koliko_puta; i++){
			if(molim_te==period)molim_te=0;
			for(int j=0; j<v.at(molim_te); j++){
			cout<<setw(3)<<pok[i][j];
			
		}
		cout<<endl;
		molim_te++;
	}
	for(int i=0;i<period*koliko_puta;i++){
		delete[] pok[i];
	}
	delete[] pok;
	}else{
		int **pok=AlocirajKontinualno(v,koliko_puta);
			int period=p(v);
			int molim_te=0;
			
			for(int i=0; i<period*koliko_puta; i++){
			if(molim_te==period)molim_te=0;
			for(int j=0; j<v.at(molim_te); j++){
			cout<<setw(3)<<pok[i][j];
			
		}
		cout<<endl;
		molim_te++;
	}
	delete[] pok[0];
	
	delete[] pok;
	}

	return 0;
}