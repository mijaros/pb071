Zadání zápočtového příkladu
===========================

##Podmínky
 * Čas na vypracování: _50 minut_
 * Povolené pomůcky:
   * _Dokumentace standardní knihovny_
   * _Vaše zdrojové kódy ze cvičení i domácích úkolů_
   * _Slidy z přednášek_
   * _Další libovolné dokumenty_
 * _Jakákoliv komunikace se živou osobou, nebo použití audiovizuální pomůcky je zakázáno_

##Zadání
Vaším úkolem je napsat spustitelný program, který níže popsaným způsobem zpracuje relační data, popisující
stav skladu materiálu.

Vstupními soubory pro Váš program nechť jsou dva soubory __items.csv__ a __movements.csv__
ve formátu [CSV - comma-separated values](http://cs.wikipedia.org/wiki/CSV).

_Items.csv_ informace o naskladněných položkách obsahuje:
  * identifikátor - celé nezáporné číslo, primární klíč v db
  * název produktu - řetězec, který neobsahuje čárrku či znak konce řádku
  * cena za jednotku - nezáporné celé číslo popisující cenu za prodej jednotky

_Movements.csv_ informace o pohybech ve skladu:
  * Identifikátor transakce - primární klíč tabulky
  * Identifikátor z tabulky items - cizí klíč
  * Datum pohybu
  * Objem pohybu, celé nenulové číslo
    * Záporné - prodej jednotek
    * Kladné - naskladnění jednotek


Váš program po spuštění vhodným způsobem rozparsuje vstupní soubory a vypočítá statistiku
po té vypíše současný stav skladu ve formátu

```
${id} - ${nazev polozky}: stav skladu ${soucasny objem} ${celková cena}
```
Celková cena je součin ceny položky a objemu položek

Na závěr váš program vypíše celkovou hodnotu skladu - tedy sumu veškerých cen ve formátu

```

---------------------
Celková cena: ${cena}
```


###Items.csv
```
0,bowl of petunias,42
1,Deep thought,10000000
2,Sperm Whale, 1200
```

###Movements.csv
```
0,1,1.1.2001,1
1,0,1.1.2001,10
2,2,1.1.2001,2
3,0,2.1.2001,-5
4,0,3.1.2001,50
5,0,3.1.2001,-24
6,2,5.1.2004,-1
7,0,7.1.2004,100
```

###Výstup

```
0 - bowl of petunias: 131 5502
1 - Deep thought:     1 10000000
2 - Sperm Whale, 1 1200

----------------------
Celkova cena: 10006702
```

