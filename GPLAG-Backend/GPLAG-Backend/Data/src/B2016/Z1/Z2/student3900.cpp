#include <iostream>
#include <stdexcept>
#include <vector>
#include <iomanip>
using namespace std;

vector<vector<double>> HorizontalnoOgledalo(vector<vector<double>>mat){
	vector<vector<double>>mat2;
	vector<double>v2;
	for(int i=0; i<mat.size(); i++){
		v2.clear();
		for(int j=mat[i].size()-1; j>=0; j--){
			v2.push_back(mat[i][j]);
		}
		mat2.push_back(v2);
	}
	return mat2;
}

vector<vector<double>> VertikalnoOgledalo(vector<vector<double>>mat){
	vector<double>v1;
	vector<vector<double>>mat1;
	for(int i=mat.size()-1; i>=0; i--){
		for(int j=0; j<mat[i].size(); j++){
			v1.push_back(mat[i][j]);
		}
		mat1.push_back(v1);
		v1.clear();
	}
	return mat1;
}

vector<vector<double>> HVOgledalo(vector<vector<double>>mat){
	vector<double>v;
	vector<vector<double>>mat3;
	for(int i=mat.size()-1; i>=0; i--){
		for(int j=mat[i].size()-1; j>=0; j--){
			v.push_back(mat[i][j]);
		}
		mat3.push_back(v);
		v.clear();
	}
	return mat3;
}

vector<vector<double>> OgledaloMatrica(vector<vector<double>>mat){
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat[i].size(); j++){
		if(mat[0].size()!=mat[i].size()) throw domain_error("Matrica nije korektna");
		}
	}
	vector<vector<double>>pom;
	vector<vector<double>>ho1=HorizontalnoOgledalo(mat);
	vector<vector<double>>vo1=VertikalnoOgledalo(mat);
	vector<vector<double>>ko1=HVOgledalo(mat);
	vector<vector<double>>mat2=mat;
	for(int i=0; i<mat.size(); i++){
		vector<double>red;
		for(int j=0; j<mat[i].size(); j++){
			red.push_back(ko1[i][j]);
		}
		for(int j=0; j<mat[i].size(); j++){
			red.push_back(vo1[i][j]);
		}
		for(int j=0; j<mat[i].size(); j++){
			red.push_back(ko1[i][j]);
		}
		pom.push_back(red);
	}
	
	for(int i=0; i<mat.size(); i++){
		vector<double>red2;
		for(int j=0; j<mat[i].size(); j++){
			red2.push_back(ho1[i][j]);
		}
		for(int j=0; j<mat[i].size(); j++){
			red2.push_back(mat2[i][j]);
		}
		for(int j=0; j<mat[i].size(); j++){
			red2.push_back(ho1[i][j]);
		}
		pom.push_back(red2);
	}
	for(int i=0; i<mat.size(); i++){
		vector<double>red3;
		for(int j=0; j<mat[i].size(); j++){
			red3.push_back(ko1[i][j]);
		}
		for(int j=0; j<mat[i].size(); j++){
			red3.push_back(vo1[i][j]);
		}
		for(int j=0; j<mat[i].size(); j++){
			red3.push_back(ko1[i][j]);
		}
		pom.push_back(red3);
	}

	return pom;
}

int main ()
{
	try{
	int n, m;
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>n>>m;
	if(n<0 || m<0){
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	vector<vector<double>>mat(n, vector<double>(m));
	cout<<"Unesite elemente matrice: ";
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat[i].size(); j++){
			cin>>mat[i][j];
		}
	}
	mat=OgledaloMatrica(mat);
	cout<<endl<<"Rezultantna matrica: "<<endl;
	for(int i=0; i<mat.size(); i++){
		for(int j=0; j<mat[i].size(); j++){
			cout<<setw(4)<<mat[i][j];
		}
		cout<<endl;
	}
	}
	catch(domain_error izuzetak){
		cout<<izuzetak.what()<<endl;
	}
	return 0;
}