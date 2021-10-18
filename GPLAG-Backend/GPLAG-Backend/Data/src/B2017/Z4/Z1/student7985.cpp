/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <memory> //pametni pok
#include <vector>
#include <tuple>
#include <cmath>
using std::domain_error;
using std::make_tuple;
using std::make_shared;
using std::shared_ptr;
using std::transform;
using std::for_each;
using std::vector;
using std::tuple;
using std::sort;
using std::cout;
using std::endl;
using std::sqrt;
using std::fabs;
using std::get;
using std::cin;
typedef tuple<double, double, double> Tapl;
const double PI(4*std::atan(1));
const long double EPS(10e-11);

class Kugla{
    double x, y, z, r;
    static void ProvjeriPoluprecnik(double r){ if(r < 0) throw domain_error("Ilegalan poluprecnik\n"); }
    static bool Jednako(double a, double b){
        return fabs(a-b) <= EPS*(fabs(a)+fabs(b));
    }
    static bool JednakiTaplovi(Tapl a, Tapl b){
        return Jednako(get<0>(a), get<0>(b)) && Jednako(get<1>(a), get<1>(b)) && Jednako(get<2>(a), get<2>(b));
    }
  public:
    explicit Kugla(double r = 0): x(0), y(0), z(0) {
        ProvjeriPoluprecnik(r);
        this->r = r;
    }
    Kugla(double x, double y, double z, double r = 0) : x(x), y(y), z(z) {
        ProvjeriPoluprecnik(r);
        Kugla::r = r;
    }
    explicit Kugla(const Tapl &centar, double r = 0) : x(get<0>(centar)), y(get<1>(centar)), z(get<2>(centar)) {
        ProvjeriPoluprecnik(r);
        Kugla::r = r;
    }
    double DajX() const { return x; }
    double DajY() const { return y; }
    double DajZ() const { return z; }
    Tapl DajCentar() const { return make_tuple(x, y, z); }
    double DajPoluprecnik() const { return r; }
    double DajPovrsinu() const { return 4*DajPoluprecnik()*DajPoluprecnik()*PI; }
    double DajZapreminu() const { return DajPovrsinu()/3*DajPoluprecnik(); }
    Kugla& PostaviX(double xx) { x = xx; return *this; }
    Kugla& PostaviY(double yy) { y = yy; return *this; }
    Kugla& PostaviZ(double zz) { z = zz; return *this; }
    Kugla& PostaviCentar(double xx, double yy, double zz){ x = xx; y = yy; z = zz; return *this; }
    Kugla& PostaviCentar(const Tapl &centar) { 
        x = get<0>(centar);
        y = get<1>(centar);
        z = get<2>(centar);
        return *this;
    }
    Kugla& PostaviPoluprecnik(double rr){
        ProvjeriPoluprecnik(rr);
        r = rr;
        return *this;
    }
    void Ispisi() const {
        cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}" << endl;
    }
    void Transliraj(double deltax, double deltay, double deltaz){
        x += deltax; y += deltay; z += deltaz;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
        return DaLiSuKoncentricne(k1, k2) && DaLiSuPodudarne(k1, k2);
    }
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){ 
        return Jednako(k1.DajPoluprecnik(), k2.DajPoluprecnik());
    }
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
        return JednakiTaplovi(k1.DajCentar(), k2.DajCentar());
    }
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
        return Jednako(RastojanjeCentara(k1, k2), k1.r + k2.r);
    }
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
        return !DaLiSuIdenticne(k1, k2) && RastojanjeCentara(k1, k2) < k1.r + k2.r ; //dodati** &&..
    }
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
        if(DaLiSuIdenticne(k1, k2)) return true;
        return RastojanjeCentara(k1, k2) < k1.r + k2.r;
    }
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
        if(DaLiSuIdenticne(k1, k2)) return true;
        double d(RastojanjeCentara(k1, k2));
        return d < k1.r + k2.r && d > fabs(k1.r - k2.r);
    }
    bool DaLiSadrzi(const Kugla &kk) const{
        double d(RastojanjeCentara(*this, kk));
        return d < (*this).r + kk.r && d <= fabs((*this).r - kk.r);
    }
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
        return sqrt((k1.DajX()-k2.DajX())*(k1.x - k2.x) + (k1.y - k2.y)*(k1.y - k2.y) + (k1.z-k2.z)*(k1.z - k2.z));
    }
};

typedef shared_ptr<Kugla> Pametni;
void Oporavi(){ cin.clear(); cin.ignore(10000, '\n'); }

int main (){
    int n(0);
    cout << "Unesite broj kugla: ";
    cin >> n;
    while(n <= 0 || !cin) {
        Oporavi();
        cout << "Neispravan broj kugli, unesite ponovo!" << endl;
        cin >> n;
    }
    vector<Pametni> vec;
    for(int i=0; i<n; i++){
        double a, b, c;
        cout << "Unesite centar " << i+1 << ". kugle: ";
        cin >> a >> b >> c;
        if(!cin || (cin.peek() != ' ' && cin.peek() != '\n')) {  //**
            Oporavi();
            cout << "Neispravan centar" << endl;
            i--; 
            continue; 
        }
        double r;
        cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
        cin >> r;
        try{
            if(r < 0 || !cin) throw domain_error("Ilegalan poluprecnik\n");
            try{
                vec.emplace_back(make_shared<Kugla>(Kugla(a, b, c, r)));
            }
            catch(...){
                cout << "Nedovoljno memorije"; //**
                n = i; //**
            }
        }
        catch(domain_error er){
            cout << er.what();
            Oporavi();
            i--;
        }
        
    }
    double dx, dy, dz;
    cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    do {
        cin >> dx >> dy >> dz;
        if(cin) break;
        Oporavi();
        cout << "Neispravni parametri translacije, unesite ponovo!" << endl;
    } while(1);
    transform(vec.begin(), vec.end(), vec.begin(), [dx, dy, dz](Pametni pok){
        pok->Transliraj(dx, dy, dz);
        return pok;
    });
    sort(vec.begin(), vec.end(), [](Pametni pok1, Pametni pok2){
        return pok1->DajZapreminu() < pok2->DajZapreminu();
    });
    cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << endl; //***???!??!?! obavljene
    for_each(vec.begin(), vec.end(), [](Pametni pok){
        pok->Ispisi();
    });
    cout << "Kugla sa najvecom povrsinom je: ";
    (*max_element(vec.begin(), vec.end(), [](Pametni pok1, Pametni pok2){
        return  pok2->DajPovrsinu() > pok1->DajPovrsinu();
    }))->Ispisi(); 
    
    int i(1), br(0);
    for_each(vec.begin(), vec.end(), [&vec, &i, &br](Pametni pok1){
        for_each(vec.begin() + i, vec.end(), [&pok1, &i, &br](Pametni pok2){
            if(DaLiSeSijeku(*pok1, *pok2)) {
                br++;
                cout << "Presjecaju se kugle: "; 
                pok1->Ispisi();
                pok2->Ispisi();
            }
        });
        i++;
    });
    if(!br) cout << "Ne postoje kugle koje se presjecaju!" << endl;
    
    
	return 0;
}
