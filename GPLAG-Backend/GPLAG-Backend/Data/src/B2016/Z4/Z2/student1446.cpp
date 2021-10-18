#include <iostream>
#include <stdexcept>
#include <new>
#include <algorithm>
struct Tacka {
 double x, y;
};
enum Pozicija {GoreLijevo, GoreDesno, DoljeLijevo, DoljeDesno};
enum Smjer {Nalijevo, Nadesno};
class NepreklapajuciPravougaonik{
    Tacka a,b,c,d;
    public:
    NepreklapajuciPravougaonik(const Tacka &t1,const  Tacka &t2);
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
    void Transliraj(double delta_x, double delta_y);
    void Rotiraj( Tacka t, Smjer s);
    void Ispisi() const;
    friend bool DaLiSuPodudarni( NepreklapajuciPravougaonik &p1,  NepreklapajuciPravougaonik &p2);
    friend bool DaLiSuSlicni( NepreklapajuciPravougaonik &p1,  NepreklapajuciPravougaonik &p2);
    friend bool DaLiSePresjecaju(NepreklapajuciPravougaonik &p1, NepreklapajuciPravougaonik &p2);
};
void NepreklapajuciPravougaonik::Postavi(const Tacka &t1,const  Tacka &t2){
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
NepreklapajuciPravougaonik::NepreklapajuciPravougaonik(const Tacka &t1,const  Tacka &t2){
    Postavi(t1,t2);
}
void NepreklapajuciPravougaonik::Postavi(Pozicija p,  Tacka &t){
    if(p==Pozicija::GoreLijevo) Postavi(t,d);
    if(p==Pozicija::GoreDesno) Postavi(a,t);   
    if(p==Pozicija::DoljeLijevo) Postavi(t,c);
    if(p==Pozicija::DoljeDesno) Postavi(b,t);
}
void NepreklapajuciPravougaonik::Centriraj(const Tacka &t){
    double f((b.y-a.y)/2);
    double g((c.x-b.x)/2);
    a.x=t.x-g;  a.y=t.y-f;
    b.x=a.x;    b.y=t.y+f;
    c.x=t.x+g;  c.y=b.y;
    d.x=c.x;    d.y=a.y;
}
Tacka NepreklapajuciPravougaonik:: DajTjeme(Pozicija p) const{
    if(p==Pozicija::DoljeLijevo)return a;
    if(p==Pozicija::GoreLijevo)return b;
    if(p==Pozicija::GoreDesno)return c;
    return d;
}
Tacka NepreklapajuciPravougaonik:: DajCentar() const{
    Tacka m;
    m.x=(c.x+b.x)/2;
    m.y=(b.y+a.y)/2;
    return m;
}
void NepreklapajuciPravougaonik::Transliraj(double delta_x, double delta_y){
    a.x+=delta_x;   a.y+=delta_y;
    b.x+=delta_x;   b.y+=delta_y;
    c.x+=delta_x;   c.y+=delta_y;
    d.x+=delta_x;   d.y+=delta_y;
}
void NepreklapajuciPravougaonik::Rotiraj( Tacka t, Smjer s){
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
void NepreklapajuciPravougaonik::Ispisi() const{
    std::cout << "{{"<<b.x<<","<<b.y<<"}"<<","<<"{"<<d.x<<","<<d.y<<"}}" ;
}
bool DaLiSuPodudarni( NepreklapajuciPravougaonik &p1,  NepreklapajuciPravougaonik &p2){
    try{
        if(DaLiSePresjecaju(p1,p2))throw std::logic_error ("Nedozvoljeno preklapanje");
        if(p1.DajHorizontalnu()==(p2.DajHorizontalnu()||p2.DajVertikalnu()) && p1.DajVertikalnu()==(p2.DajHorizontalnu()||p2.DajVertikalnu()))return true;
    }
    catch(std::logic_error greska){
        std::cout << greska.what() << std::endl;
    }
    return false;
}
bool DaLiSuSlicni( NepreklapajuciPravougaonik &p1,  NepreklapajuciPravougaonik &p2){
    try{
    if(DaLiSePresjecaju(p1,p2))throw std::logic_error ("Nedozvoljeno preklapanje");
    if(p1.DajHorizontalnu() / p2.DajHorizontalnu() == p1.DajVertikalnu() / p2.DajVertikalnu())return true;
    }
    catch(std::logic_error greska){
        std::cout << greska.what() << std::endl;
    }
    return false;
}
bool DaLiSePresjecaju(NepreklapajuciPravougaonik &p1, NepreklapajuciPravougaonik &p2){
     if((p2.d.x>=p1.b.x && p2.d.x<=p1.d.x && p2.c.y>=p1.b.y)||(p2.d.x>=p1.b.x && p2.d.x<=p1.d.x && p2.c.y<=p1.b.y)||(p2.b.x>=p1.b.x && p2.b.x<=p1.d.x && p2.c.y>=p1.b.y)||(p2.b.x>=p1.b.x && p2.b.x<=p1.d.x && p2.c.y<=p1.b.y))
        return true;
    return false;    
}
int main(){
    
    return 0;
}

