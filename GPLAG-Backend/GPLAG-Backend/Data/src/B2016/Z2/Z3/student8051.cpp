#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
// Prije nego sto krenete provjeravati kod, zelim da kazem da je kod "jako mrljavo" i "traljavo" napisan. Kod je napisan u preko 250 linija, mada sam svjestan da se moze puno krace i efikasnije napisati.
bool prost (long long int k)    //	Funkcija koja mi govori da li je broj prost ili ne.
{
	if(k==1)
		return false;
 auto  kor(sqrt(k));
	for(long long int i=2;i<=kor;i++)
		if(k%i==0)
			return false;
	return true;
}
int SumaCifara(long long int n)		//	Funkcija racuna sumu cifara broja koji je poslat kao parametar. 
{
	int s(0);
	while(n!=0)
	{
		s+=abs(n%10);
		n/=10;
	}
	return s;
}
int BrojSavrsenihDjelilaca(long long int f){	//	Funkcija koja salje broj savrsenih djelilaca nekog broja. 
	long long int k(4);
	int  s(0);
	do
	{
		if(prost(k-1))	
		{
			if(f%(k*(k-1)/2)==0)
				s++;
		}
		k*=2;
		
	}while(k<=f);
	return s;
}

int SumaDjelilaca(long long int p){		//	Funkcija koja racuna sumu svih djelilaca nekog broja poslan kao parametar.
	if(p==0)
		return 0;
	if(p==1||p==-1)
		return 1;
	long long int s(abs(p)+1);
	for(long long int i=2;i<=abs(p/2);i++)
	{
		if(p%i==0)
			s+=i;
	}
	return s;
}
int BrojProstihFaktora(long long int f)		//	Sam naziv ove funkcije govori sta se radi.
{
	if(prost(f))
		return 1;
	int s(0);
	long long int k=2,p(f);
	while(k<=abs(f/2))
	{
		if(!prost(k))
		{
			k+=2;
		}
		else{
		while(p%k==0)
		{
			s++;
			p/=k;
			p=abs(p);
		}
		if(k==2)
			k++;
		else
			k+=2;
		p=f;
		}
	}
	return s;
}
template<typename tip,typename tip2, typename tip3,typename tip4>
void Unos(std::vector<tip>&v,tip2 const &a, tip3 const &b,tip4 const  &f)	// Funkcija koja vrsi unos clanova u vektor.
{
	v.push_back(a);
	v.push_back(b);
	v.push_back(f);
}
template<typename tip,typename tip2,typename tip3>	//	Kao i prethodna funkcija, samo sa 2 parametra.
void Unos(std::vector<tip>&v, tip2 const  &a, tip3 const &f)
{
	v.push_back(a);
	v.push_back(f);
}

template <typename tip1, typename tip2,typename tip3, typename tip4>
auto UvrnutiPresjek(tip1 poc1, tip1 kr1, tip2 poc2, tip2 kr2, tip3 f(tip4))-> std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>>
{
	std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> v;	//	Matrica v koja se salje kao rezultat. 
	tip1 k1;	// Pokazivaci, odnosno iteratori koji nam sluze za "prolazak" kroz kontenjere koje su nam poslati u funkciju.
	tip2 k2;
	while(poc1!=kr1)
	{
		auto fun(f(*poc1));
		k2=poc2;
		while(k2!=kr2)
		{
			if(f(*k2)==fun)	//	Ukoliko ispunjava uslov, punimo v.
			{
				v.resize(v.size()+1);
				Unos(v.at(v.size()-1),*poc1,*k2,fun);
			}
			k2++;
		}
		poc1++;
	}
	poc1--;
	std::sort(v.begin(),v.end(),[](const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &v1,const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &v2){if(v1.at(2)<v2.at(2)||(v1.at(2)==v2.at(2)&&v1.at(0)<v2.at(0))||(v1.at(2)==v2.at(2)&&v1.at(0)==v2.at(0)&&v1.at(1)<v2.at(1))) return true; else return false; }); //Jedna jaaako duga linija koja nam sluzi za sortiranje.
	return v;
}

template <typename tip1, typename tip2>	//	Genericka funkcija koja nam sluzi ako se pozove i sa 4 parametra.
auto UvrnutiPresjek(tip1 poc1, tip1 kr1, tip2 poc2, tip2 kr2)-> std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>>
{
	std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> v;
	tip1 k1;
	tip2 k2;
	while(poc1!=kr1)
	{
		k2=poc2;
		while(k2!=kr2)
		{
			if(*k2==*poc1)
			{
				v.resize(v.size()+1);
				Unos(v.at(v.size()-1),*k2,0,0);
			}
			k2++;
		}
		poc1++;
	}
	std::sort(v.begin(),v.end()); //Obicno sortiranje.
	return v;
}

template<typename tip1, typename tip2,typename tip3, typename tip4>
auto UvrnutaRazlika(tip1 poc1, tip1 kr1, tip2 poc2, tip2 kr2, tip3 f(tip4))-> std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>>
{
	std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> v; //	Matrica v u kojoj unosimo trazene vrijednosti.
	tip1 k1(poc1);	//	Analogno prethodnoj funkciji, k1 i k2 su iterator/pokazivaci na elemente kontenjera koji su poslani ovoj generickoj funkciji.
	tip2 k2(poc2);	
	while(k1!=kr1)
	{
		auto p(f(*k1));	//	p je vrijednost elementa iz prvog skupa kroz funkciju. 
		k2=std::find_if(poc2,kr2,[f, p](typename std::remove_reference<decltype(*poc2)>::type a){return f(a)==p;});	//	Trazimo zeljenu vrijednost.
		if(k2==kr2)
		{
			v.resize(v.size()+1);	//	Prosirujemo, pa unosimo.
			Unos(v.at(v.size()-1),*k1,p);
		}
		k1++;
	}
	k2=poc2;
	//Ovdje je isti princip, samo sto gledamo elemente iz drugog skupa sa prvim skupom (prethodno je bilo obrnuto).
	while(k2!=kr2)
	{
		auto p=f(*k2);
		k1=std::find_if(poc1,kr1,[f, p](typename std::remove_reference<decltype(*poc1)>::type a){return f(a)==p;});
		if(k1==kr1)
		{
			v.resize(v.size()+1);
			Unos(v.at(v.size()-1),*k2,f(*k2));
		}
		k2++;
	}
	//	Ovdje sortiramo preko onog zadanog kriterija.
	std::sort(v.begin(),v.end(),[](const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &v1,const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &v2){if(v1.at(0)>v2.at(0)||(v1.at(0)==v2.at(0)&&v1.at(1)>v2.at(1))) return true; else return false; });
	return v;
}
template<typename tip1, typename tip2>	//	Analogno kao i prethodna funkcija, samo ako se posalje 4, a ne 5 parametara.
auto UvrnutaRazlika(tip1 poc1, tip1 kr1, tip2 poc2, tip2 kr2)-> std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>>
{
	std::vector<std::vector<typename std::remove_reference<decltype(*poc1)>::type>> v;
	tip1 k1(poc1);
	tip2 k2(poc2);
	while(k1!=kr1)
	{
		k2=std::find(poc2,kr2,*k1);
		if(k2==kr2)
		{
			v.resize(v.size()+1);
			Unos(v.at(v.size()-1),*k1,0);
		}
		k1++;
	}
	k2=poc2;
	while(k2!=kr2)
	{
		k1=std::find(poc1,kr1,*k2);
		if(k1==kr1)
		{
			v.resize(v.size()+1);
			Unos(v.at(v.size()-1),*k2,0);
		}
		k2++;
	}
	std::sort(v.begin(),v.end(),[](const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &v1,const std::vector<typename std::remove_reference<decltype(*poc1)>::type> &v2){return v1.at(0)>v2.at(0);});
	return v;
}

int main ()			//	Obicni main program, koji vrsi unos elemenata u 2 kontenjera i vrsi pozivanje funkcije. Naravno, ne mogu se unijeti "duplikati".
{															
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";		
	int n;
	std::cin>>n;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::deque<int> d1,d2;
	int k;
	for(int i=0;i<n;i++)
	{
		std::cin>>k;
		auto p=find(d1.begin(),d1.end(),k);
		if(p==d1.end())
			d1.push_back(k);
		else
			i--;
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>n;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0;i<n;i++)
	{
		std::cin>>k;
		auto p=find(d2.begin(),d2.end(),k);
		if(p==d2.end())
			d2.push_back(k);
		else 
			i--;
	}
	std::vector<std::vector<int>> v1{UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara)};
	std::vector<std::vector<int>> v2{UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora)};
	std::cout<<"Uvrnuti presjek kontejnera: "<<std::endl;
	for (const auto& red : v1)
	{
		for (const auto& broj : red)
			std::cout <<std::setw(6)<< broj << " ";
		std::cout << std::endl;
	}
	std::cout <<"Uvrnuta razlika kontejnera: "<< std::endl;
	for (const auto & red : v2)
	{
		for (const auto & broj : red)
			std::cout <<std::setw(6)<< broj << " ";
		std::cout << std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
}