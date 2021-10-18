#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <deque>
#include <vector>



template <typename t>
int SumaCifara(t n) {
int suma(0);
while(n!=0) {
    suma+=n%10;
    n/=10;
}
return suma;
}

int SumaDjelilaca(int n) {
int suma(0);
for(int i=3;i<n;i++) {
    if(n%i==0) suma+=i;
}
return suma;
}

int prost(int x) {
    int p;
    for (p = 2; p <= x / 2; p++) {
        if (x / p * p == x) {
            return p;
        }
    }
    return 1;
}


int BrojProstihFaktora(int x) {
    int faktor,brojac(1);
    faktor = prost(x);
    while (faktor > 1) {
        brojac++;
        x = x / faktor;
        faktor = prost(x);
    }
    return brojac;
}


int BrojSavrsenihDjelilaca(int n) {
int broj(0);
for(int i=3;i<n;i++) {
    if(n%i==0) {
        if(i==6 || i==28 || i==496 || i==8128 || i==33550336) broj++;
    }
}
return broj;
}


template <typename Tip1,typename Tip2>
std::vector<std::vector<int>> UvrnutiPresjek(Tip1 p1,Tip1 p2,Tip2 p3,Tip2 p4,int f(int)) {
std::vector<std::vector<int>>M;
Tip2 p=p3;
int brojac(0),i(0);
while(p1!=p2) {
    while(p3!=p4) {
        if(f(*p1)==f(*p3)) {
            brojac++;
            M.resize(brojac);
            M[i].resize(3);
            M[i][0]=*p1;
            M[i][1]=*p3;
            M[i][2]=f(*p1);
            i++;
        }
        p3++;
    }
    p3=p;
    p1++;
}
for(int i=0;i<brojac-1;i++) {
    for(int j=i+1;j<brojac;j++) {
        if(M[i][2]>M[j][2] || (M[i][2]==M[j][2] && M[i][0]>M[j][0]) || (M[i][2]==M[j][2] && M[i][0]==M[j][0] && M[i][1]>M[j][1]) ) {
            for(int k=0;k<3;k++) {
                int pom=M[i][k];
                M[i][k]=M[j][k];
                M[j][k]=pom;
            }
        }
    }
}
return M;
}




template <typename Tip1,typename Tip2>
std::vector<std::vector<int>> UvrnutaRazlika(Tip1 p1,Tip1 p2,Tip2 p3,Tip2 p4,int f(int)) {
std::vector<std::vector<int>>M;
int test_1(0),test_2(0),i(0),brojac(0);
Tip2 p=p3;
Tip1 r=p1;
while(p1!=p2) {
    while(p3!=p4) {
        if (f(*p1)==f(*p3)) {test_1++;}
        p3++;
    }
    if(test_1==0) {
        brojac++;
        M.resize(brojac);
        M[i].resize(2);
        M[i][0]=*p1;
        M[i][1]=f(*p1);
        i++;
    }
    test_1=0;
    p3=p;
    p1++;
}

p3=p;
p1=r;
while(p3!=p4) {
        test_2=0;
    while(p1!=p2) {
        if(f(*p3)==f(*p1)) {test_2++;}
        p1++;
    }
    if(test_2==0) {
        brojac++;
        M.resize(brojac);
        M[i].resize(2);
        M[i][0]=*p3;
        M[i][1]=f(*p3);
        i++;
    }
    test_2=0;
    p1=r;
    p3++;
}
for(int i=0;i<brojac-1;i++) {
    for(int j=i+1;j<brojac;j++) {
        if(M[i][0]<M[j][0]) {
            for(int k=0;k<3;k++) {
                int pom=M[i][k];
                M[i][k]=M[j][k];
                M[j][k]=pom;
            }
        }
    }
}
return M;
}




int main () {
int m,n,brojaci_1[10000]={0},brojaci_2[10000]={0},broj;
std::cout<<"Unesite broj elemenata prvog kontejnera: ";
std::cin>>m;
std::cout<<"Unesite elemente prvog kontejnera: ";
std::deque<int>A(m);
for(int i=0;i<m;i++) {
    std::cin>>broj;
    brojaci_1[broj]++;
    if(brojaci_1[broj]==1) A[i]=(broj);
    else {i--;}
}
std::cout<<"Unesite broj elemenata drugog kontejnera: ";
std::cin>>n;
std::cout<<"Unesite elemente drugog kontejnera: ";
std::deque<int>B(n);
for(int i=0;i<n;i++) {
    std::cin>>broj;
    brojaci_2[broj]++;
    if(brojaci_2[broj]==1) B[i]=(broj);
    else {i--;}
}
std::vector<std::vector<int>>M;
M=UvrnutiPresjek(A.begin(),A.end(),B.begin(),B.end(),SumaCifara);
std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
for(int i=0;i<M.size();i++) {
    for(int j=0;j<3;j++) {
        std::cout<<std::setw(6)<<M[i][j]<<" ";
    }
    std::cout<<std::endl;
}
std::vector<std::vector<int>>N=UvrnutaRazlika(A.begin(),A.end(),B.begin(),B.end(),BrojProstihFaktora);
std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
for(int i=0;i<N.size();i++) {
    for(int j=0;j<2;j++) {
        std::cout<<std::setw(6)<<N[i][j]<<" ";
    }
    std::cout<<std::endl;
}
std::cout<<"Dovidjenja!";
return 0;
}







