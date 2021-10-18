/B2016/2017: Zadaća 3, Zadatak 4
#include <iostream>
#include<list>
#include<iterator>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> imena_djece,int broj_timova){
    //prvih mod(n,k)timova ima [n/k] + 1 članova
    auto N(imena_djece.size()%broj_timova);
    auto n(int(imena_djece.size()/broj_timova)+1);
    auto N1(broj_timova-N);
    auto i(0);
    std::list<std::string> lista;
    std::vector<std::set<std::string>> timovi;
    std::string::iterator it1;
    auto it(lista.begin());
    std::copy(imena_djece.begin(),imena_djece.end(),std::back_inserter(lista));
    if(N==0){
    it=lista.begin();n=0;;}
     auto n1((imena_djece.size()-N*n)/N1);
     it=lista.begin();
       for(int j=0;j<N;j++){
        std::set<std::string>tim;
        if(lista.size()==1&&j==N-1)
        i=0;
        int t(0);
    for( it;it!=lista.end();it++){
        if(t){it=lista.begin();t=0;}
        if(i==0){
            if(lista.size()==1&&j==N-1){
            tim.insert(*it);it=lista.erase(it);break;}
        tim.insert(*it);
        i=std::count_if((*it).begin(),(*it).end(),[](char znak){
            if((znak>='A'&&znak<='Z')||(znak>='a'&&znak<='z')||(znak>='0'&&znak<='9'))
    return true;
    else
    return false;
        })-1;
        if(it==--lista.end())i++;
            it=lista.erase(it);
            if(it==lista.end())it--;
            if(lista.size()==1&&j==N-1){
            tim.insert(*it);it=lista.erase(it);}
            if(tim.size()==n)break;
        }
        if(it==--lista.end()){
        it=lista.begin();t=1;}
    i--;    
}
        timovi.push_back(tim);
    }

  for(int j=0;j<N1;j++){
        std::set<std::string>tim;
        int t(0);
        if(lista.size()==1&&j==N1-1)
        i=0;
    for( it;it!=lista.end();it++){
        if(t){it=lista.begin();t=0;}
        if(i==0){
            if(lista.size()==1&&j==N1-1){
            tim.insert(*it);it=lista.erase(it);break;}
        tim.insert(*it);
        i=std::count_if((*it).begin(),(*it).end(),[](char znak){
            if((znak>='A'&&znak<='Z')||(znak>='a'&&znak<='z')||(znak>='0'&&znak<='9'))
    return true;
    else
    return false;
        })-1;
        if(it==--lista.end())i++;
            it=lista.erase(it);
            if(it==lista.end())it--;
            if(lista.size()==1&&j==N1-1){
            tim.insert(*it);it=lista.erase(it);}
            if(tim.size()==n1)break;
        }
        if(it==--lista.end()){
        it=lista.begin();t=1;}
    i--;    
}
        timovi.push_back(tim);
    }
return timovi;
}
int main ()
{
    std::vector<std::string> imena_djece;
    int broj_djece;
    std::string imena;
    int broj_timova;
    std::cout<<"Unesite broj djece: ";
    std::cin>>broj_djece;
    std::cin.ignore(1000,'\n');
    std::cout<<"Unesite imena djece: ";
    for(int i=0;i<broj_djece;i++){
        std::getline(std::cin,imena);
        imena_djece.push_back(imena);
    }
    std::cout<<"\nUnesite broj timova: ";
    std::cin>>broj_timova;
   auto timovi(Razvrstavanje(imena_djece,broj_timova));
   for(int i=0;i<broj_timova;i++){
        std::cout<<"Tim "<<i+1<<": ";
        for(auto it=timovi[i].begin();it!=timovi[i].end();it++)
        if(it!=--timovi[i].end())
        std::cout<<*it<<", ";
        else std::cout<<*it;
        std::cout<<std::endl;
    }
	return 0;
}