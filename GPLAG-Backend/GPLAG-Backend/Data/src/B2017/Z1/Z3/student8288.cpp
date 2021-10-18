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
#include<vector>
#include<deque>
typedef std::vector<int> Vektor;
typedef std::deque<int> Deque ;

enum Smjer { Rastuci=1, Opadajuci=2};

bool DaLiJeStepenDvojke (int s) {
	
		while(s!=1){
			
			if(s%2!=0) return false ;
				s=s/2 ;
}
	return true ;
}



std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke (const Vektor &m,Smjer s)
{
   std::deque<std::vector<int>>  d ;
	Vektor r ;
	if(m.size()==0 || m.size()==1) return d ;
	
	if(s==1) {
		for(int i(0), j(1); i<m.size(); i++, j++) {
		          if( j<m.size() && DaLiJeStepenDvojke(m.at(i)) && DaLiJeStepenDvojke(m.at(j))  && (m.at(i)<m.at(j) ))
		          r.push_back(m.at(i)) ;
		          else { if(DaLiJeStepenDvojke(m.at(i))){
		          if(i != 0) if(DaLiJeStepenDvojke(m.at(j-1)) && DaLiJeStepenDvojke(m.at(i)) && m.at(i-1) < m.at(j-1))  r.push_back(m.at(i)) ;
		          d.push_back(r);
		          r.resize(0) ; //poraditi na uslov 
		          }}
			}
		}
	else if(s == 2) {
		
		for(int i(0), j(1); i<m.size(); i++, j++) {
		          if( j<m.size() && DaLiJeStepenDvojke(m.at(i)) && DaLiJeStepenDvojke(m.at(j)) && 
		           (m.at(i)>m.at(j) ))
		          r.push_back(m.at(i)) ;
		          else {if(DaLiJeStepenDvojke(m.at(i))) {
		          if(i != 0) if(DaLiJeStepenDvojke(m.at(i - 1)) 
		          && DaLiJeStepenDvojke(m.at(i)) && m.at(i-1) > m.at(j-1))  r.push_back(m.at(i)) ;
		          d.push_back(r);
		          r.resize(0) ; //poraditi na uslovu
		          }}
			}
		  
	   }
	   if(d.size() != 0) for(int i(0); i < d.size(); i++) if(d.at(i).size() == 0){ d.erase(d.begin() + i); i--;}
	return d ;
	}
		
	void Ispis(std::deque<std::vector<int>> d)
	{
		for(int i(0); i < d.size(); i++)
		{
			for(int j(0); j < d.at(i).size(); j++) std::cout<<d.at(i).at(j)<<" ";
				std::cout<<"\n";
		}
	
	}



int main()
{
	int n{0},broj{0},k{0};
    int brojac{0};
	Vektor m ;
	std::cout<<"Unesite broj elemenata vektora:" ;
	std::cin>>n ;
	std::cout<<" Unesite elemente vektora:";
	do {
	
		std::cin>>broj ;
		m.push_back(broj);
		brojac ++;
		
	} while(brojac<n) ;

	std::cout<<" Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove:";
	std::cin>>k ;

	if(k==1) 
	{
		std::cout<<" Maksimalni rastuci podnizovi:\n";
		std::deque<std::vector<int>> M(MaksimalniPodnizoviStepenaDvojke(m,Rastuci));
		Ispis(M);
	}
	else if (k==2)
	{
		std::cout<<" Maksimalni opadajuci podnizovi:\n" ;
		std::deque<std::vector<int>> S(MaksimalniPodnizoviStepenaDvojke(m,Opadajuci));
		Ispis(S);
	}

	return 0 ;
}
