#include "Course.hpp"

using namespace std;

Course::Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) : title (title), day (day), start_time (start_time), finish_time (finish_time)
{
}
Course::Course (const Course & m) : title (m.title), day (m.day), start_time (m.start_time), finish_time (m.finish_time)
{
}

bool Course::operator == (const Course & m) const {
    //TODO implement the operator
    if (day != m.day) {
        return false;
    }

    if (finish_time > m.start_time) {
        return true;
    }

    return false;
}

bool Course::operator<(const Course & m) const
{
    //TODO implement the operator
    if (day != m.day) {
        return day < m.day;
    }

    if (start_time != m.start_time) {
        return start_time < m.start_time;
    }

    if (finish_time != m.finish_time) {
        return finish_time < m.finish_time;
    }

    return false;
}

ostream & operator << (ostream &os, const Course & m)
{
    char day;
    if (m.day == 0) {
        day = 'M';
    }
    else if (m.day == 1) {
        day = 'T';
    }
    else if (m.day == 2) {
        day = 'W';
    }
    else if (m.day == 3) {
        day = 'R';
    }
    else if (m.day == 4) {
        day = 'F';
    }
    else if (m.day == 5) {
        day = 'S';
    }
    //TODO implement the operator
    cout << m.title << " " << day << " " << m.start_time << " " << m.finish_time;

    return os;
}