Zadání zápočtového příkladu naostro
===================================

__Skupina:__ pb071/17

__Datum:__ 19. 05. 2016 16:00 CEST

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

## Statistické výpočty

### Představení úkolu
Vaším úkolem je vytvořit spustitelný program, který bude schopný  načíst statistický soubor a na základě přijatých
dat vypočítat základní statistické veličiny pro položky v daném souboru:

* medián
* aritmetický průměr
* Horní a dolní kvartil
* Rozptyl
* Směrodatnou odchylku

### Formát vstupu
Vstupem pro váš program nechť je soubor, který obsahuje na každém řádku samostatné měření, tedy množinu výsledků pokusu.

Formát:  ```Jméno měření;val1,val2,...,valN\n```

Kde:

* Jméno měření je jednoznačný identifikátor souboru dat (míněno statisticky) -- string
* val1-valN jsou jednotlivé hodnoty měření -- celá nezáporná čísla

Počet řádků v souboru není nijak omezen, můžete předpokládat, že řádek nebude delší než __4096 znaků__

### Formát výstupu
Pro každý statistický soubor (řádek v reálném souboru) vypíše váš program na standardní výstup řádek

```
Metriky pro ${Jméno měření}: Q.5=${medián},E=${průměr},Q.25=${dolní kvartil},Q.75=${horní kvartil},D=${rozptyl},S=${směrodatná odchylka}
```

#### Vzorce pro výpočet
Pro další výpočty nechť A označuje vzestupně uspořádané pole celých čísel, potom:

* Aritmetický průměr E(A) = ```SUM(A)/LEN(A)```
* Medián Q.5(A) = ```A[LEN(A)/2]``` pro soubor o lichém počtu prvků jinak ```(A[LEN(A)/2] + A[LEN(A)/2 + 1])/2```
(počítáme s indexováním od 0 jinak třeba zaokrouhlit nahoru)
* Horní kvartil Q.25(A) = ```A[LEN(A)/4]``` (počítáme s indexováním od 0 jinak třeba zaokrouhlit nahoru)
* Dolní kvartil Q.75 = ```A[3*LEN(A)/4]``` (počítáme s indexováním od 0 jinak třeba zaokrouhlit nahoru)
* Rozptyl D(A) = ```sum(map(lambda u: (u - E(A))**2,A))/len(A) # zapis v pythonu```
* Směrodatná odchylka S(A) = SQRT(D(A))

### Požadavky na program
* Program získá z příkazové řádky cestu k souboru, který má otevřít
* Pokud se programu nepodaří soubor otevřít nebo získá nevalidní počet paramtetrů oznámí toto uživateli a korektně se ukončí
* Program následně postupně zpracuje soubor a vypíše zadané statistické veličiny
* Program musí korektně pracovat s pamětí a se soubory
* Pozor, medián a kvartily nelze vypočítat nad __Nesetříděným polem!!!__

#### Testovací data

Pro testování vašeho programu máte jako součást tohoto repozitáře soubor intput.txt, který obsahuje
počty medailí na Zimních/Letních olympijských hrách Česko(-)Slovenské [federativní] [socialistické] republiky, České republiky a Slovenské republiky.
Zdrojem těchto dat je česká wikipedie.
Pro tento vstup:
```
CR LOH medaile;11,8,9,6,10
SR LOH medaile;3,5,5,6,4
CSR LOH medaile;2,10,9,4,8,11,13,6,8,14,13,8,8,14,8,7
CR ZOH medaile;0,3,3,4,6,8
SR ZOH medaile;0,0,0,1,3,1
CSR ZOH medaile;0,1,0,0,1,0,0,1,1,4,3,1,1,6,3,3
```

By váš program měl vypsat následující výstup, viz output.txt

```
Metriky pro CR LOH medaile: Q.5=9.000000,E=8.800000,Q.25=8,Q.75=10,D=2.960000,S=1.720465
Metriky pro SK LOH medaile: Q.5=5.000000,E=4.600000,Q.25=4,Q.75=5,D=1.040000,S=1.019804
Metriky pro CSR LOH medaile: Q.5=8.000000,E=8.937500,Q.25=8,Q.75=13,D=11.183594,S=3.344188
Metriky pro CR ZOH medaile: Q.5=4.000000,E=4.000000,Q.25=3,Q.75=6,D=6.333333,S=2.516611
Metriky pro SK ZOH medaile: Q.5=1.000000,E=0.833333,Q.25=0,Q.75=1,D=1.138889,S=1.067187
Metriky pro CSR ZOH medaile: Q.5=1.000000,E=1.562500,Q.25=0,Q.75=3,D=2.871094,S=1.694430
```
