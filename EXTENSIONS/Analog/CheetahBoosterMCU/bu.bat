@echo off
cls
echo Backing up Schematic and Board file in .\bu folder

del "*.b#?"
del "*.s#?"

copy "CheetahBoosterMCU.brd" .\bu"
copy "CheetahBoosterMCU.sch" .\bu"
echo done
pause