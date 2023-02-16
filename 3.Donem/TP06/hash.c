#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#include"hash.h"
#define MULTIPLIER 29 

/* Stringler icin basit bir hash hesaplama fonksiyonu.
 * Her harfin ASCII degeri, onceki hash degerinin bir
 * carpanina ekleniyor.
 * Ornegin: "abcde" stringi icin:
 * ascii degerleri : a=97, b=98,c=99,d=100,e=101 
 *  h0 = 0 * 29 + 97 = 97
 *  h1 = h0 * 29 + 98 = 2911
 *  h2 = h1 * 29 + 99 = 84518
 *  h3 = h2 * 29 + 100 = 2451122
 *  h4 = h3 * 29 + 101 = 71082639
 *  71082639 % MAXBUCKETS (1000) = 639
 */
unsigned long hash_compute(const char *str){
  	// TODO: Yukaridaki aciklamalara gore fonksiyonu yazin
	int len = strlen(str);
	unsigned long hash = 0;
	for (int i = 0; i < len; i++)
	{
		hash = hash * MULTIPLIER + (int)str[i];
	}
	return hash % MAXBUCKETS;
}

/* Her elemani bir bagli liste gostericisi olan table
 * dizisi parametre olarak veriliyor. Bu table dizisi
 * aslinda hash veriyapisini temsil eder.
 *
 * str ile verilen string hash'te var ise adresi
 * dondurulur. Yoksa ve create == 1 ise, hash
 * veriyapisina bu string eklenir.
*/
Key* hash_lookup(Key **table,const char *str,int create){
	// TODO: str icin hash fonksiyonu cagirin 
	unsigned long index = hash_compute(str);
	// table hash tablosunda degeri arayin	
	// deger bulunursa o degiskeni geri dondurun.
	for (Key *i = table[index]; i != NULL; i = i->next)
	{
		if (strcmp(i->word, str)) continue;
		return i;
	}
	// deger yoksa ve ekleme yapilacaksa 
	if(create){
		Key* new = malloc(sizeof(Key));
		new->word = strdup(str);
		new->count= 0;
		new->next = table[index];
		table[index] = new;
		return new;
	}
	return NULL;
}


/* table ile verilen hash veriyapisini
 * isletim sistemine iade eden fonksiyon.
 * Temizlerken, her bagli listenin dugumlerini
 * ve bu dugumlerdeki "word" uyesini free()
 * etmeniz gerekiyor.
*/
void hash_free(Key **table){
  	// TODO
	for (int i = 0; i < MAXBUCKETS; i++)
	{
		Key* current = table[i];
		while (current)
		{
			Key* next = current->next;
			free(current->word);
			free(current);
			current = next;
		}
	}
	free(table);
}


/* count parametresi >= n olan kelimeleri ekrana
 * yazdiran fonksiyon. Ekrana yazdirirken
 * "%30s-->%5ld\n" formatini kullanin.
 * %ld: unsigned long icin gerekiyor.
*/
void hash_dump(Key **table,int n){
	// TODO 
	for (int i = 0; i < MAXBUCKETS; i++)
	{
		for (Key* j = table[i]; j != NULL; j = j->next)
		{
			if (j->count < n) continue;
			printf("%30s-->%5ld\n", j->word, j->count);
		}
	}
}
