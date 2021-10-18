/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <stdexcept>
#include <utility>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>

typedef std::pair<double, double> Tacka;

class Trougao{
    Tacka A;
    Tacka B;
    Tacka C;
    
    static double duzina_stranice(const Tacka &t1, const Tacka &t2){
        return(sqrt(pow(t1.first-t1.second,2))+pow(t2.first-t2.second,2));
    }
    
    static double izraz(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        return (t2.second-t3.second)*t1.first+(t1.second-t3.second)*t2.first+(t1.second-t2.second)*t3.first;
    }
    
    
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        
        if (Orijentacija(t1, t2, t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        A=t1;
        B=t2;
        C=t3;
        
    }
    
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if (Orijentacija(t1, t2, t3)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
        A=t1;
        B=t2;
        C=t3;
    }
    
    void Postavi (int indeks, const Tacka &t){
        if (indeks!=1||indeks!=2||indeks!=3) throw std::range_error("Nekorektan indeks");
        
        if (indeks==1) {
                if (Orijentacija(t, B, C)==0) throw std::domain_error ("Nekorektne pozicije tjemena");
                A=t;}
            
        if (indeks==2) {
                 if (Orijentacija(A, t, C)==0) throw std::domain_error("Nekorektne pozicije tjemena");
                 B=t;}
                 
        if (indeks==3) {
                 if (Orijentacija(A, B, t)==0) throw std::domain_error("Nekorektne pozicije tjemena");
                C=t;}
    }
    
    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double i(izraz(t1, t2, t3));
        if(i>0) return 1;
        if(i<0) return -1;
        if(i==0) return 0;
    }
    
    Tacka DajTjeme(int indeks) const{
        if (indeks==1) return A;
        if (indeks==2) return B;
        if (indeks==3) return C;
    
    }
    
    double DajStranicu (int indeks) const{
        
        if (indeks!=1||indeks!=2||indeks!=3) throw std::range_error("Nekorektan indeks");
        
        if (indeks==1){
            return duzina_stranice(B, C);
        }
        if (indeks==2){
            return duzina_stranice(A, C);
        } 
        if (indeks==3){
            return duzina_stranice(A, B);
        }
    }
    
    double DajUgao(int indeks) const{
        if (indeks!=1||indeks!=2||indeks!=3) throw std::range_error("Nekorektan indeks");
        if (indeks==1) {
            return acos((duzina_stranice(A,B)*duzina_stranice(A,B)+duzina_stranice(A,C)*duzina_stranice(A,C)-duzina_stranice(B,C)*duzina_stranice(B,C))/2*duzina_stranice(A,C)*duzina_stranice(A,B));
        }
        if (indeks==2) {
            return acos((duzina_stranice(A,B)*duzina_stranice(A,B)+duzina_stranice(B,C)*duzina_stranice(B,C)-duzina_stranice(A,C)*duzina_stranice(A,C))/2*duzina_stranice(A,B)*duzina_stranice(B,C));
        }
        if (indeks==3) {
            return acos((duzina_stranice(B,C)*duzina_stranice(B,C)+duzina_stranice(A,C)*duzina_stranice(A,C)-duzina_stranice(A,B)*duzina_stranice(A,B))/2*duzina_stranice(B,C)*duzina_stranice(A,C));
        }

    }
    
    Tacka DajCentar() const{
        Tacka T;
        T.first=(A.first+B.first+C.first)/3;
        T.second=(A.second+B.second+C.second)/3;
        return T;
    }
    
    double DajObim() const{
        return duzina_stranice(A,B)+duzina_stranice(B,C)+duzina_stranice(A,C);
    }
    
    double DajPovrsinu() const{
        return 0.5*fabs(izraz(A,B,C));
    }
    
    bool DaLiJePozitivnoOrijentiran() const{
        if (Orijentacija(A, B, C)==1) return 1;
        else return 0;
    }
    
    bool DaLiJeUnutra (const Tacka &t) const{
        if(Orijentacija(A,B,C)==Orijentacija(A,B,t)&&Orijentacija(A,B,t)==Orijentacija(B,C,t)&&Orijentacija(B,C,t)==Orijentacija(C,A,t)) return 1;
        else return 0;
    }
    
    void Ispisi() const{
        std::cout<<"(("<<A.first<<","<<A.second<<"),("<<B.first<<","<<B.second<<"),("<<C.first<<","<<C.second<<"))";
    }
    
    void Transliraj(double delta_x, double delta_y){
        A.first=A.first+delta_x;
        B.first=B.first+delta_x;
        C.first=C.first+delta_x;
        
        A.second=A.second+delta_y;
        B.second=B.second+delta_y;
        C.second=C.second+delta_y;
        
    }
    
    void Centriraj(const Tacka &t){
        Tacka teziste_1(DajCentar());
        
    }
    
    void Rotiraj(const Tacka &t, double ugao){
        A.first=(t.first+(A.first-t.first)*cos(ugao)-(A.second-t.second)*sin(ugao));
        A.second=(t.second+(A.first-t.first)*sin(ugao)-(A.second-t.second)*cos(ugao));
        B.first=(t.first+(B.first-t.first)*cos(ugao)-(B.second-t.second)*sin(ugao));
        B.second=(t.second+(B.first-t.first)*sin(ugao)-(B.second-t.second)*cos(ugao));
        C.first=(t.first+(C.first-t.first)*cos(ugao)-(C.second-t.second)*sin(ugao));
        C.second=(t.second+(C.first-t.first)*sin(ugao)-(C.second-t.second)*cos(ugao));
    }
    void Skaliraj(const Tacka &t, double faktor){
        if(faktor==0) throw std::domain_error("Nekorektan faktor skaliranja");
        A.first=(t.first+faktor*(A.first-t.first));
        A.second=(t.second+faktor*(A.second-t.second));
        B.first=(t.first+faktor*(B.first-t.first));
        B.second=(t.second+faktor*(B.second-t.second));
        C.first=(t.first+faktor*(C.first-t.first));
        C.second=(t.second+faktor*(C.second-t.second));
    }
    
    void Rotiraj(double ugao){
        
        Rotiraj(DajCentar(), ugao);
    }
    
    void Skaliraj(double faktor){
        Skaliraj(DajCentar(), faktor);
    }
    
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
        
        double tacke_prvog_trougla_x[3];
        double tacke_drugog_trougla_x[3];
        double tacke_prvog_trougla_y[3];
        double tacke_drugog_trougla_y[3];
        
        
        tacke_prvog_trougla_x[0]=t1.A.first;
        tacke_prvog_trougla_x[1]=t1.B.first;
        tacke_prvog_trougla_x[2]=t1.C.first;
        
        tacke_drugog_trougla_x[0]=t2.A.first;
        tacke_drugog_trougla_x[1]=t2.B.first;
        tacke_drugog_trougla_x[2]=t2.C.first;
        
        tacke_prvog_trougla_y[0]=t1.A.second;
        tacke_prvog_trougla_y[1]=t1.B.second;
        tacke_prvog_trougla_y[2]=t1.C.second;
        
        tacke_drugog_trougla_y[0]=t2.A.second;
        tacke_drugog_trougla_y[1]=t2.B.second;
        tacke_drugog_trougla_y[2]=t2.C.second;
 
        std::sort(tacke_prvog_trougla_x, tacke_prvog_trougla_x+3);
        std::sort(tacke_drugog_trougla_x, tacke_drugog_trougla_x+3);
        std::sort(tacke_prvog_trougla_y, tacke_prvog_trougla_y+3);
        std::sort(tacke_drugog_trougla_y, tacke_drugog_trougla_y+3);
        
        for (int i=0; i<3; i++){
            if (tacke_prvog_trougla_x[i]!=tacke_drugog_trougla_x[i]) {
                return false;
            }
        }
        
        for(int i=0; i<3; i++){
            if (tacke_prvog_trougla_y[i]!=tacke_drugog_trougla_y[i]) {
                return false;
            }
        }
        
        return true;
    }
    
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
        double niz_duzina_1[3];
        double niz_duzina_2[3];
        bool podudarni(0);
        
        niz_duzina_1[0]=duzina_stranice(t1.A, t1.B);
        niz_duzina_1[1]=duzina_stranice(t1.B, t1.C);
        niz_duzina_1[2]=duzina_stranice(t1.C, t1.A);
        
        niz_duzina_2[0]=duzina_stranice(t2.A, t2.B);
        niz_duzina_2[1]=duzina_stranice(t2.B, t2.C);
        niz_duzina_2[2]=duzina_stranice(t2.C, t2.A);
        
        for(int i=0; i<3; i++){
            if(niz_duzina_1[i]!=niz_duzina_2[i]) podudarni=0;
        }
        
        if(podudarni==1) return true;
        
        for(int k=0; k<3; k++){
            podudarni=1;
            std::rotate(niz_duzina_2, niz_duzina_2+1, niz_duzina_2+3);
            for(int i=0; i<3; i++){
                if(niz_duzina_1[i]!=niz_duzina_2[i]) podudarni=0;
            }
            
            if(podudarni==1) return true;
            
        }
        
        return false;
        
    }
    
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
        double niz_duzina_1[3];
        double niz_duzina_2[3];
        bool slicni(0);
        
        niz_duzina_1[0]=duzina_stranice(t1.A, t1.B);
        niz_duzina_1[1]=duzina_stranice(t1.B, t1.C);
        niz_duzina_1[2]=duzina_stranice(t1.C, t1.A);
        
        niz_duzina_2[0]=duzina_stranice(t2.A, t2.B);
        niz_duzina_2[1]=duzina_stranice(t2.B, t2.C);
        niz_duzina_2[2]=duzina_stranice(t2.C, t2.A);
        
        if(niz_duzina_1[0]/niz_duzina_2[0]==niz_duzina_1[1]/niz_duzina_2[1]&&niz_duzina_1[1]/niz_duzina_2[1]==niz_duzina_1[2]/niz_duzina_2[2]) return true;
        
        
        
        for(int k=0; k<3; k++){
            
            std::rotate(niz_duzina_2, niz_duzina_2+1, niz_duzina_2+3);
            if(niz_duzina_1[0]/niz_duzina_2[0]==niz_duzina_1[1]/niz_duzina_2[1]&&niz_duzina_1[1]/niz_duzina_2[1]==niz_duzina_1[2]/niz_duzina_2[2]) return true;
            
            
            
        }
        
        return false;
    }



};

int main ()
{
    int n;
    std::cout<<"Unesite broj n: ";
    std::cin>>n;
    std::vector<Trougao*> v(n);
    
    for(int i=0; i<n; i++){
        double A_x, A_y, B_x, B_y, C_x, C_y;
        std::cout<<"Unesite podatke za "<<i+1<<". trougao: ";
        std::cin>>A_x>>A_y;
        std::cin>>B_x>>B_y;
        std::cin>>C_x>>C_y;
        Tacka t1=std::make_pair(A_x, A_y);
        Tacka t2=std::make_pair(B_x, B_y);
        Tacka t3=std::make_pair(C_x, C_y);
        auto p=std::make_shared<Trougao>;
        try{
        *p.Postavi(t1,t2,t3);}
        catch(std::domain_error e){
            std::cout<<e.what();
            i--;
            continue;
        }
        v[i]=p;
    }
    
    double delta_x, delta_y;
    std::cout<<"Unesite podatke za translaciju: ";
    std::cin>>delta_x>>delta_y;
    double ugao;
    std::cout<<"Unesite ugao rotacije: ";
    std::cin>>ugao;
    double faktor;
    std::cout<<"Unesite faktor skaliranja: ";
    std::cin>>faktor;
    transform(v[0],v[n-1],v[0],[delta_x, delta_y](Trougao *t){
        *t.Transliraj(delta_x,delta_y);
    });
    transform(v[0],v[n-1],v[0],[ugao](Trougao *t){
        *t.Rotiraj(t.DajTjeme(1),ugao);
    });
    transform(v[0],v[n-1],v[0],[faktor](Trougao *t){
        *t.Skaliraj(faktor);
    });
    
    sort(v[0],v[n-1],[](Trougao *t1, Trougao *t2){
        return *t1.DajPovrsinu()<*t2.DajPovrsinu();
    });
    
    for_each(v[0], v[n-1], [](Trougao *t){
        *t.Ispisi();
        std::cout<<std::endl;
    });
    
    Trougao *najveci=max_element(v[0], v[n-1], [](Trougao t1, Trougao t2){
        if(*t2.DajObim()<*t1-DajObim()) return true;
    });
	return 0;
}