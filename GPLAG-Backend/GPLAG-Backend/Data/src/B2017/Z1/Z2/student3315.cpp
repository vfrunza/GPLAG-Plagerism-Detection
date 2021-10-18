#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

typedef std::vector<std::vector<double>> tip;

std::vector<std::vector<double>> planina(std::vector<std::vector<double>> mat,int indexi, int indexj){
	int brojac(0);
	std::vector<std::vector<double>>  m;
	for(int k=1;k<=mat.size()/2;k++){
		int tacna(true);
		for(int i=indexi-k;i<=indexi+k;i++){
			for(int j=indexj-k;j<=indexj+k;j++){
				if(!(i<0||i>mat.size()-1||(j<0)||j>mat.at(0).size()-1)){
					if(indexi==i && indexj==j)continue;
					if(mat.at(indexi).at(indexj)<=mat.at(i).at(j)){
						tacna=false;
					}
				}else{ 
					tacna=false; 
					break;
					
				}
				
			}
			if(!tacna) break;
		}
		if(tacna)brojac++;
	}
	if(brojac==0){
		m.resize(1);
		m.at(0).push_back(mat.at(indexi).at(indexj));
		return m;
	}
	
	int red(0),kolona(0);
	m.resize(brojac*2+1);
	
	for(int i=indexi-brojac;i<=indexi+brojac;i++){
		kolona=0;
		m.at(red).resize(brojac*2+1);
		for(int j=indexj-brojac;j<=indexj+brojac;j++){
			
			m.at(red).at(kolona)=mat.at(i).at(j);
			kolona++;
		}
		red++;
	}
	return m;
}


std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> mat){
	
	// ako se proslijedi grbava matrica
	for(int k=0;k<mat.size();k++){
		if(mat[k].size()!=mat[0].size()){
			throw std::domain_error ("Matrica nije korektna");
		}
	}
	
	// ako se proslijedi matrica formata 0x0
	if(mat.size()==0){
		return mat;
	}
	
	// planina matrice
	
	//funkcija matrica vrati planinu za svaki element
	//treba sada u for petlji za sve elemente naci planine i uporediti ih
	//kada se nadje najveca planina vratit je
	
	//matrica fja prima: matricu, indeks clana na itoj i jtoj poziciji
	
	
	std::vector<tip> vektor_matrica; // vektor koji sadrzi sve matrice kao planine!!, tip-to je deklaracija matrice!

	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat.at(i).size();j++){
			vektor_matrica.push_back(planina(mat,i,j));
		}
	}
	
	int max_index(0);
	for(int i=1;i<vektor_matrica.size();i++){
		if(vektor_matrica.at(max_index).size()<vektor_matrica.at(i).size()) max_index=i;
		else if(vektor_matrica.at(max_index).size()==vektor_matrica.at(i).size()){
			if(vektor_matrica.at(max_index).at(vektor_matrica.at(max_index).size()/2).at(vektor_matrica.at(max_index).size()/2)
			<vektor_matrica.at(i).at(vektor_matrica.at(i).size()/2).at(vektor_matrica.at(i).size()/2)) max_index=i;
			
		}
		
	}
		
		
		
	    return vektor_matrica.at(max_index);
	     
}
	
	

	
	
	











int main (){

	try{
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	std::cin>>m>>n;
	
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!"<<std::endl;
		return 0;
	}
	
	
	
	std::cout<<"Unesite elemente matrice: \n";
	
	std::vector<std::vector<double>> mat(m,std::vector<double>(n));
	std::vector<std::vector<double>> rezultat(m,std::vector<double>(n));
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			std::cin>>mat.at(i).at(j);
		}
	}
	
	rezultat=NajvecaPlaninaMatrice(mat);
	
	// ispis matrice na ekran
	std::cout<<"Najveca planina unesene matrice je: \n";
	for(int i=0;i<rezultat.size();i++){
		for(int j=0;j<rezultat.at(i).size();j++){
			std::cout<<std::setw(6)<<rezultat.at(i).at(j);
		}
		std::cout<<std::endl;	
	}
	}



	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}



	return 0;
}