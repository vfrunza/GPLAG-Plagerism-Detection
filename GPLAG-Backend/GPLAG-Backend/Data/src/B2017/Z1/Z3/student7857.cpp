/*B 2017/2018, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <iomanip>
using namespace std;
int brojredova (deque<vector<unsigned int>> m)
{
	return m.size();
}
int brojkolona(deque<vector<unsigned int>> m)
{
	return m.at(0).size();
}
bool stependvojke(int n)
{
	int suma=0;
	int d;
	d=n;
	while(d!=1)
	{
		d/=2;
		suma+=d;
	}
	if((suma+1)==n)
	return true;
	else return false;
}
deque<vector<unsigned int>> MaksimalniPodnizoviStepenaDvojke(vector<int> v,bool uslov)
{
	deque<vector<unsigned int>> d;
	vector<unsigned int> t;
	vector<int> e;
	if(uslov==true){
		
	for(int i=0;i<v.size();i++)
	{
		
		if( stependvojke(v.at(i)) && v.at(i)<v.at(i+1) && stependvojke(v.at(i+1)) /*||
		(stependvojke(v.at(i)) && stependvojke(v.at(i-1)) && v.at(i-1)<v.at(i))*/)
		{
			t.push_back(v.at(i));
		}
		else if(stependvojke(v.at(i)) && stependvojke(v.at(i+1))==false)
		{
			t.push_back(v.at(i));
		}else{

			d.push_back(t);
			t.clear();}
		if(i==v.size())
		{
			if(v.at(i)>v.at(i-1) && stependvojke(v.at(i)) && stependvojke(v.at(i-1)))
			{
				t.push_back(v.at(i));
			}
		}
	}
	}
	
	
	

	
	
	

if(uslov==false)
{
	for(int i=0;i<v.size()-1;i++)
	{
		
		
		{
			t.push_back(v.at(i));
			d.push_back(t);
		}
	}
	for(int i=0,j=0;i<d.size(),j<t.size();i++,j++)
	{
		cout<<d.at(i).at(j)<<" ";
	}
}
return d;

}


int main ()
{
	int n,brojevi;
	vector<int> v;
	cout<<"Unesite koliko ce biti elemenata: ";
	cin>>n;
	if(n<0 || n==0)
	{
		cout<<"greska!"<<endl;
		return 0;
	}
	cout<<"Unesite elemente: ";
	for(int i=0;i<n;i++)
	{
		cin>>brojevi;
		v.push_back(brojevi);
	}
	deque<vector<unsigned int>> poziv;
	bool uslov=true;
	/*enum Smjer {Rastuci,Opadajuci};*/
	cout<<"Rjesenje je "<<endl;
	poziv=MaksimalniPodnizoviStepenaDvojke(v,uslov);
	/*cout<<brojkolona(poziv)<<" ";
	cout<<brojredova(poziv);
	*/for(int i=0;i<brojredova(poziv);i++)
{
	for(int j=0;j<brojkolona(poziv);j++)
	{
	
	cout<<poziv.at(i).at(j)<<" ";
}
cout<<endl;
}
	return 0;
}