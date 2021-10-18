/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>

const double E(1e-10);

typedef std::pair<double, double> Tacka;


class Trougao {
    Tacka A,B,C;
    static bool ocelto(const double &a, const double &b){
        return std::fabs(a-b)<= E*(std::fabs(a)+std::fabs(b));
    }
    public:
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        A=t1;
        B=t2;
        C=t3;
    }
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
        A=t1;
        B=t2;
        C=t3;
    }
    void Postavi (int indeks, const Tacka &t){
        if(indeks==1){
            if(Orijentacija(t,B,C)!=0) A=t;
            else throw std::domain_error("Nekorektne pozicije tjemena");
        }
        else if(indeks==2) {
            if(Orijentacija(A,t,C)!=0) B=t;
            else throw std::domain_error("Nekorektne pozicije tjemena");
        }
        else if(indeks==3) {
            if(Orijentacija(A,B,t)!=0) C=t;
            else throw std::domain_error("Nekorektne pozicije tjemena");
        }
            else throw std::range_error("Nekorektan indeks");
    }
    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double s;
        s=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
        if(s>0) return 1; //pozitivna orijentacija
        else if(s<0) return -1;  // negativna
        else return 0; //kolinearne
    }
    Tacka DajTjeme(int indeks) const{
        if(indeks==1) return A;
        else if(indeks==2) return B;
        else if(indeks==3) return C;
        else throw std::range_error("Nekorektan indeks");
    }
    double DajStranicu(int indeks) const{
        double d;
        if(indeks==1) d=sqrt((B.first-C.first)*(B.first-C.first)+(B.second-C.second)*(B.second-C.second));
        else if(indeks==2) d=sqrt((A.first-C.first)*(A.first-C.first)+(A.second-C.second)*(A.second-C.second));
        else if(indeks==3) d=sqrt((B.first-A.first)*(B.first-A.first)+(B.second-A.second)*(B.second-A.second));
        else throw std::range_error("Nekorektan indeks");
        return d;
    }
            
            
    double DajUgao(int indeks) const{
        double a, b,c,u;
        a=sqrt((B.first-C.first)*(B.first-C.first)+(B.second-C.second)*(B.second-C.second));
        b=sqrt((A.first-C.first)*(A.first-C.first)+(A.second-C.second)*(A.second-C.second));
        c=sqrt((B.first-A.first)*(B.first-A.first)+(B.second-A.second)*(B.second-A.second));
        if(indeks==1) u=(b*b+c*c-a*a)/(2*b*c);
        else if(indeks==2) u=(a*a+c*c-b*b)/(2*a*c);
        else if(indeks==3) u=(a*a+b*b-c*c)/(2*a*b);
        else throw std::range_error("Nekorektan indeks");
        return acos(u);
    }
    Tacka DajCentar() const{
        double x,y;
        x=(A.first+B.first+C.first)/3;
        y=(A.second+B.second+C.second)/3;
        Tacka d=std::make_pair(x,y);
        return d;
    }
    double DajObim() const{
        double o, a, b,c;
        a=sqrt((B.first-C.first)*(B.first-C.first)+(B.second-C.second)*(B.second-C.second));
        b=sqrt((A.first-C.first)*(A.first-C.first)+(A.second-C.second)*(A.second-C.second));
        c=sqrt((A.first-B.first)*(A.first-B.first)+(A.second-B.second)*(A.second-B.second));
        o=a+b+c;
        return o;
    }
    double DajPovrsinu() const{
        double p;
        p=fabs(A.first*(B.second-C.second)-B.first*(A.second-C.second)+C.first*(A.second-B.second));
        return p/2;
    }
    bool DaLiJePozitivnoOrijentiran() const{
        if(Orijentacija(A,B,C)==1) return true;
        else return false;
    }
    bool DaLiJeUnutra (const Tacka &t) const{
        int p=Orijentacija(A,B,C);
        bool a=true;
        if(Orijentacija(A,B,t)!=p && Orijentacija(A,B,t)!=0) a=false;
        if(Orijentacija(B,C,t)!=p && Orijentacija(B,C,t)!=0) a=false;
        if(Orijentacija(C,A,t)!=p && Orijentacija(C,A,t)!=0) a=false;
        if(Orijentacija(B,C,t)!=p && Orijentacija(B,C,t)!=0) a=false;
        
        return a;
    }
    void Ispisi() const{
        std::cout << "(("<<A.first<<","<<A.second<<"),("<<B.first<<","<<B.second<<"),("<<C.first<<","<<C.second<<"))";
    }
    void Transliraj(double dx, double dy){
        A.first+=dx;
        A.second+=dy;
        B.first+=dx;
        B.second+=dy;
        C.first+=dx;
        C.second+=dy;
    }
    void Centriraj(const Tacka &t){
        Tacka teziste;
        teziste.first=(A.first+B.first+C.first)/3;
        teziste.second=(A.second+B.second+C.second)/3;
        double dx, dy;
        dx=t.first-teziste.first;
        dy=t.second-teziste.second;
        A.first+=dx;
        A.second+=dy;
        B.first+=dx;
        B.second+=dy;
        C.first+=dx;
        C.second+=dy;
    }
    void Rotiraj(const Tacka &t, double u){
        Tacka s;
        s.first=t.first+(A.first-t.first)*cos(u)-(A.second-t.second)*sin(u);
        s.second=t.second+(A.first-t.first)*sin(u)+(A.second-t.second)*cos(u);
        A=s;
        s.first=t.first+(B.first-t.first)*cos(u)-(B.second-t.second)*sin(u);
        s.second=t.second+(B.first-t.first)*sin(u)+(B.second-t.second)*cos(u);
        B=s;
        s.first=t.first+(C.first-t.first)*cos(u)-(C.second-t.second)*sin(u);
        s.second=t.second+(C.first-t.first)*sin(u)+(C.second-t.second)*cos(u);
        C=s;
    }
    void Skaliraj(const Tacka &t, double f){
        if(ocelto(f,0)) throw std::domain_error("Nekorektan faktor skaliranja");
        else {
            A.first=t.first+f*(A.first-t.first);
            A.second=t.second+f*(A.second-t.second);
            B.first=t.first+f*(B.first-t.first);
            B.second=t.second+f*(B.second-t.second);
            C.first=t.first+f*(C.first-t.first);
            C.second=t.second+f*(C.second-t.second);
        }
    }
    void Rotiraj(double u){
        Tacka t;
        t.first=(A.first+B.first+C.first)/3;
        t.second=(A.second+B.second+C.second)/3;
        Tacka s;
        s.first=t.first+(A.first-t.first)*cos(u)-(A.second-t.second)*sin(u);
        s.second=t.second+(A.first-t.first)*sin(u)+(A.second-t.second)*cos(u);
        A=s;
        s.first=t.first+(B.first-t.first)*cos(u)-(B.second-t.second)*sin(u);
        s.second=t.second+(B.first-t.first)*sin(u)+(B.second-t.second)*cos(u);
        B=s;
        s.first=t.first+(C.first-t.first)*cos(u)-(C.second-t.second)*sin(u);
        s.second=t.second+(C.first-t.first)*sin(u)+(C.second-t.second)*cos(u);
        C=s;
        
    }
    void Skaliraj (double f){
        if(ocelto(f,0)) throw std::domain_error("Nekorektan faktor skaliranja");
        else{
            Tacka t;
            t.first=(A.first+B.first+C.first)/3;
            t.second=(A.second+B.second+C.second)/3;
            A.first=t.first+f*(A.first-t.first);
            A.second=t.second+f*(A.second-t.second);
            B.first=t.first+f*(B.first-t.first);
            B.second=t.second+f*(B.second-t.second);
            C.first=t.first+f*(C.first-t.first);
            C.second=t.second+f*(C.second-t.second);
        }
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
        std::vector<std::pair<double,double>> v, v2;
        v.push_back(t1.A);
        v.push_back(t1.B);
        v.push_back(t1.C);
        v2.push_back(t2.A);
        v2.push_back(t2.B);
        v2.push_back(t2.C);
        std::sort(v.begin(),v.end(),[](Tacka a, Tacka b){
            if(ocelto(a.first,b.first)) return a.second<b.second;
            else return a.first<b.first;
        });
        std::sort(v2.begin(), v2.end(), [] (Tacka a, Tacka b){
            if(ocelto(a.first,b.first)) return a.second<b.second;
            else return a.first<b.first;
        });
        
        if(v==v2) return true;
        else return false;
        
    }
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
        std::vector<std::pair<Tacka, double>> v1,v2;
        double a, b,c;
        a=sqrt((t1.B.first-t1.C.first)*(t1.B.first-t1.C.first)+(t1.B.second-t1.C.second)*(t1.B.second-t1.C.second));
        b=sqrt((t1.A.first-t1.C.first)*(t1.A.first-t1.C.first)+(t1.A.second-t1.C.second)*(t1.A.second-t1.C.second));
        c=sqrt((t1.A.first-t1.B.first)*(t1.A.first-t1.B.first)+(t1.A.second-t1.B.second)*(t1.A.second-t1.B.second));
        v1.push_back(std::make_pair(t1.A,a));
        v1.push_back(std::make_pair(t1.B,b));
        v1.push_back(std::make_pair(t1.C,c));
        a=sqrt((t2.B.first-t2.C.first)*(t2.B.first-t2.C.first)+(t2.B.second-t2.C.second)*(t2.B.second-t2.C.second));
        b=sqrt((t2.A.first-t2.C.first)*(t2.A.first-t2.C.first)+(t2.A.second-t2.C.second)*(t2.A.second-t2.C.second));
        c=sqrt((t2.A.first-t2.B.first)*(t2.A.first-t2.B.first)+(t2.A.second-t2.B.second)*(t2.A.second-t2.B.second));
        v2.push_back(std::make_pair(t2.A,a));
        v2.push_back(std::make_pair(t2.B,b));
        v2.push_back(std::make_pair(t2.C,c));
        
        std::sort(v1.begin(),v1.end(),[](std::pair<Tacka,double> a, std::pair<Tacka,double> b){
           return  a.second>b.second;
        });
        std::sort(v2.begin(),v2.end(),[](std::pair<Tacka,double> a, std::pair<Tacka,double> b){
            return a.second>b.second;
        });
        
        if(Orijentacija(v1[0].first,v1[1].first,v1[2].first)!=Orijentacija(v2[0].first, v2[1].first, v2[2].first)) return false;
        else {
            for(int i(0);i<3;i++) if(!ocelto(v1[i].second, v2[i].second)) return false;
        }
        return true;
    }
    
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
        if(DaLiSuPodudarni(t1,t2)) return true;
        double a,b,c,a2,b2,c2, delta;
        bool hajzivbio(false);
        a=sqrt((t1.B.first-t1.C.first)*(t1.B.first-t1.C.first)+(t1.B.second-t1.C.second)*(t1.B.second-t1.C.second));
        b=sqrt((t1.A.first-t1.C.first)*(t1.A.first-t1.C.first)+(t1.A.second-t1.C.second)*(t1.A.second-t1.C.second));
        c=sqrt((t1.A.first-t1.B.first)*(t1.A.first-t1.B.first)+(t1.A.second-t1.B.second)*(t1.A.second-t1.B.second));
        a2=sqrt((t2.B.first-t2.C.first)*(t2.B.first-t2.C.first)+(t2.B.second-t2.C.second)*(t2.B.second-t2.C.second));
        b2=sqrt((t2.A.first-t2.C.first)*(t2.A.first-t2.C.first)+(t2.A.second-t2.C.second)*(t2.A.second-t2.C.second));
        c2=sqrt((t2.A.first-t2.B.first)*(t2.A.first-t2.B.first)+(t2.A.second-t2.B.second)*(t2.A.second-t2.B.second));
        
        if(ocelto(a/a2,b/b2) && ocelto(a/a2,c/c2)){
            hajzivbio=true;
            delta=a/a2;
        } 
        else if(ocelto(a/a2,b/c2) && ocelto(a/a2,c/b2)){
            hajzivbio=true;
            delta=a/a2;
        }
        else if(ocelto(a/b2,b/c2) && ocelto(a/b2,c/a2)){
            hajzivbio=true;
            delta=a/b2;
        }
        else if(ocelto(a/b2,b/a2) && ocelto(a/b2,c/c2)){
            hajzivbio=true;
            delta=a/b2;
        }
        else if(ocelto(a/c2,b/a2) && ocelto(a/c2,c/b2)){
            hajzivbio=true;
            delta=a/c2;
        }
        else if(ocelto(a/c2,b/b2) && ocelto(a/c2,c/a2)){
            hajzivbio=true;
            delta=a/c2;
        }
        if(hajzivbio){
            Trougao T(t2);
            T.Skaliraj(delta);
            if(DaLiSuPodudarni(t1,T)==true) return true;
            else return false;
        }
        else return false;
}
};


int main ()
{
    
    std::cout << "Koliko zelite kreirati trouglova: ";
    int n;
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    double x,y,z,a,b,c;
    try{
    for(int i(0);i<n;i++){
        std::cout << "Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin >> x>>a>>y>>b>>z>>c;
        try{
            v[i]=std::make_shared<Trougao>(Trougao(Tacka(x,a),Tacka(y,b),Tacka(z,c)));
        }
        catch(std::domain_error izuzetak){
            std::cout << izuzetak.what()<<", ponovite unos!"<<std::endl;
            i--;
        }
        
    }
    }
    catch(std::bad_alloc){
        for(int j(0);j<n;j++) v[j]=nullptr;
    }
    std::cout << "Unesite vektor translacije (dx dy): ";
    double dx, dy;
    std::cin>> dx >> dy;
    std::cout << "Unesite ugao rotacije: ";
    double u;
    std::cin >> u;
    std::cout << "Unesite faktor skaliranja: ";
    double f;
    std::cin >> f;
    
    std::transform(v.begin(), v.end(), v.begin(), [=] (std::shared_ptr<Trougao> p){
        p->Transliraj(dx,dy);
        p->Rotiraj(p->DajCentar(), u);
        p->Skaliraj(p->DajTjeme(1), f);
        return p;
    });
    
    std::sort(v.begin(), v.end(), [](std::shared_ptr<Trougao> ajmoprvi, std::shared_ptr<Trougao> ajmodrugi){
        return ajmoprvi->DajPovrsinu() < ajmodrugi->DajPovrsinu();
    });

    std::cout << "Trouglovi nakon obavljenih transformacija:"<<std::endl;  // ispisati trouglove
    std::for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> papak){
        papak->Ispisi(); std::cout << std::endl;
    });
    
    auto wannabenajveci=std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> onbi, std::shared_ptr<Trougao> ovajmuneda){
       return onbi->DajObim()<ovajmuneda->DajObim(); 
    });
    std::cout << "Trougao sa najmanjim obimom: ";
    //ispisi pa taj trougao
    (*wannabenajveci)->Ispisi();
    std::cout << std::endl;
    
    int br(0);
    for(int i(0);i<v.size();i++){
        for(int j(i+1);j<v.size();j++){
            if(DaLiSuIdenticni(*v[i],*v[j])){
                if(br==0) std::cout << "Parovi identicnih trouglova:"<<std::endl;
                br++;
                v[i]->Ispisi();
                std::cout << " i ";
                v[j]->Ispisi();
                std::cout << std::endl;
            }
        }
    }
    if(br==0) std::cout << "Nema identicnih trouglova!" << std::endl;
    
    br=0;
    for(int i(0);i<v.size();i++){
        for(int j(i+1);j<v.size();j++){
            if(DaLiSuPodudarni(*v[i],*v[j])){
                if(br==0) std::cout << "Parovi podudarnih trouglova:"<<std::endl;
                br++;
                v[i]->Ispisi();
                std::cout << " i ";
                v[j]->Ispisi();
                std::cout << std::endl;
            }
        }
    }
    if(br==0) std::cout << "Nema podudarnih trouglova!" << std::endl;
    
    br=0;
    for(int i(0);i<v.size();i++){
        for(int j(i+1);j<v.size();j++){
            if(DaLiSuSlicni(*v[i],*v[j])){
                if(br==0) std::cout << "Parovi slicnih trouglova:"<<std::endl;
                br++;
                v[i]->Ispisi();
                std::cout << " i ";
                v[j]->Ispisi();
                std::cout << std::endl;
            }
        }
    }
    if(br==0) std::cout << "Nema slicnih trouglova!" << std::endl;
    
    for(int i(0);i<v.size();i++) v[i]=nullptr;
    
    
	return 0;
}
