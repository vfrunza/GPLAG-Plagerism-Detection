#include <iostream>
#include <functional>
#include <algorithm>
#include <utility>
#include <vector>
#include <stdexcept>
#include <cmath>

void testException_order ( std::vector < std::pair < double, double > > &v )
{
/*** provjera razlicitosti sortiranih cvorova ***/
    std::sort ( v.begin (), v.end (), 
        [] ( std::pair < double, double > p1, std::pair < double, double > p2 ) 
            { return p1.first < p2.first; } 
    );
    for ( int i = 0; i < int ( v.size () - 1 ); i++ )
        if ( v.at ( i ).first == v.at ( i + 1 ).first )
            throw std::domain_error ( "Neispravni cvorovi" );
}

void testException_param ( double x_min, double x_max, double delta_x )
{
/*** provjera pravilnosti intervala i pomaka ***/
    if ( x_min > x_max or delta_x <= 0 )
        throw std::domain_error ( "Nekorektni parametri" );
}

std::function < double ( double ) > LinearnaInterpolacija ( std::vector < std::pair < double, double > > v )
{
/*** linearna interpolacija zadana nizom cvorova ***/
    testException_order ( v );
            
    return [ = ] ( double x ) -> double 
    {
        std::vector < std::pair < double, double > > vec = v; //**************** ovo je jako lose, naci bolje rjesenje
        
        if ( x < vec.at ( 0 ).first or x > vec.at ( vec.size () - 1 ).first )
            throw std::range_error ( "Argument izvan opsega" );
        
        std::vector < std::pair < double, double > >::iterator up // gornji najmanji cvor u odnosu na vrijednost aproximacije
            { std::upper_bound ( vec.begin (), vec.end (), x, [] ( double val, const std::pair < double, double > &p ) { return val <= p.first; } ) };
            
        std::vector < std::pair < double, double > >::iterator down { ( --up )++ }; // donji najveci cvor
        
        return down -> second + ( ( up -> second - down -> second  ) / ( up -> first - down -> first ) ) * ( x - down -> first );
    };
}

std::function < double ( double ) > LinearnaInterpolacija ( std::function < double ( double ) > func, double x_min, double x_max, double delta_x )
{
/*** linearna interpolacija zadana intervalom ***/
    std::vector < std::pair < double, double > > knot ( int ( ( x_max - x_min ) / delta_x ) );
    
    testException_param ( x_min, x_max, delta_x );
    
    int i { 0 };
    // kreiranje niza cvorova zadanih parametrima intervala i pomaka
    for ( std::pair < double, double > &x : knot )
        ( x.first = x_min + ( i++ ) * delta_x ), ( x.second = func ( x.first ) );
        
    return LinearnaInterpolacija ( knot );
}

enum State { OptJedan, OptDva }; // opcija izvrsavanja programa

void loop_input ( std::vector < std::pair < double, double > > knot, State state, 
    std::function < double ( double ) > func, double xmin = 0, double xmax = 0, double dx = 1 )
{
/*** aproximacija unosa na osnovu zadanih parametara ***/
    testException_order ( knot );
    testException_param ( xmin, xmax, dx );
    double x, point;
    while ( std::cout << "Unesite argument (ili \"kraj\" za kraj): " )
    {
        if ( ! ( std::cin >> x ) )
            break;
            
        try { point = ( state == OptJedan ) ? LinearnaInterpolacija ( knot ) ( x ) : LinearnaInterpolacija ( func, xmin, xmax, dx ) ( x ); }
        catch ( const std::exception &e ) { std::cout << e.what () << std::endl; continue; }
        
        ( state == OptJedan ) ?
            ( std::cout << "f(" << x << ") = " << point << std::endl ) :
            ( std::cout << "f(" << x << ") = " << func ( x ) << " fapprox(" << x << ") = " << point << std::endl );
    }
    
}

void approx ( void )
{ 
/*** izvrsavanje programa za niz cvorova ***/
    int vel;
    std::cout << "Unesite broj cvorova: ";
    std::cin >> vel;
    std::vector < std::pair < double, double > > knot ( vel, { 0, 0 } );
    
    std::cout << "Unesite cvorove kao parove x y: ";
    for ( std::pair < double, double > &p : knot )
        std::cin >> p.first >> p.second;
    
    loop_input ( knot, OptJedan, [] ( double ) -> double { return 0; } );
}

void approx ( std::function < double ( double ) > &&func )
{ 
/*** izvrsavanje programa za interval ***/
    double xmin, xmax, dx;
    std::cout << "Unesite krajeve intervala i korak: ";
    std::cin >> xmin >> xmax >> dx;

    loop_input ( std::vector < std::pair < double, double > > ( 0 ), OptDva, func, xmin, xmax, dx );
}

int main ( void )
{
    int opt;
    std::cout << "Odaberite opciju (1 - unos cvorova, 2 - aproksimacija): ";
    std::cin >> opt;

    try { ( opt == 1 ) ? approx () : approx ( [] ( double x ) -> double { return x * x + std::sin ( x ); } ); }
    catch ( const std::exception &exc ) { std::cout << exc.what (); }
    
    return 0;
}