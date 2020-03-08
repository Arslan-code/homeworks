// Hüseyin Ulaş arslan
// 08.03.2020
// bu kod girilen degerleri karmaşık sayıya cevirip oldugu gibi gosterir , toplar ,
// çıkarır ve böler
//
//


#include <iostream>
#include <string>

using namespace std;

class karmasikSayi {
    
    public:

    karmasikSayi() {

          gercek = 0;
          sanal = 0;
    }
    
   karmasikSayi(int x, int y) {

          gercek = x;
          sanal = y;
    }
    

 karmasikSayi(int i)
    : gercek(i), sanal(i) {}

 karmasikSayi(double i)
    : gercek(i), sanal(i) {}

void karmasikOlustur() {

if (sanal < 0)
    cout << gercek << "" << sanal << "i" << endl;

else if (sanal == 0)
    cout << gercek << endl;

else
    cout << gercek << "+" <<
      sanal << "i" << endl;
  }


  void setGercek(const int x) {
      gercek = x;
  }
  void setSanal(const int x) {
       sanal = x;
  }


  int getGercek() const{

      return gercek;
  }
  int getSanal() const {

      return sanal;
  }

   void topla(karmasikSayi &c) { // girilen iki degeri toplayıp karmasık sayıya çeviren fonksiyon

       int sonucGercek = gercek + c.gercek;
       int sonucSanal = sanal + c.sanal;

       if (sonucSanal < 0){
           cout << sonucGercek << "" << sonucSanal << "i" << endl;
           
           cout << sonucGercek<< "+" <<
           sonucSanal << "i" << endl;
        }
       else if (sonucSanal == 0)
           cout << sonucGercek << endl;
           
       else
       cout << sonucGercek<< "+" <<
       sonucSanal << "i" << endl;
   }


  void cıkarma(karmasikSayi &c) { // girilen iki degeri cıkarma işlemi yaparak karmaşık sayıya ceviren fonksiyon

      int sonucGercek = gercek - c.gercek;
      int sonucSanal = sanal - c.sanal;

      if (sonucSanal < 0)
          cout << sonucGercek << "" << sonucSanal << "i" << endl;

      else if (sonucSanal == 0)
          cout << sonucGercek << endl;

      else
          cout << sonucGercek << "+" <<
                   sonucSanal << "i" << endl;
      
  }


  void bol(karmasikSayi &c) {  // verilen iki degeri bolme işlemi yaparak karmaşık sayıya ceviren fonksiyon


      if (c.sanal == 0){  // kullanıcı bölene 0 girerse bolme gercekleştirilemez
          cout << "Boyle bir islem gerceklestirilemez tanimsizdir...";
      return;
      }
      double gercekt = gercek;
      double sanalt = sanal;
      double sonucGercek = gercekt / c.gercek;
      double sonucSanal = sanalt / c.sanal;

      if (sonucSanal > 0)
          cout << sonucGercek << "+" <<
          sonucSanal << "i" << endl;

      else if (sonucSanal == 0)
          cout << sonucGercek << endl;

      else
          cout << sonucGercek << "" << sonucSanal << "i" << endl;
      
  }



  private:  // değişkenleri gizledik

       int gercek;
       int sanal;

  };

  int main() {

      karmasikSayi t(2,3);  // fonkiyonlarımızı denedik burada
      karmasikSayi a(3,5);
      t.karmasikOlustur();
      a.topla(t);
      a.cıkarma(t);
      a.bol(t);
      
      return 0;
      
      }
  
  


  
