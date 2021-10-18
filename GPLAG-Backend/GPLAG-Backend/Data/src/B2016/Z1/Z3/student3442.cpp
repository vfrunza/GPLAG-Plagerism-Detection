#include <iostream>
#include <vector>

typedef std::vector<std::vector<double>> Matrica;

Matrica RastuciPodnizovi(std::vector<double> v) {
    std::vector<double> pomocni;
    Matrica m;
    bool ok = true;
    bool ok_2 = false;
    int i = 0;
    
    while(i + 1 < v.size() || ok_2) {
        ok_2 = false;
        if(ok && v[i] <= v[i+1]) {
            pomocni.push_back(v[i]);
            ok = false;
            continue;
        }
        if(i + 1 < v.size() && v[i] <= v[i+1]) {
            pomocni.push_back(v[i+1]);
            ok_2 = true;
        }
        else {
            if(pomocni.size() > 1) {
                m.push_back(pomocni);
                ok = true;
                ok_2 = false;
            }
            pomocni.erase(pomocni.begin(), pomocni.end());
        }
        i++;
    }
    return m;
}

Matrica OpadajuciPodnizovi(std::vector<double> v) {
    std::vector<double> pomocni;
    Matrica m;
    bool ok = true;
    bool ok_2 = false;
    int i = 0;
    
    while(i + 1< v.size() || ok_2) {
        ok_2 = false;
        if(ok && v[i] >= v[i+1]) {
            pomocni.push_back(v[i]);
            ok = false; 
            continue;
        }
        if(i + 1 < v.size() && v[i] >= v[i+1]) {
            pomocni.push_back(v[i+1]);
            ok_2 = true;
        } 
        else {
            if(pomocni.size() > 1) {
                m.push_back(pomocni);
                ok = true;
                ok_2 = false;
            }
            pomocni.erase(pomocni.begin(), pomocni.end());
        }
        i++;
    }
    return m;
}

int main() {
    std::cout << "Unesite broj elemenata vektora: ";
    int n;
    std::cin >> n;
    std::cout << "Unesite elemente vektora: ";
    int broj;
    std::vector<double> v;
    for(int i = 0; i < n; i++) {
        std::cin >> broj;
        v.push_back(broj);
    }
    
    auto m1 = RastuciPodnizovi(v);
    std::cout << "Maksimalni rastuci podnizovi:\n";
    for(int i = 0; i < m1.size(); i++) {
        for(int j = 0; j < m1[i].size(); j++) {
            std::cout << m1[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    std::cout << "Maksimalni opadajuci podnizovi:\n";
    auto m2 = OpadajuciPodnizovi(v);
    for(int i = 0; i < m2.size(); i++) {
        for(int j = 0; j < m2[i].size(); j++) {
            std::cout << m2[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}