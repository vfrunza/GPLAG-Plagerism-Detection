#include <iostream>
#include <stdexcept>
#include <cstdio>
#include <new>
#include <iomanip>
#include <vector>

template < typename T >
struct Matrica
{
  int br_redova, br_kolona;
  T **elementi { nullptr };
};

template < typename T >
void UnistiMatricu ( Matrica < T > mat )
{
    if ( !mat.elementi )
        return;
    for ( int i = 0; i < mat.br_redova; i++ )
        delete [] mat.elementi [ i ];
    delete [] mat.elementi;
    mat.elementi = nullptr;
}

template < typename T >
Matrica < T > StvoriMatricu ( int br_redova, int br_kolona )
{
    Matrica < T > mat;
    mat.br_redova = br_redova; mat.br_kolona = br_kolona;
    mat.elementi = new T *[ br_redova ];
    
    for ( int i = 0; i < br_redova; i++ )
        mat.elementi [ i ] = nullptr;
    try
    {
        for ( int i = 0; i < br_redova; i++ )
            mat.elementi [ i ] = new T [ br_kolona ];
    }
    catch ( ... ) { UnistiMatricu ( mat ); throw; }
    
    for ( int i = 0; i < br_redova; i++ )
        for ( int j = 0; j < br_kolona; j++ )
            mat.elementi [ i ] [ j ] = 0;
    
    return mat;
}

template < typename T >
void UnesiMatricu ( char ime_matrice, Matrica < T > &mat )
{
    for ( int i = 0; i < mat.br_redova; i++ )
        for ( int j = 0; j < mat.br_kolona; j++ )
        {
            std::cout << ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
            std::cin >> mat.elementi [ i ] [ j ];
        }
}

template < typename T >
void UnesiValMatricu ( T val, Matrica < T > &mat )
{
    for ( int i = 0; i < mat.br_redova; i++ )
        for ( int j = 0; j < mat.br_kolona; j++ )
            mat.elementi [ i ] [ j ] = val;
}

template < typename T >
void UnesiJedinicnuMatricu ( Matrica < T > &a )
{
    for ( int i = 0; i < a.br_redova; i++ )
        a.elementi [ i ] [ i ] = 1;
}

template < typename T >
void IspisiMatricu ( const Matrica < T > &mat, int sirina_ispisa, int preciznost = 6, bool treba_brisati = true )
{
    std::cout.precision ( preciznost );
    for ( int i = 0; i < mat.br_redova; i++ )
    {
        for ( int j = 0; j < mat.br_kolona; j++ )
            std::cout << std::setw ( sirina_ispisa ) << mat.elementi [ i ] [ j ];
        std::cout << std::endl;
    }
    
    if ( treba_brisati )
        UnistiMatricu ( mat );
}

template < typename T >
Matrica < T > ZbirMatrica ( const Matrica < T > &m1, const Matrica < T > &m2 )
{
    if ( m1.br_redova != m2.br_redova or m1.br_kolona != m2.br_kolona )
        throw std::domain_error ( "Matrice nemaju jednake dimenzije!" );
    auto m3 ( StvoriMatricu < T > ( m1.br_redova, m1.br_kolona ) );
    
    for ( int i = 0; i < m1.br_redova; i++ )
        for ( int j = 0; j < m1.br_kolona; j++ )
            m3.elementi [ i ] [ j ] = m1.elementi [ i ] [ j ] + m2.elementi [ i ] [ j ];
        
    return m3;
}

template < typename T > 
Matrica < T > ProduktMatrica ( Matrica < T > a, Matrica < T > b )
{
/*** "dot-produkt" parametara 'a' i 'b' ***/
    Matrica < double > product;
    // provjera da li je jedna od matrica "skalarna" matrica
    if ( ( a.br_kolona == 1 and a.br_redova == 1 ) or ( b.br_kolona == 1 and b.br_redova == 1 ) )
        goto SCALAR; // ako jeste, ide na algoritam za mnozenje sa skalarom
    else if ( a.br_kolona != b.br_redova )
        throw std::domain_error ( "Matrice nisu saglasne za mnozenje" );
    // mnozenje saglasnih matrica    
    product = StvoriMatricu < double > ( a.br_redova, b.br_kolona );
    for ( int i = 0; i < a.br_redova; i++ )
        for ( int j = 0; j < b.br_kolona; j++ )
            for ( int k = 0; k < a.br_kolona; k++ )
                product.elementi [ i ] [ j ] += a.elementi [ i ] [ k ] * b.elementi [ k ] [ j ];
    goto END; // preskace algoritam za mnozenje sa skalarom

SCALAR: // algoritam za mnozenje sa skalarom
    product = StvoriMatricu < double > ( ( a.br_redova == 1 ? b.br_redova : a.br_redova ), ( a.br_kolona == 1 ? b.br_kolona : a.br_kolona ) );
    for ( int i = 0; i < product.br_redova; i++ )
        for ( int j = 0; j < product.br_kolona; j++ )
            product.elementi [ i ] [ j ] = ( a.br_redova == 1 ) ? 
                ( a.elementi [ 0 ] [ 0 ] * b.elementi [ i ] [ j ] ) : ( a.elementi [ i ] [ j ] * b.elementi [ 0 ] [ 0 ] );
END:    
    return product;
}

template < typename T, typename IT >
Matrica < T > MatricniPolinom ( Matrica < T > a, int step, IT it )
{
    if ( step < 0 )
        throw std::domain_error ( "Neispravan stepen polinoma" );
    if ( a.br_redova != a.br_kolona )
        throw std::domain_error ( "Matrica mora biti kvadratna " );
      
    Matrica < double > p_Mat { StvoriMatricu < double > ( a.br_redova, a.br_kolona ) }; // polinom matrica
    
    Matrica < double > temp_Mat;
    Matrica < double > dd_Mat;
    Matrica < double > pro_Mat;
    
    for ( int i = 0; i <= step; i++ )
    {
        Matrica < double > t_Mat { StvoriMatricu < double > ( 1, 1 ) }; // koeficijent matrica / skalar
        UnesiValMatricu ( T ( *it++ ), t_Mat );
        
        Matrica < double > pow_Mat { StvoriMatricu < double > ( a.br_redova, a.br_kolona ) }; // stepen matrica
        UnesiJedinicnuMatricu ( pow_Mat );
    
        for ( int j = 0; j < i; j++ )
        { // stepenovanje matrice 'stepen matrica'
            temp_Mat = pow_Mat;
            pow_Mat = ProduktMatrica ( pow_Mat, a );
            UnistiMatricu ( temp_Mat );
        }
        
        pro_Mat = p_Mat;
        p_Mat = ZbirMatrica ( p_Mat, dd_Mat = ProduktMatrica ( pow_Mat, t_Mat ) );
        UnistiMatricu ( pro_Mat );
        
        UnistiMatricu ( dd_Mat );
        UnistiMatricu ( pow_Mat );
        UnistiMatricu ( t_Mat );
        
    }
    
    return p_Mat;
}

int main ( void )
{
    int num;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    std::cin >> num;
    
    Matrica < double > mat { StvoriMatricu < double > ( num, num ) };
    
    std::cout << "Unesite elemente matrice A:\n";
    UnesiMatricu( 'A', mat );
    
    int step;
    std::cout << "Unesite red polinoma: ";
    std::cin >> step;
    
    std::vector < int > coeff;
    int i = 0;
    std::cout << "Unesite koeficijente polinoma: ";
    while ( i++ <= step and std::cin >> num )
        coeff.push_back ( num );
        
    
    IspisiMatricu ( MatricniPolinom ( mat, step, coeff.begin () ), 10, 5 );
    
    UnistiMatricu ( mat );
    
    return 0;
}