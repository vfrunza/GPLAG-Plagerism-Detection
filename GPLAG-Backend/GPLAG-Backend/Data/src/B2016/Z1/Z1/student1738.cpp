//2 od 13 testova nije prošlo
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

enum vrsta {gadan,odvratan,opak};

std::vector<int> IzbaciIste (std::vector<int>v)
{
	for (int i=0;i<2;i++)
	{
		for (int i =0;i<int(v.size());i++)
		{
			for (int j=i+1;j<int(v.size());j++)
			{
				if (v.at(i)==v.at(j))
				{
					v.erase(v.begin()+j);
				}
			}
		}
	}
	return v;
}


std::vector<int> DecToTer (int b)
{
	std::vector<int> ter;
	long long int a(b);
	
	if (a<0) a=std::abs(a);
	
	int kolicnik(1),ostatak;
	while (kolicnik>0)
	{
		kolicnik=a/3;
		ostatak=a%3;
		ter.push_back(ostatak);
		a=a/3;
	}
	
	return ter;
}

enum vrsta KakavJeBroj (int a)
{
	//opak svaka cifra paran broj puta
	//odvratan svaka cifra neparan broj puta
	std::vector<int>ter(DecToTer(a));
	int nule(0),jedinice(0),dvice(0);
	for (int x:ter)
	{
		if (x==0) nule++;
		else if (x==1) jedinice++;
		else dvice++;
	}
	if ((nule%2==0 && jedinice%2==0 && dvice%2==0)||(nule==0 && jedinice%2==0 && dvice%2==0)||(nule==0 && jedinice==0 && dvice%2==0)||(nule%2==0 && jedinice%2==0 && dvice==0)||(nule%2==0 && jedinice==0 && dvice%2==0)||(nule==0 && jedinice%2==0 && dvice==0)) return opak;
	else if ( (nule%2!=0 && jedinice%2!=0 && dvice%2!=0) || (nule==0 && jedinice%2!=0 && dvice%2!=0) || (jedinice==0 && dvice%2!=0 && nule%2!=0) || (dvice==0 && jedinice%2!=0 && nule%2!=0) 
	|| (nule==0 && jedinice==0 && dvice%2!=0)|| (nule==0 && jedinice%2!=0 && dvice==0)|| (nule%2!=0 && jedinice%2!=0 && dvice==0)) return odvratan;
	else return gadan;
}


std::vector<int> IzdvojiGadne (std::vector<int> v, bool m)
{
	std::vector<int> novivektor;
	for (int x:v)
	{
		if (m==true && KakavJeBroj(x)==opak)
		{
			novivektor.push_back(x);
		}
		else if (m==false &&KakavJeBroj(x)==odvratan)
		{
			novivektor.push_back(x);
		}
	}
	
	novivektor=IzbaciIste(novivektor);
	return novivektor;
}
int main ()
{
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	int br;
	do
	{
		std::cin>> br;
		if(!(std::cin)) break;
		if (br!=0)
		v.push_back(br);
	}while (br!=0);
	std::cout << "Opaki: ";
	std::vector<int> v1(IzdvojiGadne(v,true));
	for (int x:v1)
	{
		std::cout <<x<<" ";
	}
	std::cout << std::endl;
	std::cout << "Odvratni: ";
	v1=(IzdvojiGadne(v,false));
	for (int x:v1)
	{
		std::cout<<x<<" ";
	}
	return 0;
}