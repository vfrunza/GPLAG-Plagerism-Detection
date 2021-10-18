/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>

using namespace std;



class NepreklapajucaKugla
{
    double x,y,z,r;

    double pi=atan(1)*4;

    double ep=pow(10,-10);
    
    static NepreklapajucaKugla *stat_pointer;

    friend bool Presjek(NepreklapajucaKugla &k1,NepreklapajucaKugla &k2) {

        double udaljenost=sqrt(pow(k1.x-k2.x,2)+pow(k1.y-k2.y,2)+pow(k1.z-k2.z,2));

        double min,max;

        if(k1.r>k2.r) {
            max=k1.r;
            min=k2.r;
        } else {
            max=k2.r;
            min=k1.r;
        }


        if(k1.DaLiSadrzi(k2))return true;




        if(udaljenost==k1.r || udaljenost==k2.r ||udaljenost==k1.r+k2.r) return true;

        return(min>=fabs(max-udaljenost));

    }
    
    friend void Testiraj(NepreklapajucaKugla &k1) {

        
        NepreklapajucaKugla*pom=NepreklapajucaKugla::stat_pointer;
    
        k1.pointer=stat_pointer;
        
        while(pom!=nullptr) {

        if(Presjek(k1,*pom)){
                throw logic_error("Nedozvoljeno preklapanje");
            }
            pom=pom->pointer;
        }
        stat_pointer=&k1;
    }

    friend void TestirajStari(NepreklapajucaKugla &k1){
        
        NepreklapajucaKugla*pom=NepreklapajucaKugla::stat_pointer;
    
        while(pom!=nullptr) {

        if(Presjek(k1,*pom) && pom!=&k1){
                throw logic_error("Nedozvoljeno preklapanje");
            }
            pom=pom->pointer;
        }
        
    }

public:


    NepreklapajucaKugla *pointer=nullptr;//prosli


   ~NepreklapajucaKugla(){
        
        
        
        
        if(this->pointer==nullptr){
            
            NepreklapajucaKugla* pom=stat_pointer;
            
            if(pom==this)
                stat_pointer=nullptr;
            
            else while(pom->pointer!=this)
                pom=pom->pointer;
            
            pom->pointer=nullptr;
        }
        else if(this==stat_pointer){
            stat_pointer=stat_pointer->pointer;
        }
        
        else
        {
            NepreklapajucaKugla* pom=stat_pointer;
            while(pom->pointer!=this){
                pom=pom->pointer;
            }
            pom->pointer=this->pointer;
        }
        
        
    } 
    

    explicit NepreklapajucaKugla(double r = 0):x(0),y(0),z(0) {

        Testiraj(*this);
        if (r<0) throw domain_error("Ilegalan poluprecnik");

    }

     NepreklapajucaKugla(double x, double y, double z, double r = 0):x(x),y(y),z(z),r(r) {
        Testiraj(*this);

    }



    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0) {

        double x,y,z;
        tie(x,y,z)=centar;
        this->x=x;
        this->y=y;
        this->z=z;
        this->r=r;
        Testiraj(*this);


    }

    NepreklapajucaKugla &operator=(const NepreklapajucaKugla &k1) =delete;
    
    

    double DajX() const {
        return this->x;
    }

    double DajY() const {
        return this->y;
    }

    double DajZ() const {
        return this->z;
    }

    std::tuple<double, double, double> DajCentar() const {
        return make_tuple(this->x,this->y,this->z);
    }

    double DajPoluprecnik() const {
        return this->r;
    }

    double DajPovrsinu() const {

        return 4*pi*r*r;

    }

    double DajZapreminu() const {

        return (4/3)*pi*r*r*r;

    }

    NepreklapajucaKugla &PostaviX(double x) {
        
        double t1=x;
        try{
        this->x=x;
        TestirajStari(*this);
        }
        catch(exception &ex){
            cout<<ex.what()<<endl;
            this->x=t1;
        }
        return *this;
    }

    NepreklapajucaKugla &PostaviY(double y) {
        double t1=y;
        try{
        this->y=y;
        TestirajStari(*this);
        }
        catch(exception &ex){
            cout<<ex.what()<<endl;
            this->y=t1;
        }
        return *this;
    }

    NepreklapajucaKugla &PostaviZ(double z) {
        double t1=z;
        try{
        this->z=z;
        TestirajStari(*this);
        }
        catch(exception &ex){
            cout<<ex.what()<<endl;
            this->z=t1;
        }
        return *this;
    }

    NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {

 double t1(this->x),t2(this->y),t3(this->z);
        try {
          
            this->x=x;
            this->y=y;
            this->z=z;
            TestirajStari(*this);
        } catch(exception &ex) {
            cout<<ex.what()<<endl;
            this->x=t1;
            this->y=t2;
            this->z=t3;
        }

        return *this;


    }

    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {


        double t1(this->x),t2(this->y),t3(this->z);
        try {
            double x,y,z;
            tie(x,y,z)=centar;
            this->x=x;
            this->y=y;
            this->z=z;
            TestirajStari(*this);
        } catch(exception &ex) {
                cout<<ex.what()<<endl;
                this->x=t1;
            this->y=t2;
            this->z=t3;
        }

        return *this;
    }

    NepreklapajucaKugla &PostaviPoluprecnik(double r) {

        if (r<0) throw domain_error("Ilegalan poluprecnik");

        double temp=this->r;
        try {
            this->r=r;
            TestirajStari(*this);
        } catch(exception &ex) {
            this->r=temp;
            cout<<ex.what()<<endl;
        }
        //return *this;
    }

    void Ispisi() const {

        cout<<"{"<<"("<<this->x<<","<<this->y<<","<<this->z<<")"<<","<<r<<"}"<<endl;

    }

    void Transliraj(double delta_x, double delta_y, double delta_z) {

        try {


            this->x+=delta_x;
            this->y+=delta_y;
            this->z+=delta_z;
            Testiraj(*this);
        } catch(exception &ex) {
            cout<<ex.what()<<endl;
            this->x-=delta_x;
            this->y-=delta_y;
            this->z-=delta_z;

        }
    }

    bool DaLiSadrzi(const NepreklapajucaKugla &k) const {

        double udaljenost=sqrt(pow(this->x-k.x,2)+pow(this->y-k.y,2)+pow(this->z-k.z,2));

        return (fabs(this->r-k.r)>=udaljenost);
    }

    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2) {
        double udaljenost=sqrt(pow(k1.x-k2.x,2)+pow(k1.y-k2.y,2)+pow(k1.z-k2.z,2));
        return udaljenost;
    }

};


 NepreklapajucaKugla* NepreklapajucaKugla::stat_pointer=nullptr;


int main ()
{

   

    vector<shared_ptr<NepreklapajucaKugla>> v,vt;

    int n;
    cout<<"Unesite broj kugli: ";

    while(1) {
        cin>>n;
        if(n<=0) {
            cout<<"Neispravan broj kugli, unesite ponovo!"<<endl;
            cin.clear();
            cin.ignore(10000, '\n');
        } else break;
    }

    for(int i=0; i<n; i++) {
        double p=0,x=0,y=0,z=0;



        cout<<"Unesite centar za "<<i+1<<". kuglu: ";
        while(1) {
            if(!(cin>>x>>y>>z)) {
                cout<<"Neispravan centar, unesite ponovo:"<<endl;
                cin.clear();
                cin.ignore(10000, '\n');
            } else break;
        }


        cout<<"Unesite poluprecnik: ";

        while(1) {
            if(!(cin>>p )) {
                cout<<"Neispravan poluprecnik, unesite ponovo:"<<endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }

            else if(p<0) {
                cout<<"Neispravan poluprecnik, unesite ponovo:"<<endl;
                cin.clear();
                cin.ignore(10000, '\n');
            } else break;

        }
        try {

            shared_ptr<NepreklapajucaKugla> ptr=make_shared<NepreklapajucaKugla>(x,y,z,p);

            v.push_back(ptr);

        }

        catch(exception &ex) {
            cout<<ex.what()<<endl;
            i--;
        }
    }

    
   
    
    sort(v.begin(),v.end(),[](shared_ptr<NepreklapajucaKugla> k1,shared_ptr<NepreklapajucaKugla> k2) {
        return k1->DajZapreminu()<k2->DajZapreminu();
    });
    cout<<"\nKugle nakon obavljenog sortiranja: "<<endl;
    for_each(v.begin(),v.end(),[](shared_ptr<NepreklapajucaKugla> k) {
        k->Ispisi();
    });

    

    return 0;
}
    
    
    // 3 5 5 5 1 0 0 0 2 3 3 3 1    
    
    // 3 0 0 0 2 3 3 3 1 50 50 50 1
    
    //3 0 0 0 2 3 3 3 1 6 6 6 1
    
    //3 0 0 0 2 9 9 9 1 1 1 1 3
    
    //3 0 0 0 2 5 5 5 3 13 13 13 4
    
/*3
2 3 1
5
10 7 8 xx
2      XX
4 6 3
7
5 8 4
1*/