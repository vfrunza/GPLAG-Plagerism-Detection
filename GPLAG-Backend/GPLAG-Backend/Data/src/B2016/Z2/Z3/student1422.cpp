#include <iostream>
#include <vector>
#include <iomanip>
#include <deque>
#include <cmath>

typedef std::deque<int> dek;

int SumaDjelilaca(long long int x){
	int suma(0);
	for(int i=1;i<=x;i++){
		if(x%i==0) suma+=i;
	}
	return suma;
}

int SavrsenDjelilac(long long int x){
	int suma(0);
	for(int i=1;i<x;i++){
		if(x%i==0) suma+=i;
	}
	return suma;
}

bool Prost(int x){
	bool jeste(1);
	for(int i=2;i<x;i++){
		if(x%i==0) jeste=0;
	}
	if(jeste) return true;
	return false;
}

int BrojProstihFaktora(long long int x){
	int brojac(0),pom(0);
	for(int i=2;i<x;i++){
		pom=x%i;
		if(pom==0 && Prost(pom)) brojac++;
	}
	return brojac;
}

int BrojSavrsenihDjelilaca(long long int x){
	int brojac(0);
	for(int i=2;i<x;i++){
		if(x%i==0 && i==SavrsenDjelilac(i)) brojac++;
	}
	return brojac;
}

template<typename IterTip1, typename IterTip2, typename ProizvoljanTip>
std::vector<std::vector<ProizvoljanTip>> UvrnutiPresjek(IterTip1 pocetak1, 
IterTip1 iza_kraja1,IterTip2 pocetak2,IterTip2 iza_kraja2,ProizvoljanTip f(ProizvoljanTip)){
	
	IterTip1 pomocna1(pocetak1);
	IterTip2 pomocna2(pocetak2);
	int n(0);
	//izbrojimo koliko je istih da vidimo koliko ce biti redova
	while(pomocna1!=iza_kraja1){
		while(pomocna2!=iza_kraja2) {
			if(f(*pomocna1)==f(*pomocna2)) n++;
			pomocna2++;
		}
		pomocna2=pocetak2;
		pomocna1++;
	}
	
	
	std::vector<std::vector<ProizvoljanTip>> Matrica;
	Matrica.resize(n);
	pomocna1=pocetak1;
	pomocna2=pocetak2;
	for(int i=0;i<n;i++) Matrica[i].resize(3);
	int brojac_redova(0);
	while(pomocna1!=iza_kraja1){
		while(pomocna2!=iza_kraja2){
			if(f(*pomocna1)==f(*pomocna2)){
				for(int i=brojac_redova;i<brojac_redova+1;i++){
					for(int j=0;j<3;j++){
						if(j==0) Matrica[i][j]=*pomocna1;
						else if(j==1) Matrica[i][j]=*pomocna2;
						else if (j==2) Matrica[i][j]=f(*pomocna1);
					}
						brojac_redova++;
						if(brojac_redova==n) return Matrica;
						break;
				}
			}
			pomocna2++;
		}
		pomocna2=pocetak2;
		pomocna1++;
	}
	
	//sortiranje
	
	
	return Matrica;
}

template<typename IterTip1, typename IterTip2, typename ProizvoljanTip>
std::vector<std::vector<ProizvoljanTip>> UvrnutaRazlika(IterTip1 pocetak1, IterTip1 iza_kraja1,
IterTip2 pocetak2,IterTip2 iza_kraja2,ProizvoljanTip f(ProizvoljanTip)){
	
	IterTip1 pomocna1(pocetak1);
	IterTip2 pomocna2(pocetak2);
	int n(0);
	//izbrojimo sve elemente koji nemaju par
	while(pomocna1!=iza_kraja1){
		bool nadjen(false);
		while(pomocna2!=iza_kraja2){
			if(f(*pomocna1)!=f(*pomocna2)) nadjen=true;
			pomocna2++;
		}
		if(nadjen) n++;
		//pomocna2=pocetak2;
		pomocna1++;
	}
	
	std::vector<std::vector<ProizvoljanTip>> Matrica(0,std::vector<ProizvoljanTip>(0));
	pomocna1=pocetak1;
	pomocna2=pocetak2;
	int i=1;
	while(pomocna1!=iza_kraja1){
		bool nadjen(true);
		while(pomocna2!=iza_kraja2){
			if(f(*pomocna1)==f(*pomocna2)) nadjen=false;
		if(nadjen){
			Matrica.resize(i);
			Matrica[i-1].resize(2);
			std::cout<<"pom1="<<*pomocna1;
			Matrica[i-1][0]=*pomocna1;
			Matrica[i-1][1]=f(*pomocna1);
			i++;
			Matrica.resize(i);
			Matrica[i-1].resize(2);
			Matrica[i-1][0]=*pomocna2;
			Matrica[i-1][1]=f(*pomocna2);
			break;
		}
		pomocna2++;
		}
		pomocna2++;
		pomocna1++;
	}
	return Matrica;
}

template<typename ProizvoljanTip>
int BrojRedova(std::vector<std::vector<ProizvoljanTip>> M){
	return M.size();
}

template<typename ProizvoljanTip>
int BrojKolona(std::vector<std::vector<ProizvoljanTip>> M){
	if(M.size()==0) return 0;
	return M[0].size();
}

template<typename ProizvoljanTip>
void Ispisi(std::vector<std::vector<ProizvoljanTip>> M){
	for(int i=0;i<BrojRedova(M);i++){
		for(int j=0;j<BrojKolona(M);j++)
			std::cout<<std::setw(4)<<M[i][j];
			std::cout<<std::endl;
	}
}

int Suma(int x){
	int suma(0),pom(0);
	do{
		pom=x%10;
		suma+=pom;
		x/=10;
	}while(x!=0);
	return suma;
}

int main () {
	/*int br_el1;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>br_el1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	int pom1;
	dek d1(0);
	for(int i=0;i<br_el1;i++){
		std::cin.clear();
		std::cin.ignore(20,'\n');
		std::cin>>pom1;
		d1.push_back(pom1);
	}
	
	int br_el2;
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>br_el2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	int pom2;
	dek d2(0);
	for(int i=0;i<br_el2;i++){
		std::cin.clear();
		std::cin.ignore(20,'\n');
		std::cin>>pom2;
		for(int x:d1) {
			if(x==pom2) {
				break;
			}
			//else i--;
		}
	}
	
	std::cout<<"Prvi dek: ";
	for(int x:d1) std::cout<<x<<" ";
	std::cout<<std::endl;
	std::cout<<"Drugi dek: ";
	for(int a:d2) std::cout<<a<<" ";*/
	std::vector<int> v{21,22,23},v2{12,44,32};
	std::vector<std::vector<int>> M1(UvrnutiPresjek(v.begin(),v.end(),v2.begin(),v2.end(),Suma));
	Ispisi(M1);
	std::cout<<std::endl;
	std::vector<std::vector<int>> M2(UvrnutaRazlika(v.begin(),v.end(),v2.begin(),v2.end(),Suma));
	Ispisi(M2);
	return 0;
}