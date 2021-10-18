/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <cmath>
bool Prost (int n)
{
	//Pomocna funkcija za odredjivanje koja vraca true ako je broj prost, a false ako je slozen.
	if (n<0)
		n=-n;
	for (int i=2;i<=std::sqrt(n);i++)
	{
		if (n%i==0)
			return false;
	}
	return true;
}
std::vector<int> TernarniZapis (int n)
{
	//Pomocna funkcija koja ternarni zapis broja vraca kao vektor
	//Napomena je da ce ovaj ternarni zapisi biti obrnut,zbog funckije push_back,medjutim to nema nikakvog uticaja na ispitivanje simetricnosti.
	std::vector<int> vrati;
	if (n<0)
	{
		while (n<0)
		{
			int cifra(n%3);
			cifra=-cifra;
			n/=3;
			vrati.push_back(cifra);
		}
	}
	else
	{
		while (n>0)
		{
			int cifra=n%3;
			n/=3;
			vrati.push_back(cifra);
		}
	}
	return vrati;
}
bool DaLiSePonavlja (std::vector<int> ve, int x)
{
	//Funkciji se salje vektor koji se treba vratiti iz glavne funkcije i neka vrijednost x (koja se eventualno treba ubaciti u taj vektor)
	//Ako se utvrdi da se x ne nalazi u vektoru vraca se false.
	for (int i=0;i<ve.size();i++)
	{
		if (ve.at(i)==x)
		return true;
	}
	return false;
}
std::vector<int> IzdvojiSimetricneTernarne (std::vector<int> v, bool prosti)
{
	std::vector<int> vrati;
	//Funkcija se za rad oslanja na pomocne funkcije.
	for (int x: v)
	{
		bool simetricni(true);
		if (prosti && Prost(x))
		{
			auto pomocni(TernarniZapis(x));
			int vel(pomocni.size());
			//Kad se iz pomocne funkcije vrati ternarni zapis broja, ispituje se da li je taj broj simetrican
			//Ukoliko nadjemo prvi par koji nije simetrican, to znaci da taj broj ne zadovoljava uslov
			for (int i=0;i<vel/2;i++)
			{
				if (pomocni.at(i)!=pomocni.at(vel-i-1))
					{	simetricni=false;
						break;}
			}
			//Ako je broj simetrican i se vec ne nalazi u vectoru vrati, ubacujemo ga u taj vector.
			if (simetricni && !DaLiSePonavlja(vrati,x))
				vrati.push_back(x);
		}
		else if (!prosti && !Prost(x))
		{
			auto pomocni(TernarniZapis(x));
			int vel(pomocni.size());
			//Ovaj dio funckije isto radi kao u if-bloku,samo sto se testiraju slozeni brojevi.
			for (int i=0;i<vel/2;i++)
			{
				if (pomocni.at(i)!=pomocni.at(vel-i-1))
					{	simetricni=false;
						break;}
			}
			if (simetricni && !DaLiSePonavlja(vrati,x))
			vrati.push_back(x);
		}
	}
	return vrati;
}


int main ()
{
	std::vector<int> v;
	int unos;
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	while (std::cin>>unos,unos!=-1)
	{
		v.push_back(unos);
	}
	int n;
	std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	while (std::cin>>n,(n!=1 && n!=0))
	{
		std::cout<<"Neispravan unos! Unesite ponovo: ";
	}
	if (n==1)
	{
		auto ve(IzdvojiSimetricneTernarne(v,true));
		if (ve.size()==0)
		std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
		else
		{
			std::cout<<"Prosti simetricni brojevi iz vektora su: ";
			for (int i=0;i<ve.size();i++)
			{
				if (i==ve.size()-1)
				std::cout<<ve.at(i)<<".";
				else
				std::cout<<ve.at(i)<<", ";
			}
		}
	}
	else
	{
		auto ve(IzdvojiSimetricneTernarne(v,false));
		if (ve.size()==0)
		std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
		else
		{
			std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
			for (int i=0;i<ve.size();i++)
			{
				if (i==ve.size()-1)
				std::cout<<ve.at(i)<<".";
				else
				std::cout<<ve.at(i)<<", ";
			}
		}
	}
	return 0;
}