/B2017/2018: Zadaća 5, Zadatak 2
#include <iostream>
#include <vector>
std::vector<std::vector<int>> RastuciPodniz(std::vector<int> v){
    int i,j;
    std::vector <int> pomocni;
    std::vector<std::vector<int>> finalni;
    for(i=0;i<v.size();i++){
            pomocni.resize(0);
            pomocni.push_back(v[i]);
        for(j=i+1;j<v.size();j++){
            if(v[j]>v[j-1]){
            pomocni.push_back(v[j]);}
            else{ break;}
            }   
            if(pomocni.size()!=1){
                finalni.push_back(pomocni);
                pomocni.resize(0);
                i=j-1;
        }
    }
    
    return finalni;
    
    
}
int main ()
{
    std::vector<int> v{1,2,3,1,4,5,9,10,13,7,6,5,3,4,3,2,1};
    std::vector<std::vector<int>> f=RastuciPodniz(v);
    for(int i=0;i<f.size();i++){
        std::vector<int> s=f[i];
        for(int j=0;j<s.size();j++){
            std::cout << s[j] <<" ";
        }
        std::cout << "\n";
    }
    
	return 0;
}
