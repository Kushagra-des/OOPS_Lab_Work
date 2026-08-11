#include <iostream> 
#include <cmath>    

int main() {
    // Finds 4-digit perfect squares of the form AABB
    for (int num = 1000; num < 10000; num++) {
        // Added std:: namespace prefix for C++ compatibility
        int squareRoot = (int)std::sqrt(num); 
        
        if (squareRoot * squareRoot == num) {
            int firstTwoDigits = num / 100;
            int lastTwoDigits = num % 100;
            
            // Check if first two digits match (AA) and last two digits match (BB)
            if (firstTwoDigits / 10 == firstTwoDigits % 10 && lastTwoDigits / 10 == lastTwoDigits % 10) {
                int A = firstTwoDigits / 10;
                int B = lastTwoDigits / 10;
                
                if (A != B) {
                    // Replaced printf with standard C++ output stream
                    std::cout << num << " is a four-digit perfect square of the form AABB\n"; 
                }
            }
        }
    }
    return 0;
}
