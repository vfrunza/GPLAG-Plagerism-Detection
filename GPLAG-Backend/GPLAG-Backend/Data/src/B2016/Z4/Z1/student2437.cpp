/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <utility>
#include <cmath>
#include <memory>
#include <vector>

    typedef std::pair<double, double> Tacka;
    double const PI(atan(1)*4);
    double const eps(0.00000000001);
    
    class Trougao{
        Tacka A,B,C;
    public: 
        Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
            Postavi(t1,t2,t3);
        }
        void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
        void Postavi(int indeks, const Tacka &t);
        static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3);
        static bool Poredi(double x, double y);
        Tacka DajTjeme(int indeks)const;
        double DajStranicu(int indeks)const;
        double DajUgao(int indeks)const;
        Tacka DajCentar()const;
        double DajObim() const;
        double DajPovrsinu() const;
        bool DaLiJePozitivnoOrijentiran() const;
        bool DaLiJeUnutra(const Tacka &t) const;
        void Ispisi() const{
            std::cout<<"(("<<A.first<< ","<<A.second<< "),("<<B.first<< ","<<B.second<< "),("<<C.first<< ","<<C.second<< "))"<<std::endl;
        }
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
    
    bool Trougao::Poredi(double x, double y){
            if(fabs(x - y) < eps) return true;
            return false;
    }
    
    int Znak(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        int znak = (t1.first*(t2.second-t3.second)-t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second));
        return znak;
    }
    
    double Povrsina(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double povrsina = (t1.first*(t2.second-t3.second)+t2.first*(t3.second-t1.second)+t3.first*(t1.second-t2.second));
        povrsina = fabs(povrsina);
        povrsina = povrsina * 1/2;
        return povrsina;
    }
    
    int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        int p =  Znak(t1,t2,t3);
        if(p == 0) return 0;
        else if(p > 0) return 1;
        return -1;
    }
    
    void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        int p = Orijentacija(t1,t2,t3);
        if(p == 0) throw std::domain_error("Nekorektne pozicije tjemena");
        A = t1; B = t2; C = t3;
        
    }
    
    void Trougao::Postavi(int indeks, const Tacka &t){
        if(indeks == 1 || indeks == 2 || indeks == 3){
            if(indeks == 1){
                A = t;
                if(Orijentacija(A,B,C) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
            }
            else if(indeks == 2){
                B = t;
                if(Orijentacija(A,B,C) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
            }
            else{
                C = t;
                if(Orijentacija(A,B,C) == 0) throw std::domain_error("Nekorektne pozicije tjemena");
            }
        }
        throw std::range_error("Nekorektan indeks");

    }
    
    double DuzinaStranice(Tacka x, Tacka y){
        double duzina = std::sqrt((y.first-x.first)*(y.first-x.first) + (y.second-x.second)*(y.second-x.second));
        return duzina;
    }
    
    double Trougao::DajStranicu(int indeks)const{
        if(indeks == 1 || indeks == 2 || indeks == 3){
            if(indeks == 1){
                double d = DuzinaStranice(B,C);
                return d;
            }
            else if(indeks == 2){
                double d = DuzinaStranice(A,C);
                return d;
            }
            else{
                double d = DuzinaStranice(A,B);
                return d;
            }
        }
        throw std::range_error("Nekorektan indeks");
    }
    
    double Trougao::DajUgao(int indeks)const{
        if(indeks == 1 || indeks == 2 || indeks == 3){
            double a = DuzinaStranice(B,C);
            double b = DuzinaStranice(A,C);
            double c = DuzinaStranice(A,B);
            if(indeks == 1){
                double alfa = acos((b*b+c*c-a*a)/(2*b*c));
                return alfa;
            }
            else if(indeks == 2){
                double beta = acos((a*a+c*c-b*b)/(2*a*c));
                return beta;
            }
            else{
                double gama = acos((a*a+b*b-c*c)/(2*a*b));
                return gama;
            }
        }
        throw std::range_error("Nekorektan indeks");
    }
    
    Tacka Trougao::DajTjeme(int indeks)const{
        if(indeks == 1 || indeks == 2 || indeks == 3){
            if(indeks == 1) return A;
            else if(indeks == 2) return B;
            else return C;
        }
        throw std::range_error("Nekorektan indeks");
    }
    
    Tacka Trougao::DajCentar()const{
        Tacka centar;
        centar.first = (A.first + B.first + C.first)/3.;
        centar.second = (A.second + B.second + C.second)/3.;
        return centar;
    }
    
    double Trougao::DajObim() const{
        double a = DajStranicu(1);
        double b = DajStranicu(2);
        double c = DajStranicu(3);
        return a+b+c;
    }
    
    double Trougao::DajPovrsinu() const{
        double povrsina = Povrsina(A,B,C);
        return povrsina;
    }
    
    bool Trougao::DaLiJePozitivnoOrijentiran() const{
        double p = Znak(A,B,C);
        if(p > 0) return true;
        if(p < 0) return false;

    }
    
    bool Trougao::DaLiJeUnutra(const Tacka &t) const{
        if(DaLiJePozitivnoOrijentiran()){
            if(Znak(A,B,t) > 0 && Znak(B,C,t) > 0 && Znak(C,A,t) > 0)
                return true;
            return false;
        }
        if(!DaLiJePozitivnoOrijentiran())
            if(Znak(A,B,t) < 0 && Znak(B,C,t) < 0 && Znak(C,A,t) < 0)
                return true;
            return false;
    }
    
    bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
         if ((fabs(t1.DajTjeme(1) - t2.DajTjeme(1)) < eps || fabs(t1.DajTjeme(1) - t2.DajTjeme(2))<eps || fabs(t1.DajTjeme(1) - t2.DajTjeme(3)) < eps) && (fabs(t1.DajTjeme(2) - t2.DajTjeme(1)) < eps || fabs(t1.DajTjeme(2) - t2.DajTjeme(2)) < eps || fabs(t1.DajTjeme(2) - t2.DajTjeme(3)) < eps) && (fabs(t1.DajTjeme(3) - t2.DajTjeme(1)) < eps || fabs(t1.DajTjeme(3) - t2.DajTjeme(2)) < eps || fabs(t1.DajTjeme(3) - t2.DajTjeme(3)) < eps))
            return true;
         return false;
    }
    
    void Trougao::Transliraj(double delta_x, double delta_y){
        A.first += delta_x; B.first += delta_x; C.first += delta_x;
        A.second += delta_y; B.second += delta_y; C.second += delta_y;
    }
    
    void Trougao::Centriraj(const Tacka &t){
        Tacka a = DajCentar();
        double x = t.first - a.first;
        double y = t.second - a.second;
        Transliraj(x,y);
    }
    
    void Trougao::Rotiraj(const Tacka &t, double ugao){
        //ugao = ugao*PI/180.;
        //ugao = ugao*180/PI;
        A.first = t.first + (A.first - t.first)*cos(ugao) - (A.second - t.second)*sin(ugao);
        A.second = t.second + (A.first - t.first)*sin(ugao) + (A.second - t.second)*cos(ugao);
        B.first = t.first + (B.first - t.first)*cos(ugao) - (B.second - t.second)*sin(ugao);
        B.second = t.second + (B.first - t.first)*sin(ugao) + (B.second - t.second)*cos(ugao);
        C.first = t.first + (C.first - t.first)*cos(ugao) - (C.second - t.second)*sin(ugao);
        C.second = t.second + (C.first - t.first)*sin(ugao) + (C.second - t.second)*cos(ugao);
        
    }
    
    void Trougao::Rotiraj(double ugao){
        Tacka t = DajCentar();
        A.first = t.first + (A.first - t.first)*cos(ugao) - (A.second - t.second)*sin(ugao);
        A.second = t.second + (A.first - t.first)*sin(ugao) + (A.second - t.second)*cos(ugao);
        B.first = t.first + (B.first - t.first)*cos(ugao) - (B.second - t.second)*sin(ugao);
        B.second = t.second + (B.first - t.first)*sin(ugao) + (B.second - t.second)*cos(ugao);
        C.first = t.first + (C.first - t.first)*cos(ugao) - (C.second - t.second)*sin(ugao);
        C.second = t.second + (C.first - t.first)*sin(ugao) + (C.second - t.second)*cos(ugao);
    }
    
    void Trougao::Skaliraj(const Tacka &t, double faktor){
        if(faktor - eps >= 0) throw std::domain_error("Nekorektan faktor skaliranja");
        A.first = t.first + faktor*(A.first - t.first);
        A.second = t.second + faktor*(A.second - t.second);
        B.first = t.first + faktor*(B.first - t.first);
        B.second = t.second + faktor*(B.second - t.second);
        C.first = t.first + faktor*(C.first - t.first);
        C.second = t.second + faktor*(C.second - t.second);
    }
    
    void Trougao::Skaliraj(double faktor){
        if(faktor - eps >= 0) throw std::domain_error("Nekorektan faktor skaliranja");
        Tacka t = DajCentar();
        A.first = t.first + faktor*(A.first - t.first);
        A.second = t.second + faktor*(A.second - t.first);
        B.first = t.first + faktor*(B.first - t.first);
        B.second = t.second + faktor*(B.second - t.first);
        C.first = t.first + faktor*(C.first - t.first);
        C.second = t.second + faktor*(C.second - t.first);
    }
    
    bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
        if ((fabs(t1.DajStranicu(1) - t2.DajStranicu(1)) < eps || fabs(t1.DajStranicu(1) - t2.DajStranicu(2))<eps || fabs(t1.DajStranicu(1) - t2.DajStranicu(3)) < eps) && (fabs(t1.DajStranicu(2) - t2.DajStranicu(1)) < eps || fabs(t1.DajStranicu(2) - t2.DajStranicu(2)) < eps || fabs(t1.DajStranicu(2) - t2.DajStranicu(3)) < eps) && (fabs(t1.DajStranicu(3) - t2.DajStranicu(1)) < eps || fabs(t1.DajStranicu(3) - t2.DajStranicu(2)) < eps || fabs(t1.DajStranicu(3) - t2.DajStranicu(3)) < eps))
            return true;
         return false;
    }
    
    bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
        if ((fabs(t1.DajTjeme(1) - t2.DajTjeme(1)) < eps || fabs(t1.DajTjeme(1) - t2.DajTjeme(2))<eps || fabs(t1.DajTjeme(1) - t2.DajTjeme(3)) < eps) && (fabs(t1.DajTjeme(2) - t2.DajTjeme(1)) < eps || fabs(t1.DajTjeme(2) - t2.DajTjeme(2)) < eps || fabs(t1.DajTjeme(2) - t2.DajTjeme(3)) < eps) && (fabs(t1.DajTjeme(3) - t2.DajTjeme(1)) < eps || fabs(t1.DajTjeme(3) - t2.DajTjeme(2)) < eps || fabs(t1.DajTjeme(3) - t2.DajTjeme(3)) < eps))
            return true;
         return false;
    }
    
int main ()
{
    /*std::cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>>trouglovi;
    int i(0);
    while(i<n){
        Tacka a,b,c;
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>a.first>>a.second>>b.first>>b.second>>c.first>>c.second;
        //try {
            std::shared_ptr<Trougao>pom(std::make_shared<Trougao>(Trougao(a,b,c)));
            trouglovi.push_back(pom);
        
       /* catch (domain_error e) {
            std::cout << e.what() << std::endl;
        }
        
        i++;
    }
    
        std::cout<<"Unesite vektor translacije (dx dy): ";
        double x,y;
        std::cin>>x>>y;
        std::cout<<"Unesite ugao rotacije: ";
        double ugao;
        std::cin>>ugao;
        std::cout<<"Unesite faktor skaliranja: ";
        double faktor;
        std::cin>>faktor;
        std::cout<<"Trouglovi nakon obavljenih transformacija: ";
        transform(trouglovi.begin(), trouglovi.end(),trouglovi.begin(),[x,y](){
            Trougao::Transliraj(x,y);
        });
        transform(trouglovi.begin(), trouglovi.end(),trouglovi.begin(), [](){
            Trougao::Rotiraj(DajCentar());
        }));
        transform(trouglovi.begin(), trouglovi.end(),trouglovi.begin(), [](){
            Trougao::Skaliraj(DajTjeme(1));
        }));
        std::sort(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao>prvi, std::shared_ptr<Trougao>drugi){
            return (prvi->DajPovrsinu() > drugi->DajPovrsinu());
        });
        std::for_each(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao>prvi){
            return prvi->Ispisi();
        });*/
        
	return 0;
}