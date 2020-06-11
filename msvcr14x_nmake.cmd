@echo off
if %Platform% == x64 (
set LIB=%msvcr14x_ROOT%\x64\Release;%msvcr14x_ROOT%\x64\Debug;%LIB%
)
if %Platform% == x86 (
set LIB=%msvcr14x_ROOT%\Release;%msvcr14x_ROOT%\Debug;%LIB%
)
