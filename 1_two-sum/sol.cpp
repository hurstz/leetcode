#include <vector> // Bring in header file to allow for creation and use of vector
#include <unordered_map> // Same as above but for unordered_map

class Solution { // Define a class named Solution

public: // Make the following method(s) public (accessible outside of the class)

        // Define a method named twoSum that takes a reference to a vector of integers ("nums") and an integer ("target"), and returns a vector of integers
    std::vector<int> twoSum(std::vector<int>& nums, int target) { // Open the twoSum method

        // Create an unordered_map (hash map) named numMap to store numbers from the array as keys and their indices as values
        std::unordered_map<int, int> numMap; // Key is an integer from the array, value is the key's index
        
        // Set up a loop to iterate over each element of the vector "nums" using iterator variable of "i"
        for (int i = 0; i < nums.size(); ++i) { // Open the for loop
            int complement = target - nums[i]; // Calculate the current number's complement

            // What is a complement?
            // The complement is the value that, when added to the current number, equals the target sum.
            // It's useful because it allows us to solve the Two Sum problem in a single pass through the array.
            // Instead of checking every pair of numbers, we can check if each number's complement exists in our hash map.

            // Check for the existence of the complement within the map
            if (numMap.find(complement) != numMap.end()) { // Open the if statement
                // Return a vector with the indices of the current number and its complement
                return {numMap[complement], i};
            } // Close the if statement
            
            // Add the current number and corresponding index to the hash map ("numMap")
            numMap[nums[i]] = i;
        } // Close the for loop
        
        // Return empty vector if no solution (would not happen within the constraints of this problem)
        return {}; // Included in the best interest of using best practices and handling edge cases

    } // Close the twoSum method
}; // Close the Solution class
