cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

set(META_PROJECT_NAME        "v1")
set(META_VERSION_MAJOR       "1")
set(META_VERSION_MINOR       "0")
set(META_VERSION_PATCH       "0")
set(META_VERSION             "${META_VERSION_MAJOR}.${META_VERSION_MINOR}.${META_VERSION_PATCH}")

# Преобразование каждого небуквенно-циферного символа на входе в символ подчеркивания
string(MAKE_C_IDENTIFIER ${META_PROJECT_NAME} META_PROJECT_ID)
# Изменение регистра на (ПРОПИСНЫЕ)
string(TOUPPER           ${META_PROJECT_ID}   META_PROJECT_ID)

# -------------- Определяет является ли данные проект подпроектом --------------
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  set(${META_PROJECT_ID}_SUBPROJECT ON)
endif()
# ------------------------------------------------------------------------------

project(
    ${META_PROJECT_NAME}                # <PROJECT-NAME>
    VERSION ${META_VERSION}             # [VERSION <major>[.<minor>[.<patch>[.<tweak>]]]]
    DESCRIPTION "CMakeLists.txt v.1"    # [DESCRIPTION <project-description-string>]
    LANGUAGES CXX)                      # [LANGUAGES <language-name>...]

add_subdirectory(src)
# add_subdirectory(vendor/Catch2)

# ------------ Подведение итогов настроек, напечатанных при сборке -------------
message(STATUS " ===== Окончательный обзор для ${PROJECT_NAME} ===== ")
message(STATUS "Version:    ${META_VERSION}")
message(STATUS "Compiler:   ${CMAKE_CXX_COMPILER}")
message(STATUS "")
# ------------------------------------------------------------------------------