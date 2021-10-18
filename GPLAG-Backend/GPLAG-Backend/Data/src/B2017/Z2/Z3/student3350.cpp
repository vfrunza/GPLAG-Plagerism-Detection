#include <vector>
#include <iostream>
#include <stdexcept>
#include <deque>
#include <algorithm>
#include <iomanip>
template <typename NekiTip>
bool Da_Li_Je_Peridocan(std::vector<NekiTip>v,int d)
{
	bool t(true);
	if(d<1 || d>=v.size()) return false;
	for(int i(0);i<v.size()-d;i++)
	{
		if(v.at(i)!=v.at(i+d))
		{
			t=false;
			break;
		}
	}
	return t;
}

template <typename NekiTip>
int Odredi_Osnovni_Period(std::vector<NekiTip>v)
{
	if(v.size()==0) return 0;
	int osnovni(0);
	int br(1);
	while(br!=v.size())
	{
		if(Da_Li_Je_Peridocan(v,br)) return br;
		else br++;
	}
	if(br==v.size()) return 0;
}
template <typename NekiTip>
NekiTip **AlocirajFragmentirano(const std::vector<NekiTip> &v,int &koliko_puta)
{
	int index,duzina(v.size());
	int osnovni_period(Odredi_Osnovni_Period(v));
	if(osnovni_period>0)
		koliko_puta=std::count(v.begin(),v.end(),v[0]);
	else koliko_puta=2;
	if(v.size()==0) throw (" ");
	for(int i(0);i<v.size();i++)
		if(v.at(i)<=0) throw std::domain_error(" "); 
	int period(0),b(1);
	if(osnovni_period>0)
	{
	try
	{
	NekiTip **p(new NekiTip *[koliko_puta*osnovni_period]);
	try
	{
	for(int i(0);i<osnovni_period*koliko_puta;i++)
	{
		p[i]=new NekiTip [int(v.at(period))];
		 period++;
			if(period==osnovni_period) period=0;
	}


	period=osnovni_period;
	int max(v[0]),ma;
	for(int i(1);i<v.size();i++)
		if(v.at(i)>max) max=v[i];
	ma=max;	
	for(int i(osnovni_period*koliko_puta-1);i>=0;i--)
	{
		max=ma;
		for(int j(v.at(period-1)-1);j>=0;j--)
		{
			p[i][j]=max;
			max--;
		}
		period--;
		if(period==0) period=osnovni_period;
	}	
		return p;
	}	
	catch(std::bad_alloc)
	{
		for(int i(0);i<v.size();i++)
			delete [] p[i];
			delete [] p;
			throw;
	}
	}
	catch(std::bad_alloc)
	{
		throw;
	}
	}
	if(osnovni_period==0)
	{
		int k(0),duzina(v.size());
		try
		{
		NekiTip **p(new NekiTip *[koliko_puta*v.size()]);
		try
		{
		for(int i(0);i<koliko_puta*v.size();i++)
		{
			p[i]=new NekiTip [int(v.at(k))];
			k++;
			if(k==v.size()) k=0;
		}
		}	
		catch(std::bad_alloc)
		{
			for(int i(0);i<koliko_puta*v.size();i++)
				delete [] p[i];
			delete [] p;
			throw;
		}
		int max(v[0]),ma;
		for(int i(1);i<v.size();i++)
			if(v.at(i)>max) max=v[i];
		ma=max;	
		for(int i(koliko_puta*v.size()-1);i>=0;i--)
			{
				max=ma;
				for(int j(v.at(duzina-1)-1);j>=0;j--)
				{
					p[i][j]=max;
					max--;
				}
				duzina--;
				if(duzina==0) duzina=v.size();
			}
			return p;
		}
		catch(std::bad_alloc)
		{
			throw;
		}
	} 

}


template <typename NekiTip>
NekiTip **AlocirajKontinualno(const std::vector<NekiTip>&v,int &koliko_puta )
{
	int index,duzina(v.size());
	int osnovni_period(Odredi_Osnovni_Period(v));
	if(osnovni_period>0) koliko_puta=std::count(v.begin(),v.end(),v[0]);
	else koliko_puta=2;
	int nh,p(0);
	if(osnovni_period>0)
	{
	for(int i(0);i<v.size();i++)
	{
		if((v.size()-i)%osnovni_period==0) { p++; if(p==1) nh=i; }
	}
	}
	if(v.size()==0) throw (" ");
	for(int i(0);i<v.size();i++)
	if(v.at(i)<=0) throw std::domain_error(" ");
	int period(0);
	if(osnovni_period>0)
	{
		int n(0),k(0);
		try
		{
		NekiTip **p(new NekiTip *[koliko_puta*osnovni_period+1]);
		for(int i(0);i<koliko_puta*osnovni_period;i++)
		{
			n+=v.at(k);
			k++;
			if(k==v.size()-nh) k=0;
		} 
				try
				{
				p[0]=new NekiTip [n];
				}
				catch(std::bad_alloc)
				{
					delete[] p[0];
					throw;
				}
				k=0;
				for(int i(1);i<koliko_puta*osnovni_period;i++)
				{
					p[i]=p[i-1]+int(v.at(k));
					k++;
					if(k==v.size()-nh) k=0;
				}
			period=osnovni_period;

		int m(1),max(1),ma(1);
			for(int i(koliko_puta*osnovni_period-1);i>=0;i--)
			{
				max=ma;
				for(int j(v.at(period-1)-1);j>=0;j--)
				{
					p[i][j]=max++;
				}
				period--;
				if(period==0) period=osnovni_period;
			}
			return p;
		}
			catch(std::bad_alloc)
			{
				throw;
			}
  }
if(osnovni_period==0)
{
	int k(0),duzina(v.size()),j(0);
	try
	{
		NekiTip **p(new NekiTip *[koliko_puta*v.size()]);
			for(int i(0);i<koliko_puta*v.size();i++) 
			{
				k+=v.at(j);
				j++;
				if(j==v.size()) j=0;
			}
			try
			{
			p[0]=new NekiTip [k];
			}
			catch(std::bad_alloc)
			{
				delete[] p;
				throw;
			}
			k=0;

		for(int i(1);i<koliko_puta*v.size();i++) 
		{
			p[i]=p[i-1]+int(v.at(k));
			k++;
			if(k==v.size()) k=0;
		}
			int max(1),ma(1);
			for(int i(koliko_puta*v.size()-1);i>=0;i--)
			{
				max=ma;
				for(int j(v.at(duzina-1)-1);j>=0;j--)
				{
					p[i][j]=max;
					max++;
				}
				duzina--;
				if(duzina==0) duzina=v.size();
				
			}
			return p;
	}
			catch(std::bad_alloc)
			{
				throw;
			}
}

}  
int main ()
{
	try
	{
	std::cout << "Unesite broj elemenata vektora: ";;
	int br_elemenata;
	std::cin >> br_elemenata; 
	std::vector<int>v(br_elemenata);
	int koliko_puta(0);
	std::cout << "Unesite elemente vektora: ";
	for(int i(0);i<br_elemenata;i++)
    std::cin >> v.at(i); 
	std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	int izbor;
	std::cin >> izbor;

	if(izbor==0)
	{
	auto p0=AlocirajKontinualno(v,koliko_puta);
	std::cout << "Dinamicki alocirana matrica:" << std::endl; 
	int period(0),osnovni_period(Odredi_Osnovni_Period(v));
	int duzina(0);
	if(osnovni_period>0)
	{
	for(int i(0);i<osnovni_period*koliko_puta;i++)
		{
			for(int j(0);j<v[period];j++)
			{
				std::cout <<std::left<<std::setw(3)<<p0[i][j];
			}
			period++;
			if(period==osnovni_period) period=0;
			std::cout  << std::endl;
		}
	}
	else
	{
		for(int i(0);i<koliko_puta*v.size();i++)
		{
			for(int j(0);j<v[period];j++)
			{
				std::cout << std::left<<std::setw(3) <<p0[i][j];
			}
			period++;
			if(period==v.size()) period=0;
			std::cout  << std::endl;
		}
	}
		delete[] p0[0];
		delete[] p0;
	} 
	if(izbor==1)
	{
		auto p1=AlocirajFragmentirano(v,koliko_puta);
		std::cout << "Dinamicki alocirana matrica: " << std::endl;

		int period(0),osnovni_period(Odredi_Osnovni_Period(v));
		if(osnovni_period>0)
		{
		for(int i(0);i<koliko_puta*osnovni_period;i++)
		{
			for(int j(0);j<v[period];j++)
			{
				std::cout <<std::left<<std::setw(3)<< p1[i][j];
			}	
			std::cout  << std::endl;	
			period++;
			if(period==osnovni_period) period=0;
		}
		for(int i(0);i<koliko_puta*osnovni_period;i++)
			delete[] p1[i];
			delete[] p1;
		}
		else
		{
			period=0;
			for(int i(0);i<(koliko_puta*v.size());i++)
			{
				for(int j(0);j<v[period];j++)
					std::cout << std::left<<std::setw(3)<<p1[i][j] ;
				std::cout  << std::endl;
				period++;
				if(period==v.size()) period=0;
			}
		
		for(int i(0);i<koliko_puta*v.size();i++)
			delete [] p1[i];
			delete [] p1;
		}
	}
	}
	catch(std::bad_alloc)
	{
		std::cout << "Izuzetak: Alokacija nije uspjela!" << std::endl;
	}
	catch(std::domain_error)
	{
		std::cout <<"Izuzetak: Neispravan vektor!" << std::endl;
	}
	catch(...)
	{
		std::cout << "Izuzetak: Prazan vektor!"<< std::endl;
	}
	
	return 0;
}