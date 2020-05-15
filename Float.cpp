//initializing header files
#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;

//global variable
float number, frac_number, store_frac[1000];
int i = 0, lower_number, get_mod[1000];
int get_mod_reverse[1000], index = 0, get_frac[1000];
int siz = 0;
int expo,get_1,make_frac[1000];
int exp2[1000];
//turns off the sync in cin and cout
//makes the program faster
void turn_off()
{
    cin.tie(0);
    cout.tie(0);
}

void input()
{
    cin >> number;
}
void get_frac_int()
{
    lower_number = floor(number);
    frac_number = number - lower_number;
}

//converts integer number to binary 7=>binary
void convert_binary_int()
{
    int lower = lower_number, sum = 0;
    while (lower)
    {
        get_mod[i] = lower % 2;
        lower /= 2;
        i++;
    }

    //get_mod_reverse stores the real binary of the int
    for (;;)
    {
        get_mod_reverse[index] = get_mod[i - 1];
        i--;
        index++;
        if (i == 0)
        {
            break;
        }
    }
}

//this is a simple binary search
int bin_search(float frac)
{
    sort(store_frac, store_frac + siz);

    int start = 0, end = siz - 1, mid, flag = 0;
    while (start <= end && store_frac[start] <= store_frac[end])
    {
        mid = (start + end) / 2;
        if (store_frac[mid] == frac)
        {
            flag = 1;
            break;
        }
        else if (store_frac[mid] > frac)
        {
            end = mid;
        }
        else if (store_frac[mid] < frac)
        {
            start = mid;
        }
        else
        {
            flag = 0;
        }
    }
    return flag;
}

//converts fraction number to binary 0.01 =>binary
void convert_binary_frac()
{
    float frac = frac_number;
    while (frac != 0) //check this condition if any error comes...
    {
        //stores the fractional number
        store_frac[siz] = frac;

        //method to convert binary
        frac = frac * 2;
        get_frac[siz] = floor(frac);
        frac = fabs(frac - get_frac[siz]);
        siz++;
        //end

        //checks the repeatation of the frac number by using binary search
        if (bin_search(frac))
        {
            break;
        }
    }
}

//searches 1 to get the exponential power
void search_1()
{
    int check = 0;

    //gets the initial bit 
    for (int j = 0; j < index; j++)
    {
        if (get_mod_reverse[j] == 1)
        {
            expo = index - j;
            check = 1;
            get_1 = j;
            break;
        }
    }
    /// 0.0000001
    if (!check)
    {
        for (int j = 0; j < siz; j++)
        {
            if (get_frac[j] == 1)
            {
                expo = (j+1)*(-1);
                //check = 1;
                get_1 = j;
                break;
            }
        }
    }
}

//takes any integer number and converts it in binary 
int* make_bin(int num)
{
    
    int lower = num, sum = 0,mod[1000],mod_r[1000],j=0,inde =0;
    while (lower)
    {
        mod[j] = lower % 2;
        lower /= 2;
        j++;
    }

    //get_mod_reverse stores the real binary of the int
    for (;;)
    {
        mod_r[inde] = mod[j - 1];
        j--;
        inde++;
        if (j == 0)
        {
            break;
        }
    }
    return mod_r;
}



void frac_bit()
{
    //if there is a 1 in the integer part of number
    if(expo>=0)
    {
        //gets the fractional length of fractional bits
        int len_frac = abs(index-get_1)+siz;
        int incre=get_1,frac_incre=0;
        for(int k=0;k<len_frac;k++)
        {
            if(incre<=index)
            {
                make_frac[k]=get_mod_reverse[incre];
                incre++;
            }
            else
            {
                make_frac[k] = get_frac[frac_incre];
                frac_incre++;
            }
             
        }
    }
    //if there is 1 in the fractional part of the binary
    else
    {
           int len_frac = siz+expo,incre=get_1+1;
           for(int k=0;k<len_frac;k++)
           {
               
               make_frac[k]=get_frac[incre];
               incre++;
               if(incre == siz)
               {
                   break;
               }
           }
    }      
}

//driver fucntion
int main()
{
    turn_off();
    input();
    get_frac_int();
    convert_binary_int();
    convert_binary_frac();
    search_1();
    
    //debugger
    //cout<<"hello world"<<endl;
    return 0;
}