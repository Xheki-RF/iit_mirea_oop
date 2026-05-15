#include <iostream>
#include <string>
#include <sstream>
#include "Device.h"

int main()
{
    int n;

    std::cin >> n;
    std::cin.ignore();

    for (int i = 0; i < n; i++)
    {
        std::string line, name;
        int N, P;
        std::getline(std::cin, line);

        std::istringstream iss(line);

        // если строка пустая → считаем пустое имя
        if (!(iss >> name >> N >> P))
        {
            name = "";
        }

        try
		{
			Device d(name, N, P);
			d.show();
		}
		catch (std::string e)
		{
			printf("Exception(string): %s\n", e.c_str());	
		}
		catch (int e)
		{
			printf("Exception(int): %d\n", e);
		}
		catch (double e)
		{
			printf("Exception(double): %.f\n", e);	
		}
    }

    return 0;
}