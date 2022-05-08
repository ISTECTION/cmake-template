configure_file(
    config.hpp.in
    ${PROJECT_SOURCE_DIR}/include/config/config.hpp
    @ONLY)

# Тег @ONLY - разрешате редактирование только переменных вида @VAR@
# В то время как переменные вида ${VAR} будут не тронуты

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/module" ${CMAKE_MODULE_PATH})
# include(GetVersionFromGitTag)

find_package(GitInfo)
git_version_info(V1)

message(STATUS "Configuring NAME version: ${V1_VERSION_MAJOR}.${V1_VERSION_MINOR}.${V1_VERSION_PATCH}")