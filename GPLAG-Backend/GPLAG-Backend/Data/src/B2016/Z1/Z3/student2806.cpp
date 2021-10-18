#include <iostream>
#include <vector>
#include <complex>
#include <stdexcept>
typedef std::vector<std::vector<int>>Matrica;
std::complex<int> VrhMatrice(Matrica a,int p ,int q){
    int w=a[0].size();
    for(int e=0; e<a.size(); e++){
        if(a[e].size()!=w)throw std::domain_error("Nekorektna matrica");
    }
    if(p<0 || p>=a.size() || q<0 || q>=a[0].size())throw std::range_error("Nekorektna pocetna pozicija");
    std::complex<int>z;
    int i,j;
    int max=a[p][q];
    int tmp=max-1;
    while(tmp!=max){
        int veca=a[p][q],k=p,l=q;
        tmp=max;
        i=p;
        j=q;
        if(i==0 && j==0){
            if(a[i][j+1]>veca){
                veca=a[i][j+1];
                l=q+1;
            }
            if(a[i+1][j+1]>veca){
                veca=a[i+1][j+1];
                k=p+1;
                l=q+1;
            }
            if(a[i+1][j]>veca){
                veca=a[i+1][j];
                k=p+1;
            }
            if(max!=veca){
                max=veca;
                p=k;
                q=l;
            }
        }
        if(i==0 && (j>0 && j<a[0].size()-1)){
            if(a[i][j+1]>veca){
                veca=a[i][j+1];
                l=q+1;
            }
            if(a[i+1][j+1]>veca){
                veca=a[i+1][j+1];
                k=p+1;
                l=q+1;
            }
            if(a[i+1][j]>veca){
                veca=a[i+1][j];
                k=p+1;
            }
            if(a[i+1][j-1]>veca){
                veca=a[i+1][j-1];
                k=p+1;
                l=q-1;
            }
            if(a[i][j-1]>veca){
                veca=a[i][j-1];
                l=q-1;
            }
            if(max!=veca){
                max=veca;
                p=k;
                q=l;
            }
        }
        if(i==0 && j==a[0].size()-1){
            if(a[i+1][j]>veca){
                veca=a[i+1][j];
                k=p+1;
            }
            if(a[i+1][j-1]>veca){
                veca=a[i+1][j-1];
                k=p+1;
                l=q-1;
            }
            if(a[i][j-1]>veca){
                veca=a[i][j-1];
                l=q-1;
            }
            if(max!=veca){
                max=veca;
                p=k;
                q=l;
            }
        }
        if(j==0 && (i>0 && i<(a.size()-1))){
            if(a[i-1][j]>veca){
                veca=a[i-1][j];
                k=p-1;
            }
            if(a[i-1][j+1]>veca){
                veca=a[i-1][j+1];
                k=p-1;
                l=q+1;
            }
            if(a[i][j+1]>veca){
                veca=a[i][j+1];
                l=q+1;
            }
            if(a[i+1][j+1]>veca){
                veca=a[i+1][j+1];
                k=p+1;
                l=q+1;
            }
            if(a[i+1][j]>veca){
                veca=a[i+1][j];
                k=p+1;
            }
            if(max!=veca){
                max=veca;
                p=k;
                q=l;
            }
        }
        if((j>0 && j<a[0].size()-1) && (i>0 && i<a.size()-1)){
            if(a[i-1][j]>veca){
                veca=a[i-1][j];
                k=p-1;
            }
            if(a[i-1][j+1]>veca){
                veca=a[i-1][j+1];
                k=p-1;
                l=q+1;
            }
            if(a[i][j+1]>veca){
                veca=a[i][j+1];
                l=q+1;
            }
            if(a[i+1][j+1]>veca){
                veca=a[i+1][j+1];
                k=p+1;
                l=q+1;
            }
            if(a[i+1][j]>veca){
                veca=a[i+1][j];
                k=p+1;
            }
            if(a[i+1][j-1]>veca){
                veca=a[i+1][j-1];
                k=p+1;
                l=q-1;
            }
            if(a[i][j-1]>veca){
                veca=a[i][j-1];
                l=q-1;
            }
            if(a[i-1][j-1]>veca){
                veca=a[i-1][j-1];
                k=p-1;
                l=q-1;
            }
            if(max!=veca){
                max=veca;
                p=k;
                q=l;
            }
        }
        if(j==a[0].size()-1 && (i>0 && i<a.size()-1)){
            if(a[i-1][j]>veca){
                veca=a[i-1][j];
                k=p-1;
            }
            if(a[i+1][j]>veca){
                veca=a[i+1][j];
                k=p+1;
            }
            if(a[i+1][j-1]>veca){
                veca=a[i+1][j-1];
                k=p+1;
                l=q-1;
            }
            if(a[i][j-1]>veca){
                veca=a[i][j-1];
                l=q-1;
            }
            if(a[i-1][j-1]>veca){
                veca=a[i-1][j-1];
                k=p-1;
                l=q-1;
            }
            if(max!=veca){
                max=veca;
                p=k;
                q=l;
            }
        }
        if(i==a.size()-1 && j==0){
            if(a[i-1][j]>veca){
                veca=a[i-1][j];
                k=p-1;
            }
            if(a[i-1][j+1]>veca){
                veca=a[i-1][j+1];
                k=p-1;
                l=q+1;
            }
            if(a[i][j+1]>veca){
                veca=a[i][j+1];
                l=q+1;
            }
            if(max!=veca){
                max=veca;
                p=k;
                q=l;
            }
        }
        if(i==a.size()-1 && (j>0 && j<a[0].size()-1)){
            if(a[i-1][j]>veca){
                veca=a[i-1][j];
                k=p-1;
            }
            if(a[i-1][j+1]>veca){
                veca=a[i-1][j+1];
                k=p-1;
                l=q+1;
            }
            if(a[i][j+1]>veca){
                veca=a[i][j+1];
                l=q+1;
            }
            if(a[i][j-1]>veca){
                veca=a[i][j-1];
                l=q-1;
            }
            if(a[i-1][j-1]>veca){
                veca=a[i-1][j-1];
                k=p-1;
                l=q-1;
            }
            if(max!=veca){
                max=veca;
                p=k;
                q=l;
            }
        }
        if(i==a.size()-1 && j==a[0].size()-1){
            if(a[i-1][j]>veca){
                veca=a[i-1][j];
                k=p-1;
            }
            if(a[i][j-1]>veca){
                veca=a[i][j-1];
                l=q-1;
            }
            if(a[i-1][j-1]>veca){
                veca=a[i-1][j-1];
                k=p-1;
                l=q-1;
            }
            if(max!=veca){
                max=veca;
                p=k;
                q=l;
            }
        }
    }
    z.real(p);
    z.imag(q);
    return z;
}    
int main() {
    try{
    std::cout << "Unesite brojeve m i n: " << std::endl;
    int a,b;
    std::cin >> a>>b;
    Matrica m(a,std::vector<int>(b));
    for(int i=0; i<a; i++){
        for(int j=0;j<b;j++){
            std::cout << "Unesite element "<<i<<" x "<<j <<":"<< std::endl;
            int z;
            std::cin >> z;
            m[i][j]=z;
        }
    }
    std::cout << "Unesite brojeve p i q: " << std::endl;
    int p,q;
    std::cin >> p>>q;
    std::complex<int> k=VrhMatrice(m,p,q);
    std::cout << "Vrh matrice je na poziciji: "<<k <<"."<< std::endl;
    std::cout << "Vrijednost elementa je: "<<m[k.real()][k.imag()] <<"."<< std::endl;
    }
    catch(std::domain_error greska){
        std::cout << greska.what() << std::endl;
    }
    catch(std::range_error greske){
        std::cout << greske.what() << std::endl;
    }
    return 0;
}

