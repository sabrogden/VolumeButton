F13::
{
	winList := WinGetlist("ahk_exe ms-teams.exe",,,)

	for window in winList 							;Loop through IDs of all teams windows
	{
		if (WinGetTitle(window) != "Microsoft Teams Notification" and WinGetTitle(window) != "")	;make sure it isnt the notification	or screen sharing, which uses a null title
		{
			WinActivate(WinGetTitle(window))	;This should be either the main Teams window or the meeting window, activate it
			Send("^+M")							;send ctrl,shift,m shortcut
			sleep 20							;sometimes it activates the new window before the sendkeys finishes, delay fixes it
	}}
}