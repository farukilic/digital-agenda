#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <list>
#include <random>
#include <stdio.h>
#include <string>
#include <ctime>

/*
GEREKSİNİMLER:
-Kullanıcının girebileceği bilgiler: Görevler, notlar
-Arama ve filtreleme olmayacak
-Hatırlatıcı olacak
-Veriler dosyada tutulacak




*/
int main() {
	setlocale(LC_ALL,"Turkish");
	using namespace std;

	string baslik;
	string notlar;
	string aciklama;

	//Tarih tutma
	//Tarih tutarken çıkan hatayı engelliyor. Güvenlik açığı veriyor.
	time_t simdiki_zaman = time(nullptr);
	tm* tarih = localtime(&simdiki_zaman);
	cout << "Şu an: "; cout << asctime(tarih) << endl;

	//Giriş kısmında alınacak bilgiler(Kullanıcı arayüzü)
	string kullanici_adi;
	string isim;
	string soyisim;
	string sifre;
	int yas;

	




}