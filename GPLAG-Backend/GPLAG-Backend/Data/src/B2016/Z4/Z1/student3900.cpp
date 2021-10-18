/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <algorithm>
#include <memory>
#include <vector>
#include <limits>
#include <stdexcept>
using namespace std;
const double pi(4*atan(1));
typedef std::pair<double, double> Tacka;

class Trougao{
    Tacka t1, t2, t3;
    static double Povrsina(Tacka a, Tacka b, Tacka c) {
        double d=(a.first*(b.second-c.second)-b.first*(a.second-c.second)+ c.first*(a.second-b.second));
        return d;
    }
    static double Stranica(Tacka b, Tacka c) {
        double a=sqrt(((b.first-c.first)*(b.first-c.first)) +((b.second-c.second)*(b.second-c.second)));
        return a;
    }
    static double Mini(double a, double b, double c){
        if(a<b && a<c) return a;
        else if(b<c && b<a) return b;
        else return c;
    }
    
    static Tacka NajvisaTacka(Tacka a, Tacka b, Tacka c){
        if(a.second>b.second && a.second>c.second) return a;
        else if(b.second>c.second && b.second>a.second) return b;
        else return c;
    }
    double DeUgao(double a, double b, double c){
        double ugao;
        ugao=acos((b*b+c*c-a*a)/2*b*c);
    }
    static double NadjiMax(double a,double b, double c){
        if(a>b && a>c) return a;
        else if(b>a && b>c) return b;
        else if(c>b && c>a) return c;
    }
    static Tacka NajmanjaTacka(Tacka a, Tacka b, Tacka c){
        Tacka p=NajvisaTacka(a,b,c);
        if(Isti(p.first, a.first) && Isti(p.second, a.second)){
            if(b.first<=c.first && b.second<c.second) return b;
            else return c;
        }
        else if(Isti(p.first, b.first) && Isti(p.second, b.second)){
            if(a.first<=c.first && a.second<c.second) return a;
            else return c;
        }
        else if(Isti(p.first, c.first) && Isti(p.second, c.second)){
            if(a.first<=b.first && a.second<b.second) return a;
            else return b;
        }
    }
    static Tacka Apsolutna(Tacka &a){
        a.first=fabs(a.first);
        a.second=fabs(a.second);
    }
    static Tacka SrednjaTacka(Tacka a, Tacka b, Tacka c){
        Tacka pom1=NajvisaTacka(a,b,c);
        Tacka pom2=NajmanjaTacka(a,b,c);
        if(Isti(pom1.first, a.first) && Isti(pom1.second, a.second) && Isti(pom2.first, b.first) && Isti(pom2.second, b.second)){
            return c;
        }
        else if(Isti(pom1.first, a.first) && Isti(pom1.second, a.second) && Isti(pom2.first, c.first) && Isti(pom2.second, c.second)){
            return b;
        }
        else if(Isti(pom1.first, b.first) && Isti(pom1.second, b.second) && Isti(pom2.first, c.first) && Isti(pom2.second, c.second)){
            return a;
        }
        else if(Isti(pom1.first, b.first) && Isti(pom1.second, b.second) && Isti(pom2.first, a.first) && Isti(pom2.second, a.second)){
            return c;
        }
        
        else if(Isti(pom1.first, c.first) && Isti(pom1.second, c.second) && Isti(pom2.first, b.first) && Isti(pom2.second, b.second)){
            return a;
        }
        else if(Isti(pom1.first, c.first) && Isti(pom1.second, c.second) && Isti(pom2.first, a.first) && Isti(pom2.second, a.second)){
            return b;
        }
    }
    
    static Tacka centar(Tacka a, Tacka b, Tacka c){
        Tacka cent;
        cent.first=(a.first+b.first+c.first)/3;
        cent.second=(a.second+b.second+c.second)/3;
        return cent;
    }
    static bool Isti(double a, double b){
        double epsilon(1E-10);
        return fabs(a-b)<=epsilon*(fabs(a)+fabs(b));
    }
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) { Postavi(t1, t2, t3); } 
    
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    
    void Postavi(int indeks, const Tacka &t);
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
   
    Tacka DajTjeme(int indeks) const {
        if(indeks<1 || indeks>3) throw logic_error("Nekorektan indeks");
        if(indeks==1){
            return t1;
        }
        if(indeks==2){
            return t2;
        }
        if(indeks==3){
            return t3;
        }
    }
    double DajStranicu(int indeks) const {
        if(indeks<1 || indeks>3) throw logic_error("Nekorektan indeks");
        double stranica;
        if(indeks==1){
            stranica=sqrt((t2.first-t3.first)*(t2.first-t3.first)+(t2.second-t3.second)*(t2.second-t3.second));
        }
        if(indeks==2){
            stranica=sqrt((t1.first-t3.first)*(t1.first-t3.first)+(t1.second-t3.second)*(t1.second-t3.second));
        }
        if(indeks==3){
            stranica=sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
        }
        return stranica;
    }
    double DajUgao(int indeks) const{
        if(indeks<1 || indeks>3) throw logic_error("Nekorektan indeks");
        double pom;
        if(indeks==1){
            pom=(DajStranicu(3)*DajStranicu(3)+DajStranicu(2)*DajStranicu(2)
            -DajStranicu(1)*DajStranicu(1))/2*DajStranicu(3)*DajStranicu(2);
            pom=acos(pom);
            pom=pom*180/pi;
        }
        if(indeks==2){
            pom=(DajStranicu(3)*DajStranicu(3)+DajStranicu(1)*DajStranicu(1)
            -DajStranicu(2)*DajStranicu(2))/2*DajStranicu(3)*DajStranicu(1);
            pom=acos(pom);
            pom=pom*180/pi;
        }
        if(indeks==3){
            pom=(DajStranicu(2)*DajStranicu(2)+DajStranicu(1)*DajStranicu(1)
            -DajStranicu(3)*DajStranicu(3))/2*DajStranicu(2)*DajStranicu(1);
            pom=acos(pom);
            pom=pom*180/pi;
        }
        return pom;
    }
    Tacka DajCentar() const {
        Tacka teziste;
        teziste.first=(t1.first+t2.first+t3.first)/3;
        teziste.second=(t1.second+t2.second+t3.second)/3;
        return teziste;
    }
    double DajObim() const{
        double a=DajStranicu(3); 
        double b=DajStranicu(1); 
        double c=DajStranicu(2);
        double obim=a+b+c;
        return obim;
    }
    double DajPovrsinu() const {
        double povrsina=abs(Povrsina(t1,t2,t3));
        povrsina=povrsina/2;
        return povrsina;
    }
    bool DaLiJePozitivnoOrijentiran() const;
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const;
    void Transliraj(double delta_x, double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    if(Povrsina(t1,t2,t3)==0) throw domain_error("Nekorektne pozicije tjemena");
    Trougao::t1=t1;
    Trougao::t2=t2;
    Trougao::t3=t3;
}
void Trougao::Postavi(int indeks, const Tacka &t){
    if(indeks<1 || indeks>3) throw logic_error("Nekorektan indeks");
    if(indeks==1){
        Trougao::t1.first=t.first;
        Trougao::t1.second=t.second;
    }
    else if(indeks==2){
        Trougao::t2.first=t.first;
        Trougao::t2.second=t.second;
    }
    else if(indeks==3){
        Trougao::t3.first=t.first;
        Trougao::t3.second=t.second;
    }
} 
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
    double b=Trougao::Povrsina(t1, t2, t3);
    if(b>0) return 1;
    if(b<0) return -1;
    else return 0;
}
bool Trougao::DaLiJePozitivnoOrijentiran() const{
    if(Povrsina(t1,t2,t3)>0) return true;
    return false;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    double povrsina1, povrsina2, povrsina3, povrsina4;
    povrsina1=(abs(Povrsina(t1,t2,t3)))/2;
    povrsina2=(abs(Povrsina(t1,t2,t)))/2;
    povrsina3=(abs(Povrsina(t1,t3,t)))/2;
    povrsina4=(abs(Povrsina(t2,t3,t)))/2;
    double povrsina5=povrsina4+povrsina3+povrsina2;
    if(Isti(povrsina1, povrsina5)) return true;
    return false;
    
}
void Trougao::Ispisi() const{
    cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
}
void Trougao::Transliraj(double delta_x, double delta_y){
    t1.first=t1.first+delta_x;
    t1.second+=delta_y;
    t2.first+=delta_x;
    t2.second+=delta_y;
    t3.first+=delta_x;
    t3.second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t){
    Tacka teziste=Trougao::centar(t1,t2,t3);
    Tacka razlika;
    if(t.first>teziste.first){
        razlika.first=t.first-teziste.first;
    }
    if(t.second>teziste.second){
        razlika.second=t.second-teziste.second;
    }
    if(t.first<teziste.first){
        razlika.first=teziste.first-t.first;
    }
    if(t.second<teziste.second){
        razlika.second=teziste.second-t.second;
    }
    t1.first+=razlika.first;
    t2.first+=razlika.first;
    t3.first+=razlika.first;
    t1.second+=razlika.second;
    t2.second+=razlika.second;
    t3.second+=razlika.second;
}

void Trougao::Rotiraj(const Tacka &t, double ugao){
    Tacka pom1, pom2, pom3; pom1=make_pair(t1.first, t1.second);
    pom2=make_pair(t2.first, t2.second); pom3=make_pair(t3.first, t3.second);
    t1.first=t.first+(t1.first-t.first)*cos(ugao) - (t1.second-t.second)*sin(ugao);
    t1.second=t.second+(pom1.first-t.first)*sin(ugao)+(pom1.second-t.second)*cos(ugao);
    t2.first=t.first+(t2.first-t.first)*cos(ugao) - (t2.second-t.second)*sin(ugao);
    t2.second=t.second+(pom2.first-t.first)*sin(ugao)+(pom2.second-t.second)*cos(ugao);
    t3.first=t.first+(t3.first-t.first)*cos(ugao) - (t3.second-t.second)*sin(ugao);
    t3.second=t.second+(pom3.first-t.first)*sin(ugao)+(pom3.second-t.second)*cos(ugao);
}
void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(faktor==0) throw domain_error("Nekorektan faktor skaliranja");
    t1.first=t.first + faktor*(t1.first-t.first);
    t1.second=t.second + faktor*(t1.second-t.second);
    t2.first=t.first + faktor*(t2.first-t.first);
    t2.second=t.second + faktor*(t2.second-t.second);
    t3.first=t.first + faktor*(t3.first-t.first);
    t3.second=t.second + faktor*(t3.second-t.second);
}
void Trougao::Rotiraj(double ugao){
    Tacka center=Trougao::centar(t1,t2,t3);
    Rotiraj(center, ugao);
}
void Trougao::Skaliraj(double faktor){
    Tacka cen=Trougao::DajCentar();
    Skaliraj(cen, faktor);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    double p=Trougao::Povrsina(t1.t1, t1.t2, t1.t3);
    double p2=Trougao::Povrsina(t1.t1, t1.t2, t1.t3);
    int b=0;
    p=abs(p); p2=abs(p2);
    if(!(Trougao::Isti(p,p2))) return false;
    if(Trougao::Isti(t1.t1.first,t2.t1.first) && Trougao::Isti(t1.t1.second,t2.t1.second) && 
    Trougao::Isti(t1.t2.first, t2.t3.first) && Trougao::Isti(t1.t2.second, t2.t3.second) && 
    Trougao::Isti(t1.t3.first, t2.t2.first) && Trougao::Isti(t1.t3.second, t2.t2.second)) return true;
   
    else if(Trougao::Isti(t1.t1.first,t2.t1.first) && Trougao::Isti(t1.t1.second,t2.t1.second) && 
    Trougao::Isti(t1.t2.first, t2.t2.first) && Trougao::Isti(t1.t2.second, t2.t2.second) && 
    Trougao::Isti(t1.t3.first, t2.t3.first) && Trougao::Isti(t1.t3.second, t2.t3.second)) return true;
    
    else if(Trougao::Isti(t1.t1.first,t2.t3.first) && Trougao::Isti(t1.t1.second,t2.t3.second) && 
    Trougao::Isti(t1.t2.first, t2.t1.first) && Trougao::Isti(t1.t2.second, t2.t1.second) && 
    Trougao::Isti(t1.t3.first, t2.t2.first) && Trougao::Isti(t1.t3.second, t2.t2.second)) return true;
    
    else if(Trougao::Isti(t1.t1.first,t2.t3.first) && Trougao::Isti(t1.t1.second,t2.t3.second) && 
    Trougao::Isti(t1.t2.first, t2.t2.first) && Trougao::Isti(t1.t2.second, t2.t2.second) && 
    Trougao::Isti(t1.t3.first, t2.t1.first) && Trougao::Isti(t1.t3.second, t2.t1.second)) return true;
    
    else if(Trougao::Isti(t1.t1.first,t2.t2.first) && Trougao::Isti(t1.t1.second,t2.t2.second) && 
    Trougao::Isti(t1.t2.first, t2.t1.first) && Trougao::Isti(t1.t2.second, t2.t1.second) && 
    Trougao::Isti(t1.t3.first, t2.t3.first) && Trougao::Isti(t1.t3.second, t2.t3.second)) return true;
    
    else if(Trougao::Isti(t1.t1.first,t2.t2.first) && Trougao::Isti(t1.t1.second,t2.t2.second) && 
    Trougao::Isti(t1.t2.first, t2.t3.first) && Trougao::Isti(t1.t2.second, t2.t3.second) && 
    Trougao::Isti(t1.t3.first, t2.t1.first) && Trougao::Isti(t1.t3.second, t2.t1.second)) return true;
    
    
    else return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    if(DaLiSuIdenticni(t1,t2)) return true;
    double a=Trougao::Stranica(t1.t1, t1.t2);
    double b=Trougao::Stranica(t1.t2, t1.t3);
    double c=Trougao::Stranica(t1.t1,t1.t3);
    double a1=Trougao::Stranica(t2.t1, t2.t2);
    double b1=Trougao::Stranica(t2.t2, t2.t3);
    double c1=Trougao::Stranica(t2.t1,t2.t3);
    Trougao tp=t1; Trougao td=t2;
    double povrsina=Trougao::Povrsina(t1.t1, t1.t2, t1.t3);
    double povrsina2=Trougao::Povrsina(t2.t1, t2.t2, t2.t3);
    
    Trougao::Apsolutna(tp.t1); Trougao::Apsolutna(tp.t2); Trougao::Apsolutna(tp.t3);
    Trougao::Apsolutna(td.t1); Trougao::Apsolutna(td.t2); Trougao::Apsolutna(td.t3);
    Tacka pom=Trougao::NajvisaTacka(tp.t1, tp.t2, tp.t3);
    Tacka pom2=Trougao::NajvisaTacka(td.t1, td.t2, td.t3);
    Tacka min1=Trougao::NajmanjaTacka(tp.t1, tp.t2, tp.t3);
    Tacka min2=Trougao::NajmanjaTacka(td.t1, td.t2, td.t3);
    Tacka sr1=Trougao::SrednjaTacka(tp.t1, tp.t2, tp.t3);
    Tacka sr2=Trougao::SrednjaTacka(td.t1, td.t2, td.t3);
    double s1=Trougao::Stranica(min1, sr1); double s11=Trougao::Stranica(min2, sr2);
    //if(Trougao::Isti(ugao1,ugao11) && Trougao::Isti(min))
    double s2=Trougao::Stranica(pom,min1); double s22=Trougao::Stranica(pom2,min2);
    double s3=Trougao::Stranica(pom, sr1); double s33=Trougao::Stranica(pom2,sr2);
    
    
    if(!(Trougao::Isti(povrsina, povrsina2))) return false;
    if(Trougao::Isti(a,a1) && Trougao::Isti(b,b1) && Trougao::Isti(c,c1) && Trougao::Isti(povrsina, povrsina2)) return true;
    else if(Trougao::Isti(a,a1) && Trougao::Isti(b,c1) && Trougao::Isti(c,b1) && Trougao::Isti(povrsina, povrsina2)) return true;
    else if(Trougao::Isti(a,b1) && Trougao::Isti(b,a1) && Trougao::Isti(c,c1) && Trougao::Isti(povrsina, povrsina2)) return true;
    else if(Trougao::Isti(a,b1) && Trougao::Isti(b,c1) && Trougao::Isti(c,a1 )&& Trougao::Isti(povrsina, povrsina2)) return true;
    else if(Trougao::Isti(a,c1) && Trougao::Isti(b,b1) && Trougao::Isti(c,a1) && Trougao::Isti(povrsina, povrsina2)) return true;
    else if(Trougao::Isti(a,c1) && Trougao::Isti(b,a1) && Trougao::Isti(c,b1) && Trougao::Isti(povrsina, povrsina2)) return true;

    
    if(Trougao::Isti(pom.second, pom2.second) && Trougao::Isti(min1.second, min2.second) 
    && Trougao::Isti(sr1.second, sr2.second) && Trougao::Isti(s1,s11)) return false;

    
}
    
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    double p=Trougao::Povrsina(t1.t1, t1.t2, t1.t3);
    double p2=Trougao::Povrsina(t1.t1, t1.t2, t1.t3);
    
    p=abs(p); p2=abs(p2);
    
    if((Trougao::Isti(p,p2))){
    Tacka nula; nula=make_pair(0,0);
    double a=Trougao::Stranica(t1.t1, t1.t2);
    double b=Trougao::Stranica(t1.t1, t1.t3);
    double c=Trougao::Stranica(t1.t2, t1.t3);
    double a1=Trougao::Stranica(t2.t1, t2.t2);
    double b1=Trougao::Stranica(t2.t1, t2.t3);
    double c1=Trougao::Stranica(t2.t2, t2.t3);
    double o1=a/a1, o2=b/b1, o3=c/c1;
    if(DaLiSuIdenticni(t1,t2)) return true;
    if(DaLiSuPodudarni(t1,t2)) return true;
    if(Trougao::Isti(o1,o2) && Trougao::Isti(o1, o3)) return true;
    //return false;
}
return false;
}
int main ()
{
    int n;
    cout<<"Koliko zelite kreirati trouglova: ";
    cin>>n;
    try{
        vector<shared_ptr<Trougao>>trougao;
        trougao.resize(n);
        Tacka a,b,c;
        for(int i=0; i<trougao.size(); i++) trougao[i]=nullptr;
        for(int i=0; i<trougao.size(); i++){
        try{
            double x1,y1,x2,y2,x3,y3;
            
            cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            cin>>x1>>y1>>x2>>y2>>x3>>y3;
            a=make_pair(x1,y1);
            b=make_pair(x2,y2);
            c=make_pair(x3,y3);
            shared_ptr<Trougao>pp(new Trougao(a,b,c));
            //trougao.push_back(pp);
            trougao[i]=pp;
        }
        catch(domain_error izuzetak){
            cout<<izuzetak.what()<<", ponovite unos!"<<endl;
            i--;
        }
    }
   
    
    vector<shared_ptr<Trougao>>trougao2=trougao;
    cout<<"Unesite vektor translacije (dx dy): ";
    double delta_x, delta_y;
    cin>>delta_x>>delta_y;
    /*for(int i=0; i<trougao.size(); i++){
        trougao[i]->Transliraj(delta_x, delta_y);
    }*/
    cout<<"Unesite ugao rotacije: ";
    double ugao;
    cin>>ugao;
    cout<<"Unesite faktor skaliranja: ";
    double f;
    cin>>f;
    cout<<"Trouglovi nakon obavljenih transformacija: "<<endl;
    //Tacka tjeme=trougao.DajTjeme(1);
  
    transform(trougao.begin(), trougao.end(), trougao.begin(),
    [delta_x, delta_y](shared_ptr<Trougao>p){
        p->Transliraj(delta_x, delta_y);
        return p;
    });
    transform(trougao.begin(), trougao.end(), trougao.begin(),
    [ugao](shared_ptr<Trougao>pp){
        pp->Rotiraj(ugao);
        return pp;
    });
    Tacka t1=make_pair(3,5);
    transform(trougao.begin(), trougao.end(), trougao.begin(),
    [f, t1](shared_ptr<Trougao>pok){
        pok->Skaliraj(pok->DajTjeme(1), f);
        return pok;
    });
    sort(trougao.begin(), trougao.end(), 
    [](shared_ptr<Trougao>p1, shared_ptr<Trougao>p2){
       return p1->DajPovrsinu()<p2->DajPovrsinu();
        
    });
    for_each(trougao.begin(), trougao.end(), [](shared_ptr<Trougao>pok){
        pok->Ispisi();
        cout<<endl;
        //return pok;
    });
    cout<<"Trougao sa najmanjim obimom: ";
    auto mini=min_element(&trougao[0], &trougao[trougao.size()], 
    [](shared_ptr<Trougao>p1, shared_ptr<Trougao>p2){
       if((*p1).DajObim() < (*p2).DajObim()) return true;
       return false;
    });
    (*mini)->Ispisi();
    cout<<endl;
    int broj=0;
    for(auto i=trougao.begin(); i!=trougao.end(); i++){
        for(auto j=i; j!=trougao.end(); j++){
            if(j!=i){
                if(DaLiSuIdenticni(**i, **j)){
                    broj++;
                    if(broj==1) cout<<"Parovi identicnih trouglova: "<<endl;
                    (**i).Ispisi();
                    cout<<" i ";
                    (**j).Ispisi();
                    cout<<endl;
                }
            }
        }
    }
    if(broj==0) cout<<"Nema identicnih trouglova!"<<endl;
    int bb=0;
    for(auto i=trougao.begin(); i!=trougao.end(); i++){
        for(auto j=i; j!=trougao.end(); j++){
            if(j!=i){
                if(DaLiSuPodudarni(**i, **j)){
                    bb++;
                    if(bb==1) cout<<"Parovi podudarnih trouglova:"<<endl;
                    (**i).Ispisi();
                    cout<<" i ";
                    (**j).Ispisi();
                    cout<<endl;
                }
            }
        }
    }
    if(bb==0) cout<<"Nema podudarnih trouglova!"<<endl;
    int bc=0;
    for(auto i=trougao.begin(); i!=trougao.end(); i++){
        for(auto j=i; j!=trougao.end(); j++){
            if(j!=i){
                if(DaLiSuSlicni(**i, **j)){
                    bc++;
                    if(bc==1) cout<<"Parovi slicnih trouglova:"<<endl;
                    (**i).Ispisi();
                    cout<<" i ";
                    (**j).Ispisi();
                    cout<<endl;
                }
            }
        }
    }
    if(bc==0) cout<<"Nema slicnih trouglova!"<<endl;
    }
    catch(bad_alloc){
        cout<<"Lose";
    }
   
   
   
	return 0;
}