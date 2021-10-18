/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory>

typedef std::pair<double,double> Tacka;

class Trougao {
        Tacka tac1,tac2,tac3;
        static double Pomocna(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
            return (t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
        }
    public:
        Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
            if(Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
            Postavi(t1,t2,t3);
        }
        void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
            if(Orijentacija(t1,t2,t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
            tac1.first=t1.first; tac1.second=t1.second;
            tac2.first=t2.first; tac2.second=t2.second;
            tac3.first=t3.first; tac3.second=t3.second;
        }
        void Postavi(int indeks, const Tacka &t) {
            if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error ("Nekorektan indeks");
            switch(indeks) {
                case 1:
                    tac1.first=t.first; tac1.second=t.second;
                    if(Orijentacija(tac1,tac2,tac3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
                    break;
                case 2:
                    tac2.first=t.first; tac2.second=t.second;
                    if(Orijentacija(tac1,tac2,tac3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
                    break;
                case 3:
                    tac3.first=t.first; tac3.second=t.second;
                    if(Orijentacija(tac1,tac2,tac3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
                    break;
            }
        }
        static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
            if(Pomocna(t1,t2,t3)>0) return 1;
            else if(Pomocna(t1,t2,t3)<0) return -1;
            return 0;
        }
        Tacka DajTjeme(int indeks) const {
            if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error ("Nekorektan indeks");
            switch(indeks) {
                case 1: return tac1;
                case 2: return tac2;
                case 3: return tac3;
            }
        }
        double DajStranicu(int indeks) const {
            if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error ("Nekorektan indeks");
            double stranica;
            switch(indeks) {
                case 1:
                    stranica=sqrt(pow((tac2.first-tac3.first),2)+pow((tac2.second-tac3.second),2));
                    break;
                case 2:
                    stranica=sqrt(pow((tac1.first-tac3.first),2)+pow((tac1.second-tac3.second),2));
                    break;
                case 3:
                    stranica=sqrt(pow((tac1.first-tac2.first),2)+pow((tac1.second-tac2.second),2));
                    break;
            }
            return stranica;
        }
        double DajUgao(int indeks) const {
            if(indeks!=1 && indeks!=2 && indeks!=3) throw std::range_error ("Nekorektan indeks");
            double ugao;
            switch(indeks) {
                case 1: 
                    ugao=acos((-pow(DajStranicu(1),2)+pow(DajStranicu(2),2)+pow(DajStranicu(3),2))/(2*DajStranicu(2)*DajStranicu(3)));
                    break;
                case 2:
                    ugao=acos((-pow(DajStranicu(2),2)+pow(DajStranicu(1),2)+pow(DajStranicu(3),2))/(2*DajStranicu(1)*DajStranicu(3)));
                    break;
                case 3:
                    ugao=acos((-pow(DajStranicu(3),2)+pow(DajStranicu(2),2)+pow(DajStranicu(1),2))/(2*DajStranicu(2)*DajStranicu(1)));
                    break;
            }
            return ugao;
        }
        Tacka DajCentar() const {
            Tacka centar;
            centar.first=((tac1.first+tac2.first+tac3.first)/3);
            centar.second=((tac1.second+tac2.second+tac3.second)/3);
            return centar;
        }
        double DajObim() const {
            double obim(0);
            for(int i(1);i<=3;i++) obim+=DajStranicu(i);
            return obim;
        }
        double DajPovrsinu() const {
            double povrsina;
            povrsina=abs(Pomocna(tac1,tac2,tac3)/2);
            return povrsina;
        }
        bool DaLiJePozitivnoOrijentiran() const {
            if(Orijentacija(tac1,tac2,tac3)==1) return true;
            return false;
        }
        bool DaLiJeUnutra(const Tacka &t) const {
            bool unutra=true;
            switch(Orijentacija(tac1,tac2,tac3)) {
                case -1: 
                    if(Orijentacija(tac1,tac2,t)!=-1 || Orijentacija(tac2,tac3,t)!=-1 || Orijentacija(tac3,tac1,t)!=-1) unutra=false;
                    break;
                case 1:
                    if(Orijentacija(tac1,tac2,t)!=1 || Orijentacija(tac2,tac3,t)!=1 || Orijentacija(tac3,tac1,t)!=1) unutra=false;
                    break;
            }
            return unutra;
        }
        void Ispisi() const {
            std::cout<<"(("<<tac1.first<<","<<tac1.second<<"),("<<tac2.first<<","<<tac2.second<<"),("<<tac3.first<<","<<tac3.second<<"))";
        }
        void Transliraj(double delta_x, double delta_y) {
            tac1.first+=delta_x; tac1.second+=delta_y;
            tac2.first+=delta_x; tac2.second+=delta_y;
            tac3.first+=delta_x; tac3.second+=delta_y;
        }
        void Centriraj(const Tacka &t) {
            Tacka centar=DajCentar();
            double x=centar.first+t.first,y=centar.second+t.second;
            Transliraj(x,y);
        }
        void Rotiraj(const Tacka &t, double ugao) {
            tac1.first=t.first+(tac1.first-t.first)*cos(ugao)-(tac1.second-t.second)*sin(ugao);             //PRVA TACKA
            tac1.second=t.first+(tac1.first-t.first)*sin(ugao)+(tac1.second-t.second)*cos(ugao);            //PRVA TACKA
            tac2.first=t.first+(tac2.first-t.first)*cos(ugao)-(tac2.second-t.second)*sin(ugao);             //DRUGA TACKA
            tac2.second=t.first+(tac2.first-t.first)*sin(ugao)+(tac2.second-t.second)*cos(ugao);            //DRUGA TACKA
            tac3.first=t.first+(tac3.first-t.first)*cos(ugao)-(tac3.second-t.second)*sin(ugao);             //TRECA TACKA
            tac3.second=t.first+(tac3.first-t.first)*sin(ugao)+(tac3.second-t.second)*cos(ugao);            //TRECA TACKA
        }
        
        void Skaliraj(const Tacka &t, double faktor) {
            if(faktor==0) throw std::domain_error ("Nekorektan faktor skaliranja");
            tac1.first=(t.first+faktor*(tac1.first-t.first));
            tac1.second=(t.second+faktor*(tac1.second-t.second));
            tac2.first=(t.first+faktor*(tac2.first-t.first));
            tac2.second=(t.second+faktor*(tac2.second-t.second));
            tac3.first=(t.first+faktor*(tac3.first-t.first));
            tac3.second=(t.second+faktor*(tac3.second-t.second));
        }
        void Rotiraj(double ugao) { Rotiraj(DajCentar(),ugao); }
        void Skaliraj(double faktor) { Skaliraj(DajCentar(),faktor); }
        friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2) {
            if(abs(Pomocna(t1.tac1,t1.tac2,t1.tac3))==abs(Pomocna(t2.tac1,t2.tac2,t2.tac3))) {
                //provjera najmanje dvije tacke najvjerovatnije potrebna!
                return true;
            }
            return false;
        }
        friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
        friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};


int main ()
{
    std::cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> pok(n,nullptr);
    for(int i(0);i<n;i++) {
        Tacka t1,t2,t3;
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>t1.first>>t1.second>>t2.first>>t2.second>>t3.first>>t3.second;
        try {
            pok[i]=std::make_shared<Trougao>(t1,t2,t3);
        }
        catch(std::domain_error izuzetak) {
            std::cout<<izuzetak.what()<<", ponovite unos!"<<std::endl;
            i--;
        }
    }
    std::cout<<"Unesite vektor translacije (dx dy): ";
    double x,y;
    std::cin>>x>>y;
    std::transform(pok.begin(),pok.end(),[x,y] (Trougao t) { t.Transliraj(x,y); });
    std::cout<<"Unesite ugao rotacije: ";
    double ugao;
    std::cin>>ugao;
    std::transform(pok.begin(),pok.end(), [ugao] (Trougao t) { t.Rotiraj(ugao); });
    std::cout<<"Unesite faktor skaliranja: ";
    double faktor;
    std::cin>>faktor;
    std::transform(pok.begin(),pok.end(), [faktor] (Trougao t) { t.Skaliraj(t.DajTjeme(1),faktor); })
    std::sort(pok.begin(),pok.end(),[] (Trougao t1, Trougao t2) { if(t1.DajPovrsinu()<t2.DajPovrsinu()) return true; else return false;})
    std::cout<<"Trouglovi nakon obavljenih transformacija:\n";
    std::foreach(pok.begin(),pok.end(), [] (Trougao t) { t.Ispisi(); std::cout<<std::endl; });
    /*for(int i(0);i<n;i++) {
        pok[i]->Ispisi();
        std::cout<<std::endl;
    }*/
    std::cout<<"Trougao sa najmanjim obimom:\n";
    std::cout<<*(std::min_element(pok.begin(),pok.end(), [] (Trougao t1, Trougao t2) { if(t1.DajObim()<t2.DajObim()) return true; else return false; }));
    std::cout<<"Parovi identicnih trouglova:\n";
    std::cout<<"Parovi podudarnih trouglova:\n";
    std::cout<<"Parovi slicnih trouglova:\n";
	return 0;
}