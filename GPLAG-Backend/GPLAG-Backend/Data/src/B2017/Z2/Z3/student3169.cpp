/*B 2017/2018, Zadaća 2, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na forum (c2).
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <new>
#include <iomanip>

template<typename Tipint>
bool ImaLi(std::vector<Tipint>v,int p)
{
	if(p<1 || p>=v.size())return false;
	for(int i(0);(i+p)<v.size();i++)
	{
		if(v.at(i)!=v.at(i+p))return false;
	}
	return true;
}

template<typename Tipint>
int Osnovni(std::vector<Tipint>v)
{
	for(int i(1);i<v.size();i++)
	{
		if(ImaLi(v,i))return i;
	}
	return 0;
}

template<typename Tipint>
Tipint** AlocirajFragmentirano(const std::vector<Tipint> &v, int& koliko_puta)
{
	if(v.size()==0)throw "Prazan vektor!";
	for(int i(0);i<v.size();i++)
	{
		if(v.at(i)<=0)throw std::domain_error("Neispravan vektor!");
	}
	int e(Osnovni(v));
	if(e>0)
	{
		int a(v.size());
		while(a%e!=0)
		{
			a++;
		}
	
	koliko_puta=a/e;
	Tipint **pok(nullptr);
	try
	{
		pok=new Tipint* [koliko_puta*e];
		for(int i(0);i<koliko_puta*e;i++)pok[i]=nullptr;
		try
		{
			int k(0);
			while(k<koliko_puta*e)
			{
				for(int i(k);i<e+k;i++)pok[i]=new Tipint[v.at(i-k)];
				k+=e;
			}
		}
		catch(std::bad_alloc)
		{
			for(int i(0);i<koliko_puta*e;i++)delete[] pok[i];
			delete[] pok;
			throw std::bad_alloc();
		}
	}
	catch(std::bad_alloc)
	{
		throw std::bad_alloc();
	}
	int h(0);
	while(h<koliko_puta*e)
	{
		int max(1);
		for(int i(0);i<e;i++)
		{
			if(v.at(i)>max)max=v.at(i);
		}
		for(int i(h);i<h+e;i++)
		{
			int max1(max);
			for(int j(v.at(i-h)-1);j>=0;j--)
			{
				//kontinualna pok[i][j]=(v.at(i-h)-j);
				pok[i][j]=max1;
				max1--;
			}
		}
		h+=e;
	}
	return pok;
	}
	
	if(e==0)
	{
		e=v.size();
		koliko_puta=2;
		Tipint **pok(nullptr);
		try
		{
			pok=new Tipint* [koliko_puta*e];
			for(int i(0);i<koliko_puta*e;i++)pok[i]=nullptr;
			try
			{
				int k(0);
				while(k<koliko_puta*e)
				{
					for(int i(k);i<e+k;i++)pok[i]=new Tipint[v.at(i-k)];
					k+=e;
				}
			}
			catch(std::bad_alloc)
			{
				for(int i(0);i<koliko_puta*e;i++)delete[] pok[i];
				delete[] pok;
				throw;
			}
		}
		catch(std::bad_alloc)
		{
			throw;
		}
		int h(0);
		while(h<koliko_puta*e)
		{
			int max(1);
			for(int i(0);i<e;i++)
			{
				if(v.at(i)>max)max=v.at(i);
			}
			for(int i(h);i<h+e;i++)
			{
				int max1(max);
				for(int j(v.at(i-h)-1);j>=0;j--)
				{
					pok[i][j]=max1;
					max1--;
				}
			}
			h+=e;
		}
		return pok;
	}
	return nullptr;
}


template<typename Tipint>
Tipint** AlocirajKontinualno(const std::vector<Tipint> &v, int& koliko_puta)
{
	if(v.size()==0)throw "Prazan vektor!";
	for(int i(0);i<v.size();i++)
	{
		if(v.at(i)<=0)throw std::domain_error("Neispravan vektor!");
	}
	int e(Osnovni(v));
	if(e>0)
	{
		int a(v.size());
		while(a%e!=0)
		{
			a++;
		}
	
	koliko_puta=a/e;
	int m(0);
	for(int i(0);i<e;i++)
	{
		m+=v.at(i);
	}
	m*=koliko_puta;
	Tipint **pok(nullptr);
	try
	{
		pok=new Tipint* [koliko_puta*e];
		for(int i(0);i<koliko_puta*e;i++)pok[i]=nullptr;
		try
		{
			pok[0]=new Tipint[m];
			int k(0);
			while(k<koliko_puta*e)
			{
				for(int i(k);i<k+e;i++)
				{
					if(i==0)continue;
					int a=i-1-k;
					if(a==-1)a+=e;
				    a=v.at(a);
					pok[i]=pok[i-1]+a;
				}
				k+=e;
			}
		}
		catch(std::bad_alloc)
		{
			delete[] pok[0];
			delete[] pok;
			throw std::bad_alloc();
		}
	}
	catch(std::bad_alloc)
	{
		throw std::bad_alloc();
	}
	int h(0);
	while(h<koliko_puta*e)
	{
		for(int i(h);i<h+e;i++)
		{
			int a(1);
			for(int j(v.at(i-h)-1);j>=0;j--)
			{
				
				pok[i][j]=a;
				a++;
			}
		}
		h+=e;
	}
	return pok;
	}
	
	
	if(e==0)
	{
		e=v.size();
	
	koliko_puta=2;
	int m(0);
	for(int i(0);i<e;i++)
	{
		m+=v.at(i);
	}
	m*=koliko_puta;
	Tipint **pok(nullptr);
	try
	{
		pok=new Tipint* [koliko_puta*e];
		for(int i(0);i<koliko_puta*e;i++)pok[i]=nullptr;
		try
		{
			pok[0]=new Tipint[m];
			int k(0);
			while(k<koliko_puta*e)
			{
				for(int i(k);i<k+e;i++)
				{
					if(i==0)continue;
					int a=i-1-k;
					if(a==-1)a+=e;
				    a=v.at(a);
					pok[i]=pok[i-1]+a;
				}
				k+=e;
			}
		}
		catch(std::bad_alloc)
		{
			delete[] pok[0];
			delete[] pok;
			throw std::bad_alloc();
		}
	}
	catch(std::bad_alloc)
	{
		throw std::bad_alloc();
	}
	int h(0);
	while(h<koliko_puta*e)
	{
		for(int i(h);i<h+e;i++)
		{
			int a(1);
			for(int j(v.at(i-h)-1);j>=0;j--)
			{
				pok[i][j]=a;
				a++;
			}
		}
		h+=e;
	}
	return pok;
		
	}
	
	return nullptr;
}

int main ()
{
	try
	{
		std::cout<<"Unesite broj elemenata vektora: ";
		int broj;
		std::cin>>broj;
		std::vector<int>v(broj);
		std::cout<<"Unesite elemente vektora: ";
		for(int i(0);i<broj;i++)
		{
			int n;
			std::cin>>n;
			v.at(i)=n;
		}
		std::cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		int al;
		std::cin>>al;
		if(al==1)
		{
			int koliko_puta;
			int** pok=AlocirajFragmentirano<int>(v,koliko_puta);
			std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
			int e(Osnovni(v));	
			if(e!=0)
			{
				
				int h(0);
				while(h<koliko_puta*e)
				{
					for(int i(h);i<h+e;i++)
					{
						for(int j(0);j<v.at(i-h);j++)
						{
							std::cout<<std::left<<std::setw(3)<<pok[i][j];
						}
						std::cout<<std::endl;
						delete[] pok[i];
					}
					h+=e;
				}
				delete[] pok;
			}
			
			if(e==0)
			{
				e=v.size();	
				int h(0);
				while(h<koliko_puta*e)
				{
					for(int i(h);i<h+e;i++)
					{
						for(int j(0);j<v.at(i-h);j++)
						{
							std::cout<<std::left<<std::setw(3)<<pok[i][j];
						}
						std::cout<<std::endl;
						delete[] pok[i];
					}
					h+=e;
				}
				delete[] pok;
			}
		}
		
		if(al==0)
		{
			int koliko_puta;
			int** pok=AlocirajKontinualno<int>(v,koliko_puta);
			std::cout<<"Dinamicki alocirana matrica:"<<std::endl;
			int e(Osnovni(v));	
			if(e!=0)
			{
				
				int h(0);
				while(h<koliko_puta*e)
				{
					for(int i(h);i<h+e;i++)
					{
						for(int j(0);j<v.at(i-h);j++)
						{
							std::cout<<std::left<<std::setw(3)<<pok[i][j];
						}
						std::cout<<std::endl;
					}
					h+=e;
				}
				delete[] pok[0];
				delete[] pok;
			}
			if(e==0)
			{
				e=v.size();	
				int h(0);
				while(h<koliko_puta*e)
				{
					for(int i(h);i<h+e;i++)
					{
						for(int j(0);j<v.at(i-h);j++)
						{
							std::cout<<std::left<<std::setw(3)<<pok[i][j];
						}
						std::cout<<std::endl;
					}
					h+=e;
				}
				delete[] pok[0];
				delete[] pok;
			}			
		}
	}
	catch(std::bad_alloc)
	{
		std::cout<<"Nedovoljno memorije!";
	}
	catch(const char poruka[])
	{
		std::cout<<"Izuzetak: "<<poruka;
	}
	catch(std::domain_error Izuzetak)
	{
		std::cout<<"Izuzetak: "<<Izuzetak.what();
	}
	return 0;
}