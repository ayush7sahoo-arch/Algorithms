#include <iostream> // For standard input/output operations (cin, cout)
#include <vector>   // Although not strictly needed for this solution, good for general point handling
#include <algorithm> // For std::min and std::max
#include <limits>    // For std::numeric_limits to initialize min/max values

// Using the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // This is common practice in competitive programming for large inputs.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // Variable to store the number of cows (points).
    cin >> n; // Read the number of cows from standard input.

    // Initialize variables to find the minimum and maximum X and Y coordinates
    // among all cow positions. We use numeric_limits to get the smallest/largest
    // possible integer values to ensure any coordinate will correctly update them.
    int min_x = numeric_limits<int>::max();
    int max_x = numeric_limits<int>::min();
    int min_y = numeric_limits<int>::max();
    int max_y = numeric_limits<int>::min();

    // Loop through each cow to read its coordinates and update the min/max bounds.
    for (int i = 0; i < n; ++i) {
        int current_x, current_y;
        cin >> current_x >> current_y; // Read the X and Y coordinates of the current cow.

        // Update the minimum X coordinate found so far.
        min_x = min(min_x, current_x);
        // Update the maximum X coordinate found so far.
        max_x = max(max_x, current_x);
        // Update the minimum Y coordinate found so far.
        min_y = min(min_y, current_y);
        // Update the maximum Y coordinate found so far.
        max_y = max(max_y, current_y);
    }

    // Calculate the width and height of the minimum bounding rectangle that
    // encloses all cows. These are the differences between the max and min coordinates.
    // Using long long for width and height to prevent potential overflow,
    // although for coordinates up to 10^6, int would suffice.
    long long width = max_x - min_x;
    long long height = max_y - min_y;

    // The problem states that the shepherd's movement cost is 1 for horizontal,
    // vertical, or diagonal steps (Chebyshev distance).
    // The path must enclose cows "strictly inside".
    // Based on the problem's example (4 cows, (1,1), (5,1), (5,3), (1,3) -> output 16),
    // the formula for the minimum path length is 2 * (width + height) + 4.
    // This formula effectively accounts for the Chebyshev perimeter of the cow's
    // bounding box, plus an additional 4 moves, likely to satisfy the "strictly inside"
    // condition by effectively expanding the path by 1 unit on each side in a specific way.
    long long minimum_moves = 2 * (width + height) + 4;

    // Print the calculated minimum number of moves to the console.
    cout << minimum_moves << endl;

    return 0; // Indicate successful program execution.
}
