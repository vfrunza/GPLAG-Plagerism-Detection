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

typedef std::vector<std::vector<double>> Matrica;

Matrica vogledalo(Matrica m){	
	int a(m.size());
	int b(m[0].size());
	
	Matrica v(a, std::vector<double>(b));
	int k=0;
	for(int i=a-1;i>=0;i--){
		for(int j=0;j<v[i].size();j++){
			v[k][j]=m[i][j];
		}k++;
	}
	return v;
}
Matrica hogledalo(Matrica m){	
	int a(m.size());
	int b(m[0].size());
	
	Matrica v(a, std::vector<double>(b));
	
	for(int i=0;i<v.size();i++){
		int k=b-1;
		for(int j=0;j<v[i].size();j++){
			
				v[i][j]=m[i][k];
				k--;
			
		}
	}
	return v;
}
Matrica hvogledalo(Matrica m){	
	int a(m.size());
	int b(m[0].size());
	
	Matrica v(a, std::vector<double>(b));
	
	v=(hogledalo(m));
	v=(vogledalo(v));
	return v;
	
}
	
Matrica OgledaloMatrica(Matrica m){
		bool l=true;
		for(int i=0;i<m.size();i++){
			if(m[i].size()!=m[0].size()){
				l=false;
				break;
			}
		}
		if(l==false){
			throw std::domain_error("Matrica nije korektna");
		}
		for(int i=0;i<m.size();i++){
			if(m[i].size()!=m[0].size()){
				
			}
		}
		if(m.size()==0) return m;
		else if(m.size()!=0 && m[0].size()==0){
			m.resize(3*m.size());
			return m;
		}
		
		Matrica H(hogledalo(m));
		int a(H.size());
		int b(H[0].size());
		Matrica V(vogledalo(m));
		a+=V.size();
		b+=V[0].size();
		Matrica HV(hvogledalo(m));
		a+=HV.size();
		b+=HV[0].size();
		Matrica hvM(a, std::vector<double> (b) );
		int s(HV.size());
		int p(HV[0].size());
		for(int i=0; i<a; i++){
			for(int j=0; j<b;j++){
				if(i<s && j<p) hvM[i][j]=HV[i][j];
				if(i<s && j>=p && j<2*p) hvM[i][j]=V[i][j-p];
				if(i<s && j>=2*p) hvM[i][j]=HV[i][j-2*p];
				if(i>=s && i<2*s && j<p) hvM[i][j]=H[i-s][j];
				if(i>=s && i<2*s && j>=p && j<2*p) hvM[i][j]=m[i-s][j-p];
				if(i>=s && i<2*s && j>=2*p) hvM[i][j]=H[i-s][j-2*p];
				if(i>=2*s && j<p) hvM[i][j]=HV[i-2*s][j];
				if(i>=2*s && j>=p && j<2*p) hvM[i][j]=V[i-2*s][j-p];
				if(i>=2*s && j>=2*p) hvM[i][j]=HV[i-2*s][j-2*p];
			}
		}
		
		return hvM;
	}

int main ()
{	
	std::cout << "Unesite dimenzije matrice (m n): ";
	int m, n;
	std::cin >> m >> n;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
	}
	if(m==0 || n==0){
			Matrica M(m, std::vector<double> (n));
			M=(OgledaloMatrica(M));
	}
	std::cout<<"Unesite elemente matrice:\n";
	Matrica M(m, std::vector<double> (n));
	for(int i=0; i<M.size(); i++){
		for(int j=0;j<M[i].size(); j++){
			int x;
			std::cin>>x;
			M[i][j]=x;
		}
	}

	try{
		M=(OgledaloMatrica(M));
		std::cout<<"Rezultantna matrica:\n";
		for(int i=0; i<M.size(); i++){
			for(int j=0;j<M[i].size(); j++){
				std::cout<<std::right<<std::setw(4)<<M[i][j];
				}std::cout<<std::endl;
			}
		}
	catch(std::domain_error greska){
		std::cout<<greska.what();
	}
		
	return 0;
}