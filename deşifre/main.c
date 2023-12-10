#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(void) {
	//�ncelikle alfabeyi ve metni char de�i�keni ile tan�mlad�m.Anahtar� da tan�mlayarak de�erini verdim.
	char alfabe[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char metin[100];
	int key=3;
	
	//�ifrelenecek c�mleyi kullan�c�dan istedim ve gets ile yazmas�n� bekledim.
	
	printf("Sifrelenecek cumleyi yaziniz:");
	gets(metin);
	
	//strlen ile metnin uzunlu�unu �l�t�m,metni 100 elemanl� tan�mlad���m i�in e�er 100'den fazla olursa uyarmas�n� sa�lad�m.
	
	if(strlen(metin)>100)
	{
		printf("Cumleniz cok uzun!");
	}
	//i metindeki bir karakter ve her karakterde d�ng� s�f�rlans�n diye bir i�aret�i tan�mlad�m ve 0 de�erini verdim
	
	else
	{
		for(int i=0; i<strlen(metin);i++)
		{
			int isaretci=0;
				//isalpha fonksiyonu ile yaz�lan karakterin harf olup olmad���n� kontrol ettim e�er harfse bu blok �al��acak
				
				if (isalpha(metin[i]))
				{
					//j tan�mlad�m for ile metindeki karakterlerin s�rayla alfabenin i�indeki harflerden birine denk gelip gelmedi�ini kontrol ettim
					//tolower ile yaz�lan karakter b�y�k de olsa k���k olmas�n� sa�lad�m
					
					for(int j=0 ; j<26 ; j++)
					{
						if(alfabe[j]==tolower(metin[i]))
						{
							//anahtara 3 de�erini vermi�tim burada ise karakterin 3 ilerisindeki karakter olmas�n� sa�lad�m
							printf("%c", alfabe[(j+key+26)%26]);
							isaretci=1;
							//i�aret�i de�eri 1 oldu�unda ise d�ng�n�n durmas� iin break ekledim
							break;
						}	
					}
				}
				//e�er yaz�lan karakter harf de�ilse de isdigit ile rakam olup olmad���n� kontrol edecek ve uyar� verecek d�ng� k�r�lacak
				
				else if(isdigit(metin[i]))
				{
					printf("Girilen karakter bir rakamdir!\n");
					break;
				}
				else
				
				//son olarak ekranda anahtar ile her karakterin 3 ileri at�ld��� �ifrelenmi� metin yer alacak
				
				{
					printf("%c",metin[i]);
				}
		}
	}
	return 0;

}

