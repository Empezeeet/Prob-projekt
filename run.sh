#!/bin/bash
set -e
mkdir -p build
cd build
mkdir -p saves
g++ ../main.cpp ../Manager/Manager.cpp ../Utils/replace.cpp ../AppManager/AppManager.cpp -o soft.exe;
./soft.exe;