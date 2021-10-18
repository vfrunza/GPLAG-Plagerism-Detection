/*B 2016/2017, Zadaća 1, Zadatak 3
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <cmath>

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> opadajuca;
	std::vector<double> pomocni;
	int brojac(0), brojac_pomocnih(0);
	for(int i=0; i<v.size(); i++){
		for(int j=i+1; j<v.size(); j++){
			if((v[j-1]>v[j]  || fabs(v[j-1]-v[j])<0.00001  ) && (v[i]>v[j]  || fabs(v[i]-v[j])<0.00001 )){
				if(brojac==0){
					if(pomocni.size()==0) brojac_pomocnih++;
					pomocni.push_back(v[i]);
					pomocni.push_back(v[j]);
				}
				else pomocni.push_back(v[j]);
				brojac++;
				if(j==v.size()-1){
					opadajuca.resize(brojac_pomocnih);
					for(int k=0; k<pomocni.size(); k++){
						opadajuca[brojac_pomocnih-1].push_back(pomocni[k]);
					i=j;	
					}
				}
			}
			else if(v[j-1]<v[j] && brojac!=0){
				opadajuca.resize(brojac_pomocnih);
				for(int k=0; k<pomocni.size(); k++){
					opadajuca[brojac_pomocnih-1].push_back(pomocni[k]);
				}
				brojac=0;
				pomocni.resize(0);
				i=j;
			}
			else break;
		}
	}
	return opadajuca;
}

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v){
	std::vector<std::vector<double>> rastuca;
	std::vector<double> pomocni;
	int brojac(0), brojac_pomocnih(0);
	for(int i=0; i<v.size(); i++){
		for(int j=i+1; j<v.size(); j++){
			if((v[j-1]<v[j] || fabs(v[j-1]-v[j])<0.00001) && (v[i]<v[j] || fabs(v[i]-v[j])<0.00001)){
				if(brojac==0){
					if(pomocni.size()==0) brojac_pomocnih++;
					pomocni.push_back(v[i]);
					pomocni.push_back(v[j]);
				}
				else pomocni.push_back(v[j]);
				brojac++;
				if(j==v.size()-1){
					rastuca.resize(brojac_pomocnih);
					for(int k=0; k<pomocni.size(); k++)
				      rastuca[brojac_pomocnih-1].push_back(pomocni[k]);
				   i=j;
			}
			}
			else if(v[j-1]>v[j] && brojac!=0){
				rastuca.resize(brojac_pomocnih);
				for(int k=0; k<pomocni.size(); k++)
				   rastuca[brojac_pomocnih-1].push_back(pomocni[k]);
				brojac=0;
				pomocni.resize(0);
				i=j;
			}
			else break;
		}
	}
    return rastuca;
}

int main ()
{
	int n;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector<double> v(n);
	std::cout<<"Unesite elemente vektora: ";
    for(int i=0; i<n; i++){
    	std::cin>>v[i];
    }
    std::vector<std::vector<double>> mat=RastuciPodnizovi(v);
    std::cout<< "Maksimalni rastuci podnizovi: "<<std::endl;
    for(int i=0; i<mat.size(); i++){
    	for(int j=0; j<mat[i].size(); j++){
    		std::cout << mat[i][j]<<" ";
    	}
    	std::cout << std::endl;
    }
    std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
    mat=OpadajuciPodnizovi(v);
    for(int i=0; i<mat.size(); i++){
    	for(int j=0; j<mat[i].size(); j++){
    		std::cout << mat[i][j]<<" ";
    	}
    	std::cout<<std::endl;
    }
	return 0;
}