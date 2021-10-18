/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <type_traits>
#include <vector>
#include <algorithm>
#include <stdexcept>

/*int dummy(int a, double b) { return 0; }

int suma(int n){
	return n == 0 ? 0 : n%10 + suma(n/10);
}

bool SumaCifaraKr(int a, double b){
	return suma(a) > suma((int)b);
}*/
int funkcija(int a, int b) {
	return -2*a+b;
}
bool Kriterij(int a, int b){
	int prosti1(0);
	int prosti2(0);
	int povratnaPrva(a);
	int povratnaDruga(b);
	int i(2);
	if(a>1){
	while(a!=1){
		if(a%i==0){
			prosti1++;
			a/=i;
		}
		else i++;
	}
	}
	else prosti1=0;
	
	i=2;
	if(b>1){
		while (b!=1){
			if(b%i==0){
				prosti2++;
				b/=i;
			}
			else i++;
		}
	}
	else prosti2=0;
	
	if(prosti1!=prosti2) return prosti1>prosti2;
	else return povratnaPrva>povratnaDruga;
}

template <typename Tip1, typename Tip2, typename Tip3>

void SortirajPodrucjeVrijednosti (Tip1 pocetakPrvog, 
								  Tip1 krajPrvog, 
								  Tip2 pocetakDrugog, 
								  Tip3 pocetakTreceg, 
								  typename std::remove_reference<decltype(*pocetakTreceg)>::type f (typename std::remove_reference<decltype(*pocetakPrvog)>::type a, typename std::remove_reference<decltype(*pocetakDrugog)>::type b),
								  bool f2  (typename std::remove_reference<decltype(*pocetakPrvog)>::type a, typename std::remove_reference<decltype(*pocetakDrugog)>::type b)){
	
	int velicina(0);
	Tip1 pomocni=pocetakPrvog;
	while (pocetakPrvog!=krajPrvog){
		velicina++;
		pocetakPrvog++;
	}
	pocetakPrvog = pomocni;
	//sortiranje
	std::sort(pocetakPrvog, krajPrvog, f2);
	std::sort(pocetakDrugog, pocetakDrugog+velicina, f2);
	/*	for(int i=0;i<velicina;i++) std::cout<<pocetakPrvog[i]<<" ";
		std::cout<<std::endl;
		for(int i=0;i<velicina;i++) std::cout<<f(pocetakPrvog[i], pocetakDrugog[i])<<" ";
		std::cout<<std::endl;*/
	bool ima(false);

	for (int i=0;i<velicina;i++){
		for(int j=i;j<velicina;j++){
			
			if(f(pocetakPrvog[i], pocetakDrugog[i])==pocetakTreceg[j]){
				std::swap(pocetakTreceg[j], pocetakTreceg[i]);
				ima=true;
				
			}
		}
		if(!ima) throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		else ima=false;
	}
	
}

int main ()
{
	int n(0);
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>n;
	std::vector<int> v1;
	std::vector<int> v2;
	std::vector<int> v3;
	
	int pomocna(0);
	int vel(0);
	std::cout<<"Unesite elemente prvog vektora: ";
	bool unesen(false);
	while(vel!=n){
		std::cin>>pomocna;
		for(int i=0;i<v1.size();i++)
			if(pomocna==v1.at(i)) unesen=true;
		if(!unesen){
			v1.push_back(pomocna);
			vel++;
		}
		else unesen=false;
	}
	
	std::cout<<"Unesite elemente drugog vektora: ";
	unesen=false;
	pomocna=0;
	vel=0;
	while(vel!=n){
		std::cin>>pomocna;
		for(int i=0;i<v2.size();i++)
			if(pomocna==v2.at(i)) unesen=true;
		if(!unesen){
			v2.push_back(pomocna);
			vel++;
		}
		else unesen=false;
	}
	
	std::cout<<"Unesite elemente treceg vektora: ";
	unesen=false;
	pomocna=0;
	vel=0;
	while(vel!=n){
		std::cin>>pomocna;
		for(int i=0;i<v3.size();i++)
			if(pomocna==v3.at(i)) unesen=true;
		if(!unesen){
			v3.push_back(pomocna);
			vel++;
		}
		else unesen=false;
	}
	std::cout<<std::endl;
	try{
		SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(), funkcija , Kriterij);
		std::cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:"<<std::endl;
		for(int i=0;i<n;i++)
			std::cout<<"f("<<v1.at(i)<<", "<<v2.at(i)<<") = "<<v3.at(i)<<std::endl;
	}
	catch(std::logic_error e){
		std::cout<<"Izuzetak: "<<e.what();
		return 0;
	}
	/*
	std::sort(v1.begin(), v1.end(), Kriterij);
	std::sort(v2.begin(), v2.end(), Kriterij);
	for(int i=0;i<n;i++) std::cout<<v1.at(i)<<" ";
	std::cout<<std::endl;
	for(int i=0;i<n;i++) std::cout<<v2.at(i)<<" ";
	std::cout<<std::endl;
	try{
	bool ima(false);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(-2*v1.at(i)+v2.at(i)==v3.at(j)) {
				std::swap(v3.at(j), v3.at(i));
				ima=true;
			}
		}
		if(!ima) throw std::logic_error("nema");
		else ima=false;
	}
	}
	catch(std::logic_error e){
		std::cout<<e.what();
		return 0;
	}
	for(int i=0;i<n;i++) std::cout<<v3.at(i)<<" ";*/

	return 0;
}