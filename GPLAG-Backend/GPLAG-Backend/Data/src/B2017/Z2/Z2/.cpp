#include <iostream>
#include <vector>
using namespace std;
bool TestPerioda (vector <int> v, int p)
{
	int i;
	if(p>=v.size()) return false;
	if(v.size()==1) return false;
	if(p==0) return false;
  for (i=0;i<v.size()-p;i++)
	{
		if(v[i]!=v[i+p]) 
		{
		return false;
		}
	}
	return true;
}
int OdrediOsnovniPeriod (vector <int> v)
{
	int j;
	for (j=1;j<v.size();j++)
	{
		if(TestPerioda(v,j)) return j;
	}
	return 0;
}
int main ()
{
	
	vector <int> v;
	int broj=5;
	
	do
	{
		cin>>broj;
		if (broj!=0) v.push_back(broj);
	} while (broj!=0);
	if(OdrediOsnovniPeriod(v)!=0) cout<<"Slijed je periodican sa osnovnim periodom "<<OdrediOsnovniPeriod(v)<<".";
			else cout<<"Slijed nije periodican!";
			return 0;
	
	
}