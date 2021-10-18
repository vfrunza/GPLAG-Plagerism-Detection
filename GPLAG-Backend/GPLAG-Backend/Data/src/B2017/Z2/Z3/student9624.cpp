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
#include <memory>
#include <algorithm>


int **AlocirajFragmentirano (const std::vector<int> &v, int &koliko_puta) {
	if(v.size()==0) throw ("Prazan vektor!");
	for(int i=0 ; i<v.size() ; i++) {
		if(v.at(i)<=0) throw std::domain_error ("Neispravan vektor!");
		
	}
	int  i(0), j(1),duz(1);
	koliko_puta=1;
		while(v.at(i)!=v.at(j) && j<v.size()) {j++; duz++;}
		if(j==v.size()) {koliko_puta=2; duz=v.size(); }
		bool per(true);
		if(v.at(i)==v.at(j) && v.at(i+1)==v.at(j+1)){ 
			
			
				for(int i=0 ; i<duz ; i++){
					if(v.at(i)==v.at(j) && j<v.size()) j++;
					else per=false;
					if(i==duz-1) i=0;
				}
			
			
		}
		if(per){
			if(v.size()%duz==0) koliko_puta=v.size()/duz;
			else koliko_puta=v.size()/duz +1;
		}
		
		int **a=nullptr;
		try{
			a=new int* [koliko_puta*duz] {};
			int j(0);
			for(int i=0 ; i<koliko_puta*duz ; i++) {
				a[i]=new int[v.at(j)];
				if(j==duz-1) j=0;
				j++;
				
			}
			int *max(*std::max_element(a,a+duz));
			for(int i=0 ; i<koliko_puta*duz; i++){
				int x(*max);
				int k(duz);
				for(int j=v.at(k)-1 ; j>=0 ; j--){
					a[i][j]=x;
					x--; 
				}
				
			}
		}
		catch(...){
			if(a!=nullptr){
				for(int i=0 ; i<koliko_puta*duz ; i++){
					delete [] a[i];
				}
				delete a;
				throw;
			}
		}
		
		
		return a;
}


int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<int> v;
	for(int i=0 ; i<n ; i++ ){
		int x;
		std::cin>>x;
		v.push_back(x);
	}
	std::cout<<"Odaberite alokaciju : a - fragmentirano, 0 - kontinualno: ";
	int f;
	std::cin>>f;
	try{
		if(f==1){
			int k(0);
			int **frag(AlocirajFragmentirano(v,k));
			
		}
	}
	catch(std::domain_error e){
		std::cout<<e.what();
	}
	
	
	return 0;
}