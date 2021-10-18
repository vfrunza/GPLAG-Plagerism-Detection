#include <iostream>
#include <vector>
#include <iterator>
#include <type_traits>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <cmath>
using namespace std;
int SumaDjelilaca (long long int x) {
int suma=0;
vector<int> djelioci;
for(long long int i=1;i<=abs(x);i++) djelioci.push_back(i);
for_each(djelioci.begin(),djelioci.end(),[&](int i){
if(x%i==0) suma+=i;
});
return suma;
}
bool Prost(long long int x){  
bool prost=true;
vector<long long int> djelioci;
for(long long int i=2;i<=abs(x/2);i++) djelioci.push_back(i);
for_each(djelioci.begin(),djelioci.end(),[&](long long int i){
if(x%i==0) prost=false;
});
return prost;
}
int BrojProstihFaktora(long long int x){
int brojac=0;
long long int temp=abs(x);
for(long long int i=2;i<=temp;i++){
int exp=0;
while(temp%i==0){
exp++;
temp/=i;
}
brojac+=exp;
}
return brojac;
}
bool Savrsen(long long int x){
int suma=0;
vector<long long int> djelioci;
for(long long int i=1;i<abs(x);i++) djelioci.push_back(i);
for_each(djelioci.begin(),djelioci.end(),[&](long long int temp){
if(x%temp==0) suma+=temp;
});
return x==suma;
}
int BrojSavrsenihDjelilaca(long long int x){
int brojac=0;
vector<long long int> djelioci;
for(long long int i=1;i<abs(x);i++) djelioci.push_back(i);
for_each(djelioci.begin(),djelioci.end(),[&](long long int i){
if(x%i==0 && Savrsen (i)) brojac++;;
});
return brojac;
}
int SumaCifara(long long int broj){
int suma=0;
while(broj!=0){
suma+=broj%10;
broj/=10;
}
return suma;
}
template <typename Tip>
bool istiSu(Tip x, Tip y){
return x==y;
}
template <typename PokTip1, typename PokTip2>
auto UvrnutiPresjek(PokTip1 p1, PokTip1 p2, PokTip2 p3, PokTip2 p4) ->vector<vector<typename remove_reference<decltype(*p1)>::type>>{  
vector<vector<typename remove_reference<decltype(*p1)>::type>> vrati;
for(auto i=p1;i!=p2;i++){
for(auto j=p3;j!=p4;j++){
if(*i==*j){ 
vector<typename remove_reference<decltype(*i)>::type> temp;    
temp.push_back(*i); temp.push_back(0); temp.push_back(0);  
vrati.push_back(temp);   
}   
}
}
sort(vrati.begin(),vrati.end(),[](vector<typename remove_reference<decltype(*p1)>::type>v1,vector<typename
remove_reference<decltype(*p1)>::type>v2 {    
if(v2[0]>v1[0] return true;    
return false;
});
return vrati;
}
template <typename PokTip1, typename PokTip2, typename Tip1, typename Tip2>
auto UvrnutiPresjek(PokTip1 p1, PokTip1 p2, PokTip2 p3; PokTip2 p4, Tip2 (*Fun) (Tip1)=nullptr)->    
vector<vector<typename remove_reference<decltype(*p1)>::type>> {    
vector<vector<typename remove_reference<decltype(*p1)>::type>> vrati;    
for(auto i=p1;i!=p2;i++){    
for(auto j=p3;j!=p4;j++){    
if(istiSu(Fun(*i),Fun(*j))){    
vector<typename remove_reference<decltype(decltype(*i)>::type> temp;    
temp.push_back(*i); temp.push_back(*j); temp.push_back(Fun(*i));
vrati.push_back(temp);    
}    
}    
}    
sort(vrati.begin(),vrati.end(),[](vector<typename remove_reference<decltype(*p1)>::type>v1,    
vector<typename remove_reference<decltype(*p1)>::type> v2){    
if(v2[2]>v1[2] return true;
else if(v1[2]==v2[2] && v2[0]>v1[0])
return true;
else if(v1[2]==v2[2] && v1[0]==v2[0] && v2[1]>v1[1]) return true;
else return false;

});
return vrati;
}

template <typename PokTip1, typename PokTip2>
auto UvrnutaRazlika(PokTip1 p1, PokTip1 p2, PokTip2 p3, PokTip2 p4)-> vector<vector<typename remove_reference<decltype(*p1)>::type>>{    
vector<vector<typename remove_reference<decltype(*p1)>::type>> vrati;
bool postoji=false;
PokTip2 vrati2=p3;
PokTip1 vrati1=p1;
while(p1!=p2){
p3=vrati2;
postoji=true;
while(p3!=p4){
if(istiSu(*p1,*p3)){    
postoji=false;
break;
}
p3++;
}
if(postoji){    
vector<typename remove_reference<decltype(*p1)>::type>temp;    
temp.push_back(*p1); temp.push_back(0);    
vrati.push_back(temp);    
postoji=false;
}
p1++;
}
postoji=false;
p3=vrati2;
while(p3!=p4){
p1=vrati1;
postoji=true;
while(p1!=p2){
if(istiSu(*p1,*p3)) {    
postoji=false;
break;
}
p1++;
}
if(postoji){    
 postoji=false;
 vector<typename remove_reference<decltype(*p3)>::type> temp;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}










