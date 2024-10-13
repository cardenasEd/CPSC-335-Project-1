#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


// helper function to flip military hours to minutes
int timeToMinutes(const std::string& timeStr) {
    int hours = stoi(timeStr.substr(0, 2));
    int minutes = stoi(timeStr.substr(3, 2));
    return hours * 60 + minutes;
}

// helper function to flip minutes to military hours
std::string minutesToTime(int minutes) {
    int hours = minutes / 60;
    int mins = minutes % 60;
    return (hours < 10 ? "0" : "") + std::to_string(hours) + ":" + (mins < 10 ? "0" : "") + std::to_string(mins);

}

// Function to find free intervals given busy times and working period
std::vector<std::pair<std::string, std::string>> findFreeIntervals(std::vector<std::pair<std::string, std::string>>& busyTimes, const std::string& workStart, const std::string& workEnd) {
    std::vector<std::pair<std::string, std::string>> available;


    // Sort the busy times based on start times
    sort(busyTimes.begin(), busyTimes.end());

    // Find free time before the first busy interval
    if (timeToMinutes(busyTimes[0].first) > timeToMinutes(workStart)) {
        available.push_back({workStart, busyTimes[0].first});
    }

    // Find gaps between busy intervals
    for (size_t i = 0; i < busyTimes.size() - 1; ++i) {
        int endOfCurrent = timeToMinutes(busyTimes[i].second);
        int startOfNext = timeToMinutes(busyTimes[i + 1].first);
        if (endOfCurrent < startOfNext) {
            available.push_back({minutesToTime(endOfCurrent), minutesToTime(startOfNext)});
        }
    }

    // Find free time after the last busy interval
    if (timeToMinutes(busyTimes.back().second) < timeToMinutes(workEnd)) {
        available.push_back({busyTimes.back().second, workEnd});
    }

    return available;
}


