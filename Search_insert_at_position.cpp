#include <vector> // Include the vector library for using vectors

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) { // Function definition, taking a vector of integers and an integer target as arguments
        int low = 0; // Initialize a variable to store the lowest index
        int high = nums.size(); // Initialize a variable to store the highest index (size of the vector)
        int mid; // Declare a variable to store the middle index
        
        if (target > nums[high - 1]) { // Check if the target is greater than the last element in the vector
            return high; // If yes, return the index after the last element
        }
        
        while (low <= high) { // Start a loop that runs until low is less than or equal to high
            mid = (low + high) / 2; // Calculate the middle index
            
            if (nums[mid] == target) { // Check if the element at the middle index is equal to the target
                return mid; // If yes, return the middle index
            }
            
            if (target < nums[mid]) { // If the target is less than the element at the middle index
                high = mid - 1; // Update the high index to be one less than the middle index
            } else { // If the target is greater than the element at the middle index
                low = mid + 1; // Update the low index to be one more than the middle index
            }
        }
        
        return low; // If the target is not found, return the current low index
    }
};
#include <vector> // Include the vector library for using vectors

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) { // Function definition, taking a vector of integers and an integer target as arguments
        int low = 0; // Initialize a variable to store the lowest index
        int high = nums.size(); // Initialize a variable to store the highest index (size of the vector)
        int mid; // Declare a variable to store the middle index
        
        if (target > nums[high - 1]) { // Check if the target is greater than the last element in the vector
            return high; // If yes, return the index after the last element
        }
        
        while (low <= high) { // Start a loop that runs until low is less than or equal to high
            mid = (low + high) / 2; // Calculate the middle index
            
            if (nums[mid] == target) { // Check if the element at the middle index is equal to the target
                return mid; // If yes, return the middle index
            }
            
            if (target < nums[mid]) { // If the target is less than the element at the middle index
                high = mid - 1; // Update the high index to be one less than the middle index
            } else { // If the target is greater than the element at the middle index
                low = mid + 1; // Update the low index to be one more than the middle index
            }
        }
        
        return low; // If the target is not found, return the current low index
    }
};
#include <vector> // Include the vector library for using vectors

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) { // Function definition, taking a vector of integers and an integer target as arguments
        int low = 0; // Initialize a variable to store the lowest index
        int high = nums.size(); // Initialize a variable to store the highest index (size of the vector)
        int mid; // Declare a variable to store the middle index
        
        if (target > nums[high - 1]) { // Check if the target is greater than the last element in the vector
            return high; // If yes, return the index after the last element
        }
        
        while (low <= high) { // Start a loop that runs until low is less than or equal to high
            mid = (low + high) / 2; // Calculate the middle index
            
            if (nums[mid] == target) { // Check if the element at the middle index is equal to the target
                return mid; // If yes, return the middle index
            }
            
            if (target < nums[mid]) { // If the target is less than the element at the middle index
                high = mid - 1; // Update the high index to be one less than the middle index
            } else { // If the target is greater than the element at the middle index
                low = mid + 1; // Update the low index to be one more than the middle index
            }
        }
        
        return low; // If the target is not found, return the current low index
    }
};
