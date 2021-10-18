#include <vector>
#include <iomanip>
#include <iostream>
#include <deque>
#include <stdexcept>
enum  class SmjerKretanja
{
    NaprijedNazad,NazadNaprijed,GoreDolje,DoljeGore,LijevoDesno,DesnoLijevo
};
template <typename Tip1>
Tip1 PjescaniSat(Tip1 Cudo,SmjerKretanja s )
{
	if(Cudo.size()==0) { return Cudo; }
	int brojac_j(0),brojac_k(0),brojac_i(0);
	for(int i(0);i<Cudo.size();i++)
	{
		brojac_i++;
		for(int j(0);j<Cudo.at(i).size();j++)
		{
			brojac_j++;
			for(int k(0);k<Cudo.at(i).at(j).size();k++)
			{
				brojac_k++;
			}
		}
	}
	if(brojac_j!=brojac_i*brojac_i||brojac_k!=brojac_j*brojac_i) throw std::domain_error("3D matrica nema oblik kocke");
	if(brojac_j%2==0||brojac_k%2==0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	int k1(0);
	Tip1 l(Cudo);
	Tip1 pom(Cudo);
	auto red(Cudo.at(0).at(0));
	for(int i(0); i<Cudo.size(); i++) {
		for(int j(0); j<Cudo.size(); j++) {
			red=Cudo.at(i).at(j);
			pom.at(j).at(i)=red;
		}
	} 
	if(s==SmjerKretanja::NaprijedNazad||s==SmjerKretanja::NazadNaprijed) {

		for(int i(0); i<Cudo.size(); i++) {
			k1=0;
			for(int j(0); j<Cudo.at(i).size(); j++) {
				if(j>0&&j<Cudo.size()-1) {
					if(j<=(Cudo.size()-1)/2)
					{
						k1++;
					for(int k(0);k<k1;k++)
						pom.at(i).at(j).erase(pom.at(i).at(j).begin()+0);
					pom.at(i).at(j).resize(pom.at(i).at(j).size()-k1);
					}
					else
					{
						k1--;
						for(int k(0);k<k1;k++)
							pom.at(i).at(j).erase(pom.at(i).at(j).begin()+0);
						pom.at(i).at(j).resize(pom.at(i).at(j).size()-k1);
					}
				}	
			}
		}
		int l=0;
		Tip1 pom1(pom);
		for(int i(0); i<pom.size(); i++) {
			l=0;
			for(int j=pom.at(i).size()-1; j>=0; j--) {
				for(int k(0); k<pom.at(i).at(j).size(); k++) {
					if(l==pom.size()) break;
					pom1.at(i).at(l).at(k)=pom.at(i).at(j).at(k);
				}
				l++;
			}
		} 
		if(s==SmjerKretanja::NaprijedNazad)
			return pom;
		else
			return pom1;
		}
	if(s==SmjerKretanja::GoreDolje||s==SmjerKretanja::DoljeGore)
	{
		pom=Cudo;
		for(int i(0);i<Cudo.size();i++)
		{
			k1=0;
			for(int j(0);j<Cudo.size();j++)
				{
					if(j>0&&j<Cudo.size()-1)
					{
						if(j<=(Cudo.size()-1)/2)
						{
							k1++;
							for(int k(0);k<k1;k++)
								pom.at(i).at(j).erase(pom.at(i).at(j).begin()+0);
							pom.at(i).at(j).resize(pom.at(i).at(j).size()-k1);	
						}
						else
						{
							k1--;
							pom.at(i).at(j).erase(pom.at(i).at(j).begin()+0);
							pom.at(i).at(j).resize(pom.at(i).at(j).size()-k1);
						}
					}
				} 
		}
		if(s==SmjerKretanja::GoreDolje) return pom;
		else {
			Tip1 pom1(pom);
			int 	l(0);
			for(int i(0);i<pom.size();i++)
				{
					l=0;
					for(int j(pom.at(i).size()-1);j>=0;j--)
					{
						for(int k(0);k<pom.at(i).at(j).size();k++)
						{
							if(l==pom.size()) break;
							pom1.at(i).at(l).at(k)=pom.at(i).at(j).at(k);
						}
						l++;
					}
				}
				return pom1;
		}
	}
	if(s==SmjerKretanja::DesnoLijevo||s==SmjerKretanja::LijevoDesno)
	{
		int l(0),m(0),n(0),l1;
		auto red1(Cudo.at(0).at(0));
		Tip1 pom1(Cudo);
	   	red=Cudo.at(0).at(0);
		for(int i(0);i<Cudo.size();i++)
		{
			for(int j(Cudo.size()-1);j>=0;j--)
			{
				l1=0;
				for(int k1(Cudo.size()-1);k1>=0;k1--)
				{
				if(l1==Cudo.size()) break;
				red.at(l1)=(Cudo.at(i).at(k1).at(j));
				l1++;
				}
			l=0;
			for(int k(red.size()-1);k>=0;k--)
			{
				if(l==Cudo.size()) break;
				red1.at(l)=red.at(k);
				l++;
			}

				pom1.at(m).at(n)=red1;
			n++;
		}
		std::cout  << std::endl;
		n=0;
		m++;
		}
	for(int i(0);i<pom1.size();i++)
	{
		k1=0;
		for(int j(0);j<pom1.size();j++)
		{
			if(j>0&&j<pom1.size()-1)
			{
				if(j<=(pom1.size()-1)/2)
				{
					k1++;
					for(int k(0);k<k1;k++)
						pom1.at(i).at(j).erase(pom1.at(i).at(j).begin()+0);
					pom1.at(i).at(j).resize(pom1.at(i).at(j).size()-k1);	
					
				}
				else
				{
					k1--;
					for(int k(0);k<k1;k++)
						pom1.at(i).at(j).erase(pom1.at(i).at(j).begin()+0);
					pom1.at(i).at(j).resize(pom1.at(i).at(j).size()-k1);
				}
			}
		}
	}  
if(s==SmjerKretanja::DesnoLijevo) return pom1;
		Tip1 pom2(pom1);
		int ko(0);
		for(int i(0);i<pom1.size();i++)
		{
			 ko=0;
			for(int j(pom1.at(i).size()-1);j>=0;j--)
			{
				for(int k(0);k<pom1.at(i).at(j).size();k++)
				{
					if(ko==pom.size()) break;
					pom2.at(i).at(ko).at(k)=pom1.at(i).at(j).at(k);
				}
				ko++;
			}
		}	
 return pom2;
	}
	return Cudo;
}
int main ()
{
	try {
	std::cout << "Unesite dimenziju (x/y/z): ";
	int d;
	std::vector<std::deque<std::deque<int>>>d3,p ;
	do
	{
	std::cin >> d; 
	if(d<0) std::cout << "Dimenzija nije ispravna, unesite opet: ";
	}
	while (d<0);
	std::cout << "Unesite elemente kontejnera: ";
	d3.resize(d);
	for(int i(0); i<d3.size(); i++) {
		d3.at(i).resize(d);
		for(int j(0); j<d3.at(i).size(); j++)
			d3.at(i).at(j).resize(d);
	}
	for(int i(0); i<d; i++) {
		for(int j(0); j<d; j++) {
			for(int k(0); k<d; k++) {
				std::cin >> d3.at(i).at(j).at(k);
			}
		}
	}   
	std::cout << "Unesite smjer kretanja [0 - 5]: ";
	int smjer;
	do
	{
	std::cin >> smjer;
	if((smjer<0||smjer>5)) std::cout << "Smjer nije ispravan, unesite opet: ";
	}
	while(smjer<0||smjer>5);
	if(smjer==0)
		p=PjescaniSat(d3,SmjerKretanja::NaprijedNazad);
	if(smjer==1)
		p=PjescaniSat(d3,SmjerKretanja::NazadNaprijed);
	if(smjer==2)
		p=PjescaniSat(d3,SmjerKretanja::GoreDolje);
	if(smjer==3)
		p=PjescaniSat(d3,SmjerKretanja::DoljeGore);
	if(smjer==4)
		p=PjescaniSat(d3,SmjerKretanja::LijevoDesno);
	if(smjer==5)
		p=PjescaniSat(d3,SmjerKretanja::DesnoLijevo);
	std::cout << "\nPjescani sat unesene matrice je:" << std::endl;
	std::cout  << std::endl;
	int b(0),t(0),t1(0);
	for(int i(0); i<p.size(); i++) {
		b=1;
		for(int j(0); j<p.at(i).size(); j++) {
			if(j>0&&j<p.at(i).size()-1&&j<=(p.at(i).size()-1)/2) b++;
			if(j>(p.at(i).size()-1)/2) b--;
			t=0; t1=0;
			for(int k(0); k<p.at(i).at(j).size(); k++) {
				if(j>0&&j<p.size()-1) { 
					if(j<=(p.at(i).size()-1)/2)
					{
						if(t==0) { 
							if(j==(p.at(i).size()-1)/2) { 
								if(p.at(i).size()<4) std::cout << std::setw(4*b) <<p.at(i).at(j).at(k); 
								else std::cout << std::setw(4*b) <<p.at(i).at(j).at(k);
							}
							else std::cout << std::setw(4*b) <<p.at(i).at(j).at(k);
						}
						else
						{
							std::cout << std::setw(4)<<p.at(i).at(j).at(k);
						}
						t++;
					}
					else
					{
						if(t1==0) { std::cout << std::setw(4*b) <<p.at(i).at(j).at(k);  }
						else
						{
							if(k==0)
							std::cout << std::setw(4) <<p.at(i).at(j).at(k);
							else 
							std::cout << std::setw(4)<<p.at(i).at(j).at(k);
						}	
					t1++;	
					}
				}
			
				else	
				{
					std::cout << std::setw(4)<<p.at(i).at(j).at(k);
				}	
			}
			std::cout  << std::endl;
		}
		std::cout  << std::endl;
	}
	}
				catch (std::domain_error &izuzetak)
	{
		std::cout <<"\nIzuzetak: "<< izuzetak.what() << std::endl;
	}
	catch (std::length_error &izuzetak1)
	{
		std::cout <<"\nIzuzetak: "<<izuzetak1.what()  << std::endl;
	}
	return 0;
}