#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <stdexcept>

std::string ObrniFraze(std::string s,std::vector<std::string> v){
    int polozaj(0),c(0),broj(0),pozicija(0),razlika(0),razmak(0);
    char znak;
    std::string a,b;
    for(std::string i: v) {
        a=i;
        for(int f=0;f<a.length();f++)  {
            if((a[f]<'a' || a[f]>'z' ) && (a[f]<'A' || a[f]>'Z') && a[f]!=' ') {
                throw std::domain_error("Nekorektan izbor rijeci");
            }
        }
        razmak=0;
        polozaj=0;
      for(int k=0;k<s.length();k++) {
        while(polozaj<s.length() && polozaj+i.length()<=s.length()){
            pozicija=polozaj;
            broj=0;
            b=i;
            for(int h=0;h<b.length();h++) {
                if(b[h]==' ') {
                    razmak++;
                }
            }
            while(s[pozicija]!=' ' && pozicija<s.length()) {
                pozicija++;
                broj++;
            }
              broj=broj+razmak;
            if(broj==i.length()) {
        if(s.substr(polozaj,i.length())==i) {
            c=0;
            int j;
            for(j=polozaj;j<=polozaj+(i.length()-1)/2;j++) {
                 znak=s[j];
                s[j]=s[polozaj+i.length()-1-c];
                s[polozaj+i.length()-1-c]=znak;
                c++;
            }
           }
        else {
            while(s[polozaj]!=' ' && polozaj<s.length()) {
                polozaj++;
            }
        }
        polozaj++;
        }
        else {
       if(broj<i.length()) {
           while(s[polozaj]!=' ' && polozaj<s.length()) {
                polozaj++;
       }
        }
        else {
            razlika=pozicija-i.length();
           if(razlika<s.length() && razlika+i.length()<s.length() && s.substr(razlika,i.length())==i) {
               c=0;
               int j;
               for(j=razlika;j<=razlika+(i.length()-1)/2;j++) {
                 znak=s[j];
                s[j]=s[razlika+i.length()-1-c];
                s[razlika+i.length()-1-c]=znak;
                c++;
            }
           }            
        }
        polozaj=pozicija;
        }
        polozaj++;
        }
          polozaj=0;
}
}
    return s;
}

std::string IzmijeniUPigLatin(std::string s,std::vector<std::string> v) {
    int polozaj(0);
    char znak;
    std::string g;
    for(std::string d: v) {
        g=d;
         for(int t=0;t<g.length();t++)  {
            if((g[t]<'a' || g[t]>'z') && (g[t]<'A' || g[t]>'Z')) {
                throw std::domain_error("Nekorektan izbor rijeci");
            }
        }
        polozaj=0;
        for(int k=0;k<s.length();k+=d.length()) {
            while(polozaj<s.length() && polozaj+d.length()<=s.length()) {
                if(s.substr(polozaj,d.length())==d) {
                    znak=s[polozaj];
                    int j;
                    s.resize(s.length()+2);
                    int z;
                    for(z=s.length()-1;z>=polozaj+d.length();z--) {
                        s[z+2]=s[z];
                    }
                    for(j=polozaj;j<polozaj+d.length()-1;j++) {
                        s[j]=s[j+1];
                    }
                    s[j++]=znak;
                    s[j++]='a';
                    s[j++]='y';
                    s[j]=' ';
            }
            else {
                   while(s[polozaj]!=' ' && polozaj<s.length()) {
                       polozaj++;
                   }
            }
            polozaj++;
            }
                polozaj=0;
            
        }
    }
    return s;
}
int main ()
{
    std::string recenica,h,rezultat,povratna;
    std::vector<std::string> rijeci;
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin,recenica);
    std::cout<<"Unesite fraze: ";
    do {
        std::getline(std::cin,h);
        if(h.size()!=0) {
            rijeci.push_back(h);
        }
    }while(h.size()!=0);
    try {
    rezultat=IzmijeniUPigLatin(recenica,rijeci);
    std::cout<<"Recenica nakon PigLatin transformacije: ";
    std::cout<<rezultat;
    }
    catch(std::domain_error poruka) {
        std::cout<<"Izuzetak: "<<poruka.what()<<std::endl;
    }
    try {

    povratna=ObrniFraze(recenica,rijeci);
     std::cout<<std::endl<<"Recenica nakon obrtanja fraza: ";
     std::cout<<povratna<<std::endl;
    }
    catch(std::domain_error poruka) {
         std::cout<<"Izuzetak: "<<poruka.what()<<std::endl;        
    }
    
	return 0;
}