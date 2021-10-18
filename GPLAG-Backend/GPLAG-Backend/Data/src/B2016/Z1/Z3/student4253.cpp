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

typedef std::vector<std::vector<double>> Matrica;

bool JesuLiJednaki (double x, double y, double Eps=1e-10){
	if((x<0 && y>0) || (x>0 && y<0)) return false;
	return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
}

void IspisiMatricu (Matrica mat){
	for(auto red: mat){
		for(auto x: red) std::cout<<x<<" ";
		std::cout<<std::endl;
	}
}

Matrica RastuciPodnizovi(std::vector<double> v){
	Matrica mat;

	if(int(v.size())==0 || int(v.size())==1) return mat;

	int j(0);

	for(int i(0); i<int(v.size()); i++){
		
		if(i==0){
			if(v.at(i)<=v.at(i+1) || JesuLiJednaki(v.at(i), v.at(i+1)) )	{
				mat.push_back(std::vector<double> {v.at(i)});
				j++;
			}
		}
	
		else {
			if(i!=int(v.size())-1 && (v.at(i)<=v.at(i+1)  || JesuLiJednaki(v.at(i), v.at(i+1))) && (v.at(i)<v.at(i-1) && !JesuLiJednaki(v.at(i), v.at(i-1))) ){
				mat.push_back(std::vector<double> {v.at(i)});
				j++;
			}
			else if(v.at(i-1)<=v.at(i) || JesuLiJednaki(v.at(i-1), v.at(i))){
				mat.at(j-1).push_back(v.at(i));
			}
		}
	}
	return mat;
	
}

Matrica OpadajuciPodnizovi(std::vector<double> v){

	Matrica mat;

	if(int(v.size())==0 || int(v.size())==1) return mat;

	int j(0);

	for(int i(0); i<int(v.size()); i++){
		
		if(i==0){
			if(v.at(i+1)<=v.at(i) || JesuLiJednaki(v.at(i+1), v.at(i)) ){
				mat.push_back(std::vector<double> {v.at(i)});
				j++;
			}
		}
		
		else {
			if(i!=int(v.size())-1 && (v.at(i)>v.at(i-1) && !JesuLiJednaki(v.at(i), v.at(i-1))) && ( v.at(i+1)<=v.at(i) || JesuLiJednaki(v.at(i+1),v.at(i)) ) ){
				mat.push_back(std::vector<double> {v.at(i)});
				j++;
			}
			
			else if(v.at(i)<=v.at(i-1) || JesuLiJednaki(v.at(i), v.at(i-1)) ) {
				mat.at(j-1).push_back(v.at(i));
			}
		}
		
	}
	
	return mat;
}

int main ()
{
	
	int n;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	
	
	std::vector<double> v;
	std::cout<<"Unesite elemente vektora: ";
	
	for(int i(0); i<n; i++) {
		double p;
		std::cin>>p;
		v.push_back(p);
	}
	
	Matrica mat;
	
	mat=RastuciPodnizovi(v);
	
		std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
		IspisiMatricu(mat);
	
	
	mat.resize(0);
	mat=OpadajuciPodnizovi(v);
	
		std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
		IspisiMatricu(mat);
	
	return 0;
}