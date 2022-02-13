#include <stdio.h>
#define N 10 //ogrenci isim max karakter sayisi
#define M 3  //ogrencilerin not sayisi
#define S 5  //sinif mevcudu

// Gun(1-31) Ay(Ocak - Aralik) Yil(xxxx) seklindeki tarih bilgilerini tutmak icin bir struct tanimlayalim
typedef struct {
	int gun;
    char ay[7];
    int yil;
} tarih;

// Bir ogrencinin adini, dogum tarihini ve odevlerden aldigi M adet notu tutmak icin bir struct yapisi tanimlayalim
typedef struct {
	char isim[N];
    tarih dogum;
    int not[3];
} ogr;

// yazacagimiz fonksiyonlarin basliklari
tarih tarihiAl(void); // kullanicidan gerekli bilgileri alip bir tarih struct'ini dondurur
void tarihiAlPointer(tarih*); // alternatif
void tarihiBastir(tarih); // parametre olarak aldigi tarih struct'ini duzgun bir sekilde ekrana bastirir
ogr ogrBilgileriniAl(void); // kullanicidan gerekli bilgileri alip bir ogr struct'i dondurur
void ogrBilgileriniBastir(ogr); // parametre olarak aldigi ogr struct'ini duzgun bir sekilde ekrana bastirir
float ogrOrtalamasiHesapla(ogr); // parametre olarak aldigi ogr struct'indaki notlarin ortalamasini hesaplayip dondurur
float snfOrtalamasiHesapla(ogr snf[S], float agirlik[M]); // parametre olarak aldigi dizideki ogrencilerin notlarinin agirlik tablosunda verilen degerlere gore genel ortalamasini hesaplayip dondurur
float snfYasOrtalamasiHesapla(ogr snf[S]); // parametre olarak aldigi dizideki ogrencilerin yas ortalamasini hesaplayip dondurur

int main(void) {

	// ---------------- TARIH ----------------
	// tarih yapisinda bir degisken tanimlayalim
	tarih t;

	// tarihiAl fonksiyonunu cagirarak kullanicidan tarih alalim
	t = tarihiAl();

	// yazdigimiz fonksiyonu kullanarak bu tarihi ekrana bastiralim
	tarihiBastir(t);

	// M adet tarihi tutmak icin bir dizi tanimlayalim
	tarih dizi[M];

	// Dizinin ilk elemanina, elimizde mevcut olan tarih bilgisini atayalim
	dizi[0] = t;

	// Geri kalan elemanlari doldurmak i�in tarihiAl ile kullanicidan giris alalim
	for (int i = 1; i < M; i++)
    {
        dizi[i] = tarihiAl();
    }
    

	// Dizinin tum elemanlarini ekrana bastiralim
	for (int i = 0; i < M; i++)
    {
        printf("%d) %d / %s / %d\n", i+1, dizi[i].gun, dizi[i].ay, dizi[i].yil);
    }
    

	// ----------------- OGR -----------------
	// ogr yapisinda bir degisken tanimlayalim
	ogr abuziddin;

	// ogrBilgileriniAl fonksiyonunu cagirarak, icini dolduralim
	abuziddin = ogrBilgileriniAl();

	// bilgileri ekrana bastiralim
	ogrBilgileriniBastir(abuziddin);

	// ortalamasini ekrana bastiralim
    float abuziddinOrtalama = ogrOrtalamasiHesapla(abuziddin);

	// ----------------- SNF -----------------
	// S adet ogrenciden olusan bir sinifi temsil etmek icin bir dizi tanimlayalim
	ogr sinif[S];

	// Bu siniftaki ogrencilerin bilgilerini kullanicidan alalim
	for (int i = 0; i < S; i++)
    {
        sinif[i] = ogrBilgileriniAl();
    }
    

	float agirlik[M] = { 0.3, 0.3, 0.4 };
	// Ogrencilerin genel ortalamasini hesaplayan fonksiyonu cagirip sinifin ortalamasini bastiralim
	float notOrtalamasi = snfOrtalamasiHesapla(sinif, agirlik);
    printf("Ogrencilerin agirlikli genel not ortalamasi: %.2f\n", notOrtalamasi);

	// Sinifin yas ortalamasini ekrana bastiralim
	float yasOrtalamasi = snfYasOrtalamasiHesapla(sinif);
    printf("Ogrencilerin yas ortalamasi: %.2f\n", yasOrtalamasi);

	return 0;
}

// kullanicidan gerekli bilgileri alip bir tarih struct'ini dondurur
tarih tarihiAl(void) {
    tarih cikti;
	printf("Gun(1-31) Ay(Ocak - Aralik) Yil(xxxx) seklinde tarih bilgisi giriniz: ");
    scanf("%d%s%d", &cikti.gun, cikti.ay, &cikti.yil);
    return cikti;
}

// alternatif cozum
void tarihiAlPointer(tarih *t) {
    printf("Gun(1-31) Ay(Ocak - Aralik) Yil(xxxx) seklinde tarih bilgisi giriniz: ");
    scanf("%d%s%d", &((*t).gun), (*t).ay, &((*t).yil));
}

// parametre olarak aldigi tarih struct'ini duzgun bir sekilde ekrana bastirir
void tarihiBastir(tarih temp) {
    printf("Tarih: %d / %s / %d\n", temp.gun, temp.ay, temp.yil);
}

// kullanicidan gerekli bilgileri alip bir ogr struct'i dondurur
ogr ogrBilgileriniAl(void) {
    ogr cikti;
    tarih *t;
    printf("Ogrencinin ismini giriniz: ");
    scanf("%s", cikti.isim);
    tarihiAlPointer(t);
    printf("Ogrencinin odevlerden aldigi %d adet notu giriniz: \n", M);
    cikti.dogum = *t;
    for (int i = 0; i < M; i++)
    {
        printf("%d) ", i+1);
        scanf("%d", &cikti.not[i]);
    }
    return cikti;
}

// parametre olarak aldigi ogr struct'ini duzgun bir sekilde ekrana bastirir
void ogrBilgileriniBastir(ogr o) {
    printf("Ogrencinin ismi: %s, Dogum tarihi: %d/%s/%d, Odevlerden aldigi %d adet not: ", o.isim, o.dogum.gun, o.dogum.ay, o.dogum.yil, M);
    for (int i = 0; i < M; i++)
    {
        printf("%d ", o.not[i]);
    }
    printf("\n");
}

// parametre olarak aldigi ogr struct'indaki notlarin ortalamasini hesaplayip dondurur
float ogrOrtalamasiHesapla(ogr o) {
    float toplam = 0;
	for (int i = 0; i < M; i++)
    {
        toplam += o.not[i];
    }
    return (toplam / M);
}

// parametre olarak aldigi dizideki ogrencilerin notlarinin agirlik tablosunda verilen degerlere gore genel ortalamasini hesaplayip dondurur
float snfOrtalamasiHesapla(ogr snf[S], float agirlik[M]) {
    float toplam = 0;
	for (int i = 0; i < S; i++)
    {
        for (int n = 0; n < M; n++)
        {
            toplam += snf[i].not[n] * agirlik[n];
        }
    }
    return (toplam / (M * S));
}

// parametre olarak aldigi dizideki ogrencilerin yas ortalamasini hesaplayip dondurur
float snfYasOrtalamasiHesapla(ogr snf[S]) {
    float toplam = 0;
	for (int i = 0; i < S; i++)
    {
        toplam += 2021 - snf[i].dogum.yil;
    }
    return (toplam / S);
}