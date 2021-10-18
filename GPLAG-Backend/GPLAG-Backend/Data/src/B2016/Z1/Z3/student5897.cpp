
#include <iostream>
#include <vector>
#include <iomanip>


typedef std::vector<std::vector<double>> Matrica;


Matrica RastuciPodnizovi(std::vector<double> vekt) {
    
    Matrica mat(0);
    
    if(vekt.size()>0) {
        mat.resize(1);
        int red(0), pamti_i(0), i(0);
        
        for(; i<vekt.size()-1; i++) {
            if(vekt[i]<=vekt[i+1]) continue;
            if(i==pamti_i) {
                pamti_i = i+1;
                continue;
            }
        
            mat[red].resize(i-pamti_i+1);
        
            int k(0);
        
            for(int j=pamti_i; j<i+1; j++) {
                mat[red][k]=vekt[j];
                k++;
            }
        
            pamti_i=i+1;
            red++;
            mat.resize(red+1);
        }
    
    if(i-pamti_i >= 1) {
        mat[red].resize(i-pamti_i+1);
        int k(0);
        
        for(int j=pamti_i; j<i+1; j++) {
            mat[red][k]=vekt[j];
            k++;
        }
    }
}
    
    return mat;
} 

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> vekt) {
    
    Matrica mat(0);
    
    if(vekt.size()>0) {
        
        mat.resize(1);
        
        int red(0), pamti_i(0), i(0);
        
        for(; i<vekt.size()-1; i++) {
            if(vekt[i]>=vekt[i+1]) continue;
            if(i==pamti_i) {
                pamti_i=i+1;
                continue;
            }
            
            mat[red].resize(i-pamti_i+1);
            
            int k(0);
            
            for(int j=pamti_i; j<i+1; j++) {
                mat[red][k]=vekt[j];
                k++;
            }
            
            pamti_i=i+1;
            red++;
            mat.resize(red+1);
        }
        
        if(i-pamti_i>=1) {
            mat[red].resize(i-pamti_i+1);
            
            int k(0);
            
            for(int j=pamti_i; j<i+1; j++) {
                mat[red][k]=vekt[j];
                k++;
            }
        }
    }
    return mat;
}

int main()
{ 
    std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	
	std::cout << "Unesite elemente vektora: ";
	std::vector<double> v;
	while(n) {
		int a;
		std::cin >> a;
		v.push_back(a);
		n--;
	}

    Matrica mat1 = RastuciPodnizovi(v);
    std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
    for(int i = 0; i < mat1.size(); i++){
        for(int j = 0; j < mat1[i].size(); j++)
           std::cout<< std::setprecision(12) << mat1[i][j] << " ";
        std::cout<<std::endl;
    }
    
    //std::cout << BrojPodnizoveOpadajuce(v) << " " << BrojPodnizoveRastuce(v);
    std::cout<< "Maksimalni opadajuci podnizovi: " << std::endl;
    Matrica mat2 = OpadajuciPodnizovi(v);
    for(int i = 0; i < mat2.size(); i++){
        for(int j = 0; j < mat2[i].size(); j++)
            std::cout<< std::setprecision(12) << mat2[i][j] << " ";
        std::cout<<std::endl;
    }
    
    return 0;
}
