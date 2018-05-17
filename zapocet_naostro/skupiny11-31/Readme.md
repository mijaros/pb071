Zadání zápočtového příkladu naostro
===================================

* Zadáno 17. 5. 2018 16:00
* Skupiny 11, 31

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

## Maticová kalkulačka

Vaším úkolem bude naprogramovat jednoduchý program, který dokáže provést základní maticové operace.
Program bude akceptovat přepínače 
* `-p` vynásobí dvě matice
* `-s` sečtě dvě matice
* `-n [NUMBER]` vynásobí matici číslem
* `-t` transponuje matici
* `-i [FILE_NAME]` přidá vstupní soubor, může se opakovat
* `-o [OUT_FILE]` přidá výstupní soubor, smí být zadán právě jednou

Pravidla pro program jsou následující:
* pokud není předán parametr `-o`, potom se vypisuje na __standardní výstup__
* pokud je předán parametr `-p` nebo `-s`, potom musí být přepínač `-i` zadán předně dvakrát
* pokud je předán parametr `-t` nebo `-n` potom musí být přepínač `-i` právě jednou

### Formát souboru

Soubor popisující matici je poměrně jednoduchý, jedná se o textový soubor, který obsahuje bílými znaky oddělené čísla. Ukončení řádku znamená, že váš program obdržel řádek matice.
Všechna čísla jsou celá a zapsaná v dekadickém formátu.

Pokud narazíte na znak, který není bílý a nepopisuje číslo, potom je vstupní soubor nevalidní a váš program toto musí detekovat a validně se ukončit.
To stejné platí, pokud v souboru nebudou řádky stejné délky (ve smylu počtu čísel) i takovýto vstup musíte zamítnout.

### Požadavky

* Váš kód __MUSÍ__ používat dynamickou alokaci! protože nevíte jak velké matice vám budou předány
* Váš kód __MUSÍ__ ošetřovat chybové stavy, například situaci, kdy se neporaří otevřít libovolný soubor
* Můžete předpokládat, že validní matice z pohledu gramatiky jazyka budou validní i pro zvolenou operaci, například dimenze matic pro součin budou vždy kompatibilní.
