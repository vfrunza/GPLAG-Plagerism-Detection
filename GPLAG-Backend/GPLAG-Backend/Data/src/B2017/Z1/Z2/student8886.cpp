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
#include <cmath>
#include <vector>
#include <iomanip>
#include <stdexcept>
#define epsilon 0.0001
typedef std::vector<std::vector<double>> Matrica;
Matrica KreirajMatricu(int br_redova, int br_kolona){
	return Matrica(br_redova, std::vector<double>(br_kolona));
}
void IspisiMatricu(Matrica m){
	for(std::vector<double> x : m){
		for(double x1 : x){
			std::cout<<std::setw(6)<<x1;
		}
		std::cout<<std::endl;
	}
}
Matrica UnesiMatricu(int br_redova, int br_kolona){
	auto m(KreirajMatricu(br_redova,br_kolona));
	for(int i=0; i<br_redova; i++){
		for(int j=0; j<br_kolona; j++){
			std::cin>>m.at(i).at(j);
		}
	}
	return m;
}
std::vector<Matrica> StvarniVrhovi(std::vector<Matrica> vekvrhova){
	std::vector<Matrica> vrhovi;
	double Suma(0), Zbir(0);
	for(int k=0; k<vekvrhova.size(); k++){
    Zbir=0;
    if(vekvrhova.at(k).size()==1) vrhovi.push_back(vekvrhova.at(k));
	else if(vekvrhova.at(k).size()%2!=0){ Suma=vekvrhova.at(k).at(vekvrhova.at(k).size()/2).at(vekvrhova.at(k).size()/2);
//	std::cout<<Suma<<std::endl;

	for(int c=0; c<vekvrhova.at(k).size()/2; c++){
		for(int i=0; i<vekvrhova.at(k).size(); i++){
			for(int j=0; j<vekvrhova.at(k).at(i).size(); j++){
				if(i==c || j==c || i==vekvrhova.at(k).size()-1-c || j==vekvrhova.at(k).size()-1-c){
					Zbir+=vekvrhova.at(k).at(i).at(j);
				} 
				
			}
		}
		if(Zbir < Suma){
			Suma=Zbir;
			vrhovi.push_back(vekvrhova.at(k));
		}
	    else break;
//		std::cout<<Zbir<<std::endl;
	}
	}
	}
	return vrhovi;
}
std::vector<Matrica> NajvecePlanine(std::vector<Matrica> v, int vrh){
	std::vector<Matrica> v1;
	for(int i=0; i<v.size(); i++){
			if(v.at(i).size()==vrh) v1.push_back(v.at(i));
	}
	return v1;
}
std::vector<Matrica> NajveciVrhovi(std::vector<Matrica> v){
	std::vector<Matrica> v1;
	int vrh=v.at(0).size();
	int max(0);
			for(int i=0; i<v.size(); i++){
				if(v.at(i).at(vrh/2).at(vrh/2) > max){
						max=v.at(i).at(vrh/2).at(vrh/2);
				}
			}
	for(int i=0; i<v.size(); i++){
		if(fabs(v.at(i).at(vrh/2).at(vrh/2) -max) <= epsilon) v1.push_back(v.at(i));
	}
//	IspisiMatricu(v1.at(2));
	return v1;
}
Matrica NajvecaPlaninaMatrice(Matrica mat){
	Matrica novamat;
	Matrica povratna;
	std::vector<Matrica> vekvrhova;
	for(int i=0; i<mat.size(); i++){
		if(mat.size()== 0 || mat.at(i).size()==0 ) return mat;
		if(mat.at(i).size()!=mat.at(0).size()) throw std::domain_error("Matrica nije korektna");
	}
	
	if(mat.size()==0) return mat;
	if(mat.size()==1) return mat;
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat.at(i).size(); j++){
			int dim=mat.size()-i;
			if(j+1<dim ) dim=j+1;
			if(mat.at(i).size()-j < dim) dim=mat.at(i).size()-j;
			if(i+1 < dim ) dim=i+1;
			int c=dim-1;
			novamat.resize(dim+c);
			for(int k=0; k<dim+c; k++) novamat.at(k).resize(dim+c);
		//	std::cout<<"dim="<<dim<<std::endl;
		    int k=0, l=0; 
			for(int n=i-c; n<=i+c; n++){
				k=0;
				for(int m=j-c; m<=j+c; m++){
					novamat.at(l).at(k)=mat.at(n).at(m);
					k++;
				}
				l++;
			}
			vekvrhova.push_back(novamat);
			
		}
	}
	//Sada oznaciti vrhove koji ne mogu to biti
//	IspisiMatricu(novamat);
	auto novivekvrhova=StvarniVrhovi(vekvrhova);
//	IspisiMatricu(novivekvrhova.at(0));

	int vrh=novivekvrhova.at(0).size();
	for(int k=0; k<novivekvrhova.size();k++){
		if(novivekvrhova.at(k).size() > vrh && novivekvrhova.at(k).size()%2!=0) vrh=novivekvrhova.at(k).size(); 
	}
/*
	for(int i=0; i<novivekvrhova.size(); i++){
		for(int j=i+1; j<novivekvrhova.size(); j++){
			if(novivekvrhova.at(i).size() == novivekvrhova.at(j).size() && novivekvrhova.at(i).size()==vrh ){
			     if(novivekvrhova.at(i).at(int(vrh/2)).at(int(vrh/2)) > novivekvrhova.at(j).at(int(vrh/2)).at(int(vrh/2))){
			     	if(povratna.size()==0) povratna=novivekvrhova.at(i);
			     	else if(povratna.at(vrh/2).at(vrh/2) < novivekvrhova.at(i).at(vrh/2).at(vrh/2)) povratna=novivekvrhova.at(i);
			     } 
			     else if(fabs(novivekvrhova.at(i).at(int(vrh/2)).at(int(vrh/2)) - novivekvrhova.at(j).at(int(vrh/2)).at(int(vrh/2))) <= epsilon){
			     	int prva_koordinata(0), prva_koordinata1(0), druga_koordinata(0), druga_koordinata1(0);
			     	for(int n=0; n<mat.size(); n++){
			     		for(int m=0; m<mat.at(0).size(); m++){
			     			if(fabs(mat.at(n).at(m) - novivekvrhova.at(i).at(vrh/2).at(vrh/2))<=epsilon){
			     				prva_koordinata=n; 
			     				druga_koordinata=m;
			     			}
			     			else if(fabs(mat.at(n).at(m) - novivekvrhova.at(j).at(vrh/2).at(vrh/2)) <= epsilon ){
			     				prva_koordinata1=n;
			     				druga_koordinata1=m;
			     			}
			     			
			     		}
			     	}
			     	if(prva_koordinata < prva_koordinata1) povratna=novivekvrhova.at(i);
			     	else if(prva_koordinata==prva_koordinata1){
			     		if(druga_koordinata < druga_koordinata1) povratna=novivekvrhova.at(i);
			     		else povratna=novivekvrhova.at(j);
			     	}
			     	else povratna=novivekvrhova.at(j);
			     }
			     else povratna=novivekvrhova.at(j);
			}
		    else if(novivekvrhova.at(i).size()==vrh && povratna.size()==0) povratna=novivekvrhova.at(i);
		}
	}
*/

	auto najplanine=NajvecePlanine(novivekvrhova,vrh);
	if(najplanine.size()==1) povratna=najplanine.at(0);
	else{ 
		if(NajveciVrhovi(najplanine).size() > 1){
			auto koordinate=NajveciVrhovi(najplanine);
			povratna=koordinate.at(0);
			//ovdje dalje nastaviti ispitivati koordinate
		}
		else{
			int max(0);
			for(int i=0; i<najplanine.size(); i++){
				if(najplanine.at(i).at(vrh/2).at(vrh/2) > max){
						max=najplanine.at(i).at(vrh/2).at(vrh/2);
						povratna=najplanine.at(i);
				}
			}
		}
		
	}

//	IspisiMatricu(povratna);
	return povratna;
}
int main ()
{
//	Matrica m={{0,0,0,15,12,6},{1,25,1,5,2,9},{1,1,20,15,10,5},{3,2,19,130,14,8},{90,6,20,12,17,2},{12,3,5,1,8,4}};
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	int n(0), m(0);
	std::cin>>n>>m;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice: "<<std::endl;
    auto m1(UnesiMatricu(n, m));
    std::cout<<"Najveca planina unesene matrice je: "<<std::endl;
    try{
	auto mat=NajvecaPlaninaMatrice(m1);
	IspisiMatricu(mat);
    }
    catch(std::domain_error izuzetak){
    	std::cout<<izuzetak.what()<<std::endl;
    	return 0;
    }
	return 0;
}