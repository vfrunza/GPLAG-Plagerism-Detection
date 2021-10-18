/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/


#include<iostream>
#include<vector>
#include <deque>
#include<string>
#include <iomanip>
#include <cmath>
#include <algorithm>
template <typename nekitip1,typename nekitip2,typename nekitip3,typename nekitpi4>

auto UvrnutiPresjek(nekitip1 prvi_pocetak,nekitip1 prvi_kraj,nekitip2 drugi_pocetak,nekitip2 drugi_kraj,nekitip3 funkcija(nekitpi4))->std::vector<std::vector<typename std::remove_reference<decltype(prvi_pocetak[0])>::type>>                           
{
	int broj=0;
	using Tip=typename std::remove_reference<decltype (prvi_pocetak[0])>::type;
	typedef Tip niz_tip[3];
	std::vector<std::vector<Tip>>vrati;
	for(auto i=prvi_pocetak;i<prvi_kraj;i++)
	{	
		
		for(auto j=drugi_pocetak;j<drugi_kraj;j++)
		{
			if(funkcija(*i)==funkcija(*j))
			{	broj++;
				vrati.resize(broj);
				vrati[broj-1].resize(3);
				vrati[broj-1][0]=*i;
				vrati[broj-1][1]=*j;
				vrati[broj-1][2]=funkcija(*i);
			}
		}
	}
	sort(vrati.begin(),vrati.end(),[] (std::vector<Tip> v1,std::vector<Tip> v2)
	{
		if(v1[2]<v2[2])
		return true;
		
		if(v1[2]==v2[2])
		{
			if(v1[0]==v2[0])
			if(v1[1]<v2[1])
			return true;
			if(v1[0]<v2[0])
			return true;
			
			
		}
		
		return false;
		
		
	});
	return vrati;
}

template<typename nekitip1,typename nekitip2>
auto UvrnutiPresjek(nekitip1 prvi_pocetak,nekitip1 prvi_kraj,nekitip2 drugi_pocetak,nekitip2 drugi_kraj)->std::vector<std::vector<typename std::remove_reference<decltype(prvi_pocetak[0])>::type>>
{
	using Tip=typename std::remove_reference<decltype(prvi_pocetak[0])>::type;
	std::vector<std::vector<Tip>> vrati;
	bool nalazi_se=false;
	int broj_redova=0;
	while (prvi_pocetak<prvi_kraj) 
	{
		nalazi_se=false;
		auto temp=drugi_pocetak;
		while (temp<drugi_kraj)
		{
			if(*prvi_pocetak==*temp)
			nalazi_se=true;
			temp++;
		}
		
		if(nalazi_se==true)
		{
			vrati.resize(broj_redova+1);
			vrati[broj_redova].resize(3);
			vrati[broj_redova][0]=*prvi_pocetak;
			broj_redova++;
		}
		prvi_pocetak++;
	}
	
	sort(vrati.begin(),vrati.end(),[](std::vector<Tip> v1,std::vector<Tip> v2){
		if(v1[0]<v2[0])
		return true;
		return false;
	});
	return vrati;

}

template <typename nekitip1,typename nekitip2>
auto UvrnutaRazlika(nekitip1 prvi_pocetak,nekitip1 prvi_kraj,nekitip2 drugi_pocetak,nekitip2 drugi_kraj)-> std::vector<std::vector<typename std::remove_reference<decltype(prvi_pocetak[0])>::type>>
{
	using Tip= typename std::remove_reference<decltype(prvi_pocetak[0])>::type;
	bool nalazi_se=false;
	std::vector<std::vector<Tip>> vrati;
	auto prvi=prvi_pocetak;
	int broj_redova=0;
	while (prvi<prvi_kraj)
	{
		nalazi_se=false;
		auto drugi=drugi_pocetak;
		while (drugi<drugi_kraj)
		{
			if(*prvi==*drugi)
			{
				nalazi_se=true;
			}
			drugi++;
		}
		if(nalazi_se==false)
		{
			vrati.resize(broj_redova+1);
			vrati[broj_redova].resize(2);
			vrati[broj_redova][0]=*prvi;
			broj_redova++;
		}
		
		prvi++;
	}
	while (drugi_pocetak<drugi_kraj)
	{	nalazi_se=false;
		auto temp=prvi_pocetak;
		while (temp<prvi_kraj)
		{
			if(*drugi_pocetak==*temp)
			nalazi_se=true;
			temp++;
		}
		if(nalazi_se==false)
		{
			vrati.resize(broj_redova+1);
			vrati[broj_redova].resize(2);
			vrati[broj_redova][0]=*drugi_pocetak;
			broj_redova++;
		}
	drugi_pocetak++;	
	}
	sort(vrati.begin(),vrati.end(),[](std::vector<Tip>v1,std::vector<Tip>v2){
		if(v1[0]>=v2[0])
		return true;
		return false;
		
	});
	return vrati;
	
	
}
template <typename nekitip1,typename nekitip2,typename nekitip3,typename nekitpi4>

auto UvrnutaRazlika(nekitip1 prvi_pocetak,nekitip1 prvi_kraj,nekitip2 drugi_pocetak,nekitip2 drugi_kraj,nekitip3 funkcija(nekitpi4))->std::vector<std::vector<typename std::remove_reference<decltype(prvi_pocetak[0])>::type>>
{	
	

	int broj_redova=0;
	using Tip=typename std::remove_reference<decltype(prvi_pocetak[0])>::type;
	std::vector<std::vector<Tip>> vrati;
	for(auto i=prvi_pocetak;i<prvi_kraj;i++)
	{
		int isti=0;
		for(auto j=drugi_pocetak;j<drugi_kraj;j++)
		{
			if(funkcija(*i)==funkcija(*j))
			isti++;
		}
		if(isti==0)
		{	broj_redova++;
			vrati.resize(broj_redova);
			vrati[broj_redova-1].resize(2);
			vrati[broj_redova-1][0]=*i;
			vrati[broj_redova-1][1]=funkcija(*i);
		}
		
		
		
	}
	
		for(auto i=drugi_pocetak;i<drugi_kraj;i++)
	{
		int isti=0;
		for(auto j=prvi_pocetak;j<prvi_kraj;j++)
		{
			if(funkcija(*i)==funkcija(*j))
			isti++;
		}
		if(isti==0)
		{	broj_redova++;
			vrati.resize(broj_redova);
			vrati[broj_redova-1].resize(2);
			vrati[broj_redova-1][0]=*i;
			vrati[broj_redova-1][1]=funkcija(*i);
		}
		
		
		
	}
		sort(vrati.begin(),vrati.end(),[] (std::vector<Tip> v1,std::vector<Tip> v2)
	{
		if(v1[0]>v2[0])
		return true;
		
		if(v1[0]==v2[0])
		{
			if(v1[1]>v2[1])
			return true;
			return false;
		}
		
		return false;
		
		
	});
	return vrati;
	
}
int suma_cifara(long long int broj)
{
	broj=fabs(broj);
	int vrati=0;
	do{
	vrati=vrati+broj%10;
	broj=broj/10;
		
	}while (broj>0); 
	return vrati;
}
bool da_li_je_djelilac(long long int broj,long long int djelilac)
{
	broj=fabs(broj);
	
	if(broj%djelilac==0)
	return true;
	
	return false;
}


int SumaDjelilaca(long long int broj)
{
	int suma=0;
	broj=fabs(broj);
	for(long long int i=1;i<=broj;i++)
	{
		if(da_li_je_djelilac(broj,i)==true)
		suma=suma+i;
	}
	return suma;
}

bool prost_broj(long long int n)
{
	if(n<=1)
	return false;
	
	for(long long int i=2;i<n;i++)
	if(n%i==0)
	return false;
	
	return true;
}

int BrojProstihFaktora(long long int broj)
{
	int suma=0;
	long long int i=2;
	while (i<=broj) {
		while (prost_broj(i)==false) {
			i++;
			
		}
		if(i>broj)
		return suma;
		while (broj%i==0) {
			suma++;
			broj=broj/i;
			if(broj<=1)
			return suma;
		}
		if(broj<=1)
		return suma;
		i++;
	}
	return suma;
}
bool savrene_broj(long long int broj)
{
	if(broj<=1)
	return false;
	int suma=1;
	for(long long int i=2;i<broj;i++)
	{
		if(broj%i==0 )
		{suma=suma+i;
		
			
		}
	}
	if(suma==broj)
	return true;
	
	return false;
	
}
int BrojSavrsenihDjelilaca(long long int broj)
{
	int vrati=0;
	for(long long int i=2;i<=broj;i++)
	{
		if(da_li_je_djelilac(broj,i)==true && savrene_broj(i)==true)
		vrati++;
	}
	return vrati;
	
}


int main ()

{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int broj_prvog;
	std::cin>>broj_prvog;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int> v1;
	for(int i=0;i<broj_prvog;i++)
	{
		int broj;
		std::cin>>broj;
		bool ponavlja=false;
		
			for(int j=0;j<i;j++)
			if(v1[j]==broj)
			ponavlja=true;
		
		if(ponavlja==false)
		v1.push_back(broj);
		if(ponavlja==true)
		i--;
	}

	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	int broj_drugog;
	std::cin>>broj_drugog;
	std::deque<int> v2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	
	for(int i=0;i<broj_drugog;i++)
	{int broj;
	std::cin>>broj;
	bool ponavlja=false;
	for(int j=0;j<i;j++)
	if(v2[j]==broj)
	ponavlja=true;
	if(ponavlja==false)
	v2.push_back(broj);
	if(ponavlja==true)
	i--;
	}
	
	std::cout<<"Uvrnuti presjek kontejnera:\n";
	std::vector<std::vector<int>> uvrnuti=UvrnutiPresjek(v1.begin(),v1.end(),v2.begin(),v2.end(),suma_cifara);
	for(int i=0;i<uvrnuti.size();i++)
	{
		for(int j=0;j<uvrnuti[i].size();j++)
		std::cout<<std::setw(6)<<uvrnuti[i][j]<<" ";
		std::cout<<"\n";
	}
	std::vector<std::vector<int>> razlika=UvrnutaRazlika(v1.begin(),v1.end(),v2.begin(),v2.end(),BrojProstihFaktora);
	std::cout<<"Uvrnuta razlika kontejnera:\n";
	for(int j=0;j<razlika.size();j++)
	{
		for(int i=0;i<razlika[j].size();i++)
		std::cout<<std::setw(6)<<razlika[j][i]<<" ";
		std::cout<<"\n";
	}
	std::cout<<"Dovidjenja!";
	return 0;
}