/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#define PI 4*atan(1);
using namespace std;

class NepreklapajucaKugla {
    double X, Y, Z, R;
public:  
    explicit NepreklapajucaKugla(double r = 0);
    NepreklapajucaKugla(double x, double y, double z, double r = 0);
    explicit NepreklapajucaKugla(const tuple<double, double, double> &centar, double r = 0);
    double DajX() const { return X; }
    double DajY() const { return Y; }
    double DajZ() const { return Z; }
    tuple<double, double, double> DajCentar() const;
    double DajPoluprecnik() const { return R; }
    double DajPovrsinu() const { return 4*R*R*PI; }
    double DajZapreminu() const { return (4/3.)*R*R*R*PI; }
    
    NepreklapajucaKugla &PostaviX(double x){ X=x; }
    NepreklapajucaKugla &PostaviY(double y){ Y=y; }
    NepreklapajucaKugla &PostaviZ(double z){ Z=z; }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z){ X=x; Y=y; Z=z; }
    NepreklapajucaKugla &PostaviCentar(const tuple<double, double, double> &centar);
    NepreklapajucaKugla &PostaviPoluprecnik(double r) {
        if (r<0) throw domain_error ("Ilegalan poluprecnik");
        R=r;
    }
    
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y, double delta_z);
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const;
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};

NepreklapajucaKugla::NepreklapajucaKugla(double r){
    if (r<0) throw domain_error ("Ilegalan poluprecnik");
    R = r; X=0; Y=0; Z=0;
}
NepreklapajucaKugla::NepreklapajucaKugla (double x, double y, double z, double r){
    if (r<0) throw domain_error ("Ilegalan poluprecnik");
    X = x; Y = y; Z = z; R = r; 
}
void NepreklapajucaKugla::Ispisi() const {
    cout << "{(" << X << "," << Y << "," << Z << ")," << R << "}";
}
void NepreklapajucaKugla::Transliraj(double delta_x, double delta_y, double delta_z){
    X += delta_x; Y+=delta_y; Z+=delta_z;
}
bool DaLiSuIdenticne (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return (k1.R == k2.R && k1.X == k2.X && k1.Y == k2.Y && k1.Z == k2.Z);
}
bool DaLiSuPodudarne (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
    return k1.R == k2.R;
}
bool DaLiSuKoncentricne (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return k1.X == k2.X && k1.Y == k2.Y && k1.Z == k2.Z;
}
bool DaLiSeDodirujuIzvana (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return k1.R+k2.R == sqrt(pow(k2.X-k1.X,2) + pow(k2.Y-k1.Y,2) + pow(k2.Z-k1.Z,2));
}
bool DaLiSeDodirujuIznutra (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return sqrt(pow(k1.R-k2.R,2)) == sqrt(pow(k2.X-k1.X,2) + pow(k2.Y-k1.Y,2) + pow(k2.Z-k1.Z,2)); 
}
bool DaLiSePreklapaju (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return sqrt(pow(k2.X-k1.X,2) + pow(k2.Y-k1.Y,2) + pow(k2.Z-k1.Z,2)) < k1.R + k2.R;
}
bool DaLiSeSijeku (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return (sqrt(pow(k2.X-k1.X,2) + pow(k2.Y-k1.Y,2) + pow(k2.Z-k1.Z,2)) < k1.R + k2.R) && 
    sqrt(pow(k1.R-k2.R,2)) < sqrt(pow(k2.X-k1.X,2) + pow(k2.Y-k1.Y,2) + pow(k2.Z-k1.Z,2));
}
bool NepreklapajucaKugla::DaLiSadrzi (const NepreklapajucaKugla &k) const {
    return R+k.R > sqrt(pow(k.X-X,2) + pow(k.Y-Y,2) + pow(k.Z-Z,2));
}
double RastojanjeCentara (const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return sqrt(pow(k2.X-k1.X,2) + pow(k2.Y-k1.Y,2) + pow(k2.Z-k1.Z,2));
}


int main (){
    int n;
    cout << "Unesite broj NepreklapajucaKugla: ";
    do {
        int x;
        cin >> x;
        if (x<=0 || (!cin)){
            cout << "Neispravan broj kugli, unesite ponovo!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else {
            n=x;
            break;
        }
        
    } while(1);
    /*
    for (;;){
        double x;
        cin >> x;
        if (x>0){
            n=x;
            break;
        }
        cout << "Neispravan broj kugli, unesite ponovo!" << endl;
    }
    */
    
    
    
    
    NepreklapajucaKugla *p = new NepreklapajucaKugla[n];
    for (int i=0; i<n; i++){
        double x,y,z,r;
        cout << "Unesite centar " << i+1 << ". kugle: ";
        cin >> x >> y >> z;
        p[i].PostaviCentar(x,y,z);
        cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        for (;;){
            double x;
            cin >> x;
            if (x>=0){
                r=x;
                break;
            }
            cout << "Ilegalan poluprecnik" << endl;
        }
        p[i].PostaviPoluprecnik(r);
    }
    
    
    
    
    int trans_x, trans_y, trans_z;
    cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    cin >> trans_x >> trans_y >> trans_z;
    transform(p, p+n, p, [&](NepreklapajucaKugla k) -> NepreklapajucaKugla{
        k.Transliraj(trans_x, trans_y, trans_z);
        return k;
    });
    
    cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << endl;
    sort (p, p+n, [](NepreklapajucaKugla k1, NepreklapajucaKugla k2){
        return k1.DajZapreminu() < k2.DajZapreminu();
    });
    for_each(p, p+n, [](NepreklapajucaKugla k)->void {k.Ispisi(); cout << endl; });
    
    auto najveci (max_element(p, p+n, [](const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2)->bool{
        return k1.DajPovrsinu() < k2.DajPovrsinu();
    }));
    cout << "NepreklapajucaKugla sa najvecom povrsinom je: ";
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