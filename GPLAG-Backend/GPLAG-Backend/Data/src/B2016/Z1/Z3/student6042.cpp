#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <iomanip>

int Broj_redova_1(const std::vector<double>&v) {
int brojac(0);
for (int i=0;i<v.size()-1;i++) {
    if (v[i]<=v[i+1] && i<v.size()-1) {
        brojac++;
        while (v[i]<=v[i+1] && i<v.size()-2) i++;
        if (i==v.size()) break;
    }
}
return brojac;
}


std::vector<std::vector<double>> RastuciPodnizovi(std::vector<double>v) {
std::vector<std::vector<double>>r(Broj_redova_1(v));
int l=0;
for (int i=0;i<v.size()-1;i++) {
    if (i<v.size()-1 && v[i]<=v[i+1]) {
        while (i<v.size()-1 && v[i]<=v[i+1]) {
            r[l].push_back(v[i]);
            i++;
        }
        r[l].push_back(v[i]);
        l++;
    }
    if (i==v.size()) break;
}
return r;
}



int Broj_redova_2(const std::vector<double>&v) {
int brojac(0);
for (int i=0;i<v.size()-1;i++) {
    if (v[i]>=v[i+1] && i<v.size()-1) {
        brojac++;
        while (v[i]>=v[i+1] && i<v.size()-2) i++;
        if (i==v.size()) break;
    }
}
return brojac;
}


std::vector<std::vector<double>> OpadajuciPodnizovi(std::vector<double>v) {
std::vector<std::vector<double>>r(Broj_redova_2(v));
int l=0;
for (int i=0;i<v.size()-1;i++) {
    if (i<v.size()-1 && v[i]>=v[i+1]) {
        while (i<v.size()-1 && v[i]>=v[i+1]) {
            r[l].push_back(v[i]);
            i++;
        }
        r[l].push_back(v[i]);
        l++;
    }
    if (i==v.size()) break;
}
return r;
}






int main () {
std::vector<double>v;
int n;
int broj;
std::cout<<"Unesite broj elemenata vektora: ";
std::cin>>n;
std::cout<<"Unesite elemente vektora: ";
for (int i=0;i<n;i++) {
    std::cin>>broj;
    v.push_back(broj);
}

std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
std::vector<std::vector<double>>r=RastuciPodnizovi(v);
for (int i=0;i<r.size();i++) {
    for (int j=0;j<r[i].size();j++) {
        std::cout<<r[i][j]<<" ";
    }
    std::cout<<std::endl;
}

std::cout<<std::endl;
std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
std::vector<std::vector<double>>o=OpadajuciPodnizovi(v);
for (int i=0;i<o.size();i++) {
    for (int j=0;j<o[i].size();j++) {
        std::cout<<o[i][j]<<" ";
    }
    std::cout<<std::endl;
}


return 0;
}









