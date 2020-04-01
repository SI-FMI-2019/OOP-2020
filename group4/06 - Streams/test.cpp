/**
 * Write tests for Paragraph and Notebook
 */

#include "Paragraph.h"
#include <iostream>
#include <fstream>

int main() {
    // Write to file
    
    Paragraph s1 = "hello";
    std::ofstream outputFile("tmp"); // Opens file and truncates it (deletes all the text)
    // std::ofstream outputFile("tmp", std::ios::app);  // Opens file and places the cursor at the end without deleting the data
    outputFile << s1;
    outputFile.close(); // We can forcefully close it
    /* The close is called automatically when the object goes out of scope so it's not needed
    I'm calling it here because I need to open the same file bellow in the same scope */

    /* Read from file */

    Paragraph s2 = "";  
    std::ifstream inputFile("tmp");
    inputFile >> s2;

    std::cout << s2; // Check if the data is read correctly

    /* Open file for reading and writing simultaneously */
    // std::fstream file("tmp", std::ios::in | std::ios::out);
    // char buffer[1000];
    /* The cursor for reading/writing is one and where we stop reading is where we start writing */
    // file >> buffer; // Backup the data because when we write to the file we will destroy it later
    // std::cout << buffer;

    /* file << "asd"; // This starts writing where we stopped reading with >> */

    /* Move the cursor inside an opened file - seekg */
    // file.seekg(0); // Go back to the start
    // file << "asd"; // This starts writing from the start because that's where we moved the cursor


}
