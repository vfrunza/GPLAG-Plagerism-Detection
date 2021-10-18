/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!

#include <iostream>
#include <exception>
#include <algorithm>
#include <utility>
#include <memory>

using namespace std;
typedef pair < double, double > Tacka ;


class Trougao {
    Tacka tjeme_1;
    Tacka tjeme_2;
    Tacka tjeme_3;
    public:
  
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        
       
        
        if(Orijentacija(t1, t2, t3) == 0) throw domain_error("Nekorektne pozicije tjemena");
        tjeme_1 = t1;
        tjeme_2 = t2;
        tjeme_3 = t3;
    }
    
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
       
        
        if(Orijentacija(t1,t2,t3) == 0) throw domain_error("Nekorektne pozicije tjemena");
        tjeme_1 = t1; 
        tjeme_2 = t2;
        tjeme_3 = t3;
        
    }
    
    void Postavi(int indeks, const Tacka &t){
        if(indeks<1 || indeks>3) throw range_error ("Nekorektan indeks");
        if(indeks==1) tjeme_1 = t;
        else if (indeks==2) tjeme_2 = t;
        else if (indeks==3) tjeme_3 = t;
    }
    
    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(ProvjeraOrijentacije(t1,t2,t3)<0) return -1;
        else if(ProvjeraOrijentacije(t1,t2,t3)>0) return 1;
        else return 0;
        
    }
    
    static double ProvjeraOrijentacije(const Tacka &t1, const Tacka &t2, const Tacka &t3){
      double Orj =(t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second));
        return Orj;
    }
    
    
    Tacka DajTjeme (int indeks) const{
        if(indeks<1 || indeks>3) throw range_error ("Nekorektan indeks");
        if(indeks==1) return tjeme_1;
        else if(indeks==2) return tjeme_2;
        else return tjeme_3;
        
    }
    
    double DajStranicu (int indeks) const{
        if(indeks<1 ||  indeks>3) throw range_error ("Nekorektan indeks");
        if(indeks==1){double d1=sqrt(pow((tjeme_3.first-tjeme_2.first),2)+pow((tjeme_3.second-tjeme_2.second),2)); return d1;}
        else if(indeks==2){double d2=sqrt(pow((tjeme_1.first-tjeme_3.first),2)+pow((tjeme_1.second-tjeme_3.second),2)); return d2;}
        else{double d3=sqrt(pow((tjeme_2.first-tjeme_1.first),2)+pow((tjeme_2.second-tjeme_1.second),2)); return d3;}
    }
    
    double DajUgao (int indeks) const{
        if(indeks<1 ||  indeks>3) throw range_error ("Nekorektan indeks");
        double a=DajStranicu(1);
        double b=DajStranicu(2);
        double c=DajStranicu(3);
        if(indeks==1) {
           double a1=acos((c*c+b*b-(a*a))/(2*b*c)) * 180 / 3.14159265;
            return a1;
        }
           else if(indeks==2){
           double b1=acos((a*a+c*c-(b*b))/(2*a*c)) * 180 / 3.14159265;
               return b1;
           }
           else{
           double c1=acos((a*a+b*b-(c*c))/(2*a*b)) * 180 / 3.14159265;
           return c1;
           }
    }
    
    Tacka DajCentar () const{
        Tacka rezultat;
        rezultat.first=((tjeme_1.first+tjeme_2.first+tjeme_3.first)/3);
        rezultat.second=((tjeme_1.second+tjeme_2.second+tjeme_3.second)/3);
        return rezultat;
    }
    
    double DajObim () const{
        double a=DajStranicu(1);
        double b=DajStranicu(2);
        double c=DajStranicu(3);
        double obim=a+b+c;
        return obim;
    }
    
    double DajPovrsinu () const{
        double povrsina=(1/2*(fabs(ProvjeraOrijentacije(tjeme_1,tjeme_2,tjeme_3))));
        return povrsina;
    }
    bool DaLiJePozitivnoOrijentiran () const{
        if(ProvjeraOrijentacije(tjeme_1, tjeme_2, tjeme_3)>0) return true;
        else return false;
    }
    
    bool DaLiJeUnutra (const Tacka &t) const{
        
              double prvaOr = ProvjeraOrijentacije(tjeme_1, tjeme_2, t);
              double drugaOr = ProvjeraOrijentacije(tjeme_2, tjeme_3, t);
              double trecaOr = ProvjeraOrijentacije(tjeme_3, tjeme_1, t);
              
        if(this -> DaLiJePozitivnoOrijentiran()){      
              if (prvaOr > 0 && drugaOr > 0 && trecaOr > 0) return true;
        }
        
        else if(!(this -> DaLiJePozitivnoOrijentiran())){
            if(prvaOr < 0 && drugaOr < 0 && trecaOr < 0) return true;
        }
        
        return false;
    }
    
    void Ispisi () const{
       cout<<"(("<<tjeme_1.first<<","<<tjeme_1.second<<"),("<<tjeme_2.first<<","<<tjeme_2.second<<"),("<<tjeme_3.first<<","<<tjeme_3.second<<"))";
    }
    
    void Transliraj (double delta_x, double delta_y){
        Tacka novo_t1;
        Tacka novo_t2;
        Tacka novo_t3;
        
        novo_t1.first = tjeme_1.first + delta_x;
        novo_t2.first = tjeme_2.first + delta_x;
        novo_t3.first = tjeme_3.first + delta_x;
        
        novo_t1.second = tjeme_1.second + delta_y;
        novo_t2.second = tjeme_2.second + delta_y;
        novo_t3.second = tjeme_3.second + delta_y;
        
        tjeme_1 = novo_t1;
        tjeme_2 = novo_t2;
        tjeme_3 = novo_t3;
    }
    
    void Centriraj (const Tacka &t){
        Tacka Centar = this -> DajCentar();
        double delta_x = t.first - Centar.first;
        double delta_y = t.second - Centar.second;
        
        this -> Transliraj(delta_x, delta_y);
    }
    
    void Rotiraj (const Tacka &t, double ugao){
         tjeme_1 = rotirajTacku(tjeme_1, t, ugao);
         tjeme_2 = rotirajTacku(tjeme_2, t, ugao);
         tjeme_3 = rotirajTacku(tjeme_3, t, ugao);
    }
    
    void Skaliraj (const Tacka &t, double faktor){
        tjeme_1 = skalirajTacku(tjeme_1, t, faktor);
        tjeme_2 = skalirajTacku(tjeme_2, t, faktor);
        tjeme_3 = skalirajTacku(tjeme_3, t, faktor);
    }
    
    void Rotiraj(double ugao){
        Tacka centar = this -> DajCentar();
        
        tjeme_1 = rotirajTacku(tjeme_1, centar, ugao);
        tjeme_2 = rotirajTacku(tjeme_2, centar, ugao);
        tjeme_3 = rotirajTacku(tjeme_3, centar, ugao);
    }
    
    void Skaliraj(double faktor){
        Tacka centar = this -> DajCentar();
        
        
        tjeme_1 = skalirajTacku(tjeme_1, centar, faktor);
        tjeme_2 = skalirajTacku(tjeme_2, centar, faktor);
        tjeme_3 = skalirajTacku(tjeme_3, centar, faktor);
    }
    
    friend bool DaLiSuIdenticni ( const Trougao &t1, const Trougao &t2){
        
        if( ( JednakeTacke(t1.DajTjeme(1), t2.DajTjeme(1)) || JednakeTacke(t1.DajTjeme(1), t2.DajTjeme(2)) || JednakeTacke(t1.DajTjeme(1), t2.DajTjeme(3)) )
            && ( JednakeTacke(t1.DajTjeme(2), t2.DajTjeme(1)) || JednakeTacke(t1.DajTjeme(2), t2.DajTjeme(2)) || JednakeTacke(t1.DajTjeme(2), t2.DajTjeme(3)) )
            && ( JednakeTacke(t1.DajTjeme(3), t2.DajTjeme(1)) || JednakeTacke(t1.DajTjeme(3), t2.DajTjeme(2)) || JednakeTacke(t1.DajTjeme(3), t2.DajTjeme(3)) )
            ) return true;
        else return false;
    }
    
    friend bool DaLiSuPodudarni ( const Trougao &t1, const Trougao &t2){
        int counter = 0;
        double Ugao = 0.5; 
        Tacka noviCentar(100,100);
        
        Trougao nov_t1(t1.DajTjeme(1), t1.DajTjeme(2), t1.DajTjeme(3));
        Trougao nov_t2(t2.DajTjeme(1), t2.DajTjeme(2), t2.DajTjeme(3)); 
        
        nov_t1.Centriraj(noviCentar);
        nov_t2.Centriraj(noviCentar);
        
        do{
            nov_t2.Rotiraj(Ugao);
            Ugao += 0.5;
            counter ++;
        }while(DaLiSuIdenticni(t1, t2) == false && counter < 720);
        
        if(DaLiSuIdenticni(nov_t1,nov_t2)) return true;
        else return false;
    }
    
    friend bool DaLiSuSlicni (const Trougao &t1, const Trougao &t2){
        double stranica1, stranica2, stranica3;
         stranica1 = t1.DajStranicu(1);
         stranica2 = t1.DajStranicu(2);
         stranica3 = t1.DajStranicu(3);
         
         long double stranice1[3] = {stranica1, stranica2, stranica3};
         sort(stranice1, stranice1+3);
         
         double stranica4, stranica5, stranica6;
         stranica4 = t2.DajStranicu(1);
         stranica5 = t2.DajStranicu(2);
         stranica6 = t2.DajStranicu(3);
         
         long double stranice2[3] = {stranica4, stranica5, stranica6};
         sort(stranice2, stranice2+3);
         
         if( Jednaki(stranice1[0] * stranice2[1], stranice2[0] * stranice1[1]) 
            && Jednaki(stranice1[2]*stranice2[1], stranice2[2] * stranice1[1]))
            return true;
        return false;
    }
    
    private:
        
        static bool Jednaki(double a, double b){
            double y = 0.0000000001;
            
            if((a-b) < y) return true;
            else return false;
        }
        
        static bool JednakeTacke(const Tacka &t1, const Tacka &t2)
        {
            if(Jednaki(t1.first, t2.first) && Jednaki(t1.second, t2.second)) return true;
            return false;
        }
        
        static Tacka rotirajTacku(Tacka &zaRot, const Tacka &t, double ugao1)
        {
            Tacka rez;
            double ugao = (ugao1 * 3.14159265 / 180);
            
            rez.first = t.first + (zaRot.first - t.first) * cos(ugao) - (zaRot.second - t.second) * sin(ugao);
            rez.second = t.second + (zaRot.first - t.first) * sin(ugao) + (zaRot.second - t.second) * cos(ugao);
            
            return rez; 
        }
        
        static Tacka skalirajTacku(Tacka &zaSkal, const Tacka &t, double faktor)
        {
            Tacka rez;
            
            rez.first = t.first + (faktor * (zaSkal.first - t.first));
            rez.second = t.second + (faktor * (zaSkal.second - t.second));
            
            
            
            return rez;
        }
    
};

int main ()
{/*
    cout<<"Koliko zelite kreirati trouglova: ";
    int broj_trouglova;
    cin>>broj_trouglova;
    
    
        vector<shared_ptr<Trougao>> p(broj_trouglova, nullptr);
        Tacka t1, t2, t3;
         
         int i=0;
         while(i<broj_trouglova){
             cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
             cin>>t1.first>>t1.second>>t2.first>>t2.second>>t3.first>>t3.second;
             try{
                 p[i]=shared_ptr<Trougao>(new Trougao (t1,t2,t3));}
                 catch(domain_error e){
                     cout<<e.what()<<endl;
                     i++;
                 }
         
                 i++;
             }
    
    
    cout<<"Unesite vektor translacije (dx dy): ";
    double deltaX,deltaY, faktor_skaliranja, ugao_rotacije;
    cin>>deltaX>>deltaY;
    cout<<"Unesite ugao rotacije: ";
    cin>>ugao_rotacije;
    cout<<"Unesite faktor skaliranja: ";
    cin>>faktor_skaliranja;
    
    transform(p.begin(), p.end(),p.begin(), [deltaX,deltaY,ugao_rotacije,faktor_skaliranja](const shared_ptr<Trougao> &tro1){
                                                    tro1 -> Transliraj(deltaX, deltaY);
                                                    tro1 -> Rotiraj(ugao_rotacije);
                                                    tro1 -> Skaliraj(tro1->DajTjeme(1), faktor_skaliranja);
                                                    return tro1;
                                                });
    sort(p.begin(),p.end(),[](const shared_ptr<Trougao> &tro1, const shared_ptr<Trougao> &tro2){
                                                    return tro1 -> DajPovrsinu() < tro2 -> DajPovrsinu();
                                                });
    auto min (*min_element(p.begin(), p.end(), [](const shared_ptr<Trougao> &tro1, const shared_ptr<Trougao> &tro2){
                                                    return tro1 -> DajObim() < tro2 -> DajObim();
                                                })) ;
    
    cout << "Trouglovi nakon obavljenih transformacija: " << endl;
                  
    for_each(p.begin(), p.end(), [](const shared_ptr<Trougao> &tro1){
                                                    tro1 -> Ispisi();
                                                    cout << endl;
                                                });
                                                
    cout << "Trougao sa najmanjim obimom: ";
    min -> Ispisi(); 
    cout << endl;
    
    cout << "Parovi identicnih trouglova: " << endl;
    for(int i = 0; i < p.size(); i++)
    {
        for(int j = i+1; j < p.size(); j++)
        {
            if(DaLiSuIdenticni(*const_cast<Trougao*>(p[i].get()), *const_cast<Trougao*>(p[j].get())))
            {
                p[i] -> Ispisi();
                cout << " i ";
                p[j] -> Ispisi();
                cout << endl;
            }
        }
    }
                                                
    cout << "Parovi podudarnih trouglova: " << endl;
    for(int i = 0; i < p.size(); i++)
    {
        for(int j = i+1; j < p.size(); j++)
        {
            if(DaLiSuPodudarni(*const_cast<Trougao*>(p[i].get()), *const_cast<Trougao*>(p[j].get())))
            {
                p[i] -> Ispisi();
                cout << " i ";
                p[j] -> Ispisi();
                cout << endl;
            }
        }
    }
    
    cout << "Parovi slicnih trouglova: " << endl;
    for(int i = 0; i < p.size(); i++)
    {
        for(int j = i+1; j < p.size(); j++)
        {
            if(DaLiSuSlicni(*const_cast<Trougao*>(p[i].get()), *const_cast<Trougao*>(p[j].get())))
            {
                p[i] -> Ispisi();
                cout << " i ";
                p[j] -> Ispisi();
                cout << endl;
            }
        }
    }
    */
    
	return 0;
}