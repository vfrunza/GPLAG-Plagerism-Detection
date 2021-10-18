/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

int SumaDjelilaca (long long int broj) {
	int brojac=0;
	for(long long int i=1; i<=abs(broj); i++) {
		if (abs(broj)%i==0) brojac=brojac+i;
	}
	return brojac;
}

std::vector<long long int> prosti(long long int br) {
	long long int broj=abs(br);
	std::vector<long long int> v;
	for(long long int i=2; i<=broj; i++){
		int m=1;
		for(long long int j=2; j<std::sqrt(i); j++){
			if(i%j==0) m=0; break;
		}
		if(m!=0) v.push_back(i);
	}
	return v;
}
int BrojProstihFaktora (long long int b) {
	long long int broj=abs(b);
	int br=0;
	std::vector<long long int> v=prosti(broj);
	for(long long int m=0; m<v.size(); m++) {
		while(broj%v[m]==0 ) {br++; broj=broj/v[m];}
	}
	return br;
}

bool savrsen(long long int br){
	long long int broj=abs(br);
	long long int suma=0;
	for(long long int i=1; i<broj; i++) {
		if(broj%i==0) suma=suma+i;
	}
	if(suma==broj) return true;
	else return false;
}
int BrojSavrsenihDjelilaca (long long int br) {
	long long int broj=abs(br);
	int brojac=0;    
	for(long long int i=1; i<=broj; i++) {
		if (broj%i==0 && savrsen(i)==true) {
			brojac++;
		}
	}
	return brojac;
}

int SumaCifara (long long int br) {
	long long int broj=abs(br);
	int suma=0;
	while(broj!=0) {
		int cifra=broj%10;
		broj=broj/10;
		suma=suma+cifra;
	}
	return suma;
}
template <typename itertip1, typename itertip2, typename fun_tip>
std::vector<std::vector<int>> UvrnutiPresjek (itertip1 poc1, itertip1 kraj1, itertip2 poc2, itertip2 kraj2, fun_tip f) {
	std::vector<std::vector<int>> matrica/*(1, std::vector<int>(3))*/;
	int red=0;
	itertip2 p=poc2;
	while (poc1!=kraj1) {
		poc2=p;
		while(poc2!=kraj2) {
			if(f(abs(*poc1))==f(abs(*poc2))) {
				matrica.resize(red+1);
				matrica[red].resize(3);
				matrica[red][0]=*poc1;
				matrica[red][1]=*poc2;
				matrica[red][2]=f(*poc1);
				red++;
			}
			poc2++;
		}
		poc1++;
	}
	std::sort(matrica.begin(), matrica.end(), [](std::vector<int> p1, std::vector<int> p2){
		if(p1[2]==p2[2]) {
			if(p1[0]==p2[0]) {if(p1[1]<p2[1]) return true;}
			return(p1[0]<p2[0]);}
			return(p1[2]<p2[2]);
	});
	return matrica;
}

template <typename itertip1, typename itertip2>
auto UvrnutiPresjek (itertip1 poc1, itertip1 kraj1, itertip2 poc2, itertip2 kraj2) ->std::vector<std::vector<decltype((*poc1+0))>>{
	std::vector<std::vector<decltype((*poc1+0))>>  matrica;
	int red=0;
	itertip2 p=poc2;
	while (poc1!=kraj1) {
		poc2=p;
		while(poc2!=kraj2) {
			if(*poc1==*poc2) {
				matrica.resize(red+1);
				matrica[red].resize(3);
				matrica[red][0]=*poc1;
				matrica[red][1]=0;
				matrica[red][2]=0;
				red++;
			}
			poc2++;
		}
		poc1++;
	}
	std::sort(matrica.begin(), matrica.end(), [](std::vector<int> p1, std::vector<int> p2){
			return(p1[0]<p2[0]);
	});
	return matrica;
}

template <typename itertip1, typename itertip2, typename fun_tip>
std::vector<std::vector<int>> UvrnutaRazlika(itertip1 poc1, itertip1 kraj1, itertip2 poc2, itertip2 kraj2, fun_tip f) {
	std::vector<std::vector<int>> matrica;
	int red=0;
	bool a=false;
	itertip2 p2=poc2;
	itertip1 p1=poc1;
	while (poc1!=kraj1) {
		poc2=p2;
		while(poc2!=kraj2) {
			if(f(abs(*poc1))==f(abs(*poc2))) a=true;
			poc2++;
		}
		if(a==false) {
			matrica.resize(red+1);
			matrica[red].resize(2);
			matrica[red][0]=*poc1;
			matrica[red][1]=f(*poc1);
			red++;
			
		}
		a=false;
		poc1++;
	}
	bool b=false;
	poc1=p1;
	poc2=p2;
	while (poc2!=kraj2) {
		poc1=p1;
		while(poc1!=kraj1) {
			if(f(abs(*poc1))==f(abs(*poc2))) b=true;
			poc1++;
		}
		if(b==false) {
			matrica.resize(red+1);
			matrica[red].resize(2);
			matrica[red][0]=*poc2;
			matrica[red][1]=f(*poc2);
			red++;
		}
		b=false;
		poc2++;
	}
	std::sort(matrica.begin(), matrica.end(), [](std::vector<int> p1, std::vector<int> p2){
		if(p1[0]==p2[0]) {
			return(p1[1]>p2[1]);}
			return(p1[0]>p2[0]);
	});
	return matrica;
}

template <typename itertip1, typename itertip2>
auto UvrnutaRazlika (itertip1 poc1, itertip1 kraj1, itertip2 poc2, itertip2 kraj2) ->std::vector<std::vector<decltype((*poc1)+(*poc1))>>{
	std::vector<std::vector<decltype((*poc1)+(*poc1))>> matrica;
	int red=0;
	bool a=false;
	itertip2 p2=poc2;
	itertip1 p1=poc1;
	while (poc1!=kraj1) {
		poc2=p2;
		while(poc2!=kraj2) {
			if((*poc1)==(*poc2)) a=true;
			poc2++;
		}
		if(a==false) {
			matrica.resize(red+1);
			matrica[red].resize(2);
			matrica[red][0]=*poc1;
			matrica[red][1]=0;
			red++;
			
		}
		a=false;
		poc1++;
	}
	bool b=false;
	poc1=p1;
	poc2=p2;
	while (poc2!=kraj2) {
		poc1=p1;
		while(poc1!=kraj1) {
			if(*poc1==*poc2) b=true;
			poc1++;
		}
		if(b==false) {
			matrica.resize(red+1);
			matrica[red].resize(2);
			matrica[red][0]=*poc2;
			matrica[red][1]=0;
			red++;
		}
		b=false;
		poc2++;
	}
	std::sort(matrica.begin(), matrica.end(), [](std::vector<int> p1, std::vector<int> p2){
			return(p1[0]>p2[0]);
	});
	return matrica;
}

int main ()
{
	int n1;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>n1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int> dek1;
	dek1.resize(n1);
	for(int i=0; i<n1; i++) {
		std::cin>>dek1[i];
		for(int j=0; j<i; j++)
		if(dek1[i]==dek1[j]) i--;
	
	}
	int n2;
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>n2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	std::deque<int> dek2;
	dek2.resize(n2);
	for(int i=0; i<n2; i++) {
		std::cin>>dek2[i];
		for(int j=0; j<i; j++)
		if(dek2[i]==dek2[j]) i--;
	
	}
	auto mat=UvrnutiPresjek(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), SumaCifara);
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat[0].size(); j++)
		std::cout<<std::setw(6)<<mat[i][j]<<" ";
		std::cout<<std::endl;
	}
	auto mat1=UvrnutaRazlika(dek1.begin(), dek1.end(), dek2.begin(), dek2.end(), BrojProstihFaktora);
	std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
	for(int i=0; i<mat1.size(); i++) {
		for(int j=0; j<mat1[0].size(); j++)
		std::cout<<std::setw(6)<<mat1[i][j]<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	
	return 0;
}