configure_file(
    config.hpp.in
    ${PROJECT_SOURCE_DIR}/include/config/config.hpp
    @ONLY)

# Тег @ONLY - разрешате редактирование только переменных вида @VAR@
# В то время как переменные вида ${VAR} будут не тронуты

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/module" ${CMAKE_MODULE_PATH})
# include(GetVersionFromGitTag)

find_package(Gitinfo)
git_version_info(NAME)

message(STATUS "Configuring NAME version: ${NAME_VERSION}(${NAME_VERSION_MAJOR}.${NAME_VERSION_MINOR}.${NAME_VERSION_PATCH})")