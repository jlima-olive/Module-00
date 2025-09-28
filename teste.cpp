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

	// Get individual components
    int year = tm.tm_year + 1900;  // tm_year is years since 1900
    int month = tm.tm_mon + 1;     // tm_mon is 0-11
    int day = tm.tm_mday;
    int hour = tm.tm_hour;
    int minute = tm.tm_min;
    int second = tm.tm_sec;
    
	printf("%d%d%d%D")

    // std::cout << tm.tm_year + 1900 << tm.tm_mon + 1 << tm.tm_mday << '_';
    // std::cout << tm.tm_hour << tm.tm_min << tm.tm_sec;
}