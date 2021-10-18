#include <iostream>
#include <stdexcept>
#include <utility>
#include <cmath>
#include <algorithm>
#include <map>
#include <memory>
#include <vector>
typedef std::pair<double,double> Tacka;
const double eps(1E-10);
class Trougao{
    Tacka t1,t2,t3;
    static double DajOrijentaciju(Tacka t1,Tacka t2,Tacka t3){
        return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    }
    static double Duzina(Tacka t1,Tacka t2){
        return sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));
    }
    static bool IsteTacke(const Tacka &t1,const Tacka &t2){
        return (std::fabs(t1.first-t2.first) < eps) && (std::fabs(t1.second-t2.second) < eps);
    }
    public:
    Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        Postavi(t1,t2,t3);
    }
    void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        if(std::fabs(DajOrijentaciju(t1,t2,t3)) < eps)throw std::domain_error("Nekorektne pozicije tjemena");
        Trougao::t1=t1;Trougao::t2=t2;Trougao::t3=t3;
    }
    
    void Postavi(int indeks,const Tacka &t){
        if(indeks == 1)*this=Trougao(t,t2,t3);
        else if(indeks == 2)*this=Trougao(t1,t,t3);
        else if(indeks == 3)*this=Trougao(t1,t2,t);
        else throw std::logic_error("Nekorektan indeks");
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double orjentacija(DajOrijentaciju(t1,t2,t3));
        if(std::fabs(orjentacija) < eps)return 0;
        else if(orjentacija > 0)return 1;
        else return -1;
    };
    Tacka DajTjeme(int indeks) const{
        if(indeks==1)return t1;
        else if(indeks == 2)return t2;
        else if(indeks == 3)return t3;
        else throw std::logic_error("Nekorektan indeks");
    };
    double DajStranicu(int indeks) const{
        if(indeks == 1)return Duzina(t2,t3);
        else if(indeks==2)return Duzina(t1,t3);
        else if(indeks==3)return Duzina(t1,t2);
        else throw std::logic_error("Nekorektan indeks");
    };
    double DajUgao(int indeks) const{
        double a,b,c;
        if(indeks==1){a=Duzina(t2,t3);b=Duzina(t1,t3);c=Duzina(t1,t2);}
        else if(indeks == 2){a=Duzina(t1,t3);b=Duzina(t2,t3);c=Duzina(t1,t2);}
        else if(indeks == 3){a=Duzina(t1,t2);b=Duzina(t1,t3);c=Duzina(t2,t3);}
        else throw std::logic_error("Nekorektan indeks");
        return acos((b*b+c*c-a*a)/(2*b*c));
    };
    Tacka DajCentar() const{
        return {(t1.first+t2.first+t3.first)/3,(t1.second+t2.second+t3.second)/3};
    };
    double DajObim() const{
        return Duzina(t1,t2)+Duzina(t1,t3)+Duzina(t2,t3);
    };
    double DajPovrsinu() const{
        return std::fabs(DajOrijentaciju(t1,t2,t3)/2);
    };
    bool DaLiJePozitivnoOrijentiran() const{
        return DajOrijentaciju(t1,t2,t3) > 0;
    };
    bool DaLiJeUnutra(const Tacka &t) const{
        return (Orijentacija(t1,t2,t3) == 1 && Orijentacija(t1,t2,t) == 1 && Orijentacija(t2,t3,t) == 1 && Orijentacija(t3,t1,t) == 1) ||(Orijentacija(t1,t2,t3) == -1 && Orijentacija(t1,t2,t) == -1 && Orijentacija(t2,t3,t) == -1 && Orijentacija(t3,t1,t) == -1);
    };
    void Ispisi() const{std::cout << "((" << t1.first << "," << t1.second << "),(" << t2.first << "," << t2.second << "),(" << t3.first << "," << t3.second << "))";}
    void Transliraj(double delta_x, double delta_y){
        t1.first+=delta_x;t2.first+=delta_x;t3.first+=delta_x;
        t1.second+=delta_y;t2.second+=delta_y;t3.second+=delta_y;
    };
    void Centriraj(const Tacka &t){
        auto centar(DajCentar());
        t1.first+=t.first-centar.first;t1.second+=t.second-centar.second;
        t2.first+=t.first-centar.first;t2.second+=t.second-centar.second;
        t3.first+=t.first-centar.first;t3.second+=t.second-centar.second;
    };
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao){
        Rotiraj(DajCentar(),ugao);
    };
    void Skaliraj(double faktor){Skaliraj(DajCentar(),faktor);};
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
        int brojac(0);
        if(IsteTacke(t1.t1,t2.t1) || IsteTacke(t1.t1,t2.t2) || IsteTacke(t1.t1,t2.t3))brojac++;
        if(IsteTacke(t1.t2,t2.t1) || IsteTacke(t1.t2,t2.t2) || IsteTacke(t1.t2,t2.t3))brojac++;
        if(IsteTacke(t1.t3,t2.t1) || IsteTacke(t1.t3,t2.t2) || IsteTacke(t1.t3,t2.t3))brojac++;
        return brojac==3;
    };
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
bool  DaLiSuPodudarni(const Trougao &t1,const Trougao &t2){
        double s[]{t1.DajStranicu(1),t1.DajStranicu(2),t1.DajStranicu(3)};
      double z[]{t2.DajStranicu(1),t2.DajStranicu(2),t2.DajStranicu(3)};
      int brojac(0);
      if(fabs(s[0]-z[0]) < eps || fabs(s[0]-z[1]) < eps || fabs(s[0]-z[2]) < eps)brojac++;
      if(fabs(s[1]-z[0]) < eps || fabs(s[1]-z[1]) < eps || fabs(s[1]-z[2]) < eps)brojac++; 
      if(fabs(s[2]-z[0]) < eps || fabs(s[2]-z[1]) < eps || fabs(s[2]-z[2]) < eps)brojac++;
     if(brojac != 3)return false;  
      if(brojac == 3 && (fabs(s[0]-s[1]) < eps || fabs(s[0]-s[2]) < eps || fabs(s[1]-s[2]) < eps))return true;
      int a[]{1,2,3},b[]{1,2,3};
      std::sort(a,a+3,[t1](int x,int y){return t1.DajStranicu(x) < t1.DajStranicu(y);});
      std::sort(b,b+3,[t2](int x,int y){return t2.DajStranicu(x) < t2.DajStranicu(y);});
      return Trougao::Orijentacija(t1.DajTjeme(a[0]),t1.DajTjeme(a[1]),t1.DajTjeme(a[2])) == Trougao::Orijentacija(t2.DajTjeme(b[0]),t2.DajTjeme(b[1]),t2.DajTjeme(b[2]));
} 
bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2){
     double s[]{t1.DajUgao(1),t1.DajUgao(2),t1.DajUgao(3)};
      double z[]{t2.DajUgao(1),t2.DajUgao(2),t2.DajUgao(3)};
      int brojac(0);
      if(fabs(s[0]-z[0]) < eps || fabs(s[0]-z[1]) < eps || fabs(s[0]-z[2]) < eps)brojac++;
      if(fabs(s[1]-z[0]) < eps || fabs(s[1]-z[1]) < eps || fabs(s[1]-z[2]) < eps)brojac++; 
      if(fabs(s[2]-z[0]) < eps || fabs(s[2]-z[1]) < eps || fabs(s[2]-z[2]) < eps)brojac++;
     if(brojac != 3)return false;  
      if(brojac == 3 && (fabs(s[0]-s[1]) < eps || fabs(s[0]-s[2]) < eps || fabs(s[1]-s[2]) < eps))return true;
      int a[]{1,2,3},b[]{1,2,3};
      std::sort(a,a+3,[t1](int x,int y){return t1.DajStranicu(x) < t1.DajStranicu(y);});
      std::sort(b,b+3,[t2](int x,int y){return t2.DajStranicu(x) < t2.DajStranicu(y);});
      return Trougao::Orijentacija(t1.DajTjeme(a[0]),t1.DajTjeme(a[1]),t1.DajTjeme(a[2])) == Trougao::Orijentacija(t2.DajTjeme(b[0]),t2.DajTjeme(b[1]),t2.DajTjeme(b[2]));
}
    void Trougao::Rotiraj(const Tacka &t,double ugao){
        Tacka a1(t1),a2(t2),a3(t3);
        t1.first=t.first+(a1.first-t.first)*cos(ugao)-(a1.second-t.second)*sin(ugao);t1.second=t.second+(a1.second-t.second)*cos(ugao)+(a1.first-t.first)*sin(ugao);
        t2.first=t.first+(a2.first-t.first)*cos(ugao)-(a2.second-t.second)*sin(ugao);t2.second=t.second+(a2.second-t.second)*cos(ugao)+(a2.first-t.first)*sin(ugao);
        t3.first=t.first+(a3.first-t.first)*cos(ugao)-(a3.second-t.second)*sin(ugao);t3.second=t.second+(a3.second-t.second)*cos(ugao)+(a3.first-t.first)*sin(ugao);
    }
    void Trougao::Skaliraj(const Tacka &t,double faktor){
        if(std::fabs(faktor) < eps)throw std::domain_error("Nekorektan faktor skaliranja");
        t1.first=t.first+faktor*(t1.first-t.first);t1.second=t.second+faktor*(t1.second-t.second);
        t2.first=t.first+faktor*(t2.first-t.first);t2.second=t.second+faktor*(t2.second-t.second);
        t3.first=t.first+faktor*(t3.first-t.first);t3.second=t.second+faktor*(t3.second-t.second);
    }

int main ()
{
    int n;
    double dx,dy,ugao,faktor;
    bool x(true);
    std::vector<std::shared_ptr<Trougao>> trouglovi;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    
        for(int i(0);i < n;i++){
            Tacka t1,t2,t3;
            std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
            std::cin >> t1.first >> t1.second;
            std::cin >> t2.first >> t2.second;
            std::cin >> t3.first >> t3.second;
            try{
                trouglovi.push_back(std::shared_ptr<Trougao>(new Trougao(t1,t2,t3)));
            }catch(std::domain_error izuzetak){
                std::cout << izuzetak.what() << ", ponovite unos!\n";
                i--;
            }
        }
        std::cout << "Unesite vektor translacije (dx dy): ";
        std::cin >> dx >> dy;
        std::cout << "Unesite ugao rotacije: ";
        std::cin >> ugao;
        std::cout << "Unesite faktor skaliranja: ";
        std::cin >> faktor;
        std::transform(trouglovi.begin(),trouglovi.end(),trouglovi.begin(),[dx,dy,ugao,faktor](std::shared_ptr<Trougao> x){
            x->Transliraj(dx,dy);
            x->Rotiraj(ugao);
            x->Skaliraj(x->DajTjeme(1),faktor);
           return x; 
        });
        std::cout << "Trouglovi nakon obavljenih transformacija: \n";
        std::sort(trouglovi.begin(),trouglovi.end(),[](std::shared_ptr<Trougao> x,std::shared_ptr<Trougao> y){
            return x->DajPovrsinu() < y->DajPovrsinu();
        });
        std::for_each(trouglovi.begin(),trouglovi.end(),[](std::shared_ptr<Trougao> x){
            x->Ispisi();
            std::cout << std::endl;
        });
        std::cout << "Trougao sa najmanjim obimom: ";
        (*std::min_element(trouglovi.begin(),trouglovi.end(),[](std::shared_ptr<Trougao> x,std::shared_ptr<Trougao> y){
            return x->DajObim() < y->DajObim();
        }))->Ispisi();
        std::cout << std::endl;

        std::vector<int> tmp;
        for(int i(0);i < n;i++){
            for(int j(0);j< n;j++){
                for(int k(0);k < tmp.size();k++)
                    if(tmp[k]==j){j++;break;}
                if(i==j)continue;
                if(DaLiSuIdenticni(*trouglovi[i],*trouglovi[j])){
                    if(x){
                        x=false;
                        std::cout << "Parovi identicnih trouglova:\n";
                    }
                    trouglovi[i]->Ispisi();
                    std::cout << " i ";
                    trouglovi[j]->Ispisi();
                    std::cout << std::endl;
                    tmp.push_back(i);
                }
            }
        }
        if(tmp.size()==0)std::cout << "Nema identicnih trouglova!\n";
        tmp.resize(0);
        x=true;
        for(int i(0);i < n;i++){
            for(int j(0);j< n;j++){
                for(int k(0);k < tmp.size();k++)
                    if(tmp[k]==j){j++;break;}
                if(i==j)continue;
                if(DaLiSuPodudarni(*trouglovi[i],*trouglovi[j])){
                    if(x){
                        std::cout << "Parovi podudarnih trouglova:\n";
                        x=false;
                    }
                    trouglovi[i]->Ispisi();
                    std::cout << " i ";
                    trouglovi[j]->Ispisi();
                    std::cout << std::endl;
                    tmp.push_back(i);
                }
            }
        }
        if(tmp.size()==0)std::cout << "Nema podudarnih trouglova!\n";
        x=true;
        tmp.resize(0);
        for(int i(0);i < n;i++){
            for(int j(0);j< n;j++){
                for(int k(0);k < tmp.size();k++)
                    if(tmp[k]==j){j++;break;}
                if(i==j)continue;
                if(DaLiSuSlicni(*trouglovi[i],*trouglovi[j])){
                    if(x){
                        std::cout << "Parovi slicnih trouglova:\n";
                        x=false;
                    }
                    trouglovi[i]->Ispisi();
                    std::cout << " i ";
                    trouglovi[j]->Ispisi();
                    std::cout << std::endl;
                    tmp.push_back(i);
                }
            }
        }
        if(tmp.size()==0)std::cout << "Nema slicnih trouglova!\n";
	return 0;
}