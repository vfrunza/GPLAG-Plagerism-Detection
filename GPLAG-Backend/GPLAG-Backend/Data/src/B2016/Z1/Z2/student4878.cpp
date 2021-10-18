#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using namespace std;

vector<vector<double>> HorizontalnoOgledalo(vector<vector<double>> A)
{
	for(int i = 0 ; i < A.size() ; i++) {
		for(int j = 0 ; j < A[0].size(); j++) {
			if(j<A[0].size()/2) {
				double temp=0;
				temp=A[i][j];
				A[i][j]=A[i][A[0].size()-1-j];
				A[i][A[0].size()-1-j]=temp;
			}
		}
	}
	return A;
}
vector<vector<double>> VertikalnoOgledalo(vector<vector<double>> A)
{
	for(int i = 0 ; i < A.size() ; i++) {
		for(int j = 0 ; j < A[0].size(); j++) {
			if(i<A.size()/2) {
				double temp=0;
				temp=A[i][j];
				A[i][j]=A[A.size()-1-i][j];
				A[A.size()-1-i][j]=temp;
			}
		}
	}
	return A;
}
vector<vector<double>> OgledaloMatrica(vector<vector<double>> A)
{
	for(int i = 0 ; i < A.size() ; i++)
		if(A[0].size() != A[i].size())
			throw domain_error("Grbava matrica!");
	if(A.size()==0 || A[0].size()==0) return vector<vector<double>>(A.size(), vector<double> (A[0].size()));
	else {
		vector<vector<double>> Mat(3*A.size(), vector<double>(3*A[0].size()));
		int a=Mat.size();
		int b=Mat[0].size();
		vector<vector<double>> Hor=HorizontalnoOgledalo(A);
		vector<vector<double>> Ver=VertikalnoOgledalo(A);
		vector<vector<double>> Miks=HorizontalnoOgledalo(A);
		Miks=VertikalnoOgledalo(Miks);
		for(int i = 0 ; i < a ; i++) {
			for(int j = 0 ; j < b ; j++) {
				if((i >= A.size() && i <= (2*A.size()-1)) && ((j >= 0 && j <= (A[0].size()-1)) || (j >= 2*A[0].size() && j <= b))) {
					Mat[i][j]=Hor[i%A.size()][j%A[0].size()];
				}
				if((j >= A[0].size() && j <= (2*A[0].size()-1)) && ((i >= 0 && i <= (A.size()-1)) || (i >= 2*A.size() && i <= a))) {
					Mat[i][j]=Ver[i%A.size()][j%A[0].size()];
				}
				if((i >= A.size() && i <= (2*A.size()-1)) && (j >= A[0].size() && j <= (2*A[0].size()-1))) {
					Mat[i][j]=A[i%A.size()][j%A[0].size()];
				}
				if((i >= 0 && i < A.size() && j >= 0 && j < A[0].size()) || (i >= 0 && i < A.size() && j >= 2*A[0].size() && j < b) || (i >= 2*A.size() && i <= a && j >= 0 && j <A[0].size()) || (i >= 2*A.size() && i <= a && j >= 2*A[0].size() && j < b)) {
					Mat[i][j]=Miks[i%A.size()][j%A[0].size()];
				}
			}
		}
		return Mat;
	}
}
int main()
{
	cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	cin>>m>>n;
	if(m<0 || n<0) cout<<"Dimenzije matrice moraju biti nenegativne!";
	else {
		vector<vector<double>> mat(m, vector<double> (n));
		cout<<"Unesite elemente matrice: "<<endl;
		for(int i = 0 ; i < m ; i++)
			for(int j = 0 ; j < n ; j++)
				cin>>mat[i][j];
		cout<<"Rezultantna matrica:"<<endl;
		if(m==0 && n==0) {
			cout<<endl;
		} else {
			try {
				vector<vector<double>> Ogl=OgledaloMatrica(mat);
				for(int i = 0 ; i < Ogl.size() ; i++) {
					for(int j = 0 ; j < Ogl[0].size() ; j++) {
						cout<<setw(4)<<Ogl[i][j];
					}
					cout<<endl;
				}
			}
			catch(domain_error izuzetak) {
 cout << izuzetak.what() << endl;
		}
	}
	}
	return 0;
}