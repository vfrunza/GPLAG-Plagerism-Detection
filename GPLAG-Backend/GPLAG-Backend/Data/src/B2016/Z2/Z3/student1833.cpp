/*B 16/17, Zadaća 2, Zadatak 3

	NAPOMENA: i javni ATo-vi su dio postavke

	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba

*/
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include<functional>
#include<iomanip>
#include <deque>
//template<typename tip>
template <typename IterTip1, typename IterTip2>
auto UvrnutiPresjek(IterTip1 a1, IterTip1 a2,IterTip2 b1, IterTip2 b2) ->std::vector<std::vector<decltype(*a1+*b1)>>{
	IterTip1 a11=a1;
	IterTip2 b11=b1;
	std::vector<IterTip1> prva;
	std::vector<IterTip2> druga;
	std::vector<decltype(*a1+*b1)> funkcija;

while(a1!=a2) {
	auto b1p=b1;
	while(b1p!=b2)
	{
		if(*a1==*b1p)
		{

			prva.push_back(a1);
			funkcija.push_back(0);
		}
		b1p++;
	}
	a1++;
}
std::vector<std::vector<decltype(*a11+*b11)>> niz(funkcija.size(), std::vector<decltype(*a11+*b11)>(3));;
for(int i=0;i<funkcija.size();i++)
{
	niz[i][0]=*(prva[i]);
	niz[i][1]=0;
	niz[i][2]=funkcija[i];
}
std::sort(niz.begin(),niz.end(),[](std::vector<decltype(*a11+*b11)> niz1,std::vector<decltype(*a11+*b11)> niz2)->bool
{
	if(niz1[2]<niz2[2]) return true;
	else if(niz1[2]>niz2[2]) return false;
	else
	{
	if(niz1[0]<niz2[0]) return true;
	else if(niz1[0]>niz2[0]) return false;
	else
	{
		if(niz1[1]<niz2[1]) return true;
	else if(niz1[1]>niz2[1]) return false;
	}
	}
}

);
return niz;
}





template <typename IterTip1, typename IterTip2,typename tip1>
auto UvrnutiPresjek(IterTip1 a1, IterTip1 a2,IterTip2 b1, IterTip2 b2,tip1 f) ->std::vector<std::vector<decltype(*a1+*b1)>>{
	IterTip1 a11=a1;
	IterTip2 b11=b1;
	std::vector<IterTip1> prva;
	std::vector<IterTip2> druga;
	std::vector<decltype(*a1+*b1)> funkcija;

while(a1!=a2) {
	auto b1p=b1;
	while(b1p!=b2)
	{
		if(f(*a1)==f(*b1p))
		{
			prva.push_back(a1);
			druga.push_back(b1p);
			funkcija.push_back(f(*a1));
		}
		b1p++;
	}
	a1++;
}
std::vector<std::vector<decltype(*a11+*b11)>> niz(funkcija.size(), std::vector<decltype(*a11+*b11)>(3));;
for(int i=0;i<funkcija.size();i++)
{
	niz[i][0]=*(prva[i]);
	niz[i][1]=*(druga[i]);
	niz[i][2]=funkcija[i];
}
std::sort(niz.begin(),niz.end(),[](std::vector<decltype(*a11+*b11)> niz1,std::vector<decltype(*a11+*b11)> niz2)->bool
{
	if(niz1[2]<niz2[2]) return true;
	else if(niz1[2]>niz2[2]) return false;
	else
	{
	if(niz1[0]<niz2[0]) return true;
	else if(niz1[0]>niz2[0]) return false;
	else
	{
		if(niz1[1]<niz2[1]) return true;
	else if(niz1[1]>niz2[1]) return false;
	}
	}
});
return niz;
}

































template <typename IterTip1, typename IterTip2>
auto UvrnutaRazlika(IterTip1 a1, IterTip1 a2,IterTip2 b1, IterTip2 b2) ->std::vector<std::vector<decltype(*a1+*b1)>>{
	IterTip1 a11=a1,apom=a1;
	IterTip2 b11=b1,bpom=b1;
	std::vector<IterTip1> prva;
	std::vector<decltype(*a1+*b1)> funkcija;

while(a1!=a2) {
	auto b1p=b1;
	bool postoji=false;
	while(b1p!=b2)
	{
		if(*a1==*b1p)
		{
postoji=true;
		}
		b1p++;
	}
	if(!postoji)
	{
		prva.push_back(a1);
	}
	a1++;
}

while(bpom!=b2) {
	auto a1p=apom;
	bool postoji=false;
	while(a1p!=a2)
	{
		if(*bpom==*a1p)
		{
postoji=true;
		}
		a1p++;
	}
	if(!postoji)
	{
		prva.push_back(bpom);
	}
	bpom++;
}






std::vector<std::vector<decltype(*a11+*b11)>> niz(prva.size(), std::vector<decltype(*a11+*b11)>(2));;
for(int i=0;i<prva.size();i++)
{
	niz[i][0]=*(prva[i]);
	niz[i][1]=(0);
}
std::sort(niz.begin(),niz.end(),[](std::vector<decltype(*a11+*b11)> niz1,std::vector<decltype(*a11+*b11)> niz2)->bool
{
		if(niz1[0]>niz2[0]) return true;
	else if(niz1[0]<niz2[0]) return false;
	else
	{
		if(niz1[1]>niz2[1]) return true;
	else if(niz1[1]<niz2[1]) return false;
	}
});
return niz;
}





template <typename IterTip1, typename IterTip2,typename tip1>
auto UvrnutaRazlika(IterTip1 a1, IterTip1 a2,IterTip2 b1, IterTip2 b2,tip1 f) ->std::vector<std::vector<decltype(*a1+*b1)>>{
	IterTip1 a11=a1,apom=a1;
	IterTip2 b11=b1,bpom=b1;
	std::vector<IterTip1> prva;
	std::vector<decltype(*a1+*b1)> funkcija;

while(a1!=a2) {
	auto b1p=b1;
	bool postoji=false;
	while(b1p!=b2)
	{
		
		if(f(*a1)==f(*b1p))
		{
			postoji=true;
		}
		b1p++;
	}
	if(!postoji)
	{
		
			prva.push_back(a1);
			funkcija.push_back(f(*a1));
	}
	a1++;
}


while(bpom!=b2) {
	auto a1p=apom;
	bool postoji=false;
	while(a1p!=a2)
	{
		
		if(f(*a1p)==f(*bpom))
		{
			postoji=true;
		}
		a1p++;
	}
	if(!postoji)
	{
		
			prva.push_back(bpom);
			funkcija.push_back(f(*bpom));
	}
	bpom++;
}


std::vector<std::vector<decltype(*a11+*b11)>> niz(prva.size(), std::vector<decltype(*a11+*b11)>(2));;
for(int i=0;i<prva.size();i++)
{
	niz[i][0]=*(prva[i]);
	niz[i][1]=funkcija[i];
}
std::sort(niz.begin(),niz.end(),[](std::vector<decltype(*a11+*b11)> niz1,std::vector<decltype(*a11+*b11)> niz2)->bool
{
		if(niz1[0]>niz2[0]) return true;
	else if(niz1[0]<niz2[0]) return false;
	else
	{
		if(niz1[1]>niz2[1]) return true;
	else if(niz1[1]<niz2[1]) return false;
	}
});
return niz;
}









int SumaCifara(long long int x)
{
	int k=0;
	while(x!=0)
	{
		k=k+x%10;
		x=x/10;
	}
	return k;
}

int SumaDjelilaca(long long int x)
{
	int k=0;
	for(int i=1;i<=x;i++)
	if(x%i==0)
	k+=i;
	return k;
}
bool jeLiProst(long long int x)
{
	if(x==2) return true;
	for(int i=2;i<x/2;i++)
	if(x%i==0) return false;
	return true;
}
int BrojProstihFaktora(long long int x)
{
	int k=0;
	for(int i=2;i<=x;i++)
	{
		if(x%i==0)
		{
			if(jeLiProst(i))
			{
				x=x/i;
				i=1;
			k++;
			}
		}
	}
	return k;
}
bool jeLiJednakZbiruDjelilaca(long long int x)
{
	int k=0;
	for(int i=1;i<x;i++)
	if(x%i==0) k+=i;
	return x==k;
}
int BrojSavrsenihDjelilaca(long long int x)
{
	int k=0;
	for(int i=2;i<=x;i++)
	{
			if(x%i==0 && jeLiJednakZbiruDjelilaca(i))
			{
			k++;
			}
	}
	return k;
}
int main ()
{
	
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int prvi;
	std::cin>>prvi;
	std::deque<int> dek1,dek2;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	std::vector<int> prviDek,drugiDek;
	for(int i=0;i<prvi;i++)
	{
		int p;
		std::cin>>p;
		bool postoji=false;
		for(int j=0;j<dek1.size();j++)
		if(p==dek1[j]) {postoji=true; i--;}
		if(!postoji)
		dek1.push_back(p);
	}
	std::cout<<"Unesite broj elemenata drugog kontejnera: ";
	std::cin>>prvi;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	for(int i=0;i<prvi;i++)
	{
		int p;
		std::cin>>p;
		bool postoji=false;
		for(int j=0;j<dek2.size();j++)
		if(p==dek2[j]) {postoji=true; i--;}
		if(!postoji)
		dek2.push_back(p);
	}


	auto p1=UvrnutiPresjek(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),SumaCifara);
	std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
	
	for(int i=0;i<p1.size();i++)
    {

        for(int j=0;j<3;j++)
        if(j==0)
            std::cout<<std::setw(6)<<p1[i][j];
            else
            std::cout<<std::setw(7)<<p1[i][j];
        std::cout<<" "<<std::endl;
    }
    std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
    auto p2=UvrnutaRazlika(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),BrojProstihFaktora);
    	for(int i=0;i<p2.size();i++)
    {

        for(int j=0;j<2;j++)
            std::cout<<std::setw(6)<<p2[i][j]<<" ";
        std::cout<<std::endl;
    }
    std::cout<<"Dovidjenja!";
    
	return 0;
}

