#include <iostream>
#include <cmath>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <algorithm>
#include <memory>
#include <vector>
#include <new>

static constexpr double eps(pow(10,-10));
static constexpr double PI(3.14159265359);

int broj(1);
int pr(0);

class NepreklapajucaKugla{
    double x, y, z, r;
    NepreklapajucaKugla *prethodni;
    static NepreklapajucaKugla *zadnji;
   
    static bool DaLiSePreklapaju(double x, double y, double z, double r, NepreklapajucaKugla &k){
        //if(std::fabs(r-0)<eps || std::fabs(k.DajPoluprecnik()-0)<eps) return false;
        double rastojanje=std::sqrt(std::pow((x-k.DajX()),2)+std::pow((y-k.DajY()),2)+std::pow((z-k.DajZ()),2));
        
        if((r+k.DajPoluprecnik())>rastojanje || std::fabs((r+k.DajPoluprecnik())-rastojanje)<eps ) return true;
       
      return false;  
    }
    
    public:
    
        explicit NepreklapajucaKugla(double r=0) {
            for(auto pok=zadnji;pok!=nullptr;pok=pok->prethodni){
            if(DaLiSePreklapaju(0,0,0,r, *pok)) throw std::logic_error("Nedozvoljeno preklapanje");
            }
            this->x=0;
            this->y=0;
            this->z=0;
            this->r=r;
            prethodni=zadnji;
            zadnji = this;
        }
        NepreklapajucaKugla(double x, double y, double z, double r=0){
            for(auto pok=zadnji;pok!=nullptr;pok=pok->prethodni){
            if(DaLiSePreklapaju(x,y,z,r, *pok)) throw std::logic_error("Nedozvoljeno preklapanje");
            }
            this->x=x;
            this->y=y;
            this->z=z;
            this->r=r;
            
            prethodni=zadnji;
            zadnji=this;
        }
        explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r=0){
            
            for(auto pok=zadnji;pok!=nullptr;pok=pok->prethodni){
            if(DaLiSePreklapaju(std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),r, *pok)) throw std::logic_error("Nedozvoljeno preklapanje");
            }
            
            this->x=std::get<0>(centar);
            this->y=std::get<1>(centar);
            this->z=std::get<2>(centar);
            this->r=r; 
            
            prethodni=zadnji;
            zadnji=this;
        }
        
        ~NepreklapajucaKugla(){
            if(this==zadnji){
                auto *temp(zadnji->prethodni);
                if(temp==zadnji||temp==nullptr) zadnji=nullptr;
                else{
                    zadnji = nullptr;
                    zadnji = temp;
                }
            }
            else{
                for(auto pok = zadnji; pok!=nullptr; pok=pok->prethodni)
                if(this==pok->prethodni){
                    auto *temp(pok->prethodni->prethodni);
                    if(temp==nullptr||temp==pok->prethodni) pok->prethodni=nullptr;
                    else{
                        pok->prethodni=nullptr;
                        pok->prethodni=temp;
                    }
                }
            }
        }
        
        double DajX() const {return x; }
        double DajY() const {return y; }
        double DajZ() const {return z; }
        std::tuple<double, double, double> DajCentar() const { return std::make_tuple(x,y,z); };
        
        double DajPoluprecnik() const {return r;}
        double DajPovrsinu() const {
            double p;
            p=4*r*r*PI;
            return p;
        }
        double DajZapreminu() const{
            double z;
            z=pow(r,3)*(4/3)*PI;
            return z;
        }
        NepreklapajucaKugla &PostaviX(double x) {
            for(auto pok=zadnji;pok!=nullptr;pok=pok->prethodni){
            if(DaLiSePreklapaju(x,this->y,this->z,this->r,*pok)) throw std::logic_error("Nedozvoljeno preklapanje");
            }
            this->x= x;
            return *this;
            
        }
        NepreklapajucaKugla &PostaviY(double y) {
            for(auto pok=zadnji;pok!=nullptr;pok=pok->prethodni){
            if(DaLiSePreklapaju(this->x,y,this->z,this->r,*pok)) throw std::logic_error("Nedozvoljeno preklapanje");
            }
            this->y= y; 
            return *this;
        }
        NepreklapajucaKugla &PostaviZ(double z) {
            for(auto pok=zadnji;pok!=nullptr;pok=pok->prethodni){
            if(DaLiSePreklapaju(this->x,this->y,z,this->r,*pok)) throw std::logic_error("Nedozvoljeno preklapanje");
            }
            this->z= z;
            return *this;
        }
        NepreklapajucaKugla &PostaviCentar(double x, double y, double z) {
            for(auto pok=zadnji;pok!=nullptr;pok=pok->prethodni){
            if(DaLiSePreklapaju(x,y,z,this->r,*pok)) throw std::logic_error("Nedozvoljeno preklapanje");}
            this->x = x;
            this->y = y;
            this->z = z;
            return *this;
        }
        NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar) {
            for(auto pok=zadnji;pok!=nullptr;pok=pok->prethodni){
            if(DaLiSePreklapaju(std::get<0>(centar),std::get<1>(centar),std::get<2>(centar),this->r,*pok)) throw std::logic_error ("Nedozvoljeno preklapanje");
            }
            this->x=std::get<0>(centar);
            this->y=std::get<1>(centar);
            this->z=std::get<2>(centar);
            return *this;
        }
        NepreklapajucaKugla &PostaviPoluprecnik(double r){
            if(r<0) throw std::domain_error("Neispravan poluprecnik, unesite ponovo:");
            for(auto pok=zadnji;pok!=nullptr;pok=pok->prethodni){
            if(DaLiSePreklapaju(this->x,this->y,this->z,r,*pok)) throw std::logic_error("Nedozvoljeno preklapanje");}
            this->r=r;
            return *this;
        }
        void Ispisi() const {
            std::cout<<"{("<<this->DajX()<<","<<this->DajY()<<","<<this->DajZ()<<"),"<<DajPoluprecnik()<<"}";
        }
        void Transliraj(double delta_x, double delta_y, double delta_z){
            this->x=this->x+delta_x;
            this->y=this->y+delta_y;
            this->z=this->z+delta_z;
        }
        
        
        bool DaLiSadrzi(const NepreklapajucaKugla &k) const;
        friend double RastojanjeCentara(const NepreklapajucaKugla &k1,const NepreklapajucaKugla &k2);
    
};

NepreklapajucaKugla *NepreklapajucaKugla::zadnji(nullptr);
    
    double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
        double rastojanje=std::sqrt(pow((k1.DajX()-k2.DajX()),2)+pow((k1.DajY()-k2.DajY()),2)+pow((k1.DajZ()-k2.DajZ()),2));
     return rastojanje;
    }
    bool NepreklapajucaKugla::DaLiSadrzi(const NepreklapajucaKugla &k) const {
        double rastojanje=RastojanjeCentara(*this,k);
        if(this->r<k.DajPoluprecnik()){
            if((this->r+rastojanje)<k.DajPoluprecnik()) return true;
        }
        else{
            if((k.DajPoluprecnik()+rastojanje)<this->r) return true;
        }
        return false;
    }


int main ()
{ 
    int n;
    bool validacija(false);
    bool cen(true);
    bool pol(true);
    std::tuple<double, double,double> centar;
    std::cout << "Unesite broj kugli: ";
  
    do{
        validacija = false;
       try{
           std::cin >> n;
            if(!(std::cin)) {
               std::cin.clear();
               std::cin.ignore(1000,'\n');
                throw std::domain_error("Neispravan broj kugli, unesite ponovo!");
            }
            else if(n<=0){
                std::cin.clear();
                std::cin.ignore(1000,'\n');
                throw std::domain_error("Neispravan broj kugli, unesite ponovo!");
            }
            else {
                validacija = true;
            }
       }
       catch(std::domain_error greska){
           std::cout << greska.what() << std::endl;
           validacija = false;
       }
    }while(!validacija);
    
    std::vector<std::shared_ptr<NepreklapajucaKugla>>v_kugli(n,nullptr);
    for(int i=0;i<n;i++){
        
        double x,y,z,r;
        
            std::cout << "Unesite centar za "<< i+1<<". kuglu: ";
            do{
                cen=false;
                
                try{
                    std::cin >> x>>y>>z;
                    if(!(std::cin)){
                        std::cin.clear();
                        std::cin.ignore(1000,'\n');
                        throw std::domain_error("Neispravan centar, unesite ponovo:");
                    }
                    else{
                        cen=true;
                    }
                }
                catch(std::domain_error e){
                    std::cout << e.what() << std::endl;
                    cen=false;
                }
            }while (!cen); 
            
           
            std::cout << "Unesite poluprecnik: ";
            do{
                pol=false;
            
                try{   
                    std::cin>>r;
                    if(!(std::cin)){
                        std::cin.clear();
                        std::cin.ignore(1000,'\n');
                        throw std::domain_error("Neispravan poluprecnik, unesite ponovo:");
                    }
                    else if(r<0){
                        std::cin.clear();
                        std::cin.ignore(1000,'\n');
                        throw std::domain_error("Neispravan poluprecnik, unesite ponovo:");
                    }
                    else pol=true;
                }
                catch(std::domain_error e){
                    std::cout << e.what() << std::endl;
                    pol=false;
                }
            } while (!pol);
        
        centar=std::make_tuple(x,y,z); 
        try{
            auto novaKugl = std::shared_ptr<NepreklapajucaKugla>(new NepreklapajucaKugla(x,y,z,r));
            v_kugli.at(i)=novaKugl;
        }
        catch(std::logic_error e){
            std::cout << e.what() << std::endl;
            i--;
        }
        
    }
    std::cout << std::endl;
    std::cout << "Kugle nakon obavljenog sortiranja: " << std::endl;
    std::sort(v_kugli.begin(),v_kugli.end(),[](std::shared_ptr<NepreklapajucaKugla>k1,std::shared_ptr<NepreklapajucaKugla>k2)->bool{return k1->DajPovrsinu()<k2->DajPovrsinu();});
    std::for_each(v_kugli.begin(),v_kugli.end(),[](std::shared_ptr<NepreklapajucaKugla>k)->void{k->Ispisi(); std::cout << std::endl;});
    
	return 0;
}

