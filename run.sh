#!/bin/bash
clear;
set -e
mkdir -p build
cd build
mkdir -p saves # FIXME: this should be done by program itself.
g++ ../Interfaces/ISelectable.h ../main.cpp ../Manager/Manager.cpp ../Utils/replace.cpp ../AppManager/AppManager.cpp ../Utils/selector.cpp ../StatsCalculator/StatsCalculator.cpp -g -o soft.exe;
./soft.exe;