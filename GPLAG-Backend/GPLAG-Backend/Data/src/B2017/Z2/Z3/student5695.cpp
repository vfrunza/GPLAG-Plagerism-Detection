#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using namespace std;

template <typename tip_int>
bool TestPerioda(vector<tip_int> vektor, int p) {
	if(vektor.size()==0 || vektor.size()<=p || p==0) return false;
	for(int i=0;i<vektor.size();i++) {
		if(i+p>=vektor.size()) break;
 		if(vektor[i]!=vektor[i+p]) return false; 
 	}
 	return true;
}

template <typename tip_int>
int OdrediOsnovniPeriod(vector<tip_int> vektor) {
	for(int i=2;i<vektor.size();i++) {
		if(TestPerioda(vektor,i)) return i;
	}
	return 0;
}

template <typename tip_int>
tip_int** AlocirajFragmentirano(const vector<tip_int> &v, int &koliko_puta) {
	if(v.size()==0) throw length_error("Prazan vektor!");
	for(int i=0;i<v.size();i++) {
		if(v.at(i)<=0) throw domain_error("Neispravan vektor!");
	}
	int osnovni(OdrediOsnovniPeriod(v));
	int duzina=v.size();
	tip_int **f;
	try {
	    if(osnovni==0) {
	        duzina=v.size()*2;
	        osnovni=v.size();
	        koliko_puta=2;
	    }
	    else {
	    	koliko_puta=v.size()/osnovni;
		    if(koliko_puta*osnovni!=v.size()) {
		    	duzina=(koliko_puta+1)*osnovni;
		    	koliko_puta+=1;
		    }
		    else if(v.size()%osnovni!=0) {
		    	koliko_puta=v.size()/osnovni;
		    	duzina=v.size();
		    }
	    }
	    // alociranje matrice
	    f=new tip_int*[duzina];
	    int el(0);
	    for(int i=0;i<duzina;i++) {
	    	if(el==osnovni) el=0;
	    	f[i]=new tip_int[v.at(el)];
	    	el++;
	    }
	    tip_int max(v.at(0));
	    for(int i=1;i<osnovni;i++) {
	    	if(v.at(i)>max) max=v.at(i);
	    }
	    // popunjavanje alocirane matrice
	    el=0;
	    for(int i=0;i<duzina;i++) {
	    	auto pom_max=max;
	    	for(int j=v.at(el)-1;j>=0;j--) {
	    		f[i][j]=pom_max;
	    		pom_max--;
	    	}
	    	el++;
	    	if(el==osnovni) el=0;
	    }
	    return f;
    }
    catch(bad_alloc) {
    	for(int i=0;i<osnovni*koliko_puta;i++) delete [] f[i];
		delete [] f;
		f=nullptr;
		throw;
    }
    catch(...) {
    	throw;
    } 
}

template <typename tip_int>
int** AlocirajKontinualno(vector<tip_int> &v, int &koliko_puta) {
	if(v.size()==0) throw length_error("Prazan vektor!");
	for(int i=0;i<v.size();i++) {
		if(v.at(i)<=0) throw domain_error("Neispravan vektor!");
	}
	int osnovni(OdrediOsnovniPeriod(v));
	int duzina=v.size();
	tip_int **f=nullptr;
	try {
	    if(osnovni==0) {
	        duzina=v.size()*2;
	        osnovni=v.size();
	        koliko_puta=2;
	    }
	    else {
	    	koliko_puta=v.size()/osnovni;
		    if(koliko_puta*osnovni!=v.size()) {
		    	duzina=(koliko_puta+1)*osnovni;
		    	koliko_puta+=1;
		    }
		    else if(v.size()%osnovni!=0) {
		    	koliko_puta=v.size()/osnovni;
		    	duzina=v.size();
		    }
	    }
	    int suma(0);
	    for(int i=0;i<osnovni;i++) suma+=v.at(i);
	    // alociranje matrice
	    int **f=new int*[duzina];
	    f[0]=new int[koliko_puta*suma];
	    int el(0);
	    for(int i=1;i<duzina;i++) {
	    	f[i]=f[i-1]+v.at(el);
	    	el++;
	    	if(el==osnovni) el=0;
	    }
	    // popunjavanje matrice
	    el=0;
	    for(int i=0;i<duzina;i++) {
	    	int min(1);
	    	for(int j=v.at(el)-1;j>=0;j--) {
	    		f[i][j]=min;
	    		min++;
	    	}
	    	el++;
	    	if(el==osnovni) el=0;
	    }
	    return f;
	}
	catch(bad_alloc) {
		delete [] f[0];
		delete f;
		f=nullptr;
		throw;
	}
	catch(...) {
		throw;
	}
}

int main() {
	int broj_el;
	cout << "Unesite broj elemenata vektora: ";
	cin >> broj_el;
	cout << "Unesite elemente vektora: ";
	vector<int> vektor;
	for(int i=0;i<broj_el;i++) {
		int pom;
		cin >> pom;
		vektor.push_back(pom);
	}
	cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int al;
	cin >> al;
	int koliko_puta(0);
	int **pok;
	try {
		if(al==1) pok=AlocirajFragmentirano(vektor,koliko_puta);
		else if(al==0) pok=AlocirajKontinualno(vektor,koliko_puta);
	}
	catch (bad_alloc) {
		cout << "Losa alokacija!";
		return 0;
	}
	catch (domain_error izuzetak) {
		cout << "Izuzetak: " << izuzetak.what();
		return 0;
	}
	catch (length_error izuzetak) {
		cout << "Izuzetak: " << izuzetak.what();
		return 0;
	}
	int osnovni(OdrediOsnovniPeriod(vektor));
	if(osnovni==0) osnovni=vektor.size();
	cout << "Dinamicki alocirana matrica: " << endl;
	int el(0);
	for(int i=0;i<osnovni*koliko_puta;i++) {
		for(int j=0;j<vektor.at(el);j++) cout << setw(3) << left << pok[i][j];
		el++;
		if(el==osnovni) el=0;
		cout<<endl;
	}
	if(al==1) {
		for(int i=0;i<osnovni*koliko_puta;i++) delete [] pok[i];
			delete [] pok;
		}
	else if(al==0) {
		delete [] pok[0];
		delete  [] pok;
	}
	return 0;
}