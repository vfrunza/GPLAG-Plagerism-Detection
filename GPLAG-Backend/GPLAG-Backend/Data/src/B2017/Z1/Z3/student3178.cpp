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
#include <cmath>

enum Smjer{Rastuci=1, Opadajuci};

bool Dalijestepen2(int a){
	int broj;
	if(broj==1) return 1; 
	broj=1;
	while(broj<a || broj==a){
		if(broj==a) return true;
		broj*=2;
	}
	return false;
}
std::deque<std::vector<int>> MaksimalniPodnizoviStepenaDvojke(std::vector<int> v, Smjer s){
	std::deque<std::vector<int>> novi(1);
	if(int(s)==2){
	int prvi=0;//prvi u redu 
			int vrijednostprvog;
			int imavec=0;//ima vec upisano u tom redu prije njega
			int x=0;//za kretanje kroz redove deka
			int prosli=0;
		for(int i(0);i<v.size();i++){
			
			if(prvi==0 && Dalijestepen2(v.at(i))==true){ prvi=1; vrijednostprvog=v.at(i); imavec=0; prosli=0;}
			else if(prvi==0 && Dalijestepen2(v.at(i))==false){ prvi=0; imavec=0; prosli=0;}
			else if(prvi==1 && Dalijestepen2(v.at(i))==true){ //ako postoji neki prije njega koji zadovoljava i ovaj je stepen dvojke
				     if(imavec==0){ 
				     	    if(v.at(i)<vrijednostprvog){ //i manji od proslog
				     	    	      novi.at(x).push_back(vrijednostprvog);//dodaj prosli
				     	    	      novi.at(x).push_back(v.at(i)); //dodaj taj
				     	    	      imavec=1; prosli=v.at(i);} 
				     	    else{ prvi=0;imavec=0;prosli=0;i--;}} 
				     else if(imavec==1){
				     	    if(v.at(i)<prosli){ novi.at(x).push_back(v.at(i));prosli=v.at(i);}
				     	    else if(v.at(i)>=prosli){prvi=0;imavec=0;prosli=0;x++; novi.resize(novi.size()+1);i--;}}}
				     	    
			else if(prvi==1 && Dalijestepen2(v.at(i))==false){ if(imavec==1){x++; novi.resize(novi.size()+1);i--;}prvi=0; imavec=0;prosli=0;}
		}
}
	if(int(s)==1){
            int prvi=0;//prvi u redu 
			int vrijednostprvog;
			int imavec=0;//ima vec upisano u tom redu prije njega
			int x=0;//za kretanje kroz redove deka
			int prosli=0;
		for(int i(0);i<v.size();i++){
			
			if(prvi==0 && Dalijestepen2(v.at(i))==true){ prvi=1; vrijednostprvog=v.at(i); imavec=0; prosli=0;}
			else if(prvi==0 && Dalijestepen2(v.at(i))==false){ prvi=0; imavec=0; prosli=0;}
			else if(prvi==1 && Dalijestepen2(v.at(i))==true){ //ako postoji neki prije njega koji zadovoljava i ovaj je stepen dvojke
				     if(imavec==0){ 
				     	    if(v.at(i)>vrijednostprvog){ //i veci od proslog
				     	    	      novi.at(x).push_back(vrijednostprvog);//dodaj prosli
				     	    	      novi.at(x).push_back(v.at(i)); //dodaj taj
				     	    	      imavec=1; prosli=v.at(i);} 
				     	    else{ prvi=0;imavec=0;prosli=0;}} 
				     else if(imavec==1){
				     	    if(v.at(i)>prosli){ novi.at(x).push_back(v.at(i));prosli=v.at(i);}
				     	    else if(v.at(i)<=prosli){prvi=0;imavec=0;prosli=0;x++; novi.resize(novi.size()+1);i--;}}}
				     	    
			else if(prvi==1 && Dalijestepen2(v.at(i))==false){ if(imavec==1){x++; novi.resize(novi.size()+1);i--;}prvi=0; imavec=0;prosli=0;}
		}
		
	}
    return novi;
}


int main ()
{
	
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
    std::vector<int> v(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0);i<n;i++){
		std::cin>>v.at(i);
	}
	std::cout<<"Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
	int a;
	std::cin>>a;
	std::deque<std::vector<int>> m;
	if(a==1){ 
		 m=MaksimalniPodnizoviStepenaDvojke(v, Rastuci);
		 std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	}
	else{
		m=MaksimalniPodnizoviStepenaDvojke(v,Opadajuci);
	    std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	}
	for(int i(0);i<m.size();i++){
		for(int j(0);j<m.at(i).size();j++){
			std::cout<<m.at(i).at(j)<<" ";
		}
		std::cout<<std::endl;
	}
	
	return 0;
}