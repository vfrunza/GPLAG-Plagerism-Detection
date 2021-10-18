#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

class Kugla
{
    double x, y, z;
    double r;
    
    static constexpr double pi { 4 * std::atan ( 1 ) };

    void TestPP ( double pp ) { if ( pp < 0 ) throw std::domain_error ( "Ilegalan poluprecnik" ); }
    
    static bool EQ ( double a, double b ) { return std::fabs ( a - b ) < ( 0.0000000001 * ( std::fabs ( a ) + std::fabs ( b ) ) ); }

public:
    explicit Kugla ( double r = 0 ) { TestPP ( r ); Kugla::r = r; x = y = z = 0; }
    
    Kugla ( double x, double y, double z, double r = 0 ) { TestPP ( r ); Kugla::x = x; Kugla::y = y; Kugla::z = z; Kugla::r = r; }
    
    explicit Kugla ( const std::tuple < double, double, double > &centar, double r = 0 )
        { TestPP ( r ); x = std::get < 0 > ( centar ); y = std::get < 1 > ( centar ); z = std::get < 2 > ( centar ); Kugla::r = r; }
        
    double DajX ( void ) const { return x; }
    double DajY ( void ) const { return y; }
    double DajZ ( void ) const { return z; }
    
    std::tuple < double, double, double > DajCentar ( void ) const { return std::tie ( x, y, z ); }
    
    double DajPoluprecnik ( void ) const { return r; }
    
    double DajPovrsinu ( void ) const { return 4 * pi * r * r; }
    double DajZapreminu ( void ) const { return ( DajPovrsinu () * r ) / 3; }
    
    Kugla &PostaviX ( double x ) { Kugla::x = x; return *this; }
    Kugla &PostaviY ( double y ) { Kugla::y = y; return *this; }
    Kugla &PostaviZ ( double z ) { Kugla::z = z; return *this; }
    
    Kugla &PostaviCentar ( double x, double y, double z ) { Kugla::x = x; Kugla::y = y; Kugla::z = z; return *this; }
    Kugla &PostaviCentar ( const std::tuple < double, double, double > &centar )
        { x = std::get < 0 > ( centar ); y = std::get < 1 > ( centar ); z = std::get < 2 > ( centar ); return *this; }
    
    Kugla &PostaviPoluprecnik ( double r ) { TestPP ( r ); Kugla::r = r; return *this; }
    
    void Ispisi ( void ) const { std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}"; }
    
    void Transliraj ( double delta_x, double delta_y, double delta_z ) { x += delta_x; y += delta_y; z += delta_z; }
    
    friend bool DaLiSuIdenticne ( const Kugla &, const Kugla & );
    friend bool DaLiSuPodudarne ( const Kugla &, const Kugla & );
    friend bool DaLiSuKoncentricne ( const Kugla &, const Kugla & );
    friend bool DaLiSeDodirujuIzvana ( const Kugla &, const Kugla & );
    friend bool DaLiSeDodirujuIznutra ( const Kugla &, const Kugla & );
    friend bool DaLiSePreklapaju ( const Kugla &, const Kugla & );
    friend bool DaLiSeSijeku ( const Kugla &, const Kugla & );
    
    bool DaLiSadrzi ( const Kugla & ) const;
    
    friend double RastojanjeCentara ( const Kugla &, const Kugla & );
    
    //Test pravilnosti rada prijateljskih funkcija klase
    //friend void TESTCLASS ( Kugla &, Kugla & );
};

bool DaLiSuIdenticne ( const Kugla &k1, const Kugla &k2 ) 
    { return Kugla::EQ ( k1.x, k2.x ) and Kugla::EQ ( k1.y, k2.y ) and Kugla::EQ ( k1.z, k2.z ) and Kugla::EQ ( k1.r, k2.r ); }

bool DaLiSuPodudarne ( const Kugla &k1, const Kugla &k2 ) 
    { return Kugla::EQ ( k1.r, k2.r ); }

bool DaLiSuKoncentricne ( const Kugla &k1, const Kugla &k2 ) 
    { return Kugla::EQ ( k1.x, k2.x ) and Kugla::EQ ( k1.y, k2.y ) and Kugla::EQ ( k1.z, k2.z ); }

bool DaLiSeDodirujuIzvana ( const Kugla &k1, const Kugla &k2 )
    { return Kugla::EQ ( k1.r + k2.r, RastojanjeCentara ( k1, k2 ) ); }

bool DaLiSeDodirujuIznutra ( const Kugla &k1, const Kugla &k2 )
    { return Kugla::EQ ( std::abs ( k1.r - k2.r ), RastojanjeCentara ( k1, k2 ) ); }

bool DaLiSePreklapaju ( const Kugla &k1, const Kugla &k2 )
    { return RastojanjeCentara ( k1, k2 ) < k1.r + k2.r; }

bool DaLiSeSijeku ( const Kugla &k1, const Kugla &k2 )
    { return DaLiSePreklapaju ( k1, k2 ) and RastojanjeCentara ( k1, k2 ) > std::abs ( k1.r - k2.r ); }

bool Kugla::DaLiSadrzi ( const Kugla &k ) const
    { return DaLiSePreklapaju ( *this, k ) and RastojanjeCentara ( *this, k ) <= std::abs ( ( this -> r ) - k.r ); }

double RastojanjeCentara ( const Kugla &k1, const Kugla &k2 ) 
    { return std::sqrt ( std::pow ( k2.x - k1.x, 2 ) + std::pow ( k2.y - k1.y, 2 ) + std::pow ( k2.z - k1.z, 2 ) ); }


void UnosKugle ( std::vector < std::shared_ptr < Kugla > > &v, int i )
{
    double x, y, z, r;
CENTAR:
    std::cout << "Unesite centar " << i + 1 << ". kugle: ";
    std::cin >> x >> y >> z;
    if ( !std::cin ) 
        { std::cout << "Neispravan centar\n"; std::cin.clear (); std::cin.ignore ( 20, '\n' ); goto CENTAR; }
    
    std::cout << "Unesite poluprecnik " << i + 1 << ". kugle: ";
    std::cin >> r;
    
    try
    {
        if ( !std::cin )
            throw std::domain_error ( "Ilegalan poluprecnik" );
            
        Kugla k ( x, y, z, r );
        v.push_back ( std::make_shared < Kugla > ( k ) );
    }
    catch ( std::domain_error err ) 
        { std::cout << err.what () << std::endl; std::cin.clear (); std::cin.ignore ( 20, '\n' ); goto CENTAR; }
}

//uncomment in-class function TESTCLASS ( Kugla &, Kugla & )
//#define MAIN__
#ifdef MAIN__
void TESTCLASS ( Kugla &k1, Kugla &k2 )
{
    k1.x = 1; k1.y = 1; k1.z = 1; k1.r = 1;
    k2.x = 1; k2.y = 1; k2.z = 1; k2.r = 1;
    std::cout << "\nDaLiSuIdenticne (): " << std::boolalpha << DaLiSuIdenticne ( k1, k2 ) << " = true";
    k2.r = 15;
    std::cout << "\nDaLiSuIdenticne (): " << std::boolalpha << DaLiSuIdenticne ( k1, k2 ) << " = false";
    
    k1.r = 15;
    std::cout << "\nDaLiSuPodudarne (): " << std::boolalpha << DaLiSuPodudarne ( k1, k2 ) << " = true";
    k2.r = 10;
    std::cout << "\nDaLiSuPodudarne (): " << std::boolalpha << DaLiSuPodudarne ( k1, k2 ) << " = false";
    
    std::cout << "\nDaLiSuKoncentricne (): " << std::boolalpha << DaLiSuKoncentricne ( k1, k2 ) << " = true";
    k2.x = 0;
    std::cout << "\nDaLiSuKoncentricne (): " << std::boolalpha << DaLiSuKoncentricne ( k1, k2 ) << " = false";
    
    k1.x = 0; k1.y = 0; k1.z = 0; k1.r = 1;
    k2.x = 2; k2.y = 0; k2.z = 0; k2.r = 1;
    std::cout << "\nDaLiSeDodirujuIzvana (): " << std::boolalpha << DaLiSeDodirujuIzvana ( k1, k2 ) << " = true";
    k2.r = 1.1;
    std::cout << "\nDaLiSeDodirujuIzvana (): " << std::boolalpha << DaLiSeDodirujuIzvana ( k1, k2 ) << " = false";

    k1.r = 3; k2.r = 1;
    std::cout << "\nDaLiSeDodirujuIznutra (): " << std::boolalpha << DaLiSeDodirujuIznutra ( k1, k2 ) << " = true";
    k2.r = 0.5;
    std::cout << "\nDaLiSeDodirujuIznutra (): " << std::boolalpha << DaLiSeDodirujuIznutra ( k1, k2 ) << " = false";    
    
    k1.x = 0; k1.y = 0; k1.z = 0; k1.r = 5;
    k2.x = 2; k2.y = 0; k2.z = 0; k2.r = 1;
    std::cout << "\nDaLiSePreklapaju (): " << std::boolalpha << DaLiSePreklapaju ( k1, k2 ) << " = true";
    k1.r = 1; k2.r = 0.5;
    std::cout << "\nDaLiSePreklapaju (): " << std::boolalpha << DaLiSePreklapaju ( k1, k2 ) << " = false";    
    k1.r = 1.5; k2.r = 1;
    std::cout << "\nDaLiSePreklapaju (): " << std::boolalpha << DaLiSePreklapaju ( k1, k2 ) << " = true";
    
    k1.r = 5; k2.r = 1;
    std::cout << "\nDaLiSeSijeku (): " << std::boolalpha << DaLiSeSijeku ( k1, k2 ) << " = false";
    k1.r = 0.1; k2.r = 0.5;
    std::cout << "\nDaLiSeSijeku (): " << std::boolalpha << DaLiSeSijeku ( k1, k2 ) << " = false";    
    k1.r = 0.5; k2.r = 1.75;
    std::cout << "\nDaLiSeSijeku (): " << std::boolalpha << DaLiSeSijeku ( k1, k2 ) << " = true";
    
    k1.r = 5; k2.r = 1;
    std::cout << "\nDaLiSeSadrzi (): " << std::boolalpha << k1.DaLiSadrzi ( k2 ) << " = true";
    std::cout << "\nDaLiSeSadrzi (): " << std::boolalpha << k2.DaLiSadrzi ( k1 ) << " = false";
}
#endif

int main ( void )
{
    
#ifndef MAIN__

    int n;
    std::cout << "Unesite broj kugla: ";
    while ( ( std::cin >> n ), !std::cin or n <= 0 )
        { std::cout << "Neispravan broj kugli, unesite ponovo!\n"; std::cin.clear (); std::cin.ignore ( 20, '\n' ); } 
    
    std::vector < std::shared_ptr < Kugla > > v;
    
    std::shared_ptr < Kugla > k;
    for ( int i = 0; i < n; i++ )
        UnosKugle ( v, i );
        
    double dx, dy, dz;
    std::cout << "Unesite parametre translacije (delta_x,delta_y,delta_z): ";
    while ( ( std::cin >> dx >> dy >> dz ), !std::cin ) 
        { std::cout << "Neispravni parametri translacije, unesite ponovo!"; std::cin.clear (); std::cin.ignore ( 20, '\n' ); }
    
    std::transform ( v.begin (), v.end (), v.begin (),
        [ = ] ( std::shared_ptr < Kugla > p ) -> std::shared_ptr < Kugla > 
            { p -> Transliraj ( dx, dy, dz ); return p; } 
    );
    
    std::sort ( v.begin (), v.end (), 
        [] ( std::shared_ptr < Kugla > p1, std::shared_ptr < Kugla > p2 ) -> bool 
            { return p1 -> DajZapreminu () < p2 -> DajZapreminu (); }
    );
    
    std::cout << "Kugle nakon obavljenje transformacije imaju sljedece vrijednosti: \n";
    std::for_each ( v.begin (), v.end (), 
        [] ( std::shared_ptr < Kugla > p ) -> void 
            { p -> Ispisi (); std::cout << std::endl; }
    );
    
    std::cout << "Kugla sa najvecom povrsinom je: ";
    std::shared_ptr < Kugla > max_k = *std::max_element ( v.begin (), v.end (),
        [] ( std::shared_ptr < Kugla > p1, std::shared_ptr < Kugla > p2 ) -> bool 
            { return p1 -> DajPovrsinu () < p2 -> DajPovrsinu (); }
    );
    max_k -> Ispisi ();
    
    int act { 0 }, i { 0 };
    std::for_each ( v.begin (), v.end (), 
        [ v, &act, &i ] ( std::shared_ptr < Kugla > k1 ) -> void
        {
            std::for_each ( v.begin () + ( ++i ), v.end (),
                [ & ] ( std::shared_ptr < Kugla > k2 ) -> void
                {
                    if ( DaLiSeSijeku ( *k1, *k2 ) and k1 != k2 )
                    {
                        std::cout << "\nPresjecaju se kugle: ";
                        k1 -> Ispisi ();
                        std::cout << std::endl;
                        k2 -> Ispisi ();
                        act++;
                    }
                }
            );
        }
    );
    
    if ( !act )
        std::cout << "\nNe postoje kugle koje se presjecaju!";
        
#else

    Kugla k1, k2;
    TESTCLASS ( k1, k2 );
    
#endif

    return 0;
}