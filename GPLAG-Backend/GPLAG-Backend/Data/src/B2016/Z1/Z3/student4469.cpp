/*B 2016/2017, Zadaća 1, Zadatak 3

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/

#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double>a)
{	std::vector<std::vector<double>> matrica;



	if(a.size()==0)
	{	return matrica;
	}

int m=0;
	for(int i=0; i<a.size()-1;i++)
	{	std::vector<double>vektor;
      
		if (  (i<a.size()-1) &&  (a[i]<=a[i+1]) )
	 {      
	 matrica.resize(matrica.size()+1);
	 
			matrica[m].push_back(a[i]);

		while ( (i<a.size()-1)   &&  (a[i]<=a[i+1]) )
		{	matrica[m].push_back(a[i+1]);
			i++;
		}
		m++;
                     }
                     
                    

           }
	return matrica;
}



std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double>a)
{	std::vector<std::vector<double>> matrica;



	if(a.size()==0)
	{	return matrica;
	}

int m=0;
	for(int i=0; i<a.size()-1;i++)
	{	std::vector<double>vektor;
      
		if (  (i<a.size()-1) &&  (a[i]>=a[i+1]) )
	 {      
	 matrica.resize(matrica.size()+1);
	 
			matrica[m].push_back(a[i]);

		while ( (i<a.size()-1)   &&  (a[i]>=a[i+1]) )
		{	matrica[m].push_back(a[i+1]);
			i++;
		}
		m++;
                     }
                     
                    

           }
	return matrica;
}


int main ()
{	int brojelemenata;
double broj;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>brojelemenata;
	std::vector<std::vector<double>> matrica;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double>a;
	for(int i=0; i<brojelemenata; i++)
	{

		std::cin>>broj;
		a.push_back(broj);
	}

	matrica=RastuciPodnizovi(a);
	


std::cout<<"Maksimalni rastuci podnizovi: ";
	for(int i=0; i<matrica.size(); i++)
	{	
			std::cout<<std::endl;
		for( int j=0; j<matrica[i].size(); j++)
		{
			std::cout<<matrica[i][j]<<" ";
		}

	}


matrica=OpadajuciPodnizovi(a);
std::cout<<std::endl;
std::cout<<"Maksimalni opadajuci podnizovi: ";
	for(int i=0; i<matrica.size(); i++)
	{	
			std::cout<<std::endl;
		for( int j=0; j<matrica[i].size(); j++)
		{

			std::cout<<matrica[i][j]<<" ";

		}
	
	}

	return 0;
}