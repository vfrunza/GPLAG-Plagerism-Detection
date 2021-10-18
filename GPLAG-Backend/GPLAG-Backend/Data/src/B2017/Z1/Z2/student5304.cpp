#include <iostream>
#include <math.h>
#include <vector>
#include <stdexcept>
#include <iomanip>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int format(std::vector<std::vector<double>> V, int ind1, int ind2){
	double suma=V.at(ind1).at(ind2), s(0);
	for(int k = 0; k < 100; k++){
		s = 0;
		if(k==0)s=V.at(ind1).at(ind2);
		if(ind1 - k < 0 || ind2 - k < 0 || ind1 + k >= V.size() || ind2 + k >= V.at(0).size()){
			return k-1;
		}
		for(int i = ind1 - k; i <= ind1 + k; i++){
			for(int j = ind2 - k; j <= ind2 + k; j++){
				if(i == ind1 && j == ind2 )continue;
				if(i==ind1 - k ||i==ind1 + k ||j==ind2 - k||j==ind2 + k)	s+=V.at(i).at(j);
			}
		}
	if(s < suma) suma=s;
	else if(s>suma){
		return k-1;
	}
	}
}

std::vector<std::vector<double>> NajvecaPlaninaMatrice(std::vector<std::vector<double>> V){
	for(int i = 0; i < V.size(); i++){
		if(V.at(0).size() != V.at(i).size()) throw std::domain_error("Matrica nije korektna");
	}
	if(V.size() == 0 || V.at(0).size() == 0) throw std::domain_error("Matrica nije korektna");
	if(V.size()<=2 ||V.at(0).size()<=0){
		int max = V.at(0).at(0);
		for(int i = 0; i < V.size(); i++){
			for(int j = 0; j < V.at(0).size(); j++){
				if(V.at(i).at(j) > max) max = V.at(i).at(j);
			}
		}
		vector<vector<double>> rezultat;
		rezultat.push_back(std::vector<double> (0));
		rezultat.at(0).push_back(max);
		return rezultat;
	}
	int k(0), koord1(0), koord2(0);
	for(int i = 1; i < V.size()-1; i++){
		for(int j = 1; j < V.at(i).size()-1; j++){
			int k1 = format(V, i, j); 
			
			if(k < k1){
				k = k1;
				koord1 = i;
				koord2 = j;
			}
		}
	}
	int ind1(0), ind2(0);
	vector<std::vector<double>> rezultat(k*2+1, std::vector<double> (k*2+1));
	for(int i = koord1 - k; i <= koord1 + k; i++){
		ind2=0;
		for(int j = koord2 - k; j <= koord1 + k; j++){
			rezultat.at(ind1).at(ind2) = V.at(i).at(j);
			ind2++;
		}	
	ind1++;
	}
	return rezultat;
}

int main (){
	try{
	cout<<"Unesite dimenzije matrice (m i n): ";
	int m, n;
	cin>>m>>n;
	if(m < 0 || n < 0){
		throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
	}
	cout<<"Unesite elemente matrice: ";
	vector<vector<double>> V(m, std::vector<double> (n));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			double element;
			cin>>element;
			V.at(i).at(j)=element;
		}
	}
	cout<<endl<<"Najveca planina unesene matrice je: "<<endl;
	std::vector<std::vector<double>> P = NajvecaPlaninaMatrice(V);
	for(std::vector<double> red : P){
		for(double x : red){
			cout<<std::setw(6)<<x;
		}
		cout<<endl;
	}
	}catch(std::domain_error e){
		cout<<e.what()<<endl;
	}
	return 0;
}