#!/bin/bash
set -e
mkdir -p build
cd build
mkdir -p saves # FIXME: this should be done by program itself.
g++ ../main.cpp ../Manager/Manager.cpp ../Utils/replace.cpp ../AppManager/AppManager.cpp ../Utils/selector.cpp ../StatsCalculator/StatsCalculator.cpp -o soft.exe;
./soft.exe;