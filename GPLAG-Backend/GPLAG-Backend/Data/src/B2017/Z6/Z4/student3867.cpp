#include <iostream>
#include <fstream>
#include <functional>
#include <stdexcept>

template < typename T >
class DatotecniKontejner
{
    std::fstream file;

    void test_ffail ( void ) const { if ( file.bad () ) throw std::logic_error ( "Problemi prilikom pristupa datoteci" ); }

    void test_fcursor ( int pos ) { if ( pos < 0 or pos >= DajBrojElemenata () ) throw std::range_error ( "Neispravna pozicija" ); }

public:
    DatotecniKontejner ( const std::string & );
    void DodajNoviElement ( const T & );
    int DajBrojElemenata ( void );
    T DajElement ( int );
    void IzmijeniElement ( int, const T & );
    
    void Sortiraj ( std::function < bool ( const T &, const T & ) > kriterij = std::less < T > () )
    {
        for ( int i = 1; i < DajBrojElemenata (); i++ )
        {
            T temp = DajElement ( i );
            int j = i - 1;
            while ( j >= 0 and kriterij ( temp, DajElement ( j ) ) )
            { 
                IzmijeniElement ( j + 1, DajElement ( j ) ); 
                j--; 
            }
                
            IzmijeniElement ( j + 1, temp );
        }
    }
};

template < typename T >
DatotecniKontejner < T >::DatotecniKontejner ( const std::string &ime_datoteke ) //: file ( ime_datoteke, std::fstream::out )
{
    file.open ( ime_datoteke, std::fstream::out | std::fstream::app );
    file.close ();
    file.open ( ime_datoteke, file.binary | file.ate | file.in | file.out );
    
    if ( !file.is_open () ) throw std::logic_error ( "Problemi prilikom otvaranja ili kreiranja datoteke" );
}

template < typename T >
inline void DatotecniKontejner < T >::DodajNoviElement ( const T &element )
{
    file.seekp ( 0, std::ios::end );
    file.write ( reinterpret_cast < char * > ( &( const_cast < T & > ( element ) ) ), sizeof element );
    test_ffail ();
    file.sync (); //file.flush ();
}

template < typename T >
inline int DatotecniKontejner < T >::DajBrojElemenata ( void ) 
{
    file.seekg ( 0, std::ios::end );
    int vel = static_cast < int > ( file.tellg () / sizeof ( T ) );
    return vel;
}

template < typename T >
inline T DatotecniKontejner < T >::DajElement ( int pozicija )
{
    test_fcursor ( pozicija );
    
    file.seekg ( pozicija * sizeof ( T ) );
    T el;
    file.read ( reinterpret_cast < char * > ( &el ), sizeof el );
    file.seekg ( 0, std::ios::end );
    
    test_ffail ();
    
    return el; 
}

template < typename T >
inline void DatotecniKontejner < T >::IzmijeniElement ( int pozicija, const T &element )
{
    test_fcursor ( pozicija );
    
    file.seekp ( pozicija * sizeof ( T ) );
    file.write ( reinterpret_cast < char * > ( &( const_cast < T & > ( element ) ) ), sizeof element );
    file.seekp ( 0, std::ios::end );
    
    test_ffail ();
}

int main ( void )
{
    DatotecniKontejner < double > cont ( "cont.bin" );
    
    std::cout << "Unesite velicinu kontejnera : ";
    int vel;
    std::cin >> vel;
    
    std::cout << "Unesite elemente kontejnera:\n";
    for ( int i = 0; i < vel; i++ )
    {
        std::cout << "[" << i + 1 << "] = "; 
        double in;
        std::cin >> in;
        cont.DodajNoviElement ( in );
    }

    std::cout << "Sadrzaj kontejnera:\n";
    for ( int i = 0; i < cont.DajBrojElemenata (); i++ )
        std::cout << cont.DajElement ( i ) << " ";
    std::cout << std::endl;
    
    cont.Sortiraj ();
    std::cout << "Sadrzaj kontejnera nakon sortiranja:\n";
    for ( int i = 0; i < cont.DajBrojElemenata (); i++ )
        std::cout << cont.DajElement ( i ) << " ";
    std::cout << std::endl;
    
    return 0;
}