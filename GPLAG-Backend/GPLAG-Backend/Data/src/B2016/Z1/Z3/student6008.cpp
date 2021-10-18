#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

typedef std::vector<std::vector<double>> matrica;
typedef std::vector<double> vec;


matrica RastuciPodnizovi(vec v){
    matrica m;
    m.resize(1);
    int k(0);
    for(int i=0; i < v.size(); i++){
        m[k].push_back(v[i]);
        
        if (i < v.size()-1 && v[i] > v[i+1]) {
            while (i < v.size()-1 && v[i] > v[i+1]) {
                i++;
            }
            k++;
            m.resize(m.size()+1);
            m[k].push_back(v[i]);
        }
    }

    matrica mat;
    k = 0;
    
    for (int i = 0; i < m.size(); i++) {
        if (m[i].size() > 1) {
            mat.resize(mat.size() + 1);
            for (int j = 0; j < m[i].size(); j++) {
                mat[k].push_back(m[i][j]);
            }
            k++;
        }
    }
    
    return mat;
}

matrica OpadajuciPodnizovi(vec v){
    matrica m;
    m.resize(1);
    int k(0);
    
    for(int i=0; i < v.size(); i++){
        m[k].push_back(v[i]);
        if (i < v.size()-1 && v[i] < v[i+1]) {
            while (i < v.size()-1 && v[i] < v[i+1]) {
                i++;
            }
            k++;
            m.resize(m.size() + 1);
            m[k].push_back(v[i]);
        }
    }

    matrica mat;
    k = 0;
    
    for (int i = 0; i < m.size(); i++) {
        if (m[i].size() > 1) {
            mat.resize(mat.size() + 1);
            for (int j = 0; j < m[i].size(); j++) {
                mat[k].push_back(m[i][j]);
            }
            k++;
        }
    }
    
    return mat;
    
}

int main ()
{
    matrica m, c;
	vec v;
	int n;
	double j;
	std::cout<<"Unesite broj elemenata vektora: ";
	std::cin>>n;
	std::cout<<"Unesite elemente vektora: ";
	for(int i=0; i<n; i++){
	    std::cin>>j;
	    v.push_back(j);
	}
	m=RastuciPodnizovi(v);
	std::cout<<"Maksimalni rastuci podnizovi: \n";
	for(int i=0; i<m.size(); i++){
	    for(int j=0; j<m[i].size(); j++){
	        std::cout<<m[i][j]<<" ";
	    }
	    std::cout<<std::endl;
	}
	c=OpadajuciPodnizovi(v);
	std::cout<<"Maksimalni opadajuci podnizovi: \n";
	for(int i=0; i<c.size(); i++){
	    for(int j=0; j<c[i].size(); j++){
	        std::cout<<c[i][j]<<" ";
	    }
	    std::cout<<std::endl;
	}
	

	return 0;
}