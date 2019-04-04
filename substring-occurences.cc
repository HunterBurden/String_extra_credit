/*
*        File: substring-occurences.cc
*      Author: Hunter Burden
*        Date: April 3, 2019
* Description: find the occurences of a substring within a string
*/

#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<string>
#include<cctype>
using namespace std;

//function prototype
int count_occurences(string str1, string str2);

int main() {
    string text_line; //stores the entire line of text 
    string substring; //stores the smaller substring being searched inside the line of text
    int count; //stores the total times the substring occurs returned by count_occurences
    cout << "Please enter line of text. They can be uppercase or lowercase: ";
    getline(cin, text_line); //user input for text_line
    cout << "Now enter a substring of characters you like to find the total occurences of: ";
    getline(cin, substring); //user input for the substring inside text_line
    count = count_occurences(text_line, substring); //
    cout << "The total number of times the substring occurs in the line of text is: " << count << endl;
    return 0;
} //main

//function documentation

/******************************************************************************
 * Function: count_occurences
 * 
 * Purpose: find the number of times a substring occurs within a 
 *          line of text
 * 
 * Parameters: str1 - the whole line of text entered by the user
 *             str2 - the substring entered by the user
 * 
 * Pre-conditions: str1 and str2 are valid series of strings
 * 
 * Post-conditions: the total number of times str2, the substring,
 *                  occurs within str1, the text line, is counted
 ******************************************************************************/
int count_occurences(string str1, string str2) {
    int count = 0; //stores the count of the substring, returned by the function
    int first_length = str1.length(); //stores the length of the text line
    int second_length = str2.length(); //stores the length of the substring
    for(int i = 0; i < first_length; i++) {
        str1[i] = toupper(str1[i]);
        //uppercases every text line letter so uppercase and lowercase letters do not matter 
    }
    for(int i = 0; i < second_length; i++) {
        str2[i] = toupper(str2[i]);
        //uppercases every text line letter so uppercase and lowercase letters do not matter 
    }
    for(int i = 0; i < first_length; i++) {
        if(str1.substr(i, second_length) == str2) {
            //finds a substring the length of the user input substring and compares the results to said substring
            count++;
        }
    }
    return count;
}