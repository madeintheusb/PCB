cls
write-host "Removing un-needed files"
pause
Remove-Item -rec  -path .\* -include "*.s#?" # -whatif
write-host "Done"

