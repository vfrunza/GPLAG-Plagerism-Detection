#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <string>
#include <fstream>
#include <sstream>

template < typename T >
class Matrica
{
    int br_redova, br_kolona;
    T **elementi;
    char ime_matrice;
    
    static T **AlocirajMemoriju ( int br_redova, int br_kolona );
    static void DealocirajMemoriju ( T **elementi, int br_redova );
    void KopirajElemente ( T **elementi );
    
    void TestIndex ( int one, int two ) const
    {
        if ( one < 1 or one > br_redova or two < 1 or two > br_kolona )
            throw std::range_error ( "Neispravan indeks" );
    }
    
    std::string tostring ( T n ) const { return ( ( n - int ( n ) == 0 ) ? std::to_string ( int ( n ) ) : std::to_string ( int ( n ) ) ); }
    
public:
    Matrica ( int, int, char );
    Matrica ( int, int );
    Matrica ( const Matrica & );
    Matrica ( Matrica && );
    
    Matrica ( const std::string &, bool );
    
    ~Matrica ( void ) { DealocirajMemoriju ( elementi, br_redova ); }
    
    Matrica &operator = ( const Matrica & );
    Matrica &operator = ( Matrica && );
    
    template < typename X > friend Matrica < X > operator + ( const Matrica < X > &, const Matrica < X > & );
    template < typename X > friend Matrica < X > operator + ( const Matrica < X > &, int );
    template < typename X > friend Matrica < X > operator - ( const Matrica < X > &, const Matrica < X > & ); 
    template < typename X > friend Matrica < X > operator - ( const Matrica < X > &, int );

    Matrica < T > &operator += (const Matrica < T > &m ) { return *this = *this + m; }
    Matrica < T > &operator += ( int broj ) { return *this = *this + broj; }
    
    Matrica < T > &operator -= ( const Matrica < T > &m ) { return *this = *this - m; }
    Matrica < T > &operator -= ( int broj ) { return *this = *this - broj; }
    
    template < typename X > friend Matrica < X > operator * ( const Matrica < X > &, const Matrica < X > & );
    template < typename X > friend Matrica < X > operator * ( const Matrica < X > &, int );
    template < typename X > friend Matrica < X > operator * ( int, const Matrica < X > & );
    
    Matrica < T > &operator *= ( const Matrica < T > &m ) { return *this = *this * m; }
    Matrica < T > &operator *= ( int broj ) { return * this = *this * broj; }
    
    T *&operator [] ( int index ) { return elementi [ index ]; }
    T *operator [] ( int index ) const { return elementi [ index ]; }
    
    T &operator () ( int one, int two ) { TestIndex ( one, two ); return elementi [ one - 1 ] [ two - 1 ]; }
    T operator () ( int one, int two ) const { TestIndex ( one, two ); return elementi [ one - 1 ] [ two - 1 ]; }

    template < typename X > friend std::ostream &operator << ( std::ostream &, const Matrica < X > & );
    template < typename X > friend std::istream &operator >> ( std::istream &, Matrica < X > & );
    
    operator std::string() const
    {
        std::string s { "{" };
        for ( int i = 0; i < br_redova; i++ )
        {
            s += "{";
            for ( int j = 0; j < br_kolona; j++ )
                s += tostring ( elementi [ i ] [ j ] ) + std::string ( ( j != br_kolona - 1 ) ? "," : "" );
            s += "}" + std::string ( ( i != br_redova - 1 ) ? "," : "" );
        }
        return s += "}";
    }
    
    void SacuvajUTekstualnuDatoteku ( const std::string & );
    void SacuvajUBinarnuDatoteku ( const std::string & );
    void ObnoviIzTekstualneDatoteke ( const std::string & );
    void ObnoviIzBinarneDatoteke ( const std::string & );
};

template < typename T > 
T **Matrica < T >::AlocirajMemoriju ( int br_redova, int br_kolona )
{
    T **elementi ( new T *[ br_redova ] { nullptr } );
    try  { for ( int i = 0; i < br_redova; i++ ) elementi [ i ] = new T [ br_kolona ]; }
    catch ( ... ) { DealocirajMemoriju ( elementi, br_redova ); throw; }
    
    for ( int i = 0; i < br_redova; i++ )
        for ( int j = 0; j < br_kolona; j++ )
            elementi [ i ] [ j ] = 0;
    
    return elementi;
}

template < typename T >
void Matrica < T >::DealocirajMemoriju ( T **elementi, int br_redova )
{
    if ( elementi == nullptr ) return;
    for ( int i = 0; i < br_redova; i++ )
        delete [] elementi [ i ];
    delete [] elementi;
    elementi = nullptr;
}

template < typename T >
Matrica < T >::Matrica ( int br_redova, int br_kolona, char ime ) :
    br_redova ( br_redova ), br_kolona ( br_kolona ), ime_matrice ( ime ), elementi ( AlocirajMemoriju ( br_redova, br_kolona ) ) {}

template < typename T >
Matrica < T >::Matrica ( int br_redova, int br_kolona ) :
    br_redova ( br_redova ), br_kolona ( br_kolona ), elementi ( AlocirajMemoriju ( br_redova, br_kolona ) ) {}
    
template < typename T >
void Matrica < T >::KopirajElemente ( T **elementi )
{
    for ( int i = 0; i < br_redova; i++ )
        for ( int j = 0; j < br_kolona; j++ )
            Matrica::elementi [ i ] [ j ] = elementi [ i ] [ j ];
}

template < typename T >
Matrica < T >::Matrica ( const Matrica < T > &m ) :
    br_redova ( m.br_redova ), br_kolona ( m.br_kolona ), ime_matrice ( m.ime_matrice ), elementi ( AlocirajMemoriju ( m.br_redova, m.br_kolona ) ) 
{ KopirajElemente ( m.elementi ); }

template < typename T >
Matrica < T >::Matrica ( Matrica < T > &&m ) :
    br_redova ( m.br_redova ), br_kolona ( m.br_kolona ), ime_matrice ( m.ime_matrice ), elementi ( m.elementi ) 
{ m.elementi = nullptr; }

template < typename T >
Matrica < T > &Matrica < T >::operator = ( const Matrica < T > &m )
{
    if ( br_redova < m.br_redova or br_kolona < m.br_kolona )
    {
        T **novi_prostor ( AlocirajMemoriju ( m.br_redova, m.br_kolona ) );
        DealocirajMemoriju ( elementi, br_redova );
        elementi = novi_prostor;
    }
    else if ( br_redova > m.br_redova )
        for ( int i = m.br_redova; i < br_redova; i++ )
            delete elementi [ i ];
    
    br_redova = m.br_redova; br_kolona = m.br_kolona;
    ime_matrice = m.ime_matrice; KopirajElemente ( m.elementi );
    return *this;
}

template < typename T >
Matrica < T > &Matrica < T >::operator = ( Matrica < T > &&m )
{
    std::swap ( br_redova, m.br_redova ); std::swap ( br_kolona, m.br_kolona );
    std::swap ( ime_matrice, m.ime_matrice ); std::swap ( elementi, m.elementi );
    return *this;
}

template < typename X >
std::istream &operator >> ( std::istream &stream, Matrica < X > &m )
{
    for ( int i = 0; i < m.br_redova; i++ )
        for ( int j = 0; j < m.br_kolona; j++ )
        {
            std::cout << m.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            stream >> m.elementi [ i ] [ j ];
        }
    return stream;
}

template < typename X >
std::ostream &operator << ( std::ostream &stream, const Matrica < X > &m )
{
    long int width { stream.width () };
    for ( int i = 0; i < m.br_redova; i++ )
    {
        for ( int j = 0; j < m.br_kolona; j++ )
            stream << std::setw ( width ) << m.elementi [ i ] [ j ];
        std::cout << std::endl;
    }
    return stream;
}

template < typename T >
Matrica < T > operator + ( const Matrica < T > &m1, const Matrica < T > &m2 )
{
    if ( m1.br_redova != m2.br_redova or m1.br_kolona != m2.br_kolona )
        throw std::domain_error ( "Matrice nemaju jednake dimenzije!" );
    Matrica < T > m3 ( m1.br_redova, m1.br_kolona, 'C' );
    for ( int i = 0; i < m3.br_redova; i++ )
        for ( int j = 0; j < m3.br_kolona; j++ )
            m3.elementi [ i ] [ j ] = m1.elementi [ i ] [ j ] + m2.elementi [ i ] [ j ];
    return m3;
}

template < typename T >
Matrica < T > operator + ( const Matrica < T > &m, int broj )
{
    Matrica < T > m3 ( m.br_redova, m.br_kolona, 'C' );
    for ( int i = 0; i < m3.br_redova; i++ )
        for ( int j = 0; j < m3.br_kolona; j++ )
            m3.elementi [ i ] [ j ] = m.elementi [ i ] [ j ] + broj;
    return m3;
}

template < typename T >
Matrica < T > operator - ( const Matrica < T > &m1, const Matrica < T > &m2 )
{
    if ( m1.br_redova != m2.br_redova or m1.br_kolona != m2.br_kolona )
        throw std::domain_error ( "Matrice nemaju jednake dimenzije!" );
    Matrica < T > m3 ( m1.br_redova, m1.br_kolona, 'C' );
    for ( int i = 0; i < m3.br_redova; i++ )
        for ( int j = 0; j < m3.br_kolona; j++ )
            m3.elementi [ i ] [ j ] = m1.elementi [ i ] [ j ] - m2.elementi [ i ] [ j ];
    return m3;
}

template < typename T >
Matrica < T > operator - ( const Matrica < T > &m, int broj )
{
    Matrica < T > m3 ( m.br_redova, m.br_kolona, 'C' );
    for ( int i = 0; i < m3.br_redova; i++ )
        for ( int j = 0; j < m3.br_kolona; j++ )
            m3.elementi [ i ] [ j ] = m.elementi [ i ] [ j ] - broj;
    return m3;
}

template < typename T >
Matrica < T > operator * ( const Matrica < T > &m1, const Matrica < T > &m2 )
{
    if ( m1.br_redova != m2.br_kolona )
        throw std::domain_error ( "Matrice nisu saglasne za mnozenje" );
    Matrica < T > m3 ( m1.br_redova, m2.br_kolona, 'C' );
    for ( int i = 0; i < m1.br_redova; i++ )
        for ( int j = 0; j < m2.br_kolona; j++ )
            for ( int k = 0; k < m1.br_kolona; k++ )
                m3 [ i ] [ j ] += m1 [ i ] [ k ] * m2 [ k ] [ j ];
    return m3;
}

template < typename T >
Matrica < T > operator * ( const Matrica < T > &m, int broj )
{
    Matrica < T > temp ( m.br_redova, m.br_kolona, 'C' );
    for ( int i = 0; i < temp.br_redova; i++ )
        for ( int j = 0; j < temp.br_kolona; j++ )
            temp [ i ] [ j ] = m [ i ] [ j ] * broj;
    return temp;
}

template < typename T >
Matrica < T > operator * ( int broj, const Matrica < T > &m ) { return m * broj; }

template < typename T >
Matrica < T >::Matrica ( const std::string &ime_dat, bool tip ) : br_redova ( 1 ), br_kolona ( 1 ), elementi ( nullptr )
{
    elementi = AlocirajMemoriju ( br_redova, br_kolona );
    //std::fstream file ( ime_dat, std::ios::out | std::ios::in | static_cast < std::ios_base::openmode > ( int ( tip ) << 2 ) );
    try { ( tip ) ? this -> ObnoviIzBinarneDatoteke ( ime_dat ) : this -> ObnoviIzTekstualneDatoteke ( ime_dat ); }
    catch ( ... ) { this -> ~Matrica (); throw; }
}

template < typename T >
void Matrica < T >::SacuvajUTekstualnuDatoteku ( const std::string &ime_dat )
{
    std::ofstream file ( ime_dat );
    for ( int i = 0; i < br_redova; i++ )
    {
        for ( int j = 0; j < br_kolona; j++ )
        {
            file << elementi [ i ] [ j ];
            if ( j != br_kolona - 1 )
                file << ',';
        }
        
        if ( i != br_redova - 1 )
            file << std::endl;
    }
    
    if ( file.bad () ) 
        throw std::logic_error ( "Problemi sa upisom u datoteku" );
}

template < typename T >
void Matrica < T >::SacuvajUBinarnuDatoteku ( const std::string &ime_dat )
{
    std::ofstream file ( ime_dat, std::ios::binary );
    
    file.write ( reinterpret_cast < char * > ( &br_redova ), sizeof br_redova );
    file.write ( reinterpret_cast < char * > ( &br_kolona ), sizeof br_kolona );
    
    for ( int i = 0; i < br_redova; i++ )
        for ( int j = 0; j < br_kolona; j++ )
            file.write ( reinterpret_cast < char * > ( elementi [ i ] + j ), sizeof ( T ) );
            
    if ( file.bad () )
        throw std::logic_error ( "Problemi sa upisom u datoteku" );
}

template < typename T >
void Matrica < T >::ObnoviIzTekstualneDatoteke ( const std::string &ime_dat )
{
    std::ifstream file ( ime_dat, file.ate );
    if ( !file.is_open () )
        throw std::logic_error  ( "Trazena datoteka ne postoji" );
    
    int row { 0 }, col { 0 };
    
    std::string line;
    
    file.seekg ( 0 );
    int pre_col { 0 };
    while ( std::getline ( file, line ) )
    {
        col = 0;
        
        for ( char c : line )
            if ( !std::isdigit ( c ) and c != '.' and c != ',' and c != '-' and c != ' ' )
                throw std::logic_error ( "Datoteka sadrzi besmislene podatke" );

        std::string broj;
        std::istringstream iss ( line );
        while ( std::getline ( iss, broj, ',' ) ) col++;

        if ( pre_col == 0 )
            pre_col = col;
        else if ( pre_col != col )
            throw std::logic_error ( "Datoteka sadrzi besmislene podatke" );

        pre_col = col;
        row++;
    }
    
    this -> ~Matrica ();
    elementi = AlocirajMemoriju ( br_redova = row, br_kolona = col );
    
    file.close ();
    file.open ( ime_dat, file.ate );
    file.seekg ( 0 );
    
    for ( int i = 0; i < br_redova; i++ )
    {
        std::getline ( file, line );
        
        std::string broj;
        std::istringstream ss ( line );
        
        for ( int j = 0; j < br_kolona; j++ )
        {
            std::getline ( ss, broj, ',' );
            elementi [ i ] [ j ] = static_cast < T > ( std::stod ( broj ) );
        }
    }
    
    if ( file.bad () and !file.eof () )
        throw std::logic_error ( "Problemi pri citanju datoteke" );
}

template < typename T >
void Matrica < T >::ObnoviIzBinarneDatoteke ( const std::string &ime_dat )
{
    std::ifstream file ( ime_dat, std::ios::binary );
    if ( !file.is_open () )
        throw std::logic_error  ( "Trazena datoteka ne postoji" );
    
    int row, col;
    file.read ( reinterpret_cast < char * > ( &row ), sizeof ( row ) );
    file.read ( reinterpret_cast < char * > ( &col ), sizeof ( col ) );
    
    if ( file.bad () )
        throw std::logic_error ( "Problemi pri citanju datoteke" );
    
    this -> ~Matrica ();
    elementi = AlocirajMemoriju ( br_redova = row, br_kolona = col );
    
    for ( int i = 0; i < br_redova; i++ )
        for ( int j = 0; j < br_kolona; j++ )
            file.read ( reinterpret_cast < char * > ( elementi [ i ] + j ), sizeof ( T ) );
    
    if ( file.bad () and !file.eof () )
        throw std::logic_error ( "Problemi pri citanju datoteke" );
}

int main ( void )
{
    int m, n;
    std::cout << "Unesi broj redova i kolona:\n";
    std::cin >> m >> n;
    
    try
    {
        Matrica < double > matrica ( m, n, 'A' );
        std::cout << "Unesi matricu A:\n";
        std::cin >> matrica;
        
        matrica.SacuvajUTekstualnuDatoteku ( "txtmat.txt" );
        matrica.SacuvajUBinarnuDatoteku ( "binmat.bin" );
        
        Matrica < double > a ( "txtmat.txt", false ), b ( "binmat.bin", true );
        std::cout << std::endl << a << std::endl << b;
        
    }
    catch ( std::bad_alloc ) { std::cout << "Nema dovoljno memorije!\n"; }
    
    return 0;
}