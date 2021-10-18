/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <deque>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::deque;


vector <int> IzdvojiGadne(vector <int> niz, bool tacnost)
{
	vector <int>pravi, kopija1, kopija2, podloga{0,0,0};
	deque <int> temp;
	bool parnost;
	int s, moze;
	
	kopija2=podloga;
	
	if (tacnost==true)
	{
		for (int i=0; i<niz.size(); i++)
		{
			parnost=true;
			kopija1=niz;
			podloga=kopija2;
			temp.resize(0);
			while (niz[i]!=0)
			{
				s=niz[i]%3;
				niz[i]=niz[i]/3;
				temp.push_front(s);
			}
			
			for (int j=0; j<temp.size(); j++)
			{
				if (temp[j]==0)
				{
					podloga[0]++;
				}
				
				else if (temp[j]==1)
				{
					podloga[1]++;
				}
				
				else if (temp[j]==2)
				{
					podloga[2]++;
				}
			}
			
			for (int k=0; k<podloga.size(); k++)
			{
				if (podloga[k]>0)
				{
					if (podloga[k]%2!=0)
					{
						parnost=false;
					}
				}
			}
			
			if (parnost==true)
			{
				moze=1;
				for (int m=0; m<pravi.size(); m++)
				{
					if (pravi[m]==kopija1[i])
					{
						moze=0;
					}
				}
				if (moze==1)
				{
					pravi.push_back(kopija1[i]);
				}
			}
		}
	}
	
	
	
	else if (tacnost==false)
	{
		for (int i=0; i<niz.size(); i++)
		{
			parnost=false;
			kopija1=niz;
			podloga=kopija2;
			temp.resize(0);
			while (niz[i]!=0)
			{
				s=niz[i]%3;
				niz[i]=niz[i]/3;
				temp.push_front(s);
			}
			
			for (int j=0; j<temp.size(); j++)
			{
				if (temp[j]==0)
				{
					podloga[0]++;
				}
				
				else if (temp[j]==1)
				{
					podloga[1]++;
				}
				
				else if (temp[j]==-1)
				{
					podloga[1]++;
				}
				
				else if (temp[j]==2)
				{
					podloga[2]++;
				}
				
				else if (temp[j]==-2)
				{
					podloga[2]++;
				}
			}
			
			for (int k=0; k<podloga.size(); k++)
			{
				if (podloga[k]>0)
				{
					if (podloga[k]%2==0)
					{
						parnost=true;
					}
				}
			}
			
			if (parnost==false)
			{
				moze=1;
				for (int m=0; m<pravi.size(); m++)
				{
					if (pravi[m]==kopija1[i])
					{
						moze=0;
					}
				}
				if (moze==1)
				{
					pravi.push_back(kopija1[i]);
				}
				
			}
		}
	}
	
	return pravi;
}

int main ()
{
	int n(1);
	bool tacnost(true);
	vector<int> niz, niza, nizb;
	
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	while (n!=0)
	{
		cin>>n;
		if (n!=0)
		{
			niz.push_back(n);
		}
	}
	
	niza=IzdvojiGadne(niz,tacnost);
	cout<<"Opaki: ";
	for (int i=0; i<niza.size(); i++)
	{
		if (i==niza.size()-1)
		{
			cout<<niza[i];
		}
		
		else
		{
			cout<<niza[i]<<" ";
		}
	}
	cout<<endl;

	tacnost=false;
	
	nizb=IzdvojiGadne(niz,tacnost);
	cout<<"Odvratni: ";
	for (int j=0; j<nizb.size(); j++)
	{
		if (j==nizb.size()-1)
		{
			cout<<nizb[j];
		}
		
		else
		{
			cout<<nizb[j]<<" ";
		}
	}
	

	
	return 0;
}