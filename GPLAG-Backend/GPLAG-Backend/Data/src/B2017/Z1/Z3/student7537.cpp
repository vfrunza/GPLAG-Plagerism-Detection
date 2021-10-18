/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <deque>
#include <vector>
#include <cmath>

typedef std::vector<int> Vektor;
typedef std::deque<Vektor> Dek; 

Vektor Stepen(Vektor v){
	Vektor povratni;
		for(int i=0; i<v.size(); i++){
			if(v.at(i)<=0) povratni.push_back(0);
	 	   for(int j=0; j<v.at(i); j++){
		    if(static_cast<long long int>(std::pow(2,j))==v.at(i)){ povratni.push_back(v.at(i)); break;}
		    if(static_cast<long long int>(std::pow(2,j))>v.at(i)){ povratni.push_back(0); break;}
	       }}
	return povratni;
}

enum Smjer {Rastuci=1, Opadajuci};

Dek MaksimalniPodnizoviStepenaDvojke(Vektor vektor, Smjer smjer){
	Dek Konacni; 
	Vektor pomocni{Stepen(vektor)}, v;
	int br{0}, b{0};
	if(pomocni.size()==0) return Konacni;
	
	if(smjer==Rastuci){
		for(int i=0; i<pomocni.size()-1; i++){
			while(pomocni.at(i)!=0 && pomocni.at(i)<=pomocni.at(i+1)){
				if(br==0) Konacni.push_back(v);
			    Konacni.at(b).push_back(pomocni.at(i));
			    br++; i++;
			    if(i==pomocni.size()-1) break;
			}
			if(i!=0 && pomocni.at(i)>=pomocni.at(i-1) && pomocni.at(i-1)!=0){
				Konacni.at(b).push_back(pomocni.at(i));
				b++; br=0;
			}
		}
	}
	else if(smjer==Opadajuci){
		for(int i=0; i<pomocni.size()-1; i++){
			while(pomocni.at(i)>=pomocni.at(i+1) && pomocni.at(i+1)!=0){
				if(br==0) Konacni.push_back(v);
			    Konacni.at(b).push_back(pomocni.at(i));
			    br++; i++;
			    if(i==pomocni.size()-1) break;
			}
			if(i!=0 && pomocni.at(i)<=pomocni.at(i-1) && pomocni.at(i)!=0){
				Konacni.at(b).push_back(pomocni.at(i));
				b++; br=0;
			}
		}
	}

	return Konacni;
}

int main ()
{
	int elem;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> elem;
	
	Vektor v(elem);
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<elem; i++)
	std::cin >> v.at(i);
	
	std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	Smjer a;
	int b;
	std::cin >> b;
	a=Smjer(b);
	
   Dek dek(MaksimalniPodnizoviStepenaDvojke(v, a));
   if(a==1)
   std::cout << "Maksimalni rastuci podnizovi: \n";
   else std::cout << "Maksimalni opadajuci podnizovi: \n";
   for(int i=0; i<dek.size(); i++){
   	for(int j=0; j<dek.at(i).size(); j++)
   	std::cout << dek.at(i).at(j) << " ";
   	std::cout << std::endl;
   }
   
	return 0;
}