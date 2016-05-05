Zadání zápočtového příkladu nanečisto
=====================================

Vaším úkolem  na tomto cvičení bude příprava na ostrý zápočtový příklad. Podmínky
pro vypracování budou stejné, podobně jako obtížnost úkolu, který vám bude zadán.

### Požadavky:
* Čas na vypracování: _60 minut_
* Program půjde přeložit, nebudou v něm syntaktické chyby
* Máte povoleno používat online/offline dokumentaci
* Máte povoleno používat __VLASTNÍ!!__ kódy
  * Nikoliv kódy někoho jiného nebo referenční implementace
  * Výjimkou jsou ukázky kódu v dokumentaci
* Nesmíte používat žádnou formu komunikace, na jejímž druhém konci je entita, která projde [Turingovým testem](https://cs.wikipedia.org/wiki/Turing%C5%AFv_test)

## Zadání
Vaším úkolem bude napsat jednoduchý parser výstupu příkazu `ps aux` dostupného v linuxových distribucích pro zobrazení současných běžících procesů.

### Formát výpisu
Výpis vypadá následovně:
```
USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
mjaros    1415  0.0  0.0  34100  4552 ?        Ss   11:46   0:00 /usr/lib/systemd/systemd --user
mjaros    1416  0.0  0.0 105884  2252 ?        S    11:46   0:00 (sd-pam)
mjaros    1426  0.0  0.0 353824 15012 ?        SLl  11:46   0:02 /usr/bin/gnome-keyring-daemon --daemonize --login
mjaros    1430  0.0  0.0 197300  5464 tty2     Ssl+ 11:46   0:00 /usr/lib/gdm/gdm-x-session --run-script gnome-session
mjaros    1432  1.8  1.0 706284 172536 tty2    Sl+  11:46   0:48 /usr/lib/xorg-server/Xorg vt2 -displayfd 3 -auth /run/user/1000/gdm/Xauthority -nolisten tcp -background none -noreset -keept
mjaros    1439  0.0  0.0 576220 13500 tty2     Sl+  11:46   0:00 /usr/lib/gnome-session/gnome-session-binary
```

__Kde:__
* __USER__ uživatel pod jehož uid proces běží
* __PID__ Id procesu
* __%CPU__ Kolik procent procesorového času proces využívá
* __%MEM__ Kolik procent z alokované paměti proces využívá
* __VSZ__  Celkový objem paměti dostupné pro proces
* __RSS__ Aktuální objem alokované paměti v RAM
* __TTY__ Terminál pod nímž proces běží
* __STAT__ Status procesu
* __START__ Čas startu procesu
* __TIME__ Celkový čas používání CPU ve formátu `[DD:]HH:MM`
* __COMMAND__ Příkaz, který proces spustil

Z této tabulky vás budou zajímat pouze sloupce
* USER
* PID
* %CPU
* %MEM
* TIME
* COMMAND

#### Poznámka k formátu
Sloupce výpisu jsou odděleny bílým znakem, s výjimkou sloupce command, do něj patří vše po znak konce řádku `'\n'` tedy rozparsování řádku
```
user 12 1.2 1.2 3325 1560 tty1 S 23:59 1:12 ps aux
```

Znamená:
* __USER__ = user
* __PID__ = 12
* __%CPU__ = 1.2
* __%MEM__ = 1.2
* __TIME__ = 72 minut
* __COMMAND__ = ps aux

### Požadavky na program
Vaším úkolem je vytvořit spustitelný program, který očekává na předem definovaný formát na standardním vstupu. Zároveň bude možné tento program spustit s přepínačem `-f FILE_NAME`. V tomto případě načítá váš program ze zadaného souboru.

__Můžete předpokládat, že vstup bude validní, nicméně defensivní programování bude oceněno!__

Po načtení a rozparsování vstupu do vhodné struktury následně vypíše tyto informace:
* PID a COMMAND s nejvyšším aktuálním vytížením procesoru
* PID a COMMAND s nejvyšším aktuálním vytížením paměti
* Statistiku uživatelů ve formátu:
  * `USERNAME: CPU=SUM(%CPU), MEM=SUM(%MEM),TIME=SUM(get_minutes(TIME))`

Kde
* SUM(%CPU) a SUM(%MEM) jsou součty jednotlivých sloupců pro daného uživatele
* SUM(get_minutes(TIME)) je součet všech hodnot ve sloupci TIME převedených na minuty pro daného uživatele.

__Na školních počítačích můžete svůj program otestovat následujícím příkazem:__

``` bash
$ ps aux | ./my_prog
```

### Poznámky
* Můžete předpokládat, že procentuální hodnoty (%MEM a %CPU) budou vždy obsahovat desetinnou tečku
* TIME je vždy ve formátu `HH:MM`
* První řádek vstupu je vždy hlavička, kterou nezpracovávátable
* Bílý znak který odděluje hodnoty nikdy není `'\n'`
* Řádek nepřesáhne délkou 2048 byte
* Váš program musí korektně pracovat s pamětí i se soubory!!.
