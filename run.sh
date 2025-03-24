#!/bin/bash
set -e
g++ main.cpp Manager/Manager.cpp Utils/replace.cpp AppManager/AppManager.cpp -o soft;
./soft;