@ECHO OFF
cd /d %~dp0
GOTO find_vs
:find_vs
setlocal enabledelayedexpansion
REM Visual Studio 2022
set VSWHERE_EXE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe
set vsversion=17.0
set vscount=0
set VS_PATH=
echo Installed visual studio instances: 
for /f "usebackq tokens=1,* delims=: " %%i in (`"%VSWHERE_EXE%" -version %vsversion% -requires Microsoft.Component.MSBuild`) do (
  if "%%i"=="installationPath" set /a vscount=vscount+1 && echo     !vscount!.%%j && set VS_PATH!vscount!=%%j
)

if %vscount% LSS 1 echo "The Visual Studio 2022 not installed." && goto :eof

if %vscount% EQU 1 (
  set ID=1
) else (
  ECHO.Which Visual Studio 2022 Edition do you want to use, default is 1:
  set /p ID=
  if not defined ID set ID=1
  set VS_PATH=!VS_PATH%ID%!
)

set VS_PATH=!VS_PATH%ID%!

if not exist "%VS_PATH%"  echo Invalid input ID. && goto :eof

for /F "delims=" %%i in ("%VS_PATH%") do set VS_EDITION=%%~ni

:start_build

WScript check_prerequisite.vbs
set /P CheckPrerequisite_Result=<CheckPrerequisite_Result.txt
DEL CheckPrerequisite_Result.txt
if "%CheckPrerequisite_Result%" NEQ "True" EXIT
if not defined boost_ROOT (
    for /F "tokens=3* skip=2" %%P in ('reg query "HKCU\Environment" /v boost_ROOT') do @set "boost_ROOT=%%P %%Q"
)

git pull -v --progress "origin"

:check_ntdll
if not exist ../ntdll (
  git clone https://github.com/sonyps5201314/ntdll.git ../ntdll
  goto :check_ntdll
)
git -C ../ntdll pull -v --progress "origin"

:check_YY-Thunks
if not exist ../YY-Thunks (
  git clone https://github.com/sonyps5201314/YY-Thunks.git ../YY-Thunks
  goto :check_YY-Thunks
)
git -C ../YY-Thunks pull -v --progress "origin"

WScript ../ntdll/setup.vbs

@ECHO ON

CALL "%VS_PATH%\VC\Auxiliary\Build\vcvars32.bat"
msbuild "../YY-Thunks\src\YY-Thunks.UnitTest\YY-Thunks.UnitTest.vcxproj" -t:Build_YY_Thunks_List_hpp

msbuild /m msvcr14x.sln /t:Build /p:Configuration=Debug;Platform=x86
msbuild /m msvcr14x.sln /t:Build /p:Configuration=AnsiDebug;Platform=x86
msbuild /m msvcr14x.sln /t:Build /p:Configuration=Release;Platform=x86
msbuild /m msvcr14x.sln /t:Build /p:Configuration=AnsiRelease;Platform=x86
msbuild /m msvcr14x.sln /t:Build /p:Configuration=Debug;Platform=x64
msbuild /m msvcr14x.sln /t:Build /p:Configuration=AnsiDebug;Platform=x64
msbuild /m msvcr14x.sln /t:Build /p:Configuration=Release;Platform=x64
msbuild /m msvcr14x.sln /t:Build /p:Configuration=AnsiRelease;Platform=x64
