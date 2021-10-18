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
Matrica KreirajMatricu(int red, int kolona){
	return Matrica(red, std::vector<double>(kolona));
}
int Grbava(Matrica m){
	int pom=m.at(0).size();
	for(int i=0; i<m.size(); i++) if(m.at(i).size()!=pom) return 1;
	return 0;
}
int PlaninaBrKrugova(Matrica m, int ind_red, int ind_kol, int max){
	double suma1(m.at(ind_red).at(ind_kol));
	if(max==1){
		double sumap(0);
		for(int i=0; i<3; i++){
			sumap+=(m.at(ind_red-1).at(i) + m.at(ind_red).at(i) + m.at(ind_red+1).at(i));
		}
		sumap-=suma1;
		if(suma1>sumap) return 1;
		return 0;
	}
	for(int k=1; k<=max/2; k++){
		double suma2;
		for(int i=ind_red-k; i<=ind_red+k; i++){
			for(int j=ind_kol-k; j<=ind_kol+k;j++){
				if(i==ind_red && j==ind_kol) continue;
				suma2+=m.at(i).at(j);
				if(suma2>suma1) return k-1;
			}
		}
		suma1=suma2;
	}
	return max/2;
}
int UdaljenostOdKraja(int i, int j, int max){
	if(max<=1) return 0;
	if(j<=max/2){
		if(i<j) return i;
		if(j>max-i) return max-i;
		return j;
	}
	int pom(max-j);
	if(i<pom) return i;
	if(pom<max-i) return pom;
	return max-i;
}
Matrica NajvecaPlaninaMatrice(Matrica m){
	Matrica nova_matrica;
	if(Grbava(m)) throw std::domain_error("Matrica nije korektna");
	if(m.size()==0 || m.at(0).size()==0) return nova_matrica;
	if(m.size()==1){
		nova_matrica=KreirajMatricu(1,1);
		nova_matrica.at(0).at(0)=m.at(0).at(0);
		return nova_matrica;
	}
	int red(m.size()),udaljenost,index_i, index_j, dim;
	for(int i=1; i<m.size()-1; i++){
		for(int j=1; j<m.at(i).size()-1; j++){
			//dodati uslov da se pronadje najveca moguca velicina matrice i to je udaljenost
			udaljenost=UdaljenostOdKraja(i,j,red);
			dim=PlaninaBrKrugova(m,i,j,udaljenost);
			if(dim!=0){
				index_i=i;
				index_j=j;
				break;
			}
		}
	}
	for(int i=1; i<m.size()-1; i++){
		for(int j=1; j<m.at(i).size()-1; j++){
			udaljenost=UdaljenostOdKraja(i,j,red);
			int pom(PlaninaBrKrugova(m,i,j,udaljenost));
			/* if(pom=dim){
			     ovdje za ispitati u kojem je kvadrantu msm koja je na visoj toj poziciji sta vec treba
				if(i<index_i ){
					dim=pom;
					index_i=i;
					index_j=j;
				}
			} else */ if(pom>dim){
				dim=pom; 
				index_i=i;
				index_j=j;
			}
			
		}
	}
	nova_matrica=KreirajMatricu(2*dim+1, 2*dim+1);
	for(int i=index_i-dim ; i<=index_i+dim ; i++){
		for(int j=index_j-dim; j<=index_j+dim ; j++){
			double temp=m.at(i).at(j);
			nova_matrica.at(i).at(j)=temp;
		}
	}
	return nova_matrica;
}

int main ()
{
	try{
	  int n,m;
	  std::cout << "Unesite dimenzije matrice (m i n): ";
	  std::cin>>m>>n;
	  std::cout<<"Unesite elemente matrice : ";
	  Matrica mat(KreirajMatricu(m,n));
	  for(int i=0; i<m; i++){
	  	for(int j=0; j<n; j++){
	  		double temp;
	  		std::cin>>temp;
	  		mat.at(i).at(j)=temp;
	  	}
	  }
	  std::cout<<PlaninaBrKrugova(mat,3,3,2);
	  
	  Matrica nova_matrica(NajvecaPlaninaMatrice(mat));
	  std::cout<<"Najveca planina unesene matrice je:"<<std::endl;
	  for(int i=0; i<nova_matrica.size();i++){
	  	for(int j=0; j<nova_matrica.at(i).size(); j++){
	  		std::cout<<std::setw(6)<<nova_matrica.at(i).at(j);
	  	}
	  	std::cout<<std::endl;
	  }
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
	catch(...){
		std::cout<<"nesto drugo";
	}
	return 0;
}