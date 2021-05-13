WScript check_prerequisite.vbs
if not defined boost_ROOT (
    for /F "tokens=3* skip=2" %%P in ('reg query "HKCU\Environment" /v boost_ROOT') do @set "boost_ROOT=%%P %%Q"
)
git clone https://github.com/sonyps5201314/ntdll.git ../ntdll
git pull -v --progress "origin"
git clone https://github.com/sonyps5201314/YY-Thunks.git ../YY-Thunks
git pull -v --progress "origin"
WScript ../ntdll/setup.vbs
expand ./first_time_build_need_files.cab . -F:*
CALL "C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\VC\Auxiliary\Build\vcvars32.bat"
msbuild /m msvcr14x.sln /t:Build /p:Configuration=Debug;Platform=x86
msbuild /m msvcr14x.sln /t:Build /p:Configuration=Release;Platform=x86
msbuild /m msvcr14x.sln /t:Build /p:Configuration=Debug;Platform=x64
msbuild /m msvcr14x.sln /t:Build /p:Configuration=Release;Platform=x64
