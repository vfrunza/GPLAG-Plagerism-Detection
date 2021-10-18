#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <set>
#include <stdexcept>
#include <algorithm>
#include <vector>

typedef std::map < std::string, std::vector < std::string > > Knjiga;

typedef std::set < std::tuple < std::string, long, long > > Pozicije;

typedef std::map < std::string, Pozicije > IndeksPojmova;

IndeksPojmova KreirajIndeksPojmova ( Knjiga book )
{
    int pos;
    std::string word { "" };
    IndeksPojmova pojmovi;
    for ( auto const &page : book )
        for ( int i = 0; i < page.second.size (); i++ )
            for ( int j = 0; j < page.second.at ( i ).length (); j++ )
            {
                if ( isalnum ( page.second.at ( i ).at ( j ) ) )
                { // formiranje rijeci iz vektora
                    pos = j; // pozicija rijeci
                    while ( j != page.second.at ( i ).length () and isalnum ( page.second.at ( i ).at ( j ) ) )
                        word += page.second.at ( i ).at ( j++ );
                }
                else 
                    continue;
                
                std::transform ( word.begin (), word.end (), word.begin (), ::tolower );
                int foo = i + 1; // stranica na kojoj se nalazi rijec, 1+index
                
                pojmovi [ word ].insert ( std::tie ( page.first, foo, pos ) );
                word = "";
            }

    return pojmovi;            
}

Pozicije PretraziIndeksPojmova ( std::string s, IndeksPojmova pojmovi )
{
    IndeksPojmova::iterator it { pojmovi.find ( s ) };
    if ( it == pojmovi.end () )
        throw std::logic_error ( "Unesena rijec nije nadjena!" );
    
    return it -> second;
}

void IspisiIndeksPojmova ( IndeksPojmova pojmovi )
{
    for ( auto const &pojam : pojmovi )
    {
        std::cout << pojam.first << ":";
        unsigned long vel { pojam.second.size () }, i { 0 };
        
        for ( const std::tuple < std::string, long, long > &tup : pojam.second )
            std::cout << " " << std::get < 0 > ( tup ) << "/" << std::get < 1 > ( tup ) << "/" << std::get < 2 > ( tup ) << 
                ( ( ++i == vel ) ? "\n" : "," );
    }
}

int main ( void )
{
    std::string input, head;
    Knjiga book;
    while ( true )
    {
        std::cout << "Unesite naziv poglavlja: ";
        std::getline ( std::cin, head );
        if ( head == "." )
            break;
        for ( int i = 1; ; i++ )
        {
            std::cout << "Unesite sadrzaj stranice " << i << ": ";
            std::getline ( std::cin, input );
            if ( input == "." )
                break;
            book [ head ].push_back ( input );
        }
    }
    
    IndeksPojmova indp { KreirajIndeksPojmova ( book ) };
    
    std::cout << "\nKreirani indeks pojmova:" << std::endl;
    IspisiIndeksPojmova ( indp );
    std::cout << std::endl;
    
    Pozicije pos;
    while ( true )
    {
        std::cout << "Unesite rijec: ";
        std::getline ( std::cin, input );
        if ( input == "." )
            break;
                
        std::transform ( input.begin (), input.end (), input.begin (), ::tolower );
        
        try { pos = PretraziIndeksPojmova ( input, indp ); }
        catch ( const std::exception &e) { std::cout << e.what () << std::endl; continue; }

        for ( const std::tuple < std::string, long, long > &tup : pos )
            std::cout << std::get < 0 > ( tup ) << "/" << std::get < 1 > ( tup ) << "/" << std::get < 2 > ( tup ) << " ";
        
        std::cout << std::endl;
    }
    
    return 0;
}