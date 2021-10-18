//B 2017/2018, Zadaća 1, Zadatak 4
#include <iostream>
#include <vector>
#include <string>

typedef std::string String;
typedef std::vector<String> Vektor;

//Funkcija koja izvrce frazu naopacke; zavisno od logicke vrijednosti koji je drugi parametar funkcija vraca ili pola ili citavu izvrnutu frazu 
String Naopako (String s, bool Polu)
{   
//Ako trazimo palindrom 
    if(!Polu)
    {
        String naop;
        naop.resize(s.length());
        int j(0);
        for(int i=s.length()-1; i>=0; i--)
        {
//Prvi clan povratnog stringa je zadnji clan polaznog itd.           
            naop.at(j++)=s.at(i);
        }
        return naop;
    }
//Ako trazimo polu-palindrom    
    else 
    {
        String naop;
        int j(0);
//Odsijecamo pola fraze i stavljamo u string      
        for(int i=0; i<=(s.length()-1)/2; i++)
        {
            naop.resize(j+1);
            naop.at(j++)=s.at(i);
        }
//Potrebno je izvrnuti tu polovinu fraze buduci da to nije prethodno uradjeno         
    return Naopako(naop,false);
    }
}
//Funkcija koja prima string i vektor stringova, a vraca string primljen kao prvi parametar, tako da za svaku frazu koja je njegov podstring napravi odgovarajuci palindrom unutar stringa
String NapraviPalindrom (String s, Vektor v)
{   
    for(int i=0; i<v.size(); i++)
    {   
        int vel(0), pocetak(0), mjera(0);
        for(int j=0; j<s.length(); j++)
        {   
            int n(0), m(j);
//Ako dodjemo do razamaka ili zareza, povecavamo indeks za jedan u slucaju da taj razmak ili zarez se ne pojavljuje na istom mjestu u frazi koja je potencijalni podstring, da bi presli na novu rijec u glavnom stringu         
            if(m<s.length() && (s.at(m)==' ' || s.at(m)==','))m++;
//Promjenljiva vel predstavlja broj elemenata fraze koji su uzastopno isti kao u glavnom stringu, te ih broji do prvog elementa koji nije isti
//Tu promjenljivu poslije racunamo tako da se ova petlja vrsi samo u slucaju da se velicina vraca na nulu tj. da trazena fraza nije podstring  
            while(vel==0)
            {
//Ako smo dosli do bilo kakve znamenke koje predstavlja kraj rijeci u stringu koja nije na isti nacin manifestovana unutar fraze ta fraza nije podstring             
                if(m<s.length() && (s.at(m)==' ' || s.at(m)==',') && s.at(m)!=v.at(i).at(n))break;
//Promjenljiva mjera predstavlja broj uzastopnih slova jedne rijeci glavnog stringa, uz to da ako se u frazi koja je potencijalni podstring pojavljuje razmak ili zarez na istom mjestu kao i u glavnom stringu onda uracunavamo i taj razmak/zarez                 
                mjera++;
//Ako su elementi glavnog stringa i fraze isti povecavamo odgovarajuce brojace koji sluze kao indeksi                
                if(m<s.length() && s.at(m)==v.at(i).at(n))
                {  
                    m++;
                    n++;
                }
//Ako indeksi i fraze i glavnog stringa dodju do svojih respektivnih granica prekidamo petlju               
                if(n==v.at(i).length() && m==s.length())break;
//Ako broj elemenata rijeci glavnog stringa premasuje duzinu fraze te fraza nije trazeni podstring                
                if(mjera>n)break;
//Da ne bi izasli van opsega u slucaju da samo jedan a ne oba brojaca dodju do svojih granica smanjujemo ih za jedan kada su na samoj granici duzine fraze/stringa                
                if(n>v.at(i).length()-1)n--;
                if(m>=s.length())m--;
            }
            n=0;
            m=j;
//Za svaki zajednicki element glavnog stringa i fraze povecavamo varijablu vel dok ne dodjemo do elementa koji se razlikuje ili do kraja i stringa i fraze u slucaju da su isti          
            while(s.at(m)==v.at(i).at(n))
            {  
                vel++;
//Prvi zajednicki element predstavlja prvo slovo palindroma u glavnom stringu                
                if(vel==1)pocetak=m;
                m++;
                n++;
                if(n==v.at(i).length() && m==s.length())break;
                if(n>v.at(i).length()-1)n--;
                if(m>=s.length())m--;
            }
//Ako je varijabla vel, koja predstavlja broj zajednickih uzastopnih elemenata fraze i stringa, razlicita od duzine fraze onda ta fraza nije podstring            
            if(vel!=v.at(i).length())vel=0;
//Ako je varijabla mjera, predstavlja broj uzastopnih slova jedne rijeci glavnog stringa, razlicita od duzine fraze onda ta fraza nije podstring            
            if(mjera!=vel)
            {
                vel=0;
                mjera=0;
            }
//U slucaju da se broj uzastopnih slova jedne rijeci glavnog stringa, broj zajednickih uzastopnih elemenata fraze i stringa i duzina fraze poklapaju podstring je pronadjen          
            else if(mjera==vel && vel==v.at(i).length())
            {
//U tom slucaju brojac koji predstavlja indeks koji prolazi kroz elemente fraze vracamo na nulu                
                n=0;
                break;
            }
        } 
//Ako je broj elemenata fraze koji su uzastopno isti kao u glavnom stringu jedan duzini fraze nasli smo podstring  
        if(vel==v.at(i).length())
        {
//Produzujemo string da bi mogli smjestiti palindrom            
            int duz(s.length()+vel);
            s.resize(duz);
//Da bi ubacili palindrom unutar glavnog stringa izdvajamo elemente od pocetka stringa do kraja rijeci ciji smo podstring pronasli, izvrcemo taj podstring i dodajemo ga u string, te na to dodamo ostatak stringa pocevsi od rijeci koja je bila iza potencijalnog palindroma            
            s=s.substr(0,pocetak+vel)+Naopako(v.at(i),false)+s.substr(pocetak+vel,duz-pocetak+vel); 
            s.resize(duz);
//U slucaju da imamo vise istih rijeci za koje fraza predstavlja podstring koje treba pretvoriti u palindrom, smanjujemo brojac za jedan tako da ostanemo na istoj frazi unutar vektora stringova          
            i--;
        } 
    }
    return s;
}
//Funkcija koja prima string i vektor stringova, a vraca string primljen kao prvi parametar, tako da za svaku frazu koja je njegov podstring napravi odgovarajuci polu-palindrom unutar stringa
String NapraviPoluPalindrom (String s, Vektor v)
{   
//Funkcija je identicna funkciji NapraviPalindrom sve do narednog komentara    
    for(int i=0; i<v.size(); i++)
    {   
        int vel(0), poc(0), mjera(0);
        for(int j=0; j<s.length(); j++)
        {   
            int n(0), m(j);
            if(m<s.length() && (s.at(m)==' ' || s.at(m)==','))m++;
            while(vel==0)
            {
                if(m<s.length() && (s.at(m)==' ' || s.at(m)==',') && s.at(m)!=v.at(i).at(n))break;
                mjera++;
                if(m<s.length() && s.at(m)==v.at(i).at(n))
                {  
                    m++;
                    n++;
                }
                if(n==v.at(i).length() && m==s.length())break;
                if(mjera>n)break;
                if(n>v.at(i).length()-1)n--;
                if(m>=s.length())m--;
            }
            n=0;
            m=j;
            while(s.at(m)==v.at(i).at(n))
            {  
                vel++;
                if(vel==1)poc=m;
                m++;
                n++;
                if(n==v.at(i).length() && m==s.length())break;
                if(n>v.at(i).length()-1)n--;
                if(m>=s.length())m--;
            }
            if(vel!=v.at(i).length())vel=0;
            if(mjera!=vel){
                vel=0;
                mjera=0;
            }
            else if(mjera==vel && vel==v.at(i).length())
            {
                n=0;
                break;
            }
        }
//Ako pravimo polu-palindrom nema potrebe za mijenjanjem velicine glavnog stringa buduci da nakon umetanja polupalindroma on zauzme prostor gdje je prethodno bio dio glavnog stringa koji je pretvoren u polu-palindrom         
        if(vel==v.at(i).length())
        {
//Da bi ubacili polu-palindrom unutar glavnog stringa izdvajamo elemente od pocetka stringa do polovine rijeci ciji smo podstring pronasli, polovicu podstringa izvrcemo i dodajemo u string, te na to dodamo ostatak stringa pocevsi od rijeci koja je bila iza potencijalnog polu-palindroma            
            s=s.substr(0,poc+vel/2)+Naopako(v.at(i), true)+s.substr(poc+vel,s.length()-poc+3*vel/2); 
            i--;
        } 
    }
    return s;
}

int main ()
{
    std::cout << "Unesite recenicu: ";
    String s, prazan;
    std::getline(std::cin, s);
    std::cout << "Unesite fraze: ";
    Vektor v;
    for(int i=0; i<=v.size(); i++)
    {   
        v.resize(i+1);
        std::getline(std::cin, v.at(i));
        if(v.at(i)==prazan){
            v.resize(i);
            break;
        }
    }
    std::cout << "Recenica nakon Palindrom transformacije: " << NapraviPalindrom(s, v) << std::endl;
    std::cout << "Recenica nakon PoluPalindrom transformacije: " << NapraviPoluPalindrom(s, v) << std::endl;
    return 0;
}