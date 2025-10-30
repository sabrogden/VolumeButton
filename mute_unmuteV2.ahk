#include Acc_v2.ahk

F13::
{
	winList := WinGetlist("ahk_exe ms-teams.exe",,,)
	for window in winList
	{
		try
		{
            oAcc := Acc.ElementFromHandle('ahk_id ' window)
            ;find the window with the "leave" button, will be the meating window or the minimized window
			TargetElement := oAcc.FindElement({Name:"Leave"})
			If TargetElement {
				WinActivate(WinGetTitle(window))
				;send ctrl,shift,m shortcut
				Send("^+M")
				sleep 20
                break
			}
		}
		Catch
		{
		}
	}
}