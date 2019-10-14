# Microsoft Developer Studio Project File - Name="unixem.core" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=unixem.core - Win32 Debug Multithreaded pseudoUnix
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "unixem.core.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "unixem.core.mak" CFG="unixem.core - Win32 Debug Multithreaded pseudoUnix"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "unixem.core - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "unixem.core - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "unixem.core - Win32 Debug pseudoUnix" (based on "Win32 (x86) Static Library")
!MESSAGE "unixem.core - Win32 Release pseudoUnix" (based on "Win32 (x86) Static Library")
!MESSAGE "unixem.core - Win32 Debug Multithreaded pseudoUnix" (based on "Win32 (x86) Static Library")
!MESSAGE "unixem.core - Win32 Release Multithreaded pseudoUnix" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "unixem.core - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O1 /I "..\..\..\include" /D "NDEBUG" /D "UNIX" /D "unix" /D "_WIN32" /D "_WINDOWS" /YX /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\..\lib\unixem.1.core.vc6.lib"
# ADD LIB32 /nologo /out:"..\..\..\lib\unixem.1.core.vc6.lib"

!ELSEIF  "$(CFG)" == "unixem.core - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /I "..\..\..\include" /D "_DEBUG" /D "UNIX" /D "unix" /D "_WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\..\lib\unixem.1.core.vc6.debug.lib"
# ADD LIB32 /nologo /out:"..\..\..\lib\unixem.1.core.vc6.debug.lib"

!ELSEIF  "$(CFG)" == "unixem.core - Win32 Debug pseudoUnix"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugUnix"
# PROP BASE Intermediate_Dir "DebugUnix"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugUnix"
# PROP Intermediate_Dir "DebugUnix"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /I "..\..\..\include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /I "..\..\..\include" /D "_DEBUG" /D "UNIX" /D "unix" /D "_WIN32" /D "_WINDOWS" /YX /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\..\lib\unixem.1.core.vc6.unix.debug.lib"
# ADD LIB32 /nologo /out:"..\..\..\lib\unixem.1.core.vc6.unix.debug.lib"

!ELSEIF  "$(CFG)" == "unixem.core - Win32 Release pseudoUnix"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseUnix"
# PROP BASE Intermediate_Dir "ReleaseUnix"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseUnix"
# PROP Intermediate_Dir "ReleaseUnix"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O1 /I "..\..\..\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O1 /I "..\..\..\include" /D "NDEBUG" /D "UNIX" /D "unix" /D "_WIN32" /D "_WINDOWS" /YX /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\..\lib\unixem.1.core.vc6.unix.lib"
# ADD LIB32 /nologo /out:"..\..\..\lib\unixem.1.core.vc6.unix.lib"

!ELSEIF  "$(CFG)" == "unixem.core - Win32 Debug Multithreaded pseudoUnix"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugMTUnix"
# PROP BASE Intermediate_Dir "DebugMTUnix"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugMTUnix"
# PROP Intermediate_Dir "DebugMTUnix"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /I "..\..\..\include" /D "_DEBUG" /D "UNIX" /D "unix" /D "_WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /I "..\..\..\include" /D "_DEBUG" /D "UNIX" /D "unix" /D "_WIN32" /D "_WINDOWS" /FR /YX /FD /GZ /c
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\..\lib\unixem.1.core.vc6.unix.mt.debug.lib"
# ADD LIB32 /nologo /out:"..\..\..\lib\unixem.1.core.vc6.unix.mt.debug.lib"

!ELSEIF  "$(CFG)" == "unixem.core - Win32 Release Multithreaded pseudoUnix"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMTUnix"
# PROP BASE Intermediate_Dir "ReleaseMTUnix"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMTUnix"
# PROP Intermediate_Dir "ReleaseMTUnix"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O1 /I "..\..\..\include" /D "NDEBUG" /D "UNIX" /D "unix" /D "_WIN32" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O1 /I "..\..\..\include" /D "NDEBUG" /D "UNIX" /D "unix" /D "_WIN32" /D "_WINDOWS" /FR /YX /FD /c
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\..\lib\unixem.1.core.vc6.unix.mt.lib"
# ADD LIB32 /nologo /out:"..\..\..\lib\unixem.1.core.vc6.unix.mt.lib"

!ENDIF 

# Begin Target

# Name "unixem.core - Win32 Release"
# Name "unixem.core - Win32 Debug"
# Name "unixem.core - Win32 Debug pseudoUnix"
# Name "unixem.core - Win32 Release pseudoUnix"
# Name "unixem.core - Win32 Debug Multithreaded pseudoUnix"
# Name "unixem.core - Win32 Release Multithreaded pseudoUnix"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Supporting / Additional Source"

# PROP Default_Filter ""
# End Group
# Begin Source File

SOURCE=..\..\..\src\atomic.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\dirent.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\dlfcn.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\glob.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\hostname.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\mktemp.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\mmap.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\resource.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\setenv.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\time.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\uio.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\unistd.c
# End Source File
# Begin Source File

SOURCE=..\..\..\src\internal\util.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "Unixem Header Files"

# PROP Default_Filter ""
# Begin Group "arpa"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\include\unixem\arpa\inet.h
# End Source File
# End Group
# Begin Group "asm"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\include\unixem\asm\atomic.h
# End Source File
# End Group
# Begin Group "internal"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\include\unixem\internal\safestr.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\unixem\internal\util.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\unixem\internal\winsock.h
# End Source File
# End Group
# Begin Group "netinet"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\include\unixem\netinet\in.h
# End Source File
# End Group
# Begin Group "sys"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\include\unixem\sys\mman.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\unixem\sys\resource.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\unixem\sys\socket.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\unixem\sys\time.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\unixem\sys\uio.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\include\unixem\dirent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\unixem\dlfcn.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\unixem\glob.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\unixem\implicit_link.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\unixem\setenv.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\unixem\time.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\unixem\unistd.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\unixem\unixem.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\include\dirent.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\dlfcn.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\glob.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\unistd.h
# End Source File
# End Group
# Begin Group "Distribution Files"

# PROP Default_Filter "txt"
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\AUTHORS.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\CHANGES.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\FAQ.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\HISTORY.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\INSTALL.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\KNOWN_ISSUES.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\LICENSE.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\NEWS.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\README.txt"
# End Source File
# Begin Source File

SOURCE="..\..\..\_internal\dist-src\TODO.txt"
# End Source File
# End Group
# End Target
# End Project
