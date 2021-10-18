#include <iostream>
#include <utility>
#include <string>
#include <map>
#include <stdexcept>
#include <algorithm>
#include <stack>
#include <vector>
#include <new>
#include <memory>

enum class Boje { Pik, Tref, Herc, Karo };

static const char *BojeString [] { "Pik", "Tref", "Herc", "Karo" };
static const char *KarteString [] { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

const std::map < std::string, short > StrBoje = { { "Pik", 0 }, { "Tref", 1 }, { "Herc", 2 }, { "Karo", 3 } };
const std::map < std::string, short > karte = { { "2", 0 }, { "3", 1 }, { "4", 2 }, { "5", 3 }, { "6", 4 }, { "7", 5 }, { "8", 6 }, { "9", 7 }, 
                                                { "10", 8 }, { "J", 9 }, { "Q", 10 }, { "K", 11 }, { "A", 12 } };

struct Karta 
{ 
    Boje boja; 
    std::string broj; 
};

struct Cvor 
{ 
    Karta karta; 
    std::shared_ptr < Cvor > sljedeci; 
};

namespace ab
{
    bool besmisleno ( std::shared_ptr < Cvor > it )
    {
    /*** vraca 'true' ako se vrijednosti iz parametra 'it' ne nalaze u predefinisanim vrijednostima koje oznacavaju karte ***/
        if ( karte.find ( it -> karta.broj ) == karte.end () ) // provjera za broj
            return true;
       
        for ( const std::pair < std::string, short > &boja : StrBoje ) // provjera za znak
            if ( it -> karta.boja == static_cast < Boje > ( boja.second ) )
                return false;
       
        return true;
    }
    
    unsigned size ( std::shared_ptr < Cvor > first )
    {
    /*** vraca velicinu liste***/
        if ( first == nullptr ) // prazan spil
            return 0;
        
        unsigned vel { 0 };
        std::shared_ptr < Cvor > slider { first };
        do
        {
            vel++;
            if ( vel > 52 ) // prelazak validne velicine za spil
                break;
            slider = slider -> sljedeci;
        }while ( slider != first and slider != nullptr ); // i ciklicne i linearne liste
        
        return vel;
    }
    
    void CardValidation ( std::shared_ptr < Cvor > first )
    {
    /*** testiranje na izuzetke definisane za tip 'Spil' ***/
        if ( first == nullptr )
            return;
    
        if ( size ( first ) > 52 or besmisleno ( first ) ) // provjerava takodjer prvi element, jer ne provjerava zajedno sa ostalim el. u petlji ispod 
            throw std::logic_error ( "Neispravna lista!" );
            
        std::shared_ptr < Cvor > slider { first }, aftbeg { first -> sljedeci };
        do // provjera da li su elementi sortirani po postavci zadatka i da li odgovaraju predefinisanim vrijednostima za karte
        {          
            if ( ( static_cast < int > ( slider -> karta.boja ) > static_cast < int > ( aftbeg -> karta.boja ) and
                karte.at ( slider -> karta.broj ) > karte.at ( aftbeg -> karta.broj ) ) or 
                besmisleno ( aftbeg ) )
                    throw std::logic_error ( "Neispravna lista!" );      
            
            aftbeg = aftbeg -> sljedeci;
            slider = slider -> sljedeci;
        }while ( aftbeg != first );
    }
    
    void StackValidation ( std::stack < std::pair < std::string, std::string > > stek, int n )
    {
    /*** testiranje na izuzetke definisane za neki tip reda ***/
        if ( n < 0 or n > 52 )
            throw std::domain_error ( "Broj n je besmislen!" );
        if ( n > stek.size () )
            throw std::range_error ( "Nedovoljno karata u steku!" );
        // provjera da li se vrijednosti reda nalaze u predefinisanim vrijednostima za karte        
        while ( !stek.empty () )
        {
            std::pair < std::string, std::string > card = stek.top ();
            stek.pop ();
            if ( karte.find ( card.second ) == karte.end () or
                StrBoje.find ( card.first ) == StrBoje.end () )
                    throw std::logic_error ( "Neispravne karte!" );
        }
    }
    
    std::shared_ptr < Cvor > last_el ( std::shared_ptr < Cvor > first )
    {
    /*** vraca adresu "posljednjeg" elementa u listi ***/
        if ( first == nullptr ) // prazan spil
            return nullptr;
            
        std::shared_ptr < Cvor > slider { first }, pre { first };
        do
        {
            if ( slider != first )
                pre = pre -> sljedeci;
            slider = slider -> sljedeci;
        }while ( slider != first );
    
        return pre;
    }
    
    std::shared_ptr < Cvor > find ( std::shared_ptr < Cvor > first, const std::pair < Boje, std::string > &el )
    {        
    /*** vraca element koji se nalazi prije elemente iz liste koji je jednak parametru 'el' ***/
        if ( first == nullptr ) // prazna lista
            return nullptr;
            
        std::shared_ptr < Cvor > slider { first };
        do
        {
            if ( slider -> karta.boja == el.first and slider -> karta.broj == el.second )
                return last_el ( slider );

            slider = slider -> sljedeci;
        }while ( slider != first );            
        
        return nullptr; // parametar 'el' se ne podudara niti sa jednim elementom iz liste
    }
    
    std::shared_ptr < Cvor > insert ( std::shared_ptr < Cvor > first, const std::pair < Boje, std::string > &el )
    {
        if ( first == nullptr )
        {
            first = std::make_shared < Cvor > ();
            first -> karta.boja = el.first; first -> karta.broj = el.second;
            first -> sljedeci = nullptr;
            return first -> sljedeci = first;
        }
        
        std::shared_ptr < Cvor > exist { find ( first, el ) }, pre { nullptr };
        if ( !exist ) // da li vec postoji element u listi
        {
            std::shared_ptr < Cvor > slider { first };
            while ( static_cast < int > ( slider -> karta.boja ) < static_cast < int > ( el.first ) )
                slider = slider -> sljedeci;
                
            while ( karte.at ( slider -> karta.broj ) < karte.at ( el.second ) )
                slider = slider -> sljedeci;
                
            pre = last_el ( slider );    
                
            std::shared_ptr < Cvor > novi = std::make_shared < Cvor > ();
            novi -> karta.boja = el.first; novi -> karta.broj = el.second;
            novi -> sljedeci = slider;
            
            pre -> sljedeci = novi;
        }
        
        return pre -> sljedeci; // vraca se pokazivac na novouneseni element
    }
    
    std::shared_ptr < Cvor > erase ( std::shared_ptr < Cvor > it )
    {
        if ( it -> sljedeci == it ) // brisanje elementa koji je jedini clan liste, nakon ovoga lista je prazna
        {
            it -> sljedeci = nullptr;
            return it = nullptr;
        }
        
        std::shared_ptr < Cvor > pre { last_el ( it ) };
        
        pre -> sljedeci = it -> sljedeci;
        
        return pre; // vraca pokazivac na prethodni element obrisanog elementa
    }
}

void IspisiSpil ( std::shared_ptr < Cvor > first )
{
/*** ispis kontejnera 'Spil' u formatu zadanom u postavci zadatka ***/;
    std::shared_ptr < Cvor > slider { first }, pre { ab::last_el ( first ) };
    
    std::cout << "U spilu trenutno ima " << ab::size ( first ) << " karata, i to:";
    for ( const char *boja : BojeString )
    {
        std::cout << std::endl << boja << ":";
        if ( first == nullptr or static_cast < std::string > ( boja ) != BojeString [ static_cast < int > ( slider -> karta.boja ) ] )
            continue; // prazna lista ili se ne poklapa znak
            
        do
        {
            std::cout << " " << slider -> karta.broj;
            
            pre = pre -> sljedeci;
            slider = slider -> sljedeci;
        }while ( karte.at ( slider -> karta.broj ) > karte.at ( pre -> karta.broj ) );
    }    
}

std::shared_ptr < Cvor > KreirajSpil ( void )
{
/*** vraca pokazivac na prvi 'element' liste ***/

    std::shared_ptr < Cvor > prvi, last;
    
    for ( int i = 0; i < 4; i++ )
        for ( const char *broj : KarteString )
        {
            std::shared_ptr < Cvor > novi = std::make_shared < Cvor > ();
            novi -> karta.boja = static_cast < Boje > ( i ); novi -> karta.broj = static_cast < std::string > ( broj );
            novi -> sljedeci = nullptr;
            ( !prvi ) ? ( prvi = novi ) : ( last -> sljedeci = novi );
            last = novi;
        }
        
    return last -> sljedeci = prvi;
}

void IzbaciKarte ( std::shared_ptr < Cvor > &spil, std::multimap < Boje, std::string > &izb )
{    
    ab::CardValidation ( spil );
    
    std::shared_ptr < Cvor > del;
    for ( typename std::multimap < Boje, std::string >::iterator card = izb.begin (); card != izb.end(); card++ )
    {
        del = ab::find ( spil, *card );
        if ( !del )
        {
            card = izb.erase ( card );
            
            ab::erase ( del -> sljedeci );
        }
    }
}

std::stack < std::pair < std::string, std::string > > IzbaciKarteRazbrajanjem ( std::shared_ptr < Cvor > &first, const short &r, const int &b )
{
    if ( r < 1 or r > 52 or b < 1 )
        throw std::logic_error ( "Neispravni elementi za izbacivanje!" );
    ab::CardValidation ( first );
    
    std::shared_ptr < Cvor > slider { first };
    
    std::stack < std::pair < std::string, std::string > > stek;
    int i { 0 }, count { 0 };
    while ( slider != nullptr and i != b )
    {
        if ( ++count == r )
        {
            stek.emplace ( BojeString [ static_cast < int > ( slider -> karta.boja ) ], slider -> karta.broj );
            
            slider = ab::erase ( slider );
            
            if ( slider == nullptr )
                break;

            count = 0;
            i++;
        }

        slider = slider -> sljedeci;
    }    

    return stek;
}

void VratiPosljednihNKarata ( std::shared_ptr < Cvor > &first, std::stack < std::pair < std::string, std::string > > &stek, int n )
{
    ab::StackValidation ( stek, n );
    ab::CardValidation ( first );
    
    std::pair < std::string, std::string > par;
    int i { 0 };
    while ( i++ != n )
    {
        par = stek.top ();
        stek.pop ();
        
        ab::insert ( first, std::make_pair ( static_cast < Boje > ( StrBoje.at ( par.first ) ), par.second ) );
    }
}

int main ( void ) 
{
    short raz;
    std::cout << "Unesite korak razbrajanja: ";
    std::cin >> raz;
    
    int izb;
    std::cout << "Unesite broj karata koje zelite izbaciti: ";
    std::cin >> izb;
    
    std::shared_ptr < Cvor > spil;
    try
    {
        spil = KreirajSpil ();
        std::stack < std::pair < std::string, std::string > > obrisane { IzbaciKarteRazbrajanjem ( spil, raz, izb ) };
        
        IspisiSpil ( spil );
        
        std::cout << "\nUnesite broj karata koje zelite vratiti u spil: ";
        std::cin >> izb;
        VratiPosljednihNKarata ( spil, obrisane, izb );
        
        IspisiSpil ( spil );
    }
    catch ( const std::exception &exc ) { std::cout << "Izuzetak: " << exc.what (); }
    return 0;
}