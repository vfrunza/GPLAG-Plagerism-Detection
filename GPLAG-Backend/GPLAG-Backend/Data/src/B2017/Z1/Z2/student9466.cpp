/*B 2017/2018, Zadaća 1, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.
*/

#include <iostream>
#include<cmath>
#include <vector>
#include<iomanip>
#include<stdexcept>
typedef std::vector<double> Vekdo;
typedef std::vector<std::vector<double>> Matrica;
struct Planina {
	double vrh;
	Matrica b;
	int kod1;
	int kod2;
	int dimenzija;
};

Matrica NajvecaPlaninaMatrice(Matrica m)
{
	if(m.size() == 0)
		return m;
	int vel=m.at(0).size();
	if(vel == 0)
	{
		m.resize(0);
		return m;
	}
	for(int j=0; j<m.size(); j++)
		if(vel!=m.at(j).size()) throw std::domain_error("Matrica nije korektna");
	struct Planina plan;
	int max=0;
	int n=0;
	for(int i=0; i<m.size(); i++) {
		for(int u=0; u<m.at(0).size(); u++) {
			for(n=1; ; n+=2) {
				int pomoc = (n-1)/2;
				//gledamo da li se moze formirati te dimenzije matica oko vrha sa koordinatama i,u
				if((i-pomoc)>=0 && (u-pomoc)>=0 && (i+pomoc)<m.size() && (u+pomoc)<m.at(0).size()) {
					int s1=0;
					//racuna se suma svih elemenata oko vrha
					for(int k=i-pomoc; k<i+pomoc; k++) {
						for(int p=u-pomoc; p<u+pomoc; p++) {
							if(k!=i && p!=u) s1+=m.at(k).at(p);
						}
					}
					//std::cout<<"s1: "<<s1<<std::endl;
					//std::cout<<"vrhovi: "<<m[i][u]<<std::endl;
					if(s1<m.at(i).at(u)) {
						n+=2;
						pomoc = (n-1)/2;
						if((i-pomoc)>=0 && u-pomoc>=0 && i+pomoc<m.size() && u+pomoc<m.at(0).size()) {
							int s2=0;
							for(int k=i-pomoc; k<i+pomoc; k++) {
								for(int p=u-pomoc; p<u+pomoc; p++) {
									if (!((p>(u-pomoc) || p<u+pomoc-1) && k!=i-pomoc && k!=i+pomoc-1)) s2+=m.at(k).at(p);
								}
							}
							n-=2;
							//std::cout<<"s2: "<<s2<<std::endl;
							if(s2<s1) {

								if(max==0) {
									max=1;
									plan.vrh=m.at(i).at(u);
									plan.dimenzija=n;
									plan.kod1=i;
									plan.kod2=u;

								} 
								else {
									if(plan.dimenzija<n || (plan.dimenzija==n && plan.vrh<m.at(i).at(u)) || (plan.dimenzija==n && plan.vrh==m.at(i).at(u) && i>plan.kod1) || (plan.dimenzija==n && plan.vrh==m.at(i).at(u) && i==plan.kod1 && u>plan.kod2) ) {
										plan.vrh=m.at(i).at(u);
										plan.dimenzija=n;
										plan.kod1=i;
										plan.kod2=u;

									}

								}
							}
						} else {
							n-=2;

							if(max==0) {
								max=1;
								plan.vrh=m.at(i).at(u);
								plan.dimenzija=n;
								plan.kod1=i;
								plan.kod2=u;

							} else {
								if(plan.dimenzija<n || (plan.dimenzija==n && plan.vrh<m.at(i).at(u)) || (plan.dimenzija==n && plan.vrh==m.at(i).at(u) && i>plan.kod1) || (plan.dimenzija==n && plan.vrh==m.at(i).at(u) && i==plan.kod1 && u>plan.kod2) ) {
									plan.vrh=m.at(i).at(u);
									plan.dimenzija=n;
									plan.kod1=i;
									plan.kod2=u;

								}
							}

						}


					} else break;

				} else break;
			}

		}
	}
	plan.b.resize(plan.dimenzija);
	int r=0;

//std::cout<<"vrh je "<<plan.vrh<<" dok je dimenzija "<<plan.dimenzija<<" dok su kordinate: "<<plan.kod1<<", "<<plan.kod2<<std::endl;
	for(int i=plan.kod1-(plan.dimenzija-1)/2; i<=plan.kod1+(plan.dimenzija-1)/2; i++) {
		for(int j=plan.kod2-(plan.dimenzija-1)/2; j<=plan.kod2+(plan.dimenzija-1)/2; j++) {
			plan.b.at(r).push_back(m.at(i).at(j));
//	std::cout<<m.at(i).at(j)<<" ";

		}
//	std::cout<<std::endl;
		r++;
	}

	return plan.b;
}



int main ()
{
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	int m=0,n=0;
	std::cin>>m;
	std::cin>>n;
	Matrica mat;

	if(m<0 || n<0) std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	else {
		mat.resize(m);
		std::cout<<"Unesite elemente matrice: ";
		for(int i=0; i<m; i++) {
			mat.at(i).resize(n);
			for(int j=0; j<n; j++) {
				std::cin>>mat.at(i).at(j);
			}
		}

		Matrica c;
		c=NajvecaPlaninaMatrice(mat);
		std::cout<<"\nNajveca planina unesene matrice je:\n";
		for(int r=0; r<c.size(); r++) {
			for(int u=0; u<c.at(r).size(); u++)
				std::cout<<std::setw(6)<<c.at(r).at(u);
			std::cout<<std::endl;
		}
	}

	return 0;
}