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
using namespace std;

vector <int> IzbaciVisak(vector<int> brojevi)
{
	for(unsigned int i=0;i<brojevi.size();i++)
	{
		for(unsigned int j=i+1;j<brojevi.size();j++)
		{
			if(brojevi[i]==brojevi[j])
			{
				brojevi.erase(brojevi.begin()+j);
				j--;
			}
		}
	}
	return brojevi;
}



vector <int> IzdvojiGadne(vector <int>brojevi,bool vratiOpake)
{
	vector <int> opaki;
	vector <int> odvratni;
	vector <int> ispitivani{IzbaciVisak(brojevi)};
	for(int x: ispitivani)
	{
		int m; 
		int n{x};
		int brojac0{0},brojac1{0},brojac2{0};
		do{
			m=n%3;
			n=n/3;
			m=abs(m);
			if(m==0) brojac0++;
			if(m==1) brojac1++;
			if(m==2) brojac2++;
		}while(n!=0);
		if(brojac0%2==0 && brojac1%2==0 && brojac2%2==0)  //ako je broj opak
		{
			opaki.push_back(x);
		}
		else if( (brojac0%2==1 || brojac0==0) && (brojac1%2==1 || brojac1==0) && (brojac2%2==1 || brojac2==0) )
		{
			odvratni.push_back(x);
		}
	}
	if(vratiOpake) return opaki;
	return odvratni;
}
int main ()
{
	vector <int> brojevi;
	cout <<"Unesite brojeve (0 za prekid unosa): ";
	int broj;
	cin >>broj;
	while(broj!=0)
	{
		brojevi.push_back(broj);
		cin >>broj;
	}
	vector<int> opaki;
	opaki=IzdvojiGadne(brojevi,true);
	if(opaki.size()>0)
	{
		cout <<"Opaki: ";
		for(unsigned int i=0;i<opaki.size();i++)
			cout <<opaki[i]<<" ";
		cout <<endl;
	}
	vector <int> odvratni;
	odvratni=IzdvojiGadne(brojevi,false);
	if(odvratni.size()>0)
	{
		cout <<"Odvratni: ";
		for(unsigned int i=0;i<odvratni.size();i++)
			cout<<odvratni[i]<<" ";
	}
	
	return 0;
}