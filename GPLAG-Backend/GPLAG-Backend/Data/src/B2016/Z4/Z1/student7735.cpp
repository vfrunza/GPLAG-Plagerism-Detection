/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <memory>
#include <utility>
#include <iterator>
#include <new>
const double eps(1e-10);

typedef std::pair<double,double> Tacka;

class Trougao{
    std::vector<Tacka> vrhovi;
    public:
    Trougao(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        vrhovi.resize(3);
        Postavi(t1,t2,t3);
        };
    void Postavi(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        vrhovi[0].first=t1.first;
        vrhovi[0].second=t1.second;
        vrhovi[1].first=t2.first;
        vrhovi[1].second=t2.second;
        vrhovi[2].first=t3.first;
        vrhovi[2].second=t3.second;
        double a,b,c;
        a=sqrt(pow((vrhovi[0].first-vrhovi[1].first),2)+pow((vrhovi[0].second-vrhovi[1].second),2));
        b=sqrt(pow((vrhovi[1].first-vrhovi[2].first),2)+pow((vrhovi[1].second-vrhovi[2].second),2));
        c=sqrt(pow((vrhovi[0].first-vrhovi[2].first),2)+pow((vrhovi[0].second-vrhovi[2].second),2));
        if(fabs(a+b-c)<eps || fabs(b+c-a)<eps || fabs(a+c-b)<eps)throw std::domain_error ("Nekorektne pozicije tjemena");
    };
    void Postavi(int indeks,const Tacka &t);
    static int Orijentacija(const Tacka &t1,const Tacka &t2,const Tacka &t3){
        double d=t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
        if(d>0) return 1;
        else if(d<0) return -1;
        return 0;
    };
    Tacka DajTjeme(int indeks)const{
        if(indeks==1)return vrhovi[0];
        else if(indeks==2) return vrhovi[1];
        else if(indeks==3) return vrhovi[2];
        else throw std::range_error ("Nekorektan indeks");
    };
    double DajStranicu(int indeks)const{
        if(indeks==1)return sqrt((vrhovi[1].first-vrhovi[2].first)*(vrhovi[1].first-vrhovi[2].first)+(vrhovi[1].second-vrhovi[2].second)*(vrhovi[1].second-vrhovi[2].second));
        else if(indeks==2)return sqrt((vrhovi[0].first-vrhovi[2].first)*(vrhovi[0].first-vrhovi[2].first)+(vrhovi[0].second-vrhovi[2].second)*(vrhovi[0].second-vrhovi[2].second));
        else if(indeks==3)return sqrt((vrhovi[0].first-vrhovi[1].first)*(vrhovi[0].first-vrhovi[1].first)+(vrhovi[0].second-vrhovi[1].second)*(vrhovi[0].second-vrhovi[1].second));
        else throw std::range_error ("Nekorektan indeks");
    };
    double DajUgao(int indeks)const{
        double ugao;
        if(indeks==1)return ugao=acos((DajStranicu(1)*DajStranicu(1)-DajStranicu(2)*DajStranicu(2)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(2)*DajStranicu(3)));
        else if(indeks==2)return ugao=acos((DajStranicu(2)*DajStranicu(2)-DajStranicu(1)*DajStranicu(1)-DajStranicu(3)*DajStranicu(3))/(2*DajStranicu(1)*DajStranicu(3)));
        else if(indeks==3)return ugao=acos((DajStranicu(3)*DajStranicu(3)-DajStranicu(2)*DajStranicu(2)-DajStranicu(1)*DajStranicu(1))/(2*DajStranicu(1)*DajStranicu(2)));
        else throw std::range_error ("Nekorektan indeks");

    };
    Tacka DajCentar()const{
        Tacka centar;
        centar.first=(vrhovi[0].first+vrhovi[1].first+vrhovi[2].first)/3;
        centar.second=(vrhovi[0].second+vrhovi[1].second+vrhovi[2].second)/3;
        return centar;
    };
    double DajObim()const{
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);};
    double DajPovrsinu()const{
        return (0.5)*abs(vrhovi[0].first*(vrhovi[1].second-vrhovi[2].second)+vrhovi[1].first*(vrhovi[2].second-vrhovi[0].second)+vrhovi[2].first*(vrhovi[0].second-vrhovi[1].second));};
    bool DaLiJePozitivnoOrijentiran()const{
        if (Orijentacija(vrhovi[0],vrhovi[1],vrhovi[2])==1) return true;
        return false;
    };
    bool DaLiJeUnutra(const Tacka &t)const;
    void Ispisi()const{
        std::cout << "(("<<vrhovi[0].first<<","<<vrhovi[0].second<<"),("<<vrhovi[1].first<<","<<vrhovi[1].second<<"),("<<vrhovi[2].first<<","<<vrhovi[2].second<<"))";
    };
    void Transliraj(double delta_x,double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj (const Tacka &t,double ugao);
    void Skaliraj(const Tacka &t,double faktor);
    void Rotiraj(double ugao){
        Rotiraj(DajCentar(),ugao);
    };
    void Skaliraj(double faktor){
        Skaliraj(DajCentar(),faktor);};
    friend bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2);
};

void Trougao::Postavi(int indeks,const Tacka &t){
    if (indeks==1)Postavi(t,vrhovi[1],vrhovi[2]);
    else if(indeks==2)Postavi(vrhovi[0],t,vrhovi[2]);
    else if(indeks==3)Postavi(vrhovi[0],vrhovi[1],t);
    else throw std::range_error ("Nekorektan indeks");
}
bool Trougao::DaLiJeUnutra(const Tacka &t)const{
    double p=DajPovrsinu();
    if((fabs(t.first-vrhovi[0].first)<eps && fabs(vrhovi[0].first-vrhovi[1].first)<eps) || 
       (fabs(t.second-vrhovi[0].second)<eps && fabs(vrhovi[0].second-vrhovi[1].second)<eps)||
       (fabs(t.first-vrhovi[1].first)<eps && fabs(vrhovi[1].first-vrhovi[2].first)<eps) ||
       (fabs(t.second-vrhovi[1].second)<eps && fabs(vrhovi[1].second-vrhovi[2].second)<eps) ||
       (fabs(t.first-vrhovi[2].first)<eps && fabs(vrhovi[2].first-vrhovi[0].first)<eps) ||
       (fabs(t.second-vrhovi[2].second)<eps && fabs(vrhovi[2].second-vrhovi[0].second)<eps))return false;
    Trougao pomocni(vrhovi[0],vrhovi[1],t);
    double p1=pomocni.DajPovrsinu();
    pomocni.Postavi(vrhovi[1],vrhovi[2],t);
    double p2=pomocni.DajPovrsinu();
    pomocni.Postavi(vrhovi[2],vrhovi[0],t);
    double p3=pomocni.DajPovrsinu();
    if(fabs(p-(p1+p2+p3))<eps)return true;
    return false;
}
void Trougao::Transliraj(double delta_x,double delta_y){
    Postavi(Tacka(vrhovi[0].first+delta_x,vrhovi[0].second+delta_y),Tacka(vrhovi[1].first+delta_x,vrhovi[1].second+delta_y),Tacka(vrhovi[2].first+delta_x,vrhovi[2].second+delta_y));
}
void Trougao::Centriraj(const Tacka &t){
    Tacka centar=DajCentar();
    double dx,dy;
    dx=centar.first-t.first;
    dy=centar.second-t.second;
    Transliraj(dx,dy);
}
void Trougao::Rotiraj(const Tacka &t,double ugao){
    Tacka A(t.first+(vrhovi[0].first-t.first)*cos(ugao)-(vrhovi[0].second-t.second)*sin(ugao),t.second+(vrhovi[0].first-t.first)*sin(ugao)+(vrhovi[0].second-t.second)*cos(ugao));
    Tacka B(t.first+(vrhovi[1].first-t.first)*cos(ugao)-(vrhovi[1].second-t.second)*sin(ugao),t.second+(vrhovi[1].first-t.first)*sin(ugao)+(vrhovi[1].second-t.second)*cos(ugao));
    Tacka C(t.first+(vrhovi[2].first-t.first)*cos(ugao)-(vrhovi[2].second-t.second)*sin(ugao),t.second+(vrhovi[2].first-t.first)*sin(ugao)+(vrhovi[2].second-t.second)*cos(ugao));
    Postavi(A,B,C);
}
void Trougao::Skaliraj(const Tacka &t,double faktor){
    if(fabs(faktor)<eps)throw std::domain_error ("Nekorektan faktor skaliranja");
    Tacka a,b,c;
    a=std::make_pair((t.first+faktor*(vrhovi[0].first-t.first)),(t.second+faktor*(vrhovi[0].second-t.second)));
    b=std::make_pair((t.first+faktor*(vrhovi[1].first-t.first)),(t.second+faktor*(vrhovi[1].second-t.second)));
    c=std::make_pair((t.first+faktor*(vrhovi[2].first-t.first)),(t.second+faktor*(vrhovi[2].second-t.second)));
    Postavi(a,b,c);
}
bool DaLiSuIdenticni(const Trougao &t1,const Trougao &t2){
    Tacka A,B,C;
    A=t1.DajTjeme(1);
    B=t1.DajTjeme(2);
    C=t1.DajTjeme(3);
    Tacka D,E,F;
    D=t2.DajTjeme(1);
    E=t2.DajTjeme(2);
    F=t2.DajTjeme(3);
    
    if((fabs(A.first-D.first)<eps && fabs(A.second-D.second)<eps && fabs(B.first-E.first)<eps && fabs(B.second-E.second)<eps && fabs(C.first-F.first)<eps && fabs(C.second-F.second)<eps)
    || (fabs(A.first-F.first)<eps && fabs(A.second-F.second)<eps && fabs(B.first-E.first)<eps && fabs(B.second-E.second)<eps && fabs(C.first-D.first)<eps && fabs(C.second-D.second)<eps)//return true;
    || (fabs(A.first-E.first)<eps && fabs(A.second-E.second)<eps && fabs(B.first-F.first)<eps && fabs(B.second-F.second)<eps && fabs(C.first-D.first)<eps && fabs(C.second-D.second)<eps)//return true;
    || (fabs(A.first-D.first)<eps && fabs(A.second-D.second)<eps && fabs(B.first-F.first)<eps && fabs(B.second-F.second)<eps && fabs(C.first-E.first)<eps && fabs(C.second-E.second)<eps)//return true;
    || (fabs(A.first-F.first)<eps && fabs(A.second-F.second)<eps && fabs(B.first-D.first)<eps && fabs(B.second-D.second)<eps && fabs(C.first-E.first)<eps && fabs(C.second-E.second)<eps)//return true;
    || (fabs(A.first-E.first)<eps && fabs(A.second-E.second)<eps && fabs(B.first-D.first)<eps && fabs(B.second-D.second)<eps && fabs(C.first-F.first)<eps && fabs(C.second-F.second)<eps))return true;
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1,const Trougao &t2){
    if(DaLiSuIdenticni(t1,t2)==true){return true;}
    Trougao pomocni(t2);
    int orijent1=Trougao::Orijentacija(t1.vrhovi[0],t1.vrhovi[1],t1.vrhovi[2]);
    int orijent2=Trougao::Orijentacija(t2.vrhovi[0],t2.vrhovi[1],t2.vrhovi[2]);
    
    if(orijent2!=orijent1){
       pomocni.Postavi(t2.vrhovi[2],t2.vrhovi[1],t2.vrhovi[0]);
    }
    //odrediti najvecu stranicu u trouglu i krenuti od nje...
    double a,b,c,d,e,f;
    int indeks1=1,indeks2=1;
    a=t1.DajStranicu(1);b=t1.DajStranicu(2);c=t1.DajStranicu(3);
    d=pomocni.DajStranicu(1);e=pomocni.DajStranicu(2);f=pomocni.DajStranicu(3);
    double maxx1=a,maxx2=d;
    
    if(b>=maxx1 && b>=c) {maxx1=b; indeks1=2;}
    else if(c>=maxx1 && c>=b){maxx1=c; indeks1=3;}
    
    if(e>=maxx2 && e>=f) {maxx2=e; indeks2=2;}
    else if(f>=maxx2 && f>=e){maxx2=f;indeks2=3;}
  
    if(fabs(maxx1-maxx2)>eps){return false;}
    else{
        if(indeks1==3)indeks1=1;
        else indeks1++;
       
        if(indeks2==3)indeks2=1;
        else indeks2++;
      
        double pomocna1=t1.DajStranicu(indeks1);
        double pomocna2=pomocni.DajStranicu(indeks2);
       
        if(fabs(pomocna1-pomocna2)<eps){return true;}
        else {return false;}
    }
}
bool DaLiSuSlicni(const Trougao &t1,const Trougao &t2){
    if(DaLiSuPodudarni(t1,t2))return true;
    else if(DaLiSuIdenticni(t1,t2))return true;
    else{
        Trougao pomocni(t2);
        int ori1=Trougao::Orijentacija(t1.vrhovi[0],t1.vrhovi[1],t1.vrhovi[2]);
        int ori2=Trougao::Orijentacija(t2.vrhovi[0],t2.vrhovi[1],t2.vrhovi[2]);
        if(ori1!=ori2)pomocni.Postavi(t2.vrhovi[2],t2.vrhovi[1],t2.vrhovi[0]);
       
        double a,b,c,d,e,f;
        int index1=1,index2=1;
        a=t1.DajStranicu(1);b=t1.DajStranicu(2);c=t1.DajStranicu(3);
        d=pomocni.DajStranicu(1);e=pomocni.DajStranicu(2);f=pomocni.DajStranicu(3);
       
        double maxi1=a,maxi2=d;   
        if(b>=maxi1 && b>=c){maxi1=b; index1=2;}
        else if(c>=maxi1 && c>=b){maxi1=c; index1=3;}
       
        if(e>=maxi2 && e>=f){maxi2=e; index2=2;}
        else if(f>=maxi2 && f>=e){maxi2=f; index2=3;}
        
        double koef1,koef2;
        koef1=maxi2/maxi1;
        
        if(index1==3)index1=1;
        else index1++;
        if(index2==3)index2=1;
        else index2++;
       
        double dodatna1=t1.DajStranicu(index1);
        double dodatna2=pomocni.DajStranicu(index2);
    
       koef2=dodatna2/dodatna1;
      
       if(fabs(koef1-koef2)<eps)return true;
       return false;
    }
}

int main ()
{
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin >> n;
    std::vector<std::shared_ptr<Trougao>> trouglovi;
    Tacka A,B,C;
    for(int i=0;i<n;i++){
        try{
            std::cout << "Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            std::cin >> A.first >>A.second;
            std::cin >> B.first >> B.second;
            std::cin >> C.first >> C.second;
            Trougao t1(A,B,C);
            std::shared_ptr<Trougao> pok(new Trougao(t1));
            trouglovi.push_back(pok);
        }catch(std::domain_error e){
            std::cout<<e.what()<<", ponovite unos!"<< std::endl;
            i--;
        }
        catch(std::range_error e){
            std::cout << e.what()<<", ponovite unos!" << std::endl;
        }
        catch(std::bad_alloc){
            std::cout << "Nema memorije" << std::endl;
        }
    }
    auto it1(trouglovi.begin());
    auto it2(trouglovi.end());
    double dx,dy;
    double ugaoo,faktor;
    
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> dx>>dy;
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> ugaoo;
    std::cout << "Unesite faktor skaliranja: ";
    std::cin >> faktor;
    std::cout << "Trouglovi nakon obavljenih transformacija: "<<std::endl;
   
    std::transform(it1,it2,it1,[dx,dy,ugaoo,faktor](std::shared_ptr<Trougao> p1){
        p1->Transliraj(dx,dy);
        p1->Rotiraj(p1->DajCentar(),ugaoo);
        Tacka G=(*p1).DajTjeme(1);
        p1->Skaliraj(G,faktor);
       
        return p1;
    });
    
    it1=(trouglovi.begin());
    it2=(trouglovi.end());
    std::sort(it1,it2,[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){
       return (t1->DajPovrsinu()<t2->DajPovrsinu()); 
    });
     
     it1=(trouglovi.begin());
     it2=(trouglovi.end());
    std::for_each(it1,it2,[](std::shared_ptr<Trougao> t1){
        t1->Ispisi();std::cout << std::endl;
    });

    std::cout << "Trougao sa najmanjim obimom: ";
    
    auto m=(std::min_element(it1,it2,[](std::shared_ptr<Trougao> t1,std::shared_ptr<Trougao> t2){
        return bool(t1->DajObim()<t2->DajObim());
    }));
    (*m)->Ispisi();
    std::cout  << std::endl;
    int b=0;int c=0;int d=0;
  
    for(int i=0;i<trouglovi.size()-1;i++){
        for(int j=i+1;j<trouglovi.size();j++)
        if(DaLiSuIdenticni(*trouglovi[i],*trouglovi[j])==true){
           if(b==0)std::cout << "Parovi identicnih trouglova: "<<std::endl;
             b++;
             trouglovi[i]->Ispisi();
             std::cout << " i ";
             trouglovi[j]->Ispisi();
          std::cout  << std::endl;
          
          }
    }
    if(b==0)std::cout << "Nema identicnih trouglova!" << std::endl;
    for(int i=0;i<trouglovi.size()-1;i++){
        for(int j=i+1;j<trouglovi.size();j++)
       if(DaLiSuPodudarni(*trouglovi[i],*trouglovi[j])){
           if(c==0)std::cout << "Parovi podudarnih trouglova: "<<std::endl;
             c++;
             trouglovi[i]->Ispisi();
             std::cout << " i ";
             trouglovi[j]->Ispisi();
             std::cout  << std::endl;
         }
    }
    if(c==0)std::cout << "Nema podudarnih trouglova!" << std::endl;
    for(int i=0;i<trouglovi.size()-1;i++){
        for(int j=i+1;j<trouglovi.size();j++)
       if(DaLiSuSlicni(*trouglovi[i],*trouglovi[j])){
             if(d==0)std::cout << "Parovi slicnih trouglova: "<<std::endl;
             d++;
             trouglovi[i]->Ispisi();
             std::cout << " i " ;
             trouglovi[j]->Ispisi();
             std::cout << std::endl;
         }
    }   
    if(d==0)std::cout << "Nema slicnih trouglova!" << std::endl;
    
    return 0;
    
}