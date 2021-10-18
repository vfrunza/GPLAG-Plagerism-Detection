/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok



#include <iostream>
#include <utility>
#include <cmath>
#include <new>
#include <stdexcept>
#include <memory>
#include <vector>
#include <algorithm>

const double eps(pow(10,-10));
using std::cout;
using std::cin;
using std::endl;

typedef std::pair<double,double> Tacka;

/*bool operator== (const std::pair<double,double> &p1, const std::pair<double,double> &p2)
{
    return (std::fabs(p1.first-p2.first)<=eps*(std::fabs(p1.first) + std::fabs(p2.first))) && (std::fabs(p1.second-p2.second) <= eps*(std::fabs(p1.second)+ std::fabs(p2.second)));
}*/

class Trougao{
    Tacka t1, t2,t3;
public: 
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        Postavi(t1,t2,t3);
    }
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
         if(Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        Trougao::t1=t1;
        Trougao::t2=t2;
        Trougao::t3=t3;
    }
    void Postavi(int indeks, const Tacka &t){
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        if(indeks!=1 ||indeks!=2 || indeks !=3) throw std::range_error("Nekorektan indeks");
        if(indeks==1)
        {
            Trougao::t1=t;
        }
        else if(indeks==2)
        {
            Trougao::t2=t;
        }
        else if(indeks==3) Trougao::t3=t;
        
    }
    static bool poredjenje(double x, double y)
    {
        return std::fabs(x-y)<=eps*(std::fabs(x)+ std::fabs(y));
    }
    static double Racunaj(const Tacka &t1, const Tacka &t2, const Tacka &t3)
    {
        
        return (t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
        
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double izraz(Racunaj(t1,t2,t3));
        if(izraz>0) return 1;
        else if(izraz <0) return -1;
        else return 0;
    }
    Tacka DajTjeme(int indeks) const{
        if(indeks !=1 && indeks!=2 && indeks !=3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return t1;
        else if(indeks==2) return t2;
        return t3;
        
    }
    static double duzina(const Tacka &t1, const Tacka &t2)
    {
        return sqrt((t1.first- t2.first)*(t1.first-t2.first) + (t1.second-t2.second)*(t1.second- t2.second));
    }
    double DajStranicu(int indeks) const{
        if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
        if(indeks==1)
        {
            double duz(duzina(t2,t3));
            return duz;
        }
        else if(indeks==2)
        {
            double duz(duzina(t1,t3));
            return duz;
        }
        double duz(duzina(t2,t1));
        return duz;
        
    }
    double DajUgao(int indeks) const{
        if(indeks!=1 &&indeks!=2 && indeks !=3) throw std::range_error("Nekorektan indeks");
        double a(DajStranicu(1)), b(DajStranicu(2)), c(DajStranicu(3));
        if(indeks ==1)
        {
            return acos((b*b+c*c-a*a)/(2*b*c));
        }
        else if(indeks==2)
        {
            return acos((a*a+c*c-b*b)/(2*a*c));
        }
        return acos((a*a+b*b-c*c)/(2*a*b));
        
    }
    Tacka DajCentar() const{
        Tacka teziste;
        teziste.first=(t1.first+t2.first+t3.first)/3;
        teziste.second=(t1.second+t2.second + t3.second)/3;
        return teziste;
    }
    double DajObim() const{
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu() const{
        return 1/2.*std::fabs(Racunaj(t1,t2,t3));
    }
    bool DaLiJePozitivnoOrijentiran() const{
        int o(Orijentacija(t1,t2,t3));
        if(o==1) return true;
        return false;
        
    }
    bool DaLiJeUnutra(const Tacka &t) const{
        int ABC(Orijentacija(t1,t2,t3));
        int ABU(Orijentacija(t1,t2,t));
        int BCU(Orijentacija(t2,t3,t));
        int CAU(Orijentacija(t3,t1,t));
        if(ABC==1)
        {
            if( ABU==1 && BCU==1 && CAU==1) return true;
        }
        else if(ABC==-1)
        {
            if( ABU==-1 && BCU==-1 && CAU==-1) return true;
        }
        return false;
    }
    void Ispisi() const{
        std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
    }
    void Transliraj(double delta_x, double delta_y)
    {
        t1.first+=delta_x; t2.first+=delta_x; t3.first+=delta_x;
        t1.second+=delta_y; t2.second+=delta_y; t3.second+=delta_y;
    }
    void Centriraj(const Tacka &t){
        Tacka teziste(DajCentar());
        double delta_x(t.first-teziste.first);
        double delta_y(t.second-teziste.second);
        Transliraj(delta_x, delta_y);
    }
    void Rotiraj(const Tacka &t, double ugao){
        Tacka t11(t1), t22(t2), t33(t3);
        t1.first=t.first+(t11.first-t.first)*cos(ugao) - (t11.second - t.second)*sin(ugao);
        t1.second=t.second+(t11.first-t.first)*sin(ugao) + (t11.second - t.second)*cos(ugao);
        
        
        
        t2.first=t.first+(t22.first-t.first)*cos(ugao) - (t22.second - t.second)*sin(ugao);;
        t2.second=t.second+(t22.first-t.first)*sin(ugao) + (t22.second - t.second)*cos(ugao);
        
        
        
        t3.first=t.first+(t33.first-t.first)*cos(ugao) - (t33.second - t.second)*sin(ugao);
        t3.second=t.second+(t33.first-t.first)*sin(ugao) + (t33.second - t.second)*cos(ugao);
        
    }
    void Skaliraj(const Tacka &t, double k){
        if(poredjenje(k,0)) throw std::domain_error("Nekorektan faktor skaliranja");
        if(k>0)
        {
            t1.first=t.first + k*(t1.first - t.first);
            t1.second=t.second + k*(t1.second - t.second);
            
            t2.first=t.first + k*(t2.first - t.first);
            t2.second=t.second +k*(t2.second - t.second);
            
            t3.first=t.first + k*(t3.first - t.first);
            t3.second=t.second +k*(t3.second - t.second);
        }
        else if(k<0)
        {
            t1.first=t1.first + k*(t.first - t1.first);
            t1.second+=k*(t.second - t1.second);
            
            t2.first=t2.first + k*(t.first - t2.first);
            t2.second+=k*(t.second - t2.second);
            
            t3.first=t3.first + k*(t.first - t3.first);
            t3.second+=k*(t.second - t3.second);
            Rotiraj(t,180);
        }
        
    }
    void Rotiraj(double ugao){
        Tacka teziste(DajCentar());
        Rotiraj(teziste, ugao);
    }
    void Skaliraj(double faktor)
    {
        if(poredjenje(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka teziste(DajCentar());
        Rotiraj(teziste,faktor);
    }
    
    static double Ugao(double a, double b, double c)
    {
        return acos((b*b+c*c-a*a)/(2*b*c));
    }
    
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
        if(t1.t1==t2.t1 && t1.t2==t2.t2 && t1.t3==t2.t3) return true;
        if(t1.t1==t2.t2 && t1.t2==t2.t1 && t1.t3==t2.t3) return true;
        if(t1.t1==t2.t3 && t1.t2==t2.t2 && t1.t3==t2.t1) return true;
        if(t1.t1==t2.t2 && t1.t2==t2.t3 && t1.t3==t2.t1) return true;
        if(t1.t1==t2.t1 && t1.t2==t2.t3 && t1.t3==t2.t2) return true;
        if(t1.t1==t2.t3 && t1.t2==t2.t1 && t1.t3==t2.t2) return true;
        return false;
        
    }
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
        double a1(t1.DajStranicu(1)), b1(t1.DajStranicu(2)), c1(t1.DajStranicu(3));
        double a2(t2.DajStranicu(1)), b2(t2.DajStranicu(2)), c2(t2.DajStranicu(3));
        double alfa1(Ugao(a1,b1,c1)), beta1(Ugao(b1,c1,a1)), gama1(Ugao(c1,a1,b1));
        double alfa2(Ugao(a2,b2,c2)), beta2(Ugao(b2,c2,a2)), gama2(Ugao(c2,a2,b2));
        if(poredjenje(a1,a2) && poredjenje(b1,b2) && poredjenje(c1,c2) && poredjenje(alfa1,alfa2) && poredjenje(beta1,beta2) && poredjenje(gama1,gama2)){
            return true;
        }
        return false;
        
    }
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
        double obim1(t1.DajObim()), obim2(t2.DajObim());
        double s1(t1.DajPovrsinu()), s2(t2.DajPovrsinu());
        double s=s1/s2;
        double obim=obim1/obim2;
        obim=pow(obim,2);
        if(poredjenje(s,obim)) return true;
        return false;
    }
};


int main ()
{
    cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    cin>>n;
    std::vector<std::shared_ptr<Trougao>> trouglovi;
    for(int i=0; i<n; i++)
    {
        cout<<"Unesite podatke za "<<i+1<<". trougao: ";
        double x1,x2,x3,y1,y2,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        Tacka t1, t2, t3;
        t1=std::make_pair(x1,y1);
        t2=std::make_pair(x2,y2);
        t3=std::make_pair(x3,y3);
        try
        {
            std::shared_ptr<Trougao> pom(std::make_shared<Trougao>(Trougao(t1,t2,t3)));
            trouglovi.push_back(pom);
        }
        catch( std::domain_error e)
        {
            cout<<e.what()<<endl;
        }
    }
    cout<<"Unesite vektor translacije (dx dy): ";
    double xv, yv;
    cin>>xv>>yv;
    Tacka v_translacije(std::make_pair(xv,yv));
    cout<<"Unesite ugao rotacije: ";
    double ugao;
    cin>>ugao;
    cout<<"Unesite faktor skaliranja: ";
    double k;
    cin>>k;
    cout<<"Trouglovi nakon obavljenih transformacija: "<<endl;
    for( int i=0; i<n; i++)
    {
       trouglovi[i]->Centriraj(v_translacije);
       trouglovi[i]->Rotiraj(ugao);
       Tacka t1;
       try{
           t1=trouglovi[i]->DajTjeme(1);
       }
       catch(std::range_error e)
       {
           cout<<e.what()<<endl;
       }
       try{
          trouglovi[i]->Skaliraj(t1,k);
       }
       catch (std::domain_error e)
       {
           cout<<e.what()<<endl;
       }
        trouglovi[i]->Ispisi();
        cout<<endl;
    }
    std::sort(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2)
    {
        return t1->DajPovrsinu()>t2->DajPovrsinu();
    });
    
    
    
	return 0;
}