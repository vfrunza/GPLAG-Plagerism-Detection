#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>
#include <utility>
#include <algorithm>
#include <memory>
#include <functional>
typedef std::pair<double,double> Tacka;
class Trougao{
    std::vector<Tacka> v= std::vector<Tacka>(3);
    public: 
        Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
            Postavi(t1,t2,t3);
        }
        void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
            if(!Orijentacija(t1,t2,t3)) throw std::domain_error("Nekorektne pozicije tjemena");
            v[0] = t1; v[1] = t2; v[2] = t3;
        }
        void Postavi(int indeks, const Tacka &t){
            if(indeks < 1 || indeks > 3) throw std::range_error("Nekorektan indeks");
            std::vector<Tacka> w(v); w[indeks-1] = t; if(!Orijentacija(w[0],w[1],w[2])) throw std::domain_error("Nekorektne pozicije tjemena");
            v[indeks-1] = t;
            }
        static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
            double x(ubiloSe(t1,t2,t3));
            if(e(x,0)) return 0; if(x<0) return -1; return 1;
        }
        Tacka DajTjeme(int indeks) const{ return v[indeks-1]; }
        double DajStranicu(int indeks) const{
        if(indeks == 1) return dist(v[1],v[2]); if(indeks == 2) return dist(v[0],v[2]);
        return dist(v[0],v[1]);
        }
        double DajUgao(int indeks) const{
            double a(dist(v[1],v[2])),b(dist(v[0],v[2])),c(dist(v[0],v[1]));
            if(indeks == 1) return calcAng(c,b,a);
            if(indeks == 2) return calcAng(c,a,b); return calcAng(a,b,c);
        }
        Tacka DajCentar()const{ 
            return std::make_pair((v[0].first+v[1].first+v[2].first)/3,(v[0].second+v[1].second+v[2].second)/3);
        }
        double DajObim() const{ return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);}
        double DajPovrsinu()const{ return std::abs(ubiloSe(v[0],v[1],v[2])/2);}
        bool DaLiJePozitivnoOrijentiran()const{return Orijentacija(v[0],v[1],v[2])==1;}
        bool DaLiJeUnutra(Tacka t){
            int x(Orijentacija(v[0],v[1],v[2])), y(Orijentacija(v[0],v[1],t)),z(Orijentacija(v[1],v[2],t)),w(Orijentacija(v[2],v[0],t));
            return x == y && y == z && z== w;
        }
        void Ispisi()const{
            std::cout<<"("; char c = ',';
            for(int i = 0; i < 3; i++){
                if(i == 2) c=')';
                std::cout<<"("<<v[i].first<<","<<v[i].second<<")"<<c;
            }
        }
        void Transliraj(double delta_x,double delta_y){
            for(auto &t:v) {t.first+=delta_x; t.second+=delta_y;}
        }
        void Centriraj(const Tacka &t){
            auto c(DajCentar()); Transliraj(c.first-t.first,c.second-t.second);
        }
        void Rotiraj(const Tacka &t,double ugao){
            for(auto &r:v){
                auto tmp(r.first);
                r.first = t.first+(r.first-t.first)*std::cos(ugao)-(r.second-t.second)*std::sin(ugao);
                r.second = t.second + (tmp- t.first)*std::sin(ugao) + (r.second-t.second)*std::cos(ugao);
            }
        }
        void Skaliraj(const Tacka &t, double faktor){
            if(e(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja");
            bool rot(false); if(faktor < 0) rot = true;
            for(auto &r:v){
                r.first = t.first + faktor*(r.first - t.first);
                r.second = t.second + faktor*(r.second -t.second);
            }
            if(rot) Rotiraj(t,2*std::atan(1));
        }
        void Rotiraj(double ugao){ Rotiraj(DajCentar(),ugao); }
        void Skaliraj(double ugao){ Skaliraj(DajCentar(),ugao); }
        friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
        friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
        friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
    private: 
        static double ubiloSe(Tacka t1,Tacka t2,Tacka t3){return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);}
        static bool e(double a, double b){ return std::abs(a-b) < 0.0000000001; }
        static double dist(Tacka t1, Tacka t2){ 
            return std::sqrt((t1.first-t2.first)*(t1.first-t2.first) + (t1.second-t2.second)*(t1.second-t2.second));
        }
        static double calcAng(double a, double b, double c){
            return std::acos((-c*c + a*a + b*b)/(2*a*b));
        }
        static bool vecIma(std::vector<Tacka> &v, Tacka x){ for(auto t: v) if(e(t.first,x.first) && e(t.second,x.second)) return true; return false; }
        static void dajTacke(std::vector<Tacka> &v,std::vector<double> &d, const Trougao &t){
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    if(e(t.DajStranicu(j+1), d[i]) && !vecIma(v,t.v[j]))
                        v.push_back(t.v[j]);
        }
        static bool DaLiSuPodudarnii(const Trougao &t1, const Trougao &t2,bool test);
};
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    for(auto a:t1.v){
        bool ima(false);
        for(auto b:t2.v)
            if(a == b) ima = true;
        if(!ima) return false;
    }
    return true;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    return Trougao::DaLiSuPodudarnii(t1,t2,true);
}
bool Trougao::DaLiSuPodudarnii(const Trougao &t1, const Trougao &t2, bool test){
    std::vector<double> v1,v2;
    for(int i = 0; i < 3; i++) {
        v1.push_back(t1.DajStranicu(i+1));
        v2.push_back(t2.DajStranicu(i+1));
    }
    std::sort(v1.begin(),v1.end()); std::sort(v2.begin(), v2.end());
    if(test) for(int i = 0; i < 3; i++) if(!Trougao::e(v1[i],v2[i])) return false; 
    std::vector<Tacka> p1,p2;
    Trougao::dajTacke(p1,v1,t1); Trougao::dajTacke(p2,v2,t2);
    if(!test){
        Trougao tro1(p1[0],p1[1],p1[2]), tro2(p2[0],p2[1],p2[2]);
        for(int i = 0; i < 3; i++) if(!Trougao::e(tro1.DajUgao(i+1),tro2.DajUgao(i+1))) return false;
    }
    return (Trougao::Orijentacija(p1[0],p1[1],p1[2]) == Trougao::Orijentacija(p2[0],p2[1],p2[2]));
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    return Trougao::DaLiSuPodudarnii(t1,t2,false);
}
bool ispisiParove(std::vector<std::shared_ptr<Trougao>> &v, std::function<bool(Trougao,Trougao)> f, int n, bool test = false){
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(f(*v[i],*v[j])){
                if(test) return true; v[i]->Ispisi(); std::cout << " i "; v[j]->Ispisi(); std::cout << std::endl;
            }
    //if(!test)std::cout << std::endl;
    return false;
}
int main(){
    std::cout << "Koliko zelite kreirati trouglova: ";
    int n; std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    for(int i = 0; i < n; i++){
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        std::vector<Tacka> t(3); 
        for(int j = 0; j < 3; j++) std::cin >> t[j].first >> t[j].second;
        try{
            v[i] = std::make_shared<Trougao>(t[0],t[1],t[2]);
        }catch(std::domain_error err){
            std::cout << err.what() << ", ponovite unos!\n";
            i--;
        }
    }
    std::cout << "Unesite vektor translacije (dx dy): "; 
    double dx,dy; std::cin >> dx >> dy;
    std::cout << "Unesite ugao rotacije: "; 
    double rot; std::cin >> rot;
    std::cout << "Unesite faktor skaliranja: ";
    double k; std::cin>>k;
    std::cout << "Trouglovi nakon obavljenih transformacija: \n";
    std::transform(v.begin(),v.end(),v.begin(),[dx,dy,k,rot](std::shared_ptr<Trougao> p){
        p->Transliraj(dx,dy);p->Rotiraj(rot);
        p->Skaliraj(p->DajTjeme(1),k); return p;
    });
    std::sort(v.begin(),v.end(),[](std::shared_ptr<Trougao> p,std::shared_ptr<Trougao> q){
    return p->DajPovrsinu() < q->DajPovrsinu();    
    });
    std::for_each(v.begin(),v.end(), [](std::shared_ptr<Trougao> p){
       p->Ispisi(); std::cout << std::endl;
    });
    std::cout << "Trougao sa najmanjim obimom: ";
    (*std::min_element(v.begin(), v.end(), [](std::shared_ptr<Trougao> p, std::shared_ptr<Trougao> q){
        return p->DajObim() < q->DajObim();
    })) ->Ispisi(); std::cout << std::endl;
    if(ispisiParove(v,DaLiSuIdenticni,n,true)){
        std::cout << "Parovi identicnih trouglova: \n";
        ispisiParove(v,DaLiSuIdenticni,n);
    }else std::cout << "Nema identicnih trouglova!\n";
    if(ispisiParove(v,DaLiSuPodudarni,n,true)){
        std::cout << "Parovi podudarnih trouglova: \n";
        ispisiParove(v,DaLiSuPodudarni,n);
    }else std::cout << "Nema podudarnih trouglova!\n";
    if(ispisiParove(v,DaLiSuSlicni,n,true)){
        std::cout << "Parovi slicnih trouglova: \n";
        ispisiParove(v,DaLiSuSlicni,n);
    }else std::cout << "Nema slicnih trouglova!\n";
    return 0;
}