
#include<iostream>
#include<vector>
#include<iomanip>
#include<limits>
typedef std::vector<std::vector<double> >Matrica;
typedef std::vector<double> Vektor ;
Matrica OpadjuciPodnizovi(Vektor v )
{
	Vektor v1[20];
	int l(0);
		for(int i=0;i<v.size();i++)
		{
		while(i<v.size()&&v[i]>=v[i+1])
		{
			v1[l].push_back(v[i]);
			i++;
		}
		if(i<v.size()&&v[i]<v[i+1])
		{
			v1[l].push_back(v[i]);
		}
		l++;
	 	}	
		Matrica opadajuca(l);
		int i(0);
		for(int k=0;k<l;k++)
		{
			if(v1[k].size()>1)
			{
				opadajuca[i]=v1[k];
				i++;
			}
		}
		return opadajuca;
}
Matrica RastuciPodnizovi(std::vector<double>v )
{
	Vektor v2[20];
	int j(0);
		for(int i=0;i<v.size();i++)
		{
		while(i<v.size()&&v[i]<=v[i+1])
		{
			v2[j].push_back(v[i]);
			i++;
		}
		if(i<v.size()&&v[i]>v[i+1])
		{
			v2[j].push_back(v[i]);
		}
		j++;
	   }	
		Matrica rastuca(j);
		int p(0);
		for(int k=0;k<j;k++)
		{
			if(v2[k].size()>1)
			{
				rastuca[p]=v2[k];
				p++;
			}
		}
		return rastuca;
}
int main ()
{
	int n(0);
	double elementi;
	Vektor v ;
	Matrica Rastuca;
	Matrica Opadajuca;
	std::cout <<"Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::cout <<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++)
	{
		std::cin >> elementi;
		v.push_back(elementi);
	}
	Rastuca=RastuciPodnizovi(v);
	std::cout <<"Maksimalni rastuci podnizovi: "<<std::endl;;
	for(int i=0;i<Rastuca.size();i++)
	{
		for(int j=0;j<Rastuca[i].size();j++)
		{
			std::cout <<Rastuca[i][j]<<" ";
			if(j==Rastuca[i].size()-1) 	std::cout<< std::endl;
		}
	}
	Opadajuca=OpadjuciPodnizovi(v);
	std::cout <<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int j=0;j<Opadajuca.size();j++)
	{
		for(int i=0;i<Opadajuca[j].size();i++)
		{
			std::cout <<Opadajuca[j][i]<<" ";
			if(i==Rastuca[j].size()-1) 	std::cout<< std::endl;
		}
		std::cout<<std::endl;
	}
	return 0;
}