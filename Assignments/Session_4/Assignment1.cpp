#include <iostream>

using namespace std;

class Date
{
    int day;
    int month;
    int year;

public:
    Date() : day{-1}, month{-1}, year{-1}
    {
    }

    void setDay(int d)
    {
        if(d > 31 || d < 1)
        {
            day = -1;
        }
        else
        {
            day = d;
        }
    }

    void setMonth(int m)
    {
        if(m > 12 || m < 1)
        {
            month = -1;
        }
        else
        {
            month = m;
        }
    }

    void setYear(int y)
    {
        if(y > 2100 || y < 1960)
        {
            year = -1;
        }
        else
        {
            year = y;
        }
    }

    int getDay(void)
    {
        return day;
    }

    int getMonth(void)
    {
        return month;
    }

    int getYear(void)
    {
        return year;
    }

    int isValid(void)
    {
        if(day == -1 || month == -1 || year == -1)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }

    void displayDate(void)
    {
        cout << day <<"/"<<month<<"/"<<year<<endl;
    }

};


int main()
{
    Date d;
    int temp;
    cout << "Input Day: " ;
    cin >> temp;
    d.setDay(temp);

    cout << "Input Month: " ;
    cin >> temp;
    d.setMonth(temp);
    
    cout << "Input Year: " ;
    cin >> temp;
    d.setYear(temp);

    d.displayDate();

    if(d.isValid())
    {
        cout << "The date is valid"<<endl;
    }
    else
    {
        cout << "The date is not valid"<<endl;
    }



    return 0;
}