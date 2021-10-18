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
#include <iomanip>
#include <stdexcept>
#include <vector>

typedef std::vector<std::vector<double>> matrica;
matrica KreirajMatricu(int br_redova, int br_kolona)
{
	return matrica(br_redova,std::vector<double>(br_kolona));
}
matrica UnesiMatricu(int br_redova,int br_kolona)
{
	matrica m(KreirajMatricu(br_redova,br_kolona));
	for(int i=0; i<br_redova; i++)
		for(int j=0; j<br_kolona; j++)
			std::cin>>m.at(i).at(j);
	return m;
}

matrica NajvecaPlaninaMatrice(matrica mat)
{
	matrica mat_pl;

	bool pl(0);
	int vel_mat(0),max_clan(0),poc_i(0),poc_j(0),maxi(0);

	if(mat.size()==0 || mat.at(0).size()==0) {
		for(int i=0; i<mat.size(); i++) {
			for(int j=0; j<mat.at(i).size(); j++) {
				mat_pl.at(i).at(j)=mat.at(i).at(j);
			}
		}
		return mat_pl;
	}

	for(int i=0; i<mat.size(); i++) {
		if(mat.at(i).size()!=mat.at(0).size())
			throw std::domain_error("Matrica nije korektna");
	}
	int pocetak(0),kraj(0),max;

	if(mat.size()==1 || mat.at(0).size()==1) {
		for(int i=0; i<mat.size(); i++) {
			max=mat.at(0).at(0);
			for(int j=0; j<mat.at(i).size(); j++) {
				if(mat.at(i).at(j)>max) {
					max=mat.at(i).at(j);
					pocetak=i;
					kraj=j;
				}
			}
		}
		mat_pl.resize(1);
		for(int k=0; k<1; k++) mat_pl.at(k).resize(1);
		mat_pl.at(0).at(0)=mat.at(pocetak).at(kraj);
		return mat_pl;
	}

	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat.at(i).size(); j++) {
			int br=0;
			while(i>0 && i<mat.size()-1 && j>0 && j<mat.at(i).size()-1 && j-(br+1)>=0 && i+(1+br)<mat.size() && j+(br+1)<mat.at(i).size() && i-(br+1)>=0 && mat.at(i).at(j) > (mat.at(i-(br+1)).at(j)+mat.at(i+(br+1)).at(j)+mat.at(i).at(j+(br+1))+mat.at(i).at(j-(br+1))+mat.at(i+(br+1)).at(j-(br+1))+mat.at(i+(br+1)).at(j+(br+1))+mat.at(i-(br+1)).at(j+(br+1))+mat.at(i-(br+1)).at(j-(br+1)))) {
				br++;
			}
			vel_mat=2*br+1; //mora biti neparna
			if(br>0 && (vel_mat>maxi || (vel_mat==maxi && mat.at(i).at(j)>mat.at(poc_i).at(poc_j)) || (vel_mat==maxi && mat.at(i).at(j)==mat.at(poc_i).at(poc_j) && i<poc_i )|| (vel_mat==maxi && mat.at(i).at(j)==mat.at(poc_i).at(poc_j) && j<poc_j && i==poc_i))) {
				poc_i=i;
				poc_j=j;
				if(vel_mat>maxi)maxi=vel_mat;
				mat_pl.resize(vel_mat);
				for(int k=0; k<vel_mat; k++) mat_pl.at(k).resize(vel_mat);
				for(int z=0; z<vel_mat; z++) {
					for(int t=0; t<vel_mat; t++) {
						mat_pl.at(z).at(t)=mat.at(i-br).at(j-br);
						j++;
					}
					j=poc_j;
					i++;
				}
				i=poc_i;
				j=poc_j;
				pl=1;
			}
		}
	}
	if(pl) return mat_pl;
	else {
		for(int i=0; i<mat.size(); i++) {
			for(int j=0; j<mat.at(i).size(); j++) {
				if(mat.at(i).at(j)>max_clan)max_clan=mat.at(i).at(j);
			}
		}
		mat_pl.resize(vel_mat);
		for(int k=0; k<vel_mat; k++)mat_pl.at(k).resize(vel_mat);
		mat.at(0).at(0)=max_clan;
		return mat_pl;
	}

}

int main ()
{
	int n,m;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if(n<0 || m<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice: ";
	matrica a(UnesiMatricu(m,n));
	matrica planina;
	try {
		planina=NajvecaPlaninaMatrice(a);
	} catch(std::domain_error izuzetak) {
		std::cout<<izuzetak.what()<<std::endl;
	}
	std::cout<<std::endl;
	std::cout<<"Najveca planina unesene matrice je:"<<std::endl;
	for(int i=0; i<planina.size(); i++) {
		for(int j=0; j<planina.at(i).size(); j++) {
			std::cout<<std::setw(6)<<planina.at(i).at(j);
		}
		std::cout<<std::endl;
	}

	return 0;
}