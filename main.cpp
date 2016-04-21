#include <stdio.h>
#include <string>
#include <iostream>
 
using namespace std;
 
void convert_to_words(int n);
int find_k(int n);
 
int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    int k = find_k(n);
    convert_to_words(k);
    convert_to_words(n*k);

    return 0;
}
 
void convert_to_words(int n)
{
    int value[6] = { 0 };
    int modulo = 10;
    string result;
 
    for (int i = 0; i<6; i++)
    {
        while (n % modulo != 0)
        {
            n -= modulo / 10;
            value[i]++;
        }
        modulo *= 10;
    }
 
    string one[] = { "", "jeden", "dwa", "trzy", "cztery", "piec", "szesc", "siedem", "osiem", "dziewiec" };
    string ten[] = { "", "dziesiec", "dwadziescia", "trzydziesci", "czterdziesci", "piecdziesiat", "szescdziesiat", "siedemdziesiat", "osiemdziesiat", "dziewiecdziesiat" };
    string hundred[] = { "", "sto", "dwiescie", "trzysta", "czterysta", "piecset", "szescset", "siedemset", "osiemset", "dziewiecset" };
    string teen[] = { "", "jedenascie", "dwanascie", "trzynascie", "czternascie", "pietnascie", "szesnascie", "siedemnascie", "osiemnascie", "dziewietnascie" };
    string thousend[] = { "tysiac", "tysiecy", "tysiace" };
 
    if (value[4] == 1 && value[3] != 0)
    {
        result = hundred[value[5]] + " " + teen[value[3]] + " " + thousend[1];      //dla nascie
    }
    else
    {
 
        if (value[3] == 0 && value[4] == 0 && value[5] == 0)        //dla 0 tysiecy
        {
            result = "";
        }
        else
        {
            if (value[3] == 0 || value[3] == 5 || value[3] == 6 || value[3] == 7 || value[3] == 8 || value[3] == 9)  //dla tysiecy
            {
                result = hundred[value[5]] + " " + ten[value[4]] + " " + one[value[3]] + " " + thousend[1];
            }
 
            else if (value[5] == 0 && value[4] == 0 && value[3] == 1)       //dla tysiaca
            {
                result = thousend[0] + " ";
            }
            else
            {
                result = hundred[value[5]] + " " + ten[value[4]] + " " + one[value[3]] + " " + thousend[2];     //dla tysiace
            }
        }
    }
    if (value[1] == 1 & value[0] != 0)
    {
        result = result + " " + hundred[value[2]] + " " + teen[value[0]];
    }
    else
    {
        result = result + " " + hundred[value[2]] + " " + ten[value[1]] + " " + one[value[0]];
    }
 
 
    cout << result<<endl;
}
 
int find_k(int n)
{
    int k = 1;
    int quantity = n;
    while (quantity > 0)
    {
        if (quantity % 10 == 1 || quantity % 10 == 0)
        {
            quantity = quantity / 10;
        }
        else
        {
            k++;
            quantity = n*k;
        }
    }
    return k;
}