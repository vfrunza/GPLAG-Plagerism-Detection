/*B 2017/2018, Zadaća 2, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <vector>
#include <stdexcept>
#include <type_traits>
enum class SmjerKretanja {NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo}; 

template<typename nekitip>
decltype(nekitip()) PjescaniSat(nekitip kont, SmjerKretanja smjer) {
int n=kont.size();
if(n>0){

for(int i=0;i<n;i++) 
for(int j=0;j<n;j++)
	if(kont.at(i).size()!=n || n!=kont.at(0).size() || kont.at(i).at(j).size()!=n) throw std::domain_error("3D matrica nema oblik kocke");
	}else throw std::domain_error("3D matrica nema oblik kocke");

for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
if(kont.at(i).size()%2==0 || kont.at(i).at(j).size()%2==0 )throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");


decltype(nekitip()) kontejner;

if(smjer==SmjerKretanja::DoljeGore || smjer==SmjerKretanja::GoreDolje || smjer==SmjerKretanja::DesnoLijevo || smjer==SmjerKretanja::LijevoDesno) {

for(int i=0;i<n;i++)kontejner.push_back(kont.at(i));


for(int i=0;i<kont.size();i++) {
	
	if(smjer==SmjerKretanja::DoljeGore){    //obrnuti redove
		 	int z=0;
		 for(int j=n-1;j>=0;j--) {
		 
		   for(int k=0;k<n;k++){
		kontejner.at(i).at(z).at(k)=kont.at(i).at(j).at(k);
		   }
		   	z++;
		 }
		}
		
	
	else if(smjer==SmjerKretanja::DesnoLijevo || smjer==SmjerKretanja::LijevoDesno) {
		
		if(smjer==SmjerKretanja::DesnoLijevo) {
			for(int j=0;j<n;j++){
				
			for(int k=0;k<n/2;k++){
				auto pomocna=kont.at(i).at(j).at(k);
			kont.at(i).at(j).at(k)=kont.at(i).at(j).at(n-k-1);
		kont.at(i).at(j).at(n-k-1)=pomocna;
			}
			} 
			
			
		}
		
			for(int j=0;j<n;j++)
		for(int k=0;k<n;k++) 
			kontejner.at(i).at(j).at(k)=kont.at(i).at(k).at(j);

	}
		
	
}


decltype(nekitip()) grbava(n);
for(int i=0;i<n;i++)
grbava.at(i).push_back({});
	

for(int i=0;i<n;i++) {
int k=0;

for(int j=0;j<n;j++) {
	
grbava.at(i).push_back({});
for(int z=k;z<n-k;z++) {
grbava.at(i).at(j).push_back(kontejner.at(i).at(j).at(z));
}
   if(j<n/2)k++;
	else k--;
}

}

return grbava;

}
else if(smjer==SmjerKretanja::NaprijedNazad || smjer==SmjerKretanja::NazadNaprijed) {

if(smjer==SmjerKretanja::NazadNaprijed) {
	
for(int i=n-1;i>=0;i--)kontejner.push_back(kont.at(i));

}
else for(int i=0;i<n;i++)kontejner.push_back(kont.at(i));

for(int i=0;i<n;i++) {

for(int j=0;j<n;j++) {
for(int k=0;k<n;k++) {

kontejner.at(i).at(j).at(k)=kont.at(j).at(i).at(k);
}
}
}


if(smjer==SmjerKretanja::NazadNaprijed) {
for(int i=0;i<n;i++) {
	
		for(int j=0;j<n/2;j++) {
			
			auto pomocna(kontejner.at(i).at(j));
			for(int k=0;k<n;k++) {
			kontejner.at(i).at(j).at(k)=kontejner.at(i).at(n-j-1).at(k);
			}
			for(int k=0;k<n;k++) {
				kontejner.at(i).at(n-j-1).at(k)=pomocna.at(k);
			}
			
		}
		
} 

} 




}

decltype(nekitip()) grbava(n); 

for(int i=0;i<n;i++){

		grbava.at(i).push_back({});
}

for(int i=0;i<n;i++) {
int k=0;
for(int j=0;j<n;j++) {
	grbava.at(i).push_back({});
for(int z=k;z<n-k;z++) {
grbava.at(i).at(j).push_back(kontejner.at(i).at(j).at(z));

}
	if(j<n/2)k++;
	else k--;
}
	
}
return grbava;

}

int main ()
{
	
	std::cout<<"Unesite dimenziju (x/y/z): ";
	int n; 
	std::cin>>n;
	while(n<=0 || !std::cin) {
		std::cout<<"Dimenzija nije ispravna, unesite opet: ";
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		std::cin>>n;
	}
	
	std::cout<<"Unesite elemente kontejnera: ";
	std::vector<std::deque<std::deque<int>>> kontejner (n,std::deque<std::deque<int>>(n,std::deque<int>(n,0)) );
int broj;
   for(int i=0;i<n;i++) {
   	for(int j=0;j<n;j++) {
   	   for(int k=0;k<n;k++) {
   	   	std::cin>>broj; kontejner.at(i).at(j).at(k)=broj;
   	   }	
   	}
   }
   
   
   
   std::cout<<"Unesite smjer kretanja [0 - 5]: ";
   int smjer; std::cin>>smjer;
   	while(smjer>5 ||smjer<0) {
		std::cout<<"Smjer nije ispravan, unesite opet: ";
		std::cin>>smjer;
	}
	SmjerKretanja s;
   if(smjer==0) s=SmjerKretanja::NaprijedNazad;
   else if(smjer==1)s=SmjerKretanja::NazadNaprijed;
   else if(smjer==2)s=SmjerKretanja::GoreDolje;
   else if(smjer==3)s=SmjerKretanja::DoljeGore;
   else if(smjer==4)s=SmjerKretanja::LijevoDesno;
   else if(smjer==5)s=SmjerKretanja::DesnoLijevo;
   
try {
kontejner=PjescaniSat(kontejner,s);
std::cout<<std::endl;
std::cout<<"Pjescani sat unesene matrice je: "<<std::endl<<std::endl;

for(int i=0;i<n;i++) {
	for(int j=0;j<n;j++) {
		
	for(int k=0;k<kontejner.at(i).at(j).size();k++) {
	
	if(k==0 && j!=0 && j<=n/2)std::cout<<std::setw(4*(j+1))<<kontejner.at(i).at(j).at(k);
	else if (k==0 && j!=0 && j>n/2)std::cout<<std::setw( 4*(n-j))<<kontejner.at(i).at(j).at(k);
	else std::cout<<std::setw(4)<<kontejner.at(i).at(j).at(k);
		
	}

	std::cout<<std::endl;
	}
	std::cout<<std::endl;
}

}
catch(std::domain_error izuzetak) {
	std::cout<<std::endl;
	std::cout<<"Izuzetak: "<<izuzetak.what();
}
	catch(std::length_error izuzetak) {
		std::cout<<std::endl;
		std::cout<<"Izuzetak: "<<izuzetak.what();
	}
	
	return 0;
}