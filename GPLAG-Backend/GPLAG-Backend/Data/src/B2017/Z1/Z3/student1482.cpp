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


int main ()
{
	std::vector<int> a;
	std::vector<int> t;
	std::vector<std::vector<int>> l;
	int b, f, n(0);
	
	std::cout<<"Unesite broj elemenata drugog vektora: ";
    std::cin>>b;
    std::cout<<"Unesite elemente drugog vektora: ";
    while(b--){
        std::cin>>f;
        a.push_back(f);
    }
    
    
	for(int i=0; i<=a.size()-2; i++){
		if(a.at(i)<a.at(i+1)){
			t.push_back(a.at(i));
			if(i<=a.size()-2)
		    t.push_back(a.at(i+1));
		}
	}
		
	
	for(int i=0; i<t.size(); i++)
	for(int j=i+1; j<t.size(); j++){
		if(t.at(i)==t.at(j)){
			t.erase(t.begin()+j);
			j--;
		}
	}
	
	for(int i=0; i<=t.size()-2; i++){
		if(t.at(i)<t.at(i+1)){
			(l.at(n)).push_back(t.at(i));
			if(i<=a.size()-2)
			(l.at(n)).push_back(t.at(i+1));
		}
		else n++;
	}
	
	
	
	
	for(auto h: l)
	for(int k: h)
	std::cout<<k<<" ";
	return 0;
}