#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 250  // ornek sayisi
#define C 5    // katsayi sayisi

// C adet katsayiyi tutmak icin bir tamsayi dizi, N adet x ve
// bunlara denk gelen y koordinatlarini tutmak icin ayri ayri iki
// double dizi ve bir de double hata alani iceren equation isimli
// bir yapi tanimlayalim
typedef struct {
	int coefficient[C];
	double abscissa[N];
	double ordinate[N];
	double error;
} equation;

// Fonksiyonlarin aciklamalari icin main'in altina bakiniz
equation newEquation(int c[C], double x[N]);
void computeY(equation *e);
double computeMSE(equation e1, equation e2);
equation equationGuesser(int c[C], equation e1);
equation realEquation(equation e1);


int main(int argc, char *argv[]) {

	// equation yapisinda bir degisken tanimlayalim
	equation real;

	// dosya yolu/adi komut satirindan girilen dosyadan x ve y
	// koordinatlarini okuyup, equation yapisindaki degiskenin x ve
	// y dizilerine kopyalayalim
	if (argc < 2)
	{
		printf("Insufficient arguments!");
		return 2;
	}
	
	FILE* data = fopen(argv[1], "r");
	if (!data)
	{
		printf("File not found!");
		return 1;
	}
	
	for (int i = 0; !feof(data) ; i++)
	{
		fscanf(data, "%lf,%lf\n", &real.abscissa[i], &real.ordinate[i]);
	}

	fclose(data);

	// her sey yolunda mi, bir kontrol edelim: struct'in x ve y
	// dizilerinin elemanlarini duzgun bir sekilde ekrana bastiralim

	for (int i = 0; i < N; i++)
	{
		printf("x: %lf, y: %lf\n", real.abscissa[i], real.ordinate[i]);
	}
	

	// asil hedefimiz, elimizdeki 4. dereceden denklemin
	// katsayilarini bulmak yani:
	// y = ax^4 + bx^3 + cx^2 + dx^1 + e denklemindeki a, b, c, d, e
	// tam sayilarinin degerlerini tahmin etmeye calisacagiz

	// kafadan bir deneme yaparak baslayalim, ilk denememiz
	// y = x^4 + x^3 + x^2 + x^1 + 1 olsun

	// equation tipinde bir yapi tanimlayalim ve newEquation
	// fonksiyonu ile katsayilar ve x dizilerinin ilk deger
	// atamasini yapalim

	int c0[C] = { 1, 1, 1, 1, 1 };
	equation guess = newEquation(c0, real.abscissa);

	// denklem katsayilarini ve x koordinatlarini kullanarak y'leri
	// hesaplayan computeY fonksiyonunu cagiralim

	computeY(&guess);

	// simdi elimde bir gercek y'ler (THE_eq) var bir de tahmin
	// ettigim y'ler (eq0) var, bunlari karsilastirip aralarindaki
	// farki olcmem lazim ki, tahmin ettigim y'lerin gercek y'lere
	// ne kadar benzedigini goreyim, bunun icin bir hata fonksiyonu
	// kullanacagiz: computeMSE

	// computeMSE'yi kullanarak uydurdugumuz denklemin hatasini
	// ekrana basalim ve struct icindeki mse degerini guncelleyelim

	guess.error = computeMSE(real, guess);
	printf("Tahmin ettigimiz denklemin MSE degeri: %lf\n", guess.error);

	// aslinda hedefimiz bu hata degerini minimize eden katsayilari
	// bulmak ama onu BONUS olarak size birakiyorum ve odevde sizden
	// sadece bir yakinsama calismasi yapmanizi istiyorum

	// yukaridaki islemleri asagidaki katsayilari kullanarak
	// tekrarlayin ve hangisinin THE denklemimizin katsayilarina
	// daha yakin oldugunu bulun

	int c1[C] = { 6, 7, 5, 8, 4 };
	int c2[C] = { 5, 3, 8, 7, 2 };
	int c3[C] = { 2, 9, 4, 7, 3 };
	int c4[C] = { 3, 3, 9, 8, 2 };
	int c5[C] = { 8, 7, 5, 1, 9 };

	// bu asamadan sonra kontrol sizde, programinizi istediginiz
	// gibi yazabilirsiniz

	equation cEq[5] = { equationGuesser(c1, real), equationGuesser(c2, real), equationGuesser(c3, real), equationGuesser(c4, real), equationGuesser(c5, real) };
	equation *min = cEq;
	for (equation* i = cEq; i < cEq + 5; i++)
	{
		if ((*min).error > (*i).error)
		{
			min = i;
		}
	}

	// Hangi set daha yakin? Cevabinizi asagiya yazin
	printf("Cevap: %ld.set\n", min - cEq + 1);

	// BONUS: Size verilen denklemin katsayilarini bulun
	equation realEq = realEquation(real);
	printf("Gercek denklemin katsayilari: ");
	for (int i = 0; i < C; i++)
	{
		printf("%d ", realEq.coefficient[i]);
	}
	
	return 0;
}

// Parametre olarak aldigi katsayi dizisi ve x koordinat dizilerini
// kullanarak equation yapisindaki bir degiskenin coeff ve x
// alanlarini doldurur (diger alanlara herhangi bir atama yapmaz) ve 
// bu yapida bir degisken dondurur
equation newEquation(int c[C], double x[N]) {
	equation guess;
	for (int i = 0; i < C; i++)
	{
		guess.coefficient[i] = c[i];
	}
	for (int i = 0; i < N; i++)
	{
		guess.abscissa[i] = x[i];
	}
	return guess;
}

// Parametre olarak aldigi equation yapisindaki degiskenin coeff ve
// x dizilerini kullanarak x koordinatlarina denk dusen y
// degerlerini hesaplar ve equation'daki y alanina yazar
void computeY(equation *e) {
	for (int i = 0; i < N; i++)
	{
		// C degeri degistirilerek istenilen derecede bir denkleme gore hesap yapabilecek bir fonksiyon yazmaya calistim
		(*e).ordinate[i] = 0.0;
		for (int n = C - 1, m = 0; n >= 0 && m < C; n--, m++)
		{
			(*e).ordinate[i] += pow((*e).abscissa[i], n) * (*e).coefficient[m];
		}
	}
}

// Parametre olarak aldigi iki equation yapisindaki degisken
// arasindaki ortalama kare hatayi hesaplayip dondurur
// e1 (gercek deger), e2 (tahmin)
double computeMSE(equation e1, equation e2) {
	double mse = 0.0;
	for (int i = 0; i < N; i++)
	{
		mse += pow((e1.ordinate[i] - e2.ordinate[i]), 2) / N;
	}
	return mse;
}


// Parametre olarak aldigi tam sayi katsayilari iceren bir diziyi 
// ve gercek deklemi kullanarak newEquation, computeY ve computeMSE
// fonksiyonlarini bir yerde toplayan bir fonksiyon
equation equationGuesser(int c[C], equation e1)
{
	equation result = newEquation(c, e1.abscissa);
	computeY(&result);
	result.error = computeMSE(e1, result);
	return result;
} 

// C tane katsayiya sahip bir denklemi tahmin ederken ilk olarak tum
// katsayilari sifira esitler. Sonra bu katsayilari yan yana koyarak bir
// tam sayi elde eder. Bu tam sayiyi bir arttirir ve her basamaktaki sayiyi
// sirayla katsayilar listesine geri yazar. Parametre olarak girdigimiz
// e1 (gercek denklem) ile MSE hesabi yapilir. MSE = 0 olana kadar bu islem 
// tekrar edilir. Aklima gelen en iyi yontem bu oldu ama sanirim pek verimli degil :( 
equation realEquation(equation e1)
{
	double number = 0.0;
	int c[C];
	for (int i = 0; i < C; i++)
	{
		c[i] = 0;
	}
	equation e2 = equationGuesser(c, e1);
	// Double ile kiyaslama olmadigindan dolayi MSE degerini 0.99 ile topladim ve toplami tam sayiya cevirdim.
	// While'in kosulunun 0 dondurmesi icin MSE degeri ancak ve ancak 0'in 0.01'lik voisinage'inda olmalidir. 
	while ((long long) (e2.error + 0.99) != 0)
	{
		for (int i = 0; i < C; i++)
		{
			number += c[i] * pow(10, C-i-1);
		}
		number++;
		for (int i = 0; i < C; i++)
		{
			c[i] = (int) (number / pow(10, C-i-1));
			number -= c[i] * pow(10, C-i-1);
		}
		e2 = equationGuesser(c, e1);
	}
	return e2;
}