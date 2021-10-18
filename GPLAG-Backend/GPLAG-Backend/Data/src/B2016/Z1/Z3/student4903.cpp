/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/

#include<iostream>
#include<vector>
#include<iomanip>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v)
{
	std::vector<std::vector<double>> rastuci;
	if(v.size()==0)
		return rastuci;
	int brojac(0); //Brojac odredjuje u koji red ce se upisati nadjeni rastuci niz
	
//Trazenje minimalnog rastuceg niza (2 clana) i upisivanje u vektor, ako postoji testira se da li je duzi od 2 clana	
	
	for(int i(0);i<v.size()-1;i++)
	{
		if(v.at(i)<=v.at(i+1))
		{
			rastuci.push_back(std::vector<double> {});
			
			while(i<v.size()-1 && v.at(i)<=v.at(i+1))	//Kratkospojna evaluacija spasava uslov od prekoracenja
			{
				rastuci[brojac].push_back(v[i]);
				i++;
			}
			rastuci[brojac].push_back(v[i]);
			brojac++;
		}
	}
	
	return rastuci;
}

//Analogno prvoj funkciji radi i funkcija za opadajuce podnizove

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v)
{
	std::vector<std::vector<double>> opadajuci;
	if(v.size()==0)
		return opadajuci;
	int brojac(0);
	for(int i(0);i<v.size()-1;i++)
	{

		if(v.at(i)>=v.at(i+1))
		{
			opadajuci.push_back(std::vector<double> {});
			
			while(i<v.size()-1 && v.at(i)>=v.at(i+1))
			{
				opadajuci[brojac].push_back(v[i]);
				i++;
			}
			opadajuci[brojac].push_back(v[i]);
			brojac++;
		}
	}
	
	return opadajuci;
}

int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int n;
	std::cin>>n;
	std::vector<double> v(n);
	std::cout<<"Unesite elemente vektora: ";
	for(int i(0);i<n;i++)
	{
		std::cin>>v[i];
	}
	std::vector<std::vector<double>> vekvek1,vekvek2;
	vekvek1=RastuciPodnizovi(v);
	vekvek2=OpadajuciPodnizovi(v);
	
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i(0); i<vekvek1.size();i++)
	{
		for(int j(0);j<vekvek1[i].size();j++)
		 {
			std::cout<<vekvek1[i][j]<< " ";
		 }
		 std::cout<<std::endl;
	}
	
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i(0); i<vekvek2.size();i++)
	{
		for(int j(0);j<vekvek2[i].size();j++)
		 {
			std::cout<<vekvek2[i][j]<< " ";
		 }
		 std::cout<<std::endl;
	}
	return 0;
}