void make_shot_kovalev(char symb, char BF[][DIME])
{
    char en_symb;
    if (symb == 'X')
        en_symb = 'O';
    else
        en_symb = 'X';
    int res_danger = 0;
    int res_i = 0;
    int res_j = 0;
    int to_left;
    int to_right;
    int to_up;
    int to_down;
    int danger;
    int en_conter;
    int conter;
    int space;
    int dig_power = 3;
    for (int i = 0; i < DIME - 3; i++)
        dig_power = (dig_power * 3 + 2) * 3 + 2;
    

    for (int i = 0; i < DIME; i++)
    {
        printf("\n");
        for(int j = 0; j < DIME; j++)
        {
            if (BF[i][j] == ' ')
            {
                danger = 0;
                to_left = j;
                to_right = DIME - 1 - j;
                to_up = i;
                to_down = DIME - 1 - i;

                en_conter = 0;
                conter = 0;
                space = 0;
                for(int z = 1; z <= to_left; z++)
                {
                    if (BF[i][j - z] == symb)
                        conter++;
                    else
                    {
                        if(BF[i][j - z] == en_symb)
                            en_conter++;
                        else
                            space++;
                    }
                }

                for(int z = 1; z <= to_right; z++)
                {
                    if (BF[i][j + z] == symb)
                        conter++;
                    else
                    {
                        if(BF[i][j + z] == en_symb)
                            en_conter++;
                        else
                            space++;
                    }
                }

                int new_d = 0;
                if (conter == 0)
                {
                    new_d = 1;
                    for (int wei = 1; wei < en_conter; wei++)
                    {
                        new_d = (new_d * 3 + 2) * 3 + 2;
                    }
                }

                if (en_conter == 0)
                {
                    new_d = 5;
                    for (int wei = 1; wei < conter; wei++)
                    {
                        new_d = (new_d * 3 + 2) * 3 + 2;
                    }
                }
                danger+=new_d;

                en_conter = 0;
                conter = 0;
                space = 0;
                for(int z = 1; z <= to_up; z++)
                {
                    if (BF[i - z][j] == symb)
                        conter++;
                    else
                    {
                        if(BF[i - z][j] == en_symb)
                            en_conter++;
                        else
                            space++;
                    }
                }

                for(int z = 1; z <= to_down; z++)
                {
                    if (BF[i + z][j] == symb)
                        conter++;
                    else
                    {
                        if(BF[i + z][j] == en_symb)
                            en_conter++;
                        else
                            space++;
                    }
                }
                new_d = 0;
                if (conter == 0)
                {
                    new_d = 1;
                    for (int wei = 1; wei < en_conter; wei++)
                    {
                        new_d = (new_d * 3 + 2) * 3 + 2;
                    }
                }

                if (en_conter == 0)
                {
                    new_d = 5;
                    for (int wei = 1; wei < conter; wei++)
                    {
                        new_d = (new_d * 3 + 2) * 3 + 2;
                    }
                }
                danger+=new_d;


                if(i == j)
                {
                    danger+=dig_power;
                    en_conter = 0;
                    conter = 0;
                    space = 0;
                    for(int z = 1; z <= to_left; z++)
                    {
                        if (BF[i - z][j - z] == symb)
                            conter++;
                        else
                        {
                            if(BF[i - z][j - z] == en_symb)
                                en_conter++;
                            else
                                space++;
                        }
                    }

                    for(int z = 1; z <= to_right; z++)
                    {
                        if (BF[i + z][j + z] == symb)
                            conter++;
                        else
                        {
                            if(BF[i + z][j + z] == en_symb)
                                en_conter++;
                            else
                                space++;
                        }
                    }
                    new_d = 0;
                    if (conter == 0)
                    {
                        new_d = 1;
                        for (int wei = 1; wei < en_conter; wei++)
                        {
                            new_d = (new_d * 3 + 2) * 3 + 2;
                        }
                    }

                    if (en_conter == 0)
                    {
                        new_d = 5;
                        for (int wei = 1; wei < conter; wei++)
                        {
                            new_d = (new_d * 3 + 2) * 3 + 2;
                        }
                    }
                    danger+=new_d;
                }

                if(i + j == DIME -1)
                {
                    danger+=dig_power;
                    en_conter = 0;
                    conter = 0;
                    space = 0;
                    for(int z = 1; z <= to_left; z++)
                    {
                        if (BF[i + z][j - z] == symb)
                            conter++;
                        else
                        {
                            if(BF[i + z][j - z] == en_symb)
                                en_conter++;
                            else
                                space++;
                        }
                    }

                    for(int z = 1; z <= to_right; z++)
                    {
                        if (BF[i - z][j + z] == symb)
                            conter++;
                        else
                        {
                            if(BF[i - z][j + z] == en_symb)
                                en_conter++;
                            else
                                space++;
                        }
                    }
                    new_d = 0;
                    if (conter == 0)
                    {
                        new_d = 1;
                        for (int wei = 1; wei < en_conter; wei++)
                        {
                            new_d = (new_d * 3 + 2) * 3 + 2;
                        }
                    }

                    if (en_conter == 0)
                    {
                        new_d = 5;
                        for (int wei = 1; wei < conter; wei++)
                        {
                            new_d = (new_d * 3 + 2) * 3 + 2;
                        }
                    }
                    danger+=new_d;
                }

                if (danger >= res_danger)
                {
                    res_danger = danger;
                    res_i = i;
                    res_j = j;
                }
            }
        }
    }
    BF[res_i][res_j] = symb;
}