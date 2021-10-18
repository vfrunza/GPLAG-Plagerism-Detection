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
#include <vector> 
#include <iomanip>
#include <deque>
#include <stdexcept>
enum class SmjerKretanja{NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo }; 
typedef std::vector<std::deque<std::deque<int>>> Kontejner;
Kontejner KreirajKontejner(int size){
	return Kontejner(size, std::deque<std::deque<int>>(size, std::deque<int>(size,0)));
}
Kontejner UnesiKontejner(int size){
	auto kont(KreirajKontejner(size));
	for(int k=0; k<size; k++){
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				std::cin>>kont.at(k).at(i).at(j);
			}
		}
	}
	return kont;
}
void IspisiKontejner(Kontejner kont){
	int broj;
	for(int k=0; k<kont.size(); k++){
		broj=0;
		for(int i=0; i<kont.at(k).size()/2; i++){
			for(int l=0; l<i; l++) std::cout<<std::setw(4)<<" ";
			for(int j=0; j<kont.at(k).at(i).size(); j++){
				std::cout<<std::setw(4)<<kont.at(k).at(i).at(j);
			}
			broj+=1;
			std::cout<<std::endl;
		}
		for(int i=kont.at(k).size()/2; i<kont.at(k).size(); i++){
			for(int l=0; l<broj; l++) std::cout<<std::setw(4)<<" ";
			for(int j=0; j<kont.at(k).at(i).size(); j++){
				std::cout<<std::setw(4)<<kont.at(k).at(i).at(j);
			}
			broj-=1;
			std::cout<<std::endl;
		}
		std::cout<<std::endl;
	}
}
template <typename Tip>
Tip PjescaniSat(Tip kont, SmjerKretanja smjer){
	if(kont.size()==0) return kont;
	if(kont.size()!=kont.at(0).size() || kont.at(0).at(0).size()!=kont.size() || kont.at(0).size()!=kont.at(0).at(0).size()) throw std::domain_error("3D matrica nema oblik kocke");
	if(kont.size()%2!=1) throw std::length_error ("3D kontejner ne zadovoljava uvjet neparnosti");
    
//	Tip rezGD(KreirajKontejner(kont.at(0).size()); //Ispraviti kreiraj odmah dodijeliti rez=kont a potom sve vrijednosti vratiti na 9556091
	Tip rezGD=kont;
	int size=kont.at(0).size();
	if(smjer==SmjerKretanja::GoreDolje){
		for(int k=0; k<kont.size(); k++){
			for(int i=0; i<size; i++){
				for(int j=0; j<size; j++){
					rezGD.at(k).at(i).at(j)=kont.at(k).at(i).at(j);
//					if((j<size/2 && i>0+j && i<size-1-j) || (j>size/2 && i>size-j-1 && i<size-(size-j))) rezGD.at(k).at(i).at(j)=0;
				}
			}
		}
	}
	if(smjer==SmjerKretanja::DoljeGore){
		for(int k=0; k<kont.size(); k++){
			for(int i=0; i<size; i++){
				for(int j=0; j<size; j++){
					rezGD.at(k).at(i).at(j)=kont.at(k).at(size-1-i).at(j);
//					if((j<size/2 && i>0+j && i<size-1-j) || (j>size/2 && i>size-j-1 && i<size-(size-j))) rezGD.at(k).at(i).at(j)=0;
				}
			}
		}
	}
	if(smjer==SmjerKretanja::LijevoDesno){
		for(int k=0; k<kont.size(); k++){
			for(int i=0; i<size; i++){
				for(int j=0; j<size; j++){
				    rezGD.at(k).at(i).at(j)=kont.at(k).at(j).at(i);	
//				    if((j<size/2 && i>0+j && i<size-1-j) || (j>size/2 && i>size-j-1 && i<size-(size-j))) rezGD.at(k).at(i).at(j)=0;
				}
			}
		}
	}
	if(smjer==SmjerKretanja::DesnoLijevo){
		for(int k=0; k<kont.size(); k++){
			for(int i=0; i<size; i++){
				for(int j=0;  j<size; j++){
					rezGD.at(k).at(i).at(j)=kont.at(k).at(j).at(size-i-1);
//					if((j<size/2 && i>0+j && i<size-1-j) || (j>size/2 && i>size-j-1 && i<size-(size-j))) rezGD.at(k).at(i).at(j)=0;
				}
			}
		}
	}
	if(smjer==SmjerKretanja::NaprijedNazad){
		for(int k=0; k<kont.size(); k++){
			for(int i=0; i<size; i++){
				for(int j=0; j<size; j++){
					rezGD.at(k).at(i).at(j)=kont.at(i).at(k).at(j);
//					if((j<size/2 && i>0+j && i<size-1-j) || (j>size/2 && i>size-j-1 && i<size-(size-j))) rezGD.at(k).at(i).at(j)=0;
				}
			}
		}
	}
	if(smjer==SmjerKretanja::NazadNaprijed){
		for(int k=0; k<kont.size(); k++){
			for(int i=0; i<size; i++){
				for(int j=0; j<size; j++){
					rezGD.at(k).at(i).at(j)=kont.at(size-i-1).at(k).at(j);
//					if((j<size/2 && i>0+j && i<size-1-j) || (j>size/2 && i>size-j-1 && i<size-(size-j))) rezGD.at(k).at(i).at(j)=0;
				}
			}
		}
	}
	Tip rez(size);
	int broj(0);
		for(int k=0; k<kont.size(); k++){
			broj=0;
			for(int i=0; i<size/2; i++){
				rez.at(k).push_back({});
				for(int j=broj; j<size; j++){
				rez.at(k).at(i).push_back(0);
				}
				broj+=2;
			}
			for(int i=size/2; i<size; i++){
				rez.at(k).push_back({});
				for(int j=broj; j<size; j++){
				rez.at(k).at(i).push_back(0);
				}
				broj-=2;
			}
		}
		
	for(int k=0; k<size; k++){
		broj=0;
		for(int i=0; i<size/2; i++){
			for(int j=broj; j<size-broj; j++){
				rez.at(k).at(i).at(j-broj)=rezGD.at(k).at(i).at(j);
			}
			broj+=1;
		}
		for(int i=size/2; i<size; i++){
			for(int j=broj; j<size-broj; j++){
				 rez.at(k).at(i).at(j-broj)=rezGD.at(k).at(i).at(j);
			}
			broj-=1;
		}
	}
//	IspisiKontejner(rez);
	//Ovdje je potrebno napraviti novi kont sa grbavim matricama potom probati 
	//push_back-om dodijeliti novom kontejneru vrijednsoti razlicite od broja 995...
	//	IspisiKontejner(rezGD);
	return rez;
}
int main ()
{
	try{
	int n,m;
	std::cout<<"Unesite dimenziju (x/y/z): ";
	do{
		std::cin>>n;
		if(n<0) std::cout<<"Dimenzija nije ispravna, unesite opet: ";
	}while(n<0);
	std::cout<<"Unesite elemente kontejnera: ";
	auto kont=UnesiKontejner(n);
//	Kontejner kont={{{11, 12, 13, 14, 15},{16, 17, 18, 19, 20},{21, 22, 23, 24, 25},{26, 27 ,28, 29, 30},{31, 32, 33, 34, 35}},{{-9,-8,-7,-6,-5},{-4,-3,-2,-1,17},{14,25,28,30,35},{19,-8,54,78,65},{22,11,72,16,67}},{{89,28,17,56,55},{64,93,12,81,17},{14,25,28,31,35},{19,44,53,72,65},{22,18,72,16,69}},{{36,37,38,42,43},{39,40,41,44,45},{46,47,48,55,56},{49,50,51,57,58},{52,53,54,59,60}},{{61,62,63,67,68},{64,65,66,69,70},{71,72,73,80,82},{74,75,76,81,83},{77,78,79,84,85}}};
	std::cout<<"Unesite smjer kretanja [0 - 5]: ";
	do{
		std::cin>>m;
		if(m<0 || m>5) std::cout<<"Smjer nije ispravan, unesite opet: ";
	}while(m<0 || m>5);
	std::cout<<std::endl;
	auto novi=PjescaniSat(kont,SmjerKretanja(m));
	std::cout<<"Pjescani sat unesene matrice je: "<<std::endl;
	std::cout<<std::endl;
	IspisiKontejner(novi);
	}catch(std::domain_error Izuzetak){
		std::cout<<"Izuzetak: "<<Izuzetak.what()<<std::endl;
	}catch(std::length_error Izuzetak){
		std::cout<<"Izuzetak: "<<Izuzetak.what()<<std::endl;
	}
	return 0;
}