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

typedef std::vector<std::vector<double>> Matrica;

Matrica NapraviMatricu(int m, int n) {
	return Matrica(m, std::vector<double> (n));
}

Matrica UnesiMatricu(int m, int n) {
	Matrica A(m, std::vector<double> (n));
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			std::cin >> A[i][j];
		}
	}
	return A;
}

Matrica NapraviOgledaloMatricu(Matrica A, Matrica h, Matrica v, Matrica hv, int br_redova, int br_kolona) {
	Matrica B(br_redova, std::vector<double> (br_kolona));
	for(int i=0; i<br_redova; i++) {
		for(int j=0; j<br_kolona; j++) {
			if(i<br_redova/3 && j<br_kolona/3) B[i][j]=hv[i][j];
			else if(i>=br_redova/3 && i<2*br_redova/3 && j<br_kolona/3) B[i][j]=h[i-h.size()][j];
			else if(i>=2*br_redova/3 && j<br_kolona/3) B[i][j]=hv[i-2*hv.size()][j];
			else if(i<br_redova/3 && j>=br_kolona/3 && j<2*br_kolona/3) B[i][j]=v[i][j-v[0].size()];
			else if(i>=br_redova/3 && i<2*br_redova/3 && j>=br_kolona/3 && j<2*br_kolona/3) B[i][j]=A[i-A.size()][j-A[0].size()];
			else if(i>=2*br_redova/3 && j>=br_kolona/3 && j<2*br_kolona/3) B[i][j]=v[i-2*v.size()][j-v[0].size()];
			else if(i<br_redova/3 && j>=2*br_kolona/3) B[i][j]=hv[i][j-2*hv[0].size()];
			else if(i>=br_redova/3 && i<2*br_redova/3 && j>=2*br_kolona/3) B[i][j]=h[i-h.size()][j-2*h[0].size()];
			else B[i][j]=hv[i-2*hv.size()][j-2*hv[0].size()];
		}
	}
	return B;
}

Matrica OgledaloMatrica(Matrica A) {
	for(int i=0; i<A.size(); i++) {
		for(int j=0; j<A.size(); j++) {
			if(A[i].size()!=A[j].size()) throw std::domain_error("Matrica nije korektna");
		}
	}
	int brkolona(0);
	for(int i=0; i<A.size(); i++) {
		for(int j=0; j<A[i].size(); j++) brkolona++;
		break;
	}
	Matrica B, h=A, v=A, hv=A;
	for(int i=0; i<v.size()/2; i++) {
		std::vector<double> pomocni;
		pomocni=std::move(v[i]);
		v[i]=std::move(v[v.size()-(i+1)]);
		v[v.size()-(i+1)]=std::move(pomocni);
	}
	for(int i=0; i<h.size(); i++) {
		for(int j=0; j<h[i].size()/2; j++) {
			double pomocni;
			pomocni=h[i][j];
			h[i][j]=h[i][h[i].size()-(j+1)];
			h[i][h[i].size()-(j+1)]=pomocni;
		}
	}
	for(int i=0; i<hv.size()/2; i++) {
		std::vector<double> pomocni;
		pomocni=std::move(hv[i]);
		hv[i]=std::move(hv[hv.size()-(i+1)]);
		hv[hv.size()-(i+1)]=std::move(pomocni);
	}
	for(int i=0; i<hv.size(); i++) {
		for(int j=0; j<hv[i].size()/2; j++) {
			double pomocni;
			pomocni=hv[i][j];
			hv[i][j]=hv[i][hv[i].size()-(j+1)];
			hv[i][hv[i].size()-(j+1)]=pomocni;
		}
	}
	B=NapraviOgledaloMatricu(A, h, v, hv, 3*A.size(), 3*brkolona);
	return B;
}
	
int main ()
{	
	std::cout << "Unesite dimenzije matrice (m n): ";
	int m, n;
	std::cin >> m >> n;
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	auto A=NapraviMatricu(m, n);
	std::cout << "Unesite elemente matrice: ";
	std::cout << std::endl;
	A=UnesiMatricu(m, n);
	try {
		A=OgledaloMatrica(A);
		std::cout << "Rezultantna matrica: " << std::endl;
		for(int i=0; i<A.size(); i++) {
			for(int j=0; j<A[i].size(); j++) {
				std::cout << std::setw(4) << std::right << A[i][j];
			}
			std::cout << std::endl;
		}
	}
	catch(std::domain_error izuzetak) {
		std::cout << izuzetak.what();
	}
	return 0;
}