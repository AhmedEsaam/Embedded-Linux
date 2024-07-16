#include <iostream>
#include <iomanip>

class Time
{
public:
    /* No-Arg Constructor */
    Time() : m_hours(0), m_minutes(0), m_seconds(0)
    {
    }

    /* Multi-Arguments Comnstructor */
    Time(int hrs, int mins, int sec) : m_hours(hrs), m_minutes(mins), m_seconds(sec)
    {
    }

    /* Display Time Object */
    void display() const
    {
        std::cout << std::setw(2) << std::setfill('0') << m_hours << ":"
                  << std::setw(2) << std::setfill('0') << m_minutes << ":"
                  << std::setw(2) << std::setfill('0') << m_seconds << std::endl;
    }

    /* Adding Two Time Ibjects*/
    void add2Times(const Time &t1, const Time &t2)
    {
        /* Caculating the total nuber of seconds, minutes, and hours */
        int seconds_sum = t1.m_seconds + t2.m_seconds;
        int minutes_sum = t1.m_minutes + t2.m_minutes + (seconds_sum / 60);
        int hours_sum = t1.m_hours + t2.m_hours + (minutes_sum / 60);

        /* Get the result seconds, minutes, and hours and store them in the member variables */
        m_seconds = seconds_sum % 60;
        m_minutes = minutes_sum % 60;
        m_hours = hours_sum;
    }

private:
    int m_hours, m_minutes, m_seconds;
};

int main()
{
    /* creating two initialized Time objects - They are declared as 'const' because we will not alter their values in this application */
    const Time time1 = {5, 45, 30};
    const Time time2 = {11, 20, 50};

    /* creating an un-initialized Time object */
    Time time3;

    /* Adding the two Time Objects and store the result in the 3rd Time object */
    time3.add2Times(time1, time2);

    /* Display the resulted time3 object */
    std::cout << "**** Adding Two Times ****" << std::endl;
    time1.display();
    time2.display();
    std::cout << "---------" << std::endl;
    time3.display();

    return 0;
}