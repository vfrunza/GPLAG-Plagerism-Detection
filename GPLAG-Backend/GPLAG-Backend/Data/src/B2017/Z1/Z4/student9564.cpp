#include <iostream>
#include <string>
#include <vector>

bool JelMaloIlNije(char slovo)
{
    if((slovo>='A' && slovo <='Z')|| (slovo>='a' && slovo <='z' )) return true;
    return false;
}
/*
std::string NapraviPalindrom (std::string recenica, std::vector<std::string> vektor)
{
    //vektor sadrzi popis rijeci/fraza koje moramo transformisat

    std::string sastavljenarijec;
    std::string obrnuta;

    for(int i=0 ; i<vektor.size() ; i++) {
        for(int j=0 ; j<recenica.size()- vektor.at(i).size() +1 ; j++) {
            if(j>0 && JelMaloIlNije(recenica.at(j-1))) continue;
            if(j< recenica.size()-vektor.at(i).size() && JelMaloIlNije(recenica.at(j+vektor.at(i).size()))) continue;

            if(recenica.substr(j,vektor.at(i).size())==vektor.at(i)) {
                obrnuta.clear();

                for(int k=vektor.at(i).size()-1 ; k>=0 ; k--) {
                    obrnuta+=vektor.at(i).at(k);
                }
                recenica.insert(j+vektor.at(i).size(),obrnuta);

            }

        }


    }

    return recenica;
}
*/
std::string NapraviPalindrom (std::string recenica, std::vector<std::string> vektor){
    
        if(recenica.length()==0 || recenica == " ") return "";
        if(vektor.size()==0) return recenica;

    for(int i(0); i<vektor.size(); i++){
        for(int j(0); j<recenica.length()-vektor.at(i).size()+1; j++){
            if(vektor.at(i).size()!= 0 && recenica.at(j)==vektor.at(i).at(0)){
                int k(1), l(1);
                while(j+l<recenica.size() && k<vektor.at(i).size() && recenica.at(j+l)==vektor.at(i).at(k)){
                    l++; k++;
                }
                bool a (false), b(false);
                if(j+k==recenica.size()){
                    a=true;
                }
                else if(!JelMaloIlNije(recenica.at(j+k))) a=true;
                if(j==0) b=true;
                else if(!JelMaloIlNije(recenica.at(j-1))) b=true;
                if(k==vektor.at(i).size() && a==true && b==true){
                    j+=k;
                    for(int s(0); s<vektor.at(i).size();s++){
                        recenica.insert(recenica.begin()+j+s, vektor.at(i).at(vektor.at(i).size()-1-s));
                    }
                    
                }
                
            }
        }
    }
    
    return recenica;
}


std::string NapraviPoluPalindrom (std::string recenica, std::vector<std::string> vektor)
{
    //vektor sadrzi popis rijeci/fraza koje moramo transformisat

   /* std::string sastavljenarijec;
    std::string obrnuta;
    if(recenica.length()==0 || recenica==" ") return recenica;
    for(int i=0 ; i<vektor.size() ; i++) {
        for(int j=0 ; j<recenica.size()- vektor.at(i).size() +1 ; j++) {
            if(j>0 && JelMaloIlNije(recenica.at(j-1))) continue;
            if(j< recenica.size()-vektor.at(i).size() && JelMaloIlNije(recenica.at(j+vektor.at(i).size()))) continue;

            if(recenica.substr(j,vektor.at(i).size())==vektor.at(i)) {
                obrnuta.clear();

                for(int k=vektor.at(i).size()/2 ; k>=0 ; k--) {
                    obrnuta+=vektor.at(i).at(k);
                }

                if(vektor.at(i).size()%2!=0) {
                    recenica.erase(j+vektor.at(i).size()/2 , vektor.at(i).size()/2 +1 );
                    recenica.insert(j+vektor.at(i).size()/2,obrnuta);

                } else {
                    recenica.erase(j+vektor.at(i).size()/2, vektor.at(i).size()/2 ); //OVO SREDITI NECE NESTOS

                    recenica.insert(j+vektor.at(i).size()/2  ,obrnuta);
                }


            }

        }


    }*/
    
    if(recenica.length()==0 || recenica==" ") return recenica;
        if(vektor.size()==0) return recenica;

    for(int i(0); i<vektor.size(); i++){
        for(int j(0); j<recenica.size()-vektor.at(i).size()+1; j++){
            if(vektor.at(i).size()!= 0 && recenica.at(j)==vektor.at(i).at(0)){
                int k(1), l(1);
                while(j+l<recenica.size() && k<vektor.at(i).size() && recenica.at(j+l)==vektor.at(i).at(k)){
                    l++; k++;
                }
                bool a (false), b(false);
                if(j+k==recenica.size()){
                    a=true;
                }
                else if(!JelMaloIlNije(recenica.at(j+k))) a=true;
                if(j==0) b=true;
                else if(!JelMaloIlNije(recenica.at(j-1))) b=true;
                if(k==vektor.at(i).size() && a==true && b==true){
                    for(int s(0); s<vektor.at(i).size()/2;s++){
                        recenica.at(j+k-1-s)=vektor.at(i).at(s);
                    }
                    
                }
                
            }
        }
    }


    return recenica;
}




int main ()
{
    std::string s;

    std::vector<std::string> fraza;
    std::cout << "Unesite recenicu: ";
    std::getline(std::cin, s);
    // std::cin>>std::ws;
    std::string zaunosa;
    std::string rijecuizradi;
    std::cout << "Unesite fraze: ";
    while (true) {
        std::getline (std:: cin, zaunosa);
        if (zaunosa.size()==0) break;
        fraza.push_back(zaunosa);

    }

    std::cout << "Recenica nakon Palindrom transformacije: ";
    std::string modifikacijapalindrom(NapraviPalindrom(s,fraza));
    std::cout << modifikacijapalindrom;
    std::cout << std::endl;
    std::cout << "Recenica nakon PoluPalindrom transformacije: ";
    std::string modifikacijapalindrom_2(NapraviPoluPalindrom(s,fraza));
    std::cout << modifikacijapalindrom_2;



    return 0;
}