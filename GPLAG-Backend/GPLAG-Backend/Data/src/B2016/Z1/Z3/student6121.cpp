#include<iostream>
#include<vector>
#include<iomanip>

typedef std::vector<std::vector<double> > Matrica;
Matrica KreirajMatricu (int m, int n) {
	
	
	return Matrica (m, std::vector<double> (n));
	
}

Matrica RastuciPodnizovi(std::vector<double> a) {
std::vector<double>b;
Matrica m;
	
		for (int i=0; i<a.size()-1;) {
		
			if (a[i]<=a[i+1]) {
							
							b.push_back(a[i]);
							
						
						
				while (i<a.size()-1 && a[i] <= a[i+1]) {
						b.push_back(a[i+1]);
						i++;

							}

				m.push_back(b);
			b.resize(0);
				

			}
			else i++;
			}
					

return m;
}
	
	Matrica OpadajuciPodnizovi(std::vector<double> a) {
		std::vector<double>b;
Matrica m;
	
		for (int i=0; i<a.size()-1;) {
		
			if (a[i]>=a[i+1]) {
							
							b.push_back(a[i]);
							
						
						
				while (i<a.size()-1 && a[i] >= a[i+1]) {
						b.push_back(a[i+1]);
						i++;

							}

				m.push_back(b);
				b.resize(0);

			}
			 i++;
			}
					

return m;
}

	
	
int main ()
{

std::cout<<"Unesite broj elemenata vektora: ";
int n;
std::cin>>n;

std::cout<<"Unesite elemente vektora: ";
std::vector<double> vektor;
for (int i = 0; i < n; i++) {
	
	double broj;
	std::cin>>broj;
	vektor.push_back(broj);
}

std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;

Matrica m=RastuciPodnizovi(vektor);
for (int i = 0; i < m.size(); i++) {

for (int j = 0; j < m[0].size(); j++)  {
	
	std::cout<<m[i][j]<<" ";
	}
	std::cout<<std::endl;
}

std::cout<<"\nMaksimalni opadajuci podnizovi: "<<std::endl;

Matrica t=OpadajuciPodnizovi(vektor);
for (int i = 0; i < t.size(); i++) {

for (int j = 0; j < t[0].size(); j++)  {
	
	std::cout<<t[i][j]<<" ";
	}
	std::cout<<std::endl;
}
return 0;

}