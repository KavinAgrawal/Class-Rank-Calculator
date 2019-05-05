#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <sstream>


using namespace std;
int main()
{
    ifstream MarkSheet("Marksheet.csv");
    string student[1000];                     //it stores the roll number of students
    string marksInString[1000];
    double marksInDouble[1000];                       //it stores marks.
    string rollNumber;                        //it stores the roll number on which operation has to be done.

    while(MarkSheet.fail())
    {
        cout << "Sorry,We are not able to open file.";
        return(0);
    }



    for(int i = 0; MarkSheet.good(),i < 1000; i++)
    {
        /*
        This loop declares the roll number and marks of (i+1)th student in variable student[i]
        and variable mark[i] respectively.
        */
        getline(MarkSheet,student[i],',');
        getline(MarkSheet,marksInString[i],'\n');
    }

    for(int i=0; i<1000; i++)
    {
        stringstream (marksInString[i]) >> marksInDouble[i]; //Conversion of marks from string type to double type
    }

    cout << "Enter Roll Number: ";
    cin >> rollNumber;

    while(true)
    {
        if(rollNumber == "stop")               //It ends the loop when the user gives input as "stop".
        {
            break;
        }
        else
        {
            int rankOfStudent=1;
            int tiedBetween=0;
            int rollNumberStored;              //Contains the roll number given by the user in int type
            stringstream (rollNumber) >> rollNumberStored;

            if(rollNumberStored >=1 && rollNumberStored <=1000)
            {

                cout << "Marks Obtained: " << marksInDouble[rollNumberStored-1] << ",\t";
                //rollNumberStored-1 is used since the roll number of i th student in i-1 element of student array
                for(int j=0; j<1000; j++)
                {
                    /* This loop calculates the rank of students and number of students tied between.
                    */

                    if(marksInDouble[j]>marksInDouble[rollNumberStored-1])
                    {
                        rankOfStudent++;
                    }
                    if(marksInDouble[j]==marksInDouble[rollNumberStored-1])
                    {
                        tiedBetween++;
                    }
                }

                cout << "Rank: " << rankOfStudent << ",\t";
                cout << "Tied Between: " << tiedBetween << endl;
            }
            else
            {
                cout << "The roll number that you entered does not lie in the range.\n";
            }

            cout << "Enter Roll Number: ";
            cin >> rollNumber;    //Asking for a new input roll number.
        }
    }
}


