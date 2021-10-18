#include <iostream>
#include <iomanip> //radi setw i setprecision
#include <vector>

typedef std::vector <std::vector <double>> DoubleMatrica;

//Prototipovi funkcija
DoubleMatrica KreirajMatricu (int m, int n);
DoubleMatrica KreirajJedinicnu (DoubleMatrica A);
DoubleMatrica HorizontalnaMatrica(DoubleMatrica A, DoubleMatrica I );
DoubleMatrica VertikalnaMatrica (DoubleMatrica A);
DoubleMatrica KombinovanaMatrica (DoubleMatrica A);
DoubleMatrica OgledaloMatrica (DoubleMatrica A);

void IspisiMatricu (DoubleMatrica m) {								//Funkcija za ispis
	for (int i=0; i<m.size(); i++) {
		for (int j=0; j<m.at(0).size(); j++) {
			std::cout<<std::setw(4)<<m.at(i).at(j);
			}
		std::cout<<"\n";
	}
}

int main () {
	std::cout<<"Unesite dimenzije matrice (m n): ";
	DoubleMatrica Nula (0, std::vector<double> (0));
	DoubleMatrica mirror;
	int m, n;
	std::cin>>m>>n;
	if (m<0 || n<0) {
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout<<"Unesite elemente matrice: ";
	if (m==0 && n==0) {
		std::cout<<"\nRezultantna matrica: ";
		mirror=Nula;
		IspisiMatricu(mirror);
		return 0;
	} 
	/*if (m==0 && n!=0) {
		std::cout<<"Rezultantna matrica: ";
		DoubleMatrica GreskaUDimenzijama (m, std::vector <double> (0));
		IspisiMatricu(GreskaUDimenzijama);
		return 0;
	}*/
	
	
	DoubleMatrica A(KreirajMatricu(m,n));
	
	//Jedinicna matrica (za horizontalnu)
	DoubleMatrica I(KreirajJedinicnu(A));
	DoubleMatrica h(HorizontalnaMatrica(A, I));
	DoubleMatrica v (VertikalnaMatrica (A));
	DoubleMatrica hv (KombinovanaMatrica(A));
	mirror= OgledaloMatrica(A);
	
	std::cout<<"\nRezultantna matrica:\n";
	IspisiMatricu(mirror);
		return 0;
}

DoubleMatrica KreirajMatricu (int m, int n) {
	double a0=0; //pocetna vrijednost
	DoubleMatrica A(m, std::vector<double> (n, a0));
	
	
	for(int i=0; i<A.size(); i++) {
		for(int j=0; j<A[0].size(); j++) {
			std::cin>>A[i][j];
			
		}
	}
	
	return A;
}

//Jedinicna matrica
DoubleMatrica KreirajJedinicnu (DoubleMatrica A) {
	double a0=1;
	int temp(0);
	DoubleMatrica I(A[0].size(), std::vector <double> (A[0].size(), a0));
	if (A[0].size()>1) {
	for(int i=0; i<I.size(); i++) {
		for(int j=0; j<I[0].size(); j++) {
			if (j==I.size()-i-1) I[i][j]=1;
			else I[i][j]=0;
		}
		}
	}
	return I;
}

DoubleMatrica HorizontalnaMatrica (DoubleMatrica A, DoubleMatrica I) {
	DoubleMatrica h(A.size(), std::vector <double> (A[0].size()));
	int br_redova_A (A.size());
	int br_redova_I (I.size());
	int br_kolona_A (A[0].size());
	int br_kolona_I (I[0].size());
	
	for(int i=0; i<br_redova_A; i++) {
		for (int j=0; j<br_kolona_I; j++) {
			double suma(0);
			for(int k=0; k<br_redova_I; k++) 
				suma+=A[i][k]*I[k][j];
				h[i][j]=suma;
		}
		
	}
	return h;
}
	
//Vertikalna matrica
DoubleMatrica VertikalnaMatrica(DoubleMatrica A) {
	DoubleMatrica v(A.size(), std::vector <double> (A[0].size()));
	int br_redova_A (A.size());
	int br_kolona_A (A[0].size());
	
	for(int i=0; i<=(br_redova_A)/2; i++) {
		for(int j=0; j<br_kolona_A; j++) {
			v[A.size()-i-1][j]=A[i][j];
			v[i][j]=A[A.size()-i-1][j];
		}
	}
	return v;
}
	
//Kombinovana matrica
DoubleMatrica KombinovanaMatrica(DoubleMatrica A) {
	DoubleMatrica I(KreirajJedinicnu(A));
	DoubleMatrica hv(VertikalnaMatrica(HorizontalnaMatrica(A,I)));
	return hv;
}

//Konacno, ogledalo
DoubleMatrica OgledaloMatrica (DoubleMatrica A) {
	DoubleMatrica I(KreirajJedinicnu(A));
	DoubleMatrica h(HorizontalnaMatrica(A, I));
	DoubleMatrica v(VertikalnaMatrica(A));
	DoubleMatrica hv (VertikalnaMatrica(h));
	const int m=3*A.size();
	const int n=3*A[0].size();
	
	DoubleMatrica mirror (m, std::vector <double> (n));
	
	for(int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			if (i<A.size() && j<hv[0].size())				mirror[i][j]=hv[i][j];
			if (i<A.size() && (j>=hv[0].size() && j<2*hv[0].size())) mirror[i][j]=v[i][j-hv[0].size()];
			if (i<A.size() && (j>=2*hv[0].size() && j<3*hv[0].size())) mirror[i][j]=hv[i][j-2*hv[0].size()];
			
			if((i>=A.size() && i<2*A.size()) && j<hv[0].size()) mirror[i][j]=h[i-A.size()][j];
			if((i>=A.size() && i<2*A.size()) && (j>=hv[0].size() && j<2*hv[0].size())) mirror[i][j]=A[i-A.size()][j-hv[0].size()];
			if((i>=A.size() && i<2*A.size()) && (j>=2*hv[0].size() && j<3*hv[0].size())) mirror[i][j]=h[i-A.size()][j-2*hv[0].size()];
	
			if ((i>=2*A.size() && i<3*A.size()) && j<hv[0].size()) mirror[i][j]=hv[i-2*A.size()][j];
			if ((i>=2*A.size() && i<3*A.size()) && (j>=hv[0].size() && j<2*hv[0].size())) mirror[i][j]=v[i-2*A.size()][j-hv[0].size()];
			if ((i>=2*A.size() && i<3*A.size()) && (j>=2*hv[0].size() && j<3*hv[0].size())) mirror[i][j]=hv[i-2*A.size()][j-2*hv[0].size()];
		}
	}
	return mirror;
	
}
	

	











