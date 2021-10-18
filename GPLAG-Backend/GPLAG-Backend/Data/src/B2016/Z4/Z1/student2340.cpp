/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!

#include <iostream>
#include <cmath>
#include <utility>
#include <stdexcept>
#include <memory>
#include <algorithm>
#include <vector> 
const double eps = 1e-10;
const double PI = 4*atan(1);

typedef std::pair<double,double> Tacka;

class Trougao{
         Tacka t1,t2,t3;
         
         static double koordinate(const Tacka &t1,const Tacka &t2,const Tacka &t3){
             return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
         }

        double duzina_stranice23() const{
            return std::sqrt((t2.first-t3.first)*(t2.first-t3.first)+(t2.second-t3.second)*(t2.second-t3.second));}
        double duzina_stranice31() const{
            return std::sqrt((t3.first-t1.first)*(t3.first-t1.first)+(t3.second-t1.second)*(t3.second-t1.second));}
        double duzina_stranice12() const{
            return std::sqrt((t1.first-t2.first)*(t1.first-t2.first)+(t1.second-t2.second)*(t1.second-t2.second));}
        
        double ugaoalfa() const{
             return acos ((duzina_stranice12()*duzina_stranice12()+duzina_stranice31()*duzina_stranice31()
                            -duzina_stranice23()*duzina_stranice23())/(2*duzina_stranice12()*duzina_stranice31()));
        }
        double ugaobeta() const{
             return acos ((duzina_stranice12()*duzina_stranice12()-duzina_stranice31()*duzina_stranice31()
                            +duzina_stranice23()*duzina_stranice23())/(2*duzina_stranice12()*duzina_stranice23()));
        }
        double ugaogamma() const{
             return acos ((-duzina_stranice12()*duzina_stranice12()+duzina_stranice31()*duzina_stranice31()
                            +duzina_stranice23()*duzina_stranice23())/(2*duzina_stranice23()*duzina_stranice31()));
        }
    public:

        Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){

             auto k=Orijentacija(t1,t2,t3);
             if(k==0) throw std::domain_error("Nekorektne pozicije tjemena");
                          Trougao::t1=t1;    Trougao::t2=t2;    Trougao::t3=t3;
        }
        

        void Postavi (const Tacka &t1, const Tacka &t2, const Tacka &t3){
        auto k=Orijentacija(t1,t2,t3);
             if(k==0) throw std::domain_error("Nekorektne pozicije tjemena");
         Trougao::t1=t1;    Trougao::t2=t2;    Trougao::t3=t3;
        }

        void Postavi (int indeks, const Tacka &t){
             if(indeks==1)   Trougao::t1=t1;    
             else if(indeks==2)   Trougao::t2=t2;    
             else if(indeks==3)   Trougao::t3=t3;
             else throw std::range_error("Nekorektan indeks");
        }


        static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3){
            double a=koordinate(t1,t2,t3);
            if (a<0) return -1;
            else if (a>0) return 1;
            else 
            return 0;
        }


        Tacka DajTjeme (int indeks) const{
            if (indeks==1) return t1;
            else if (indeks==2) return t2;
            else if (indeks==3) return t3;
            else throw std::range_error("Nekorektan indeks");
        }


        double DajStranicu (int indeks) const{
            if (indeks==1)  return duzina_stranice23();
            else if (indeks==2)  return duzina_stranice31();
            else if (indeks==3)  return duzina_stranice12();
            else throw std::range_error("Nekorektan indeks");
        }
        
        double DajUgao (int indeks) const{
            if(indeks==1){ return ugaoalfa();}
            else if(indeks==2){ return ugaobeta();}
            else if(indeks==3){ return ugaogamma();}
            else throw std::range_error("Nekorektan indeks");
            
        }
        
        Tacka DajCentar () const{
            Tacka tt;
            tt.first=(t1.first+t2.first+t3.first)/3;
            tt.second=(t1.second+t2.second+t3.second)/3;
            return tt;
        }

        double DajObim () const{
            return duzina_stranice12()+duzina_stranice23()+duzina_stranice31();
            
        }

        double DajPovrsinu () const{
            return fabs(koordinate(t1,t2,t3))*(1./2);
        }


        bool DaLiJePozitivnoOrijentisan() const{
            auto a=Orijentacija(t1,t2,t3);
            if (a>0 ) return true;
            else return false;
        }


        bool DaLiJeUnutra (const Tacka &t) const{
            if((Orijentacija(t,t1,t2)==1) && (Orijentacija(t,t2,t3)==1) && (Orijentacija(t,t1,t3)==1)) return true;
            return false;
        }

        void Ispisi () const{
            std::cout<<"(("<<t1.first<<","<<t1.second<<"),("<<t2.first<<","<<t2.second<<"),("<<t3.first
                     <<","<<t3.second<<"))";
        }

        void Transliraj (double delta_x,double delta_y){
            t1.first=t1.first+delta_x;
            t2.first=t2.first+delta_x;
            t3.first=t3.first+delta_x;
            t1.second=t1.second+delta_y;
            t2.second=t2.second+delta_y;
            t3.second=t3.second+delta_y;
        }
        
     
        void Centriraj (const Tacka &t){
            Tacka tt=DajCentar();
            
            tt.first=tt.first+t.first;
            tt.second=tt.second+t.second;
            
            t1.first=t1.first+tt.first;
            t2.first=t2.first+tt.first;
            t3.first=t3.first+tt.first;
            t1.second=t1.second+tt.second;
            t2.second=t2.second+tt.second;
            t3.second=t3.second+tt.second;
        }


        void Rotiraj(const Tacka &t, double ugao){
            t1.first=t.first+(t1.first-t.first)*cos(ugao)-(t1.second-t.second)*sin(ugao);
            t2.first=t.first+(t2.first-t.first)*cos(ugao)-(t2.second-t.second)*sin(ugao);
            t3.first=t.first+(t3.first-t.first)*cos(ugao)-(t3.second-t.second)*sin(ugao);
            t1.second=t.second+(t1.first-t.first)*sin(ugao)+(t1.second-t.second)*cos(ugao);
            t2.second=t.second+(t2.first-t.first)*sin(ugao)+(t2.second-t.second)*cos(ugao);
            t3.second=t.second+(t3.first-t.first)*sin(ugao)+(t3.second-t.second)*cos(ugao);
        }

        void Skaliraj(const Tacka &t, double faktor){
            if(faktor>0){
                t1.first=t.first+faktor*(t1.first-t.first);
                t2.first=t.first+faktor*(t2.first-t.first);
                t3.first=t.first+faktor*(t3.first-t.first);
                t1.second=t.second+faktor*(t1.second-t.second);
                t2.second=t.second+faktor*(t2.second-t.second);
                t3.second=t.second+faktor*(t3.second-t.second);
        }
            else if (faktor<0){ 
                t1.first=t.first+faktor*(t1.first-t.first);
                t2.first=t.first+faktor*(t2.first-t.first);
                t3.first=t.first+faktor*(t3.first-t.first);
                t1.second=t.second+faktor*(t1.second-t.second);
                t2.second=t.second+faktor*(t2.second-t.second);
                t3.second=t.second+faktor*(t3.second-t.second);
                Rotiraj(PI);
            }
            else throw std::domain_error ("Nekorektan faktor skaliranja");
        }
        
        
        void Rotiraj(double ugao){
            Tacka tt=DajCentar();
         
            double x1=tt.first+(t1.first-tt.first)*cos(ugao)-(t1.second-tt.second)*sin(ugao);
            double x2=tt.first+(t2.first-tt.first)*cos(ugao)-(t2.second-tt.second)*sin(ugao);
            double x3=tt.first+(t3.first-tt.first)*cos(ugao)-(t3.second-tt.second)*sin(ugao);
            double y1=tt.second+(t1.first-tt.first)*sin(ugao)+(t1.second-tt.second)*cos(ugao);
            double y2=tt.second+(t2.first-tt.first)*sin(ugao)+(t2.second-tt.second)*cos(ugao);
            double y3=tt.second+(t3.first-tt.first)*sin(ugao)+(t3.second-tt.second)*cos(ugao);
            
            t1.first=x1; t2.first=x2; t3.first=x3;
            t1.second=y1; t2.second=y2; t3.second=y3;
            
        }
        
        void Skaliraj(double faktor){
            Tacka tt=DajCentar();
            
            if(faktor>0){
                t1.first=tt.first+faktor*(t1.first-tt.first);
                t2.first=tt.first+faktor*(t2.first-tt.first);
                t3.first=tt.first+faktor*(t3.first-tt.first);
                t1.second=tt.second+faktor*(t1.second-tt.second);
                t2.second=tt.second+faktor*(t2.second-tt.second);
                t3.second=tt.second+faktor*(t3.second-tt.second);
        }
            else if (faktor<0){
                t1.first=tt.first+faktor*(t1.first-tt.first);
                t2.first=tt.first+faktor*(t2.first-tt.first);
                t3.first=tt.first+faktor*(t3.first-tt.first);
                t1.second=tt.second+faktor*(t1.second-tt.second);
                t2.second=tt.second+faktor*(t2.second-tt.second);
                t3.second=tt.second+faktor*(t3.second-tt.second);
                Rotiraj(PI);
            }
            else throw std::domain_error ("Nekorektan faktor skaliranja");
        }

friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
     if((t1.t1==t2.t1) && (t1.t2==t2.t2) && (t1.t3==t2.t3)) return true;
     if((t1.t1==t2.t1) && (t1.t2==t2.t3) && (t1.t3==t2.t2)) return true;
     if((t1.t1==t2.t2) && (t1.t2==t2.t1) && (t1.t3==t2.t3)) return true;
     if((t1.t1==t2.t3) && (t1.t2==t2.t2) && (t1.t3==t2.t1)) return true;
    return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    
    std::vector<std::pair<Tacka, double>> stranice1(3);
    std::vector<std::pair<Tacka, double>> stranice2(3);
    
    stranice1[0] = std::make_pair(t1.DajTjeme(3),t1.duzina_stranice12());
    stranice1[1] = std::make_pair(t1.DajTjeme(1),t1.duzina_stranice23());
    stranice1[2] = std::make_pair(t1.DajTjeme(2),t1.duzina_stranice31());
    
    stranice2[0] = std::make_pair(t2.DajTjeme(3),t2.duzina_stranice12());
    stranice2[1] = std::make_pair(t2.DajTjeme(1),t2.duzina_stranice23());
    stranice2[2] = std::make_pair(t2.DajTjeme(2),t2.duzina_stranice31());
    
    
    sort(stranice1.begin(),stranice1.end(), [] (const std::pair<Tacka,double> &p1, const std::pair<Tacka,double> &p2){
        return p1.second<p2.second;
    });
    sort(stranice2.begin(),stranice2.end(), [] (const std::pair<Tacka,double> &p1, const std::pair<Tacka,double> &p2){
        return p1.second<p2.second;
    });
    
    
    for(int i=0; i<3; i++){
        if(stranice1[i].second!= stranice2[i].second) return false;
    }
    
    if(Trougao::Orijentacija(stranice1[0].first,stranice1[1].first,stranice1[2].first)==
      Trougao::Orijentacija(stranice2[0].first,stranice2[1].first,stranice2[2].first)) return true;
    
    return false;

}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    
    std::vector<std::pair<Tacka, double>> uglovi1(3);
    std::vector<std::pair<Tacka, double>> uglovi2(3);
    
    uglovi1[0] = std::make_pair(t1.DajTjeme(1),t1.DajUgao(1));
    uglovi1[1] = std::make_pair(t1.DajTjeme(2),t1.DajUgao(2));
    uglovi1[2] = std::make_pair(t1.DajTjeme(3),t1.DajUgao(3));
    
    uglovi2[0] = std::make_pair(t2.DajTjeme(1),t2.DajUgao(1));
    uglovi2[1] = std::make_pair(t2.DajTjeme(2),t2.DajUgao(2));
    uglovi2[2] = std::make_pair(t2.DajTjeme(3),t2.DajUgao(3));
    
    sort(uglovi1.begin(),uglovi1.end(), [] (const std::pair<Tacka,double> &p1, const std::pair<Tacka,double> &p2){
        return p1.second<p2.second;
    });
    sort(uglovi2.begin(),uglovi2.end(), [] (const std::pair<Tacka,double> &p1, const std::pair<Tacka,double> &p2){
        return p1.second<p2.second;
    });
    
    
    for(int i=0; i<3; i++){
        if(uglovi1[i].second!= uglovi2[i].second) return false;
    }
    
    if(Trougao::Orijentacija(uglovi1[0].first,uglovi1[1].first,uglovi1[2].first)==
       Trougao::Orijentacija(uglovi2[0].first,uglovi2[1].first,uglovi2[2].first)) return true;
    
    return false;
}

int main ()
{
    int n;
    double delta_x,delta_y,ugao_rotacije,faktor_skaliranja;
    Tacka t1,t2,t3;
    
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> vektor(n);
   
    for(int i(0); i<n; i++){
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>t1.first>>t1.second;
        std::cin>>t2.first>>t2.second;
        std::cin>>t3.first>>t3.second;
        try{
            vektor[i] = std::make_shared<Trougao>(t1,t2,t3);
        }
        catch(std::domain_error &e){
            std::cout<<e.what()<<", ponovite unos!\n";
            i--;
        }
    }
    std::cout<<"Unesite vektor translacije (dx dy): ";
    std::cin>>delta_x>>delta_y;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>ugao_rotacije;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor_skaliranja;
   
   std::cout<<"Trouglovi nakon obavljenih transformacija:\n";
   std::transform(vektor.begin(),vektor.end(), vektor.begin(), [delta_x,delta_y,ugao_rotacije,faktor_skaliranja] 
                (std::shared_ptr<Trougao> &t){
                    t->Transliraj(delta_x,delta_y);
                    t->Rotiraj(ugao_rotacije);
                    t->Skaliraj(t->DajTjeme(1),faktor_skaliranja);
                    return t;
   });
    std::sort(vektor.begin(),vektor.end(), [] (const std::shared_ptr<Trougao> &t1, const std::shared_ptr<Trougao> &t2){
                return t1->DajPovrsinu() < t2->DajPovrsinu();
    });
    std::for_each(vektor.begin(),vektor.end(), [] (const std::shared_ptr<Trougao> &t){
        t->Ispisi();
        std::cout<<std::endl;
    });
    std::cout<<"Trougao sa najmanjim obimom: ";
    auto min_trougao = *std::min_element(vektor.begin(), vektor.end(), [](const std::shared_ptr<Trougao> &t1,const std::shared_ptr<Trougao> &t2) {
        return t1->DajObim()<t2->DajObim();
    }); 
    min_trougao->Ispisi();
    std::cout<<std::endl;
    int brojac (0);
    
    for(int i=0; i<vektor.size()-1;i++){
        for(int j=i+1;j<vektor.size(); j++){
            if(DaLiSuIdenticni(*vektor[i],*vektor[j])) brojac++;
        }
    }
    if(brojac==0) std::cout<<"Nema identicnih trouglova!\n";
    else{
    std::cout<<"Parovi identicnih trouglova:\n";
    for(int i=0; i<vektor.size()-1;i++){
        for(int j=i+1;j<vektor.size(); j++){
            if(DaLiSuIdenticni(*vektor[i],*vektor[j])){
                vektor[i]->Ispisi();
                std::cout<<" i ";
                vektor[j]->Ispisi();
                std::cout << std::endl;
                brojac++;
                }
            }
        }
    }
    brojac=0;

    for(int i=0; i<vektor.size()-1;i++){
        for(int j=i+1;j<vektor.size(); j++){
            if(DaLiSuPodudarni(*vektor[i],*vektor[j])) brojac++;
        }
    }
    if(brojac==0) std::cout<<"Nema podudarnih trouglova!\n";
    else{
    std::cout<<"Parovi podudarnih trouglova:\n";
    for(int i=0; i<vektor.size()-1;i++){
        for(int j=i+1;j<vektor.size(); j++){
            if(DaLiSuPodudarni(*vektor[i],*vektor[j])){
                vektor[i]->Ispisi();
                std::cout<<" i ";
                vektor[j]->Ispisi();
                std::cout << std::endl;
                brojac++;
                }
            }
        }
    }
    
    brojac=0;

    
    for(int i=0; i<vektor.size()-1;i++){
        for(int j=i+1;j<vektor.size(); j++){
            if(DaLiSuSlicni(*vektor[i],*vektor[j])) brojac++;
        }
    }
    if(brojac==0) std::cout<<"Nema slicnih trouglova!\n";
    else{
    std::cout<<"Parovi slicnih trouglova:\n";
    for(int i=0; i<vektor.size()-1;i++){
        for(int j=i+1;j<vektor.size(); j++){
            if(DaLiSuSlicni(*vektor[i],*vektor[j])){
                vektor[i]->Ispisi();
                std::cout<<" i ";
                vektor[j]->Ispisi();
                std::cout << std::endl;
                brojac++;
                }
            }
        }
    }
  std::for_each(vektor.begin(),vektor.end(), [](std::shared_ptr<Trougao> &t1){
  t1=nullptr;
    });
	return 0;
}