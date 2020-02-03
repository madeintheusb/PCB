@echo off
cls
echo Backing up Schematic and Board file in .\bu folder
del "*.b#?"
del "*.s#?"

copy "CheetahBooster.brd" .\bu"
copy "CheetahBooster.sch" .\bu"
echo done
pause