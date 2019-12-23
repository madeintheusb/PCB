@echo off
cls
echo Backing up Schematic and Board file in .\bu folder

del "*.s#?"
del "*.b#?"
copy "USB Multiplicator.brd" .\bu"
copy "USB Multiplicator.sch" .\bu"
echo done
pause