#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <numeric>
#include <algorithm>
#include <memory>
#include <utility>
#include <fstream>
#include <sstream>

class Spremnik
{
protected:
    double tezina_spremnika;
    std::string naziv_sadrzaja;

public: 
    Spremnik ( double tezina, std::string naziv ) : tezina_spremnika ( tezina ), naziv_sadrzaja ( naziv ) {}
    virtual ~Spremnik ( void ) {}

    double DajTezinu ( void ) const { return tezina_spremnika; }
    
    virtual double DajUkupnuTezinu ( void ) const = 0;
    virtual void Ispisi ( void ) const = 0;
    virtual std::shared_ptr < Spremnik > Kopija ( void ) const = 0;
};

class Sanduk : public Spremnik
{
    std::vector < double > tezina_sadrzaja; //kg

public:
    Sanduk ( double tezina, std::string naziv, std::vector < double > t_sadrzaj ) : Spremnik ( tezina, naziv ), tezina_sadrzaja ( t_sadrzaj ) {}
    
    double DajUkupnuTezinu ( void ) const override { return DajTezinu () + std::accumulate ( tezina_sadrzaja.begin (), tezina_sadrzaja.end (), .0 ); }
    
    void Ispisi ( void ) const override
    {
        std::cout << "Vrsta spremnika: Sanduk\nSadrzaj: " << naziv_sadrzaja << "\nTezine predmeta: ";
        for ( double x : tezina_sadrzaja )
            std::cout << x << " ";
        std::cout << "(kg)\nVlastita tezina: " << DajTezinu () << " (kg)\nUkupna tezina: " << DajUkupnuTezinu () << " (kg)\n";
    }
    
    std::shared_ptr < Spremnik > Kopija ( void ) const override { return std::make_shared < Sanduk > ( *this ); }
};

class Vreca : public Spremnik
{
    double tezina_sadrzaja; //kg
    
public:
    Vreca ( double tezina, std::string naziv, double t_sadrzaj ) : Spremnik ( tezina, naziv ), tezina_sadrzaja ( t_sadrzaj ) {}
    
    double DajUkupnuTezinu ( void ) const override { return DajTezinu () + tezina_sadrzaja; }
    
    void Ispisi ( void ) const override
    {
        std::cout << "Vrsta spremnika: Vreca\nSadrzaj: " << naziv_sadrzaja <<
            "\nVlastita tezina: " << DajTezinu () << " (kg)\nTezina pohranjene materije: " << tezina_sadrzaja <<
            " (kg)\nUkupna tezina: " << DajUkupnuTezinu () << " (kg)\n";
    }
    
    std::shared_ptr < Spremnik > Kopija ( void ) const override { return std::make_shared < Vreca > ( *this ); }
};

class Bure : public Spremnik
{
    double tezina_sadrzaja; //kg/m^3
    double zapremina; //litar

public:    
    Bure ( double tezina, std::string naziv, double t_sadrzaj, double vol ) : Spremnik ( tezina, naziv ), tezina_sadrzaja ( t_sadrzaj ), zapremina ( vol ) {}
    
    double DajUkupnuTezinu ( void ) const override { return DajTezinu () + ( tezina_sadrzaja * zapremina / 1000 ); }
    
    void Ispisi ( void ) const override
    {
        std::cout << "Vrsta spremnika: Bure\nSadrzaj: " << naziv_sadrzaja <<
            "\nVlastita tezina: " << DajTezinu () << " (kg)\nSpecificna tezina tecnosti: " << tezina_sadrzaja <<
            " (kg/m^3)\nZapremina tecnosti: " << zapremina << " (l)\nUkupna tezina: " << DajUkupnuTezinu () << " (kg)\n";
    }    
    
    std::shared_ptr < Spremnik > Kopija ( void ) const override { return std::make_shared < Bure > ( *this ); }
};

class Skladiste
{
    std::vector < std::shared_ptr < Spremnik > > spremnici;
    
public:
    Skladiste ( void ) = default;
    ~Skladiste ( void ) = default;
    
    Skladiste ( const Skladiste &s )
    {
        for ( int i = 0; i < s.spremnici.size (); i++ )
            spremnici.push_back ( s.spremnici.at ( i ) -> Kopija () );
    }
    
    Skladiste ( Skladiste &&s ) 
    {
        for ( int i = 0; i < s.spremnici.size (); i++ )
            spremnici.push_back ( s.spremnici.at ( i ) -> Kopija () );
    }
    
    Skladiste &operator = ( const Skladiste &s )
    {
        if ( this != &s )
        {
            spremnici.resize ( 0 );
            for ( int i = 0; i < s.spremnici.size (); i++ )
                spremnici.push_back ( s.spremnici.at ( i ) -> Kopija () );
        }
        return *this;
    }
    
    Skladiste &operator = ( Skladiste &&s )
    {
        spremnici.resize ( 0 );
        for ( int i = 0; i < s.spremnici.size (); i++ )
            spremnici.push_back ( s.spremnici.at ( i ) -> Kopija () );
        return *this;
    }
    
    Spremnik *DodajSanduk ( double tezina, std::string naziv, std::vector < double > t_sadrzaj )
    {
        spremnici.push_back ( Sanduk ( tezina, naziv, t_sadrzaj ).Kopija () );
        return spremnici.at ( spremnici.size () - 1 ).get ();
    }
    
    Spremnik *DodajVrecu ( double tezina, std::string naziv, double t_sadrzaj )
    {
        spremnici.push_back ( Vreca ( tezina, naziv, t_sadrzaj ).Kopija () );
        return spremnici.at ( spremnici.size () - 1 ).get ();
    }

    Spremnik *DodajBure ( double tezina, std::string naziv, double t_sadrzaj, double vol )
    {
        spremnici.push_back ( Bure ( tezina, naziv, t_sadrzaj, vol ).Kopija () );
        return spremnici.at ( spremnici.size () - 1 ).get ();
    }
    
    Spremnik *DodajSpremnik ( Spremnik *spremnik, bool prisvoji = true )
    {
        spremnici.push_back ( ( prisvoji ) ? std::shared_ptr < Spremnik > ( spremnik ) : spremnik -> Kopija () );
        return spremnici.at ( spremnici.size () - 1 ).get ();
    }
    
    void BrisiSpremnik ( Spremnik *spremnik )
    {
        for ( std::vector < std::shared_ptr < Spremnik > >::iterator it = spremnici.begin (); it != spremnici.end (); it++ )
            if ( it -> get () == spremnik )
                { spremnici.erase ( it ); break; }
    }
    
    Spremnik &DajNajlaksi ( void )
    {
        if ( spremnici.empty () ) throw std::range_error ( "Skladiste je prazno" );
        return *( std::min_element ( spremnici.begin (), spremnici.end (), 
            [] ( const std::shared_ptr < Spremnik > s1, const std::shared_ptr < Spremnik > s2 ) -> bool 
                { return s1 -> DajUkupnuTezinu () < s2 -> DajUkupnuTezinu (); }
        ) -> get () );
    }
    
    Spremnik &DajNajlaksi ( void ) const = delete;
    
    Spremnik &DajNajtezi ( void )
    {
        if ( spremnici.empty () ) throw std::range_error ( "Skladiste je prazno" );
        return *( std::max_element ( spremnici.begin (), spremnici.end (), 
            [] ( const std::shared_ptr < Spremnik > s1, const std::shared_ptr < Spremnik > s2 ) -> bool 
                { return s1 -> DajUkupnuTezinu () > s2 -> DajUkupnuTezinu (); }
        ) -> get () );
    }
    
    Spremnik &DajNajtezi ( void ) const = delete;
    
    int BrojPreteskih ( int granica ) const
    {
        return std::count_if ( spremnici.begin (), spremnici.end (), 
            [ & ] ( const std::shared_ptr < Spremnik > s ) -> bool { return s -> DajUkupnuTezinu () >= granica; }
        );
    }
    
    void IzlistajSkladiste ( void ) const
    {
        std::vector < std::shared_ptr < Spremnik > > spremnik;
        for ( std::shared_ptr < Spremnik > s : spremnici )
            spremnik.push_back ( s -> Kopija () );
            
        std::sort ( spremnik.begin (), spremnik.end (), 
            [] ( std::shared_ptr < Spremnik > s1, std::shared_ptr < Spremnik > s2 )
                { return s1 -> DajUkupnuTezinu () > s2 -> DajUkupnuTezinu (); }
        );
        
        for ( std::shared_ptr < Spremnik > s : spremnik )
            s -> Ispisi ();
    }
    
    void UcitajIzDatoteke ( std::string ime_dat )
    {
        std::ifstream file ( ime_dat );
        if ( !file.is_open () ) throw std::logic_error ( "Trazena datoteka ne postoji" );
        
        if ( spremnici.size () > 0 ) spremnici.clear ();
        
        std::string line;
        
        while ( std::getline ( file, line ) )
        {
            char tip = line.at ( 0 );
            line.erase ( 0, 2 );
            std::string naziv = line;
            
            std::getline ( file, line );
            std::istringstream ss ( line );
            
            std::vector < double > chain;
            while ( true )
            {
                std::string unit;
                std::getline ( ss, unit, ' ' );
                if ( !ss ) break;
                chain.push_back ( std::stod ( unit ) );
            }
            
            if ( tip == 'S' )
            {
                double teg = chain.at ( 0 );
                chain.erase ( chain.begin (), chain.begin () + 2 );
                DodajSanduk ( teg, naziv, chain );
            }
            else if ( tip == 'V' )
                DodajVrecu ( chain.at ( 0 ), naziv, chain.at ( 1 ) );
            else if ( tip == 'B' )
                DodajBure ( chain.at ( 0 ), naziv, chain.at ( 1 ), chain.at ( 2 ) );
        }
        
        if ( file.bad () and !file.eof () ) throw std::logic_error ( "Problemi pri citanju datoteke" );
    }
};

class PolimorfniSpremnik
{
    std::shared_ptr < Spremnik > spremnik;
    
    void TestExc ( void ) const { if ( !spremnik ) throw std::logic_error ( "Nespecificiran spremnik" ); }

public:
    PolimorfniSpremnik ( void ) : spremnik { nullptr } {}
    ~PolimorfniSpremnik ( void ) = default;
    
    PolimorfniSpremnik ( const Spremnik &s ) : spremnik ( s.Kopija () ) {}
    
    PolimorfniSpremnik ( const PolimorfniSpremnik &s ) : spremnik ( nullptr ) { if ( s.spremnik ) spremnik = s.spremnik -> Kopija (); }
    
    PolimorfniSpremnik ( PolimorfniSpremnik &&s ) : spremnik ( s.spremnik ) { s.spremnik = nullptr; }
    
    PolimorfniSpremnik &operator = ( const Spremnik &s )
    {
        spremnik = s.Kopija ();
        return *this;
    }
    
    PolimorfniSpremnik &operator = ( const PolimorfniSpremnik &s )
    {
        spremnik = s.spremnik -> Kopija ();
        return *this;
    }
    
    PolimorfniSpremnik &operator = ( PolimorfniSpremnik &&s )
    {
        spremnik = std::move ( s.spremnik );
        s.spremnik = nullptr;
        return *this;
    }
    
    double DajTezinu ( void ) const { TestExc (); return spremnik -> DajTezinu (); }
    
    double DajUkupnuTezinu ( void ) const { TestExc (); return spremnik -> DajUkupnuTezinu (); }
    
    void Ispisi ( void ) const { TestExc (); spremnik -> Ispisi (); }
};

int main ( void )
{
    PolimorfniSpremnik s1 ( Bure ( 5, "Benzin", 930, 70 ) );
    PolimorfniSpremnik s2, s3;
    s2 = Sanduk ( 3, "Tepsije", { 0.5, 0.8, 0.6, 0.5 } );
    s3 = Vreca ( 0.4, "Brasno", 30 );
    std::cout << s1.DajTezinu () << std::endl;
    std::cout << s2.DajUkupnuTezinu () << std::endl;
    s3.Ispisi ();
    s1 = s2;
    s1.Ispisi ();
    return 0;
}