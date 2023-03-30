/**
 *    @file: hw_5.cc
 *  @author: viraj parmar
 *    @date: 3/29/2023         
 *   @brief: This program will read the website name and the IP address of them from
 *           a file and print total number of visitors and unique ip address in an
 *           outputfile. 
 *  
 */



#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;



//declare functions
void input(ifstream &fin,vector<string> &ip1,vector<string> &ip2);
void output(ofstream &fout,vector<string> &ip1,vector<string> &ip2);



int main(int argc, char* argv[])
{
    //check if we have correct number of command line arguments
    if (argc != 3)
    {
        cout << "Please, provide input and output files as command line arguments!" << endl;
        return 0;
    }

    // declare an stream object reading/writing file
    ifstream fin;
    ofstream fout;


    //declare file name variables
    string inFileName=argv[1];
    string outFileName = argv[2];

    
    // try to open the file 
    fin.open(inFileName);

    //check if success
    if (!fin)
    {
        cout << inFileName<< " file could not be opened for reading..." << endl;
        return 0;
    }

    // try to open the file 
    fout.open(outFileName);

    //check if success
    if (!fout)
    {
        cout << outFileName << " file could not be opened for writing..." << endl;
        return 0;
    }


    //store all the ip address
    vector<string> ip1;
    //store only the unique ip address
    vector<string> ip2;
    //store the name of the website
    string website;


    //Loop will end when it reaches the end of the file
    while (!fin.eof())
    {
        //get the name of the website
        getline(fin,website);
        fout<<website;
        

        //Read all the ip address
        input(fin,ip1,ip2);

        //Print website name and the unique ip address and the total visitors
        output(fout,ip1,ip2);

        //To clear the array after every website
        ip1.clear();
        ip2.clear();

    }

    //Closing of the file when the loop end
    fin.close();
    fout.close();


    return 0;
    
}


//Function that read all the ip address and then store the unique ip address
void input(ifstream &fin,vector<string> &ip1,vector<string> &ip2)
{
    
    //variable to get each ip address
    string str;

    //infinte loop
    while (1)
    {

        fin>>str;
        fin.ignore();

        //To end the loop
        if(str=="-----")
        {
            break;
        }
        
        else
        {   
            //Store all the ip address in the array ip1
            ip1.push_back(str);
        }

    }


    //Loop to sort the unique ip address
    for(size_t i=0;i<ip1.size();i++)
    {
        int j;

        for(j=0;j<i;j++)
        {
            if(ip1[i]==ip1[j])
            {
                break;
            }
        }
        if(i==j)
        {
            //Store the unique ip address into ip2
            ip2.push_back(ip1[i]);
        }
   
    }
}


//Function to print the total visitors, unique visitors and the unique ip address
void output(ofstream &fout,vector<string> &ip1,vector<string> &ip2)
{

    //Printing the number of visitors
    fout<<" | Number of visitors : "<<ip1.size()<<" | Unique visitors : "<<ip2.size()<<endl;



    //Printing the unique ip address
    for(int i=0;i<ip2.size();i++)
    {

        fout<<"\t"<<ip2[i]<<endl;
    
    }


}