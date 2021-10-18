#include <iostream>
#include <vector>
#include <stdexcept>
#include <new>
#include <type_traits>
#include <iomanip>

using std::cout;
using std::cin;
using std::vector;

template <typename Tip>
bool DaLiJePeriodicno(const vector<Tip> &v, int p)
{
	if (v.size()==1 || v.size()-p==0)
		return false;
		
	for(int i=0; i<v.size() - p; i++)
		if (v[i]!=v[i+p])
			return false;
			
	return true;	
}

template<typename Tip> 
int Periodicnost(const vector<Tip> &v)
{
	for(int i=1; i<v.size(); i++)
		if (DaLiJePeriodicno(v,i))
			return i;
	
	return 0;		
}

template <typename Tip>
int ** AlocirajFragmentirano(const vector<Tip> &v, int &koliko_puta)
{
	if (v.size()<=0)
		throw std::domain_error("Prazan vektor!");
	
	for(int i=0; i<v.size(); i++)
		if (v[i]<=0)
			throw std::domain_error("Neispravan vektor!");
	
	int p;
	bool periodicno=false;
	p=Periodicnost(v);
	if (p!=0)
		periodicno=true;

	//DA LI MOGU UPISIVATI U MATRICU POSTO SAM STAVIO TIP A TAMO **POK
	Tip max(0);
	for(int i=0; i<v.size(); i++)
		if (v[i]>max)
			max=v[i];

	int duzina = v.size(), **pok;
	if (periodicno)
	{
		if (duzina % p==0)
			koliko_puta=duzina/p;
		else if (duzina % p!=0)
		{
			while(1)
			{
				if (duzina % p==0)
					break;
				duzina++;	
			}
			koliko_puta=duzina/p;
		}
		try
		{
			pok=new int *[duzina]{};
			int k(0);
			for(int i=0; i<duzina; i++)
			{
				try
				{
					pok[i]=new int [v[k]];
					if (k==v.size()-1)
						k=v.size()-p;
					else 
						k++;
				}
				catch(std::bad_alloc)
				{
					for(int i=0; i<duzina; i++)
						delete[] pok[i];
					delete[] pok;
					throw;
				}
			}
		}	
		catch(std::bad_alloc)
		{
			throw;
		}
		
		int upisi, k(0);
		Tip var;
		for(int i=0; i<duzina; i++)
		{
			upisi=v[k];
			if (k==v.size() - 1)
				k=v.size()-p;
			else
				k++;
			var=max;	
			for(int j=upisi-1; j>=0; j--)
			{
				pok[i][j]= var;
				var--;
			}	
		}
		
	}
	
	else if (periodicno==false)
	{
		koliko_puta=2;
		duzina*=2;
		try
		{
			pok=new int *[duzina]{};
			int k(0);
			for(int i=0; i<duzina; i++)
			{
				try
				{
					pok[i]=new int [v[k]];
					if (k==v.size()-1)
						k=0;
					else 
						k++;
				}
				catch(std::bad_alloc)
				{
					for(int i=0; i<duzina; i++)
						delete[] pok[i];
					delete[] pok;		
					throw;	
				}
			
			}
		
		}
		catch(std::bad_alloc)
		{
			throw;
		}
	
		int upisi, k(0);
		Tip var;
		for(int i=0; i<duzina; i++)
		{
			upisi=v[k];
			if (k==v.size() - 1)
				k=0;
			else 
				k++;
			var=max;	
			for(int j=upisi-1; j>=0; j--)
			{
				pok[i][j]=var;
				var--;
			}	
		}
	}	
	
	return pok;
}

template<typename Tip>
int **AlocirajKontinualno (const vector<Tip> &v, int &koliko_puta)
{
	
	if (v.size()<=0)
		throw std::domain_error("Prazan vektor!");
	
	for(int i=0; i<v.size(); i++)
		if (v[i]<=0)
			throw std::domain_error("Neispravan vektor!");
			
	int p;
	bool periodicno=false;
	
	p=Periodicnost(v);
	if (p!=0)
		periodicno=true;
	

	int duzina;
	duzina=v.size();
	int k(0);
	Tip suma(0);
	int **pok;
	
	// AKO JE PERIODICNO
	if (periodicno)
	{
		if (duzina % p==0)
			koliko_puta=duzina/p;
		if (duzina % p!=0)
		{
			while(1)
			{
				if (duzina % p==0)
					break;
				duzina++;	
			}
			koliko_puta=duzina/p;
		}
		for(int i=0; i<duzina; i++)
		{
			suma+=v[k];
			if (k==v.size()-1)
				k=v.size()-p;
			else 
				k++;
		}
		try
		{
			pok=new int*[duzina];
			try
			{
				pok[0]=new int[suma];
				k=0;
				for(int i=1; i<duzina; i++)
				{
					pok[i]=pok[i-1] + v[k];
					if (k==v.size()-1)
						k=v.size() - p;
					else 
						k++;
				}
			}
			catch(std::bad_alloc)
			{
				delete[] pok;
				throw;
			}
		}
		catch(std::bad_alloc)
		{
			throw;
		}
		
		int upisi;
		k=0;
		for(int i=0; i<duzina; i++)
		{
			upisi=v[k];
			if (k==v.size() - 1)
				k=v.size() - p;
			else 
				k++;
			for(int j=0; j<upisi; j++)
				pok[i][j]=upisi - j;
		}
	}
	
	
	else if (periodicno==false)
	{
		koliko_puta=2;
		duzina*=2;
		for(int i=0; i<duzina; i++)
		{
			suma+=v[k];
			if (k==v.size()-1)
				k=0;
			else 
				k++;
		}
		try
		{
			pok=new int*[duzina];
			try
			{
				pok[0]=new int[suma];
				k=0;
				for(int i=1; i<duzina; i++)
				{
					pok[i]=pok[i-1] + v[k];
					if (k==v.size()-1)
						k=0;
					else 
						k++;
				}
			}
			catch(std::bad_alloc)
			{
				delete[] pok;
				throw;
			}
		}
		catch(std::bad_alloc)
		{
			throw;
		}
	
		int upisi;
		k=0;
		for(int i=0; i<duzina; i++)
		{
			upisi=v[k];
			if (k==v.size() - 1)
				k=0;
			else 
				k++;
			for(int j=0; j<upisi; j++)
				pok[i][j]=upisi - j;
		}
	}	
	
	return pok;
}


int main ()
{
	vector<int> vektor;
	int vel;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>vel;
	cout<<"Unesite elemente vektora: ";
	for(int i=0; i<vel; i++)
	{
		int br;
		cin>>br;
		vektor.push_back(br);
	}
	int alo;
	cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	cin>>alo;
	int **pok;
	int koliko_puta;
	if (alo==1)
	{
		try
		{
			int duzina;
			duzina=vektor.size();
			pok=AlocirajFragmentirano(vektor, koliko_puta);
	
			int k(0), upisi, p;
			
			p=Periodicnost(vektor);
			if (p!=0)
			{
				if (duzina % koliko_puta!=0)
				{
					while(1)
					{
						if (duzina % koliko_puta!=0)
							duzina++;
						else 
							break;	
					}
				}
				cout<<"Dinamicki alocirana matrica: \n";
				for(int i=0; i<duzina; i++)
				{
					upisi=vektor[k];
					if (k==vektor.size() - 1)
						k=vektor.size() - p;
					else 
						k++;
					for(int j=0; j<upisi; j++)
						cout<<std::left<<std::setw(3)<<pok[i][j];
					cout<<"\n";	
				}
			}
			else if (p==0)
			{
				duzina*=2;
				cout<<"Dinamicki alocirana matrica: \n";
				for(int i=0; i<duzina; i++)
				{
					upisi=vektor[k];
					if (k==vektor.size() - 1)
						k=0;
					else 
						k++;
					for(int j=0; j<upisi; j++)
						cout<<std::left<<std::setw(3)<<pok[i][j];
					cout<<"\n";	
				
				}
			}
			
			for(int i=0; i<duzina; i++)
				delete[] pok[i];
			delete[] pok;
		}
		catch(std::bad_alloc)
		{
			cout<<"Neuspjesna alokacija";
		}
		catch(std::domain_error izuzetak)
		{
			cout<<"Izuzetak: "<<izuzetak.what();
		}
	}
	
	else if(alo==0)
	{
		try
		{
			int duzina;
			duzina=vektor.size();
			pok=AlocirajKontinualno(vektor, koliko_puta);
		
			int k(0), upisi, p;
			
			p=Periodicnost(vektor);
			if (p!=0)
			{
				if (duzina % koliko_puta!=0)
				{
					while(1)
					{
						if (duzina % koliko_puta!=0)
							duzina++;
						else
							break;
					}
				}
				cout<<"Dinamicki alocirana matrica: \n";
				for(int i=0; i<duzina; i++)
				{
					upisi=vektor[k];
					if (k==vektor.size() - 1)
						k=vektor.size() - p;
					else 
						k++;
					for(int j=0; j<upisi; j++)
						cout<<std::left<<std::setw(3)<<pok[i][j];
					cout<<"\n";	
				}
			}
			else if (p==0)
			{
				duzina*=2;
				cout<<"Dinamicki alocirana matrica: \n";
				for(int i=0; i<duzina; i++)
				{
					upisi=vektor[k];
					if (k==vektor.size() - 1)
						k=0;
					else 
						k++;
					for(int j=0; j<upisi; j++)
						cout<<std::left<<std::setw(3)<<pok[i][j];
					cout<<"\n";	
				}
			}
			
			delete[] pok[0];
			delete[] pok;
		}
		catch(std::bad_alloc)
		{
			cout<<"Neuspjesna alokacija";
		}
		catch(std::domain_error izuzetak)
		{
			cout<<"Izuzetak: "<<izuzetak.what();
		}
	}
	
	return 0;
}