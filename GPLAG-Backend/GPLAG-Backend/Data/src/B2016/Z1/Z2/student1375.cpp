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

void IspisiMatricu(Matrica m) {
   for(int i=0;i<m.size();i++) {
      for(int j=0;j<m[0].size();j++)
      std::cout << std::setw(4) << m[i][j];
   std::cout << std::endl;   
   }
}

Matrica Kreiraj(int red, int kolona) {
	return Matrica(red, std::vector<double> (kolona));
}

Matrica Unesi(int red, int kolona) {
	Matrica a(Kreiraj(red,kolona));
	for(int i=0;i<red;i++) {
		for(int j=0;j<kolona;j++) {
			std::cin >> a[i][j];
		}
	}
	return a;
}



Matrica Horizontalno(Matrica a) {
	double pomocna;
	for(int i=0;i<a.size();i++) {
		int j=0;
		for(int k=a[0].size()-1;k>=j;k--) {
			pomocna=a[i][j];
			a[i][j]=a[i][k];
			a[i][k]=pomocna;
			j++;
		}
	}
	return a;
}
Matrica Vertikalno(Matrica a) {
	std::vector<double> pomocna;
	int i(0),j(a.size()-1);
	while(j>i) {
		pomocna=a[i];
		a[i]=a[j];
		a[j]=pomocna; 
		j--;
		i++;
	}
	return a;
}

Matrica Kombinovano(Matrica a) {
	Matrica b;
	b=(Horizontalno(Vertikalno(a)));
	return b;
}

Matrica OgledaloMatrica(Matrica a) {
	if(a.empty()) return a;
	for(int i=0;i<a.size()-1;i++) {
			if(a[i].size()!=a[i+1].size()) throw std::domain_error("Matrica nije korektna");
	}
	Matrica hv=Kombinovano(a),h=Horizontalno(a),v=Vertikalno(a);
	int m(a.size()),n(a[0].size());
	Matrica vrati(Kreiraj(3*m,3*n));
	for(int j=0;j<n;j++) {
		for(int i=0;i<m;i++) {
			vrati[i][j]=hv[i][j];
			vrati[(i+m)][j]=h[i][j];
			vrati[i+2*m][j]=hv[i][j];
		}
	}
	for(int j=0;j<n;j++) {
		for(int i=0;i<m;i++) {
			vrati[i][j+n]=v[i][j];
			vrati[i+m][j+n]=a[i][j];
			vrati[i+2*m][j+n]=v[i][j];
		}
	}
	for(int j=0;j<n;j++) {
		for(int i=0;i<m;i++) {
			vrati[i][j+2*n]=hv[i][j];
			vrati[i+m][j+2*n]=h[i][j];
			vrati[i+2*m][j+2*n]=hv[i][j];
		}
	}
	return vrati;
}



int main ()
{
	int m,n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m<0 || n<0) {
		std::cout << "Dimenzije matrice moraju biti nenegativne!";
		return 1;
	}
	std::cout << "Unesite elemente matrice: " << std::endl;
	Matrica a(Unesi(m,n));
	try {
		Matrica b=OgledaloMatrica(a);
		std::cout << "Rezultantna matrica: " << std::endl;
		IspisiMatricu(b);
	}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	return 0;
}