@echo off

if "%1"=="" (
    echo No build type specified. Defaulting to Debug.
    set BUILD_TYPE=Debug
) else (
    set BUILD_TYPE=%1
)

if /i "%BUILD_TYPE%" neq "Release" if /i "%BUILD_TYPE%" neq "Debug" (
    echo Invalid build type. Defaulting to Debug.
    set BUILD_TYPE=Debug
)

cmake --build .\build --config %BUILD_TYPE% --target ALL_BUILD -j 18 --

echo:
.\build\%BUILD_TYPE%\mavec.exe
