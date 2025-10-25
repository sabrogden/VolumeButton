F13::
{
	global ; V1toV2: Made function global
;	active_id := WinGetID("A")
	
	WinActivate("ahk_exe ms-teams.exe")
	Sleep(50)
	WinActivate("ahk_exe ms-teams.exe")
	Sleep(50)
	WinActivate("ahk_exe ms-teams.exe")
	Sleep(50)
	Send("^+m")
	
;	Sleep(300)
;	WinActivate("ahk_id " active_id)
;	Sleep(150)
;	WinActivate("ahk_id " active_id)
;	Sleep(50)
;	WinActivate("ahk_id " active_id)
}