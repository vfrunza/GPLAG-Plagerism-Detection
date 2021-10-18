/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <cstdio>
#include <utility>
#include <stdexcept>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <memory>
#include <algorithm>
#define PI 3.14159265359

const double Eps(1e-10);
typedef std::pair<double,double> Tacka;

class Trougao{
    Tacka a,b,c;
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
        else {a=t1;b=t2;c=t3;}  
    };
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0)throw std::domain_error("Nekorektne pozicije tjemena");
        else {a=t1;b=t2;c=t3;}  
    };
    void Postavi(int index,const Tacka &t){
        if(index==1){if(Orijentacija(t,b,c)==0)throw std::domain_error("Nekorektne pozicije tjemena");a.first=t.first; a.second=t.second;}
        if(index==2){if(Orijentacija(a,t,c)==0)throw std::domain_error("Nekorektne pozicije tjemena");b.first=t.first; b.second=t.second;}
        if(index==3){if(Orijentacija(a,b,t)==0)throw std::domain_error("Nekorektne pozicije tjemena");c.first=t.first; c.second=t.second;}
        else throw std::range_error("Nekorektan indeks");
    };
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    };
    Tacka DajTjeme(int indeks) const{if(indeks==1)return a; if(indeks==2)return b; if(indeks==3) return c; };
    double DajStranicu(int indeks) const{
        if(indeks==1) return sqrt(pow((b.first-c.first),2)+pow((b.second-c.second),2));
        if(indeks==2) return sqrt(pow((a.first-c.first),2)+pow((a.second-c.second),2));
        if(indeks==3) return sqrt(pow((a.first-b.first),2)+pow((a.second-b.second),2));
    };
    double DajUgao(int indeks) const{
        if(indeks==1){double broj=(pow(DajStranicu(2),2)+pow(DajStranicu(3),2)-pow(DajStranicu(1),2))/2*DajStranicu(2)*DajStranicu(3); double ugao=acos(broj); return ugao*(PI/180);}
        if(indeks==2){double broj=(pow(DajStranicu(1),2)+pow(DajStranicu(3),2)-pow(DajStranicu(2),2))/2*DajStranicu(1)*DajStranicu(3); double ugao=acos(broj); return ugao*(PI/180);}
        if(indeks==1){double broj=(pow(DajStranicu(2),2)+pow(DajStranicu(1),2)-pow(DajStranicu(3),2))/2*DajStranicu(2)*DajStranicu(1); double ugao=acos(broj); return ugao*(PI/180);}
    };
    Tacka DajCentar() const{
        Tacka centar;
        centar.first=(a.first+b.first+c.first)/3;
        centar.second=(a.second+b.second+c.second)/3;
        return centar;
    };
    double DajObim() const{
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    };
    double DajPovrsinu() const{
        return fabs(a.first*(b.second-c.second)-b.first*(a.second-c.second)+c.first*(a.second-b.second))/2;
    };
    bool DaLiJePozitivnoOrijentiran() const{
        if(Orijentacija(a,b,c)>0)return true;
        if(Orijentacija(a,b,c)<0)return false;
    };
    bool DaLiJeUnutra(const Tacka &t) const{
        if(Orijentacija(a,b,c)>0 && Orijentacija(a,b,t)>0 && Orijentacija(a,t,c)>0 && Orijentacija(b,c,t)>0)return true;
        if(Orijentacija(a,b,c)<0 && Orijentacija(a,b,t)<0 && Orijentacija(a,t,c)<0 && Orijentacija(b,c,t)<0)return true;
        else return false;
    };
    void Ispisi() const{std::cout << "(("<<a.first<<","<<a.second<<"),("<<b.first<<","<<b.second<<"),("<<c.first<<","<<c.second<<"))" << std::endl;};
    void Transliraj(double delta_x, double delta_y){
        a.first+=delta_x;b.first+=delta_x;c.first+=delta_x;
        a.second+=delta_y;b.second+=delta_y;c.second+=delta_y;
    };
    void Centriraj(const Tacka &t){
        Tacka tjeme_staro;
        tjeme_staro.first=(a.first+b.first+c.first)/3;
        tjeme_staro.second=(a.second+b.second+c.second)/3;
        Tacka razlika;
        if(t.first>tjeme_staro.first)razlika.first=t.first-tjeme_staro.first;
        else razlika.first=tjeme_staro.first-t.first;
        if(t.first>tjeme_staro.first)razlika.second=t.second-tjeme_staro.second;
        else razlika.second=tjeme_staro.second-t.second;
        a.first+=razlika.first;
        a.second+=razlika.second;
        b.first+=razlika.first;
        b.second+=razlika.second;
        c.first+=razlika.first;
        c.second+=razlika.second;
    };
    void Rotiraj(const Tacka &t, double ugao){
        a.first=(t.first+(a.first-t.first)*cos(ugao)-(a.second-t.second)*sin(ugao));
        a.second=t.second+(a.first-t.first)*sin(ugao)+(a.second-t.second)*cos(ugao);
        b.first=(t.first+(b.first-t.first)*cos(ugao)-(b.second-t.second)*sin(ugao));
        b.second=t.second+(b.first-t.first)*sin(ugao)+(b.second-t.second)*cos(ugao);
        c.first=(t.first+(c.first-t.first)*cos(ugao)-(c.second-t.second)*sin(ugao));
        c.second=t.second+(c.first-t.first)*sin(ugao)+(c.second-t.second)*cos(ugao);
    };
    void Skaliraj(const Tacka &t, double faktor){
        if(faktor==0)throw std::domain_error("Nekorektan faktor skaliranja");
        a.first=t.first+faktor*(a.first-t.first);
        a.second=t.second+faktor*(a.second-t.second);
        b.first=t.first+faktor*(b.first-t.first);
        b.second=t.second+faktor*(b.second-t.second);
        c.first=t.first+faktor*(c.first-t.first);
        c.second=t.second+faktor*(c.second-t.second);
    };
    void Rotiraj(double ugao){
        Tacka t;
        Tacka zapamti1=a;
        Tacka zapamti2=b;
        Tacka zapamti3=c;
        t.first=(zapamti1.first+zapamti2.first+zapamti3.first)/3;
        t.second=(zapamti1.second+zapamti2.second+zapamti3.second)/3;
        a.first=(t.first+(zapamti1.first-t.first)*cos(ugao)-(zapamti1.second-t.second)*sin(ugao));
        a.second=t.second+(zapamti1.first-t.first)*sin(ugao)+(zapamti1.second-t.second)*cos(ugao);
        b.first=(t.first+(zapamti2.first-t.first)*cos(ugao)-(zapamti2.second-t.second)*sin(ugao));
        b.second=t.second+(zapamti2.first-t.first)*sin(ugao)+(zapamti2.second-t.second)*cos(ugao);
        c.first=(t.first+(zapamti3.first-t.first)*cos(ugao)-(zapamti3.second-t.second)*sin(ugao));
        c.second=t.second+(zapamti3.first-t.first)*sin(ugao)+(zapamti3.second-t.second)*cos(ugao);
    };
    void Skaliraj(double faktor){
        Tacka t;
        t.first=(a.first+b.first+c.first)/3;
        t.second=(a.second+b.second+c.second)/3;
        a.first=t.first+faktor*(a.first-t.first);
        a.second=t.second+faktor*(a.second-t.second);
        b.first=t.first+faktor*(b.first-t.first);
        b.second=t.second+faktor*(b.second-t.second);
        c.first=t.first+faktor*(c.first-t.first);
        c.second=t.second+faktor*(c.second-t.second);
    };
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
bool Pomocna_Identicni(const Tacka &t1, const Tacka &t2){
    if(std::fabs(t1.first-t2.first)<=Eps*(std::fabs(t1.first)+std::fabs(t2.first)) && std::fabs(t1.second-t2.second)<=Eps*(std::fabs(t1.second)+std::fabs(t2.second)))return true;
    else return false;
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
    int a(0),b(0),c(0);
    if(Pomocna_Identicni(t1.a,t2.a)==true || Pomocna_Identicni(t1.a,t2.b)==true || Pomocna_Identicni(t1.a,t2.c))a=1;
    if(Pomocna_Identicni(t1.b,t2.a)==true || Pomocna_Identicni(t1.b,t2.b)==true || Pomocna_Identicni(t1.b,t2.c)==true)b=1;
    if(Pomocna_Identicni(t1.c,t2.a)==true || Pomocna_Identicni(t1.c,t2.b)==true || Pomocna_Identicni(t1.c,t2.c)==true)c=1;
    if(a==1 && b==1 && c==1)return true;
    else return false;
}

bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
   double str11=t1.DajStranicu(1);
   double str12=t1.DajStranicu(2);
   double str13=t1.DajStranicu(3);
   double str21=t2.DajStranicu(1);
   double str22=t2.DajStranicu(2);
   double str23=t2.DajStranicu(3);
   Tacka tackaA1=t1.DajTjeme(1);
   Tacka tackaB1=t1.DajTjeme(2);
   Tacka tackaC1=t1.DajTjeme(3);
   Tacka tackaA2=t2.DajTjeme(1);
   Tacka tackaB2=t2.DajTjeme(2);
   Tacka tackaC2=t2.DajTjeme(3);
   int a(0);
   if(std::fabs(str11-str21)<=Eps && std::fabs(str12-str22)<=Eps && std::fabs(str13-str23)<=Eps && (Trougao::Orijentacija(tackaA1,tackaB1,tackaC1)==Trougao::Orijentacija(tackaA2,tackaB2,tackaC2)))a=1;
   if(std::fabs(str11-str22)<=Eps && std::fabs(str12-str23)<=Eps && std::fabs(str13-str21)<=Eps && (Trougao::Orijentacija(tackaA1,tackaB1,tackaC1)==Trougao::Orijentacija(tackaB2,tackaC2,tackaA2)))a=1;
   if(std::fabs(str11-str23)<=Eps && std::fabs(str12-str21)<=Eps && std::fabs(str13-str22)<=Eps && (Trougao::Orijentacija(tackaA1,tackaB1,tackaC1)==Trougao::Orijentacija(tackaC2,tackaA2,tackaB2)))a=1;
   if(std::fabs(str11-str22)<=Eps && std::fabs(str13-str23)<=Eps && std::fabs(str12-str21)<=Eps && (Trougao::Orijentacija(tackaA1,tackaB1,tackaC1)==Trougao::Orijentacija(tackaB2,tackaA2,tackaC2)))a=1;
   if(std::fabs(str11-str21)<=Eps && std::fabs(str12-str23)<=Eps && std::fabs(str13-str22)<=Eps && (Trougao::Orijentacija(tackaA1,tackaB1,tackaC1)==Trougao::Orijentacija(tackaA2,tackaC2,tackaB2)))a=1;
   if(std::fabs(str11-str23)<=Eps && std::fabs(str12-str22)<=Eps && std::fabs(str13-str21)<=Eps && (Trougao::Orijentacija(tackaA1,tackaB1,tackaC1)==Trougao::Orijentacija(tackaC2,tackaB2,tackaA2)))a=1;
   if(a==1)return true;
   else return false;
}


bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
    double str11=t1.DajStranicu(1);
   double str12=t1.DajStranicu(2);
   double str13=t1.DajStranicu(3);
   double str21=t2.DajStranicu(1);
   double str22=t2.DajStranicu(2);
   double str23=t2.DajStranicu(3);
   double ugao11=t1.DajUgao(1);
   double ugao12=t1.DajUgao(2);
   double ugao21=t2.DajUgao(1);
   double ugao22=t2.DajUgao(2);
   double ugao13=t1.DajUgao(3);
   double ugao23=t2.DajUgao(3);
   if((std::fabs(ugao12-ugao22)<=Eps*(std::fabs(ugao12)+std::fabs(ugao22)) && std::fabs(ugao11-ugao21)<=Eps*(std::fabs(ugao11)+std::fabs(ugao21))) || (std::fabs(ugao12-ugao22)<=Eps*(std::fabs(ugao12)+std::fabs(ugao22)) && std::fabs(ugao13-ugao23)<=Eps*(std::fabs(ugao13)+std::fabs(ugao23))) || (std::fabs(ugao11-ugao21)<=Eps*(std::fabs(ugao11)+std::fabs(ugao21)) && std::fabs(ugao13-ugao23)<=Eps*(std::fabs(ugao13)+std::fabs(ugao23))))return true;
   else if((std::fabs(str11/str21-str13/str23)<=Eps*(std::fabs(str11/str21)+std::fabs(str13/str23)) && std::fabs(ugao12-ugao22)<=Eps*(std::fabs(ugao12)+std::fabs(ugao22))))return true;
   else if((std::fabs(str11/str21-str12/str22)<=Eps*(std::fabs(str11/str21)+std::fabs(str12/str22)) && std::fabs(ugao13-ugao23)<=Eps*(std::fabs(ugao13)+std::fabs(ugao23))))return true;
   else if((std::fabs(str12/str22-str13/str23)<=Eps*(std::fabs(str12/str22)+std::fabs(str13/str23)) && std::fabs(ugao11-ugao21)<=Eps*(std::fabs(ugao11)+std::fabs(ugao21))))return true;
   else if(std::fabs(str12/str22-str13/str23)<=Eps*(std::fabs(str12/str22)+std::fabs(str13/str23)) && std::fabs(str11/str21-str13/str23)<=Eps*(std::fabs(str11/str21)+std::fabs(str13/str23)) && std::fabs(str11/str21-str12/str22)<=Eps*(std::fabs(str11/str21)+std::fabs(str12/str22)))return true;
   else return false;
}

int main ()
{
    try{
    std::cout << "Koliko zelite kreirati trouglova: ";
    int n;
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> v(n);
    Tacka a,b,c;
    std::pair<double,double> par1,par2,par3;
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    //for(int i=0;i<n;i++)v[i]=nullptr;
    double prvi,drugi,treci,cetvrti,peti,sesti;
    for(int i=0;i<n;i++){
        std::cout << "Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        std::cin >> prvi >> drugi;
        par1=std::make_pair(prvi,drugi);
        Tacka a=par1;
        std::cin >> treci >> cetvrti;
        par2=std::make_pair(treci,cetvrti);
        Tacka b=par2;
        std::cin >> peti >> sesti;
        par3=std::make_pair(peti,sesti);
        Tacka c=par3;
        //Trougao trougao(a,b,c);
        try{
        std::shared_ptr<Trougao> p(std::make_shared<Trougao>(Trougao(a,b,c)));
         v[i]=p;
        //p=trougao;
        }catch(std::domain_error e){
            std::cout << e.what()<<", ponovite unos! "<<std::endl ;
            i--;
        }
    }
    double translira1,translira2;
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin>>translira1 >> translira2;
    std::cout << "Unesite ugao rotacije: " ;
    double ugao,faktor;
    std::cin >> ugao;
    //ugao*=(PI/180);
    std::cout << "Unesite faktor skaliranja: ";
    std::cin>>faktor;
    std::transform(v.begin(),v.end(),v.begin(),[translira1,translira2, ugao,faktor] (std::shared_ptr<Trougao> t){
            t->Transliraj(translira1,translira2);
            t->Rotiraj(ugao);
            Tacka tjeme=t->DajTjeme(1);
            t->Skaliraj(tjeme,faktor);
            return t;
        });
        
    std::sort(v.begin(),v.end(), [] (std::shared_ptr<Trougao> t,std::shared_ptr<Trougao> tr){
        double povrsina1=t->DajPovrsinu();
        double povrsina2=tr->DajPovrsinu();
        if(povrsina2>povrsina1)return true;
        else return false;
    });
    std::cout << "Trouglovi nakon obavljenih transformacija: " << std::endl;
    std::for_each(v.begin(), v.end(), [] (std::shared_ptr<Trougao> t){t->Ispisi();});
    auto pok=std::min_element(v.begin(), v.end(), [] (std::shared_ptr<Trougao> t, std::shared_ptr<Trougao> tr){
        double obim1=t->DajObim();
        double obim2=tr->DajObim();
        if(obim2>obim1)return true;
        else return false;
    });
    std::cout << "Trougao sa najmanjim obimom: ";
    (*pok)->Ispisi();
    int broj(0),brojac(0);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuIdenticni(*v[i],*v[j])==true){
                brojac++;
                if(brojac==1){std::cout << "Parovi identicnih trouglova:" << std::endl; brojac++;}
                Tacka d,e,f,g,h,k;
                d=v[i]->DajTjeme(1);
                e=v[i]->DajTjeme(2);
                f=v[i]->DajTjeme(3);
                g=v[j]->DajTjeme(1);
                h=v[j]->DajTjeme(2);
                k=v[j]->DajTjeme(3);
                std::cout << "(("<<d.first<<","<<d.second<<"),("<<e.first<<","<<e.second<<"),("<<f.first<<","<<f.second<<")) i ((" <<g.first<<","<<g.second<<"),("<<h.first<<","<<h.second<<"),("<<k.first<<","<<k.second<<"))"<<std::endl;
                broj=1;
            }
        }
    }
    if(broj==0)std::cout << "Nema identicnih trouglova!" << std::endl;
    brojac=0;broj=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuPodudarni(*v[i],*v[j])==true){
                brojac++;
                if(brojac==1){std::cout << "Parovi podudarnih trouglova:" << std::endl; brojac++;}
                Tacka d,e,f,g,h,k;
                d=v[i]->DajTjeme(1);
                e=v[i]->DajTjeme(2);
                f=v[i]->DajTjeme(3);
                g=v[j]->DajTjeme(1);
                h=v[j]->DajTjeme(2);
                k=v[j]->DajTjeme(3);
                std::cout << "(("<<d.first<<","<<d.second<<"),("<<e.first<<","<<e.second<<"),("<<f.first<<","<<f.second<<")) i ((" <<g.first<<","<<g.second<<"),("<<h.first<<","<<h.second<<"),("<<k.first<<","<<k.second<<"))"<<std::endl;
                broj=1;
            }
        }
    }
    //std::cout << brojac << std::endl;
    if(broj==0)std::cout << "Nema podudarnih trouglova!" << std::endl;
    brojac=0;broj=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuPodudarni(*v[i],*v[j])==true){
                brojac++;
                if(brojac==1){std::cout << "Parovi slicnih trouglova:" << std::endl; brojac++;}
                Tacka d,e,f,g,h,k;
                d=v[i]->DajTjeme(1);
                e=v[i]->DajTjeme(2);
                f=v[i]->DajTjeme(3);
                g=v[j]->DajTjeme(1);
                h=v[j]->DajTjeme(2);
                k=v[j]->DajTjeme(3);
                std::cout << "(("<<d.first<<","<<d.second<<"),("<<e.first<<","<<e.second<<"),("<<f.first<<","<<f.second<<")) i ((" <<g.first<<","<<g.second<<"),("<<h.first<<","<<h.second<<"),("<<k.first<<","<<k.second<<"))"<<std::endl;
                broj=1;
            }
        }
    }
    if(broj==0)std::cout << "Nema slicnih trouglova!" << std::endl;

    }catch(std::domain_error e){
        std::cout << e.what() << std::endl;
    }catch(std::range_error e){
        std::cout << e.what() << std::endl;
    }
	return 0;
}