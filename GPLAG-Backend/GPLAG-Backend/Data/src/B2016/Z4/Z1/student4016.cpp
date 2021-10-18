/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>
#include <map>
using namespace std;
typedef pair<double, double> Tacka;
double duz (Tacka t1, Tacka t2)
{
    return sqrt(pow(t2.second-t1.second, 2)+pow(t1.first-t2.first, 2));
}
bool Jednako(double a, double b){ if(fabs(a-b)<1E-10) return true; else return false; }
class Trougao
{
    Tacka a,b,c;
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        if( Jednako(t1.first*(t2.second - t3.second)+t2.first*(t3.second - t1.second)+t3.first*(t1.second - t2.second), 0) ) throw domain_error("Nekorektne pozicije tjemena");
        Trougao::a = t1; Trougao::b= t2; Trougao::c=t3;
    }
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        if( Jednako(t1.first*(t2.second - t3.second )+t2.first*(t3.second - t1.second)+t3.first*(t1.second - t2.second), 0) ) throw domain_error("Nekorektne pozicije tjemena");
        a=t1; b = t2; c=t3;
    }    
    void Postavi ( int indeks, const Tacka &t)
    {
        if (indeks > 3 || indeks <1) throw range_error("Nekorektan indeks");
        if(indeks == 1 ) Postavi(t, b,c); 
        if (indeks == 2) Postavi(a,t,c);
        if(indeks == 3) Postavi(a,b,t);
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        if(Jednako(t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second),0)) return 0;
        else if (t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second)>0) return 1;
        else return -1;
    }
    Tacka DajTjeme (int indeks) const
    {
        if(indeks > 3 || indeks < 1) throw range_error("Nekorektan indeks");
        if(indeks == 1) return a;
        if(indeks == 2) return b;
        if(indeks == 3) return c;
    }
    double DajStranicu(int indeks) const
    {
        if(indeks > 3 || indeks < 1) throw range_error("Nekorektan indeks");
        if(indeks==1) return duz(b,c);
        if(indeks==2) return duz(a,c);
        if(indeks==3) return duz(b,a);
    }
    double DajUgao(int indeks)
    {
        if(indeks>3||indeks<1) throw range_error("Nekorektan indeks");
        double a1=sqrt(pow(b.first-a.first, 2) + pow(b.second-a.second, 2));
        double b1=sqrt(pow(c.first-b.first, 2) + pow(c.second-b.second, 2));
        double c1=sqrt(pow(c.first-a.first, 2) + pow(c.second-a.second, 2));
        if(indeks==1) return acos((b1*b1+c1*c1-a1*a1)/(2*b1*c1));
        if(indeks==2) return acos((a1*a1+c1*c1-b1*b1)/(2*a1*c1));
        if(indeks==3) return acos((a1*a1+b1*b1-c1*c1)/(2*a1*b1));
    }
    Tacka DajCentar()const
    {
        return{(a.first+b.first+c.first)/3,(a.second+b.second+c.second)/3};
    }
    double DajObim()const
    {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu()
    {
        double s = DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
        s=s/2;
        return sqrt(s*(s-DajStranicu(1))*(s-DajStranicu(2))*(s-DajStranicu(3)));
    }
    bool DaLiJePozitivnoOrijentiran() const
    {
         return Orijentacija(a,b,c); 
    }
    bool DaLiJeUnutra(const Tacka &t) const    
    {
        if(Orijentacija(a,b,c)==Orijentacija(a,b,t)
        && Orijentacija(a,b,c)==Orijentacija(b,c,t)
        && Orijentacija(a,b,c)==Orijentacija(c,a,t)
        ) return true;
        else return false;
    }    
    void Transliraj(double delta_x, double delta_y)
    {
        a.first+=delta_x;
        b.first+=delta_x;
        c.first+=delta_x;
        a.second+=delta_y;
        b.second+=delta_y;
        c.second+=delta_y;
    }
    void Centriraj(const Tacka &t)
    {
        double dx,dy;
        dx=t.first-this->DajCentar().first;
        dy=t.second-this->DajCentar().second;
        Transliraj(dx,dy);
    }
    void Rotiraj(const Tacka &t, double ugao)
    {
        Tacka pomA=a, pomB=b, pomC=c ;
        a.first=t.first+(pomA.first-t.first)*cos(ugao)-(pomA.second-t.second)*sin(ugao);
        b.first=t.first+(pomB.first-t.first)*cos(ugao)-(pomB.second-t.second)*sin(ugao);
        c.first=t.first+(pomC.first-t.first)*cos(ugao)-(pomC.second-t.second)*sin(ugao);
        a.second=t.second+(pomA.first-t.first)*sin(ugao)+(pomA.second-t.second)*cos(ugao);
        b.second=t.second+(pomB.first-t.first)*sin(ugao)+(pomB.second-t.second)*cos(ugao);
        c.second=t.second+(pomC.first-t.first)*sin(ugao)+(pomC.second-t.second)*cos(ugao);
    }
    void Skaliraj(const Tacka &t, double k){
        if(Jednako(k,0)) throw domain_error ("Nekorektan faktor skaliranja");
        a.first=t.first+k*(a.first-t.first);
        a.second=t.second+k*(a.second-t.second);
        b.first=t.first+k*(b.first-t.first);
        b.second=t.second+k*(b.second-t.second);
        c.first=t.first+k*(c.first-t.first);
        c.second=t.second+k*(c.second-t.second);
    }
    void Skaliraj(double k){
        Skaliraj(DajCentar(), k);
    }
    void Rotiraj(double ugao){
        Rotiraj(DajCentar(),ugao);
    }
    friend bool DaLiSuIdenticni(const Trougao &trou1, const Trougao &trou2){
        if((Jednako(trou1.a.first,trou2.a.first) && Jednako(trou1.a.second,trou2.a.second)
        &&  Jednako(trou1.b.first,trou2.b.first) && Jednako(trou1.b.second,trou2.b.second)
        &&  Jednako(trou1.c.first,trou2.c.first) && Jednako(trou1.c.second,trou2.c.second))
        || (Jednako(trou1.a.first,trou2.b.first) && Jednako(trou1.a.second,trou2.b.second)
        &&  Jednako(trou1.b.first,trou2.a.first) && Jednako(trou1.b.second,trou2.a.second)
        &&  Jednako(trou1.c.first,trou2.c.first) && Jednako(trou1.c.second,trou2.c.second))
        || (Jednako(trou1.a.first,trou2.c.first) && Jednako(trou1.a.second,trou2.c.second)
        &&  Jednako(trou1.b.first,trou2.b.first) && Jednako(trou1.b.second,trou2.b.second)
        &&  Jednako(trou1.c.first,trou2.a.first) && Jednako(trou1.c.second,trou2.a.second))
        || (Jednako(trou1.a.first,trou2.b.first) && Jednako(trou1.a.second,trou2.b.second)
        &&  Jednako(trou1.b.first,trou2.c.first) && Jednako(trou1.b.second,trou2.c.second)
        &&  Jednako(trou1.c.first,trou2.a.first) && Jednako(trou1.c.second,trou2.a.second))
        || (Jednako(trou1.a.first,trou2.c.first) && Jednako(trou1.a.second,trou2.c.second)
        &&  Jednako(trou1.b.first,trou2.a.first) && Jednako(trou1.b.second,trou2.a.second)
        &&  Jednako(trou1.c.first,trou2.b.first) && Jednako(trou1.c.second,trou2.b.second))
        || (Jednako(trou1.a.first,trou2.a.first) && Jednako(trou1.a.second,trou2.a.second)
        &&  Jednako(trou1.b.first,trou2.c.first) && Jednako(trou1.b.second,trou2.c.second)
        &&  Jednako(trou1.c.first,trou2.b.first) && Jednako(trou1.c.second,trou2.b.second))
        ) return true;
        else return false;
    }
    friend bool DaLiSuPodudarni(const Trougao &trou1, const Trougao &trou2){
       double c1=sqrt(pow(trou1.b.first-trou1.a.first, 2) + pow(trou1.b.second-trou1.a.second, 2));
       double a1=sqrt(pow(trou1.c.first-trou1.b.first, 2) + pow(trou1.c.second-trou1.b.second, 2));
       double b1=sqrt(pow(trou1.c.first-trou1.a.first, 2) + pow(trou1.c.second-trou1.a.second, 2));
       double c2=sqrt(pow(trou2.b.first-trou2.a.first, 2) + pow(trou2.b.second-trou2.a.second, 2));
       double a2=sqrt(pow(trou2.c.first-trou2.b.first, 2) + pow(trou2.c.second-trou2.b.second, 2));
       double b2=sqrt(pow(trou2.c.first-trou2.a.first, 2) + pow(trou2.c.second-trou2.a.second, 2));
       double alfa1=acos((b1*b1+c1*c1-a1*a1)/(2*b1*c1));
       double beta1=acos((a1*a1+c1*c1-b1*b1)/(2*a1*c1));
       double gama1=acos((a1*a1+b1*b1-c1*c1)/(2*a1*b1));
       double alfa2=acos((b2*b2+c2*c2-a2*a2)/(2*b2*c2));
       double beta2=acos((a2*a2+c2*c2-b2*b2)/(2*a2*c2));
       double gama2=acos((a2*a2+b2*b2-c2*c2)/(2*a2*b2));
       //if(trou1.Orijentacija(trou1.a, trou1.b, trou1.c)!=trou2.Orijentacija(trou2.a,trou2.b,trou2.c)) return false;
       double ref_M_str_1, ref_M_str_2, ref_s_str_1, ref_s_str_2, ref_m_str_1, ref_m_str_2, ref_M_ugao_1, ref_M_ugao_2, ref_s_ugao_1, ref_s_ugao_2, ref_m_ugao_1, ref_m_ugao_2;
       Tacka ar1,br1,cr1,ar2,br2,cr2;
       if(a1>=b1 && a1>=c1) { 
            ref_M_str_1=a1;  ref_M_ugao_1=alfa1; ar1 = trou1.a;
           if(b1>=c1){
                ref_s_str_1=b1;  ref_s_ugao_1=beta1;  ref_m_str_1=c1; ref_m_ugao_1=gama1; br1=trou1.b; cr1=trou1.c;
           } else {
                ref_s_str_1=c1;  ref_s_ugao_1=gama1;  ref_m_str_1=b1;  ref_m_ugao_1=beta1; br1=trou1.c; cr1=trou1.b;
           }
           }
        if(b1>=a1 && b1>=c1) {
            ref_M_str_1=b1;  ref_M_ugao_1=beta1; ar1=trou1.b;
            if(a1>=c1){
                 ref_s_str_1=a1;  ref_s_ugao_1=alfa1;  ref_m_str_1=c1;  ref_m_ugao_1=gama1; br1=trou1.a; cr1=trou1.c;
            } else {
                 ref_s_str_1=c1;  ref_s_ugao_1=gama1;  ref_m_str_1=a1; ref_m_ugao_1=alfa1; br1=trou1.c; cr1=trou1.a;
            }
        }
       if(c1>=a1 && c1>=b1){
            ref_M_str_1=c1;  ref_M_ugao_1=gama1; ar1=trou1.c;
           if(a1>=b1){
                ref_s_str_1=a1; ref_s_ugao_1=alfa1;  ref_m_str_1=b1;  ref_m_ugao_1=beta1; br1=trou1.a; cr1=trou1.b;
       } else {
                ref_s_str_1=b1; ref_s_ugao_1=beta1;  ref_m_str_1=a1;  ref_m_ugao_1=alfa1; br1=trou1.b; cr1=trou1.a;
       }
       }
       if(a2>=b2 && a2>=c2){
           ref_M_str_2=a2;  ref_M_ugao_2=alfa2; ar2 = trou2.a;
           if(b2>=c2){
                ref_s_str_2=b2;  ref_s_ugao_2=beta2;  ref_m_str_2=c2; ref_m_ugao_2=gama2; br2=trou2.b; cr2=trou2.c;
           }
           else {
                ref_s_str_2=c2;  ref_s_ugao_2=gama2; ref_m_str_2=b2;  ref_m_ugao_2=beta2; br2=trou2.c; cr2=trou2.b;
           }
       }
       if(b2>=a2 && b2>=c2){
            ref_M_str_2=b2;  ref_M_ugao_2=beta2; ar2= trou2.b;
           if(a2>=c2){
                ref_s_str_2=a2;  ref_s_ugao_2=alfa2;  ref_m_str_2=c2; ref_m_ugao_2=gama2; br2=trou2.a; cr2=trou2.c;
           } else {
               ref_s_str_2=c2; ref_s_ugao_2=gama2;  ref_m_str_2=a2; ref_m_ugao_2=alfa1; br2=trou2.c; cr2=trou2.a;
           }
       }
       if(c2>=a2 && c2>b2){
            ref_M_str_2=c2;  ref_M_ugao_2=gama2; ar2=trou2.c;
           if(a2>=b2){
                ref_s_str_2=a2; ref_s_ugao_2=alfa2; ref_m_str_2=b2;  ref_m_ugao_2=beta2; br2=trou2.a; cr2=trou2.b;
           } else {
              ref_s_str_2=b2; ref_s_ugao_2=beta2;  ref_m_str_2=a2;  ref_m_ugao_2=alfa2; br2= trou2.b; cr2 = trou2.a;
           }
       }
       if(Jednako(ref_M_str_1,ref_M_str_2) && Jednako(ref_s_str_1,ref_s_str_2) && Jednako(ref_m_str_1,ref_m_str_2) && Orijentacija(ar1,br1,cr1)==Orijentacija(ar2,br2,cr2) ) return true; 
       else return false;
       
       
       
       /*
        if( (a1,a2) && Jednako(b1,b2) && Jednako(c1,c2) 
    
        
        || ( b1>c1 && Jednako(b1,b2) && Jednako(c1,c2) && Jednako(beta1,beta2))
        || ( c1>b1 && Jednako(b1,b2) && Jednako(c1,c2) && Jednako(gama1,gama2))
        || ( a1>a2 && Jednako(a1,a2) && Jednako(b1,b2) && Jednako(alfa1,alfa2))
        || ( b1>a1 && Jednako(a1,a2) && Jednako(b1,b2) && Jednako(beta1,beta2))
        || ( a1>c1 && Jednako(a1,a2) && Jednako(c1,c2) && Jednako(alfa1,alfa2))
        || ( c1>c2 && Jednako(a1,a2) && Jednako(c1,c2) && Jednako(gama2,gama1))
        
        || ( (alfa1,alfa2) && Jednako(beta1,beta2) && Jednako(c1,c2))
        || ( (alfa1,alfa2) && Jednako(gama1,gama2) && Jednako(b1,b2))
        || ( (beta1,beta2) && Jednako(gama1,gama2) && Jednako(a1,a2))
        
        || ( (a1,a2) && Jednako(c1,c2) && Jednako(beta1,beta2))
        || ( (a1,a2) && Jednako(b1,b2) && Jednako(gama1,gama2))
        || ((b1,b2) && Jednako(c1,c2) && Jednako(alfa1,alfa2)))
        return true;
        else return false;
        */
    }
    friend bool DaLiSuSlicni(const Trougao &trou1, const Trougao &trou2){
       double c1=sqrt(pow(trou1.b.first-trou1.a.first, 2) + pow(trou1.b.second-trou1.a.second, 2));
       double a1=sqrt(pow(trou1.c.first-trou1.b.first, 2) + pow(trou1.c.second-trou1.b.second, 2));
       double b1=sqrt(pow(trou1.c.first-trou1.a.first, 2) + pow(trou1.c.second-trou1.a.second, 2));
       double c2=sqrt(pow(trou2.b.first-trou2.a.first, 2) + pow(trou2.b.second-trou2.a.second, 2));
       double a2=sqrt(pow(trou2.c.first-trou2.b.first, 2) + pow(trou2.c.second-trou2.b.second, 2));
       double b2=sqrt(pow(trou2.c.first-trou2.a.first, 2) + pow(trou2.c.second-trou2.a.second, 2));
       double alfa1=acos((b1*b1+c1*c1-a1*a1)/(2*b1*c1));
       double beta1=acos((a1*a1+c1*c1-b1*b1)/(2*a1*c1));
       double gama1=acos((a1*a1+b1*b1-c1*c1)/(2*a1*b1));
       double alfa2=acos((b2*b2+c2*c2-a2*a2)/(2*b2*c2));
       double beta2=acos((a2*a2+c2*c2-b2*b2)/(2*a2*c2));
       double gama2=acos((a2*a2+b2*b2-c2*c2)/(2*a2*b2));
       double ax1,bx1,cx1,ax2,bx2,cx2; Tacka ar1,ar2,br1,br2,cr1,cr2; 
       
       if(a1>=b1 && a1>=c1){
           ax1=a1; ar1=trou1.a;
           if(b1>=c1){
               bx1=b1; cx1=c1; br1=trou1.b; cr1=trou1.c;
           } else {
               bx1=c1; cx1=b1; br1=trou1.c; cr1=trou1.b;
           }
       }
       if(b1>=a1 && b1>=c1){
           ax1=b1; ar1=trou1.b;
           if(a1>=c1){
               bx1=a1; cx1=c1; br1=trou1.a; cr1=trou1.c;
           } else {
               bx1=c1; cx1=a1; br1=trou1.c; cr1=trou1.a;
           }
       }
       if(c1>=b1 && c1>=a1){
           ax1=c1; ar1=trou1.c;
           if(b1>=a1){
               bx1=b1; cx1=a1; br1=trou1.b; cr1=trou1.a;
           } else {
               bx1=a1; cx1=b1; br1=trou1.a; cr1=trou1.b;
           }
       }
       if(a2>=b2 && a2>=c2){
           ax2=a2; ar2=trou2.a;
           if(b2>=c2){
               bx2=b2; cx2=c2; br2=trou2.b; cr2=trou2.c;
           } else {
               bx2=c2; cx2=b2; br2=trou2.c; cr2=trou2.b;
           }
       }
       if(b2>=a2 && b2>=c2){
           ax2=b2; ar2=trou2.b;
           if(a2>=c2){
               bx2=a2; cx2=c2; br2=trou2.a; cr2=trou2.c;
           } else {
               bx2=c2; cx2=a2; br2=trou2.c; cr2=trou2.a;
           }
       }
       if(c2>=b2 && c2>=a2){
           ax2=c2; ar2=trou2.c;
           if(b2>=a2){
               bx2=b2; cx2=a2; br2=trou2.b; cr2=trou2.a;
           } else {
               bx2=a2; cx2=b2; br2=trou2.a; cr2=trou2.b;
           }
       }
       
       
       double k = ax1/ax2, l=bx1/bx2, m=cx1/cx2;
       if(Jednako(k,l) && Jednako(l,m) && Jednako(k,m) && Orijentacija(ar1,br1,cr1)==Orijentacija(ar2,br2,cr2)) return true;
       else return false;
       
       /*
        if(((Jednako((a1/a2),(b1/b2)) && Jednako((a1/a2),(c1/c2)))
        || (Jednako(alfa1,alfa2) && Jednako(beta1,beta2) && Jednako(gama1,gama2))
        || (Jednako((a1/a2),(b1/b2)) && Jednako(gama1,gama2))
        || (Jednako((a1/a2),(c1/c2)) && Jednako(beta1,beta2))
        || (Jednako((b1/b2),(c1/c2)) && Jednako(alfa1,alfa2))
        || (c1>b1 && Jednako((b1/b2),(c1/c2)) && Jednako(gama1,gama2))
        || (a1>b1 && Jednako((a1/a2),(b1/b2)) && Jednako(alfa1,alfa2))
        || (b1>a1 && Jednako((a1/a2),(b1/b2)) && Jednako(beta1,beta2))
        || (b1>c1 && Jednako((b1/b2),(c1/c2)) && Jednako(beta1,beta2))
        || (c1>a1 && Jednako((c1/c2),(a1/a2)) && Jednako(gama1,gama2))
        || (a1>c1 && Jednako((a1/a2),(c1/c2)) && Jednako(alfa1,alfa2))) && trou1.Orijentacija(trou1.a, trou1.b, trou1.c)==trou2.Orijentacija(trou2.a, trou2.b, trou2.c)
        )return true;
        else return false;
        */
    }
    void Ispisi()const{
        cout << "(("<<a.first<<","<<a.second<<"),("<<b.first<<","<<b.second<<"),("<<c.first<<","<<c.second<<"))";
    }
};
int main ()
{
    int n;
    cout<<"Koliko zelite kreirati trouglova: ";
    cin>>n;
    vector <shared_ptr<Trougao>> v(n);
    for(int i=0; i<n; i++){
        try{
            Tacka a,b,c;
            cout << "Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            cin >> a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
            shared_ptr<Trougao> pom = make_shared<Trougao>(a,b,c);
            
            v[i] = pom;
        }catch(domain_error e){
            cout <<e.what() <<", ponovite unos!"<<endl;
            i--;
        }
    }
    cout << "Unesite vektor translacije (dx dy): ";
    double delta_x, delta_y;
    cin >> delta_x>>delta_y;
    cout << "Unesite ugao rotacije: ";
    double ugao;
    cin>>ugao;
    cout << "Unesite faktor skaliranja: ";
    double faktor;
    cin >> faktor;
    
    transform(begin(v), end(v),begin(v), [=](shared_ptr<Trougao> pok_trougao){
    pok_trougao->Transliraj(delta_x,delta_y);
    pok_trougao->Rotiraj(pok_trougao->DajCentar(), ugao);
    pok_trougao->Skaliraj(pok_trougao->DajTjeme(1),faktor);
    return pok_trougao;
    });
    sort(begin(v), end(v), [](shared_ptr<Trougao> tro1, shared_ptr<Trougao> tro2){
        return tro1->DajPovrsinu()<tro2->DajPovrsinu();
    });
    cout << "Trouglovi nakon obavljenih transformacija:"<<endl;
    for_each(begin(v), end(v), [](shared_ptr<Trougao> trouglic){ trouglic->Ispisi(); cout <<endl; });
    cout << "Trougao sa najmanjim obimom: ";
    (*(min_element(begin(v), end(v), [](shared_ptr<Trougao> trouglic_1, shared_ptr<Trougao> trouglic_2){
       return trouglic_2->DajObim()>trouglic_1->DajObim(); 
    })))->Ispisi();
    cout <<endl;
    vector<pair<Trougao, Trougao>> ident_vec_par;
    vector<bool> marker(n,false);
    for(int i=0; i< n-1; i++){
        for(int j=i+1; j<n; j++){
            if(DaLiSuIdenticni( *v[i], *v[j] )){
                if(marker[j]==true) continue;
                ident_vec_par.push_back(make_pair(*v[i], *v[j]));
               // marker(i)=true;
               // marker[j]=true;
                
            }
        } 
    }
    if(ident_vec_par.size()==0) cout << "Nema identicnih trouglova!"<<endl; else 
    cout << "Parovi identicnih trouglova:"<<endl;
    for_each(ident_vec_par.begin(), ident_vec_par.end(), [](pair<Trougao,Trougao> par){ par.first.Ispisi(); cout << " i "; par.second.Ispisi(); cout <<endl; });
    //for(int i=0; i<ident_vec_par.size(); i++) {ident_vec_par[i].first.Ispisi(); cout<<" i ";ident_vec_par[i].second.Ispisi();cout <<endl;}
    vector<pair<Trougao, Trougao>> podudarni_vec_par;
    vector<bool> markerP(n,false);
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
          //  cout << "Sad testiramo: ";v[i]->Ispisi();cout << " i ";v[j]->Ispisi();
            if(DaLiSuPodudarni(*v[i], *v[j])){
              //  cout << "Sad testiramo: ";v[i]->Ispisi();cout << " i ";v[j]->Ispisi();cout << "Rezultat je ";
                if(markerP[j]==true) continue;
                podudarni_vec_par.push_back(make_pair(*v[i],*v[j]));
               // markerP[j]=true;
            
        }
    }
    
    }
    if(podudarni_vec_par.size()==0) cout << "Nema podudarnih trouglova!"<<endl; else
    cout << "Parovi podudarnih trouglova:"<<endl;
    for_each(podudarni_vec_par.begin(), podudarni_vec_par.end(), [](pair<Trougao, Trougao> par){ par.first.Ispisi(); cout << " i "; par.second.Ispisi(); cout << endl; });
   // for(int i=0; i<podudarni_vec_par.size(); i++) {podudarni_vec_par[i].first.Ispisi(); cout<<" i ";podudarni_vec_par[i].second.Ispisi(); cout<<endl;}
    vector<pair<Trougao,Trougao>> slicni_vec_par;
    vector<bool> markerS(n,false);
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(DaLiSuSlicni(*v[i], *v[j])){
                if(markerS[j]==true) continue;
                slicni_vec_par.push_back(make_pair(*v[i], *v[j]));
               // markerS[j]=true;
            }
        }
    }
    if(slicni_vec_par.size()==0) cout << "Nema slicnih trouglova!"; else
    cout<< "Parovi slicnih trouglova:"<<endl;
    for_each(slicni_vec_par.begin(), slicni_vec_par.end(), [](pair<Trougao, Trougao> par){ par.first.Ispisi(); cout << " i "; par.second.Ispisi(); cout << endl; });
    //for(int i=0; i<slicni_vec_par.size(); i++) {slicni_vec_par[i].first.Ispisi();cout <<" i "; slicni_vec_par[i].second.Ispisi(); cout<<endl;}
    
      
	return 0;
}










