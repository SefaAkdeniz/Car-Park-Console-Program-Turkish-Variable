#include <stdio.h>
#include <stdlib.h>

struct Otopark
{
    char Plaka[50];
    char Model[50];
    char Renk[50];
    char Saat[50];
}arac[1000];

int AracEkle(int i)
{
    int j;
    char secim3[5];
    system("cls");
    printf("#### ARAC EKLEME ####\n\n");
    printf("ARACIN PLAKASINI GIRINIZ     ==> ");
    scanf("%s",&arac[i].Plaka);
    for (j=0;j<=i;j++){
        if(strcmp(arac[j].Plaka,arac[i].Plaka)==0){
            if (i==j){
                printf("ARACIN MODELINI GIRINIZ      ==> ");
                scanf("%s",&arac[i].Model);
                printf("ARACIN RENGINI GIRINIZ       ==> ");
                scanf("%s",&arac[i].Renk);
                printf("ARACIN GIRIS SAATINI GIRINIZ ==> ");
                scanf("%s",&arac[i].Saat);
                system("cls");
            }
            else{
                printf("\nARACIN ONCEDEN GIRILISI YAPILMISTIR.");
                printf("\nANA MENUYE DONMEK ICIN HER HANGI BIR TUSA BASINIZ ");
                scanf("%s",&secim3);
                return i;
            }
        }
    }
}

void AracListele(int i)
{
    system("cls");
    char secim2[5];
    int j;

    printf("#### OTOPARK ICINDEKI ARACLAR ####\n\n");
    for(j=0;j<=i;j++){
        printf("%d. ARAC PLAKASI: %s\n",j+1,arac[j].Plaka);
    }
    if (i==-1){
        printf("OTOPARKTA HENUZ ARAC YOKTUR.\n");
    }

    printf("\nANA MENUYE DONMEK ICIN HER HANGI BIR TUSA BASINIZ ");
    scanf("%s",&secim2);
}

int main()
{
    int secim;
    int aracSayi=0;
    char kontrol[10];
    int i;
    int test=0;
    char secim4[5];
    system("color a");
    while (1){
        system("cls");
        printf("###### AKDENIZ OTOPARK ######\n\n");
        printf("#### OTOPARK PROGRAMI ####\n\n");
        printf("[1] ARAC EKLE\n");
        printf("[2] ARACLARI LISTELE\n");
        printf("[3] ARAC SORGULAMA\n");
        printf("[4] ARAC CIKAR\n\n");
        printf("ISLEM NO GIRINIZ ==> ");
        scanf("%d",&secim);

        if (secim==1){
            aracSayi++;
            aracSayi=AracEkle(aracSayi-1);
        }
        if (secim==2){
            AracListele(aracSayi-1);
        }
        if (secim==3){
            system("cls");
            printf("#### ARAC SORGULAMA ####\n\n");
            printf("SORGULAMAK ISTEDIGINIZ ARACIN PLAKASINI GIRINIZ ==> ");
            scanf("%s",&kontrol);
            test=0;

            for (i=0;i<aracSayi;i++){
                    if(strcmp(arac[i].Plaka,kontrol)==0){
                        printf("\nARAC OTOPARKTA\n");
                        printf("ARAC %d NOLU PARK YERINE %s ZAMANINDA PARK OLMUSTUR.\n",i+1,arac[i].Saat);
                        test++;
                        printf("\nANA MENUYE DONMEK ICIN HER HANGI BIR TUSA BASINIZ ");
                        scanf("%s",&secim4);
                        break;
                    }
            }
            if (test==0){
                printf("\nARAC OTOPARKTA DEGIL\n");
                printf("\nANA MENUYE DONMEK ICIN HER HANGI BIR TUSA BASINIZ ");
                scanf("%s",&secim4);
            }

        }
        if (secim==4){
            system("cls");
            printf("#### ARAC CIKAR ####\n\n");
            printf("CIKARMAK ISTEDIGINIZ ARACIN PLAKASINI GIRINIZ ==> ");
            scanf("%s",&kontrol);
            test=0;

            for (i=0;i<aracSayi;i++){
                    if(strcmp(arac[i].Plaka,kontrol)==0){
                        test++;
                        for(i=i;i<=aracSayi;i++){
                            arac[i]=arac[i+1];
                        }
                        aracSayi--;
                        printf("\nARAC CIKISI YAPILMISTIR.\n");
                        printf("\nANA MENUYE DONMEK ICIN HER HANGI BIR TUSA BASINIZ ");
                        scanf("%s",&secim4);
                        break;
                    }
            }
            if (test==0){
                printf("\nARAC DAHA ONCEDEN CIKIS YAPMISTIR VEYA ONCEDEN GIRIS YAPMAMISTIR\n");
                printf("\nANA MENUYE DONMEK ICIN HER HANGI BIR TUSA BASINIZ ");
                scanf("%s",&secim4);
            }
        }
    }
}






