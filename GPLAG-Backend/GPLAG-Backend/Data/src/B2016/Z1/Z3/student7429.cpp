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
std::vector<std::vector<double>>RastuciPodnizovi(std::vector<double>ulaz)
{
	int prosli(0),broj(0);
	std::vector<std::vector<double>>izlaz;
	
	for(int i=0;i<ulaz.size();i++)
	{
		std::vector<double>ubac;
		broj=0;
		for(int j=i;j<ulaz.size();j++)
		{
			broj++;
			if(j==ulaz.size()-1)
			continue;
			if(ulaz[j]>ulaz[j+1])
			break;
		}
		if(broj>=prosli && broj>=2)
		{
			for(int j=i;j<i+broj;j++)
			ubac.push_back(ulaz[j]);
			izlaz.push_back(ubac);
			
		}
		prosli=broj;
	}
	
	
	
	
	return izlaz;
}

std::vector<std::vector<double>>OpadajuciPodnizovi(std::vector<double>ulaz)
{
	int prosli(0),broj(0);
	std::vector<std::vector<double>>izlaz;
	
	for(int i=0;i<ulaz.size();i++)
	{
		std::vector<double>ubac;
		broj=0;
		for(int j=i;j<ulaz.size();j++)
		{
			broj++;
			if(j==ulaz.size()-1)
			continue;
			if(ulaz[j]<ulaz[j+1])
			break;
		}
		if(broj>=prosli && broj>=2)
		{
			for(int j=i;j<i+broj;j++)
			ubac.push_back(ulaz[j]);
			izlaz.push_back(ubac);
			
		}
		prosli=broj;
		
	}
	
	
	
	
	return izlaz;
}















int main ()
{
	
		std::cout<<"Unesite broj elemenata vektora: ";
	    int n;
	    std::cin>>n;
	    
	
	std::vector<double>ulaz;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0;i<n;i++)
	{
		double a;
		std::cin>>a;
		ulaz.push_back(a);
	}
	std::vector<std::vector<double>>izlaz=RastuciPodnizovi(ulaz);
	std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
	for(int i=0;i<izlaz.size();i++)
	{
		for(int j=0;j<izlaz[i].size();j++)
		{
			/*std::printf("%lf ",izlaz[i][j]);
			std::cout<<"    "<<izlaz[i][j]<<" ";*/
			std::cout<<std::setprecision(12)<<izlaz[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	izlaz=OpadajuciPodnizovi(ulaz);
    std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0;i<izlaz.size();i++)
	{
		for(int j=0;j<izlaz[i].size();j++)
		{
			/*std::printf("%lf ",izlaz[i][j]);*/
			std::cout<<std::setprecision(12)<<izlaz[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	
	
	
return 0;
}

