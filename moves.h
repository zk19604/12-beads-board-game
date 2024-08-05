int onlyonecolor(int arr[][5])
{
    int cx = 0, co = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j] == 1)
                cx++;
            if (arr[i][j] == 2)
                co++;
        }
    }
    if (co == 0 && cx > 0)
        return 0;
    else if (co > 0 && cx == 0)
        return -1;
    else
        return 1;
}
void moves(int arr[][5], int selX, int selY, int movX, int movY, int player, int opponent, int &current)
{
    int i = selX, j = selY, k = movY, l = movX;
    if (player == 1 && current == 1)
    {
        if (arr[i][j] == player && arr[l][k] == 0)
        {
            if ((l == i + 1 && k == j) || (l == i - 1 && k == j) || (k == j + 1 && l == i) || (k == j - 1 && l == i))
            {
                arr[l][k] = player;
                arr[i][j] = 0;
                current = 2;
            }
            if ((l == i + 2 && k == j) && arr[i + 1][j] == opponent)
            {
                arr[l][k] = player;
                arr[i][j] = 0;
                arr[i + 1][j] = 0;
                current = 2;
            }
            else if ((l == i - 2 && k == j) && arr[i - 1][j] == opponent)
            {
                arr[l][k] = player;
                arr[i][j] = 0;
                arr[i - 1][j] = 0;
                current = 2;
            }
            else if ((k == j + 2 && l == i) && arr[i][j + 1] == opponent)
            {
                arr[l][k] = player;
                arr[i][j] = 0;
                arr[i][j + 1] = 0;
                current = 2;
            }
            else if ((k == j - 2 && l == i) && arr[i][j - 1] == opponent)
            {
                arr[l][k] = player;
                arr[i][j] = 0;
                arr[i][j - 1] = 0;
                current = 2;
            }
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
            {
                if ((l == i - 1 && k == j - 1) || (l == i - 1 && k == j + 1) || (l == i + 1 && k == j - 1) || (l == i + 1 && k == j + 1))
                {
                    arr[l][k] = player;
                    arr[i][j] = 0;
                    current = 2;
                }
                if ((l == i - 2 && k == j - 2) && arr[i - 1][j - 1] == opponent)
                {
                    arr[l][k] = player;
                    arr[i][j] = 0;
                    arr[i - 1][j - 1] = 0;
                    current = 2;
                }
                if ((l == i - 2 && k == j + 2) && arr[i - 1][j + 1] == opponent)
                {
                    arr[l][k] = player;
                    arr[i][j] = 0;
                    arr[i - 1][j + 1] = 0;
                    current = 2;
                }
                if ((l == i + 2 && k == j - 2) && arr[i + 1][j - 1] == opponent)
                {
                    arr[l][k] = player;
                    arr[i][j] = 0;
                    arr[i + 1][j - 1] = 0;
                    current = 2;
                }
                if ((l == i + 2 && k == j + 2) && arr[i + 1][j + 1] == opponent)
                {
                    arr[l][k] = player;
                    arr[i][j] = 0;
                    arr[i + 1][j + 1] = 0;
                    current = 2;
                }
            }
        }
    }

    else if (player == 2 && current == 2)
    {
        if (arr[i][j] == player && arr[l][k] == 0)
        {
            if ((l == i + 1 && k == j) || (l == i - 1 && k == j) || (k == j + 1 && l == i) || (k == j - 1 && l == i))
            {
                arr[l][k] = player;
                arr[i][j] = 0;
                current = 1;
            }
            if ((l == i + 2 && k == j) && arr[i + 1][j] == opponent)
            {
                arr[l][k] = player;
                arr[i][j] = 0;
                arr[i + 1][j] = 0;
                current = 1;
            }
            else if ((l == i - 2 && k == j) && arr[i - 1][j] == opponent)
            {
                arr[l][k] = player;
                arr[i][j] = 0;
                arr[i - 1][j] = 0;
                current = 1;
            }
            else if ((k == j + 2 && l == i) && arr[i][j + 1] == opponent)
            {
                arr[l][k] = player;
                arr[i][j] = 0;
                arr[i][j + 1] = 0;
                current = 1;
            }
            else if ((k == j - 2 && l == i) && arr[i][j - 1] == opponent)
            {
                arr[l][k] = player;
                arr[i][j] = 0;
                arr[i][j - 1] = 0;
                current = 1;
            }
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))
            {
                if ((l == i - 1 && k == j - 1) || (l == i - 1 && k == j + 1) || (l == i + 1 && k == j - 1) || (l == i + 1 && k == j + 1))
                {
                    arr[l][k] = player;
                    arr[i][j] = 0;
                    current = 1;
                }
                if ((l == i - 2 && k == j - 2) && arr[i - 1][j - 1] == opponent)
                {
                    arr[l][k] = player;
                    arr[i][j] = 0;
                    arr[i - 1][j - 1] = 0;
                    current = 1;
                }
                if ((l == i - 2 && k == j + 2) && arr[i - 1][j + 1] == opponent)
                {
                    arr[l][k] = player;
                    arr[i][j] = 0;
                    arr[i - 1][j + 1] = 0;
                    current = 1;
                }
                if ((l == i + 2 && k == j - 2) && arr[i + 1][j - 1] == opponent)
                {
                    arr[l][k] = player;
                    arr[i][j] = 0;
                    arr[i + 1][j - 1] = 0;
                    current = 1;
                }
                if ((l == i + 2 && k == j + 2) && arr[i + 1][j + 1] == opponent)
                {
                    arr[l][k] = player;
                    arr[i][j] = 0;
                    arr[i + 1][j + 1] = 0;
                    current = 1;
                }
            }
        }
    }
}