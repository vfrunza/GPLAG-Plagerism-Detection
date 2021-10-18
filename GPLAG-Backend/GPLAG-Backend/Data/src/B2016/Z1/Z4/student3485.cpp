#include <iostream>
#include <vector>
#include <math.h>
#include <string>
 

std::string IzmijeniUPigLatin(std::string s,std::vector<std::string>v){
        std::string s1{},s2{},s3{};
        int i=0,r=0,t=0;
         int k=0,l=0,brojac1=0,brojac=0,q=0;

        if(v.size()==0)
        
        {i=0;
            while(i<s.length()-1){
              r=i;t=i;
              while(i<s.length()){
                  if(i==s.length()) break;
                  if(s[i]==' ' || i==s.length()) break;
                  i++;t++;
              }
               std::string s3{s[r]};
                s.insert(i,s3);
                  s.erase(r,1); 
                  s.insert(i,"ay");
                i++;i++;          
               
               if(i==s.length()) break;
               i++;
        }return s;
            
        }
        for(int e=0;e<=v.size();e++){
           if(e==v.size()) break;
            s2=v[e];brojac1=0;q=0;
            while(q<s2.length()){
                
                if(q==s2.length()) break;
                if(s2[q]>'z' || s2[q]<'A' || (s2[q]>'Z' && s2[q]<'a')) brojac1++;
                
                if(q<s2.length()) q++;
                if(brojac1!=0) throw "Izuzetak: Nekorektan izbor rijeci";
            }
           
        }
        for(int j=0;j<=v.size();j++){
            if(j==v.size()) break;
            s1=v[j];
            int i=0;
            while(i<s.length()){
          
            brojac=0;
            l=i;
            k=0;
            while(s[i]!=' '){
                if(s[i]!=s1[k]){
                    brojac++;
                }
                
                if(i<s.length()) i++;
                else break;
               
               if(k<s1.length()) k++;
                
            }
            
            if(brojac==0){
                std::string s2{s[l]};
                s.insert(i,s2);
                s.erase(l,1);
                s.insert(i,"ay");
            }
            if(i<s.length()) 
            i++;
            else break;
        } 
       
    }
    return s;
    
    
}

std::string ObrniFraze(std::string s,std::vector<std::string> v){
    std::string s1,s2;
    int q=0,brojac1=0;
    if(v.size()==0) {
        return s;
    }
    int brojac=0,k=0,l,t,n;
    char pomocna;
    for(int j=0;j<v.size();j++){
        s1=v[j];q=0;
        brojac1=0;
         while(q<s1.length()){
                
                if(q==s1.length()) break;
                if(s1[q]>'z' && s1[q]!=' ' || s1[q]<'A' && s1[q]!=' ' || (s1[q]>'Z' && s1[q]<'a' && s1[q]!=' ')) brojac1++;
                
                if(q<s1.length()) q++;
                if(brojac1!=0) throw "Izuzetak: Nekorektan izbor rijeci";
            }
        for(int i=0;i<=s.length();i++){
            if(i==s.length()) break;
            l=i;n=i;
            brojac=0;k=0;
                 while(k<s1.length()){
                    
                    if(s[n]!=s1[k]) brojac++;
                    if(n==s.length()) break;
                    if(k==s1.length()) break;
                    n++;k++;
                }
                if(brojac==0) i=n;
            
            if(brojac==0){
                t=i-1;
              for(int z=0;z<s1.length()/2;z++){
                  pomocna=s[l];
                  s[l]=s[t];
                  s[t]=pomocna;
                  t--;l++;
                                 
              }  
            }
    
    
            }
    }return s;
    
    
}




int main ()
{   //std::string s{"Danas je lijep i suncan dan"};
    //std::vector<std::string> v{"Danas","lijep","suncan"};
   
   std::string s,rijec;
    std::vector<std::string> v;
    std::cout<<"Unesite recenicu: ";
    std::getline(std::cin,s);
    std::cout<<"Unesite fraze: ";
    for(; ;){
        std::getline(std::cin,rijec);
        if(rijec.length()==0) break;	

        v.push_back(rijec);

    }
   
    try{
         
        std::string s3=IzmijeniUPigLatin(s,v);
        std::cout<<"Recenica nakon PigLatin transformacije: ";
        std::cout<<s3<<std::endl;
            
        
    }  
    catch(const char poruka[]){
        std::cout<<poruka<<std::endl;
    }
    try{
    std::string s4=ObrniFraze(s,v);
    std::cout<<"Recenica nakon obrtanja fraza: ";
        std::cout<<s4;
    }
    catch(const char poruka1[]){
        std::cout<<poruka1<<std::endl;
    }
    
	return 0;
}
    
