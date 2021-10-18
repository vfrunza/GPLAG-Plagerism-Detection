#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<vector<double>> RastuciPodnizovi(vector<double> brojevi);
void printajMatricu(vector<vector<double>> matrica);
vector<vector<double>> OpadajuciPodnizovi(vector<double> brojevi);

const double epsilon(0.000000000001);

int main() {
    cout << "Unesite broj elemenata vektora: ";
    int brojElemenata;
    cin >> brojElemenata;
    vector<double> brojevi(0);
    cout << "Unesite elemente vektora: ";
    for(int i=0; i<brojElemenata; i++) {
        double pomocna;
        cin >> pomocna;
        brojevi.push_back(pomocna);
    }
    cout << "Maksimalni rastuci podnizovi: " << endl;
    printajMatricu(RastuciPodnizovi(brojevi));
    cout << "Maksimalni opadajuci podnizovi: " << endl;
    printajMatricu(OpadajuciPodnizovi(brojevi));
    //*/
    return 0;
}

vector<vector<double>> RastuciPodnizovi(vector<double> brojevi) {
    vector<vector<double>> rezultat(0);
    vector<double> podniz(0);
    for(int i = 0; i < brojevi.size()-1; i++) {
        if(brojevi.at(i) < brojevi.at(i+1) || std::fabs(brojevi.at(i+1) - brojevi.at(i)) < epsilon) {
            podniz.push_back(brojevi.at(i));

        } else {
            podniz.push_back(brojevi.at(i));
            if(1 < podniz.size())
                rezultat.push_back(podniz);
            podniz.clear();
        }

        if(i == brojevi.size()-2) {
            podniz.push_back(brojevi.at(brojevi.size()-1));
        }
    }
    if(1 < podniz.size())
        rezultat.push_back(podniz);
    return rezultat;
}
vector<vector<double>> OpadajuciPodnizovi(vector<double> brojevi) {
    vector<vector<double>> rezultat(0);
    vector<double> podniz(0);
    for(int i = 0; i < brojevi.size()-1; i++) {
        if(brojevi.at(i+1) < brojevi.at(i) || std::fabs(brojevi.at(i+1) - brojevi.at(i)) < epsilon) {
            podniz.push_back(brojevi.at(i));

        } else {
            podniz.push_back(brojevi.at(i));
            if(1 < podniz.size())
                rezultat.push_back(podniz);
            podniz.clear();
        }

        if(i == brojevi.size()-2) {
            podniz.push_back(brojevi.at(brojevi.size()-1));
        }
    }
    if(1 < podniz.size())
        rezultat.push_back(podniz);
    return rezultat;
}
void printajMatricu(vector<vector<double>> matrica) {
    for(vector<double> red : matrica) {
        for(double clan : red)
            cout << clan << " ";
        cout << endl;
    }
}

