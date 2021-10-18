#include <iostream>
#include <vector>
#include <stdexcept>
typedef std::vector< std::vector<double> >Matrica;

Matrica KreirajMatricu3x3(Matrica m, int a, int b)
{
	Matrica m3x3(3,std::vector <double> (3));

	int k=0, l=0;
	for(int i=a; i<a+3; i++) {
		for(int j=b; j<b+3; j++) {
			m3x3.at(k).at(l)=m.at(i).at(j);
			l++;
		}
		l=0;
		k++;

	}

	return m3x3;
}

bool DaLiJePlanina(Matrica m,int a, int b)
{
	double suma=0;
	for(int i=a; i<m.size(); i++) {
		for(int j=b; j<m[0].size(); j++) {
			if(i==1 && j==1)
				continue;
			else
				suma+=m.at(i).at(j);
		}
	}
	if(suma<m[1][1])
		return true;
	return false;
}

bool GrbavaMatrica(Matrica m)
{
	for(int i=1; i<m.size(); i++) {
		if(m[i].size()!=m[0].size())
			return true;
	}
	return false;
}


Matrica NajvecaPlaninaMatrice(Matrica m)
{
	if(GrbavaMatrica(m))
		throw std::domain_error("Matrica nije korektna");

	Matrica MaxPlaninaMatrice,PlaninaMatrice,Matrica3x3;
	int brRedova=m.size();
	int brKolona=m[0].size();
	int k,l;
	double Maxvrh;
	for(int i=0; i<brRedova-2; i++) {
		for(int j=0; j<brKolona-2; j++) {
			Matrica3x3=KreirajMatricu3x3( m,i,j);
	
		
			if(DaLiJePlanina(Matrica3x3,i,j)) {  
				MaxPlaninaMatrice=Matrica3x3; //Pronasla se prva planina matrice
				Maxvrh=MaxPlaninaMatrice[1][1];
				k=i; //pozicija gornjeg lijevog coska planine [k][l]
				l=j;
				break;
			}
		}

	}

	for(int i=k; i<brRedova-2; i++) { //poredimo ostale matrice 3x3 sa pocetnom planinom 3x3 koju smo maloprije nasli
		for(int j=l+1; j<brKolona-2; j++) {
			Matrica3x3=KreirajMatricu3x3( m,i,j);

			if(DaLiJePlanina(Matrica3x3,i,j)) {
				PlaninaMatrice=Matrica3x3;
				double vrh=PlaninaMatrice[1][1];
				if(vrh>Maxvrh) {
					MaxPlaninaMatrice=PlaninaMatrice;
					Maxvrh=vrh;
					
					k=i; //pozicija gornjeg lijevog coska Maxplanine je MaxPlaninaMatrice[k][l]
					l=j;
				}

			}

		}
	}




	return MaxPlaninaMatrice;
}

int main ()
{
	try {
		int br,red,kolona;
		Matrica k;
		std::cout<<"Unesite dimenzije matrice (m i n): ";
		std::cin>> red >> kolona;
		if(red<0 || kolona<0)
			throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
		Matrica m(red,std::vector <double> (kolona));
		std::cout<<"Unesite elemente matrice:";
		for(int i=0; i<red; i++) {
			for(int j=0; j<kolona; j++) {
				std::cin>>br;
				m[i][j]=br;
			}
		}
		if(red<3 || kolona<3 || (red==3 && kolona==3)) { //ukoliko je dimenzija matrice manja od 3
			double max=m[0][0];
			for(int i=0; i<red; i++) {
				for(int j=1; j<kolona; j++) {
					if(m.at(i).at(j)>max)
						max=m[i][j];
				}
			}
			std::cout<<"\nNajveca planina unesene matrice je:\n";
			std::cout.width(6);
			std::cout<<max;
			return 0;
		}
		
		k=NajvecaPlaninaMatrice(m);
		std::cout<<"\nNajveca planina unesene matrice je:\n";
		for(int i=0; i<k.size(); i++) {
			for(int j=0; j<k[0].size(); j++) {
				std::cout.width(6);
				std::cout<<k[i][j];
			}
			std::cout<< "\n";
		}
	} catch (std::domain_error izuzetak) {
		std::cout<<izuzetak.what();
	}
	return 0;
}
