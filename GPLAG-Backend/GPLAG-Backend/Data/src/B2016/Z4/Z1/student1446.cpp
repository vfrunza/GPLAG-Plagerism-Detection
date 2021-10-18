#include <iostream>
#include <stdexcept>
#include <new>
#include <algorithm>
struct Tacka {
 double x, y;
};
enum Pozicija {GoreLijevo, GoreDesno, DoljeLijevo, DoljeDesno};
enum Smjer {Nalijevo, Nadesno};
class Pravougaonik{
    Tacka a,b,c,d;
    public:
    Pravougaonik(const Tacka &t1,const  Tacka &t2);
    void Postavi(const Tacka &t1,const  Tacka &t2);
    void Postavi(Pozicija p,  Tacka &t);
    void Centriraj(const Tacka &t);
    Tacka DajTjeme(Pozicija p) const;
    Tacka DajCentar() const;
    double DajHorizontalnu() const{
        return d.x-a.x;
    }
    double DajVertikalnu() const{
        return b.y-a.y;
    }
    double DajObim() const{
        return 2*DajHorizontalnu()+2*DajVertikalnu();
    }
    double DajPovrsinu() const{
        return DajHorizontalnu()*DajVertikalnu();
    }
    static Pravougaonik Presjek( Pravougaonik &p1,  Pravougaonik &p2);
    void Transliraj(double delta_x, double delta_y);
    void Rotiraj( Tacka t, Smjer s);
    void Ispisi() const;
    friend bool DaLiSePoklapaju( Pravougaonik &p1,  Pravougaonik &p2);
    friend bool DaLiSuPodudarni( Pravougaonik &p1,  Pravougaonik &p2);
    friend bool DaLiSuSlicni( Pravougaonik &p1,  Pravougaonik &p2);
};
void Pravougaonik::Postavi(const Tacka &t1,const  Tacka &t2){
    Tacka v(t1),n(t2);
    if(t1.x>t2.x){
        Tacka tmp(t1);
        v=n;
        n=tmp;
    }
    if(v.y<n.y){
        a=v;
        c=n;
        Tacka t3;
        t3.x=v.x;  t3.y=n.y;
        b=t3;
        Tacka t4;
        t4.x=n.x;  t4.y=v.y;
        d=t4;
    }
    if(v.y>n.y){
        b=v;
        d=n;
        Tacka t3;
        t3.x=v.x;  t3.y=n.y;
        a=t3;
        Tacka t4;
        t4.x=n.x;  t4.y=v.y;
        c=t4;
    }
}
Pravougaonik::Pravougaonik(const Tacka &t1,const  Tacka &t2){
    Postavi(t1,t2);
}
void Pravougaonik::Postavi(Pozicija p,  Tacka &t){
    if(p==Pozicija::GoreLijevo) Postavi(t,d);
    if(p==Pozicija::GoreDesno) Postavi(a,t);   
    if(p==Pozicija::DoljeLijevo) Postavi(t,c);
    if(p==Pozicija::DoljeDesno) Postavi(b,t);
}
void Pravougaonik::Centriraj(const Tacka &t){
    double f((b.y-a.y)/2);
    double g((c.x-b.x)/2);
    a.x=t.x-g;  a.y=t.y-f;
    b.x=a.x;    b.y=t.y+f;
    c.x=t.x+g;  c.y=b.y;
    d.x=c.x;    d.y=a.y;
}
Tacka Pravougaonik:: DajTjeme(Pozicija p) const{
    if(p==Pozicija::DoljeLijevo)return a;
    if(p==Pozicija::GoreLijevo)return b;
    if(p==Pozicija::GoreDesno)return c;
    return d;
}
Tacka Pravougaonik:: DajCentar() const{
    Tacka m;
    m.x=(c.x+b.x)/2;
    m.y=(b.y+a.y)/2;
    return m;
}
Pravougaonik Pravougaonik:: Presjek( Pravougaonik &p1,  Pravougaonik &p2){
    Pravougaonik q(p1);
    try{
        if(p1.d.x<p2.a.x || p2.d.x<p1.a.x)throw std::domain_error ("Pravougaonici se ne presjecaju");
        if(p1.a.y>p2.b.y || p2.a.y>p1.d.y)throw std::domain_error ("Pravougaonici se ne presjecaju");
        if(p2.d.x>=p1.b.x && p2.d.x<=p1.d.x && p2.c.y>=p1.b.y) q.Postavi(p1.b,p2.d);
        if(p2.d.x>=p1.b.x && p2.d.x<=p1.d.x && p2.c.y<=p1.b.y) q.Postavi(p1.a,p2.c);
        if(p2.b.x>=p1.b.x && p2.b.x<=p1.d.x && p2.c.y>=p1.b.y) q.Postavi(p2.a,p1.c);
        if(p2.b.x>=p1.b.x && p2.b.x<=p1.d.x && p2.c.y<=p1.b.y) q.Postavi(p2.b,p1.d);
    }
    catch(std::domain_error greska){
        std::cout << greska.what() << std::endl;
    }
    return q;
}
void Pravougaonik::Transliraj(double delta_x, double delta_y){
    a.x+=delta_x;   a.y+=delta_y;
    b.x+=delta_x;   b.y+=delta_y;
    c.x+=delta_x;   c.y+=delta_y;
    d.x+=delta_x;   d.y+=delta_y;
}
void Pravougaonik::Rotiraj( Tacka t, Smjer s){
    double q,w,e,r;
    if(s==Smjer::Nalijevo){
        q=t.x-c.x;  w=c.y-t.y;  e=t.x-a.x;  r=t.y-a.y;
        c.x=t.x-w;  c.y=t.y-q;  a.x=t.x+r;  a.y=t.y-e;
        d=a;    b=c;
        Postavi(b,d);
        Tacka tmp(b),tmp1(d);   b=a;    d=c;    a=tmp1; c=tmp;
    }
    if(s==Smjer::Nadesno){
        q=t.x-c.x;  w=c.y-t.y;  e=t.x-a.x;  r=t.y-a.y;
        c.x=t.x+w;  c.y=t.y+q;  a.x=t.x-r;  a.y=t.y+e;
        b=a;    d=c;
        Postavi(b,d);
    }
}//Popravi nije kako bi trebalo 
void Pravougaonik::Ispisi() const{
    std::cout << "{{"<<b.x<<","<<b.y<<"}"<<","<<"{"<<d.x<<","<<d.y<<"}}" ;
}
bool DaLiSePoklapaju( Pravougaonik &p1,  Pravougaonik &p2){
    if(p1.a.x==p2.a.x && p1.a.y==p2.a.y && p1.b.x==p2.b.x && p1.b.y==p2.b.y && p1.c.x==p2.c.x && p1.c.y==p2.c.y && p1.d.x==p2.d.x && p1.d.y==p2.d.y)return true;
    return false;
}
bool DaLiSuPodudarni( Pravougaonik &p1,  Pravougaonik &p2){
    if(p1.DajHorizontalnu()==(p2.DajHorizontalnu()||p2.DajVertikalnu()) && p1.DajVertikalnu()==(p2.DajHorizontalnu()||p2.DajVertikalnu()))return true;
    return false;
}
bool DaLiSuSlicni( Pravougaonik &p1,  Pravougaonik &p2){
    if(p1.DajHorizontalnu() / p2.DajHorizontalnu() == p1.DajVertikalnu() / p2.DajVertikalnu())return true;
    return false;
}
int main() {
    int k(0);
        std::cout<<"Unesite n: ";
        std::cin>>k;
        Pravougaonik** niz_pokazivaca{nullptr};
        niz_pokazivaca = new Pravougaonik*[k];
        for(int i=0;i<k;i++){
            try{
                Tacka a,b;
                std::cout<<"Unesite 1. tjeme pravougaonika "<<i+1<<": ";
                std::cin>>a.x>>a.y;
                std::cout<<"Unesite 2. tjeme pravougaonika "<<i+1<<": ";
                std::cin>>b.x>>b.y;
                niz_pokazivaca[i]=new Pravougaonik(a,b);
            }
            catch(std::logic_error greska){
                std::cout<<greska.what()<<std::endl;
                std::cout<<"Ponovite unos!"<<std::endl;
                std::cin.ignore(100, '\n');
                i--;
            }
        }
        double delta_x,delta_y;
        std::cout<<"Unesite podatke za transliranje (dx dy): ";
        std::cin>>delta_x>>delta_y;
        std::transform(niz_pokazivaca,niz_pokazivaca+k,niz_pokazivaca,[delta_x,delta_y](Pravougaonik* tmp){
            tmp->Transliraj(delta_x,delta_y);
            tmp->Rotiraj(tmp->DajCentar(),Smjer::Nadesno);
            return tmp;
        });
        std::cout<<"Pravougaonici, nakon transformacija: "<<std::endl;
        std::for_each(niz_pokazivaca,niz_pokazivaca+k,[](Pravougaonik* tmp){
            tmp->Ispisi();
            std::cout<<std::endl;
        });
        Pravougaonik** pmax=std::max_element(niz_pokazivaca,niz_pokazivaca+k,[](Pravougaonik* p1,Pravougaonik* p2){
            return (p1->DajPovrsinu())<(p2->DajPovrsinu());
        });
        std::cout<<"Pravougaonik s najvecom povrsinom: ";
        Pravougaonik* tmpmax=*pmax;
        tmpmax->Ispisi();
        for(int i=0;i<k;i++){
            delete niz_pokazivaca[i];
        }
        delete []niz_pokazivaca;
         
        return 0;
}

