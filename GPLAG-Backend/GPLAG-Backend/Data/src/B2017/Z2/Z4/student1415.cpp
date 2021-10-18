/B2018/2019: Zadaća 2, Zadatak 4
#include <iostream>
#include <cstring>
#include <new>
#include <algorithm>
#include <vector>

char **SortirajRecenice(char ** pok_na_pocetak, char **pok_iza_kraja)
{
   
    std::sort(pok_na_pocetak, pok_iza_kraja, [](char *recenica1, char *recenica2){
        if(std::strlen(recenica1)<std::strlen(recenica2)) return true;
        else if (std::strlen(recenica1)>std::strlen(recenica2)) return false;
        else {
            if(std::strcmp (recenica1, recenica2)==-1 || std::strcmp(recenica1, recenica2)==0) return true;
            else return false;
        }
    });
    return pok_na_pocetak;
}

/*char binarna_pretraga(char **pok_na_pocetak, char **pok_iza_kraja, std::string pretrazi){
    if((std::binary_search(pok_na_pocetak,pok_iza_kraja,pretrazi))==true) std::cout<<"Nalazi se.";
    else std::cout<<"Ne nalazi se";
    return **pok_na_pocetak;
}*/

int NadjiIndeks(std::vector<std::string>v, std::string pretrazi)
{
  /*  int pocetak=0;
    int kraj=v.size()-1;
    int sredina=0;
    while(pocetak<=kraj)
    {
        sredina=(pocetak+kraj)/2;
        if(v.at(sredina)==pretrazi) return sredina;
        else if(pretrazi.length()>v.at(sredina).length()) pocetak=sredina+1;
        else if(pretrazi.length()<v.at(sredina).length()) kraj=sredina-1;
    }
    return -1;*/
    for(int i=0; i<v.size(); i++)
    {
       // std::cout<<"|"<<v.at(i)<<"|"<<pretrazi<<"|"<<std::endl;
            
        if(v.at(i)==pretrazi) 
        {
            
            return i;
        }
    }
    throw("Trazena recenica se ne nalazi u nizu!");
}

int main ()
{
    
    int n=0;
    std::cout<<"Unesite broj recenica: ";
    std::cin>>n;
    //std::cin.clear();
    std::cin.ignore(1000,'\n');
    std::cout<<"Unesite recenice: ";
    try{
    char **niz=new char*[n]{};
    std::vector<std::string> v;
  
    for(int i=0; i<n; i++)
    {
        std::string s;
        int duzina=0;
        std::getline(std::cin,s);
       std::cin.clear();
       //std::cin.ignore(1000,'\n');
      
        duzina=s.length();
       v.push_back(s);
       try{
        (*(niz+i))=new char[duzina +1];
        for(int j=0; j<duzina; j++)
        {
            //niz.at(i).at(j)=s.at(i);
           *(*(niz+i)+j)=s.at(j);
          
        }
       *(*(niz+i)+s.size())='\0';
       }catch(...){
           for(int j=0; j<i+1; j++)
           {
               delete[] niz[j];
               delete [] niz;
               throw;
           }
       }
    
    }
    
  
  

    std::cout<<std::endl;
   
    std::sort(v.begin(), v.end(),[](std::string recenica1, std::string recenica2){
        if(recenica1.length()<recenica2.length()) return true;
       
        else if (recenica1.length()>recenica2.length()) return false;
        else {
            if(recenica1<recenica2) return true;
            else return false;
        }
    });
   
   
   /* std::cout<<"Sortirani:";
   
    for(int i=0; i<v.size(); i++)
    {
       std::cout<<v.at(i);
       std::cout<<" ";
      
    }
    */
    auto finalni=SortirajRecenice(niz, niz+n);
    std::cout<<"Recenice nakon sortiranja: ";
    std::cout<<std::endl;
   for(int i=0; i<n; i++)
   {
       std::cout<<*finalni;
       std::cout<<" ";
       finalni++;
       std::cout<<std::endl;
   }
   
   
 
   std::cout<<std::endl;
   std::cout<<"Unesite recenicu za pretragu: ";
   std::string pretrazi;
   std::getline(std::cin, pretrazi);
   //std::cin.clear();
  //std::cin.ignore(1000,'\n');
  
  /* for(int i=0; i<v.size(); i++)
    {
        std::cout<<"|"<<v.at(i)<<"|"<<pretrazi<<"|"<<std::endl;
        std::cout<<std::boolalpha<<(v.at(i)==pretrazi);
    }*/
   
       if(std::binary_search(v.begin(), v.end(),pretrazi)) {
          // std::cout<<"Usli smo u if.";
            std::cout<<"Recenica se nalazi na poziciji: "<<NadjiIndeks(v,pretrazi);
       }
       else {
          std::cout<<"Trazena recenica se ne nalazi u nizu!";
       }
       
      for(int i=0; i<n; i++)
   {
       delete [] finalni[i];
   }
   
    }catch(...){
        std::cout<<"Problemi sa memorijom.";
    }
  
   
    
	return 0;
}