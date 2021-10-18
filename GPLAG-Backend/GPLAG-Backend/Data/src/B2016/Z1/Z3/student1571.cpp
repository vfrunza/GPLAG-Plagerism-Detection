#include <iostream>
#include <vector>
#include <iomanip>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi (std::vector<double> v) {
    Matrica mat;
    std::vector<double> pomocni;
    
    for (int i=0; i<v.size()-1; i++) {
      
        while (v[i] <= v[i+1]) {
            pomocni.push_back (v[i]);
           
            if (i == v.size() - 2) {
                pomocni.push_back(v[i+1]);
                break;
            }
            else 
                i++;
        }
    
         if (i!=0 && v[i] >= v[i-1] && i != v.size()-2) {
            pomocni.push_back(v.at(i));
        }
        if (pomocni.size()!=0) {
            mat.push_back(pomocni);
            pomocni.resize(0);
        }
    }
    return mat;
}

Matrica OpadajuciPodnizovi (std::vector<double> v) {
    Matrica mat;
    
    std::vector<double> pomocni;
    
    for (int i=0; i<v.size()-1; i++) {
        while (v[i] >= v[i+1]) {
            
            pomocni.push_back (v[i]);
            if (i == v.size()-2) {
                pomocni.push_back(v[i+1]);
                break;
            }
            else
                i++;
        }
        
        if (i!= 0 && v[i] <= v[i-1] && i != v.size()-2) {
            pomocni.push_back(v[i]);
        }
        if (pomocni.size()!=0) {
            mat.push_back(pomocni);
            pomocni.resize(0);
        }
    }
    return mat;
}

int main ()
{
    std::cout << "Unesite broj elemenata vektora: ";
    int n;
    std::cin >> n;
    std::cout << "Unesite elemente vektora: ";
    std::vector<double> v;
    for (int i=0; i<n; i++) {
        double a;
        std::cin >> a;
        v.push_back(a);
    }
    
    std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
    Matrica mat (RastuciPodnizovi(v));
    for (int i=0; i<mat.size(); i++) {
        for (int j=0; j<mat[i].size(); j++) 
            std::cout << mat[i][j] << " ";
        std::cout << std::endl;
    }
    
    std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
    Matrica pomocna (OpadajuciPodnizovi(v));
    for (int i=0; i<pomocna.size(); i++) {
        for (int j=0; j<pomocna[i].size(); j++)
            std::cout << pomocna[i][j] << " ";
        std::cout << std::endl;
    }
	return 0;
}