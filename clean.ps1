cls
write-host "Removing un-needed files"
pause
Remove-Item -rec  -path .\* -include "*.s#?" # -whatif
Remove-Item -rec  -path .\* -include "*.b#?" # -whatif
write-host "Done"

