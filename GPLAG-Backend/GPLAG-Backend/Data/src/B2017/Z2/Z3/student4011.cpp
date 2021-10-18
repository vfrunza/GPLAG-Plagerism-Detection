/*B 2017/2018, Zadaća 2, Zadatak 3
	
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
#include <iomanip>

using namespace std;

bool JelPeriodicna(vector<int>v,int &period)
{    
    
	for(int i=0;i<v.size();i++)
	{	
		int temp=1;
		for(int j=i+1;j<v.size();j++)
			if(v[i]!=v[j]) temp++;
			else {period=temp;break;}
		
		for(int j=i;j<v.size();j+=period)
			if(v[i]!=v[j])return false;

	}
	
	return true;
}


int **AlocirajFragmentirano(vector<int> &v,int &koliko_puta)//AlocirajFragmentirano
{   
	int period;int **mat;
	
	if(JelPeriodicna(v,period))
	{
		while(v.size()%period!=0)
			v.push_back(v[v.size()-period]);
		
		int max=v[0];
		for(int i=1;i<v.size();i++)
				if(v[i]>max) max=v[i];
			
		mat=new int *[v.size()];
		for(int i=0;i<v.size();i++)
			mat[i]=new int[v[i]];
			
		for(int i=0;i<v.size();i++)
		{   int temp=max;
			for(int j=v[i]-1;j>=0;j--)
			{
				mat[i][j]=temp;
				temp--;
			}
		}
	}
	else if(!JelPeriodicna(v,period))
	{   
		int temp=v.size();
		for(int i=0;i<temp;i++)
			v.push_back(v[i]);
		
		int max=v[0];
		for(int i=1;i<v.size();i++)
				if(v[i]>max) max=v[i];
		
		mat=new int *[v.size()];
		for(int i=0;i<v.size();i++)
			mat[i]=new int[v[i]];
			
		for(int i=0;i<v.size();i++)
		{   int temp=max;
			for(int j=v[i]-1;j>=0;j--)
			{
				mat[i][j]=temp;
				temp--;
			}
		}
	}
	return mat;
}






int **AlocirajKontinualno(vector<int> &v,int &koliko_puta)//AlocirajKontinualno
{
	int period;int **mat;
	
	if(JelPeriodicna(v,period))
	{
		while(v.size()%period!=0)
		{
			v.push_back(v[v.size()-period]);
		}
		
		int suma=0;
	
		for(int i=0;i<v.size();i++)
			suma+=v[i];
	    
	    mat=new int *[v.size()];
		mat[0]=new int[suma];
		for(int i=1;i<v.size();i++)
			mat[i]=mat[i-1]+v[i-1];
			
		for(int i=0;i<v.size();i++)
		{  
			int temp=1;
			for(int j=v[i]-1;j>=0;j--)
			{
				mat[i][j]=temp;
				temp++;
			}
		}
		
	}
	else if(!JelPeriodicna(v,period))
	{   
		int temp=v.size();
		for(int i=0;i<temp;i++)
			v.push_back(v[i]);
		
		int suma=0;
	
		for(int i=0;i<v.size();i++)
			suma+=v[i];
	    
	    mat=new int *[v.size()];
		mat[0]=new int[suma];
		for(int i=1;i<v.size();i++)
			mat[i]=mat[i-1]+v[i-1];
			
		for(int i=0;i<v.size();i++)
		{  
			int temp=1;
			for(int j=v[i]-1;j>=0;j--)
			{
				mat[i][j]=temp;
				temp++;
			}
		}
	}
	return mat;
}


int main ()
{	
	
	int koliko_puta;
	
	cout<<"Unesite broj elemenata vektora: ";
	int n;cin>>n;
	cout<<"Unesite elemente vektora: ";
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	
	cout<<"Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
	cin>>n;
	try {
	int **mat;
	if(n==1)	
		mat=AlocirajFragmentirano(v,koliko_puta);
	else if(n==0)
		mat=AlocirajKontinualno(v,koliko_puta);
	
	cout<<"Dinamicki alocirana matrica:"<<endl;

	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<v[i];j++)
			cout<<setw(3)<<left<<mat[i][j];
		cout<<endl;
	}
	
	
	if(n==1)
	{
		for(int i=0;i<v.size();i++)
			delete[] mat[i];
		delete []mat;
	}
	else if(n==0)
	{
		delete [] mat[0];
		delete [] mat;
	}
	}
	
	return 0;
}