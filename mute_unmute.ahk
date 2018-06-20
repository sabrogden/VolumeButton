;14 - logitech
;16 - seenheiser

F13::
	SoundGet, master_mute, , mute, 14
	if(master_mute = "Off")
	{
		SoundSet, +1, MASTER, mute, 14 
	}
return

F14::
	SoundGet, master_mute, , mute, 14
	if(master_mute = "On")
	{
		SoundSet, +1, MASTER, mute, 14
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