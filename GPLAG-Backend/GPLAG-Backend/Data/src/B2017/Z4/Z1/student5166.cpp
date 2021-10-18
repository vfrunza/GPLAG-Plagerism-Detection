/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <tuple>
#define PI 4*atan(1);
using namespace std;

class Kugla {
    double X, Y, Z, R;
public:  
    explicit Kugla(double r = 0);
    Kugla(double x, double y, double z, double r = 0);
    explicit Kugla(const tuple<double, double, double> &centar, double r = 0){
        X=get<0>(centar); Y=get<1>(centar); Z=get<2>(centar);
    }
    double DajX() const { return X; }
    double DajY() const { return Y; }
    double DajZ() const { return Z; }
    tuple<double, double, double> DajCentar() const {
        return make_tuple (X,Y,Z);
    }
    double DajPoluprecnik() const { return R; }
    double DajPovrsinu() const { return 4*R*R*PI; }
    double DajZapreminu() const { return (4/3.)*R*R*R*PI; }
    
    Kugla &PostaviX(double x){ X=x; }
    Kugla &PostaviY(double y){ Y=y; }
    Kugla &PostaviZ(double z){ Z=z; }
    Kugla &PostaviCentar(double x, double y, double z){ X=x; Y=y; Z=z; }
    Kugla &PostaviCentar(const tuple<double, double, double> &centar){
        X=get<0>(centar); Y=get<1>(centar); Z=get<2>(centar);
    }
    Kugla &PostaviPoluprecnik(double r) {
        if (r<0) throw domain_error ("Ilegalan poluprecnik");
        R=r;
    }
    
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y, double delta_z);
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2);
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2);
    bool DaLiSadrzi(const Kugla &k) const;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);
};

Kugla::Kugla(double r){
    if (r<0) throw domain_error ("Ilegalan poluprecnik");
    R = r; X=0; Y=0; Z=0;
}
Kugla::Kugla (double x, double y, double z, double r){
    if (r<0) throw domain_error ("Ilegalan poluprecnik");
    X = x; Y = y; Z = z; R = r; 
}
void Kugla::Ispisi() const {
    cout << "{(" << X << "," << Y << "," << Z << ")," << R << "}";
}
void Kugla::Transliraj(double delta_x, double delta_y, double delta_z){
    X += delta_x; Y+=delta_y; Z+=delta_z;
}
bool DaLiSuIdenticne (const Kugla &k1, const Kugla &k2){
    return (k1.R == k2.R && k1.X == k2.X && k1.Y == k2.Y && k1.Z == k2.Z);
}
bool DaLiSuPodudarne (const Kugla &k1, const Kugla &k2) {
    return k1.R == k2.R;
}
bool DaLiSuKoncentricne (const Kugla &k1, const Kugla &k2){
    return k1.X == k2.X && k1.Y == k2.Y && k1.Z == k2.Z;
}
bool DaLiSeDodirujuIzvana (const Kugla &k1, const Kugla &k2){
    return k1.R+k2.R == sqrt(pow(k2.X-k1.X,2) + pow(k2.Y-k1.Y,2) + pow(k2.Z-k1.Z,2));
}
bool DaLiSeDodirujuIznutra (const Kugla &k1, const Kugla &k2){
    return sqrt(pow(k1.R-k2.R,2)) == sqrt(pow(k2.X-k1.X,2) + pow(k2.Y-k1.Y,2) + pow(k2.Z-k1.Z,2)); 
}
bool DaLiSePreklapaju (const Kugla &k1, const Kugla &k2){
    return sqrt(pow(k2.X-k1.X,2) + pow(k2.Y-k1.Y,2) + pow(k2.Z-k1.Z,2)) < k1.R + k2.R;
}
bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2){
    return (sqrt(pow(k2.X-k1.X,2) + pow(k2.Y-k1.Y,2) + pow(k2.Z-k1.Z,2)) < k1.R + k2.R) && 
    sqrt(pow(k1.R-k2.R,2)) < sqrt(pow(k2.X-k1.X,2) + pow(k2.Y-k1.Y,2) + pow(k2.Z-k1.Z,2));
}
bool Kugla::DaLiSadrzi (const Kugla &k) const {
    return R+k.R > sqrt(pow(k.X-X,2) + pow(k.Y-Y,2) + pow(k.Z-Z,2));
}
double RastojanjeCentara (const Kugla &k1, const Kugla &k2){
    return sqrt(pow(k2.X-k1.X,2) + pow(k2.Y-k1.Y,2) + pow(k2.Z-k1.Z,2));
}


int main (){
    int n;
    cout << "Unesite broj kugla: "; 
    do {
        int pom;
        cin >> pom;
        if (pom<=0 || (!cin)){
            cout << "Neispravan broj kugli, unesite ponovo!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else {
            n=pom;
            break;
        }
    } while(1);

    Kugla *p = new Kugla[n];
  
    for (int i=0; i<n; i++){
        double x,y,z,r;
        for(;;){
            cout << "Unesite centar " << i+1 << ". kugle: ";
            cin >> x >> y >> z;
            if (!cin){
                cout << "Neispravan centar" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else {
                cout << "Unesite poluprecnik " << i+1 << ". kugle: "; 
                cin >> r;
                if (!cin || r<0){
                    cout << "Ilegalan poluprecnik" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                } 
                else break;
            }
        }
        p[i].PostaviCentar(x,y,z);
        p[i].PostaviPoluprecnik(r);
    }
        
    int trans_x, trans_y, trans_z;
    cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    do {
        int trans_xPom, trans_yPom, trans_zPom;
        cin >> trans_xPom >> trans_yPom>> trans_zPom;
        if (!cin){
            cout << "Neispravni parametri translacije, unesite ponovo!" << endl;
            cin.clear();
            cin.ignore(10000,'\n');
        }
        else {
            trans_x = trans_xPom;
            trans_y = trans_yPom;
            trans_z = trans_zPom;
            break;
        }
    } while(1);
    transform(p, p+n, p, [&](Kugla k) -> Kugla{
        k.Transliraj(trans_x, trans_y, trans_z);
        return k;
    });
    
    cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << endl;
    sort (p, p+n, [](Kugla k1, Kugla k2){
        return k1.DajZapreminu() < k2.DajZapreminu();
    });
    for_each(p, p+n, [](Kugla k)->void { k.Ispisi(); cout << endl; });
    
    auto najveci (max_element(p, p+n, [](const Kugla &k1, const Kugla &k2)->bool{
        return k1.DajPovrsinu() < k2.DajPovrsinu();
    }));
    cout << "Kugla sa najvecom povrsinom je: ";
    (*najveci).Ispisi();
    cout << endl;
    
    int brojac = 0;
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (DaLiSeSijeku(p[i], p[j])){
                cout << "Presjecaju se kugle: ";
                p[i].Ispisi();
                cout << endl;
                p[j].Ispisi();
                cout << endl;
                brojac++;
            }
        }
    }
    if (brojac==0) cout << "Ne postoje kugle koje se presjecaju!";
    delete[] p;
    
	return 0;
}