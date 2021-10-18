#include <iostream>
#include <vector>
#include <deque>
#include <type_traits>
#include <iomanip>
#include <algorithm>


bool ProstBroj(long long int n){
    int brojac(1);
    if(n<2) return false;
    for(int i(2);i<n;i++){
        if(n%i==0){
            brojac=brojac+1;
        }
    }
    if(brojac==1){
        return true;
    }
    else return false;
}

int SumaDjelilaca(long long int broj){
    if(broj<0) broj=-1*broj;
    int suma(0);
    int nesto(0);
    if(broj==1) nesto++;
    for(long long int i(1);i<=broj/2;i++){
        if(broj%i==0){
            suma=suma+i;
        }
    }
    suma+=broj;
    return suma;
}
int SumaCifara(long long int broj){
    if(broj<0) broj=-1*broj;
    int suma(0);
    while(broj!=0){
        int cifra=broj%10;
        suma=suma+cifra;
        broj/=10;
    }
    return suma;
}
int BrojSavrsenihDjelilaca(long long int broj){
    if(broj<0) broj=-1*broj;
    int brojac(0);
    int suma(0);
    for(long long int i(2);i<=broj/2;i++){
        if(broj%i==0){
            int brojara=i;
            for(int j(1);j<=brojara/2;j++){
                if(brojara%j==0){
                    suma=suma+j;
                }
            }
            if(suma==brojara) brojac++;
            suma=0;
        }
    }
    for(int i(1);i<=broj/2;i++){
        if(broj%i==0){
            suma+=i;
        }
    }
    if(suma==broj) brojac++;
    return brojac;
}

int BrojProstihFaktora(long long int broj){ 
    if(broj<0) broj=-1*broj;
    int brojac(0);
    if(ProstBroj(broj)) return 1;
    long long int pomocni=broj;
    for(int i(1);i<=broj/2;i++){
        //if(i==1) continue;
        if(pomocni%i==0){
            int brojara=i;
            bool c=ProstBroj(brojara);
            if(c==true){ brojac++;
                   pomocni/=i;
                   i--;
                    }
                }
            }
    return brojac;
}

template <typename Tip1, typename Tip2, typename Tip3, typename Tip4>

auto UvrnutiPresjek(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip3 f(Tip4))-> std::vector<std::vector<typename std::remove_reference <decltype (*p1)>::type>> {
    std::vector<std::vector<typename std::remove_reference<decltype (*p1)>::type>> matrica;
    Tip2 temp=p3;
    while(p1!=p2){
        while(p3!=p4){
            if(f(*p1)==f(*p3)) matrica.push_back({*p1,*p3,f(*p1)});
            p3++;}
        p3=temp;
        p1++;
    }
    std::sort(matrica.begin(),matrica.end(),[](std::vector<typename std::remove_reference<decltype(*p1)>::type> vektor1, std::vector<typename std::remove_reference<decltype(*p1)>::type> vektor2){
    if(vektor1[2]>vektor2[2]) return false;
    else if(vektor1[2]==vektor2[2]){
        if(vektor1[0]>vektor2[0]) return false;
        else if(vektor1[0]==vektor2[0]){
            if(vektor1[1]>vektor2[1]) return false;
            else return true;
        }
    }
    return true;
});
    return matrica;
}
template <typename Tip1,typename Tip2, typename Tip3, typename Tip4>

auto UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4, Tip3 f(Tip4))-> std::vector<std::vector<typename std::remove_reference <decltype (*p1)>::type>>{
    std::vector<std::vector<typename std::remove_reference<decltype (*p1)>::type>> matrica;
    int brojac(0);
    int brojacprvogdeka(0);
    int brojacdrugogdeka(0);
    Tip1 pomocni1=p1;
    Tip1 pomocni2=p2;
    while(pomocni1!=pomocni2) {brojacprvogdeka++; pomocni1++;}
    Tip2 pomocni3=p3;
    Tip2 pomocni4=p4;
    while(pomocni3!=pomocni4) {brojacdrugogdeka++; pomocni3++;}
    Tip1 temp1=p1;
    Tip1 temara=p1;
    Tip2 temp3=p3;
    Tip2 temp4=p4;
    Tip1 temp2=p2;
    while(temp1!=temp2){
        while(temp3!=temp4){
            if(f(*temp1)!=f(*temp3)) brojac++;
            temp3++;}
        
        if(brojac==brojacdrugogdeka) matrica.push_back({*temp1,f(*temp1)});
        brojac=0;
        temp3=p3;
        temp1++;
        }
    brojac=0;
    while(p3!=p4){
        while(p1!=p2){
            if(f(*p3)!=f(*p1)) brojac++;
            p1++;}
        if(brojac==brojacprvogdeka) matrica.push_back({*p3,f(*p3)});
        brojac=0;
        p1=temara;
        p3++;
        }
    std::sort(matrica.begin(),matrica.end(),[](std::vector<typename std::remove_reference<decltype(*p1)>::type> vektor1,std::vector<typename std::remove_reference<decltype(*p1)>::type> vektor2){
        if(vektor1[0]<vektor2[0]) return false;
        else if(vektor1[0]==vektor2[0]) return true;
        return true;
    });
    
    return matrica;
}

template <typename Tip1, typename Tip2>

auto UvrnutiPresjek(Tip1 p1,Tip1 p2,Tip2 p3,Tip2 p4) ->std::vector<std::vector<typename std::remove_reference<decltype (*p1)>::type>>{
    std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> matrica;
    Tip2 temp=p3;
    
    while(p1!=p2){
        while(p3!=p4){
            if(*p1==*p3) matrica.push_back({*p1,0,0});
            p3++;
        }
        p3=temp;
        p1++;
        
    }
    std::sort(matrica.begin(),matrica.end(),[](std::vector<typename std::remove_reference<decltype(*p1)>::type> vektor1,std::vector<typename std::remove_reference<decltype(*p1)>::type> vektor2){
        if(vektor1[0]>vektor2[0]) return false;
        else if(vektor1[0]==vektor2[0]) return true;
        return true;
    });

return matrica;}

template <typename Tip1, typename Tip2>

auto UvrnutaRazlika(Tip1 p1, Tip1 p2, Tip2 p3, Tip2 p4)->std::vector<std::vector<typename std::remove_reference<decltype (*p1)>::type>>{
    std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>> matrica;
    Tip2 temp=p3;
    int brojacprvogdeka(0);
    int brojacdrugogdeka(0);
    Tip1 tempa=p1;
    Tip1 pomocni1=p1;
    Tip1 pomocni2=p2;
    Tip2 pomocni3=p3;
    Tip2 pomocni4=p4;
    while(pomocni1!=pomocni2) {brojacprvogdeka++; pomocni1++;}
    while(pomocni3!=pomocni4) {brojacdrugogdeka++; pomocni3++;}
    Tip1 s1=p1;
    Tip1 s2=p2;
    Tip2 s3=p3;
    Tip2 s4=p4;
    int brojac(0);
    // (1,2,3) (2,4,3,5)
    while(p1!=p2){
        while(p3!=p4){
            if(*p1!=*p3) brojac++;
            p3++;
        }
        if(brojac==brojacdrugogdeka) matrica.push_back({*p1,0});
        brojac=0;
        p3=temp;
        p1++;
    }
    brojac=0;
    while(s3!=s4){
        while(s1!=s2){
            if(*s3!=*s1) brojac++;
            s1++;
        }
        if(brojac==brojacprvogdeka) matrica.push_back({*s3,0});
        brojac=0;
        s1=tempa;
        s3++;
    }
    std::sort(matrica.begin(),matrica.end(),[](std::vector<typename std::remove_reference<decltype (*p1)>::type>vektor1, std::vector<typename std::remove_reference<decltype (*p1)>::type> vektor2){
        if(vektor1[0]<vektor2[0]) return false;
        else if(vektor1[0]==vektor2[0]) return true;
        return true;
    });
    return matrica;
}



int main ()
{
    int broj1,broj2;
    std::cout<<"Unesite broj elemenata prvog kontejnera: ";
    std::cin>>broj1;
    std::deque<long long int> dek1;
    std::cout<<"Unesite elemente prvog kontejnera: ";
    for(int i(0);i<broj1;i++){
        long long int brojara;
        std::cin>>brojara;
        bool ponavljanje(false);
        auto pok1=dek1.begin();
        auto pok2=dek1.end();
        while(pok1!=pok2){
            if(*pok1==brojara) ponavljanje=true;
            pok1++;
        }
        if(ponavljanje==true){
            i--;}
        else dek1.push_back(brojara);
    }
    std::cout<<"Unesite broj elemenata drugog kontejnera: ";
    std::cin>>broj2;
    std::deque<long long int> dek2;
    std::cout<<"Unesite elemente drugog kontejnera: ";
    for(int i(0);i<broj2;i++){
        long long int brojara;
        std::cin>>brojara;
        bool ponavljanje(false);
        auto pok1=dek2.begin();
        auto pok2=dek2.end();
        while(pok1!=pok2){
            if(*pok1==brojara) ponavljanje=true;
            pok1++;
        }
        if(ponavljanje==true) {
            i--;}
        
        else dek2.push_back(brojara);
    }
    std::cout<<"Uvrnuti presjek kontejnera:"<<std::endl;
    auto matrica=UvrnutiPresjek(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),SumaCifara);
    for(int i(0);i<matrica.size();i++){
        for(int j(0);j<3;j++){
            std::cout<<std::setw(6)<<matrica[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"Uvrnuta razlika kontejnera:"<<std::endl;
    auto matrica2=UvrnutaRazlika(dek1.begin(),dek1.end(),dek2.begin(),dek2.end(),BrojProstihFaktora);
	for(int i(0);i<matrica2.size();i++){
	    for(int j(0);j<2;j++){
	        std::cout<<std::setw(6)<<matrica2[i][j]<<" ";
	    }
	    std::cout<<std::endl;
	}
	std::cout<<"Dovidjenja!";
	return 0;
}



