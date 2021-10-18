/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<vector<double>> RastuciPodnizovi(vector<double> v)
{
	 
	int n=1,br1=0,br=1,br2=0;
	vector<vector<double>> mat;
	if(v.size()==0)return mat;
	for(int i=0;i<v.size()-1;i++)
	{
		if(v[i]<=v[i+1])
		{   br=1;
			br2=br1;
			br1++;
		while(v[i]<=v[i+1]){br++;if(i+2==v.size())break;i++;}
		
	mat.resize(br1);
	for(int k=br2;k<mat.size();k++)
	mat[k].resize(br);
		}
	}
	
	
	int k=0;
	for(int i=0;i<v.size()-1;i++)
	{  n=1; 
		if(v[i]<=v[i+1])
		{
			mat[k][0]=v[i];
				for(int j=i+1;j<v.size();j++)
				{ 
					if(v[j]>=v[j-1])
					{   
						mat[k][n]=v[j];
						n++;
					}
					else break;
					i=j-1;
				}
				k++;
		}
			        
	}
	return mat;
}
vector<vector<double>> OpadajuciPodnizovi(vector<double> v)
{
	int n=1,br1=0,br=1,br2=0;
	vector<vector<double>> mat;
	if(v.size()==0)return mat;
	for(int i=0;i<v.size()-1;i++)
	{
		if(v[i]>=v[i+1])
		{   br=1;
			br2=br1;
			br1++;
		while((v[i]>=v[i+1])){br++;if(i+2==v.size())break;i++;}
		
	mat.resize(br1);
	for(int k=br2;k<mat.size();k++)
	mat[k].resize(br);
		}
	}
	
	
	int k=0;
	for(int i=0;i<v.size()-1;i++)
	{  n=1; 
		if((v[i]>=v[i+1]) && (i<v.size()-1))
		{	
			mat[k][0]=v[i];
				for(int j=i+1;j<v.size();j++)
				{ 
					if(v[j]<=v[j-1])
					{   
						mat[k][n]=v[j]; 
						n++;
					}
					else  break;
					i=j-1;
				}
				k++; 
		}
			        
	}
	return mat;
}

int main ()
{
	int  a;
	double n;
	vector<vector<double>>mat,mat1;
	vector<double>v;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>a;
	cout<<"Unesite elemente vektora: ";
	for(int i=0;i<a;i++)
	{
		cin>>n;
		v.push_back(n);
	}
	cout<<"Maksimalni rastuci podnizovi:"<<endl;
	mat1=RastuciPodnizovi(v);
	for(int i=0;i<mat1.size();i++){
	for(int j=0;j<mat1[i].size();j++)
	cout<<mat1[i][j]<<" ";
	cout<<endl;
	}
	cout<<"Maksimalni opadajuci podnizovi:"<<endl;
	mat=OpadajuciPodnizovi(v);
	for(int i=0;i<mat.size();i++){
	for(int j=0;j<mat[i].size();j++)
	cout<<mat[i][j]<<" ";
	cout<<endl;
	}
	
	return 0;
}