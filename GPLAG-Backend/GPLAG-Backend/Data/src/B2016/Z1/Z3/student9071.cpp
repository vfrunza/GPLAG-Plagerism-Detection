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

typedef std::vector<std::vector<double>> Vektor;


Vektor RastuciPodnizovi (std::vector<double> v)
{
	Vektor rastuci;
	int a;
	a = int(v.size());
    for (int i=0; i<a; i++)
    {
        if (v[i] <= v[i+1]) 
        {
        	if(i==(a - 1)) std::cout << v[i] << " ";
			else std::cout << v[i] << " ";
        }
    }
    
    for(int x : v) rastuci.resize(x);
    
    return rastuci;
}

Vektor OpadajuciPodnizovi (std::vector<double> v)
{
	Vektor opadajuci;
	int a;
	a = int(v.size());
    for (int i=0; i<a; i++)
    {
        if (v[i] >= v[i+1]) 
        {
        	if(i==(a - 1)) std::cout << v[i] << std::endl;
			else std::cout << v[i] << " ";
        }
    }
    
    for (int x : v) opadajuci.resize(x);
    
    return opadajuci;
}

int main ()
{
	std::vector<double> v;
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
    std::cout << "Unesite elemente vektora: ";
    for (int i=0; i<n; i++)
    {
        int a;
        std::cin >> a;
        v.push_back(a);
    }
	//std::cout << std::endl;
	std::cout << "Maksimalni rastuci podnizovi: ";
	std::cout << std::endl;
	(RastuciPodnizovi(v));
	 std::cout << std::endl;
	 std::cout << "Maksimalni opadajuci podnizovi: ";
	 std::cout << std::endl;
	 (OpadajuciPodnizovi(v));
	return 0;
}