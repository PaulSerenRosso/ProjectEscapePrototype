@echo on

REM CLEAR UNEEDED FILES

RD /s /q Intermediate
RD /s /q Saved
RD /s /q Binaries
RD /s /q Script
RD /s /q .vs
RD /s /q DerivedDataCache
DEL *.sln
RD /s /q .idea
Rem DEL *.bin