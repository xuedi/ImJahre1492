PROC delay
	Parameters N&
	  Declare Ende%
	  SetTimer N&
	  Let Ende% = 0
	  WHILENOT Ende%
	    WaitInput
	    Case %wmTimer:Let Ende% = 1
	  ENDWHILE
	  KillTimer
Endproc

