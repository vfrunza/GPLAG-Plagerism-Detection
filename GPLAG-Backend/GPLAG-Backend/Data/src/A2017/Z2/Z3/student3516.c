#include <iostream>
#include <cmath>

using namespace std;

void devedesetStepeni(int &a, int &b, int &c, int &d)
{
    int temp = a;
    a = b;
    b = c;
    c = d;
    d = temp;
}

int main()
{
    
    int A[100][100],
        B[100][100];
    int i, j, n, m;
    bool jednaki = true;
        
    do
    {
        cout << "Unesite velicinu niza A: ";
        cin >> n;
        
    }while(n <= 0 || n > 100);
    
    do
    {
        cout << "Unesite velicinu niza B: ";
        cin >> m;
        
    }while(m <= 0 || m > 100);
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < m; j++)
        {
            cin >> B[i][j];
        }
    }
            
    for(i = 0; i < n / 2; i++)
        for(j = 0; j < (n+1) / 2; j++)
            devedesetStepeni(A[i][j], A[n-1-j][i], A[n-1-i][n-1-j], A[j][n-1-i]);
        

    if(n != m) cout << "NE" << endl;
    else
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(A[i][j] != B[i][j])
                {
                    jednaki = false;
                    break;
                }
            }
            
        }
        
        if(!jednaki) cout << "NE" << endl;
        else cout << "DA" << endl;
    }
	
	
	return 0;
}