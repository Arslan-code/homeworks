// bu program kullanıcının istegine göre yıldızlarla ucgen ters ucgen veya ters ucgen sekli olusturur
// Bu kod Hüseyin Ulaş Arslan'a aittir
// 20.02.2020 tarihinde yazılmıştır


#include <iostream>
#include <stdlib.h>
using namespace std;
 void DuzUcgenBas(int girdi){ // Fonksiyonumuzu tanımladık
    
    for(int k=0;k<3;k++){
        cout << "Sayiyi girin\n";
           cin >> girdi;
        if(girdi<3||girdi>15||girdi%2==0){ // girdiği sayı istediğimiz sartları saglamıyor mu ona baktık
            if(k==2){ //eger ucuncu kez de saglamıyorsa programdan atalım
                exit(0);
            }
            cout<<"Lutfen gecerli gir deger giriniz!!\n";
            
            }
        else{
            k=3; // eger giridigi sayı sartları saglıyorsa yukarıdakı for dongusune bir daha girmesin diye yaptık
            
   
    int yildiz,bosluk;
    
    yildiz =1;
    bosluk= girdi/2; // bölü iki yapmamın sebebi bosluk bir integer deger oldugu için problem yasamayız
    
    
    for(int i=0;i<girdi/2+1;i++){
        for(int j=0;j<bosluk;j++){
            cout<<" ";
        }
        for(int j=0;j<yildiz;j++){
            cout <<"*";
        }
        cout<<"\n";
        bosluk--; // her satırda bir azalıyor
        yildiz +=2; // yıldız sayımız seklimiz uçgen oldugu için iki iki artıyor her satırda o yuzden bir ustteki for'a her satırda iki kere fazla girmesi gerekir
    }
        }

        }
}


void TersUcgenBas(int girdi){ // Fonksiyonumuzu tanımladık
    int m=0; // bazı dongu degıskenleri
    int n=0;
    
    
    
 while(m<3){
     
     cout << "Sayiyi girin\n";
        cin >> girdi;
     if(girdi<3||girdi>15||girdi%2==0){ // girdiği sayı istediğimiz sartları saglamıyor mu ona baktık
        
         if(m==2){ //eger ucuncu kez de saglamıyorsa programdan atalım
             exit(0);
         }
         m++;
         cout<<"Lutfen gecerli gir deger giriniz!!\n";
         }
     else{
         m=3; // eger giridigi sayı sartları saglıyorsa yukarıdakı while dongusune bir daha girmesin diye yaptık
         

 int yildiz,bosluk;
 
 yildiz =girdi; // baslangıcta yıldız sayısı kullanıcının girdiği sayıyla aynı olcak
 bosluk= 0; // baslangıcta hiç bosluk olmayacak
         
         
             while(n<girdi/2+1){ // dikkat ederseniz ortaya cıkacak sekilde satır sayısı girilen sayının yarısının integer sayıya göre yuvarlandıgının bir fazlası kadar satır var
                 int l=0;
                 while(l<bosluk){
                     cout<<" ";
                     l++;
                 }
                 int p=0;
                 while(p<yildiz){
                     cout <<"*";
                     p++;
                 }
                 cout<<"\n";
                 bosluk++; // her satırda bir artıyor
                 yildiz =yildiz-2;
                 // yıldız sayımız seklimiz ters uçgen oldugu için iki iki azalıyor her satırda o yuzden bir ustteki while'a her satırda iki kere az girmesi gerekir
                 n++;
             }
                 }

                 }
         }


    
int main(){
    
    int secim;
    cout << "1: Düz Üçgen, 2: Ters Üçgen, 0: Çıkış\n";
    cout<<"Lutfen yapmak istediginiz islemi secin\n";
    cin>>secim;
     int girdim; // fonksiyonu cagırmak icin kullanılan gereksiz bir seydi
    if (secim==2){
    TersUcgenBas(girdim); // fonksiyon cagrıldı
    }
    if (secim==1){
    DuzUcgenBas(girdim); // fonksiyon cagrıldı
    }
    if(secim==0){
        exit(0);
    }
    
        
    return 0;
}

