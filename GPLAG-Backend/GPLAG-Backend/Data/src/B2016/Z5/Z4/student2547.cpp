#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <algorithm>


using namespace std;

template <class T>
class GMatrica {

private:
    T mat[4][4];
    int kol;
    int red;

public:
    GMatrica();
    GMatrica(int kol, int red, T vrijednost = 0);


    template <class Y>
    GMatrica(Y mat);
    GMatrica(T mat[4][4]);
    GMatrica(vector<vector<T>> mat);

    int DajBrojRedova()const;
    int DajBrojKolona()const;
    T VratiMatricu();

    GMatrica<T> operator+(const GMatrica& b);
    GMatrica<T> operator-(const GMatrica& b);
    GMatrica<T> operator*(const GMatrica& b);
    GMatrica& operator+=(const GMatrica& b);
    GMatrica& operator-=(const GMatrica& b);
    GMatrica& operator*=(const GMatrica& b);
    bool operator==(const GMatrica& b);
    bool operator!=(const GMatrica& b);
    T& operator()(const int a, const int b);
    T& operator[](const int a);

    template <class S>
    friend ostream& operator<<(ostream& os, const GMatrica<S>& b);
    template <class S>
    friend istream& operator>>(istream &is, GMatrica<S>& b);

};
template<class T>
int GMatrica<T>::DajBrojRedova() const {
    return this->red;
}
template<class T>
int GMatrica<T>::DajBrojKolona() const {
    return this->kol;
}

template<class T>
GMatrica<T>::GMatrica() {
    this->kol = 0;
    this->red = 0;
}
template<class T>
GMatrica<T>::GMatrica(int kol, int red, T vrijednost) {
    this->kol = kol;
    this->red = red;
    for(int i(0); i<red; i++) {
        for(int j(0); j<kol; j++) {
            this->mat[i][j] = vrijednost;
        }
    }

}


template<class T>
template<class Y>
GMatrica<T>::GMatrica(Y mat) {
    for(int i(0); i<mat->DajBrojRedova(); i++) {
        for(int j(0); j<mat->DajBrojKolona(); j++) {
            this->mat[i][j] = mat->mat[i][j];
        }
    }
}
template<class T>
GMatrica<T>::GMatrica(T mat[4][4]) {
    for(int i(0); i<4; i++) {
        for(int j(0); j<4; j++) {
            this->mat[i][j] = mat[i][j];
        }
    }
}
template<class T>
GMatrica<T>::GMatrica(vector<vector<T>> mat) {
    if(mat.size() > 4 ) return;
    for(int i(0); i<mat.size(); i++) {
        if(mat.at(i).size() > 4) return;
        for(int j(0); j<mat.at(i).size(); j++) {
            this->mat[i][j] = mat[i][j];
        }
    }
}

template<class T>
GMatrica<T> GMatrica<T>::operator+(const GMatrica& b) {

    GMatrica a = *this;
    for(int i(0); i<b.DajBrojRedova(); i++) {
        for(int j(0); j<b.DajBrojKolona(); j++) {
            a.mat[i][j] += b.mat[i][j];
        }
    }
    return a;
}
template<class T>
T GMatrica<T>::VratiMatricu() {
    return this->mat;
}
template<class T>
GMatrica<T> GMatrica<T>::operator-(const GMatrica& b) {

    GMatrica a = *this;
    for(int i(0); i<b.DajBrojRedova(); i++) {
        for(int j(0); j<b.DajBrojKolona(); j++) {
            a.mat[i][j] -= b.mat[i][j];
        }
    }
    return a;
}

template<class T>
GMatrica<T> GMatrica<T>::operator*(const GMatrica& b) {

    GMatrica a = *this;

    for(int i (0); i < a.DajBrojRedova(); ++i)
        for(int j(0); j < b.DajBrojKolona(); ++j)
            for(int k(0); k < a.DajBrojKolona(); ++k)
            {
                a.mat[i][j] += this->mat[i][k] * b.mat[k][j];
            }

    return a;
}

template<class T>
GMatrica<T>& GMatrica<T>::operator+=(const GMatrica& b) {

    for(int i(0); i<b.DajBrojRedova(); i++) {
        for(int j(0); j<b.DajBrojKolona(); j++) {
            this->mat[i][j] += b.mat[i][j];
        }
    }
    return *this;
}

template<class T>
GMatrica<T>& GMatrica<T>::operator-=(const GMatrica& b) {

    for(int i(0); i<b.DajBrojRedova(); i++) {
        for(int j(0); j<b.DajBrojKolona(); j++) {
            this->mat[i][j] -= b.mat[i][j];
        }
    }
    return *this;
}

template<class T>
GMatrica<T>& GMatrica<T>::operator*=(const GMatrica& b) {

    for(int i (0); i < this->DajBrojRedova(); ++i)
        for(int j(0); j < b.DajBrojKolona(); ++j)
            for(int k(0); k < this->DajBrojKolona(); ++k)
            {
                this->mat[i][j] += this->mat[i][k] * b.mat[k][j];
            }

    return *this;
}

template<class T>
bool GMatrica<T>::operator==(const GMatrica& b) {

    for(int i(0); i<b.DajBrojRedova(); i++) {
        for(int j(0); j<b.DajBrojKolona(); j++) {
            if(this->mat[i][j] != b.mat[i][j])
                return false;
        }
    }

    return true;
}

template<class T>
bool GMatrica<T>::operator!=(const GMatrica& b) {

    for(int i(0); i<b.DajBrojRedova(); i++) {
        for(int j(0); j<b.DajBrojKolona(); j++) {
            if(this->mat[i][j] != b.mat[i][j])
                return false;
        }
    }
    return false;
}
template<class T>
T& GMatrica<T>::operator()(const int a, const int b) {
    if(a > this->red || b > this->kol || a < 0 || b < 0)
        throw range_error("Nedozvoljen indeks");
    return this->mat[a][b];
}

template<class T>
T& GMatrica<T>::operator[](const int a) {
    return this->mat[a];
}
template<class T>
ostream& operator<<(ostream& os, const GMatrica<T>& b) {

    int w = os.width();
    if(w < 6) w = 6;
    for (int i(0); i < b.red; i++)
    {
        os << b.mat[i][0];
        for (int j(1); j < b.kol; j++)
        {
            os << setw(w) << b.mat[i][j];
        }
        os << endl;
    }

    return os;
}

template<class T>
istream& operator>>(istream &is, GMatrica<T>& b) {

    string in;
    is >> in;
    if (!is)
        return is;

    if( in[0] != '[') return is;
    if( in[in.length()-1] != ']') return is;

    int old_len = in.length();
    in.erase(0, 1);
    in[old_len-1] = '\0';
    stringstream ss(in);
    T broj;

    int i=0;
    int j=0;
    int r = 0;

    while (ss >> broj) {

        b.mat[i][j] = broj;

        if (ss.peek() == ',') {
            ss.ignore();
            j++;
            r++;
        }
        if(ss.peek() == ';') {
            i++;
            j=0;
            ss.ignore();
        }
    }

    b.kol = j+1;
    b.red = i+1;

    return is;
}


int main() {

    cout << "Unesite matricu: \n";

    GMatrica<double> i(2, 3, 4);

    cin >> i;

    cout << i;

    cout << "Unesite matricu: \n";

    GMatrica<double> j(2, 3, 4);

    cin >> j;

    cout << j;

    cout << "Sabiranje: \n";

    cout << "I+J" << endl;
    GMatrica<double> a;
    a = i+j;
    cout << a;

    cout << "I+=J " << endl;
    a = i;
    a+=j;
    cout << a;

    cout << "Oduzimanje: \n";
    cout << "I-J" << endl;
    GMatrica<double> b;
    b = i-j;
    cout << i-j;

    cout << "I-=J" << endl;
    b = i;
    b-=j;
    cout << b;

    cout << "Mnozenje: \n";
    cout << "I*J" << endl;
    GMatrica<double> c;
    c = i*j;
    cout << i*j;

    cout << "I*=J" << endl;
    c = i;
    c*=j;
    cout << c;

    cout << "Poredjenje: \n";

    cout << (i == j) << " | " << (i != j);

    cout << "Pristup elementima: " << endl;

    cout << "I(1,1)=" << i(1,1) << endl;

    cout << "J(0,1)=" << j(0,1) << endl;

    return 0;
}