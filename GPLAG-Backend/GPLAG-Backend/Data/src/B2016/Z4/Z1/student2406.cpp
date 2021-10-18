#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <string>
#include <cmath>         
#include <algorithm>
#include <stdexcept>          
#include <memory>           

const double PI{4*atan(1)};
typedef std::pair<double,double> Tacka;

class Trougao
{         
    std::vector<Tacka>trougao;         
    Tacka T1,T2,T3;
    
public:    
       
      static double DaLiSuJednaki(double x,double y,double eps=1e-10) {
        return std::fabs(x-y)<=eps*(std::fabs(x)+std::fabs(y));
    }     
                                          
    friend bool DaLiSuSlicni(const Trougao &tro1,const Trougao &tro2);
    friend bool DaLiSuPodudarni(const Trougao &tro_1,const Trougao &tro_2);
    friend bool DaLiSuIdenticni(const Trougao &tro1,const Trougao &tro_2);

    Trougao(const Tacka &t1,const Tacka &t2, const Tacka &t3) {
        try {
            if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
            trougao.push_back(t1); T1=t1;
            trougao.push_back(t2); T2=t2;
            trougao.push_back(t3); T3=t3;
        } 
        catch(std::domain_error e) {                 
            throw;
        }       
    }
   /*void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        if(Orijentacija(t1,t2,t3)==0) throw std::domain_error("Nekorektne pozicije tjemena");
                auto it(trougao.begin());
        while(it!=trougao.end()) {
            trougao.erase(it);
            trougao.insert(it,t);
        }
        T1=t1; T2=t2; T3=t3;
    }*/
    void Postavi(int indeks, const Tacka &t) {
        if(indeks<1||indeks>3) throw std::range_error("Nekorektan indeks");
        auto it(trougao.begin());
    if(indeks==1){
        trougao.erase(it);
            trougao.insert(it,t);}
            if(indeks==2){
                it++; trougao.erase(it);
            trougao.insert(it,t);}
    if(indeks==3){
        it=trougao.end()-1;
        trougao.erase(it);
            trougao.insert(it,t);
    }
        if(indeks==1) T1=t;
        if(indeks==2) T2=t;
        if(indeks==3) T3=t;                    
        
    }
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3) {
        int x;
        if((t1.first*(t2.second-t3.second)+t2.first*(t2.second-
                t3.second)+t3.first*(t1.second-t2.second))>0) x=1;
        if((t1.first*(t2.second-t3.second)+t2.first*(t2.second-
                t3.second)+t3.first*(t1.second-t2.second))<0) x=-1;
        if(DaLiSuJednaki((t1.first*(t2.second-t3.second)+t2.first*(t2.second-
                          t3.second)+t3.first*(t1.second-t2.second)),0)) x=0;
        return x;
    }
   
    double DajStranicu(int indeks) const {
        double x(0);
        try {
            if(indeks==1) {
                x=sqrt(pow((T3.first-T2.first),2)
                       +pow((T3.second-T2.second),2));
            }
            if(indeks==2) {
                x=sqrt(pow((T3.first-T1.first),2)
                       +pow((T3.second-T1.second),2));
            }
            if(indeks==3) {
                x=sqrt(pow((T2.first-T1.first),2)
                       +pow((T2.second-T1.second),2));
            }
        } catch(std::domain_error e) {
            throw;
        }
        return x;
    }

    double DajUgao(int indeks) const {
        double x(0);
        double str1(DajStranicu(1)), str2(DajStranicu(2)),str3(DajStranicu(3));
        if(indeks==1) {
            x=acos((pow(str2,2)+pow(str3,2)-pow(str1,2))/(2*str2*str3));
        }
        if(indeks==2) {
            x=acos((pow(str1,2)+pow(str3,2)-pow(str2,2))/(2*str3*str1));
        }
        if(indeks==3) {
            x=acos((pow(str1,2)+pow(str2,2)-pow(str3,2))/(2*str1*str2));
        }
        return x;
    }

    void Ispisi() const {
        std::cout<<"(";
            
    for (auto it(trougao.begin()); it!=trougao.end();++it )
{   bool prvi(true);
std::cout<<"("<<it->first<<","<<it->second<<")";  
            if(it==trougao.end()-1) prvi=false;

        else std::cout<<",";
}
        std::cout<<")"<<std::endl;

    }

    double DajObim() const {
        double str1(DajStranicu(1)), str2(DajStranicu(2)), str3(DajStranicu(3));
        return str1+str2+str3;
    }

    double DajPovrsinu() const {
            return fabs((T1.first*(T2.second-T3.second)-T2.first*(T1.second-T3.second)+T3.first*(T1.second-T2.second))/2);
        
    }

     Tacka  DajTjeme(int indeks) const {
        Tacka T;
        if(indeks==1) T=T1;
        if(indeks==2) T=T2;
        if(indeks==3) T=T3;
        return T;
    }

    Tacka DajCentar() const {
        Tacka T=std::make_pair((T1.first+T2.first+T3.first)/3,(T1.second+T2.second+T3.second)/3);
        return T;
    }
    bool DaLiJePozitivnoOrjentiran()const {
        bool x(true);
        if(Orijentacija(T1,T2,T3)==0) x=false;
        return x;
    }

    bool DaLiJeUnutra(const Tacka &t) const {
        bool x(false);
        if((Orijentacija(T1,T2,T3)==1&&Orijentacija(T1,T2,t)==1&&Orijentacija(T2,T3,t)==1&&Orijentacija(T3,T1,t)==1)||
                (Orijentacija(T1,T2,T3)==-1&&Orijentacija(T1,T2,t)==-1&&Orijentacija(T2,T3,t)==-1&&Orijentacija(T3,T1,t)==-1)) {
            x=true;
        }
        return x;
    }              

    void Transliraj(double delta_x,double delta_y) {
            T1.first+=delta_x; T1.second+=delta_y;
            T2.first+=delta_x; T2.second+=delta_y;
           T3.first+=delta_x; T3.second+=delta_y;  
}
    void Centriraj(const Tacka &t) {       
        Tacka srediste(DajCentar()); 
        double x(t.first-srediste.first), y(t.second-srediste.second);
        Transliraj(x,y);

    }

    void Rotiraj(const Tacka &t,double ugao) {
                   Tacka T; 
                for(int i(1);i<=3;i++){
                    T=DajTjeme(i);
                        for(auto it(trougao.begin());it!=trougao.end();it++){
                *it=((std::make_pair((t.first+(T.first-t.first)*cos(ugao)-(T.second-t.second)*sin(ugao)),(t.second+(T.first-t.first)*sin(ugao)+(T.second -t.second)*cos(ugao)))));
            }
        }
    }
    void Rotiraj(double ugao) {
        Tacka t(DajCentar().first,DajCentar().second);
        Tacka T; 
        for(int i(1);i<=3;i++){
            T=DajTjeme(i); 
            for(auto it(trougao.begin());it!=trougao.end();it++){
            *it=(std::make_pair(t.first+(T.first-t.first)*cos(ugao)-(T.second-t.second)*sin(ugao),(t.second+(T.first-t.first)*sin(ugao)+(T.second -t.second)*cos(ugao))));
          
            }
        }
    }

    void Skaliraj(const Tacka &t, double faktor) {
        try { 
            if(DaLiSuJednaki(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja!");
            Tacka T;
            for(int i(1); i<=3;i++) {
                T=DajTjeme(i);
                for(auto it(trougao.begin());it!=trougao.end();it++){
                    *it=(std::make_pair(t.first+faktor*(T.first-t.first),t.second+faktor*(T.second-t.second)));
                }
            }
        } catch(std::domain_error e) {
            throw;
        }

    }
    
   void Skaliraj(double faktor) {
        try {
            if(DaLiSuJednaki(faktor,0)) throw std::domain_error("Nekorektan faktor skaliranja!");
            if(faktor<0) Rotiraj(PI);
            Tacka t(DajCentar().first,DajCentar().second),T; 
            for(int i(1); i<=3; i++) {
                 T=DajTjeme(i);
                 for(auto it(trougao.begin());it!=trougao.end();it++){
                    *it=(std::make_pair(faktor*T.first,faktor*T.second));
                    
                 }
            }
        } catch(std::domain_error e) {
            throw;
        }
    }
};

bool DaLiSuIdenticni(const Trougao &tro1,const Trougao &tro2)
{
    bool x(false);
    for(int i(1); i<=3; i++) {
        Tacka Tjeme_1(tro1.DajTjeme(i));
        for(int j(1); j<=3; i++) {
            Tacka Tjeme_2(tro2.DajTjeme(j));
            if(Trougao::DaLiSuJednaki(Tjeme_1.first,Tjeme_2.first)&&Trougao::DaLiSuJednaki(Tjeme_1.second,Tjeme_2.second)) x=true;
        }
    }
    return x;
}

bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
bool x(false); 
double str1(t1.DajStranicu(1)),str2(t1.DajStranicu(2)),str3(t1.DajStranicu(3)),str_1(t2.DajStranicu(1)),str_2(t2.DajStranicu(2)),str_3(t2.DajStranicu(3));
	    if(Trougao::DaLiSuJednaki(str1/str_1,str2/str_2)&&Trougao::DaLiSuJednaki(str3/str_3,str1/str_1)) x=true;
	    
	return x;                     
}

bool DaLiSuPodudarni(const Trougao &tro_1,const Trougao &tro_2)
{
    bool x(false);
    for(int i(1); i<=3; i++) {
        if(Trougao::DaLiSuJednaki(tro_1.DajStranicu(i),tro_2.DajStranicu(i))) x=true;
    }
    return x;
}

int main()
{
    try {
        std::cout<<"Koliko zelite kreirati trouglova: ";
        int n;
        std::cin>>n;
        while(!(std::cin)) {
            std::cin.ignore(10000,'\n');
            std::cin.clear();
            std::cout<<"Pogresan unos, ponovite: ";
            std::cin>>n;
        }
        std::vector<std::shared_ptr<Trougao>> v(n);

        for(int i(0); i<n; i++) {
            std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x2 y3): ";
            Tacka T1,T2,T3;
            std::cin>>T1.first>>T1.second>>T2.first>>T2.second>>T3.first>>T3.second;
    double JARAN(fabs((T1.first*(T2.second-T3.second)-T2.first*(T1.second-T3.second)+T3.first*(T1.second-T2.second))/2)); //JARAN provjerava da li su tacke kolinearne
            while(!(std::cin)||Trougao::DaLiSuJednaki(JARAN,0)) {
                std::cout<<"Nekorektne pozicije tjemena, ponovite unos"<<std::endl;
                std::cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x2 y3): ";
                std::cin>>T1.first>>T1.second>>T2.first>>T2.second>>T3.first>>T3.second;
                JARAN=fabs((T1.first*(T2.second-T3.second)-T2.first*(T1.second-T3.second)+T3.first*(T1.second-T2.second))/2);
            }
            std::shared_ptr<Trougao> p(new Trougao(T1,T2,T3));             
            v[i]=p;
        }                                                             
        double delta_x,delta_y;
        std::cout<<"Unesite vektor translacije (dx dy): ";
        std::cin>>delta_x>>delta_y;
        std::transform(v.begin(),v.end(),v.begin(),[delta_x,delta_y](std::shared_ptr<Trougao> pok) {
            pok->Transliraj(delta_x,delta_y);
            return pok;
        });
        std::cout<<"Unesite ugao rotacije: ";
        double ugao;
        std::cin>>ugao;
        std::transform(v.begin(),v.end(),v.begin(),[ugao](std::shared_ptr<Trougao>pok) {
            pok->Rotiraj(ugao);
            return pok;
        });
        std::cout<<"Unesite faktor skaliranja: ";
        double faktor;
        std::cin>>faktor;
        std::transform(v.begin(),v.end(),v.begin(),[faktor](std::shared_ptr<Trougao>pok) {
            pok->Skaliraj(faktor);
            return pok;
        });
        std::sort(v.begin(),v.end(),[](std::shared_ptr<Trougao>p,std::shared_ptr<Trougao> p1) {
            return p->DajPovrsinu()< p1->DajPovrsinu();
        });
std::cout<<"Trouglovi nakon obavljenih transformacija: "<<std::endl;
        std::for_each(v.begin(),v.end(),[](std::shared_ptr<Trougao>pok) {
            pok->Ispisi();
        });

        std::cout<<"Trougao sa najmanjim obimom: ";
         auto p=std::min_element(v.begin(),v.end(),[](std::shared_ptr<Trougao>p1,std::shared_ptr<Trougao>p2){
             	return p1->DajObim()< p2->DajObim();});
         std::shared_ptr<Trougao>pomocni;
         (*p)->Ispisi();
         
         std::cout<<"Parovi identicnih trouglova: "<<std::endl;
       /*  auto it(v.begin());
         auto it1(v.begin()+1);
while(it1!=v.end()){
                 if(DaLiSuIdenticni(**it,**it1)){
            (*it)->Ispisi(); std::cout<<" i ";(*it1)->Ispisi();
            }
            it++; it1++;
    }*/
         std::cout<<"Parovi podudarnih trouglova: "<<std::endl;
          /*it=v.begin();
          it1=v.begin()+1;
         while(it1!=v.end()){
                 if(DaLiSuPodudarni(**it,**it1)){
            (*it)->Ispisi(); std::cout<<" i ";(*it1)->Ispisi();
            }
            it++; it1++;
    }*/
 std::cout<<"Parovi slicnih trouglova: "<<std::endl;
    /*  auto it2=v.begin();
         auto it3=v.begin()+1;
         while(it3!=v.end()){
                 if(DaLiSuSlicni(**it2,**it3)){
            (*it2)->Ispisi(); std::cout<<" i ";(*it3)->Ispisi();
            }
            it++; it1++;
    }
    */
    }  
    
    catch(std::domain_error e) {
        std::cout<<e.what();
    }
    catch(std::range_error e) {
        std::cout<<e.what();
    }

    return 0;
}
