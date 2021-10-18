#include <iostream>
#include <vector>
#include <deque>
#include <iomanip>
#include <stdexcept>

using std::vector;
using std::deque;
using std::cin;
using std::cout;

typedef vector<vector<deque<int>>> KontejnerProba;

enum class SmjerKretanja{NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo};

template <typename Kontejner>
Kontejner PjescaniSat(Kontejner kont,SmjerKretanja smjer)
{
	Kontejner novi;
	if (kont.size()==0 && kont.at(0).size()==0 && kont.at(0).at(0).size()==0)
		return novi;
	
	for(int i=0; i<kont.size(); i++)
		for(int j=0; j<kont.at(i).size();j++)
			if (kont.size()!=kont.at(j).size())
				throw std::domain_error("3D matrica nema oblik kocke");
	
	for(int i=0; i<kont.size(); i++)
		for(int j=0; j<kont.at(i).size(); j++)
			if (kont.at(i).size()!=kont.at(i).at(j).size())
				throw std::domain_error("3D matrica nema oblik kocke");
	
	for(int i=0; i<kont.size()-1; i++)
		for(int j=0; j<kont.at(i).size(); j++)
			if (kont.at(i).size()!=kont.at(i+1).size() || kont.at(i).at(j).size()!=kont.at(i+1).at(j).size())
				throw std::domain_error("3D matrica nema oblik kocke");
	
	for(int i=0; i<kont.size(); i++)
		for(int j=0; j<kont.at(i).size(); j++)
			if (kont.at(i).size()%2==0 || kont.at(i).at(j).size()%2==0)
				throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	
	
//	typename std::remove_reference<decltype(kont.at(0))>::type 
	if (smjer==SmjerKretanja::GoreDolje)
	{
		for(int i=0; i<kont.size(); i++)
		{
			int a, b;
			a=0;
			b=kont.at(i).size();
			typename std::remove_reference<decltype(kont.at(0))>::type matrica;
			for(int j=0; j<kont.at(i).size()/2 + 1; j++)
			{
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type vektor;
				for(int k=a; k<b; k++)
					vektor.push_back(kont.at(i).at(j).at(k));
				matrica.push_back(vektor);	
				if (j!=kont.at(i).size()/2)	
				{
					a++;
					b--;
				}	
			}
			a--;
			b++;
			for(int j=kont.at(i).size()/2 + 1; j<kont.at(i).size(); j++)
			{
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type vektor;
				for(int k=a; k<b; k++)
					vektor.push_back(kont.at(i).at(j).at(k));
				matrica.push_back(vektor);	
				a--;
				b++;
			}
			
			novi.push_back(matrica);	
		}
	}
	
	else if(smjer==SmjerKretanja::DoljeGore)
	{
		for(int i=0; i<kont.size(); i++)
		{
			int a,b, red(0);
			a=0;
			b=kont.at(i).size();
			typename std::remove_reference<decltype(kont.at(0))>::type matrica;
			for(int j=kont.at(i).size()-1; j>=kont.at(i).size()/2; j--)
			{
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type vektor;
				for(int k=a; k<b; k++)
					vektor.push_back(kont.at(i).at(j).at(k));
				matrica.push_back(vektor);	
				if (j!=kont.at(i).size()/2)	
				{
					red++;
					a++;
					b--;
				}	
			}
			red++;
			a--;
			b++;
			for(int j=kont.at(i).size()/2 - 1; j>=0; j--)
			{
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type vektor;
				for(int k=a; k<b; k++)
					vektor.push_back(kont.at(i).at(j).at(k));
				matrica.push_back(vektor);	
				red++;
				a--;
				b--;
			}
			novi.push_back(matrica);
		}
	}
	
	else if (smjer==SmjerKretanja::LijevoDesno)
	{
		for(int i=0; i<kont.size(); i++)
		{
			typename std::remove_reference<decltype(kont.at(0))>::type matrica;
			int k(0), red(0), a(0), b;
			b=kont.at(i).size();
			while(k<(kont.at(0).at(0).size()/2 + 1))
			{
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type vektor;
				for(int j=a; j<b; j++)
					vektor.push_back(kont.at(i).at(j).at(k));
				matrica.push_back(vektor);	
				if (k!=kont.at(0).at(0).size()/2)
				{
					a++;
					b--;
				}	
				k++;
				red++;
			}
			a--;
			b++;
			while(k<kont.at(0).at(0).size())
			{
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type vektor;
				for(int j=a; j<b; j++)
					vektor.push_back(kont.at(i).at(j).at(k));
				matrica.push_back(vektor);	
				a--;
				b++;
				red++;
				k++;
			}
			novi.push_back(matrica);
		}
	}
	
	else if(smjer==SmjerKretanja::DesnoLijevo)
	{
		//cout<<"Tu sam";
		for(int i=0; i<kont.size(); i++)
		{
			typename std::remove_reference<decltype(kont.at(0))>::type matrica;
			int red(0), a, b, k;
			a=0;
			b=kont.at(i).size();
			k=kont.at(0).at(0).size()-1;
			while(k>=kont.at(0).at(0).size()/2)
			{
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type vektor;
				for(int j=a; j<b; j++)
					vektor.push_back(kont.at(i).at(j).at(k));
				matrica.push_back(vektor);	
				if (k!=kont.at(0).at(0).size()/2)
				{
					a++;
					b--;
				}
				red++;
				k--;
			}
			a--;
			b++;
			while(k>=0)
			{
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type vektor;
				for(int j=a; j<b; j++)
					vektor.push_back(kont.at(i).at(j).at(k));
				matrica.push_back(vektor);	
				a--;
				b++;
				red++;
				k--;
			}
			novi.push_back(matrica);
		}
	}
	
	else if (smjer==SmjerKretanja::NaprijedNazad)
	{
		int br(0);
		for(int i=0; i<kont.size(); i++)
		{
				int a(0), b;
				b=kont.at(0).size();
				typename std::remove_reference<decltype(kont.at(0))>::type matrica;
				for(int j=0; j<kont.size()/2; j++)
				{
					typename std::remove_reference<decltype(kont.at(0).at(0))>::type vektor;
					for(int k=a; k<b; k++)
						vektor.push_back(kont.at(j).at(br).at(k));
					matrica.push_back(vektor);	
					a++;
					b--;
				}		
			
				for(int j=kont.size()/2; j<kont.size();j++)
				{
					typename std::remove_reference<decltype(kont.at(0).at(0))>::type vektor;
					for(int k=a; k<b; k++)
						vektor.push_back(kont.at(j).at(br).at(k));
					matrica.push_back(vektor);
					a--;
					b++;
				}
				novi.push_back(matrica);
				br++;
		}
		
	}
	
	else if (smjer==SmjerKretanja::NazadNaprijed)
	{
		int br;
		br=0;
		for(int i=kont.size()-1; i>=0; i--)
		{
			int a(0), b;
			b=kont.at(0).size();
			typename std::remove_reference<decltype(kont.at(0))>::type matrica;
			for(int j=kont.size()-1; j>kont.size()/2; j--)
			{
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type vektor;
				for(int k=a; k<b; k++)
					vektor.push_back(kont.at(j).at(br).at(k));
				matrica.push_back(vektor);
				a++;
				b--;
			}
			for(int j=kont.size()/2; j>=0; j--)
			{
				typename std::remove_reference<decltype(kont.at(0).at(0))>::type vektor;
				for(int k=a; k<b; k++)
					vektor.push_back(kont.at(j).at(br).at(k));
				matrica.push_back(vektor);
				a--;
				b++;
			}
			novi.push_back(matrica);
			br++;
		}
		
	}
	
	return novi;
	
}

int main ()
{
	int x,z,y;
	cout<<"Unesite dimenziju (x/y/z): ";
	
	while(1)
	{
		cin>>x;
		if (x<0)
			cout<<"Dimenzija nije ispravna, unesite opet: ";
		else
			break;
	}
	
	y=x;
	z=x;
	KontejnerProba kont;
	
	kont.resize(x);
	for(int i=0; i<x; i++)
		kont.at(i).resize(y);
	
	cout<<"Unesite elemente kontejnera: ";
	for(int i=0; i<x; i++)
		for(int j=0; j<y; j++)
			for(int k=0; k<z; k++)
				{
					int br;
					cin>>br;
					kont.at(i).at(j).push_back(br);
				}
	int smjer;			
	cout<<"Unesite smjer kretanja [0 - 5]: ";
	while(1)
	{
		cin>>smjer;
		if (smjer<0 || smjer>5)
			cout<<"Smjer nije ispravan, unesite opet: ";
		else 
			break;
	}		
	try
	{
		KontejnerProba vraceni;
		if (smjer==0)
			vraceni=PjescaniSat(kont, SmjerKretanja::NaprijedNazad);
		else if (smjer==1)
			vraceni=PjescaniSat(kont, SmjerKretanja::NazadNaprijed);
		else if (smjer==2)
			vraceni=PjescaniSat(kont, SmjerKretanja::GoreDolje);
		else if (smjer==3)
			vraceni=PjescaniSat(kont, SmjerKretanja::DoljeGore);
		else if (smjer==4)
			vraceni=PjescaniSat(kont, SmjerKretanja::LijevoDesno);
		else if (smjer==5)
			vraceni=PjescaniSat(kont, SmjerKretanja::DesnoLijevo);
		cout<<"\nPjescani sat unesene matrice je: \n";
		cout<<"\n";
		for(int i=0; i<vraceni.size(); i++)
		{
			for(int j=0; j<vraceni.at(i).size(); j++)
			{
				
				if (j<=vraceni.at(i).size()/2)
					for(int k=0;k<j;k++) 
						cout << "    ";
				else 
					for(int k=0;k<vraceni.at(i).size()-1-j; k++) 
						cout << "    ";
				
				for(int k=0; k<vraceni.at(i).at(j).size(); k++)
					cout<<std::setw(4)<<vraceni.at(i).at(j).at(k);
				cout<<"\n";	
			}	
			cout<<"\n";
		}
			
	}
	catch(std::domain_error izuzetak)
	{
		cout<<"\nIzuzetak: "<<izuzetak.what();
	}
	catch(std::length_error izuzetak_dva)
	{
		cout<<"\nIzuzetak: "<<izuzetak_dva.what();
	}
		
	return 0;
}