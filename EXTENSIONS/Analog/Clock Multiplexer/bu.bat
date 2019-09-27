@echo off
cls
echo Backing up Schematic and Board file in .\bu folder


copy "Clock Multiplexer.brd" .\bu"
copy "Clock Multiplexer.sch" .\bu"
echo done
pause