/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <algorithm>
#include <deque>
#include <cmath>
#include <iomanip>
#include <vector> 
#include <functional>

bool DaLiSePonavlja(std::deque<int> dek, int broj){
	bool ponavljase(false);
	for(int i=0;i<dek.size();i++){
		if(dek[i]==broj){ 
			ponavljase=true;
			break;
		}
	}
	return ponavljase;
}
int SumaDjelilaca(long long int n){
	int suma(0);
	if(n<0) n*=-1;
	for(int i=1;i<=n;i++){
		if(n%i==0) suma+=i;
	}
	return suma;
}
bool DaLiJeProst(int n){
	if(n<=0 || n==1) return false;
	for(int i=((int)std::sqrt(n));i>=2;i--){
		if(n%i==0) return false;
	}
	return true;
}
int BrojProstihFaktora(long long int n){
	int brojac(0);
	if(n<0) n*=-1;
	long long int x(n);
	for(int i=2; i<=n;i++){
		if(DaLiJeProst(i) && x%i==0 && x!=1) 
		{
			brojac++;
		    x/=i;
			i=1;

		}
	}
	return brojac;
}
bool DaLiJeSavrsen(int n){
	int suma=0;
	if(n<0) n*=-1;
	for(int i=1;i<n;i++){
		if(n%i==0) suma+=i;
	}
	if(suma==n) return true;
	else return false;
}

int BrojSavrsenihDjelilaca(long long int n){
	int brojac(0);
	if(n<0) n*=-1;
	for(int i=1;i<=n;i++)
	{
		if(n%i==0 && DaLiJeSavrsen(i)) brojac++;
	}
	return brojac;
}

int SumaCifara (long long int n)
{
	int suma(0);
	if(n<0) n*=-1;
	while(n!=0)
	{
		suma+=n%10;
		n/=10;
	}
	return suma;
}


template <typename Tip1,typename Tip2>
std::vector<std::vector<int> >UvrnutiPresjek(Tip1 p1,Tip1 p2,Tip2 p3,Tip2 p4, std::function<int(long long int)> f = [](double x) {return (int)x;})
{
	Tip2 pomocni_pok=p3;
	std::vector<std::vector<int> >matrica;
	while(p1!=p2)
	{
		
		p3=pomocni_pok;
		while(p3!=p4)
		{
			if(f(*p1)==f(*p3))
			{ 
				std::vector<int> pomocni;
				pomocni.push_back(*p1);
				pomocni.push_back(*p3);
				pomocni.push_back(f(*p1));
				matrica.push_back(pomocni);
			}
			p3++;
		}
		p1++;
	}
	std::sort(matrica.begin(),matrica.end(),[] (std::vector<int> v1, std::vector<int> v2 )
	{
		if(v1[2]<v2[2]) return true;
		else if(v1[2]==v2[2] && v1[0]<v2[0]) return true;
		else if(v1[2]==v2[2] && v1[0]==v2[0] && v1[1]<v2[1]) return true;
		return false;	
	});
	return matrica;
}

template <typename Tip1,typename Tip2>
std::vector<std::vector<int> >UvrnutaRazlika(Tip1 p1,Tip1 p2,Tip2 p3,Tip2 p4, std::function<int(long long int)> f = [](double x) {return (int)x;})
{
	Tip2 pomocni_pok=p3;
	Tip1 pom_p1=p1;
	Tip1 pom_p2=p2;
	Tip2 pom_p3=p3;
	Tip2 pom_p4=p4;
	std::vector<std::vector<int> >matrica;
	while(p1!=p2)
	{
		bool ima_par(false);
		p3=pomocni_pok;
		while(p3!=p4)
		{
			if(f(*p1)==f(*p3))
			{ 
				ima_par=true;
			}
			p3++;
		}
		if(!ima_par) 
		{
			std::vector<int> pomocni ;
			pomocni.push_back(*p1);
			pomocni.push_back(f(*p1));
			matrica.push_back(pomocni);
		}
		p1++;
	}
	p1=pom_p1; p2=pom_p2; p3=pom_p3; p4=pom_p4;
	while(p3!=p4)
	{
		bool ima_par(false);
		p1=pom_p1;
		while(p1!=p2)
		{
			if(f(*p1)==f(*p3))
			{ 
				ima_par=true;
			}
			p1++;
		}
		if(!ima_par) 
		{
			std::vector<int> pomocni ;
			pomocni.push_back(*p3);
			pomocni.push_back(f(*p3));
			matrica.push_back(pomocni);
		}
		p3++;
	}
	
	
	std::sort(matrica.begin(),matrica.end(),[] (std::vector<int> v1, std::vector<int> v2 )
	{
		if(v1[0]==v2[0])
		{
			if(v1[1]>v2[1]) return true;
		}
		else if(v1[0]>v2[0]) return true;
		return false;	
	});
	return matrica;
}

int main ()
{
	int n1,n2,broj1,broj2;
	std::deque<int> dek1,dek2;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	std::cin>>n1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0;i<n1;i++){
		std::cin>>broj1;
		if(!DaLiSePonavlja(dek1,broj1)){ 
			dek1.push_back(broj1);
		}
		else{
			i--;
		}
	}
//	std::cin.clear();
//	std::cin.ignore(9999,'\n'); 
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>n2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0;i<n2;i++){
		std::cin>>broj2;
		if(!DaLiSePonavlja(dek2,broj2)){
			dek2.push_back(broj2);
		}
		else{
			i--;
		}
	}
	//std::cin.clear();
	//std::cin.ignore(9999,'\n'); 
	std::vector<std::vector<int>> matricauvrnutipresjek=UvrnutiPresjek(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),SumaCifara);
	std::vector<std::vector<int>> matricauvrnutarazlika=UvrnutaRazlika(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),BrojProstihFaktora);
	std::cout<<"Uvrnuti presjek kontejnera:\n";
	for(int i=0;i<(int)matricauvrnutipresjek.size();i++)
	{
		for(int j=0;j<1;j++)
		{
			std::cout<<std::setw(6)<<matricauvrnutipresjek[i][0]<<std::setw(7)<<matricauvrnutipresjek[i][1]<<std::setw(7)<<matricauvrnutipresjek[i][2]<<" ";
		}
		std::cout<<"\n";
	}
	std::cout<<"Uvrnuta razlika kontejnera:\n";
	for(int i=0;i<(int)matricauvrnutarazlika.size();i++)
	{
		for(int j=0;j<1;j++)
		{
			std::cout<<std::setw(6)<<matricauvrnutarazlika[i][0]<<std::setw(7)<<matricauvrnutarazlika[i][1];
		}
		std::cout<<"\n";
	}
	std::cout<<"Dovidjenja!";
	return 0;
}