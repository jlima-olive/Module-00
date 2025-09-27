#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>

int main()
{
	std::chrono::time_point now = std::chrono::system_clock::now();
    long time_t = std::chrono::system_clock::to_time_t(now);
    tm tm = *std::localtime(&time_t);

	printf("[%4d%02d%02d_", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
	printf("%02d%02d%02d]", tm.tm_hour, tm.tm_min, tm.tm_sec);
}