/B2017/2018: Zadaća 4, Zadatak 2
#include <iostream>
#include <tuple>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

class NepreklapajucaKugla;

struct Cvor{
    NepreklapajucaKugla* nesto;
    Cvor *p;
};

class NepreklapajucaKugla{
double x,y,z,r;
static Cvor *pocetak;
Cvor *zadnji;
public:
    explicit NepreklapajucaKugla(double r = 0){
        //std::cout << "pozvana prva" << std::endl;
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        //p = this;
        //p->NepreklapajucaKugla::x = 0; p->NepreklapajucaKugla::y = 0; p->NepreklapajucaKugla::z = 0; p->NepreklapajucaKugla::r = r;
        //NepreklapajucaKugla::x = 0; NepreklapajucaKugla::y = 0; NepreklapajucaKugla::z = 0; NepreklapajucaKugla::r = r;
        //if(pocetak == nullptr) pocetak = p;
        //else {
        //    for(auto q = p; q != pocetak; q--){
        //        if(q->DajPoluprecnik() + p->DajPoluprecnik() > RastojanjeCentara(*p, *q) ) std::cout << " greska";
        //    }
        //}
        
        
    }
    ~NepreklapajucaKugla(){
    }
    NepreklapajucaKugla(double x, double y, double z, double r = 0){
        bool tacno = false;
        //std::cout << "pozvana druga" << std::endl;
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        //auto q = new NepreklapajucaKugla;
        
        //std::cout << pocetak;
        //(*this).p-> new NepreklapajucaKugla;
        //(*this).p-> = 
        NepreklapajucaKugla::x = x; NepreklapajucaKugla::y = y; NepreklapajucaKugla::z = z; NepreklapajucaKugla::r = r;
        //std::cout << std::endl << "x je " << NepreklapajucaKugla::x << std::endl;
        if(pocetak == nullptr){
            Cvor* novi(new Cvor{new NepreklapajucaKugla, nullptr}); 
            novi-> nesto -> NepreklapajucaKugla::x = x; novi-> nesto -> NepreklapajucaKugla::y = y; novi-> nesto -> NepreklapajucaKugla::z = z; novi-> nesto -> NepreklapajucaKugla::r = r;
            zadnji = novi; pocetak = novi;
            delete novi -> nesto;
            //delete novi;
        }
        else {
            Cvor* novi( new Cvor{new NepreklapajucaKugla, nullptr});// novi -> p = nullptr;
            novi-> nesto -> NepreklapajucaKugla::x = x; novi-> nesto -> NepreklapajucaKugla::y = y; novi-> nesto -> NepreklapajucaKugla::z = z; novi-> nesto -> NepreklapajucaKugla::r = r;
            //std::cout << novi-> nesto -> NepreklapajucaKugla::x;
            novi -> p = pocetak;
            pocetak = novi;
            //zadnji = novi;
            //std::cout << "adresa pocetka " << pocetak << std::endl;
            int i = 0;
            //q = pocetak;
            for(Cvor *neki = pocetak; neki != nullptr; neki = neki -> p){
                //if (neki == zadnji) break;
                //std::cout << i++ << ", " << neki->nesto->x << ", " ;
                //neki->nesto->Ispisi();
                //if(i > 0 && pocetak -> nesto -> r + neki -> nesto -> r > RastojanjeCentara(*(pocetak -> nesto), *(neki -> nesto))) std::cout << "sijeku se"<<std::endl;
                //if(neki->nesto->x == pocetak -> nesto ->x && i >0) std::cout <<"isti su";
                if(i >0){
                std::cout << "Sijeku se!? " <<(pocetak -> nesto -> r + neki -> nesto -> r > RastojanjeCentara(*(pocetak -> nesto), *(neki -> nesto))) << std::endl;
                //~NepreklapajucaKugla();
                //delete this;
                    //tacno = true;
                    delete novi -> nesto;
                    delete novi;
                    pocetak = pocetak -> p;
                    throw std::logic_error("Nedozvoljeno preklapanje");
                }
                i++;
            }
            //if(!tacno) delete novi -> nesto;
        }

    }
    explicit NepreklapajucaKugla(const std::tuple<double, double, double> &centar, double r = 0){
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        NepreklapajucaKugla::x = std::get<0>(centar); NepreklapajucaKugla::y = std::get<1>(centar); NepreklapajucaKugla::z = std::get<2>(centar); NepreklapajucaKugla::r = r;
    }
    double DajX() const{
        return x;
    }
    double DajY() const{
        return y;
    }
    double DajZ() const{
        return z;
    }
    std::tuple<double, double, double> DajCentar() const{
        return std::make_tuple(x, y, z);
    }
    double DajPoluprecnik() const{
        return r;
    }
    double DajPovrsinu() const{
        return 4 * 4 * atan(1) * r * r;
    }
    double DajZapreminu() const{
        return 4 / 3 * 4 * atan(1) * r * r * r;
    }
    NepreklapajucaKugla &PostaviX(double x){
        (*this).x = x;
        return *this;
    }
    NepreklapajucaKugla &PostaviY(double y){
        (*this).y = y;
        return *this;
    }
    NepreklapajucaKugla &PostaviZ(double z){
        (*this).z = z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(double x, double y, double z){
        (*this).x = x; (*this).y = y; (*this).z = z;
        return *this;
    }
    NepreklapajucaKugla &PostaviCentar(const std::tuple<double, double, double> &centar){
        (*this).x = std::get<0>(centar); (*this).y = std::get<1>(centar); (*this).z = std::get<2>(centar);
        return *this;
    }
    NepreklapajucaKugla &PostaviPoluprecnik(double r){
        if(r < 0) throw std::domain_error("Ilegalan poluprecnik");
        (*this).r = r;
        return *this;
    }
    void Ispisi() const{
        std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}" << std::endl;
    }
    void Translatiraj(double delta_x, double delta_y, double delta_z){
        (*this).x += delta_x; (*this).y += delta_y; (*this).z += delta_z;
    }
    bool DaLiSadrzi(const NepreklapajucaKugla &k) const{
        //std::cout << std::endl << (*this).r << " , novi" << k.r << " RastojanjeCentara " << RastojanjeCentara((*this), k) <<std::endl;
        //if((*this).r < k.r) 
        return abs((*this).r - k.r) >= RastojanjeCentara((*this), k);
        //else return k.r <= RastojanjeCentara((*this), k);
    }
    friend double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2);
};



Cvor* NepreklapajucaKugla::pocetak = nullptr;

double RastojanjeCentara(const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2){
    return sqrt(pow((k1.x-k2.x),2)+pow((k1.y-k2.y),2)+pow((k1.z-k2.z),2));
}

void Unos(double &x, double &y, double &z, int nesto, int brojac){
    while(!(std::cin >> x >> y >> z)){
        std::cin.clear();
        std::cin.ignore(9999, '\n');
        if(nesto == 1) {
            std::cout << "Neispravan centar" << std::endl;
            std::cout << "Unesite centar " << brojac + 1 << ". kugle: ";
        }
        if(nesto == 0) std::cout << "Neispravni parametri translacije, unesite ponovo!" << std::endl;
    }
}

int main ()
{
    std::cout << "Unesite broj kugla: ";
    int broj(-1);
    while(!(std::cin >> broj)||broj <= 0){
        //std::cin >> broj;
        std::cin.clear();
        std::cin.ignore(9999, '\n');
        if(broj <= -1) std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
        else std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
    }
    std::vector<std::shared_ptr<NepreklapajucaKugla>> vektor(broj);
    double x, y, z, r(-1);
    int brojac(0);
    for(;;){
        std::cout << "Unesite centar " << brojac + 1 << ". kugle: ";
        Unos(x,y,z, 1, brojac);
        std::cout << "Unesite poluprecnik " << brojac + 1 << ". kugle: ";
        while(!(std::cin >> r) || r < 0){
            std::cin.clear();
            std::cin.ignore(9999, '\n');
            if(r < 0){
                std::cout << "Ilegalan poluprecnik" << std::endl;
                std::cout << "Unesite centar " << brojac + 1 << ". kugle: ";
                Unos(x, y, z, 1, brojac);
                std::cout << "Unesite poluprecnik " << brojac + 1 << ". kugle: ";
            }
            else {
                std::cout << "Ilegalan poluprecnik" << std::endl;
                std::cout << "Unesite centar " << brojac + 1 << ". kugle: ";
                Unos(x, y, z, 1, brojac);
                std::cout << "Unesite poluprecnik " << brojac + 1 << ". kugle: ";
            }
        }try{
            vektor[brojac] = std::make_shared<NepreklapajucaKugla> (x, y, z, r);
        }
        catch(...){brojac-=2;}
        //if(vektor[brojac]==nullptr) brojac--;
        brojac++;
            std::cout << std::endl << "Brojac je: " << brojac << std::endl;
        if(brojac==broj) break;
    }
    /*std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    double dx, dy, dz;
    Unos(dx, dy, dz, 0, brojac);
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
    std::transform(vektor.begin(), vektor.end(), vektor.begin(),
        [=](std::shared_ptr<NepreklapajucaKugla>& prvo) -> std::shared_ptr<NepreklapajucaKugla> {
            (*prvo).PostaviX(dx+(*prvo).DajX()); (*prvo).PostaviY(dy+(*prvo).DajY()); (*prvo).PostaviZ(dz+(*prvo).DajZ());
            return prvo;
        });
    std::sort(vektor.begin(), vektor.end(),
    [](const std::shared_ptr<NepreklapajucaKugla>& prvo, const std::shared_ptr<NepreklapajucaKugla>& drugo){
        return (*prvo).DajZapreminu()<(*drugo).DajZapreminu();
    });*/
    std::cout << "velicina vektora je: "<<vektor.size() << std::endl;
    std::for_each(vektor.begin(), vektor.end(),
        [](std::shared_ptr<NepreklapajucaKugla>& prvo){
            return prvo->Ispisi();
        });
    std::cout << "Kugla sa najvecom povrsinom je: ";
    (**(std::max_element(vektor.begin(), vektor.end(),
    [](std::shared_ptr<NepreklapajucaKugla>& prvo, std::shared_ptr<NepreklapajucaKugla>& drugo){
        return (*prvo).DajPovrsinu()<(*drugo).DajPovrsinu();
    }))).Ispisi();
    brojac=1;
    bool tacno(false);
    //(*vektor[brojac]).Ispisi();
	/*std::for_each(vektor.begin(), vektor.end(),
	    [&](const std::shared_ptr<NepreklapajucaKugla> &prvo) -> void{
	        std::for_each(vektor.begin()+brojac, vektor.end(),
	            [&](const std::shared_ptr<NepreklapajucaKugla> &drugo) -> void{
	                //std::cout << "Pozvano" ;
	                if(DaLiSeSijeku((*prvo), (*drugo))){
	                    std::cout << "Presjecaju se kugle: ";
	                    (*prvo).Ispisi(); 
	                    (*drugo).Ispisi();
	                    tacno = true;
	                };
	            });
	        brojac++;
	    });
	if(!tacno) std::cout << "Ne postoje kugle koje se presjecaju!";*/
	//std::cout << "precnik prve: " << (*vektor[0]).DajPoluprecnik() << ", precnik druge: " << (*vektor[2]).DajPoluprecnik() << ", udaljenost izmedju dvije tacke je: " << RastojanjeCentara(*vektor[0], *vektor[2]);
	//
	//std::cout << std::endl << DaLiSeDodirujuIznutra((*vektor[0]),(*vektor[1])) << std::endl;
	return 0;
}