/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>

typedef std::pair<double,double> Tacka;

class Trougao {
    Tacka tjemena [3];
    public:
    //konstruktor
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
         if(Orijentacija(t1,t2,t3)==0) throw std:: domain_error ("Nekorektne pozicije tjemena");
        Postavi(t1,t2,t3);
    }   
    
    //fje clanice
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
       if(Orijentacija(t1,t2,t3)==0) throw std:: domain_error ("Nekorektne pozicije tjemena");
        tjemena[0]=t1;
        tjemena[1]=t2;
        tjemena[2]=t3;
    }
    void Postavi(int indeks, const Tacka &t){
        Test_indeksa(indeks);
        tjemena[indeks-1]=t;
    } 
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double orijentacija(Orijentacija_i_Povrsina(t1,t2,t3));
        if (orijentacija<0) return -1;
        if (orijentacija>0) return 1;
        else return orijentacija;
    }
   
    
    Tacka DajTjeme(int indeks) const{
        Test_indeksa(indeks);
        return tjemena[indeks-1];
    }
    
    double DajStranicu(int indeks) const{
        Test_indeksa(indeks);
        double duzina(std::pow((DajTjeme(Tacka_desno(indeks)).first - DajTjeme(Tacka_lijevo(indeks)).first),2)  +  std::pow((DajTjeme(Tacka_desno(indeks)).second - DajTjeme(Tacka_lijevo(indeks)).second),2));
        return std::sqrt(duzina);
    }
    
    double DajUgao(int indeks) const{
        Test_indeksa(indeks);
        double kosinusugla(std::pow(DajStranicu(Tacka_desno(indeks)),2)+std::pow(DajStranicu(Tacka_lijevo(indeks)),2)-std::pow(DajStranicu(indeks),2));
        return std::acos(kosinusugla/(2 * DajStranicu(Tacka_desno(indeks)) * DajStranicu(Tacka_lijevo(indeks))));
    }
    
    Tacka DajCentar() const {
        double x((tjemena[0].first +  tjemena[1].first + tjemena[2].first)/3);
        double y((tjemena[0].second +  tjemena[1].second + tjemena[2].second)/3);
        return std::make_pair(x,y);
    }
        
    double DajObim() const{
        return (DajStranicu(1)+DajStranicu(2)+DajStranicu(3));
    }
    double DajPovrsinu() const{
       return ( abs ( Orijentacija_i_Povrsina(tjemena[0], tjemena[1], tjemena[2])  )/ 2);
     }
     
    bool DaLiJePozitivnoOrijentiran() const {
        if(Orijentacija(tjemena[0],tjemena[1],tjemena[2])==1) return true;
        else return false;
    }
        
    bool DaLiJeUnutra(const Tacka &t) const{
        auto x(Orijentacija(tjemena[0],tjemena[1], tjemena[2]));
        if(x==Orijentacija(tjemena[0],tjemena[1],t) && 
           x==Orijentacija(tjemena[1],tjemena[2],t) &&
           x==Orijentacija(tjemena[2],tjemena[0],t)) return true;
         else return false;  
    }
    
    void Ispisi() const{
        std::cout<<"(("<<DajTjeme(1).first<<","<<DajTjeme(1).second<<"),("<<DajTjeme(2).first<<","<<DajTjeme(2).second<<"),(";
        std::cout<<DajTjeme(3).first<<","<<DajTjeme(3).second<<"))";
        
    }
    
   void Transliraj(double delta_x, double delta_y){
        for(int i=0;i<3; i++){
            tjemena[i].first+=delta_x;
            tjemena[i].second+=delta_y;
        }
    }
    
    void Centriraj(const Tacka &t){
        auto teziste(DajCentar());
        Transliraj(teziste.first - t.first, teziste.second - t.second);
    }
    
    void Rotiraj(const Tacka &t, double ugao){
        for(int i=0; i<3; i++){
           double x=t.first+(tjemena[i].first-t.first)*std::cos(ugao)-(tjemena[i].second-t.second)*std::sin(ugao);
           double y=t.second+(tjemena[i].first-t.first)*std::sin(ugao)+(tjemena[i].second-t.second)*std::cos(ugao);
           tjemena[i].first=x;
           tjemena[i].second=y;
        }
     }
     void Skaliraj(const Tacka &t, double faktor){
         if(JesuLiJednaki(faktor,0)) throw std::domain_error ("Nekorektan faktor skaliranja");
         for(int i=0;i <3; i++){
             tjemena[i].first=t.first + faktor*(tjemena[i].first - t.first);
             tjemena[i].second=t.second + faktor*(tjemena[i].second - t.second);
         }
     }
     void Rotiraj(double ugao){
         auto teziste(DajCentar());
         Rotiraj(teziste,ugao);
     }   
     void Skaliraj(double faktor){
         auto teziste(DajCentar());
         Skaliraj(teziste,faktor);
         
     }
     
      // pomocne funkcije
    void Test_indeksa(int indeks)const{
        if (indeks<1 ||indeks>3) throw std:: range_error ("Nekorektan indeks");
    }
    
     static bool JesuLiJednaki(double x, double y, double Eps = 0.00000000001)  {
        return std::fabs(x - y) <= Eps * (std::fabs(x) + std::fabs(y));
    }
    
    static double Orijentacija_i_Povrsina(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        return (t1.first * (t2.second-t3.second)  -  t2.first * (t1.second-t3.second)  +  t3.first * (t1.second-t2.second)); 
    }
    
    int Tacka_desno(int indeks) const{
        Test_indeksa(indeks);
        indeks++;
        if(indeks==4) indeks=1;
        return indeks;
    }
    
    int Tacka_lijevo(int indeks) const{
        Test_indeksa(indeks);
        indeks--;
        if(indeks==0) indeks=3;
        return indeks;
        
    }
    
     //Prijateljske funkcije
     
     friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
     friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
     friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
     
};

bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(t1.tjemena[i]==t2.tjemena[j]) break;
            if(j==2){
                return false;
            }
        }
    }    
    return true;
}    

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
    bool podudarni(false);
    int i,j,k;
    for(i=1; i<4; i++){
        if(Trougao::JesuLiJednaki(t1.DajStranicu(1),t2.DajStranicu(i))) break;
        if(i==3) return podudarni;
    }
    
    for(j=1; j<4; j++){
        if(Trougao::JesuLiJednaki(t1.DajStranicu(2),t2.DajStranicu(j)) && j!=i) break;
        if(j==3) return podudarni;
    }
    
    for(k=1; k<4; k++){
        if(Trougao::JesuLiJednaki(t1.DajStranicu(3),t2.DajStranicu(k)) && k!=j && k!=i) break;
        if(k==3) return podudarni;
    }
    
    if(Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))==Trougao::Orijentacija(t2.DajTjeme(i), t2.DajTjeme(j), t2.DajTjeme(k))) podudarni=true;
    return podudarni;
}    


bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
     bool slicni=false;
    int i,j,k;
    for(i=1; i<4;i++){
        if(Trougao::JesuLiJednaki(t1.DajUgao(1),t2.DajUgao(i))) break;
        if (i==3) return slicni;
    }
    for(j=1; j<4; j++){
        if(Trougao::JesuLiJednaki(t1.DajUgao(2),t2.DajUgao(j)) && j!=i) break;
        if(j==3) return slicni;
    }
    for(k=1; k<4; k++){
        if(Trougao::JesuLiJednaki(t1.DajUgao(3),t2.DajUgao(k)) && k!=i && k!=j) break;
        if(k==3) return slicni;
    }    
    //provjera orijentacije uglova t1 i orijentacije njima podudarnih uglova
    if(Trougao::Orijentacija(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3))== Trougao::Orijentacija(t2.DajTjeme(i), t2.DajTjeme(j), t2.DajTjeme(k))) slicni=true;

    return slicni;
}

int main (){
    int n;
    std::cout<<"Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    std::vector<std::shared_ptr<Trougao>> trouglovi(n);
    for(int i=0; i<n; i++){
        double x1,y1,x2,y2,x3,y3;
        std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
        Tacka niz[3];
        niz[0]=std::make_pair(x1,y1);
        niz[1]=std::make_pair(x2,y2);
        niz[2]=std::make_pair(x3,y3);
        try{
            std::shared_ptr<Trougao> p(new Trougao(niz[0],niz[1],niz[2]));
            trouglovi[i]=p;
        }catch(std::domain_error Izuzetak){
            std::cout<<Izuzetak.what()<<","<<" ponovite unos!"<<std::endl;
            i--;
        }    
}
        
        
        std::cout<<"Unesite vektor translacije (dx dy): ";
        double dx,dy;
        std::cin>>dx>>dy;
        std::transform(trouglovi.begin(), trouglovi.end(), trouglovi.begin(), [dx,dy](std::shared_ptr<Trougao> x) {
            (*x.get()).Transliraj(dx,dy);
            return x;
        });
        
        
        std::cout<<"Unesite ugao rotacije: ";
        double ugao;
        std::cin>>ugao;
        std::transform(trouglovi.begin(), trouglovi.end(), trouglovi.begin(), [ugao](std::shared_ptr<Trougao> x){
            (*x.get()).Rotiraj(ugao);
            return x;
        });
        
       
        std::cout<<"Unesite faktor skaliranja: "; 
        double faktor;
        std::cin>>faktor;
        std::transform(trouglovi.begin(), trouglovi.end(), trouglovi.begin(), [faktor] (std::shared_ptr<Trougao> x){
            (*x.get()).Skaliraj((*x.get()).DajTjeme(1), faktor);
            return x;
        });
        
        std::sort(trouglovi.begin(), trouglovi.end(), [] (std::shared_ptr<Trougao> x, std::shared_ptr<Trougao> y) {
            if((*x.get()).DajPovrsinu()<(*y.get()).DajPovrsinu()) return true;
            else return false;
        });
        
        std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
        
        std::for_each(trouglovi.begin(),trouglovi.end(),[](std::shared_ptr<Trougao> x) {
            (*x).Ispisi();
            std::cout<<std::endl;
        });
        
        auto min_obim=min_element(trouglovi.begin(), trouglovi.end(), [](std::shared_ptr<Trougao>x, std::shared_ptr<Trougao> y) {
            if((x->DajObim())<(y->DajObim())) return true;
            else return false;
        });
        std::cout<<"Trougao sa najmanjim obimom: ";
        (*min_obim)->Ispisi(); 
        
        bool identicni(false);
        bool slicni(false);
        bool podudarni(false);
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(DaLiSuIdenticni( (*trouglovi[i]), (*trouglovi[j]))) identicni=true;
                if(DaLiSuPodudarni((*trouglovi[i]), (*trouglovi[j])))  podudarni=true;
                if(DaLiSuSlicni((*trouglovi[i]), (*trouglovi[j])))     slicni=true;
                } 
            }
            
         
        
      
            if(identicni){
                std::cout<<std::endl<<"Parovi identicnih trouglova:"<<std::endl;
               for(int i=0; i<n-1; i++){
                  for(int j=i+1; j<n; j++){
                    if(DaLiSuIdenticni( (*trouglovi[i]), (*trouglovi[j]))) {
                        (trouglovi[i])->Ispisi(); std::cout<<" i "; (trouglovi[j])->Ispisi();
                       std::cout<<std::endl;
                    }
               }
            }
            }
            else std::cout<<std::endl<<"Nema identicnih trouglova!"<<std::endl;
        
        if(podudarni){
            std::cout<<"Parovi podudarnih trouglova:"<<std::endl;
              for(int i=0; i<n-1; i++){
                for(int j=i+1; j<n; j++){
                    if(DaLiSuPodudarni( (*trouglovi[i]), (*trouglovi[j]))) {
                        (trouglovi[i])->Ispisi(); std::cout<<" i "; (trouglovi[j])->Ispisi();
                       std::cout<<std::endl;
                    }
                }
            }
        }
        else std::cout<<"Nema podudarnih trouglova!"<<std::endl;
        
        if(slicni){
            std::cout<<"Parovi slicnih trouglova:"<<std::endl;
              for(int i=0; i<n-1; i++){
                for(int j=i+1; j<n; j++){
                    if(DaLiSuSlicni( (*trouglovi[i]), (*trouglovi[j]))) {
                        (trouglovi[i])->Ispisi(); std::cout<<" i "; (trouglovi[j])->Ispisi();
                       std::cout<<std::endl;
                    }
                }
            }
        }
        else std::cout<<"Nema slicnih trouglova!";
       
        
        
        
    
    
    
	return 0;
}