/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

using namespace std;


vector <vector<double>> HorizontalnoOgledalo (vector<vector<double>> mat ) {
	for ( int i = 0; i < mat.size(); i ++ )
		for ( int j = 0; j < mat[i].size() / 2; j ++ ) {
			double n = mat[i][j];
			mat[i][j] = mat[i][mat[i].size() - j - 1]; 
			mat[i][mat[i].size() - j - 1] = n;
		}
		
	return mat;
}


vector <vector<double>> VertikalnoOgledalo (vector<vector<double>> mat) {
	if ( mat.size() == 0 ) return mat;
	int vel = mat[0].size();
	for ( vector<double> red : mat )
		if ( red.size() != vel ) throw domain_error("Matrica nije korektna");
	
	for ( int i = 0; i < mat.size() / 2; i ++ ) {
		vector<double> red = mat[i];
		mat[i] = mat[ mat.size() - i - 1 ];
		mat[ mat.size() - i - 1 ] = red;
	}
	return mat;
}


vector <vector<double>> KombinovanoOgledalo (vector<vector<double>> mat) {
	if ( mat.size() == 0 ) return mat;
	int vel = mat[0].size();
	for ( vector<double> red : mat ) 
		if ( red.size() != vel ) throw domain_error("Matrica nije korektna");
		
	return VertikalnoOgledalo( HorizontalnoOgledalo( mat ) );	
}

void ispisimat(vector<vector<double>> mat) {
	for ( vector<double> red : mat ) {
	   for ( double kol : red ) 
	      cout << setw(4) << kol;
	   cout << endl;
	}
}

vector<vector<double>> UbaciPodmatrice( vector<vector<double>> mat, vector<vector<double>> lijevo, vector<vector<double>> sredina, vector<vector<double>> desno) {
	for ( int i = 0; i < lijevo.size(); i ++ ) {
		vector<double> red = lijevo[i];
		for ( double n : sredina[i] ) red.push_back(n);
		for ( double n : desno[i] ) red.push_back(n);
		
		mat.push_back(red);
	}	
	
	return mat;
}

vector <vector<double>> OgledaloMatrica (vector<vector<double>> mat)
{
	if ( mat.size() == 0 ) return mat;
	
	int vel = mat[0].size();
	for ( vector<double> red : mat ) if ( red.size() != vel ) throw domain_error("Matrica nije korektna");
	
	// (<1> <2> <3>)
	// (<4> <5> <6>)
	// (<7> <8> <9>)
	
	// 1 - KombinovanoOgledalo(mat)
	// 2 - VertikalnoOgledalo(mat)
	// 3 - KombinovanoOgledalo(mat)
	// 4 - HorizontalnoOgledalo(mat)
	// 5 - mat
	// 6 - HorizontalnoOgledalo(mat)
	// 7 - KombinovanoOgledalo(mat)
	// 8 - VertikalnoOgledalo(mat)
	// 9 - KombinovanoOgledalo(mat)
	
	vector<vector<double>> pomocna;
	
	vector<vector<double>> hv = KombinovanoOgledalo(mat);
	vector<vector<double>> h = HorizontalnoOgledalo(mat);
	vector<vector<double>> v = VertikalnoOgledalo(mat);
	
	pomocna = UbaciPodmatrice(pomocna, hv, v, hv );
	pomocna = UbaciPodmatrice(pomocna, h, mat, h );
	pomocna = UbaciPodmatrice(pomocna, hv, v, hv );
	
	return pomocna;
}


int main ()
{
	int m, n;
	
	cout<<"Unesite dimenzije matrice (m n): ";
	cin>>m>>n;
	if ( m < 0 || n < 0 ) {
		cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	
	vector<vector<double>> mat(m, vector<double>(n));

	cout<<"Unesite elemente matrice: "<<endl;
	for ( vector<double>& red : mat ) 
		for ( double& kol : red )
			cin>>kol;
			
	try {
		cout<<"Rezultantna matrica: "<<endl;
		
		ispisimat(OgledaloMatrica(mat));
	} catch ( domain_error izuzetak ) {
		cout << izuzetak.what() << endl;
	}
	
	return 0;
}