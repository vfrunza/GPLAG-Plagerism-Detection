#include <iostream>
#include <deque>
#include <vector>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
string NapraviPalindrom(string recenica,vector<string> fraze)
{
   
    
  /*  if(recenica.length()==0) {
        string s;
        return s;
    }
*/

     if(int(fraze.size())==0)
        return recenica;

    if(recenica.length()>0)
        for(int i=0; i<fraze.size(); i++) {
            string fraza(fraze.at(i));
            string palindrom;
            //pravljnje fraze-obrnutog redoslijeda slova
            for(int i=int(fraza.length())-1; i>=0; i--)
                palindrom+=fraza.at(i);
            //.
            int j(0);

            while(j<recenica.length()) {
                int k(0);
                while(recenica.at(j)==' ')j++;
                while(recenica.at(j)==fraza.at(k)) {
                    k++;
                    j++;
                   
                    if(k==int(fraza.length())) break;
                    if(j==int(recenica.length())) break;
                };
                //ako je nasao frazu...


                if( ((j==int(recenica.length())) || (!((recenica.at(j)>='A' && recenica.at(j)<='Z') || (recenica.at(j)>='a' && recenica.at(j)<='z')))) && (k!=0) && (k==fraza.length())) {

                    int pomoc(int(recenica.length())-1);

                    recenica.resize(recenica.length()+palindrom.length());
                    int kraj(int(recenica.length()-1));
                    //pomjeranje
                    while(pomoc>=j) {
                        recenica.at(kraj)=recenica.at(pomoc);
                        kraj--;
                        pomoc--;
                    }
                    int p(0);
                    int velicina(palindrom.length());
                    while(velicina!=0) {
                        recenica.at(j)=palindrom.at(p);
                        j++;
                        p++;
                        velicina--;
                    }
                }
                while(j<recenica.length() && recenica.at(j)!=' ') j++;
            }
        }
    
    return recenica;
}
string NapraviPoluPalindrom(string recenica,vector<string>fraze)
{
    if(int(fraze.size())==0) return recenica;
    else {
        for(int i=0; i<fraze.size(); i++) {
            string fraza(fraze.at(i));

            int j(0);
            while(j<recenica.length()) {
                int k(0);
                while(recenica.at(j)==' ')j++;
                //provjeriti kako ce funkcionisati
                int indeks(j);

                while(recenica.at(j)==fraza.at(k)) {

                    k++;
                    j++;
                    //if(j==int(recenica.length()))  k=int(fraza.length());
                    if(k==int(fraza.length())) break;
                    if(j==int(recenica.length())) break;
                };
                //ako je nasao frazu...

                //if((k!=0)&&(k==fraza.length()  && (j==int(recenica.length())) || (!((recenica.at(j)>='A' && recenica.at(j)<='Z') || (recenica.at(j)>='a'&& recenica.at(j)<='z')))))
                if( ((j==int(recenica.length())) || (!((recenica.at(j)>='A' && recenica.at(j)<='Z') || (recenica.at(j)>='a' && recenica.at(j)<='z')))) && (k!=0) && (k==fraza.length())) {
                    int pomoch(j-1);
                    while(pomoch>indeks) {
                        recenica.at(pomoch)=recenica.at(indeks);
                        pomoch--;
                        indeks++;
                    }

                }
                while(j<recenica.length() && recenica.at(j)!=' ') j++;
            }

        }
    }
    return recenica;
}

int main ()
{
    try{
    cout<<"Unesite recenicu: ";
    string recenica;
    getline(cin,recenica,'\n');
  
    
    cout<<"Unesite fraze: ";
    vector<string> fraze;
    do {
        string something;
        getline(cin,something,'\n');
        if(something.size()==0) break;
        fraze.push_back(something);
    } while(cin.peek()!='\n');
    
    if(recenica.length()==0) throw recenica;
   /*if(recenica.length()==0){
        cout<<"Recenica nakon Palindrom transformacije: ";
        string novi;
        cout<<novi<<endl;

        cout<<"Recenica nakon PoluPalindrom transformacije: ";
        
        cout<<novi;
        return 1;
    }
    else{ */
    if(fraze.size()>0) {
        cout<<"Recenica nakon Palindrom transformacije: ";
        string rezultat=NapraviPalindrom(recenica,fraze);
        cout<<rezultat<<endl;

        cout<<"Recenica nakon PoluPalindrom transformacije: ";
        string rezultat2=NapraviPoluPalindrom(recenica,fraze);
        cout<<rezultat2;
    } else {
        cout<<"Recenica nakon Palindrom transformacije: ";
        string rezultatp=NapraviPalindrom(recenica,fraze);
        cout<<rezultatp<<endl;
        cout<<"Recenica nakon PoluPalindrom transformacije: ";
        string rezultat2p=NapraviPoluPalindrom(recenica,fraze);
        cout<<rezultat2p;
    }
}catch(string s){
     cout<<"Recenica nakon Palindrom transformacije: ";
     cout<<endl;
       cout<<"Recenica nakon PoluPalindrom transformacije: ";
}

    return 0;
}