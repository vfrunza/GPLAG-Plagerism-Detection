#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <iomanip>


using std::setw;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::fabs;
using std::domain_error;

vector<double> Maximalna(vector<vector<double>> himalaji){
	vector<double> max=himalaji.at(0);
	for(int i=1; i<himalaji.size(); i++){
		if(himalaji.at(i).at(0)>max.at(0))max=himalaji.at(i);
		if(himalaji.at(i).at(0)>max.at(0))max=himalaji.at(i);
			if(himalaji.at(i).at(1)>max.at(1))max=himalaji.at(i);
		
	}
	return max;
}

vector<vector<double>> NapraviMat(vector<vector<double>> matrica, vector<double> v){
	int v1=v.at(1);
	vector<vector<double>> x(v1, vector<double> (v1));
	int i=v.at(2);
	int j=v.at(3);
	int m=0, n=0;
	for(int k=i-(v1/2); k<=i+ (v1/2); k++){
		n=0;
		for(int l=j-(v1/2); l<=j+(v1/2); l++){
			x.at(m).at(n)=matrica.at(k).at(l);
			n++;
		}
		m++;
	}
	return x;
	
}


vector<vector<double>> NajvecaPlaninaMatrice(vector<vector<double>> M){
	for(int i=0; i>M.size(); i++){
		if(M.at(i).size()!=M.at(0).size()) throw domain_error("Matrica nije korektna");
	}
	
	if(M.size()<3 && M.at(0).size()<3){
		vector<vector<double>> matrica (1, vector<double> (1));
		double najveci=matrica.at(0).at(0);
		if(matrica.at(0).at(0) && matrica.size()==1) return matrica;
		for(int i=0; i<matrica.size();i++){
			for(int j=1;j<matrica.at(0).size();j++){
			if(matrica.at(i).at(j)>najveci) najveci=matrica.at(i).at(j);
			}
		}
		matrica.at(0).at(0)=najveci;
		return matrica;
	}
	
	double vrh;
	vector<vector<double>> mount, himalaji;
	for(int i=1; i<M.size()-1; i++){
		for(int j=1; j<M.at(i).size()-1; j++){
			vrh=M.at(i).at(j);
			int dim=1;
			int tmp1=i-1;
			int tmp2=j-1;
			double najveca_suma=vrh;
			
			
			while(tmp1>=0 && 2*tmp1+3<=M.size() && tmp2>=0 && 2*tmp2<=M.at(0).size()){
				dim+=2;
				double suma=0;
				for(int k=0; k<dim; k++){
					for(int l=0; l<dim; l++){
						if(k==0 || k==dim-1) suma+=M.at(tmp1+k).at(tmp2+l);
						else if (l==0 || l==dim-1)suma+=M.at(tmp1+l).at(tmp2+k);
					}
				}
				if(suma<najveca_suma){
					tmp1--;
					tmp2--;
				}
				else break;
				
			}
			
			if(dim>=3){
				vector<double>temp;
				temp.push_back(vrh);
				temp.push_back(dim);
				temp.push_back(i);
				temp.push_back(j);
				himalaji.push_back(temp);
			}
		}
	}
	
	if(himalaji.size()==0) return mount;
	vector<double> temp(Maximalna(himalaji));
	mount=NapraviMat(M, temp);
	return mount;
	
}


	
int main (){

cout << "Unesite dimenzije matrice (m i n): ";
	int m,n;
	cin >> m >> n;
	if(m<=0 || n<=0) {
		cout << "Dimenzije matrice moraju biti nenegativne!";	
		return 0;
	}
	cout << "Unesite elemente matrice: ";
	vector<vector<double>> matrica(m, vector<double> (n));
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			double a;
			cin >> a;
			matrica.at(i).at(j)=a;	
		}
	}
	try {
		matrica=NajvecaPlaninaMatrice(matrica);
		cout << endl << "Najveca planina unesene matrice je: " << endl;
		for(int i=0;i<matrica.size();i++) {
			for(int j=0;j<matrica.at(i).size();j++) cout << setw(6) << matrica.at(i).at(j);
				cout << endl;
			}
		}
	catch(domain_error izuzetak) {
		cout << "Izuzetak: " << izuzetak.what();
	} 
	
	return 0;
}