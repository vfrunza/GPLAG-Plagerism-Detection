#include <iostream>
#include <vector>
#include <cmath>

const double EPS(1e-10);

std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double> v) {
    
    std::vector<std::vector<double>> ItIsMeYouWant;
    int new_size(0);
    
    std::vector<double> empty, tmp;
    int count(0);
    
    for (int i = 0; i < v.size(); i++) {
        
        if (count == 0) {
            tmp.push_back(v[i]);
            count++;
            continue;
        } else if (v[i] > tmp[count - 1] && i < v.size() - 1) {
            tmp.push_back(v[i]);
            count++;
        } else if (v[i] > tmp[count - 1] - EPS && i < v.size() - 1) { //
            tmp.push_back(v[i]);
            count++;
        } else {
            
            if (v.size() - 1 == i) {
                if (v[i] > tmp[count - 1]) {
                    tmp.push_back(v[i]);
                    count++;
                } else if (v[i] > tmp[count-1] - EPS) { //
                    tmp.push_back(v[i]);
                    count++;
                }
            }
            
            if (count >= 2) {
                new_size++;
                ItIsMeYouWant.resize(new_size);
                ItIsMeYouWant[new_size - 1] = tmp;
            }
            
            if (v.size() - 1 == i) break;
            tmp = empty;
            count = 0;
            i--;
        }
    }
    
    return ItIsMeYouWant;
}

std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double> v) {
    
    std::vector<std::vector<double>> ItIsMeYouWant;
    int new_size(0);
    
    std::vector<double> empty, tmp;
    int count(0);
    
    for (int i = 0; i < v.size(); i++) {
    
        if (count == 0) {
            tmp.push_back(v[i]);
            count++;
            continue;
        } else if (v[i] < tmp[count - 1] && i < v.size() - 1) {
            tmp.push_back(v[i]);
            count++;
        } else if (v[i] < tmp[count - 1] + EPS && i < v.size() - 1) { //
            tmp.push_back(v[i]);
            count++;
        } else {
            
            if (v.size() - 1 == i) {
                if(v[i] < tmp[count - 1]) {
                    tmp.push_back(v[i]);
                    count++;
                } else if (v[i] < tmp[count - 1] + EPS) { //
                    tmp.push_back(v[i]);
                    count++;
                }
            }
            
            if (count >= 2) {
                new_size++;
                ItIsMeYouWant.resize(new_size);
                ItIsMeYouWant[new_size - 1] = tmp;
            }
            
            if (v.size() - 1 == i) break;
            
            tmp = empty;
            count = 0;
            i--;
            
        }
    }
    
    return ItIsMeYouWant;
}

int main () {
	
	std::vector<double> vec;
	
	std::cout << "Unesite broj elemenata vektora: ";
	int br_el(0);
	std::cin >> br_el;
	
	std::cout << "Unesite elemente vektora: ";
	for (int i = 0; i < br_el; i++) {
	    double num(0);
	    std::cin >> num;
	    vec.push_back(num);
	}
	
	auto rastuci(RastuciPodnizovi(vec));
	auto opadajuci(OpadajuciPodnizovi(vec));
	
	std::cout << "Maksimalni rastuci podnizovi: " << std::endl;
	for (int i = 0; i < rastuci.size(); i++) {
	    for (int j = 0; j < rastuci[i].size(); j++) {
	        std::cout << rastuci[i][j] << " ";
	    }
	    std::cout << std::endl;
	}
	
	std::cout << "Maksimalni opadajuci podnizovi: " << std::endl;
	for (int i = 0; i < opadajuci.size(); i++) {
	    for (int j = 0; j < opadajuci[i].size(); j++) {
	        std::cout << opadajuci[i][j] << " ";
	    }
	    std::cout << std::endl;
	}
	
	return 0;
}