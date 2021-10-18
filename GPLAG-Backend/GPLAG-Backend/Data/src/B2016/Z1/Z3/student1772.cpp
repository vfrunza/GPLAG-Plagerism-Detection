#include <iostream>
#include <vector> 

std::vector<std::vector<double>>RastuciPodnizovi(std::vector<double>v){
    std::vector<double> Podniz;
    for(int i=0;i<v.size()-1;i++){
        int j=i+1;
        if(v[j]>=v[i]){
        for(j=i+1;j<v.size()+1;j++){
            if(j==v.size()){
                if(v[i]>=v[i-1]){
            Podniz.push_back(v[i]);
            break;
                }
                else break;
            }
            if(v[i]>v[j]){
                Podniz.push_back(v[i]);
                break;
            }
            Podniz.push_back(v[i]);
            i++;
        }
               }
    }
    std::vector<std::vector<double>>m(1);
    int a(1);
    for(int i=0;i<Podniz.size()-1;i++){
        for(int j=i+1;j<Podniz.size();j++){
        if(Podniz[j]<=Podniz[j-1]){
            int k(j);
            while(i!=k){
                m[a-1].push_back(Podniz[i]);
                i++;
            }
            a++;
            m.resize(a);
        }
        if(j==Podniz.size()-1 && Podniz[j]>=Podniz[j-1]){
            int k(j);
            while(i<=k){
                m[a-1].push_back(Podniz[i]);
                i++;
            }
            a++;
            m.resize(a);
        }
            }
            
}
return m;
}

std::vector<std::vector<double>>OpadajuciPodnizovi(std::vector<double>v){
    std::vector<double>Podniz ;
    for(int i=0;i<v.size()-1;i++){
        int j=i+1;
        if(v[j]<=v[i]){
            for(j=i+1;j<v.size()+1;j++){
                if(j==v.size()){
                    if(v[i]<=v[i-1]){
                        Podniz.push_back(v[i]);
                        break;
                    }
                    else break;
                }
                if(v[i]<v[j]){
                    Podniz.push_back(v[i]);
                    break;
                }
                Podniz.push_back(v[i]);
                i++;
            }
        }
    }
    std::vector<std::vector<double>>m(1);
    int b(1) ;
    for(int i=0;i<Podniz.size()-1;i++){
        for(int j=i+1;j<Podniz.size();j++){
            if(Podniz[j]>=Podniz[j-1]){
                int k(j);
                while(i!=k){
                    m[b-1].push_back(Podniz[i]);
                    i++;
                }
                b++;
                m.resize(b);
            }
            if(j==Podniz.size()-1 && Podniz[j]<=Podniz[j-1]){
                int k(j);
                while(i<=k){
                    m[b-1].push_back(Podniz[i]);
                    i++;
                }
                b++;
                m.resize(b);
            }
        }
        
}
return m;
}
    


    
int main ()
{
    std::vector<double>m;
    std::vector<std::vector<double>>f;
    std::vector<std::vector<double>>g;
    int n;
    std::cout<<"Unesite broj elemenata vektora: ";
    std::cin>>n;
    std::cout<<"Unesite elemente vektora: ";
    for(int i=0;i<n;i++){
        int t;
        std::cin >> t;
        m.push_back(t);
    }
    f=RastuciPodnizovi(m);
    std::cout<<"Maksimalni rastuci podnizovi: "<<std::endl;
    for(int i=0;i<f.size();i++){
        for(int j=0;j<f[i].size();j++){
        std::cout<<f[i][j]<<" ";
    }
    std::cout<<std::endl;
    }
    g=OpadajuciPodnizovi(m);
    std::cout<<"Maksimalni opadajuci podnizovi: "<<std::endl;
    for(int i=0;i<g.size();i++){
        for(int j=0;j<g[i].size();j++){
            std::cout<<g[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    
    return 0;
}