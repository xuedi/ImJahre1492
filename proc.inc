'***************************************************************
'************************ Prozeduren ***************************
'***************************************************************

proc fehler1
	playsound "fehler.sou",1
	@messagebox("Die Bildschirmauflösung von Windows muß 640x480 mit eine Farbtiefe von mindesten 16 Bit (High-Color) betragen, um das Spiel zu starten!", "Auflösung oder Farbtiefe Fehler",0)
	playsound "klick.sou",0
	end
endproc

'************************* Fehler **********************************

fehler2:
proc fehler2
	@messagebox("Bitte wählen Sie eine Stadt aus, von der aus Sie das Spiel beginnen wollen!","Keine Anfangstadt angewählt",0)
	playsound "klick.sou",1
endproc

'********************* Spieler-namenseingabe  ********************

Proc CR_Menue
    parameters Para%
	loadbmp "Bilder/Menue2.bg",0,0;0
	temp%[8] = @createtext(%HWnd,"",200,88,232,288) ' 3328
	temp%[9] = @createedit(%HWnd,SpielerName$[Para%],208,120,216,24) ' 3332
	temp%[0] = @createbutton(%HWnd,"OK",320,328,104,32) ' 3336
	temp%[1] = @createradiobutton(%HWnd,"Hamburg",216,192,200,24) ' 3340
  	temp%[2] = @createradiobutton(%HWnd,"London",216,224,200,24) ' 3344
  	temp%[3] = @createradiobutton(%HWnd,"Madrid",216,256,200,24) ' 3348
  	temp%[4] = @createradiobutton(%HWnd,"Stockholm",216,288,200,24) ' 3352
	temp%[5] = @createtext(%HWnd,"Wo wollen Sie beginnen:",208,168,216,24) ' 3356
	temp%[6] = @createbutton(%HWnd,"Neuer Spieler",208,328,104,32) ' 3360
	temp%[7] = @createtext(%HWnd,"Bitte geben Sie Ihren Namen ein:",208,96,216,16) ' 3364
	'@setfocus(temp$[1])
endproc

'************************** Menü Löschen ****************************************
proc DT_Menue
	destroywindow(temp%[0])
	destroywindow(temp%[1])
	destroywindow(temp%[2])
	destroywindow(temp%[3])
	destroywindow(temp%[4])
	destroywindow(temp%[5])
	destroywindow(temp%[6])
  	destroywindow(temp%[7])
	destroywindow(temp%[8])
  	destroywindow(temp%[9])
endproc
proc WahleStadt
if Zeit% >= 1
    case @mouse(285,105-290,110): ret% = 0 'rom
    case @mouse(283,80-288,85): ret% = 1 'hamburg
    case @mouse(250,80-256,86): ret% = 2 'london
    case @mouse(250,112-255,117): ret% = 3 'madrid
    case @mouse(296,52-302,58): ret% = 4 'stockholm
    case @mouse(307,113-313,119): ret% = 5 'athen
    case @mouse(295,135-300,140): ret% = 6 'kairo
    case @mouse(353,155-358,160): ret% = 7 'djidda
    case @mouse(271,194-276,199): ret% = 8 'doula
    case @mouse(366,265-371,270): ret% = 9 'tomasina
    case @mouse(302,291-307,296): ret% = 10'kapstadt
endif
if Zeit% >= 2
    case @mouse(472,151-477,156): ret% = 11'kalcutta
    case @mouse(507,204-512,209): ret% = 12'singapur
    case @mouse(547,137-552,142): ret% = 13'shanghai
    case @mouse(596,120-602,125): ret% = 14'tokio
endif
if Zeit% >= 3
    case @mouse(24,53-29,58): ret% = 15'eskimo point
    case @mouse(50,136-55,141): ret% = 16'cheechee indi`s
    case @mouse(33,161-38,166): ret% = 17'Azteken
    case @mouse(43,177-48,182): ret% = 18'arwak
    case @mouse(120,212-125,217): ret% = 19'tupis
    case @mouse(118,290-123,295): ret% = 20'iroquies
    case @mouse(84,328-89,333): ret% = 21'palena
endif
endproc
'************************ Stadt Funktion *********************************
Proc Stadt
destroywindow(MainEnde%)
parameters SpielerNummer%
cls @RGB(0,0,0)
loadbmp @add$("Stadte/",Stadtbild$[Standtort%[SpielerNummer%]]), 0,0; 0
loadbmp "Bilder/Leiste.bg", 0,420; 0
CreateStadtMenue
    whilenot @GetFocus(_Button%[7])
'---------- stadtbild laden --------------
        drawtext 10, 10, Spielername$[SpielerNummer%] + " ist in " + stadtname$[Standtort%[SpielerNummer%]]

        '---------- auswahlentscheidung ----------

        waitmouse
        Case @GetFocus(_Button%[2]) : Kontor SpielerNummer%
     endwhile
DestroyStadtMenue
'---------------------------- Das Reiseziehl wählen ---------------------------------
case Zeit% = 1: loadbmp "Bilder/map1.BG",0,0;0
case Zeit% = 2: loadbmp "Bilder/map2.BG",0,0;0
case Zeit% = 3: loadbmp "Bilder/map3.BG",0,0;0
TextColor @RGB(255,255,255),@RGB(0,0,0)
UsePen 0,1,@rgb(255,0,0)
UseBrush 1,@rgb(255,0,0)
ende% = @Create("Button",%HWnd,"Abfart",500,460,80,20)
whilenot @and(@GetFocus(ende%),ret%<>22)
    ret% = 22
    WahleStadt 'Auf welcher stadt die maus ist
    Zielhafen%[SpielerNummer%]=ret%
    DrawText 50,420,"                                                   "
    DrawText 50,440,"                                                   "
    DrawText 50,420,"Standtort:"
    DrawText 50,440,"Zielhafen:"
    DrawText 150,420,stadtname$[Standtort%[SpielerNummer%]]
    case ret% <> 22 : ellipse StadtPos%[ret%,0],StadtPos%[ret%,1]-StadtPos%[ret%,0]+5,StadtPos%[ret%,1]+5
    case ret% <> 22 : DrawText 150,440,stadtname$[Zielhafen%[SpielerNummer%]]
    WaitMouse
    'Roten fleck entfernen aus dem MemBild restaurieren
    MCopyBmp StadtPos%[ret%,0],StadtPos%[ret%,1]-StadtPos%[ret%,0]+5,StadtPos%[ret%,1]+5 > StadtPos%[ret%,0],StadtPos%[ret%,1];0
wend
destroywindow(ende%)
TextColor @RGB(255,255,255),-1
'---------------------------- Weltkugelherstellen -----------------------------------
    case Zeit% = 1: loadbmp "Bilder/map1.BG",0,0;0
    case Zeit% = 2: loadbmp "Bilder/map2.BG",0,0;0
    case Zeit% = 3: loadbmp "Bilder/map3.BG",0,0;0
    MainEnde% = @Create("Button",%HWnd,"Ende",50,460,80,20)
    'Standtort%[SpielerNummer%]=90
endproc
