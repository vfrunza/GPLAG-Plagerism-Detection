#include <iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<limits>
#include<string>
#include<stdexcept>


std::string cyka (std::string a,std::string b,std::vector<int> c,int uu){
    std::string bb;
    int k=0;
    for(int i=0;i<c.size();i++){
        for(int j=0;j<b.size();j++){
            if(uu==1&&c.size()-1==i)k=1;
             a.insert(a.begin()+c.at(i)+k+b.size()*i,b.at(j));
             // std::cout<<"       "<<b.at(j)<<std::endl;
        }
    }
    return a;
}

std::string NapraviPalindrom(std::string a, std::vector<std::string> b){
    if(a.size()==0)return 0;
    if(b.size()==0)return a;
    std::vector<int> indexi;
    int uu=0;
    int kks=1;
    int brojac=1;
    for(int i=0;i<b.size();i++){
        indexi.resize(0);
        for(int j=0;j<a.size();j++){
            if((a.at(j)==b.at(i).at(0))&&(j==0||a.at(j-1)==' ')){
                int provjera =j;
                int u=0;
                int k=1;
                 brojac=1;
                while(u<b.at(i).size()){
                 if(j==a.size())break;
                    if(a.at(j)!=b.at(i).at(u)){k=0;break;}
                    j++;
                    u++;
                    brojac++;
                
                }if(brojac<b.at(i).size())kks=1;
               else if(j==a.size()){uu=1;indexi.push_back(j-1);}
                else if(k==1&&(a.at(j)<'A'||a.at(j)>'z')){uu=0;indexi.push_back(j);}
            }
        }if(brojac<b.at(i).size()&&indexi.size()==0)continue;
        if(indexi.size()==0)continue;
       a=cyka(a,b.at(i),indexi, uu);
    }
   
    return a;
}
std::string funkcija(std::string a,std::string b,std::vector<int> c){
    if(b.size()%2==1){
        int kkk=b.size()/2;
        for(int i=0;i<c.size();i++){
            for(int j=0;j<b.size()/2;j++){
                a.at(c.at(i)-j)=a.at(c.at(i)-2*kkk+j);
            }
        }
    }
    if(b.size()%2==0){
        int kkk=b.size()/2;
        for(int i=0;i<c.size();i++){
            for(int j=0;j<b.size()/2;j++){
                a.at(c.at(i)-j)=a.at(c.at(i)-2*kkk+j+1);
               // std::cout<<a.at(c.at(i)-j)<<"       "<<a.at(c.at(i)-2*kkk+j+1)<<std::endl;
            }
        }
    }
    return a;
}
std::string NapraviPoluPalindrom(std::string a, std::vector<std::string> b){
    if(a.size()==0)return 0;
    if(b.size()==0)return a;
    std::vector<int> indexi;
    int brojac=1;
    int kks=1;
    for(int i=0;i<b.size();i++){
        indexi.resize(0);
        for(int j=0;j<a.size();j++){
            if((a.at(j)==b.at(i).at(0))&&(j==0||a.at(j-1)==' ')){
                int u=0;
                int k=1;
                brojac=1;
                while(u<b.at(i).size()){
                     if(j==a.size())break;
                    if(a.at(j)!=b.at(i).at(u)){k=0;break;}
                    j++;
                    u++;
                    brojac++;
                }if(brojac<b.at(i).size())kks=1;
                else if(j==a.size()){indexi.push_back(j-1);}
                else if(k==1&&(a.at(j)<'A'||a.at(j)>'z')){indexi.push_back(j-1);}
            }
            if(brojac<b.at(i).size()&&indexi.size()==0)continue;
        }if(indexi.size()==0)continue;
       a=funkcija(a,b.at(i),indexi);
    }

    return a;
}
int main(){

    std::string a,b;
    std::cout << "Unesite recenicu: ";
    std::getline(std::cin,a);
  
   
    std::vector<std::string> vv;
    std::string temp;
    std::cout<<"Unesite fraze: ";
  while (std::getline(std::cin, b))
    {
        if (!b.empty())
            vv.push_back(b);
        if (std::cin.peek() == '\n') break;
    }
   std::string i=NapraviPalindrom(a,vv);
  std::string j=NapraviPoluPalindrom(a,vv);
   std::cout<<"Recenica nakon Palindrom transformacije: ";
    std::cout<<i<<std::endl;
   std::cout << "Recenica nakon PoluPalindrom transformacije: ";
    std::cout<<j<<std::endl;
  
 return 0;   
}



/*for(int i=0;;i++){
        if(b.at(i)=='\n'&&b.at(i+1)=='\n')break;
        if(b.at(i)=='\n')continue;
        temp.push_back(b.at(i));
        if(b.at(i+1)=='\n'){vv.push_back(temp);temp.resize(0);}
   }*/
  //Izasla je prva zadaca iz predmeta Tehnike programiranjaajnarimargorp ekinheT, a ovih dana ocekujemo i jos zadaca iz drugih predmetaatemderp higurd 
  //Izasla je prva zadaca iz predmeta Tehnike programiranjaajnarimargorp ekinheT, a ovih dana ocekujemo i jos zadaca iz drugih predmetaatemderp higurd
  //Izasla je prva zadacaacadaz iz predmeta Tehnike programiranjaajnarimargorp ekinheT, a ovih dana ocekujemo i jos zadacaacadaz iz drugih predmetaatemderp higurd
  //Izasla je prva zadacaacadaz iz predmeta Tehnike programiranjaajnarimargorp ekinheT, a ovih dana ocekujemo i jos zadaca iz drugih predmetaatemderp higurd
  
  /*std::string cyka(std::string a,std::string b, int dd){
    int u=b.size();
    std::string cs;
    for(int i=0;i<u;i++){
        cs.insert(cs.begin(),b.at(i));
    }
    int ss=u;
    ss--;
    for(int i=0;i<u;i++){
        a.insert(a.begin()+dd+u+i,cs.at(i));
        ss--;
    }
    
    return a;
}
std::string cyka2(std::string a,std::string b, int dd){
   int  u=b.size();
    u/=2;
        int k=1;
        for(int i=dd+u;i<=dd+2*u;i++){
            a.at(i)=a.at(i-k);
            k++;k++;
        }
    return a;
}

std::string NapraviPalindrom(std::string a, std::vector<std::string> b){
   for(int i=0;i<b.size();i++){
       int dd=a.find(b.at(i));
       if(dd<0)continue;
            a=cyka(a,b.at(i),dd);
          
   }
    return a;
}
std::string NapraviPoluPalindrom(std::string a, std::vector<std::string> b){
   for(int i=0;i<b.size();i++){
       int dd=a.find(b.at(i));
       if(dd<0)continue;
       
            a=cyka2(a,b.at(i),dd);
          
   }
    return a;
}
*/
  
  