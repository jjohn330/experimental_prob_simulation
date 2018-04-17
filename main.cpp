/*
    Developer: Justin Johnson
    Date: April 17th, 2018
    Coding Langauge: C++

    Description:
        This small bit of code is concerned with testing for the experimental probability of a specific situation. If we suppose
        we cannot calculate the theoretical probability of a situation, we can test for the experimental probability and find
        an approximate value. If we suppose we want to find the probability of getting 8 heads out of 8 coin flips, we can use
        a bit of math to find this value.

        8C8 = 8!/8! * 1! = 1/2^8 as 2^8 is our sample size which yields about 3.9 results for every 1,000 results. As such, we are
        testing to receive an approximate answer for 3.9/1000. The program finds the average of 100 trials of 1000 sequences of 8 coin flips
        to test for how closely the experimental probability converges to the theoretical probability.

        For my individual run, I received the result 3.905 or only about a 0.128% difference!

*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    double sum = 0, counter = 0;
    string flip_trial = "";
    bool all_heads;
    int rand_num;
    srand(time(0));
    for (int i = 0; i < 1000; i++) { // runs 1000 trials for the experiment to find the average we desire
        for (int j = 0; j < 1000; j++) { // runs 1000 sequences of 8 coin flips to find how many times we get 8/8 heads
                all_heads = true;
            for (int k = 0; k < 8; k++) {
                rand_num = rand()%2;
                if (rand_num) // if odd result (50% of the time) make heads conversion
                    flip_trial += "H";
                else {  // else makes tails conversion and make all_heads bool false (as in contains at least one tails)
                    flip_trial += "T";
                    all_heads = false;
                    break; // saves computing power by skipping over silly, unnecessary calculations
                }
            }

            if (all_heads) // adds result to our occurrences of all heads result
                counter++;

            flip_trial = "";
        }

        sum += counter;
        counter = 0;
    }

    cout << sum/1000 << endl;
}
