@echo off
cls
echo Backing up Schematic and Board file in .\bu folder
del "*.b#?"
del "*.s#?"

copy "4017-7Segment.brd" .\bu"
copy "4017-7Segment.sch" .\bu"
echo done
pause