#include <iostream>
#include <vector>
#include <deque>
#include <limits>

enum Smjer { Opadajuci, Rastuci };

/*** vraca 'true' ako je drugi parametar 'b' jednak ili VECI od prvog parametra 'a' ***/
bool bigger ( long a, long b ) { return ( a <= b ) ? true : false; }

/*** vraca 'true' ako je drugi parametar 'b' jednak ili MANJI od prvog parametra 'a' ***/
bool smaller ( long a, long b ) { return ( a >= b ) ? true : false; }

bool isPowerOf2 ( long n )
{
/*** vraca true ako je parametar 'n' stepen broja 2 ***/
    if ( n < 1 ) return false; // ne treba ovo, ali eto
//dodaje bit na lijevo
    return ( ( n & -n ) == n ) ? true : false;
}

std::deque < std::vector < int > > MaksimalniPodnizoviStepenaDvojke ( std::vector < int > v, Smjer smjer )
{
/*** MaksimalniPodnizoviStepenaDvojke, mislim da naziv funkcije ne moze biti jasniji ***/
    std::deque < std::vector < int > > skup;
    
    std::vector < int > tt;
    long temp;
    bool first = false;
    
    for ( int i = 0; i < int ( v.size () ); i++ )
    {
        if ( isPowerOf2 ( v.at ( i ) ) )
        {
            if ( !first ) //da li je trenutni clan vektora iz parametra 'v' -> $ potencijalni PRVI ELEMENT podniza stepena dvojke
            {
                first = true;
                tt.resize ( 0 );
                temp = ( smjer == Rastuci ) ? 0 : std::numeric_limits < long >::max ();
            }
            
            if ( ( smjer == Rastuci ) ? bigger ( temp, v.at ( i ) ) : smaller ( temp, v.at ( i ) ) ) // uporedba veci-manji od prethodnog
                tt.push_back ( temp = v.at ( i ) );
            else    // trenutni clan odgovara suprotnom smjeru za podniz
            {
                if ( tt.size () > 1 ) skup.push_back ( tt );
                tt.resize ( 0 );
                tt.push_back ( temp = v.at ( i ) ); // trenutni clan je prosao uslov da je stepen dvojke -> $
            }
        }
        else
            first = false; // ## osposobljava da sljedeci clan koji je stepen dvojke bude -> $
//dodavanje pomocnog vektora u deque, i praznjenje istog            
        if ( !first and tt.size () > 1 ) // trenutni clan nije stepen dvojke, ako vektor ima dovoljno elemenata dodaje se u deque
        {
            skup.push_back ( tt );
            tt.resize ( 0 );
            first = false; // ##
        }
    }
//ostatak elemenata u pomocnom vektoru se dodaje u deque
    if ( tt.size () >  1 ) skup.push_back ( tt );

	return skup;
}

int main ( void )
{
    int vel;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> vel;
	
	std::vector < int > vec;
	long temp;
//unos vectora
    std::cout << "Unesite elemente vektora: ";
    for ( int i = 0; i < vel; i++ )
        ( std::cin >> temp ), vec.push_back ( temp );
//unos i konverzija smjera
    Smjer direct;
    int stat;
    std::cout << "Unesite: 1 - za rastuce podnizove, 2 - za opadajuce podnizove: ";
    std::cin >> stat;
    direct = ( stat == 2 ) ? Opadajuci : Rastuci;
    
    std::deque < std::vector < int > > subarr = MaksimalniPodnizoviStepenaDvojke ( vec, direct );

	std::cout << "Maksimalni " << ( ( stat == 1 ) ? "rastuci" : "opadajuci" ) << " podnizovi: ";
	for ( std::vector < int > x : subarr )
	{
        std::cout << std::endl;
	    for ( int y : x )
	        std::cout << y << " ";
	}
	
	return 0;
}