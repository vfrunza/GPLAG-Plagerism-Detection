/B 2016/2017, Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <vector>
#include <algorithm>



typedef std::pair<double, double> Tacka;

class Trougao {
    Tacka tacka1,tacka2,tacka3;
    int indeks;
    double faktor, ugao;
    public:
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if (Orijentacija(t1,t2,t3) == 0) throw std::domain_error ("Nekorektne pozicije tjemena");
        this->tacka1 = t1;
        this->tacka2 = t2;
        this->tacka3 = t3;
    }
        
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if (Orijentacija(t1,t2,t3) == 0) throw std::domain_error ("Nekorektne pozicije tjemena");
        this->tacka1 = t1; this->tacka2 = t2; this->tacka3 = t3;
    }
    void Postavi (int indeks, const Tacka &t) {
        if (indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error ("Nekorektan indeks");
        this->tacka1=t;
    }
    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if ((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second)) > 0) {
            return 1; }
            
            if ((t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second)) < 0) {
                return -1; }
            
            else return 0;
        }
    Tacka DajTjeme (int indeks) const {
        if (indeks == 1) { return tacka1; }
        if (indeks == 2) { return tacka2; }
        if (indeks == 3) { return tacka3; }
    }
    double DajStranicu (int indeks) const {
        double s;
        if (indeks == 1) 
            s = sqrt ((tacka3.first-tacka2.first)*(tacka3.first-tacka2.first)+(tacka3.second-tacka2.second)*(tacka3.second-tacka2.second));
        
        if (indeks == 2) 
            s = sqrt ((tacka3.first-tacka1.first)*(tacka3.first-tacka1.first)+(tacka3.second-tacka1.second)*(tacka3.second-tacka1.second));
            
        if (indeks == 3) 
            s = sqrt ((tacka2.first-tacka1.first)*(tacka2.first-tacka1.first)+(tacka2.second-tacka1.second)*(tacka2.second-tacka1.second));
        
        return s;
    }
 
    double DajUgao (int indeks) const {
        const double PI=4*atan(1);
        double ugao;
        double a=sqrt((tacka2.first-tacka1.first)*(tacka2.first-tacka1.first)+(tacka2.second-tacka1.second)*(tacka2.second-tacka1.second));
        double b=sqrt((tacka3.first-tacka2.first)*(tacka3.first-tacka1.first)+(tacka3.second-tacka2.second)*(tacka3.second-tacka2.second));
        double c=sqrt((tacka3.first-tacka1.first)*(tacka3.first-tacka1.first)+(tacka3.second-tacka1.second)*(tacka3.second-tacka1.second));
       if (indeks==1) { ugao=acos((b*b+c*c-a*a)/(2*b*c)); ugao*=180/PI; }
       if (indeks==2) { ugao=acos((a*a+c*c-b*b)/(2*a*c)); ugao*=180/PI; }
       if (indeks==3) { ugao=acos((a*a+b*b-c*c)/(2*a*b)); ugao*=180/PI; }
       return ugao;
       }
    Tacka DajCentar () const {
        Tacka T;
        T.first = (tacka1.first + tacka2.first + tacka3.first ) / 2;
        T.second = (tacka1.second + tacka2. second + tacka3.second) / 2;
        return T;
    }
     double DajObim () const {
        double stranica1 = sqrt ((tacka2.first-tacka1.first)*(tacka2.first-tacka1.first)+(tacka2.second-tacka1.second)*(tacka2.second-tacka1.second));
        double stranica2 = sqrt ((tacka3.first-tacka2.first)*(tacka3.first-tacka2.first)+(tacka3.second-tacka2.second)*(tacka3.second-tacka2.second));
        double stranica3 = sqrt ((tacka3.first-tacka1.first)*(tacka3.first-tacka1.first)+(tacka3.second-tacka1.second)*(tacka3.second-tacka1.second));
        return stranica1+stranica2+stranica3;
    }
    double DajPovrsinu () const {
        double povrsina = ( tacka1.first*(tacka2.second-tacka3.second)-tacka2.first*(tacka1.second-tacka3.second)+tacka3.first*(tacka1.second-tacka2.second) )/2;
        return povrsina;
    }
    bool DaLiJePozitivnoOrijentisan () const {
        bool logicka=false;
        if(Orijentacija(tacka1,tacka2,tacka3)==1) logicka=true;
        return logicka;
    }
    bool DaLiJeUnutra (const Tacka &t) const;
    void Ispisi () const {
        std::cout << "(" << tacka1.first << tacka1.second << "," << tacka2.first << tacka2.second << "," << tacka3.first << tacka3.second << ")";
    }
    void Transliraj (double delta_x, double delta_y) {
        tacka1.first = tacka1.first + delta_x;  tacka1.second = tacka1.second + delta_y;
        tacka2.first = tacka2.first + delta_x;  tacka2.second = tacka2.second + delta_y;
        tacka3.first = tacka3.first + delta_x;  tacka3.second = tacka3.second + delta_y;
    }
    void Centriraj (const Tacka &t) {
        Tacka nova;
        nova=DajCentar();
        nova.first=t.first;
        nova.second=t.second;
    }
    void Rotiraj (const Tacka &t, double ugao) {
        tacka1.first = t.first+(tacka1.first-t.first)*cos(ugao) - (tacka1.second-t.second)*sin(ugao);
        tacka2.first = t.first+(tacka2.first-t.first)*cos(ugao) - (tacka2.second-t.second)*sin(ugao);
        tacka3.first = t.first+(tacka3.first-t.first)*cos(ugao) - (tacka3.second-t.second)*sin(ugao);
        tacka1.second = t.second+(tacka1.first-t.first)*sin(ugao) + (tacka1.second-t.second)*cos(ugao);
        tacka2.second = t.second+(tacka2.first-t.first)*sin(ugao) + (tacka2.second-t.second)*cos(ugao);
        tacka3.second = t.second+(tacka3.first-t.first)*sin(ugao) + (tacka3.second-t.second)*cos(ugao);
    }
    void Skaliraj (const Tacka &t, double faktor) {
        if (faktor==0) throw std::domain_error ("Nekorektan faktor skaliranja");
        tacka1.first = (t.first + faktor*(tacka1.first-t.first));
        tacka1.second = (t.second + faktor*(tacka1.second-t.second));
        tacka2.first = (t.first + faktor*(tacka2.first-t.first));
        tacka2.second = (t.second + faktor*(tacka2.second-t.second));
        tacka3.first = (t.first + faktor*(tacka3.first-t.first));
        tacka3.second = (t.second + faktor*(tacka3.second-t.second));
    }
    
    void Rotiraj (double ugao) {
        Tacka tt;
        tt=DajCentar();
        tacka1.first = tt.first+(tacka1.first-tt.first)*cos(ugao) - (tacka1.second-tt.second)*sin(ugao);
        tacka2.first = tt.first+(tacka2.first-tt.first)*cos(ugao) - (tacka2.second-tt.second)*sin(ugao);
        tacka3.first = tt.first+(tacka3.first-tt.first)*cos(ugao) - (tacka3.second-tt.second)*sin(ugao);
        tacka1.second = tt.second+(tacka1.first-tt.first)*sin(ugao) + (tacka1.second-tt.second)*cos(ugao);
        tacka2.second = tt.second+(tacka2.first-tt.first)*sin(ugao) + (tacka2.second-tt.second)*cos(ugao);
        tacka3.second = tt.second+(tacka3.first-tt.first)*sin(ugao) + (tacka3.second-tt.second)*cos(ugao);
    }
    void Skaliraj (double faktor) {
        if (faktor==0) throw std::domain_error ("Nekorektan faktor skaliranja");
        Tacka teziste;
        teziste=DajCentar();
        tacka1.first = (teziste.first + faktor*(tacka1.first-teziste.first));
        tacka1.second = (teziste.second + faktor*(tacka1.second-teziste.second));
        tacka2.first = (teziste.first + faktor*(tacka2.first-teziste.first));
        tacka2.second = (teziste.second + faktor*(tacka2.second-teziste.second));
        tacka3.first = (teziste.first + faktor*(tacka3.first-teziste.first));
        tacka3.second = (teziste.second + faktor*(tacka3.second-teziste.second));
    }
    friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2);
};

int main ()
{
    Tacka t1,t2,t3;
    int vek1,vek2,ugao_rot,n;
   
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
   
    std::vector<std::shared_ptr<Trougao>> v(n);
    for (int i=0; i<n; i++) 
    {
        std::cout << "Unesite podatke za " << i+1 << "." << " trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin >> t1.first >> t1.second >> t2.first >> t2.second >> t3.first >> t3.second; 
        try {
        v[i] = std::make_shared<Trougao> (Trougao (t1,t2,t3));
        
        
        } catch (std::domain_error e) {
        std::cout << e.what() << ", ponovite unos!" << std::endl;
        i--;
      }
    }
     Trougao t4(t1,t2,t3);
     t4.Postavi(t1,t2,t3);
     t4.Transliraj(1,1);

    sort (v.begin(), v.end(), [] (std::shared_ptr<Trougao> m, std::shared_ptr<Trougao>n) {
        return m->DajPovrsinu() < n->DajPovrsinu(); });
        
        for_each(v.begin(), v.end(), [](std::shared_ptr<Trougao> &m) {
            m->Ispisi();
            std::cout << std::endl;
        });
    std::cout << "Trougao sa najmanjim obimom: ";
    
    auto it = min_element(v.begin(),v.end(), [] (std::shared_ptr<Trougao> &m, std::shared_ptr<Trougao> &n) {
        return m->DajObim() < n->DajObim();
    });
    (*it)->Ispisi(); std::cout << std::endl;
    
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> vek1 >> vek2;
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> ugao_rot;
 
	return 0;
}