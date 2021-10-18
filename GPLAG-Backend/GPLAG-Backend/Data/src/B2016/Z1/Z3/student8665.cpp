#include <iostream>
#include <vector>
#include <iomanip>
typedef std::vector<std::vector<double>> Matrica;
Matrica RastuciPodnizovi(std::vector<double>v){
    Matrica a;
    double c;
    int p(0),f(0);
    int k;              // 10,1,2,3,4,3,2,1,2,3,4 
    std::vector<double>b;
    std::vector<double>n;
    for(int i=0; i<v.size(); i++){
        c = v[i];
        if(i==0){
          b.push_back(c); 
        }else if(i!=0  && v[i]>=v[i-1]){
            b.push_back(c);
        }else if(b.size()>=2){
                k = b.size();
                p++;
                a.resize(p);
                a[f].resize(k);
                f++;
                    for(int j=0; j<a[f-1].size(); j++){
                        a[f-1][j] = b[j];
                    }
                b = std::vector<double>(0);
            }
            else if(b.size()==1) b=std::vector<double>(0);
             if(b.size()==0){
                 b.push_back(c);
             }
             if(i==v.size()-1 && b.size()>=2){
                k = b.size();
                p++;
                a.resize(p);
                a[f].resize(k);
                f++;
                    for(int j=0; j<a[f-1].size(); j++){
                        a[f-1][j] = b[j];
                    }
                }  
            }
        return a;
    }
 Matrica OpadajuciPodnizovi(std::vector<double> v){
      Matrica a;
    double c;
    int p(0),f(0);          
    int k;             // 1, 3 , 2 , 6, 7, 9, 10, 4 , 3  , 1, 7, 
    std::vector<double>b;  //3,2 //10,4,3,1
    std::vector<double>n;
    for(int i=0; i<v.size(); i++){
        c = v[i];
        if(i==0){
          b.push_back(c); 
        }else if(i!=0 && v[i]<=v[i-1]){
            b.push_back(c);
        }else if(b.size()>=2){
                k = b.size();
                p++;
                a.resize(p);
                a[f].resize(k);
                f++;
                for(int j=0; j<a[f-1].size(); j++){
                       a[f-1][j] = b[j];
                    }
                b = std::vector<double>(0);
            }
             else if(b.size()==1) b=std::vector<double>(0);
             if(b.size()==0){
                 b.push_back(c);
             }
             if(i==v.size()-1 && b.size()>=2){
                k = b.size();
                p++;
                a.resize(p);
                a[f].resize(k);
                f++;
                    for(int j=0; j<a[f-1].size(); j++){
                        a[f-1][j] = b[j];
                    }
             }
        }
        return a;
    }
int main (){
    int n;
    double broj;
    Matrica a;   //10 1 2 3 4 3 2 1 2 3 4
    Matrica b;
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin>>n;
    std::vector<double>v;
    std::cout<<"Unesite elemente vektora: ";
    while(v.size()<n){
        std::cin>>broj;
        v.push_back(broj);
    }
    a = RastuciPodnizovi(v);
    std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
    for(int i=0; i<a.size(); i++){
    	for(int j=0; j<a[i].size(); j++){
    		std::cout<<std::setprecision(12)<<a[i][j]<<" ";
    	}
    	std::cout<<std::endl;
    }
    b = OpadajuciPodnizovi(v);
    std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
    for(int i=0; i<b.size(); i++){
    	for(int j=0; j<b[i].size(); j++){
    		std::cout<<std::setprecision(12)<<b[i][j]<<" ";
    	}
    	std::cout<<std::endl;
    } 
    
	return 0;
}