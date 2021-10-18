#include <iostream>
#include <utility>
#include <vector>
#include <stdexcept>
#include <functional>

std::function<double(double)> BaricentricnaInterpolacija (std::vector<std::pair<double,double>>Par,int d){
    int n=Par.size();
    return [n,d,Par] (double x){
        double w(0);
        for(int i=0;i<n;i++){
            for(int k=std::max(1,i+1-d);k<=std::min(i+1,n-d);k++){
                int p=1;
                for(int j=k;j<=k+d;j++){
                    if(j - 1!=i){
                        std::cout << "Par 1 - Par 2 = " << Par[i].first << " - " << Par[j - 1].first << std::endl;
                        p=p/(Par[i].first-Par[j-1].second);
                    }
                    if (k%2==0){
                        p=-p;
                    }
                    w=w+p;
                }
            }
            double p=0;
            double q=0;
            if(x==Par[i].first){
                return Par[i].second;
            }
            double u=w/(x-Par[i].first);
            p=p+u*Par[i].second;
            q=q+u;
            return p/q;
        }
    };
}
int main ()
{
    std::vector<std::pair<double,double>> p{{1,3},{2,5},{4,4},{5,2},{7,1}};
    auto f(BaricentricnaInterpolacija(p,2));
    std::cout<<f(2.5);
	return 0;
}