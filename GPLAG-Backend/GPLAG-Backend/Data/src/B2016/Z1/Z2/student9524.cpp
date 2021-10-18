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

std::vector<std::vector<double>> HorizontalnoOgledalo(std::vector<std::vector<double>> a){
	std::vector<std::vector<double>> h(a.size());
	for(int i=0; i<a.size(); i++){
		for(int j=a[i].size()-1; j>=0; j--){
			h[i].push_back(a[i][j]);
		}
	}
	return h;
}

std::vector<std::vector<double>> VertikalnoOgledalo(std::vector<std::vector<double>> a){
	std::vector<std::vector<double>> v(a.size());
	int x(0);
	for(int i=a.size()-1; i>=0; i--){
		for(int j=0; j<a[i].size(); j++){
			v[x].push_back(a[i][j]);
		}
		x++;
	}
	return v;
}

std::vector<std::vector<double>> KombinovanoOgledalo(std::vector<std::vector<double>> a){
	std::vector<std::vector<double>> hv(HorizontalnoOgledalo(VertikalnoOgledalo(a)));
	return hv;
}

std::vector<std::vector<double>> PoveziRedove(std::vector<std::vector<double>> a, std::vector<std::vector<double>> b){
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<b[i].size(); j++){
			a[i].push_back(b[i][j]);
		}
	}
	return a;
}

std::vector<std::vector<double>> PoveziKolone(std::vector<std::vector<double>> a, std::vector<std::vector<double>> b){
	if(a.size()>b.size()){
		a.resize(3*b.size());
		for(int i=2*b.size(); i<a.size(); i++){
			for(int j=0; j<b[i-2*b.size()].size(); j++){
				a[i].push_back(b[i-2*b.size()][j]);
			}
		}
	} else {
	    a.resize(2*b.size());
	    for(int i=b.size(); i<a.size(); i++){
	 	    for(int j=0; j<b[i-b.size()].size(); j++){
			    a[i].push_back(b[i-b.size()][j]);
		    }
	    }
	}
	return a;
}

std::vector<std::vector<double>> OgledaloMatrica (std::vector<std::vector<double>> a){
	for(int i=1; i<a.size(); i++){
		if(a[i].size()!=a[i-1].size())throw std::domain_error("Matrica nije korektna");
	}
	std::vector<std::vector<double>> h(HorizontalnoOgledalo(a)), v(VertikalnoOgledalo(a)), hv(KombinovanoOgledalo(a));
	std::vector<std::vector<double>> hv_v_hv(PoveziRedove(PoveziRedove(hv, v), hv)), h_a_h(PoveziRedove(PoveziRedove(h, a), h));
	return PoveziKolone(PoveziKolone(hv_v_hv, h_a_h), hv_v_hv);
}

int main ()
{
	int m, n;
	std::vector<std::vector<double>> Matrica;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m<0 || n<0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	std::cout << "Unesite elemente matrice: ";
	Matrica.resize(m);
	for(int i=0; i<m; i++){
		Matrica[i].resize(n);
		for (int j=0; j<n; j++){
			std::cin >> Matrica[i][j];
		}
	}
	std::cout << "\nRezultantna matrica: " << std::endl;;
	try{
		std::vector<std::vector<double>> RezultantnaMatrica(OgledaloMatrica(Matrica));
	    for(int i=0; i<RezultantnaMatrica.size(); i++){
		    for(int j=0; j<RezultantnaMatrica[i].size(); j++){
			    std::cout << std::setw(4) <<RezultantnaMatrica[i][j];
		    }
		    std::cout << std::endl;
	    }
    }
    catch(std::domain_error izuzetak){
    	std::cout << izuzetak.what();
    }
	/*std::cout << "\n";
	std::vector<std::vector<double>> a(HorizontalnoOgledalo(Matrica));
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<a[i].size(); j++){
			std::cout << std::setw(4) << a[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << "\n";
	a=VertikalnoOgledalo(Matrica);
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<a[i].size(); j++){
			std::cout << std::setw(4) << a[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << "\n";
	a=KombinovanoOgledalo(Matrica);
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<a[i].size(); j++){
			std::cout << std::setw(4) << a[i][j];
		} 
		std::cout << std::endl;
	} */
	return 0;
}