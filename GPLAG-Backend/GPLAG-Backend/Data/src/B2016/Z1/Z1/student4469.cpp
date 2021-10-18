/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <vector>
#include<cmath>
#include<deque>


int prebroji(int a)
{	int i=0;
	while(a!=0)
	{	a=a/10;
		i++;
	}
	return i;

}

bool opak(int broj)
{

	std::deque<int>a;
	int brojac=1;

	while(broj!=0)
	{

		a.push_front(broj%10);
		broj=broj/10;
	}

	for(int i=0; i<a.size(); i++)
	{	for(int j=0; j<a.size(); j++)
		{	if((a[i]==a[j]) && (i!=j)  )
				brojac++;
		}


		if ((brojac%2!=0) || (brojac==1))
		{	return false;
		}

		brojac=1;
	}

	return true;
}

bool odvratan (int broj)
{

	std::deque<int> a;
	int brojac=1;

	while(broj!=0)
	{

		a.push_front(broj%10);
		broj=broj/10;
	}

	for(int i=0; i<a.size(); i++)
	{	for(int j=0; j<a.size(); j++)
		{	if((a[i]==a[j]) && (i!=j)  )
				brojac++;
		}

		if (brojac%2==0 && brojac!=1)
		{	return false;
		}
		brojac=1;
	}

	return true;
}





int ternarni (int a)
{	int broj=0,i=0;

	while(a!=0)
	{	broj+=(a%3)*pow(10,i);
		i++;
		a=a/3;
	}

	return broj;
}


std::vector<int> IzdvojiGadne (std::vector<int> a,bool tacno)
{	
	
	
	for(int i=0; i<a.size(); i++)
	{	for(int j=0; j<a.size(); j++)
		{	if((a[i]==a[j]) && (i!=j))
			{
				a.erase(a.begin()+j);
				j--;
			}

		}
	}
	
	
	std::vector<int>b=a;

	for(int i=0; i<b.size(); i++)
	{	b[i]=ternarni(b[i]);
	}

	std::vector<int>nizopakih;
	std::vector<int>nizodvratnih;

	if (tacno)
	{

		for(int i=0; i<a.size(); i++)
		{

			if(opak(b[i]))
			{	nizopakih.push_back(a[i]);
			}
		}
		


	}

	if (!tacno)
	{

		for(int i=0; i<a.size(); i++)
		{

			if(odvratan(b[i]))
			{	nizodvratnih.push_back(a[i]);
			}
		}
		

return nizodvratnih;
	}
	


return nizopakih;
}


int main ()
{	std::vector<int> a;
	std::vector<int>b;
	std::vector<int>c;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int broj;
	do
	{	std::cin>>broj;

		if(broj!=0)
		{	a.push_back(broj);
		}

	}
	while(broj!=0);


	b=IzdvojiGadne(a,true);
	c=IzdvojiGadne(a,false);

	std::cout<<"Opaki: ";
	for(int i:b)
		std::cout<<i<<" ";

	std::cout<<std::endl;
	std::cout<<"Odvratni: ";
	for(int i:c)
		std::cout<<i<<" ";

	return 0;
}