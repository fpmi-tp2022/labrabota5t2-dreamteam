@echo off

set build_folder="./build"
set mypath=%~dp0
echo %mypath%

cd %mypath%
rmdir /S /Q %build_folder%
mkdir %build_folder%
cd %build_folder%
cmake ../
cd ..