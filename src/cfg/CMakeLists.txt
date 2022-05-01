configure_file(
    config.hpp.in
    ${PROJECT_SOURCE_DIR}/include/config/config.hpp
    @ONLY)

# Тег @ONLY - разрешате редактирование только переменных вида @VAR@
# В то время как переменные вида ${VAR} будут не тронуты