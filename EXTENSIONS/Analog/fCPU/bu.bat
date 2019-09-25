@echo off
cls
echo Backing up Schematic and Board file in .\bu folder


copy "fCPU.brd" .\bu"
copy "fCPU.sch" .\bu"
echo done
pause