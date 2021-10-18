#include <iostream>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

typedef std::pair<double, double> Tacka;
constexpr double EPSILON = 0.00000000001;

class Trougao{
    Tacka tjemena[3];
    void IspravanIndeks(int indeks) const;
    void PreostaleDvije(int indeks, Tacka &prva, Tacka &druga) const;
    void PreostaliIndeksi(int indeks, int &a, int &b) const;
    static double VratiUgaoTacaka(Tacka centar, Tacka prva, Tacka druga);
    void RotirajTacku(Tacka &t, const Tacka &r, double ugao){
        double prva(t.first);
        t.first=r.first+(t.first-r.first)*cos(ugao) - (t.second-r.second)*sin(ugao);
        t.second=r.second+(prva-r.first)*sin(ugao) + (t.second-r.second)*cos(ugao);
    }
    void SkalirajTacku(Tacka &t, const Tacka &r, double k){
        t.first=r.first + k*(t.first-r.first);
        t.second=r.second+k*(t.second-r.second);
    }
    static bool DaLiSuIste(const Tacka &t1, const Tacka &t2) {
        return fabs(t1.first-t2.first)<EPSILON and fabs(t1.second-t2.second)<EPSILON;
    }
   public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        Postavi(t1,t2,t3);
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const;
    Tacka DajCentar() const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    double DajObim() const;
    double DajPovrsinu() const;
    bool DaLiJePozitivnoOrijentiran() const;
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

double Trougao::VratiUgaoTacaka(Tacka prva, Tacka centar, Tacka druga){
        try{
            Trougao tr(prva,centar,druga);
            return tr.DajUgao(2);
        }
        catch(std::domain_error){ //kolinearne
            return 4*atan(1);
        }
}
    
void Trougao::PreostaliIndeksi(int indeks, int &a, int &b) const{
    if(indeks==1){
        a=2; b=3;
    }
    if(indeks==2){
        a=1; b=3;
    }
    if(indeks==3){
        a=1; b=2;
    }
}

void Trougao::PreostaleDvije(int indeks, Tacka &prva, Tacka &druga) const {
    if(indeks==1){
        prva=tjemena[1]; druga=tjemena[2];
    }
    if(indeks==2){
        prva=tjemena[0]; druga=tjemena[2];
    }
    if (indeks==3){
        prva=tjemena[0]; druga=tjemena[1];
    }
}

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        tjemena[0]=t1; tjemena[1]=t2; tjemena[2]=t3;
}

void Trougao::IspravanIndeks(int indeks) const{
    if(indeks<1 or indeks>3)
        throw std::range_error("Nekorektan indeks");
}
void Trougao::Postavi(int indeks, const Tacka &t){
    IspravanIndeks(indeks);
    if(indeks==1 and Orijentacija(t,tjemena[1],tjemena[2])==0) 
        throw std::domain_error("Nekorektne pozicije tjemena");
    else if(indeks==2 and Orijentacija(tjemena[0],t,tjemena[1])==0)
        throw std::domain_error("Nekorektne pozicije tjemena");
    else if(indeks==3 and Orijentacija(tjemena[0],tjemena[1],t)==0)
        throw std::domain_error("Nekorektne pozicije tjemena");
    tjemena[indeks-1]=t;
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double rez (t1.first*(t2.second - t3.second) - t2.first*(t1.second-t3.second)+ t3.first*(t1.second-t2.second));
    if(fabs(rez)<EPSILON) return 0;
    if(rez>0) return 1;
    else return -1;
}

Tacka Trougao::DajTjeme(int indeks) const {
    IspravanIndeks(indeks);
    return tjemena[indeks-1];
}

double Trougao::DajStranicu(int indeks) const{
    IspravanIndeks(indeks);
    Tacka t1,t2;
    PreostaleDvije(indeks,t1,t2);
    return sqrt(pow(t1.first-t2.first,2)+pow(t1.second-t2.second,2));
}

double Trougao::DajUgao(int indeks) const{
    IspravanIndeks(indeks);
    int t2,t3;
    PreostaliIndeksi(indeks,t2,t3);
    double a(DajStranicu(indeks)),b(DajStranicu(t2)),c(DajStranicu(t3));
    return acos((b*b+c*c-a*a)/(2*b*c));
}

Tacka Trougao::DajCentar() const{
    return  {(tjemena[0].first + tjemena[1].first + tjemena[2].first)/3, (tjemena[0].second + tjemena[1].second + tjemena[2].second)/3};
}

double Trougao::DajObim() const {
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}

double Trougao::DajPovrsinu() const {
    return fabs(tjemena[0].first*(tjemena[1].second - tjemena[2].second) - tjemena[1].first*(tjemena[0].second-tjemena[2].second)+ tjemena[2].first*(tjemena[0].second-tjemena[1].second))/2;
}

bool Trougao::DaLiJePozitivnoOrijentiran() const{
    return Orijentacija(tjemena[0],tjemena[1],tjemena[2])>0;
}
     
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    return Orijentacija(tjemena[0],tjemena[1],tjemena[2])
           ==Orijentacija(tjemena[0],tjemena[1],t)
           ==Orijentacija(tjemena[1],tjemena[2],t)
           ==Orijentacija(tjemena[2],tjemena[0],t);
}

void Trougao::Ispisi() const {
    std::cout<<"(("<<tjemena[0].first<<","<<tjemena[0].second<<"),("
             <<tjemena[1].first<<","<<tjemena[1].second<<"),("
             <<tjemena[2].first<<","<<tjemena[2].second<<"))";
}

void Trougao::Transliraj(double delta_x, double delta_y){
    tjemena[0].first+=delta_x; tjemena[0].second+=delta_y; 
    tjemena[1].first+=delta_x; tjemena[1].second+=delta_y; 
    tjemena[2].first+=delta_x; tjemena[2].second+=delta_y; 
}

void Trougao::Centriraj(const Tacka &t){
    Tacka c(DajCentar());
    double delta_x=t.first-c.first;
    double delta_y=t.second-c.second;
    Transliraj(delta_x,delta_y);
}

void Trougao::Rotiraj(const Tacka &t, double ugao){
    RotirajTacku(tjemena[0],t,ugao);
    RotirajTacku(tjemena[1],t,ugao);
    RotirajTacku(tjemena[2],t,ugao);
}

void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(fabs(faktor)<EPSILON) throw std::domain_error("Nekorektan faktor skaliranja");
    SkalirajTacku(tjemena[0],t,faktor);
    SkalirajTacku(tjemena[1],t,faktor);
    SkalirajTacku(tjemena[2],t,faktor);
    
}
inline void Trougao::Rotiraj(double ugao){
    Rotiraj(DajCentar(),ugao);
}

inline void Trougao::Skaliraj(double faktor){
    Skaliraj(DajCentar(),faktor);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
   bool prva(Trougao::DaLiSuIste(t1.tjemena[0],t2.tjemena[0]) or Trougao::DaLiSuIste(t1.tjemena[0],t2.tjemena[1]) or Trougao::DaLiSuIste(t1.tjemena[0],t2.tjemena[2]));
   bool druga(Trougao::DaLiSuIste(t1.tjemena[1],t2.tjemena[0]) or Trougao::DaLiSuIste(t1.tjemena[1],t2.tjemena[1]) or Trougao::DaLiSuIste(t1.tjemena[1],t2.tjemena[2]));
   bool treca(Trougao::DaLiSuIste(t1.tjemena[2],t2.tjemena[0]) or Trougao::DaLiSuIste(t1.tjemena[2],t2.tjemena[1]) or Trougao::DaLiSuIste(t1.tjemena[2],t2.tjemena[2]));
   return prva and druga and treca;
}

bool JednakiDouble(double a, double b){
    if(fabs(a-b)<EPSILON) return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    std::vector<double> stranice1(3),stranice2(3),uglovi1(3),uglovi2(3);
    std::vector<int> indeksi;
    for(int i=0; i<3; i++){
        stranice1.at(i)=t1.DajStranicu(i+1);
        stranice2.at(i)=t2.DajStranicu(i+1);
        uglovi1.at(i)=t1.DajUgao(i+1);
        uglovi2.at(i)=t2.DajUgao(i+1);;
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(JednakiDouble(stranice1.at(i),stranice2.at(j)) and JednakiDouble(uglovi1.at(i),uglovi2.at(j))){
                if(std::find(indeksi.begin(),indeksi.end(),j)==indeksi.end())
                    indeksi.push_back(j);
            }
        }
    }
    if(indeksi.size()!=3) return false;
    return t1.Orijentacija(t1.tjemena[0],t1.tjemena[1],t1.tjemena[2]) 
    == t2.Orijentacija(t2.tjemena[indeksi[0]],t2.tjemena[indeksi[1]],t2.tjemena[indeksi[2]]);
}
    
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    std::vector<double> uglovi1(3),uglovi2(3);
    std::vector<int> indeksi;
    for(int i=0; i<3; i++){
        uglovi1.at(i)=t1.DajUgao(i+1);
        uglovi2.at(i)=t2.DajUgao(i+1);;
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(JednakiDouble(uglovi1.at(i),uglovi2.at(j))){
                if(std::find(indeksi.begin(),indeksi.end(),j)==indeksi.end())
                    indeksi.push_back(j);
            }
        }
    }
    if(indeksi.size()!=3) return false;
    return t1.Orijentacija(t1.tjemena[0],t1.tjemena[1],t1.tjemena[2]) 
    == t2.Orijentacija(t2.tjemena[indeksi.at(0)],t2.tjemena[indeksi.at(1)],t2.tjemena[indeksi.at(2)]);
}

template <typename T, typename G>
void IspisujParove(T funkcija, const G &trouglovi, string tip_fje){
    bool ima(false), pisi(true);
    for(int i=0; i<int(trouglovi.size()-1); i++){
        for(int j=i+1; j<trouglovi.size(); j++){
            if(funkcija(*(trouglovi.at(i)), *(trouglovi.at(j)) )){
                ima=true;
                if(pisi){
                    cout<<"Parovi "+tip_fje+" trouglova: "<<endl;
                    pisi=false;
                }
                trouglovi.at(i)->Ispisi();
                cout<<" i ";
                trouglovi.at(j)->Ispisi();
                cout<<endl;
            }
        }
    }
    if(!ima) cout<<"Nema "+tip_fje+" trouglova!"<<endl;
}

int main ()
{
    int n;
    cout<<"Koliko zelite kreirati trouglova: ";
    cin>>n;
    try{
        std::vector<std::shared_ptr<Trougao>> trouglovi(n);
        for(int i=0; i<n; i++){
            try{
                cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
                double x1,y1,x2,y2,x3,y3;
                cin>>x1>>y1>>x2>>y2>>x3>>y3;
                Tacka t1(x1,y1),t2(x2,y2),t3(x3,y3);
                trouglovi.at(i)=std::make_shared<Trougao>(t1,t2,t3);
            }
            catch(std::domain_error e){
                cout<<e.what()<<", ponovite unos!"<<endl;
                i--;
            }
        }
        cout<<"Unesite vektor translacije (dx dy): ";
        double dx,dy,fi,faktor;
        cin>>dx>>dy;
        cout<<"Unesite ugao rotacije: ";
        cin>>fi;
        cout<<"Unesite faktor skaliranja: ";
        cin>>faktor;
        auto trans_trouglovi(trouglovi);
        std::transform(trouglovi.begin(),trouglovi.end(), trouglovi.begin(), //SKALIRANJE,ROTIRANJE..
        [dx,dy,fi,faktor](std::shared_ptr<Trougao> p1){
            p1->Transliraj(dx,dy); 
            p1->Rotiraj(fi); 
            p1->Skaliraj(p1->DajTjeme(1),faktor); 
            return p1;
        });
        cout<<"Trouglovi nakon obavljenih transformacija: "<<endl;
        std::sort(trouglovi.begin(),trouglovi.end(),
        [](std::shared_ptr<Trougao> p1,std::shared_ptr<Trougao> p2){ //SORTIRANJE
            return p1->DajPovrsinu()<p2->DajPovrsinu();
        });
        
        std::for_each(trouglovi.begin(),trouglovi.end(), //ISPIS
        [](std::shared_ptr<Trougao> p1){p1->Ispisi(); cout<<endl;});
        
        cout<<"Trougao sa najmanjim obimom: ";
        auto p(std::min_element(trouglovi.begin(),trouglovi.end(),
        [](std::shared_ptr<Trougao> p1,std::shared_ptr<Trougao> p2){return p1->DajObim()<p2->DajObim(); }));
        if(p!=trouglovi.end()) (**p).Ispisi();
        cout<<endl;
        IspisujParove(DaLiSuIdenticni,trouglovi,"identicnih");
        IspisujParove(DaLiSuPodudarni,trouglovi,"podudarnih");
        IspisujParove(DaLiSuSlicni,trouglovi,"slicnih");
    }
    
    catch(std::bad_alloc){
        cout<<"Problemi s memorijom";
    }
	return 0;
}