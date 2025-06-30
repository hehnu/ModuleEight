# Module Eight

# Corner Grocer Item Tracking Program

## Project Summary
This C++ project was created for Corner Grocer to help track how often different items are purchased throughout the day. The program reads a text file of recorded purchases and presents the data in three ways: the frequency of a specific item, a complete list of all item frequencies, and a visual histogram made of asterisks. The goal here was to help the store make better decisions about how to organize their produce section based on customer behavior.

## Strengths
One of the parts I’m especially proud of is the class design. I created a class  called `ItemTracker`  that keeps all the logic for the program in one place. I also used `std::map` for the file input/output and to count and store item frequencies. The interactive menu takes in user input and helps users select menu options.

## Room for Improvement
The input function currently takes out non-letter characters, which works for produce names but wouldn’t be good if item names were like “7Up” or “Vitamin B12” were added. In the future, I can improve this by allowing numbers or special characters as needed, or implementing case-insensitive matching.

## Challenges
One challenge was making sure the histogram matched the frequency output exactly and remained visually aligned. I had to adjust spacing and use the `setw()` function from `<iomanip>` to keep everything readable. Another tricky part was where the input file wasn't found and  this required adding error checks and exits to make sure the program didn’t crash unexpectedly. 

## Transferable Skills
This project helped reinforce my understanding of file processing, user input handling, and using data structures like maps in C++. I also gained experience writing clean code that can be reused or expanded in future projects. These skills will be helpful in both my academic and professional career.

## Best Practices
I added clear comments above each function, used distinctive variable names, and organized the code into sections. I oraganized the program's data and behavior into classes to keep everything aligned. This made debugging easier and allows others to understand and update the code more easily.


