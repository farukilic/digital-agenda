#define _CRT_SECURE_NO_WARNINGS
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
	string telefon_numarası;
	string kayıt_zamanı;
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

	cout << "Numaranızı giriniz:(Başına '0' koymayınız.)\n";
	getline(cin, user.telefon_numarası);
	cin >> user.telefon_numarası;
	while (user.telefon_numarası.size() != 10) {
		cout << "Yanlış girdiniz. Tekrar giriniz:";
		cin >> user.telefon_numarası;
	}

	//Alttaki kod kullanıcının ne zaman kayıt olduğu verisini tutuyor.
	user.kayıt_zamanı = asctime(tarih);


	//ofstream dosya("Veri.txt", ios::app);
	//Üstteki kod her bir giriş bilgilerini tek tek dosyaya kaydediyor. Hiçbir giriş kaybolmuyor.
	ofstream dosya("Admin_Information.txt");
	//Bir üst satırdaki kod ise geçici olarak giriş bilgilerini tutuyor.
	dosya << user.kullanici_adi << "\n" << user.isim << "\n" << user.soyisim << "\n" << user.sifre << "\n" << user.yas << "\n" << user.telefon_numarası << "\n" << user.kayıt_zamanı << "\n";
	/*Alttaki gibi ayrı da yazılabilir ama o zaman txt dosyasına alt alta yazılmıyor.Belki bir yolu vardır ama bulamadım.
	dosya << user.isim;
	dosya << user.soyisim;
	dosya << user.sifre;
	dosya << user.yas;
	dosya << user.telefon_numarası;
	dosya << user.kayıt_zamanı;*/
	dosya.close();
	//Aşağı kodun amacı: ifstream dosyayı okuyor. Daha sonra liste oluşturuyoruz. Listeye aldığımız verileri kaydediyoruz.
	ifstream dosya_if("Admin_Information.txt");
	list<string> Admin_bilgi;
	Admin_bilgi.push_back(user.kullanici_adi);
	Admin_bilgi.push_back(user.isim);
	Admin_bilgi.push_back(user.soyisim);
	Admin_bilgi.push_back(user.telefon_numarası);
	Admin_bilgi.push_back(user.kayıt_zamanı);
	Admin_bilgi.push_back(user.sifre);
	dosya_if.close();


	dosya_if.is_open();

	vector<string> dosya_if_vector;
	string satir;
	while (getline(dosya_if, satir)) {
		dosya_if_vector.push_back(satir);
	}




}