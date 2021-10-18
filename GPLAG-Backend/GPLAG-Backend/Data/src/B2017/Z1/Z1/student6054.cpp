/*B 2017/2018, Zadaća 1, Zadatak 1
	
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
#include <cmath>
std::vector<int> IzdvojiSimetricneTernarne(std::vector<int>v,bool a)
{
	std::vector<int>brojevi;
	std::vector<int>konacni;
	for(int i=0; i<v.size(); i++) {
		if(!a) {
			for(int j=2; j<v.at(i); j++) {
				if((v.at(i))%j==0) {
					brojevi.push_back(v.at(i));
					break;
				}
			}
		}
		else {
			int x=1;
			for(int k=2; k<v.at(i); k++) {
				if((v.at(i))%k==0) x=0; 
			}
			if(x==1) brojevi.push_back(v.at(i));
		}
	}
	int s=brojevi.size();
	for(int i=0;i<s;i++){
		for(int j=i+1;j<s;j++){
			if(brojevi.at(i)==brojevi.at(j)) {
				for(int k=j;k<s;k++){
					brojevi.at(k)==brojevi.at(k+1);
				}
				s--;
				j--;
			}
		}
	}
	std::vector<int>final;
	final=brojevi;
	for(int i=0;i<brojevi.size();i++){
        	std::vector<int>novi;
		int ostatak;
		do{
		ostatak=brojevi.at(i)%3;
		novi.push_back(ostatak);
		brojevi.at(i)=brojevi.at(i)/3;
		} while(brojevi.at(i)!=0);
		int x=novi.size();
		int y=1;
		for(int j=0;j<novi.size();j++){
			if(j==x) break;
			if(novi.at(j)==novi.at(x-1)){
				x--;
				continue;
				
			} 
			else {
				y=0;
				break; 
		}
		
	}
	
	if(y==1) konacni.push_back(final.at(i));
	

}
return konacni;	
}


int main ()

{
	int broj;
	int  a;
	std::vector<int>v ;
	
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	do{
		std::cin>>broj;
		if(broj!=-1)  {
		if(broj<0) broj=abs(broj);
		v.push_back(broj);}
		else break;
	} while(broj!=-1);
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin>>a;
	while(a!=0||a!=1){
		if(a==0||a==1) break;
		else{
		std::cout<<"Neispravan unos! Unesite ponovo: ";
		std::cin>>a;}
	}
std::vector<int>novi;
novi=IzdvojiSimetricneTernarne(v, a);
if(a){
	if(novi.size()==0) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
	else{
		std::cout<<"Prosti simetricni brojevi iz vektora su: ";
		for(int i=0;i<novi.size();i++){
	if(i<novi.size()-1){
	std::cout<<novi.at(i)<<", ";}
	else std::cout<<novi.at(i)<<".";
}
	}
}
else {
	if(novi.size()==0) std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	else{
		std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
		for(int i=0;i<novi.size();i++){
	if(i<novi.size()-1){
	std::cout<<novi.at(i)<<", ";}
	else std::cout<<novi.at(i)<<".";
}
	}
	
}



return 0;
}