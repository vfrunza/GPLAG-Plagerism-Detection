#include <iostream>
#include <deque>
#include <vector>

enum class SmjerKretanja { NaprijedNazad, NazadNaprijed, GoreDolje, DoljeGore, LijevoDesno, DesnoLijevo };

template < typename C >
auto PjescaniSat ( C kont, SmjerKretanja smjer ) -> decltype ( kont )
{
//size at push_back
	typedef typename std::remove_reference < decltype ( kont*** ) >::type ETip;
	typedef typename std::remove_reference < decltype ( kont** ) >::type FCTip;
	typedef typename std::remove_reference < decltype ( kont* ) >::type SCTip;
	typedef typename std::remove_reference < decltype ( kont ) >::type CTip;
	
	for ( int i = 0; i < kont.size (); i++ )
	{
		if ( kont.size () != kont.at ( i ).size () )
			throw std::domain_error ( "3D matrica nema oblik kocek" );
		for ( int j = 0; j < kont.at ( i ). size (); j++ )
			if ( kont.size () != kont.at ( i ).at ( j ).size () )
				throw std::domain_error ( "3D matrica nema oblik kocke");
	}
	if ( kont.size () % 2 == 0 )
		throw std::length_error ( "3D kontejner ne zadovoljava uvjet neparnosti" );

	CTip sat;
		
	for ( int i = 0; i < kont.size (); i++ )
	{
		sat.push_back ( SCTip () );
		for ( int j = ( smjer == SmjerKretanja::GoreDolje ) ? kont.at ( i ).size () - 1 : 0;
			( smjer == SmjerKretanja::GoreDolje ) ? j >= 0 : j < kont.at ( i ).size (); j++ )
		{
			sat.at ( i ).push_back ( FCTip );
			for ( int k = 0; k < kont.at ( i ).at ( j ).size (); k++ )
			{
				if (  )
					sat.at ( i ).at ( j ).push_back ( kont.at ( i ).at ( j ).at ( k );
			}
		}
	}
		
	return sat;
}

int main ( void )
{
	int n;
	std::cout << "Unesite dimenziju (x/y/z): ";
	std::cin >> n;
	std::vector < std::deque < std::deque < int > > > kont ( n, std::deque < std::deque < int > > ( n, std::deque < int > ( n ) ) );
	std::cout << "Unesite elemente kontejnera: ";
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			for ( int k = 0; k < n; k++ )
				std::cin >> kont.at ( i ).at ( j ).at ( k );
	
	int dir;
	std::cout << "Unesite smjer kretanja [0 - 5]:";
	std::cin >> dir;
	try
	{
		auto sat = PjescaniSat ( kont, static_cast < SmjerKretanja > ( dir ) );
	}
	catch ( const std::exception &exc )
	{
		std::cout << exc.what ();
	}
	
	return 0;
}