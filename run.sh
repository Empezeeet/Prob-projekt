#!/bin/bash
set -e
g++ main.cpp Manager.cpp replace.cpp -o soft;
./soft;