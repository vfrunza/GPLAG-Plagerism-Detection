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
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#include <type_traits>
#include <stdexcept>

int funkcija(int x, int y)
{
	return (-2)*x+y;
}

int ProstiFaktori(int broj)
{
	if (broj<2) return 0;
	int i(2);
	int brojac(0);
	do{
		if(broj%i==0)
		{
			brojac++;
			broj=broj/i;
		}
		else
		i++;
	}while(broj!=1);
	
	return brojac;
}

bool Sortiraj(int prvi, int drugi)
{
	int brojac1(0), brojac2(0);

	brojac1=ProstiFaktori(prvi);
	brojac2=ProstiFaktori(drugi);
	
	if(brojac1==brojac2)
	{
		return prvi>drugi;
	}
	else
	return brojac1>brojac2;
}

template <typename Tip1, typename Tip2, typename Tip3>
void SortirajPodrucjeVrijednosti(Tip1 p1, Tip1 p2, Tip2 p3, Tip3 p4, typename std::remove_reference<decltype(*p4)>::type funckija( typename std::remove_reference<decltype(*p1)>::type,  typename std::remove_reference<decltype(*p3)>::type ), bool Sortiraj( typename std::remove_reference<decltype(*p1)>::type,  typename std::remove_reference<decltype(*p1)>::type ) )
{
	int velicina_kontejnera=p2-p1;
	
	std::sort(p1, p2, Sortiraj);
	std::sort(p3, p3+velicina_kontejnera, Sortiraj);
	
	bool ima=false;
	do{
		int razdaljina=p2-p1;
		
		typename std::remove_reference<decltype(*p4)>::type rezultat=funkcija(*p1, *p3);
		Tip3 pomocni=p4;
		
		do{
			if(rezultat==*pomocni)
			ima=true;
			
			pomocni++;
		}while(pomocni!=(p4+velicina_kontejnera));
		
		if(!ima)
		throw std::logic_error("Vrijednost koja odgovara nekom od parova nije nadjena");
		else
		{
			pomocni=std::find(p4, p4+velicina_kontejnera, rezultat);
			std::swap(*pomocni, *(p4+velicina_kontejnera-razdaljina));
		}
		
		ima=false;
		p1++;
		p3++;
	}while(p1!=p2);
	
	/*for(int i=0; i<velicina_kontejnera; i++)
	{
		std::cout<<*p4<<" ";
		p4++;
	}*/
}

void Ubaci(std::vector<int> &S, int br_cl)
{

	for(int i=0; i<br_cl; i++)
	{
		int clan;
		bool ima=false;
		
		std::cin>>clan;
		for(int j=0; j<i; j++)
		{
			if(S.at(j)==clan)
				ima=true;
		}
		
		if(!ima)
		S.at(i)=clan;
		else 
		i--;
	}
}

int main ()
{
	int br_cl;
	std::cout<<"Unesite broj elemenata: ";
	std::cin>>br_cl;
	std::vector<int> S1(br_cl), S2(br_cl), S3(br_cl);
	
	std::cout<<"Unesite elemente prvog vektora: ";
	Ubaci(S1, br_cl);
	std::cout<<"Unesite elemente drugog vektora: ";
	Ubaci(S2, br_cl);
	std::cout<<"Unesite elemente treceg vektora: ";
	Ubaci(S3, br_cl);
	
	std::cout<<std::endl;
	
	try{
	SortirajPodrucjeVrijednosti(S1.begin(), S1.end(), S2.begin(), S3.begin(), funkcija, Sortiraj);
	}
	catch(std::logic_error poruka)
	{
		std::cout<<"Izuzetak: "<<poruka.what();
		return 0;
	}
	
	std::cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke:"<<std::endl;
	for(int i=0; i<br_cl; i++)
	{
		std::cout<<"f("<<S1.at(i)<<", "<<S2.at(i)<<") = "<<S3.at(i)<<std::endl;
	}
	return 0;
}