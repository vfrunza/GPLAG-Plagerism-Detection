#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

typedef std::vector<vector<double>> Matrica;
typedef std::vector<double> Vektor;

Matrica KreirajMatricu(int m, int n){
	return Matrica(m,Vektor(n));
}
/*
int BrojRedova(Matrica m){	//funkcija za saznavanje broja redova
	int br_redova(0)
	for(int i=0;i<m.size();i++){
		br_redova++;	
	}
	return br_redova;
}
*/
int SirinaKolone(Matrica m, int i){
	int br_kolona(0);
	for(int j=0;j<m.at(i).size();j++){
		br_kolona++;
	}
}

Matrica NajvecaPlaninaMatrice(Matrica m){
	int visina(m.size()),sirina(0);
	for(int i=0;i<visina-1;i++){	//petlja koja otkriva grbavu matricu
		if(SirinaKolone(m,i)!=SirinaKolone(m,i+1)) throw "Ovo je grbava matrica!";
	}
	sirina=SirinaKolone(m,0);
	//pronalazak planine matrice (IDEEMOOOO!!!)
	Matrica m1(KreirajMatricu(visina,sirina));
	int zbir(0),l,k,i,j;
	for(i=0;i<m.size();i++){
		for(j=0;j<m.at(i).size();j++){
			if(i==0 && j==0){
				zbir=((m.at(i).at(j+1))+(m.at(i+1).at(j+1))+(m.at(i+1).at(j)));
				if(zbir<m.at(i).at(j))
		}
	}
	
	return m1;
}


int main ()
{
	return 0;
}