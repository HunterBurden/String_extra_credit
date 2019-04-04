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
    string text_line;
    string substring;
    int count;
    cout << "Please enter line of text. They can be uppercase or lowercase: ";
    getline(cin, text_line);
    cout << "Now enter a substring of characters you like to find the total occurences of: ";
    getline(cin, substring);
    count = count_occurences(text_line, substring);
    cout << "The total number of times the substring occurs in the line of text is: " << count << endl;
    return 0;
}

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
    int count = 0;
    int first_length = str1.length();
    int second_length = str2.length();
    for(int i = 0; i < first_length; i++) {
        str1[i] = toupper(str1[i]);
    }
    for(int i = 0; i < second_length; i++) {
        str2[i] = toupper(str2[i]);
    }
    for(int i = 0; i < first_length; i++) {
        if(str1.substr(i, second_length) == str2) {
            count++;
        }
    }
    return count;
}