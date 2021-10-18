#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<deque>
#include<iomanip>
#include<cstdlib>
#define remref std::remove_reference
template<typename T>
auto fun(T a) -> T
{
	return a;
}
template<typename T1,typename T2,typename F1,typename F2>
auto UvrnutiPresjek(T1 it1, T1 it2,T2 it3,T2 it4, F1 fun(F2) ) -> std::vector<std::vector<typename remref<decltype(*it1)> ::type> >
{
	typedef typename remref<decltype(*it1)>::type Tip;
	std::vector<std::vector<Tip> > v;
	
	auto iter1 = it1;
	auto iter3 = it3;
	while(iter1 != it2)
	{
		iter3 = it3;
		
		while(iter3!=it4)
		{
			if(fun(*iter1) == fun(*iter3))
			{
				if(std::count(v.begin(),v.end(),std::vector<Tip>{*iter1,*iter3,fun(*iter1)}) == 0) v.push_back(std::vector<Tip>{*iter1,*iter3,fun(*iter1)});
			}
			iter3++;
		}
		iter1++;
	}
	sort(v.begin(),v.end(),[](std::vector<Tip> a,std::vector<Tip> b){
	return a[2]<b[2] || (a[2]==b[2] && a[0]<b[0]) || (a[2]==b[2] && a[0]==b[0] && a[1]<b[1]);	
	});
	return v;
}

template<typename T1,typename T2>
auto UvrnutiPresjek(T1 it1, T1 it2,T2 it3,T2 it4) -> std::vector<std::vector<typename remref<decltype(*it1)> ::type> >
{
	typedef typename remref<decltype(*it1)>::type Tip;
	std::vector<std::vector<Tip> > v;
	
	auto iter1 = it1;
	auto iter3 = it3;
	while(iter1 != it2)
	{
		iter3 = it3;
		
		while(iter3!=it4)
		{
			if(fun(*iter1) == fun(*iter3))
			{
				if(std::count(v.begin(),v.end(),std::vector<Tip>{*iter1,*iter3,fun(*iter1)}) == 0) v.push_back(std::vector<Tip>{*iter1,Tip(),Tip()});
			}
			iter3++;
		}
		iter1++;
	}
	sort(v.begin(),v.end(),[](std::vector<Tip> a,std::vector<Tip> b){
	return a[2]<b[2] || (a[2]==b[2] && a[0]<b[0]) || (a[2]==b[2] && a[0]==b[0] && a[1]<b[1]);	
	});
	return v;
}


int SumaCifara(long long a)
{
	if(a==0) return a;
	return abs(a%10) + SumaCifara(a/10);
}
template<typename T1,typename T2,typename F1,typename F2>
auto UvrnutaRazlika(T1 it1, T1 it2,T2 it3,T2 it4, F1 fun(F2) ) -> std::vector<std::vector<typename remref<decltype(*it1)> ::type> >
{
	typedef typename remref<decltype(*it1)>::type Tip;
	std::vector<std::vector<Tip> > v;
	auto iter1 = it1;
	auto iter3 = it3;
	while(iter1 != it2)
	{
		bool ima = false;
		iter3 = it3;
		while(iter3!=it4)
		{
			if(fun(*iter3) == fun(*iter1) ) ima = true;
			iter3++;
		}
		if(!ima && std::count(v.begin(),v.end(),std::vector<Tip>{*iter1,fun(*iter1)}) == 0) v.push_back({*iter1,fun(*iter1)});
		iter1++;
	}
	iter3 = it3;
	while(iter3!=it4)
	{
		iter1 = it1;
		bool ima = false;
		while(iter1!=it2)
		{
			if(fun(*iter1) == fun(*iter3)) ima = true;
			iter1++;
		}
		if(!ima && std::count(v.begin(),v.end(),std::vector<Tip>{*iter3,fun(*iter3)}) == 0) v.push_back({*iter3,fun(*iter3)});
		iter3++;
	}
	sort(v.begin(),v.end(),[](std::vector<Tip> a,std::vector<Tip> b){
		return a[0]>b[0] || (a[0]==b[0] && a[1]>b[1]);
	});
	return v;
}
template<typename T1,typename T2>
auto UvrnutaRazlika(T1 it1, T1 it2,T2 it3,T2 it4) -> std::vector<std::vector<typename remref<decltype(*it1)> ::type> >
{
	typedef typename remref<decltype(*it1)>::type Tip;
	std::vector<std::vector<Tip> > v;
	auto iter1 = it1;
	auto iter3 = it3;
	while(iter1 != it2)
	{
		bool ima = false;
		iter3 = it3;
		while(iter3!=it4)
		{
			if(fun(*iter3) == fun(*iter1) ) ima = true;
			iter3++;
		}
		if(!ima && std::count(v.begin(),v.end(),std::vector<Tip>{*iter1,fun(*iter1)}) == 0) v.push_back({*iter1,0});
		iter1++;
	}
	iter3 = it3;
	while(iter3!=it4)
	{
		iter1 = it1;
		bool ima = false;
		while(iter1!=it2)
		{
			if(fun(*iter1) == fun(*iter3)) ima = true;
			iter1++;
		}
		if(!ima && std::count(v.begin(),v.end(),std::vector<Tip>{*iter3,fun(*iter3)}) == 0) v.push_back({*iter3,0});
		iter3++;
	}
	sort(v.begin(),v.end(),[](std::vector<Tip> a,std::vector<Tip> b){
		return a[0]>b[0] || (a[0]==b[0] && a[1]>b[1]);
	});
	return v;
}



int BrojProstihFaktora(long long int a)
{
	int cnt=0;
	while(a!=1 && a!=0)
	{
		for(int i=2;;i++)
		{
			if(i>std::abs(a/i))
			{
				a=1;
				cnt++;
				break;
			}
			if(a%i == 0 )
			{
				cnt++;
				a/=i;
				break;
			}
		}
	}
	return cnt;
}
bool jeLiSavrsen(long long x)
{
	if(x<1) return false;
	long long suma = 0;
	for(int i=1;;i++)
	{
		if(x/i<=i) break;
		if(x%i == 0) suma+=i;
	   	if(x%i == 0) suma+=x/i;
	}
	return suma == 2*x;
}
int BrojSavrsenihDjelilaca(long long a)
{
	int cnt=0;
	a = std::abs(a);
	for(int i=1;i<=a;i++) if(a%i==0 && jeLiSavrsen(i)) cnt++;
	return cnt;
}
int SumaDjelilaca(long long a)
{
	int s=0;
	a = std::abs(a);
	for(int i=1;i<=a;i++) if(a%i==0) s+=i;
	return s;
}
int main ()
{
	std::vector<int> S1;
	std::deque<int> S2;
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int N1,N2,a;
	std::cin>>N1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	for(int i=0;i<N1;i++)
	{
		std::cin>> a;
	   if(std::count(S1.begin(),S1.end(),a)==0)	S1.push_back(a);
		else i--;
	}
	
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>N2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0;i<N2;i++)
	{
		std::cin>> a;
		if(std::count(S2.begin(),S2.end(),a)==0)	S2.push_back(a);
		else i--;
	}
//
	std::cout<<"Uvrnuti presjek kontejnera:\n";
	auto vv = UvrnutiPresjek(S1.begin(),S1.end(),S2.begin(),S2.end(),SumaCifara);
	for(auto e:vv) std::cout<<std::setw(6)<<e[0]<<" "<<std::setw(6)<<e[1]<<" "<<std::setw(6)<<e[2]<<" \n";
	std::cout<<"Uvrnuta razlika kontejnera:\n";
    vv = UvrnutaRazlika(S1.begin(),S1.end(),S2.begin(),S2.end(),BrojProstihFaktora);
	for(auto e:vv) std::cout<<std::setw(6)<<e[0]<<" "<<std::setw(6)<<e[1]<<" \n";
	std::cout<<"Dovidjenja!";
	return 0;
}