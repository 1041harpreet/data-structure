// n persons of different height h(i) are standing in a queue. Distribute chocolates among people in such a way that

// person i gets more chocolate than person i-1 and i+1 if h(i-1)<h(i) and h(i)>h(j+1)
// every one gets atleat one chocolate
// Find how many min chocolates are required.

// Example :
// height : 1,10,8,7,6,5,11

// Chocolate given 1, 5, 4, 3, 2, 1, 2
// total chocolate : 18

/*
    This function finds the minimum difference between the maximum and minimum packets
    chosen by 'numStudents' students from a given list of 'numPackets' packets
*/
// int findMinimumDifference(vector<int>& packets, int numStudents) {
//     int numPackets = packets.size();
    
//     // If the number of packets is less than the number of students, it is invalid
//     if (numPackets < numStudents)
//         return -1;
    
//     // Initializing minimum difference to maximum value
//     int minDifference = INT_MAX;
    
//     //Sorting the packets in ascending order.
//     sort(packets.begin(),packets.end());
    
//     // Loop through the packets to find the minimum difference
//     for (int i = 0; i <= numPackets - numStudents; i++) {
        
//         // Find the maximum and minimum packets in the current window
//         int maxPacket = packets[i+numStudents-1];
//         int minPacket = packets[i];
        
//         // Update the minimum difference if the current difference is smaller
//         int difference = abs(maxPacket - minPacket);
        
//         if (difference < minDifference)
//             minDifference = difference;
//     }
//     return minDifference;
// }