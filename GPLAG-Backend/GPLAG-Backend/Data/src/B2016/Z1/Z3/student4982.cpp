#include<iostream>
#include<vector>
#include<stdexcept>


std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> vektor)
{
	std::vector<std::vector<double>> podnizovi;
	if(vektor.size()==0) return podnizovi;
	int p=0,q=0;
	while(q<vektor.size()-1)
	{
		if(vektor[q+1]<=vektor[q] && q<vektor.size()-1) q++;
		else
		{
			if(q>p) {
			std::vector<double> podniz;
			while(p<=q)
			{
				podniz.push_back(vektor[p]);
				p++;
			} q++;
			podnizovi.push_back(podniz);
		}
		else
		{
			p++; q++;
		}
		} 
		if(q==vektor.size()-1 && p<q)
		{
			std::vector<double> podniz;
			while(p<=q)
			{
				podniz.push_back(vektor[p]);
				p++;
			}
			podnizovi.push_back(podniz);
		}
	}
	return podnizovi;
}

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> vektor)
{
	std::vector<std::vector<double>> podnizovi;
	if(vektor.size()==0) return podnizovi;
	int p=0,q=0;
	while(q<vektor.size()-1)
	{
		if(vektor[q+1]>=vektor[q] && q<vektor.size()-1) q++;
		else
		{
			if(p<q)
			{
				std::vector<double> podniz;
				while(p<=q)
				{
					podniz.push_back(vektor[p]);
					p++;
				}
				q++;
				podnizovi.push_back(podniz);
			}
			else
			{
				p++;
				q++;
			}
		}
		if(q==vektor.size()-1 && p<q)
		{
			std::vector<double> podniz;
			while(p<=q)
			{
				podniz.push_back(vektor[p]);
				p++;
			}
			podnizovi.push_back(podniz);
		}
		
	}
	return podnizovi;
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	if(n<0) 
	{
		std::cout<<"Broj elemenata ne moze biti negativan";
		return 0;
	}
	std::vector<double> v(n);
	if(n>0) {
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++)
	{
		std::cin>>v[i];
	}
	}
	std::vector<std::vector<double>> rastuci=RastuciPodnizovi(v);
	std::vector<std::vector<double>> opadajuci=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(std::vector<double> podniz: rastuci)
	{
		for(double x: podniz) std::cout<<x<<" ";
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(std::vector<double> podniz: opadajuci)
	{
		for(double x: podniz) std::cout<<x<<" ";
		std::cout<<std::endl;
	}
	return 0;
}