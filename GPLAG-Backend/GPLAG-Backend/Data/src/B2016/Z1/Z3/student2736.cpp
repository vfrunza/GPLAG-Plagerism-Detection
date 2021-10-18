/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <deque>



std::deque<std::vector<double>> RastuciPodnizovi(std::vector<double> v)
{
    std::deque<std::vector<double>> rastuci;
    int brojac(0),broj_redova(0);

	for(int i=0;i<v.size();i++)
	{
		brojac=0;
		for(int j=i;j<v.size()-1;j++)
		{
			if(v.at(j)<=v.at(j+1))
				brojac++;
            else
               break;
		}
		if(brojac>=1)
		{
			rastuci.resize(rastuci.size()+1);
			for(int k=0;k<=brojac;k++)
            	rastuci[broj_redova].push_back(v[k+i]);
        	broj_redova++;
		}
		i+=brojac;
	}	
	return rastuci;
}

std::deque<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v)
{
	std::deque<std::vector<double>> opadajuci;
	int brojac(0),broj_redova(0);
	
	for(int i=0;i<v.size();i++)
	{
		brojac=0;
		for(int j=i;j<v.size()-1;j++)
		{
			if(v[j]>=v[j+1])
				brojac++;
			else
				break;
		}
		
		if(brojac>=1)
		{
			opadajuci.resize(opadajuci.size()+1);
			for(int k=0;k<=brojac;k++)
				opadajuci[broj_redova].push_back(v[k+i]);
			broj_redova++;	
		}
		i+=brojac;
	}
	return opadajuci;
}

void IspisiMaxMonRast(std::deque<std::vector<double>> v)
{
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i].size();j++)
			std::cout<<v[i][j]<<" ";
		std::cout<<std::endl;	
	}
}

int main()
{
    std::vector<double> v;
    int broj,n;
    
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin>>n;
    
    std::cout<<"Unesite elemente vektora: ";
    
    for(int i=0;i<n;i++)
    {
    	std::cin>>broj;
    	v.push_back(broj);
    }
    
    std::deque<std::vector<double>> MaxRastuciNiz,MaxOpadajuciNiz;
    
    std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
    MaxRastuciNiz=RastuciPodnizovi(v);
    IspisiMaxMonRast(MaxRastuciNiz);
    
    std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
    MaxOpadajuciNiz=OpadajuciPodnizovi(v);
    IspisiMaxMonRast(MaxOpadajuciNiz);

 	return 0;
}
