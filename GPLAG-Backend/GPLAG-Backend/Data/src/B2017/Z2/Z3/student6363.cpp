#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
int velicina_matrice {0};
int period {0};
void Podesi(int &x, int &y, int &z, int size) {
    if(x==0) {
        x=size;
        z=2;
        y=size*2;
    } else {
        y=size;
        while((y%x)!=0) y++;
        z=y/x;
    }
}
template <typename Tip>
int OdrediOsnovniPeriod(vector<Tip>x) { 
    vector<Tip> z(x.size());
    if(x.size()==1) return 0;
    /* Z algoritam - https://goo.gl/U5ykZd */
    int L = 0, R = 0;
    for (int i = 1; i < x.size(); i++) {
        if (i > R) {
            L = R = i;
            while (R < x.size() && x.at(R-L)==x.at(R)) R++;
            z.at(i) = R-L;
            R--;
        } else {
            int k = i-L;
            if (z.at(k) < R-i+1) z.at(i) = z.at(k);
            else {
                L = i;
                while (R < x.size() && x.at(R-L)==x.at(R)) R++;
                z.at(i) = R-L;
                R--;
            }
        }
    }
    for(int j=0; j<x.size(); j++)
        if(z.at(j)!=0 && j+z.at(j)==x.size()) {
            return j;
        }
    return 0;
}
template <typename Tip1>
int **AlocirajFragmentirano(const vector<Tip1> &v, int &koliko_puta) {
    if(v.empty()) throw "Prazan vektor!";
    for(int i=0; i<v.size(); i++) if(v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
    int **x {nullptr};
    period=OdrediOsnovniPeriod(v);
    Podesi(period,velicina_matrice,koliko_puta,v.size());

    try {
        x=new int*[velicina_matrice]{};
        try {
            for(int i=0,j=0; i<velicina_matrice; i++,j++) {
                if(j==period) j=0;
                x[i]=new int[v.at(j)];
            }
        } catch(...) {
            for(int i=0; i<velicina_matrice; i++) delete[] x[i];
            delete[] x;
            throw;
        }
        for(int i=0,k=0; i<velicina_matrice; i++,k++) {
            int temp=*(std::max_element(v.begin(),v.end()));
            if(k==period) k=0;
            for(int j=v.at(k)-1; j>=0; j--) {
                x[i][j]=temp--;
            }
        }
    } catch(...) {
        delete[] x;
        throw;
    }

    return x;
}
template <typename Tip1>
int **AlocirajKontinualno(const vector<Tip1> &v, int &koliko_puta) {
    if(v.empty()) throw "Prazan vektor!";
    for(int i=0; i<v.size(); i++) if(v.at(i)<=0) throw std::domain_error("Neispravan vektor!");
    int **x {nullptr};
    period=OdrediOsnovniPeriod(v);
    Podesi(period,velicina_matrice,koliko_puta,v.size());

    try {
        x=new int*[velicina_matrice]{};
        int suma {0};
        for(int i=0; i<period; i++) suma+=v.at(i);
        try {
            x[0] = new int[suma*period];
            for(int i=1,j=0; i<velicina_matrice; i++,j++) {
                if(j==period) j=0;
                x[i]= x[i-1] + v.at(j);
            }
        } catch(...) {
            throw;
        }

        for(int i=0,j=0; i<suma*period; i++,j++) {
            if(j==period) j=0;
            int temp=v.at(j);
            while(temp!=0) x[0][i++]=temp--;
            i--;
        }
    } catch(...) {
        delete[] x;
        throw;
    }

    return x;
}
int main () {
    int n;
    cout << "Unesite broj elemenata vektora: ";
    cin >> n;
    vector<int> x(n);
    cout << "Unesite elemente vektora: ";
    std::for_each(x.begin(),x.end(),[](int &a) {
        cin>>a;
    });
    int izbor;
    cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
    cin >> izbor;
    int **MAT;
    int koliko_puta;
    try {
        if(izbor) MAT=AlocirajFragmentirano(x,koliko_puta);
        else MAT=AlocirajKontinualno(x,koliko_puta);
        cout << "Dinamicki alocirana matrica: " << endl;

        for(int i=0; i<velicina_matrice; i++) {
            for(int j=0; j<x.at(i%period); j++)
                cout << std::left << std::setw(3) << MAT[i][j];
            cout << endl;
        }

        if(izbor) for(int i=0; i<velicina_matrice; i++) delete[] MAT[i];
        else delete[] MAT[0];
        delete[] MAT;
    } catch(const char* &ex) {
        cout << "Izuzetak: " << ex;
    } catch(std::exception &ex) {
        cout << "Izuzetak: " << ex.what();
    }

    return 0;
}