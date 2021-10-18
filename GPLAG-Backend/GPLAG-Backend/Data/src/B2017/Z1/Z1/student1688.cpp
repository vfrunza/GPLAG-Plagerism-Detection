#include <iostream>
#include <vector>
#include <cmath>

/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/

bool prost_slozen(int br){
	if(br<2) return false;
	for(int i=2;i<br;i++){
		if(br%i==0) return false;
	}
	return true;
}
int ternarni (int broj){
	int novi_broj(0);
	int k(1);
	while(broj>0){
	 int cifra=broj%3;
	 novi_broj+=cifra*k;
	 k*=10;
	 broj/=3;
	}
	return novi_broj;
}

bool palindrom(int n){
	int temp(n);
	int pomocna(n);
	int novi(0);
	int br(0);
	while(temp>0){
		temp/=10;
		br++;
	}
	br--;
	while(pomocna>0){
		int cifra=pomocna%10;
		novi+=cifra*pow(10,br);
		br--;
		pomocna/=10;
	}
	
	if(novi!=n) return false;
	return true;
}

std::vector<int>IzdvojiSimetricneTernarne(std::vector<int>v, bool a){
	std::vector<int>v1;
	std::vector<int>v2;
	for(int i=0;i<v.size();i++){
		if(v.at(i)<0) v.at(i)*=(-1);
		int pom=v.at(i);
		if(a){
			if((prost_slozen(pom)==a) && (palindrom(ternarni(pom))==a)) v1.push_back(pom);
			continue;

		}
		else{
			if((prost_slozen(pom)==a) && (palindrom(ternarni(pom))!=a)) v2.push_back(pom);
			continue;
		}
		
	}	
	
	for(int i=0;i<v1.size();i++){
        for(int j=i+1;j<v1.size();j++)
            if(v1.at(i)==v1.at(j)){
                for(int k=j;k<v1.size()-1;k++)
                v1.at(k)=v1.at(k+1);
                j--;
                v1.resize(v1.size()-1);
            }
    }
    
 for(int i=0;i<v2.size();i++){
 	for(int j=i+1;j<v2.size();j++)
 	if(v2.at(i)==v2.at(j)){
 		for(int k=j;k<v2.size()-1;k++)
 		v2.at(k)=v2.at(k+1);
 		j--;
 		v2.resize(v2.size()-1);
 	}
 }
	if(a)   return v1;
 return v2;
	
}




int main ()
{
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int>v;
	int n;
	for(;;){
		std::cin>>n;
		if(n==-1) break;
		v.push_back(n);
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	int x;
	bool a;
	std::cin>>x;
	if(x!=1 && x!=0){
	//	while(x!=1 && x!=0){
		std::cout<<"Neispravan unos! ";
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		std::cout<<"Unesite ponovo: ";
		std::cin>>x; 
	//	}
	}
	if(x == 1) a = true;
	else a = false;
	std::vector<int>vec(IzdvojiSimetricneTernarne(v,a));
	if(a==true && vec.size()==0){
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		return 0;
	}
	if(a==false && vec.size()==0){
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		return 0;
	}
	if(a){
		int i(0);
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(i=0;i<vec.size()-1;i++)
		std::cout<<vec.at(i)<<", ";
		std::cout<<vec.at(i)<<".";
	}
	else{
		int i(0);
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(i=0;i<vec.size()-1;i++)
		std::cout<<vec.at(i)<<", ";
		std::cout<<vec.at(i)<<".";
	}
	return 0;
}