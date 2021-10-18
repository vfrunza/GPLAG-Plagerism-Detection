#include <iostream>
#include <vector>
#include <iomanip>
#include<stdexcept>
typedef std::vector<std::vector<double>> Matrica;

bool DaLiJePlanina(Matrica matrica, int m, int n, int velicina){
	double najvecasuma=matrica.at(m).at(n);
	for(int i=0; i<=(velicina+2)/2; i++){
		int msuma=0;
		for(int j=m-i; j<=m+i; j++){
			for(int k=n-i; k<n+i; k++){
				if(k!=n+i && k!=n+i) continue;
				msuma=msuma+matrica.at(i).at(j);
			}
		}
		if(msuma>najvecasuma) return false;
		najvecasuma=msuma;
	}
	return true;
}
int BrojRedova (Matrica m)
{
    return m.size();
}
int BrojKolona (Matrica m)
{
    if(BrojRedova(m)>0) return m.at(0).size();
    return 0;
}

Matrica NajvecaPlaninaMatrice(Matrica matrica){
	 int a, maxi=0, maxj=0;
	 for(int i=1; i<BrojRedova(matrica); i++){
    if(matrica.at(0).size()!=matrica.at(i).size()) throw std::domain_error("Matrica nije korektna");
}
    if(matrica.size()>matrica.at(0).size()) a=matrica.at(0).size();
    else a=matrica.size();
    for(a=matrica.size(); a>2; a--){
        for(int i = 0;i < matrica.size();i++){
             if(i+a/2 >= matrica.size() || i-a/2 < 0)continue;
            for(int j = 0;j < matrica.at(0).size();j++){
                if(j + a/2 >= matrica.at(0).size() || j - a/2 < 0) continue;
                if(DaLiJePlanina(matrica,i,j,a)){
                    if(!maxi){
                            maxi=i;
                            maxj=j;
                    }else{
                        if(matrica.at(i).at(j) > matrica.at(maxi).at(maxj)){
                            maxi=i;
                            maxj=j;
                        }else if(matrica.at(i).at(j) == matrica.at(maxi).at(maxj)){
                            if(i < maxi){
                                maxi=i;
                                maxj=j;
                            }else if(i == maxi){
                                if(j < maxi){
                                    maxi=i;
                                    maxj=j;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(maxi)break;
    }
int b(0);
 
Matrica planina(a,std::vector<double>());
        for(int i = maxi-a/2;i <= maxi+a/2;i++){
            for(int j = maxj-a/2;j <= maxj+a/2;j++){
                planina.at(b).push_back(matrica.at(i).at(j));
            }
            b++;
        }
    return planina;
}

int main(){
	try{
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	int m,n;
	std::cin>>m;
	std::cin>>n;
	if(m<=0 || n<=0) {std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	std::cin.clear();
		std::cin.ignore(10000, '\n');
		return 0;
	}
	std::vector<std::vector<double>> matrica(m, std::vector<double> (n));
	std::cout<<"Unesite elemente matrice: ";
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			std::cin>>matrica.at(i).at(j);
		}
	}
	std::cout<<"\nNajveca planina unesene matrice je: \n";
	std::vector<std::vector<double>> planina(NajvecaPlaninaMatrice(matrica));
     for(int i=0 ;i<planina.size(); i++){
        for(int j=0; j<planina.at(0).size(); j++){
 
            std::cout<<std::setw(6)<<planina.at(i).at(j);
        }
        std::cout<<std::endl;
     }
		
	}
	
	catch(std::domain_error izuzetak) {
        std::cout<<izuzetak.what()<<std::endl;
    }
     
	return 0;
}