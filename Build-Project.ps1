Param
(
    [Parameter(Mandatory=$false)]   # опциональный параметр - doxygen документация
    [switch]$doc=$false,
    [Parameter(Mandatory=$false)]   # опциональный параметр - компиляция Google Test
    [switch]$gtest=$false,
    [Parameter(Mandatory=$false)]   # опциональный параметр - компиляция CTest
    [switch]$ctest=$false,

    [Parameter(Mandatory=$false)]   # путь к компилируемому проекту (default: build)
    [string]$build_path='build',

    [Parameter(Mandatory=$false)]   # компилятор (default: Visual Studio)
    [ValidateSet('MinGW','default')]
    $compile='default'
)

if (Test-Path -Path $build_path) {
    Remove-Item -Force -Recurse -Path $build_path }
New-Item -Path $build_path -ItemType Directory

# используем двойные кавычки для вставки переменной в строку
if($compile -eq 'MinGW') {
    cmake -G 'MinGW Makefiles' -S . -B $build_path "-DDOC=$doc" "-DGTEST=$gtest" "-DCTEST=$ctest"
} else {
    cmake -S . -B $build_path "-DDOC=$doc" "-DGTEST=$gtest" "-DCTEST=$ctest"
}
cmake --build $build_path