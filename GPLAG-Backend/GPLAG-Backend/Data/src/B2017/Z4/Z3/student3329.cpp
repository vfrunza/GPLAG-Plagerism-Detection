#include <iostream>
#include <tuple>
#include <utility>
#include <stdexcept>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <initializer_list>
#include <algorithm>

/*Datum*/
class Datum
{
    int dan, mjesec, godina;

public:
    Datum ( int d, int m, int g ) { this -> Postavi ( d, m, g ); }
    void Postavi ( int, int, int );
    
    std::tuple < int, int, int > Ocitaj ( void ) const { return std::tie ( dan, mjesec, godina ); }
    
    void Ispisi ( void ) const { std::cout << dan << "/" << mjesec << "/" << godina; }
};

void Datum::Postavi ( int d, int m, int g )
{
    int broj_dana [ 12 ] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ( ( g % 4 == 0 and g % 100 != 0 ) or g % 400 == 0 )  broj_dana [ 1 ]++;
    if ( g < 1 or d < 1 or m < 1 or m > 12 or d > broj_dana [ m - 1 ] )
        throw std::domain_error ( "Neispravan datum" );
    dan = d; mjesec = m; godina = g;
}
/*~Datum*/

/*Vrijeme*/
class Vrijeme
{
    int sati, minute;

public:
    Vrijeme ( int sati, int minute ) { this -> Postavi ( sati, minute ); }
    void Postavi ( int, int );
    
    std::pair < int, int > Ocitaj ( void ) const { return std::make_pair ( sati, minute ); }
    
    void Ispisi ( void ) const { std::cout << std::right << std::setw ( 2 ) << std::setfill ( '0' ) << sati << ":" << 
        std::right << std::setw ( 2 ) << std::setfill ( '0' ) << minute; }
};

void Vrijeme::Postavi ( int h, int m )
{
    if ( h < 0 or h > 23 or m < 0 or m > 59 )
        throw std::domain_error ( "Neispravno vrijeme" );
    sati = h; minute = m;
}
/*~Vrijeme*/

/*Pregled*/
class Pregled
{
    std::string ime;
    Datum datum;
    Vrijeme vrijeme;    
    
    //broj proteklih dana od pocetka godine za svaki mjesec
    const int dim [ 12 ] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

    int NumberOfDays ( void ) const // broj dana od nultog dana u Gregorijanskom kalendaru
    {
        std::tuple < int, int, int > date ( this -> DajDatumPregleda ().Ocitaj () );
        int dan { std::get < 0 > ( date ) }, mjesec { std::get < 1 > ( date ) }, godina { std::get < 2 > ( date ) };
        return
        (
            ( godina - 1 ) * 365 + ( mjesec > 1 ? dim [ mjesec - 2 ] : 0 ) + dan - 1 + 
            ( mjesec > 2 ? godina / 4 - godina / 100 + godina / 400 :
            ( godina - 1 ) / 4 - ( godina - 1 ) / 100 + ( godina - 1 ) / 400 )
        );
    }

    int NumberOfMinutes ( void ) const // broj minuta od nulte minute u Gregorijanskom kalendaru
    { 
        std::pair < int, int > par ( this -> DajVrijemePregleda ().Ocitaj () );
        int sati { par.first }, minute { par.second };
        return ( this -> NumberOfDays () ) * 1440 + sati * 60 + minute; 
    }
    
public:
    Pregled ( const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda )
        : ime { ime_pacijenta }, datum { datum_pregleda }, vrijeme { vrijeme_pregleda } {}
    
    Pregled ( const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, int sati_pregleda, int minute_pregleda )
        : ime { ime_pacijenta }, datum ( dan_pregleda, mjesec_pregleda, godina_pregleda ), vrijeme ( sati_pregleda, minute_pregleda ) {}
    
    void PromijeniPacijenta  ( const std::string &ime_pacijenta ) { ime = ime_pacijenta; }
    void PromijeniDatum ( const Datum &novi_datum ) { datum = novi_datum; }
    void PromijeniVrijeme ( const Vrijeme &novo_vrijeme ) { vrijeme = novo_vrijeme; }
    
    void PomjeriDanUnaprijed ( void );
    void PomjeriDanUnazad ( void );
    
    std::string DajImePacijenta ( void ) const { return ime; }
    Datum DajDatumPregleda ( void ) const { return datum; }
    Vrijeme DajVrijemePregleda ( void ) const { return vrijeme; }
    
    static bool DolaziPrije ( const Pregled &p1, const Pregled &p2 ) 
        { return p1.NumberOfMinutes () < p2.NumberOfMinutes (); }
    
    void Ispisi ( void ) const
    {
        std::cout << std::setw ( 30 ) << std::left  << std::setfill ( ' ' ) << ime;
        datum.Ispisi (); std::cout << " "; vrijeme.Ispisi ();
    }
};

void Pregled::PomjeriDanUnaprijed ( void )
{
    std::tuple < int, int, int > date = datum.Ocitaj ();
    int d { std::get < 0 > ( date ) }, m { std::get < 1 > ( date ) }, g { std::get < 2 > ( date ) };
    
    int broj_dana [ 12 ] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ( ( g % 4 == 0 and g % 100 != 0 ) or g % 400 == 0 )  broj_dana [ 1 ]++;
    
    if ( d > broj_dana [ m - 1 ] ) ( d = 1 ), m++;
    if ( m > 12 ) ( m = 1 ), g++;
    
    datum.Postavi ( d, m, g );
}

void Pregled::PomjeriDanUnazad ( void )
{
    std::tuple < int, int, int > date = datum.Ocitaj ();
    int d { std::get < 0 > ( date ) }, m { std::get < 1 > ( date ) }, g { std::get < 2 > ( date ) };
    
    int broj_dana [ 12 ] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ( ( g % 4 == 0 and g % 100 != 0 ) or g % 400 == 0 )  broj_dana [ 1 ]++;
    
    if ( d < 1 )
    {
        m--;
        if ( m < 1 )
            g--;
        d = broj_dana [ m - 1 ];
    }
    
    datum.Postavi ( d, m, g );
}
/*~Pregled*/

/*Pregledi*/
class Pregledi
{
    Pregled **p;
    
    unsigned int velicina_niza, trenutna_velicina;
    
    void Alloc ( int n ) // alokacija memorije za clan 'p'
    {
        p = new Pregled *[ n ];
        for ( int i = 0; i < n; i++ )
            p [ i ] = nullptr;
        velicina_niza = n;
        trenutna_velicina = 0;
    }

public:
    explicit Pregledi ( int max_broj_pregleda ) { this -> Alloc ( max_broj_pregleda ); }
    
    Pregledi ( std::initializer_list < Pregled > spisak_pregleda )
    {
        this -> Alloc ( spisak_pregleda.size () );
        int i { 0 };
        for ( Pregled pregled : spisak_pregleda )
            p [ i++ ] = new Pregled ( pregled.DajImePacijenta (), pregled.DajDatumPregleda (), pregled.DajVrijemePregleda () );
            
        trenutna_velicina = velicina_niza = spisak_pregleda.size ();
    }
    
    ~Pregledi ( void )
    {
        for ( int i = 0; i < trenutna_velicina; i++ )
            delete p [ i ];
        delete [] p;
    }
    
    Pregledi ( const Pregledi &pregledi )
    {
        this -> Alloc ( pregledi.velicina_niza );
        trenutna_velicina = pregledi.trenutna_velicina;
        
        for ( int i = 0; i < trenutna_velicina; i++ )
            p [ i ] = new Pregled 
                ( pregledi.p [ i ] -> DajImePacijenta (), pregledi.p [ i ] -> DajDatumPregleda (), pregledi.p [ i ] -> DajVrijemePregleda () );
    }
    
    Pregledi ( Pregledi &&pregledi ) 
        : p { pregledi.p }, velicina_niza { pregledi.velicina_niza }, trenutna_velicina { pregledi.trenutna_velicina }
        { pregledi.~Pregledi (); }   

    Pregledi &operator = ( const Pregledi &pregledi )
    {
        this -> ~Pregledi ();
        this -> Alloc ( pregledi.velicina_niza );
        trenutna_velicina = pregledi.trenutna_velicina;
        
        for ( int i = 0; i < trenutna_velicina; i++ )
            p [ i ] = new Pregled 
                ( pregledi.p [ i ] -> DajImePacijenta (), pregledi.p [ i ] -> DajDatumPregleda (), pregledi.p [ i ] -> DajVrijemePregleda () );
        
        return *this;
    }
    
    Pregledi &operator = ( Pregledi &&pregledi )
    {
        if ( this != &pregledi )
        {
            this -> ~Pregledi ();
            p = pregledi.p;
            velicina_niza = pregledi.velicina_niza;
            trenutna_velicina = pregledi.trenutna_velicina;
        }
        pregledi.~Pregledi ();
        return *this;
    }
    
    void RegistrirajPregled ( const std::string &ime_pacijenta, const Datum &datum_pregleda, const Vrijeme &vrijeme_pregleda )
    {
        if ( trenutna_velicina == velicina_niza )
            throw std::domain_error ( "Dostignut maksimalni broj pregleda" );
        
        p [ trenutna_velicina++ ] = new Pregled ( ime_pacijenta, datum_pregleda, vrijeme_pregleda );
    }
    
    void RegistrirajPregled ( const std::string &ime_pacijenta, int dan_pregleda, int mjesec_pregleda, int godina_pregleda, 
        int sati_pregleda, int minute_pregleda )
    {
        if ( trenutna_velicina == velicina_niza )
            throw std::domain_error ( "Dostignut maksimalni broj pregleda" );
        
        p [ trenutna_velicina++ ] = new Pregled ( ime_pacijenta, dan_pregleda, mjesec_pregleda, godina_pregleda, sati_pregleda, minute_pregleda );
    }
    
    void RegistrirajPregled ( Pregled *pregled )
    {
        if ( trenutna_velicina == velicina_niza )
            { delete pregled; throw std::domain_error ( "Dostignut maksimalni broj pregleda" ); }
        
        p [ trenutna_velicina++ ] = new Pregled ( pregled -> DajImePacijenta (), pregled -> DajDatumPregleda (), pregled -> DajVrijemePregleda () );
        
        delete pregled;
    }
    
    int DajBrojPregleda ( void ) const { return trenutna_velicina; }
    int DajBrojPregledaNaDatum ( const Datum &datum ) const
    {
        return std::count_if ( p, p + trenutna_velicina, 
            [ = ] ( Pregled *p ) -> bool
            {
                std::tuple < int, int, int > d1 ( p -> DajDatumPregleda ().Ocitaj () ), d2 ( datum.Ocitaj () );
                int dan1 { std::get < 0 > ( d1 ) }, mjesec1 { std::get < 1 > ( d1 ) }, godina1 { std::get < 2 > ( d1 ) },
                    dan2 { std::get < 0 > ( d2 ) }, mjesec2 { std::get < 1 > ( d2 ) }, godina2 { std::get < 2 > ( d2 ) };
                return dan1 == dan2 and mjesec1 == mjesec2 and godina1 == godina2;
            }
        );
    }
    
    Pregled &DajNajranijiPregled ( void )
    {
        if ( trenutna_velicina == 0 )
            throw std::domain_error ( "Nema registriranih pregleda" );
        
        return **std::min_element ( this -> p, this -> p + trenutna_velicina,
            [] ( Pregled *p1, Pregled *p2 ) -> bool
                { return Pregled::DolaziPrije ( *p1, *p2 ); }
        );
    }
    
    Pregled DajNajranijiPregled ( void ) const
    {
        if ( trenutna_velicina == 0 )
            throw std::domain_error ( "Nema registriranih pregleda" );
        
        return **std::min_element ( this -> p, this -> p + trenutna_velicina,
            [] ( Pregled *p1, Pregled *p2 ) -> bool
                { return Pregled::DolaziPrije ( *p1, *p2 ); }
        );        
    }
    
    void IsprazniKolekciju ( void )
    {
        for ( int i = 0; i < trenutna_velicina; i++ )
            ( delete p [ i ] ), p [ i ] = nullptr;
    }
    
    void ObrisiNajranijiPregled ( void )
    {
        if ( trenutna_velicina == 0 )
            throw std::range_error ( "Prazna kolekcija" );
        
        Pregled pregled { this -> DajNajranijiPregled () };
        
        for ( int i = 0; i < trenutna_velicina; i++ )
            if 
            ( 
                p [ i ] -> DajImePacijenta () == pregled.DajImePacijenta () and 
                p [ i ] -> DajDatumPregleda ().Ocitaj () == pregled.DajDatumPregleda ().Ocitaj () and
                p [ i ] -> DajVrijemePregleda ().Ocitaj () == pregled.DajVrijemePregleda ().Ocitaj () 
            )
            {
                delete p [ i ];
                
                if ( trenutna_velicina == 1 or i + 1 == trenutna_velicina ) // prazan niz nakon brisanja ili zadnji pregled u nizu
                    { p [ i ] = nullptr; trenutna_velicina--; }
                else
                { // mijenja pregled za brisanje sa zadnjim pregledom u nizu
                    p [ i ] = new Pregled ( p [ --trenutna_velicina ] -> DajImePacijenta (), 
                        p [ trenutna_velicina ] -> DajDatumPregleda (), p [ trenutna_velicina ] -> DajVrijemePregleda () );
                    delete p [ trenutna_velicina ];
                    p [ trenutna_velicina ] = nullptr;
                }
                break;
            }
    }
    
    void ObrisiPregledePacijenta ( const std::string &ime_pacijenta )
    {
        for ( int i = 0; i < trenutna_velicina; i++ )
            if ( p [ i ] -> DajImePacijenta () == ime_pacijenta )
            {
                delete p [ i ];
                if ( trenutna_velicina == 1 or i + 1 == trenutna_velicina ) // prazan niz nakon brisanja ili zadnji pregled u nizu
                    { p [ i ] = nullptr; trenutna_velicina--; }
                else
                { // mijenja pregled za brisanje sa zadnjim pregledom u nizu
                    p [ i ] = new Pregled ( p [ --trenutna_velicina ] -> DajImePacijenta (), 
                        p [ trenutna_velicina ] -> DajDatumPregleda (), p [ trenutna_velicina ] -> DajVrijemePregleda () );
                    delete p [ trenutna_velicina ];
                    p [ trenutna_velicina ] = nullptr;
                }
                i--;
            }
    }
    
    void IspisiPregledeNaDatum ( const Datum &datum ) const
    {
        Pregledi pp ( *this );
        while ( pp.DajBrojPregleda () != 0 )
        {
            if ( pp.DajNajranijiPregled ().DajDatumPregleda ().Ocitaj () == datum.Ocitaj () )
                pp.DajNajranijiPregled ().Ispisi ();
            pp.ObrisiNajranijiPregled ();
            std::cout << std::endl;
        }
    }
    
    void IspisiSvePreglede ( void ) const
    {
        Pregledi pp ( *this );
        while ( pp.DajBrojPregleda () != 0 )
        {
            pp.DajNajranijiPregled ().Ispisi ();
            pp.ObrisiNajranijiPregled ();
            std::cout << std::endl;
        }
    }
};
/*~Pregledi*/

int main ( void )
{
    int max_br_p;
    std::cout << "Unesite maksimalan broj pregleda: ";
    std::cin >> max_br_p;
    
    Pregledi pregledi ( max_br_p );
    int i { 0 };
    std::string p_ime;
    int p_dan, p_mjesec, p_godina;
    int p_sat, p_minut;
    
    try
    {
    while ( std::cout << "Unesite ime novog pacijenta ili 'kraj' za zavrsetak unosa: " )
    {
        std::cin.clear ();
        std::cin.ignore ( 30, '\n' );
        p_ime = "";
        std::getline ( std::cin, p_ime );
        if ( p_ime == "kraj" )
            break;
        
        std::cout << "Unesite dan mjesec i godinu pregleda: ";
        std::cin >> p_dan >> p_mjesec >> p_godina;
        
        std::cout << "Unesite sate i minute pregleda: ";
        std::cin >> p_sat >> p_minut;
        
        pregledi.RegistrirajPregled ( p_ime, p_dan, p_mjesec, p_godina, p_sat, p_minut );
        if ( max_br_p == ++i )
            break;
    }
    }
    catch ( const std::exception &e ) { std::cout << e.what (); return 0; }
    
    std::cout << "Trenutno su registrovani sljedeci pregledi\n";
    pregledi.IspisiSvePreglede ();
    
    while ( std::cout << "\nOdaberite jednu od sljedecih opcija\n"
        "1 - Broj pregleda na datum\n2 - Najraniji pregled\n3 - Obrisi pregled pacijenta\n"
        "4 - Obrisi najraniji pregled\n5 - Ispisi sve pregleda na datum\n6 - Ispisi sve preglede\n"
        "7 - Kraj programa\n" )
    {
        int izbor, pre_pre { pregledi.DajBrojPregleda () };
        std::cin >> izbor;
        if ( izbor == 7 )
            break;
        switch ( izbor )
        {
            case 1 :
                    std::cout << "Unesite dan mjesec i godinu : ";
                    std::cin >> p_dan >> p_mjesec >> p_godina;
                    std::cout << "Broj pregleda na datum " << p_dan << " " << p_mjesec << " " << p_godina << " je: " << 
                        pregledi.DajBrojPregledaNaDatum ( Datum ( p_dan, p_mjesec, p_godina ) ) << std::endl;
                break;
            case 2 :
                    std::cout << "Najraniji pregled je:\n";
                    try { pregledi.DajNajranijiPregled ().Ispisi (); }
                    catch ( const std::exception &e ) { std::cout << e.what (); }
                    std::cout << std::endl;
                break;
            case 3 :
                    std::cout << "Unesite ime pacijenta: ";
                    std::cin.clear ();
                    std::cin.ignore ( 30, '\n' );
                    p_ime = "";
                    std::getline ( std::cin, p_ime );
                    pregledi.ObrisiPregledePacijenta ( p_ime );
                    std::cout << "Uspjesno obrisano " << pre_pre - pregledi.DajBrojPregleda () << " pregleda\n";
                    i = pregledi.DajBrojPregleda ();
                break;
            case 4 :
                    try { pregledi.ObrisiNajranijiPregled (); }
                    catch ( const std::exception &e ) { std::cout << e.what () << std::endl; continue; }
                    std::cout << "Najraniji pregled uspjesno obrisan\n";
                break;
            case 5 :
                    std::cout << "Unesite dan mjesec i godinu : ";
                    std::cin >> p_dan >> p_mjesec >> p_godina;
                    std::cout << "Pregledi na datum " << p_dan << " " << p_mjesec << " " << p_godina << " su:\n";
                    pregledi.IspisiPregledeNaDatum ( Datum ( p_dan, p_mjesec, p_godina ) );
                    std::cout << std::endl;
                break;
            case 6 :
                pregledi.IspisiSvePreglede ();
        }
    }
    
    return 0;
}