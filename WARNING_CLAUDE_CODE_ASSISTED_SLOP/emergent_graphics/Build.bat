@echo off
:: Compile the DLL
g++ -shared -o logic.dll Logic.cpp -I. -lraylib

:: Compile the Host
g++ Host.cpp -o Host.exe -I. -lraylib -lgdi32 -lwinmm

echo Build Complete!
