configure_file(
    config.hpp.in
    ${PROJECT_SOURCE_DIR}/include/config/config.hpp
    @ONLY)

# Тег @ONLY - разрешате редактирование только переменных вида @VAR@
# В то время как переменные вида ${VAR} будут не тронуты

# set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/module" ${CMAKE_MODULE_PATH})
# include(GetVersionFromGitTag)

# message(STATUS "${CMAKE_MODULE_PATH}")
# message(STATUS "Версия ${PROJECT_NAME}: ${${PROJECT_NAME}_VERSION_STRING}")