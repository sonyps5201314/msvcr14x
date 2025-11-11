@ECHO OFF
GOTO MENU
:MENU
set ID=%1
if not defined ID (
  ECHO.Which Visual Studio 2026 Edition do you want to use?
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

git pull -v --progress "origin"

:check_ntdll
if not exist ../ntdll (
  git clone https://github.com/sonyps5201314/ntdll.git ../ntdll
  goto :check_ntdll
)
git -C ../ntdll pull -v --progress "origin"

:check_boost-math
if not exist ../boost-math (
  git clone https://github.com/boostorg/math.git ../boost-math
  goto :check_boost-math
)
cd ../boost-math
git checkout 4d0885ae44f7d4ce94568339b2ae5501eb234e8f
cd %~dp0
  
:check_YY-Thunks
if not exist ../YY-Thunks (
  git clone https://github.com/sonyps5201314/YY-Thunks.git ../YY-Thunks
  goto :check_YY-Thunks
)
git -C ../YY-Thunks pull -v --progress "origin"

WScript ../ntdll/setup.vbs

for /f "delims=" %%i in ('"C:\Program Files (x86)\Microsoft Visual Studio\Installer\vswhere.exe" -version 18.0 -property installationPath -products Microsoft.VisualStudio.Product.%VS_EDITION%') do set "VS_PATH=%%i"
@ECHO ON
CALL "%VS_PATH%\VC\Auxiliary\Build\vcvars32.bat"
msbuild "../YY-Thunks\src\YY-Thunks.UnitTest\YY-Thunks.UnitTest.vcxproj" -t:Build_YY_Thunks_List_hpp

msbuild /m msvcr14x.slnx /t:Build /p:Configuration=Debug;Platform=x86
msbuild /m msvcr14x.slnx /t:Build /p:Configuration=AnsiDebug;Platform=x86
msbuild /m msvcr14x.slnx /t:Build /p:Configuration=Release;Platform=x86
msbuild /m msvcr14x.slnx /t:Build /p:Configuration=AnsiRelease;Platform=x86
msbuild /m msvcr14x.slnx /t:Build /p:Configuration=Debug;Platform=x64
msbuild /m msvcr14x.slnx /t:Build /p:Configuration=AnsiDebug;Platform=x64
msbuild /m msvcr14x.slnx /t:Build /p:Configuration=Release;Platform=x64
msbuild /m msvcr14x.slnx /t:Build /p:Configuration=AnsiRelease;Platform=x64
