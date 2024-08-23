del *.dll

del *.exp

del *.lib

del *.obj

cl.exe /c /EHsc MyMathTwoDiv.c

link.exe MyMathTwoDiv.obj /DLL /DEF:MyMathTwoDiv.def user32.lib /SUBSYSTEM:WINDOWS