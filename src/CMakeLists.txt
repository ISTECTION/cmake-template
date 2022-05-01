# ------------------------ LIBRARY ------------------------ #
# Избавляемся от стандартного префикса создания статических библиотек
set(CMAKE_STATIC_LIBRARY_PREFIX      "")
# set(CMAKE_STATIC_LIBRARY_SUFFIX "lib.a")  # Суффикс для статических библиотек

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)    # Каталог статических библиотек

# Исходные файлы статической библиотеки
set(LIB_SOURCES ${PROJECT_SOURCE_DIR}/src/lib.cpp)

# Заголовочные файлы для статической библиотеки (необязательно)
# Нужны только для документации
set(LIB_HEADERS ${PROJECT_SOURCE_DIR}/include/lib.hpp)

# Создаем библиотеку "PROJECT_NAME"+"lib"
add_library(${PROJECT_NAME}_lib STATIC ${LIB_SOURCES})

# Указываем путь к заголовочным файлам статической библиотеки
target_include_directories(
    ${PROJECT_NAME}_lib     PUBLIC
    ${PROJECT_SOURCE_DIR}/include)
# ------------------------ LIBRARY ------------------------ #

# ${CMAKE_CURRENT_SOURCE_DIR} - в каждом файле будем указывать для
# Doxygen - документации, так как Doxyfile находится в другой дирректории,
# заимствуя все объявленные файлы данных переменных
set(SOURCES ${PROJECT_SOURCE_DIR}/src/main.cpp)               # Исходные файлы
set(HEADERS ${PROJECT_SOURCE_DIR}/include/header.hpp)         # Заголовочные файлы

# Компилируем исполняемый файл с заданным именем
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Линкуем статическую библиотеку к исполняему файлу
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}_lib)

# Переопределние пути до заголовочных файлов
target_include_directories(
    ${PROJECT_NAME}        PRIVATE
    ${PROJECT_SOURCE_DIR}/include)

# ---------------------------------------------------------------------------- #
set_target_properties(${PROJECT_NAME}      PROPERTIES
    CXX_STANDARD ${${META_PROJECT_NAME}_CXX_STANDARD}   # CXX - стандарт
    CXX_STANDARD_REQUIRED                          ON   # Обязательная поддержка стандарта
    RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/bin

    # Задает рабочий каталог локального отладчика
    # для целевых объектов Visual Studio C++
    VS_DEBUGGER_WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

if(MSVC)        # Если это MSVC
    # Устанавливаем пользовательный проект в качестве запускаемого
    set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
    #[[
        /W0 - подавляют все предупреждения. Это эквивалентно /w
        /W1 - отображает предупреждения уровня 1 (серьезные)
        /W2 - отображает предупреждения уровня 1 и уровня 2 (значительные)
        /W3 - отображает предупреждения уровня 1,  уровня 2 и уровня 3 (качество продукции)
        /W4 - отображает предупреждения уровня 1,  уровня 2 и уровня 3, а также все предупреждения уровня 4 (информационные)
    ]]
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
        "$<$<CONFIG:RELEASE>:/O2>"
        /W3
        /WX) # Обрабатывает все предупреждения компилятора как ошибки.
else()
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE
        -Wall               # Вывод сообщений о всех предупреждениях или ошибках, возникающих во время компиляции программы.
        -Wextra
        -Wundef             # Предупредить, если неинициализированный идентификатор оценивается в #ifдирективе
        -Wunused
        -Wshadow            # Предупреждает всякий раз, когда локальная переменная затеняет другую локальную переменную
        -Wfloat-equal       # Полезно, потому что обычно проверка чисел с плавающей точкой на равенство плохая.
        -Wswitch-default    # Предупреждать, когда в switchвыражении нет defaultрегистра
        -Wnon-virtual-dtor)
endif()

# ------------------------------ Опции --------------------------------------- #
option(DOC   "Включить документирование"   OFF)  # Докуметация doxygen
option(GTEST "Включить тестирование GTest" OFF)  # Googletest
option(CTEST "Включить тестирование CTest" OFF)  # CTest
# ---------------------------------------------------------------------------- #

# Подключение doxygen документации
if(DOC)
    message(STATUS "Автодокументирование проекта ${PROJECT_NAME} включено")
    add_subdirectory(doc)
endif()

if(GTEST OR CTEST)
    enable_testing()
    if(GTEST)
        message(STATUS "Тестирование проекта ${PROJECT_NAME} включено (GTest)")
        add_subdirectory(gtest)
    endif()
    if(CTEST)
        message(STATUS "Тестирование проекта ${PROJECT_NAME} включено (CTest)")
        add_subdirectory(ctest)
    endif()
endif()

add_subdirectory(cfg)
add_subdirectory(rep)