#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

std::string IzmijeniUPigLatin(std::string recenica,std::vector<std::string> rijec){
    for(auto i:rijec)
    {
        for(auto j:i)
        {
            if(toupper(j)<'A' || toupper(j)>'Z')
            {
                throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
                }//Izuzetak koji ne postoji u engl alfabetu i eventualne fraze
        }
    }
    if(rijec.size()==0){
    std::vector<std::string> privremena;
    int brojac3=1;
    privremena.resize(brojac3);
    for(int i(0);i<recenica.size();i++){
        if(toupper(recenica[i])>'Z' || toupper(recenica[i])<'A'){
            brojac3++;
            privremena.resize(brojac3);
            while(toupper(recenica[i])>'Z' || toupper(recenica[i])<'A'){
                i++;
            }
            i--;
        }
        else{
            privremena[brojac3-1].push_back(recenica[i]);
        }
    }
    for(int i(0);i<privremena.size();i++){
        int brojac=0;
        for(int k(0);k<recenica.size();k++){
            if(privremena[i][brojac]==recenica[k])brojac++;
                else {brojac=0;}
            if (  (brojac==(privremena[i].size()))  && ((toupper(recenica[k+1])>'Z') || (k==recenica.size()-1) || (toupper(recenica[k+1])<'A')) && ((toupper(recenica[k-brojac])<'A') || (k==privremena[i].size()-1) || (toupper(recenica[k-brojac])>'Z' ))    ){
                std::string umetni="ay";
                for(int j(0);j<privremena[i].size();j++){
                    char privremeni;
                    privremeni=recenica[k-j];
                    recenica[k-j]=recenica[k-privremena[i].size()+1];
                    recenica[k-privremena[i].size()+1]=privremeni;
                    if(j==(privremena[i].size()-1))recenica.insert(k+1,umetni);
                }
            }
        }
    }
    }
    else if(rijec.size()!=0){
    for(int i(0);i<rijec.size();i++){
        int brojac=0;
        int brojac1=0;
        for(int k(0);k<recenica.size();k++){
                if(toupper(recenica[k])>'Z' || toupper(recenica[k])<'A')brojac1=0;
                else brojac1++;
            if(rijec[i][brojac]==recenica[k])brojac++;
                else {brojac=0;}
            if((brojac==(rijec[i].size()))  && (brojac==brojac1) && ( (toupper(recenica[k+1])>'Z') || (k==recenica.size()-1) || (toupper(recenica[k+1])<'A')) && ((toupper(recenica[k-brojac])<'A') || (k==rijec[i].size()-1) || (toupper(recenica[k-brojac])>'Z' ))  ){
                std::string umetni="ay";
                for(int j(0);j<rijec[i].size();j++){
                    char privremeni;
                    privremeni=recenica[k-j];
                    recenica[k-j]=recenica[k-rijec[i].size()+1];
                    recenica[k-rijec[i].size()+1]=privremeni;
                    if(j==(rijec[i].size()-1))recenica.insert(k+1,umetni);
                }
            }
        }
    }
    }
    return recenica;
}

std::string ObrniFraze(std::string recenica,std::vector<std::string> rijec){
    for(int i(0);i<rijec.size();i++){
        int brojac=0;
        for(int k(0);k<recenica.size();k++){
            if(rijec[i][brojac]==recenica[k])brojac++;
                else {brojac=0;}
            if(brojac==(rijec[i].size())){
                for(int j(0);j<rijec[i].size();j++){
                    recenica[k-j]=rijec[i][j];
                }
            }
        }
    }
return recenica;
}

int main()
{
   std::string recenica,recenica2,recenica1;
    std::vector<std::string> rijec;
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin,recenica);
    std::cout<<"Unesite fraze: ";
    while(2){
    std::string s;
    std::getline(std::cin,s);
    rijec.push_back(s);
    if(std::cin.peek()=='\n'&& std::cin.peek()=='\n'){
            if(rijec[0].size()==0)rijec.resize(0);
            break;
    }
    }
    try{
        recenica2=IzmijeniUPigLatin(recenica,rijec);
        std::cout<<"Recenica nakon PigLatin transformacije: "<<recenica2;
        }
    catch(std::domain_error greska){
            std::cout <<greska.what();
        }
    recenica1=ObrniFraze(recenica,rijec);
    std::cout<<std::endl<<"Recenica nakon obrtanja fraza: "<<recenica1;
return 0;
}
