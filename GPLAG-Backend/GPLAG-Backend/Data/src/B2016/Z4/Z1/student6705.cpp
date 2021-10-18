/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

typedef pair<double, double> Tacka;

class Trougao{
    Tacka tr1,tr2,tr3;
    static double RacunajIzraz(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    }
    public:
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3 );
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao (int indeks) const;
    Tacka DajCentar() const;
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
    friend bool DaLiSuSlicni( const Trougao &t1, const Trougao &t2);
};
Trougao::Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3){
    Postavi(t1,t2,t3);
}
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3 ){
    if(Orijentacija(t1,t2,t3)==0) throw domain_error("Nekorektne pozicije");
    tr1=t1;
    tr2=t2;
    tr3=t3;
}
void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks!=1 && indeks!=2 && indeks!=3) throw range_error("Nekorektan indeks");
    if(indeks==1) {
        try{
            Orijentacija(t,tr2,tr3);
            tr1=t;
        } catch(...){throw;}
    }
    else if(indeks==2) {
        try{
            Orijentacija(tr1,t,tr3);
            tr2=t;
        } catch(...){throw;}
    }
    else try{
            Orijentacija(tr1,tr2,t);
            tr3=t;
        } catch(...){throw;}
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double izraz=RacunajIzraz(t1,t2,t3);
    if(izraz>0) return 1;
    else if(izraz<0) return -1;
    else return 0;
}
Tacka Trougao::DajTjeme(int indeks) const{
    if(indeks==1) return tr1;
    if(indeks==2) return tr2;
    if(indeks==3) return tr3;
}
double Trougao::DajStranicu(int indeks) const{
    if(indeks==1) return sqrt((tr2.first-tr3.first)*(tr2.first-tr3.first)+(tr2.second-tr3.second)*(tr2.second-tr3.second));
    if(indeks==2) return sqrt((tr1.first-tr3.first)*(tr1.first-tr3.first)+(tr1.second-tr3.second)*(tr1.second-tr3.second));
    if(indeks==3) return sqrt((tr2.first-tr1.first)*(tr2.first-tr1.first)+(tr2.second-tr1.second)*(tr2.second-tr1.second));
}
double Trougao::DajUgao (int indeks) const{
    if(indeks==1) return acos((DajStranicu(2)+DajStranicu(3)-DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)));
    if(indeks==2) return acos((DajStranicu(1)+DajStranicu(3)-DajStranicu(2))/(2*DajStranicu(1)*DajStranicu(3)));
    if(indeks==3) return acos((DajStranicu(1)+DajStranicu(2)-DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2)));
}
Tacka Trougao::DajCentar() const{
    return pair<double,double>((tr1.first+tr2.first+tr3.first)/3,(tr1.second+tr2.second+tr3.second)/3);
}
double Trougao::DajObim() const{
    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}
double Trougao::DajPovrsinu() const{
    return 0.5*abs(RacunajIzraz(tr1,tr2,tr3));
}
bool Trougao::DaLiJePozitivnoOrijentiran() const{
    if(Orijentacija(tr1,tr2,tr3)==1) return true;
    else return false;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    if(Orijentacija(tr1,tr2,tr3)==1 && Orijentacija(tr1,tr2,t)==1 && Orijentacija(tr2, tr3, t)==1 && Orijentacija(tr3,tr1,t)==1) return true;
    else if(Orijentacija(tr1,tr2,tr3)==-1 && Orijentacija(tr1,tr2,t)==-1 && Orijentacija(tr2, tr3, t)==-1 && Orijentacija(tr3,tr1,t)==-1) return true;
    return false;
}
void Trougao::Transliraj(double delta_x, double delta_y){
    tr1.first+=delta_x;
    tr1.second+=delta_y;
    tr2.first+=delta_x;
    tr2.second+=delta_y;
    tr3.first+=delta_x;
    tr3.second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t){
    double delta_x=abs(t.first-DajCentar().first);
    double delta_y=abs(t.second-DajCentar().second);
    Transliraj(delta_x,delta_y);
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
    tr1.first=t.first+(tr1.first-t.first)*cos(ugao)-(tr1.second-t.second)*sin(ugao);
    tr1.second=t.second+(tr1.first-t.first)*sin(ugao)+(tr1.second-t.second)*cos(ugao);
    tr2.first=t.first+(tr2.first-t.first)*cos(ugao)-(tr2.second-t.second)*sin(ugao);
    tr2.second=t.second+(tr2.first-t.first)*sin(ugao)+(tr2.second-t.second)*cos(ugao);
    tr3.first=t.first+(tr3.first-t.first)*cos(ugao)-(tr3.second-t.second)*sin(ugao);
    tr3.second=t.second+(tr3.first-t.first)*sin(ugao)+(tr3.second-t.second)*cos(ugao);
}
void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(faktor==0) throw domain_error("Nekorektan faktor skaliranja");
    tr1.first=t.first+faktor*(tr1.first-t.first);
    tr1.second=t.second+faktor*(tr1.second-t.second);
    tr2.first=t.first+faktor*(tr2.first-t.first);
    tr2.second=t.second+faktor*(tr2.second-t.second);
    tr3.first=t.first+faktor*(tr3.first-t.first);
    tr3.second=t.second+faktor*(tr3.second-t.second);
    
}
void Trougao::Rotiraj(double ugao){
    Rotiraj(DajCentar(),ugao);
}
void Trougao::Skaliraj(double faktor){
    Skaliraj(DajCentar(),faktor);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    vector<pair<double,double>>v1{t1.tr1,t1.tr2,t1.tr3},v2{t2.tr1,t2.tr2,t2.tr3};
    auto it1(v1.begin());
    auto it2(v2.begin());
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++){
            if(v1[i]==v2[j]){
                v1.erase(it1+i);
                v2.erase(it2+j);
                i--;
                break;
            }
        }
    }
    if(v1.size()==0 && v2.size()==0) return true;
    else return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    vector<double>v1{t1.DajStranicu(1),t1.DajStranicu(2),t1.DajStranicu(3)},v2{t2.DajStranicu(1),t2.DajStranicu(2),t2.DajStranicu(3)};
    auto it1(v1.begin());
    auto it2(v2.begin());
    for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++){
            if(v1[i]==v2[j]){
                v1.erase(it1+i);
                v2.erase(it2+j);
                i--;
                break;
            }
        }
    }
    if(v1.size()==0 && v2.size()==0) return true;
    else return false;
}

bool DaLiSuSlicni( const Trougao &t1, const Trougao &t2){

 vector<double>v1{t1.DajStranicu(1),t1.DajStranicu(2),t1.DajStranicu(3)},v2{t2.DajStranicu(1),t2.DajStranicu(2),t2.DajStranicu(3)};   
 sort(v1.begin(),v1.end());
 sort(v2.begin(),v2.end());
 auto it1(v1.begin());
    auto it2(v2.begin());
 double k(v1[0]/v2[0]);
 for(int i=0;i<v1.size();i++){
        for(int j=0;j<v2.size();j++){
            if(v1[i]/v2[j]==k){
                v1.erase(it1+i);
                v2.erase(it2+j);
                i--;
                break;
            }
        }
    }
    if(v1.size()==0 && v2.size()==0) return true;
    else return false;
}
int main ()
{
    cout << "Koliko zelite kreirati trouglova: ";
    int n;
    cin >> n;
    vector<shared_ptr<Trougao>> v;
    for(int i(0); i < n; i++)
    {
        cout << "Unesite podatke za " << i + 1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        double x1, y1, x2, y2, x3, y3;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        try
        {
            Tacka tr1{x1, y1}, tr2{x2, y2}, tr3{x3, y3};
            auto p(make_shared<Trougao>(Trougao(tr1, tr2, tr3)));
            v.push_back(p);
        }
        catch(domain_error izuzetak)
        {
            cout << izuzetak.what() << ", ponovite unos!" << std::endl;
            i--;
        }
    }
    cout << "Unesite vektor translacije (dx dy): ";
    double dx, dy;
    cin >> dx >> dy;
    transform(v.begin(), v.end(), v.begin(),
    [dx, dy](shared_ptr<Trougao> p)
    {
        p->Transliraj(dx, dy);
        return p;
    });
    
    cout << "Unesite ugao rotacije: ";
    double ugao;
    cin >> ugao;
    transform(v.begin(), v.end(), v.begin(),
    [ugao](shared_ptr<Trougao> p)
    {
        p->Rotiraj(ugao);
        return p;
    });
    
    cout << "Unesite faktor skaliranja: ";
    double faktor;
    cin >> faktor;
    transform(v.begin(), v.end(), v.begin(),
    [faktor](shared_ptr<Trougao> p)
    {
        auto tjeme(p->DajTjeme(1));
        p->Skaliraj(tjeme, faktor);
        return p;
    });
    
    sort(v.begin(), v.end(),
    [](shared_ptr<Trougao> p1, shared_ptr<Trougao> p2)
    {
        return p1->DajPovrsinu() < p2->DajPovrsinu();
    });
    
   /* cout << "Trouglovi nakon obavljenih transformacija:" << endl;
    
    for_each(v.begin(), v.end(),
    [](shared_ptr<Trougao> p)
    {
        p->Ispisi();
        cout << endl;
 */
    
    cout << "Trougao sa najmanjim obimom: ";
   // (*(*min_element(v.begin(), v.end(), [](shared_ptr<Trougao> p1, shared_ptr<Trougao> p2){return p1->DajObim() < p2.DajObim();})))->Ispisi();
    cout << endl;
    
	return 0;
}