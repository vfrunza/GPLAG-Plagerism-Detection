/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	at izuzeci
*/
#include<iostream>
#include<vector>
#include<iomanip>
#include <stdexcept>
typedef std::vector<std::vector<double>> Matrica;
typedef std::vector<std::vector<std::vector<std::vector<double>>>> Matrica4D;
Matrica4D Kreiraj4DMatricu (int x, int y){
	return Matrica4D (3, std::vector<std::vector<std::vector<double>>>(3,std::vector<std::vector<double>>(x,std::vector<double>(y))));
}
Matrica KreirajMatricu (int x, int y){
	return Matrica (x, std::vector<double>(y));
}
Matrica Matrica_h (Matrica m){
	Matrica pomocna (m);
	for (int i=0; i<m.size(); i++){
		m[i]=pomocna[m.size() -1-i];
	}
	return m;
}
Matrica Matrica_v (Matrica m){
		Matrica pomocna (m);
		for (int i=0; i<m.size(); i++){
		for (int j=0; j<m[i].size(); j++){
		m[i][j]=pomocna[i][m[i].size() -1-j];
	}
	}
	return m;
}
Matrica Matrica_hv (Matrica m){
	m = Matrica_h (m);
	m = Matrica_v (m);
	return m;
}
Matrica OgledaloMatrica(Matrica m){
	Matrica h_matrica=Matrica_h(m);
    Matrica	v_matrica=Matrica_v(m);
	Matrica hv_matrica=Matrica_hv(m);
	for (int i=1; i<m.size(); i++) {
		if (m[0].size()!=m[i].size()) throw std::domain_error("Matrica nije korektna");
	}
	int y; 
	int x = m.size(); if (x ==0) {y =0;}
	else { y = m[0].size(); }
	Matrica4D a(Kreiraj4DMatricu(x,y));
	Matrica kenan(KreirajMatricu(3*x,3*y)); 
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
		if ((i==0 && j==0)||(i==2 && j==0)||(i==2 && j==2)||(i==0 && j==2)) a[i][j]=hv_matrica;
		if (i==1&&j==1) a[i][j]=m;
		if ((i==1&&j==0)|| (i==1&&j==2)) a[i][j]=v_matrica;
		if ((i==0 &&j==1) ||(i==2 && j==1)) a[i][j]=h_matrica;
	}
	}
	int tic(0), tac(0);
	for (int i=0; i<3; i++){
		int k(0);
		for (int z=0; z<x; z++){
			for (int j=0; j<3; j++){
				for (int l=0; l<y; l++) { kenan[tic][tac]=a[i][j][k][l]; tac++;}
			} tac =0; tic++; k++;
			
		}
	}
	return kenan;
}
int main ()
{
	std::cout<<"Unesite dimenzije matrice (m n): ";
		int x,y;
	std::cin>>x;
	std::cin>>y;
	if (x<0 || y<0) {std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
	Matrica a(KreirajMatricu(x,y)); 
	std::cout<<"Unesite elemente matrice: "<<std::endl;
	for (int i=0; i<x; i++){
		for (int j=0; j<y; j++){
			std::cin>>a[i][j];  
		}	
	} Matrica b;
	std::cout<<"Rezultantna matrica:"<<std::endl;
	try{b=(OgledaloMatrica(a)); } 
	catch(std::domain_error e){std::cout<<e.what(); return 0;}
	for (int i =0; i<3*x; i++){
		for (int j =0; j<3*y; j++){
		std::cout<<std::setw(4)<<b[i][j];
	}
	std::cout<<std::endl;
	} 
	return 0;
}