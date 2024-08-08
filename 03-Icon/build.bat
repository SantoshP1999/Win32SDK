cls
del *.exe
del *obj
del *.res
cl.exe /c /EHsc Window.c
rc.exe Window.rc
Link.exe Window.obj Window.res User32.lib gdi32.lib /SUBSYSTEM:WINDOWS
Window.exe