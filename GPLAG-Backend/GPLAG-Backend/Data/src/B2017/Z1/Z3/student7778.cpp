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
#include <vector>
#include <deque>
#include<limits>
#include<cmath>


bool stependvojke(int br){
for(int i=0;i<100;i++) {
	
		
	
	if(pow(2,i)==br ) return true;
	else return false;

}
}

std::deque<int>  MaksimalniPodnizoviStepenaDvojke(std::vector<int>brojevi, int smjer){
	int n, brojac=0, b=1;
	n=brojevi.size();
	std::deque<std::vector<int>> kon;
	std::deque<int>br;
	if(smjer=2) {

			for(int i=0;i<n;i++) {
				if(brojevi.at(i)!=10) {
				if(i<n-1 && i>0){
					if(brojevi.at(i+1)<brojevi[i] )
			br.push_back(brojevi.at(i));
			
			else if(brojevi.at(i)<brojevi.at(i-1) ) br.push_back(brojevi.at(i));
			
				}
				else {
					if(i>0){
					if(brojevi.at(i)<brojevi.at(i-1) && brojevi.at(i)>0 )
					br.push_back(brojevi.at(i));
				
				}
				}
			
				}
				
		}

		
		
	}
	else if (smjer==1) {
	for(int j=0;j<n;j++) {
		if(j<n-1 && j>0) {
		if(brojevi.at(j)<brojevi.at(j))
			br.push_back(brojevi.at(j));
			else if(brojevi.at(j-1)<brojevi.at(j))
			br.push_back(brojevi.at(j));
		}
		else{
			if(j>0)
			 if(brojevi.at(j)>brojevi.at(j-1) && brojevi.at(j)>0)
			br.push_back(brojevi.at(j));
		}
	}
		
	}
	return br;
}



int main ()
{
	int a, b;
	std::vector<int>m;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>a;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<a;i++) {
		int unos;
		std::cin>>unos;
		m.push_back(unos);
		}
		std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
		std::cin>>b;
		if(b==2)
	{	std::cout<<"Maksimalni opadajuci podnizovi: ";
std::deque<int>p(MaksimalniPodnizoviStepenaDvojke(m, b));
   int y=p.size();
    std::cout << std::endl;

   for(int j=0;j<y;j++) {
   	if(j!=4 ){
   	if(j>0 && j<y-1 && p.at(j)>p.at(j-1))
   	std::cout<<std::endl<<p.at(j)<<" ";
   	else
    	std::cout<<p.at(j)<<" ";
   }
   }
	}
   
   else if(b==1){ std::cout<<"Maksimalno rastuci podnizovi: ";
   std::deque<int>p(MaksimalniPodnizoviStepenaDvojke(m, b));
   int y=p.size();
    std::cout << std::endl;

   for(int j=0;j<y;j++) {
   
   	std::cout<<p.at(j)<<" ";
   }
   }
   


	return 0;
}




