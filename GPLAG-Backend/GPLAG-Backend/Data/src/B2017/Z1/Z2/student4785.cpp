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
#include <stdexcept>
#include <cmath>

typedef std::vector<std::vector<double>> Matrica;

Matrica NajvecaPlaninaMatrice(Matrica matrica)
{
	const double Eps(1e-10);
	Matrica planina;
	int m=matrica.size();
	if(m==0) return planina;
	int n=matrica.at(0).size();
	if(n==0) return planina;
	for(int i=1; i<m; i++)
		if(matrica.at(i).size()!=matrica.at(i-1).size()) throw std::domain_error("Matrica nije korektna");
	int p(m);
	if(n<m) p=n;
	if(p%2==0) p--;
	int x(0),y(0),velicina(0);
	double vrh(0);
	while(p>0) {
		if(p<velicina) return planina;
		for(int i=0; i<m-p+1; i++) {
			for(int j=0; j<n-p+1; j++) {
				bool jeste_planina(true);
				int suma1(0),suma2(0);
				int vrh2=matrica.at(i+p/2).at(j+p/2);
				int a(p/2),b(p/2);
				suma1=vrh2+1;
				do{
					int suma(0);
					for(int k=i;k<i+p;k++){
						for(int l=j;l<j+p;l++){
							if((k>i+a && k<i+b &&(l==j+a || l==j+b)) ||((l>=j+a && l<=j+b)&&(k==i+a || k==j+b))) 
									suma+=matrica.at(k).at(l);
						}
					}
					suma2=suma1;
					suma1=suma;
					if(suma1>=suma2){
						jeste_planina=false;
						break;
					}
					a--;
					b++;
				}while(a>=0);
				if(!jeste_planina)	continue;
				if(vrh2<vrh) continue;
				else if(std::fabs(vrh2-vrh)<=Eps*(std::fabs(vrh2)+std::fabs(vrh)) && x<i+p/2) continue;
				else if(std::fabs(vrh2-vrh)<=Eps*(std::fabs(vrh2)+std::fabs(vrh)) && x==i+p/2 && y<j+p/2) continue;
				planina.resize(0);
				int brojac_redova(0);
				for(int k=i; k<i+p; k++) {
					planina.push_back(std::vector<double>(p));
					int brojac_kolona(0);
					for(int l=j; l<j+p; l++) {
						planina.at(brojac_redova).at(brojac_kolona)=matrica.at(k).at(l);
						brojac_kolona++;
					}
					brojac_redova++;
				}
				velicina=p;
				x=i+p/2;
				y=j+p/2;
				vrh=matrica.at(x).at(y);
			}
		}
		p-=2;
	}
	return planina;
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
	Matrica a(m,std::vector<double>(n));
	std::cout<<"Unesite elemente matrice:";
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			std::cin>>a.at(i).at(j);
	std::cout<<std::endl<<"Najveca planina unesene matrice je:"<<std::endl;
	Matrica planina=NajvecaPlaninaMatrice(a);
	for(int i=0; i<planina.size(); i++) {
		for(int j=0; j<planina.at(i).size(); j++)
			std::cout<<std::setw(6)<<planina.at(i).at(j);
		std::cout<<std::endl;
	}
	return 0;
}