//1 store in new array and sort and find meadian

//2 put in any data structure for sorting

//3
//this return sum of midddles , divide by 2 to get median
// class Solution {
// public:
//    int findMidSum(int ar1[], int ar2[], int n) {
//     int first = 0;
//     int second = 0;
//     int m1 = -1;
//     int m2 = -1;

//     for (int i = 0; i <= n; i++) {
//         if (first == n) {
//             m1 = m2;
//             m2 = ar2[0];
//             break;
//         } else if (second == n) {
//             m1 = m2;
//             m2 = ar1[0];
//             break;
//         } else {
//             if (ar1[first] <ar2[second]) {
//                 m1 = m2;
//                 m2 = ar1[first];
//                 first++;
//             } else {
//                 m1 = m2;
//                 m2 = ar2[second];
//                 second++;
//             }
//         }
//     }
//     return  (m1 + m2);
// }


// };
