/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

typedef std::vector<std::vector<double>> Matrica ;

std::vector<double> UnosVektora(int n) {
	double x;
	std::vector<double> v;
	std::cout << "Unesite elemente vektora: ";
	for(int i=0; i<n; i++) {
		std::cin>>x;
		v.push_back(x);
	}
	return v;
}

//Poredjenje 
bool JesuLiJednaki(double x, double y, double Eps = 1e-10) {
	return std::fabs(x-y) <= Eps * (std::fabs(x) + std::fabs(y));
}

Matrica RastuciPodnizovi(std::vector<double> v) {
Matrica m;
int p, k;
std::vector<double> v1;
int t (0);

for(int i=1; i<v.size(); i++) {
	if((v[i] >=v[i-1] ) || JesuLiJednaki(v[i] ,v[i-1], 1e-10)) {
		
		p = i-1;
		while((v[i] >= v[i-1]) || JesuLiJednaki(v[i] ,v[i-1], 1e-10)) {
		i++;
		if (i==v.size()) break;
		} 
			
		k = i;
		m.resize(t+1);
		for(int j=p; j<k; j++) {
			m[t].push_back(v[j]);
		}
		t++;
	}
	}
	return m;
}

Matrica OpadajuciPodnizovi(std::vector<double> v) {
Matrica m;
int p, k;
std::vector<double> v1;
int t (0);

for(int i=1; i<v.size(); i++) {
	
	if((v[i] <= v[i-1] ) || JesuLiJednaki(v[i] ,v[i-1], 1e-10)) {
		
		p=i-1;
		while((v[i] <= v[i-1] ) || JesuLiJednaki(v[i] ,v[i-1], 1e-10)) {
		i++;
		if (i==v.size()) break;
		}
		k = i;
		m.resize(t+1);
		for(int j=p; j<k; j++) {
			m[t].push_back(v[j]);
		}
		t++;
	}
	
	}
	return m;
}

// Duzina pojedinih elemenata
int Duzina ( int n ) {
   int br(0);
   if ( n< 0) br++;
   while(n!=0) {
      br++;
      n/=10;
      
   }
   return br;
}

// Ispis matrice
void IspisiMatricu( Matrica m) {
   for( int i=0; i<m.size(); i++) {
      for(int j=0; j<m[i].size(); j++) {
        // std::cout<< std::setw(Duzina(m[i][j])+1) << std::left << m[i][j];
         std::cout<< std::setprecision(12) << m[i][j] << " " ;
      }
      std::cout << std::endl;
   }
}

int main ()
{
	int n;

	std::cout<< ("Unesite broj elemenata vektora: ");
	std::cin >> n;
  	std::vector<double> v = (UnosVektora(n));
	std::cout <<"Maksimalni rastuci podnizovi: "  << std::endl;

	Matrica m1 = RastuciPodnizovi(v);
	
	IspisiMatricu(m1);

	std::cout <<"Maksimalni opadajuci podnizovi: " << std::endl ;
	Matrica m2 = OpadajuciPodnizovi(v);
	
	IspisiMatricu(m2);
	
	return 0;
}