#include <iostream>
#include <new>
#include <stdexcept>
#include <vector>
#include <type_traits>
#include <algorithm>
#include <iomanip>

namespace ab
{
	template < typename T > 
	int Period ( const std::vector < T > &v )
	{
	/*** vraca minimalni period elemenata vektora***/
		int p, i;
		for ( p = 1; p < v.size (); p++ )
		{
			for ( i = 0; i < v.size () - p; i++ )
				if ( v.at ( i ) != v.at ( i + p ) )
					break;
		
			if ( i == v.size () - p )
				break;
		}
		
		return p;
	}
	
	template < typename T > 
	void expand ( const std::vector < T > &v, int &koliko_puta, int &period )
	{
	/*** dodjeljuje vrijednost koliko_puta u skladu sa prosirenjem perioda ili ne; periodu dodjeljuje osnovni period vektora ***/
		period = Period ( v );
		koliko_puta = v.size () / period;
		
		koliko_puta = ( v.size () % koliko_puta != 0 or koliko_puta == 1 ) ? ( koliko_puta == 1 ) ? 2 : koliko_puta + 1 : koliko_puta;
	}
	
	template < typename T > 
	void testException ( const std::vector < T > &v )
	{
	/*** testira izuzetke za vektor ( definisani u zadatku ) ***/
		if ( v.empty () )
			throw ( "Prazan vektor!" );
		
		for ( T x : v )
			if ( x < 1 )
				throw std::domain_error ( "Neispravan vektor!" );
	}
	
	template < typename T > 
	int numOfElements ( const std::vector < T > &v, int koliko_puta, int period )
	{
	/*** vraca broj elemenata koji je potreban za kontinualnu alokaciju matrice ***/
		int n { 0 };
		for ( int i = 0; i < period * koliko_puta; i++ )
			n += v.at ( i % period );
			
		return n;
	}

}

template < typename T >
auto AlocirajFragmentirano ( const std::vector < T > &v, int &koliko_puta ) ->
	typename std::remove_const < typename std::remove_reference < decltype ( v [ 0 ] ) >::type >::type **
{
// sve sto nije alokacija
	ab::testException ( v );
	int period;
	ab::expand ( v, koliko_puta, period );
//
	typedef	typename std::remove_const < typename std::remove_reference < decltype ( v [ 0 ] ) >::type >::type RRCT;
	
	RRCT **p { nullptr };
	try
	{
		p = new RRCT *[ period * koliko_puta ];
		for ( int i = 0; i < v.size (); i++ )
			p [ i ] = nullptr;
		
		for ( int i = 0; i < period * koliko_puta; i++ )
			p [ i ] = new RRCT [ int ( v.at ( i % period ) ) ];
	}
	catch ( std::bad_alloc )
	{
		for ( int i = 0; i < period * koliko_puta; i++ )
			delete [] p [ i ];
		delete [] p;
		throw;
	}
	
	RRCT max = *std::max_element ( std::begin ( v ), std::end ( v ) );
	for ( int i = 0; i < period * koliko_puta; i++ )
	{
		int k = max - v.at ( i % period ) + 1;
		for ( int j = 0; j < v.at ( i % period ); j++ )
			p [ i ] [ j ] = k++;
	}
	
	return p;
}

template < typename T >
auto AlocirajKontinualno ( const std::vector < T > &v, int &koliko_puta ) ->
	typename std::remove_const < typename std::remove_reference < decltype ( v [ 0 ] ) >::type >::type **
{
// sve sto nije alokacija
	ab::testException ( v );
	int period;
	ab::expand ( v, koliko_puta, period );
//	
	typedef	typename std::remove_const < typename std::remove_reference < decltype ( v [ 0 ] ) >::type >::type RRCT;
	
	RRCT **p { nullptr };
	try
	{
		p = new RRCT *[ period * koliko_puta ];
		*p = nullptr;
		
		*p = new RRCT [ ab::numOfElements ( v, koliko_puta, period ) ];
		for ( int i = 0; i < period * koliko_puta - 1; i++ )
			p [ i + 1 ] = p [ i ] + v.at ( i % period );
	}
	catch ( std::bad_alloc )
	{
		delete [] *p;
		delete [] p;
		throw;
	}
	
	int k;
	for ( int i = 0; i < period * koliko_puta; i++ )
	{
		k = v.at ( i % period );
		for ( int j = 0; j < v.at ( i % period ); j++ )
			p [ i ] [ j ] = k--;
	}
	
	return p;
}

int main ( void )
{
	int n, all, koliko_puta;
	std::cout << "Unesite broj elemenata vektora: ";
	std::cin >> n;
	std::vector < int > v;
	
	int **p { nullptr };
	try
	{	
		v.resize ( n );
		std::cout << "Unesite elemente vektora: ";
		for ( int &x : v )
			std::cin >> x;
			
		std::cout << "Odaberite alokaciju: 1 - fragmentirana, 0 - kontinualna: ";
		std::cin >> all;
		
		p = ( all == 1 ) ? AlocirajFragmentirano ( v, koliko_puta ) : AlocirajKontinualno ( v, koliko_puta );
	}
	catch ( std::domain_error domain )
	{
		std::cout << "Izuzetak: " << domain.what ();
		return 0;
	}
	catch ( const char *c )
	{
		std::cout << "Izuzetak: " << c;
		return 0;
	}
	catch ( std::bad_alloc ball )
	{
		std::cout << "Izuzetak: " << ball.what ();
		return 0;
	}
	
	int period = ab::Period ( v );
	
	std::cout << "Dinamicki alocirana matrica:" << std::endl;
	for ( int i = 0; i < period * koliko_puta; i++ )
	{
		for ( int j = 0; j < v.at ( i % period ); j++ )
			std::cout << std::left << std::setw ( 3 ) << p [ i ] [ j ];
		std::cout << std::endl;
	}
	
	if ( all == 1 )
	{
		for ( int i = 0; i < period * koliko_puta; i++ )
			delete [] p [ i ];
		delete [] p;
	}
	else
	{
		delete [] *p;
		delete [] p;
	}
	
	return 0;
}