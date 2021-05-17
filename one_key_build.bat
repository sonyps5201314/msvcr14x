@ECHO OFF
GOTO MENU
:MENU
ECHO.Which Visual Studio 2019 Edition do you want to use?
ECHO.1.Enterprise
ECHO.2.Professional
ECHO.3.Community
echo.Please enter the order number of your selected item:
set /p  ID=
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
@ECHO ON
git clone https://github.com/sonyps5201314/ntdll.git ../ntdll
git pull -v --progress "origin"
git clone https://github.com/sonyps5201314/YY-Thunks.git ../YY-Thunks
git pull -v --progress "origin"
WScript ../ntdll/setup.vbs
expand ./first_time_build_need_files.cab . -F:*
CALL "C:\Program Files (x86)\Microsoft Visual Studio\2019\%VS_EDITION%\VC\Auxiliary\Build\vcvars32.bat"
msbuild /m msvcr14x.sln /t:Build /p:Configuration=Debug;Platform=x86
msbuild /m msvcr14x.sln /t:Build /p:Configuration=Release;Platform=x86
msbuild /m msvcr14x.sln /t:Build /p:Configuration=Debug;Platform=x64
msbuild /m msvcr14x.sln /t:Build /p:Configuration=Release;Platform=x64
