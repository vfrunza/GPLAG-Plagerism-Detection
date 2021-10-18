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

typedef std::vector<std::vector<double>> matrica;
matrica KreirajMatricu(double broj_redova,double broj_kolona)
{
    return matrica(broj_redova, std::vector<double>(broj_kolona));
}
matrica NajvecaPlaninaMatrice(matrica M){
	matrica Mp;
	int max(0),i_prije(0),j_prije(0),planina(0),max_el(0),vel(0),br_el_reda;
	for(int i=1; i<M.size(); i++){
		br_el_reda=M.at(0).size();
		if(M.at(i).size()!=br_el_reda) throw std::domain_error("Matrica nije korektna");
	}
	if(M.size()==0 || M.at(0).size()==0){
		for(int i=0; i<M.size(); i++){
		for(int j=0; j<M.at(i).size(); j++){
			Mp.at(i).at(j)=M.at(i).at(j);
		}
		}
		return Mp;
	}
	for(int i=0; i<M.size(); i++){
		for(int j=0; j<M.at(i).size(); j++){
			int k=0;
			while(i>0 && i<M.size()-1 && j>0 && j<M.at(i).size()-1 && i-(k+1)>=0 && j-(k+1)>=0 && i+(k+1)<M.size() && j+(k+1)<M.at(i).size() && M.at(i).at(j)>M.at(i-(k+1)).at(j)+M.at(i+(k+1)).at(j)+M.at(i).at(j-(k+1))+M.at(i).at(j+(k+1))+M.at(i+(k+1)).at(j-(k+1))+M.at(i+(k+1)).at(j+(k+1))+M.at(i-(k+1)).at(j-(k+1))+M.at(i-(k+1)).at(j+(k+1))){
				k++;
			}
			vel=2*k+1;
			if(k>0 && (vel>max || vel==max && M.at(i).at(j)>M.at(i_prije).at(j_prije) || vel==max && M.at(i).at(j)==M.at(i_prije).at(j_prije) && i<i_prije || vel==max && M.at(i).at(j)==M.at(i_prije).at(j_prije) && i==i_prije && j<j_prije)){
				i_prije=i;
				j_prije=j;
			if(vel>max)	
			max=vel;
			Mp.resize(vel);
			for(int c=0; c<vel; c++) Mp.at(c).resize(vel);
				for(int m=0; m<vel; m++){
				for(int n=0; n<vel; n++){
					Mp.at(m).at(n)=M.at(i-k).at(j-k);
					j++;
				}
				i++;
				j=j_prije;
			}
			i=i_prije;
			j=j_prije;
			planina=1;
		}
		}
	}
	if(planina)
	return Mp;
	else{
		for(int i=0; i<M.size(); i++){
		for(int j=0; j<M.at(i).size(); j++){
			if(M.at(i).at(j)>max_el) max_el=M.at(i).at(j);
		}
		}
	Mp.resize(vel);
	for(int c=0; c<vel; c++) Mp.at(c).resize(vel);
	Mp.at(0).at(0)=max_el;
	return Mp;
	}
}
int main ()
{
	int m,n;
	matrica mat,mat_p;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	mat=KreirajMatricu(m,n);
	std::cout<<"Unesite elemente matrice: "<<std::endl;
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
		std::cin>>mat.at(i).at(j);
		}
	}
	try{
	mat_p=NajvecaPlaninaMatrice(mat);
	std::cout<<"Najveca planina unesene matrice je:"<<std::endl;
	for(int i=0; i<mat_p.size(); i++){
		for(int j=0; j<mat_p.at(i).size(); j++){
			std::cout<<" "<<std::setw(5)<<mat_p.at(i).at(j);
		}
		std::cout<<std::endl;
	}
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what();
	}
	return 0;
}