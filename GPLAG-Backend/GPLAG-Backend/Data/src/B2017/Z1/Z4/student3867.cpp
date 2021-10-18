#include <iostream>
#include <string>
#include <vector>

enum Napravi { palindrom, polupalindrom };

namespace ab
{
    std::string reverse ( std::string s )
    {
    /*** vraca parametar 's' kojem se elementi zamjenjuju na istim udaljenostima od njihovih najblizih krajeva tog stringa ***/
        int j = s.length () - 1;
        for ( int i = 0; i < j; i++, j-- )
        {
            s.at ( i ) ^= s.at ( j );
            s.at ( j ) ^= s.at ( i );
            s.at ( i ) ^= s.at ( j );
        }
        
        return s;
    }
    
    std::vector < std::string > sort ( std::vector < std::string > v )
    {
    /*** vraca parametar 'v' koji je sortiran od najduzih do najkracih stringova iz parametra 'v' ***/
        std::string temp;
        int pos;
        for ( int i = 1; i < v.size (); i++ )
        {
            pos = i + 1;
            while ( --pos > 0 and v.at ( pos - 1 ).length () < v.at ( pos ).length () )
            {   
                temp = v.at ( pos );
                v.at ( pos ) = v.at ( pos - 1 );
                v.at ( pos - 1 ) = temp;
            }
        }
        
        return v;
    }
    
    /*** vraca 'true' ako je parametar 'c' slovo ***/
    bool isalpha ( char c ) { return ( ( c >= 'a' and c <= 'z') or ( c >= 'A' and c <= 'Z' ) ) ? true : false; }
    
    bool isPhrase ( std::string s, int i, int len )
    {
    /*** vraca 'false' ako je podstring iz parametra 's', ogranicen parametriam 'i' i 'len', podstring neke fraze***/
        if ( i == 0 )
            return ( i + len == s.length () or !isalpha ( s.at ( i + len ) ) ) ? true : false;
        if ( i + len == s.length () )
            return ( !isalpha ( s.at ( i - 1 ) ) ) ? true : false;

        return ( !isalpha ( s.at ( i - 1 ) ) and !isalpha ( s.at ( i + len ) ) ) ? true : false;
    }
}

std::string Palindromize ( std::string s, std::vector < std::string > v, Napravi napravi )
{
/*** vraca palindromiziran ili polupalandromiziran parametar 's' u zavisnosti od parametra 'napravi' ***/
    for ( std::string fr : v )
        for ( int i = 0; i <= int ( s.length () ) - int ( fr.length () ); i++ )
            if ( s.substr ( i, fr.length () ) == fr and ab::isPhrase ( s, i, fr.length () ) )
            {
                if ( napravi == palindrom )
                    s.insert ( i + fr.length (), ab::reverse ( fr ) );
                else
                    s.erase ( i + fr.length () / 2, fr.length () / 2 + ( fr.length () % 2 == 0 ? 0 : 1 ) ), 
                    s.insert ( i + fr.length () / 2, ab::reverse ( fr ).substr ( fr.length () / 2, fr.length () / 2 + 1 ) );
            }
            
    return s;
}

/*** vraca parametar 's' u kojem su na kraj svih podstringova, koji su elementi parametra 'v', dodani isti podstringovi sa obrnutim redoslijedom ***/
std::string NapraviPalindrom ( std::string s, std::vector < std::string > v ) { return Palindromize ( s, ab::sort ( v ), palindrom ); }

/*** vraca parametar 's' u kojem su unutar svakog podstringa, koji su elementi parametra 'v', 
izmijenjena druga polovina sa prvom polovinom podstringa sa obrnutim redoslijedom ***/
std::string NapraviPoluPalindrom ( std::string s, std::vector < std::string > v ) { return Palindromize ( s, v, polupalindrom ); }

int main ( void )
{
	std::string rec;
	std::cout << "Unesite recenicu: ";
	std::getline ( std::cin, rec );
//unos fraza	
	std::vector < std::string > fraze;
	std::string temp;
	std::cout << "Unesite fraze: ";
	while ( std::getline ( std::cin, temp ), !temp.empty() )
	    fraze.push_back ( temp );
//palindromizacija	
	std::string pl = NapraviPalindrom ( rec, fraze );
	std::cout << "Recenica nakon Palindrom transformacije: " << pl << std::endl;
	
	std::string polupl = NapraviPoluPalindrom ( rec, fraze );
	std::cout << "Recenica nakon PoluPalindrom transformacije: " << polupl << std::endl;

	return 0;
}