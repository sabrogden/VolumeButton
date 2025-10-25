F13::
{ ; V1toV2: Added opening brace for [F13]
global ; V1toV2: Made function global
active_id := WinGetID("A")
WinActivate("ahk_exe ms-teams.exe")
Sleep(250)
Send("^+m")
Sleep(250)
WinActivate("ahk_id " active_id)
} ; V1toV2: Added closing brace for [F13] (NO CLEAR EXIT FOUND)