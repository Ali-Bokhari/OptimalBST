Ali Bokhari
Assignment 3
March 3, 2020
0970498
abokhari

Just run make and it will compile and start the program, select one of the menu options to pick which function to run.

2.4) Brute Force and Horspool functions work perfectly, Boyer Moore works some of the time so i'll mostly be comparing the first two.
The number of switches affects the runtime as thats how many times the comparison was made. BruteForce always has the same number of switches as it always increments by one and then checks.
Bases on the tests, Horspool's algorithm makes lesser and lesser switches as the length of the pattern increases. When the BooreMoore does work it seems to be performing just a little worse than Horspool but still better than brute force. 
Horspool was the best for searching as it was almost always more efficient than the other string search algorithms.
