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


using std::cout;
using std::cin;
using std::vector;

typedef vector<vector<double>> Matrica; 

Matrica RastuciPodnizovi(vector<double>vektor)
{
	Matrica vracaj;
	
	for(int i=0;i<vektor.size()-1;i++)
		{
			vector<double> pomocni;
			if ( i<vektor.size()-1  && vektor[i]<=vektor[i+1])
			{
				pomocni.push_back(vektor[i]);
				while(vektor[i]<=vektor[i+1])
				{
					pomocni.push_back(vektor[i+1]);
					i++;
					if (i>=vektor.size()-1) break;
					
				}
					i--;
					vracaj.push_back(pomocni);
				}
					
		}	
		
		return vracaj;	
		}
	
	
Matrica OpadajuciPodnizovi(vector<double>vektor)
{
	Matrica vracaj;
	
	for(int i=0;i<vektor.size()-1;i++)
	{
		vector<double> pomocni;
		if(i<vektor.size()-1 && vektor[i]>=vektor[i+1])
		{
			pomocni.push_back(vektor[i]);
			while (vektor[i]>=vektor[i+1])
			{
				pomocni.push_back(vektor[i+1]);
				i++;
				if(i>=vektor.size()-1) break;
			}
			i--;
			vracaj.push_back(pomocni);
		}
			
		
	}
	
	
	
	return vracaj;
}
	

int main ()
{
	vector<double> vektor;
	Matrica matrica1, matrica2;
	int n;
	cout<<"Unesite broj elemenata vektora: ";
	cin>>n;
	
	cout<<"Unesite elemente vektora: ";
	while(vektor.size()<n)
	{
		double x;
		cin>>x;
		vektor.push_back(x);
	}
	
	matrica1=RastuciPodnizovi(vektor);
	matrica2=OpadajuciPodnizovi(vektor);
	
	cout<<"Maksimalni rastuci podnizovi: ";
	cout<<"\n";
	
	for(vector<double> x:matrica1)
	{
		for(double y:x)
		cout<<std::setprecision(12)<<y<<" ";
		cout<<"\n";
	}
	cout<<"Maksimalni opadajuci podnizovi: ";
	cout<<"\n";
	
	for(vector<double>x:matrica2)
	{
		for(double y:x)
		cout<<std::setprecision(12)<<y<<" ";
		cout<<"\n";
	}
	
	
	return 0;
}