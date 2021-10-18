/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <tuple>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Kugla {
    double X, Y, Z, R;
public:
    explicit Kugla(double r = 0) {
        if(r < 0) throw domain_error("Ilegalan poluprecnik");
        
        X = 0;
        Y = 0;
        Z = 0;
        R = r;
    }
    Kugla(double x, double y, double z, double r = 0) {
        if(r < 0) throw domain_error("Ilegalan poluprecnik");
        
        X = x;
        Y = y;
        Z = z;
        R = r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0) {
        if(r < 0) throw domain_error("Ilegalan poluprecnik");
        
        X = get<0>(centar);
        Y = get<1>(centar);
        Z = get<2>(centar);
        R = r;
    }
    double DajX() const { return X; }
    double DajY() const { return Y; }
    double DajZ() const { return Z; }
    std::tuple<double, double, double> DajCentar() const { return make_tuple(X, Y, Z); }
    double DajPoluprecnik() const { return R; }
    double DajPovrsinu() const { return (4 * R * R * 4 * atan(1)); }
    double DajZapreminu() const { return (4 / 3 * R * R * R * 4 * atan(1)); }
    Kugla &PostaviX(double x) { X = x; }
    Kugla &PostaviY(double y) { Y = y; }
    Kugla &PostaviZ(double z) { Z = z; }
    Kugla &PostaviCentar(double x, double y, double z) { X = x; Y = y; Z = z; }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
        X = get<0>(centar);
        Y = get<1>(centar);
        Z = get<2>(centar);
    }
    Kugla &PostaviPoluprecnik(double r) {
        if(r < 0) throw domain_error("Ilegalan poluprecnik");
        
        R = r;
    }
    void Ispisi() const {
        cout << "{(" << X << "," << Y << "," << Z << ")," << R << "}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        X += delta_x;
        Y += delta_y;
        Z += delta_z;
    }
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

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2) {
    return (k1.X == k2.X && k1.Y == k2.Y && k1.Z == k2.Z && k1.R == k2.R);
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    return (k1.R == k2.R);
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2) {
    return (k1.X == k2.X && k1.Y == k2.Y && k1.Z == k2.Z);
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2) {
    return (k1.R + k2.R == sqrt(pow(k1.X - k2.X, 2) + pow(k1.Y - k2.Y, 2) + pow(k1.Z - k2.Z, 2)));
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2) {
    return (sqrt(pow(k1.R - k2.R, 2)) == sqrt(pow(k1.X - k2.X, 2) + pow(k1.Y - k2.Y, 2) + pow(k1.Z - k2.Z, 2)));
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2) {
    return (sqrt(pow(k1.X - k2.X, 2) + pow(k1.Y - k2.Y, 2) + pow(k1.Z - k2.Z, 2)) < (k1.R + k2.R));
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2) {
    return (sqrt(pow(k1.X - k2.X, 2) + pow(k1.Y - k2.Y, 2) + pow(k1.Z - k2.Z, 2)) < (k1.R + k2.R) &&
        sqrt(pow(k1.R - k2.R, 2)) < sqrt(pow(k1.X - k2.X, 2) + pow(k1.Y - k2.Y, 2) + pow(k1.Z - k2.Z, 2)));
}
bool Kugla::DaLiSadrzi(const Kugla &k) const {
    return ((R + k.R) > sqrt(pow(k.X - X, 2) + pow(k.Y - Y, 2) + pow(k.Z - Z, 2)));
}
    
double RastojanjeCentara(const Kugla &k1, const Kugla &k2) {
    return sqrt(pow(k1.X - k2.X, 2) + pow(k1.Y - k2.Y, 2) + pow(k1.Z - k2.Z, 2));
}

int main ()
{
    int n;
    cout << "Unesite broj kugla: ";
    cin >> n;
    vector<shared_ptr<Kugla>> kugle;
    for(int i = 0; i < n; i++) {
        cout << "Unesite centar " << i + 1 << ". kugle: ";
        double x, y, z, r;
        cin >> x >> y >> z;
        cout << "Unesite poluprecnik " << i + 1 << ". kugle: ";
        cin >> r;
        try {
            Kugla k(x, y, z, r);
            kugle.push_back(make_shared<Kugla>(x, y, z, r));
        } catch(domain_error e) {
            cout << e.what() << endl;
            i--;
        }
    }
    double dx, dy, dz;
    cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    cin >> dx >> dy >> dz;
    //transform(kugle.begin(), kugle.end(), kugle.begin(), [&](Kugla k)->Kugla 
    //    { k.Transliraj(dx, dy, dz); return k; });
    for(int i = 0; i < kugle.size(); i++) {
        kugle[i]->Transliraj(dx, dy, dz);
    }
    cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << endl;
    sort(kugle.begin(), kugle.end(), [](shared_ptr<Kugla> k1, shared_ptr<Kugla> k2) { return k1->DajZapreminu() < k2->DajZapreminu(); });
    
    for_each(kugle.begin(), kugle.end(), [](shared_ptr<Kugla> k)->void { k->Ispisi(); cout << endl; });
    auto najvecaPovrsina(max_element(kugle.begin(), kugle.end(), [](const Kugla &k1, const Kugla &k2)->bool { return k1.DajPovrsinu() < k2.DajPovrsinu(); }));
    cout << "Kugla sa najvecom povrsinom je: ";
    
	return 0;
}
