#include <iostream>
#include <map>
#include<vector>
#include<algorithm>
#include<set>
 std::vector<std::string>v;
 std::vector<std::string >poglavlje;
template <typename iter>
void kopiraj(iter s,iter s1,iter p){
    while(s1!=s){
        *p=*s1;
        p++;s1++;
        
    }
}
typedef std::map<std::string, std::vector<std:: string>> Knjiga;
std::string rimski(int a){
   std:: string ans;
    std:: string M[] = {"","M","MM","MMM"};
    std:: string C[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
     std::string X[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    std:: string I[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    ans = M[a/1000]+C[(a%1000)/100]+X[(a%100)/10]+I[(a%10)];
    return ans;
}
void IzbaciDuplikate(std::vector<std::string> &s){
    for(int i=0;i<s.size();i++){
        for(int j=i+1;j<s.size();j++){
            if(s.at(i)==s.at(j)){
                for(int k=j+1;k<s.size();k++){
                    s.at(k-1)=s.at(k);
                }
                s.resize(s.size()-1);
                j--;
            }
        }
    }
}
std::set<std::tuple<std::string,int ,int>> PretraziIndeksPojmova(std::string s,std::map<std::string,std::set<std::tuple<std::string,int ,int>>> wow){
    for(int i=0;i<s.size();i++){
        if(s[i]<='Z')s[i]=s[i]+('a'-'A');
    }int i;
    for( i=0;i<v.size();i++){
        if(v[i]==s)break;
    }if(i==v.size())throw std::logic_error{"Unesena rijec nije nadjena!"};
    return wow[s];
}
void IspisiIndeksPojmova ( std::map<std::string,std::set<std::tuple<std::string,int ,int>>> wow){
   for(int i=0;i<v.size();i++){
        std::cout << v[i]<<": "  ;
        auto it(wow[v[i]].begin());
        for(int k=0;k<wow[v[i]].size();k++){
            if (k==wow[v[i]].size()-1)std::cout <<std::get<0>(*it) <<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<"";
            else std::cout <<std::get<0>(*it) <<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<", ";
            it++;
        }std::cout  << std::endl;
    }
}
void radi(std::string str,int j,std::map<std::string,std::set<std::tuple<std::string,int ,int>>>&wow,int i){
      auto s(str.begin());  
    auto s1(s);
   while (*s!='\0') {
    if(*s>='A'&&*s<='Z')*s+='a'-'A';
    s++;
   }s=s1;
  
   while(*s!='\0'){
       while(!((*s>='a'&&*s<='z')||(*s>='0'&&*s<='9'))){if(*s=='\0')break;s++;}
       s1=s;
       std::string temp;
       while((*s>='a'&&*s<='z')||(*s>='0'&&*s<='9')){if(*s=='\0')break;s++;}
       temp.resize(s-s1);
       kopiraj(s,s1,temp.begin());
       v.push_back(temp);
       while(!((*s>='a'&&*s<='z')||(*s>='0'&&*s<='9'))){if(*s=='\0')break;s++;}
       
   }
   IzbaciDuplikate(v);
   std::sort(v.begin(),v.end());
   

   std::vector<std::set<std::tuple<std::string,int ,int>>>v1(v.size());
   for(int k=0;k<v.size();k++){
       if(str.size()==1){{std::tuple<std::string,int ,int> tp(poglavlje[i-1],j+1,0);wow[str].insert(tp);};break;}
      for(int l=0;l<=str.size()-v[k].size();l++){
          bool provjera=true;
          int zapamti=l;
          
          for(int m=0;m<v[k].size();m++){
               
              if(l!=str.size()-v[k].size())
              if(m==v[k].size()-1&&((str[l+1]>='a'&&str[l+1]<='z')||(str[l+1]>='0'&&str[l+1]<='9'))){provjera=false;break;}
              if(l!=0)if((m==0)&&((str[l-1]>='a'&&str[l-1]<='z')||(str[l-1]>='0'&&str[l-1]<='9'))){provjera=false;break;}
              if(v[k][m]!=str[l]){provjera=false;break;}
              l++;
          }
    
          if(provjera==true){std::tuple<std::string,int ,int>t; t=std::make_tuple(poglavlje[i-1],j+1,zapamti);v1[k].insert(t);}
         else  l=zapamti;
          
      }
   }
    for(int k=0;k<v.size();k++){
        auto p(v1[k].begin());
        for(int s=0;s<v1[k].size();s++){
            wow[v[k]].insert(*p);
            p++;
        }
    
    }
  
}
void ispisi(std::set<std::tuple<std::string,int ,int>> t){
    auto it (t.begin());
        for(int k=0;k<t.size();k++){
            std::cout <<std::get<0>(*it) <<"/"<<std::get<1>(*it)<<"/"<<std::get<2>(*it)<<" ";
            it++;
        }std::cout  << std::endl;
    
}

std::map<std::string,std::set<std::tuple<std::string,int ,int>>> KreirajIndeksPojmova(Knjiga k){
    std::map<std::string,std::set<std::tuple<std::string,int ,int>>> wow;
    for(int i=1;i<=k.size();i++){
        for(int j=0;j<k[poglavlje[i-1]].size();j++){
             radi(k[poglavlje[i-1]][j],j,wow,i);
        }
}
return wow;
}


int main (){
    Knjiga k;
    std::string tocka{"."};
    while(1){
    std::cout << "Unesite naziv poglavlja: ";
    std::string pog;
    
    std::getline(std::cin,pog);
   
    if(pog==tocka)break;
    poglavlje.push_back(pog);
    std::vector<std::string>stranice;
    
    int i=0;
    while (true) {
        std::string temp;
        std::cout << "Unesite sadrzaj stranice "<<i+1<<": " ;
      
        std::getline(std::cin,temp);
       
        if(temp==tocka)break;
        stranice.push_back(temp);
        i++;
    }
    k[pog]=stranice;
    
    
}
std::cout << "\nKreirani indeks pojmova:" << std::endl;
auto wow(KreirajIndeksPojmova (k));
IspisiIndeksPojmova(wow);
while(1){
  
   try {
        std::cout << "Unesite rijec: "; 
   std::string a;
  
   std::getline(std::cin,a);
    if(a==tocka)break;
       auto t(PretraziIndeksPojmova(a,wow));ispisi(t);
   }
   catch (std::logic_error error) {
       std::cout << error.what() << std::endl;
   }
   
  
  
}

    
    
	return 0;
}
//{(“I”, 1, 0), (“I”, 1, 14), (“I”, 1, 18)}, {(“I”,1, 22), (“I”, 1, 35)},
//{(“I”, 1, 30)}, {(“I”, 1, 4), (“I”, 1, 26)} i {(“I”, 1, 8)}