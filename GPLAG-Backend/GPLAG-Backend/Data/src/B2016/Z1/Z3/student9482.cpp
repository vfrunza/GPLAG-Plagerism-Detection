/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> Matrica)
{
	std::vector<std::vector<double>> Vratiti(1);
	if(Matrica.size()==0)
	{
		return Vratiti;
	}
	int j=0;
	for(int i=0;i<Matrica.size();i++)
	{
		if(i==0)
		{
			if(Matrica[0]<=Matrica[1])
			{
				Vratiti[j].push_back(Matrica[i]);
			}
		}
		if(i>0 && i<Matrica.size()-1)
		{
			if(Matrica[i]<=Matrica[i+1])
			{
				Vratiti[j].push_back(Matrica[i]);
			}
			if(Matrica[i-1]<=Matrica[i] && Matrica[i]>Matrica[i+1])
			{
				Vratiti[j].push_back(Matrica[i]);
				j++;
				Vratiti.resize(j+1);
			}
		}
		if(i==Matrica.size()-1)
		{
			if(Matrica[i]>=Matrica[i-1])
			{
				Vratiti[j].push_back(Matrica[i]);
			}
		}
	}
	return Vratiti;
}
std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> Matrica)
{
	std::vector<std::vector<double>> Vratiti(1);
	if(Matrica.size()==0)
	{
		return Vratiti;
	}
	int j=0;
	for(int i=0;i<Matrica.size();i++)
	{
		if(i==0)
		{
			if(Matrica[0]>=Matrica[1])
			{
				Vratiti[j].push_back(Matrica[i]);
			}
		}
		if(i>0 && i<Matrica.size()-1)
		{
			if(Matrica[i]>=Matrica[i+1])
			{
				Vratiti[j].push_back(Matrica[i]);
			}
			if(Matrica[i-1]>=Matrica[i] && Matrica[i]<Matrica[i+1])
			{
				Vratiti[j].push_back(Matrica[i]);
				j++;
				Vratiti.resize(j+1);
			}
		}
		if(i==Matrica.size()-1)
		{
			if(Matrica[i]<=Matrica[i-1])
			{
				Vratiti[j].push_back(Matrica[i]);
			}
		}
	}
	return Vratiti;
}
int main ()
{
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	std::vector<double> Vektor(n);
	for(int i=0;i<n;i++)
	{
		std::cin>>Vektor[i];
	}
	std::vector<std::vector<double>> Rastuci(RastuciPodnizovi(Vektor));
	std::vector<std::vector<double>> Opadajuci(OpadajuciPodnizovi(Vektor));
	std::cout<<"Maksimalni rastuci podnizovi:"<<std::endl;
	for(int i=0;i<Rastuci.size();i++)
	{
		for(int j=0;j<Rastuci[i].size();j++)
		{
			std::cout<<Rastuci[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
	for(int i=0;i<Opadajuci.size();i++)
	{
		for(int j=0;j<Opadajuci[i].size();j++)
		{
			std::cout<<Opadajuci[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
	return 0;
}