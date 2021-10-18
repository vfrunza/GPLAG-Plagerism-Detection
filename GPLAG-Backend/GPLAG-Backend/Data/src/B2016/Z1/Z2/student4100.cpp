
#include <iostream>
#include <vector> 
#include <iomanip>
#include <stdexcept>

typedef std::vector<std::vector<double>> Matrica;

Matrica hfilp (Matrica M){
	if(M[0].size()==0||M[0].size()==1)
	return M;
	int m=M.size();
	int n=M[0].size();
	
	Matrica h(m, std::vector<double>(n));
	
	for ( int i = 0; i<m; i++){
		for ( int j = 0; j<n; j++){
			h [i][j] = M[i][ n - 1 - j ];
		}
	}
	return h;
}
Matrica vflip (Matrica M){
	if(M.size()==0||M.size()==1)
	return M;
	int m=M.size();
	int n=M[0].size();
	
	Matrica v(m, std::vector<double>(n));
	
	for ( int i = 0; i<m; i++){
		for ( int j = 0; j<n; j++){
			v[i][j] = M[m - i - 1][j];
		}
	}
	return v;
}
Matrica hvflip(Matrica M){
	Matrica hv(vflip(M));
	hv = hfilp(hv);

	return hv;
}
Matrica OgledaloMatrica ( Matrica M){
	if(M.size()!=0&&M[0].size()==0){
		M.resize(M.size()*3);
		return M;
	}
	else if(M.size()==0)
		return M;
	int m=M.size() * 3;
	int n=M[0].size() * 3;

	Matrica h=hfilp(M);
	Matrica v=vflip(M);
	Matrica hv=hvflip(M);
	
	Matrica ogledalo (m, std::vector<double>(n));
	
	//KREIRANJE MATRICE
	int s=M.size();
	for ( int i = 0; i<s; i++){
	//	int s=M.size();
		int s1=M[i].size();
		for ( int j = 0; j<s1; j++){
			ogledalo[i][j] = hv[i][j];
			ogledalo[i + 2 * s][j] = hv[i][j];
			ogledalo[i][j + 2 * s1] = hv[i][j];
			ogledalo[i + 2 * s][j + 2 * s1] = hv[i][j];
		}
	}
	
	for ( int i = 0; i<s; i++){
		int s1=M[i].size();
		for ( int j = 0; j<s1; j++){
			ogledalo[i][j + s1] = v[i][j];
			ogledalo[i + 2 * s][j + s1] = v[i][j];
		}
	}
	
	for ( int i = 0; i<s; i++){
		int s1=M[i].size();
		for ( int j = 0; j<s1; j++){
			ogledalo[i + s][j] = h[i][j];
			ogledalo[i + s][j + 2 * s1] = h[i][j];
		}
	}
	
	for ( int i = 0; i<s; i++){
		int s1=M[i].size();
		for ( int j = 0; j<s1; j++){
			ogledalo[i + s][j + s1] = M[i][j];
		}
	}
	return ogledalo;
}
int main ()
{
 int m, n;
 try {
 	std::cout<<"Unesite dimenzije matrice (m n): ";
 	std::cin>>m;
 	std::cin>>n;
 	if ( m < 0 || n < 0 ) throw std::domain_error( "Dimenzije matrice moraju biti nenegativne!");
 }
 catch (std::domain_error izuzetak) {
 	std::cout<<izuzetak.what();
 	return 0;
 }
 
 Matrica M (m, std::vector<double>(n));
 std::cout<<"Unesite elemente matrice:"<<"\n";
 for ( int i = 0; i<m; i++){
 	for ( int j = 0; j<n; j++){
 		std::cin>>M[i][j];
 	} 
 }
 // Matrica h=hfilp(M);
  //Matrica v=vflip(M);
  //Matrica hv=hvflip(M);
 
 Matrica ogledalo(OgledaloMatrica(M));
 
 std::cout <<"Rezultantna matrica:" << "\n";
 for ( int i = 0; i<ogledalo.size(); i++){
 	for ( int j = 0; j<ogledalo[0].size(); j++){
 		std::cout << std::setw(4) << ogledalo[i][j];
 	}
 	std::cout<<"\n";
 }
 
	return 0;
}