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
#include <stdexcept>
#include <algorithm>
#include <iomanip>

template <typename Tip1>
bool TestPerioda(const std::vector<Tip1> a, int p){
	if (p>=a.size()) return false;
	for(int i=0;i<a.size()-p;i++){
		if(a.at(i)!=a.at(i+p)) return false;
	}
	return true && p!=0;
}

template <typename Tip2>
int OdrediPeriod(const std::vector<Tip2> a){
	for(int i=1;i<=a.size();i++){
		if(TestPerioda(a,i))return i;
	}
	return 0;
}

template <typename Tip>
int **AlocirajFragmentirano(const std::vector<Tip> &a, int &koliko_puta){
	if(a.size()==0) throw "Prazan vektor!";
	for(int i=0;i<a.size();i++) if(a.at(i)<=0) throw std::domain_error("Neispravan vektor!");
	
	int period=OdrediPeriod(a);
	if(period==0) koliko_puta=2;
	else if(a.size()%period!=0) koliko_puta=a.size()/period + 1;
	else koliko_puta=a.size()/period;

	int velicina(0);
	if(period==0) {velicina=a.size()*2; period=a.size();}
	else velicina=period*koliko_puta;
	Tip najveci=a.at(0);
	for(int i=0;i<a.size();i++) if(a.at(i)>najveci) najveci=a.at(i);
	

	try{
		int **povratna=new int *[velicina]{nullptr};
		int koji=0;
		for(int i=0;i<velicina;i++){
			try{
				
				povratna[i]=new int[a.at(koji)];
				for(int j=0;j<a.at(koji)-1;j++) povratna[i][j]=int(najveci)-a.at(koji)+j+1;
				povratna[i][a.at(koji)-1]=int(najveci);
				koji++;
				if(koji==period) koji=0;
				
			}
			catch(std::bad_alloc){
				for(int i=0;i<velicina;i++) delete [] povratna[i];
				delete [] povratna;
				throw;
			}
		}
		return povratna;
	}
	catch(std::bad_alloc){
		throw;
	}
}
template <typename Tip1>
int **AlocirajKontinualno(const std::vector<Tip1> &a, int &koliko_puta){
	if(a.size()==0) throw "Prazan vektor!";
	for(int i=0;i<a.size();i++) if(a.at(i)<=0) throw std::domain_error("Neispravan vektor!");
	
	int period=OdrediPeriod(a);
	if(period==0) koliko_puta=2;
	else if(a.size()%period!=0) koliko_puta=a.size()/period+1;
	else koliko_puta=a.size()/period;
	
	int velicina(0);
	if(period==0) {velicina=a.size()*2; period=a.size();}
	else velicina=period*koliko_puta;
	Tip1 najveci=a.at(0);
	for(int i=0;i<a.size();i++) if(a.at(i)>najveci) najveci=a.at(i);
	Tip1 suma(0);
	for(int i=0;i<period;i++) suma+=a.at(i);
	int prostor=int(suma)*koliko_puta;
	
	try{
		int **povratna=new int *[velicina]{nullptr};
		int koji=0;
		try{
			povratna[0]=new int[prostor];
			for(int i=1;i<velicina;i++){
				povratna[i]=povratna[i-1]+a.at(koji);
				koji++;
				if(koji==period)koji=0;
			}
			koji=0;
			for(int i=0; i<velicina; i++){
				for(int j=0;j<a.at(koji);j++) povratna[i][j]=a.at(koji)-j;
				
				koji++;
				if(koji==period) koji=0;
			}
			return povratna;
		}
		catch(std::bad_alloc){
			delete [] povratna;
			throw;
		}
	}
	catch(std::bad_alloc){
		throw;
	}

}
int main ()
{
	
	/*std::vector<int> a{1,2,1,3};
	int n=2;
	AlocirajKontinualno(a,n);*/
	
	std::cout<<"Unesite broj elemenata vektora: ";
	int n(0);
	std::cin>>n;
	try{
	std::vector<int> b(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++) std::cin>>b.at(i);
	std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int f(0);
	std::cin>>f;
	if(f==1){
		try{
			int koliko_puta(0);
			int **pok=AlocirajFragmentirano(b, koliko_puta);
			
			int velicina=OdrediPeriod(b);
			if (velicina==0) velicina=b.size()*koliko_puta;
			else velicina*=koliko_puta;
			
			int period=OdrediPeriod(b);
			if(period==0) period=b.size();
			//std::cout<<pok[2][0]<<" "<<pok[2][1]<<" "<<pok[2][2];
			int koji=0;
			std::cout<<"Dinamicki alocirana matrica:";
			std::cout<<std::endl;
			for(int i=0; i<velicina; i++){
				for(int j=0;j<b.at(koji);j++){
					std::cout<<std::setw(3)<<std::left<<pok[i][j];
					
				}
				koji++;
				if(koji==period) koji=0;
				std::cout<<std::endl;
			}
			for(int i=0;i<velicina;i++) delete [] pok[i];
			delete[] pok;
			
		}
		catch(const char nesto[]){
			std::cout<<"Izuzetak: "<<nesto;
		}
		catch(std::domain_error e){
			std::cout<<"Izuzetak: "<<e.what();
		}
		catch(std::bad_alloc){
			
		}
	}
	else if(f==0){
		try{
		int koliko_puta(0);
		int **pok=AlocirajKontinualno(b, koliko_puta);
		int velicina=OdrediPeriod(b);
		if(velicina==0) velicina=b.size()*koliko_puta;
		else velicina*=koliko_puta;
		int period=OdrediPeriod(b);
		if(period==0) period=b.size();
		int koji=0;
		std::cout<<"Dinamicki alocirana matrica:";
		std::cout<<std::endl;
		for(int i=0;i<velicina;i++){
			for(int j=0;j<b.at(koji);j++){
				std::cout<<std::setw(3)<<std::left<<pok[i][j];
			}
			koji++;
			if(koji==period) koji=0;
			std::cout<<std::endl;
		}
		delete[] pok[0];
		delete[] pok;
	}
	catch(const char nesto[]){
		std::cout<<"Izuzetak: "<<nesto;
	}
	catch(std::domain_error e){
		std::cout<<"Izuzetak: "<<e.what();
	}
	catch(std::bad_alloc){
		
	}
	}
	}
	catch(std::bad_alloc){
		
	}
	return 0;
}