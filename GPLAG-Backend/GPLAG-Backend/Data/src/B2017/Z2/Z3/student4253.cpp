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
#include<vector>
#include<stdexcept>
template<typename Tip>
int periodican(const std::vector<Tip>&v){
	for(int i(1);i<=v.size()-1;i++){
		bool periodican=true;
		
		for(int j(0);j<v.size()-1;j++){
			for(int k(j+i);k<v.size();k+=i){
			if(v.at(j)!=v.at(k))
			periodican=false;
			}
		}
		if(periodican==true) return i;
	}
	return-1;
}


template<typename Tip>
int**AlocirajFragmentirano(const std::vector<Tip>&v,int &koliko_puta){
	int periodicnost=periodican(v);{
	if(periodicnost!=-1){
		koliko_puta=(v.size()+(periodicnost-(v.size()%periodicnost)))/periodicnost;
	}
	else{
		koliko_puta=2;
		
	}
	for(int i(0); i<v.size();i++){
		if(v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
	
	}
	try{
		int**matrica=new int*[koliko_puta*periodicnost];
		for(int i(0);i<koliko_puta*periodicnost;i++){
		matrica[i]=nullptr;
		}
		try{
		for(int i(0);i<koliko_puta*periodicnost;i++){
			matrica[i]=new int[v.at(i%periodicnost)];
		}
		
		int maksimalni=v.at(0);
		for(int i(0);i<periodicnost;i++){
			if(v.at(i)>maksimalni) maksimalni=v.at(0);
		}
		for(int i(0);i<koliko_puta*periodicnost;i++){
			for(int j=v.at(i%periodicnost)-1;j>=0;j--){
				if(j==v.at(i%periodicnost)-1) matrica[i][j]=maksimalni;
				else{
					matrica[i][j]=matrica[i][j+1]-1;
				}
			}
			return matrica;
		}
	}catch(...){
		for(int i(0);i<koliko_puta*periodicnost;i++){
		delete[] matrica[i];
	}
	delete[] matrica;
	throw;
	}
	}catch(...){
		throw;
	}
}
}
template<typename Tip1>
int**AlocirajKontinualno(const std::vector<Tip1>&v,int &koliko_puta){
	int periodicnost=periodican(v);
		if(periodicnost!=-1){
			koliko_puta=(v.size()+(periodicnost-(v.size()%periodicnost)))/periodicnost;
			
		}
		else{
			koliko_puta=2;
		}
		for(int i(0);i<v.size();i++){
			if(v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
			
			}
			try{
				int**matrica =new int *[koliko_puta*periodicnost];
				for(int i(0);i<koliko_puta*periodicnost;i++){
				matrica[i]=nullptr;
			}
			try{
				for(int i(0);i<koliko_puta*periodicnost;i++){
					matrica[i]=new int[v.at(i%periodicnost)];
				}			
				for(int i(0);i<koliko_puta*periodicnost;i++){
					for(int j=v.at(i%periodicnost)-1;j>=0;j--){
						if(j==v.at(i%periodicnost)-1) matrica[i][j]=1;
						else{
							matrica[i][j]=matrica[i][j+1]+1;
							
						}
					}
				}
				return matrica;
			}
			catch(...){
				for(int i(0);i<koliko_puta*periodicnost;i++){
					delete[] matrica[i];
				}
			}
		}
		
	}

int main (){
	int n,elementi;
	std::vector<int>v1,v2;
	std::cout<<"Unesite broj elementa vektora:";
	std::cin>>n;
	std::cout<<"\nUnesite elemente vektora:";
	for(int i(0);i<n;i++){
		std::cin>>elementi;
		v1.push_back(elementi);
	}
	for(int j(0);j<n;j++){
		std::cin>>elementi;
		v2.push_back(elementi);
	}
	
	return 0;
}