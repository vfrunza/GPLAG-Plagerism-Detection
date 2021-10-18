/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> IzdvojiGadne(std::vector<int> help, bool hell) 
{
	std::vector<int> hellno;
	std::vector<int> pomoc;
	
	int really;
	for(int dude: help)
	{
		//u slučaju da su negativni
		if(dude<0)
			really=-dude;
		else
			really=dude;
		// nove broj po bazi 3	
		int newreally;
	
		
		while(really!=0)
		{
			newreally=abs(really%3);
			really/=3;
			pomoc.push_back(newreally); //vektor cifri
		}
		
		int brojac0(0),brojac1(0),brojac2(0);
		for(int brb:pomoc)
		{
			if(brb==0) //po bazi 3 broj ima cifre 0 1 2
				brojac0++;
			else if(brb==1)
				brojac1++;
			else if(brb==2)
				brojac2++;
		}
		
		if(hell)
		{
			if(brojac0!=0 && brojac0%2==0 && brojac2!=0 && brojac2%2==0 && brojac1!=0 && brojac1%2==0)//sadrzi sve 3 cifra paran broj puta
				hellno.push_back(dude);
			else if(brojac0!=0 && brojac0%2==0 && brojac1!=0 && brojac1%2==0 && brojac2==0)//sadrzi 0 i 1 paran broj puta
				hellno.push_back(dude);
			else if(brojac0!=0 && brojac0%2==0 && brojac2!=0 && brojac2%2==0 && brojac1==0)//sadrzi 0 i 2 paran broj puta
				hellno.push_back(dude);
			else if(brojac2!=0 && brojac2%2==0 && brojac1!=0 && brojac1%2==0 && brojac0==0)//sadrzi 1 i 2 paran broj puta
				hellno.push_back(dude);	
			else if(brojac1%2==0 && brojac0==0 && brojac2==0)//u broju se nalaze sve jedinice
				hellno.push_back(dude);
			else if(brojac2%2==0 && brojac0==0 && brojac1==0)//u broju se nalaze sve dvice
				hellno.push_back(dude);
					}
		else
		{
			if(brojac0!=0 && brojac0%2!=0 && brojac2!=0 && brojac2%2!=0 && brojac1!=0 && brojac1%2!=0)//sadrzi sve 3 cifra neparan broj puta
				hellno.push_back(dude);
			else if(brojac0!=0 && brojac0%2!=0 && brojac1!=0 && brojac1%2!=0 && brojac2==0)//sadrzi 0 i 1 neparan broj puta
				hellno.push_back(dude);
			else if(brojac0!=0 && brojac0%2!=0 && brojac2!=0 && brojac2%2!=0 && brojac1==0)//sadrzi 0 i 2 neparan broj puta
				hellno.push_back(dude);
			else if(brojac2!=0 && brojac2%2!=0 && brojac1!=0 && brojac1%2!=0 && brojac0==0)//sadrzi 1 i 2 neparan broj puta
				hellno.push_back(dude);	
			else if(brojac1%2!=0 && brojac0==0 && brojac2==0) //u broju se nalaze sve jedinice
				hellno.push_back(dude);
			else if(brojac2%2!=0 && brojac0==0 && brojac1==0)//u broju se nalaze sve dvice
				hellno.push_back(dude);
			
		}
		pomoc.resize(0);
		}

//erase blizance
		for(int i=0;i<hellno.size();i++)
		{
			for(int j=i+1;j<hellno.size();j++)
			{
				if(hellno.at(i)==hellno.at(j))
				{
					hellno.erase(hellno.begin()+j);
					i--;
					break;
				}
			}
		}

	return hellno;
}
int main ()
{
	std::vector<int> a;
	std::cout <<"Unesite brojeve (0 za prekid unosa): ";
	int element;
	for(int i=0;i<=a.size();i++)
	{
		std::cin>>element;
		if(element==0) break;
		a.push_back(element);
	}
	std::vector<int> b;
	std::vector<int> c;
	bool gadno(1),nijegadno(0);
	b=IzdvojiGadne(a, gadno);
	c=IzdvojiGadne(a, nijegadno);
	std::cout << "Opaki: ";
	for(int x: b)
	std::cout<<x<<" ";
	std::cout<<std::endl;
	std::cout << "Odvratni: ";
	for(int y:c)
	std::cout << y <<" ";
	
	return 0;
}