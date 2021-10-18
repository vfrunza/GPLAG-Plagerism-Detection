/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include<stdexcept>
#include<memory>
#include<vector>
#include<algorithm>
#define E 0.0000000001
using namespace std;

typedef std::pair<double, double> Tacka;



class Trougao{
    Tacka a;
    Tacka b;
    Tacka c;
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(fabs((t2.first-t1.first)/(t3.first-t1.first)-(t2.second-t1.second)/(t3.second-t1.second))<E)throw domain_error("nije trougao");
    a=t1;b=t2;c=t3;
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(fabs((t2.first-t1.first)/(t3.first-t1.first)-(t2.second-t1.second)/(t3.second-t1.second))<E)throw domain_error("nije trougao");
    a=t1;b=t2;c=t3;
    }
    void Postavi(int indeks, const Tacka &t){
    if(indeks <1||indeks>3)throw range_error("nije indeks");
    if(indeks==1){
        if(fabs((b.first-t.first)/(c.first-t.first)-(b.second-t.second)/(c.second-t.second))<E){
            throw domain_error("nije trougao");
        }
        a=t;
    }
    if(indeks==2){
        if(fabs((t.first-a.first)/(c.first-a.first)-(t.second-a.second)/(c.second-a.second))<E){
                throw domain_error("nije trougao");
        }
        b=t;
        }
    if(indeks==3){
        if(fabs((b.first-a.first)/(t.first-a.first)-(b.second-a.second)/(t.second-a.second))<E){
                throw domain_error("nije trougao");
        }
        c=t;
    }

    }

static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(fabs((t1.first*(t2.second-t2.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second)))<E){
        throw domain_error("nije trougao");

   }
    return(t1.first*(t2.second-t2.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))/fabs((t1.first*(t2.second-t2.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second)));

}

Tacka DajTjeme(int indeks) const{
            if(indeks <1||indeks>3)throw range_error("nije indeks");
            if(indeks==1)return a;
            if(indeks==2)return b;
            return c;
           }
double DajStranicu(int indeks) const{
     if(indeks <1||indeks>3)throw range_error("nije indeks");
     if(indeks==1)return sqrt((b.first-c.first)*(b.first-c.first)+(b.second-c.second)*(b.second-c.second));
     if(indeks==2)return sqrt((a.first-c.first)*(a.first-c.first)+(a.second-c.second)*(a.second-c.second));
     if(indeks==3)return sqrt((b.first-a.first)*(b.first-a.first)+(b.second-a.second)*(b.second-a.second));
}

double DajUgao(int indeks) const{
    if(indeks <1||indeks>3)throw range_error("nije indeks");
    if(indeks==1)return acos((DajStranicu(1)*DajStranicu(1)-DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/2*DajStranicu(2)*DajStranicu(3));
    if(indeks==2)return acos((DajStranicu(2)*DajStranicu(2)-DajStranicu(1)*DajStranicu(1)-DajStranicu(3)*DajStranicu(3))/2*DajStranicu(1)*DajStranicu(3));
    if(indeks==1)return acos((DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2)-DajStranicu(1)*DajStranicu(1))/2*DajStranicu(2)*DajStranicu(1));

}

Tacka DajCentar() const{
    Tacka c;
    c.first=(a.first+b.first+c.first)/3;
    c.second=(a.second+b.second+c.second)/3;
return c;
}
double DajObim() const{
    return(DajStranicu(1)+DajStranicu(2)+DajStranicu(3));
}
double DajPovrsinu() const{
    double s =(DajObim())/2;

return(sqrt(s*s-DajStranicu(1)*s-DajStranicu(2)*s-DajStranicu(3)));
}
bool DaLiJePozitivnoOrijentiran() const{
if(Orijentacija(a,b,c)==1)return true;
return false;
}bool DaLiJeUnutra(const Tacka &t) const{
if(Orijentacija(a,b,c)==1&&Orijentacija(a,b,t)==1&&Orijentacija(b,c,t)==1&&Orijentacija(c,a,t)==1)return true;
return false;
}
void Ispisi() const{// “(( , ),( , ),( , ))

cout<<"(("<<a.first<<","<<a.second<<"),("<<b.first<<","<<b.second<<"),("<<c.first<<","<<c.second<<"))";
}
void Transliraj(double delta_x, double delta_y){
    a.first+=delta_x;
    a.second+=delta_y;
    b.first+=delta_x;
    b.second+=delta_y;
    c.first+=delta_x;
    c.second+=delta_y;
}
void Centriraj(const Tacka &t){
    double dx=(3*t.first)/(a.first+b.first+c.first);
    double dy=(3*t.second)/(a.second+b.second+c.second);
    Transliraj(dx,dy);

}

void Rotiraj(const Tacka &t, double ugao){
    a.first=t.first+(a.first-t.first)*cos(ugao)-(a.second-t.second)*sin(ugao);
    b.first=t.first+(b.first-t.first)*cos(ugao)-(b.second-t.second)*sin(ugao);
    c.first=t.first+(c.first-t.first)*cos(ugao)-(c.second-t.second)*sin(ugao);
    a.second=t.second+(a.first-t.first)*sin(ugao)+(a.second-t.second)*cos(ugao);
    b.second=t.second+(b.first-t.first)*sin(ugao)+(b.second-t.second)*cos(ugao);
    c.second=t.second+(c.first-t.first)*sin(ugao)+(c.second-t.second)*cos(ugao);

}
void Skaliraj(const Tacka &t, double faktor){
    if(fabs(faktor)<0)throw domain_error("Nekorektan faktor skaliranja");
    double mf=fabs(faktor);
    a.first=t.first+mf*(a.first-t.first);
    b.first=t.first+mf*(b.first-t.first);
    c.first=t.first+mf*(c.first-t.first);
    a.second=t.second+mf*(a.second-t.second);
    b.second=t.second+mf*(b.second-t.second);
    c.second=t.second+mf*(c.second-t.second);
    if(faktor<0){
        Rotiraj(DajCentar(),4*atan(1.));
        }
    }
void Rotiraj(double ugao){
    Rotiraj(DajCentar(),ugao);
    }

void Skaliraj(double faktor){
    Skaliraj(DajCentar(),faktor);

    }
friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    if(fabs(t1.a.first-t2.a.first)<E&&fabs(t1.a.second-t2.a.second)<E){
        if(fabs(t1.b.first-t2.b.first)<E&&fabs(t1.b.second-t2.b.second)<E&&fabs(t1.c.first-t2.c.first)<E&&fabs(t1.c.second-t2.c.second)<E)return true;
        if(fabs(t1.b.first-t2.c.first)<E&&fabs(t1.b.second-t2.c.second)<E&&fabs(t1.c.first-t2.b.first)<E&&fabs(t1.c.second-t2.b.second)<E)return true;
        }
    if(fabs(t1.a.first-t2.b.first)<E&&fabs(t1.a.second-t2.b.second)<E){
        if(fabs(t1.b.first-t2.a.first)<E&&fabs(t1.b.second-t2.a.second)<E&&fabs(t1.c.first-t2.c.first)<E&&fabs(t1.c.second-t2.c.second)<E)return true;
        if(fabs(t1.b.first-t2.c.first)<E&&fabs(t1.b.second-t2.c.second)<E&&fabs(t1.c.first-t2.a.first)<E&&fabs(t1.c.second-t2.a.second)<E)return true;
        }
    if(fabs(t1.a.first-t2.c.first)<E&&fabs(t1.a.second-t2.c.second)<E){
        if(fabs(t1.b.first-t2.a.first)<E&&fabs(t1.b.second-t2.a.second)<E&&fabs(t1.c.first-t2.b.first)<E&&fabs(t1.c.second-t2.b.second)<E)return true;
        if(fabs(t1.b.first-t2.b.first)<E&&fabs(t1.b.second-t2.b.second)<E&&fabs(t1.c.first-t2.a.first)<E&&fabs(t1.c.second-t2.a.second)<E)return true;
        }
    return false;

}
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    if((t1.DajStranicu(1)-t2.DajStranicu(1)<E&&t1.DajStranicu(2)-t2.DajStranicu(2)<E&&t1.DajStranicu(3)-t2.DajStranicu(3))||(t1.DajStranicu(1)-t2.DajStranicu(2)<E&&t1.DajStranicu(2)-t2.DajStranicu(3)<E&&t1.DajStranicu(3)-t2.DajStranicu(1))||(t1.DajStranicu(1)-t2.DajStranicu(3)<E&&t1.DajStranicu(2)-t2.DajStranicu(1)<E&&t1.DajStranicu(3)-t2.DajStranicu(2)))
    return true;
    return false;
}

friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    double j,k,l;
    j=t1.DajStranicu(1)/t2.DajStranicu(1);
    k=t1.DajStranicu(2)/t2.DajStranicu(2);
    l=t1.DajStranicu(3)/t2.DajStranicu(3);
    if(fabs(j-k)<E&&fabs(j-l)<E&&fabs(k-l)<E)return true;
    j=t1.DajStranicu(1)/t2.DajStranicu(3);
    k=t1.DajStranicu(2)/t2.DajStranicu(1);
    l=t1.DajStranicu(3)/t2.DajStranicu(2);
    if(fabs(j-k)<E&&fabs(j-l)<E&&fabs(k-l)<E)return true;
     j=t1.DajStranicu(1)/t2.DajStranicu(2);
    k=t1.DajStranicu(2)/t2.DajStranicu(3);
    l=t1.DajStranicu(3)/t2.DajStranicu(1);
    if(fabs(j-k)<E&&fabs(j-l)<E&&fabs(k-l)<E)return true;
    return false;
}


};
int main()
{
return 0;
}