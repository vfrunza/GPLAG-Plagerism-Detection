#include <iostream>
#include <stdexcept>
#include <cmath>

class Datum
{
    int dan, mjesec, godina;

    mutable int broj_dana [ 12 ] { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int broj_dana_do [ 12 ] { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 }; // kumulativni broj dana za svaki mjesec
    
    const char *ime_dana [ 7 ] { "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja", "Ponedjeljak", "Utorak" };
    const char *ime_mjesec [ 12 ] { "Januar", "Februar", "Mart", "April", "Maj", "Juni", "Juli", "August", "Septembar", "Oktobar", "Novembar", "Decembar" };

    
    bool LeapFebruar ( void ) const 
    {
        bool leap { false }; 
        if ( ( godina % 4 == 0 and godina % 100 != 0 ) or godina % 400 == 0 ) { leap = true; broj_dana [ 1 ]++; } 
        return leap; 
    }
    
    void ResetFebruar ( void ) const { broj_dana [ 1 ] = 28; }
    
    void Test_and_Set ( int, int, int ); // Testiranje parametara u formatu Datum i postavljanje clanova na vrijednosti parametara
    
    long DaysTillDate ( void ) const; // Konverzija u broj dana od 1/1/1800 do datuma 'this'
    
    int DoomsDay ( void ) const { return DaysTillDate () % 7; } // Konverzija datuma 'this' u redni dan u sedmici
    
    Datum ToDate ( long ); // Konverzija broja dana od 1/1/1800 u datum
    
public:
    enum Mjeseci { Januar = 1, Februar, Mart, April, Maj, Juni, Juli, August, Septembar, Oktobar, Novembar, Decembar };
    enum Dani { Ponedjeljak = 1, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja };

    Datum ( int dan, int mjesec, int godina ) { this -> Test_and_Set ( dan, mjesec, godina ); }
    Datum ( int dan, Mjeseci mjesec, int godina ) { this -> Test_and_Set ( dan, static_cast < int > ( mjesec ), godina ); }
    
    void Postavi ( int dan, int mjesec, int godina ) { this -> Test_and_Set ( dan, mjesec, godina ); }
    void Postavi ( int dan, Mjeseci mjesec, int godina ) { this -> Test_and_Set ( dan, static_cast < int > ( mjesec ), godina ); }
    
    int DajDan ( void ) const { return dan; }
    Mjeseci DajMjesec ( void ) const { return static_cast < Mjeseci > ( mjesec ); }
    int DajGodinu ( void ) const { return godina; }
    
    const char *DajImeMjeseca ( void ) const { return ime_mjesec [ mjesec - 1 ]; }
    
    Dani DanUSedmici ( void ) const { return static_cast < Dani > ( ( this -> DoomsDay () + 3 ) % 7 ); }
    const char *DajImeDanaUSedmici ( void ) const { return ime_dana [ this -> DoomsDay () ]; }
    
    Datum &operator ++ ( void );
    Datum operator ++ ( int );
    Datum &operator -- ( void );
    Datum operator -- ( int );
    friend Datum operator + ( const Datum &, long );
    friend Datum operator - ( const Datum &, long );
    
    friend long operator - ( const Datum &d1, const Datum &d2 ) { return d1.DaysTillDate () - d2.DaysTillDate (); }
    
    Datum &operator += ( long n ) { return *this = *this + n; }
    Datum &operator -= ( long n ) { return *this = *this - n; }

    friend bool operator == ( const Datum &d1, const Datum &d2 ) { return d1.DaysTillDate () == d2.DaysTillDate (); }
    friend bool operator != ( const Datum &d1, const Datum &d2 ) { return d1.DaysTillDate () != d2.DaysTillDate (); }
    
    friend bool operator < ( const Datum &d1, const Datum &d2 ) { return d1.DaysTillDate () < d2.DaysTillDate (); }
    friend bool operator > ( const Datum &d1, const Datum &d2 ) { return d1.DaysTillDate () > d2.DaysTillDate (); }
    
    friend bool operator <= ( const Datum &d1, const Datum &d2 ) { return d1 < d2 or d1 == d2; }
    friend bool operator >= ( const Datum &d1, const Datum &d2 ) { return d1 > d2 or d1 == d2; }
    
    operator std::string() const 
        { return std::to_string ( dan ) + "." + DajImeMjeseca () + " " + std::to_string ( godina ) + ".(" + DajImeDanaUSedmici () + ")"; }
    
    explicit operator int() const { return this -> DaysTillDate (); }
    
    friend std::ostream &operator << ( std::ostream &stream, const Datum &datum ) { return stream << std::string ( datum ); }
        
    friend std::istream &operator >> ( std::istream &, Datum & );
};

/** PRIVATE **/
inline Datum Datum::ToDate ( long d )
{
    godina = ( 10000 * d + 14780 ) / 3652425;
    dan = d - ( godina * 365 + godina / 4 - godina / 100 + godina / 400 );
    if ( dan < 0 )
    {
        godina--;
        dan = d - ( godina * 365 + godina / 4 - godina / 100 + godina / 400 );
    }
    
    long mi = ( 277 + 100 * dan ) / 3060;
    mjesec = mi % 12 + 1;

    dan = dan - broj_dana_do [ mjesec - 1 ] + 1;
    godina += 1800;
    if ( mjesec == 2 and dan <= 0 ) { mjesec = 1; dan = 31 + dan; }

    return *this;
}

inline long Datum::DaysTillDate ( void ) const
{
    long prvi = godina - 1800;
    prvi = prvi * 365 + std::trunc ( ( prvi - 1 ) / 4 ) - std::trunc ( ( prvi - 1 ) / 100 ) + std::trunc ( ( prvi - 1 ) / 400 );
    
    LeapFebruar ();
    prvi += dan + broj_dana_do [ mjesec - 1 ];
    
    if ( !LeapFebruar () ) prvi--;
    ResetFebruar ();
    
    return prvi;
}

void Datum::Test_and_Set ( int d, int m, int g )
{
    LeapFebruar ();
    if ( g < 1800 or d < 1 or m < 1 or m > 12 or d > broj_dana [ m - 1 ] )
    {
        ResetFebruar ();
        throw std::domain_error ( "Nelegalan datum" );
    }
    
    dan = d; mjesec = m; godina = g;
    ResetFebruar ();
}
/** =private= **/

/** PUBLIC **/
Datum &Datum::operator ++ ( void )
{
    LeapFebruar ();
    
    if ( ++dan > broj_dana [ mjesec - 1 ] ) { dan = 1; mjesec++; }
    if ( mjesec > 12 ) { mjesec = 1; godina++; }
    
    ResetFebruar ();
    
    return *this;
}

Datum Datum::operator ++ ( int )
{
    Datum temp { *this };
    ++( *this );
    return temp;
}

Datum &Datum::operator -- ( void )
{
    LeapFebruar ();
    
    if ( --dan < 1 )
    {
        if ( --mjesec < 1 ) { godina--; mjesec = 12; }
        
        dan = broj_dana [ mjesec - 1 ];
    }
    
    ResetFebruar ();
    
    if ( godina < 1800 )
        throw std::domain_error ( "Nelegalan datum" );
    
    return *this;
}

Datum Datum::operator -- ( int )
{
    Datum temp { *this };
    --( *this );
    return temp;
}

Datum operator + ( const Datum &d, long n )
{
    Datum datum ( d.dan, d.mjesec, d.godina );
    
    datum.ToDate ( d.DaysTillDate () + n );
    
    if ( datum.godina < 1800 )
        throw std::domain_error ( "Nelegalan datum" );
    
    return datum;
}

Datum operator - ( const Datum &d, long n )
{
    Datum datum ( d.dan, d.mjesec, d.godina );
    
    datum.ToDate ( d.DaysTillDate () - n );
    
    if ( datum.godina < 1800 )
        throw std::domain_error ( "Nelegalan datum" );
    
    return datum;
}

std::istream &operator >> ( std::istream &stream, Datum &datum )
{
    int d, m, y;
    char f, s;
    stream >> d >> f >> m >> s >> y;
    
    datum.LeapFebruar ();
    if ( f != '/' or s != '/' or y < 1800 or d < 1 or m < 1 or m > 12 or d > datum.broj_dana [ m - 1 ] )
        stream.setstate ( std::ios_base::failbit );
        
    datum.ResetFebruar ();
    
    if ( std::cin )
        datum.Postavi ( d, m, y );
    
    return stream;
}
/** =public= **/

int main ( void )
{
    Datum today ( 3, Datum::Januar, 2097 );
    Datum start_date ( today.DajDan (), today.DajMjesec (), today.DajGodinu () );
    
    std::cout << "Welcome to most advanced time machine in history,\ncapable of traveling at speeds faster than light .\n"
        "\nYou've been selected to test all functions of this\ninvention as most suitable candidate .\n\nGoodluck .\n";

    while ( std::cout << "\nTIME TRAVEL MENU : \n"
        "[ 1 ] Travel to date\n[ 2 ] Travel number of days\n[ 3 ] Travel to tomorrow\n"
        "[ 4 ] Travel to yesterday\n[ 5 ] Current date\n[ 6 ] Starting date\n[ 7 ] Rules of time travel\n"
        "[ 8 ] Machine info\n[ 9 ] How do I go back where I started ?\n" )
    {
        int opcija { 0 };
        std::cout << ">>> ";
        std::cin >> opcija;
            
        std::cout << std::endl;
        try
        {
            int days;
            Datum dest ( 1, 1, 1800 );
            switch ( opcija )
            {
                case 1 :
                        std::cout << "Input destination ( dd/mm/yyyy ) : ";
                        std::cin >> dest;
                        
                        if ( !std::cin )
                        {
                            std::cin.clear ();
                            std::cin.ignore ( 20, '\n' );
                            throw std::domain_error ( "Wrong input format!" );
                        }
                            
                        today.Postavi ( dest.DajDan (), dest.DajMjesec (), dest.DajGodinu () );
                        
                        if ( today == start_date )
                            throw std::runtime_error ( "" );
                    break;
                case 2 :
                        std::cout << "Input destination ( days ) from now : ";
                        std::cin >> days;
                        if ( days > 50000 or days < -50000 )
                            throw std::domain_error ( "You can not travel more than 50.000 days " );

                        dest.Postavi ( today.DajDan (), today.DajMjesec (), today.DajGodinu () );
                        dest += days;
                            
                        today.Postavi ( dest.DajDan (), dest.DajMjesec (), dest.DajGodinu () );
                        
                        if ( today == start_date )
                            throw std::runtime_error ( "" );
                    break;
                case 3 :                       
                        if ( ++today == start_date )
                            throw std::runtime_error ( "" );
                    break;
                case 4 :                       
                        if ( --today == start_date )
                            throw std::runtime_error ( "" );
                    break;
                case 5 : std::cout << "Today's date is " << today << std::endl; break;
                case 6 : std::cout << "Starting date is " << start_date << std::endl; break;
                case 7 :
                        std::cout << "RULES :\n"
                            "   -You can not travel longer than 50.000 days per run\n   -You can not travel to dates before 1st January 1800\n"
                            "   -You can not tell anyone that You're a time-traveler\n   -You can not bring any souvenirs with You\n"
                            "   -You can not kill your grandfather\n   -You can not have physical intercourse with anyone\n"
                            "   -You can not use data to make personal profit\n";
                    break;
                case 8 :
                        std::cout << "!!! GROUNDHOG THE TIME HACKER 9000 !!!\n"
                            "\nv.alpha.3\nModel Maverick\nRunning on Raspberry Pi OS\nOn 5000 x Raspberry Pi 17\n";
                    break;
                case 9 : std::cout << "In order to come back to today, You travel to today .\n";
            }
        }
        catch ( const std::domain_error &e ) { std::cout << "\nerror ( " << e.what () << " )\n"; continue; }
        catch ( const std::runtime_error &ext ) { break; }
    }
    
    std::cout << "\nWELCOME BACK TO TODAY\n";

    // Datum datum ( 1, 1, 1800 );
    // for ( int t = 1997; t < 1998; t++ ) for ( int k = 1; k < 13; k++ ) for ( int i = 1; i < 32; i++ )
    // {
    //     if ( k == 2 and i == 29 ) break;
    //     if ( ( k == 4 or k == 6 or k == 9 or k == 11 ) and ( i == 31 ) ) break;
    //     datum.Postavi ( i, k, t );
    //     std::cout << datum.DaysTillDate () << " (" << i << ")" << " " << datum.ToDate ( datum.DaysTillDate () ) << std::endl;
    // }
    
    // Datum d ( 3, 5, 1997 );
    // std::cout << std::endl << std::endl << d + 35 << std::endl;
    // std::cout << d - 5 << std::endl;
    // std::cout << int ( d ) << std::endl;
    // std::cout << datum - d << std::endl;

    return 0;
}