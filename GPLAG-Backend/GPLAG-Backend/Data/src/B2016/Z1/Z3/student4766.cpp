#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <cmath>
#include <string>

typedef std::vector<std::vector<double>> matrix;

bool jeInt (double x){
    if(x < 0) x = -x;
    return x == std::floor(x);
}

matrix RastuciPodnizovi(std::vector<double> v){
    matrix ret;
    std::vector<double> tmp;
    unsigned int len = v.size();
    if(len < 2)
        return ret;
    unsigned int p, q;
    for(unsigned int i = 0; i < len-1; i++){
        p = i;
        while(v[i] <= v[i+1] && i < len-1){
            i++;
            if(i == len - 1)
                break;
        }
        q = i;
        for(int j = p; j <= q; j++){
            tmp.push_back(v[j]);
        }
        if(q - p > 0)
            ret.push_back(tmp);
        tmp.resize(0);
    }
    return ret;
}

matrix OpadajuciPodnizovi(std::vector<double> v){
    matrix ret;
    std::vector<double> tmp;
    unsigned int len = v.size();
    if(len < 2)
        return ret;
    unsigned int p, q;
    for(unsigned int i = 0; i < len-1; i++){
        p = i;
        while(v[i] >= v[i+1] && i < len-1){
            i++;
            if(i == len -1)
                break;
        }
            
        q = i;
        for(int j = p; j <= q; j++){
            tmp.push_back(v[j]);
        }
        if(q - p > 0)
            ret.push_back(tmp);
        tmp.resize(0);
    }
    return ret;
}
void ispisiMatricu(matrix m, std::string x){
    std::cout << "Maksimalni " << x << " podnizovi: " << std::endl;
    for(unsigned int i = 0; i < m.size(); i++){
        for(unsigned int j = 0; j < m[i].size(); j++){
            if(jeInt(m[i][j])){
                //int x = std::cout.precision();
                std::cout << std::setprecision(12) << m[i][j] << " ";
                //std::cout << std::setprecision(0) << std::fixed << m[i][j] << " ";
                //std::cout.unsetf(std::ios::floatfield);
                //std::cout.precision(x);
            }
            else
            std::cout << std::setprecision(12) << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main () {
	std::cout << "Unesite broj elemenata vektora: ";
	int n;
	std::cin >> n;
	if(n < 0){
	    std::cout << "Broj elemenata mora biti pozitivan!";
	    return 0;
	}
	std::vector<double> v(n);
	std::cout << "Unesite elemente vektora: ";
	for(int i = 0; i < n; i++){
	    std::cin >> v[i];
	}
	ispisiMatricu(RastuciPodnizovi(v), "rastuci");
	ispisiMatricu(OpadajuciPodnizovi(v), "opadajuci");/*
	std::cout <<"Maksimalni rastuci podnizovi: "<< std::endl;
	matrix x(RastuciPodnizovi(v));
	for(int i = 0; i < x.size(); i++){
	    for(int j = 0; j < x[i].size(); j++){
	        std::cout << x[i][j] <<  " ";
	    }
	    std::cout << std::endl;
	}
	//e307
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	x = OpadajuciPodnizovi(v);
	for(int i = 0; i < x.size(); i++){
	    for(int j = 0; j < x[i].size(); j++){
	        if(jeInt(x[i][j])){
	            std::cout << std::setprecision(0)<< std::
	        }
	        else
	        std::cout << x[i][j] <<  " ";
	    }
	    std::cout << std::endl;
	}*/
	return 0;
}