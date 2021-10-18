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

double Suma_Koncentricnih(std::vector<std::vector<double>> mat1,int k, int z,int daljina){
	double suma(0);
	if(k-daljina>=0 && z-daljina>=0 && k+daljina<=mat1.size() && z+daljina<=mat1.size()){
	for(int i=k-daljina;i<=(k+daljina);i++){
		for(int j=z-daljina;j<=(z+daljina);j++){
			if((i==k-daljina || i==k+daljina) && (j>=(z-daljina) && j<=(z+daljina))) suma+=mat1.at(i).at(j);
			else if((j==z-daljina || j==z+daljina) && (i>k-daljina && i<k+daljina)) suma+=mat1.at(i).at(j);
		}
	}
	}
	return suma;
}

std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> matrica){
	double sumakoncentricnih(0);
	std::vector<std::vector<double>> planincina;
	int udaljenost(0);
	int max(0);
	double suma(0);
	int x(0),y(0);
	int broj;
	if(matrica.size()!=0){
	broj=matrica.at(0).size();
	for(int i=0;i<matrica.size();i++){
		if(broj!=matrica.at(i).size()) throw std::domain_error ("Matrica nije korektna");
	}
	}
	if(matrica.size()!=0){
	for(int i=0;i<matrica.size();i++){
		for(int j=0;j<matrica.at(i).size();j++){
				if(i-udaljenost>=0 && j-udaljenost>=0 && i+udaljenost<matrica.size() && j+udaljenost<matrica.at(i).size()) sumakoncentricnih=Suma_Koncentricnih(matrica,i,j,udaljenost);
				if(sumakoncentricnih<=matrica.at(i).at(j)){
					suma=sumakoncentricnih;
					udaljenost++;
					if(i-udaljenost>=0 && j-udaljenost>=0 && i+udaljenost<matrica.size() && j+udaljenost<matrica.at(i).size()) sumakoncentricnih=Suma_Koncentricnih(matrica,i,j,udaljenost);
					while(i-udaljenost>=0 && j-udaljenost>=0 && i+udaljenost<matrica.size() && j+udaljenost<matrica.at(i).size() && sumakoncentricnih<suma){
						suma=sumakoncentricnih;
						udaljenost++;// std::cout<<".."<<udaljenost<<".. ";
					if(i-udaljenost>=0 && j-udaljenost>=0 && i+udaljenost<matrica.size() && j+udaljenost<matrica.at(i).size()) sumakoncentricnih=Suma_Koncentricnih(matrica,i,j,udaljenost);
					}
					if(udaljenost>=max){
				//		std::cout<<" { "<<udaljenost<<" } ";
				//	std::cout<<"  druga { "<<udaljenost<<" } ";
					max=udaljenost;
				if(matrica.at(i).at(j)>=matrica.at(x).at(y)) {x=i;y=j;}
					}
				}
				udaljenost=0;
				suma=0;
				sumakoncentricnih=0;
				}
			
		}
		max--;
	int k=0;
		int z=0;
		int kolika=2*max+1;
		planincina.resize(kolika);
		for(int i=0;i<kolika;i++) planincina.at(i).resize(kolika);
		for(int i=x-max;i<x+max+1;i++){
			for(int j=y-max;j<y+max+1;j++){
				planincina.at(k).at(z)=matrica.at(i).at(j);
				z++;
			}
			k++;
		    z=0;
		}
	}
	
	return planincina;
	
		
	
}




int main ()
{
	
	/*std::cout<<"Unesite dimenzije matrice (m i n): ";
	int m(0),n(0);
	std::cin>>m>>n;
	if(m<0 || n<0) std::cout<<"Dimenzije matrice moraju biti nenegativne!";*/
	//else{/*
	/*std::cout<<"Unesite elemente matrice:"<<std::endl;
	std::vector<std::vector<double>> planinica;
	planinica.resize(m);
	for(int i=0;i<m;i++) planinica.at(i).resize(n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			std::cin>>planinica.at(i).at(j);
		}
	}*/
	
   try{	
  	//std::vector<std::vector<double>> planinica {{0,0,0,15,12,6},{1,25,1,5,2,9},{1,1,20,15,10,5},{3,2,19,130,14,8},{90,6,20,12,17,2},{12,3,5,1,8,4}};
  	//std::vector<std::vector<double>> planinica {{24}};
  	//std::vector<std::vector<double>> planinica {{0,0,0,15},{1,25,1,5},{1,1,20,15}};
  	//std::vector<std::vector<double>> planinica{{1,2},{3,4}};
  	std::vector<std::vector<double>> planinica{{-1,-1,-1},{-1,-7.9,-1},{-1,-1,-1}};
  	std::cout<<"Najveca planina unesene matrice je: "<<std::endl;
	std::vector<std::vector<double>> najveca_planina;
	najveca_planina=NajvecaPlaninaMatrice(planinica);
	for(int i=0;i<najveca_planina.size();i++){
		for(int j=0;j<najveca_planina.at(0).size();j++){
			std::cout<<std::setw(6)<<najveca_planina.at(i).at(j);
		}
		std::cout<<std::endl;
	}
	}
	catch (std::domain_error izuzetak)
	{
		std::cout<<izuzetak.what();
	}
	
	//std::vector<std::vector<double>> matricicia{{25}};
	//std::cout<<"["<<NajvecaPlaninaMatrice(planinica)<<"]  ";
    //std::cout<<"["<<Suma_Koncentricnih(planinica,1,1,1);
    //if(1-1>=0) std::cout<<" KAKO?";
	return 0;
}