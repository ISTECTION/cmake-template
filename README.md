# CMake + Doxygen + GTest + CTest + LaTeX (v.1)

<!-- BUILD STATUS -->
<!-- [![Build status](https://ci.appveyor.com/api/projects/status/3de0b919bwn2wpa4?svg=true)](https://ci.appveyor.com/project/ISTECTION/cmake-template) -->
<!-- BUILD STATUS -->


<!-- TOTAL LINES -->
<!-- [![LOC](https://sloc.xyz/github/ISTECTION/cmake-template)](https://github.com/ISTECTION/cmake-template) -->
<!-- TOTAL LINES -->

## Клонирование репозитория

Клонирование репозитория:

```
git clone <URL проекта>
```

Инициализация и обновление подмодулей:

```
git submodule init
git submodule update
```

## Сборка

Для генерации проекта необходимо запустить скрипт `Build-Project.ps1`. Кроме этого в нем реализавоны дополнительные опции, Вы можете передать опции:

* **doc**   - для генерации doxygen документации
* **gtest** - для генерации google тестов
* **ctest** - для генерации CMake тестов
* **build_path** *'new_path'* - для переопределения стандартной дирректории компилируемого проекта
* **compile** *'MinGW'* - для выбора определенного компилятора из имеющихся:
    * *default*
    * *MinGW*

Все опции передаются в формате: `-option ['string']`

## Ссылки

* [Скачать CMake](https://cmake.org/download/)
* [Скачать Inkscape](https://inkscape.org/ru/release/inkscape-1.0/)
* [Скачать Chocolatey](https://chocolatey.org/)
* [Скачать Git](https://gitforwindows.org/)

## Репозитории

* [GitHub репозиторий CMake](https://github.com/Kitware/CMake)
* [GitHub репозиторий Doxygen](https://github.com/doxygen/doxygen)
* [GitHub репозиторий Tectonic](https://github.com/tectonic-typesetting/tectonic)
* [GitHub репозиторий PowerShell](https://github.com/PowerShell/PowerShell)
* [GitHub репозиторий GCC](https://github.com/gcc-mirror/gcc)

## Документация

* [Tectonic](https://tectonic-typesetting.github.io/book/latest/installation/)

## Команды

* SVG to LaTeX
```
inkscape --export-filename=yourpdfoutput.pdf plot.svg --export-latex
```

* Загрузка подмодулей
```
git submodule add <URL репозитория> <директория>
```

* Удаление подмодулей
```
git rm <директория>
```

* Установка истории фиксации (--depth=1)
```
git config -f .gitmodules submodule.vendor/tabulate.shallow true
```

* Создание тега
```
git tag -a v1.0.0 -m "cmake-template 1.0.0"
git push --tags
```

## TODO

- Добавить больше конфигураций сборки