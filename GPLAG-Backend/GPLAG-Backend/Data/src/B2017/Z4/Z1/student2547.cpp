#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>
#include <new>
#include <tuple>

using namespace std;

#define e pow(10,-10)
#define pi 4*atan(1)

int br(1);
int pr(0);

class Kugla {
    double x,y,z,r;
    public:
    explicit Kugla(double r = 0) {
        Kugla::r=r; x=0; y=0; z=0;
    }
    Kugla(double x, double y, double z, double r = 0) {
        Kugla::r=r; Kugla::x=x; Kugla::y=y; Kugla::z=z;
    }
    explicit Kugla(const tuple<double, double, double> &centar, double r = 0) {
        Kugla::r=r; x=get<0>(centar); y=get<1>(centar); z=get<2>(centar);
    }
    double DajX() const {
        return x;
    }
    double DajY() const {
        return y;
    }
    double DajZ() const {
        return z;
    }
    tuple<double, double, double> DajCentar() const {
        tuple<double, double, double> centar;
        get<0>(centar)=x; get<1>(centar)=y; get<2>(centar)=z;
        return centar;
    }
    double DajPoluprecnik() const {
        return r;
    }
    double DajPovrsinu() const {
        return 4*r*r*pi;
    }
    double DajZapreminu() const {
        return 2*(r*r*r*pi)/3;
    }
    Kugla &PostaviX(double x) {
        this->x=x;
        return *this;
    }
    Kugla &PostaviY(double y) {
        this->y=y;
        return *this;
    }
    Kugla &PostaviZ(double z) {
        this->z=z;
        return *this;
    }
    Kugla &PostaviCentar(double x, double y, double z) {
        this->x=x; this->y=y; this->z=z;
        return *this;
    }
    Kugla &PostaviCentar(const tuple<double, double, double> &centar) {
        x=get<0>(centar); y=get<1>(centar); z=get<2>(centar);
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) {
        Kugla::r=r;
        return *this;
    }
    void Ispisi() const {
        cout << "{(" << x << "," << y << "," << z << ")," << r << "}"; 
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        x+=delta_x; y+=delta_y; z+=delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
        if(fabs(k1.x-k2.x)<e*(fabs(k1.x)+fabs(k2.x)) && fabs(k1.y-k2.y)<e*(fabs(k1.y)+fabs(k2.y)) && fabs(k1.z-k2.z)<e*(fabs(k1.z)+fabs(k2.z)) && fabs(k1.r-k2.r)<e*(fabs(k1.r)+fabs(k2.r))) return true;
        return false;
    }
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
        if(fabs(k1.r-k2.r)<e*(fabs(k1.r)+fabs(k2.r))) return true;
        return false;
    }
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
        if(fabs(k1.x-k2.x)<e*(fabs(k1.x)+fabs(k2.x)) && fabs(k1.y-k2.y)<e*(fabs(k1.y)+fabs(k2.y)) && fabs(k1.z-k2.z)<e*(fabs(k1.z)+fabs(k2.z))) return true;
        return false;
    }
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
        double d(RastojanjeCentara(k1,k2));
        Kugla veca, manja;
        if(k1.r<=k2.r) manja=k1, veca=k2;
        else manja=k2, veca=k1;
        if(fabs(manja.r+veca.r-d)<e*(fabs(manja.r+veca.r)+fabs(d))) return true;
        return false;
    }
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
        double d(RastojanjeCentara(k1,k2));
        Kugla veca, manja;
        if(k1.r<=k2.r) manja=k1, veca=k2;
        else manja=k2, veca=k1;
        if(fabs(manja.r+d-veca.r)<e*(fabs(manja.r+d)+fabs(veca.r))) return true;
        return false;
    }
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
        if(k1.r+k2.r<RastojanjeCentara(k1,k2) || DaLiSeDodirujuIzvana(k1,k2)) return false;
        return true;
    }
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
        double d(RastojanjeCentara(k1,k2));
        if(d<k1.r+k2.r && !(DaLiSeDodirujuIznutra(k1,k2)) && !(DaLiSuKoncentricne(k1,k2)) && !(DaLiSeDodirujuIzvana(k1,k2))) return true;
        return false;
    }
    bool DaLiSadrzi(const Kugla &k) const {
        double d(RastojanjeCentara(*this,k));
        if(k.r+d<this->r) return true;
        return false;
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
        return sqrt( (k2.x-k1.x)*(k2.x-k1.x) + (k2.y-k1.y)*(k2.y-k1.y) + (k2.z-k1.z)*(k2.z-k1.z) );
    }
};

int main () {
    cout << "Unesite broj kugla: ";
    int n(0);
    while(n<1) {
        cin >> n;
        if(cin.fail() || n<1){
            cin.clear();
            cin.ignore(10000, '\n'); 
            n=0;
            cout << "Neispravan broj kugli, unesite ponovo!" << endl;;
        }
    }
    vector<shared_ptr<Kugla>> vektor_ptr;
    int i(0);
    
    while(i!=n) {
        double x,y,z,r;
        cout << "Unesite centar " << i+1 << ". kugle: ";
        cin >> x >> y >> z;
        int pom(0);
        while(pom==0) {
            if(cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n'); 
                cout << "Neispravan centar" << endl << "Unesite centar " << i+1 << ". kugle: ";
                cin >> x >> y >> z;
            }
            else pom++;
        }
        
        cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        cin >> r;
        if(cin.fail() || r<0){
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Ilegalan poluprecnik" << endl;
            continue;
        }
        
        shared_ptr<Kugla> din_kugla(new Kugla(x,y,z,r));
        vektor_ptr.push_back(din_kugla);
        i++;
    }
    cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    cin.clear();
    cin.ignore(10000, '\n');
    double dx,dy,dz;
    cin >> dx >> dy >> dz;
    int pom(0);
    while(pom==0) {
        if(cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n'); 
            cout << "Neispravni parametri translacije, unesite ponovo!" << endl;
            pom=0;
            cin >> dx >> dy >> dz;
        }
        else pom++;
    }
    transform(vektor_ptr.begin(), vektor_ptr.end(), vektor_ptr.begin(),[dx,dy,dz](shared_ptr<Kugla> a){
        (*a).Transliraj(dx,dy,dz); 
        return a; });
    sort(vektor_ptr.begin(), vektor_ptr.end(),[](shared_ptr<Kugla> k1, shared_ptr<Kugla> k2) -> bool {
        if((*k1).DajZapreminu()<(*k2).DajZapreminu()) return false;
        return true;
    } );
    cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << endl;
    for_each(vektor_ptr.begin(), vektor_ptr.end(), [] (shared_ptr<Kugla> k) {
	    (*k).Ispisi();
	    cout << endl;
	} );
	auto najveca=max_element(vektor_ptr.begin(), vektor_ptr.end(), [] (shared_ptr<Kugla> k1, shared_ptr<Kugla> k2) {
	    if((*k1).DajPovrsinu()<(*k2).DajPovrsinu()) return true;
	    return false;
	});
	cout << "Kugla sa najvecom povrsinom je: ";
	(**najveca).Ispisi();
	
    for_each(vektor_ptr.begin(), vektor_ptr.end(), [vektor_ptr](shared_ptr<Kugla> a){
        for_each(vektor_ptr.begin()+br, vektor_ptr.end(), [a](shared_ptr<Kugla> b){
            if(DaLiSeSijeku(*a,*b)) {
                cout << endl << "Presjecaju se kugle: "; (*a).Ispisi(); cout << endl; (*b).Ispisi();
                pr++;
            }
        });
        br++;
    });
    if(pr==0) cout << endl << "Ne postoje kugle koje se presjecaju!";
	return 0;
}