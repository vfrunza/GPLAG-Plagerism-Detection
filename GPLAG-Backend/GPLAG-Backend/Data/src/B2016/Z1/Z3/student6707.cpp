#include <iostream>
#include <vector>
/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
typedef std::vector<std::vector<double>> Matrica;

void IspisiMatricu(Matrica matrica)
{
	for(int i=0; i<matrica.size(); i++)
	{
		for(int j=0; j<matrica[i].size(); j++)
		{
			std::cout<<matrica[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}

Matrica RastuciPodnizovi(std::vector<double> vektor)
{
	
	Matrica v(10);
	int broj=0;
	int j=0;
	for(int i=0; i<vektor.size()-1;i++)
	{
		while(i!=vektor.size()-1 && vektor[i]<=vektor[i+1] )
		{
			v[j].push_back(vektor[i]);
			broj=1;
			i++;
		}
		if(i==vektor.size()-1 && broj==1 && vektor[i]>=vektor[i-1]) v[j].push_back(vektor[i]);
		else if(i!=vektor.size()-1 && broj==1 && vektor[i+1]<vektor[i] ) {
		v[j].push_back(vektor[i]);
		j++;
		}
		broj=0;
	
	}

	
	v.resize(j+1);
	return v;
}

Matrica OpadajuciPodnizovi(std::vector<double> vektor)
{
	
	Matrica v(10);
	int broj=0;
	int j=0;
	for(int i=0; i<vektor.size()-1;i++)
	{
		while(i!=vektor.size()-1 && vektor[i]>=vektor[i+1] )
		{
			v[j].push_back(vektor[i]);
			broj=1;
			i++;
		}
		if(i==vektor.size()-1 && broj==1 && vektor[i]<=vektor[i-1]) v[j].push_back(vektor[i]);
		else if(i!=vektor.size()-1 && broj==1 && vektor[i+1]>vektor[i] ) {
		v[j].push_back(vektor[i]);
		j++;
		}
		broj=0;
	
	}

	
	v.resize(j+1);
	return v;
}
int main ()
{
	std::vector<double> vektor;
	int n;
	double element;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<< "Unesite elemente vektora: ";
	for(int i=0; i<n; i++)
	{
		std::cin>>element;
		vektor.push_back(element);
	}
	
	Matrica v= RastuciPodnizovi(vektor);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
IspisiMatricu(v);
	 v=OpadajuciPodnizovi(vektor);
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	IspisiMatricu(v);
	return 0;
}
