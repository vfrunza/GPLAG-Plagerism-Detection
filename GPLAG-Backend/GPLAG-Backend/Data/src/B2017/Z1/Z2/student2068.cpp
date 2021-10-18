/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
typedef std::vector<std::vector<double>>Matrica;
bool DaLiJeParan(int a){
	if(a%2==0) return true;
	return false;
}
Matrica NajvecaPlaninaMatrice(Matrica mat){   
	if((mat.size()==0)||(mat.at(0).size()==0)){
		return mat;
	}
	int t(mat.at(0).size());
	for(int i=0;i<mat.size();i++){
		if(mat.at(i).size()!=t) throw std::domain_error("Matrica nije korektna");	
	}
	int m(mat.size());
	int n(mat.at(0).size());
	int N;
	if(DaLiJeParan(m)) m=m-1;
	if(DaLiJeParan(n)) n=n-1;
	if(m<=n) N=m;
	else N=n;
	if(N==3) N++;
	int krug;
	if(N==1||N==2)krug=0;
	else
	krug=N-3;
	int max(0);
	double suma(0);
	int k(0);
	int l(0);
	int a;
		for(int i=krug;i<mat.size()-krug;i++){
			for(int j=krug;j<mat.at(0).size()-krug;j++){
			if(max<mat.at(i).at(j)) {
				m=i;
				n=j;
				max=mat.at(i).at(j);
			}
		}
	}
	if(N>=2)
	a=N/2;
	else
	a=1;
	
	for(int s(0);s<a;s++){
			for(int i=krug;i<mat.size()-krug;i++){
		for(int j=krug;j<mat.at(0).size()-krug;j++){
			if(max<mat.at(i).at(j)) {
				m=i;
				n=j;
				max=mat.at(i).at(j);
			}
		}
	}
	for(k=0;k<krug;k++){
		l=0;
		suma=0;
		for(int i=m-(k+1);i<=m+k+1;i++){
			for(int j=n-(k+1);j<=n+k+1;j++){
				if(i==m&&j==n) continue;
				if((i>m-(k+1)&&i<m+k+1)&&(j>n-(k+1)&&j<n+k+1)){ continue;}
				suma=suma+mat.at(i).at(j);
				if(suma>=max){
					l=1;
					break;	
				}
			}
			if(l==1){
				break;
			}
		}
		if(l==1){
		break;
		}
		max=suma;
	}
	
	if(k==1){
		Matrica planina(k+2,std::vector<double>(k+2, 0));
		for(int i=0;i<planina.size();i++){
			for(int j=0;j<planina.at(0).size();j++){
				planina.at(i).at(j)=mat.at(m-(k-i)).at(n-(k-j));
			}
		}
		return planina;
	}
	else if(DaLiJeParan(k)&&k!=0) {
		Matrica planina(k+3,std::vector<double>(k+3, 0));
		for(int i=0;i<planina.size();i++){
            for(int j=0;j<planina.at(0).size();j++){
				planina.at(i).at(j)=mat.at(m-(k-i)).at(n-(k-j));
			}
		}
		return planina;
	}
	krug--;
	}
	Matrica planina(1,std::vector<double>(1, max));
	return planina;
}


int main ()
{
	try{
		int m,n;
		std::cout<<"Unesite dimenzije matrice (m i n): ";
		std::cin>>m>>n;
		if(m<0||n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
		return 0;
		}
		std::cout<<"Unesite elemente matrice: ";
	
	Matrica Mat(m,std::vector<double>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int a;
			std::cin>>a;
			Mat.at(i).at(j)=a;
		}
	}
	std::cout<<"\nNajveca planina unesene matrice je: "<<std::endl;
    auto mat(NajvecaPlaninaMatrice(Mat));
    	for(int i=0;i<mat.size();i++){
			for(int j=0;j<mat.at(0).size();j++){
				std::cout<<"  "<<std::right<<std::setw(4)<<mat.at(i).at(j);
			}
			std::cout<<std::endl;
	}
	}catch(std::domain_error Izuzetak){
		std::cout<<"Izuzetak:"<<Izuzetak.what();
	}
    
	
	return 0;
}