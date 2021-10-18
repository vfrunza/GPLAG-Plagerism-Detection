//q:~WHAT DO PROGRAMMERS OFTEN DO WHEN THEY HAVE break; FROM CODING?
//a:~THEY goto; PUB!

#include <iostream>
#include <vector>
#include <cstdlib>

std::vector<int> IzdvojiGadne(std::vector<int> svi, bool koji)
{
	std::vector<int> novi;
	for(int i=0;i<svi.size();i++)
	{
		unsigned int num{abs(svi.at(i))};
		std::vector<int> nula,jedan,dva;
//popunjavanje vektora sa ciframa broja koji se ispituje u bazi-3
		do
		{
			unsigned int block{num%3};
			if(block==0)
				nula.push_back(0);
			else if(block==1)
				jedan.push_back(1);
			else if(block==2)
				dva.push_back(2);
			num/=3;
		}while(num!=0);
//ispitivanje ucestalosti cifara sa bool-om poslanim u funkciju
		if((nula.size()%2!=koji || nula.size()==0) && (jedan.size()%2!=koji || jedan.size()==0) && (dva.size()%2!=koji || dva.size()==0))
		{
	//ispitivanje da li se taj broj vec pojavljuje unutar vektora koji se vraca, te dodavanje u vektor
			bool test=false;
			for(int j=0;j<novi.size();j++)
				if(novi.at(j)==svi.at(i))
					test=true;
			if(test==false)
				novi.push_back(svi.at(i));
		}
	}
	return novi;
}

int main()
{
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> brojevi;
//unos brojeva u vektor, prekid sa nulom(0)
	for(;;)
	{
		int n;
		std::cin>>n;
		if(n==0)
			break;
		else brojevi.push_back(n);
	}
	std::vector<int> opaki{IzdvojiGadne(brojevi,true)};
	std::vector<int> odvratni{IzdvojiGadne(brojevi,false)};
	std::cout<<"Opaki: ";
	for(int x:opaki)
		std::cout<<x<<" ";
	std::cout<<std::endl<<"Odvratni: ";
	for(int x:odvratni)
		std::cout<<x<<" ";
	return 0;
}