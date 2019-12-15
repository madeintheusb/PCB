@echo off
cls
echo Backing up Schematic and Board file in .\bu folder


copy "OneLedBlinker.brd" .\bu"
copy "OneLedBlinker.sch" .\bu"
echo done
pause