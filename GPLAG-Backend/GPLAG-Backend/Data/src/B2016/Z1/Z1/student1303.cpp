/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
// prvo pretvori broj u bazu 3
//napravi vektor koji pamti broj svake cifre u broju
//gadni su samo oni kojima se SVE cifre pojavljuju paran ILI neparan broj puta.
//
#include <iostream>
#include <vector>

std::vector<int> IzbaciDuple(std::vector<int> novi){
	
	for(int i(0); i<novi.size(); i++){
		
		for(int j(i+1); j<novi.size(); j++){
			
			if (novi.at(i)==novi.at(j)){
				
				novi.erase(novi.begin()+j);
				j--;
				
			}
			
		}
	}
	return novi;
}

bool SveParne(unsigned long long int n){
	int brojac0(0), brojac1(0), brojac2(0); //pravimo tri brojaca od kojih svaki pamti broj cifara 0, 1 ili 2
	do{
		int cifra=(n%10);
		if(cifra==0) brojac0++;
		else if(cifra==1) brojac1++;
		else if(cifra==2) brojac2++;
		n/=10;
	}while(n!=0);
	if(brojac0%2==0 && brojac1%2==0 && brojac2%2==0) return true;
	else return false;
	
}
bool SveNeparne(unsigned long long int n){
	int brojac0(0), brojac1(0), brojac2(0); //pravimo tri brojaca od kojih svaki pamti broj cifara 0, 1 ili 2
	do{
		int cifra=(n%10);
		if(cifra==0) brojac0++;
		else if(cifra==1) brojac1++;
		else if(cifra==2) brojac2++;
		n/=10;
	}while(n!=0);
	if( (brojac0==0 || brojac0%2==1) && (brojac1==0 || brojac1%2==1) && (brojac2==0 || brojac2%2==1) ) return true;
	else return false;
	
}

unsigned long long int PretvoriUBazuTri(int n){
	std::vector<int> a;
	while(n!=0){
		int ostatak;
		ostatak= abs((n%3));
		a.push_back(ostatak);
		n/=3;
	}
	long long int b(0), tezina(1);
	for(int i(0); i<a.size(); i++){
		
		b+=(a.at(i)*tezina);
		tezina*=10;
	}
	return b;
}


std::vector<int> IzdvojiGadne (std::vector<int> v, bool x){
	
	std::vector<unsigned long long int> terca;  //vektor terca je pocetni vektor u ternarnom zapisu
	std::vector<int> novi ;     
	
	for(int i(0); i<v.size(); i++){
		terca.push_back(PretvoriUBazuTri(v.at(i)));
	}
	
	for(int i(0); i<terca.size(); i++){
		
		if(x){
			if(SveParne(terca.at(i))) novi.push_back(v.at(i));
		}
		
		else{
			if(SveNeparne(terca.at(i))) novi.push_back(v.at(i));
		}
	}
	novi=IzbaciDuple(novi);
	return novi;
}


int main ()
{
	std::vector<int>v;
	
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int n;
	do{
		std::cin>>n;
		if(n!=0) v.push_back(n);
		
	}while(n!=0);
	
	std::vector<int>novi ;
	novi=IzdvojiGadne(v, true);
	std::cout<<"Opaki: ";
	for(int i(0); i<novi.size(); i++){
		std::cout<<novi.at(i)<<" ";
	}
	novi=IzdvojiGadne(v, false);
	std::cout<<"\nOdvratni: ";
	for(int i(0); i<novi.size(); i++){
		std::cout<<novi.at(i)<<" ";
	}
	return 0;
}
