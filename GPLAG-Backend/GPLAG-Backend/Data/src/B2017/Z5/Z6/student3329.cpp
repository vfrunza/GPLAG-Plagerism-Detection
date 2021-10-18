#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <functional>
#include <iomanip>

class Berza
{
    std::vector < int > cijena;
    
    int min, max;

    void NegativeParam ( int x, int y ) const { if ( x < 0 or y < 0 ) throw std::range_error ( "Ilegalne granice cijene" ); }

public:
    Berza ( int min, int max ) : min { min }, max { max } { NegativeParam ( min, max ); }
    explicit Berza ( int max ) : min { 0 }, max { max } { NegativeParam ( min, max ); }
    
    void RegistrirajCijenu ( int nova_cijena )
    {
        if ( nova_cijena < min or nova_cijena > max )
            throw std::range_error ( "Ilegalna cijena" );
            
        cijena.push_back ( nova_cijena );
    }
    
    int DajBrojRegistriranihCijena ( void ) const { return cijena.size (); }
    
    void BrisiSve ( void ) { cijena.clear (); }
    
    int DajMinimalnuCijenu ( void ) const
    {
        if ( cijena.empty () )
            throw std::range_error ( "Nema registriranih cijena" );
        return *std::min_element ( cijena.begin (), cijena.end () );
    }
    
    int DajMaksimalnuCijenu ( void ) const
    {
        if ( cijena.empty () )
            throw std::range_error ( "Nema registriranih cijena" );
        return *std::max_element ( cijena.begin (), cijena.end () );
    }
    
    bool operator ! ( void ) const { return cijena.empty (); }
    
    int DajBrojCijenaVecihOd ( int x ) const
    {
        if ( cijena.empty () ) 
            throw std::range_error ( "Nema registriranih cijena" );
        
        return std::count_if ( cijena.begin (), cijena.end (), std::bind ( std::greater < int > (), std::placeholders::_1, x ) );
    }
    
    void Ispisi ( void ) const
    {
        std::vector < int > temp = cijena;
        std::sort ( temp.begin (), temp.end (), std::greater < int > () );
        
        std::cout.setf ( std::ios::fixed );
        for ( int x : temp )
        {
            float w = static_cast < float > ( x ) / 100.0;
            std::cout << std::setprecision ( 2 ) << w << std::endl;
        }
    }
    
    int operator [] ( int idx )
    {
        if ( idx < 1 or idx > cijena.size () )
            throw std::range_error ( "Neispravan indeks" );
        return cijena.at ( idx + 1 );
    }
    
    Berza &operator ++ ( void )
    {
        std::for_each ( cijena.begin (), cijena.end (), std::bind ( std::multiplies < int > (), std::placeholders::_1, 100 ) );
    
        for ( int x : cijena )
            if ( x < min or x > max )
             throw std::range_error ( "Prekoracen dozvoljeni opseg cijena" );
    }
    
    Berza operator ++ ( int ) 
    {
        Berza temp = *this;
        ++( *this );
        return temp;
    }
    
    Berza &operator -- ( void )
    {
        std::for_each ( cijena.begin (), cijena.end (), std::bind ( std::divides < int > (), std::placeholders::_1, 100 ) );
    
        for ( int x : cijena )
            if ( x < min or x > max )
             throw std::range_error ( "Prekoracen dozvoljeni opseg cijena" );
    }
    
    Berza operator -- ( int ) 
    {
        Berza temp = *this;
        --( *this );
        return temp;
    }
    
    Berza &operator - ( void )
    {
        int avg = min + max;
        Berza nova = *this;
        std::for_each ( nova.cijena.begin (), nova.cijena.end (), std::bind ( std::minus < int > (), avg, std::placeholders::_1 ) );
        return nova;
    }
};


int main ( void )
{
    return 0;
}