@echo off
cls
echo Backing up Schematic and Board file in .\bu folder
del "*.b#?"

copy "UpTo11.FrontPanel.brd" .\bu"
copy "UpTo11.FrontPanel.sch" .\bu"
echo done
pause