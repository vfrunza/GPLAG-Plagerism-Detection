#include <stdio.h>
/*
 Dat je neki niz prirodnih brojeva (uključujući nulu), na primjer:
	233, 38, 17777, 7737, 152
Ovaj niz možemo posmatrati kao neprekinuti niz cifara, npr:
	23338177777737152
Potrebno je u drugi niz upisati: cifru i koliko puta uzastopno se ta cifra nalazi u ovom neprekinutom nizu. Dakle, za primjer iznad drugi niz bi trebao glasiti:
	2 1 3 3 8 1 1 1 7 6 3 1 7 1 1 1 5 1 2 1
(cifra 2 se pojavljuje 1 put uzastopno, cifra 3 se pojavljuje 3 puta uzastopno itd.)

Potrebno je napisati program koji radi na sljedeći način: najprije se unosi veličina polaznog niza (max. 100 elemenata), a zatim i njegovi članovi (osigurati da se ponavlja unos ako korisnik proba unijeti neispravnu veličinu ili član koji nije prirodan broj ili nula). Zatim se na ekranu ispisuju članovi drugog niza razdvojeni znakom razmaka
*/
int main() {
    int niz[100], niz_cifara[1000], i=0, j=0, vel=0, vel2=0, brcfr=0, temp=0, brpojavljivanja=0;
    printf("Unesite velicinu: ");
    scanf("%d", &vel);
    printf("Unesite clanove niza: ");
    for(i=0; i<vel; i++) scanf("%d", &niz[i]);
    
    for(i=0; i<vel; i++) {
        brcfr=0;
        temp=niz[i];
        while(temp!=0) {
            brcfr++; temp/=10;
        }
        vel2+=brcfr; 
        for(j=vel2-1; j>=vel2-brcfr; j--) {
            niz_cifara[j]=niz[i]%10;
            niz[i]/=10;
        }
        
    }
    
    for(i=0; i<vel2; i+=2) { 
        brpojavljivanja=1;
        j=i+1;
        while(niz_cifara[i]==niz_cifara[j]) {brpojavljivanja++; j++;}
        if(brpojavljivanja==1) {
            for(j=vel2; j>i; j--) {
                niz_cifara[j]=niz_cifara[j-1];
            } niz_cifara[i+1]=brpojavljivanja; 
            vel2++;
        }
        else {
            for(j=i+2; j<vel2-1; j++) niz_cifara[j]=niz_cifara[j+brpojavljivanja-2];
            niz_cifara[i+1]=brpojavljivanja;
            vel2-=brpojavljivanja-2;
        }
    }
    for(i=0; i<vel2; i++) printf("%d ", niz_cifara[i]);
    
    return 0;
}