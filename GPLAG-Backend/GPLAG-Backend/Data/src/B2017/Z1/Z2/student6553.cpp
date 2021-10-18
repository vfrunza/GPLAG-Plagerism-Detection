#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <cmath>

typedef std::vector<std::vector<double>> Matrica;

bool ProvjeraIspravnosti(Matrica d)
{
	int sirina=d.at(0).size();
	for(int i=1; i<d.size(); i++) {
		if(d.at(i).size()!=sirina) return false;
	}
	return true;
}


int Kvadrati(Matrica d, int a, int b)
{
	int brojac(1), visina=d.size(), sirina=d.at(0).size();
	double suma2(0),suma(d.at(a).at(b));

	while(a-brojac>=0 && a+brojac<visina && b-brojac>=0 && b+brojac<sirina) {
		for(int i=a-brojac; i<=a+brojac; i++) {
			for(int j=b-brojac; j<=b+brojac; j++) {
				if(i==a-brojac || i==a+brojac || j==b+brojac || j==b-brojac) suma2=suma2+d.at(i).at(j);
			}

		}

		if(suma2<suma) {
			suma=suma2;
			suma2=0;
			brojac++;
		} else return brojac-1;
	}
	return brojac-1;
}

Matrica NajvecaPlaninaMatrice(Matrica d)
{ const double Eps(1e-10);
	Matrica nova;
	if(d.size()) {
		if(!ProvjeraIspravnosti(d)) {
			throw std::domain_error("Matrica nije korektna");
		}

		int brojac1(0),brojac2(0),kor1(0),kor2(0);

		for(int i=0; i<d.size(); i++) {
			for(int j=0; j<d.at(0).size(); j++) {


				brojac1=Kvadrati(d,i,j);


				if(brojac1>brojac2) {
					brojac2=brojac1;
					kor1=i;
					kor2=j;
				} else if(brojac1==brojac2) {
					if(d.at(kor1).at(kor2)<d.at(i).at(j)) {
						kor1=i;
						kor2=j;
					} else if(fabs(d.at(kor1).at(kor2)-d.at(i).at(j))<Eps) {
						if(i<kor1) {
							kor1=i;
							kor2=j;
						} else if(i==kor1) {
							if(j<kor2) {
								kor1=i;
								kor2=j;
							}
						}
					}

				}
			}
		}
		if(brojac2>0) {

			std::vector<double> s;
			for(int i=kor1-brojac2; i<=kor1+brojac2; i++) {
				s.resize(0);
				for(int j=kor2-brojac2; j<=kor2+brojac2; j++) {
					s.push_back(d.at(i).at(j));
				}
				nova.push_back(s);
			}
		} else if(brojac2==0 && d.at(0).size()) {
			nova.resize(1);
			nova.at(0).push_back(d.at(kor1).at(kor2));
		}


	}
	return nova;

}

int main ()

{
	Matrica glavna, nova;
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m i n): ";

	std::cin>>m>>n;
	if(m<0 || n<0) {

		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
if(m && n){	std::cout<<"Unesite elemente matrice: "<<std::endl;
	glavna.resize(m);
	for(int i=0; i<m; i++) {
		glavna.at(i).resize(n);
		for(int j=0; j<n; j++) {
			std::cin>>glavna.at(i).at(j);
		}

	}}
	try {
		nova=NajvecaPlaninaMatrice(glavna);
		if(nova.size()) {
			std::cout<<"Najveca planina unesene matrice je: "<<std::endl;
			for(std::vector<double>t: nova) {
				for(double x: t) std::cout<<std::setw(6)<<x;
				std::cout<<std::endl;
			}
		} else std::cout<<"Ne postoji planina!";
	} catch (std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
	

	return 0;
}