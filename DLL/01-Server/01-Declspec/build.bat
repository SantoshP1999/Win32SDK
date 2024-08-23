del *.dll

del *.exp

del *.lib

del *.obj

cl.exe /c /EHsc MyMathOne.c

link.exe MyMathOne.obj /DLL /MyMathOne.def user32.lib /SUBSYSTEM:WINDOWS