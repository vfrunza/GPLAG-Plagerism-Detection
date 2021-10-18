/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <memory>
#include <algorithm>
#define EPS 0.000001

typedef std::pair<double, double> Tacka;

class Trougao {
        Tacka t1,t2,t3;
    public:
        Trougao(const Tacka & t1, const Tacka & t2, const Tacka & t3);
        void Postavi(const Tacka & t1, const Tacka & t2, const Tacka & t3);
        void Postavi(int indeks, const Tacka & t);
        static int Orijentacija(const Tacka & t1, const Tacka & t2, const Tacka & t3);
        Tacka DajTjeme(int indeks) const;
        double DajStranicu(int indeks) const;
        double DajUgao(int indeks) const;
        Tacka DajCentar() const;
        double DajObim() const;
        double DajPovrsinu() const;
        bool DaLiJePozitivnoOrijentiran() const;
        bool DaLiJeUnutra(const Tacka & t) const;
        void Ispisi() const;
        void Transliraj(double delta_x, double delta_y);
        void Centriraj(const Tacka & t);
        void Rotiraj(const Tacka & t, double ugao);
        void Skaliraj(const Tacka & t, double faktor);
        void Rotiraj(double ugao);
        void Skaliraj(double faktor);
        friend bool DaLiSuIdenticni(const Trougao & t1, const Trougao & t2);
        friend bool DaLiSuPodudarni(const Trougao & t1, const Trougao & t2);
        friend bool DaLiSuSlicni(const Trougao & t1, const Trougao & t2);
};
/*
Trougao::Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if (Trougao::Orijentacija==0) throw std::domain_error ("Nekorektne pozicije tjemena");
    Trougao::Postavi(t1,t2,t3);
}*/
//FUNKCIJA POSTAVI TJEMENA TROUGLA
void Trougao::Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    Trougao::t1.first=t1.first; Trougao::t1.second=t1.second;
    Trougao::t2.first=t2.first; Trougao::t2.second=t2.second;
    Trougao::t3.first=t3.first; Trougao::t3.second=t3.second;
}

bool Validan_indeks (int broj) {
    if (broj!=1 && broj!=2 && broj!=3) return false;
    return true;
}
//FUNKCIJA POSTAVLJA JEDNO TJEME, BIRAMO GA POMOCU INDEKSA
void Trougao::Postavi (int indeks,const Tacka &t) {
    if (!Validan_indeks(indeks)) throw std::range_error("Nekorektan indeks");
    if (indeks==1) { t1.first=t.first; t1.second=t.second; }
    else if (indeks==2) { t2.first=t.first; t2.second=t.second; }
    else { t3.first=t.first; t3.second=t.second; }
    if (Trougao::Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
}

double Vrijednost_za_orijentaciju (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    double vrijed=0;
    vrijed=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    return vrijed;
}
//PROVJERA ORIJENTACIJE TROUGLA, POZ-SUPROTNO OD MIJERA KAZALJKE, NEG-U SMIJERU KAZALJKE
int Trougao::Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    int orijentacija=1;
    double vrijednost=Vrijednost_za_orijentaciju(t1,t2,t3);
    if (vrijednost<EPS && vrijednost>(-EPS)) orijentacija=0;
    else if (vrijednost<0) orijentacija=-1;
    return orijentacija;
}
//KONSTRUKTOR
Trougao::Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
    if (Trougao::Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
    Trougao::t1=t1; Trougao::t2=t2; Trougao::t3=t3;
}

//VRACA KOORDINATE TJEMENA, BIRAMO INDEKSOM
Tacka Trougao::DajTjeme (int indeks) const {
    if (!Validan_indeks(indeks)) throw std::range_error("Nekorektan indeks");
    if (indeks==1) return t1;
    else if (indeks==2) return t2;
    return t3;
}
//VRACA DUZINU STRANICE, ODREDJENE INDEKSOM
double Trougao::DajStranicu (int indeks) const {
    if (!Validan_indeks(indeks)) throw std::range_error("Nekorektan indeks");
    double duzina=0;
    if (indeks==1) duzina=sqrt((t2.first-t3.first)*(t2.first-t3.first)+(t2.second-t3.second)*(t2.second-t3.second));
    else if (indeks==2) duzina=sqrt((t1.first-t3.first)*(t1.first-t3.first)+(t1.second-t3.second)*(t1.second-t3.second));
    else duzina=sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
    return duzina;
}
//VRACA VRIJEDNOST UGLA, ODREDJENOG INDEKSOM
double Trougao::DajUgao (int indeks) const {
    if (!Validan_indeks(indeks)) throw std::range_error("Nekorektan indeks");
    double velicina=0;
    int a=1,b=2,c=3;
    if (indeks==1) velicina=acos((Trougao::DajStranicu(b)+Trougao::DajStranicu(c)-Trougao::DajStranicu(indeks))/(2*Trougao::DajStranicu(b)*Trougao::DajStranicu(c)));
    else if (indeks==2) velicina=acos((Trougao::DajStranicu(a)+Trougao::DajStranicu(c)-Trougao::DajStranicu(indeks))/(2*Trougao::DajStranicu(a)*Trougao::DajStranicu(c)));
    else velicina=acos((Trougao::DajStranicu(a)+Trougao::DajStranicu(b)-Trougao::DajStranicu(indeks))/(2*Trougao::DajStranicu(a)*Trougao::DajStranicu(b)));
    return velicina;
}
//VRACA TACKU CENTRA, TJ TEZISTA TROUGLA
Tacka Trougao::DajCentar() const {
    Tacka c;
    c.first=(t1.first+t2.first+t3.first)/3;
    c.second=(t1.second+t2.second+t3.second)/3;
    return c;
}
//RACUNA OBIM TROUGLA
double Trougao::DajObim() const {
    int a=1,b=2,c=3;
    return Trougao::DajStranicu(a)+Trougao::DajStranicu(b)+Trougao::DajStranicu(c);
}
//POVRSINA TRUGLA
double Trougao::DajPovrsinu() const {
    return fabs(Vrijednost_za_orijentaciju(Trougao::t1,Trougao::t2,Trougao::t3))/2;
}

bool Trougao::DaLiJePozitivnoOrijentiran() const {
    if(Trougao::Orijentacija(Trougao::t1,Trougao::t2,Trougao::t3)==1) return true;
    return false; 
}
//PROVJERAVA DA LI JE ZADANA TACKA UNUTAR TROUGLA
bool Trougao::DaLiJeUnutra (const Tacka & t) const {
    if (Trougao::Orijentacija(Trougao::t1,Trougao::t2,Trougao::t3)!=0 && Trougao::Orijentacija(Trougao::t1,Trougao::t2,Trougao::t3)==Trougao::Orijentacija(Trougao::t1,Trougao::t2,t) && Trougao::Orijentacija(Trougao::t1,Trougao::t2,Trougao::t3)==Trougao::Orijentacija(Trougao::t2,Trougao::t3,t) && Trougao::Orijentacija(Trougao::t1,Trougao::t2,Trougao::t3)==Trougao::Orijentacija(Trougao::t3,Trougao::t1,t))
        return true;
    return false;
}
//ISPISUJE VRIJEDNOST TJEMENA TROUGLA
void Trougao::Ispisi() const {
    std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first<<","<<t3.second<<"))";
}
//TRANSLIRAJ TROUGAO
void Trougao::Transliraj (double delta_x, double delta_y) {
    t1.first+=delta_x; t2.first+=delta_x; t3.first+=delta_x;
    t1.second+=delta_y; t2.second+=delta_y; t3.second+=delta_y;
}
//CENTRIRAJ TROUGAO, TRANSLIRA GA TAKO DA TACKA TRANSLACIJE BUDE NJEGOV CENTAR
void Trougao::Centriraj (const Tacka & t) {
    Tacka c=Trougao::DajCentar();
    double x=t.first-c.first, y=t.second-c.second;
    Transliraj(x,y);
}

void Rotira_tacku (Tacka &t, const Tacka &tc, double alfa) {
    double tx=t.first,ty=t.second;
    t.first=tc.first+(tx-tc.first)*cos(alfa)-(ty-tc.second)*sin(alfa);
    t.second=tc.second+(tx-tc.first)*sin(alfa)+(ty-tc.second)*cos(alfa);
}
//ROTIRAJ OKO NEKE TACKE, ZA ZADANI UGAO
void Trougao::Rotiraj (const Tacka &t, double ugao) {
    Rotira_tacku(Trougao::t1,t,ugao);
    Rotira_tacku(Trougao::t2,t,ugao);
    Rotira_tacku(Trougao::t3,t,ugao);
}

void Skalira_tacku (Tacka &tn, const Tacka &c, double faktor) {
    tn.first=c.first+faktor*(tn.first-c.first);
    tn.second=c.second+faktor*(tn.second-c.second);
}
//SKALIRAJ TROUGAO OKO NEKE TACKE ZA ZADANI FAKTOR
void Trougao::Skaliraj (const Tacka &t, double faktor) {
    if (faktor<EPS && faktor>(-EPS)) throw std::domain_error("Nekorektan faktor skaliranja");
    Skalira_tacku(Trougao::t1,t,faktor);
    Skalira_tacku(Trougao::t2,t,faktor);
    Skalira_tacku(Trougao::t3,t,faktor);
}
//ROTIRAJ OKO CENTRA TROUGLA
void Trougao::Rotiraj (double ugao) {
    Trougao::Rotiraj(Trougao::DajCentar(),ugao);
}
//SKALIRAJ OKO CENTRA TROUGLA
void Trougao::Skaliraj (double faktor) {
    Trougao::Skaliraj(Trougao::DajCentar(),faktor);
}

bool Ista_tacka (const Tacka &T1,const Tacka &T2) {
    if (T1.first-T2.first<EPS && T1.first-T2.first>(-EPS) && T1.second-T2.second<EPS && T1.second-T2.second>(-EPS)) return true;
    return false;
}

bool Duzina_jednaka(double d1, double d2) {
    if (d1-d2<EPS && d1-d2>(-EPS)) return true;
    return false;
}
//DA LI SU TROUGLOVI IDENTICNI, ISTE VELICINE, NA ISTOM MJESTU
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    if (Duzina_jednaka(t1.DajObim(),t2.DajObim())==true && Duzina_jednaka(t1.DajPovrsinu(),t2.DajPovrsinu())==true) {
        if (((Ista_tacka(t1.t1,t2.t1) && Ista_tacka(t1.t2,t2.t2) ) || (Ista_tacka(t1.t1,t2.t1) && Ista_tacka(t1.t2,t2.t3)) || (Ista_tacka(t1.t1,t2.t2) && Ista_tacka(t1.t2,t2.t1)) || (Ista_tacka(t1.t1,t2.t2) && Ista_tacka(t1.t2,t2.t3)) || (Ista_tacka(t1.t1,t2.t3) && Ista_tacka(t1.t2,t2.t1)) || (Ista_tacka(t1.t1,t2.t3) && Ista_tacka(t1.t2,t2.t2))) && DaLiSuPodudarni(t1,t2))
        return true;
    }
    return false;
}

double Duzina_stranice (Tacka t1,Tacka t2) {
    return sqrt((t2.first-t1.first)*(t2.first-t1.first)+(t2.second-t1.second)*(t2.second-t1.second));
}
//DA LI SU PODUDARNI TROUGLOVI, ISTEVELICINE I ISTOG RASPOREDA
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
    double x1=Duzina_stranice(t1.t2,t1.t3),y1=Duzina_stranice(t1.t1,t1.t3),z1=Duzina_stranice(t1.t1,t1.t2);
    double x2=Duzina_stranice(t2.t2,t2.t3),y2=Duzina_stranice(t2.t1,t2.t3),z2=Duzina_stranice(t2.t1,t2.t2);
    
    if (Duzina_jednaka(x1,x2) && Duzina_jednaka(y1,y2) && Duzina_jednaka(z1,z2) && Duzina_jednaka(Vrijednost_za_orijentaciju(t1.t2,t1.t3,t1.t1),Vrijednost_za_orijentaciju(t2.t2,t2.t3,t2.t1))) return true;
    else if (Duzina_jednaka(x1,x2) && Duzina_jednaka(y1,z2) && Duzina_jednaka(z1,y2) && Duzina_jednaka(Vrijednost_za_orijentaciju(t1.t2,t1.t3,t1.t1),Vrijednost_za_orijentaciju(t2.t3,t2.t2,t2.t1))) return true;
    else if (Duzina_jednaka(x1,y2) && Duzina_jednaka(y1,x2) && Duzina_jednaka(z1,z2) && Duzina_jednaka(Vrijednost_za_orijentaciju(t1.t2,t1.t3,t1.t1),Vrijednost_za_orijentaciju(t2.t1,t2.t3,t2.t2))) return true;
    else if (Duzina_jednaka(x1,y2) && Duzina_jednaka(y1,z2) && Duzina_jednaka(z1,x2) && Duzina_jednaka(Vrijednost_za_orijentaciju(t1.t2,t1.t3,t1.t1),Vrijednost_za_orijentaciju(t2.t3,t2.t1,t2.t2))) return true;
    else if (Duzina_jednaka(x1,z2) && Duzina_jednaka(y1,x2) && Duzina_jednaka(z1,y2) && Duzina_jednaka(Vrijednost_za_orijentaciju(t1.t2,t1.t3,t1.t1),Vrijednost_za_orijentaciju(t2.t1,t2.t2,t2.t3))) return true; 
    else if (Duzina_jednaka(x1,z2) && Duzina_jednaka(y1,y2) && Duzina_jednaka(z1,x2) && Duzina_jednaka(Vrijednost_za_orijentaciju(t1.t2,t1.t3,t1.t1),Vrijednost_za_orijentaciju(t2.t2,t2.t1,t2.t3))) return true;
    return false;
}
bool DaLiSuSlicni(const Trougao & t1, const Trougao & t2) {
    double x1=Duzina_stranice(t1.t2,t1.t3),y1=Duzina_stranice(t1.t1,t1.t3),z1=Duzina_stranice(t1.t1,t1.t2);
    double x2=Duzina_stranice(t2.t2,t2.t3),y2=Duzina_stranice(t2.t1,t2.t3),z2=Duzina_stranice(t2.t1,t2.t2);
    if(Duzina_jednaka(x1/x2,y1/y2) && Duzina_jednaka(y1/y2,z1/z2) && Duzina_jednaka(Vrijednost_za_orijentaciju(t1.t2,t1.t3,t1.t1),Vrijednost_za_orijentaciju(t2.t2,t2.t3,t2.t1))) return true;
    else if(Duzina_jednaka(x1/x2,y1/z2) && Duzina_jednaka(y1/z2,z1/y2) && Duzina_jednaka(Vrijednost_za_orijentaciju(t1.t2,t1.t3,t1.t1),Vrijednost_za_orijentaciju(t2.t3,t2.t2,t2.t1))) return true;
    else if(Duzina_jednaka(x1/y2,y1/x2) && Duzina_jednaka(y1/x2,z1/z2) && Duzina_jednaka(Vrijednost_za_orijentaciju(t1.t2,t1.t3,t1.t1),Vrijednost_za_orijentaciju(t2.t1,t2.t3,t2.t2))) return true;
    else if(Duzina_jednaka(x1/y2,y1/z2) && Duzina_jednaka(y1/z2,z1/x2) && Duzina_jednaka(Vrijednost_za_orijentaciju(t1.t2,t1.t3,t1.t1),Vrijednost_za_orijentaciju(t2.t3,t2.t1,t2.t2))) return true;
    else if(Duzina_jednaka(x1/z2,y1/x2) && Duzina_jednaka(y1/x2,z1/y2) && Duzina_jednaka(Vrijednost_za_orijentaciju(t1.t2,t1.t3,t1.t1),Vrijednost_za_orijentaciju(t2.t1,t2.t2,t2.t3))) return true;
    else if(Duzina_jednaka(x1/z2,y1/y2) && Duzina_jednaka(y1/y2,z1/x2) && Duzina_jednaka(Vrijednost_za_orijentaciju(t1.t2,t1.t3,t1.t1),Vrijednost_za_orijentaciju(t2.t2,t2.t1,t2.t3))) return true;
    return false;
}

void Unos_tjemena (Tacka &t) {
    double x,y;
    std::cin>>x>>y;
    t.first=x; t.second=y;
}

int main ()
{
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> v_troug;
    for (int i=0; i<n; i++) {
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        Tacka A,B,C;
        Unos_tjemena(A);
        Unos_tjemena(B);
        Unos_tjemena(C);
        try {
            std::shared_ptr<Trougao>n(new Trougao(A,B,C));
            v_troug.push_back(n); 
        }
        catch (std::domain_error a) {
            std::cout<<a.what()<<", ponovite unos!"<<std::endl;;
            i--;
        }
        catch (std::bad_alloc) {
            std::cout<<"Nedovoljno memorije."<<std::endl;
        }
    }
    double x,y,alfa,faktor;
        
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>x>>y;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>alfa;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor;
    std::cout<<"Trouglovi nakon obavljenih transformacija:\n";
    
    std::transform (v_troug.begin(), v_troug.end(), v_troug.begin(), [x,y] (std::shared_ptr<Trougao> a) 
    { a->Trougao::Transliraj(x,y); return a;} );
    std::transform (v_troug.begin(), v_troug.end(),v_troug.begin(), [alfa] (std::shared_ptr<Trougao> a) 
    { a->Trougao::Rotiraj(alfa); return a; });
    std::transform (v_troug.begin(), v_troug.end(), v_troug.begin(), [faktor] (std::shared_ptr<Trougao> a) 
    { int broj=1;
    Tacka centar=a->Trougao::DajTjeme(broj); 
    a->Trougao::Skaliraj(centar,faktor);
    return a; });
    std::sort (v_troug.begin(), v_troug.end(), [] (std::shared_ptr<Trougao> a, std::shared_ptr<Trougao> b) {if((a->Trougao::DajPovrsinu())<(b->Trougao::DajPovrsinu())) return true; else return false; });
    std::for_each (v_troug.begin(), v_troug.end(), [] (std::shared_ptr<Trougao> a) { a->Trougao::Ispisi(); std::cout<<std::endl;});
    
    std::cout<<"Trougao sa najmanjim obimom: ";    
    auto min=std::min_element(v_troug.begin(), v_troug.end(), [] (std::shared_ptr<Trougao> a, std::shared_ptr<Trougao> b) { if(a->Trougao::DajObim()<b->Trougao::DajObim()) return true; return false; });
    (**min).Trougao::Ispisi();
    std::cout<<std::endl;
    
      //  std::for_each (v_troug.begin(), v_troug.end(), [] (std::shared_ptr<Trougao> a, std::shared_ptr<Trougao> b) { if(DaLiSuIdenticni(*a,*b)==true) {(**a).Trougao::Ispisi(); std::cout<<" "; (**b).Trougao::Ispisi(); std::cout<<std::endl;} });
        
        //std::for_each (v_troug.begin(), v_troug.end(), [] (std::shared_ptr<Trougao> a, std::shared_ptr<Trougao> b) { if(DaLiSuPodudarni(*a,*b)==true) {(**a).Trougao::Ispisi(); std::cout<<" "; (**b).Trougao::Ispisi(); std::cout<<std::endl;} });
        
    //    std::for_each (v_troug.begin(), v_troug.end(), [] (std::shared_ptr<Trougao> a, std::shared_ptr<Trougao> b)  { if(DaLiSuSlicni(*a,*b)==true) {(**a).Trougao::Ispisi(); std::cout<<" "; (**b).Trougao::Ispisi(); std::cout<<std::endl;} });
//    std::cout<<"Parovi identicnih trouglova:\n";
    int g=0;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if (DaLiSuIdenticni(*v_troug[i],*v_troug[j])==true) {
                if (g==0) {std::cout<<"Parovi identicnih trouglova:\n"; g=1;}
                v_troug[i]->Trougao::Ispisi(); 
                std::cout<<" i "; 
                v_troug[j]->Ispisi(); 
                std::cout<<std::endl;
            }
    if (g==0) std::cout<<"Nema identicnih trouglova!\n";
 //   std::cout<<"Parovi podudarnih trouglova:\n";
    int a=0;
    for(int i=0; i<n; i++) 
        for (int j=i+1; j<n; j++)
            if(DaLiSuPodudarni(*v_troug[i],*v_troug[j])==true) {
                if (a==0) {std::cout<<"Parovi podudarnih trouglova:\n"; a=1; }
                v_troug[i]->Trougao::Ispisi();
                std::cout<<" i ";
                v_troug[j]->Trougao::Ispisi();
                std::cout<<std::endl;
            }
    if(a==0) std::cout<<"Nema podudarnih trouglova!\n";
    
///    std::cout<<"Parovi slicnih trouglova:\n";
    int b=0;
    for(int i=0; i<n; i++) 
        for(int j=i+1; j<n; j++)
            if(DaLiSuSlicni(*v_troug[i],*v_troug[j])==true) {
                if(b==0) {std::cout<<"Parovi slicnih trouglova:\n"; b=1;}
                v_troug[i]->Trougao::Ispisi();
                std::cout<<" i ";
                v_troug[j]->Trougao::Ispisi();
                std::cout<<std::endl;
            }
    if (b==0) std::cout<<"Nema slicnih trouglova!\n";
	return 0;
}