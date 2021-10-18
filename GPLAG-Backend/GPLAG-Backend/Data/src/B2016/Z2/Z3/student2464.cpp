#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;
using std::deque;

int SumaCifara(long long int a)
{
    int br=0;
    while(a!=0)
    {
        br+=abs(a%10);
        a/=10;
    }
    return br;
}

int SumaDjelilaca(long long int a)
{
    int br=0;
    for(long long int i=1;i<=abs(a);i++) if(abs(a)%i==0) br+=i;
    return br;
}

int BrojProstihFaktora(long long int a)
{
    int br=0;
    for (int i=2;i<=abs(a);i++)
    {
        if(abs(a)%i==0)
        {
            bool prost=true;
            for(int j=2;j<=std::sqrt(i);j++) if(i%j==0) prost=false;
            if(prost)
            {
                while(abs(a)%i==0)
                {
                    a/=i;
                    br++;
                }
            }
        }
        
    }
    return br;
}

int BrojSavrsenihDjelilaca(long long int a)
{
    int br=0;
    for(long long int i=6;i<=abs(a);i++)
    {
        if(a%i==0)
        {
            int s=0;
            for(int j=1;j<i;j++) if(i%j==0) s+=j;
            if(s==i) br++;
        }
    }
    return br;
}

template <typename tipp1, typename tipp2, typename tipfu, typename tipfr>
auto UvrnutiPresjek(tipp1 p1, tipp1 p2, tipp2 q1, tipp2 q2, tipfr f(tipfu)) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
{
    typedef typename std::remove_reference<decltype(*p1)>::type haos;
    vector<vector<haos>> mat;
    int k=0;
    while(p1!=p2)
    {
        tipfr c1=f(*p1);
        tipp2 q=q1;
        while(q!=q2)
        {
            tipfr c2=f(*q);
            if(c1==c2)
            {
                bool ima=false;
                for(int i=0;i<k;i++) if(*p1==mat[i][0] && *q==mat[i][1]) ima=true;
                if(!ima)
                {
                    mat.push_back(vector<haos>());
                    mat[k].push_back(*p1);
                    mat[k].push_back(*q);
                    mat[k].push_back(c1);
                    k++;
                }
            }
            q++;
        }
        p1++;
    }
    std::sort(mat.begin(), mat.end(), [](vector<haos> a, vector<haos> b)
    {
        if(a[2]!=b[2]) return a[2]<b[2];
        if(a[0]!=b[0]) return a[0]<b[0];
        else return a[1]<b[1];
    });
    return mat;
}

template <typename tipp1, typename tipp2>
auto UvrnutiPresjek(tipp1 p1, tipp1 p2, tipp2 q1, tipp2 q2) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
{
    typedef typename std::remove_reference<decltype(*p1)>::type haos;
    vector<vector<haos>> mat;
    int k=0;
    while(p1!=p2)
    {
        tipp2 q=q1;
        while(q!=q2)
        {
            if(*p1==*q)
            {
                bool ima=false;
                for(int i=0;i<k;i++) if(*p1==mat[i][0]) ima=true;
                if(!ima)
                {
                    mat.push_back(vector<haos>());
                    mat[k].push_back(*p1);
                    mat[k].push_back(0);
                    mat[k].push_back(0);
                    k++;
                }
            }
            q++;
        }
        p1++;
    }
    std::sort(mat.begin(), mat.end(), [](vector<haos> a, vector<haos> b)
    {
        return a[0]<b[0];
    });
    return mat;
}

template <typename tipp1, typename tipp2, typename tipfu, typename tipfr>
auto UvrnutaRazlika(tipp1 p1, tipp1 p2, tipp2 q1, tipp2 q2, tipfr f(tipfu)) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
{
    typedef typename std::remove_reference<decltype(*p1)>::type haos;
    vector<vector<haos>> mat;
    int k=0;
    tipp1 p=p1;
    while(p!=p2)
    {
        tipfr c1=f(*p);
        tipp2 q=q1;
        bool ima=false;
        while(q!=q2)
        {
            tipfr c2=f(*q);
            if(c1==c2) ima=true;
            q++;
        }
        if(!ima)
        {
            mat.push_back(vector<haos>());
            mat[k].push_back(*p);
            mat[k].push_back(c1);
            k++;
        }
        p++;
    }
    tipp2 q=q1;
    while(q!=q2)
    {
        tipfr c1=f(*q);
        tipp2 p=p1;
        bool ima=false;
        while(p!=p2)
        {
            tipfr c2=f(*p);
            if(c1==c2) ima=true;
            p++;
        }
        if(!ima)
        {
            mat.push_back(vector<haos>());
            mat[k].push_back(*q);
            mat[k].push_back(c1);
            k++;
        }
        q++;
    }
    std::sort(mat.begin(), mat.end(), [](vector<haos> a, vector<haos> b)
    {
        if(a[0]!=b[0]) return a[0]>b[0];
        return a[1]>b[1];
    });
    return mat;
}

template <typename tipp1, typename tipp2>
auto UvrnutaRazlika(tipp1 p1, tipp1 p2, tipp2 q1, tipp2 q2) -> typename std::vector<std::vector<typename std::remove_reference<decltype(*p1)>::type>>
{
    typedef typename std::remove_reference<decltype(*p1)>::type haos;
    vector<vector<haos>> mat;
    int k=0;
    tipp1 p=p1;
    while(p!=p2)
    {
        tipp2 q=q1;
        bool ima=false;
        while(q!=q2)
        {
            if(*p==*q) ima=true;
            q++;
        }
        if(!ima)
        {
            mat.push_back(vector<haos>());
            mat[k].push_back(*p);
            mat[k].push_back(0);
            k++;
        }
        p++;
    }
    tipp2 q=q1;
    while(q!=q2)
    {
        tipp2 p=p1;
        bool ima=false;
        while(p!=p2)
        {
            if(*p==*q) ima=true;
            p++;
        }
        if(!ima)
        {
            mat.push_back(vector<haos>());
            mat[k].push_back(*q);
            mat[k].push_back(0);
            k++;
        }
        q++;
    }
    std::sort(mat.begin(), mat.end(), [](vector<haos> a, vector<haos> b)
    {
        if(a[0]!=b[0]) return a[0]>b[0];
        return a[1]>b[1];
    });
    return mat;
}


int main ()
{
    int n;
    cout << "Unesite broj elemenata prvog kontejnera: ";
    cin >> n;
    deque<int> d1;
    cout << "Unesite elemente prvog kontejnera: ";
    int a;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        bool ima=false;
        for(int j=0;j<d1.size();j++) if(a==d1[j]) ima=true;
        if(!ima) d1.push_back(a); else i--;
    }
    cout << "Unesite broj elemenata drugog kontejnera: ";
    cin >> n;
    deque<int> d2;
    cout << "Unesite elemente drugog kontejnera: ";
    for(int i=0;i<n;i++)
    {
        cin >> a;
        bool ima=false;
        for(int j=0;j<d2.size();j++) if(a==d2[j]) ima=true;
        if(!ima) d2.push_back(a); else i--;
    }
    vector<vector<int>> up=UvrnutiPresjek(d1.begin(), d1.end(), d2.begin(), d2.end(), SumaCifara);
    cout << "Uvrnuti presjek kontejnera:\n";
    for(int i=0;i<up.size();i++)
    {
        for(int j=0;j<up[i].size();j++)
        {
            cout.width(6);
            cout << up[i][j] << " ";
        }
        cout << "\n";
    }
    vector<vector<int>> ur=UvrnutaRazlika(d1.begin(), d1.end(), d2.begin(), d2.end(), BrojProstihFaktora);
    cout << "Uvrnuta razlika kontejnera:\n";
    for(int i=0;i<ur.size();i++)
    {
        for(int j=0;j<ur[i].size();j++)
        {
            cout.width(6);
            cout << ur[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "Dovidjenja!\n";
	return 0;
}