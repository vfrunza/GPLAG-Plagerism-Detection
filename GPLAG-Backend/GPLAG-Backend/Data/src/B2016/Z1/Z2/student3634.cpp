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

std::vector<std::vector<double>> HorizontalnoOgledalo(std::vector<std::vector<double>>mat) {
	int m(mat.size()), n(mat[0].size());
	std::vector<std::vector<double>>h(m, std::vector<double>(n));
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat[i].size(); j++) {
			h[i][j]=mat[i][mat[i].size()-j-1];
		}
	}
	
	return h;
}
std::vector<std::vector<double>> VertikalnoOgledalo(std::vector<std::vector<double>>mat) {
	int m(mat.size()), n(mat[0].size());
	std::vector<std::vector<double>>v(m, std::vector<double>(n));
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat[i].size(); j++) {
			v[i][j]=mat[mat.size()-i-1][j];
		}
	}
	return v;
}
std::vector<std::vector<double>> KombinovanoOgledalo(std::vector<std::vector<double>>mat) {
	int m(mat.size()), n(mat[0].size());
	std::vector<std::vector<double>>h(m, std::vector<double>(n));
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat[i].size(); j++) {
			h[i][j]=mat[i][mat[i].size()-j-1];
		}
	}
	std::vector<std::vector<double>>hv(m, std::vector<double>(n));
	for(int i=0; i<h.size(); i++) {
		for(int j=0; j<h[i].size(); j++) {
			hv[i][j]=h[h.size()-i-1][j];
		}
	}
	return hv;
}

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> mat) {
	
	if(mat.size()==0) return mat;
	
	int m(mat.size()), n(mat[0].size());
	std::vector<std::vector<double>>spiglo(3*m, std::vector<double>(3*n));

	
	for(int i=0; i<3*m; i++) {
		for(int j=0; j<3*n; j++) {
		  if(i<m)
        {
            if(j<n)
            {
                spiglo[i][j]=KombinovanoOgledalo(mat)[i%m][j%n];
            }else if(j>=n && j<2*n)
            {
                spiglo[i][j]=VertikalnoOgledalo(mat)[i%m][j%n];
            }else if(j>=2*n && j<3*n)
            {
                spiglo[i][j]=KombinovanoOgledalo(mat)[i%m][j%n];
            }
        }else if(i>=m && i<2*m)
        {
            if(j<n)
            {
                spiglo[i][j]=HorizontalnoOgledalo(mat)[i%m][j%n];
            }else if(j>=n && j<2*n)
            {
                spiglo[i][j]=mat[i%m][j%n];
            }else if(j>=2*n && j<3*n)
            {
                spiglo[i][j]=HorizontalnoOgledalo(mat)[i%m][j%n];
            }

        }else if(i>=2*m && i<3*m)
        {
            if(j<n)
            {
                spiglo[i][j]=KombinovanoOgledalo(mat)[i%m][j%n];
            }else if(j>=n && j<2*n)
            {
                spiglo[i][j]=VertikalnoOgledalo(mat)[i%m][j%n];
            }else if(j>=2*n && j<3*n)
            {
                spiglo[i][j]=KombinovanoOgledalo(mat)[i%m][j%n];
            }
        }
		}
	}
	return spiglo;
}

int main ()
{	
	try{
	int m, n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m<0 || n<0) std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	else{
	std::vector<std::vector<double>>mat(m, std::vector<double>(n));
	std::cout << "Unesite elemente matrice: ";
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			std::cin >> mat[i][j];
		}
	}
	std::vector<std::vector<double>>spiglo(3*m, std::vector<double>(3*n));
	spiglo=OgledaloMatrica(mat);
	std::cout << std::endl;
	std::cout << "Rezultantna matrica: " << std::endl;
	for(int i=0; i<spiglo.size(); i++) {
		for(int j=0; j<3*n; j++) {
			std::cout << std::right << std::setw(4) << spiglo[i][j];
		}
		std::cout << std::endl;
	}
	}
	}catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what();
    }
	
	return 0;
}