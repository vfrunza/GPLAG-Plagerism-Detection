#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <limits>

/*** varijable 'x' i 'y' predstavljaju pozicije u vektoru vektora, 'level' najvecu-najmanju odaljenost od rubova, 'vrh' element na poziciji ('x','y') ***/
struct t_coord { int x, y, level; long double vrh; };


int min ( int a, int b ) { return ( a < b ) ? a : b; }

bool isRegular ( std::vector < std::vector < double > > m )
{
/*** vraca 'true' ako svaki red ima isti broj elemenata  ***/
    for ( std::vector < double > x : m )
        if ( m.at ( 0 ).size () != x.size () )
            return false;
    
    return true;
}

std::vector < std::vector < double > > makeMatrix (std::vector < std::vector < double > > m, t_coord c )
{
/*** vraca vector vectora kreiran iz parametra 'm' ogranicen vrijednostima iz 'c' ***/
	std::vector < std::vector < double > > pl ( 0 );
	int k;
	for ( int i = c.x - c.level, k = 0; i <= c.x + c.level; i++, k++ )
	{ 
		pl.push_back ( std::vector < double > ( 0 ) );
		for ( int j = c.y - c.level; j <= c.y + c.level; j++ )
			pl.at ( k ).push_back ( m.at ( i ).at ( j ) );
	}
	
	return pl;
}

int getLevel ( t_coord pos, int ver, int hor )
{
/*** vraca vrijednost jednaku minimalnoj udaljenosti pozicije 'pos' od rubova vectora vectora zadanog parametrima 'ver i 'hor' ***/
	if ( pos.x < ( ( ver % 2 == 0 ) ? ver / 2 : ver / 2 + 1 ) )
		return ( pos.y < ( ( hor % 2 == 0 ) ? hor / 2 : hor / 2 + 1 ) ) ? min ( pos.x, pos.y ) : min ( pos.x, hor - 1 - pos.y );
		
	return ( pos.y < ( ( hor % 2 == 0 ) ? hor / 2 : hor / 2 + 1 ) ) ? min ( ver - 1 - pos.x, pos.y ) : min ( ver - 1 - pos.x, hor - 1 - pos.y );
}

long double getSum ( std::vector < std::vector < double > > m, t_coord c )
{
/*** vraca sumu svih elemenata udaljenih za udaljenost iz 'c' od pozicije iz 'c' ***/
	long double sum { 0 };
	for ( int i = c.x - c.level; i <= c.x + c.level; i++ )
		for ( int j = c.y - c.level; j <= c.y + c.level; j++ )
			sum += ( i == c.x - c.level or i == c.x + c.level or
					j == c.y - c.level or j == c.y + c.level ) ? m.at ( i ).at ( j ) : 0;
			
	return sum;
}

bool isMountain ( std::vector < std::vector < double > > m, t_coord pos )
{
/*** vraca 'true' ako je pozicija iz parametra 'pos' "planina" u parametru 'm' ***/
	long double now_sum, pre_sum { m.at ( pos.x ).at ( pos.y ) };
	
	for ( int lvl = 1; lvl <= pos.level; lvl++ )
	{
		now_sum = getSum ( m, { pos.x, pos.y, lvl } );
		if ( pre_sum < now_sum ) // ovdje treba da bude '<='
			return false;
		pre_sum = now_sum;
	}
			
	return true;
}

std::vector < std::vector < double > > NajvecaPlaninaMatrice ( std::vector < std::vector < double > > m )
{
/*** vraca najdominantniji vector vectora ***/
    if ( m.size () == 0 or m.at ( 0 ).size () == 0 )
        return std::vector < std::vector < double > > ( 0 );
//provjera regularnosti i validnosti
    if ( !isRegular ( m ) )
        throw std::domain_error ( "Matrica nije korektna" );

  	t_coord cmax { 0, 0, 0, std::numeric_limits < long double >::min () };
  	int lvl;
  	
  	for ( int i = 0; i < int ( m.size () ); i++ )
  		for ( int j = 0; j < int ( m.at ( 0 ).size () ); j++ )
  		{
  			lvl = getLevel ( { i, j }, m.size (), m.at ( 0 ).size () ); // najmanja udaljenost trenutne pozicije od rubova
  			for ( int dis = lvl; dis >= 0; dis-- )
	  			if 
	  			( // poredjenje velicine elemenata && udaljenosti od rubova && planina
  					( cmax.vrh >= m.at ( i ).at ( j ) and cmax.level < dis and isMountain ( m, { i, j, dis } ) ) or
  					( cmax.vrh < m.at ( i ).at ( j ) and cmax.level <= dis and isMountain ( m, { i, j, dis } ) )
  				)
  					{ cmax = { i, j, dis, m.at ( i ).at ( j ) }; break; }
  		}
	
    return makeMatrix ( m, cmax );
}

int main ( void )
{
	int m, n;
	std::cout << "Unesite dimenzije matrice (m i n): ";
	std::cin >> m >> n;
	
	if ( m < 0 or n < 0 )
	{
	    std::cout << "Dimenzije matrice moraju biti nenegativne!";
	    return 0;
	}
	
	std::vector < std::vector < double > > mat ( m , std::vector < double > ( n ) );
	std::cout << "Unesite elemente matrice: ";
	for ( int i = 0; i < mat.size (); i++ )
	    for ( int j = 0; j < mat.at ( 0 ).size (); j++ )
	        std::cin >> mat.at ( i ).at ( j );
//poziv NPM funkcije, ispis, i provjera validnosti
	std::vector < std::vector < double > > planina;    
	try
	{
	    planina = NajvecaPlaninaMatrice ( mat );
	    std::cout << std::endl << "Najveca planina unesene matrice je:" << std::endl;
	    for ( std::vector < double > x : planina )
	    {
	        for ( double y : x )
	            std::cout << std::setw ( 6 ) << y;
	        std::cout << std::endl;
	    }
	}
	catch ( std::domain_error msg ) { std::cout << msg.what () << std::endl; }
	
	return 0;
}