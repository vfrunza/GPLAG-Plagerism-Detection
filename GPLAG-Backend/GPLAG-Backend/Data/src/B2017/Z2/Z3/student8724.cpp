#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <iomanip>

using namespace std;


template <typename Tip> 
bool TestPerioda(vector<Tip>v, int p){
   
    if(v.empty()) return false;
    if(v.size()<=p || p==0) return false;
        for(int i=0; i<v.size(); i++){
            if(i+p==v.size()) break;
            if(v[i]!=v[i+p]) return false;
        }
        return true;
}

template<typename Tip>
int OdrediOsnovniPeriod(vector<Tip>v){
    for(int i=1;i<=v.size()-1;i++){
        if(TestPerioda(v,i)) return i;
    }
    return 0;
}

template<typename Tip>
void PostavljanjeParametara(int &period, int &koliko_puta, vector<Tip> vektor){
	if(period==0){
		period = vektor.size();
		koliko_puta = 2;
	}
	else if(vektor.size() % period == 0) koliko_puta = vektor.size()/period;
	else  koliko_puta = int(vektor.size() / period + 1);
}

int  **UnosElemenata(int **pok, int koliko_puta, int period, vector<int> vektor, bool br){
	int k=0;
	for(int i=0; i<koliko_puta*period; i++){
		int brojac=0;
		if(br) brojac=1;
		for(int j=vektor.at(k)-1; j>=0; j--){
			if(br) pok[i][j]=brojac;
			else pok[i][j]=period-brojac;
			brojac++;
		}
		k++;
		if(k==period) k=0;
	}
	return pok;
}

template<typename Tip>
void SmislenVektor(vector<Tip> vektor){
	for(int i = 0; i < vektor.size(); i++){
		if(vektor.at(i) <= 0) throw domain_error("Neispravan vektor!");
	}
	if(vektor.size() == 0) throw ("Prazan vektor! ");
}

template<typename Tip>
int **AlocirajFragmentirano(const vector<Tip> &vektor, int &koliko_puta){
	SmislenVektor(vektor);
	
	int period=OdrediOsnovniPeriod(vektor);
	PostavljanjeParametara(period, koliko_puta, vektor);
	int **pok(new int *[koliko_puta*period]);
	int j=0;
	for(int i=0; i<koliko_puta*period; i++){
			pok[i]=new int [vektor.at(j)+1];
			j++;
			if(j==period) j=0;
	}
    pok=UnosElemenata(pok, koliko_puta, period, vektor, false);
	return pok;
	
}

template<typename Tip>
int **AlocirajKontinualno(const vector<Tip> &vektor, int &koliko_puta){
	SmislenVektor(vektor);
	int period=OdrediOsnovniPeriod(vektor);
	PostavljanjeParametara(period, koliko_puta, vektor);
	int **pok(new int *[koliko_puta * period]);
	int k=0;
	int suma=0;
	for(int i=0; i<period; i++){
		suma+=vektor.at(i);
	}
	suma*=koliko_puta;
	pok[0]=new int[suma];
	for(int i=1; i<koliko_puta*period; i++){
		pok[i]=pok[i-1]+vektor.at(k);
		k++;
		if(k==period) k=0;
	}
	pok=UnosElemenata(pok, koliko_puta, period, vektor, true);
	return pok;
}

template<typename Tip>
void Ispis(int koliko_puta, int period, int **pok, vector<Tip> vektor){
	int k=0;
	for(int i=0; i<period*koliko_puta; i++){
		for(int j=0; j<vektor.at(k); j++){
			cout<<setw(3)<<left<<pok[i][j];
			
		}
		k++; 
		if(k == period) k = 0;
		cout<<endl;
	}
}

int main (){
	try{
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	vector<int> vektor(n);
	for(int i=0; i<n; i++){
		cin>>vektor.at(i);
	}
	int temp;
	cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	cin>>temp;
	int koliko_puta;
	int **pok;
	if(temp == 1) pok = AlocirajFragmentirano(vektor, koliko_puta);
	else pok = AlocirajKontinualno(vektor, koliko_puta);
	cout<<"Dinamicki alocirana matrica: \n";
	int period=OdrediOsnovniPeriod(vektor);
	if(period==0){
		period=vektor.size();
		koliko_puta=2;
	}
	Ispis(koliko_puta, period, pok, vektor);
	
	if(temp == 1){
	for(int i = 0; i < koliko_puta*period; i++){
		delete[] pok[i];
	}
	delete[] pok;
	}
	else{
		delete[] pok[0]; delete[] pok;
	}
	
	}
	catch(domain_error izuzetak){
		cout<<"Izuzetak: "<<izuzetak.what();
	}
	catch(bad_alloc){
		cout<<"Izuzetak: Problemi sa memorijom! ";
	}
	catch(const char poruka[]){
		cout<<"Izuzetak: "<<poruka;
	}

	return 0;
}



