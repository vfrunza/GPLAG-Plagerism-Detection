/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include<stdexcept>
 std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> niz)
 {
 	std::vector<std::vector<double>> novi;
 	std::vector<double> red;
 	double trenutni;
 	int redPoceo=0;
 	for(int i=0;i<niz.size();i++)
 	{
 		if(redPoceo==0) {
 			trenutni=niz[i];
 			redPoceo++;
 			continue;
 		}
 		if(trenutni<=niz[i])
 		{
 			red.push_back(trenutni);
 			trenutni=niz[i];
 			if(i==(niz.size()-1))
 			{
 				red.push_back(niz[i]);
 				novi.push_back(red);
 			}
 		}
 		else
 		{
 			if(red.size()>0) 
 			{
 				red.push_back(trenutni);
 				novi.push_back(red);
 			}
 			red.resize(0);
 			trenutni=niz[i];
 		}
 		
 	}
 	return novi;
 }
 std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> niz)
 {
 	std::vector<std::vector<double>> novi;
 	std::vector<double> red;
 	double trenutni;
 	int redPoceo=0;
 	for(int i=0;i<niz.size();i++)
 	{
 		if(redPoceo==0) {
 			trenutni=niz[i];
 			redPoceo++;
 			continue;
 		}
 		if(trenutni>=niz[i])
 		{
 			red.push_back(trenutni);
 			trenutni=niz[i];
 			if(i==(niz.size()-1))
 			{
 				red.push_back(niz[i]);
 				novi.push_back(red);
 			}
 		}
 		else
 		{
 			if(red.size()>0) 
 			{
 				red.push_back(trenutni);
 				novi.push_back(red);
 			}
 			red.resize(0);
 			trenutni=niz[i];
 		}
 		
 	}
 	return novi;
 }
int main ()
{
	std::cout<<"Unesite broj elemenata vektora: ";
	int a;
	std::cin>>a;
	if(a<0) std::cout<<"broj elemenata ne smije biti manji od 0!";
	else
	{
	std::vector<double> matrica;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<a;i++)
	{
		double x;
		std::cin>>x;
		matrica.push_back(x);
	}
	std::vector<std::vector<double>> novi=RastuciPodnizovi(matrica);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0;i<novi.size();i++)
	{
		for(int j=0;j<novi[i].size();j++)
		std::cout<<novi[i][j]<<" ";
		std::cout<<std::endl;
	}
	novi=OpadajuciPodnizovi(matrica);
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0;i<novi.size();i++)
	{
		for(int j=0;j<novi[i].size();j++)
		std::cout<<novi[i][j]<<" ";
		std::cout<<std::endl;
	}
}
	return 0;
}