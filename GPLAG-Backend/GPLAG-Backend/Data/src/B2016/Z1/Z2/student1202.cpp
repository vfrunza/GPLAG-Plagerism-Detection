/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double> > Matrica;
bool Grbava_matrica(Matrica mat){
	bool istina(true);
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[i].size();j++){
			if(mat[i].size()!=mat[0].size()){
				istina=false;
				break;
			}
		}
	}
	return istina;
}
int NajvecaSirina(Matrica a){
	int najvecasirina(0);
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].size();j++){
			int broj=a[i][j];
			int brojac(0);
			if(a[i][j]<0)brojac++;
			while(broj!=0){
				broj/=10;
				brojac++;
			}
		if(brojac>najvecasirina)najvecasirina=brojac;
		}
	}
	return najvecasirina;
}
Matrica H_M(Matrica m){
	Matrica a;
	a.resize(m.size());
	for(int i=0;i<m.size();i++){
		a[i].resize(m[0].size());
		for(int j=0;j<m[i].size();j++){
			a[i][j]=m[i][m[i].size()-j-1];
		}
	}
	return a;
}
Matrica V_M(Matrica m){
	Matrica a;
	a.resize(m.size());
	for(int i=0;i<m.size();i++){
		a[i].resize(m[0].size());
		for(int j=0;j<m[i].size();j++){
			a[i][j]=m[m.size()-i-1][j];
		}
	}
	return a;
}
Matrica VH_M(Matrica m){
	Matrica a;
	a.resize(m.size());
	for(int i=0;i<m.size();i++){
		a[i].resize(m[0].size());
		for(int j=0;j<m[i].size();j++){
			a[i][j]=m[m.size()-i-1][m[i].size()-1-j];
		}
	}
	return a;
}
Matrica OgledaloMatrica(Matrica matrica){
	Matrica mat;
	if(matrica.size()==0)return mat;
	if(Grbava_matrica(matrica)==false)throw std::domain_error("Matrica nije korektna");
	Matrica ver(V_M(matrica));
	Matrica hor(H_M(matrica));
	Matrica ver_hor(VH_M(matrica));
	mat.resize(3*matrica.size());
	int broj_redova=matrica.size();
	int broj_kolona=matrica[0].size();
//	std::cout<<"Broj redova: "<<broj_redova<<" Broj kolona: "<<broj_kolona<<"\n";
	
	for(int i=0;i<mat.size();i++){
		mat[i].resize(3*matrica[0].size());
	}
//	std::cout<<"Broj redova: "<<mat.size()<<" Broj kolona: "<<mat[0].size()<<"\n";
		//	horizontalna 1
		 for(int k=hor.size()-1;k>=0;k--){
		 	for(int l=hor[0].size()-1;l>=0;l--){
		 		mat[k+broj_redova][l]=hor[k][l];
		 	}
		 }
		 // horizontalna 2
		 for(int k=hor.size()-1;k>=0;k--){
		 	for(int l=hor[0].size()-1;l>=0;l--){
		 		mat[k+broj_redova][l+2*broj_kolona]=hor[k][l];
		 	}
		 }
		 //vertikalna 1
		 for(int k=ver.size()-1;k>=0;k--){
		 	for(int l=ver[0].size()-1;l>=0;l--){
		 		mat[k][broj_kolona+l]=ver[k][l];
		 	}
		 }
		 //vertikalna 2
		 for(int k=0;k<ver.size();k++){
		 	for(int l=0;l<ver[0].size();l++){
		 		mat[k+2*broj_redova][broj_kolona+l]=ver[k][l];
		 	}
		 }
		// matrica matrica
		for(int k=0;k<matrica.size();k++){
			for(int l=0;l<matrica[0].size();l++){
				mat[broj_redova+k][broj_kolona+l]=matrica[k][l];
			}
		}
		//ver_hor1, 1.red,slijeva
		for(int k=0;k<ver_hor.size();k++){
			for(int l=0;l<ver_hor[0].size();l++){
				mat[k][l]=ver_hor[k][l];
			}
		}
		//ver_hor 2 , 1.red,zdesna
		 for(int k=0;k<ver_hor.size();k++){
		 	for(int l=0;l<ver_hor[0].size();l++){
		 		mat[k][l+2*broj_kolona]=ver_hor[k][l];
		 	}
		 }
		 //ver_hor3,zadnji red, slijeva
		 for(int k=0;k<ver_hor.size();k++){
		 	for(int l=0;l<ver_hor[0].size();l++){
		 		mat[k+2*broj_redova][l]=ver_hor[k][l];
		 	}
		 }
		 // ver_hor 4,zadnji red,zedesna
		 for(int k=0;k<ver_hor.size();k++){
		 	for(int l=0;l<ver_hor[0].size();l++){
		 		mat[k+2*broj_redova][l+2*broj_kolona]=ver_hor[k][l];
		    }
		 }
		
		
   return mat;
}
int main () {
	int m,n;
	std::cout<<"Unesite dimenzije matrice (m n): ";
	std::cin>>m>>n;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	//Matrica mat= OgledaloMatrica ({{},{4,5,6},{},{6,7,8,9}});
	try{
	Matrica mat(m,std::vector<double>(n));
	std::cout<<"Unesite elemente matrice:"<<std::endl;
    for(int i=0;i<m;i++){
    	for(int j=0;j<n;j++){
    		std::cin>>mat[i][j];
    	}
    }
    
    std::cout<<"Rezultantna matrica: "<<std::endl;
    Matrica matrica=OgledaloMatrica(mat);
    if(matrica.size()==0)return 0;
    //int max=NajvecaSirina(matrica);
    for(int i=0;i<matrica.size();i++){
    	for(int j=0;j<matrica[0].size();j++){
    		std::cout<<std::right<<std::setw(4)<<matrica[i][j];
    }
    std::cout<<std::endl;
    }
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what()<<std::endl;
	}
   /* Matrica ver(V_M(mat));
	Matrica hor(H_M(mat));
	Matrica ver_hor(VH_M(mat));
    for(int i=0;i<hor.size();i++){
    	for(int j=0;j<hor[0].size();j++){
    		std::cout<<hor[i][j]<<" ";
    	}
    	std::cout<<std::endl;
    }*/
	return 0;
}