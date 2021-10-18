/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>


typedef std::pair<double, double> Tacka;
class Trougao
{
   Tacka a,b,c;
    static bool JesuLiJednaki(double x, double y, double Eps=1e-10) { //SMIJE LI SE DODATI FIJA
        return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
    }
public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        Postavi(t1,t2,t3);
    } 
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
        a.first=t1.first;
        a.second=t1.second;
        b.first=t2.first;
        b.second=t2.second;
        c.first=t3.first;
        c.second=t3.second;
    }
    void Postavi(int indeks, const Tacka &t) {
        if(indeks != 1 || indeks != 2 || indeks != 3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) {
            a.first=t.first;
            a.second=t.second;
            if(Orijentacija(a,b,c)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
        } else if(indeks==2) {
            b.first=t.first;
            b.second=t.second;
             if(Orijentacija(a,b,c)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
        } else if(indeks==3) {
            c.first=t.first;
            c.second=t.second;
             if(Orijentacija(a,b,c)==0) throw std::domain_error("Nekorektne pozicije tjemena, ponovite unos!");
        }
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        int orijentacija=0;
        if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))<0) orijentacija=-1;
        else if((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second))>0) orijentacija=1;
        else orijentacija=0;


        return orijentacija;
    }
    Tacka DajTjeme(int indeks) const {
        if(indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) return a;
        else if(indeks==2) return b;
        else /*if(indeks==3) */return c;
    }
    double DajStranicu(int indeks) const {
        if(indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
        if(indeks==1) {
            return sqrt((b.first-c.first)*(b.first-c.first)+(b.second-c.second)*(b.second-c.second));
        } else if(indeks==2) {
            return sqrt((a.first-c.first)*(a.first-c.first)+(a.second-c.second)*(a.second-c.second));
        } else {
            return sqrt((b.first-a.first)*(b.first-a.first)+(b.second-a.second)*(b.second-a.second));
        }
    }
    double DajUgao(int indeks) const {
        if(indeks != 1 && indeks != 2 && indeks != 3) throw std::range_error("Nekorektan indeks");
        double stranica_a=DajStranicu(1);
        double stranica_b=DajStranicu(2);
        double stranica_c=DajStranicu(3);
        double ugao=0;
        if(indeks==1) {
            ugao=acos((stranica_b*stranica_b+stranica_c*stranica_c-stranica_a*stranica_a)/(2*stranica_b*stranica_c));
        } else if(indeks==2) {
            ugao=acos((stranica_a*stranica_a+stranica_c*stranica_c-stranica_b*stranica_b)/(2*stranica_a*stranica_c));
        } else if(indeks==3) {
            ugao=acos((stranica_b*stranica_b+stranica_a*stranica_a-stranica_c*stranica_c)/(2*stranica_b*stranica_a));
        }
        return ugao;
    }
    Tacka DajCentar() const {
        Tacka centar;
        centar.first=(a.first+b.first+c.first)/3;
        centar.second=(a.second+b.second+c.second)/3;
        return centar;
    }
    double DajObim() const {
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu() const {
        double p;
        p=0.5*fabs(a.first*(b.second-c.second)-b.first*(a.second-c.second)+c.first*(a.second-b.second));
        return p;
    }
    bool DaLiJePozitivnoOrijentiran() const {
        return Orijentacija(a,b,c)==1;
    }
    bool DaLiJeUnutra(const Tacka &t) const {
        if(Orijentacija(a,b,c)==1) {
            if(Orijentacija(a,b,t)==-1) return false;
            else if(Orijentacija(b,c,t)==-1) return false;
            else if(Orijentacija(c,a,t)==-1) return false;
        } else if(Orijentacija(a,b,c)==-1) {
            if(Orijentacija(a,b,t)==1) return false;
            else if(Orijentacija(b,c,t)==1) return false;
            else if(Orijentacija(c,a,t)==1) return false;
        } else return true;
    }
    void Ispisi() const {
        std::cout<<"(("<<a.first<<" , "<<a.second<<") , ("<<b.first<<" , "<<b.second<<") , ("<<c.first<<" , "<<c.second<<"))";
    }
    void Transliraj (double delta_x, double delta_y) {
        a.first+=delta_x;
        b.first+=delta_x;
        c.first+=delta_x;
        a.second+=delta_y;
        b.second+=delta_y;
        c.second+=delta_y;
    }
    void Centriraj (const Tacka &t) {
        Tacka centar=DajCentar();
        double deltax=centar.first-t.first;
        double deltay=centar.second-t.second;
        Transliraj(deltax, deltay);
    }
    void Rotiraj(const Tacka &t, double ugao) {
        Tacka ar, br, cr;
        ar.first=t.first+(a.first-t.first)*cos(ugao)-(a.second-t.second)*sin(ugao);
        ar.second=t.second+(a.first-t.first)*sin(ugao)+(a.second-t.second)*cos(ugao);
        a.first=ar.first;
        a.second=ar.second;

        br.first=t.first+(b.first-t.first)*cos(ugao)-(b.second-t.second)*sin(ugao);
        br.second=t.second+(b.first-t.first)*sin(ugao)+(b.second-t.second)*cos(ugao);
        b.first=br.first;
        b.second=br.second;

        cr.first=t.first+(c.first-t.first)*cos(ugao)-(c.second-t.second)*sin(ugao);
        cr.second=t.second+(c.first-t.first)*sin(ugao)+(c.second-t.second)*cos(ugao);
        c.first=cr.first;
        c.second=cr.second;
    }
    void Skaliraj(const Tacka &t, double faktor) {
        Tacka as,bs,cs;
        if(JesuLiJednaki(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
        if(faktor<1) {
            Rotiraj(t, atan(1*4)); //za 180 stepeni ne znam jel u rad treba else if?
        }

        as.first=t.first+faktor*(a.first-t.first);
        as.second=t.second+faktor*(a.second-t.second); // jel ovdje trebalo -t.second
        a.first=as.first;
        a.second=as.second;

        bs.first=t.first+faktor*(b.first-t.first);
        bs.second=t.second+faktor*(b.second-t.second); // jel ovdje trebalo -t.second
        b.first=bs.first;
        b.second=bs.second;

        cs.first=t.first+faktor*(c.first-t.first);
        cs.second=t.second+faktor*(c.second-t.second); // jel ovdje trebalo -t.second
        c.first=cs.first;
        c.second=cs.second;

    }
    void Rotiraj(double ugao) {
        Tacka centar=DajCentar();
        Rotiraj(centar, ugao);

    }
    void Skaliraj(double faktor) {
        Tacka centar=DajCentar();
        Skaliraj(centar, faktor);
    }
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
    if(t1.a==t2.a && t1.b==t2.b && t1.c==t2.c) return true;
    else if(t1.a==t2.a && t1.b==t2.c && t1.c==t2.b) return true;
    else if(t1.a==t2.b && t1.b==t2.a && t1.c==t2.c) return true;
    else if(t1.a==t2.b && t1.b==t2.c && t1.c==t2.a) return true;
    else if(t1.a==t2.c && t1.b==t2.a && t1.c==t2.b) return true;
    else if(t1.a==t2.c && t1.b==t2.b && t1.c==t2.a) return true;
    else return false;
    }
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
        double stra1=t1.DajStranicu(1);
        double strb1=t1.DajStranicu(2);
        double strc1=t1.DajStranicu(3);
        double stra2=t2.DajStranicu(1);
        double strb2=t2.DajStranicu(2);
        double strc2=t2.DajStranicu(3);
        Tacka a1, b1,c1,a2,b2,c2;
        if(stra1<strb1 && stra1<strc1) {
            a1=t1.a;
            if(strb1<strc1) {
                b1=t1.b;
                c1=t1.c;
            } else {
                b1=t1.c;
                c1=t1.b;
            }
        } else if(strb1<stra1 && strb1<strc1) {
            a1=t1.b;
            if(stra1<strc1) {
                b1=t1.a;
                c1=t1.c;
            } else {
                b1=t1.c;
                c1=t1.a;
            }
        } else {
            a1=t1.c;
            if(strb1<stra1) {
                b1=t1.b;
                c1=t1.a;
            } else {
                b1=t1.a;
                c1=t1.b;
            }
        }
        //2
        if(stra2<strb2 && stra2<strc2) {
            a2=t2.a;
            if(strb2<strc2) {
                b2=t2.b;
                c2=t2.c;
            } else {
                b2=t2.c;
                c2=t2.b;
            }
        } else if(strb2<stra2 && strb2<strc2) {
            a2=t2.b;
            if(stra2<strc2) {
                b2=t2.a;
                c2=t2.c;
            } else {
                b2=t2.c;
                c2=t2.a;
            }
        } else {
            a2=t2.c;
            if(strb2<stra2) {
                b2=t2.b;
                c2=t2.a;
            } else {
                b2=t2.a;
                c2=t2.b;
            }
        }

        bool straniceIste=false;
        Trougao s1(a1,b1,c1),s2(a2,b2,c2);
        if(JesuLiJednaki(s1.DajStranicu(1),s2.DajStranicu(1)) && JesuLiJednaki(s1.DajStranicu(2),s2.DajStranicu(2)) && JesuLiJednaki(s1.DajStranicu(3),s2.DajStranicu(3)))

            straniceIste=true;

        if(straniceIste && (JesuLiJednaki(s1.DajStranicu(1),s1.DajStranicu(2)) || JesuLiJednaki(s1.DajStranicu(1),s1.DajStranicu(3)) || JesuLiJednaki(s1.DajStranicu(3),s1.DajStranicu(2)))) return true;

                return straniceIste && Orijentacija(a1,b1,c1) == Orijentacija(a2,b2,c2);
    }
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2) {
        double stra1=t1.DajStranicu(1);
        double strb1=t1.DajStranicu(2);
        double strc1=t1.DajStranicu(3);
        double stra2=t2.DajStranicu(1);
        double strb2=t2.DajStranicu(2);
        double strc2=t2.DajStranicu(3);
        Tacka a1, b1,c1,a2,b2,c2;
        if(stra1<strb1 && stra1<strc1) {
            a1=t1.a;
            if(strb1<strc1) {
                b1=t1.b;
                c1=t1.c;
            } else {
                b1=t1.c;
                c1=t1.b;
            }
        } else if(strb1<stra1 && strb1<strc1) {
            a1=t1.b;
            if(stra1<strc1) {
                b1=t1.a;
                c1=t1.c;
            } else {
                b1=t1.c;
                c1=t1.a;
            }
        } else {
            a1=t1.c;
            if(strb1<stra1) {
                b1=t1.b;
                c1=t1.a;
            } else {
                b1=t1.a;
                c1=t1.b;
            }
        }
        //2
        if(stra2<strb2 && stra2<strc2) {
            a2=t2.a;
            if(strb2<strc2) {
                b2=t2.b;
                c2=t2.c;
            } else {
                b2=t2.c;
                c2=t2.b;
            }
        } else if(strb2<stra2 && strb2<strc2) {
            a2=t2.b;
            if(stra2<strc2) {
                b2=t2.a;
                c2=t2.c;
            } else {
                b2=t2.c;
                c2=t2.a;
            }
        } else {
            a2=t2.c;
            if(strb2<stra2) {
                b2=t2.b;
                c2=t2.a;
            } else {
                b2=t2.a;
                c2=t2.b;
            }
        }

        bool ugloviIsti=false;
        Trougao s1(a1,b1,c1),s2(a2,b2,c2);
        if(JesuLiJednaki(s1.DajUgao(1),s2.DajUgao(1)) && JesuLiJednaki(s1.DajUgao(2),s2.DajUgao(2)) && JesuLiJednaki(s1.DajUgao(3),s2.DajUgao(3)))
            ugloviIsti=true;

        if(ugloviIsti && (JesuLiJednaki(s1.DajUgao(1),s1.DajUgao(2)) || JesuLiJednaki(s1.DajUgao(1),s1.DajUgao(3)) || JesuLiJednaki(s1.DajUgao(3),s1.DajUgao(2)))) return true;

                return ugloviIsti && Orijentacija(a1,b1,c1) == Orijentacija(a2,b2,c2);
    }
};


int main ()
{
    try {
        int n;
        double ugao, faktor,deltax,deltay;
        std::cout<<"Koliko zelite kreirati trouglova: ";
        std::cin>>n;
  
        std::vector<std::shared_ptr<Trougao>> trouglovi(n,nullptr);
        
        for(int i=0; i<n; i++) {
            Tacka x,y,z;
            std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            //std::cout<<"Unesite prvo tjeme za "<<i+1<<". trougao: ";
            std::cin>>x.first>>x.second;
           // std::cout<<"Unesite drugo tjeme za "<<i+1<<". trougao: ";
            std::cin>>y.first>>y.second;
           // std::cout<<"Unesite trece tjeme za "<<i+1<<". trougao: ";
            std::cin>>z.first>>z.second;
            try{
            trouglovi[i]=std::make_shared<Trougao>(x,y,z);
            }
            catch(std::domain_error e){
                std::cout<<e.what()<<std::endl;
                i--;
            }

        }
        
        
        std::cout<<"Unesite vektor translacije (dx dy): ";
        std::cin>>deltax>>deltay;
        std::cout<<"Unesite ugao rotacije: ";
        std::cin>>ugao;
        std::cout<<"Unesite faktor skaliranja: ";std::cout<<"Trouglovi nakon obavljenih transformacija:"<<std::endl;
        std::cin>>faktor;
        transform(trouglovi.begin(),trouglovi.end(),trouglovi.begin(),[deltax,deltay,ugao,faktor](std::shared_ptr<Trougao> t){
            t->Transliraj(deltax,deltay);
            t->Rotiraj(ugao);
            t->Skaliraj(t->DajTjeme(1),faktor);
            
            return t;
        });
        sort(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){
            return t1->DajPovrsinu()<t2->DajPovrsinu();
        });
        
        for_each(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao> t){
            std::cout<<"(("<<t->DajTjeme(1).first<<","<<t->DajTjeme(1).second<<"),("<<
            t->DajTjeme(2).first<<","<<t->DajTjeme(2).second<<"),("<<t->DajTjeme(3).first<<","<<t->DajTjeme(3).second<<"))"<<std::endl;
        });
        auto pok=*min_element(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2){
        return t1->DajObim()<t2->DajObim();
        });
        std::cout<<"Trougao sa najmanjim obimom: "<<"(("<<pok->DajTjeme(1).first<<","<<pok->DajTjeme(1).second<<"),("<<
            pok->DajTjeme(2).first<<","<<pok->DajTjeme(2).second<<"),("<<pok->DajTjeme(3).first<<","<<pok->DajTjeme(3).second<<"))"<<std::endl;
     
        std::vector<std::pair<Trougao,Trougao>> identicni;
        std::vector<std::pair<Trougao,Trougao>> podudarni;
        std::vector<std::pair<Trougao,Trougao>> slicni;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(DaLiSuIdenticni(*trouglovi[i], *trouglovi[j])) identicni.push_back(std::make_pair(*trouglovi[i], *trouglovi[j]));
            }
        }
         for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(DaLiSuPodudarni(*trouglovi[i], *trouglovi[j])) podudarni.push_back(std::make_pair(*trouglovi[i], *trouglovi[j]));
            }
        }
         for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(DaLiSuSlicni(*trouglovi[i], *trouglovi[j])) slicni.push_back(std::make_pair(*trouglovi[i], *trouglovi[j]));
            }
        }
        
        if(identicni.size()==0) std::cout<<"Nema identicnih trouglova!\n";
    else{   
        std::cout<<"Parovi identicnih trouglova:\n";
        for(int i=0; i<identicni.size(); i++){
             std::cout<<"(("<<identicni[i].first.DajTjeme(1).first<<","<<identicni[i].first.DajTjeme(1).second<<"),("<<
            identicni[i].first.DajTjeme(2).first<<","<<identicni[i].first.DajTjeme(2).second<<"),("<<identicni[i].first.DajTjeme(3).first<<","<<identicni[i].first.DajTjeme(3).second<<"))"
            <<" i "<<"(("<<identicni[i].second.DajTjeme(1).first<<","<<identicni[i].second.DajTjeme(1).second<<"),("<<
            identicni[i].second.DajTjeme(2).first<<","<<identicni[i].second.DajTjeme(2).second<<"),("<<identicni[i].second.DajTjeme(3).first<<","<<identicni[i].second.DajTjeme(3).second<<"))"<<std::endl;
        }}
        
         if(podudarni.size()==0) std::cout<<"Nema podudarnih trouglova!\n";
         else {
              std::cout<<"Parovi podudarnih trouglova:\n";
             for(int i=0; i<podudarni.size(); i++){
             std::cout<<"(("<<podudarni[i].first.DajTjeme(1).first<<","<<podudarni[i].first.DajTjeme(1).second<<"),("<<
            podudarni[i].first.DajTjeme(2).first<<","<<podudarni[i].first.DajTjeme(2).second<<"),("<<podudarni[i].first.DajTjeme(3).first<<","<<podudarni[i].first.DajTjeme(3).second<<"))"
            <<" i "<<"(("<<podudarni[i].second.DajTjeme(1).first<<","<<podudarni[i].second.DajTjeme(1).second<<"),("<<
            podudarni[i].second.DajTjeme(2).first<<","<<podudarni[i].second.DajTjeme(2).second<<"),("<<podudarni[i].second.DajTjeme(3).first<<","<<podudarni[i].second.DajTjeme(3).second<<"))"<<std::endl;
        }}
         
         if(slicni.size()==0) std::cout<<"Nema slicnih trouglova!\n";
       else{ 
           std::cout<<"Parovi slicnih trouglova:\n";
           for(int i=0; i<slicni.size(); i++){
            std::cout<<"(("<<slicni[i].first.DajTjeme(1).first<<","<<slicni[i].first.DajTjeme(1).second<<"),("<<
            slicni[i].first.DajTjeme(2).first<<","<<slicni[i].first.DajTjeme(2).second<<"),("<<slicni[i].first.DajTjeme(3).first<<","<<slicni[i].first.DajTjeme(3).second<<"))"
            <<" i "<<"(("<<slicni[i].second.DajTjeme(1).first<<","<<slicni[i].second.DajTjeme(1).second<<"),("<<
            slicni[i].second.DajTjeme(2).first<<","<<slicni[i].second.DajTjeme(2).second<<"),("<<slicni[i].second.DajTjeme(3).first<<","<<slicni[i].second.DajTjeme(3).second<<"))"<<std::endl;
        }}
    }
    catch(std::range_error e){
        std::cout<<e.what()<<std::endl;
    }
    catch(std::domain_error e){
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}