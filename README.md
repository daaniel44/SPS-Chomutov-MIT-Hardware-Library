## ÚVOD
- Toto je knihovna určena pro žáky na SPŠ Chomutov, ostatním je docela k ničemu :)
- __Slouží pouze pro inspiraci nebo pro experimentální užití, Já vím že to budeš kopírovat__
- knihovna obsahuje snad každý hardware dole v Laboratoři Mikroprocessorové techniky
- Pokud nějaký ještě chybí, pravděpodobně bude přidán, stejně neodmaturuju takže čas bude

- Knihovna bude upravována v průbehu, chyby a připomínky můžete dávat do Issues na githubu

## INSTALACE 
- __Doporuju používat Visual Studio Code__ projekt je nastavený pro použití platformio který umožňuje nahrávání do arduina přímo z VS code
- Použití VS Code
  - Nainstalovat Platformio Rozšíření
  - Stáhnout celý repozitář
  - __Červené řádky z terminálu zkopírovat do ChatGPT__
  - V levo v okně platformio tlačítko Upload
  - Platformio podporuje i sériový monitor
- Použití Arduino IDE / NIVOLAB
  - Stáhnout repozitář ale použít jen soubory ve složce src
  - do ```main.ino``` potom stačí jen ```#include "custom_avr.h"```
- upřímně nemám tušení zda to bude fungovat v NIVOLABU takže GL

## JAK POUŽÍVAT TUTO KNIHOVNU  
- Každý hardware má v konstruktoru typ konektoru, který představuje fyzické připojení na vývojovém Shieldu  
- Konstruktor automaticky nastaví adresy portů do interních proměnných.  

### POUŽÍVÁNÍ KONSTRUKTORŮ  
- Každý hardware je inicializován s typem konektoru.  
- PŘÍKLAD: ```muxLed *myLed = new muxLed(CON_1);``` – musí to být ukazatel (*myLed).  
- Každá funkce se volá pomocí ```->```.  
- PŘÍKLAD: ```myLed->show(1);```  

## POUŽÍVÁNÍ ```PortAddress``` V POTENCIÁLNĚ NOVÝCH TŘÍDÁCH  
- Namísto PORTx, DDRx, PINx se používá ```_SFR_IO8(portAddress)```.  
- ```portAddress``` ukládá adresu ```PORTx```, pro ```DDRx``` použijte ```portAddress - 1``` a pro ```PINx``` ```portAddress - 2```.  
