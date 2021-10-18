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

std::string Obrni(std::string s){
    
    int i=0;
    int j=s.length()-1;
    while(i<j){
        char pom;
        pom=s[i];
        s[i]=s[j];
        s[j]=pom;
        i++;
        j--;
    }
    
    return s;
    
    
}
std::string ObrniFraze(std::string s, std::vector<std::string> v){
     
     std::vector<std::string> obrnuti;
     for(int i=0;i<v.size();i++){
         obrnuti.push_back(Obrni(v[i]));
     }
     for (int i=0;i<v.size();i++){
         for(int j(0);j<s.length();j++){
             int k=0;
             if(v[i][0]==s[j]){
                 int brojac=j;
                 bool dalije(true);
                 while(k<v[i].length()){
                     if(v[i][k]!=s[j]) {
                         dalije=false;
                         break;
                     }
                     j++;
                     k++;
                 }
                 if (dalije)
                 {
                     j=brojac;
                     for(int slovo=0;slovo<v[i].length();slovo++){
                         std::string pom=Obrni(v[i]);
                         s[j]=pom[slovo];
                         j++;
                     }
                 }
             }
         }
     }
    return s;
}
std::string ObrniPrvo(std::string s){
    s.insert(s.begin()+s.length(),s[0]);
    s.erase(s.begin());
    
    return s;
}

void fun(std::string &s, std::string obrnutarijec, int index){
    
    int br=index;
    for(int i=0;i<obrnutarijec.length();i++){
        s[index]=obrnutarijec[i];
        index++;
    }
    s.insert(s.begin()+obrnutarijec.length()+br,'a');
    
    s.insert(s.begin()+obrnutarijec.length()+1+br,'y');
}

std::string IzmijeniUPigLatin(std::string s, std::vector<std::string> v){

    
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].length();j++){
            if(v[i][j]=='.') continue;
            bool engl(false);
            for(char k=65;k<=122;k++){
                if(k==91) k=97;
                if(v[i][j]==k){
                    engl=true;
                    break;
                }
            }
            if (!engl) throw std::domain_error("Nekorektan izbor rijeci");
        }
    }
    
    if(v.size()==0) {
        for(int i=0;i<s.length();i++){
            if(i==0) {
                std::string pom;
                while(s[i]!=' ' && i!=s.length()){
                    pom.push_back(s[i]);
                    i++;
                }
                fun(s,ObrniPrvo(pom),0);
                i+=2;
            }
            else
            {
                int brojac=i;
                std::string pom;
                while(s[i]!=' ' && i!=s.length()){
                    pom.push_back(s[i]);
                    i++;
                }
                fun(s,ObrniPrvo(pom),brojac);
                
                i+=2;
            }
            
        }
    }
    else
    {
        for(int i=0;i<v.size();i++){
            for(int j=0;j<s.length();j++){
                if(v[i][0]==s[0] || (v[i][0]==s[j] && j>0 && s[j-1]==' ')){
                    int k=0;
                    bool dalije(true);
                    int brojac=j;
                    while(k<v[i].length()){
                        if(v[i][k]!=s[j]){
                            dalije=false;
                            break;
                            }
                            k++;
                            j++;
                    }
                        std::string s1;
                        if(dalije){
                            s1=v[i];
                            s1=ObrniPrvo(s1);
                            fun(s,s1,brojac);
                            j+=2;
                        }
                        
                }
            }
        }
    }
    return s;
    
}

int main ()
{
    
   std::vector<std::string>fraze;
    std::string s;
    try{
	
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin,s);
    
    std::cout<<"Unesite fraze: ";
    for(;;)
    {
        std::string rijec;
        std::getline(std::cin,rijec);
        if(rijec.length()!=0)
        {
            fraze.push_back(rijec);
        }
        else break;
    }
    std::string p;
    p=IzmijeniUPigLatin(s,fraze);
    std::cout<<"Recenica nakon PigLatin transformacije: ";
    std::cout<<p<<std::endl;
    
    std::string r;
    r=ObrniFraze(s,fraze);
    std::cout<<"Recenica nakon obrtanja fraza: ";
    std::cout<<r;
   
    
    }
 
    catch(std::domain_error izuzetak)
    {
        std::cout <<"Izuzetak: "<<izuzetak.what()<<std::endl;
        std::cout<<"Recenica nakon obrtanja fraza: ";
        std::cout<<ObrniFraze(s,fraze);
    }
    
	return 0;
}
