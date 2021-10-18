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
#include <stdexcept>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;
double suma_koncentricnih(Matrica v, int i , int j, int brojac)
{
	double suma(0);
	if(i+brojac>=v.size() || j+brojac>=v.at(i).size() || i-brojac<0 || j-brojac<0) return -100;
	for(int k=i-brojac; k<=i+brojac; k++) {
		for(int l=j-brojac; l<=j+brojac; l++) {
			if(k==i-brojac && (l==j-brojac || l==j+brojac)) suma+=v.at(k).at(l);
			else if(k==i-brojac && (l!=j-brojac || l!=j+brojac)) suma+=v.at(k).at(l);
			else if(k==i+brojac && (l==j-brojac || l==j+brojac)) suma+=v.at(k).at(l);
			else if(k==i+brojac && (l!=j-brojac || l!=j+brojac)) suma+=v.at(k).at(l);
			else if(l==j+brojac || l==j-brojac) suma+=v.at(k).at(l);
		}
	}

	return suma;

}
Matrica napravi_pod_matricu(Matrica v, int i, int j,int brojac)
{
	std::vector<double> pomocni;
	Matrica nova;
	for(int k=0; k<v.size(); k++) {
		for(int l=0; l<v.at(i).size(); l++) {
			if(k>=i-brojac && k<=i+brojac && l>=j-brojac && l<=j+brojac)
				pomocni.push_back(v.at(k).at(l));

		}
		nova.push_back(pomocni);
		pomocni.resize(0);
	}

	return nova;
}
Matrica nadjimax(Matrica v)
{
	double max=v.at(0).at(0);
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<v.at(i).size(); j++) {
			if(v.at(i).at(j)>max) max=v.at(i).at(j);
		}
	}

	Matrica pomocna(1);
	pomocna.at(0).push_back(max);

	return pomocna;
}
Matrica NajvecaPlaninaMatrice(Matrica v)
{
	if(v.size()==0) return {};
	bool prazan_vektor(true);
	for(int i=0;i<v.size();i++){
		if(v.at(i).size()!=0) prazan_vektor=false;
	}
	if(prazan_vektor) return {};
	for(int i=0; i<v.size(); i++) {
		if(v.at(i).size()!=v.at(0).size()) throw std::domain_error("Matrica nije korektna");
	}
	if(v.size()==0) return {};
	if(v.size()==3) {

	}
	int brojac(0),max_brojac(0),max_i(0),max_j(0);
	for(int i=0; i<v.size(); i++) {
		for(int j=0; j<v.at(i).size(); j++) {
			brojac=0;
			if(i-brojac>=0 && i+brojac<v.size() && j-brojac>=0 && j+brojac<v.at(i).size()) {
				if(v.at(i).at(j)>suma_koncentricnih(v,i,j,1)) {
					while(suma_koncentricnih(v,i,j,brojac)>suma_koncentricnih(v,i,j,brojac+1)) {
						brojac++;
						if(brojac+1==v.size()-1 || brojac+1==v.at(i).size()-1) break;
					}
					if(suma_koncentricnih(v,i,j,brojac)==-100) brojac--;
					if(brojac>max_brojac) {
						max_brojac=brojac;
						max_i=i;
						max_j=j;
					}
					if(brojac==max_brojac) {
						if(v.at(i).at(j)>v.at(max_i).at(max_j)) {
							max_i=i;
							max_j=j;
						} else if(v.at(i).at(j)==v.at(max_i).at(max_j)) {
							if(i<max_i) {
								max_i=i;
								max_j=j;
							} else if(i==max_i) {
								if(j<max_j) {
									max_j=j;
								}
							}
						}
					}
				}
			}
		}
	}
	Matrica planina(napravi_pod_matricu(v,max_i,max_j,max_brojac));
	int br(0);
	for(int i=0; i<planina.size(); i++) {
		if(planina.at(i).size()!=0) br++;
	}
	if(br==1) planina=nadjimax(v);

	return planina;

}


int main ()
{
	try {
		std::cout<<"Unesite dimenzije matrice (m i n): ";
		int m,n;
		std::cin>>m>>n;
		if(m<0 || n<0) {
			std::cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		std::cout<<"Unesite elemente matrice:";
		Matrica mat;
		for(int i=0; i<m; i++) {
			std::vector<double> pomocni;
			for(int j=0; j<n; j++) {
				int k;
				std::cin>>k;
				pomocni.push_back(k);
			}
			mat.push_back(pomocni);
		}
		
		Matrica f(NajvecaPlaninaMatrice(mat));
		std::cout<<std::endl<<"Najveca planina unesene matrice je:"<<std::endl;
		

		for(auto red : f) {
			for(auto k : red)
				std::cout<<std::setw(6)<<k;
			std::cout<<std::endl;
		}
	} catch(std::domain_error a) {
		std::cout<<a.what();
	}

	return 0;
}