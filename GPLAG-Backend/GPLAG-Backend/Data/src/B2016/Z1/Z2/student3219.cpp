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

using namespace std;

vector<vector<double> > h(vector<vector<double> > mat) {
	double temp;
	for(int i(0);i<mat.size();i++){
		for(int j(0);j<mat[0].size()/2;j++){
			temp=mat[i][j];
			mat[i][j]=mat[i][mat[i].size()-1-j];
			mat[i][mat[i].size()-1-j]=temp;
		}
	}
	return mat;
}
vector<vector<double> > v(vector<vector<double> > mat) {
	vector<double> temp;
	for(int i(0);i<mat.size()/2;i++) {
		temp=mat[i];
		mat[i]=mat[mat.size()-1-i];
		mat[mat.size()-1-i]=temp;
	}
	return mat;
}
vector<vector<double> > hv(vector<vector<double> > mat) {
	mat=h(mat);
	mat=v(mat);
	
	return mat;
}

vector<vector<double> > OgledaloMatrica(vector<vector<double> > M) {
	vector<vector<double> > MAT;
	for(int i(0);i<M.size();i++) {
		if(M[i].size() != M[0].size()) throw domain_error("Matrica nije korektna");
	}
	MAT.resize(3*M.size());
	for(int i(0);i<3*M.size();i++) {
		MAT[i].resize(3*M[0].size());
	}
	vector<vector<double> > mat;
	for(int i(0);i<3*M.size();i+=M.size()) {
		for(int j(0);j<3*M[0].size();j+=M[0].size()) {
			if(i==0 && j==0) {
				mat=hv(M);
				for(int k(0);k<mat.size();k++) {
					for(int l(0);l<mat[0].size();l++) {
						MAT[k+i][l+j]=mat[k][l];
					}
				}
			}
			if(i==0 && j==M[0].size()) {
				mat=v(M);
				for(int k(0);k<mat.size();k++) {
					for(int l(0);l<mat[0].size();l++) {
						MAT[k+i][l+j]=mat[k][l];
					}
				}
			}
			if(i==0 && j==2*M[0].size()) {
				mat=hv(M);
				for(int k(0);k<mat.size();k++) {
					for(int l(0);l<mat[0].size();l++) {
						MAT[k+i][l+j]=mat[k][l];
					}
				}
			}
			if(i==M.size() && j==0) {
				mat=h(M);
				for(int k(0);k<mat.size();k++) {
					for(int l(0);l<mat[0].size();l++) {
						MAT[k+i][l+j]=mat[k][l];
					}
				}
			}
			if(i==M.size() && j==M[0].size()) {
				mat=M;
				for(int k(0);k<mat.size();k++) {
					for(int l(0);l<mat[0].size();l++) {
						MAT[k+i][l+j]=mat[k][l];
					}
				}
			}
			if(i==M.size() && j==2*M[0].size()) {
				mat=h(M);
				for(int k(0);k<mat.size();k++) {
					for(int l(0);l<mat[0].size();l++) {
						MAT[k+i][l+j]=mat[k][l];
					}
				}
			}
			if(i==2*M.size() && j==0) {
				mat=hv(M);
				for(int k(0);k<mat.size();k++) {
					for(int l(0);l<mat[0].size();l++) {
						MAT[k+i][l+j]=mat[k][l];
					}
				}
			}
			if(i==2*M.size() && j==M[0].size()) {
				mat=v(M);
				for(int k(0);k<mat.size();k++) {
					for(int l(0);l<mat[0].size();l++) {
						MAT[k+i][l+j]=mat[k][l];
					}
				}
			}
			if(i==2*M.size() && j==2*M[0].size()) {
				mat=hv(M);
				for(int k(0);k<mat.size();k++) {
					for(int l(0);l<mat[0].size();l++) {
						MAT[k+i][l+j]=mat[k][l];
					}
				}
			}
		}
	}
	return MAT;
}

int main ()
{
	cout<< "Unesite dimenzije matrice (m n): ";
	int m,n;
	
	vector<vector<double> > mat;
	cin>>m>>n;
	if(m<0 || n<0) { cout<< "Dimenzije matrice moraju biti nenegativne!"; return 0; }
	mat.resize(m);
	for(int i(0);i<m;i++) mat[i].resize(n);
	cout<< "Unesite elemente matrice: \n";
	for(int i(0);i<m;i++) {
		for(int j(0);j<n;j++) {
			cin>>mat[i][j];
		}
	}
	try {
		mat=OgledaloMatrica(mat);
		cout<<"Rezultantna matrica: \n";
		for(int i(0);i<mat.size();i++) {
			for(int j(0);j<mat[i].size();j++) {
				cout<<setfill(' ')<<setw(4);
				cout<<mat[i][j];
			}
			cout<<endl;
		}
	}catch(domain_error izuzetak) { cout<< izuzetak.what() << endl; }
	return 0;
}