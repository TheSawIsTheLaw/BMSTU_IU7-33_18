// N - максимальная длина строки, она будет объявлена в мейне

char *strtok_Namestnik(char *string, const char *delim)
{
    static char * next;
    register int i = 0;
    
    if (string)
    {
        next = string;
        if (*next)
        {
            i = 0;
            while (delim[i])
            {
                if (*next == delim[i])
                {
                    *next++ = '\0';
                    break;
                }
                i++;
            }
        }
    }
    if ( ! *next )
        return NULL;
    
    string = next;
   
    while (*next)
    {
        i = 0;
        while (*next != delim[i] && delim[i] != '\0')
            i++;
        if (delim[i] == '\0')
            ++next;
        else
            break;
    }
    while (*next)
    {
        i = 0;
        while (*next != delim[i] && delim[i] != '\0')
            i++;
        if (delim[i] == '\0')
            break;
        else
            *next++ = '\0';
    }
    return string;
}

int split_Namestnik(const char *string, char matrix[][N], const char symbol)
{
    register int row = 0, col = 0;
    while (*string)
    {
        if (*string == symbol)
        {
            matrix[row++][col] = '\0';
            col = 0;
        }
        else
            matrix[row][col++] = *string;
        string++;
    }
    matrix[row][col] = '\0';
    
    return ++row;
}

