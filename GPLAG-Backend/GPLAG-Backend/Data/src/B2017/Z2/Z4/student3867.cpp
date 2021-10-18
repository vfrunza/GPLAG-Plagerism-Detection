#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <type_traits>

template < typename T, typename U, typename F >
void SortirajPodrucjeVrijednosti ( T slider_prvi, T end_prvi, T slider_drugi, U slider_treci, 
	F equation, bool ( *comp_func ) ( int, int ) )	
{
/*** uparuje elemente treceg skupa sa odgovarajucim pozicijama u druga dva skupa na osnovu uvjeta zadanim funkcijom ***/
	long size { end_prvi - slider_prvi }; // velicina niza
	std::sort ( slider_prvi, end_prvi, comp_func );
	std::sort ( slider_drugi, slider_drugi + size, comp_func );
	
	typedef typename std::remove_reference < decltype ( *slider_treci ) >::type UType;
	
	UType eval { 0 };
	U eval_pos { 0 };
	U begin_treci { slider_treci }; //za pretrazivanje treceg niza
	
	while ( slider_prvi != end_prvi )
	{
		eval = equation ( *slider_prvi, *slider_drugi );
	// pozicija trazenog elementa u trecem nizu
		eval_pos = std::find ( begin_treci, begin_treci + size, eval );
	// ako ne postoji, onda je pozicija iza kraja niza
		if ( eval_pos == begin_treci + size )
			throw std::logic_error ( "Vrijednost koja odgovara nekom od parova nije nadjena" );
		
		std::swap ( *slider_treci, *eval_pos ); // zamjena trenutne sa pozicijom na kojoj se nalazi element
	// sljedeca iteracija kroz nizove
		slider_prvi++; slider_drugi++; slider_treci++;
	}
}

namespace ab
{
	template < typename T >
	void InputUniqueVector ( std::vector < T > &v, int n )
	{
	/*** unos elemenata u parametar 'v' do velicine n, bez ponavljanja elemenata ***/
		T temp;
		while ( n != v.size() and n > 0 )
		{
		AGAIN: std::cin >> temp;
			for ( int i = 0; i < v.size (); i++ )
				if ( v.at ( i ) == temp )
					goto AGAIN;
			v.push_back ( temp );
		}
	}
	
	template < typename T >
	int numOfPF ( T n )
	{
	/*** broj prostih faktora parametra 'n' ***/
		if ( n < 2 )
			return 0;
			
		int pf { 0 };
		while ( n % 2 == 0 )
			pf++, ( n /= 2 );
		
		for ( int i = 3; i <= int ( std::sqrt ( n ) ); i += 2 )
			while ( n % i == 0 )
				pf++, ( n /= i );
		
		return ( n > 2 ) ? ++pf : pf;
	}
}

int main ( void )
{
	int n;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;
	
	std::vector < int > prvi;
	std::cout << "Unesite elemente prvog vektora: ";
	ab::InputUniqueVector ( prvi, n );
	
	std::vector < int > drugi;
	std::cout << "Unesite elemente drugog vektora: ";
	ab::InputUniqueVector ( drugi, n );
	
	std::vector < int > treci;
	std::cout << "Unesite elemente treceg vektora: ";
	ab::InputUniqueVector ( treci, n );

	try
	{
		SortirajPodrucjeVrijednosti ( prvi.begin (), prvi.end (), drugi.begin (), treci.begin (), 
			[] ( int p1, int p2 ) { return -2 * p1 + p2; },
			[] ( int p1, int p2 ) -> bool 
			{
				int npf1 { ab::numOfPF ( p1 ) }, npf2 { ab::numOfPF ( p2 ) }; 
				return ( npf1 == npf2 ) ? ( ( p1 > p2 ) ? true : false ) : ( ( npf1 > npf2 ) ? true : false );
			});
	}
	catch ( const std::exception &exc )
	{
		std::cout << "\nIzuzetak: " << exc.what ();
		return 0;
	}
	
	std::cout << "\nNakon sortiranja podrucja vrijednosti imamo sljedece trojke:\n";
	for ( int i = 0; i < n; i++ )
		std::cout << "f(" << prvi.at ( i ) << ", " << drugi.at ( i ) << ") = " << treci.at ( i ) << std::endl;
	
	return 0;
}