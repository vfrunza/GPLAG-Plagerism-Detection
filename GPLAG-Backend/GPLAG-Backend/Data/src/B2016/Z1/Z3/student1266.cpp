/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std:: vector< std:: vector <double> > RastuciPodnizovi (std:: vector <double> vektor)
{
	std:: vector <double> rastuci;
	std:: vector < std:: vector <double> > vektor_rastucih;
	for (int i=0; i<vektor.size(); i++)
	{
		double ib =vektor[i];
		for (int j=i; j< vektor.size()-1; j++)
		{
			double jb=vektor[j];
			if (ib<jb)
			rastuci.push_back(vektor[j]);
		}  
        
        vektor_rastucih.push_back(rastuci);
		
	}
	return vektor_rastucih;
}

std:: vector <std:: vector <double> > OpadajuciPodnizovi (std:: vector <double> vektor)
{
	std:: vector <double> opadajuci;
	std:: vector <std:: vector <double > > vektor_opadajucih;
	for (int i=0; i<vektor.size(); i++)
	{
		double ib=vektor[i];
		for (int j=i; j<vektor.size()-1; j++)
		{
			double jb=vektor[j];
			if (ib>jb)
			opadajuci.push_back(vektor[j]);
		}
		
		vektor_opadajucih.push_back(opadajuci);
	}
	return vektor_opadajucih;
}
int main ()
{
	int n;
	std:: cout << "Unesi broj elemenata: ";
	std:: cin >> n;
	
	
	std:: cout << "Unesi elemente: ";
	std:: vector <double> vektor;
	for (int i=0; i<n; i++)
	{
		int x;
		std:: cin>> x;
		vektor.push_back(x);
	}
	std:: vector < std:: vector <double> > vektor_opadajucih = OpadajuciPodnizovi(vektor);
	std:: vector < std:: vector <double> > vektor_rastucih = RastuciPodnizovi(vektor);
	std:: cout << "Maksimalni rastuci podnizovi: " << vektor_rastucih << std:: endl;
	vektor_opadajucih=OpadajuciPodnizovi(vektor);
	std:: cout << "Maksimalni opadajuci podnizovi: " << vektor_opadajucih << std:: endl;
	
	return 0;
}