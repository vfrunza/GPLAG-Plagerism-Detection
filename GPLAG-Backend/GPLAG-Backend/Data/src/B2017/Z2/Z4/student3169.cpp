/*B 2017/2018, Zadaća 2, Zadatak 4
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <type_traits>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <deque>
#include <string>
#include <limits>

long long int BrojProstihFaktora(int n)
{
	long long int brojac(0);
	if(n<=1)return brojac;
	long long int a(2);
//	while(n!=1)
while(a*a<=n) //i dodati brojac++
	{
		if(n%a==0)
		{
			brojac++;
			n/=a;
		}
		else a++;
	}
	brojac++;
	return brojac;
}

bool Veci(long long int x, long long int y)
{
	if(BrojProstihFaktora(x)==BrojProstihFaktora(y))return x>y;
	return(BrojProstihFaktora(x)>BrojProstihFaktora(y));
}

long long int fun(long long int x,long long int y)
{
	return -2*x+y;
}

template<typename Iter1, typename Iter2, typename Iter3, typename tip1, typename ptip3,typename funtip1, typename funtip2>		  // funtip1 f1    // funtip2 g
void SortirajPodrucjeVrijednosti(Iter1 pocetak1, Iter1 kraj1, Iter2 pocetak2, Iter3 pocetak3, funtip1 f,funtip2 g)
{
	int broj(kraj1-pocetak1);
	std::sort(pocetak1, kraj1, g);
	std::sort(pocetak2, pocetak2+broj, g);
/*	for(int i(0);i<broj;i++)
	{
		int brojac(0);
		for(int j(0);j<broj;j++)
		{

			if(f(*(pocetak1+i),*(pocetak2+i))==*(pocetak3+j))brojac++;
		}
		if(brojac==0)throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
	}
	
	for(int i(0);i<broj;i++)
	{

		for(int j(0);j<broj;j++)
		{
			if(f(*(pocetak1+i),*(pocetak2+i))==*(pocetak3+j))
			{
				if(j!=i)
				{
					auto pomocna=*(pocetak3+i);
					*(pocetak3+i)=*(pocetak3+j);
					*(pocetak3+j)=pomocna;
				}
			}
		}
	}
	*/
	for(int i(0);i<broj;i++)
	{
		int brojac(0);
		for(int j(i);j<broj;j++)
		{

			if(f(*(pocetak1+i),*(pocetak2+i))==*(pocetak3+j))
			{
				brojac++;
				if(j!=i)
				{
					auto pomocna=*(pocetak3+i);
					*(pocetak3+i)=*(pocetak3+j);
					*(pocetak3+j)=pomocna;
				}
			}
		}
		if(brojac==0)throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
	}
	
	
}
int main ()
{
/*	//std::cout<<BrojProstihFaktora(8128);
	try{
	std::cout<<"Unesite broj elemenata: ";
	int broj;
	std::cin>>broj;
	std::vector<int>s1;
	std::cout<<"Unesite elemente prvog vektora: ";
	while(s1.size()!=broj)
	{
		int n;
		std::cin>>n;
		bool f(false);
		for(int i(0);i<s1.size();i++)
		{
			if(s1.at(i)==n)
			{
				f=true;
				break;
			}
		}
		if(!f)s1.push_back(n);
	}
	
	std::vector<int>s2;
	std::cout<<"Unesite elemente drugog vektora: ";
	while(s2.size()!=broj)
	{
		int n;
		std::cin>>n;
		bool f(false);
		for(int i(0);i<s2.size();i++)
		{
			if(s2.at(i)==n)
			{
				f=true;
				break;
			}
		}
		if(!f)s2.push_back(n);
	}
	
	std::vector<int>s3;
	std::cout<<"Unesite elemente treceg vektora: ";
	while(s3.size()!=broj)
	{
		int n;
		std::cin>>n;
		bool f(false);
		for(int i(0);i<s3.size();i++)
		{
			if(s3.at(i)==n)
			{
				f=true;
				break;
			}
		}
		if(!f)s3.push_back(n);
	}	
	std::cout<<std::endl;
	SortirajPodrucjeVrijednosti(s1.begin(),s1.end(),s2.begin(),s3.begin(),fun,Veci);
	std::cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:"<<std::endl;
	for(int i(0);i<broj;i++)
	{
		std::cout<<"f("<<s1.at(i)<<", "<<s2.at(i)<<") = "<<s3.at(i)<<std::endl;
	}
		
	}
	catch(std::logic_error Izuzetak)
	{
		std::cout<<"Izuzetak: "<<Izuzetak.what();
	}*/
	
	 try {
        std::vector<int> v1;
        std::vector<int> v2;
        std::vector<long int> v3 {1,2,3};
        SortirajPodrucjeVrijednosti(v1.begin(),v1.end(),v2.begin(),v3.begin(),
        [] (int a,int b)->long int {return -2*a+b;},
        [] (int a,int b){return a<b;});

        for(int i=0; i<v3.size(); i++) {
            std::cout<<v3[i]<<std::endl;
        }

    }
    catch(std::logic_error e) {
                std::cout<<e.what();
    }
    catch(...){
        std::cout<<"Pogresan tip izuzetka!";
    }
	
	return 0;
}