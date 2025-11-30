#include <windows.h> // Renkli yazi (SetConsoleTextAttribute) ve Sleep fonksiyonu icin gerekli
#include <stdio.h>   // Temel giris-cikis (printf, scanf) icin gerekli
#include <stdlib.h>  // Rastgele sayi (rand, srand) ve system komutlari icin gerekli
#include <ctype.h>   // Karakter islemleri (toupper) icin gerekli
#include <time.h>    // Zaman fonksiyonlari (time) icin gerekli, rastgelelik tohumu icin
#include <conio.h>   // Klavyeden tek tus okuma (getch) icin gerekli

int main()
{
    // Program her calistiginda farkli rastgele sayilar uretsin diye zamani "seed" (tohum) olarak kullaniyoruz.
    srand(time(NULL));

    // Oyun degiskenlerinin baslangic degerleri
    int saglik = 100;
    int enerji = 100;
    int yemek = 0;
    int siginak = 0; // 0: Yok, 1: Var
    int gun = 1;

    char komut;
    int i;
    char sifre;

    // --- OYUN DONGUSU BASLANGICI ---
    // do-while kullandik cunku oyun en az bir kere calismali ve sart saglandigi surece donmeli.
    do {
        system("cls"); // Konsol ekranini temizler, boylece yazilar ust uste binmez.
        
        // Kullaniciya komutlari goster
        printf("Komutlar: A=avlan, S=siginak, E=envanter, R=rehabilite, F=felaket, P=sifre, Y=yardim, X=cikis\n\n");
        
        // Yazi rengini 3 (Mavi tonu) yapar
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        printf("===============================================\n");
        printf("Gun=%d || Saglik=%d || Enerji=%d || Yemek=%d\n", gun, saglik, enerji, yemek);
        printf("===============================================\n\n");
        
        // Yazi rengini 6 (Sari) yapar
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        printf("Bir komut giriniz: ");
        
        // Rengi tekrar 7 (Beyaz/Varsayilan) yapar
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        scanf(" %c", &komut); // Kullanicidan komut harfini alir (bosluk birakarak yazdik ki enter karakterini yutmasin)
        komut = toupper(komut); // Girilen harf kucukse (a -> A) buyuge cevirir.

        printf("\n"); 

        // Girilen komuta gore islem secimi
        switch (komut) {
            
        case 'A': // AVLANMA DURUMU
            if (enerji > 15) { // Enerji kontrolu
                enerji -= 15; // Enerjiyi 15 azalt
                printf("Avlanmaya ciktiniz...\n\n");
                Sleep(1500); // Kullaniciyi 1.5 saniye (1500 ms) bekletir (Gerilim yaratmak icin)
                
                int sans = rand() % 100; // 0 ile 99 arasinda rastgele sayi uretir
                
                if (sans < 50) { // %50 sansla avlanma basarili
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); // Yesil renk
                    printf("Bir geyik avladiniz.\t");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Beyaz renk
                    yemek++; // Yemek sayisini artir
                    printf("Mevcut yemek: %d\n\n", yemek);
                    
                    // Avlanirken kaza gecirme ihtimali
                    int kazaSans = rand() % 100;
                    if (kazaSans < 20) { // %20 ihtimalle kaza
                        int hasar = (rand() % 5) + 5; // 5 ile 10 arasi hasar
                        saglik = saglik - hasar;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); // Kirmizi renk
                        printf("Avlanirken yuksek yerden duserek yaralandiniz. %d hasar aldiniz.\n", hasar);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
                    else if (kazaSans < 50) { // %30 ihtimalle saldiri (%20 ile %50 arasi)
                        int saldiriHasari = (rand() % 11) + 10;
                        saglik = saglik - saldiriHasari;
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                        printf("Yirtici bir hayvanin saldirisina ugradin. %d hasar aldin.\n", saldiriHasari);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
                    else { // Kaza yoksa
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                        printf("Temiz bi sekilde avlandin\n");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    }
                }
                else { // Avlanma basarisizsa
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("Yemek bulamadiniz.\n\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
            }
            else { // Yeterli enerji yoksa
                printf("Yeterli enerjiniz yok! 15 enerji lazim.\n\n");
            }
            break; // Switch'ten cik

        case 'S': // SIGINAK ARAMA
            if (siginak == 1) { // Zaten siginak varsa
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
                Sleep(1500); // Arama suresi efekti
                
                int sans = rand() % 100;
                if (sans < 50) { // %50 sansla bulunur
                    siginak = 1; // Siginak degiskenini 'var' (1) yap
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

        case 'E': // ENVANTER GOSTERME
            printf("Saglik: %d\n", saglik);
            printf("Enerji: %d\n", enerji);
            printf("Yemek: %d\n", yemek);
            // Ternary operator (? :) kullanarak kisa if-else yazimi: 1 ise "var", degilse "yok" yazar.
            printf("Siginak: %s\n", siginak == 1 ? "Var" : "Yok");
            break;

        case 'R': // DINLENME (REHABILITASYON)
            if (saglik < 100 || enerji < 100) { // Herhangi biri eksikse dinlen
                saglik += 50;
                enerji += 60;
                gun++; // Dinlenince 1 gun gecer

                // 100'u asmasini engellemek icin sinirlama
                if (saglik > 100) saglik = 100;
                if (enerji > 100) enerji = 100;

                printf("Uyuyorsunuz...\n\n");
                Sleep(2000); // Uyuma efekti
                printf("Uyudunuz ve dinlendiniz.\t");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                printf("+50 saglik ve +60 enerji kazandiniz\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                printf("Zaten gucunuz yerinde, dinlenmeye gerek yok.\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            break;

        case 'F': // FELAKET SENARYOSU
            printf("UYARI: Firtina yaklasiyor.\n");
            Sleep(2000);
            for (i = 1; i <= 3; i++) { // 3 dalga halinde hasar verir
                int hasar = rand() % 10 + 5;
                saglik -= hasar;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                printf("%d. defa dalga vurdu, %d hasar yediniz\n", i, hasar);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                
                if (saglik <= 0) break; // Olurse donguden cik
                else {
                    printf("Kalan Saglik: %d\n", saglik);
                    Sleep(1000); // Dalgadan sonra bekle
                }
            }
            break;

        case 'P': // SIFRE COZME OYUNU
            printf("Kilitli kapi var. Sifreyi cozmek ister misin?\t");
            do {
                printf("(Cozum icin 'K', Cikmak icin 'X'): ");
                scanf(" %c", &sifre);
                sifre = toupper(sifre);
                
                if (sifre == 'K') { // Dogru sifre
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                    printf("Sifre dogru! +10 enerji kazandiniz.\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    enerji += 10;
                    if (enerji > 100) enerji = 100;
                }
                else if (sifre != 'X') { // Yanlis ve cikis degilse
                    printf("HATALI SIFRE!\n");
                }
            // Dogru bilinene kadar veya X'e basana kadar doner
            } while (sifre != 'K' && sifre != 'X'); 
            break;

        case 'Y': // YARDIM CAGIRMA (OYUNU KAZANMA)
            printf("Radyo sinyali gonderiyosunuz...\n");
            Sleep(3000); // Gerilim icin uzun bekleme
            
            // "==" kullanilmali (Karsilastirma), "=" degil (Atama)
            if (siginak == 1 && yemek >= 5) { 
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                printf("***************************************************************\n");
                printf("Helikopter yolda! Yeterince yemeginiz ve siginaginiz var.\n");
                printf("****************************************************************\n\n");
                Sleep(2000);
                printf("TEBRIKLER!! - KURTARILDINIZ.\n\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                printf("Oyundan cikmak icin herhangi bir tusa basin...");
                getch(); // Kullanicinin tusa basmasini bekler
                return 0; // Programi basariyla sonlandirir
            }
            else {
                // Sartlar saglanmadiysa nedenini soyle
                if (siginak == 0) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("Yardim cagirmak icin bir SIGINAGA ihtiyaciniz var.\n");
                }
                if (yemek < 5) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                    printf("Yardim cagirmak icin stogunuzda en az 5 YEMEK olmasi gerek.\n");
                }
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            break;
            
        case 'X': // OYUNDAN CIKIS
            printf("Oyundan cikiliyor...\n");
            break;

        default: // GECERSIZ TUS
            printf("Gecersiz komut! Lutfen listeden bir harf secin.\n");
            break;
        }

        // Saglik 0 veya altina duserse oyun biter (Lose Condition)
        if (saglik <= 0) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("\n\nOLDUNUZ! Sagliginiz tukendi.\n");
            printf("GAME OVER\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            printf("Cikmak icin bir tusa basin...");
            getch();
            return 0;
        }

        // Dongu sonu: Ekranin hemen silinmemesi icin kullanici tusa basana kadar bekle
        if (komut != 'X') {
            printf("\nDevam etmek icin bir tusa basin...");
            getch(); // Klavyeden bir tusa basilmasini bekler
        }

    } while (komut != 'X'); // Komut 'X' olmadigi surece oyun doner

    return 0;
}
