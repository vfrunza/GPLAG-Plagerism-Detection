/*B 2016/2017, Zadaća 1, Zadatak 4

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using std::cin;
using std::cout;
using std::endl;

std::string Zamijeni(std::string s)
{
    std::string novi;
    for(int i=s.length()-1; i>=0; i--) {
        novi.push_back(s[i]);
    }
    return novi;
}

bool JeLiSLovo(char slovo)
{
    bool d(false);
    if((slovo>='A' && slovo<='Z') || (slovo>='a' && slovo<='z')) d=true;
    if(d) return 1;
    else return 0;
}

std::string ObrniFraze(std::string s, std::vector<std::string>fraza)
{
    std::string s1(s);
    for(int i=0; i<fraza.size(); i++) {
        for(int j=0; j<s.length(); j++) {
            if(s.substr(j,fraza[i].length())==fraza[i]) {
                s1=Zamijeni(fraza[i]);
                for(int k=j; k<j+fraza[i].length(); k++) {
                    s[k]=s1[k-j];
                }
            }
        }
    }
    return s;
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string>fraza)
{

    for(int i=0; i<fraza.size(); i++) {
        std::string n(fraza[i]);
        for(int j=0; j<n.length(); j++) {
            if(!JeLiSLovo(n[j])) {
                throw std::domain_error("Nekorektan izbor rijeci");
            
            }
        }
    }

    std::vector<std::string>novi;
    std::string st;
    if(fraza.size()==0) {
        for(int i=0; i<s.length(); i++) {
            while(i<s.length() && JeLiSLovo(s[i])) {
                st.push_back(s[i]);
                i++;
            }
            if(st.size()!=0){
            novi.push_back(st);
            st.resize(0);
            }
        }

        fraza=novi;
    }

    for(int i=0; i<fraza.size(); i++) {
        for(int j=0; j<s.length(); j++) {
            if((j==0 || !JeLiSLovo(s[j-1])) && (j+fraza[i].length()-1)<s.length() && !JeLiSLovo(s[j+fraza[i].length()])) {
                if(s.substr(j,fraza[i].length())==fraza[i]) {
                    std::string n(fraza[i]);
                    char sl(n[0]);
                    s.insert(s.begin()+j+fraza[i].length(),sl);
                    s.erase(s.begin()+j);
                    s.insert(s.begin()+j+fraza[i].length(),'a');
                    s.insert(s.begin()+j+fraza[i].length()+1,'y');
                }

            }

        }

    }

    return s;

}
int main ()
{
    std::string recenica;
    cout<<"Unesite recenicu: ";
    std::getline(cin, recenica);
    std::vector<std::string>fraze;
    std::string el;
    cout<<"Unesite fraze: ";
    do {
        std::getline(cin, el);
        if(el.size()==0) break;
        fraze.push_back(el);
    } while(el.size()!=0);


    try {
        std::string s(IzmijeniUPigLatin(recenica,fraze));
        cout<<"Recenica nakon PigLatin transformacije: "<<s<<endl;
    } catch(std::domain_error izuzetak) {
        cout<<"Izuzetak: "<<izuzetak.what()<<endl;
    }
    cout<<"Recenica nakon obrtanja fraza: "<<ObrniFraze(recenica, fraze)<<endl;
    return 0;
}