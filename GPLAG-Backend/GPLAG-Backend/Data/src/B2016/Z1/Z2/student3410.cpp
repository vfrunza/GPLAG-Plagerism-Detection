/*B 2016/2017, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <iterator>
#include <stdexcept>
#include <iomanip>
std::vector<std::vector<double>> Vmatrica(std::vector<std::vector<double>> m){
	std::vector<std::vector<double>> v=m;
	int i=0;
	int vel=v.size();
	while(i!=vel && i!=--vel){
		std::vector<double> pom=v[i];
		v[i]=v[vel];
		v[vel]=pom;
		++i;
	}
	return v;
} 
std::vector<double> pom(std::vector<double> &v1){
	std::vector<double> v2;
	int i=v1.size();
	while (i>0) v2.push_back(v1[--i]);
	return v2;
}
std::vector<std::vector<double>> Hmatrica(std::vector<std::vector<double>> m){
	std::vector<std::vector<double>> h;
	for(int i=0; i<m.size();i++){
		h.push_back(pom(m[i]));
	}
	return h;
}

std::vector<std::vector<double>> HVmatrica(std::vector<std::vector<double>> m){
	std::vector<std::vector<double>> v=Hmatrica(Vmatrica(m));
	return v;
}  

std::vector<std::vector<double>> OgledaloMatrica(std::vector<std::vector<double>> m){
	if(m.size()==0) return m;
	for(int i=0; i<m.size();i++){
		if(m[i].size()!=m[0].size()) throw std::domain_error("Matrica nije korektna");
	}
	int brojRedova=m.size();
	int brojKolona=m[0].size();
	std::vector<std::vector<double>> vrati;
	vrati.resize(m.size()*3);
	vrati[0].resize(m[0].size()*3);
	for(int i=0; i<vrati.size();i++){
		vrati[i].resize(m[0].size()*3);
	}
	std::vector<std::vector<double>> v=Vmatrica(m);
	std::vector<std::vector<double>> hv=HVmatrica(m);
	std::vector<std::vector<double>> h=Hmatrica(m);
	for(int i=0; i<vrati.size(); i++){
		for(int j=0; j<vrati[0].size();j++){
			if((i/brojRedova==0 || i/brojRedova==2) && (j/brojKolona==0 || j/brojKolona==2)){
				vrati[i][j]=hv[i-brojRedova*(i/brojRedova)][j-brojKolona*(j/brojKolona)];
			}
			else if((i/brojRedova==0 || i/brojRedova==2) && j/brojKolona==1){
				vrati[i][j]=v[i-brojRedova*(i/brojRedova)][j-brojKolona*(j/brojKolona)];
			}
			else if((i/brojRedova==0 || i/brojRedova==2) && j/brojKolona==1){
				vrati[i][j]=v[i-brojRedova*(i/brojRedova)][j-brojKolona*(j/brojKolona)];
			}
			else if(i/brojRedova==1 && (j/brojKolona==0 || j/brojKolona==2)){
				vrati[i][j]=h[i-brojRedova*(i/brojRedova)][j-brojKolona*(j/brojKolona)];
			}
			else vrati[i][j]=m[i-brojRedova*(i/brojRedova)][j-brojKolona*(j/brojKolona)];
			
		}
	}
	return vrati;
	
}

int main ()
{
	try{
    std::vector<std::vector<double>> v;
    int m;
    int n;
    std::cout<<"Unesite dimenzije matrice (m n): ";
    std::cin>>m>>n;
    if(m<0 || n<0) throw std::domain_error("Dimenzije matrice moraju biti nenegativne!");
    if(m==0 || n==0) {
         std::cout<<"Unesite elemente matrice: "<<std::endl;
         std::cout<<"Rezultantna matrica: "<<std::endl;
         return 0;
    }
    v.resize(m);
    v[0].resize(n);
    for(int i=0;i<v.size();i++) v[i].resize(n);
    std::cout<<"Unesite elemente matrice: "<<std::endl;
    for(int i=0; i<v.size();i++){
        for(int j=0; j<v[0].size();j++){
            std::cin>>v[i][j];
        }
    }

    v=OgledaloMatrica(v);
    std::cout<<"Rezultantna matrica: "<<std::endl;
    for(int i=0; i<v.size();i++){
        for(int j=0; j<v[0].size();j++){
            std::cout<<std::setw(4)<<v[i][j];
        }
        std::cout<<std::endl;
    }
    }
    catch(std::domain_error ex){
    std::cout<<ex.what()<<std::endl;
    }
	return 0;
}