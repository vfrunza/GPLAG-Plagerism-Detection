#include <iostream>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include <memory>
#include <vector>
#include <algorithm>

class NepreklapajucaKugla
{
    double x, y, z;
    double r;
    
    NepreklapajucaKugla *prethodni;
    static NepreklapajucaKugla *zadnji;
    
    static constexpr double pi { 4 * std::atan ( 1 ) };

    void TestPP ( double pp ) { if ( pp < 0 ) throw std::domain_error ( "Ilegalan poluprecnik" ); }
    
    static bool EQ ( double a, double b ) { return std::fabs ( a - b ) < ( 0.0000000001 * ( std::fabs ( a ) + std::fabs ( b ) ) ); }
    static bool DaLiSePreklapaju ( const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2 ) { return RastojanjeCentara ( k1, k2 ) < k1.r + k2.r; }
    
    void TestPreklapanje ( void )
    {
        NepreklapajucaKugla *pom_k { zadnji };
        while ( true ) // provjera da li se *this preklapa sa ostalim kuglama
        {
            if ( this != pom_k and 
                ( DaLiSePreklapaju ( *this, *pom_k ) or EQ ( RastojanjeCentara ( *this, *pom_k ), this -> DajPoluprecnik () + pom_k -> DajPoluprecnik () ) ) )
            {
                this -> ~NepreklapajucaKugla (); // izbacivanje iz liste
                throw std::logic_error ( "Nedozvoljeno preklapanje" );
            }
            pom_k = pom_k -> prethodni;
            if ( pom_k == nullptr )
                break;
        }
    }

public:
    explicit NepreklapajucaKugla ( double r = 0 ) 
    { 
        TestPP ( r ); NepreklapajucaKugla::r = r; x = y = z = 0;         
        prethodni = ( zadnji == nullptr ) ? nullptr : zadnji;
        zadnji = this; 
        this -> TestPreklapanje ();
    }
    
    NepreklapajucaKugla ( double x, double y, double z, double r = 0 ) 
    { 
        TestPP ( r ); NepreklapajucaKugla::x = x; NepreklapajucaKugla::y = y; NepreklapajucaKugla::z = z; NepreklapajucaKugla::r = r;          
        prethodni = ( zadnji == nullptr ) ? nullptr : zadnji;
        zadnji = this; 
        this -> TestPreklapanje ();
    }
    
    explicit NepreklapajucaKugla ( const std::tuple < double, double, double > &centar, double r = 0 )
    { 
        TestPP ( r ); x = std::get < 0 > ( centar ); y = std::get < 1 > ( centar ); z = std::get < 2 > ( centar ); NepreklapajucaKugla::r = r;          
        prethodni = ( zadnji == nullptr ) ? nullptr : zadnji;
        zadnji = this; 
        this -> TestPreklapanje ();
    }

// zabrana kopiranja i dodjele    
    NepreklapajucaKugla ( const NepreklapajucaKugla & ) = delete;   
    NepreklapajucaKugla ( NepreklapajucaKugla && ) = delete;
    NepreklapajucaKugla &operator = ( const NepreklapajucaKugla & ) = delete;
    NepreklapajucaKugla &operator = ( NepreklapajucaKugla && ) = delete;
/**/
    
    ~NepreklapajucaKugla ( void )
    {
        if ( zadnji == this )
            ( zadnji = prethodni ), ( prethodni = nullptr );
        else 
        {
            NepreklapajucaKugla *pom_k { zadnji };
            while ( pom_k -> prethodni != this )
                pom_k = pom_k -> prethodni;
            
            pom_k -> prethodni = this -> prethodni;
            this -> prethodni = nullptr;
        }
    }
    
    double DajX ( void ) const { return x; }
    double DajY ( void ) const { return y; }
    double DajZ ( void ) const { return z; }
    
    std::tuple < double, double, double > DajCentar ( void ) const { return std::tie ( x, y, z ); }
    
    double DajPoluprecnik ( void ) const { return r; }
    
    double DajPovrsinu ( void ) const { return 4 * pi * r * r; }
    double DajZapreminu ( void ) const { return ( DajPovrsinu () * r ) / 3; }
    
    NepreklapajucaKugla &PostaviX ( double x ) 
    { 
        double px = NepreklapajucaKugla::x;
        NepreklapajucaKugla::x = x;
        try { this -> TestPreklapanje (); }
        catch ( ... ) 
        {
            NepreklapajucaKugla::x = px;
            throw std::logic_error ( "Nedozvoljeno preklapanje" );
        }
        
        return *this; 
    }
    
    NepreklapajucaKugla &PostaviY ( double y ) 
    { 
        double py = NepreklapajucaKugla::y;
        NepreklapajucaKugla::y = y; 
        try { this -> TestPreklapanje (); }
        catch ( ... ) 
        {
            NepreklapajucaKugla::y = py;
            throw std::logic_error ( "Nedozvoljeno preklapanje" );
        }
        
        return *this; 
    }
    
    NepreklapajucaKugla &PostaviZ ( double z ) 
    { 
        double pz = NepreklapajucaKugla::z;
        NepreklapajucaKugla::z = z; 
        try { this -> TestPreklapanje (); }
        catch ( ... ) 
        {
            NepreklapajucaKugla::z = pz;
            throw std::logic_error ( "Nedozvoljeno preklapanje" );
        }
        
        return *this; 
    }
    
    NepreklapajucaKugla &PostaviCentar ( double x, double y, double z ) 
    { 
        double pre_x { NepreklapajucaKugla::x }, pre_y { NepreklapajucaKugla::y }, pre_z { NepreklapajucaKugla::z };
        NepreklapajucaKugla::x = x; NepreklapajucaKugla::y = y; NepreklapajucaKugla::z = z; 
        try { this -> TestPreklapanje (); }
        catch ( ... ) 
        {
            x = pre_x; y = pre_y; z = pre_z;
            throw std::logic_error ( "Nedozvoljeno preklapanje" );
        }
        
        return *this; 
    }
    NepreklapajucaKugla &PostaviCentar ( const std::tuple < double, double, double > &centar )
    {
        double pre_x { x }, pre_y { y }, pre_z { z };
        x = std::get < 0 > ( centar ); y = std::get < 1 > ( centar ); z = std::get < 2 > ( centar ); 
        try { this -> TestPreklapanje (); }
        catch ( ... ) 
        {
            x = pre_x; y = pre_y; z = pre_z;
            throw std::logic_error ( "Nedozvoljeno preklapanje" );
        }
        
        return *this; 
    }
    
    NepreklapajucaKugla &PostaviPoluprecnik ( double r ) 
    { 
        double pre_r = r; TestPP ( r ); NepreklapajucaKugla::r = r; 
        try { this -> TestPreklapanje (); }
        catch ( ... ) 
        {
            NepreklapajucaKugla::r = pre_r;
            throw std::logic_error ( "Nedozvoljeno preklapanje" );
        }
        
        return *this; 
    }
    
    void Ispisi ( void ) const { std::cout << "{(" << x << "," << y << "," << z << ")," << r << "}"; }
    
    void Transliraj ( double delta_x, double delta_y, double delta_z ) 
    { 
        x += delta_x; y += delta_y; z += delta_z;
        try { this -> TestPreklapanje (); }
        catch ( ... ) 
        {
            x -= delta_x; y -= delta_y; z -= delta_z;
            throw std::logic_error ( "Nedozvoljeno preklapanje" );
        }
    }

    bool DaLiSadrzi ( const NepreklapajucaKugla & ) const;
    
    friend double RastojanjeCentara ( const NepreklapajucaKugla &, const NepreklapajucaKugla & );
};

bool NepreklapajucaKugla::DaLiSadrzi ( const NepreklapajucaKugla &k ) const
    { return NepreklapajucaKugla::DaLiSePreklapaju ( *this, k ) and RastojanjeCentara ( *this, k ) <= std::abs ( ( this -> r ) - k.r ); }

double RastojanjeCentara ( const NepreklapajucaKugla &k1, const NepreklapajucaKugla &k2 ) 
    { return std::sqrt ( std::pow ( k2.x - k1.x, 2 ) + std::pow ( k2.y - k1.y, 2 ) + std::pow ( k2.z - k1.z, 2 ) ); }


void iStreamRefresh ( const char *msg )
    { std::cout << msg << std::endl; std::cin.clear (); std::cin.ignore ( 20, '\n' ); }

void UnosKugle ( std::vector < std::shared_ptr < NepreklapajucaKugla > > &v, int i )
{
    double x, y, z, r;
CENTAR:
    std::cout << "Unesite centar za " << i + 1 << ". kuglu: ";
    std::cin >> x >> y >> z;
    while ( !std::cin ) 
    { 
        iStreamRefresh ( "Neispravan centar, unesite ponovo:" ); 
        std::cin >> x >> y >> z;
    }
    
    std::cout << "Unesite poluprecnik: ";
    while ( ( std::cin >> r ), !std::cin or r < 0 )
        { iStreamRefresh ( "Neispravan poluprecnik, unesite ponovo:" ); }
        
    try
    {
        std::shared_ptr < NepreklapajucaKugla > k ( std::make_shared < NepreklapajucaKugla > ( x, y, z ,r ) );
        v.push_back ( k );
    }
    catch ( const std::exception &err ) 
        { iStreamRefresh ( err.what () ); goto CENTAR; }
}

NepreklapajucaKugla *NepreklapajucaKugla::zadnji = nullptr; // INITIALIZE STATIC MEMBER
    
int main ( void )
{
    int n;
    std::cout << "Unesite broj kugli: ";
    while ( ( std::cin >> n ), !std::cin or n <= 0 )
        { std::cout << "Neispravan broj kugli, unesite ponovo!\n"; std::cin.clear (); std::cin.ignore ( 20, '\n' ); } 
    
    std::vector < std::shared_ptr < NepreklapajucaKugla > > v;
    
    std::shared_ptr < NepreklapajucaKugla > k;
    for ( int i = 0; i < n; i++ )
        UnosKugle ( v, i );
    
    std::sort ( v.begin (), v.end (), 
        [] ( std::shared_ptr < NepreklapajucaKugla > p1, std::shared_ptr < NepreklapajucaKugla > p2 ) -> bool 
            { return p1 -> DajPovrsinu () < p2 -> DajPovrsinu (); }
    );
    
    std::cout << "\nKugle nakon obavljenog sortiranja: \n";
    std::for_each ( v.begin (), v.end (), 
        [] ( std::shared_ptr < NepreklapajucaKugla > p ) -> void 
            { p -> Ispisi (); std::cout << std::endl; }
    );

    return 0;
}