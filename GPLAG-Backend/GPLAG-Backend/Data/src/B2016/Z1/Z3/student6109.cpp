/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> v)
{
	int br_redova(0);
	
	for(int i=0;i<v.size()-1;i++)
	{
		if(v[i]<=v[i+1])
		{
			while(v[i]<=v[i+1] && i<v.size()-2)
			{
				i++;
			}
			br_redova++;
		}
	}
	
	Matrica M(br_redova, std::vector<double> (0));
	std::vector<double> v1;
	int k(0);
	
	for(int i=0;i<v.size()-1;i++)
	{
		if(v[i]<=v[i+1])
		{
			v1.resize(0);
			while(v[i]<=v[i+1] && i<v.size()-2)
			{
				v1.push_back(v[i]);
				i++;
			}
			v1.push_back(v[i]);
			
			if(i==v.size()-2)
			{
				i++;
				v1.push_back(v[i]);
			}
			
			M[k].resize(v1.size());
			for(int j=0;j<v1.size();j++)
				M[k][j]=v1[j];
			
			k++;
		}
	}
	return M;
}


Matrica OpadajuciPodnizovi(std::vector<double> v)
{
	int br_redova(0);
	
	for(int i=0;i<v.size()-1;i++)
	{
		if(v[i]>=v[i+1])
		{
			while(v[i]>=v[i+1] && i<v.size()-2)
				i++;
			br_redova++;
		}
	}
	
	Matrica M(br_redova, std::vector<double>(0));
	std::vector<double> v1;
	int k(0);
	
	for(int i=0;i<v.size()-1;i++)
	{
		if(v[i]>=v[i+1])
		{
			v1.resize(0);
			while(v[i]>=v[i+1] && i<v.size()-2)
			{
				v1.push_back(v[i]);
				i++;
			}
			v1.push_back(v[i]);
			if(i==v.size()-2) 
			{
				i++;
				v1.push_back(v[i]);
			}
			
			M[k].resize(v1.size());
			for(int j=0;j<v1.size();j++)
				M[k][j]=v1[j];
			
			k++;
		}
	}
	return M;
}

int main ()
{
	std::vector<double> v;
	int n;
	
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++)
	{
		double a;
		std::cin>>a;
		v.push_back(a);
	}
	
	Matrica M(RastuciPodnizovi(v));
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	
	for(int i=0;i<M.size();i++)
	{
		for(int j=0;j<M[i].size();j++)
		{
			std::cout<<M[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	Matrica N(OpadajuciPodnizovi(v));
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	
	for(int i=0;i<N.size();i++)
	{
		for(int j=0;j<N[i].size();j++)
		{
			std::cout<<N[i][j]<<" ";
		}
		std::cout<<std::endl;
	}

	return 0;
}