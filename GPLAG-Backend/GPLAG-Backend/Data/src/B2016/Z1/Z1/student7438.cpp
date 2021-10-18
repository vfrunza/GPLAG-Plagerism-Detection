/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<cmath>
#include<iostream>
#include<vector>
using std::cin;
using std::cout;
using std::vector;
vector<int> IzdvojiGadne(vector<int> a,bool p)
{
	vector<int> a1(a);
	vector<int> b;
	vector<int> c;
	for(int i=0;i<a.size();i++)
	{
		int br0(0),br1(0),br2(0),bristih(0);
		while(a1.at(i)!=0)
		{
			if(a1.at(i)%3==0)
			br0++;
			else if(a1.at(i)%3==1 || a1.at(i)%3==-1)
			br1++;
			else
			br2++;
			a1.at(i)/=3;
		}
		for(int j=0;j<i;j++)
		{
			if(a.at(i)==a.at(j))
			bristih++;
		}
		if((br0%2==0) && (br1%2==0) && (br2%2==0) && bristih==0 && a.at(i)!=0)
		b.push_back(a.at(i));
		else
		{
			/*Povecavamo brojace da brojevi koji se ne pojavljuju u zapisu
			ne bi imali utjecaj na to da li je broj opak ili odvratan*/
			if(br0==0)
			br0++;
			if(br1==0)
			br1++;
			if(br2==0)
			br2++;
			if((br0%2==1) && (br1%2==1) && (br2%2==1) && bristih==0)
			c.push_back(a.at(i));
		}
	}
	if(p)
	return b;
	return c;
}
int main ()
{   int x;
	vector<int> a;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	cin>>x;
	while(x!=0)
	{
		a.push_back(x);
		cin>>x;
	}
	cout<<"Opaki: ";
	if(IzdvojiGadne(a,1).size()>0)
	{
		for(int i=0;i<IzdvojiGadne(a,1).size();i++)
		cout<<IzdvojiGadne(a,1).at(i)<<" ";
	}
	cout<<"\nOdvratni: ";
	if(IzdvojiGadne(a,0).size()>0)
	{
		for(int i=0;i<IzdvojiGadne(a,0).size();i++)
		cout<<IzdvojiGadne(a,0).at(i)<<" ";
	}
	return 0;
}


