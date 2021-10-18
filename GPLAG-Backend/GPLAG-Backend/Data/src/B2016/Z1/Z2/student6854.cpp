/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<stdexcept>
typedef std::vector<std::vector<double>> Matrica;
Matrica KreijarMatricu(int r, int k){
	return Matrica(r, std::vector<double>(k));
}
Matrica Kombinovana(Matrica m){
	int r=m.size(), k=m[0].size();
	if(r==0 && k==0) return m;
	Matrica nm=KreijarMatricu(r,k);
	for(int i=0; i<r; i++){
		for(int j=0; j<k; j++){
			nm[r-1-i][k-1-j]=m[i][j];
		}
	}
	return nm;
}
Matrica Horizontalna(Matrica m){
	int r=m.size(), k=m[0].size();
	if(r==0 && k==0) return m;
	Matrica nm=KreijarMatricu(r,k);
	for(int i=0; i<r; i++){
		for(int j=0; j<k; j++){
			nm[i][k-1-j]=m[i][j];
		}
	}
	return nm;
}
Matrica Vertikalna(Matrica m){
	int r=m.size(), k=m[0].size();
	if(r==0 && k==0) return m;
	Matrica nm=KreijarMatricu(r,k);
	for(int i=0; i<r; i++){
		for(int j=0; j<k; j++){
			nm[r-1-i][j]=m[i][j];
		}
	}
	return nm;
}
Matrica OgledaloMatrica(Matrica m){
	int r=m.size(),k=m[0].size();
	if(r>1){
	int izuz=1;
	for(int i=1; i<r; i++){
		if(m[i].size()!=k) {
			izuz=0;
			break;
		}
	}
	if(izuz==0) throw std::domain_error("Matrica nije konkretna.");
	}
	try{
		if(r!=0 || k!=0){
	Matrica om=KreijarMatricu(3*r,3*k);
	Matrica h=Horizontalna(m);
	Matrica v= Vertikalna(m);
	Matrica hv=Kombinovana(m);
	for(int i=0; i<3*r; i++){
		for(int j=0; j<3*k; j++){
			if(i<r && j<k) om[i][j]=hv[i][j];
			if(i<r && j>=k && j<2*k) om[i][j]=v[i][j-k];
			if(j<k && i>=r && i<2*r) om[i][j]=h[i-r][j];
			if(i<r && j>=2*k && j<3*k) om[i][j]=hv[i][j-2*k];
			if(j<k && i>=2*r && i<3*r) om[i][j]=hv[i-2*r][j];
			if(i>=r && i<2*r && j>=k && j<2*k) om[i][j]=m[i-r][j-k];
			if(i>=r && i<2*r && j>=2*k && j<3*k) om[i][j]=h[i-r][j-2*k];
			if(j>=k && j<2*k && i>=2*r && i<3*r) om[i][j]=v[i-2*r][j-k];
			if(i>=2*r && i<3*k && j>=2*k && j<3*k) om[i][j]=hv[i-2*r][j-2*k];
		}
	}
	return om;
		} 
		return m;
	}
	catch(std::domain_error izuzetak){
		std::cout << izuzetak.what() << std::endl;
	}
}
int main ()
{
	int m,n;
	std::cout << "Unesite dimenzije matrice (m n): ";
	std::cin >> m >> n;
	if(m<0 || n<0){
		std::cout << "Dimenzije matrice moraju biti nenegativne!" << std::endl;
		return 1;
	}
	Matrica mat=KreijarMatricu(m,n);
	std::cout << "Unesite elemente matrice: " << std::endl;
	for(int i=0; i<m; i++)
	   for(int j=0; j<n; j++)
	       std::cin >> mat[i][j];
	Matrica nm=OgledaloMatrica(mat);
	int r=nm.size(), k=nm[0].size();
	std::cout << "Rezultantna matrica:" << std::endl;
	if(r==0 && k==0) return 0;
	for(int i=0; i<r; i++){
		for(int j=0; j<k; j++){
			std::cout.width(4);
			std::cout<<nm[i][j];
		}
		std::cout<<std::endl;
	}
	return 0;
}