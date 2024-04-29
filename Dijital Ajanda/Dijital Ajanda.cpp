﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <list>
#include <random>
#include <stdio.h>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;
/*
GEREKSİNİMLER:
-Kullanıcının girebileceği bilgiler: Görevler, notlar
-Arama ve filtreleme olmayacak
-Hatırlatıcı olacak
-Veriler dosyada tutulacak

*/
struct User {
	string kullanici_adi;
	string isim;
	string soyisim;
	string sifre;
	int yas;
};

int main() {
	setlocale(LC_ALL, "Turkish");
	User user;

	//Tarih tutma
	time_t simdiki_zaman = time(nullptr);
	tm* tarih = localtime(&simdiki_zaman);
	cout << "Şu an: "; cout << asctime(tarih) << endl;

	//Giriş kısmında alınacak bilgiler(Kullanıcı arayüzü)

	cout << "8 ile 12 hane arasında bir kullanıcı adı belirleyiniz: \n";
	getline(cin, user.kullanici_adi);
	while (user.kullanici_adi.size() < 8 || user.kullanici_adi.size() > 12) {
		cout << "8 ile 12 hane arasında bir kullanıcı adı belirleyiniz: \n";
		getline(cin, user.kullanici_adi);
	}

	cout << "İsminizi giriniz: \n";
	getline(cin, user.isim);
	while (user.isim.size() < 2 || user.isim.size() > 14) {
		cout << "8 ile 12 hane arasında bir isim giriniz: \n";
		getline(cin, user.isim);
	}

	cout << "Soyisminizi giriniz: \n";
	getline(cin, user.soyisim);
	while (user.soyisim.size() < 1 || user.soyisim.size() > 14) {
		cout << "8 ile 12 hane arasında bir soyisim giriniz: \n";
		getline(cin, user.soyisim);
	}

	cout << "Şifre belirleyiniz: (8 ile 18 karakter arasında olmalı) \n";
	getline(cin, user.sifre);
	while (user.sifre.size() < 8 || user.sifre.size() > 18) {
		cout << "Şifre belirleyiniz : (8 ile 18 karakter arasında olmalı)  \n";
		getline(cin, user.sifre);
	}

	cout << "Yaşınız kaç: \n";
	cin >> user.yas;
	while ((13 < user.yas) && (user.yas > 120)) {
		cout << "Yaşınız uygun değildir! \n";
		cin >> user.yas;
	}
	ofstream dosya("Veri.txt");
	dosya << user.kullanici_adi;
	dosya << user.isim;
	dosya << user.soyisim;
	dosya << user.yas;
	dosya << user.sifre;
	dosya.close();

}
