/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>

typedef std::pair<double,double> Tacka;

const double epsilon(1E-10);

void DaLiJeIspravanIndeks(int indeks){
    if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
}

/*void DaLiJeKorektnaPozicija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(!Orijentacija(t1,t2,t3)) throw std::domain_error("Nekorektne pozicije tjemena");
}*/

double KosinusnaTeorema(double a, double b, double c){
    return (b*b+c*c-a*a)/(2*b*c);
}

double RuzniIzraz(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
}

Tacka RuznaTacka(const Tacka &A, const Tacka &B, double ugao){
    double prva_koor(B.first+(A.first-B.first)*std::cos(ugao)-(A.second-B.second)*std::sin(ugao));
    double druga_koor(B.second+(A.first-B.first)*std::sin(ugao)+(A.second-B.second)*std::cos(ugao));
    Tacka ruzna(prva_koor,druga_koor);
    return ruzna;
}
class Trougao{
    Tacka x, y, z;
    void DaLiJeKorektnaPozicija(const Tacka &t1, const Tacka &t2, const Tacka &t3) const;
    bool DaLiJePozitivnoOrijentiran(const Tacka &t1, const Tacka &t2, const Tacka &t3) const{ if(Orijentacija(t1,t2,t3)==1) return true; return false;}
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        DaLiJeKorektnaPozicija(t1,t2,t3);
        x=t1; y=t2; z=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        DaLiJeKorektnaPozicija(t1,t2,t3);
        x=t1; y=t2; z=t3;
    }
    void Postavi(int indeks, const Tacka &t){
        DaLiJeIspravanIndeks(indeks);
        if(indeks==1) {DaLiJeKorektnaPozicija(t,y,z); x=t;}
        if(indeks==2) {DaLiJeKorektnaPozicija(x,t,z); y=t;}
        if(indeks==3) {DaLiJeKorektnaPozicija(x,y,t); z=t;}
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const{
        DaLiJeIspravanIndeks(indeks);
        if(indeks==1) return x;
        if(indeks==2) return y;
        return z;
    }
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const{ return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);}
    double DajPovrsinu() const {return std::fabs(RuzniIzraz(x,y,z)/2);}
    bool DaLiJePozitivnoOrijentiran() const {if(Orijentacija(x,y,z)==1) return true; return false;}
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao) {Rotiraj(DajCentar(),ugao);}
    void Skaliraj(double faktor) {Skaliraj(DajCentar(),faktor);};
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double izraz(RuzniIzraz(t1,t2,t3));
    if(izraz>0) return 1;
    if(izraz<0) return -1;
    return 0;
}

void Trougao::DaLiJeKorektnaPozicija(const Tacka &t1, const Tacka &t2, const Tacka &t3) const{
    if(!Orijentacija(t1,t2,t3)) throw std::domain_error("Nekorektne pozicije tjemena");
}

bool IsItOk(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(!Trougao::Orijentacija(t1,t2,t3)) return false;
    return true;
}
double Trougao::DajStranicu(int indeks) const{
    DaLiJeIspravanIndeks(indeks);
    if(indeks==1) return std::sqrt(std::pow((z.second-y.second),2)+std::pow((z.first-y.first),2));
    if(indeks==2) return std::sqrt(std::pow((z.second-x.second),2)+std::pow((z.first-x.first),2));
    return std::sqrt(std::pow((x.second-y.second),2)+std::pow((x.first-y.first),2));
}

double Trougao::DajUgao(int indeks) const{
    DaLiJeIspravanIndeks(indeks);
    if(indeks==1) return std::acos(KosinusnaTeorema(DajStranicu(1),DajStranicu(2),DajStranicu(3)));
    if(indeks==2) return std::acos(KosinusnaTeorema(DajStranicu(2),DajStranicu(1),DajStranicu(3)));
    return std::acos(KosinusnaTeorema(DajStranicu(3),DajStranicu(1),DajStranicu(2)));
}

Tacka Trougao::DajCentar() const{
    Tacka centar;
    centar.first=(x.first+y.first+z.first)/3.;
    centar.second=(x.second+y.second+z.second)/3.;
    return centar;
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const {
    if(Orijentacija(t,y,z) != 0 && Orijentacija(t,x,z) != 0 && Orijentacija(t,x,y)!=0){
        if(DaLiJePozitivnoOrijentiran(x,y,z)){
            if(DaLiJePozitivnoOrijentiran(x,y,t) && DaLiJePozitivnoOrijentiran(y,z,t) && DaLiJePozitivnoOrijentiran(z,x,t)) return true;
            return false;
        }
        else{
            if(!DaLiJePozitivnoOrijentiran(x,y,t) && !DaLiJePozitivnoOrijentiran(y,z,t) && !DaLiJePozitivnoOrijentiran(z,x,t)) return true;
            return false;
        }
    }
    else return false;
}

void Trougao::Ispisi() const{
    std::cout<<"(("<<x.first<<","<<x.second<<"),"<<"("<<y.first<<","<<y.second<<"),"<<"("<<z.first<<","<<z.second<<"))";
}

void Trougao::Transliraj(double delta_x, double delta_y){
    x.first+=delta_x; y.first+=delta_x; z.first+=delta_x;
    x.second+=delta_y; y.second+=delta_y; z.second+=delta_y;
}

void Trougao::Centriraj(const Tacka &t1){
    double delta_x(t1.first-DajCentar().first);
    double delta_y(t1.second-DajCentar().second);
    Transliraj(delta_x,delta_y);
}

void Trougao::Rotiraj(const Tacka &t, double ugao){
    Tacka pomoc(x.first,x.second);
    x=RuznaTacka(pomoc,t,ugao);
    pomoc=y;
    y=RuznaTacka(pomoc,t,ugao);
    pomoc=z;
    z=RuznaTacka(pomoc,t,ugao);
}

Tacka Cudno(const Tacka &t1, const Tacka &t2, double faktor){
    Tacka cudna(t2.first+faktor*(t1.first-t2.first),t2.second+faktor*(t1.second-t2.second));
    return cudna;
}
void Trougao::Skaliraj (const Tacka &t, double faktor){
    if(faktor<epsilon) throw std::domain_error("Nekorektan faktor skaliranja");
    x=Cudno(x,t,faktor);
    y=Cudno(y,t,faktor);
    z=Cudno(z,t,faktor);
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    //t1.Ispisi();
    std::vector<Tacka> koordinate{t1.x, t1.y, t1.z};
    //std::cout<<"broj: "<<std::count_if(koordinate.begin(), koordinate.end(), [&t2](Tacka t) {if(epsilon>(std::fabs(t2.x.first-t.first)) && epsilon>(std::fabs(t2.x.second-t.second))) return true; return false;});
   // std::cout<<koordinate[0].first<<" "<<t1.x.second;
    if(std::count_if(koordinate.begin(), koordinate.end(),[&t2](Tacka t){if(epsilon>std::fabs(t2.x.first-t.first) && epsilon>std::fabs(t2.x.second-t.second)) return true; return false;})==1 && std::count_if(koordinate.begin(), koordinate.end(), [&t2](Tacka t){if(epsilon>std::fabs(t2.y.first-t.first) && epsilon>std::fabs(t2.y.second-t.second)) return true; return false;})==1 && std::count_if(koordinate.begin(), koordinate.end(), [&t2](Tacka t){if(epsilon>std::fabs(t2.z.first-t.first) && epsilon>std::fabs(t2.z.second-t.second)) return true; return false;})==1) return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    Trougao a(t1.x, t1.y, t1.z), b(t2.x, t2.y, t2.z);
    a.Centriraj(b.DajCentar());
    int indeks(0);
    for(int i=0; i<3; i++){
        if(epsilon>(std::fabs(t1.DajUgao(1)-t2.DajUgao(i+1)))){ indeks=i+1; break;}
    }
    if(indeks==0) return false;
    if(!IsItOk(a.DajTjeme(1), a.DajCentar(), b.DajTjeme(indeks))) {
       if(DaLiSuIdenticni(a,b)) return true;
       return false;
    }
    else{
        Trougao rotacije(a.DajTjeme(1),a.DajCentar(),b.DajTjeme(indeks));
        //std::cout<<"indeks "<<indeks<<" ";
        double kut;
        /*if(rotacije.DaLiJePozitivnoOrijentiran() && rotacije.DajUgao(2)<=4*std::atan(1)) kut=rotacije.DajUgao(2);
        else if(!rotacije.DaLiJePozitivnoOrijentiran() && rotacije.DajUgao(3)<=4*std::atan(1)) kut=rotacije.DajUgao(3);
        else if(rotacije.DaLiJePozitivnoOrijentiran()) kut=8*std::atan(1)-rotacije.DajUgao(2);
        else kut=8*std::atan(1)-rotacije.DajUgao(3);*/
        kut=rotacije.DajUgao(2);
        if(rotacije.DaLiJePozitivnoOrijentiran()) {a.Rotiraj(2*4*std::atan(1)-kut); }
        else {a.Rotiraj(kut);}
        //if(a.DajCentar()==b.DajCentar()){ a.Ispisi(); std::cout<<std::endl; b.Ispisi();}
        //std::cout<<"\n"; a.Ispisi();
        if(DaLiSuIdenticni(a,b)) return true;
        return false;
    }
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    Trougao a(t1.x, t1.y, t1.z), b(t2.x, t2.y, t2.z);
    int indeks(0);
    for(int i=0; i<3; i++){
        if(epsilon>std::fabs(a.DajUgao(1)-b.DajUgao(i+1))) {indeks=i+1; break;}
    }
    if(indeks==0) return false;
    double faktor(0);
    faktor=b.DajStranicu(indeks)/a.DajStranicu(1);
    a.Skaliraj(faktor);
    if(DaLiSuPodudarni(a,b)) return true;
    return false;
}

void ObicnaFunkcija(const std::vector<std::shared_ptr<Trougao>> &vektor, bool f(const Trougao &t1, const Trougao &t2), std::string s1, std::string s2){
    int broj(0);
    for(int i=0; i<vektor.size(); i++){
        for(int j=i+1; j<vektor.size(); j++){
            if(f(*vektor[i], *vektor[j])) broj++;
        }
    }
    if(broj==0) std::cout<<s1<<std::endl;
    else{
        std::cout<<s2<<std::endl;
        for(int i=0; i<vektor.size(); i++){
            for(int j=i+1; j<vektor.size(); j++){
                if(f(*vektor[i], *vektor[j])) {vektor[i] ->Ispisi(); std::cout<<" i "; vektor[j]->Ispisi(); std::cout<<std::endl;}
            }
        }
    }
}
int main ()
{
    try{
        std::cout<<"Koliko zelite kreirati trouglova: ";
        int n;
        std::cin>>n;
        std::vector<std::shared_ptr<Trougao>> vektor(n);
        for(int i=0; i<n; i++){
            Tacka tockica1,tockica2,tockica3;
            do{
            std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            std::cin>>tockica1.first>>tockica1.second;
            std::cin>>tockica2.first>>tockica2.second;
            std::cin>>tockica3.first>>tockica3.second;
            if(!IsItOk(tockica1,tockica2,tockica3)) std::cout<<"Nekorektne pozicije tjemena, ponovite unos! "<<std::endl;
            }while(!IsItOk(tockica1,tockica2,tockica3));
            vektor[i]=std::make_shared<Trougao>(tockica1,tockica2,tockica3);
        }
        std::cout<<"Unesite vektor translacije (dx dy): ";
        double dx, dy;
        std::cin>>dx>>dy;
        std::transform(vektor.begin(), vektor.end(), vektor.begin(), [dx,dy](std::shared_ptr<Trougao> t)->std::shared_ptr<Trougao>{ t->Transliraj(dx,dy); return t;});
        std::cout<<"Unesite ugao rotacije: ";
        double ugao;
        std::cin>>ugao;
        std::transform(vektor.begin(), vektor.end(), vektor.begin(), [ugao](std::shared_ptr<Trougao> t)->std::shared_ptr<Trougao>{t->Rotiraj(ugao); return t;});
        std::cout<<"Unesite faktor skaliranja: ";
        double faktor;
        std::cin>>faktor;
        std::transform(vektor.begin(), vektor.end(), vektor.begin(), [faktor](std::shared_ptr<Trougao> t)->std::shared_ptr<Trougao> {t->Skaliraj(t->DajTjeme(1),faktor); return t;});
        std::sort(vektor.begin(), vektor.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2)->bool {if(t1->DajPovrsinu()<t2->DajPovrsinu()) return true; return false;});
        std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
        std::for_each(vektor.begin(), vektor.end(), [](std::shared_ptr<Trougao> t){t->Ispisi(); std::cout<<std::endl;});
        auto min(*std::max_element(vektor.begin(), vektor.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2)->bool {if((t1->DajObim())>(t2->DajObim())) return true; return false;}));
        std::cout<<"Trougao sa najmanjim obimom: "; min->Ispisi(); std::cout<<std::endl;
        int broj(0);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(DaLiSuIdenticni(*vektor[i], *vektor[j])) broj++;
            }
        }
        if(broj==0) std::cout<<"Nema identicnih trouglova!"<<std::endl;
        else{
            std::cout<<"Parovi identicnih trouglova: "<<std::endl;
            for(int i=0; i<n; i++){
                for(int j=i+1; j<n; j++){
                    if(DaLiSuIdenticni(*vektor[i], *vektor[j])){
                        vektor[i]->Ispisi(); std::cout<<" i "; vektor[j]->Ispisi(); std::cout<<std::endl;
                    }
                }
            }
        }
        broj=0;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                if(DaLiSuPodudarni(*vektor[i], *vektor[j])) broj++;
        if(broj==0) std::cout<<"Nema podudarnih trouglova!"<<std::endl;
        else{
            std::cout<<"Parovi podudarnih trouglova: "<<std::endl;
            for(int i=0; i<n; i++){
                for(int j=i+1; j<n; j++){
                    if(DaLiSuPodudarni(*vektor[i], *vektor[j])){
                        vektor[i]->Ispisi(); std::cout<<" i "; vektor[j]->Ispisi(); std::cout<<std::endl;
                    }
                }
            }
        }
        //ObicnaFunkcija(vektor, DaLiSuPodudarni, "Nema podudarnih trouglova!", "Parovi podudarnih trouglova: ");
        ObicnaFunkcija(vektor, DaLiSuSlicni, "Nema slicnih trouglova!", "Parovi slicnih trouglova: ");
    }
    catch(std::domain_error izuzetak){
        std::cout<<izuzetak.what()<<std::endl;
    }
    catch(std::logic_error izuz){
        std::cout<<izuz.what()<<std::endl;
    }
    catch(...){
        return 0;
    }
    
	return 0;
}