int connectCouples(int *seatArrangement, const int numSeats){
    int findValue;
    int tempValue;
    int totalSwaps = 0;
    
    if (numSeats == 0)
        return 0;
    
    for(int i = 0; i < (numSeats - 1); i++){
        if(seatArrangement[i] % 2 == 0)
            findValue = (seatArrangement[i] + 1);
        else
            findValue = (seatArrangement[i] - 1);
        
        if(seatArrangement[i+1] == findValue || seatArrangement[i -1] == findValue)
            continue;

        
        for(int j = i + 1; j < numSeats; j++){
            if(seatArrangement[j] == findValue){
                tempValue = seatArrangement[i + 1];
                seatArrangement[i + 1] = seatArrangement[j];
                seatArrangement[j] = tempValue;
                totalSwaps++;
                continue;
            }
        }
    }
    return totalSwaps;
}
