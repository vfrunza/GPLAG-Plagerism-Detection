/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> niz)
{
	std::vector<std::vector<double>> rastuci;
	int red=0;
	for(int i=1;i<niz.size();i++)
	{
		if(niz[i-1]<=niz[i]) // provjerava da li su dva susjedna elementa rastuca
		{
			rastuci.push_back(std::vector<double>{}); //ako jesu prvo pravi novi red vektora
			rastuci[red].push_back(niz[i-1]);	// pa u njega zapisuje prvi od rastucih elemenata
			i++;
			if(i<niz.size())while(niz[i-1]<=niz[i]&&i<niz.size())
			{
				rastuci[red].push_back(niz[i-1]);	//sve dokle ima rastucih elemenata upisuje ih u trenutni red
				i++;
				if(i==niz.size()) break;
			}
			rastuci[red].push_back(niz[i-1]); //na kraju upisuje posljednji clan
			red++;	// i povecava broj redova vektora
		}
	}
	return rastuci;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> niz)
{
	std::vector<std::vector<double>> opadajuci;
	int red=0;
	for(int i=1;i<niz.size();i++)
	{
		if(niz[i-1]>=niz[i]) // provjerava da li su dva susjedna elementa opadajuca
		{
			opadajuci.push_back(std::vector<double>{}); //ako jesu prvo pravi novi red vektora
			opadajuci[red].push_back(niz[i-1]);// pa u njega zapisuje prvi od opadajucih elemenata
			i++;
			if(i<niz.size())while(niz[i-1]>=niz[i]&&i<niz.size())
			{
				opadajuci[red].push_back(niz[i-1]); //sve dokle ima opadajucih elemenata upisuje ih u trenutni red
				i++;
				if(i==niz.size()) break;
			}
			opadajuci[red].push_back(niz[i-1]); //na kraju upisuje posljednji clan
			red++; // i povecava broj redova vektora
		}
	}
	return opadajuci;
}

int main ()
{
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	while(std::cin >> n,n<0) std::cout << "Broj elemenata ne moze biti manji od 0\n"<< "Unesite broj elemenata vektora: ";
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> niz(n) ;
	for(int i=0;i<n;i++)	std::cin >> niz[i];
	std::cout << "Maksimalni rastuci podnizovi:\n";
	std::vector<std::vector<double>> krnjmat=RastuciPodnizovi(niz);
	for(std::vector<double> x:krnjmat)
	{
		for(double y:x) std::cout << y << " ";
		std::cout << "\n";
	}
	krnjmat=OpadajuciPodnizovi(niz);
	std::cout << "Maksimalni opadajuci podnizovi: \n";
	for(std::vector<double> x:krnjmat)
	{
		for(double y:x) std::cout << y << " ";
		std::cout << "\n";
	}
	return 0;
}