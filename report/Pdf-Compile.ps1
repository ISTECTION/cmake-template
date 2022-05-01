Set-content -Path .\src\code\_abspath.tex -Value ("\newcommand{\abspath}{" + ((Get-Location) -replace '\\', '/') + "/src/code/}")
tectonic -X build