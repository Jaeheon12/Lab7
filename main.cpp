#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <set>
#include "Course.hpp"

using namespace std;

/*
 * print schedule - outputs course schedule to the screen
 * @param - add any new parameters you need
 */
void printSchedule(vector<Course> &vec)
{
    //TODO implement your print using the copy algorithm, 2 iterators, and an ostream_iterator
    ostream_iterator<Course> os(cout, "\n");
    copy(vec.begin(), vec.end(), os);
}


int main () {

    //TODO read from courses.txt
    string path = "../courses.txt";

    ifstream fin{path};
    if (!fin.is_open()) {
        cout << "Failed to open a file : \"" << path << "\"" << endl;
        exit(1);
    }

    map<char, Course::dayOfWeek> m;
    m.insert(make_pair('M', Course::MON));
    m.insert(make_pair('T', Course::TUE));
    m.insert(make_pair('W', Course::WED));
    m.insert(make_pair('R', Course::THUR));
    m.insert(make_pair('F', Course::FRI));
    m.insert(make_pair('S', Course::SAT));

    //TODO store data in an STL container
    vector<Course> container;

    while (true) {
        if (fin.eof()) {
            break;
        }

        string title = "";
        char day;
        unsigned int start_time = 0;
        unsigned int finish_time = 0;

        fin >> title;
        fin >> day;
        fin >> start_time;
        fin >> finish_time;

        Course course(title, m[day], start_time, finish_time);
        container.push_back(course);
        //cout << course.title << ", " << course.day << ", " << course.start_time << ", " << course.finish_time << endl;
    }

    fin.close();

    //TODO sort your STL container with the sort algorithm
    sort(container.begin(), container.end());

    //TODO implement code to determine schedule conflicts
    //TODO print out schedule conflicts
    for (int i = 0; i < container.size() - 1; i++) {
        for (int j = i + 1; j < container.size(); j++) {
            if (container.at(i) == container.at(j)) {
                cout << "CONFLICT:" << endl;
                cout << container.at(i) << endl;
                cout << container.at(j) << endl << endl;
            }
        }
    }
    cout << '\n';

    //TODO print out schedule
    printSchedule(container);
    cout << endl;

    return 0;
}