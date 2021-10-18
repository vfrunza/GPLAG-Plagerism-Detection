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

long long int Prosti(long long int n){
	
	if(n<0) n=-n;
	if(n==1 || n==0 ) return 2;
	if(n==2) return 1;
	for(int i=2; i<n; i++){
		if(n%i==0) return 0;
	}
	return 1;
}
long long int Stepen(long long int n){
	long long int pom=1; 
	if(n==0) return 1;
	for(int i=0; i<n; i++) pom*=10;
	return pom;
}
int BrCifara(long long int n){
	if(n<0) n=-n;
	int br=0;
	if(n==0) return 1;
	while(n!=0){
		n/=3;
		br++;
	}
	return br;
}
long long int Ternarni(long long int n){
	long long int pom1=0,pom2(n);
	int br(BrCifara(n));
	if(n<0) pom2=-n;
	for(int i=0; i<br; i++){
		auto m=pom2%3;
		pom2/=3;
		auto s=Stepen(i);
		pom1+=m*s;
	}
	return pom1;
}
int Simetricni(long long int n){
	long long int t(Ternarni(n));
	int br(BrCifara(n));
	while(t!=0){
		auto a=t%10;
		auto s=Stepen(br-1);
		auto b=t/s;
		if(a!=b) return 0;
		t=t-b*s;
		t/=10;
		if(t<10) break;
		br-=2;
	}
	return 1;
}
std::vector<int> IzdvojiSimetricneTernare(std::vector<int> v1, bool t){
	std::vector<int> v2;
	if(v1.size()==0) return v2;
	for(int i=0; i<v1.size(); i++){
		if( Simetricni(v1.at(i))==1 && t==Prosti(v1.at(i))){
			if(v2.size()>0){
				int c(0);
				for(int j=0; j<v2.size(); j++){
					if(v2.at(j)==v1.at(i)) c=1;
				}
				if(c==0) v2.push_back(v1.at(i));
				c=0;
			}
			else v2.push_back(v1.at(i));
		}
	}
	return v2;
}
int main ()
{
	/*int c;
	std::cout<<"Unesi: ";
	std::cin>>c;
	std::cout<<Simetricni(c);
	bool t;
	std::cin>>t;
	if(t==true) std::cout<<"da";
	else std::cout<<"ne";*/
	std::vector<int> v;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	int broj(0);
	while(broj!=-1){
		std::cin>>broj; 
		if(broj!=-1) v.push_back(broj);
	}
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	bool t;
	int a;
	for(;;){
	std::cin>>a;
	if(a==1) break;
	if(a==0) break;
	std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	if(a==1) t=true;
	else if(a==0) t=false;
	std::vector<int> v2=IzdvojiSimetricneTernare(v,t);
	if(v2.size()==0){
		if(t) std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
	}
	else{
	if(t) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
	else std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
	for(int i=0; i<v2.size(); i++){
		if(i!=v2.size()-1) std::cout<<v2.at(i)<<", ";
		else std::cout<<v2.at(i)<<".";
	}
	}
	return 0;
}