# Microsoft Developer Studio Project File - Name="dllnctest" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103
# TARGTYPE "Win32 (ALPHA) Console Application" 0x0603

CFG=dllnctest - Win32 AlphaDbg
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "dllnctest.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "dllnctest.mak" CFG="dllnctest - Win32 AlphaDbg"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "dllnctest - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "dllnctest - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "dllnctest - Win32 AlphaRel" (based on "Win32 (ALPHA) Console Application")
!MESSAGE "dllnctest - Win32 AlphaDbg" (based on "Win32 (ALPHA) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""

!IF  "$(CFG)" == "dllnctest - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\dllnctest\Release"
# PROP BASE Intermediate_Dir ".\dllnctest\Release"
# PROP BASE Target_Dir ".\dllnctest"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\..\mfhdf\nctest\Release"
# PROP Intermediate_Dir "..\..\..\..\mfhdf\nctest\Release\dllnctest"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ".\dllnctest"
F90=df.exe
# ADD BASE F90 /include:".\dllnctest\Release/" /I "..\..\..\..\dllnctest\Release/"
# ADD F90 /include:".\dllnctest\Release/" /I "..\..\..\..\dllnctest\Release/"
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /MD /W3 /Gi /GX /I "..\..\..\..\mfhdf\libsrc" /I "..\..\..\..\mfhdf\xdr" /I "..\..\..\..\hdf\src" /D "_CONSOLE" /D "HDF" /D "NO_SYS_XDR_INC" /D "NDEBUG" /D "INTEL86" /D "WIN32" /D "DOS_FS" /FD /c
# SUBTRACT CPP /YX
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib $(HDF4_EXT_ZLIB) $(HDF4_EXT_SZIP) $(HDF4_EXT_JPEG) /nologo /subsystem:console /machine:I386 /libpath:".\windows\lib\release\multithreaded"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\dllnctest\Debug"
# PROP BASE Intermediate_Dir ".\dllnctest\Debug"
# PROP BASE Target_Dir ".\dllnctest"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\..\mfhdf\nctest\Debug"
# PROP Intermediate_Dir "..\..\..\..\mfhdf\nctest\Debug\dllnctest"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ".\dllnctest"
F90=df.exe
# ADD BASE F90 /include:".\dllnctest\Debug/" /I "..\..\..\..\dllnctest\Debug/"
# ADD F90 /dbglibs /include:".\dllnctest\Debug/" /I "..\..\..\..\dllnctest\Debug/"
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /YX /c
# ADD CPP /nologo /MDd /W3 /Gm /Gi /GX /ZI /Od /I "..\..\..\..\mfhdf\xdr" /I "..\..\..\..\mfhdf\libsrc" /I "..\..\..\..\hdf\src" /D "_CONSOLE" /D "HDF" /D "NO_SYS_XDR_INC" /D "_DEBUG" /D "INTEL86" /D "WIN32" /D "DOS_FS" /FD /c
# SUBTRACT CPP /YX
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386
# ADD LINK32 wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib $(HDF4_EXT_ZLIB) $(HDF4_EXT_SZIP) $(HDF4_EXT_JPEG) /nologo /subsystem:console /debug /machine:I386 /libpath:".\windows\lib\debug\multithreaded"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "dllnctest\AlphaRel"
# PROP BASE Intermediate_Dir "dllnctest\AlphaRel"
# PROP BASE Target_Dir "dllnctest"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "dllnctest\AlphaRel"
# PROP Intermediate_Dir "dllnctest\AlphaRel"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir "dllnctest"
CPP=cl.exe
# ADD BASE CPP /nologo /Gt0 /W3 /GX /O2 /I "..\..\..\..\hdf\src" /I "..\..\..\..\hdf\zlib" /I "..\..\..\..\hdf\jpeg" /I "..\..\..\..\mfhdf\xdr" /I "..\..\..\..\mfhdf\libsrc" /I "..\..\..\..\hdf/src" /I "..\..\..\..\hdf\src" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "HDF" /D "NO_SYS_XDR_INC" /D "INTEL86" /D "DOS_FS" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MD /Gt0 /W3 /GX /O2 /I "..\..\..\..\hdf\src" /I "..\..\..\..\hdf\zlib" /I "..\..\..\..\hdf\jpeg" /I "..\..\..\..\mfhdf\xdr" /I "..\..\..\..\mfhdf\libsrc" /I "..\..\..\..\hdf/src" /I "..\..\..\..\hdf\src" /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /D "HDF" /D "NO_SYS_XDR_INC" /D "INTEL86" /D "DOS_FS" /FD /c
# SUBTRACT CPP /YX
F90=df.exe
# ADD BASE F90 /compile_only /include:"dllnctest\AlphaRel/" /nologo /warn:nofileopt /I "..\..\..\..\dllnctest\Release/"
# ADD F90 /compile_only /include:"dllnctest\AlphaRel/" /nologo /warn:nofileopt /I "..\..\..\..\dllnctest\Release/"
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wsock32.lib src\release\src.lib jpeg\release\jpeg.lib zlib\release\zlib.lib xdr\release\xdr.lib libsrc\release\libsrc.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:console /machine:ALPHA
# ADD LINK32 wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:console /machine:ALPHA

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "dllnctest\AlphaDbg"
# PROP BASE Intermediate_Dir "dllnctest\AlphaDbg"
# PROP BASE Target_Dir "dllnctest"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "dllnctest\AlphaDbg"
# PROP Intermediate_Dir "dllnctest\AlphaDbg"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir "dllnctest"
CPP=cl.exe
# ADD BASE CPP /nologo /Gt0 /W3 /GX /Zi /Od /I "..\..\..\..\hdf\zlib" /I "..\..\..\..\hdf\jpeg" /I "..\..\..\..\mfhdf\xdr" /I "..\..\..\..\mfhdf\libsrc" /I "..\..\..\..\hdf\src" /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /D "HDF" /D "NO_SYS_XDR_INC" /D "INTEL86" /D "DOS_FS" /FD /c
# SUBTRACT BASE CPP /YX
# ADD CPP /nologo /MDd /Gt0 /W3 /GX /Zi /Od /I "..\..\..\..\hdf\zlib" /I "..\..\..\..\hdf\jpeg" /I "..\..\..\..\mfhdf\xdr" /I "..\..\..\..\mfhdf\libsrc" /I "..\..\..\..\hdf\src" /D "_CONSOLE" /D "_MBCS" /D "HDF" /D "NO_SYS_XDR_INC" /D "WIN32" /D "_DEBUG" /D "DOS_FS" /FD /c
# SUBTRACT CPP /YX
F90=df.exe
# ADD BASE F90 /compile_only /dbglibs /debug:full /include:"dllnctest\AlphaDbg/" /nologo /warn:nofileopt /I "..\..\..\..\dllnctest\Debug/"
# ADD F90 /compile_only /dbglibs /debug:full /include:"dllnctest\AlphaDbg/" /nologo /warn:nofileopt /I "..\..\..\..\dllnctest\Debug/"
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 wsock32.lib src\debug\src.lib jpeg\debug\jpeg.lib zlib\debug\zlib.lib xdr\debug\xdr.lib libsrc\debug\libsrc.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:console /debug /machine:ALPHA
# ADD LINK32 wsock32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:console /debug /machine:ALPHA

!ENDIF 

# Begin Target

# Name "dllnctest - Win32 Release"
# Name "dllnctest - Win32 Debug"
# Name "dllnctest - Win32 AlphaRel"
# Name "dllnctest - Win32 AlphaDbg"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\add.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

NODEP_CPP_ADD_C=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

NODEP_CPP_ADD_C=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\add.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\atttests.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

NODEP_CPP_ATTTE=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\mfhdf\nctest\val.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

NODEP_CPP_ATTTE=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\mfhdf\nctest\val.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\cdftests.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

NODEP_CPP_CDFTE=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

NODEP_CPP_CDFTE=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\dimtests.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

NODEP_CPP_DIMTE=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

NODEP_CPP_DIMTE=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\driver.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

NODEP_CPP_DRIVE=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\hlimits.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\tests.h"\
	

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

NODEP_CPP_DRIVE=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\hlimits.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\tests.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\emalloc.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

NODEP_CPP_EMALL=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

NODEP_CPP_EMALL=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\emalloc.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\error.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

NODEP_CPP_ERROR=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\hlimits.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

NODEP_CPP_ERROR=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\hlimits.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\error.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\misctest.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

NODEP_CPP_MISCT=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

NODEP_CPP_MISCT=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\rec.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

NODEP_CPP_REC_C=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\mfhdf\nctest\val.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

NODEP_CPP_REC_C=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\mfhdf\nctest\val.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\slabs.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

NODEP_CPP_SLABS=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

NODEP_CPP_SLABS=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\testcdf.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\tests.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\val.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

NODEP_CPP_VAL_C=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\val.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

NODEP_CPP_VAL_C=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\val.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\val.h
# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\vardef.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

NODEP_CPP_VARDE=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

NODEP_CPP_VARDE=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\varget.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

NODEP_CPP_VARGE=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

NODEP_CPP_VARGE=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\varget_unlim.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\vargetg.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

NODEP_CPP_VARGET=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

NODEP_CPP_VARGET=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\varput.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

NODEP_CPP_VARPU=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\mfhdf\nctest\val.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

NODEP_CPP_VARPU=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\mfhdf\nctest\val.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\varputg.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

NODEP_CPP_VARPUT=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\mfhdf\nctest\val.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

NODEP_CPP_VARPUT=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\mfhdf\nctest\val.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\vartests.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

NODEP_CPP_VARTE=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

NODEP_CPP_VARTE=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\vputget.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

NODEP_CPP_VPUTG=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\mfhdf\nctest\val.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

NODEP_CPP_VPUTG=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\mfhdf\nctest\val.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\..\..\..\mfhdf\nctest\vputgetg.c

!IF  "$(CFG)" == "dllnctest - Win32 Release"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 Debug"

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaRel"

NODEP_CPP_VPUTGE=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\mfhdf\nctest\val.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ELSEIF  "$(CFG)" == "dllnctest - Win32 AlphaDbg"

NODEP_CPP_VPUTGE=\
	".\hdf\src\api_adpt.h"\
	".\hdf\src\atom.h"\
	".\hdf\src\bitvect.h"\
	".\hdf\src\dfivms.h"\
	".\hdf\src\dynarray.h"\
	".\hdf\src\fmpio.h"\
	".\hdf\src\hbitio.h"\
	".\hdf\src\hchunks.h"\
	".\hdf\src\hcomp.h"\
	".\hdf\src\hdf.h"\
	".\hdf\src\hdfi.h"\
	".\hdf\src\herr.h"\
	".\hdf\src\hfile.h"\
	".\hdf\src\hlimits.h"\
	".\hdf\src\hntdefs.h"\
	".\hdf\src\hproto.h"\
	".\hdf\src\hqueue.h"\
	".\hdf\src\htags.h"\
	".\hdf\src\IOTrace.h"\
	".\hdf\src\linklist.h"\
	".\hdf\src\maldebug.h"\
	".\hdf\src\mcache.h"\
	".\hdf\src\mfgr.h"\
	".\hdf\src\ProcIDs.h"\
	".\hdf\src\tbbt.h"\
	".\hdf\src\vg.h"\
	".\hdf\src\vgint.h"\
	".\mfhdf\libsrc\alloc.h"\
	".\mfhdf\libsrc\hdf2netcdf.h"\
	".\mfhdf\libsrc\netcdf.h"\
	".\mfhdf\nctest\add.h"\
	".\mfhdf\nctest\emalloc.h"\
	".\mfhdf\nctest\testcdf.h"\
	".\mfhdf\nctest\tests.h"\
	".\mfhdf\nctest\val.h"\
	".\ys\stat.h"\
	".\ys\types.h"\
	

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project