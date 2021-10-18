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


std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> matrica){
    std::vector<std::vector<double>> najveca;
    std::vector<std::vector<double>> trenutna;
    std::vector<std::vector<double>> proslo;
    std::vector<std::vector<double>> prazna;
    int n=0;
    double s_predhodna=0;
    if(matrica.size()==0 && matrica.at(0).size()==0) return najveca;
     if(matrica.size()==1 && matrica.at(0).size()==1) return matrica;
     for(int slj=0; slj<matrica.size(); slj++){
     	if(matrica.at(slj).size()!=matrica.at(0).size()) throw std::domain_error("Matrica nije korektna");
     }
    if(matrica.size()==2 || matrica.at(0).size()==2 || matrica.size()==1 || matrica.at(0).size()==1){
    	double max=matrica.at(0).at(0);
    	for(int i=0;i<matrica.size();i++){
    		for(int j=0;j<matrica.at(0).size();j++){
    			if(matrica.at(i).at(j)>=max) max=matrica.at(i).at(j); //std::cout<<max<<" ";
    		}
    	}
    	if(fabs(max-matrica.at(0).at(0))<0.0000001) return najveca;
    	else{
    		trenutna.resize(trenutna.size()+1);
    		trenutna.at(0).push_back(max);
    		return trenutna;
    	}
    }
    for(int i(0); i<matrica.size();i++){
    	for(int j(0);j<matrica.at(0).size();j++){
    		 double s=0;
    		n=1;
    	//	int uslauwhile=0;
    //		double vrh=matrica.at(i).at(j);
    		s_predhodna=matrica.at(i).at(j);
    		double zaoduzet=matrica.at(i).at(j);
    	    while(i+n<matrica.size() && j+n<matrica.at(0).size() && i-n>=0 && j-n>=0){
    	    //	if(n==2)std::cout<<"opaaa janadva janadva";
    	    //	uslauwhile=1;
    	    	int prodji_i=0, prodji_j=0;
    	    	trenutna=prazna;
    	    	s=0;
    			for(int k=i-n;k<=i+n;k++){
    				trenutna.resize(trenutna.size()+1);
    				for(int l=j-n;l<=j+n;l++){
    					//std::cout<<"proso";
    					s+=matrica.at(k).at(l);
    					//if(n==2)std::cout<<"kkk"<<s<<"kkk";
    					trenutna.at(prodji_i).push_back(matrica.at(k).at(l));
    					prodji_j++;
    				}
    				prodji_i++;
    			}
    		//	std::cout<<s<<" ";
    		s-=zaoduzet;
    		zaoduzet=s+zaoduzet;
    		//std::cout<<"zaoduzetslj put je "<<zaoduzet<<"suma je "<<s<<" manja od "<<s_predhodna<<" ";
    			if(s>=s_predhodna){/*std::cout<<s<<" ";*//*std::cout<<"Brejka";*/ break;}
    			else if(trenutna.size()>najveca.size() && s<s_predhodna){proslo=trenutna; /*std::cout<<"ispunjava sumu "<<s<<" ";*/ /*std::cout<<"usosam";/*najveca=trenutna;*/}
		        najveca=proslo;
		        s_predhodna=s;
    	/*	if(uslauwhile){
    			int prodji_i=0;
    			int prodji_j=0;
    			for(int k=i-n;k<=i+n;k++){
    				trenutna.resize(trenutna.size()+1);
    				for(int l=j-n;l<=j+n;l++){
    					trenutna.at(prodji_i).push_back(matrica[k][l]);
    					prodji_j++;
    				}
    				prodji_i++;
    			}
    		}*/
    	//	if(trenutna.size()>najveca.size()) najveca=trenutna;
    	n++;
    	}
    }
    }
    return najveca;
}

int main ()
{
	int m, n;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	if(m<0 || n<0){ std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
	std::vector<std::vector<double>> mati(m, std::vector<double>(n));
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			std::cin>>mati.at(i).at(j);
		}
	}
	std::vector<std::vector<double>> mat;
	try{
	mat=NajvecaPlaninaMatrice(mati);}
	catch(...){
	}
	std::cout<<std::endl<<"Najveca planina unesene matrice je: "<<std::endl;
	for(int i(0);i<mat.size();i++){
		for(int j(0);j<mat.at(0).size();j++){
			std::cout<<std::setw(6)<<mat.at(i).at(j);
		}
		std::cout<<std::endl;
	}
	return 0;
}