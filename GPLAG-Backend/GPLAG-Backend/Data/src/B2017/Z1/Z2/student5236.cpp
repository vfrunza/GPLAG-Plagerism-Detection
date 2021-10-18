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

std::vector<std::vector<double>>KreirajMatricu(int br_redova,int br_kolona){
if(br_redova <0 || br_kolona<0)throw "Dimenzije matrice moraju biti nenegativne!";
return std::vector<std::vector<double>>(br_redova,std::vector<double>(br_kolona));
}
int BrojRedova(std::vector<std::vector<double>>mat){
	return mat.size();
}
int BrojKolona(std::vector<std::vector<double>>mat){
	return mat.at(0).size();
}
std::vector<std::vector<double>>NajvecaPlaninaMatrice(std::vector<std::vector<double>>mat){
	int sirina=mat.at(0).size();
	bool a(true);
	for(int g(0);g<BrojRedova(mat);g++){
		int sirina1=mat.at(g).size();
		for(int f(0);f<sirina;f++){
			continue;
		}
		if(sirina!=sirina1){
			a=false;
			break;
		}
	}
	if(!a)throw std::domain_error("Matrica nije korektna");
	std::vector<double>v;
	std::vector<std::vector<double>>mat1;
	if((BrojKolona(mat)>0 && BrojKolona(mat)<3) || (BrojRedova(mat)>0 && BrojRedova(mat)<3)){
		v.push_back(mat.at(BrojRedova(mat)-1).at(BrojKolona(mat)-1));
		mat1.push_back(v);
		v.clear();
		return mat1;
	}

	int suma1,br1(1),br(1);
	for(int i(0);i<BrojRedova(mat);i++){
		for(int j(0);j<BrojKolona(mat);j++){
			suma1=mat.at(i).at(j);
			br=1;br1=1;
			if(i==0 || i==(BrojRedova(mat)-1) || j==0 || j==(BrojKolona(mat)-1)){
				continue;
			}else{
				int suma(0);
				while((i-br)>=0 && (i+br)<BrojRedova(mat) && (j-br)>=0 && (j+br)<BrojKolona(mat)){
					for(int k(i-br);k<(i+br);k++){
						for(int l(j-br);l<(j+br);l++){
							suma+=mat.at(k).at(l);
						}
					}
					suma-=suma1;
					if(suma>=suma1){
						break;
					}else{
						suma1=suma;
					}
			        br++;
				}
				if(mat1.size()==0 && br>1){
					br--;
					br1=br;
					for(int k(i-br);k<=(i+br);k++){
						for(int l(j-br);l<=(j+br);l++){
							v.push_back(mat.at(k).at(l));
						} 
						mat1.push_back(v);
						v.clear();
					}
				}else if(br>br1 && mat.size()!=0){
					br--;
					br1=br;
					mat1.clear();
					for(int k(i-br);k<(i+br);k++){
						for(int l(j-br);l<(j+br);l++){
							v.push_back(mat.at(k).at(l));
						}
						mat1.push_back(v);
					}
					
				}
			}
		}
	}
	return mat1;
}
int main ()
{
	try{
	int m,n;
	std::vector<std::vector<double>>mat;
	std::vector<std::vector<double>>mat1;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m;
	std::cin>>n;
	mat=KreirajMatricu(m,n);
	std::cout<<"Unesite elemente matrice: ";
	for(int i(0);i<m;i++){
		for(int j(0);j<n;j++){
			std::cin>>mat.at(i).at(j);
		}
	}
	std::cout<<std::endl;
	mat1=NajvecaPlaninaMatrice(mat);
	std::cout<<"Najveca planina unesene matrice je:"<<std::endl;
	for(int i(0);i<BrojRedova(mat1);i++){
		for(int j(0);j<BrojKolona(mat1);j++){
			std::cout<<std::setw(6)<<mat1.at(i).at(j);
		}
		std::cout<<std::endl;
	}
	}catch(std::domain_error izuzetak){
		std::cout<<"Izuzetak: "<<izuzetak.what()<<std::endl;
	}catch(const char poruka[]){
		std::cout<<poruka<<std::endl;
	}
	return 0;
}
