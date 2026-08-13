#include "Queue.h"
#include <random>
#include <ctime>
#include <iostream>

const int MIN_PER_HOUR = 60;

bool new_customer(double x);

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    cout << "Case Study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line1(qs), line2(qs);
    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HOUR * hours;
    cout << "Enter the average number of customers per hour: ";
    double per_hour;
    cin >> per_hour;
    double min_per_cust = per_hour / MIN_PER_HOUR;
    Item temp;
    long turn_aways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time1(0), wait_time2(0);
    long line_wait = 0;

    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (new_customer(min_per_cust))
        {
            if (line1.is_full() && line2.is_full())
                turn_aways++;
            else 
            {
                customers++;
                temp.set(cycle);
                if (line1.queue_count() < line2.queue_count())
                    line1.enqueue(temp);
                else
                    line2.enqueue(temp);
            }
        }
        if (wait_time1 <= 0 && !line1.is_empty())
        {
            line1.dequeue(temp);
            wait_time1 = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        } 
        if (wait_time2 <= 0 && !line2.is_empty())
        {
            line2.dequeue(temp);
            wait_time2 = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
        }
        if (wait_time1 > 0)
            wait_time1--;
        if (wait_time2 > 0)
            wait_time2--;
        sum_line += line1.queue_count();
        sum_line += line2.queue_count();
        
    }

    if (customers > 0)
    {
        cout << "customers accepted: " << customers << endl;
        cout << " customers served: " << served << endl;
        cout << " turnaways: " << turn_aways << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / cyclelimit << endl;
        cout << " average wait time: "
             << (double) line_wait / served << " minutes\n";
    }
    else
        cout << "No customers!\n";
    cout << "Done!\n";
    return 0;
}

bool new_customer(double x)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution dist(x);
    return dist(gen);
    
}



//18 клинетов в час для 1 банкомата
//51 клиентов в час для двух