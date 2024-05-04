Zadání zápočtového příkladu nanecisto
===================================

* Zadáno 2024-05-07 18:00:00 CEST

### Požadavky:
* Čas na vypracování: _60 minut_
* Program půjde přeložit, nebudou v něm syntaktické chyby.
* Implementovat budete zde, na __fakultních počítáčích__.
  * Tedy své laptopy si můžete schovat.
* Máte povoleno používat offline dokumentaci a online dokumentaci jazyka C.
* Nesmíte používat žádnou formu komunikace, na jejímž druhém konci je entita, která projde [Turingovým testem](https://cs.wikipedia.org/wiki/Turing%C5%AFv_test)
* Dbejte na dobrou strukturu kódu.
* Správným způsobem ošetřujte práci s pamětí a soubory.

## Získání tajného vstupu

Nejdříve budete muset získat tajný vstup. Pro jeho získání máte v této složce tři soubory

* libzap.a
* library.h
* CMakeLists.txt

Pomocí těchto souborů vytvořte program (tak jak to již znáte), který zavolá funkci `get_your_message` (viz níže)
s vaším učem a souborem do kterého chcete váš tajný vstup uložit.

Následně dle postupu níže zpracujte soubor vytvořený funkcí `get_your_message`. Pokud byste měli nějaký problém, váš vstupní soubor
Vám po prvním úspěšném volání `get_your_message` přijde na mail. 

Potom co budete hotovi se zpracováním, zavolejte druhou knihovní funkci ve vašem programu na aise s vaší tajnou zprávou (viz níže) a dovíte se, zda jste našli správnou zprávu, nebo ne.

## Steganografie

Steganografie je metoda skrývání komunikace do zpráv, o kterých třetí osoba neví, že jakoukoliv informaci obsahují.
Více o steganografii si můžete přečíst například [zde](https://cs.wikipedia.org/wiki/Steganografie).

Vaším úkolem bude vydolovat ukrytou zprávu v obrázku ve formátu bitmapy __(bmp)__. Formát je popsán přesně [zde](https://en.wikipedia.org/wiki/BMP_file_format),
nicméně pro tento úkol potřebujete pouze pár informací:

* Bitmapa, kterou budete prohledávat, má 24 bit pixel formát, tedy každý pixel je zakódovaný do 3 byte.
* Tajná zpráva je řetězec (pole znaků), jehož bity jsou kódovány do __nejméně významných bitů (LSB)__ obrazových dat.
  * Každý pixel obsahuje 3 bity informace (jeden bit v každé barevné složce pixelu).
* Tajná zpráva je zakončená koncovou nulou.
* Hlavička bitmapy obsahuje informaci o offsetu od začátku souboru, kde se nachází samotné pixely.
* Offset je číslo o délce 4B v kódování little endian, které se nachází v souboru s bitmapou od 10. byte dále (offset 10).
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

* Funkce očekává na vstupu vaše UČO a výstupní soubor, do kterého uložíte bitmapu.
* Funkce Vám pro jistotu pošle váš vstup i emailem na vaši učo adresu.
* Pokud je soubor již stažen, vypíše na standardní chybový výstup hlášku a skončí.
* V případě, že je zavolána s nekorektním vstupem, který by mohl vést k selhání knihovny,
  funkce informuje o chybě a rovnou ukončí program.



```c
int post_your_message(const char *message);
```

* Funkce verifikuje vámi nalezenou zprávu a vrátí vám informaci, zda jste byli úspěšní.
* Pokud by vstup byl obzvláště špatný, informuje funkce uživatele o výrazně chybném vstupu,
  na standardní chybový výstup.


Hodně štěstí při implementaci.
