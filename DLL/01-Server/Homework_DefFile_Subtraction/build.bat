del *.dll

del *.exp

del *.lib

del *.obj

cl.exe /c /EHsc MyMathOneSub.c

link.exe MyMathOneSub.obj /DLL user32.lib /SUBSYSTEM:WINDOWS