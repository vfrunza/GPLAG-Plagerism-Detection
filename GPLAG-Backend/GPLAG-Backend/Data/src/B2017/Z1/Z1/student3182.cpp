/B2017/2018: ZSR 1, Zadatak 2
#include <iostream>
#include <deque> 
#include <cmath>
#include <vector>

	bool DaLiJeTernarnoSimetrican(int n) {
	
	std::deque<int> a;
	std::deque<int> b;
	
	std::deque<int> v;
	while (n!=0) {
    	v.push_front(n%3);
    	n=n/3; }
    	
	
    for(int i=0; i<v.size()/2; i++) {
    	a.push_back (v.at(i))	;
    }
    

  	if(v.size()%2!=0) {
    for (int i=v.size()-1; i>v.size()/2; i--) {
		b.push_back( v.at(i) ); }
  	}
	
	if(v.size()%2==0) {
    for (int i=v.size()-1; i>=v.size()/2; i--) {
		b.push_back( v.at(i) ); }
  	}
	
	
	if(a==b) return true; 
		else return false;
	}


	bool DaLiJeProst(int n) {
		int i;
		
		if (n<0) n=fabs(n);
		for (i=2; i<=std::sqrt(n); i++) 
		{
	
		if (n%i == 0 ) 
			{
				return false; /*slozen*/
				
			}
		}
	     return true; /*prost*/
		
	}
	
	std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> a, bool b) {
	std::vector<int> m;
	std::vector<int> n;
	
		int i;
		for (i=0; i<a.size(); i++) {
		
			
			if (b==true) {
				
				int x = DaLiJeProst(a.at(i));
				int y = DaLiJeTernarnoSimetrican(a.at(i));
				if (x==1 && y==1) m.push_back(a.at(i));
			}
			
			if (b==false) {
				
				int x = DaLiJeProst(a.at(i));
				int y = DaLiJeTernarnoSimetrican(a.at(i));
				if (x==0 && y==1) n.push_back(a.at(i));
			}
			
		}
		
		if (b==true) return m; else return n;
	}	

int main ()
{
		
	std::vector<int> brojevi;
	int broj;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	
	do {
    	std::cin >> broj;
    		if(broj != -1)  {
    			brojevi.push_back(broj);
    			}
    
	} while(broj != -1);
		
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";

	int a;
    std::cin>>a;
    while (a!=0 && a!=1) {
         std::cout<<"Neispravan unos! Unesite ponovo: ";
        std::cin >> a; }
		
	auto m (IzdvojiSimetricneTernarne(brojevi, a));
		
	if (m.size()==0 && a==1) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	if (m.size()==0 && a==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	if (m.size()!=0 && a==1) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	if (m.size()!=0 && a==0) std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		
		for (int i=0; i<m.size(); i++) {
			if (i==m.size()-1) std::cout << m.at(i) << ". ";
 		else std::cout<< m.at(i) << ", ";
		}
	

    
	return 0;
}

