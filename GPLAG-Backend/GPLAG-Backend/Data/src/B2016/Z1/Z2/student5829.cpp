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


Matrica Horizontalna_matrica (Matrica m){
	int a(m.size());
	int b(m[0].size());

	Matrica horiz_matrica (a, std::vector<double>(b));


	for (int i=0; i<horiz_matrica.size(); i++){
    int k(b-1);
		for(int j=0; j<horiz_matrica[0].size(); j++){
			horiz_matrica[i][j]=m[i][k];
            k--;
		}

	}

	return horiz_matrica;
}

Matrica Vertikalna_matrica (Matrica m){
	int a(m.size());
	int b(m[0].size());
	Matrica vertik_matrica (a, std::vector<double>(b));
int k(a-1);

	for (int i=0; i<vertik_matrica.size(); i++){

		for(int j=0; j<vertik_matrica[0].size(); j++){
			vertik_matrica[i][j]=m[k][j];

		}
		k--;

	}

	return vertik_matrica;
}

Matrica Vertikalna_Horizontalna (Matrica m){
	int a(m.size());
	int b(m[0].size());
	Matrica v_h_matrica (a, std::vector<double>(b));
	v_h_matrica=Horizontalna_matrica(Vertikalna_matrica(m));
	return v_h_matrica;


}



Matrica OgledaloMatrica (Matrica m){
	
	if (m.size()==0) return m;
	bool grbava=0;
	int vel=m[0].size();
	for(int i=1; i<m.size();i++){
		if (m[i].size()!=vel) grbava=1;
	}
	
	if (grbava==1) throw std::domain_error("Matrica nije korektna");
	
	int a(m.size());
	int b(m[0].size());

	Matrica matrica_ogledala (3*a, std::vector<double>(3*b));
	Matrica h (Horizontalna_matrica(m));
	Matrica v (Vertikalna_matrica(m));
	Matrica h_v (Vertikalna_Horizontalna(m));

	for (int i=0; i<a; i++){
		for (int j=0; j<b; j++){
			matrica_ogledala.at(i).at(j)=h_v.at(i).at(j);
		}
	}

	for (int i=0; i<a; i++){
	for (int j=2*b; j<3*b; j++){
		matrica_ogledala.at(i).at(j)=h_v.at(i).at(j-2*b);
	}
}
	for (int i=0; i<a; i++){
		for (int j=b; j<2*b; j++){
			matrica_ogledala.at(i).at(j)=v.at(i).at(j-b);
		}
	}
	
		for (int i=a; i<2*a; i++){
		for (int j=0; j<b; j++){
			matrica_ogledala.at(i).at(j)=h.at(i-a).at(j);
		}
	}
	
		for (int i=a; i<2*a; i++){
		for (int j=b; j<2*b; j++){
		matrica_ogledala.at(i).at(j)=m.at(i-a).at(j-b);
		}
	}
	
		for (int i=a; i<2*a; i++){
		for (int j=2*b; j<3*b; j++){
			matrica_ogledala.at(i).at(j)=h.at(i-a).at(j-2*b);
		}
	}
		for (int i=2*a; i<3*a; i++){
		for (int j=0; j<b; j++){
			matrica_ogledala.at(i).at(j)=h_v.at(i-2*a).at(j);
		}
	}
	
		for (int i=2*a; i<3*a; i++){
		for (int j=b; j<2*b; j++){
			matrica_ogledala.at(i).at(j)=v.at(i-2*a).at(j-b);
		}
	}
	
		for (int i=2*a; i<3*a; i++){
		for (int j=2*b; j<3*b; j++){
			matrica_ogledala.at(i).at(j)=h_v.at(i-2*a).at(j-2*b);
		}
	}
	

	return matrica_ogledala;
}

int main ()
{
try{
	int m,n;
    std::cout << "Unesite dimenzije matrice (m n): " ;
    std::cin >>m >>n;
    
    if (m<0 || n<0) throw std::range_error("Dimenzije matrice moraju biti nenegativne!");
    
    
    Matrica mat(m, std::vector <double>(n));
    std::cout << "Unesite elemente matrice: ";
    std::cin.ignore();
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            std::cin >> mat.at(i).at(j);
        }
    }
	std::cout<< std::endl<<"Rezultantna matrica: ";
	
	if (m==0 && n==0) return 0;
    int a{mat.size()};
    int b{mat[0].size()};
    std::cout<<std::endl;
	Matrica matrica_ogledala (OgledaloMatrica(mat));
		for (int i=0; i<3*a; i++){
		for (int j=0; j<3*b; j++){
			std::cout << std::right << std::setw(4)<<matrica_ogledala.at(i).at(j);
		}
		std::cout<< std::endl;
	}}

	catch (std::range_error izuzetak){
		std::cout << izuzetak.what();
	}
	
	catch (std::domain_error izuzetak){
		std::cout  << izuzetak.what();
	}
	
	return 0;
}
