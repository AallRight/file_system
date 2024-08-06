#include <iostream>
#include <cstring> // Add this line to include the <cstring> header file

namespace tool_namespace
{
    int parseLine(char *line, char *command_array[])
    {
        char *p;
        int count = 0;
        p = strtok(line, " ");
        while (p != NULL)
        {
            command_array[count] = p;
            count++;
            p = strtok(NULL, " ");
        }
        return count;
    }
    int generate_512bytes_data(int operations_types, int cylinder_num, int sector_num, char *data_256, char *data_512)
    {
        memset(data_512, '\0', 512);
        int *data_in_int_512 = (int *)data_512;
        data_in_int_512[0] = operations_types;
        data_in_int_512[1] = cylinder_num;
        data_in_int_512[2] = sector_num;
        memcpy(data_512 + 256, data_256, 256);
        return 0;
    }

}