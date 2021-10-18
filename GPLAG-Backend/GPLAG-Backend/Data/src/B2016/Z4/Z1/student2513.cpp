/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>
#include <utility>
typedef  std::pair<double, double>Tacka;



bool jednaki(double a, double b)
{
    return fabs(a-b)<0.000001;
}

class Trougao
{
    Tacka A,B,C;

public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0)
            throw std::domain_error("Nekorektne pozicije tjemena");
        A=t1;
        B=t2;
        C=t3;
    }
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        A=t1;
        B=t2;
        C=t3;
    }
    void Postavi (int indeks, const Tacka &t) {
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) A=t;
        if(indeks==2) B=t;
        if(indeks==3) C=t;
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))>0)
            return 1;
        else return -1;
    }
    Tacka DajTjeme (int indeks) const {
        if(indeks<1 || indeks >3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return A;
        else if(indeks==2) return B;
        else return C;
    }

    double DajStranicu (int indeks) const {
        if(indeks<1 || indeks >3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return sqrt((B.first-C.first)*(B.first-C.first)+(B.second-C.second)*(B.second-C.second));
        else if(indeks==2) return sqrt((A.first-C.first)*(A.first-C.first)+(A.second-C.second)*(A.second-C.second));
        else return sqrt((A.first-B.first)*(A.first-B.first)+(A.second-B.second)*(A.second-B.second));
    }
    double DajUgao (int indeks) const {
        double ugao;
        if(indeks==1) {
            ugao=((*this).DajStranicu(2)*(*this).DajStranicu(2)+(*this).DajStranicu(3)*(*this).DajStranicu(3)-
                  (*this).DajStranicu(1)*(*this).DajStranicu(1))/(2*(*this).DajStranicu(2)*(*this).DajStranicu(3));
        }

        if(indeks==2) {
            ugao=((*this).DajStranicu(1)*(*this).DajStranicu(1)+(*this).DajStranicu(3)*(*this).DajStranicu(3)-
                  (*this).DajStranicu(2)*(*this).DajStranicu(2))/(2*(*this).DajStranicu(1)*(*this).DajStranicu(3));
        }

        if(indeks==3) {
            ugao=((*this).DajStranicu(2)*(*this).DajStranicu(2)+(*this).DajStranicu(1)*(*this).DajStranicu(1)-
                  (*this).DajStranicu(3)*(*this).DajStranicu(3))/(2*(*this).DajStranicu(2)*(*this).DajStranicu(1));
        }
        ugao=acos(ugao);
        return (ugao*atan(1)*4)/180;

    }

    Tacka DajCentar() const {
        Tacka centar;
        centar.first=(A.first+B.first+C.first)/3;
        centar.second=(A.second+B.second+C.second)/3;
        return centar;
    }
    double DajObim() const {
        return (sqrt((B.first-C.first)*(B.first-C.first)+(B.second-C.second)*(B.second-C.second))+
                sqrt((A.first-C.first)*(A.first-C.first)+(A.second-C.second)*(A.second-C.second))
                +sqrt((A.first-B.first)*(A.first-B.first)+(A.second-B.second)*(A.second-B.second)));
    }
    double DajPovrsinu() const {
        return abs((A.first*(B.second-C.second)-B.first*(A.second-C.second)+C.first*(A.second-B.second)))/2;
    }
    bool DaLiJePozitivnoOrijentiran() const {
        if(Orijentacija(this->A,this->B,this->C)) return true;
        else return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const {
        if(Orijentacija(A,B,C)==Orijentacija(A,B,t)==Orijentacija(B,C,t)==Orijentacija(C,A,t)) return true;
        return false;
    }
    void Ispisi()const {
        std::cout<<"("<<"("<<A.first<<","<<A.second<<")"<<","<<"("<<B.first<<","<<B.second<<")"<<","<<"("<<C.first<<","<<C.second<<")"<<")";
    }
    void Transliraj(double delta_x, double delta_y) {
        A.first=A.first+delta_x;
        B.first=B.first+delta_x;
        C.first=C.first+delta_x;
        A.second=A.second+delta_y;
        B.second=B.second+delta_y;
        C.second=C.second+delta_y;
    }
    void Centriraj (const Tacka &t) {
        Tacka pomocna=(*this).DajCentar();
        Transliraj(t.first-pomocna.first,t.second-pomocna.second);
    }

    void Rotiraj (const Tacka &t, double ugao) {
        A.first=(t.first+(A.first-t.first)*cos(ugao)-(A.second-t.second)*sin(ugao));
        A.second=(t.second+(A.first-t.first)*sin(ugao)+(A.second-t.second)*cos(ugao));
        B.first=(t.first+(B.first-t.first)*cos(ugao)-(B.second-t.second)*sin(ugao));
        B.second=(t.second+(B.first-t.first)*sin(ugao)+(B.second-t.second)*cos(ugao));
        C.first=(t.first+(C.first-t.first)*cos(ugao)-(C.second-t.second)*sin(ugao));
        C.second=(t.second+(C.first-t.first)*sin(ugao)+(C.second-t.second)*cos(ugao));
    }
    void Skaliraj(const Tacka &t, double faktor) {
        A.first=(t.first+faktor*(A.first-t.first));
        A.second=(t.second+faktor*(A.second-t.second));
        B.first=(t.first+faktor*(B.first-t.first));
        B.second=(t.second+faktor*(B.second-t.second));
        C.first=(t.first+faktor*(C.first-t.first));
        C.second=(t.second+faktor*(C.second-t.second));
    }
    void Rotiraj (double ugao) {
        Tacka t=(*this).DajCentar();
        A.first=(t.first+(A.first-t.first)*cos(ugao)-(A.second-t.second)*sin(ugao));
        A.second=(t.second+(A.first-t.first)*sin(ugao)+(A.second-t.second)*cos(ugao));
        B.first=(t.first+(B.first-t.first)*cos(ugao)-(B.second-t.second)*sin(ugao));
        B.second=(t.second+(B.first-t.first)*sin(ugao)+(B.second-t.second)*cos(ugao));
        C.first=(t.first+(C.first-t.first)*cos(ugao)-(C.second-t.second)*sin(ugao));
        C.second=(t.second+(C.first-t.first)*sin(ugao)+(C.second-t.second)*cos(ugao));
    }
    void Skaliraj(double faktor) {
        Tacka t=(*this).DajCentar();
        A.first=(t.first+faktor*(A.first-t.first));
        A.second=(t.second+faktor*(A.second-t.second));
        B.first=(t.first+faktor*(B.first-t.first));
        B.second=(t.second+faktor*(B.second-t.second));
        C.first=(t.first+faktor*(C.first-t.first));
        C.second=(t.second+faktor*(C.second-t.second));
    }
    friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2) {
         std::vector<Tacka>v;
        v.push_back(t2.A);
        v.push_back(t2.B);
        v.push_back(t2.C);
        for(int i=0; i<3;i++){
            if(jednaki(t1.A.first,v[i].first) && jednaki(t1.A.second,v[i].second)){
                v.erase(v.begin()+i);
                i--;
            }
        }
         for(int i=0; i<v.size();i++){
            if(jednaki(t1.B.first,v[i].first) && jednaki(t1.B.second,v[i].second)){
                v.erase(v.begin()+i);
                i--;
            }
        }
         for(int i=0; i<v.size();i++){
            if(jednaki(t1.C.first,v[i].first) && jednaki(t1.C.second,v[i].second)){
                v.erase(v.begin()+i);
                i--;
                }
          
            }
            if(v.size()==0) return true;
        return false;
        
    }
    

    friend bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2) {
        std::vector<std::pair<double, Tacka>>v;
        
        v.push_back(std::pair<double,Tacka>(t1.DajStranicu(1),t1.A));
        v.push_back(std::pair<double,Tacka>(t1.DajStranicu(2),t1.B));
        v.push_back(std::pair<double,Tacka>(t1.DajStranicu(3),t1.C));

        std::vector<std::pair<double, Tacka>>v1;
        v1.push_back(std::pair<double,Tacka>(t2.DajStranicu(1),t2.A));
        v1.push_back(std::pair<double,Tacka>(t2.DajStranicu(2),t2.B));
        v1.push_back(std::pair<double,Tacka>(t2.DajStranicu(3),t2.C));

        sort(v.begin(),v.end(),[](const std::pair<double,Tacka>a, const std::pair<double,Tacka>b) {
            return(a.first>b.first);
        });
        sort(v1.begin(),v1.end(),[](const std::pair<double,Tacka>a, const std::pair<double,Tacka>b) {
            return(a.first>b.first);
        }
    );
    bool logicka=1;
    for(int i=0; i<3; i++) {
    if(!jednaki(v[i].first,v1[i].first)) {
            logicka=false;
            return false;

        }
    }
    if(Orijentacija(v[0].second,v[1].second,v[2].second)==Orijentacija(v1[0].second,v1[1].second,v1[2].second)) return true;
        return false;
    }
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    std::vector<std::pair<double, Tacka>>v;
    v.push_back(std::pair<double, Tacka>(t1.DajUgao(1),t1.A));
    v.push_back(std::pair<double, Tacka>(t1.DajUgao(2),t1.B));
    v.push_back(std::pair<double, Tacka>(t1.DajUgao(3),t1.C));

    std::vector<std::pair<double, Tacka>>v1;
    v1.push_back(std::pair<double, Tacka>(t2.DajUgao(1),t2.A));
    v1.push_back(std::pair<double, Tacka>(t2.DajUgao(2),t2.B));
    v1.push_back(std::pair<double, Tacka>(t2.DajUgao(3),t2.C));

    std::sort(v.begin(),v.end(),[](const std::pair<double,Tacka>a, const std::pair<double,Tacka>b) {
        return(a.first>b.first);
    });
    std::sort(v1.begin(),v1.end(),[](const std::pair<double,Tacka>a, const std::pair<double,Tacka>b) {
        return(a.first>b.first);
    }
);
bool logicka=1;
for(int i=0; i<3; i++)
{
if(!jednaki(v[i].first,v1[i].first)) {
        logicka=false;
        return false;

    }
}
if(Orijentacija(v[0].second,v[1].second,v[2].second)==Orijentacija(v1[0].second,v1[1].second,v1[2].second)) return true;
    return false;
}
};

bool IspravanUnosTrougla(Trougao pomocni)
{
    if(jednaki(pomocni.DajStranicu(1)+pomocni.DajStranicu(2),pomocni.DajStranicu(3))) return false;
    return true;
}

int main ()
{
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>>v;
    int k=0;

    while(k<n) {
        try {
            std::cout<<"Unesite podatke za "<<k+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            Tacka tacka1, tacka2, tacka3;
            std::cin>>tacka1.first>>tacka1.second>>tacka2.first>>tacka2.second>>tacka3.first>>tacka3.second;
            Trougao pomocni(tacka1,tacka2,tacka3);
            auto p=std::make_shared<Trougao>(tacka1,tacka2,tacka3);
            v.push_back(p);
        } catch(std::domain_error err) {
            std::cout<<err.what()<<std::endl;
            k--;
        }
        k++;
    }

    double x,y;
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>x>>y;
    transform(v.begin(),v.end(),v.begin(), [x,y](std::shared_ptr<Trougao>p) {
        (*p).Transliraj(x,y);
        return p;
    });
    std::cout<<"Unesite ugao rotacije: ";
    double ugao;
    std::cin>>ugao;
    transform(v.begin(),v.end(),v.begin(), [ugao](std::shared_ptr<Trougao>p) {
        Tacka t=(*p).DajCentar();
        (*p).Rotiraj(t,ugao);
        return p;
    });
    std::cout<<"Unesite faktor skaliranja: ";
    std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
    double faktor;
    std::cin>>faktor;

    transform(v.begin(),v.end(),v.begin(), [faktor](std::shared_ptr<Trougao>p) {
        Tacka t=(*p).DajTjeme(1);
        (*p).Skaliraj(t,faktor);
        return p;
    });
    sort(v.begin(),v.end(), [](std::shared_ptr<Trougao>p,std::shared_ptr<Trougao>p1) {
        return((*p).DajPovrsinu()<(*p1).DajPovrsinu());
    });

    std::for_each(v.begin(),v.end(),[](std::shared_ptr<Trougao>p) {
        std::cout<<"("<<"("<<((*p).DajTjeme(1)).first<<","<<((*p).DajTjeme(1)).second<<")"<<","
        <<"("<<((*p).DajTjeme(2)).first<<","<<((*p).DajTjeme(2)).second<<")"
        <<","<<"("<<((*p).DajTjeme(3)).first<<","<<((*p).DajTjeme(3)).second<<"))"<<std::endl;
    });
    Trougao tmin_obima=**(min_element(v.begin(),v.end(),[](std::shared_ptr<Trougao>p,std::shared_ptr<Trougao>p1) {
        return ((*p).DajObim()<(*p1).DajObim());
    }));
    std::cout<<"Trougao sa najmanjim obimom: "<<"(("<<(tmin_obima.DajTjeme(1)).first<<","<<(tmin_obima.DajTjeme(1)).second<<"),("
    <<(tmin_obima.DajTjeme(2)).first<<","<<(tmin_obima.DajTjeme(2)).second<<"),("
    <<(tmin_obima.DajTjeme(3)).first<<","<<(tmin_obima.DajTjeme(3)).second<<"))"<<std::endl;
    
    
    std::cout<<"Parovi identicnih trouglova:"<<std::endl;
    for(int i=0; i<n;i++){
        for(int j=i+1; j<n;j++){
            if(DaLiSuIdenticni(*v[i],*v[j])){
                v[i]->Ispisi();
                std::cout<<" i ";
                v[j]->Ispisi();
                std::cout<<std::endl;
            }
        }
    }
    std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
    for(int i=0; i<n;i++){
        for(int j=i+1; j<n;j++){
            if(DaLiSuPodudarni(*v[i],*v[j])){
                v[i]->Ispisi();
                std::cout<<" i ";
                v[j]->Ispisi();
            }
        }
    }
    std::cout<<"Parovi slicnih trouglova:"<<std::endl;
    for(int i=0; i<n;i++){
        for(int j=i+1; j<n;j++){
            if(DaLiSuSlicni(*v[i],*v[j])){
                v[i]->Ispisi();
                std::cout<<" i ";
                v[j]->Ispisi();
                std::cout<<std::endl;
            }
        }
    }
    


    return 0;
}