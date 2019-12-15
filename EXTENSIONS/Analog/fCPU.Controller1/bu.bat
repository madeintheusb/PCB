@echo off
cls
echo Backing up Schematic and Board file in .\bu folder


copy "fCPU.Controller1.brd" .\bu"
copy "fCPU.Controller1.sch" .\bu"
echo done
pause