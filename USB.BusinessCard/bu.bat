@echo off
cls
echo Backing up Schematic and Board file in .\bu folder


copy "USB.BusinessCard.brd" .\bu"
copy "USB.BusinessCard.sch" .\bu"
echo done
pause