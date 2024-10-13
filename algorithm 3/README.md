Psuedo Code:

    Problem: want to take in schedules in Military hours then find the available meeting times. 

    Inputs: 
        List of availible times ex. (21:00, 08:00)
        list of collective times to meet
        Duration of meetup int: minutes
    Outputs:
        list of possible meetup times. 
    
    assumptions
        time is already in military hours
        int is positive 
        at least 2 people's schedule.
        time slot  are precise down to the minute.

Function findMeetingTimes(Busy_Schedules, Working_Periods, Duration):
    Input:
        Busy_Schedules: List of each person's busy time intervals
        Working_Periods: List of each person's working period [start, end]
        Duration: Minimum meeting time in minutes

    Output:
        List of available time intervals when all members are free for the specified duration

    // Step 1: Calculate available slots for each person
    availableSlots = []
    For each i from 0 to length(Busy_Schedules) - 1:
        busyTimes = Busy_Schedules[i]
        [workStart, workEnd] = Working_Periods[i]
        
        // Find available time between busy times within the working period
        personAvailable = findFreeIntervals(busyTimes, workStart, workEnd)
        availableSlots.append(personAvailable)

    // Step 2: Find common free intervals across all people
    commonSlots = availableSlots[0]
    For each i from 1 to length(availableSlots) - 1:
        commonSlots = findIntersection(commonSlots, availableSlots[i])

    // Step 3: Filter common slots for minimum meeting duration
    result = []
    For each [start, end] in commonSlots:
        If end - start >= Duration:
            result.append([start, end])

    // Step 4: Return the sorted list of available meeting times
    Return result
End Function

Function findFreeIntervals(busyTimes, workStart, workEnd):
    Input: 
        busyTimes: List of [start, end] busy intervals
        workStart, workEnd: Working period start and end times

    Output: 
        List of available [start, end] intervals within working period

    available = []
    Sort busyTimes by start time
    
    // Find free time before the first busy interval
    If workStart < busyTimes[0][0]:
        available.append([workStart, busyTimes[0][0]])

    // Find gaps between busy intervals
    For each j from 0 to length(busyTimes) - 2:
        If busyTimes[j][1] < busyTimes[j+1][0]:
            available.append([busyTimes[j][1], busyTimes[j+1][0]])

    // Find free time after the last busy interval
    If busyTimes[-1][1] < workEnd:
        available.append([busyTimes[-1][1], workEnd])

    Return available
End Function

Function findIntersection(slots1, slots2):
    Input:
        slots1, slots2: Lists of [start, end] time intervals

    Output:
        List of intersected [start, end] intervals

    intersection = []
    For each interval1 in slots1:
        For each interval2 in slots2:
            start = max(interval1[0], interval2[0])
            end = min(interval1[1], interval2[1])
            If start < end:
                intersection.append([start, end])
    
    Return intersection
End Function

Efficiency analysis

    
