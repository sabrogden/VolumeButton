F13::
WinGet, active_id, ID, A
WinActivate, ahk_exe Teams.exe
sleep 250
Send ^+m
sleep 250
WinActivate, ahk_id %active_id%