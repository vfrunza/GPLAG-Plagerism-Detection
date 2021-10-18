/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using std:: cout;
using std:: cin;
using std:: endl;
using std:: vector;
using std:: setw;

typedef std::vector<std::vector<double>> Matrica;

Matrica Vertikalna(Matrica matrica)
{
	Matrica vertikalna_matrica;
	for(int i=matrica.size()-1; i>=0; i--) {
		vertikalna_matrica.push_back(matrica[i]);
	}
	return vertikalna_matrica;
}

Matrica Horizontalna(Matrica matrica)
{
	Matrica horizontalna_matrica;
	vector<double>vektor;

	for(int i=0; i<matrica.size(); i++) {
		for(int j=matrica[i].size()-1; j>=0; j--) {
			vektor.push_back(matrica[i][j]);
		}
		horizontalna_matrica.push_back(vektor);
		vektor.resize(0);
	}
	return horizontalna_matrica;
}

Matrica Kombinovana(Matrica matrica)
{
	Matrica kombinovana_matrica;
	kombinovana_matrica=Horizontalna(matrica);
	kombinovana_matrica=Vertikalna(kombinovana_matrica);
	return kombinovana_matrica;
}

Matrica SpojiMatrice(Matrica matrica, int red)
{
	Matrica spojena_matrica;
	Matrica kombinovana_matrica1=Kombinovana(matrica);
	Matrica vertikalna_matrica1=Vertikalna(matrica);
	Matrica horizontalna_matrica1=Horizontalna(matrica);

	vector<double>pomocni;

	if(red==1 || red == 3) {
		for(int i=0; i<matrica.size(); i++) {
			for(int j=0; j<matrica[i].size(); j++)
				pomocni.push_back(kombinovana_matrica1[i][j]);
			for(int j=0; j<matrica[i].size(); j++)
				pomocni.push_back(vertikalna_matrica1[i][j]);
			for(int j=0; j<matrica[i].size(); j++)
				pomocni.push_back(kombinovana_matrica1[i][j]);
			spojena_matrica.push_back(pomocni);
			pomocni.resize(0);
		}
	} else if(red==2) {
		for(int i=0; i<matrica.size(); i++) {
			for(int j=0; j<matrica[i].size(); j++)
				pomocni.push_back(horizontalna_matrica1[i][j]);
			for(int j=0; j<matrica[i].size(); j++)
				pomocni.push_back(matrica[i][j]);
			for(int j=0; j<matrica[i].size(); j++)
				pomocni.push_back(horizontalna_matrica1[i][j]);
			spojena_matrica.push_back(pomocni);
			pomocni.resize(0);
		}
	}
	return spojena_matrica;
}

Matrica OgledaloMatrica(Matrica matrica)
{
	int brojac(0);
	vector<int>vektor_brojaca;
	for(int i=0; i<matrica.size(); i++)
	{
		brojac=matrica[i].size();
		vektor_brojaca.push_back(brojac);
		brojac=0;
	}
	
	for(int i=0; i<vektor_brojaca.size(); i++)
	{
		for(int j=0; j<vektor_brojaca.size(); j++)
		if(vektor_brojaca[i]!=vektor_brojaca[j]) throw std:: domain_error("Matrica nije korektna");
	}

	if(matrica.size()==0) return matrica;
	Matrica ogledalo_matrica;
	Matrica pomocna;
	for(int i=1; i<=3; i++) {
		pomocna = SpojiMatrice(matrica, i);
		for(int j=0; j<pomocna.size(); j++)
			ogledalo_matrica.push_back(pomocna[j]);
	}
	return ogledalo_matrica;
}



int main ()
{
	
	cout<<"Unesite dimenzije matrice (m n): ";
	int m, n;
	cin>>m>>n;
	if(m<0 || n<0) {
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}

	Matrica matrica(m, vector<double>(n));
	cout<<"Unesite elemente matrice: ";
	for(int i=0; i<matrica.size(); i++) {
		for(int j=0; j<matrica[i].size(); j++) {
			cin>>matrica[i][j];
		}
	}
	cout<<endl;
	
	try
	{
		cout<<"Rezultantna matrica: "<<endl;
		Matrica rezultantna = OgledaloMatrica(matrica);
		for(int i=0; i<rezultantna.size(); i++)
		{
			for(int j=0; j<rezultantna[i].size(); j++) 
			{
				cout<<setw(4)<<rezultantna[i][j];
			}
			cout<<endl;
		}
	}
	
	catch(std:: domain_error izuzetak)
	{
		cout<<"Izuzetak: "<<izuzetak.what()<<endl;
	}

	return 0;
}





