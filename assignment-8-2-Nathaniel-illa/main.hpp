#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// Function prototypes
void fillvector(vector<int> &, int size);
int getTarget(const vector<int> &);
int binSearch(const vector<int> &, int, int &);
int LinearSearch(const vector<int> &, int, int &);
void print(const vector<int> &);

// Function to fill the vector with random values
void fillvector(vector<int> &numbers, int N) {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < N; i++)
        numbers.push_back(rand() % 1000);
}

// Function to get a target value from the vector
int getTarget(const vector<int> &numbers) {
    int index = rand() % numbers.size();
    return numbers[index];
}

// Implementation of Linear Search
int LinearSearch(const vector<int> &numbers, int target, int &cmpcnt) {
    for (int i = 0; i < numbers.size(); i++) {
        cmpcnt++;
        if (numbers[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

// Implementation of Binary Search
int binSearch(const vector<int> &numbers, int target, int &cmpcnt) {
    int left = 0;
    int right = numbers.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoids overflow
        cmpcnt++;

        if (numbers[mid] == target) {
            return mid; // Return index if found
        } else if (numbers[mid] > target) {
            right = mid - 1; // Search left half
        } else {
            left = mid + 1; // Search right half
        }
    }
    return -1; // Return -1 if not found
}

// Function to print the contents of the vector
void print(const vector<int> &numbers) {
    for (auto v : numbers)
        cout << v << "\t";
    cout << endl;
}

#endif // MAIN_HPP