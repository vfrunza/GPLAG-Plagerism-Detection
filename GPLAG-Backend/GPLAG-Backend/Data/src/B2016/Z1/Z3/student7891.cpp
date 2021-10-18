
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

typedef std::vector<std::vector<double>> VektorVektora ;

VektorVektora RastuciPodnizovi( std::vector<double>v )
{
	int n=v.size();
	VektorVektora mat;
	for(int i=0; i<n; i++)
	{
		
		
		for(int j=i+1; j<n; j++)
		{
			std::vector<double> vrste ;
		if(i<n && j<n && v[i]<=v[j])
		{
			
			vrste.push_back(v[i]);
		while(i<n && j<n && v[i]<=v[j])
		{
		
			vrste.push_back(v[j]);
			i++; 
			j++;
		
		}
		mat.push_back(vrste);
		}
		else break;
		j--;
		
	}
	}
	return mat;
	
	
}

VektorVektora OpadajuciPodnizovi( std::vector<double>v )
{
	int n=v.size();
	VektorVektora mat;
	for(int i=0; i<n; i++)
	{
		
		
		for(int j=i+1; j<n; j++)
		{
			std::vector<double> vrste ;
		if(i<n && j<n && v[i]>=v[j] )
		{
			
		
		while(i<n && j<n && v[i]>=v[j] )
		{
			
			vrste.push_back(v[i]);
			i++; 
			j++;
			
		
		}
		vrste.push_back(v[i]);
		mat.push_back(vrste);
		}
		else break;
		j--;
		
	}
	}
	return mat;
	
	
}


int main ()

{
	cout<<"Unesite broj elemenata vektora: ";
	int n;
	cin>>n;
	cout<<"Unesite elemente vektora: ";
	std::vector<double> v;
	
	for(int i=0; i<n; i++)
	{
		double broj;
		cin>>broj;
		v.push_back(broj);

	}
	VektorVektora vector1=RastuciPodnizovi(v) ;
	VektorVektora vector2=OpadajuciPodnizovi(v) ;
	
	cout<<"Maksimalni rastuci podnizovi: \n";
	for(int i=0; i<vector1.size(); i++)
	{
		for(int j=0; j<vector1[i].size(); j++)
		{
			cout<<vector1[i][j]<<" ";
		}
		cout<<endl;
		
	}
	cout<<"Maksimalni opadajuci podnizovi: \n";
	
	for(int i=0; i<vector2.size(); i++)
	{
		for(int j=0; j<vector2[i].size(); j++)
		{
			cout<<vector2[i][j]<<" ";
		}
		cout<<endl;
		
	}
	
	 
	 
	return 0;
}