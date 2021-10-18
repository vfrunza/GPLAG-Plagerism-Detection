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
typedef std::vector<std::vector<double>> Matrica;

Matrica Vertikalna(Matrica a){
	Matrica m(a.size());
	for(int i=0; i<m.size(); i++)m[i].resize(a[0].size());
	for(int i=0; i<a[0].size(); i++){
		for(int j=0; j<a.size();j++){
			m[m.size()-1-j][i]=a[j][i];
		}
	}
	return m;
}

Matrica Horizontalna(Matrica a){
	Matrica m(a.size());
	for(int i=0; i<m.size(); i++)m[i].resize(a[0].size());
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<a[0].size();j++){
			m[i][m[0].size()-1-j]=a[i][j];
		}
	}
	return m;
}

Matrica OgledaloMatrica(Matrica a){
	if(a.size()==0)return a;
	for(int i=0; i<a.size()-1; i++){
		if(a[i].size()<a[i+1].size())throw std::domain_error("Matrica nije korektna");
	}
	Matrica h,v,hv,m;
	m.resize(3*a.size());
	for(int i=0; i<m.size(); i++)m[i].resize(a[0].size()*3);
	v=Vertikalna(a);
	h=Horizontalna(a);
	hv=Vertikalna(h);
	/*1.RED*/
	for(int i=0; i<hv.size(); i++){
		for(int j=0; j<hv[0].size(); j++){
			m[i][j]=hv[i][j];
		}
	}
	
	for(int i=0; i<v.size(); i++){
		for(int j=(m[0].size()/3); j<(m[0].size()/3)*2; j++){
			m[i][j]=v[i][j-(m[0].size()/3)];
		}
	}
	
	for(int i=0; i<hv.size(); i++){
		for(int j=(m[0].size()/3)*2; j<m[0].size(); j++){
			m[i][j]=hv[i][j-((m[0].size()/3)*2)];
		}
	}
	/*2. RED*/
	for(int i=m.size()/3; i<(m.size()/3)*2; i++){
		for(int j=0; j<h[0].size(); j++){
			m[i][j]=h[i-m.size()/3][j];
		}
	}
	
	for(int i=m.size()/3; i<(m.size()/3)*2; i++){
		for(int j=(m[0].size()/3); j<(m[0].size()/3)*2; j++){
			m[i][j]=a[i-m.size()/3][j-(m[0].size()/3)];
		}
	}
	
	for(int i=m.size()/3; i<(m.size()/3)*2; i++){
		for(int j=(m[0].size()/3)*2; j<m[0].size(); j++){
			m[i][j]=h[i-m.size()/3][j-((m[0].size()/3)*2)];
		}
	}
	/*3.RED*/
	for(int i=(m.size()/3)*2; i<m.size(); i++){
		for(int j=0; j<hv[0].size(); j++){
			m[i][j]=hv[i-((m.size()/3)*2)][j];
		}
	}
	
	for(int i=(m.size()/3)*2; i<m.size(); i++){
		for(int j=(m[0].size()/3); j<(m[0].size()/3)*2; j++){
			m[i][j]=v[i-((m.size()/3)*2)][j-(m[0].size()/3)];
		}
	}
	
	
	for(int i=(m.size()/3)*2; i<m.size(); i++){
		for(int j=(m[0].size()/3)*2; j<m[0].size(); j++){
			m[i][j]=hv[i-((m.size()/3)*2)][j-(m[0].size()/3)*2];
		}
	}
		return m;
}

int main ()
{
	std::cout<<"Unesite dimenzije matrice (m n): ";
	int m,n;
	std::cin>>m>>n;
	if(m<0 || n<0){std::cout<<"Dimenzije matrice moraju biti nenegativne!"; return 0;}
	std::cout<<"Unesite elemente matrice: ";
	Matrica a(m,std::vector<double>(n));
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			std::cin>>a[i][j];
		}
	}
	Matrica k;
	try {
		k=OgledaloMatrica(a);
	}
	catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what() << std::endl;
	}
	std::cout<<std::endl<<"Rezultantna matrica:"<<std::endl;
	for(int i=0; i<m*3; i++){
		for(int j=0; j<n*3; j++){
			std::cout<<std::setw(4)<<k[i][j];
			
		}
		std::cout<<std::endl;
	}
	return 0;
}