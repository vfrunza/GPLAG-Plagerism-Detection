/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include<iostream>
#include<vector>
#include<iomanip>
#include<stdexcept>
typedef std::vector<std::vector<double>> matrica;


matrica unesi(int m,int n){
	
	if(m<0 || n<0 ){
		
	 throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
	}
	
	matrica M(m,std::vector<double>(n));
	
	for(int i=0;i<m;i++){
		if(M[0].size()!=M[i].size()){
			throw std::domain_error("Matrica nije korektna");
		}
	}
	
	

	
	std::cout<<"Unesite elemente matrice: ";
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			std::cin>>M[i][j];
		}
		
	}
	
return M;	
}


int brojredova(matrica m){
	return m.size();
}
int brojkolona(matrica m){
	if(brojredova(m)==0) return 0;
	
	return m[0].size();
}

matrica hmatrica(matrica a){
	
	
	
	
	
	
	int m(brojredova(a));
	int n(brojkolona(a));

	
	matrica h(m);
	
	for(int i=0;i<m;i++){
		for(int j=n-1;j>=0;j--){
			
			
		h[i].push_back(a[i][j]);
			
			
		}
	}
	
 return h;
}
matrica vmatrica(matrica a){
	int m(brojredova(a));
	int n(brojkolona(a));
	
	matrica v(m);
	int k(0);
	for(int i=m-1;i>=0;i--){
		
		
		for(int j=0;j<n;j++){
			
		v[k].push_back(a[i][j]);
	//	std::cout<<v[i][j];
	 
		}
		k++;
		
		
	}
return v;
}

matrica hvmatrica(matrica a){
	int m(brojredova(a));
	int n(brojkolona(a));
	
	matrica hv(m);
	int k(0);
	for(int i=m-1;i>=0;i--){
		for(int j=n-1;j>=0;j--){
			hv[k].push_back(a[i][j]);
	}
		k++;
	}
	return hv;
}

matrica OgledaloMatrica(matrica a){
	

	
	
	
	int m(brojredova(a));
	
	for(int i=0;i<m;i++){
		if(a[0].size()!=a[i].size()) throw std::domain_error("Matrica nije korektna");
	}
	
	
	
	int n(brojkolona(a));
	matrica h(hmatrica(a)),v(vmatrica(a)),hv(hvmatrica(a));
	
	matrica x(3*m);
	int k(0),ii(0),z(0);
	
	for(int i=0;i<3*m;i++){
	if(i<m){
		for(int j=0;j<n;j++){
			
			x[i].push_back(hv[k][j]);
		}
		for(int j=0;j<n;j++){
			x[i].push_back(v[k][j]);
			
		}
		for(int j=0;j<n;j++){
			x[i].push_back(hv[k][j]);
		}
		k++;
	}
		
if(i>=m && i<2*m){
	

		for(int j=0;j<n;j++){
			x[i].push_back(h[ii][j]);
		}
		for(int j=0;j<n;j++){
			x[i].push_back(a[ii][j]);
		}
		for(int j=0;j<n;j++){
			x[i].push_back(h[ii][j]);
		}
		ii++;
		
	
		
}
if(i>=2*m && i<3*m){
	for(int j=0;j<n;j++){
		x[i].push_back(hv[z][j]);
	}
	for(int j=0;j<n;j++){
		x[i].push_back(v[z][j]);
	}
	for(int j=0;j<n;j++){
		x[i].push_back(hv[z][j]);
	}
	z++;
}
	}
	
	
	return x;
	
}
int main ()
{
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin>>m>>n;
	
	try{
//	std::cout<<"Unesite elemente matrice: ";
	auto M(unesi(m,n));
	
//	auto V(hvmatrica(M));



auto V(OgledaloMatrica(M));

//	std::cout<<V.size();
//std::cout<<V[0].size();
	std::cout<<"\nRezultantna matrica: "<<std::endl;
	for(int i=0;i<V.size();i++){
		for(int j=0;j<V[0].size();j++){
			
			std::cout<<std::setw(4)<<V[i][j];
			
			
		}
		std::cout<<std::endl;
	}


}
catch(std::domain_error poruka){
	std::cout<<poruka.what();
}

	
	return 0;
}