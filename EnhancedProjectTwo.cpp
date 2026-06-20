//============================================================================
// Name        : EnhancedProjectTwo.cpp
// Author      : Thy Tran
// Version     : 2.0
// Copyright   : Copyright © 2025
// Description : Enhanced Hash Table Course Planner
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

// Hash table for courses
unordered_map<string, Course> courses;

// Graph representation (prerequisite -> dependent courses)
unordered_map<string, vector<string>> prerequisiteGraph;

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

    unordered_map<string, Course> loadedCourses;

    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "File cannot be opened: " << fileName << endl;
        return loadedCourses;
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

        // Load prerequisites
        for (size_t i = 2; i < fields.size(); i++) {

            string prereq = toUpperCase(fields[i]);

            if (!prereq.empty()) {
                course.prerequisites.push_back(prereq);

                // Build graph edge: prereq -> course
                prerequisiteGraph[prereq].push_back(course.courseNumber);
            }
        }

        loadedCourses[course.courseNumber] = course;
    }

    file.close();

    return loadedCourses;
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
    }
    else {
        cout << "Prerequisites: ";

        for (size_t i = 0; i < course.prerequisites.size(); i++) {
            cout << course.prerequisites[i];
            if (i < course.prerequisites.size() - 1) {
                cout << ", ";
            }
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

// DFS traversal for the prerequisite chain
void printPrerequisiteChain(
    const unordered_map<string, Course>& courses,
    const string& courseNumber,
    unordered_map<string, bool>& visited) {

    if (visited[courseNumber]) {
        return;
    }

    visited[courseNumber] = true;

    auto it = courses.find(courseNumber);

    if (it == courses.end()) {
        return;
    }

    for (const string& prereq : it->second.prerequisites) {
        printPrerequisiteChain(courses, prereq, visited);
    }

    cout << courseNumber << " - " << it->second.name << endl;
}

// Main Program - Menu Options
int main() {

    int choice = 0;

    cout << "Welcome to the course planner." << endl;

    while (choice != 9) {

        cout << "\n";
        cout << "1. Load Data Structure." << endl;
        cout << "2. Print Course List." << endl;
        cout << "3. Print Course." << endl;
        cout << "4. Print Prerequisite Chain." << endl;
        cout << "9. Exit\n" << endl;

        cout << "What would you like to do? ";
        cin >> choice;

        switch (choice) {

        case 1:
            courses = loadCourses("CS 300 ABCU_Advising_Program_Input.csv");

            if (!courses.empty()) {
                cout << "Courses loaded successfully." << endl;
            }
            break;

        case 2:
            if (courses.empty()) {
                cout << "Please load courses first (option 1)." << endl;
            }
            else {
                printCourseList(courses);
            }
            break;

        case 3: {
            if (courses.empty()) {
                cout << "Please load courses first (option 1)." << endl;
                break;
            }

            string courseNumber;

            cout << "What course do you want to know about? ";
            cin >> courseNumber;

            printCourse(courses, courseNumber);

            break;
        }

        case 4: {
            if (courses.empty()) {
                cout << "Please load courses first (option 1)." << endl;
                break;
            }

            string courseNumber;

            cout << "Enter course number: ";
            cin >> courseNumber;

            courseNumber = toUpperCase(courseNumber);

            if (courses.find(courseNumber) == courses.end()) {
                cout << "Course not found." << endl;
                break;
            }

            unordered_map<string, bool> visited;

            cout << "\nPrerequisite Chain:\n";

            printPrerequisiteChain(courses, courseNumber, visited);

            break;
        }

        case 9:
            cout << "Thank you for using the course planner!" << endl;
            break;

        default:
            cout << choice << " is not a valid option." << endl;
        }
    }

    return 0;
}