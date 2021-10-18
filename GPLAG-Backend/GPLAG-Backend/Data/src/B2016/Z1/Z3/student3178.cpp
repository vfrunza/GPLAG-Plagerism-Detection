/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
/*
#include <iostream>
#include <vector>
#include <iomanip>


typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int m, int n){
	return Matrica(m, std::vector<double>(n));
}




Matrica RastuciPodnizovi(std::vector<double> v){
	Matrica A;

for(int i=0; i<v.size()-1; i++){
	
	if(v[i] < v[i+1]){
		A.push_back({});
		A[A.size() - 1].push_back(v[i]);
	     while( i<v.size()-1 && v[i]<v[i+1]){
                A[A.size()-1].push_back(v[i+1]);
                i++;
            }
        }
    }
	return A;
}


Matrica OpadajuciPodnizovi(std::vector<double> v){
	Matrica A;

for(int i=0; i<v.size()-1; i++){
	
	if(v[i] > v[i+1]){
		A.push_back({});
		A[A.size() - 1].push_back(v[i]);
		
	    while(i<v.size()-1 && v[i]>v[i+1] ){
                A[A.size()-1].push_back(v[i+1]);
                i++;
            }
        }
    }
	return A;
}




void IspisiKrezavuMatricu(Matrica A){
	for(int i=0; i<A.size(); i++){
		for(int j=0; j<A[i].size(); j++){
			int pomocna = A[i][j];
			int brojac{0};
			while(pomocna !=0){
				pomocna=pomocna/10;
				brojac++;
			}
			if(brojac==2){
			std::cout << std::left << std::setw(2) << A[i][j]  <<" ";}
			else std::cout << std::left << std::setw(2) << A[i][j] ;}
		std::cout << std::endl;
	}
}	
	
	
int main ()
{
	
	std::vector<double> v;
	int i{0};
	int k{0};
	double element;
	
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> k;
	
	std::cout << "Unesite elemente vektora: ";
	do{
		std::cin >> element;
		v.push_back(element);
		i++;
	} while(i != k);
	
	std::cout <<"Maksimalni rastuci podnizovi:\n";
	IspisiKrezavuMatricu(RastuciPodnizovi(v));

	std::cout <<"Maksimalni opadajuci podnizovi: \n";
	IspisiKrezavuMatricu(OpadajuciPodnizovi(v));
	return 0;
}


*/
#include <iostream>
#include <vector>
#include <iomanip>


typedef std::vector<std::vector<double>> Matrica;

Matrica KreirajMatricu(int m, int n){
	return Matrica(m, std::vector<double>(n));
}




Matrica RastuciPodnizovi(std::vector<double> v){
	Matrica A;

for(int i=0; i<v.size()-1; i++){
	
	if(v.at(i) <= v.at(i+1)){ //
		A.push_back({});
		A[A.size() - 1].push_back(v.at(i));
	     while( i<v.size()-1 && v.at(i)<=v.at(i+1)){ //
                A[A.size()-1].push_back(v.at(i+1));
                i++;
            }
        }
    }
	return A;
}


Matrica OpadajuciPodnizovi(std::vector<double> v){
	Matrica A;

for(int i=0; i<v.size()-1; i++){
	
	if(v.at(i) >= v.at(i+1)){  //
		A.push_back({});
		A[A.size() - 1].push_back(v.at(i));
		
	    while(i<v.size()-1 && v.at(i)>=v.at(i+1) ){  //
                A[A.size()-1].push_back(v.at(i+1));
                i++;
            }
        }
    }
	return A;
}




void IspisiKrezavuMatricu(Matrica A){
	for(int i=0; i<A.size(); i++){
		for(int j=0; j<A.at(i).size(); j++){
			int pomocna = A.at(i).at(j);
			int brojac{0};
			while(pomocna !=0){
				pomocna=pomocna/10;
				brojac++;
			}
			if(brojac==2){
			std::cout << std::left << std::setw(2) << A[i][j]  <<" ";}
			else std::cout << std::left << std::setw(2) << A[i][j] ;}
		std::cout << std::endl;
	}
}	
	
	
int main ()
{
	
	std::vector<double> v;
	int i{0};
	int k{0};
	double element;
	
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> k;
	
	std::cout << "Unesite elemente vektora: ";
	do{
		std::cin >> element;
		v.push_back(element);
		i++;
	} while(i != k);
	
	std::cout <<"Maksimalni rastuci podnizovi:\n";
	IspisiKrezavuMatricu(RastuciPodnizovi(v));

	std::cout <<"Maksimalni opadajuci podnizovi: \n";
	IspisiKrezavuMatricu(OpadajuciPodnizovi(v));
	return 0;
}