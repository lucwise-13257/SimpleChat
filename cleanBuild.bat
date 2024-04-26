@echo off
set BuildOption="Debug"
set BuildSystem="Ninja"

FOR %%A IN (%*) DO (
  IF "%%A" == "-r" (
    echo Setting Release
    set BuildOption="Release"
  )
  IF "%%A" == "-ms" (
    echo Setting MSBuild
    set BuildSystem="MSBuild"
  )
)

echo Building With These Options:
echo BuildType: %BuildOption%
echo BuildSystem: %BuildSystem%
choice /C yn /M "Are these options OK?"
IF errorlevel == 2 GOTO :eof

rmdir /S /Q build
mkdir build

IF %BuildSystem% == "Ninja" (
  echo BUILDING WITH NINJA
  cmake -B build -G Ninja
) ELSE IF %BuildSystem% == "MSBuild" (
  echo BUILDING WITH MSBUILD
  cmake -B build
)

IF %BuildOption% == "Release" (
  echo RELEASE BUILD
  cmake --build build --config Release
) ELSE (
  echo DEBUG BUILD
  cmake --build build
)

@REM IF "%2" == "-ms" (
@REM   echo USING MSBUILD
@REM   cmake -B build
@REM ) ELSE (
@REM   echo USING NINJA
@REM   cmake -B build -G Ninja
@REM )

@REM IF "%1" == "-r" (
@REM     echo "Building RELEASE"
@REM     cmake --build build --config Release
@REM ) ELSE (
@REM     echo "Building DEBUG"
@REM     cmake --build build
@REM )