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

typedef std::vector<std::vector<double>> Matrica;


Matrica RastuciPodnizovi(std::vector <double> v)
{
	Matrica m;
	int i,k,j,brojac=0,l=0;
	for(i=0;i<v.size();i++)
	{
		if(v[i]>=v[i+1] && l<=i)
		{
			l=i;
			brojac++;
			if(brojac==1) k=0;
			else k++;
			m.resize(k);
		
			j=0;
			
			do {
				m[k].resize(j);
				m[k].push_back(v[l]);
				j++;
				l++;
				
			}
			while(v[l]>=v[l+1] && l!=v.size()-1);
		}
	}
	return m;
}


Matrica OpadajuciPodnizovi(std::vector <double> v)
{
	Matrica m;
	int i,j,k,brojac=0,l=0;
	for(i=0;i<v.size();i++)
	{
		if(v[i]<=v[i+1] && l<=i)
	   {
	   	l=i;
	   	brojac++;
	   	if(brojac==1) k=0;
	   	else k++;
	   	
	   	
	   	j=0;
	   	m.resize(k);
	   do{
	   	
	   	m[k].resize(j);
	   	m[k][j]=v[l];
	   	l++;
	   	j++;
	   	
	   }
	   while(v[l]<=v[l+1] && l!=v.size()-1);
	  }
	}
	
	
	return m;
}



int main ()
{
	int i,j,broj_elemenata;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>broj_elemenata;
	std::vector <double> v(broj_elemenata);
	Matrica mat1,mat2;
	std::cout<<"Unesite elemente vektora: ";
	for(i=0;i<v.size();i++)
	{
		std::cin>>v[i];
		
	}
	std::cout<<"Maksimalni rastuci podnizovi: \n";
	mat1=RastuciPodnizovi(v);
	for(i=0;i<mat1.size();i++)
	{
		for(j=0;j<mat1[i].size();j++)
		{
			std::cout<<std::setw(5)<<mat1[i][j];
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: \n";
	mat2=OpadajuciPodnizovi(v);
	for(i=0;i<mat2.size();i++)
	{
		for(j=0;j<mat2[i].size();j++)
		{
			std::cout<<std::setw(5)<<mat2[i][j];
		}
		std::cout<<std::endl;
	}
	return 0;
}