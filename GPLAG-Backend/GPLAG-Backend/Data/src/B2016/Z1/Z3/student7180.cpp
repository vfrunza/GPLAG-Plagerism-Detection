#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;
typedef std::vector<double> Vektor;

Matrica RastuciPodnizovi(Vektor v)
{
    Matrica mat;
    v.resize(v.size()+1);
	Vektor temp;
	double a(v[0]);
	int i=1; 
	do{
		temp.push_back(a);
		if(v[i]<a || i==v.size()-1)
		{
			if(temp.size()>1) mat.push_back(temp);
			temp.resize(0);
		}
		a=v[i];
		i++;
	}while(i<v.size());
	return mat;
}
Matrica OpadajuciPodnizovi(Vektor v)
{
    Matrica mat;
    v.resize(v.size()+1);
	Vektor temp;
	double a(v[0]);

	int i=1;
	do{
		temp.push_back(a);
		if(v[i]>a || i==v.size()-1)
		{
			if(temp.size()>1) mat.push_back(temp);
			temp.resize(0);
		}
		a=v[i];
		i++;
	}while(i<v.size());
	return mat;
}
int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n; 
	std::cin>>n;
	Vektor v;
	v.resize(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i!=v.size(); i++) 
	{
		std::cin>>v[i];
	}
	Matrica mat1=RastuciPodnizovi(v);
	Matrica mat2=OpadajuciPodnizovi(v);
	
	std::cout<<"Maksimalni rastuci podnizovi: ";
	std::cout<<std::endl;
	for(int i=0; i!=mat1.size(); i++)
	{
	    for(int j=0; j!=mat1[i].size(); j++)
	    {
	        std::cout<<mat1[i][j]<<" ";
	    } 
	    std::cout<<std::endl;
	}
	
	std::cout<<"Maksimalni opadajuci podnizovi: ";
	std::cout<<std::endl;
	for(int i=0; i!=mat2.size(); i++)
	{
	    for(int j=0; j!=mat2[i].size(); j++)
	    {
	        std::cout<<mat2[i][j]<<" ";
	    } 
	    std::cout<<std::endl;
	}
	return 0;
}