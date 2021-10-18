#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <string>

bool isPrime ( unsigned long n )
{
/*** vraca 'true' ako je parametar prost broj, u suprotnom 'false' ***/
    if ( n <= 2 )
        return ( n == 2 ) ? true : false;
    
    for ( long i = 2; i <= static_cast < long > ( std::sqrt ( n ) ); i++ )
        if ( n % i == 0 )
            return false;
        
    return true;
}

bool isDuplicate ( std::vector < int > v, long n )
{
/*** vraca 'true' ako se u vectoru 'v' nalazi element sa istom vrijednoscu kao parametar 'n' ***/
    for ( long x : v )
        if ( x == n ) 
            return true;
    
    return false;
}

bool isSimetric ( std::string s )
{
/*** vraca 'true' ako je parametar simetrican ( lijevo-desno ) ***/
    int i { int ( s.length () ) - 1 };
    int j { 0 };
//poredjenje znakova linearno izvana ka unutra
    for ( ; i > ( s.length () - 1 ) / 2; )
        if ( s.at ( i-- ) != s.at ( j++ ) )
            return false;
            
    return true;
}

std::string toBase3 ( long n )
{
/*** vraca vrijednost u bazi 10 predstavljenu u bazi 3 od parametra 'n' ***/
    std::string ter;
    do { ter += std::to_string ( std::abs ( n % 3 ) ); } while ( ( n /= 3 ) != 0 );

    return ter;
}

std::vector < int > IzdvojiSimetricneTernarne ( std::vector < int > v, bool p )
{
/*** vraca vector u kojem se nalaze vrijednosti koje su simetricne svojoj reprezentaciji u bazi 3,
    te odgovaraju uslovu parametra 'p' ***/
    std::vector < int > smtrc;

    for ( long x : v )
        if ( !isDuplicate ( smtrc, x ) and isPrime ( std::abs ( x ) ) == p and isSimetric ( toBase3 ( x ) ) )
            smtrc.push_back ( x );
    
    return smtrc;
}

int main ( void )
{
//unos vector
    std::vector < int > vec;
    int temp;
    std::cout << "Unesite elemente vektora (-1 za kraj): ";
    while ( std::cin >> temp, temp != -1 )
        vec.push_back ( temp );
//unos prost - slozen
    std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    while ( std::cin >> temp, temp != 0 and temp != 1 )
        std::cout << "Neispravan unos! Unesite ponovo: ";
    bool prime ( temp );
//provjera i ispis simetric vector    
    std::vector < int > sim = IzdvojiSimetricneTernarne ( vec, prime );
    if ( sim.size () > 0 )
    {
        temp = sim.at ( sim.size () - 1 );
        std::cout << ( ( prime ) ? "Prosti" : "Slozeni" ) << " simetricni brojevi iz vektora su: ";
        for ( int x : sim )
            std::cout << x << ( ( x != temp ) ? ", " : "." );
    }
    else std::cout << "Nema "<< ( ( prime ) ? "prostih" : "slozenih" ) << " simetricnih brojeva u vektoru.";
    std::cout << std::endl;
    
    return 0;
}