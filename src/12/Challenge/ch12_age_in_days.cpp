// C++ Code Challenges, LinkedIn Learning

// Challenge #12: Age in Days Calculator
// Write an application that asks the user's birth date and responds with the user's age in days. 
// If the user claims to be over 120 years old, output a message calling the bluff.

#include <iostream>
#include <string>
#include <ctime>

bool is_leap_year(int year){
    if (year%4 != 0) return false;
    if (year%100 == 0 && year%400 != 0) return false;
    return true;
}

const int days[12] ={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// Age in Days, main()
// Summary: This application asks the user's birth date and prints their age in days.
int main(){
    int birth_y, birth_m, birth_d, today_y, today_m, today_d, age;

    std::cout << "Enter your birth date's month as a number: " << std::flush;
    std::cin >> birth_m;
    std::cout << "Enter your birth date's day: " << std::flush;
    std::cin >> birth_d;
    std::cout << "Enter your birth date's year: " << std::flush;
    std::cin >> birth_y;

    //today
    std::time_t now = std::time(nullptr);
    std::tm* time_now = std::localtime(&now);
    today_y = time_now->tm_year + 1900;
    today_m = time_now->tm_mon + 1;
    today_d = time_now->tm_mday;
    
    
    
    if(birth_m < 1)
        birth_m = 1;
    if(birth_m > 12)
        birth_m = 12;

    // Write your code here
    age =0;

    if (today_y != birth_y){
        // first year calculation
        for (int i=1; i<birth_m; i++){
            age += days[i-1];
        }
        age += birth_d;
        if(is_leap_year(birth_y) && birth_m>=3 )age++;
        age = (is_leap_year(birth_y) ? 366:365) - age;

        // between birth and today
        for (int i=birth_y+1; i<today_y; i++){
            age += is_leap_year(i) ? 366 : 365;
        }

        // today year
        for (int i=1; i<today_m; i++){
            age += days[i-1];
        } 
        age += today_d;
        if(is_leap_year(today_y) && today_m>=3 )age++;
    }



    if(age < 43830)
        std::cout << "You are " << age << " days old.";
    else
        std::cout << "Come on. You can't be " << age << " days old!";
    std::cout << "\n\n" << std::flush;
}
