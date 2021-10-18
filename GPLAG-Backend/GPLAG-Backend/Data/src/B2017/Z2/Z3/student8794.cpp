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
#include <type_traits>
template<typename NekiTip>
bool TestPerioda (std::vector<NekiTip> brojevi, int p){
	if (p==0 || p==brojevi.size() || brojevi.size()==1) return false;
	
	for (int i=0; i<=p; i++){
		if ((i+p)==brojevi.size()) break;
		if (brojevi[i]!=brojevi[i+p]) return false;
		
	}
	return true;
}
/*vraca osnovni period*/
template<typename NekiTip>
int OdrediOsnovniPeriod (std::vector<NekiTip> brojevi){
	for (int i=0; i<brojevi.size(); i++){
		if (TestPerioda(brojevi, i)){
			
		}
		return i;
	}
	return 0;
}

template <typename NekiTip>

auto AlocirajFragmentirano (const std::vector<NekiTip> &vek, int &koliko_puta)->typename std::remove_reference<decltype(vek)>::type**{
try{
		if (vek.size()==0) throw std::range_error ("Prazan vektor!");	
			
			for (int i=0; i<vek.size(); i++){
				if (vek.at(i)<=0){ 
					//fali delete
					throw std::domain_error ("Neispravan vektor!");
			}
			
		}
}

catch(std::domain_error){
	//obrisati alocirano...
	throw;
}
catch(...){
	throw;
}
		//return ;
}

template <typename NekiTip>
auto AlocirajKontinualno (const std::vector<NekiTip> &vek, int &koliko_puta)->typename std::remove_reference<decltype(vek)>::type**{
try{
	if (vek.size()==0) throw std::range_error ("Prazan vektor!");
	for (int i=0; i<vek.size(); i++){
		if (vek.at(i)<=0){
			throw std::domain_error ("Neispravan vektor!");
		}
	}
}

catch (std::domain_error){
	//obrisati alocirano
	throw;
}
catch (...){
	throw;
}

}


int main ()
{
	int brel;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>brel;
	std::cin.ignore(1000, '\n');
	std::cin.clear();
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> vektor;
	int element;
	for (int i=0; i<brel; i++){
		std::cin>>element;
		
		vektor.push_back(element);
	}
	std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int opcija;
	do{
	std::cin>>opcija;
	if (opcija!=1 && opcija!=0) std::cout<<"Neispravna opcija, unesite novu";
	}while (opcija!=1 && opcija!=0);
	
	int kolikoputa;
	if (opcija==1){
	try{
		auto m1=AlocirajFragmentirano(vektor, kolikoputa);
		std::cout<<"Dinamicki alocirana matrica: ";
		
	/*	for (int i=0; i<brel; i++){
			for (int j=0; j<brel; j++)
				std::cout<<m1[i][j];
				std::cout<<std::endl;
		}
		*/
	}
	catch(std::range_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	catch (std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
}

if (opcija==0){
	try{
		auto m2=AlocirajKontinualno(vektor, kolikoputa);
		std::cout<<"Dinamicki alocirana matrica: ";
		
	}
	catch (std::range_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	catch (std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
}

	return 0;
}