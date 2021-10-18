
#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

std::vector<int> Ternarni (int n) 
{
	std::vector<int> br(3) ;
	
	while(n!=0)
	{
		int b=abs(n%3);
		if(b==0) br[0]++;
		if(b==1) br[1]++;
		if(b==2) br[2]++;
		n=n/3;
		
	}
	
	return br;
	
	
}
int Gadan(int n)
{
	std::vector<int> brojaci= Ternarni(n) ;
	if(brojaci[0] % 2==0 && brojaci[1]%2==0 && brojaci[2]%2==0) return 1; //statement true
	else if((brojaci[0] % 2!=0 || brojaci[0]==0)  && (brojaci[1]%2!=0  || brojaci[1]==0) && (brojaci[2]%2!=0 ||brojaci[2]==0)) return 0; //statement false
	else return -1;
}





std::vector<int> IzdvojiGadne ( std::vector<int > v, bool brojevi )
{
	int n=v.size();
	if(n==0)
	{
		return v;
	}
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(v[i]==v[j])
			{
				for( int k=j; k<n-1; k++)
				{
					v[k]=v[k+1];
				}
				n--; 
				j--;
			}
		}
	}
	
	v.resize(n);
	
	std::vector<int> vector ;
	for(int i=0; i<=v.size()-1; i++)
	{
		
		if(Gadan(v[i])==brojevi) vector.push_back(v[i]);
		if(i==v.size()-1) break;
	}
	
	return vector;
	
}


int main ()
{
	cout<<"Unesite brojeve (0 za prekid unosa): ";
	
	std::vector<int> v;
	int n;	
		do{
			n=0;
			cin>>n;
			if(n==0) break;
			else v.push_back(n);
			
		}while(n!=0);
	auto vector1(IzdvojiGadne(v,true));
	auto vector2(IzdvojiGadne(v,false));
	
	cout<<"Opaki: ";
	for(int i=0; i<vector1.size(); i++)
	{
		cout<<vector1[i]<<" ";
	}
	cout<<endl<<"Odvratni: ";
	for( int i=0; i<vector2.size(); i++)
	{
		cout<<vector2[i]<<" ";
	}
	
	return 0;
}