#!/bin/bash
clear;
set -e
mkdir -p build
cd build
mkdir -p saves
g++ ../main.cpp ../Utils/time.cpp ../Structs/Auto/Auto.cpp ../Structs/Wpis/Wpis.cpp ../Manager/Manager.cpp ../Utils/replace.cpp ../AppManager/AppManager.cpp ../Utils/selector.cpp ../StatsCalculator/StatsCalculator.cpp -o soft -std=c++0x;
./soft;