#include <stdio.h>
#include <stdlib.h>

int main()
{
    int M,N,yemekSayisi,i,j;
    printf("oyun alaninin eni ve boyu: ");
    scanf("%d %d",&M,&N);
    printf("yemek sayisini giriniz: ");
    scanf("%d",&yemekSayisi);
    while(yemekSayisi>N*M-1 || yemekSayisi<0)//yemek sayisi kontrolü
    {
        printf("Gecerli bir deger giriniz!\n");
        printf("yemek sayisini giriniz: ");
        scanf("%d",&yemekSayisi);
    }
    char oyunAlani[N][M],null='_';
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            oyunAlani[i][j]=null;
        }
    }
    int a=0,x,y;

    i=rand()%N;
    j=rand()%M;
    x=i;
    y=j;
    oyunAlani[x][y]='1';
    while(a<yemekSayisi)
    {
        i=rand()%N;
        j=rand()%M;
        if(oyunAlani[i][j]!='1' && oyunAlani[i][j]!='0')
        {
        oyunAlani[i][j]='0';
        a++;
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            printf(" %c ",oyunAlani[i][j]);
        }
        printf("\n");
    }
    int hamleSayisi=1,yilanBoyutu=1,alanDisiMi=0;
    char hamle;
    while(alanDisiMi==0 && yemekSayisi!=0) //komut istemi,komutlardan sonraki koordinatlardaki degisim
    {                                      //miktari,yilanin alan disindami kontrolü
        printf("HAMLE:");
        scanf(" %c",&hamle);
        int artis_i=0,artis_j=0;
        if(hamle=='U' || hamle=='u'){
           if(x-1<0){
                alanDisiMi=1;
           }else{
                artis_i=-1;
                hamleSayisi++;
            }
        }
        else if(hamle=='D' || hamle=='d'){
             if(x+1==M){
                alanDisiMi=1;
             }else{
                artis_i=1;
                hamleSayisi++;
              }
              }else if(hamle=='R' || hamle=='r'){
            if(y+1==N){
                alanDisiMi=1;
            }else{
                artis_j=1;
                hamleSayisi++;
             }
                    }
        else if(hamle=='L'|| hamle=='l'){
                if(y-1<0){
                    alanDisiMi=1;
                }else{
                    artis_j=-1;
                    hamleSayisi++;
                 }
             }else{ //istem disi komut uyarisi
         printf("lutfen gecerli komut giriniz!\n");
              }
        int yeni_i=x+artis_i,yeni_j=y+artis_j,yemYediMi=0;
        if(alanDisiMi==0){ //buyume kontrolu
            if(oyunAlani[yeni_i][yeni_j]=='0'){
                yemYediMi=1;
                yilanBoyutu++;
                yemekSayisi--;
            }
            if(yilanBoyutu==1){
                oyunAlani[x][y]=null;
                x=yeni_i;
                y=yeni_j;
                oyunAlani[x][y]='1';
            }else{
                int hareket_sayisi=1,onceki_i=x,onceki_y=y;
                x=yeni_i;
                y=yeni_j;
                oyunAlani[x][y]='1';
                while(hareket_sayisi!=yilanBoyutu){
                    if(yemYediMi==1 && yilanBoyutu -1 == hareket_sayisi){
                        oyunAlani[onceki_i][onceki_y]=yilanBoyutu+'0';//1'in onceki konumuna 2'yi atar
                        hareket_sayisi++;
                    }else{
                        hareket_sayisi++;
                        char aranacak=hareket_sayisi+'0';//hareket_sayisi int degerini char degere donusturur
                        if(oyunAlani[onceki_i-1][onceki_y]==aranacak){
                            oyunAlani[onceki_i][onceki_y]=oyunAlani[onceki_i-1][onceki_y];
                            if(yemYediMi==0 && yilanBoyutu == hareket_sayisi){
                                oyunAlani[onceki_i-1][onceki_y]=null;
                            }
                            onceki_i -=1;
                        }else if(oyunAlani[onceki_i+1][onceki_y]==aranacak){
                            oyunAlani[onceki_i][onceki_y]=oyunAlani[onceki_i+1][onceki_y];
                            if(yemYediMi==0 && yilanBoyutu == hareket_sayisi){
                                oyunAlani[onceki_i+1][onceki_y]=null;
                            }
                            onceki_i +=1;
                        }else if(oyunAlani[onceki_i][onceki_y-1]==aranacak){
                            oyunAlani[onceki_i][onceki_y]=oyunAlani[onceki_i][onceki_y-1];
                            if(yemYediMi==0 && yilanBoyutu == hareket_sayisi){
                                oyunAlani[onceki_i][onceki_y-1]=null;
                            }
                            onceki_y -=1;
                        }else if(oyunAlani[onceki_i][onceki_y+1]==aranacak){
                            oyunAlani[onceki_i][onceki_y]=oyunAlani[onceki_i][onceki_y+1];
                            if(yemYediMi==0 && yilanBoyutu == hareket_sayisi){
                                oyunAlani[onceki_i][onceki_y+1]=null;
                            }
                            onceki_y +=1;
                        }
                    }
                }
            }
        for(i=0;i<M;i++) // Oyun alanini yazdiriyor
        {
            for(j=0;j<N;j++)
            {
                printf(" %c ",oyunAlani[i][j]);
            }
            printf("\n");
        }
            printf("Hamle Sayisi: %d\n",hamleSayisi);
            if(yemekSayisi==0){
                printf("Tebrikler kazandiniz!");
            }
        }else{//alanDisiMi==1
            printf("Oyun Bitmistir!\n");
            printf("Yilan Buyuklugu: %d\n",yilanBoyutu);
            printf("Kalan Yemek Sayisi: %d\n",yemekSayisi);
        }
    }
  return 0;
}
