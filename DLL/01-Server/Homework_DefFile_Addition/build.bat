del *.dll

del *.exp

del *.lib

del *.obj

cl.exe /c /EHsc MyMathOneAdd.c

link.exe MyMathOneAdd.obj /DLL user32.lib /SUBSYSTEM:WINDOWS