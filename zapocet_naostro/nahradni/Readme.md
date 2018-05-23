Zadání zápočtového příkladu naostro
===================================

Příklad zadán: _tbd_

### Požadavky:

* Čas na vypracování: _60 minut_
* Program půjde přeložit, nebudou v něm syntaktické chyby
* Máte povoleno používat online/offline dokumentaci
* Nesmíte používat žádnou formu komunikace, na jejímž druhém konci je entita, která projde [Turingovým testem](https://cs.wikipedia.org/wiki/Turing%C5%AFv_test)
* Dbejte na dobrou strukturu kódu
* Správným způsobem ošetřujte práci s pamětí a soubory

## Plánovač procesů

Operační systém má jako jednu ze svých nezbytných komponent plánovač procesů, který je zodpovědný
za přidělování procesorového času jednotlivým procesorům. Existuje několik metod, jakým způsobem 
tento problém řešit, jedním z nejjednodušších je princip FCFS (first come first served), který ovšem
v případě moderních procesorů a současných programů nefunguje, kvůli počtu procesů a jejich
požadavkům.

Vaším úkolem bude implementovat jednoduchý plánovač s prioritní frontou, princip jeho fungování je
následující:

* Po určité časové okno procesor sbírá požadavky procesů na procesorový čas (v počtu taktů)
* Tyto požadavky po skončení časového okna převede do plánu dle zadané priority, který předá komponentě pro přidělování času
* Následně opět sbírá požadavky
* Priorita procesů je určena celým číslem, kde nižší číslo reprezentuje vyšší prioritu, například proces s prioritou `2` má výšší prioritu než proces s prioritou `10`
* Váš program bude simulovat situaci startu OS, tedy jeho spuštením začíná čas `0` na procesoru a s každým taktem se tento čas o `1` zvyšuje.

### Jak to bude fungovat

Váš program bude akceptovat právě jeden argument z příkazové řádky a to soubor s požadavky.
Soubor s požadavky má velice jednoduchý formát, jde o textový soubor, v němž jsou na jednotlivých
řádcích zapsány tyto požadavky ve formátu: 

```
PID PRI TIME
```

* `PID` identifikátor procesu - celé nezáporné číslo v rozmezí `<0; 1024>` 
* `PRI` priorita procesu - celé číslo v rozmezí `<-20; 20>`
* `TIME` doba o kterou proces žádá

Dále se v souboru objevuje řádek ve formátu: 

```
plan X
```

* `X` celé kladné číslo, které instruuje váš plánovač k provedení plánování `X` procesů ve frontě

Vaším úkolem je provést toto plánování procesů, na základě předaného souboru a po skončení vypsat na
na standardní výstup několik informací o procesech, které jste plánovali ve formátu

```
PID: CAS_PRVNIHO_BEHU, POCET_SPOTREBOVANYCH_TAKTU, CAS_OPUSTENI_PROCESORU
```

Kde:

* `PID` - identifikátor procesu (viz výše)
* `CAS_PRVNIHO_BEHU` - okamžik, kdy byl procesu poprvé přidělen procesorový čas
* `POCET_SPOTREBOVANYCH_TAKTU` - počet všech taktů procesoru které byly procesoru v rámci plánování přiděleny
* `CAS_OPUSTENI_PROCESORU` - poslední okamžik, kdy měl procesor přidělený procesorový čas

Čas prvního běhu a čas opuštění procesoru počítáme relativně vzhledem ke startu programu, tedy první proces, který bude naplánován bude mít čas prvního běhu roven `0`, druhý bude mít čas prvního běhu roven počtu taktů předchozího procesu.

Může se stát, že po přečtení souboru vám zůstanou ve frontě některé procesy, tyto procesy neplánujte.
Pokud by se tedy stalo, že některý proces se objeví poprvé ve frontě po skončení čtení souboru, nicméně nebude z fronty vybrán po vykonání posledního execute, nesmí být zahrnut do výsledného výpisu.

Můžete se spolehnout, že procesů nebude více než 1024, a můžete předpokládat, že soubor bude v korektním formátu.

### Příklad

```
1 -1 20
2 -3 10
1 -1 15
0 -20 10
plan 4
0 -20 15
1 -1 10
15 20 15568
0 -20 12
plan 2
1 -1 10
2 -3 10
plan 25
0 -10 25
2 -11 26
16 -10 42
plan 1
```

Pro výše zadaný vstup by váš program měl vypsat:

```
0: 0 37 81
1: 20 55 111
2: 10 46 15705
15: 112 15568 15679
```

### Co to je prioritní fronta?

Pokud si pamatujete ze cvičení strukturu fronty, tedy datovou strukturu FIFO, prioritní fornta pro 
vás nebude ničím zvlášť komplikovaným. Prioritní fronta, narozdíl od té normální, řadí prvky nejen 
na základě toho, kdy byly vloženy, ale i na základě nějakého přidaného kritéria, ktere určí jak brzy
či pozdě se má daný prvek zpracovat. Pokud se pokusíte prioritní frontu hledat na internetu, 
zjistíte, že doporučené způsoby implementace jsou pomocí hald (tedy binární, binomiální nebo 
fibonaciho). Těmto strukturám se radši vyhněte a použijte datovou strukturu, kterou znáte lépe 
a ve které jste si frontu implementovali na cvičeních, jen upravenou o hodnotící kritérium.
