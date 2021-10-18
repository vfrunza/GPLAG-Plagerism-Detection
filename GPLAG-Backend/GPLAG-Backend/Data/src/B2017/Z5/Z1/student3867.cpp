#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <cstring>
#include <map>
#include <utility>

class Student
{
    int index;
    std::string godina, ime, adresa, telefon;
    
    const char *god [ 11 ] { "1", "2", "3", "1/B", "2/B", "3/B", "1/M", "2/M", "1/D", "2/D", "3/D" };
    
    std::string GSNormal ( const std::string &godina ) const // uzima u obzir da je godina ispravnog formata
        { return ( godina.length () == 1 ) ? godina + "/B" : godina; }
    
    void ParamExc ( void ) const { throw std::domain_error ( "Neispravni parametri" ); }
    
    void EraseMultipleSpaces ( std::string &s ) // brisanje 'prefiksalnih', 'postfiksalnih' i duplih razmaka
    {
        for ( int i = 0; i < s.length (); i++ )
            if ( s.at ( i ) == ' ' and ( i == 0 or i == s.length () - 1 or s.at ( i + 1 ) == ' ' ) )
                s.erase ( s.begin () + i-- );
    }
    
public:
    Student ( int index, std::string godina, std::string ime, std::string adresa, std::string telefon )
        : index { index }, godina { godina }, ime { ime }, adresa { adresa }, telefon { telefon }
    {
        if ( index < 10000 or index > 99999 )
            ParamExc ();

        bool godina_correct { false };
        for ( int i = 0; i < 11; i++ )
            if ( god [ i ] == godina )
                { godina_correct = true; break; }
                
        if ( !godina_correct ) ParamExc ();
        
        EraseMultipleSpaces ( this -> ime );
        EraseMultipleSpaces ( this -> adresa );

        int i { 0 }; // validacija telefonskog broja
        while ( i != telefon.size () and std::isdigit ( telefon.at ( i ) ) ) i++;
        if ( i == telefon.size () or i == 0 or telefon.at ( i++ ) != '/' )
            ParamExc ();
        int j { i };
        while ( i != telefon.size () and std::isdigit ( telefon.at ( i ) ) ) i++;
        if ( i == telefon.size () or i == j or telefon.at ( i++ ) != '-' )
            ParamExc ();
        j = i;
        while ( i != telefon.size () and std::isdigit ( telefon.at ( i ) ) ) i++;
        if ( i != telefon.size () or i == j )
            ParamExc ();
    }
    
    ~Student ( void ) = default;
    
    int DajIndeks ( void ) const { return index; }
    std::string DajGodinuStudija ( void ) const { return GSNormal ( this -> godina ); }
    std::string DajImePrezime ( void ) const { return ime; }
    std::string DajAdresu ( void ) const { return adresa; }
    std::string DajTelefon ( void ) const { return telefon; }
    
    void Ispisi ( void ) const
    {
        std::cout << "Broj indeksa: " << DajIndeks () <<
            "\nGodina studija: " << DajGodinuStudija () << 
            "\nIme i prezime: " << DajImePrezime () <<
            "\nAdresa: " << DajAdresu () <<
            "\nTelefon: " << DajTelefon ();
    }
};

class Laptop
{
    int ev_broj;
    std::string naziv, karakteristike;
    Student *kod_koga_je;

public:
    Laptop ( int ev_broj, std::string naziv, std::string karakteristike )
        : ev_broj { ev_broj }, naziv { naziv }, karakteristike { karakteristike }, kod_koga_je { nullptr } 
        { if ( ev_broj <= 0 ) throw std::domain_error ( "Neispravni parametri" ); }
        
    ~Laptop ( void ) { delete kod_koga_je; }
    
    int DajEvidencijskiBroj ( void ) const { return ev_broj; }
    std::string DajNaziv ( void ) const { return naziv; }
    std::string DajKarakteristike ( void ) const { return karakteristike; }
    
    void Zaduzi ( Student &s )
    {
        if ( kod_koga_je != nullptr ) throw std::domain_error ( "Laptop vec zaduzen" );
        kod_koga_je = new Student ( s.DajIndeks (), s.DajGodinuStudija (), s.DajImePrezime (), s.DajAdresu (), s.DajTelefon () );
        
    }

    void Razduzi ( void ) { kod_koga_je = nullptr; }

    bool DaLiJeZaduzen ( void ) const { return kod_koga_je != nullptr; }
    
    Student &DajKodKogaJe ( void ) const 
        { if ( this -> DaLiJeZaduzen () ) throw std::domain_error ( "Laptop nije zaduzen" ); return *kod_koga_je; }
    
    Student *DajPokKodKogaJe ( void ) const { return kod_koga_je; }
    
    void Ispisi ( void ) const
    {
        std::cout << "Evidencijski broj: " << DajEvidencijskiBroj () <<
            "\nNaziv: " << DajNaziv () <<
            "\nKarakteristike: " << DajKarakteristike ();
    }
};

class Administracija
{
    std::map < int, Student * > studenti;
    std::map < int, Laptop * > laptopi;
    
public:
    Administracija ( void ) {}
    
    ~Administracija ( void )
    {
        for ( std::map < int, Student * >::iterator it = studenti.begin (); it != studenti.end (); it++ )
            delete it -> second;
        
        for ( std::map < int, Laptop * >::iterator it = laptopi.begin (); it != laptopi.end (); it++ )
            delete it -> second;
    }
    
    Administracija ( const Administracija &admin )
    {
        for ( const std::pair < const int, Student * > &p : admin.studenti )
            studenti [ p.first ] = new Student 
                ( p.second -> DajIndeks (), p.second -> DajGodinuStudija (), 
                p.second -> DajImePrezime (), p.second -> DajAdresu (), p.second -> DajTelefon () );
                
        for ( const std::pair < const int, Laptop * > &p : admin.laptopi )
            laptopi [ p.first ] = new Laptop 
                ( p.second -> DajEvidencijskiBroj (), p.second -> DajNaziv (), p.second -> DajKarakteristike () );
    }
    
    Administracija ( Administracija &&admin )
    { // swap iz biblioteke <map>
        studenti.swap ( admin.studenti );
        laptopi.swap ( admin.laptopi );
    }
    
    Administracija &operator = ( const Administracija &admin )
    {
        this -> ~Administracija ();
        
        for ( const std::pair < const int, Student * > &p : admin.studenti )
            studenti [ p.first ] = new Student 
                ( p.second -> DajIndeks (), p.second -> DajGodinuStudija (), 
                p.second -> DajImePrezime (), p.second -> DajAdresu (), p.second -> DajTelefon () );
                
        for ( const std::pair < const int, Laptop * > &p : admin.laptopi )
            laptopi [ p.first ] = new Laptop 
                ( p.second -> DajEvidencijskiBroj (), p.second -> DajNaziv (), p.second -> DajKarakteristike () );

        return *this;
    }
    
    Administracija &operator = ( Administracija &&admin )
    { // swap iz biblioteke <map>
        studenti.swap ( admin.studenti );
        laptopi.swap ( admin.laptopi );
        
        return *this;
    }
    
    void RegistrirajNovogStudenta ( int index, std::string godina, std::string ime, std::string adresa, std::string telefon )
    {
        if ( studenti.find ( index ) != studenti.end () )
            throw std::domain_error ( "Student s tim indeksom vec postoji" );
        studenti [ index ] = new Student ( index, godina, ime, adresa, telefon );
    }
    
    void RegistrirajNoviLaptop ( int ev_broj, std::string naziv, std::string karakteristike )
    {
        if ( laptopi.find ( ev_broj ) != laptopi.end () )
            throw std::domain_error ( "Laptop s tim evidencijskim brojem vec postoji" );
        laptopi [ ev_broj ] = new Laptop ( ev_broj, naziv, karakteristike );
    }
    
    Student &NadjiStudenta ( int index )
    {
        if ( studenti.find ( index ) == studenti.end () )
            throw std::domain_error ( "Student nije nadjen" );
        
        return *studenti.at ( index );
    }
    
    Student NadjiStudenta ( int index ) const
    {
        if ( studenti.find ( index ) == studenti.end () )
            throw std::domain_error ( "Student nije nadjen" );
        
        return *studenti.at ( index );
    }
    
    Laptop &NadjiLaptop ( int ev_broj )
    {
        if ( laptopi.find ( ev_broj ) == laptopi.end () )
            throw std::domain_error ( "Laptop nije nadjen" );
        
        return *laptopi.at ( ev_broj );
    }
    
    Laptop NadjiLaptop ( int ev_broj ) const
    {
        if ( laptopi.find ( ev_broj ) == laptopi.end () )
            throw std::domain_error ( "Laptop nije nadjen" );
        
        return *laptopi.at ( ev_broj );
    }
    
    void IzlistajStudente ( void ) const
    {
        int i { 0 };
        for ( const std::pair < const int, Student * > p : studenti )
        {
            p.second -> Ispisi ();
            std::cout << ( ( i++ % 2 ) ? "\n\n" : "\n" ); // razmak izmedju svakog drugog
        }
    }
    
    void IzlistajLaptope ( void ) const
    {
        int i { 0 };
        for ( const std::pair < const int, Laptop * > p : laptopi )
        {
            p.second -> Ispisi ();
            if ( p.second -> DaLiJeZaduzen () )
                std::cout << std::endl << "Zaduzio(la): " << p.second -> DajPokKodKogaJe () -> DajImePrezime () << " (" <<
                    p.second -> DajPokKodKogaJe () -> DajIndeks () << ")";
            std::cout << ( ( i++ % 2 ) ? "\n\n" : "\n" ); // razmak izmedju svakog drugog
        }
    }
    
    void ZaduziLaptop ( int index, int ev_broj )
    {
        if ( studenti.find ( index ) == studenti.end () )
            throw std::domain_error ( "Student nije nadjen" );
        if ( laptopi.find ( ev_broj ) == laptopi.end () )
            throw std::domain_error ( "Laptop nije nadjen" );
        
        for ( const std::pair < const int, Laptop * > p : laptopi )
            if ( p.second -> DajPokKodKogaJe () != nullptr )
                if ( p.second -> DajPokKodKogaJe () -> DajIndeks () == index )
                    throw std::domain_error ( "Student je vec zaduzio laptop" );
            
        if ( laptopi.at ( ev_broj ) -> DaLiJeZaduzen () )
            throw std::domain_error ( "Laptop vec zaduzen" );
        
        //laptopi.at ( ev_broj ) -> Zaduzi ( *studenti.at ( index ) );
        this -> NadjiLaptop ( ev_broj ).Zaduzi ( this -> NadjiStudenta ( index ) );
    }
    
    int NadjiSlobodniLaptop ( void ) const
    {
        for ( const std::pair < const int, Laptop * > p : laptopi )
            if ( !p.second -> DaLiJeZaduzen () )
                return p.first;
        
        throw std::domain_error ( "Nema slobodnih laptopa" );        
                
        return 0;
    }
    
    void RazduziLaptop ( int ev_broj )
    {
        if ( laptopi.find ( ev_broj ) == laptopi.end () )
            throw std::domain_error ( "Laptop nije nadjen" );
        
        if ( !laptopi.at ( ev_broj ) -> DaLiJeZaduzen () )
            throw std::domain_error ( "Laptop nije zaduzen" );
        
        laptopi.at ( ev_broj ) -> Razduzi ();
    }
    
    void PrikaziZaduzenja ( void ) const
    {
        int i { 0 };
        for ( const std::pair < const int, Laptop* > p : laptopi )
            if ( p.second -> DaLiJeZaduzen () )
            {
                std::cout << "Student " << p.second -> DajPokKodKogaJe () -> DajImePrezime () <<
                    " (" << p.second -> DajPokKodKogaJe () -> DajIndeks () << 
                    ") zaduzio/la laptop broj " << p.first << std::endl;
                i++;
            }
            
        if ( i == 0 )
            std::cout << "Nema zaduzenja" << std::endl;
    }
};

int main ( void )
{
    Administracija sluzba;
    
    while ( std::cout << "\nOdaberite jednu od sljedecih opcija\n"
        "[ 1 ] Registriraj nove studente\n[ 2 ] Registriraj nove laptope\n"
        "[ 3 ] Zaduzi laptop\n[ 4 ] Razduzi laptop\n[ 5 ] Izlistaj studente\n"
        "[ 6 ] Izlistaj laptope\n[ 7 ] Prikazi zaduzenja\n[ 8 ] Prekini izvrsavanje programa\n" )
    {
        int opcija { 0 };
        std::cout << ">>> ";
        std::cin >> opcija;
        
        if ( opcija == 8 )
            break;
            
        std::cout << std::endl;
        int evb, n, ind;
        evb = n = ind = 0;
        try
        {
            switch ( opcija )
            {
                case 1 :
                        std::cout << "Unesite broj studenata koje zelite registrovati : ";
                        std::cin >> n;
                        for ( int i = 1; i <= n; i++ )
                        {
                            std::cout << "\n" << i << ". student\nBroj indeksa : ";
                            std::cin >> ind;
                            
                            std::string god, ime, adr, tel;
                            std::cout << "Godina studija (1,2,3,1/B,2/B,3/B,1/M,2/M,1/D,2/D,3/D) : ";
                            std::cin >> god;
                            std::cout << "Ime i prezime : ";
                            
                            std::cin.clear (); std::cin.ignore ( 30, '\n' );
                            std::getline ( std::cin, ime );
                            std::cout << "Adresa stanovanja : ";
                            std::getline ( std::cin, adr );
                            std::cout << "Telefon (000/000-000) : ";
                            std::getline ( std::cin, tel );
                            
                            try { sluzba.RegistrirajNovogStudenta ( ind, god, ime, adr, tel ); }
                            catch ( const std::exception &e )
                            {
                                std::cout << "\nerror ( " << e.what () << " )\n";
                                std::cout << "[ next ] Registriraj sljedeceg studenta\n"
                                    "[ stop ] Prekini registraciju studenata\n>>> ";
                                std::string up;
                                std::cin >> up;
                                if ( up == "stop" )
                                    break;
                                i--;
                            }
                        }
                    break;
                case 2 :
                        std::cout << "Unesite broj laptopa koje zelite registrovati : ";
                        std::cin >> n;
                        for ( int i = 1; i <= n; i++ )
                        {
                            std::cout << "\n" << i << ". laptop\nEvidencijski broj : ";
                            std::cin >> evb;
                            
                            std::string naziv, spec;
                            std::cout << "Naziv : ";
                            std::cin >> naziv;
                            std::cout << "Karakteristike : ";
                            std::cin >> spec;
                            
                            std::cin.clear (); std::cin.ignore ( 30, '\n' );
                            
                            try { sluzba.RegistrirajNoviLaptop ( evb, naziv, spec ); }
                            catch ( const std::exception &e )
                            {
                                std::cout << "\nerror ( " << e.what () << " )\n";
                                std::cout << "[ next ] Registriraj sljedeci laptop\n"
                                    "[ stop ] Prekini registraciju laptopa\n>>> ";
                                std::string up;
                                std::cin >> up;
                                if ( up == "stop" )
                                    break;
                                i--;
                            }
                        }
                    break;
                case 3 :
                        std::cout << "Unesite indeks studenta koji zaduzuje laptop : ";
                        std::cin >> ind;
                        sluzba.ZaduziLaptop ( ind, sluzba.NadjiSlobodniLaptop () );
                    break;
                case 4 :
                        std::cout << "Unesite evidencijski broj laptopa : ";
                        std::cin >> evb;
                        sluzba.RazduziLaptop ( evb );
                    break;
                case 5 : sluzba.IzlistajStudente (); break;
                case 6 : sluzba.IzlistajLaptope (); break;
                case 7 : sluzba.PrikaziZaduzenja ();
            }
        }
        catch ( const std::exception &e )
            { std::cout << "\nerror ( " << e.what () << " )\n"; continue; }
    }
    
    std::cout << "\nIZVRSAVANJE PROGRAMA PREKINUTO\n";

	return 0;
}
