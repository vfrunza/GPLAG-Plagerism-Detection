/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>  
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <new>
#include <vector>
#include <memory>

typedef std::pair<double, double> Tacka;

class Trougao{
    Tacka a,b,c;
public:
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi (int indeks, const Tacka &t1);
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme(int indeks) const;
    double DajStranicu(int indeks) const;
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const;
    double DajPovrsinu() const;
    bool DaLiJePozitivnoOrijentiran() const;
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const;
    void Transliraj (double delta_x, double delta_y);
    void Centriraj (const Tacka &t);
    void Rotiraj (const Tacka &t, double ugao);
    void Skaliraj (const Tacka &t, double faktor);
    void Rotiraj (double ugao);
    void Skaliraj (double faktor);
    friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2);
};

int main ()
{
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> niz(n);
    for(int i(0); i<n; i++){
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::vector<double> kordinate;
        for(int j(0); j<6; j++){
            double k;
            std::cin>>k;
            kordinate.push_back(k);
        }
        Tacka a,b,c;
        a.first=kordinate[0];
        a.second=kordinate[1];
        b.first=kordinate[2];
        b.second=kordinate[3];
        c.first=kordinate[4];
        c.second=kordinate[5];
        try{
            niz[i]=std::make_shared<Trougao>(a,b,c);
        }
        catch(std::domain_error poruka){
            std::cout<<poruka.what()<<", ponovite unos!"<<std::endl;
            i--;
        }
    }
    double dx, dy;
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>dx>>dy;
    double ugao;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>ugao;
    double faktor;
    std::cout<<"Unesite faktor skaliranja:";
    std::cin>>faktor;
    
    std::transform(niz.begin(), niz.end(), niz.begin(), [dx,dy] (std::shared_ptr<Trougao> trougao) { trougao->Transliraj(dx, dy); return trougao;});
    std::transform(niz.begin(), niz.end(), niz.begin(), [ugao] (std::shared_ptr<Trougao> trougao) { trougao->Rotiraj(ugao); return trougao;});
    try{
        std::transform(niz.begin(), niz.end(), niz.begin(), [faktor] (std::shared_ptr<Trougao> trougao) { trougao->Skaliraj(trougao->DajTjeme(1), faktor); return trougao;});
    }
    catch(std::domain_error poruka){
        std::cout<<poruka.what()<<std::endl;
    }
    std::sort(niz.begin(), niz.end(), [] (std::shared_ptr<Trougao> trougao1, std::shared_ptr<Trougao> trougao2){
        if(trougao1->DajPovrsinu() < trougao2->DajPovrsinu()) return true;
        return false;
    });
    std::cout<<" Trouglovi nakon obavljenih transformacija:"<<std::endl;
    std::for_each(niz.begin(), niz.end(), [] (std::shared_ptr<Trougao> trougao) {trougao->Ispisi(); std::cout<<std::endl;});
    auto minObim=std::min_element(niz.begin(), niz.end(), [] (std::shared_ptr<Trougao> trougao1, std::shared_ptr<Trougao> trougao2){
        if(trougao1->DajObim() < trougao2->DajObim()) return true;
        return false;
    });
    std::cout<<"Trougao sa najmanjim obimom: ";
    (*minObim)->Ispisi();
    std::cout<<std::endl;
    std::vector<std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>>> parovi;
    for(int i(0); i<n-1; i++){
        for(int j(i+1); j<n; j++){
            if(DaLiSuIdenticni(*niz[i], *niz[j])){
                parovi.push_back(make_pair(niz[i], niz[j]));
            }
        }
    }
    if(parovi.size()!=0){
        std::cout<<"Parovi identicnih trouglova:"<<std::endl;
        for(int i(0); i<parovi.size(); i++){
            parovi[i].first->Ispisi();
            std::cout<<" i ";
            parovi[i].second->Ispisi();
            std::cout<<std::endl;
        }
    }
    else{
        std::cout<<"Nema identicnih trouglova!"<<std::endl;
    }
    std::vector<std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>>> paroviPodudarnih;
    for(int i(0); i<n-1; i++){
        for(int j(i+1); j<n; j++){
            if(DaLiSuPodudarni(*niz[i],*niz[j])){
                paroviPodudarnih.push_back(make_pair(niz[i], niz[j]));
            }
        }
    }
    if(paroviPodudarnih.size()!=0){
        std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
        for(int i(0); i<paroviPodudarnih.size(); i++){
            paroviPodudarnih[i].first->Ispisi();
            std::cout<<" i ";
            paroviPodudarnih[i].second->Ispisi();
            std::cout<<std::endl;
        }
    }
    else{
        std::cout<<"Nema podudarnih trouglova!"<<std::endl;
    }
    std::vector<std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>>> paroviSlicnih;
    for(int i(0); i<n-1; i++){
        for(int j(i+1); j<n; j++){
            if(DaLiSuSlicni(*niz[i], *niz[j])){
                paroviSlicnih.push_back(make_pair(niz[i],niz[j]));
            }
        }
    } 
    if(paroviSlicnih.size()!=0){
        std::cout<<"Parovi slicnih trouglova:"<<std::endl;
        for(int i(0); i<paroviSlicnih.size(); i++){
            paroviSlicnih[i].first->Ispisi();
            std::cout<<" i ";
            paroviSlicnih[i].second->Ispisi();
            std::cout<<std::endl;
        }
    }
    else{
        std::cout<<"Nema slicnih trouglova!"<<std::endl;
    }
    return 0;
}

Trougao::Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Trougao::Orijentacija(t1,t2,t3)==0){
        throw std::domain_error("Nekorektne pozicije tjemena");
    }
    else{
        a=t1;
        b=t2;
        c=t3;
    }
}

void Trougao::Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3){
    a=t1;
    b=t2;
    c=t3;
}

void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks<1 || indeks>3){
        throw std::range_error ("Nekorektan indeks");
    }
    else if(indeks==1){
        a=t;
    }
    else if(indeks==2){
        b=t;
    }
    else if(indeks==3){
        c=t;
    }
}

int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second)>0){
        return 1;
    }
    else if(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second)<0){
        return -1;
    }
    else if(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second)==0){
        return 0;
    }
}

Tacka Trougao::DajTjeme(int indeks) const{
    if(indeks<1 || indeks>3){
        throw std::range_error ("Nekorektan indeks");
    }
    else if(indeks==1){
        return a;
    }
    else if(indeks==2){
        return b;
    }
    else if(indeks==3){
        return c;
    }
}

double Trougao::DajStranicu(int indeks) const {
    if(indeks<1 || indeks>3){
        throw std::range_error ("Nekorektan indeks");
    }
    else if(indeks == 1){
        return sqrt((b.first-c.first)*(b.first-c.first)+(b.second-c.second)*(b.second-c.second));
    }
    else if(indeks == 2){
        return sqrt((a.first-c.first)*(a.first-c.first)+(a.second-c.second)*(a.second-c.second));
    }
    else if(indeks == 3){
        return sqrt((b.first-a.first)*(b.first-a.first)+(b.second-a.second)*(b.second-a.second));
    }
}

double Trougao::DajUgao(int indeks) const{
    if(indeks<1 || indeks>3){
        throw std::range_error ("Nekorektan indeks");
    }
    else if(indeks==1){
        return acos((( Trougao::DajStranicu(2) * Trougao::DajStranicu(2) ) + ( Trougao::DajStranicu(3) * Trougao::DajStranicu(3) ) - (Trougao::DajStranicu(1) * Trougao::DajStranicu(1))) / (2 * Trougao::DajStranicu(2) * Trougao::DajStranicu(3) ));
    }
    else if(indeks==2){
        return acos((( Trougao::DajStranicu(1) * Trougao::DajStranicu(1) ) + ( Trougao::DajStranicu(3) * Trougao::DajStranicu(3) ) - (Trougao::DajStranicu(2) * Trougao::DajStranicu(2))) / (2 * Trougao::DajStranicu(1) * Trougao::DajStranicu(3) ));
    }
    else if(indeks==3){
        return acos((( Trougao::DajStranicu(1) * Trougao::DajStranicu(1) ) + ( Trougao::DajStranicu(2) * Trougao::DajStranicu(2) ) - (Trougao::DajStranicu(3) * Trougao::DajStranicu(3))) / (2 * Trougao::DajStranicu(1) * Trougao::DajStranicu(2) ));
    }
}

Tacka Trougao::DajCentar() const{
    double x,y;
    x=(a.first+b.first+c.first)/3;
    y=(a.second+b.second+c.second)/3;
    Tacka m(std::make_pair(x,y));
    return m;
}

double Trougao::DajObim() const{
    return Trougao::DajStranicu(1)+Trougao::DajStranicu(2)+Trougao::DajStranicu(3);
}

double Trougao::DajPovrsinu() const{
    return 0.5*abs(a.first*(b.second-c.second)-b.first*(a.second-c.second)+c.first*(a.second-b.second));
}

bool Trougao::DaLiJePozitivnoOrijentiran() const{
    if(Trougao::Orijentacija(a,b,c)==1){
        return true;
    }
    else if(Trougao::Orijentacija(a,b,c)==-1){
        return false;
    }
}

bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    if(Trougao::Orijentacija(a, b, c)==1 && Trougao::Orijentacija(a, b, t)==1 && Trougao::Orijentacija(b, c, t)==1 && Trougao::Orijentacija(c, a, t)==1) return true;
    if(Trougao::Orijentacija(a, b, c)==-1 && Trougao::Orijentacija(a, b, t)==-1 && Trougao::Orijentacija(b, c, t)==-1 && Trougao::Orijentacija(c, a, t)==-1) return true;
    else false;
}

void Trougao::Ispisi() const{
    std::cout<<"(("<<a.first<<","<<a.second<<"),("<<b.first<<","<<b.second<<"),("<<c.first<<","<<c.second<<"))";
}

void Trougao::Transliraj (double delta_x, double delta_y){
    a.first+=delta_x;
    a.second+=delta_y;
    b.first+=delta_x;
    b.second+=delta_y;
    c.first+=delta_x;
    c.second+=delta_y;
}

void Trougao::Centriraj(const Tacka &t){
    double delta_x=DajCentar().first-t.first;
    double delta_y=DajCentar().second-t.second;
    a.first+=delta_x;
    a.second+=delta_y;
    b.first+=delta_x;
    b.second+=delta_y;
    c.first+=delta_x;
    c.second+=delta_y;
}

void Trougao::Rotiraj(const Tacka &t, double ugao){
    double x=a.first;
    double y=a.second;
    a.first=(t.first+(x-t.first)*cos(ugao)-(y-t.second)*sin(ugao));
    a.second=(t.second+(x-t.first)*sin(ugao)+(y-t.second)*cos(ugao));
    x=b.first;
    y=b.second;
    b.first=(t.first+(x-t.first)*cos(ugao)-(y-t.second)*sin(ugao));
    b.second=(t.second+(x-t.first)*sin(ugao)+(y-t.second)*cos(ugao));
    x=c.first;
    x=c.second;
    c.first=(t.first+(x-t.first)*cos(ugao)-(y-t.second)*sin(ugao));
    c.second=(t.second+(x-t.first)*sin(ugao)+(y-t.second)*cos(ugao));
}

void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(faktor==0){
        throw std::domain_error("Nekorektan faktor skaliranja");
    }
    else{
        a.first=t.first+faktor*(a.first-t.first);
        a.second=t.second+faktor*(a.second-t.second);
        b.first=t.first+faktor*(b.first-t.first);
        b.second=t.second+faktor*(b.second-t.second);
        c.first=t.first+faktor*(c.first-t.first);
        c.second=t.second+faktor*(c.second-t.second);
    }
}

void Trougao::Rotiraj(double ugao){
    a.first=(Trougao::DajCentar().first+(a.first-Trougao::DajCentar().first)*cos(ugao)-(a.second-Trougao::DajCentar().second)*sin(ugao));
    a.second=(Trougao::DajCentar().second+(a.first-Trougao::DajCentar().first)*sin(ugao)+(a.second-Trougao::DajCentar().second)*cos(ugao));
    b.first=(Trougao::DajCentar().first+(b.first-Trougao::DajCentar().first)*cos(ugao)-(b.second-Trougao::DajCentar().second)*sin(ugao));
    b.second=(Trougao::DajCentar().second+(b.first-Trougao::DajCentar().first)*sin(ugao)+(b.second-Trougao::DajCentar().second)*cos(ugao));
    c.first=(Trougao::DajCentar().first+(c.first-Trougao::DajCentar().first)*cos(ugao)-(c.second-Trougao::DajCentar().second)*sin(ugao));
    c.second=(Trougao::DajCentar().second+(c.first-Trougao::DajCentar().first)*sin(ugao)+(c.second-Trougao::DajCentar().second)*cos(ugao));
}

void Trougao::Skaliraj(double faktor){
    if(faktor==0){
        throw std::domain_error("Nekorektan faktor skaliranja");
    }
    else{
        a.first=Trougao::DajCentar().first+faktor*(a.first-Trougao::DajCentar().first);
        a.second=Trougao::DajCentar().second+faktor*(a.second-Trougao::DajCentar().second);
        b.first=Trougao::DajCentar().first+faktor*(b.first-Trougao::DajCentar().first);
        b.second=Trougao::DajCentar().second+faktor*(b.second-Trougao::DajCentar().second);
        c.first=Trougao::DajCentar().first+faktor*(c.first-Trougao::DajCentar().first);
        c.second=Trougao::DajCentar().second+faktor*(c.second-Trougao::DajCentar().second);
    }
}

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    Tacka niz1[3]{t1.a,t1.b,t1.c};
    Tacka niz2[3]{t2.a,t2.b,t2.c};
    int br=0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(niz1[i]==niz2[j]){
                br++;
                break;
            }
        }
    }
    if(br==3) return true;
    else return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    double stranica1_a=t1.DajStranicu(1);
    double stranica1_b=t1.DajStranicu(2);
    double stranica1_c=t1.DajStranicu(3);

    double stranica2_a=t2.DajStranicu(1);
    double stranica2_b=t2.DajStranicu(2);
    double stranica2_c=t2.DajStranicu(3);

    const double Eps=1e-10;
    if(std::fabs(stranica1_a-stranica2_a)<Eps && std::fabs(stranica1_b-stranica2_b)<Eps && std::fabs(stranica1_c-stranica2_c)<Eps && t1.Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(1), t2.DajTjeme(2), t2.DajTjeme(3))) return true;
    else if(std::fabs(stranica1_a-stranica2_a)<Eps && std::fabs(stranica1_b-stranica2_c)<Eps && std::fabs(stranica1_c-stranica2_b)<Eps && t1.Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(1), t2.DajTjeme(3), t2.DajTjeme(2))) return true;
    else if(std::fabs(stranica1_a-stranica2_b)<Eps && std::fabs(stranica1_b-stranica2_a)<Eps && std::fabs(stranica1_c-stranica2_c)<Eps && t1.Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(2), t2.DajTjeme(1), t2.DajTjeme(3))) return true;
    else if(std::fabs(stranica1_a-stranica2_b)<Eps && std::fabs(stranica1_b-stranica2_c)<Eps && std::fabs(stranica1_c-stranica2_a)<Eps && t1.Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(2), t2.DajTjeme(3), t2.DajTjeme(1))) return true;
    else if(std::fabs(stranica1_a-stranica2_c)<Eps && std::fabs(stranica1_b-stranica2_b)<Eps && std::fabs(stranica1_c-stranica2_a)<Eps && t1.Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(3), t2.DajTjeme(2), t2.DajTjeme(1))) return true;
    else if(std::fabs(stranica1_a-stranica2_c)<Eps && std::fabs(stranica1_b-stranica2_a)<Eps && std::fabs(stranica1_c-stranica2_b)<Eps && t1.Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(3), t2.DajTjeme(1), t2.DajTjeme(2))) return true;
    else return false;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    double stranica1_a=t1.DajStranicu(1);
    double stranica1_b=t1.DajStranicu(2);
    double stranica1_c=t1.DajStranicu(3);
    
    double stranica2_a=t2.DajStranicu(1);
    double stranica2_b=t2.DajStranicu(2);
    double stranica2_c=t2.DajStranicu(3);
    const double Eps=1e-10;
    
    if(std::fabs((stranica1_a/stranica2_a)-(stranica1_b/stranica2_b))<Eps && std::fabs((stranica1_a/stranica2_a)-(stranica1_c/stranica2_c))<Eps && t1.Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(1), t2.DajTjeme(2), t2.DajTjeme(3))) return true;
    else if(std::fabs((stranica1_a/stranica2_a)-(stranica1_b/stranica2_c))<Eps && std::fabs((stranica1_a/stranica2_a)-(stranica1_c/stranica2_b))<Eps && t1.Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(1), t2.DajTjeme(3), t2.DajTjeme(2))) return true;
    else if(std::fabs((stranica1_a/stranica2_b)-(stranica1_b/stranica2_c))<Eps && std::fabs((stranica1_a/stranica2_b)-(stranica1_c/stranica2_a))<Eps && t1.Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(2), t2.DajTjeme(3), t2.DajTjeme(1))) return true;
    else if(std::fabs((stranica1_a/stranica2_b)-(stranica1_b/stranica2_a))<Eps && std::fabs((stranica1_a/stranica2_b)-(stranica1_c/stranica2_c))<Eps && t1.Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(2), t2.DajTjeme(1), t2.DajTjeme(3))) return true;
    else if(std::fabs((stranica1_a/stranica2_c)-(stranica1_b/stranica2_b))<Eps && std::fabs((stranica1_a/stranica2_c)-(stranica1_c/stranica2_a))<Eps && t1.Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(3), t2.DajTjeme(2), t2.DajTjeme(1))) return true;
    else if(std::fabs((stranica1_a/stranica2_c)-(stranica1_b/stranica2_a))<Eps && std::fabs((stranica1_a/stranica2_c)-(stranica1_c/stranica2_b))<Eps && t1.Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==t2.Orijentacija(t2.DajTjeme(3), t2.DajTjeme(1), t2.DajTjeme(2))) return true;
    else return false;
}