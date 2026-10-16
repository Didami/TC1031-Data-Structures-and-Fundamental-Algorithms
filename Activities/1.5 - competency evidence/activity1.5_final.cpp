/*
    Activity 1.5 - Comprehensive Activity of Basic Concepts and Fundamental Algorithms (Competency Evidence)
    Description: This project is a C++ program that processes and manages system logs stored in a text file. It uses Quick Sort (due to its time and space complexity) to organize logs chronologically by date and time, allowing users to filter records within a specified date range. The filtered logs can be displayed on the console and exported to a separate text file. The project implements fundamental algorithms, including sorting and binary search, as well as file handling, data structures, and object-oriented programming.
    Authors: Diego Flores Álvarez (A01788809) & Miguel Tejero de la Fuente (A01788818)
    Delivery date: 16/10/26
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#define monthFactor 100000000
#define dayFactor 1000000
#define hourFactor 10000
#define minuteFactor 100

using namespace std;

/// Helper method that calculates timestamp for a date using the correct factors `month` and `day`.
int dateTimestamp(int month, int day) { 
    return month * monthFactor + day * dayFactor;
}

/// Class that models each line of `binnacle.txt` as a log.
class Log {
    private:
    string month;
    int day;
    string time;

    int timestamp;

    string ip;
    string message;

    /// Private method that returns the corresponding index for each month in the corresponding format.
    int monthToNum(string monthStr) {
        string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        for (int i = 0; i < 12; i++) {
            if (months[i] == monthStr) 
                return i + 1;
        }
        return 0;
    }

    /// Private method that converts a formatted time string to an int.
    int timeToNum(string time) {
        int hours = stoi(time.substr(0, 2)); 
        int minutes = stoi(time.substr(3, 2));
        int seconds = stoi(time.substr(6, 2));

        return hours * hourFactor + minutes * minuteFactor + seconds;
    }

    public:
    Log() {}

    Log(string month, int day, string time, string ip, string message) {
        this->month = month;
        this->day = day;
        this->time = time;
        this->timestamp =  dateTimestamp(monthToNum(month), day) + timeToNum(time);
        this->ip = ip;
        this->message = message;
    }

    int getTimestamp() {
        return timestamp;
    }

    void print() {
        cout << month << " " << day << " " << time << " " << ip << " " << message << endl;
    }

    void save(ofstream &file) {
        file << month << " "
             << day << " "
             << time << " "
             << ip << " "
             << message
             << endl;
    }
};

/// Auxiliar method for `quickSort`.
int partition(vector<Log> &logs, int low, int high) {
    int pivot = logs[high].getTimestamp();
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (logs[j].getTimestamp() < pivot) {
            i++;
            swap(logs[i], logs[j]);
        }
    }
    swap(logs[i+1], logs[high]);
    return i+1;
}

/// Quick Sort: The algorithm selects a pivot element and rearranges the list so that all elements smaller than the pivot appear on its left, and all greater elements on its right. Time Complexity (Average): `O(n log n)`. Space Complexity: `O(log n)` avg / `O(n)` worst.
void quickSort(vector<Log> &logs, int low, int high) {
    if (low >= high)
        return;
    int pi = partition(logs, low, high);
    quickSort(logs, low, pi-1);
    quickSort(logs, pi+1, high);
}

/// Binary Search: The list must be sorted. It works by dividing the search space into two halves by finding the middle index. The middle element is compared with the `target`. If it is equal, the middle index is returned. If it is less than the `target`, the right side is used for the next search. If it is greater, the left side is used for the next search. This process is continued until the key is found or the total search space is exhausted. Time Complexity: `O(log n)`. Space Complexity: `O(1)`.
int binarySearch(vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (target > nums[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

/// Helper method that asks user for a date input (month and day) with a custom message. Includes dates validation.
int dateInput(string message) {
    int month = 0, day = 0;
    int dayAmount = 2;
    vector<int> thirtyDayMonths = {4, 6, 9, 11};

    cout << message << endl;
    while (month < 1 || month > 12) {
        cout << "- Month (1: Jan, 2: Feb, 3: Mar, etc.): ";
        cin >> month;
    }
    if (month == 2)
        dayAmount = 0;
    else if (binarySearch(thirtyDayMonths, month) != -1)
        dayAmount = 1;

    while (day < 1 || ((dayAmount == 2 && day > 31) || (dayAmount == 1 && day > 30) || (dayAmount == 0 && day > 28))) {
        cout << "- Day: ";
        cin >> day;
    }

    return dateTimestamp(month, day);
}

/// Helper method that filters a `vector<Log>` within a `startDate` and `endDate` range.
vector<Log> filter(vector<Log> &logs, int startDate, int endDate) {
    vector<Log> newLogs;

    for (int i = 0; i < logs.size(); i++) {
        if (logs[i].getTimestamp() >= startDate && logs[i].getTimestamp() <= (endDate + dayFactor))
            newLogs.push_back(logs[i]);
    }
    
    return newLogs;
}

/// Helper method that save a `vector<Log>` to a new `.txt` file by using `ofstream`.
void saveLogs(vector<Log> &logs) {
    ofstream file("./filtered.txt");

    for (Log log : logs) {
        log.save(file);
    }

    file.close();
}

// MAIN
int main() {
    // INIT LOGS
    int ans = 0;
    vector<Log> logs;
    vector<Log> filtered;

    string line, values[5];
    ifstream file("binnacle.txt");

    while (getline(file, line)) {
        stringstream ss(line);

        string month, time, ip, message;
        int day;

        ss >> month >> day >> time >> ip;
        getline(ss, message);

        // Remove the space before the message
        if (!message.empty() && message[0] == ' ')
            message.erase(0, 1);

        logs.push_back(Log(month, day, time, ip, message));
    }

    // SORT LOGS
    quickSort(logs, 0, logs.size() - 1);

    cout << "Loaded and sorted " << logs.size() << " logs." << endl;

    // USER INPUTS
    while (ans != 3){
        cout << endl << "Please select an option: " << endl;
        cout << "1.- Filter logs and store. (This will overwrite any previous filtered.txt; make copy if you want to keep the record)" <<endl;
        cout << "2.- Show Filtered logs." << endl;
        cout << "3.- End." << endl;
        cin >> ans;
        if (ans ==  1){
            int startDate = dateInput("ENTER START DATE:");
            int endDate;
            
            do {
                endDate = dateInput("ENTER END DATE:");
                if (endDate < startDate)
                    cout << "End date cannot be earlier than start date.\n";
            } while (endDate < startDate);

            filtered = filter(logs, startDate, endDate);
            saveLogs(filtered);
            cout << "Saved " << filtered.size() << " filtered logs on 'filtered.txt'!" << endl;
        } else if (ans == 2) {
            if (filtered.size() == 0)
                cout << "No logs have been filtered yet." << endl;
            for (int i = 0; i < filtered.size(); i++)
                filtered[i].print();
        }
    }
    cout << "Thanks for using our program!" << endl;
    return 0;
}