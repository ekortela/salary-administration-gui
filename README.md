# salary-administration-gui
Graphical User Interface that allows user to save and administer personnel salaries with easy and understandable user interface.

Software Requirements

PERSONNELL MANAGEMENT APPLICATION

Your task is to design and implement a company personnel management
application. Design your application so that the UI part can be replaced easily. You
should make a simple graphical user interface without graphical user interface builders. 

User interface should contain only basic functionality to set and get relevant information 
(see tables below). You should also make a simple information structure, where employees can 
be added and stored. In the following section there is a description of the employee 
information that your application should be able to contain.

The company has different kinds of workers. The following table tells you what kind
of information you should save of each worker so that you would then be able to
print out all this information of all the saved workers at the same time (e.g. in the
form of a list).

Monthly paid employee Hourly paid employee Salesman
Name                            Name                                    Name
Social security number          Social security number 			Social security number
Monthly compensation            Hourly Compensation 			Monthly compensation
                                Done hours                              Bonus % 
                                                                        Realized outcome
                                                                        Outcome claim

The workers clearly differ from each other in the salary formation.

Employee                        Salary Formation
Monthly paid employee           Monthly compensation
Hourly paid employee            Done hours*hourly compensation
Salesman                        Monthly compensation raised by the bonus % if the 
                                outcome claim comes true

Based on this information you should make a class hierarchy or a data structures
for your company personnel management application. If you include extra
functionality in your application you should document them also.
You can fill up all relevant information that is missing with reasonable assumption.



TODO-lista

Koodausta:
    () GUI: Jos tyontekijaa on klikattu listalla, tallennetaan View:n muuttujaan tyontekijan SSN numero.
    (30%) GUI: Lisaa delete -napin funktionaalisuus
            Ohje:
            1. Jos delete nappia on painettu JA listasta on valittu on aktiivinen tyontekija
            2. Kysy kayttajalta varmistus poistetaanko tyontekija
            3. Poista tyontekija model-vektorista JA employeeList-vektorista
            4. Paivita tyontekijalista kutsumalla observerin handleEventRequestUpdate() metodia
            HUOM!! Vaatii IObserver -rajapinnalle kahden metodin implementoimista
    () GUI: Paatabi, jossa on vahintaan Save, Load, Help/About ja Exit valinnat. Save tallentaa
            mallin parametrit tekstitiedostoon, jotka ladataan automaattisesti GUI:n kaynnistyksessa!
    (20%) BACKEND: Unit testerit backendille QtTest frameworkilla
    (70%) BACKEND: Implementoi metodit tyontekijoiden parametrien asettamiseen controllerissa
    () BACKEND: Lisaa run-time lokitiedosto, johon kaikki qDebug/qCritical/qInfo viestit tallentuvat

Infrastruktuuri:
    () Muuta hakemiston rakenne selkeammaksi (esim. src/model/, src/controller/, src/main/, ...)
    () QT:n staattinen buildi: Yleensa ottaen on hyva, etta liittymaa voidaan ajaa standalonena. Tama
        vaatii allaolevan ohjeen seuraamista
        https://wiki.qt.io/Building_a_static_Qt_for_Windows_using_MinGW

Dokumentaatio:
    () Luo Use Case diagrammi dokumenttia varten (esim. EAP)
    () GUI:n dokumentaatio
    () Backendin dokumentaatio

Valmiit:
    (x) Luo ohjelmistoarkkitehtuurin UML class diagrammi
	(100%) GUI: Lisaa double click napin funktionaalisuus

Poistettu:
    (-) Staattinen CPPUTEST yksikkotestien ajamiseen meidan repositoryssa (kaytetaan QtTest frameworkkia)
