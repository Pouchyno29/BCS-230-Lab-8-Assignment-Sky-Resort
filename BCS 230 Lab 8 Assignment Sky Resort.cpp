/**
   Programmer's name    : Stanley
   Class                : BCS 230 Foundations of Computer Programming II
   Date                 : 10/25/2017
   Lab                  : Lab 8 Assignment
   Professor's name     : Moaath Alrajab
   Software uses        : Code:blocks
**/

/**
    Problem:
    Write a program that can be used by a sky resort to keep track of the
    local snow conditions for one week. It should have seven-element array of
    structures or class objects, where each structure or object holds a date
    and the number of inches of snow in the base on that date. The program
    should have the user input the name of the month, the starting and
    ending date of the seven-day period being measured, and then the
    seven base snow depths.
    The program should then sort the data in the ascending order by base
    depth and display the results (two functions one for sorting and one for
    displaying the results). Here is the beginning of a sample report.

    Snow Report December 12-18
         Date       Base
         13         42.3
         12         42.5
         14         42.8

**/


#include <iostream>
#include <string>

using namespace std;

//Structure to hold the user's data
    struct Report{

        int date;       //Variable to hold the current date for the month
        double depth;   //Variable to hold the depth of snow for the current date

    };

void inputData(Report newReport[], int size, string &month, int &startDate, int &endDate);
void displayData(Report newReport[], int size, string month, int startDate, int endDate);
void sortDate(Report newReport[], int size);
bool checkDate(int startDate, int endDate);
//void mSwap(double &num1, double &num2);
//void mSwap(int &num1, int &num2);
void mSwap(auto &num1, auto &num2);

int main()
{
    // set the floating point precision of the output
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout.precision(1);

    string month;                                                   // Variable to save the month
    int startDate;                                                  // Variable to save the starting date
    int endDate;                                                    // Variable to save the ending date
    const int SIZE = 7;                                             // The size of the array of structure

    struct Report newReport[SIZE];                                  // Declare a structure's array of 7 elements

    inputData(newReport, SIZE, month, startDate, endDate);          // Take data from the user

    cout << endl << endl;                                           // Skip two lines

    displayData(newReport, SIZE,  month, startDate, endDate);       // Display data before sorting

    sortDate(newReport, SIZE);                                      // Sorting data from smaller to larger

    cout << endl << endl;                                           // Skip two lines

    displayData(newReport, SIZE,  month, startDate, endDate);       // Display data after sorting

    return 0;
}

//Function to take data input from user
void inputData(Report newReport[], int size, string &month, int &startDate, int &endDate){

    //Get the month from the user
    cout << "Please enter the name of the month for the Snow Report: ";
    cin >> month;

    // Check if the user enter a valid date
    do{
        cout << "Enter the starting date: ";
        cin >> startDate;                           //Get the starting date
        cout << "Enter the end date: ";
        cin >> endDate;                             //Get the ending date


        if(checkDate(startDate, endDate) == true){  //Check if the starting date and the ending date is 7 days
            break;                                  // If it is then get out
        }else{                                      // If not show a message
            cout << "Start date and end date is not equal 7 days. \nTry again!!!" << endl;
        }
    }while(true);

    //Loop over the structure while taking data from the user
    for(int index = 0; index  < size; index++){
        //Set the date
        newReport[index ].date = (startDate + index );
        //Take the amount of snow for the current date
        cout << "Enter the snow's depth for " << month << " " << newReport[index ].date << ": ";
        cin >> newReport[index ].depth;
    }
}
/*
    Function to sort the data taken from the user
    Using Bubble sort to sort the data from smaller to larger
    The data that are sorted are the snow's depth
    Using Bubble sort cause it is only for 7 days of data
    therefore Bubble sort is sufficient for sorting the data.
*/
void sortDate(Report newReport[], int size){

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(newReport[j].depth > newReport[j + 1].depth){

                mSwap(newReport[j].depth , newReport[j + 1].depth);
//                temp = newReport[j].depth;
//                newReport[j].depth = newReport[j + 1].depth;
//                newReport[j + 1].depth = temp;

                mSwap(newReport[j].date , newReport[j + 1].date);
//                temp2 = newReport[j].date;
//                newReport[j].date = newReport[j + 1].date;
//                newReport[j + 1].date = temp2;
            }
        }
    }

}

//Function to check if the start date and the end date is 7 days
bool checkDate(int startDate, int endDate){

//    if(startDate > endDate){                  // If the starting date is greater than the ending date
//        return false;                         // Return false, date input is wrong
//    }
//
//    if((startDate < 1) || (startDate > 25)){  // If the stating date is smaller than ONE or starting date is greater then 25
//         return false;                        // return false. Cause month does not have negative date,
//                                              // and starting date can't be grater than 25, assuming a month is 31 days.
//    }
//
//    if((endDate < 7) || (endDate > 31)){      // If the ending date is smaller than SEVEN or ending date is greater then 31
//        return false;                         // return false. Cause Ending date can't be smaller than 7 if we have to take data for 7 days
//                                              // and ending date cant be grater than 31, assuming a month is 31 days
//    }

    if((endDate - startDate) == 6){             // If the starting date and the ending date is 6 days + 1
        return true;                            // Return true
    }else{                                      // Otherwise
        return false;                           // Return false
    }
}


// Function to swap two elements while sorting them from smaller to larger
// Basically this function will be used to swap the data of an array of structure.
void mSwap(auto &num1, auto &num2){

    auto temp = num1;             // Save the value of the first variable into a temporary variable
    num1 = num2;                  // Save the value of the second variable into first variable
    num2 = temp;                  // Replace the value of the second variable with the value of the temporary variable
}
//
////Function to swap two elements during the sorting
//void mSwap(int &num1, int &num2){
//
//    double temp = num1;
//    num1 = num2;
//    num2 = temp;
//}


//Function to display the data to the screen or console
void displayData(Report newReport[], int size, string month, int startDate, int endDate){

    cout << "Snow Report " << month << " " << startDate << "-" << endDate << endl;
    cout << string(5,' ') << "Date" << string(7,' ')<< "Base" << endl;

    for(int index = 0; index < size; index++){
        cout << string(5,' ') << newReport[index].date << string(9,' ')<< newReport[index].depth << endl;
    }

}






