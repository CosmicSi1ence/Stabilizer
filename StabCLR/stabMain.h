#pragma once

#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int stabMain(string sourcePath, string resultPath, uint8_t k_filter, uint8_t delta, uint8_t alg, uint8_t proc, uint8_t info, bool* close, double* timeRem, bool* stopTimer);
