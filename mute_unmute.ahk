#include VA.ahk

global inputName = "MicToMuteUnMute"

MuteTimer() {
	currentSound := VA_GetMasterMute(inputName)		
	if(currentSound = 0)
	{	
		VA_SetMasterMute(True, inputName)
	}		
	return
}

F13::
	;mute input name
	
	currentSound := VA_GetMasterMute(inputName)		
	if(currentSound = 0)
	{	
		VA_SetMasterMute(True, inputName)
	}		
	
	SetTimer, MuteTimer, 1000
	
return

F14::			
	;unmute input name
	
	SetTimer, MuteTimer, Off
	
	currentSound := VA_GetMasterMute(inputName)		
	if(currentSound = 1)
	{	
		VA_SetMasterMute(False, inputName)
	}
return

F15:: ;System Mute
	
	SoundGet, master_mute, , mute
	if ( master_mute == "Off" )  
		Send {Volume_Mute}	
return

F16:: ;System Un Mute

	SoundGet, master_mute, , mute
	if ( master_mute == "On" )  
		Send {Volume_Mute}
return