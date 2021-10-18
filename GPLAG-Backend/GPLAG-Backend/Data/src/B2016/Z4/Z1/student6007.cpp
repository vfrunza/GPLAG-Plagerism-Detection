/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <memory>
#include <cmath>
#define e 0.000000001


typedef std::pair<double, double> Tacka;
typedef std::vector<Tacka> vekt;

bool BacaLiIzuzetak (int indeks){
    bool dobar_indeks = false;
    if(indeks != 1 && indeks !=2 && indeks != 3)
        dobar_indeks = true;
    return dobar_indeks;
}

bool ProvjeraDoubleova (double prvi, double drugi){
    bool vracam = false;
    if(std::fabs(prvi-drugi)<=e) 
        vracam = true;
    return vracam;
}
class Trougao{
    private:
        Tacka tac1;
        Tacka tac2;
        Tacka tac3;
        
    public:
        Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3){
            if(Orijentacija(t1, t2, t3)==0)
                throw std::domain_error("Nekorektne pozicije tjemena");
            tac1 = t1;
            tac2 = t2;
            tac3 = t3;
        }
        void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
            if(Orijentacija(t1, t2, t3)==0)
                throw std::domain_error("Nekorektne pozicije tjemena");
            tac1 = t1;
            tac2 = t2;
            tac3 = t3;
        }
        void Postavi(int indeks, const Tacka &t){
            bool izuzetak = BacaLiIzuzetak(indeks);
            if(izuzetak) throw std::range_error("Nekorektan indeks");
            else if(indeks == 1) Postavi(t, tac2, tac3);
            else if(indeks == 2) Postavi(tac1,t, tac3);
            else if(indeks == 3) Postavi(tac1, tac2, t);
        }
        static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
            int vracam;
            static int nula = 0, minus = -1, plus = 1;
            vracam = t1.first*(t2.second-t3.second) - t2.first*(t1.second-t3.second) + t3.first*(t1.second-t2.second);
            if(vracam == 0) return nula;
            if(vracam > 0) return plus;
            return minus;
        }
        Tacka DajTjeme(int indeks) const {
            bool izuzetak = BacaLiIzuzetak(indeks);
            if(izuzetak) throw std::range_error("Nekorektan indeks");
            else if (indeks == 1) return tac1;
           else if (indeks == 2) return tac2;
            return tac3;
        }
        double DajStranicu(int indeks) const {
            double vracam;
            bool izuzetak = BacaLiIzuzetak(indeks);
            if(izuzetak) throw std::range_error("Nekorektan indeks");
            else if(indeks == 1) {
                vracam = std::sqrt(std::pow(tac2.first-tac3.first, 2) + std::pow(tac2.second-tac3.second,2));
            }
            else if (indeks == 2){
                vracam = std::sqrt(std::pow(tac1.first-tac3.first, 2) + std::pow(tac1.second-tac3.second,2));
            }
            else {
                vracam = std::sqrt(std::pow(tac1.first-tac2.first, 2) + std::pow(tac1.second-tac2.second,2));
            }
            return vracam;
        }
        double DajUgao(int indeks) const{
            bool izuzetak = BacaLiIzuzetak(indeks);
            double a, b, c;
            a = DajStranicu(1); b = DajStranicu(2); c = DajStranicu(3);
            if(izuzetak) throw std::range_error("Nekorektan indeks");
            else if (indeks == 1) return (std::acos((b*b+c*c-a*a)/(2*b*c)));
            else if (indeks == 2) return (std::acos((a*a+c*c-b*b)/(2*a*c)));
            else if (indeks == 3) return (std::acos((a*a+b*b-c*c)/(2*a*b)));
            //return vracam;
        }
        Tacka DajCentar() const{
            Tacka centar;
            centar.first = (tac1.first+tac2.first+tac3.first)/3;
            centar.second = (tac1.second + tac2.second + tac3.second)/3;
            return centar;
        }
        double DajObim() const{
            double o, a, b, c;
            a = DajStranicu(1); b = DajStranicu(2); c = DajStranicu(3);
            o = a + b + c;
            return o;
        }
        double DajPovrsinu() const{
            return ((1/2.)*std::fabs(tac1.first*(tac2.second-tac3.second)+tac2.first*(tac3.second-tac1.second)+tac3.first*(tac1.second-tac2.second)));
        }
        bool DaLiJePozitivnoOrijentiran() const{
            static int je_li_pozitivno;
            je_li_pozitivno = Orijentacija(tac1, tac2, tac3);
            if(je_li_pozitivno<=0) return false;
            else return true;
        }
        bool DaLiJeUnutra(const Tacka &t) const{
            try{
                Trougao prvi(tac1, tac2, tac3);
                Trougao drugi (tac1, tac2, t);
                Trougao treci (tac2, tac3, t);
                Trougao cetvrti (tac3, tac1, t);
                auto provjera1 = prvi.DajPovrsinu();
                auto provjera = drugi.DajPovrsinu()+treci.DajPovrsinu()+cetvrti.DajPovrsinu();
                if((ProvjeraDoubleova(provjera1, provjera)==true))
                    return true;
            }
            catch (...){
                return false;
            }
            return false;
        }
        void Ispisi() const {
            std::cout<<"(("<<tac1.first<<","<<tac1.second<<"),("<<tac2.first<<","<<tac2.second<<"),("<<tac3.first<<","<<tac3.second<<"))"<<std::endl;
        }
        void Ispisi1() const {
            std::cout<<"(("<<tac1.first<<","<<tac1.second<<"),("<<tac2.first<<","<<tac2.second<<"),("<<tac3.first<<","<<tac3.second<<"))";
        }
        void Transliraj(double delta_x, double delta_y){
            tac1.first = tac1.first + delta_x;
            tac1.second = tac1.second + delta_y;
            tac2.first = tac2.first + delta_x;
            tac2.second = tac2.second + delta_y;
            tac3.first = tac3.first + delta_x;
            tac3.second = tac3.second + delta_y;
        }
        void Centriraj(const Tacka &t){
            double dx, dy;
            Tacka c;
            
            c = DajCentar();
            dx = std::fabs(c.first+std::fabs(t.first));
            dy = std::fabs(c.second + std::fabs(t.second));
            
            if(ProvjeraDoubleova(c.first, t.first)==true)
                dx = 0;
            if (ProvjeraDoubleova(c.second, t.second)==true)
                dy = 0;
            if(t.first>=c.first && t.second>=c.second){
                tac1.first = tac1.first + dx;
                tac2.first = tac2.first + dx;
                tac3.first = tac3.first + dx;
                tac1.second = tac1.second + dy;
                tac2.second = tac2.second + dy;
                tac3.second = tac3.second + dy;
            }
            else if(t.first>c.first && t.second<c.second){
                tac1.first = tac1.first + dx;
                tac2.first = tac2.first + dx;
                tac3.first = tac3.first + dx;
                tac1.second = tac1.second - dy;
                tac2.second = tac2.second - dy;
                tac3.second = tac3.second - dy;
            }
            else if(t.first<c.first && t.second>c.second){
                tac1.first = tac1.first - dx;
                tac2.first = tac2.first - dx;
                tac3.first = tac3.first - dx;
                tac1.second = tac1.second + dy;
                tac2.second = tac2.second + dy;
                tac3.second = tac3.second + dy;
            }
            else{
                tac1.first = tac1.first - dx;
                tac2.first = tac2.first - dx;
                tac3.first = tac3.first - dx;
                tac1.second = tac1.second - dy;
                tac2.second = tac2.second - dy;
                tac3.second = tac3.second - dy;
            }
        }
        void Rotiraj(const Tacka &t, double ugao){
            Tacka a, b, c;
            
            a.first = t.first + cos(ugao)*(tac1.first-t.first) - sin(ugao)*(tac1.second-t.second);
            a.second = t.second + sin(ugao)*(tac1.first-t.first) + cos(ugao)*(tac1.second-t.second);
            tac1 = a;
            
            b.first = t.first + cos(ugao)*(tac2.first-t.first) - sin(ugao)*(tac2.second-t.second);
            b.second = t.second + sin(ugao)*(tac2.first-t.first) + cos(ugao)*(tac2.second-t.second);
            tac2 = b;
            
            c.first = t.first + cos(ugao)*(tac3.first - t.first) - sin(ugao)*(tac3.second-t.second);
            c.second = t.second + sin(ugao)*(tac3.first-t.first) + cos(ugao)*(tac3.second-t.second);
            tac3 = c;
        }
        void Skaliraj(const Tacka &t, double faktor){
            Tacka a, b, c;
            if((ProvjeraDoubleova(faktor, 0)==true))
                throw std::domain_error("Nekorektan faktor skaliranja");
            a.first = t.first + faktor*(tac1.first - t.first);
            a.second = t.second + faktor*(tac1.second - t.second);
            tac1 = a;
            
            b.first = t.first + faktor*(tac2.first - t.first);
            b.second = t.second + faktor*(tac2.second - t.second);
            tac2 = b;
            
            c.first = t.first + faktor*(tac3.first - t.first);
            c.second = t.second + faktor*(tac3.second - t.second);
            tac3 = c;
        }
        void Rotiraj(double ugao){
        Tacka a, b, c;
        Tacka t;
        t = DajCentar();
            a.first = t.first + cos(ugao)*(tac1.first-t.first) - sin(ugao)*(tac1.second-t.second);
            a.second = t.second + sin(ugao)*(tac1.first-t.first) + cos(ugao)*(tac1.second-t.second);
            tac1 = a;
            
            b.first = t.first + cos(ugao)*(tac2.first-t.first) - sin(ugao)*(tac2.second-t.second);
            b.second = t.second + sin(ugao)*(tac2.first-t.first) + cos(ugao)*(tac2.second-t.second);
            tac2 = b;
            
            c.first = t.first + cos(ugao)*(tac3.first - t.first) - sin(ugao)*(tac3.second-t.second);
            c.second = t.second + sin(ugao)*(tac3.first-t.first) + cos(ugao)*(tac3.second-t.second);
            tac3 = c;    
        }
        void Skaliraj(double faktor){
        Tacka a, b, c;
        Tacka t;
        t = DajCentar();
            if((ProvjeraDoubleova(faktor, 0)==true))
                throw std::domain_error("Nekorektan faktor skaliranja");
            a.first = t.first + faktor*(tac1.first - t.first);
            a.second = t.second + faktor*(tac1.second - t.second);
            tac1 = a;
            
            b.first = t.first + faktor*(tac2.first - t.first);
            b.second = t.second + faktor*(tac2.second - t.second);
            tac2 = b;
            
            c.first = t.first + faktor*(tac3.first - t.first);
            c.second = t.second + faktor*(tac3.second - t.second);
            tac3 = c;    
        }
        friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){

        if ((t1.tac1==t2.tac1 || t1.tac1==t2.tac2 || t1.tac1==t2.tac3) && (t1.tac2==t2.tac1 || t1.tac2==t2.tac2 || t1.tac2==t2.tac3) && (t1.tac3==t2.tac1 || t1.tac3==t2.tac2 || t1.tac3==t2.tac3)) return true;
           return false;

        }
        friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
        auto a = t1.DajStranicu(1); auto b = t1.DajStranicu(2); auto c = t1.DajStranicu(3);
        
        auto a1 = t2.DajStranicu(1); auto b1 = t2.DajStranicu(2); auto c1 = t2.DajStranicu(3);
                
        if((ProvjeraDoubleova(a, c1)==true) && (ProvjeraDoubleova(b, b1)==true) && (ProvjeraDoubleova(c, a1)==true) && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(3),t2.DajTjeme(2),t2.DajTjeme(1)))
            return true;

        else if((ProvjeraDoubleova(a, a1)==true) && (ProvjeraDoubleova(b, b1)==true) && (ProvjeraDoubleova(c, c1)==true) && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3)))
            return true;
        else if((ProvjeraDoubleova(a, a1)==true) && (ProvjeraDoubleova(b, c1)==true) && (ProvjeraDoubleova(c, b1)==true) && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(3),t2.DajTjeme(2)))
            return true;
        else if((ProvjeraDoubleova(a, b1)==true) && (ProvjeraDoubleova(b, a1)==true) && (ProvjeraDoubleova(c, c1)==true) && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(2),t2.DajTjeme(1),t2.DajTjeme(3)))
            return true;
        else if((ProvjeraDoubleova(a, b1)==true) && (ProvjeraDoubleova(b, c1)==true) && (ProvjeraDoubleova(c, a1)==true) && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(2),t2.DajTjeme(3),t2.DajTjeme(1)))
            return true;
        else if((ProvjeraDoubleova(a, c1)==true) && (ProvjeraDoubleova(b, a1)==true) && (ProvjeraDoubleova(c, b1)==true) && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(3),t2.DajTjeme(1),t2.DajTjeme(2)))
            return true;
        else
            return false;

    }
             
        
        friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
            /*double a, b, c, al, bet, gam, al1, bet1, gam1, a1, b1, c1;
            a = t1.DajStranicu(1); b = t1.DajStranicu(2); c = t1.DajStranicu(3);
            a1 = t2.DajStranicu(1); b1 = t2.DajStranicu(2); c1 = t2.DajStranicu(3);
            al = t1.DajUgao(1); bet = t1.DajUgao(2); gam = t1.DajUgao(3);
            al1 = t2.DajUgao(1); bet1 = t2.DajUgao(2); gam1 = t2.DajUgao(3);
            double aa1 = a/a1;
            double bb1 = b/b1;
            double cc1 = c/c1;
            if((((ProvjeraDoubleova(al, al1)==true) && (ProvjeraDoubleova(bet, bet1))==true)) || (((ProvjeraDoubleova(al, al1)==true) && (ProvjeraDoubleova(gam, gam1))==true)) || (((ProvjeraDoubleova(gam, gam1)==true) && (ProvjeraDoubleova(bet, bet1))==true))) 
                return true;
            
            else if((ProvjeraDoubleova(aa1, cc1)==true) && (ProvjeraDoubleova(bet, bet1)==true)) 
                return true;
            else if((ProvjeraDoubleova(aa1, bb1)==true) && (ProvjeraDoubleova(aa1, cc1)==true)) 
                return true;
            else if((ProvjeraDoubleova(aa1, bb1)==true) && (ProvjeraDoubleova(gam, gam1)==true)) 
                return true;
            else if((ProvjeraDoubleova(bb1, cc1)==true) && (ProvjeraDoubleova(al, al1)==true))
                return true;
            else 
                return false;*/
        double a = t1.DajStranicu(1); double b = t1.DajStranicu(2); double c = t1.DajStranicu(3); double a1 = t2.DajStranicu(1); double b1 = t2.DajStranicu(2); double c1 = t2.DajStranicu(3);
        double stra = a/a1; double strb = b/b1; double strc = c/c1; double strab = a/b1; double strcb = c/b1; double strca = c/a1; double strac1 = a/c1; double strba1 = b/c1; double strba2 = b/a1;
                
        if((ProvjeraDoubleova(strac1,strb)==true) && (ProvjeraDoubleova(strac1,strca)==true) && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(3),t2.DajTjeme(2),t2.DajTjeme(1)))
            return true;
        else if((ProvjeraDoubleova(stra,strb)==true) && (ProvjeraDoubleova(stra,strc)==true) && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(2),t2.DajTjeme(3)))
            return true;
        else if((ProvjeraDoubleova(stra,strba1)==true) && (ProvjeraDoubleova(stra,strcb)==true) && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(1),t2.DajTjeme(3),t2.DajTjeme(2)))
            return true;
        else if((ProvjeraDoubleova(strab,strba2)==true) && (ProvjeraDoubleova(strab,strc)==true) && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(2),t2.DajTjeme(1),t2.DajTjeme(3)))
            return true;
        else if((ProvjeraDoubleova(strab,strba1)==true) && (ProvjeraDoubleova(strab,strca)==true) && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(2),t2.DajTjeme(3),t2.DajTjeme(1)))
            return true;
        else if((ProvjeraDoubleova(strac1,strba2)==true) && (ProvjeraDoubleova(strac1,strcb)==true) && t1.Orijentacija(t1.DajTjeme(1),t1.DajTjeme(2),t1.DajTjeme(3)) == t2.Orijentacija(t2.DajTjeme(3),t2.DajTjeme(1),t2.DajTjeme(2)))
            return true;
        else 
            return false;
    }
};
typedef std::vector<std::shared_ptr<Trougao>> vekdijeljeni;
int main (){
    int broj_trouglova;
    vekdijeljeni vek;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>broj_trouglova;
    vek.resize(broj_trouglova);
    double dx, dy, s, ugao; 
    
    for(int i = 0; i <vek.size(); ++i){
        Tacka a, b, c;
        std::cout<<"Unesite podatke za "<< i+1<<". trougao (x1 y1 x2 y2 x3 y3): "; 
        std::cin>>a.first; 
        std::cin>>a.second;
        
        std::cin>>b.first; 
        std::cin>>b.second;
       
        std::cin>>c.first; 
        std::cin>>c.second;
        
        
        try{
            Trougao t (a, b, c);
            vek[i] = std::make_shared<Trougao> (t);
        }
        catch(std::domain_error izuzetak){
            std::cout<<izuzetak.what()<<", ponovite unos!"<<std::endl;
            i--;
        }
        catch(std::bad_alloc izuzetak){
            std::cout<<"Problem sa memorijom!";
        }
    }
    
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>dx; 
    std::cin>>dy;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>ugao;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>s;
    
    auto pok = vek.begin();
    std::transform(vek.begin(), vek.end(), pok, [dx, dy](std::shared_ptr<Trougao> t){
        (*t).Transliraj(dx, dy);
        return t;
        }
    );
    auto pok1 = vek.begin();
    std::transform(vek.begin(), vek.end(), pok1, [ugao](std::shared_ptr<Trougao> t){
        (*t).Rotiraj((*t).DajCentar(), ugao);
        return t;
        }
    );

    //std::cout<<std::endl;
   
    auto pok2 = vek.begin();
    std::transform(vek.begin(), vek.end(), pok2, [s](std::shared_ptr<Trougao> t){
        (*t).Skaliraj(t->DajTjeme(1),s);
        return t;
        }
    );
 
    std::sort(vek.begin(), vek.end(), [](std::shared_ptr<Trougao> trokut, std::shared_ptr<Trougao> trokutt){
        if((*trokut).DajPovrsinu()<(*trokutt).DajPovrsinu()) 
            return true;
        return false;
        }
    );
    
    std::cout<<"Trouglovi nakon obavljenih transformacija:\n";
    auto pocetak = vek.begin();
    auto kraj = vek.end();
    
    std::for_each(pocetak, kraj, [](std::shared_ptr<Trougao> t){
        (*t).Ispisi();
        }
    );
    
    auto beg = vek.begin();
    auto endd = vek.end();
    auto pokazuje(std::min_element(beg, endd, [](std::shared_ptr<Trougao> trokut, std::shared_ptr<Trougao> trokutt){
        if((*trokut).DajObim()>=(*trokutt).DajObim())
            return false;
        return true;
        }
    ));
    
    std::cout<<"Trougao sa najmanjim obimom: ";
    (*pokazuje)->Ispisi();
    //std::cout<<std::endl;
    int velicina = vek.size();
    std::vector<std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>>> parovi;
    for(int i = 0; i <velicina - 1; i++ ){
        for(int j = i + 1; j<velicina; j++){
            if(DaLiSuIdenticni(*vek[i],*vek[j])){
                parovi.push_back(make_pair(vek[i],vek[j]));
            }
        }
    }
    if(parovi.size()!=0){
        std::cout<<"Parovi identicnih trouglova:\n";
        for(int i = 0; i<parovi.size(); i++){
            parovi[i].first->Ispisi1(); 
            std::cout<<" i "; parovi[i].second->Ispisi();
        }
    }
    else{
        std::cout<<"Nema identicnih trouglova!"<<std::endl;
    }
    std::vector<std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>>> parovi1;
    for(int i = 0; i <velicina - 1; i++ ){
        for(int j = i + 1; j<velicina; j++){
            if(DaLiSuPodudarni(*vek[i],*vek[j])){
                parovi1.push_back(make_pair(vek[i],vek[j]));
            }
        }
    }
    if(parovi1.size()!=0){
        std::cout<<"Parovi podudarnih trouglova:\n";
        for(int i = 0; i<parovi1.size(); i++){
            parovi1[i].first->Ispisi1();
            std::cout<<" i ";
            parovi1[i].second->Ispisi();
        }
    }
    else{
        std::cout<<"Nema podudarnih trouglova!"<<std::endl;
    }
    std::vector<std::pair<std::shared_ptr<Trougao>, std::shared_ptr<Trougao>>> parovi2;
    for(int i = 0; i <velicina - 1; i++ ){
        for(int j = i + 1; j<velicina; j++){
            if(DaLiSuSlicni(*vek[i],*vek[j])){
                parovi2.push_back(make_pair(vek[i],vek[j]));
            }
        }
    }
    if(parovi2.size()!=0){
        std::cout<<"Parovi slicnih trouglova:\n";
        for(int i = 0; i<parovi2.size(); i++){
            parovi2[i].first->Ispisi1();
            std::cout<<" i ";
            parovi2[i].second->Ispisi();
        }
    }
    else{
        std::cout<<"Nema slicnih trouglova!"<<std::endl;
    }
    
	return 0;
}