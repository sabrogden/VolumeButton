+^!F4::  ;shift - control - alt - F3
	SoundGet, master_mute, , mute, 6

	if(master_mute = "On")
	{
		;any positive number will turn on the setting and a zero will turn it off. However, if the number begins with a plus or minus sign, the setting will be toggled (set to the opposite of its current state).
		;6 was my mic id number use the code below the dotted line to find your mic id. you need to replace all 12's  <---------IMPORTANT

		SoundSet, +1, MASTER, mute, 6 

		traytip, Microphone UnMuted, 1

;		Sleep, 2500
	}
return


+^!F3::  ;shift - control - alt - F4
	SoundGet, master_mute, , mute, 6

	if(master_mute = "Off")
	{
		;any positive number will turn on the setting and a zero will turn it off. However, if the number begins with a plus or minus sign, the setting will be toggled (set to the opposite of its current state).
		;6 was my mic id number use the code below the dotted line to find your mic id. you need to replace all 12's  <---------IMPORTANT

		;6 was my mic id number use the code below the dotted line to find your mic id. you need to replace all 12's  <---------IMPORTANT

		SoundSet, +1, MASTER, mute, 6 

		traytip, Microphone Muted, 1

;		Sleep, 2500
	}
return

+^!F1::  ;shift - control - alt - F1
	Send {Volume_Up}
	Send {Volume_Up}
return

+^!F2::  ;shift - control - alt - F2
	Send {Volume_Down}
	Send {Volume_Down}
return

+^!F5::  ;shift - control - alt - F5
	;always mute
	
	SoundGet, master_mute, , mute

	if ( master_mute == "Off" )  
		Send {Volume_Mute}	
;	else
;	   traytip, Mute status is:, %master_mute%, 1
return

+^!F6::  ;shift - control - alt - F6
;	;always unmute

	SoundGet, master_mute, , mute

	if ( master_mute == "On" )  
		Send {Volume_Mute}

;	else
;	   traytip, Mute status is:, %master_mute%, 1
return