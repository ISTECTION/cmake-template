cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

set(V1_PROJECT_NAME        "v1")

# Преобразование каждого небуквенно-циферного символа на входе в символ подчеркивания
string(MAKE_C_IDENTIFIER ${V1_PROJECT_NAME} V1_PROJECT_ID)
# Изменение регистра на (ПРОПИСНЫЕ)
string(TOUPPER           ${V1_PROJECT_ID}   V1_PROJECT_ID)

# -------------- Определяет является ли данные проект подпроектом --------------
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
  set(${V1_PROJECT_ID}_SUBPROJECT ON)
endif()
# ------------------------------------------------------------------------------
project(
    ${V1_PROJECT_NAME}                  # <PROJECT-NAME>
    DESCRIPTION "CMakeLists.txt v.1"    # [DESCRIPTION <project-description-string>]
    LANGUAGES CXX)                      # [LANGUAGES <language-name>...]

add_subdirectory(vendor/argparse)

add_subdirectory(src)

# ------------ Подведение итогов настроек, напечатанных при сборке -------------
message(STATUS "===== Окончательный обзор для ${PROJECT_NAME} =====")
message(STATUS "  Version:    ${V1_VERSION}")
message(STATUS "  Compiler:   ${CMAKE_CXX_COMPILER}")
# ------------------------------------------------------------------------------