/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <tuple>
#include <cmath>
#include <vector>
#include <memory>
#include <stdexcept>
#include <algorithm>

using namespace std;
class Kugla{
    
    double x,y,z,r;
    double eps=pow(10,-10);
    
    public:
    //PRVI KONSTRUKTOR
    explicit Kugla(double r = 0){
        if(r<0) throw domain_error("Ilegalni poluprecnik");
        this->x=0;
        this->y=0;
        this->z=0;
        this->r=r;
        
    }
   
    //DRUGI KONSTRUKTOR
    Kugla(double X, double Y, double Z, double R = 0){
        if(R<0) throw domain_error("Ilegalni poluprecnik");
        this->x=X;
        this->y=Y;
        this->z=Z;
        this->r=R;
    }
    //TRECI KONSTRUKTOR
    explicit Kugla(const  tuple<double, double, double> &centar, double R = 0){
        
        double X,Y,Z;
        
        tie(X,Y,Z)=centar;
        
        this->x=X;
        this->y=Y;
        this->z=Z;
        if(R<0) throw domain_error("Ilegalni poluprecnik");

        this->r=R;
        
    }
    
    double DajX() const{ return Kugla::x;}
    
    double DajY() const{ return Kugla::y;}
    
    double DajZ() const{ return Kugla::z;}
    
    tuple<double, double, double> DajCentar() const{ return make_tuple(this->x,this->y,this->z); }
    
    double DajPoluprecnik() const{ return Kugla::r; }
   
    double DajPovrsinu() const{
        
        double P;
        double PI;
        PI=4*atan(1);
        
        P=4*PI*pow(this->r,2);
        
        return P;
        
    }
    
    double DajZapreminu() const{
        
        double V;
        double PI;
        PI=4*atan(1);
        
        V=(4/3)*PI*pow(this->r,3);
        
        return V;
        
    }   
   
    Kugla &PostaviX(double x){
        this->x=x;
        return *this;
    }
    Kugla &PostaviY(double y){
        this->y=y;
        return *this;
    }
    Kugla &PostaviZ(double z){
        this->z=z;
        return *this;
    }
    
    
    Kugla &PostaviCentar(double x, double y, double z){
        this->x=x;
        this->y=y;
        this->z=z;
        
        return *this;
    }
    
    
    Kugla &PostaviCentar(const  tuple<double, double, double> &centar){
        
        double X,Y,Z;
        
        tie(X,Y,Z)=centar;
        
        this->x=X;
        this->y=Y;
        this->z=Z;
        
        return *this;
        
    }
    
    
    Kugla &PostaviPoluprecnik(double r){
        
        if(r<0) throw domain_error("Ilegalni poluprecnik");
        
        this->r=r;
        return *this;
    }
    
    
    void Ispisi() const{
        cout<<"{"<<"("<<this->x<<","<<this->y<<","<<this->z<<")"<<","<<this->r<<"}"<<endl;
    }
    
    void Transliraj(double delta_x, double delta_y, double delta_z){
        
        double X,Y,Z;
        
        X=this->x+delta_x;
        Y=this->y+delta_y;
        Z=this->z+delta_z;
        
        this->x=X;
        this->y=Y;
        this->z=Z;
        
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2){
        
        if(fabs(k1.x-k2.x)<k1.eps*(fabs(k1.x)+fabs(k2.x)) && fabs(k1.y-k2.y)<k1.eps*(fabs(k1.y)+fabs(k2.y)) && fabs(k1.z-k2.z)<k1.eps*(fabs(k1.z)+fabs(k2.z))
        && fabs(k1.r-k2.r)<k1.eps*(fabs(k1.r)+fabs(k2.r)) )return true;
        return false;
        
    }
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2){
        
        if(fabs(k1.r-k2.r)<k1.eps*(fabs(k1.r)+fabs(k2.r)))return true;
        return false;
    }
    
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2){
        if(fabs(k1.x-k2.x)<k1.eps*(fabs(k1.x)+fabs(k2.x)) && 
           fabs(k1.y-k2.y)<k1.eps*(fabs(k1.y)+fabs(k2.y)) && 
           fabs(k1.z-k2.z)<k1.eps*(fabs(k1.z)+fabs(k2.z)))return true;
        return false;
    }
    
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2){
        
        double d,rd;
        rd=fabs(k1.r+k2.r);
        d=sqrt(pow(k2.x-k1.x,2)+pow(k2.y-k1.y,2)+pow(k2.z-k1.z,2));
        
        if(fabs(d-rd)<k1.eps*(fabs(d)+fabs(rd)))return true;
        return false;
        
    }
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2){
        double d,rd;
        rd=fabs(k1.r-k2.r);
        d=sqrt(pow(k2.x-k1.x,2)+pow(k2.y-k1.y,2)+pow(k2.z-k1.z,2));
        if(!(DaLiSuKoncentricne(k1,k2))){
            if(fabs(rd-d)<k1.eps*(fabs(rd)+fabs(d)))return true;}
        return false;
        
    }
    
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2){
        if(DaLiSeSijeku(k1,k2))return true;
        return false;
        
    }
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2){
        double d,r1,r2;
        d=sqrt(pow(k2.x-k1.x,2)+pow(k2.y-k1.y,2)+pow(k2.z-k1.z,2));
        
        if(k1.r>k2.r){
            r1=k1.r;
            r2=k2.r;
        }
        if(k1.r<=k2.r){
            r1=k2.r;
            r2=k1.r;
        }
        
        if(r2>fabs(d-r1))return true;
        return false;
        
    }
    
    bool DaLiSadrzi(const Kugla &k) const{
        double d;
        d=sqrt(pow(this->x-k.x,2)+pow(this->y-k.y,2)+pow(this->z-k.z,2));
        
        if(d<this->r || d<k.r)return true;
        return false;
        
    }
     friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2){
        double d;
        
        d=sqrt(pow(k2.x-k1.x,2)+pow(k2.y-k1.y,2)+pow(k2.z-k1.z,2));
        return d;
    }
    
};

  

int main (){
    int n;
    cout<<"Unesite broj kugla: ";
   
   do{
       cin>>n;
        if(n<=0){cout<<"Neispravan broj kugli, unesite ponovo!"<<endl; cin.clear();
            cin.ignore(10000,'\n');}
       else break;
   }while(1==1);
    
    vector<shared_ptr<Kugla>> v_pok;
    double x,y,z,r;
    for(int i=0;i<n;i++){
        
        cout<<"Unesite centar "<<i+1<<". kugle: ";
        if(!(cin>>x>>y>>z)){
            cout<<"Neispravan centar"<<endl;
            cin.clear();
            cin.ignore(10000,'\n');
            i--;
            continue;
        }
        cout<<"Unesite poluprecnik "<<i+1<<". kugle: ";
        if(!(cin>>r)){
            cout<<"Ilegalan poluprecnik"<<endl;
            cin.clear();
            cin.ignore(10000,'\n');
            i--;
            continue;
        }
        if(r<0){
            cout<<"Ilegalan poluprecnik"<<endl;
            cin.clear();
            cin.ignore(10000,'\n');
            i--;
            continue;
        }
        
        Kugla k(x,y,z,r);
        shared_ptr<Kugla> pok=make_shared<Kugla>(k);
        v_pok.push_back(pok);
    }
    
    double delta_z,delta_y,delta_x;
    
    cout<<"Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    while(1==1){
        if(!(cin>>delta_x>>delta_y>>delta_z)){
            cout<<"Neispravni parametri translacije, unesite ponovo!"<<endl;
            cin.clear();
            cin.ignore(10000,'\n');
            continue;
        }
        else break;
    }
    
    vector<shared_ptr<Kugla>> v;
    v.resize(v_pok.size());


    transform(v_pok.begin(),v_pok.end(),v.begin(),[delta_x,delta_y,delta_z](shared_ptr<Kugla> p){ p->Transliraj(delta_x,delta_y,delta_z);return p;});
    
    sort(v.begin(),v.end(), [](shared_ptr<Kugla> p1, shared_ptr<Kugla> p2){return p1->DajZapreminu()<p2->DajZapreminu(); });
    
    cout<<"Kugle nakon obavljenje transformacije imaju sljedece vrijednosti:"<<endl;

    for_each(v.begin(),v.end(),[](shared_ptr<Kugla> p){ p->Ispisi();});
    
    cout<<"Kugla sa najvecom povrsinom je: ";
    
    auto pok=*max_element(v.begin(),v.end(), [](shared_ptr<Kugla> p1,shared_ptr<Kugla> p2){return p1->DajPovrsinu()<p2->DajPovrsinu();});
    
    pok->Ispisi();
    
    int br=0,br1=0;
    for_each(v.begin(),v.end(),[v,br,&br1](shared_ptr<Kugla> p1)mutable{
        for_each(v.begin()+br,v.end(), [br,p1,&br1](shared_ptr<Kugla> p2)mutable { 
            if(DaLiSeSijeku(*p1,*p2)) {
                br1++;
                cout<<"Presjecaju se kugle: ";
                p1->Ispisi();
                p2->Ispisi();
            }
        });
        br++;
    });
    
    if(br1==0)cout<<"Ne postoje kugle koje se presjecaju!";
 

	return 0;
}
