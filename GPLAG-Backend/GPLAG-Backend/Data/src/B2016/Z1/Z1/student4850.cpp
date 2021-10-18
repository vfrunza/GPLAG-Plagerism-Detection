/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <cmath>
#include <vector>
using std::cout;
using std::cin;
bool JesiLiOpak(int a)
{
	int br0=0,br1=0,br2=0;
	
	while(a!=0)
	{
	if(a%3==0)
	br0++;
	if(a%3==1)
	br1++;
	if(a%3==2)
	br2++;
	a/=3;
	}
	if( (br0%2==0 || br0==0) && (br1%2==0 || br1==0) && (br2%2==0 || br2==0))
	return true;
	else return false;
}
bool JesiLiOdvratan(int a)
{
	int br0=0,br1=0,br2=0;
	
	while(a!=0)
	{
	if(a%3==0)
	br0++;
	if(a%3==1)
	br1++;
	if(a%3==2)
	br2++;
	a/=3;
	}
	if( (br0%2==1 || br0==0) && (br1%2==1 || br1==0) && (br2%2==1 || br2==0))
	return true;
	else return false;
}
std::vector<int> IzdvojiGadne(std::vector<int>v,bool a){
	std::vector<int>v1;
		for(int i=0;i<v.size();i++)
		{
			if(JesiLiOpak(v[i]) && a)
			v1.push_back(v[i]);
			if(JesiLiOdvratan(v[i]) && !a)
			v1.push_back(v[i]);
		}	
		for(int i=0;i<v1.size();i++)
		{
			for(int j=i+1;j<v1.size();j++)
			{
				if(v1[j]==v1[i])
				{
					for(int k=j;k<v1.size()-1;k++)
					v1[k]=v1[k+1];
					v1.resize(v1.size()-1);
					j--;
				}
			}
		}
		return v1;
}
int main(){
std::vector<int>v;
	int n;
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	do {
		cin>>n;
		v.push_back(n);

}while(n!=0);
				std::vector<int>v1=IzdvojiGadne(v,true);
				cout<<"Opaki: ";
				for(int i=0;i<v1.size();i++)
				if(v1[i]!=0)
				cout<<v1[i]<<" ";
				cout<<std::endl;
				cout<<"Odvratni: ";
				std::vector<int>v2=IzdvojiGadne(v,false);
				for(int i=0;i<v2.size();i++)
				if(v2[i]!=0)
				cout<<v2[i]<<" ";
}
