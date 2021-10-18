#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::vector;


vector<vector<double>> OgledaloMatrica (vector<vector<double>> matrica);
bool daLiJeMatricaGrbava(vector<vector<double>> matrica);
vector<vector<double>> vertikalnoOgledaloMatrice(vector<vector<double>> matrica);
vector<vector<double>> horizontalnoOgledaloMatrice(vector<vector<double>> matrica);
void printajMatricu(vector<vector<double>> matrica);

int main() {
    cout << "Unesite dimenzije matrice (m n): ";
    int m, n;
    cin >> m >> n;
    if(m < 0 || n < 0){
        cout << "Dimenzije matrice moraju biti nenegativne!";
        return 0;
    }
    vector<vector<double>> matrica(m);
    for(auto &red : matrica)
        red.resize(n);
    cout << "Unesite elemente matrice: " << endl;
    for(auto &red : matrica)
        for(auto &clan : red)
            cin >> clan;
    cout << "Rezultantna matrica: " << endl;
    printajMatricu(OgledaloMatrica(matrica));
    return 0;
}

vector<vector<double>> OgledaloMatrica (vector<vector<double>> matrica) {
    if(daLiJeMatricaGrbava(matrica)) throw std::domain_error("Matrica nije korektna");
    vector<vector<double>> rezultat(0), vertikalnoOgledalo(0), horizontalnoOgledalo(0), kombinovanoOgledalo(0);
    vertikalnoOgledalo = vertikalnoOgledaloMatrice(matrica);
    horizontalnoOgledalo = horizontalnoOgledaloMatrice(matrica);
    kombinovanoOgledalo = vertikalnoOgledaloMatrice(horizontalnoOgledalo);
    for(unsigned int i = 0; i < matrica.size(); i++) {
        vector<double> pomocni(0);//2*kombinovanoOgledalo.size() + vertikalnoOgledalo.size());
        pomocni.insert(pomocni.end(), kombinovanoOgledalo[i].begin(), kombinovanoOgledalo[i].end());
        pomocni.insert(pomocni.end(), vertikalnoOgledalo[i].begin(), vertikalnoOgledalo[i].end());
        pomocni.insert(pomocni.end(), kombinovanoOgledalo[i].begin(), kombinovanoOgledalo[i].end());
        rezultat.push_back(pomocni);
    }
    kombinovanoOgledalo = rezultat;
    for(unsigned int i = 0; i < matrica.size(); i++) {
        vector<double> pomocni(0);//2*horizontalnoOgledalo.size() + matrica.size());
        pomocni.insert(pomocni.end(), horizontalnoOgledalo[i].begin(), horizontalnoOgledalo[i].end());
        pomocni.insert(pomocni.end(), matrica[i].begin(), matrica[i].end());
        pomocni.insert(pomocni.end(), horizontalnoOgledalo[i].begin(), horizontalnoOgledalo[i].end());
        rezultat.push_back(pomocni);
    }
    //rezultat.resize(rezultat.size() + kombinovanoOgledalo.size());
    rezultat.insert(rezultat.end(), kombinovanoOgledalo.begin(), kombinovanoOgledalo.end());
    return rezultat;
}

bool daLiJeMatricaGrbava(vector<vector<double>> matrica) {
    for(vector<double> red : matrica) {
        if(red.size() != matrica[0].size())
            return true;
    }
    return false;
}
vector<vector<double>> vertikalnoOgledaloMatrice(vector<vector<double>> matrica) {
    vector<vector<double>> rezultat(0);
    int i = matrica.size();
    while(i > 0)
        rezultat.push_back(matrica[--i]);
    return rezultat;
}
vector<vector<double>> horizontalnoOgledaloMatrice(vector<vector<double>> matrica) {
    vector<vector<double>> rezultat(0);
    for(vector<double> red : matrica) {
        vector<double> pomocna(0);
        int i = red.size();
        while(i > 0)
            pomocna.push_back(red[--i]);
        rezultat.push_back(pomocna);
    }
    return rezultat;
}
void printajMatricu(vector<vector<double>> matrica) {
    for(vector<double> red : matrica) {
        for(double clan : red){
            cout << std::setw(4) << clan;
        }
        cout << endl;
    }
}

