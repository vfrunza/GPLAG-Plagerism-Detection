/*B 2017/2018, Zadaća 2, Zadatak 2
	
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
#include <deque>
#include <stdexcept>
#include <type_traits>
#include <iomanip>

using namespace std;

enum class SmjerKretanja {
 NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo
};

template<typename kontejner>
void IspisiKocku(kontejner kont)
{    
	cout<<"Pjescani sat unesene matrice je:"<<endl;
	for(auto a:kont)
	{	int br=0;
		for(auto b:a)
		{	
			int uvuci=br+1;
			if (br>kont.size()/2) uvuci=kont.size()-uvuci+1;
			int br1=0;
			for(auto c:b)
			{	
			    if(br>0 && br<kont.size()-1 && br1>0 && br1<kont.size()-1)uvuci=1;
				cout<<setw((uvuci)*4)<<c;
				br1++;
			}
			br++;
			cout<<endl;
		}
		cout<<endl;
	}
}

template<typename kontejner>
kontejner PjescaniSat(kontejner kont,SmjerKretanja s)
{   
	for(auto a:kont)
	{   
		if(a.size()%2==0) throw length_error("3D kontejner ne zadovoljava uvjet neparnosti");
		for(auto b:kont)
		{
			if(a.size()!=b.size()) throw domain_error("3D matrica nema oblik kocke");
		}
	}

	typename remove_reference<decltype(kont)>::type cube;
	for(int i=0;i<kont.size();i++)
	{   
		typename remove_reference<decltype(kont.at(i))>::type mat;
		if((int)s%2==0)
		{
			for(int j=0;j<kont.size();j++)
			{
				typename remove_reference<decltype(kont.at(i).at(j))>::type v;
					int uvuci=j;
					if(j>kont.size()/2) uvuci=kont.size()-1-j;
				
					for(int k=uvuci;k<kont.size()-uvuci;k++)
					{   	
						switch((int)s)
						{   
							case 0:
						    v.push_back(kont.at(j).at(i).at(k));
							break;
							
							case 2:
							v.push_back(kont.at(i).at(j).at(k));
							break;
							
							case 4:
							v.push_back(kont.at(i).at(k).at(j));
							break;
						}
					}
					mat.push_back(v);
			}
			
		}
		else 
		{
			for(int j=kont.size()-1;j>=0;j--)
			{
				typename remove_reference<decltype(kont.at(i).at(j))>::type v;
					
				  	int uvuci=j;
					if(j>kont.size()/2) uvuci=kont.size()-1-j;
				
					for(int k=uvuci;k<kont.size()-uvuci;k++)
					{ 
						switch((int) s)
						{   
							case 1:
						    v.push_back(kont.at(j).at(i).at(k));
							break;
							
							case 3:
							v.push_back(kont.at(i).at(j).at(k));
							break;
							
							case 5:
							v.push_back(kont.at(i).at(k).at(j));
							break;
						}
					}
					mat.push_back(v);
			}
		}
		cube.push_back(mat);
	}
	
	return cube;
}

int main ()
{	
	
	int n;
	cout<<"Unesite dimenziju (x/y/z): ";
	while(true)
	{
		cin>>n;
		if(n>=0) break;
		else cout<<"Dimenzija nije ispravna, unesite opet: ";
	}
	
	
	vector<deque<deque<int>>> kont(n,deque<deque<int>>(n,deque<int>(n)));
	
	cout<<"Unesite elemente kontejnera: ";
	for(auto &a:kont)
		for(auto &b:a)
			for(auto &c:b)
				cin>>c;
	
	
	
	cout<<"Unesite smjer kretanja [0 - 5]: ";
	while(true)
	{
		cin>>n;
		if(n>=0 && n<=5) break;
		else cout<<"Smjer nije ispravan, unesite opet: ";
	}
	cout<<endl;
	
		try
		{
			kont=PjescaniSat(kont,(SmjerKretanja)n);
			IspisiKocku(kont);
		}
		catch(domain_error e){cout<<"Izuzetak: "<<e.what();}
		catch(length_error e){cout<<"Izuzetak: "<<e.what();}
		
	return 0;
}