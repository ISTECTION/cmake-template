message(STATUS "Генерация файла `report/Tectonic.toml`")
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Tectonic.toml.in
    ${CMAKE_SOURCE_DIR}/report/Tectonic.toml
    @ONLY)

message(STATUS "Генерация файла `report/code/_abspath.tex`")
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/_abspath.tex.in
    ${CMAKE_SOURCE_DIR}/report/src/code/_abspath.tex
    @ONLY)