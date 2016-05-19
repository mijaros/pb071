Zadání zápočtového příkladu naostro
===================================

__Skupina:__ pb071/05

__Datum:__ 19. 05. 2016 18:00 CEST

Tento soubor obsahuje zadání pro ostrý zápočtový příklad, na základě jehož vypracování vám bude, či nebude udělen zápočet za cvičení.

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

## Key:value store
Vaším úkolem v tomto příkladu bude vytvořit spustitelný program, který rozparsuje soubor ve formátu key:value do paměti a následně vypíše
informace uložené v souboru

### Formát vstupu
Vstupní soubor bude obsahovat popis osob a jejich vztahy ve formatu
```
F1:Frantisek Novak
F1.birthDate:12.2.1984
Josef:Josef Novak
Josef.birthDate:12.2.1985
Karel:Karel Novotny
Karel.birthDate:12.2.1992
Karel.friend:Josef
F1.friend:Josef
Josef.friend:F1
Josef.friend:Karel
```

Kde:
* Pokud klíč neobsahuje znak ```'.'``` potom se jedná o klíč v tabulce, hodnota tohoto řádku je jméno osoby, klíč je zároveň id osoby
* Pokud klíč obsahuje znak ```'.'``` potom je hodnota vlastností klíče před . tedy _jméno.birthDate_ je datem narození osoby s id _jméno_
* Každá osoba má id, jméno, datum narození a 0-255 přátel

Můžete předpokládat, že klíč bude v souboru originální, délka řádku nepřesáhne __1024 znaků__

### Výstup programu
Váš program vypíše po zpracování vstupních dat vypíše na stdout informace o osobách a jejich vztazích ve formátu:

```
Josef Novak: Datum narozeni=12.2.1985 Pratele=(Frantisek Novak, Karel Novotny)
```

### Požadavky
* Program získá z příkazové řádky cestu k souboru, který má otevřít
* Pokud se programu nepodaří soubor otevřít nebo získá nevalidní počet paramtetrů oznámí toto uživateli a korektně se ukončí
* Program následně rozparsuje soubor do paměti a vypíše požadovaná data na stdout.
* Program musí korektně pracovat s pamětí a se soubory
* Pozor řádky v souboru nemusí být uspořádané! máte nicméně garantováno, že pokud je v souboru nějaký klíč potom jako první se v souboru vyskytne řádek s plným jménem a že v případě přátel je id přítele též definováno.
* Pozor přátelství není reciproční, tedy to, že A má za přítele B neznamená, že B má za přítele A.

#### Testovací data
Pro testování máte dodaný soubor input.txt (viz výše), pro tento input, by váš program měl vypsat následující text:
```
Frantisek Novak: Datum narozeni=12.2.1984 Pratele=(Josef Novak)
Josef Novak: Datum narozeni=12.2.1985 Pratele=(Frantisek Novak, Karel Novotny)
Karel Novotny: Datum narozeni=12.2.1992 Pratele=(Josef Novak)
```
