#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

using namespace std;

vector<vector<double> > hor(vector<vector<double> > v) {
	vector<vector<double> > mat;
	mat.resize(v.size());
	for(int i=0;i<mat.size();i++)
		mat[i].resize(v[i].size());
	for(int i=0;i<mat.size();i++) 
		for(int j=0;j<mat[i].size();j++) 
			mat[i][j]=v[i][v[0].size()-1-j];
	return mat;	
}

vector<vector<double> > vert(vector<vector<double>> v) {
	vector<vector<double>> mat;
	mat.resize(v.size());
	for(int i=0;i<mat.size();i++)
		mat[i].resize(v[i].size());
	for(int i=0;i<mat.size();i++) 
		for(int j=0;j<mat[i].size();j++) 
			mat[i][j]=v[v.size()-1-i][j];
	return mat;	
}

vector<vector<double>> combo(vector<vector<double>> v) {
	vector<vector<double>> mat;
	mat.resize(v.size());
	for(int i=0;i<mat.size();i++)
		mat[i].resize(v[i].size());
	mat=hor(v);
	mat=vert(mat);
	return mat;
}

vector<vector<double>> OgledaloMatrica(vector<vector<double>> v) {
	vector<vector<double>> ver=vert(v), h=hor(v), hv=combo(v);
	for(int i=1;i<v.size();i++)
		if(v[0].size()!=v[i].size()) throw domain_error("Matrica nije korektna");
	vector<vector<double>> mat;
	mat.resize(v.size()*3);
	for(int i=0;i<mat.size();i++)
		mat[i].resize(v[0].size()*3);
	for(int i=0;i<mat.size();i++) {
		for(int j=0;j<v[0].size();j++) {
			if(i<v.size()) {
				mat[i][j]=hv[i][j];
				mat[i][j+v[0].size()]=ver[i][j];
				mat[i][j+2*v[0].size()]=hv[i][j];
			}
			else if(i<2*v.size()) {
				mat[i][j]=h[i-v.size()][j];
				mat[i][j+v[0].size()]=v[i-v.size()][j];
				mat[i][j+2*v[0].size()]=h[i-v.size()][j];
			}
			else {
				mat[i][j]=hv[i-2*v.size()][j];
				mat[i][j+v[0].size()]=ver[i-2*v.size()][j];
				mat[i][j+2*v[0].size()]=hv[i-2*v.size()][j];
			}
		}
	}
	return mat;
}

int main ()
{
	try {
		cout<<"Unesite dimenzije matrice (m n): ";
		int m,n;
		cin>>m>>n;
		if(m<0 || n<0) {
			cout<<"Dimenzije matrice moraju biti nenegativne!";
			return 0;
		}
		vector<vector<double>> mat;
		mat.resize(m);
		cout<<"Unesite elemente matrice: "<<endl;
		for(int i=0;i<mat.size();++i)
			mat[i].resize(n);
		for(int i=0;i<mat.size();i++)
			for(int j=0;j<mat[i].size();j++)
				cin>>mat[i][j];
		mat=OgledaloMatrica(mat);
		cout<<"Rezultantna matrica: ";
		cout<<endl;
		for(int i=0;i<mat.size();i++) {
			for(int j=0;j<mat[i].size();j++) 
				cout<<setw(4)<<right<<mat[i][j];
			cout<<endl;
			}
		}
	catch(domain_error e) {
		cout<<e.what();
	}
	return 0;
}