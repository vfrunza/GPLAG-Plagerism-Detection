/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<iomanip>
#include<vector>
#include<stdexcept>
std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> Matrica){
	int Red;
	for(int i=0;i<Matrica.size();i++){
		if(i==0){
			Red=Matrica[i].size();
			continue;
		}
		if(Matrica[i].size()!=Red) throw std::domain_error("Matrica nije korektna"); 
	}
	int BrojRedova(0);
	int BrojKolona(0);
	BrojRedova=Matrica.size();
	if(BrojRedova!=0) BrojKolona=Matrica[0].size();
	auto VertikalnoOgledalo(Matrica);
	for(int i=0; i<(VertikalnoOgledalo.size()/2);i++){
		for(int j=0;j<VertikalnoOgledalo[i].size(); j++){
			double tmp(VertikalnoOgledalo[i][j]);
			VertikalnoOgledalo[i][j]=VertikalnoOgledalo[VertikalnoOgledalo.size()-1-i][j];
			VertikalnoOgledalo[VertikalnoOgledalo.size()-1-i][j]=tmp;
		}
	}
	auto HorizontalnoOgledalo(Matrica);
	for(int i=0; i<HorizontalnoOgledalo.size();i++){
		for(int j=0;j<(HorizontalnoOgledalo[i].size()/2); j++){
			double tmp(HorizontalnoOgledalo[i][j]);
			HorizontalnoOgledalo[i][j]=HorizontalnoOgledalo[i][HorizontalnoOgledalo[i].size()-j-1];
			HorizontalnoOgledalo[i][HorizontalnoOgledalo[i].size()-j-1]=tmp;
		}
	}
	auto KombinovanoOgledalo(Matrica);
	for(int i=0; i<KombinovanoOgledalo.size();i++){
		for(int j=0;j<(KombinovanoOgledalo[i].size()/2); j++){
			double tmp(KombinovanoOgledalo[i][j]);
			KombinovanoOgledalo[i][j]=KombinovanoOgledalo[i][KombinovanoOgledalo[i].size()-j-1];
			KombinovanoOgledalo[i][KombinovanoOgledalo[i].size()-j-1]=tmp;
		}
	}
	for(int i=0; i<(KombinovanoOgledalo.size()/2);i++){
		for(int j=0;j<KombinovanoOgledalo[i].size(); j++){
			double tmp(KombinovanoOgledalo[i][j]);
			KombinovanoOgledalo[i][j]=KombinovanoOgledalo[KombinovanoOgledalo.size()-1-i][j];
			KombinovanoOgledalo[KombinovanoOgledalo.size()-1-i][j]=tmp;
		}
	}
	std::vector<std::vector<double>> Ogledalo;
	Ogledalo.resize(3*BrojRedova);
	for(int a=0; a<BrojRedova;a++){
		for(int b=0; b<BrojKolona;b++) Ogledalo[a].push_back(KombinovanoOgledalo[a][b]);
		for(int b=0; b<BrojKolona;b++) Ogledalo[a].push_back(VertikalnoOgledalo[a][b]);
		for(int b=0; b<BrojKolona;b++) Ogledalo[a].push_back(KombinovanoOgledalo[a][b]);
	}
	for(int a=BrojRedova; a<2*BrojRedova;a++){
		for(int b=0; b<BrojKolona;b++) Ogledalo[a].push_back(HorizontalnoOgledalo[a-BrojRedova][b]);
		for(int b=0; b<BrojKolona;b++) Ogledalo[a].push_back(Matrica[a-BrojRedova][b]);
		for(int b=0; b<BrojKolona;b++) Ogledalo[a].push_back(HorizontalnoOgledalo[a-BrojRedova][b]);
	}
	for(int a=2*BrojRedova; a<3*BrojRedova;a++){
		for(int b=0; b<BrojKolona;b++) Ogledalo[a].push_back(KombinovanoOgledalo[a-2*BrojRedova][b]);
		for(int b=0; b<BrojKolona;b++) Ogledalo[a].push_back(VertikalnoOgledalo[a-2*BrojRedova][b]);
		for(int b=0; b<BrojKolona;b++) Ogledalo[a].push_back(KombinovanoOgledalo[a-2*BrojRedova][b]);
	}
	return Ogledalo;
}
int main(){
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin>>m>>n;
	if(m>=0 && n>=0){
		std::cout<<"Unesite elemente matrice: ";
		std::vector<std::vector<double>> Matrica(m,std::vector<double>(n));
		for(int i=0;i<Matrica.size();i++) for(int j=0;j<Matrica[i].size();j++) std::cin>>Matrica[i][j];
		try{
			auto NovaMatrica(OgledaloMatrica(Matrica));
			std::cout<<"\nRezultantna matrica: \n";
			for(auto x:NovaMatrica){
				for(auto y: x) std::cout<<std::setw(4)<<y;
				std::cout<<"\n";
			}
		}catch(std::domain_error grbava){
			std::cout<<grbava.what();
		}
	}else std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	return 0;
}