#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::endl;
vector <int> konvertuj_u_3(int n)//iz baze 10 u bazu 3
{
	int cifra;
	vector <int> baza3;
	while(n)
	{
		cifra=abs(n%3);
		baza3.push_back(cifra);
		n/=3;
	}
	return baza3;
}
bool gadan_or_nah(int n)//provjerava da li je gadan ili ne
{
	//valjda ce vako radit
	int brojac0(0),brojac1(0),brojac2(0);
	vector <int> broj(konvertuj_u_3(n));
	for(int i(0);i<broj.size();i++)
	{
		if(broj.at(i)==0)brojac0++;
		if(broj.at(i)==1)brojac1++;
		if(broj.at(i)==2)brojac2++;
	}
	if(brojac0!=0 && brojac1!=0 && brojac2!=0)return true;
	return false;
}
bool opak_or_nah(int n)
{
	int brojac0(0),brojac1(0),brojac2(0);
	vector <int> broj(konvertuj_u_3(n));
	for(int i(0);i<broj.size();i++)
	{
		if(broj.at(i)==0)brojac0++;
		if(broj.at(i)==1)brojac1++;
		if(broj.at(i)==2)brojac2++;
	}
	if(brojac0%2==0 && brojac1%2==0 && brojac2%2==0)return true;
	return false;
}
vector <int> IzdvojiGadne(vector <int> iz_glavne, bool stanje)
{
	vector <int> vektor_odavd;
	int brojac(0);
	if(!stanje) // 
	{
		for(int i(0);i<iz_glavne.size();i++)
		{
			if(gadan_or_nah(iz_glavne.at(i)))
			{
				for(int j(0);j<vektor_odavd.size();j++)
				{
					
					if(iz_glavne.at(i)!=vektor_odavd.at(j))brojac++;
				}
				if(brojac==vektor_odavd.size())vektor_odavd.push_back(iz_glavne.at(i));
				brojac=0;
			}
		}
	}
	else // ODVRATNI
	{
		for(int i(0);i<iz_glavne.size();i++)
		{
			if(opak_or_nah(iz_glavne.at(i)))
			{
				for(int j(0);j<vektor_odavd.size();j++)
				{
					
					if(iz_glavne.at(i)!=vektor_odavd.at(j))brojac++;
				}
				if(brojac==vektor_odavd.size())vektor_odavd.push_back(iz_glavne.at(i));
				brojac=0;
			}
		}
	}
	return vektor_odavd;
}
int main ()
{
    vector <int> iz_glovne;
	//cout<<"kompajliraj se";
	int x;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	do
	{
		cin>>x;
		if(!x)break;
		iz_glovne.push_back(x);
	}while(x);
	cout<<"Opaki: ";
	std::vector<int>opaki(IzdvojiGadne(iz_glovne,true));
	for(int i(0);i<opaki.size();i++)
	{
		if(i==opaki.size()-1)cout<<opaki.at(i);
		 else cout<<opaki.at(i)<<" ";
	}
	cout<<"\nOdvartni: ";
	std::vector<int>odvratni(IzdvojiGadne(iz_glovne,false));
	for(int i(0);i<odvratni.size();i++)
	{
		if(i==odvratni.size()-1)cout<<odvratni.at(i);
		else cout<<odvratni.at(i)<<" ";
	}
	//vector <int> ispisni{IzdvojiGadne(iz_glovne,true)};
//	for(int z:ispisni)cout<<z<<" ";
/*	int test=0;
	while(test)
	{
		cout<<"\nunesi: ";
		cin>>test;
		for(int x:konvertuj_u_3(test))cout<<x;
	}*/
	return 0;
}