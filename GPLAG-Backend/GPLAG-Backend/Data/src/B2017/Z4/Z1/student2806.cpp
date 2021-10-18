/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <memory>
#include <stdexcept>
using namespace std;
typedef tuple<double,double,double> Tacka;
double const PI (4*atan(1));

const double eps(1e-10);

class Kugla{
    Tacka C;
    double poluprecnik;
    static bool Jednake(double x, double y);
    static bool Jednake(Tacka c1, Tacka c2);
    static bool Dodiruju(Kugla k1, Kugla k2);
    static bool Preklop(Kugla k1, Kugla k2);
    public:
    explicit Kugla(double r = 0) {
        PostaviPoluprecnik(r);
        get<0>(C)=0; get<1>(C)=0; get<2>(C)=0;
    } 
    Kugla(double x, double y, double z, double r = 0){
    if(r<0) throw domain_error ("Ilegalan poluprecnik");
    C=make_tuple(x, y, z);
    poluprecnik=r;
} 
    explicit Kugla(const Tacka &centar, double r = 0){
    if(r<0) throw domain_error ("Ilegalan poluprecnik");
    C=centar;
    poluprecnik=r;
} 
    double DajX() const {return get<0>(C);} 
    double DajY() const{return get<1>(C);} 
    double DajZ() const {return get<2>(C);}
    Tacka DajCentar() const {return C;} 
    double DajPoluprecnik() const {return poluprecnik;} 
    double DajPovrsinu() const {return 4*PI*poluprecnik*poluprecnik;}
    double DajZapreminu() const {return (4/3.)*PI*poluprecnik*poluprecnik*poluprecnik;} 
    Kugla &PostaviX(double x) {get<0>(C)=x; return *this;} 
    Kugla &PostaviY(double y) {get<1>(C)=y; return *this;} 
    Kugla &PostaviZ(double z) {get<2>(C)=z; return *this;}
    Kugla &PostaviCentar(double x, double y, double z) {
        Tacka C;
        get<0>(C)=x; get<1>(C)=y; get<2>(C)=z; 
        return *this;
    }
    Kugla &PostaviCentar(const Tacka &centar){
        C=centar;
        return *this;
    } 
    Kugla &PostaviPoluprecnik(double r) {
        if(r<0) throw domain_error ("Ilegalan poluprecnik");
        poluprecnik=r;
        return *this;
    }
    void Ispisi() const {
        cout<<"{("<<get<0>(C)<<","<<get<1>(C)<<","<<get<2>(C)<<"),"<<poluprecnik<<"}";
    } 
    void Transliraj(double delta_x, double delta_y, double delta_z) {
        get<0>(C)+=delta_x; get<1>(C)+=delta_y; get<2>(C)+=delta_z;
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

bool Kugla::Jednake(double x, double y){
    return fabs(x-y)<eps*(fabs(x)+fabs(y));
    //if(fabs(get<0>(c1)-get<0>(c2))<eps*(fabs(get<0>(c1))+fabs(get<0>(c2))) && fabs(get<1>(c1)-get<1>(c2))<eps*(fabs(get<1>(c1))+fabs(get<1>(c2))) && fabs(get<2>(c1)-get<2>(c2))<eps*(fabs(get<2>(c1))+fabs(get<2>(c2))) && fabs(r1-r2)<eps*(fabs(r1)+fabs(r2))) return true;
    //return false;
}

bool Kugla::Jednake(Tacka c1, Tacka c2){
    if(fabs(get<0>(c1)-get<0>(c2))<eps*(fabs(get<0>(c1))+fabs(get<0>(c2))) && fabs(get<1>(c1)-get<1>(c2))<eps*(fabs(get<1>(c1))+fabs(get<1>(c2))) && fabs(get<2>(c1)-get<2>(c2))<eps*(fabs(get<2>(c1))+fabs(get<2>(c2)))) return true;
    return false;
}

bool Kugla::Dodiruju(Kugla k1, Kugla k2){
    double rastojanje, zbirpol;
    rastojanje=sqrt((get<0>(k1.DajCentar())-get<0>(k2.DajCentar())) * (get<0>(k1.DajCentar())-get<0>(k2.DajCentar())) + (get<1>(k1.DajCentar())-get<1>(k2.DajCentar())) * (get<1>(k1.DajCentar())-get<1>(k2.DajCentar())) + (get<2>(k1.DajCentar())-get<2>(k2.DajCentar())) * (get<2>(k1.DajCentar())-get<2>(k2.DajCentar())));
    zbirpol=k1.DajPoluprecnik()+k2.DajPoluprecnik();
    if(fabs(rastojanje-zbirpol)<eps*(fabs(rastojanje)+fabs(zbirpol))) return true;
    return false;
}

bool Kugla::Preklop(Kugla k1, Kugla k2){
    double rastojanje, zbirpol;
    rastojanje=sqrt((get<0>(k1.DajCentar())-get<0>(k2.DajCentar())) * (get<0>(k1.DajCentar())-get<0>(k2.DajCentar())) + (get<1>(k1.DajCentar())-get<1>(k2.DajCentar())) * (get<1>(k1.DajCentar())-get<1>(k2.DajCentar())) + (get<2>(k1.DajCentar())-get<2>(k2.DajCentar())) * (get<2>(k1.DajCentar())-get<2>(k2.DajCentar())));
    zbirpol=k1.DajPoluprecnik()+k2.DajPoluprecnik();
    if(rastojanje<zbirpol) return true;
    return false;
}

bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
  if(Kugla::Jednake(k1.DajX(), k2.DajX()) && Kugla::Jednake(k1.DajY(), k2.DajY()) && Kugla::Jednake(k1.DajZ(), k2.DajZ()) && Kugla::Jednake(k1.DajPoluprecnik(), k2.DajPoluprecnik())) return true;
  return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2) {
    return fabs(k1.DajPoluprecnik()-k2.DajPoluprecnik()<eps*(fabs(k1.DajPoluprecnik())+fabs(k2.DajPoluprecnik())));
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
    if(Kugla::Jednake(k1.DajCentar(), k2.DajCentar())) return true;
    return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
    // Pretpostavlja se da se kugle dodiruju ukoliko im rubovi (tj. sfere kojima su omeđene) imaju tačno jednu zajedničku tačku. 
    //Pri tome, dodir može biti izvana,  ili iznutra (dodir je izvana ukoliko je tim kuglama ta zajednička tačka ujedno i jedina zajednička tačka).
    if(Kugla::Dodiruju(k1, k2) && (k1.DajPoluprecnik()>k2.DajPoluprecnik() && sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())>k1.DajPoluprecnik()) || k2.DajPoluprecnik()>k1.DajPoluprecnik() && sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX())>k2.DajPoluprecnik()))) return true;
    return false;
    //not sure trebam li provjeravat jel jedina tacka
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
    if(Kugla::Dodiruju(k1, k2) && !DaLiSeDodirujuIzvana(k1,k2)) return true;
    return false;
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
    return (DaLiSeSijeku(k1,k2) || k1.DaLiSadrzi(k2) || k2.DaLiSadrzi(k1));
    //if(Kugla::Preklop(k1, k2)) return true;
    //return false;
}

bool DaLiSeSijeku (const Kugla &k1, const Kugla &k2) {
    //return ((sqrt((get<0>(k1.DajCentar())-get<0>(k2.DajCentar())) * (get<0>(k1.DajCentar())-get<0>(k2.DajCentar())) + (get<1>(k1.DajCentar())-get<1>(k2.DajCentar())) * (get<1>(k1.DajCentar())-get<1>(k2.DajCentar())) + (get<2>(k1.DajCentar())-get<2>(k2.DajCentar())) * (get<2>(k1.DajCentar())-get<2>(k2.DajCentar())))<(k1.DajPoluprecnik()+k2.DajPoluprecnik())) && (sqrt((get<0>(k1.DajCentar())-get<0>(k2.DajCentar())) * (get<0>(k1.DajCentar())-get<0>(k2.DajCentar())) + (get<1>(k1.DajCentar())-get<1>(k2.DajCentar())) * (get<1>(k1.DajCentar())-get<1>(k2.DajCentar())) + (get<2>(k1.DajCentar())-get<2>(k2.DajCentar())) * (get<2>(k1.DajCentar())-get<2>(k2.DajCentar())))>sqrt(k1.DajPoluprecnik()+k2.DajPoluprecnik()))))// return true;
    //return false;//fali jos u uslovu 
    return (sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX()) + (k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY()) + (k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ()))<(k1.DajPoluprecnik()+k2.DajPoluprecnik()) && (sqrt((k1.DajX()-k2.DajX())*(k1.DajX()-k2.DajX()) + (k1.DajY()-k2.DajY())*(k1.DajY()-k2.DajY()) + (k1.DajZ()-k2.DajZ())*(k1.DajZ()-k2.DajZ()))>((k1.DajPoluprecnik()-k2.DajPoluprecnik())*(k1.DajPoluprecnik()-k2.DajPoluprecnik()))));
}

bool Kugla::DaLiSadrzi(const Kugla &k) const {
   
    if(sqrt((get<0>(Kugla::C)-k.DajX())*(get<0>(Kugla::C)-k.DajX()) + (get<1>(Kugla::C)-k.DajY())*(get<1>(Kugla::C)-k.DajY()) + (get<2>(Kugla::C)-k.DajZ())*(get<2>(Kugla::C)-k.DajZ()))>(Kugla::poluprecnik+k.DajPoluprecnik())) return true;
    return false;
}

double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
    double d;
    d=sqrt((get<0>(k1.DajCentar())-get<0>(k2.DajCentar())) * (get<0>(k1.DajCentar())-get<0>(k2.DajCentar())) + (get<1>(k1.DajCentar())-get<1>(k2.DajCentar())) * (get<1>(k1.DajCentar())-get<1>(k2.DajCentar())) + (get<2>(k1.DajCentar())-get<2>(k2.DajCentar())) * (get<2>(k1.DajCentar())-get<2>(k2.DajCentar())));
    return d;
}

int main ()
{
    int n;
    cout<<"Unesite broj kugla: ";
    //cin>>n;
    /*while(n<=0){
        cout<<"Neispravan broj kugli, unesite ponovo!";
        cin>>n;
    }
    if(!cin){
        cout<<"Neispravan broj kugli, unesite ponovo!";
    }*/
   
    for(;;) {
        cin>>n;
        if(!cin || n<0 || n!=int(n)) cout<<"Neispravan broj kugli, unesite ponovo!"<<endl;
        else break;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    
    vector<shared_ptr<Kugla>> vek(n);
    for (int i=0; i<n; i++){
        for(;;) {
            cout<<"Unesite centar "<<i+1<<". kugle: ";
            double x, y, z;
            cin>>x>>y>>z;
            if(!cin) {
                cout<<"Neispravan centar"<<endl; //zasad
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }
            cin.clear();
            cin.ignore(10000, '\n');
            cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
            double r;
            cin>>r;
            if(!cin || r<0) cout<<"Ilegalan poluprecnik"<<endl;
            else break;
            cin.clear();
            cin.ignore(10000, '\n');
        }        
            Tacka t1=make_tuple(x, y, z);
            try{
            vek[i]=make_shared<Kugla>(t1, r);//dinamicki alociramo kuglu;
        }
        catch(domain_error izuzetak){
            cout<<izuzetak.what()<<endl;
            i--;
        }
    }
    
    double d_x, d_y, d_z;
    cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    for(;;) {
        cin>>d_x>>d_y>>d_z;
        if(!cin) cout<<"Neispravni parametri translacije, unesite ponovo!"<<endl;
        else break;
        cin.clear();
        cin.ignore(10000, '\n');
    }
    
    transform(vek.begin(), vek.end(), vek.begin(), [d_x, d_y, d_z](shared_ptr<Kugla>pok)->shared_ptr<Kugla>{pok->Transliraj(d_x, d_y, d_z); return pok;});
    sort(vek.begin(), vek.end(), [](shared_ptr<Kugla>pok1, shared_ptr<Kugla>pok2){return (pok1->DajZapreminu())<(pok2->DajZapreminu());});
    cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: "<<endl;
    for_each(vek.begin(), vek.end(), [](shared_ptr<Kugla>pok){pok->Ispisi(); cout<<endl;});
    cout<<"Kugla sa najvecom povrsinom je: ";
    auto p(max_element(vek.begin(), vek.end(), [](shared_ptr<Kugla>pok1, shared_ptr<Kugla>pok2){return (pok1->DajPovrsinu())<(pok2->DajPovrsinu());}));
    (*p)->Ispisi(); cout<<endl;
    
    /*bool presjek(false);
    for (int i=0; i<n-1; i++){
        for(int j=1; j<n; j++){
            if(DaLiSeSijeku(*vek[i], *vek[j])){
                cout<<"Presjecaju se kugle: ";
                vek[i]->Ispisi(); cout<<endl;
                vek[j]->Ispisi();
                cout<<endl;
                presjek=true;
            }
        }
    }*/
    bool presjek(false);
    for_each(vek.begin(), vek.end(), [&](shared_ptr<Kugla>k2){};) {
        //if(DaliSeSijeku(*pok, *k2)) {
            cout<<"Presjecaju se kugle: ";
            pok->Ispisi();
            k2->Ispisi();
            presjek=true;        
            
        //}
        
    }
    
    if(!presjek) cout<<"Ne postoje kugle koje se presjecaju!";
	return 0;
}

