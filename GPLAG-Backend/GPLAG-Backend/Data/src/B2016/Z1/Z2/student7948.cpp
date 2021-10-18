#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <stdexcept>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
typedef vector<vector<double>> matrica;

matrica OgledaloMatrica(matrica mat) {
	if(mat.size()==0) {
		return {};
	}
	for(int i=0; i<mat.size()-1; i++) {
		if(mat[i].size()!=mat[i+1].size()) throw std::domain_error("Matrica nije korektna");
	}	
	int x(mat.size()), y(mat[0].size());
	matrica ogld(3*x, vector<double>(3*y));

	// horizontalna transformacija
	matrica ht(x, vector<double>(y));
	int m(x-1), n(y-1);
	for(int i=0; i<x; i++) {
		for(int j=0; j<y; j++) {
			ht[i][j]=mat[m][j];
		}
		m--;
	}

	// vertikalna transformacija
	matrica vt(x, vector<double>(y));
	m=(x-1);
	for(int i=0; i<x; i++) {
		n=(y-1);
		for(int j=0; j<y; j++) {
			vt[i][j]=mat[i][n];
			n--;
		}
	}

	// (horizontalna + vertikalna) transofrmacija
	matrica hvt(x, vector<double>(y));
	m=(x-1);
	for(int i=0; i<x; i++) {
		n=(y-1);
		for(int j=0; j<y; j++) {
			hvt[i][j]=mat[m][n];
			n--;
		}
		m--;
	}

	// ubacivanje u ogledalo matricu
	for(int i=0; i<x*3; i++) {
		for(int j=0; j<y*3; j++) {
			if(i<x && j<y) ogld[i][j]=hvt[i][j];
			else if(i>=x && i<2*x && j<y) ogld[i][j]=vt[i-x][j];
			else if(i>=2*x && i<3*x && j<y) ogld[i][j]=hvt[i-2*x][j];
			else if(i<x && j>=y && j<2*y) ogld[i][j]=ht[i][j-y];
			else if(i>=x && i<2*x && j>=y && j<2*y) ogld[i][j]=mat[i-x][j-y];
			else if(i>=2*x && i<3*x && j>=y && j<2*y) ogld[i][j]=ht[i-2*x][j-y];
			else if(i<x && j>=2*y && j<3*y) ogld[i][j]=hvt[i][j-2*y];
			else if(i>=x && i<2*x && j>=2*y && j<3*y) ogld[i][j]=vt[i-x][j-2*y];
			else if(i>=2*x && i<3*x && j>=2*y && j<3*y) ogld[i][j]=hvt[i-2*x][j-2*y];
		}
	}
	return ogld;
}

int main ()
{
	int a, b;
	cout << "Unesite dimenzije matrice (m n): ";
	cin >> a >> b;
	if(a<0 || b<0) {
		cout << "Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	matrica mat(a, vector<double>(b)), nova;
	cout << "Unesite elemente matrice: ";
	for(int i=0; i<a; i++) {
		for(int j=0; j<b; j++) {
			cin >> mat[i][j];
		}
	}
	nova=OgledaloMatrica(mat);
	try {
		
	}
	catch(std::domain_error izuetak) {
		cout << izuetak.what() << endl;
	}
	cout << endl << "Rezultantna matrica: ";
	for(int i=0; i<nova.size(); i++) {
		cout << endl;
		for(int j=0; j<nova[0].size(); j++) {
			cout << std::setw(4) << nova[i][j];
		}
	}
	return 0;
}