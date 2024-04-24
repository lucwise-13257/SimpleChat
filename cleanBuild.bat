rmdir /S build
mkdir build
IF "%2" == "-ms" (
  echo USING MSBUILD
  cmake -B build
) ELSE (
  echo USING NINJA
  cmake -B build -G Ninja
)

IF "%1" == "-r" (
    echo "Building RELEASE"
    cmake --build build --config Release
) ELSE (
    echo "Building DEBUG"
    cmake --build build
)