/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <utility>
#include <cmath>
#include <vector>
#include <memory>
#include <algorithm>

typedef std::pair<double, double> Tacka;

double Pomocni(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        double pom;
        pom =  (t1.first * (t2.second-t3.second) - t2.first * (t1.second-t3.second) + t3.first * (t1.second-t2.second));
        return pom;
    
}
bool JesuLiJednaki(double x, double y, double Eps = 1e-10){
    return (std::fabs(x-y)) <= Eps * (std::fabs(x) + std::fabs(y));
}

class Trougao{
    Tacka k1,k2,k3;
    public:
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if (JesuLiJednaki(Pomocni(t1,t2,t3), 0.)) throw std::domain_error ("Nekorektne pozicije tjemena");
        Trougao::k1 = t1; Trougao::k2 = t2; Trougao::k3 = t3;
    }
    void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if (JesuLiJednaki(Pomocni(t1,t2,t3),0.)) throw std::domain_error ("Nekorektne pozicije tjemena");
        Trougao::k1 = t1; Trougao::k2 = t2; Trougao::k3 = t3;
    }
   /* double Pomocni(const Tacka &t1, const Tacka &t2, const Tacka &t3) const{
        double pom;
        pom =  (t1.first * (t2.second-t3.second) - t2.first * (t1.second-t3.second) + t3.first * (t1.second-t2.second));
        return pom;}*/
    void Postavi (int indeks, const Tacka &t){
        if (indeks<1 && indeks>3) throw std::range_error ("Nekorektan indeks");
        if (indeks==1) { Trougao::k1 = t; if (JesuLiJednaki(Pomocni(k1,k2,k3),0.)) throw std::domain_error ("Nekorektne pozicije tjemena"); };
        if (indeks==2) { Trougao::k2=t; if (JesuLiJednaki(Pomocni(k1,k2,k3),0.)) throw std::domain_error ("Nekorektne pozicije tjemena"); };
        if (indeks==3) { Trougao::k3=t; if (JesuLiJednaki(Pomocni(k1,k2,k3),0.)) throw std::domain_error ("Nekorektne pozicije tjemena"); };
    }
    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if (Pomocni(t1,t2,t3)>0) return 1;
        if (Pomocni(t1,t2,t3)<0) return -1;
        else return 0;
    }
    Tacka DajTjeme(int indeks) const{
        if (indeks<1 && indeks>3) throw std::range_error ("Nekorektan indeks");
        if (indeks==1) return k1;
        if (indeks==2) return k2;
        else return k3; //indeks=3
    }
    double DajStranicu (int indeks) const{
        if (indeks<1 && indeks>3) throw std::range_error ("Nekorektan indeks");
        if (indeks==1) return sqrt(((k3.first-k2.first)*(k3.first-k2.first))+((k3.second-k2.second)*(k3.second-k2.second)));
        if (indeks==2) return sqrt(((k3.first-k1.first)*(k3.first-k1.first))+((k3.second-k1.second)*(k3.second-k1.second)));
        else return sqrt(((k2.first-k1.first)*(k2.first-k1.first))+((k2.second-k1.second)*(k2.second-k1.second))); //indeks=3
    }
    double DajUgao(int indeks) const{
        if (indeks<1 && indeks>3) throw std::range_error ("Nekorektan indeks");
        if (indeks==1) return acos((DajStranicu(2)*DajStranicu(2)+DajStranicu(3)*DajStranicu(3)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(2)*DajStranicu(3)));
        if (indeks==2) return acos((DajStranicu(3)*DajStranicu(3)+DajStranicu(1)*DajStranicu(1)-DajStranicu(2)*DajStranicu(2))/(2*DajStranicu(3)*DajStranicu(1)));
        else return acos((DajStranicu(1)*DajStranicu(1)+DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(2))); //indeks=3
    };
    Tacka DajCentar() const{
        Tacka centar;
        centar.first = (k1.first+k2.first+k3.first)/3;
        centar.second = (k1.second+k2.second+k3.second)/3;
        return centar;
    };
    double DajObim() const{
        return (DajStranicu(1)+DajStranicu(2)+DajStranicu(3));
    };
    double DajPovrsinu() const{
        double pom = std::fabs(k1.first * (k2.second-k3.second) - k2.first * (k1.second-k3.second) + k3.first * (k1.second-k2.second));
        return pom/2.;
    };
    bool DaLiJePozitivnoOrijentiran () const{
        if (Orijentacija(k1,k2,k3)==1) return true;
        if (Orijentacija(k1,k2,k3)==-1) return false;
    };
    bool DaLiJeUnutra(const Tacka &t) const{
        if ((k1.first * (k2.second-k3.second) - k2.first * (k1.second-k3.second) + k3.first * (k1.second-k2.second))>0 && (k1.first * (k2.second-t.second) - k2.first * (k1.second-t.second) + t.first * (k1.second-k2.second))>0 && (k2.first * (k3.second-t.second) - k3.first * (k2.second-t.second) + t.first * (k2.second-k3.second))>0 && (k3.first * (k1.second-t.second) - k1.first * (k3.second-t.second) + t.first * (k3.second-k1.second))>0) return true;
        if ((k1.first * (k2.second-k3.second) - k2.first * (k1.second-k3.second) + k3.first * (k1.second-k2.second))<0 && (k1.first * (k2.second-t.second) - k2.first * (k1.second-t.second) + t.first * (k1.second-k2.second))<0 && (k2.first * (k3.second-t.second) - k3.first * (k2.second-t.second) + t.first * (k2.second-k3.second))<0 && (k3.first * (k1.second-t.second) - k1.first * (k3.second-t.second) + t.first * (k3.second-k1.second))<0) return true;
      //  if (Pomocni(k1,k2,k3)<0 && Pomocni(k1,k2,t)<0 && Pomocni(k2,k3,t)<0 && Pomocni(k3,k1,t)<0) return true;
        else return false;
    }
    void Ispisi() const{
        std::cout << "((" << k1.first << "," << k1.second << "),(" << k2.first << "," << k2.second << "),(" << k3.first << "," << k3.second << "))";
    }
    void Transliraj (double delta_x, double delta_y){
       k1.first = k1.first+delta_x; k1.second = k1.second+delta_y;
        k2.first = k2.first+delta_x; k2.second = k2.second+delta_y;
        k3.first = k3.first+delta_x; k3.second = k3.second+delta_y;
        Postavi(k1,k2,k3);
    }
    void Centriraj (const Tacka &t){
        Tacka c = DajCentar();
        double delta_x, delta_y;
        delta_x = t.first - c.first ; delta_y = t.second - c.second;
        Transliraj(delta_x,delta_y);
    }
    void Rotiraj (const Tacka &t, double ugao){
        Tacka tt1,tt2,tt3;
        tt1.first = t.first+(k1.first-t.first)*cos(ugao)-(k1.second-t.second)*sin(ugao);
        tt1.second = t.second+(k1.first-t.first)*sin(ugao)+(k1.second-t.second)*cos(ugao);
        tt2.first = t.first+(k2.first-t.first)*cos(ugao)-(k2.second-t.second)*sin(ugao);
        tt2.second = t.second+(k2.first-t.first)*sin(ugao)+(k2.second-t.second)*cos(ugao);
        tt3.first = t.first+(k3.first-t.first)*cos(ugao)-(k3.second-t.second)*sin(ugao);
        tt3.second = t.second+(k3.first-t.first)*sin(ugao)+(k3.second-t.second)*cos(ugao);
        Postavi(tt1,tt2,tt3);
    }
    void Skaliraj (const Tacka &t, double faktor){
        if (JesuLiJednaki(faktor, 0.)) throw std::domain_error ("Nekorektan faktor skaliranja");
        k1.first = t.first + faktor*(k1.first - t.first); k1.second = t.second + faktor*(k1.second - t.second);
        k2.first = t.first + faktor*(k2.first - t.first); k2.second = t.second + faktor*(k2.second - t.second);
        k3.first = t.first + faktor*(k3.first - t.first); k3.second = t.second + faktor*(k3.second - t.second);
    }
    void Rotiraj (double ugao){
        Tacka t = DajCentar();
        Rotiraj(t,ugao);
    };
    void Skaliraj (double faktor){
        Tacka t = DajCentar();
        Skaliraj(t,faktor);
    };
    friend bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni (const Trougao &t1, const Trougao &t2){
    //Dodati provjeru trouglova
    if ((t1.DajTjeme(1)==t2.DajTjeme(1) || t1.DajTjeme(1)==t2.DajTjeme(2) || t1.DajTjeme(1)==t2.DajTjeme(3))
    && (t1.DajTjeme(2)==t2.DajTjeme(1) || t1.DajTjeme(2)==t2.DajTjeme(2) || t1.DajTjeme(2)==t2.DajTjeme(3))
    && (t1.DajTjeme(3)==t2.DajTjeme(1) || t1.DajTjeme(3)==t2.DajTjeme(2) || t1.DajTjeme(3)==t2.DajTjeme(3)))      
        return true;
    else return false;
}

bool DaLiSuPodudarni (const Trougao &t1, const Trougao &t2){
    if (t1.DajStranicu(1)==t2.DajStranicu(2) && t1.Orijentacija(t1.k1,t1.k2,t1.k3)==t2.Orijentacija(t2.k1,t2.k2,t2.k3) && t1.DajStranicu(2)==t2.DajStranicu(3) && t1.DajStranicu(3)==t2.DajStranicu(1) ||
        (t1.DajStranicu(1)==t2.DajStranicu(2) && t1.Orijentacija(t1.k1,t1.k2,t1.k3)!=t2.Orijentacija(t2.k1,t2.k2,t2.k3) && t1.DajStranicu(2)==t2.DajStranicu(1) && t1.DajStranicu(3)==t2.DajStranicu(3) ))
        return true;
    if (t1.DajStranicu(1)==t2.DajStranicu(3) && t1.Orijentacija(t1.k1,t1.k2,t1.k3)!=t2.Orijentacija(t2.k1,t2.k2,t2.k3) && t1.DajStranicu(2)==t2.DajStranicu(2) && t1.DajStranicu(3)==t2.DajStranicu(1) ||
        (t1.DajStranicu(1)==t2.DajStranicu(3) && t1.Orijentacija(t1.k1,t1.k2,t1.k3)==t2.Orijentacija(t2.k1,t2.k2,t2.k3) && t1.DajStranicu(2)==t2.DajStranicu(1) && t1.DajStranicu(3)==t2.DajStranicu(2) ))
        return true;
    if (t1.DajStranicu(1)==t2.DajStranicu(1) && t1.Orijentacija(t1.k1,t1.k2,t1.k3)==t2.Orijentacija(t2.k1,t2.k2,t2.k3) && t1.DajStranicu(2)==t2.DajStranicu(2) && t1.DajStranicu(3)==t2.DajStranicu(3) ||
        (t1.DajStranicu(1)==t2.DajStranicu(1) && t1.Orijentacija(t1.k1,t1.k2,t1.k3)!=t2.Orijentacija(t2.k1,t2.k2,t2.k3) && t1.DajStranicu(2)==t2.DajStranicu(3) && t1.DajStranicu(3)==t2.DajStranicu(2) ))
        return true;
    if (DaLiSuIdenticni(t1,t2))
        return true;
    return false;
};

bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2){
   if (JesuLiJednaki(t1.DajUgao(1)-t2.DajUgao(2),0.) && t1.Orijentacija(t1.k1,t1.k2,t1.k3)==t2.Orijentacija(t2.k1,t2.k2,t2.k3) && JesuLiJednaki(t1.DajUgao(2)-t2.DajUgao(3),0.) && JesuLiJednaki(t1.DajUgao(3)-t2.DajUgao(1),0.) 
   || (JesuLiJednaki(t1.DajUgao(1)-t2.DajUgao(2),0.) && t1.Orijentacija(t1.k1,t1.k2,t1.k3)!=t2.Orijentacija(t2.k1,t2.k2,t2.k3) && JesuLiJednaki(t1.DajUgao(2)-t2.DajUgao(1),0.) && JesuLiJednaki(t1.DajUgao(3)-t2.DajUgao(3),0.) ))
        return true;
    if (JesuLiJednaki(t1.DajUgao(1)-t2.DajUgao(3),0.) && t1.Orijentacija(t1.k1,t1.k2,t1.k3)==t2.Orijentacija(t2.k1,t2.k2,t2.k3) && JesuLiJednaki(t1.DajUgao(3)-t2.DajUgao(2),0.) && JesuLiJednaki(t1.DajUgao(2)-t2.DajUgao(1),0.) 
    || (t1.DajUgao(1)==t2.DajUgao(3) && t1.Orijentacija(t1.k1,t1.k2,t1.k3)!=t2.Orijentacija(t2.k1,t2.k2,t2.k3) && t1.DajUgao(3)==t2.DajUgao(1) && t1.DajUgao(2)==t2.DajUgao(1) ))
        return true;
    if (t1.DajUgao(1)==t2.DajUgao(1) && t1.Orijentacija(t1.k1,t1.k2,t1.k3)==t2.Orijentacija(t2.k1,t2.k2,t2.k3) && t1.DajUgao(2)==t2.DajUgao(2) && t1.DajUgao(3)==t2.DajUgao(3) ||
        (t1.DajUgao(1)==t2.DajUgao(1) && t1.Orijentacija(t1.k1,t1.k2,t1.k3)!=t2.Orijentacija(t2.k1,t2.k2,t2.k3) && t1.DajUgao(2)==t2.DajUgao(3) && t1.DajUgao(3)==t2.DajUgao(2) ))
        return true;
    if (DaLiSuIdenticni(t1,t2))
        return true;
    return false;
}


int main ()
{
    try{
        std::cout << "Koliko zelite kreirati trouglova: ";
        int n;
        std::cin >> n;
        std::vector<std::shared_ptr<Trougao> > vpok;
        double x,y;
        for (int j=0;j<n;j++){
            std::cout << "Unesite podatke za " << j+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            Tacka k1,k2,k3;
            for (int i=0;i<3;i++){
                std::cin >> x >> y;
                if (i==0) k1 = std::pair<double,double> (x,y);
                if (i==1) k2 = std::pair<double,double> (x,y);
                if (i==2) k3 = std::pair<double,double> (x,y);
            }
            while (JesuLiJednaki(Pomocni(k1,k2,k3),0.)){
                    std::cout << "Nekorektne pozicije tjemena, ponovite unos!" << std::endl ;
                    std::cout << "Unesite podatke za " << j+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
                    for (int i=0;i<3;i++){
                    //    std::cout << "Unesite koordinate " << i+1 << " tjemena: ";
                        std::cin >> x >> y;
                        if (i==0) k1 = std::pair<double,double> (x,y);
                        if (i==1) k2 = std::pair<double,double> (x,y);
                        if (i==2) k3 = std::pair<double,double> (x,y);
                    }
                } 
            vpok.push_back( std::shared_ptr<Trougao> ( new Trougao(k1,k2,k3) ));
        }
        //Transliranje
        double delta_x, delta_y,ugao_rot,fs;
        std::cout << "Unesite vektor translacije (dx dy): ";
        std::cin >> delta_x >> delta_y;
        std::cout << "Unesite ugao rotacije: "; std::cin >> ugao_rot;
        std::cout << "Unesite faktor skaliranja: "; std::cin >> fs;
            std::transform(vpok.begin(), vpok.end(), vpok.begin(), [delta_x,delta_y, ugao_rot, fs] (std::shared_ptr<Trougao> x){
                x->Transliraj(delta_x, delta_y); 
                x->Rotiraj(x->DajCentar(), ugao_rot); 
                x->Skaliraj(x->DajTjeme(1), fs);
                return x;
            } );
        
        std::sort (vpok.begin(), vpok.end(), 
            [] (std::shared_ptr<Trougao> x, std::shared_ptr<Trougao> y) {
                return ( x->DajPovrsinu() < y->DajPovrsinu() ); });
     std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
     std::for_each (vpok.begin(), vpok.end(), [] (std::shared_ptr<Trougao> x) {
             x->Ispisi();
             std::cout << std::endl;
     });
     auto tt = *std::min_element(vpok.begin(), vpok.end(), [] (std::shared_ptr<Trougao> x, std::shared_ptr<Trougao> y){
         return x->DajObim() < y->DajObim();
     });
     std::cout << "Trougao sa najmanjim obimom: "; tt->Ispisi();
     int br1(0);
     for (int i=0;i<n-1;i++){
         for (int j=i+1;j<n;j++){
             if (DaLiSuIdenticni(*vpok[i],*vpok[j])){
             br1++;
             }
         }
     }
     if (br1==0)
        std::cout << std::endl << "Nema identicnih trouglova!\n";
    else{
        std::cout << std::endl << "Parovi identicnih trouglova:\n";
        for (int i=0;i<n-1;i++){
         for (int j=i+1;j<n;j++){
             if (DaLiSuIdenticni(*vpok[i],*vpok[j])){
             vpok[i]->Ispisi();
             std::cout << " i "; 
             vpok[j]->Ispisi();
             br1++;
             }
         }
      }
    }
    int br2(0);
     for (int i=0;i<n-1;i++){
         for (int j=i+1;j<n;j++){
             if (DaLiSuPodudarni(*vpok[i], *vpok[j])){
                 br2++;
             }
         }
     }
     if (br2==0)
        std::cout << "Nema podudarnih trouglova!\n";
    else{
        std::cout << std::endl << "Parovi podudarnih trouglova:\n";
        for (int i=0;i<n-1;i++){
            for (int j=i+1;j<n;j++){
             if (DaLiSuPodudarni(*vpok[i], *vpok[j])){
                 vpok[i]->Ispisi();
                 std::cout << " i ";
                 vpok[j]->Ispisi();
                 std::cout << std::endl;
             }
         }
     }
    }
    int br3(0);
    for (int i=0;i<n-1;i++){
         for (int j=i+1;j<n;j++){
             if (DaLiSuSlicni(*vpok[i], *vpok[j])){
                 br3++;
             }
         }
     }
     if (br3==0)
        std::cout << "Nema slicnih trouglova!\n";
    else{
         std::cout << "Parovi slicnih trouglova:\n";
    for (int i=0;i<n-1;i++){
         for (int j=i+1;j<n;j++){
             if (DaLiSuSlicni(*vpok[i], *vpok[j])){
                 vpok[i]->Ispisi();
                 std::cout << " i ";
                 vpok[j]->Ispisi();
                 std::cout << std::endl;
             }
         }
     }
    }
    }
    catch(std::range_error e){
        std::cout << "Izuzetak: " << e.what() << std::endl;
    }
    catch(std::domain_error l){
        std::cout << "Izuzetak: " << l.what() << std::endl;
    }
	return 0;
}