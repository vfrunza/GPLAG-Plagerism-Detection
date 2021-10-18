#include <iostream>
#include <list>
#include <utility>
#include <string>
#include <map>
#include <stdexcept>
#include <algorithm>
#include <queue>
#include <vector>

enum class Boje { Pik, Tref, Herc, Karo };

std::vector < std::string > StrBoje = { "Pik", "Tref", "Herc", "Karo" };

std::list < std::string > karte = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

typedef std::list < std::pair < Boje, std::string > > Spil;

namespace ab
{
    template < typename T, typename CONT >
    int getIndex ( T s, CONT kont, CONT end )
    {
    /*** vraca poziciju elementa u iterirajucem kontejneru ***/
        int i { 0 };
        do
        {
            if ( *kont == s )
                break;
            i++;
        }while ( ++kont != end );
        
        return i;
    }
    
    template < typename IT >
    bool besmisleno ( IT it )
    {   
    /*** vraca 'true' ako se vrijednosti iz parametra 'it' ne nalaze u predefinisanim vrijednostima koje oznacavaju karte ***/
        if ( std::find ( karte.begin (), karte.end (), it -> second ) == karte.end () ) // provjera za broj
            return true;
            
        for ( int i = 0; i < 4; i++ ) // provjera za znak
            if ( it -> first == static_cast < Boje > ( i ) )
                return false;
                
        return true;
    }
    
    void CardValidation ( const Spil &spil )
    {
    /*** testiranje na izuzetke definisane za tip 'Spil' ***/
        if ( spil.size () > 52 or besmisleno ( spil.begin () ) ) // provjerava takodjer prvi element, jer ne provjerava zajedno sa ostalim el. u petlji ispod 
            throw std::logic_error ( "Neispravna lista!" );

        typename Spil::const_iterator aftbeg { spil.begin () }, prelast { spil.end () };
        aftbeg++; prelast--;
        // provjera da li su elementi sortirani po postavci zadatka i da li odgovaraju predefinisanim vrijednostima za karte
        for ( typename Spil::const_iterator it = spil.begin (); it != prelast; it++ )
            if ( static_cast < int > ( it -> first ) > static_cast < int > ( aftbeg -> first ) and 
                getIndex ( it -> second, karte.begin (), karte.end () ) > getIndex ( aftbeg -> second, karte.begin (), karte.end () ) and 
                besmisleno ( aftbeg ) )
                    throw std::logic_error ( "Neispravna lista!" );
    }
    
    void StackValidation ( std::queue < std::pair < std::string, std::string > > stek, int n )
    {
    /*** testiranje na izuzetke definisane za neki tip reda ***/
        if ( n < 0 or n > 52 )
            throw std::domain_error ( "Broj n je besmislen!" );
        if ( n > stek.size () )
            throw std::range_error ( "Nedovoljno karata u redu!" );
        // provjera da li se vrijednosti reda nalaze u predefinisanim vrijednostima za karte
        while ( !stek.empty () )
        {
            std::pair < std::string, std::string > card = stek.front ();
            stek.pop ();
            if ( std::find ( karte.begin (), karte.end (), card.second ) == karte.end () or
                std::find ( StrBoje.begin (), StrBoje.end (), card.first ) == StrBoje.end () )
                    throw std::logic_error ( "Neispravne karte!" );
        }
    }
}

void IspisiSpil ( const Spil &spil )
{
/*** ispis kontejnera 'Spil' u formatu zadanom u postavci zadatka ***/
    std::cout << "U spilu trenutno ima " << spil.size () << " karata, i to:" << std::endl;
    typename Spil::const_iterator it = spil.begin ();
    for ( int i = 0; i < StrBoje.size (); i++ )
    {
        std::cout << StrBoje.at ( i ) << ":";
        while ( it != spil.end () and it -> first == static_cast < Boje > ( i ) )
        {
            std::cout << " " << it -> second;
            it++;
        }
        std::cout << std::endl;
    }
}

Spil KreirajSpil ( void )
{
    Spil spil;
    for ( int i = 0; i < 4; i++ ) // petlja za znakove
        for ( const std::string &broj : karte ) // petlja za brojeve
            spil.emplace_back ( static_cast < Boje > ( i ), broj );
    
    return spil;
}

void IzbaciKarte ( Spil &spil, std::multimap < Boje, std::string > &izb )
{
    ab::CardValidation ( spil );
    typename Spil::iterator itspil;
    for ( typename std::multimap < Boje, std::string >::iterator card = izb.begin (); card != izb.end(); card++ )
    {
        itspil = std::find_if ( spil.begin (), spil.end (), 
            [ card ] ( const std::pair < Boje, std::string > &el ) -> bool 
                { return el.first == card -> first and el.second == card -> second; } );
        // brisanje vrijednosti iteratora iz spila i mape, ako je uslov iznad zadovoljen         
        if ( itspil != spil.end () )
        {
            spil.erase ( itspil );
            card = izb.erase ( card );
        }
    }
}

std::queue < std::pair < std::string, std::string > > IzbaciKarteRazbrajanjem ( Spil &spil, const short &r, const int &b )
{
    if ( r < 1 or r > 52 or b < 1 )
        throw std::logic_error ( "Neispravni elementi za izbacivanje!" );
    ab::CardValidation ( spil );
    
    std::queue < std::pair < std::string, std::string > > stek;
    int i { 0 }, count { 1 };
    while ( spil.size () != 0 and i != b )
    {
        for ( typename Spil::iterator it = spil.begin (); it != spil.end (); it++ )
        {
            if ( ++count == r ) // cirkulacija kroz listu
            {
                ++it;
                stek.emplace ( StrBoje.at ( static_cast < int > ( it -> first ) ), it -> second ); // dodavanje u red
                it = spil.erase ( it ); // brisanje iz spila
                it--;
                count = 1;
                i++;
            }
            if ( i == b )
                break;
        }
    }
    return stek;
}

void VratiPrvihNKarata ( Spil &spil, std::queue < std::pair < std::string, std::string > > &stek , int n )
{
    ab::StackValidation ( stek, n );
    ab::CardValidation ( spil );
    
    std::pair < std::string, std::string > par;
    int i { 0 };
    while ( i++ != n )
    {
        par = stek.front ();
        stek.pop ();
        // dodavanje karte iz reda ( sa brisanjem ) na kraj spila
        spil.emplace_back ( static_cast < Boje > ( ab::getIndex ( par.first, StrBoje.begin (), StrBoje.end () ) ), par.second );
    }
    // sortiranje spila zbog novododanih karata
    spil.sort ( [] ( const std::pair < Boje, std::string > &one, const std::pair < Boje, std::string > &two )
        { 
            if ( static_cast < int > ( one.first ) < static_cast < int > ( two.first ) ) // sortiranje po znaku
                return true;
            else if ( static_cast < int > ( one.first ) == static_cast < int > ( two.first ) )
                // sortiranje po broju
                if ( ab::getIndex ( one.second, karte.begin (), karte.end () ) < ab::getIndex ( two.second, karte.begin (), karte.end () ) )
                    return true;
            return false;
        } );
}

int main ( void ) 
{
    short raz;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> raz;
    
    int izb;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> izb;
    
    try
    {
        Spil spil { KreirajSpil () };
        std::queue < std::pair < std::string, std::string > > obrisane { IzbaciKarteRazbrajanjem ( spil, raz, izb ) };
        
        IspisiSpil ( spil );
        
        std::cout << "Unesite broj karata koje zelite vratiti u spil: ";
        std::cin >> izb;
        VratiPrvihNKarata ( spil, obrisane, izb );
        
        IspisiSpil ( spil ); 
    }
    catch ( const std::exception &exc ) { std::cout << "Izuzetak: " << exc.what (); }
    return 0;
}