/B2017/2018: Zadaća 4, Zadatak 1
#include <iostream>
#include <stdexcept>
#include <tuple>
#include <vector>
#include <memory>
#include <cmath>
#include <algorithm> 
#include <iterator>
#include <cctype>

const double PI = std::atan(1) * 4;
const double EPSILON = 0.0000000001;

class Kugla
{
    double poluprecnik;
    std::tuple<double, double, double> koordinate;
    public:
    explicit Kugla(double r = 0) 
    {
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik"); 
        else poluprecnik = r;
    }
    Kugla(double x, double y, double z, double r = 0)
    {
        std::get<0>(koordinate) = x;
        std::get<1> (koordinate) = y;
        std::get<2> (koordinate) = z;
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik"); 
        else poluprecnik = r;
    }
    explicit Kugla(const std::tuple<double, double, double> &centar, double r = 0)
    {
        std::get<0>(koordinate) = std::get<0> (centar);
        std::get<1>(koordinate) = std::get<1> (centar);
        std::get<2>(koordinate) = std::get<2> (centar);
        std::make_tuple(std::get<0>(centar), std::get<1> (centar), std::get<2> (centar));
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik"); 
        else poluprecnik = r;
    }
    double DajX() const {return std::get<0> (koordinate);}
    double DajY() const {return std::get<1> (koordinate);}
    double DajZ() const {return std::get<2> (koordinate);}
    std::tuple<double, double, double> DajCentar() const {return {std::make_tuple(std::get<0>(koordinate), std::get<1> (koordinate), std::get<2> (koordinate))};}
    double DajPoluprecnik() const {return poluprecnik;};
    double DajPovrsinu() const {return (4 * poluprecnik * poluprecnik * PI);}
    double DajZapreminu() const {return ((4./3.) * poluprecnik * poluprecnik * poluprecnik * PI);}
    Kugla &PostaviX(double x) {std::get<0> (koordinate) = x; return *this;} //this moras zbog reference
    Kugla &PostaviY(double y) {std::get<1> (koordinate) = y; return *this;}
    Kugla &PostaviZ(double z) {std::get<2> (koordinate) = z; return *this;}
    Kugla &PostaviCentar(double x, double y, double z)
    {
        std::get<0> (koordinate) = x;
        std::get<1> (koordinate) = y;
        std::get<2> (koordinate) = z;
        return *this;
    }
    Kugla &PostaviCentar(const std::tuple<double, double, double> &centar) 
   {
        std::get<0>(koordinate) = std::get<0> (centar);
        std::get<1>(koordinate) = std::get<1> (centar);
        std::get<2>(koordinate) = std::get<2> (centar);
        std::make_tuple(std::get<0>(centar), std::get<1> (centar), std::get<2> (centar));
        return *this;
    }
    Kugla &PostaviPoluprecnik(double r) 
    {
        if (r < 0) throw std::domain_error ("Ilegalan poluprecnik"); 
        else poluprecnik = r;
        return *this;
    }
    void Ispisi() const
    {
        std::cout << "{(" << DajX() << "," << DajY() << "," << DajZ() << ")," << DajPoluprecnik() << "}";
    }
    void Transliraj(double delta_x, double delta_y, double delta_z)
    {
        std::get<0> (koordinate) += delta_x;
        std::get<1> (koordinate) += delta_y;
        std::get<2> (koordinate) += delta_z;
    }
    friend bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2); //
    friend bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2); //
    friend bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2); //
    friend bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2); //
    friend bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2); //
    friend bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2); //
    friend bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2); //
    bool DaLiSadrzi(const Kugla &k) const ;
    friend double RastojanjeCentara(const Kugla &k1, const Kugla &k2);  //
};
bool DaLiSuIdenticne(const Kugla &k1, const Kugla &k2)
{
    //if ( (k1.std::get<0>(koordinate) == k2.std::get<0>(koordinate)) && (k1.std::get<1>(koordinate) == k2.std::get<1>(koordinate)) && (k1.std::get<2>(koordinate) == k2.std::get<2>(koordinate)) && (k1.poluprecnik == k2.poluprecnik)) return true;
    if ( fabs(k1.DajX() - k2.DajX()) < EPSILON * ( fabs(k1.DajX()) - fabs(k2.DajX()) ) &&  fabs(k1.DajY() - k2.DajY()) < EPSILON * ( fabs(k1.DajY()) - fabs(k2.DajY()) ) && fabs(k1.DajZ() - k2.DajZ()) < EPSILON * ( fabs(k1.DajZ()) - fabs(k2.DajZ()) ) && fabs(k1.DajPoluprecnik() - k2.DajPoluprecnik()) < EPSILON * (fabs(k1.DajPoluprecnik()) - fabs(k2.DajPoluprecnik()) )) return true;
    else return false;
}

bool DaLiSuPodudarne(const Kugla &k1, const Kugla &k2)
{
    if ( fabs(k1.DajPoluprecnik() - k2.DajPoluprecnik()) < EPSILON * (fabs(k1.DajPoluprecnik()) - fabs(k2.DajPoluprecnik()) ) ) return true;
    else return false;
}

bool DaLiSuKoncentricne(const Kugla &k1, const Kugla &k2)
{
    //if ( (k1.std::get<0>(koordinate) == k2.std::get<0>(koordinate)) && (k1.std::get<1>(koordinate) == k2.std::get<1>(koordinate)) && (k1.std::get<2>(koordinate) == k2.std::get<2>(koordinate)) ) return true;
    if ( fabs(k1.DajX() - k2.DajX()) < EPSILON * ( fabs(k1.DajX()) - fabs(k2.DajX()) ) &&  fabs(k1.DajY() - k2.DajY()) < EPSILON * ( fabs(k1.DajY()) - fabs(k2.DajY()) ) && fabs(k1.DajZ() - k2.DajZ()) < EPSILON * ( fabs(k1.DajZ()) - fabs(k2.DajZ()) ) ) return true;
    else return false;
}

bool DaLiSeDodirujuIzvana(const Kugla &k1, const Kugla &k2)
{
    std::tuple<double, double, double> c1, c2;
    c1 = k1.DajCentar(); c2 = k2.DajCentar();
    double r1, r2;
    r1 = k1.DajPoluprecnik(); r2 = k2.DajPoluprecnik();
    double rast(sqrt(((std::get<0>(c1) - std::get<0>(c2)) * (std::get<0>(c1)-std::get<0>(c2))) + ((std::get<1>(c1) - std::get<1>(c2)) * (std::get<1>(c1) - std::get<1>(c2))) +((std::get<2>(c1) - std::get<2>(c2)) * (std::get<2>(c1) - std::get<2>(c2)))));
    //if ((rast == r1 + r2) || (rast == fabs(r1 - r2))) return true;
    if (fabs(rast - (r1 + r2)) < EPSILON * (fabs(rast) + fabs(r1 + r2))) return true; 
    else return false;
}

bool DaLiSeDodirujuIznutra(const Kugla &k1, const Kugla &k2)
{
    std::tuple<double, double, double> tacka, tacka2;
    std::get<0> (tacka) = k1.DajX();  std::get<1> (tacka) = k1.DajY();  std::get<2> (tacka) = k1.DajZ();
    std::get<0> (tacka2) = k2.DajX();  std::get<1> (tacka2) = k2.DajY();  std::get<2> (tacka2) = k2.DajZ();
    if (tacka != tacka2) return true;
    else return false;
}

bool DaLiSeSijeku(const Kugla &k1, const Kugla &k2)
{
    //kugle koje se sijeku one se i preklapaju dok obrnuto ne mora vrijediti 
    std::tuple<double, double, double> c1, c2;
    c1 = k1.DajCentar(); c2 = k2.DajCentar();
    double r1, r2;
    r1 = k1.DajPoluprecnik(); r2 = k2.DajPoluprecnik();
    double rast(sqrt(((std::get<0>(c1) - std::get<0>(c2)) * (std::get<0>(c1)-std::get<0>(c2))) + ((std::get<1>(c1) - std::get<1>(c2)) * (std::get<1>(c1) - std::get<1>(c2))) +((std::get<2>(c1) - std::get<2>(c2)) * (std::get<2>(c1) - std::get<2>(c2)))));
    if ((rast < r1 + r2) && (rast > fabs(r1 - r2))) return true;
    else return false;
    
}

bool DaLiSePreklapaju(const Kugla &k1, const Kugla &k2)
{
    if (DaLiSeSijeku(k1,k2)) return true;
    else return false;
}

/*bool Kugla::DaLiSadrzi(const Kugla &k) const
{
    
}*/

double RastojanjeCentara(const Kugla &k1, const Kugla &k2)
{
    return (std::sqrt( ((k1.DajX() - k2.DajX()) * (k1.DajX() - k2.DajX()) ) + ((k1.DajY() - k2.DajY()) * (k1.DajY() - k2.DajY()) ) + ( (k1.DajZ() - k2.DajZ()) * (k1.DajZ() - k2.DajZ()) ) ) );
}

int main ()
{
    try
    {
        int n;
        std::cout << "Unesite broj kugla: ";
        do{
            std::cin >> n;
            std::cin.clear();
            std::cin.ignore(10000,'\n');
            if (n <= 0) std::cout << "Neispravan broj kugli, unesite ponovo!" << std::endl;
            //if(!std::isdigit(std::cin.peek())) {continue;}
            if(!std::isdigit(n)) {continue;}
        } while (n <= 0 );
        
        std::vector<std::shared_ptr<Kugla>> k(n);
        std::tuple<double, double, double> koordinate;
        double poluprecnik;
        //std::cin.clear();
        //std::cin.ignore(10000,'\n');
        for (int i = 0; i < n; i++)
        {
            //std::cout << "Unesite centar " << i+1 << ". kugle: ";
            do
            {
                std::cout << "Unesite centar " << i+1 << ". kugle: ";
                //std::cout << "X = "; 
                std::cin >> std::get<0> (koordinate);//x;
                //std::cout << "Y = ";
                std::cin >> std::get<1> (koordinate);//y;
                //std::cout << "Z = "; 
                std::cin >> std::get<2> (koordinate);//z;
                /*std::cin.clear();
                std::cin.ignore(10000,'\n');
                if (!std::isdigit(std::get<0> (koordinate))) { continue; }
                else if (!std::isdigit(std::get<1> (koordinate))) {continue;}
                else if (!std::isdigit(std::get<2> (koordinate))) {continue;}
            }while (std::isdigit(std::get<0> (koordinate)) || std::isdigit(std::get<1> (koordinate)) || std::isdigit(std::get<2> (koordinate)));
                //std::cout << "r = "; 
            do
            {*/
                std::cout << "Unesite poluprecnik " << i+1 << ". kugle: ";
                std::cin >> poluprecnik;
                //std::cin.clear();
                //std::cin.ignore(10000,'\n');
                if (poluprecnik < 0) std::cout << "Ilegalan poluprecnik " << std::endl;
                //if(!std::isdigit(poluprecnik)) {continue;}//std::cin.clear(); std::cin.ignore(10000,'\n');}
            } while (poluprecnik < 0);
            //dodaj ponopvni unos ako nije broj!
            Kugla kuglica = Kugla(koordinate, poluprecnik);
            k[i] = std::make_shared<Kugla>(kuglica);
        }
        //for (int i = 0; i < n; i++) {std::cout << i+1 << ". kugla: " << std::endl; k[i]->Ispisi(); std::cout << std::endl; }
        //std::cout << std::endl;
        std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
        double delta_x, delta_y, delta_z;
        std::cin >> delta_x; std::cin >> delta_y; std::cin >> delta_z;
        std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: " << std::endl;
        //for petlja
        /*for (int i = 0; i < n; i++) 
        {
            //std::cout << "Translirane kugle pomocu funkcije Transliraj: "; 
            k[i]->Transliraj(delta_x, delta_y, delta_z); 
            //k[i]->Ispisi(); 
            //std::cout << std::endl; 
        }*/
        //funkcija
        std::transform (k.begin(), k.end(), k.begin(), [delta_x, delta_y, delta_z] (std::shared_ptr<Kugla> k1) {k1->Transliraj(delta_x,delta_y,delta_z); return k1;});
        
        //Sortiraj zapremine
        std::sort (k.begin(), k.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {return (k1->DajZapreminu() < k2->DajZapreminu());});
        std::for_each (k.begin(), k.end(), [](const std::shared_ptr<Kugla> &kug) {kug->Ispisi(); std::cout << std::endl;});
        
        //Najveca povrsina
        //funkcija
        std::cout << "Kugla sa najvecom povrsinom je: " ; 
        auto pomocna = *std::max_element (k.begin(), k.end(), [](std::shared_ptr<Kugla> k1, std::shared_ptr<Kugla> k2) {return (k1->DajPovrsinu() < k2->DajPovrsinu());});
        pomocna->Ispisi();
        //for petlja
        /*for (int i  = 0; i < n; i++)
        {
            for (int j = i; j < n; j++) 
            {
                if (k[j]->DajPovrsinu() > k[i]->DajPovrsinu()) k[j]->Ispisi();
            }
        }*/
        
        //da li se presjcaju
        //for petlja
        /*bool test(false);
        for (int i  = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++) 
            {
                if (DaLiSeSijeku(*k[i], *k[j]) == true)  
                {
                    test = true; 
                    std::cout << std::endl << "Presjecaju se kugle: "; 
                    k[i]->Ispisi(); std::cout << std::endl; k[j]->Ispisi(); 
                }
                
            }
        }
        if (test == false) std::cout << std::endl << "Ne postoje kugle koje se presjecaju!";*/
        
        //funkcija
        bool test2(false); //std::cout << std::endl << "Druga varijanta-> test: " << test2;
        auto it_poc (k.begin()); auto it_kr(k.end());
        std::for_each(it_poc, it_kr, [&k, &test2, &it_poc, &it_kr] (std::shared_ptr<Kugla> &k1) 
        {
            std::for_each(it_poc + 1, it_kr, [k1, &test2, &it_kr, &it_poc] (std::shared_ptr<Kugla> &k2) 
            {
                if(DaLiSeSijeku(*k1, *k2) == true) 
                {
                    test2 = true;
                    std::cout << std::endl << "Presjecaju se kugle: ";
                    k1->Ispisi(); std::cout << std::endl; k2->Ispisi();
                }
            }); 
            it_poc++;
        });
        if(test2 == false) std::cout << std::endl << "Ne postoje kugle koje se presjecaju!";
        
    }
    catch (std::domain_error izuzetak)
    {
        std::cout << izuzetak.what() << std::endl;
    }
	return 0;
}