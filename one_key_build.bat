WScript check_prerequisite.vbs
git clone https://github.com/sonyps5201314/ntdll.git ../ntdll
WScript ../ntdll/setup.vbs
expand ./first_time_build_need_files.cab . -F:*
CALL "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Auxiliary\Build\vcvars32.bat"
msbuild /m msvcr14x.sln /t:Build /p:Configuration=Debug;Platform=x86
msbuild /m msvcr14x.sln /t:Build /p:Configuration=Release;Platform=x86
msbuild /m msvcr14x.sln /t:Build /p:Configuration=Debug;Platform=x64
msbuild /m msvcr14x.sln /t:Build /p:Configuration=Release;Platform=x64
