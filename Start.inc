'***************************************************************
'************************ Fehlerabfrage ************************
'***************************************************************

'************** Grafikeinstellungsfehler **************
'case %maxx <> 600: fehler1
'case %maxy <> 480: fehler1
'case %bitspixel < 16: fehler1


'***************************************************************
'************************ Hauptfenster *************************
'***************************************************************
WindowStyle $50
Window 0,0-%MaxX,%MaxY
'UseIcon "1492.ICO"
WindowTitle "TestVersion Aktives Programm"
MLoadBMP "Main.BG"

'------ Menue1 -----
MCopySizedBmp 0,0-1,1 > 0,0-300,300;0
menue1:
    loadbmp "Bilder/Menue1.bg",0,0;0
    WaitMouse
    Case @Mouse(100,200-520,248):goto "NeuesSpiel"
    Case @Mouse(150,250-480,294):goto "laden"
    Case @Mouse(228,300-400,338):goto "Ende"
goto "menue1"

'----- NeuesSpiel -----
NeuesSpiel:

'----- Spielerauswahl -----
Spieler1:
	SpielerName$[0] = "Spieler 1"
  	SpielerName$[1] = "Spieler 2"
   	SpielerName$[2] = "Spieler 3"
   	SpielerName$[3] = "Spieler 4"
i%=0
whilenot i%=4
	temp% = 0
	CR_Menue i%
	ende% = 0
	  whilenot ende%
	    Waitinput
	    if %key = 4
	    elseif %mousekey = 2
	    	DT_Menue
		goto "menue1"
	    elseif @getfocus(temp%[0])
		playsound "Sound/klick.sou", 0
    	    if temp% <> 0
	      	    SpielerName$[i%] = @gettext$(temp%[9])
    			Standtort%[i%] = temp%
                X%[i%] = StadtPos%[Standtort%[i%],0]
                Y%[i%] = StadtPos%[Standtort%[i%],1]
                Zielhafen%[i%]=Standtort%[i%]
	       		SpielerMax% = i%
		      	DT_Menue
    			goto "start"
	       	else
		      	fehler2
       		endif
	    elseif @getfocus(temp%[1])
		playsound "Sound/klick.sou", 0
		temp% = 1
	    elseif @getfocus(temp%[2])
		playsound "Sound/klick.sou", 0
		temp% = 2
	    elseif @getfocus(temp%[3])
		playsound "Sound/klick.sou", 0
		temp% = 3
	    elseif @getfocus(temp%[4])
		playsound "Sound/klick.sou", 0
		temp% = 4
	    elseif @getfocus(temp%[6])
	   	    playsound "Sound/klick.sou", 0
    		if temp% <> 0
	       	    SpielerName$[i%] = @gettext$(temp%[9])
    	    	Standtort%[i%] = temp%
                X%[i%] = StadtPos%[Standtort%[i%],0]
                Y%[i%] = StadtPos%[Standtort%[i%],1]
                Zielhafen%[i%]=Standtort%[i%]
		        DT_Menue
                ende%=1
	       	else
		      	fehler2
    		endif
	    endif
  	wend
    i%=i%+1
wend
