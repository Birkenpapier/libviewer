// reading a text file
#include <iostream>
#include <fstream>
#include <string>

int main ()
{
    std::string line;
    std::ifstream myfile ("E:\\Projects\\C_Plus_Plus\\fun_little_projects\\libviewer\\test_files\\ppm\\coloful.ppm");

    if(myfile.is_open())
    {
        while(std::getline (myfile,line))
        {
            std::cout << line << '\n';
        }
        
        myfile.close();
    }

    else std::cout << "unable to open image"; 

    return 0;
}