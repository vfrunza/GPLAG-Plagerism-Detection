/B 2016/2017, Zadaća 4, Zadatak 1
//Napomena: testovi ce biti dostupni dan pred rok!
#include <iostream>
#include<memory>
#include<stdexcept>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

typedef std::pair<double,double> Tacka;

class Trougao{
    Tacka niz[3];
    static bool JelJ(double x, double y, double Eps=1e-10){
        return std::fabs(x-y)<=Eps*(std::fabs(x)+std::fabs(y));
    }
    static double izraz(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        return (t1.first*(t2.second - t3.second) - t2.first*(t1.second - t3.second) + t3.first*(t1.second - t2.second));
    }
    
    public:
    Trougao(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        if(Orijentacija(t1,t2,t3)==0) throw domain_error("Nekorektne pozicije tjemena");
        niz[0]=t1; niz[1]=t2; niz[2]=t3;
    }
    
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        *this=Trougao(t1,t2,t3);
    } 
    
    void Postavi(int indeks, const Tacka &t){
        if(indeks>3 || indeks<=0) throw range_error("Nekorektan indeks");
        niz[indeks-1].first=t.first; niz[indeks-1].second=t.second;
    }
    
    static int Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3){
        double pom=izraz(t1,t2,t3);
        if(JelJ(pom, 0)) return 0;
        if(pom>0) return 1;
        if(pom<0) return -1;
        
        
    }
    
    Tacka DajTjeme(int indeks) const{
        if(indeks>3 || indeks<=0) throw range_error("Nekorektan indeks");
        return niz[indeks-1];
    }
    
    double DajStranicu(int indeks) const{
        if(indeks>3 || indeks<=0) throw range_error("Nekorektan indeks");
        
        if(indeks==1) return sqrt((niz[1].first-niz[2].first)*(niz[1].first-niz[2].first) + ((niz[1].second-niz[2].second)*(niz[1].second-niz[2].second)));
        if(indeks==2) return sqrt((niz[0].first-niz[2].first)*(niz[0].first-niz[2].first) + ((niz[0].second-niz[2].second)*(niz[0].second-niz[2].second)));
        if(indeks==3) return sqrt((niz[0].first-niz[1].first)*(niz[0].first-niz[1].first) + ((niz[0].second-niz[1].second)*(niz[0].second-niz[1].second)));
        
    }
    
    double DajUgao(int indeks) const;
    Tacka DajCentar() const;
    double DajObim() const{
        return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
    }
    double DajPovrsinu() const{
       return abs(izraz(niz[0], niz[1],niz[2]))/2;
    }
    bool DaLiJePozitivnoOrjentiran() const{
        if(Orijentacija(niz[0],niz[1],niz[2])) return 1;
        return 0;
    }
    bool DaLiJeUnutra(const Tacka &t) const;
    void Ispisi() const{
        cout<<"(("<<niz[0].first<<","<<niz[0].second<<"),"<<"("<<niz[1].first<<","<<niz[1].second<<"),"<<"("<<niz[2].first<<","<<niz[2].second<<"))";
        
    }
    void Transliraj(double delta_x, double delta_y);
    void Centriraj(const Tacka &t);
    void Rotiraj(const Tacka &t, double ugao);
    void Skaliraj(const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2){
        int brojac=0;
       for(int i=0;i<3;i++){
           for(int j=0;j<3;j++){
               if(JelJ(t1.niz[i].first, t2.niz[j].first)==1 && JelJ(t1.niz[i].second, t2.niz[j].second)==1) brojac++;
           }
       }
       if(brojac==3) return 1;
       return 0;
       
    }
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2){
        double a=t1.DajStranicu(1), b=t1.DajStranicu(2), c=t1.DajStranicu(3);
        double a2=t2.DajStranicu(1), b2=t2.DajStranicu(2), c2=t2.DajStranicu(3);
        vector<double> v1{a,b,c}, v2{a2,b2,c2};
        vector<int> v{0,1,2},vv;
        vv=v;
        
        double pom;
        for(int i=0;i<3;i++){
            for(int j=i;j<3;j++){
                if(v1[i]>v1[j]){
                    pom=v1[i];
                    v1[i]=v1[j];
                    v1[j]=pom;
                    
                    int pom1=v[i];
                    v[i]=v[j];
                    v[j]=pom1;
                }
                
                if(v2[i]>v2[j]){
                    pom=v2[i];
                    v2[i]=v2[j];
                    v2[j]=pom;
                    
                    int pom1=vv[i];
                    vv[i]=vv[j];
                    vv[j]=pom1;
                }
            }
        }
        if(Orijentacija(t1.niz[v[0]], t1.niz[v[1]], t1.niz[v[2]])==Orijentacija(t2.niz[vv[0]], t2.niz[vv[1]], t2.niz[vv[2]]) && v1==v2) return 1;
        return 0;
        
    }
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2){
        double a=t1.DajStranicu(1), b=t1.DajStranicu(2), c=t1.DajStranicu(3);
        double a2=t2.DajStranicu(1), b2=t2.DajStranicu(2), c2=t2.DajStranicu(3);
        vector<double> v1{a,b,c}, v2{a2,b2,c2};
        vector<int> v{0,1,2}, vv=v;
        
        if(DaLiSuPodudarni(t1,t2)) return 1;
        
        double pom;
        for(int i=0;i<3;i++){
            for(int j=i;j<3;j++){
                if(v[i]>v1[j]){
                    pom=v1[i];
                    v1[i]=v1[j];
                    v1[j]=pom;
                    
                    int pom1=v[i];
                    v[i]=v[j];
                    v[j]=pom1;
                }
                if(v2[i]>v2[j]){
                    pom=v2[i];
                    v2[i]=v2[j];
                    v2[j]=pom;
                    
                    int pom1=vv[i];
                    vv[i]=vv[j];
                    vv[j]=pom1;
                }
                
            }
        }
        
        bool jest=0;
        bool jest1=0;
        if(Orijentacija(t1.niz[v[0]], t1.niz[v[1]], t1.niz[v[2]])==Orijentacija(t2.niz[vv[0]], t2.niz[vv[1]], t2.niz[vv[2]])) jest=1;
        if(JelJ(v1[0]/v2[0],v1[1]/v2[1]) && JelJ(v1[0]/v2[0],v1[2]/v2[2])) jest1=1;
        
        if(jest && jest1) return 1;
        return 0;
    }
};

double Trougao::DajUgao(int indeks) const{
    if(indeks>3 || indeks<=0) throw range_error("Nekorektan indeks");
    
    double i,a,b,c;
    a=DajStranicu(1);
    b=DajStranicu(2);
    c=DajStranicu(3);
    
    if(indeks==1){
        i=(b*b+c*c-a*a)/2*b*c;
        return acos(i);
    }
    if(indeks==2){
        i=(a*a+c*c-b*b)/2*a*c;
        return acos(i);
    }
    if(indeks==1){
        i=(b*b+a*a-c*c)/2*b*a;
        return acos(i);
    }
}
Tacka Trougao::DajCentar() const{
    Tacka c;
    c.first=(niz[0].first+niz[1].first+niz[2].first)/3;
    c.second=(niz[0].second+niz[1].second+niz[2].second)/3;
    
    return c;
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const{
    int a,b,c,d;
    a=Orijentacija(niz[0], niz[1], niz[2]);
    b=Orijentacija(niz[0], niz[1], t);
    c=Orijentacija(niz[1], niz[2], t);
    d=Orijentacija(niz[2], niz[0], t);
    
    if(a==b && a==c && a==d) return 1;
    return 0;
}
void Trougao::Transliraj(double delta_x, double delta_y){
    for(int i=0;i<3;i++){
        niz[i].first+=delta_x;
        niz[i].second+=delta_y;
    }
}
void Trougao::Centriraj(const Tacka &t){
    Tacka c=DajCentar();
    
    double delta_x=c.first-t.first;
    double delta_y=c.second-t.second;
    
    Transliraj(delta_x,delta_y);
    
}
void Trougao::Rotiraj(const Tacka &t, double ugao){
    double x,y;
    for(int i=0;i<3;i++){
    
        x=t.first+(niz[i].first-t.first)*cos(ugao) - (niz[i].second-t.second)*sin(ugao);
        y=t.second+(niz[i].first-t.first)*sin(ugao) + (niz[i].second-t.second)*cos(ugao);
        
        niz[i].first=x;
        niz[i].second=y;
    }
}
void Trougao::Skaliraj(const Tacka &t, double faktor){
    if(faktor==0) throw domain_error("Nekorektan faktor skaliranja");
    for(int i=0;i<3;i++){
        niz[i].first=t.first+faktor*(niz[i].first-t.first);
        niz[i].second=t.second+faktor*(niz[i].second-t.second);
    }
}
void Trougao::Skaliraj(double faktor){
    if(JelJ(faktor,0)) throw domain_error("Nekorektan faktor skaliranja");
    Tacka c=DajCentar();
    Skaliraj(c,faktor);
}
void Trougao::Rotiraj(double ugao){
    Tacka c=DajCentar();
    Rotiraj(c,ugao);
}



int main ()
{
    
    

 cout<<"Koliko zelite kreirati trouglova: ";
    int n;
    cin>>n;
  
    vector<shared_ptr<Trougao>> v;
    for(int i=0;i<n;i++){
        
        cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
        double x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        Tacka t1,t2,t3;
        t1.first=x1; t1.second=y1;
        t2.first=x2; t2.second=y2;
        t3.first=x3; t3.second=y3;
        if(std::abs(Trougao::Orijentacija(t1,t2,t3))){
            auto tr=make_shared<Trougao>(t1,t2,t3);
            v.push_back(tr);
        }
        else{
        while(!Trougao::Orijentacija(t1,t2,t3)){
            cout<<"Nekorektne pozicije tjemena, ponovite unos!"<<endl;
            cout<<"Unesite podatke za "<<i+1<<". trougao (x1 y1 x2 y2 x3 y3): ";
            double a,b,c,d,e,f;
            cin>>a>>b>>c>>d>>e>>f;
            t1.first=a; t1.second=b;
            t2.first=c; t2.second=d;
            t3.first=e; t3.second=f;
            
        }
        auto tr=make_shared<Trougao>(t1,t2,t3);
        v.push_back(tr);
}
        
        
    }
    
    cout<<"Unesite vektor translacije (dx dy): ";
    double x,y;
    cin>>x>>y;
    transform(v.begin(), v.end(),v.begin(), [=](shared_ptr<Trougao> pok){
        pok->Transliraj(x,y);
        return pok;
    });
    
    double ugao, fskal;
    cout<<"Unesite ugao rotacije: ";
    cin>>ugao;
    cout<<"Unesite faktor skaliranja: ";
    cin>>fskal;
    cout<<"Trouglovi nakon obavljenih transformacija: ";
    transform(v.begin(), v.end(),v.begin(), [=](shared_ptr<Trougao> pok){
        pok->Rotiraj(ugao);
        return pok;
    });
    transform(v.begin(), v.end(),v.begin(), [=](shared_ptr<Trougao> pok){
        pok->Skaliraj(pok->DajTjeme(1), fskal);
        return pok;
    });
    
    sort(v.begin(),v.end(), [=](shared_ptr<Trougao> pok,shared_ptr<Trougao> pok1 ){
        return pok->DajPovrsinu()<pok1->DajPovrsinu();
    });
    
    for_each(v.begin(),v.end(), [=](shared_ptr<Trougao> pok){
       cout<<endl;
        pok->Ispisi(); 
    });
    
    auto xx=min_element(v.begin(),v.end(), [=](shared_ptr<Trougao> pok, shared_ptr<Trougao> pok1){
        return pok->DajObim()<pok1->DajObim();
    });
    cout<<endl;
    cout<<"Trougao sa najmanjim obimom: ";
    (*xx)->Ispisi();
    
    int brojac1=0, br2=0,br3=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(DaLiSuIdenticni(*v[i], *v[j])) brojac1++;
            if(DaLiSuPodudarni(*v[i], *v[j])) br2++;
            if(DaLiSuSlicni(*v[i],*v[j])) br3++;
        }
    }
    cout<<endl;
    if(brojac1==0) cout<<"Nema identicnih trouglova!";
    else{
        cout<<"Parovi identicnih trouglova: "<<endl;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(DaLiSuIdenticni(*v[i],*v[j])) {
                    v[i]->Ispisi();
                    cout<<" i ";
                    v[j]->Ispisi();
                    cout<<endl;
                }
                
            }
        }
        
        
    }
    cout<<endl;
    if(br2==0) cout<<"Nema podudarnih trouglova!";
    else{
        cout<<"Parovi podudarnih trouglova: "<<endl;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(DaLiSuPodudarni(*v[i],*v[j])) {
                    v[i]->Ispisi();
                    cout<<" i ";
                    v[j]->Ispisi();
                    cout<<endl; 
                }
               
            }
        }
    }
    cout<<endl;
    if(br3==0) cout<<"Nema slicnih trouglova!";
    else{
        cout<<"Parovi slicnih trouglova: "<<endl;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(DaLiSuSlicni(*v[i],*v[j])) {
                    v[i]->Ispisi();
                    cout<<" i ";
                    v[j]->Ispisi();
                    cout<<endl;  
                }
              
            }
        }
    }
    
    
	return 0;
}