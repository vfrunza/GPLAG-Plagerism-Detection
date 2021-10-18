#include<iostream>
#include <utility>
#include <vector>
#include <stdexcept>
#include <functional>

double BaricentricnaInterpolacija (std::vector<std::pair<double,double>>Par,int d){
    int n=Par.size();
    double w(0);
    for(int i=1;i<n;i++){
    for(int k=std::max(1,i-d);k<std::min(i,n-d);k++){
        int p;
    for(int j=k;j<k+d;j++){
        if(j!=i){
            p=1/(Par[i].first-Par[i].second);
        }
        if (k%2==0){
            p=-p;
        }
        w=w+p;
        }
    }
    }
    return w;
}
int main (){
std::vector<std::pair<double,double>> p{{1,3},{2,5},{4,4},{5,2},{7,1}};
    std::cout << BaricentricnaInterpolacija(p,2);
    return 0;
    }