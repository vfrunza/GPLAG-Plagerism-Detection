/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <map>
#include <stdexcept>
#include <cmath>
#include <string>
#include <queue>
#include <algorithm>
#include <memory>
#include <sstream>
#include <functional>

typedef std::pair<double, double> Tacka;

const double eps=1e-10;
const double pi=4*std::atan(1);

bool isti(double a, double b){
    return std::fabs(a-b)<=eps*(std::fabs(a)+std::fabs(b));
}

void provjeriindex(int a){
    if(a<1 || a>3)throw std::range_error("Nekorektan indeks");
}

double duzina(const Tacka &t1, const Tacka &t2){
    return std::sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
}

double formula(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
}

template<typename T> 
std::string PretvoriUString(T x) {
    std::ostringstream s; s << x; 
    return s.str();
}

std::string ispisitacku(const Tacka &t){
    std::string a="(";
    a=a+PretvoriUString(t.first)+","+PretvoriUString(t.second)+")";
    return a;
}

void mrdajtacku(Tacka &t, double x, double y){
    t.first+=x;
    t.second+=y;
}

void sortiraj(std::vector<Tacka> &v1){
    std::sort(v1.begin(), v1.end(), [](const Tacka &t1, const Tacka &t2) {
        if(isti(t1.first, t2.first)) {
            return t1.second<t2.second;
        }
        return t1.first<t1.second;
    });
}

bool istetacke(const Tacka &a, const Tacka &b){
    return isti(a.first, b.first) && isti(a.second, b.second);
}

class Trougao{
    Tacka tacke[3];
    void update();
public:
    Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3) {
        Postavi(t1, t2, t3);
    }
    void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        double a=formula(t1, t2, t3);
        if(isti(a, 0))return 0;
        if(a>0)return 1;
        return -1;
    }
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
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
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
    void Trougao::update(){
        for(int i=0;i<3;i++){
            if(std::abs(tacke[i].first)<eps)tacke[i].first=0;
            if(std::abs(tacke[i].second)<eps)tacke[i].second=0;
        }
    }
    void Trougao::Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        if(Orijentacija(t1, t2, t3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
        tacke[0]=t1;
        tacke[1]=t2;
        tacke[2]=t3;
        update();
    }
    void Trougao::Postavi(int indeks, const Tacka &t){
        provjeriindex(indeks);
        if(indeks==1)
            Postavi(t, tacke[1], tacke[2]);
        if(indeks==2)
            Postavi(tacke[0], t, tacke[2]);
        if(indeks==3)
            Postavi(tacke[0], tacke[1], t);
        update();
    }
    Tacka Trougao::DajTjeme(int indeks) const{
        provjeriindex(indeks);
        return tacke[indeks-1];
    }
    double Trougao::DajStranicu(int indeks) const{
        provjeriindex(indeks);
        if(indeks==1)return duzina(tacke[1], tacke[2]);
        if(indeks==2)return duzina(tacke[0], tacke[2]);
        return duzina(tacke[0], tacke[1]);
    }
    double Trougao::DajUgao(int indeks) const{
        provjeriindex(indeks);
        double a, b, c;
        if(indeks==1) {
            a=duzina(tacke[1], tacke[2]);
            b=duzina(tacke[0], tacke[2]);
            c=duzina(tacke[0], tacke[1]);
        }
        if(indeks==2) {
            a=duzina(tacke[2], tacke[0]);
            b=duzina(tacke[1], tacke[2]);
            c=duzina(tacke[1], tacke[0]);
        }
        if(indeks==3) {
            a=duzina(tacke[1], tacke[0]);
            b=duzina(tacke[0], tacke[2]);
            c=duzina(tacke[2], tacke[1]);
        }
        return std::acos((c*c+b*b-a*a)/(2*c*b));
    }
    Tacka Trougao::DajCentar() const{
        return {(tacke[0].first+tacke[1].first+tacke[2].first)/3, (tacke[0].second+tacke[1].second+tacke[2].second)/3};
    }
    double Trougao::DajObim() const{
        return duzina(tacke[0], tacke[1])+duzina(tacke[1], tacke[2])+duzina(tacke[0], tacke[2]);
    }
    double Trougao::DajPovrsinu() const{
        return std::abs(formula(tacke[0], tacke[1], tacke[2]))/2;
    }
    bool Trougao::DaLiJePozitivnoOrijentiran() const{
        if(formula(tacke[0], tacke[1], tacke[2])>0)return true;
        return false;
    }
    bool Trougao::DaLiJeUnutra(const Tacka &t) const{
        int a=0;
        a+=Orijentacija(tacke[0], tacke[1], t);
        a+=Orijentacija(tacke[1], tacke[2], t);
        a+=Orijentacija(tacke[2], tacke[0], t);
        if(std::abs(a)==3)return true;
        return false;
    }
    void Trougao::Ispisi() const{
        std::cout<<"(";
        std::cout<<ispisitacku(tacke[0]);
        std::cout<<",";
        std::cout<<ispisitacku(tacke[1]);
        std::cout<<",";
        std::cout<<ispisitacku(tacke[2]);
        std::cout<<")";
    }
    void Trougao::Transliraj(double delta_x, double delta_y){
        for(int i=0; i<3; i++)
            mrdajtacku(tacke[i], delta_x, delta_y);
        update();
    }
    void Trougao::Centriraj(const Tacka &t){
        Tacka a=DajCentar();
        Transliraj(t.first-a.first, t.second-a.second);
        update();
    }
    void Trougao::Rotiraj(const Tacka &t, double ugao){
        double a, b;
        for(int i=0; i<3; i++) {
            a=t.first+(tacke[i].first-t.first)*std::cos(ugao)-(tacke[i].second-t.second)*std::sin(ugao);
            b=t.second+(tacke[i].first-t.first)*std::sin(ugao)+(tacke[i].second-t.second)*std::cos(ugao);
            tacke[i].first=a;
            tacke[i].second=b;
        }
        update();
    }
    void Trougao::Skaliraj(const Tacka &t, double faktor){
        if(isti(faktor, 0))throw std::domain_error("Nekorektan faktor skaliranja");
        for(int i=0; i<3; i++){
            tacke[i].first=t.first+faktor*(tacke[i].first-t.first);
            tacke[i].second=t.second+faktor*(tacke[i].second-t.second);
        }
        update();
    }
    void Trougao::Rotiraj(double ugao){
        Rotiraj(DajCentar(), ugao);
    }
    void Trougao::Skaliraj(double faktor){
        Skaliraj(DajCentar(), faktor);
    }
    bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
        std::vector<Tacka> v1, v2;
        for(int i=0; i<3; i++) {
            v1.push_back(t1.tacke[i]);
            v2.push_back(t2.tacke[i]);
        }
        sortiraj(v1);
        sortiraj(v2);
        for(int i=0; i<3; i++) {
            if(!istetacke(v1[i], v2[i]))return false;
        }
        return true;
    }
    bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
        std::vector<Tacka> tac1 {t1.tacke[0], t1.tacke[1], t1.tacke[2]};
        if(Trougao::Orijentacija(tac1[0], tac1[1], tac1[2])==-1)
            std::swap(tac1[1], tac1[2]);
        std::vector<Tacka> tac2 {t2.tacke[0], t2.tacke[1], t2.tacke[2]};
        if(Trougao::Orijentacija(tac2[0], tac2[1], tac2[2])==-1)
            std::swap(tac2[1], tac2[2]);
        double a=duzina(tac1[0], tac1[1]), b=duzina(tac1[1], tac1[2]), c=duzina(tac1[0], tac1[2]);
        for(int i=0; i<3; i++) {
            if(isti(a,duzina(tac2[0], tac2[1])) && isti(b, duzina(tac2[1], tac2[2])) && isti(c, duzina(tac2[0], tac2[2])))return true;
            std::rotate(tac2.begin(), tac2.begin()+1, tac2.end());
        }
        return false;
    }
    bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
        std::vector<Tacka> tac1 {t1.tacke[0], t1.tacke[1], t1.tacke[2]};
        if(Trougao::Orijentacija(tac1[0], tac1[1], tac1[2])==-1)
            std::swap(tac1[1], tac1[2]);
        std::vector<Tacka> tac2 {t2.tacke[0], t2.tacke[1], t2.tacke[2]};
        if(Trougao::Orijentacija(tac2[0], tac2[1], tac2[2])==-1)
            std::swap(tac2[1], tac2[2]);
        double a=duzina(tac1[0], tac1[1]), b=duzina(tac1[1], tac1[2]), c=duzina(tac1[0], tac1[2]);
        double faktor;
        for(int i=0; i<3; i++) {
            faktor=a/duzina(tac2[0], tac2[1]);
            if(isti(faktor, b/duzina(tac2[1], tac2[2])) && isti(faktor, c/duzina(tac2[0], tac2[2])))return true;
            std::rotate(tac2.begin(), tac2.begin()+1, tac2.end());
        }
        return false;
    }
    
void Parovi(const std::vector<std::shared_ptr<Trougao>> &v, std::string s){
    bool ima=false;
    bool temp;
    std::string a;
    if(s=="identican"){
        a+="Parovi identicnih trouglova:\n";
    }
    if(s=="podudaran"){
        a+="Parovi podudarnih trouglova:\n";
    }
    if(s=="slican"){
        a+="Parovi slicnih trouglova:\n";
    }
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            temp=false;
            if(s=="identican"){
                temp=DaLiSuIdenticni(*v[i], *v[j]);
            }
            if(s=="podudaran"){
                temp=DaLiSuPodudarni(*v[i], *v[j]);
            }
            if(s=="slican"){
                temp=DaLiSuSlicni(*v[i], *v[j]);
            }
            if(temp){
                a+="(";
                a+=ispisitacku(v[i]->DajTjeme(1));
                a+=",";
                a+=ispisitacku(v[i]->DajTjeme(2));
                a+=",";
                a+=ispisitacku(v[i]->DajTjeme(3));
                a+=")";
                a+=" i ";
                a+="(";
                a+=ispisitacku(v[j]->DajTjeme(1));
                a+=",";
                a+=ispisitacku(v[j]->DajTjeme(2));
                a+=",";
                a+=ispisitacku(v[j]->DajTjeme(3));
                a+=")";
                a+="\n";
                ima=true;
            }
        }
    }
    if(!ima){
        if(s=="identican"){
            a="Nema identicnih trouglova!\n";
        }
        if(s=="podudaran"){
            a="Nema podudarnih trouglova!\n";
        }
        if(s=="slican"){
            a="Nema slicnih trouglova!\n";
        }
    }
    std::cout<<a;
}

int main (){
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> v;
    Tacka t[3];
    for(int i=0;i<n;i++){
        do{
            std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            for(int j=0;j<3;j++)std::cin>>t[j].first>>t[j].second;
            try{
                v.push_back(std::shared_ptr<Trougao>(new Trougao(t[0], t[1], t[2])));
            }
            catch(std::domain_error gg){
                std::cout<<gg.what()<<", ponovite unos!\n";
                continue;
            }
            break;
        }while(true);
    }
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double x, y;
    std::cin>>x>>y;
    std::cout<<"Unesite ugao rotacije: ";
    double ugao;
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    double faktor;
    std::cin>>faktor;
    std::transform(v.begin(), v.end(), v.begin(), [x, y, ugao, faktor](std::shared_ptr<Trougao> t){
        t->Transliraj(x, y);
        t->Rotiraj(ugao);
        t->Skaliraj(t->DajTjeme(1), faktor);
        return t;
    });
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){
        return t1->DajPovrsinu()<t2->DajPovrsinu();
    });
    std::cout<<"Trouglovi nakon obavljenih transformacija:\n";
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> t){
        t->Ispisi();
        std::cout<<"\n";
    });
    auto p=std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){
        return t1->DajObim()<t2->DajObim();
    });
    std::cout<<"Trougao sa najmanjim obimom: ";
    (*p)->Ispisi();
    std::cout<<"\n";
    Parovi(v, "identican");
    Parovi(v, "podudaran");
    Parovi(v, "slican");
    
    return 0;
}




/*

2
0 0 1 0 0 1
0 0 0 1 1 0
0 0
0
1


*/