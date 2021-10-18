#include <iostream>
#include <algorithm>
#include <vector>
#include <new>
bool SavrseniBrojevi(int x){
    int k(0);
    for(int i=1; i<x; i++){
        if((x%i)==0){
           k+=i; 
        }
    }
    if(k==x)
        return true;
    return false;    
}
bool BrojDjelilaca(int x,int y){
    int s1(0);
    int s2(0);
    for(int i=1; i<x; i++){
        if((x%i)==0)
            s1++;
    }
    for(int i=1; i<y; i++){
    if((y%i)==0)
        s2++;
    }
    if(s1==s2){
        return true;
    }    
    return false;
}
template <typename Pok>
int *Izdvajanje(Pok p1, Pok &p2,int& ss){
   Pok tmp=p1;
   while(tmp!=p2){
        if(SavrseniBrojevi(*tmp))
            ss++;
        tmp++;    
   }
   tmp=p1;
   int *pok=new int[ss];
   int *tmp2=pok;
   while(tmp!=p2){
       if(SavrseniBrojevi(*tmp)){
           *tmp2=*tmp;
           tmp2++;
       }
       tmp++;
   }
   tmp=p1;
   Pok tmp1=(p1+1);
   while(tmp<p2){
       tmp1=tmp+1;
       while(tmp1<p2){
           if(BrojDjelilaca(*tmp,*tmp1)){
               Pok tmp3=tmp+1;
               Pok tmp4=tmp;
               while(tmp3<tmp1){
                   *tmp4=*tmp3;
                   tmp4++;
                   tmp3++;
               }
               tmp3=tmp1+1;
               while(tmp3<p2){
                   *tmp4=*tmp3;
                   tmp4++;
                   tmp3++;
               }
               p2-=2;
               tmp--;
           }
           tmp1++;
       }
       tmp++;
   }
   return pok;
}
int main() {
    std::vector<int> k;
    std::cout << "Unesite brojeve: ";
    for(;;){
        int x;
        std::cin >>x;
        if(x==-1)
            break;
        k.push_back(x);
    }
    std::vector<int>::iterator p1 ;
    std::vector<int>::iterator p2 ;
    p1=k.begin();
    p2=k.end();
    int br_savrsenih(0);
    int &l(br_savrsenih);
    int* p=Izdvajanje(p1,p2,l);
    std::cout << "Modificirani kontejner: ";
    while(p1!=p2){
        std::cout << *p1 <<" ";
        p1++;
    }
    std::cout<< std::endl;
    std::cout<<"Savrseni brojevi: ";
    int *w=p;
    for(int i=0; i<br_savrsenih; i++){
        std::cout << *w <<" ";
        w++;
    }
    delete []p;
    return 0;
}