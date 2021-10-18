//B 2016/2017, Zadaća 1, Zadatak 4


#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>


bool JeLiIzuzetak(std::vector<std::string> s)
{
    bool m(1);
    for(int i=0; i<s.size(); i++) {
        std::string x(s[i]);
        for(int j=0; j<x.length(); j++)
            if((x[j]<'A' || x[j]>'z' || (x[j]>'Z' && x[j]<'a')) && x[j]!=' ') {
                m=0;
                break;
            }
    }
    return m;
}
bool JeLiRijec(std::vector<std::string> s)
{
    bool m(1);
    for(int i=0; i<s.size(); i++) {
        std::string x(s[i]);
        for(int j=0; j<x.length(); j++)
            if(x[j]<'A' || x[j]>'z' || (x[j]>'Z' && x[j]<'a')) {
                m=0;
                break;
            }
    }
    return m;
}

std::string PretvoriRijec(std::string s)
{
    for(int i=0; i<s.length()-1; i++) {
        s[i]=s[i+1];
    }
    return s;

}

std::string ObrniFraze(std::string s, std::vector<std::string> v)
{
    
    std::string x;
    int pocetak;
    for(int i=0; i< v.size(); i++) {
        x=v[i];

        for(int j=0; j<s.length(); j++) {
            if(x[0]==s[j] ) {
                pocetak=j;
                int k;
                for(k=0; k<x.length(); k++) {
                    if(j>=s.length() || x[k]!=s[j] || (x[k]!=' ' && (x[k]<'A' || (x[k]>'Z' && x[k]<'a') || x[k]>'z')))
                        break;
                    j++;
                }
                if(k==x.length()) {
                    //Ako su jednaki da obrne frazu
                    int n=x.length()-1;
                    for(int m=pocetak; m<j; m++) {
                        s[m]=x[n];
                        n--;

                    }}
                    j=pocetak;
                
            }
        }
    }
    return s;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v)
{
    if(JeLiRijec(v)==0) throw std::domain_error("Nekorektan izbor rijeci");
    std::string x(s);
    int pocetak;
    if(v.size()==0) {
        int k;

        for(int i=0; i<s.length(); i++) {
            while(i<s.length() && (s[i]<'A' || s[i]>'z' || (s[i]>'Z' && s[i]<'a')))
                i++;
            pocetak=i;
            if(i!=s.length()){
            char prvo_slovo(s[i]);
            int duzina(0);
            while( i<s.length() && ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z'))) {
                duzina++;
                i++;
            }
            for(k=pocetak; k<pocetak+duzina-1; k++)
                s[k]=s[k+1];
            s[k]=prvo_slovo;
            i+=2;

            s=s.substr(0, k+1) + "ay" + s.substr(k+1, s.length()-k-1) ;

        }
        }
    }
    if(v.size()!=0) {
        for(int i=0; i< v.size(); i++) {
            x=v[i];
            for(int j=0; j<s.length(); j++) {
                if(s[j]==x[0] && (j-1<0 || s[j-1]<'A' || (s[j-1]>'Z' && s[j-1]<'a') || s[j-1]>'z')) {
                    pocetak=j;
                    int k;
                    for(k=0; k<x.length(); k++) {
                        if(x[k]!=s[j] || j>=s.length())
                            break;
                        j++;
                    }
                    if(k==x.length() && (j==s.length() || (s[j])<'A' || (s[j]>'Z' && s[j]<'a') || s[j]>'z')) {
                        char prvo_slovo(s[pocetak]);
                        for(int m=pocetak; m<j-1; m++) {
                            s[m]=s[m+1];
                        }
                        s[j-1]=prvo_slovo;
                        s=s.substr(0,j) + "ay" + s.substr(j, s.length()-j);

                    }
                }
            }
        }
    }
    return s;
}

int main ()
{
    
    std::string s;
    std::cout << "Unesite recenicu: ";
    std::getline(std::cin, s);
    std::vector<std::string> a;
    std::string x;
    std::cout << "Unesite fraze: ";
    while(1) {
        std::getline(std::cin, x);
        if(x.size()==0)
            break;
        if(x.size()!=0)
            a.push_back(x);
        if(char(std::cin.peek()=='\n'))
            break;
    }
    try {
        x=IzmijeniUPigLatin(s, a);
        std::cout << "Recenica nakon PigLatin transformacije: ";
        for(int i=0; i<x.length(); i++)
            std::cout << x[i];
            std::cout << std::endl;
    } catch(std::domain_error izuzetak) {
        std::cout << "Izuzetak: " << izuzetak.what() << std::endl;;
    }
    x=ObrniFraze(s, a);
    std::cout << "Recenica nakon obrtanja fraza: ";
    for(int i=0; i<x.length(); i++)
        std::cout << x[i];

    return 0;
}