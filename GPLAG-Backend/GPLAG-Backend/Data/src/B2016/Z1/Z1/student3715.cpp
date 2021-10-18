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

std::vector<int> IzdvojiGadne(std::vector<int> v, bool a)
{
	std::vector<int> opaki, odvratni;

	
	for(int i = 0; i < v.size()-1; i++)
    {
       for(int j = i+1; j < v.size(); j++)
          {
          	if(v.at(i) == v.at(j))
          	   v.erase(v.begin() + j);   //brisanje elemenata koji se ponavljaju
          }
	
    }
	
	
	for(int i = 0; i < v.size(); i++)
	{
		int n;                   //nova varijablja koja predstavlja ostatak dijeljenja sa 3
		int y(v[i]);
		std::vector<int> pomocni;//pomocni vektor u kojeg smijestam broj u ternarnom obliku
		do
		{
			n = std::abs(y % 3);
			y /= 3;
			pomocni.push_back(n);
		}
		while(y != 0);
		int ponavlja_nula(0), ponavlja_jedan(0), ponavlja_dva(0);
		for(int k = 0; k < pomocni.size(); k++)
		{
		    if(pomocni[k] == 0) //kako broj u ternarnom zapisu moze sadrzavati samo ili 0 ili 1 ili 2
		       ponavlja_nula++; //ponavljanja cifara cemo odrediti preko brojaca
		    else if(pomocni[k] == 1)
		       ponavlja_jedan++;
		    else if(pomocni[k] == 2)
		       ponavlja_dva++;
		}
		
		if(ponavlja_nula % 2 == 0 && ponavlja_jedan % 2 == 0 && ponavlja_dva % 2 == 0)
		   opaki.push_back(v[i]);   //uslov kada se sve cifre ponavljaju paran broj puta
		else if((ponavlja_nula % 2 != 0 || ponavlja_nula == 0) && (ponavlja_jedan % 2 != 0 || ponavlja_jedan == 0) && (ponavlja_dva % 2 != 0 || ponavlja_dva == 0))
		   odvratni.push_back(v[i]);//uslov kada se sve cifre ponavljaju neparan broj puta

	}
	
	
	if(a)
	   return opaki;
	   
	return odvratni;   
}



int main ()
{

	std::vector<int> a;
	int n;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	do
	{
	   	std::cin >> n;
	   	if(n != 0)
	    	a.push_back(n);
	}while(n != 0);
	
	
	std::vector<int> b;
	b = IzdvojiGadne(a,true);
	std::vector<int> c;
	c = IzdvojiGadne(a,false);
	
	std::cout << "Opaki: ";
	for(int x: b)
	   std::cout << x << " ";
	   
	std::cout << std::endl;   
	std::cout << "Odvratni: ";
	
	for(int x: c)
	   std::cout << x << " ";
	   
	   
	return 0;
}