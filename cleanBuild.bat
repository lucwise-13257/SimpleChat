rmdir /S build
mkdir build
cmake -B build
IF "%1" == "-r" (
    echo "Building RELEASE"
    cmake --build build --config Release
) ELSE (
    echo "Building DEBUG"
    cmake --build build
)