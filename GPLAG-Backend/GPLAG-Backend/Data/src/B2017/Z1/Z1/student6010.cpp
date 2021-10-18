#include <iostream>
#include <vector>
#include <deque>

using namespace std;
deque<int> DajTernarni(int broj){
    deque<int>pomocni;
    int n=abs(broj);
    int ostatak;
    do{
        ostatak=n%3;
        pomocni.push_front(ostatak);
        n/=3;
    }while(n!=0);
    return pomocni;
}
bool JeLiProst(int broj){
    for(int i=2; i<broj; i++){
        if(broj%i==0) return false;
    }
    return true;
}

vector<int> IzdvojiSimetricneTernarne(vector<int> v, bool logic){
    vector<int>pomocni;
    for(int i=0; i<v.size(); i++){
            deque<int>dekic(DajTernarni(v[i]));
            bool simetrisanje(true);
            for(int j=0; j<dekic.size()/2; j++){
                if(dekic[j]!=dekic[dekic.size()-j-1]) simetrisanje=false;
            } cout<<simetrisanje<<"\n";
        if((logic==true && JeLiProst(v[i])==true && simetrisanje==true) || (logic==false && JeLiProst(v[i])==false && simetrisanje==true)){
            pomocni.push_back(v[i]);
        }
    }
    for(int i=0; i<pomocni.size(); i++) cout<<pomocni[i]<<" ";
    return pomocni;
}

int main()
{ std::vector<int> v={191, 233, 43, 313, 143, 13, 121, 678, 151, 23, -12, 727, 173, -1};
auto v1=IzdvojiSimetricneTernarne(v, 1);
	return 0;}