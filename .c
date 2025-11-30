#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
int main()
{
    srand(time(NULL));

    int saglik=100;
    int enerji=100;
    int yemek=0;
    int siginak=0;
    int gun=1;

    char komut;
    int i;
    char sifre;


    do{
    system("cls");
       printf("Komutlar:A=avlan,S=siginak,E=envanter,R=rehabilite,F=felaket,P=sifre,Y=yardim,X=cikis\n\n");
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);  printf("===============================================\n");
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3); printf("Gun=%d || Saglik=%d || Enerji=%d || Yemek=%d\n",gun,saglik,enerji,yemek);
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3); printf("==============================================\n\n");
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6); printf("Bir komut giriniz:");
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    scanf(" %c", &komut);
    komut=toupper(komut);
    switch(komut){
     case 'A':
         if(enerji>15){
            enerji-=15;
            printf("Avlanmaya ciktiniz...\n\n");
            Sleep(2000);
    int sans=rand()%100;
          if(sans<50){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);  printf("Bir geyik avladiniz.\t");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            yemek++;
            printf("mevcut yemek:%d\n\n",yemek);
            int kazaSans=rand() %100;
            if(kazaSans<20){
                int hasar=(rand()%5)+5;
                saglik=saglik-hasar;
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);   printf("Avlanirken yuksek yerden duserek yaralandiniz.\t");
                printf("%d hasar aldiniz.\n",hasar);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            }
             else if(kazaSans<50){
                int saldiriHasari=(rand()%11)+10;
                saglik=saglik-saldiriHasari;
              SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);  printf("Yirtici bir hayvanin saldirisina ugradin.\t");
                printf("%d hasar aldin.\n",saldiriHasari);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);

             }
              else{
               SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10); printf("Temiz bi sekilde avlandin\n");
               SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
              }



          }
             else{
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4); printf("Yemek bulamadiniz.\n\n");
              SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
             }
}
         else{
            printf("Yeterli enerjiniz yok 15 enerji lazim.\n\n");
         }
    break;



     case 'S':


    if (siginak == 1) {
        printf("Zaten guvenli bir siginaginiz var! Tekrar aramaniza gerek yok.\n\n");
    }

    else if (enerji < 20) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Yeterli enerjiniz yok! (Gereken: 20, Sizdeki: %d)\n", enerji);

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }

    else {
        enerji -= 20;

        printf("Siginak araniyor... (-20 enerji)\n");
         Sleep(2000);


        int sans = rand() % 100;


        if (sans < 50) {
            siginak = 1;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
            printf("TEBRIKLER! Guvenli bir siginak buldunuz.\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
        else {

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("Malesef bolgede uygun bir siginak bulunamadi.\n");

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
    }
    break;


     case 'E':
        printf("saglik:%d\n",saglik);
        printf("enerji:%d\n",enerji);
        printf("yemek:%d\n",yemek);
        printf("siginak:%s\n",siginak==1 ?"var" : "yok" );
        break;

     case 'R':
        if(saglik<100||enerji<100){
            saglik+=50;
            enerji+=60;
            gun++;

          if(saglik>100)
            saglik=100;
          if(enerji>100)
            enerji=100;
        printf("Uyuyorsunuz...\n\n");
        Sleep(2000);
        printf("Uyudunuz ve dinlendiniz.\t");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10); printf("+50 saglik  ve  +60 enerji kazandiniz\n");
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
        }
            else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);   printf("Zaten gucunuz yerinde,dinlenmeye gerek yok.\n");
             SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);}
         break;

     case 'F':
        printf("UYARI:Firtina yaklasiyor.\n"); Sleep(2000);
        for(i=1;i<=3;i++){
            int hasar =rand()%10+5;
            saglik-=hasar;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);    printf("%d. defa dalga vurdu,%d hasar yediniz\n",i,hasar);
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);    if(saglik<=0)break;
            else{
                printf("saglik:%d\n",saglik);}
        }
             break;

     case 'P':
         printf("Kilitli kapi var.Sifreyi cozmek ister misin\t");
         do{
            printf("(cozum'K',cikmak 'X'):");
            scanf(" %c", &sifre);
            sifre=toupper(sifre);
             if(sifre=='K'){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10); printf("sifre dogru,+10 enerji kazandiniz\n");
                 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                enerji+=10;
                if(enerji>100)
                    enerji=100;
             }
                else if(sifre!='K'){
                        printf("HATALI SIFRE");}

         }   while(sifre!='K'&&sifre!='X'); break;
     case 'Y':
          printf("Radyo sinyali gonderiyosunuz...\n");   Sleep(3000);
          if(siginak=1 && yemek>=5){
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);  printf("***************************************************************\n");
            printf("Helikopter yolda yeterince yemeginiz var helikopteri bekliyiniz.\n");
            printf("****************************************************************\n\n"); Sleep(2000);
            printf("TEBRIKLER!! - Kurtarildiniz.\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            printf("Oyundan cikmak icin herhangi bir tusa basin\n");
            getch();
            return 0;

          }
           else{
            if(siginak==0) {SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);printf("Yardim cagirmak icin bir siginaga ihtiyaciniz var.\n");}
            if(yemek<5){ SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);printf("Yardim cagirmak icin stogunuzda en az 5 yemek olmasi gerek.\n");}
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
           }  break;




    return 0;
}

















