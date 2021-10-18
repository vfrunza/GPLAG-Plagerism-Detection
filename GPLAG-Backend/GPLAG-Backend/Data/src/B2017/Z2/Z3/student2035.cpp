#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
template<typename tip1>
bool TestPerioda(const std::vector<tip1> &v, int broj) {
	int n; 
	if(v.size()==broj || broj<=1) return false; 
	for(int i=0; i<v.size(); i++)
	{
		n=i+broj; 
		if(n<v.size()) {
			if(v[i]!=v[n]) return false; 
		}
	}
	
	return true;
}

template<typename tip2>
bool PeriodicanSNekimBrojem(const std::vector<tip2> &v, int &period) {
	period=0; 
	for(int i=1; i<v.size(); i++)
	if(TestPerioda(v, i)) {period=i; return true;}
	return false; 
}

template <typename tipu_a1> 
void PeriodicnoProduziAkoImaPotrebe(const std::vector<tipu_a1> &v, int &koliko_puta, int &period) {
	//ako v.size==0 baci prazan vektro
	period=0; 
	if(PeriodicanSNekimBrojem(v, period)) {
//		std::cout << "Period je " << period;
		int a(v.size()/period);
		int koliko_nedostaje;
		if(v.size()%period!=0) koliko_nedostaje=(a+1)*period-v.size(); 
		else koliko_nedostaje=0;
//		while(koliko_nedostaje) {
//			v.push_back(v[v.size()-period]);
//			koliko_nedostaje--;
//		}
		if(koliko_nedostaje==0)
		koliko_puta=a;
		else koliko_puta=a+1;
	}
	
	else {
	//	int koliko_nedostaje(v.size()); 
	//	for(int i=0; i<koliko_nedostaje; i++)
	//	v.push_back(v[i]);
//	std::cout << "Ipak nije periodican pa je period" << v.size();
		koliko_puta=2; 
		period=v.size();
	}  }
	
	
template<typename tip3>
int **AlocirajFragmentirano(const std::vector<tip3> &v,int &koliko_puta) {
	if(v.size()==0) throw std::domain_error("Prazan vektor!");
	int period(0);
	PeriodicnoProduziAkoImaPotrebe(v,koliko_puta, period);
	tip3 najveci_element(v[0]); 
	for(int i=0; i<period; i++)
	{
		if(v[i]<=0) throw std::domain_error("Neispravan vektor!");
		if(v[i]>najveci_element) najveci_element=v[i];
	}
	int **rezultat(nullptr); 
	tip3 kopija_najveceg_elementa(najveci_element);
	try {
		rezultat=new int*[period*koliko_puta]; 
		for(int i=0; i<period*koliko_puta; i++)
		rezultat[i]=nullptr;
	//	std::cout << "Period je: " << period << std::endl << " A koliko puta je : "<< koliko_puta << std::endl;
		try {
			for(int k=0; k<koliko_puta; k++) {
		for(int i=0; i<period; i++) {
	//	std::cout << "Pokusavam alocirati rezultat od [" <<i+k*period << "] a u njega stavljam new int[" <<v[i] << "] " << std::endl; 
			rezultat[i+k*period]=new int[v[i]];
			for(long long int j=v[i]-1; j>=0; j--) {
	//			std::cout << "evo ti i info sta upisem u njega " << kopija_najveceg_elementa;
			rezultat[i+k*period][j]=kopija_najveceg_elementa; 
				kopija_najveceg_elementa--;
			} //petlja oznacena sa * sad uzmi ono s numeric limits znas vec kako sta
			kopija_najveceg_elementa=najveci_element;
			
		} }
		return rezultat; }
		catch(std::bad_alloc) {
			for(int k=0; k<period*koliko_puta; k++)
			delete[] rezultat[k];
			delete[] rezultat;
			rezultat=nullptr; 
			throw; //bac inesto sad nebitno sta
		}
		
	
	}
	
	catch(std::bad_alloc) {
		delete[] rezultat;
		throw; //nesto baci
	}
}

template <typename tip4>
int **AlocirajKontinualno(const std::vector<tip4> &v, int &koliko_puta) {
	//baci izuzetak ako je prazan vektor poslat
	if(v.size()==0) throw std::domain_error("Prazan vektor!");
	int period;
	PeriodicnoProduziAkoImaPotrebe(v, koliko_puta, period); 
	int broj_elemenata(0);
//	std::cout << "Period mi je " << period << " ";
	for(int i=0; i<period; i++) {
		if(v[i]<=0) throw std::domain_error("Neispravan vektor!"); 
		broj_elemenata=broj_elemenata+v[i];
	}
	broj_elemenata=broj_elemenata*koliko_puta;
//	std::cout << "Broj elemenata sam izracunao da je " << broj_elemenata;
	int **rezultat(nullptr); 
	try {
		rezultat=new int*[koliko_puta*period];
		rezultat[0]=nullptr;
		try{
			rezultat[0]=new int[broj_elemenata];
			//for(int j=0; j<broj_elemenata; j++) 
			//rezultat[0][j]=0;
			for(int k=0; k<koliko_puta; k++)
			for(int i=0; i<period; i++) {			//vidi ti ove granice asja DOBRO TI OVO POGLEDAJ ISPOD OVU LINIJUUU
			rezultat[i+k*period]=rezultat[0]+(v[i])*(i);
		//	rezultat[i+k*(period-1)]=rezultat[i-1+k*(period-1)]+v[i-1]; 
		//	std::cout << "U rezultat[" << i+k*period << " v[" << i << "] * " << i+k*period << " a rez tog mnozrnja je" << v[i]*(i) << std::endl;  
	
			}
			for(int k=0; k<koliko_puta; k++)
			for(int i=0; i<period; i++)
			for(int j=0; j<v[i]; j++) {
			rezultat[i+k*period][j]=v[i]-j; 
		//		std::cout << "U rezultat[" << i+k*period << "][" << j << "] upisujem " << v[i] - j << std::endl;
			}// i ovdje si ti nesto svoje 
			return rezultat;
		}
		
		catch(std::bad_alloc) {
			delete[] rezultat[0];
			delete[] rezultat; 
			rezultat=nullptr; 
			throw; //baci nesto
		} }
		catch(std::bad_alloc) {
			delete[] rezultat; 
			throw; //nesto
		}
		
	
	}


int main ()
{ try{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n; 
	std::vector<int> vektor(n);
	std::cout << "Unesite elemente vektora: "; 
	long long int suma(0);
	for(int i=0; i<n; i++) {
	std::cin >> vektor[i]; 
		suma=suma+vektor[i];
	}
	std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: "; 
	int f(5); 
	std::cin >> f; //vidi sta ako unese nesto random; 
	int **nesto; 
	int period(0);
	int koliko_puta;
	PeriodicnoProduziAkoImaPotrebe(vektor,koliko_puta ,period);
	if(f==0) nesto=AlocirajKontinualno(vektor, koliko_puta); 
	else nesto=AlocirajFragmentirano(vektor, koliko_puta);
	std::cout << "Dinamicki alocirana matrica: " << std::endl; 
	for(int k=0; k<koliko_puta; k++)
	for(int i=0; i<period; i++) {
	for(int j=0; j<vektor[i]; j++) {
	std::cout << std::left<< std::setw(3) << nesto[i+k*period][j]; 
}
	std::cout << std::endl; } 

	
if(f==0) {
	delete[] nesto[0];
	delete[] nesto; 
}

else {for(int i=0; i<koliko_puta*period; i++)
	delete[] nesto[i];
	delete[] nesto; }
	return 0;
	
}

	catch(std::domain_error d) {
		std::cout << "Izuzetak: " << d.what();
	}
	catch(...) { throw;}
}