/B2017/2018: Zadaća 3, Zadatak 2
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

typedef std::map<std::string, std::vector<std::string>> Knjiga;

typedef std::map<std::string, std::set<std::tuple<std::string,int,int>>> IndeksPojmova;

using std::cout;
using std::cin;
using std::endl;



bool jeste_slovo(const char c)
{
    return {(c>='a' && c<='z') || (c>='A' && c<='Z')};
}

bool jeste_cifra(const char c)
{
    return {c>='0' && c<='9'};
}

void PretvoriUMaloSlovo(char &znak)
{
    znak=std::tolower(znak);
}

bool iste_rijeci(std::string s1, std::string s2)
{
    std::for_each(s1.begin(),s1.end(),PretvoriUMaloSlovo);
    std::for_each(s2.begin(),s2.end(),PretvoriUMaloSlovo);
    return s1==s2;
}

std::string rijec_mala_slova(std::string s)
{
    std::for_each(s.begin(),s.end(),PretvoriUMaloSlovo);
    return s;
}

bool NijednoPojavljivanjeRijeciUTekstu(const std::string &rijec, const std::string &tekst)
{


    int i(0);

    while(i<tekst.length()) {

        while(i<tekst.length() && !jeste_slovo(tekst.at(i)) && !jeste_cifra(tekst.at(i)) ) i++;
        if(i+rijec.length()<=tekst.length() && std::tolower(tekst.at(i))==std::tolower(rijec.at(0))) {
            
            auto poc(&tekst.at(i));
            std::string podstring;;
            const char* iza_kraja;
            if(i+rijec.length()!=tekst.length()) {
                iza_kraja=&tekst.at(i+rijec.length());
                std::copy(poc,iza_kraja,std::back_inserter(podstring));
            }

            else {
                std::basic_string<char>::const_iterator it1(poc);
                std::basic_string<char>::const_iterator q(tekst.end());
                std::copy(it1,q,std::back_inserter(podstring));
            }
      
            if(iste_rijeci(rijec,podstring)) return false;



        }
        while( i<tekst.length() && ( jeste_slovo(tekst.at(i)) || jeste_cifra(tekst.at(i)) ) ) i++;
        //cout<<tekst.at(i-1)<<endl;
    }


    return true;
}


std::vector<int> VektorPolozajaRijeci(const std::string &rijec, const std::string &tekst)
{

    std::vector<int> v;
    int i(0);

    while(i<tekst.length()) {

        while(i<tekst.length() && !jeste_slovo(tekst.at(i)) && !jeste_cifra(tekst.at(i)) ) i++;

        if(i+rijec.length()<=tekst.length() && std::tolower(tekst.at(i))==std::tolower(rijec.at(0))) {
            //cout<<tekst.at(i)<<endl;
            auto poc(&tekst.at(i));
            std::string podstring;;
            const char* iza_kraja;
            if(i+rijec.length()!=tekst.length()) {
                iza_kraja=&tekst.at(i+rijec.length());
                std::copy(poc,iza_kraja,std::back_inserter(podstring));
            }

            else {
                std::basic_string<char>::const_iterator it1(poc);
                std::basic_string<char>::const_iterator q(tekst.end());
                std::copy(it1,q,std::back_inserter(podstring));
            }
            //cout<<rijec<<" "<<podstring<<endl;
            if(iste_rijeci(rijec,podstring)) v.push_back(i);


        }
        while( i<tekst.length() && ( jeste_slovo(tekst.at(i)) || jeste_cifra(tekst.at(i)) ) ) i++;

    }

    return v;
}



IndeksPojmova KreirajIndeksPojmova (const Knjiga &knjiga)
{

    IndeksPojmova indeks_pojmova;

    for(auto it=knjiga.begin(); it!=knjiga.end(); it++) {
        for(int i=0; i<it->second.size(); i++) {
            auto stranica(it->second.at(i)); //(i+1). stranica



            int j(0);
            while(j<stranica.length()) {

                while( j<stranica.length() && !jeste_slovo(stranica.at(j)) && !jeste_cifra(stranica.at(j)) ) j++;

                if(  j<stranica.length() && ( jeste_slovo(stranica.at(j)) || jeste_cifra(stranica.at(j)) )  ) {

                    const char* poc(&stranica.at(j));

                    int k(j);

                    while( k<stranica.length() && (jeste_slovo(stranica.at(k)) || jeste_cifra(stranica.at(k))) ) k++;
                    const char* iza_kraja;
                    std::string rijec;

                    if(k!=stranica.length()) {
                        iza_kraja=&stranica.at(k);
                        std::copy(poc,iza_kraja,std::back_inserter(rijec));
                    }

                    else {
                        std::basic_string<char>::const_iterator iza_kraja_it(stranica.end());
                        std::basic_string<char>::const_iterator it_poc(poc);
                        std::copy(it_poc,iza_kraja_it,std::back_inserter(rijec));
                    }


                    if(k!=stranica.length()) {

                        std::string ostatak_teksta;
                        std::basic_string<char>::const_iterator iza_kraja_2(iza_kraja);
                        std::basic_string<char>::const_iterator abc(stranica.end());
                        std::copy(iza_kraja_2,abc,std::back_inserter(ostatak_teksta));
                        
                        if( NijednoPojavljivanjeRijeciUTekstu(rijec,ostatak_teksta) ) {
                            auto v(VektorPolozajaRijeci(rijec,stranica));
                            std::string mala_rijec(rijec_mala_slova(rijec));

                            for(int n=0; n<v.size(); n++)
                                indeks_pojmova[mala_rijec].insert(std::make_tuple(it->first,i+1,v.at(n)));

                        }
                    } else {
                        auto v(VektorPolozajaRijeci(rijec,stranica));
                        std::string mala_rijec(rijec_mala_slova(rijec));
                        for(int n=0; n<v.size(); n++)
                            indeks_pojmova[mala_rijec].insert(std::make_tuple(it->first,i+1,v.at(n)));


                    }
                }

                while(j<stranica.length() && ( jeste_slovo(stranica.at(j)) || jeste_cifra(stranica.at(j)) ) ) j++;
            }
        }
    }

    return indeks_pojmova;

}

std::set<std::tuple<std::string,int,int>> PretraziIndeksPojmova(const std::string &rijec, const IndeksPojmova &indeks_pojmova)
{

    std::set<std::tuple<std::string,int,int>> skup_pozicija;
    std::string mala_rijec(rijec);
    std::for_each(mala_rijec.begin(),mala_rijec.end(),PretvoriUMaloSlovo);
    
    auto it(indeks_pojmova.find(mala_rijec));
    if(it==indeks_pojmova.end()) throw std::logic_error("Pojam nije nadjen");
    
    for(auto it=indeks_pojmova.begin(); it!=indeks_pojmova.end(); it++)
        if(it->first==mala_rijec) skup_pozicija=it->second;


    return skup_pozicija;

}

void IspisiIndeksPojmova(const IndeksPojmova &indeks_pojmova)
{

    for(auto it=indeks_pojmova.begin(); it!=indeks_pojmova.end(); it++) {
        cout<<it->first<<": ";
        for(auto it2=it->second.begin(); it2!=it->second.end(); it2++) {
            if(std::distance(it2,it->second.end())!=1)
                cout<<std::get<0>(*it2)<<"/"<<std::get<1>(*it2)<<"/"<<std::get<2>(*it2)<<", ";
            else cout<<std::get<0>(*it2)<<"/"<<std::get<1>(*it2)<<"/"<<std::get<2>(*it2);
        }
        cout<<endl;
    }
}


int main()
{
    
    Knjiga knjiga;
    
    cout<<"Unesite naziv poglavlja: ";
    std::string naziv_poglavlja;
    std::getline(cin,naziv_poglavlja);
    
    
    while(naziv_poglavlja!="."){
        
        int cnt(0);
        
        std::vector<std::string> vektor_stranica;
        cout<<"Unesite sadrzaj stranice "<<cnt+1<<": ";
        std::string sadrzaj_stranice;
        std::getline(cin, sadrzaj_stranice);
        
        while(sadrzaj_stranice!="."){
        vektor_stranica.push_back(sadrzaj_stranice);
        cnt++;
        cout<<"Unesite sadrzaj stranice "<<cnt+1<<": ";
        std::getline(cin, sadrzaj_stranice);
        
        }
        
        knjiga[naziv_poglavlja]=vektor_stranica;
        
       cout<<"Unesite naziv poglavlja: ";
       std::getline(cin,naziv_poglavlja);
    }
    
   

    auto indeks_pojmova(KreirajIndeksPojmova(knjiga));

    cout<<endl<<"Kreirani indeks pojmova:"<<endl;
    IspisiIndeksPojmova(indeks_pojmova);
    
    cout<<endl<<"Unesite rijec: ";
    std::string trazena_rijec;
    std::getline(cin,trazena_rijec);
    
    while(trazena_rijec!="."){

    try {
        auto skup_pozicija_rijeci(PretraziIndeksPojmova(trazena_rijec,indeks_pojmova));
        
        for(auto it=skup_pozicija_rijeci.begin();it!=skup_pozicija_rijeci.end();it++){
            
            if(std::distance(it,skup_pozicija_rijeci.end())!=1 )
            cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
            else cout<<std::get<0>(*it)<<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it);
            
        }
        cout<<endl;
    }
    catch(std::logic_error izuzetak) {
        cout<<"Unesena rijec nije nadjena!"<<endl;
    }
    
    cout<<"Unesite rijec: ";
    std::getline(cin,trazena_rijec);
    
    }
    
    return 0;
}
