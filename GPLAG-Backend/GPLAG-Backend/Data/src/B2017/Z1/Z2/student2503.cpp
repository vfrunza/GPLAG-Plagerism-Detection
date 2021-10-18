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
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdexcept>
const double EPSILON(0.001);

typedef std::vector<std::vector<double>> matrica;

matrica NajvecaPlaninaMatrice(matrica m)
{
	for(int i=0; i<m.size(); i++)
		if(m.at(0).size()!=m.at(i).size()) throw std::domain_error("Matrica nije korektna");
	int format(0),x(0),y(0);
	double max(0);
	matrica a;
	if(m.size()==0) return a;
	for(int i=0;i<m.size();i++)
	if(m.at(i).size()==0) return a;
	for(int i=1; i<m.size()-1; i++) {
		for(int j=1; j<m.at(i).size()-1; j++) {
			double temp=m.at(i).at(j);
			int k;
			for(k=1;; k++) {
				if(i-k<0 || i+k>m.size()-1 || j-k<0 || j+k>m.at(i).size()-1) break;
				int suma=0;
				for(int p=j-k; p<=j+k; p++)
					suma+=(m.at(i-k).at(p)+m.at(i+k).at(p));
				for(int p=i-k; p<=i+k; p++)
					suma+=(m.at(p).at(j-k)+m.at(p).at(j+k));
				suma-=(m.at(i-k).at(j-k)+m.at(i-k).at(j+k)+m.at(i+k).at(j-k)+m.at(i+k).at(j+k));
				if((suma-temp)>-EPSILON) break;
				temp=suma;
			}
			k--;
			if(k==0 || 2*k+1<format) continue;
			if(format<2*k+1)  {
				for(int p=0; p<format; p++)
					a.erase(a.begin() + 0);
				format=2*k+1;
				x=i;
				y=j;
				max=m.at(i).at(j);
				a.resize(format);
				int t=0;
				for(int p=i-k; p<=i+k; p++) {
					for(int q=j-k; q<=j+k; q++)
						a.at(t).push_back(m.at(p).at(q));
					t++;
				}
			} else if(format==2*k+1) {
				if((m.at(i).at(j)-max)>EPSILON) {
					for(int p=0; p<format; p++)
						a.erase(a.begin() + 0);
					format=2*k+1;
					x=i;
					y=j;
					max=m.at(i).at(j);
					a.resize(format);
					int t=0;
					for(int p=i-k; p<=i+k; p++) {
						for(int q=j-k; q<=j+k; q++)
							a.at(t).push_back(m.at(p).at(q));
						t++;
					}
				} else if(fabs(m.at(i).at(j)-max)<EPSILON) {
					if(i<x) {
						for(int p=0; p<format; p++)
							a.erase(a.begin() + 0);
						format=2*k+1;
						x=i;
						y=j;
						max=m.at(i).at(j);
						a.resize(format);
						int t=0;
						for(int p=i-k; p<=i+k; p++) {
							for(int q=j-k; q<=j+k; q++)
								a.at(t).push_back(m.at(p).at(q));
							t++;
						}
					} else if(x==i) {
						if(j<y) {
							for(int p=0; p<format; p++)
								a.erase(a.begin() + 0);
							format=2*k+1;
							x=i;
							y=j;
							max=m.at(i).at(j);
							a.resize(format);
							int t=0;
							for(int p=i-k; p<=i+k; p++) {
								for(int q=j-k; q<=j+k; q++)
									a.at(t).push_back(m.at(p).at(q));
								t++;
							}
						}
					}
				}
			}

		}
	}
	if(a.size()==0) {
		a.resize(1);
		max=m.at(0).at(0);
		for(int j=0; j<m.at(0).size(); j++)
			if((m.at(0).at(j)-max)>EPSILON) max=m.at(0).at(j);
		for(int i=1; i<m.size()-1; i++) {
			if((m.at(i).at(0)-max)>EPSILON) max=m.at(i).at(0);
			if((m.at(i).at(m.at(i).size()-1)-max)>EPSILON) max=m.at(i).at(m.at(i).size()-1);
		}
		for(int j=0; j<m.at(0).size(); j++)
			if((m.at(m.size()-1).at(j)-max)>EPSILON) max=m.at(m.size()-1).at(j);
		a.at(0).push_back(max);
	}
	return a;
}

int main ()
{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if(m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	matrica mat(m);
	std::cout<<"Unesite elemente matrice:"<<std::endl;
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++) {
			double x;
			std::cin>>x;
			mat.at(i).push_back(x);
		}
	std::cout<<"Najveca planina unesene matrice je:"<<std::endl;
	for(int i=0; i<NajvecaPlaninaMatrice(mat).size(); i++) {
		for(int j=0; j<NajvecaPlaninaMatrice(mat).size(); j++)
			std::cout<<std::right<<std::setw(6)<<NajvecaPlaninaMatrice(mat).at(i).at(j);
		std::cout<<std::endl;
	}
	return 0;
}