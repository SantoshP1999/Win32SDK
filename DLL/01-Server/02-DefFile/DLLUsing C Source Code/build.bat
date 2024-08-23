del *.dll

del *.exp

del *.lib

del *.obj

cl.exe /c /EHsc MyMathTwo.c

link.exe MyMathTwo.obj /DLL /DEF:MyMathTwo.def user32.lib /SUBSYSTEM:WINDOWS