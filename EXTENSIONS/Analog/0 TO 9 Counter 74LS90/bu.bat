@echo off
cls
echo Backing up Schematic and Board file in .\bu folder

del "*.job"
del "*.s#?"
del "*.b#?"
copy "0 TO 9 Counter 74LS90.brd" .\bu"
copy "0 TO 9 Counter 74LS90.sch" .\bu"
echo done
pause