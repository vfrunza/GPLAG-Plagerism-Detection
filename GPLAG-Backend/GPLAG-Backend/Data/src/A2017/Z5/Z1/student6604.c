#include <xc.h>

#pragma config FOSC=HS,WDTE=OFF,PWRTE=OFF,MCLRE=ON,CP=OFF,CPD=OFF,BOREN=OFF,CLKOUTEN=OFF
#pragma config IESO=OFF,FCMEN=OFF,WRT=OFF,VCAPEN=OFF,PLLEN=OFF,STVREN=OFF,LVP=OFF

#define _XTAL_FREQ 8000000

// Za 7-segmentni displej sa zajednickom katodom
//char cifre[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
// Za 7-segmentni displej sa zajednickom anodom
char cifre[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};

char brojac=0, uzlazna=0;

void main(void){
// Na PORTB ce biti ispisivani kodovi (radi provjere)
    TRISB=0x00;
    ANSELB=0x00;
    LATB=0x00;
    PORTB=0x00;

// Na PORTD je povezan 7-segmentni displej
    TRISD=0x00;
    TRISDbits.TRISD7=1;     // PD7 predstavlja brojacki ulaz
    ANSELD=0x00;
    LATD=0x00;
    PORTD=0x00;

    while(1) {
        if(PORTDbits.RD7){
            // Brojac treba brojati samo uzlazne ivice (promjenu sa 0 na 5 V)
            if(uzlazna==0){
                uzlazna=1;
                // 1. nacin realizacije brojaca do 9
                //brojac++;
                //if(brojac>9) brojac=0;
                // 2. nacin realizacije brojaca do 9
                brojac=brojac==9?0:brojac+1;
            }
        } else
            uzlazna=0;
        PORTD=cifre[brojac];
        PORTB=cifre[brojac];
        // Da bi se izbjeglo visestruko odbrojavanje, uvescemo kasnjenje
        __delay_ms(500);
    }
}