Zapoctovy priklad nanecisto
===========================
Vasim ukolem na cviceni bude vyzkouset si zapoctovy priklad, ktery probehne pristi tyden naostro.
Na vypracovani ukolu mate hodinu cisteho casu, muzete pouzivat veskerou dokumentaci, ci vlastni zdrojove soubory.

__Behem vypracovani nesmite komunikovat s zadnym zivym clovekem (s vyjimkou mne)__

##Zadani

Vasim ukolem je napsat program, ktery ze zadaneho souboru nacte jednoduchy binarni strom 
a na zaklade prepinace z prikazove radky vypise cely podstrom od uzlu  s nejvyssi nebo nejnizsi hodnotou.

V souboru budou uzly stromu ulozeny ve formatu ```Key=value```, kde:
* _key_ je oznaceni uzlu
* _value_ je hodnota ve formatu ```v;parent```
  * _v_ je celociselna hodnota
  * _parent_ je retezec oznacujici rodice prvku v binarnim strome
* kazda hodnota ```key:value``` je na samostatnem radku
* prvni zaznam je korenovy strom, tedy nema rodice (muzete spolehat ze prvni radek bude vzdy validni)
* Ukladate zleva doprava, tedy prvni nalezeny ulozite do leveho podstromu, druhy do praveho podstromu
* pokud se v souboru objevi treti potomek daneho uzlu, pouze vypisete chybovou hlasku a pokracujete dal
* prechozi plati i pro uzel s neexistujicim rodicem
* Program jako vystup vypise nalezeny node s jeho hodnotou a na radky pod nej bude vypisovat jeho potomky
  * Kazdy potomek bude odsazen dle urovne zanoreni od rodice, tedy primi potomci budou odsazeni jednim \t, 
  vsichni dalsi vice \t dle urovne odsazeni
  * Strom vypisujte do hloubky, tedy pro kazdy uzel nejprve jeho potomky, az potom sourozence.
* __Strom nemusi byt vyvazeny__
  
__Vas kod nebude automatizovane testovan, tedy pokud vam neco v zadani neni jasne, nebo vam prijde nedodefinovane,
muzete si chovani dodefinovat sami, dle vaseho vlastniho usudku__

Format vstupu
```
root=12
1level_left=15;root
1level_right=16;root
2level_left_1=10;1level_left
.
.
.
```

###Pozadavky
Vasim ukolem je
 1.  Vytvorit vhodnou reprezentaci pro uchovani stromu
 2.  Zpracovat cely vstupni soubor do vami vytvorene reprezentace
 3.  Po nacteni vyhledat uzel s nejnizsi/nejvyssi hodnotou a vypsat cely podstrom od tohoto vrcholu
 
####Ukazka
Pro vstup
```
root=12
l=15;root
r=17;root
ll=1;l
rl=2;r
lr=4;l
rr=7;r
rrr=8;rr
```

Pro spusteni ```$./myprog file.txt -m``` vypise:

```
Maximal node is: r, value: 17
Nodes under:
  rl: 2
  rr: 7
    rrr: 8
```
