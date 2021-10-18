#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::domain_error;
using std::range_error;
using std::sqrt;
using std::shared_ptr;
using std::make_shared;
using std::vector;
using std::transform;
using std::transform;
using std::min_element;

typedef pair<double, double> Tacka;

class Trougao{
    Tacka t1, t2, t3;
        
    double XPrim(Tacka tacka, Tacka tocka, double ugao){ return (tacka.first+(tocka.first-tacka.first)*cos(ugao)-(tocka.second-tacka.second)*sin(ugao)); }
    double Yprim(Tacka tacka, Tacka tocka, double ugao){ return (tacka.second+(tocka.first-tacka.first)*sin(ugao)+(tocka.second-tacka.second)*cos(ugao)); }

    
    
    public:
    
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1, t2, t3)==0) throw domain_error ("Nekorektne pozicije tjemena");
        else{ Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3; }
    }
    void Postavi(const Tacka & t1, const Tacka & t2, const Tacka & t3){
        if(Orijentacija(t1, t2, t3)==0) throw domain_error ("Nekorektne pozicije tjemena");
        else{ Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3; }
    }
    
    void Postavi(int indeks, const Tacka &t){
        if(indeks==1) t1=t;
        else if(indeks==2) t2=t;
        else if(indeks==3) t3=t;
        else throw range_error ("Nekorektan indeks");
        if(Orijentacija(t1, t2, t3)==0) throw domain_error ("Nekorektne pozicije tjemena");
    }
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        int temp=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
        if(temp==0) return 0;
        if(temp>0) return 1;
        if(temp<0) return -1;
    }
    
    Tacka DajTjeme(int indeks) const{
        if(indeks==1) return t1;
        if(indeks==2) return t2;
        if(indeks==3) return t3;
    }
    double DajStranicu(int indeks) const{
        if(indeks==1) return sqrt((t2.first-t3.first)*(t2.first-t3.first)+(t2.second-t3.second)*(t2.second-t3.second));
        if(indeks==2) return sqrt((t1.first-t3.first)*(t1.first-t3.first)+(t1.second-t3.second)*(t1.second-t3.second));
        if(indeks==3) return sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
    }
    double DajUgao(int indeks) const{
        if(indeks==1) return acos((DajStranicu(1)*DajStranicu(1)-DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3)) / (2*DajStranicu(3)*DajStranicu(2)));
        if(indeks==2) return acos((DajStranicu(2)*DajStranicu(2)-DajStranicu(1)*DajStranicu(1)-DajStranicu(3)*DajStranicu(3)) / (2*DajStranicu(3)*DajStranicu(1)));
        if(indeks==3) return acos((DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2)-DajStranicu(1)*DajStranicu(1)) / (2*DajStranicu(1)*DajStranicu(2)));
    }
    Tacka DajCentar() const{
        Tacka temp;
        temp.first=(t1.first+t2.first+t3.first)/3.;
        temp.second=(t1.second+t2.second+t3.second)/3.;
        return temp;
    }
    double DajObim() const{ return DajStranicu(1)+DajStranicu(2)+DajStranicu(3); }
    double DajPovrsinu() const{ return (1/2)*(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));}
    bool DaLiJePozitivnoOrijentiran() const{
        if(Orijentacija(t1, t2, t3)>0) return true;
        else if (Orijentacija(t1, t2, t3)<0) return false;
    }
    bool DaLiJeUnutra(const Tacka &t) const{
        double temp=((t2.second-t3.second)*(t.first-t3.first)+(t3.first-t2.first)*(t.second-t3.second));
        double temp2=((t2.second-t3.second)*(t1.first-t3.first)+(t3.first-t2.first)*(t1.second-t3.second));
        double temp3=((t3.second - t1.second)*(t.first - t3.first)+(t1.first - t3.first)*(t.second-t3.second));
       
        double alpha=temp/temp2;
        double beta=temp3/temp2;
        double gamma=1.0-alpha-beta; //ovdje moze biti odstupanje float and double 1.0f i 1.0
        if(alpha>0 && beta>0 && gamma>0) return true;
        else return false;
    }
    void Ispisi() const{ cout<<"(("<<DajTjeme(1).first<<","<<DajTjeme(1).second<<"),("<<DajTjeme(2).first<<","<<DajTjeme(2).second<<"),("<<DajTjeme(3).first<<","<<DajTjeme(3).second<<"))";}
    void Transliraj(double delta_x, double delta_y){ 
        t1.first+=delta_x; t1.second+=delta_y;
        t2.first+=delta_x; t2.second+=delta_y;
        t3.first+=delta_x; t3.second+=delta_y;
    }
    void Centriraj(const Tacka &t){
        Tacka temp=DajCentar();
        double delta_x=t.first-temp.first;
        double delta_y=t.second-temp.second;
        Transliraj(delta_x, delta_y);
    }
    void Rotiraj(const Tacka &t, double ugao){
        double x_prim=XPrim(t, t1, ugao);
        double y_prim=Yprim(t, t1, ugao);
        t1.first=x_prim;
        t1.second=y_prim;
        x_prim=XPrim(t, t2, ugao);
        y_prim=Yprim(t, t2, ugao);
        t2.first=x_prim;
        t2.second=y_prim;
        x_prim=XPrim(t, t3, ugao);
        y_prim=Yprim(t, t3, ugao);
        t3.first=x_prim;
        t3.second=y_prim;
    }
    void Skaliraj(const Tacka &t, double faktor){
        if(fabs(faktor)==(1e-10)*fabs(faktor)) throw domain_error ("Nekorektan faktor skaliranja");
        else{
                t1.first=t.first+faktor*(t1.first-t.first);
                t1.second=t.second+faktor*(t1.second-t.second);
                
                t2.first=t.first+faktor*(t2.first-t.first);
                t2.second=t.second+faktor*(t2.second-t.second);
                
                t3.first=t.first+faktor*(t3.first-t.first);
                t3.second=t.second+faktor*(t3.second-t.second);

        }
    }
    void Rotiraj(double ugao){
        double x_prim=XPrim(DajCentar(), t1, ugao);
        double y_prim=Yprim(DajCentar(), t1, ugao);
        t1.first=x_prim;
        t1.second=y_prim;
        x_prim=XPrim(DajCentar(), t2, ugao);
        y_prim=Yprim(DajCentar(), t2, ugao);
        t2.first=x_prim;
        t2.second=y_prim;
        x_prim=XPrim(DajCentar(), t3, ugao);
        y_prim=Yprim(DajCentar(), t3, ugao);
        t3.first=x_prim;
        t3.second=y_prim;
    }
    void Skaliraj(double faktor){
        if(fabs(faktor)==(1e-10)*fabs(faktor)) throw domain_error ("Nekorektan faktor skaliranja");
        else{
            Tacka t=DajCentar();
            t1.first=t.first+faktor*(t1.first-t.first);
                t1.second=t.second+faktor*(t1.second-t.second);
                
                t2.first=t.first+faktor*(t2.first-t.first);
                t2.second=t.second+faktor*(t2.second-t.second);
                
                t3.first=t.first+faktor*(t3.first-t.first);
                t3.second=t.second+faktor*(t3.second-t.second);
        }
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    int broj1=0;
    for (int i=0; i<3; i++){
        for (int j=0; j<3;j++){
            if (t1.DajTjeme(i+1) == t2.DajTjeme(j+1))  { broj1++;break;}
        }
    }
    if (broj1==3) return true;
    else return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    int broj1=0, broj2=0, broj3, broj4, broj5, broj6;
    double a1=t1.DajStranicu(1);
    double b1=t1.DajStranicu(2);
    double c1=t1.DajStranicu(3);
    double a2=t2.DajStranicu(1);
    double b2=t2.DajStranicu(2);
    double c2=t2.DajStranicu(3);
    double temp1, temp2, temp3, temp4, temp5, temp6;
    if (a1>b1 && a1>c1 && b1>c1) {temp1=a1; temp2=b1; temp3=c1;}
    if (a1>b1 && a1>c1 && c1>b1) {temp1=a1; temp2=c1; temp3=b1;}
    if (b1>a1 && b1>c1 && a1>c1) {temp1=b1; temp2=a1; temp3=c1;}
    if (b1>a1 && c1>a1 && b1>c1) {temp1=b1; temp2=c1; temp3=a1;}
    if (c1>b1 && c1>a1 && b1>a1) {temp1=c1; temp2=b1; temp3=a1;}
    if (c1>b1 && c1>a1 && a1>b1) {temp1=c1; temp2=a1; temp3=b1;}
    
    if (a2>b2 && a2>c2 && b2>c2) {temp4=a2; temp5=b2; temp6=c2;}
    if (a2>b2 && a2>c2 && c2>b2) {temp4=a2; temp5=c2; temp6=b2;}
    if (b2>a2 && b2>c2 && a2>c2) {temp4=b2; temp5=a2; temp6=c2;}
    if (b2>a2 && c2>a2 && b2>c2) {temp4=b2; temp5=c2; temp6=a2;}
    if (c2>b2 && c2>a2 && b2>a2) {temp4=c2; temp5=b2; temp6=a2;}
    if (c2>b2 && c2>a2 && a2>b2) {temp4=c2; temp5=a2; temp6=b2;}
    Tacka x1;
    if (temp1==a1) x1=t1.DajTjeme(1);
    else if (temp1==b1)  x1=t1.DajTjeme(2);
    else x1=t1.DajTjeme(3);
    Tacka x2;
    if (temp4==a2) x2=t2.DajTjeme(1);
    else if (temp4==b2) x2=t2.DajTjeme(2);
    else x2=t2.DajTjeme(3);
    Tacka y1;
    if (temp2==a1) y1=t1.DajTjeme(1);
    else if (temp2==b1) y1=t1.DajTjeme(1);
    else y1=t1.DajTjeme(3);
    Tacka y2;
    if (temp5==a2) y2=t2.DajTjeme(1);
    else if (temp5==b2) y2=t2.DajTjeme(2);
    else y2=t2.DajTjeme(3);
    Tacka z1;
    if (temp3==a1)  z1=t1.DajTjeme(1);
    else if (temp3=b1)  z1=t1.DajTjeme(2);
    else z1=t1.DajTjeme(3);
    Tacka z2;
    if (temp6==a2)  z2=t2.DajTjeme(1);
    else if (temp6==b2) z2=t2.DajTjeme(2);
    else z2=t2.DajTjeme(3);
    
    if (temp1==temp4 && temp2==temp5 && temp3==temp6 && Trougao::Orijentacija(x1, y1, z1)==Trougao::Orijentacija(x2, y2, z2)){
        return true;
    }
    else return false;
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    int broj1=0, broj2=0, broj3, broj4, broj5, broj6;
    double a1=t1.DajStranicu(1);
    double b1=t1.DajStranicu(2);
    double c1=t1.DajStranicu(3);
    double a2=t2.DajStranicu(1);
    double b2=t2.DajStranicu(2);
    double c2=t2.DajStranicu(3);
    double temp1, temp2, temp3, temp4, temp5, temp6;
    if (a1>b1 && a1>c1 && b1>c1) {temp1=a1; temp2=b1; temp3=c1;}
    if (a1>b1 && a1>c1 && c1>b1) {temp1=a1; temp2=c1; temp3=b1;}
    if (b1>a1 && b1>c1 && a1>c1) {temp1=b1; temp2=a1; temp3=c1;}
    if (b1>a1 && c1>a1 && b1>c1) {temp1=b1; temp2=c1; temp3=a1;}
    if (c1>b1 && c1>a1 && b1>a1) {temp1=c1; temp2=b1; temp3=a1;}
    if (c1>b1 && c1>a1 && a1>b1) {temp1=c1; temp2=a1; temp3=b1;}
    
    if (a2>b2 && a2>c2 && b2>c2) {temp4=a2; temp5=b2; temp6=c2;}
    if (a2>b2 && a2>c2 && c2>b2) {temp4=a2; temp5=c2; temp6=b2;}
    if (b2>a2 && b2>c2 && a2>c2) {temp4=b2; temp5=a2; temp6=c2;}
    if (b2>a2 && c2>a2 && b2>c2) {temp4=b2; temp5=c2; temp6=a2;}
    if (c2>b2 && c2>a2 && b2>a2) {temp4=c2; temp5=b2; temp6=a2;}
    if (c2>b2 && c2>a2 && a2>b2) {temp4=c2; temp5=a2; temp6=b2;}
    Tacka x1;
    if (temp1==a1) x1=t1.DajTjeme(1);
    else if (temp1==b1)  x1=t1.DajTjeme(2);
    else x1=t1.DajTjeme(3);
    Tacka x2;
    if (temp4==a2) x2=t2.DajTjeme(1);
    else if (temp4==b2) x2=t2.DajTjeme(2);
    else x2=t2.DajTjeme(3);
    Tacka y1;
    if (temp2==a1) y1=t1.DajTjeme(1);
    else if (temp2==b1) y1=t1.DajTjeme(1);
    else y1=t1.DajTjeme(3);
    Tacka y2;
    if (temp5==a2) y2=t2.DajTjeme(1);
    else if (temp5==b2) y2=t2.DajTjeme(2);
    else y2=t2.DajTjeme(3);
    Tacka z1;
    if (temp3==a1)  z1=t1.DajTjeme(1);
    else if (temp3=b1)  z1=t1.DajTjeme(2);
    else z1=t1.DajTjeme(3);
    Tacka z2;
    if (temp6==a2)  z2=t2.DajTjeme(1);
    else if (temp6==b2) z2=t2.DajTjeme(2);
    else z2=t2.DajTjeme(3);
    double razlika=fabs(temp1-temp4);
    if ( fabs(temp2-temp5)==razlika && (temp3-temp6)==razlika && Trougao::Orijentacija(x1, y1, z1)==Trougao::Orijentacija(x2, y2, z2)){
        return true;
    }
    else return false;

}

