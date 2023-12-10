#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	//öncelikle alfabeyi ve metni char deðiþkeni ile tanýmladým.Anahtarý da tanýmlayarak deðerini verdim.
	char alfabe[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char metin[100];
	int key=3;
	
	//Þifrelenecek cümleyi kullanýcýdan istedim ve gets ile yazmasýný bekledim.
	
	printf("Sifrelenecek cumleyi yaziniz:");
	gets(metin);
	
	//strlen ile metnin uzunluðunu ölçtüm,metni 100 elemanlý tanýmladýðým için eðer 100'den fazla olursa uyarmasýný saðladým.
	
	if(strlen(metin)>100)
	{
		printf("Cumleniz cok uzun!");
	}
	//i metindeki bir karakter ve her karakterde döngü sýfýrlansýn diye bir iþaretçi tanýmladým ve 0 deðerini verdim
	
	else
	{
		for(int i=0; i<strlen(metin);i++)
		{
			int isaretci=0;
				//isalpha fonksiyonu ile yazýlan karakterin harf olup olmadýðýný kontrol ettim eðer harfse bu blok çalýþacak
				
				if (isalpha(metin[i]))
				{
					//j tanýmladým for ile metindeki karakterlerin sýrayla alfabenin içindeki harflerden birine denk gelip gelmediðini kontrol ettim
					//tolower ile yazýlan karakter büyük de olsa küçük olmasýný saðladým
					
					for(int j=0 ; j<26 ; j++)
					{
						if(alfabe[j]==tolower(metin[i]))
						{
							//anahtara 3 deðerini vermiþtim burada ise karakterin 3 ilerisindeki karakter olmasýný saðladým
							printf("%c", alfabe[(j+key+26)%26]);
							isaretci=1;
							//iþaretçi deðeri 1 olduðunda ise döngünün durmasý iin break ekledim
							break;
						}	
					}
				}
				//eðer yazýlan karakter harf deðilse de isdigit ile rakam olup olmadýðýný kontrol edecek ve uyarý verecek döngü kýrýlacak
				
				else if(isdigit(metin[i]))
				{
					printf("Girilen karakter bir rakamdir!\n");
					break;
				}
				else
				
				//son olarak ekranda anahtar ile her karakterin 3 ileri atýldýðý þifrelenmiþ metin yer alacak
				
				{
					printf("%c",metin[i]);
				}
		}
	}
	return 0;

}

