/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>
#define EPS 0.0000001

int k(0), granica(0);
int k1(0), granica1(0);


std::vector<std::vector<double>> Pom(std::vector<std::vector<double>> m, std::vector<double> v){
   int i=granica;
	for(; i<v.size() ; i++){
		if(i<v.size()-1){
			if(v[i]<v[i+1] || (fabs(v[i]-v[i+1])<=EPS*(fabs(v[i])+fabs(v[i+1])) )){
				m[k].push_back(v[i+1]);

			}
			else break;
		}
	}
		granica = i;
		k++;
	return m;
}

std::vector<std::vector<double>> RastuciPodnizovi (std::vector<double> v){
	std::vector<std::vector<double>> mat;

	for(int i(0); i<v.size() ; i++){
		if(i<v.size()-1){
			if(v[i]<v[i+1] || (fabs(v[i]-v[i+1])<=EPS*(fabs(v[i])+fabs(v[i+1])) )) {
				mat.resize(k+1);
				mat[k].push_back(v[i]);
				granica = i;
			}
			else continue;
	}
	if(i < v.size() - 1){mat = Pom(mat, v);
    i = granica - 1;}
}
		return mat;
}

std::vector<std::vector<double>> Pom1(std::vector<std::vector<double>> m, std::vector<double> v){
   int i=granica1;
	for(; i<v.size() ; i++){
		if(i<v.size()-1){
			if(v[i]>v[i+1] || (fabs(v[i]-v[i+1])<=EPS*(fabs(v[i])+fabs(v[i+1])) )){
				m[k1].push_back(v[i+1]);

			}
			else break;
		}
	}
		granica1 = i;
		k1++;
	return m;
}
std::vector<std::vector<double>> OpadajuciPodnizovi (std::vector<double> v){
	std::vector<std::vector<double>> mat;

	for(int i(0) ; i<v.size() ; i++){
		if(i<v.size()-1){
			if(v[i]>v[i+1] || (fabs(v[i]-v[i+1])<=EPS*(fabs(v[i])+fabs(v[i+1])) )) {
				mat.resize(k1+1);
				mat[k1].push_back(v[i]);
				granica1 = i;
			}
			else continue;
	}
	if(i < v.size() - 1) {mat = Pom1(mat, v); i = granica1 - 1;}

}
		return mat;
}

void IspisiMatricu (std::vector<std::vector<double>> m){
   for(int i=0 ; i<m.size() ; i++){
      for(int j=0 ; j<m[i].size() ; j++){
         std::cout<<m[i][j]<<" ";
      }
         std::cout<<std::endl;
   }

}

int main ()
{
	int n;
	std::vector<double> v;
	std::vector<std::vector<double>> mat1, mat2;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0 ; i<n ; i++){
		double x;
		std::cin>>x;
		v.push_back(x);
	}
	mat1 = RastuciPodnizovi(v);
	mat2 = OpadajuciPodnizovi(v);

	std::cout<<"Maksimalni rastuci podnizovi: \n";
	IspisiMatricu(mat1);

	std::cout<<"Maksimalni opadajuci podnizovi: \n";
	IspisiMatricu(mat2);


	return 0;
}
