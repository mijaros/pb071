Zadání zápočtového příkladu nanečisto
===================================

* Zadáno __16. 5. 2017__
* Skupiny __11__ a __22__

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

## Kalkulačka v reverzní polské notaci

Vaším zadáním je naprogramovat kalkulačku která na vstupu bude mít výraz v [Polské reverzní notaci](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
který rozparsuje, validuje a vyhodnotí. Jako nechť váš program akceptuje soubor, ve kterém je na každém řádku jeden výraz.

### Popis formátu
_PRN_ je postfixová forma zápisu matematických výrazů s použítím zásobníku, kde:

* Pokud je na vstupu operand, uloží se na zásobník
* Pokud je na vstupu operátor, vyjme se ze zásobníku počet operandů odpovídajících aritě operátoru a uloží se výsledek
* Pokud je počet hodnot na zásobníku nižší než arita operátoru, nastává chyba - výraz není validní
* Na konci výpočtu je na zásobníku pouze jedna hodnota a ta je výsledkem
* Pokud je na konci na zásobníku více hodnot výraz není validní


__Ukázka:__
```
5 + 3 -> 5 3 +
4 * 3 - 2 -> 4 3 * 2 -
2 - 4 * 3 -> 2 4 3 * -
(2 - 4) * 3 -> 2 4 - 3 *
```

Poznámka:
Všimněte si, že operandy se aplikují v pořadí v němž jsou vkládány, tedy `5 3 -` znamená
* vyber hodnotu ze zásobníku a použij ji jako pravý operand
* vyber hodnotu ze zásobníku a použij ji jako levý operand
* odečti pravý operand od levého -> `5 - 3`

#### Operátory

V rámci úkolu implementujte následující operátory

| Operátor   |  arita    | operace   | Ukázka   |
| :--------: | --------- | --------- | -------- |
|  `+`       | binární   | Sečte dvě čísla na zásobníku | ` 5 3 + -> 8` |
|  `-`       | binární   | Odečte dvě čísla na zásobníku | ` 5 3 - -> 2` |
|  `*`       | binární   | Vynásobí dvě čísla na zásobníku | ` 5 3 * -> 15` |
|  `/`       | binární   | Vydělí dvě čísla na zásobníku | ` 5 3 / -> 1.666666` |
|  `%`       | binární   | Vypočítá zbytek po dělení čísel na zásobníku | ` 5 3 % -> 2` |
|  `^`       | binární   | Umocni čísla na zásobníku | `5 3 ^ -> 125` |
|  `!`       | unární    | Vypočítá faktoriál čísla na zásobníku | `5 ! -> 120` |
|  `M`       | binární   | Vrátí větší z hodnot | ` 5 3 M -> 5`|
|  `m`       | binární   | Vrátí menší z hodnot | ` 5 3 m -> 3` |
|  `s`       | _n_-ární  | Sečte všechna čísla na zásobníku | `5 3 4 2 1 s -> 15` |
|  `p`       | _n_-ární  | Vynásobí všechna čísla na zásobníku | `2 3 2 1 1 1 p -> 12 ` |

## Popis programu
Váš program nechť načítá vstup ze standardního vstupu, jeden výraz nechť je definován na jednom řádku.
Váš program načte řádek a vypočítá výsledek podle výše uvedených pravidel. Pokud výraz není validní, potom váš program vypíše chybu na standardní chybový výstup.

Váš program bude dále akceptovat následující přepínače z příkazové řádky:

* `-i` místo standardního vstupu, se použije soubor definovaný jako další argument
* `-o` místo standardního výstupu se použije soubor definovaný jako další argument
* `-e` místo standardního chybového výstupu se použije soubor definovaný jako další argument

### Ukázkový vstup
```
10 2 -
2 2 2 ^ ^
2 2 ^ 2 ^
100 12 2 ^ *
12 3 + 12 7 - /
2 4 8 16 32 p
2 1 2 + 3 + 4 + 5 + ^
2 4 8 16 32 s
2 1 2 5 ^ - 1 2 - / *
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 s
20 1 * 1 2 / 20 * 20 1 - * 1 * +
5 ! 2 3 + ! /
3 2 m 2 *
3 2 M 3 *
5 3 % 7 3 % + 3 %
2 1 2 5  - 1 2 - / *
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
Ahoj svete
```

### Výstup
```
8.0000
16.0000
16.0000
14400.0000
3.0000
32768.0000
32768.0000
62.0000
62.0000
210.0000
210.0000
1.0000
4.0000
9.0000
0.0000
Nevalidni vstup
Nevalidni vstup
Nevalidni vstup
```
