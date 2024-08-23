del *.dll

del *.exp

del *.lib

del *.obj

cl.exe /c /EHsc MyMathTwoMult.c

link.exe MyMathTwoMult.obj /DLL /DEF:MyMathTwoMult.def user32.lib /SUBSYSTEM:WINDOWS
