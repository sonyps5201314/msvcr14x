@ECHO OFF
GOTO MENU
:MENU
set ID=%1
if not defined ID (
  ECHO.Which Visual Studio 2022 Edition do you want to use?
  ECHO.1.Enterprise
  ECHO.2.Professional
  ECHO.3.Community
  echo.Please enter the order number of your selected item:
  
  set /p ID=
)
if "%id%"=="1" SET VS_EDITION=Enterprise
if "%id%"=="2" SET VS_EDITION=Professional
if "%id%"=="3" SET VS_EDITION=Community
if not defined VS_EDITION EXIT

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
WScript ../ntdll/setup.vbs

@ECHO ON

CALL "C:\Program Files\Microsoft Visual Studio\2022\%VS_EDITION%\VC\Auxiliary\Build\vcvars32.bat"

msbuild /m msvcr14x.sln /r /t:Build /p:Configuration=Debug;Platform=x86
msbuild /m msvcr14x.sln /r /t:Build /p:Configuration=AnsiDebug;Platform=x86
msbuild /m msvcr14x.sln /r /t:Build /p:Configuration=Release;Platform=x86
msbuild /m msvcr14x.sln /r /t:Build /p:Configuration=AnsiRelease;Platform=x86
msbuild /m msvcr14x.sln /r /t:Build /p:Configuration=Debug;Platform=x64
msbuild /m msvcr14x.sln /r /t:Build /p:Configuration=AnsiDebug;Platform=x64
msbuild /m msvcr14x.sln /r /t:Build /p:Configuration=Release;Platform=x64
msbuild /m msvcr14x.sln /r /t:Build /p:Configuration=AnsiRelease;Platform=x64
