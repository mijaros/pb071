Zadání zápočtového příkladu nanecisto
===================================

* Zadáno 7. 5. 2019 16:15

### Požadavky:
* Čas na vypracování: _60 minut_
* Program půjde přeložit, nebudou v něm syntaktické chyby
* Máte povoleno používat online/offline dokumentaci
* Máte povoleno používat __VLASTNÍ!!__ kódy
  * Nikoliv kódy někoho jiného nebo referenční implementace
  * Výjimkou jsou ukázky kódu v dokumentaci
* Nesmíte používat žádnou formu komunikace, na jejímž druhém konci je entita, která projde [Turingovým testem](https://cs.wikipedia.org/wiki/Turing%C5%AFv_test)
* Dbejte na dobrou strukturu kódu
* Správným způsobem ošetřujte práci s pamětí a soubory

## Ziskani tajneho vstupu

Nejdříve budete muset získat tajný vstup. Pro jeho získání máte v této složce dva soubory

* libzap.a
* library.h

Pomocí těchto souborů vytvořte na aise program, který zavolá funkci get_your_message (viz níže)
s vaším učem a souborem do kterého chcete váš tajný vstup uložit.

Pro přeložení si nakopírujte soubory library.h a libzap.a na aisu a následně svůj program přeložte příkazem

```
gcc -o my_prog main.c libzap.a
```

A spusťte program `my_prog`. Následně si buď stáhněte vámi vyrobený soubor, nebo zkontrolujte svůj email.

Potom co budete hotovi, zavolejte druhou knihovní funkci ve vašem programu na aise s vaší tajnou zprávou (viz níže) a dovíte se, zda jste našli správnou zprávu, nebo ne.

## Steganografie

Steganografie je metoda skrývání komunikace do zpráv, o kterých třetí osoba neví, že jakoukoliv informaci obsahují.
Více o steganografii si můžete přečíst například [zde](https://cs.wikipedia.org/wiki/Steganografie).

Vaším úkolem bude vydolovat ukrytou zprávu v obrázku ve formátu bitmapy __(bmp)__. Formát je popsán přesně [zde](https://en.wikipedia.org/wiki/BMP_file_format),
nicméně pro tento úkol potřebujete pouze pár informací:

* Bitmapa, kterou budete prohledávat, má 24 bit pixel formát, tedy každý pixel je zakódovaný do 3 byte.
* Tajná zpráva je řetězec (pole znaků), jehož bity jsou kódovány do __nejméně významných bitů (LSB)__
* Tajná zpráva je zakončená koncovou nulou
* Hlavička bitmapy obsahuje informaci o offsetu od začátku souboru, kde se nachází samotné pixely
* Offset je číslo o délce 4B v kódování little endian, které se nachází v souboru s bitmapou od 10. byte dále (offset 10)
* Formát zprávy vám bude jasný, až jej uvidíte.

### Příklad bitmapy
```
0x4D42 0x1400 0x0000 0x0000 0x0000 	// Hlavicka, ktera nas nezajima
0x0E00 0x0000 				// 4B offset o hodnote 14 dekadicky
0x0001 0x0000 0x0000 0x0001 0x0000	// Pixelova data se zakodovanou zpravou "A" -> ['A','\0']
0x0000 0x0000 0x0000 
```

### Knihovna

Nyní je na snadě otázka, co vlastně budete prohledávat. K tomuto je vám dodána knihovna,
která vám dodá váš presonalizovaný obrázek a ověří váš výsledek.

```c
void get_your_message(const char * name, const char *file);
```

Funkce očekává na vstupu vaše UČO a výstupní soubor, do kterého uložíte bitmapu.
Funkce Vám pro jistotu pošle váš vstup i emailem na vaši učo adresu.

```c
int post_your_message(const char *message);
```

Funkce verifikuje vámi nalezenou zprávu a vrátí vám informaci, zda jste byli úspěšní.

Hodně štěstí při implementaci.
