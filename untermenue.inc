proc CreateStadtMenue
    _Button%[0] = @Create("Button",%HWnd,"Bank"         ,5,455,70,20)
    _Button%[1] = @Create("Button",%HWnd,"Börse"        ,85,455,70,20)
    _Button%[2] = @Create("Button",%HWnd,"Kontor"       ,165,455,70,20)
    _Button%[3] = @Create("Button",%HWnd,"Reederei"     ,245,455,70,20)
    _Button%[4] = @Create("Button",%HWnd,"Büro"         ,325,455,70,20)
    _Button%[5] = @Create("Button",%HWnd,"Schiff"       ,405,455,70,20)
    _Button%[6] = @Create("Button",%HWnd,"Kirche"       ,485,455,70,20)
    _Button%[7] = @Create("Button",%HWnd,"Ende"         ,565,455,70,20)
endproc
proc DestroyStadtMenue
    destroywindow(_Button%[0])
    destroywindow(_Button%[1])
    destroywindow(_Button%[2])
    destroywindow(_Button%[3])
    destroywindow(_Button%[4])
    destroywindow(_Button%[5])
    destroywindow(_Button%[6])
    destroywindow(_Button%[7])
endproc
proc Kontor
    parameters SpielerNummer%
    DestroyStadtMenue
    _Button%[0] = @Create("Button",%HWnd,"Schiffsladung",5,455,100,20)
    _Button%[1] = @Create("Button",%HWnd,"Kaufen",110,455,70,20)
    _Button%[2] = @Create("Button",%HWnd,"Verkaufen",185,455,70,20)
    _Button%[3] = @Create("Button",%HWnd,"Hinweise",260,455,70,20)
    ProcEnde%   = @Create("Button",%HWnd,"Ende",335,455,70,20)
    whilenot @GetFocus(ProcEnde%)
        loadbmp "Bilder\Kontor.bg",0,0; 0
        
        
        WaitMouse
    wend
    destroywindow(_Button%[0])
    destroywindow(_Button%[1])
    destroywindow(_Button%[2])
    destroywindow(_Button%[3])
    destroywindow(ProcEnde%)
    loadbmp @add$("Stadte/",Stadtbild$[Standtort%[SpielerNummer%]]), 0,0; 0
    CreateStadtMenue
endproc
