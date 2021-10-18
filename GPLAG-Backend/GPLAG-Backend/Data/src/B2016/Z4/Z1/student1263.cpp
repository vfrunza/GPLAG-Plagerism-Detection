/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <memory>
#include <stdexcept>
#include <cmath>
#include <vector>
typedef std::pair<double, double> Tacka;

class Trougao{
    std::vector<Tacka> v(3){v.x,v.y,v.z };
    double Duzina(const Tacka &t1, const Tacka &t2) {
        return sqrt(pow((t1.first-t2.first),2)+pow((t1.second-t2.second),2));
    }
    double Izraz(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        return (t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
    }
    public:
        Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
            if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
            v[0]=t1; v[1]=t2; v[2]=t3;
        }
        void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
            if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
            v[0]=t1; v[1]=t2; v[2]=t3;
        }
        void Postavi(int indeks, const Tacka &t) {
            if(t!=1 && t!=2 && t!=3) throw std::range_error("Nekorektan indeks");
            v[indeks-1]=t;
        }
        static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
            double izraz(Izraz(t1,t2,t3));
            if(izraz>0) return 1;
            else if(izraz ==0) return izraz;
            else return -1;
        }
        Tacka DajTjeme(int indeks) const{ 
            if(indeks!=1 && indeks=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
            return v[indeks-1];
        }
        double Dajstranicu(int indeks) const {
            if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
            std::vector<Tacka> v2=v;
            for(int i=0; i<v2.size(); i++) if(i==indeks-1){
               v2[i].erase();
               break;
            } 
            return Duzina(v2[1],v2[0]);
        }
        double DajUgao(int indeks) const{
            if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error("Nekorektan indeks");
            Tacka t(v[indeks-1]);
            std::vector<Tacka> v2=v;
            for(int i=0; i<v2.size; i++) if(i==indeks-1) {
                v2[i].erase;
                break;
            }
            return acos((pow(Duzina(v2[0],v2[1]),2)-pow(Duzina(t,v2[0]),2)-pow(Duzina(t,v2[1]),2))/(2*Duzina(t,v2[0])*Duzina(t,v2[1])));
        }
        Tacka DajCentar() const{
            Tacka t;
            t.first=((v[0].first+v[1].first+v[2].first)/3);
            t.second=((v[0].second+v[1].second+v[2].second)/3);
            return t;
        }
        double DajObim() const{
            return (Duzina(v[0],v[1])+Duzina(v[1],v[2])+Duzina(v[0],v[2]));
        }
        double DajPovrsinu() const{return Izraz(v[0],v[1],v[2]); }
        bool DaLiJePozitivnoOrijentiran() const{
            if(Izraz(v[0],v[1],v[2])==1) return true;
            return false;
        }
        bool DaLiJeUnutra(const Tacka &t){
            if(Izraz(v[0],v[1],t)+Izraz(v[1],v[2],t)+Izraz(v[2],v[0],t)==Izraz(v[0],v[1],v[2]) && 
            Izraz(v[0],v[1],t)!=0 && Izraz(v[1],v[2],t)!=0 && Izraz(v[2],v[0],t)) return true;
            return false;
        };
        void Ispisi() const{std::cout<<"(("<<v[0].first<<","<<v[0].second<<"),("<<v[1].first<<","<<v[1].second<<"),("<<v[2].first<<","<<v[2].second<<"))"<<std::endl;}
        void Transliraj(double delta_x, double delta_y){
            for(auto x: v) {
                x.first+=delta_x;
                x.second+=delta_y;
            }
        }
        void Centriraj(const Tacka &t){
            Tacka p(DajCentar());
            double delta_x(t.first-p.first), delta_y(fabs(t.second-p.second));
            Transliraj(delta_x,delta_y);
        }
        void Rotiraj(const Tacka &t, double ugao){
            for(auto y:v) {
                y.first=t.first+(y.first-t.first)*cos(ugao)-(y.second-t.second)*sin(ugao);
                y.second=t.second+(y.first-t.first)*sin(ugao)+(y.second-t.second)*cos(ugao);
            }
        }
        void Skaliraj(const Tacka &t, double faktor){
            for(auto x:v) {
                x.first=t.first+faktor*(x.first-t.first);
                x.second=t.second+faktor*(x.second-t.second);
            }
        }
        void Rotiraj(double ugao){
            Tacka t(DajCentar());
            void Rotiraj(t,ugao);
        }
        void Skaliraj(double faktor){
            Tacka t(DajCentar());
            void Skaliraj(t,ugao);
        }
        friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
        friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
        friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    Trougao t3{t2[0],t2[2],t2[1]}, t4{t2[1],t2[0],t2[2]}, t5{t2[2],t2[1],t2[0]},
            t6{t2[2],t2[0],t2[1]}, t7{t2[1],t2[2],t2[0]};
    if(t1==t2 || t1==t3 || t1==t4 || t1==t5 || t1==t6 || t1==t7) return true;
    return false;
}
double Duzina(const Tacka &t1, const Tacka &t2) {
        return sqrt(pow((t1.first-t2.first),2)+pow((t1.second-t2.second),2));
    }
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2) {
        std::vector<double> d1{Duzina(t1[0],t1[1]), Duzina(t1[0],t1[2]), Duzina(t1[1],t1[2])},
                            d2{Duzina(t2[0],t2[1]), Duzina(t2[0],t2[2]), Duzina(t2[1],t2[2])};
        std::vector<double> d3{d2[0],d2[2],d2[1]}, d4{d2[1],d2[0],d2[2]}, d5{d2[2],d2[1],d2[0]},
                            d6{d2[2],d2[0],d2[1]}, d7{d2[1],d2[2],d2[0]};
        if((d1==d2 || d1==d3 || d1==d4 || d1==d5 || d1==d6 || d1==d7) && Orijentacija(t1[0],t1[1],t1[2])==Orijentacija(t2[0],t2[1],t2[2])) return true;
        return false;       
}
bool DaLiSuSlicni(const Trougao &t1m const Trougao &t2) {
        std::vector<double> d1{Duzina(t1[0],t1[1]), Duzina(t1[0],t1[2]), Duzina(t1[1],t1[2])},
                            d2{Duzina(t2[0],t2[1]), Duzina(t2[0],t2[1]), Duzina(t2[1],t2[2])};
        if(d1[0]/d2[0]==d1[1]/d2[1] && d1[0]/d2[0]==d1[2]/d2[2]) retur true;
        return false;
                                
}
int main ()
{
	return 0;
}