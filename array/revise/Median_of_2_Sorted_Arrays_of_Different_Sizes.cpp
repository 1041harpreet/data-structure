// 1 store all elemment in new array and then sort , find median now, t and space complexity is high
//2

//     public:
//     double MedianOfArrays(vector<int>& array1, vector<int>& array2)
//     {
//         int i =0;
//         int j=0;
//         int m1=-1;
//         int m2=-1;
//         for(int count=0;count<=(array1.size()+array2.size())/2;count++ ){
//             m2=m1; // store m1 into m2 for even case
//             //calculate m1
//             if(i !=array1.size()&& j !=array2.size()){
//                 if(array1[i] <array2[j]){
//                     m1=array1[i];
//                     i++;
//                 }else{
//                     m1=array2[j];
//                     j++;
//                 }
//             }
//             else if(i<array1.size()){
//                 m1=array1[i++];
//             }else{
//                 m1=array2[j++];
//             }
//         } 
//         if((array1.size()+array2.size()) %2==1){
//             //odd case
//             return m1;
//         }else{
//             //even case;
//             return (m1+m2)/2.0;
//         }
//     }
// };

// Median of two sorted arrays of different sizes using Priority Queue: 
// The Idea is simple, just push the elements into a single Priority Queue from both arrays.
//  Now we have to find median from priority queue by performing a simple traversal through it upto median.


//4 Median of two sorted arrays of different sizes using Binary Search:
// The given two arrays are sorted, so we can utilize the ability of Binary Search to divide the array and find the median. 

// Median means the point at which the whole array is divided into two parts. Hence since the two arrays are not merged so to get the median we require merging which is costly. 

// Hence instead of merging, we will use a modified binary search algorithm to efficiently find the median.