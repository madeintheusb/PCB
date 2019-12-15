@echo off
cls
echo Backing up Schematic and Board file in .\bu folder


copy "UpTo11.MotherBoard.brd" .\bu"
copy "UpTo11.MotherBoard.sch" .\bu"
echo done
pause