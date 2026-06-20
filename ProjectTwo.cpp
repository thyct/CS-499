//============================================================================
// Name        : ProjectTwo.cpp
// Author      : Thy Tran
// Version     : 1.0
// Copyright   : Copyright � 2025 
// Description : Hash Table Course Planner
//============================================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype> 

using namespace std;

// Course Structure
struct Course {
    string courseNumber;
    string name;
    vector<string> prerequisites;
};

// Convert string to uppercase
string toUpperCase(const string& str) {
    string result = str;
    for (char& c : result) {
        c = toupper(c);
    }
    return result;
}

// Load Courses from CSV
unordered_map<string, Course> loadCourses(const string& fileName) {
    unordered_map<string, Course> courses;

    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "File cannot be opened: " << fileName << endl;
        return courses;
    }
    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string token;
        vector<string> fields;

        while (getline(ss, token, ',')) {
            fields.push_back(token);
        }
        if (fields.size() < 2) continue;

        Course course;
        course.courseNumber = toUpperCase(fields[0]); 
        course.name = fields[1];
        for (size_t i = 2; i < fields.size(); ++i) {
            if (!fields[i].empty()) {
                course.prerequisites.push_back(toUpperCase(fields[i])); 
            }
        }
        courses[course.courseNumber] = course;
    }
    file.close();
    return courses;
}

// Print Course Information
void printCourse(const unordered_map<string, Course>& courses, string courseNumber) {
    courseNumber = toUpperCase(courseNumber);

    auto it = courses.find(courseNumber);
    if (it == courses.end()) {
        cout << "Course not found." << endl;
        return;
    }
    const Course& course = it->second;
    cout << course.courseNumber << ", " << course.name << endl;

    if (course.prerequisites.empty()) {
        cout << "No prerequisites" << endl;
    } else {
        cout << "Prerequisites: ";
        for (size_t i = 0; i < course.prerequisites.size(); ++i) {
            cout << course.prerequisites[i];
            if (i < course.prerequisites.size() - 1) cout << ", ";
        }
        cout << endl;
    }
}

// Print Course List - Alphanumeric Order
void printCourseList(const unordered_map<string, Course>& courses) {
    vector<Course> list;
    for (const auto& pair : courses) {
        list.push_back(pair.second);
    }
    sort(list.begin(), list.end(),
         [](const Course& a, const Course& b) {
             return a.courseNumber < b.courseNumber;
         });
    cout << "Here is a sample schedule:" << endl;
    for (const Course& course : list) {
        cout << course.courseNumber << ", " << course.name << endl;
    }
}

// Main Program - Menu Options
int main() {
    unordered_map<string, Course> courses;
    int choice = 0;

    cout << "Welcome to the course planner. " << endl;

    while (choice != 9) {
        cout << '\n';
        cout << "1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "9. Exit \n" << endl;
        cout << "What would you like to do? ";
        cin >> choice;

        switch (choice) {
            case 1:
                courses = loadCourses("CS 300 ABCU_Advising_Program_Input.csv");
                if (!courses.empty()) {
                    cout << "Courses loaded successfully. " << endl;
                }
                break;
            case 2:
                if (courses.empty()) {
                    cout << "Please load courses first (option 1). " << endl;
                } else {
                    printCourseList(courses);
                }
                break;
            case 3: {
                if (courses.empty()) {
                    cout << "Please load courses first (option 1). " << endl;
                    break;
                }
                string courseNumber;
                cout << "What course do you want to know about? ";
                cin >> courseNumber;
                printCourse(courses, courseNumber);
                break;
            }
            case 9:
                cout << "Thank you for using the course planner!" << endl;
                break;

            default:
                cout << choice << " is not a valid option. " << endl;
        }
    }
    return 0;
}