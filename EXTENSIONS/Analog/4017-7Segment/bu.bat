@echo off
cls
echo Backing up Schematic and Board file in .\bu folder
copy *.brd .\bu
copy *.sch .\bu
echo done
pause