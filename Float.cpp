//initializing header files
#include<iostream>
#include<cmath>
#include<math.h>
#include<algorithm>
using namespace std;

//global variable
float number,frac_number,store_frac[1000];
int i=0,lower_number,get_mod[1000];
int get_mod_reverse[1000],index=0,get_frac[1000];
int siz=0;


//turns off the sync in cin and cout
//makes the program faster
void turn_off()
{
    cin.tie(0);
    cout.tie(0);
}

void input()
{
    cin>> number;
}
void get_frac_int()
{
    lower_number = floor(number);
    frac_number  = number-lower_number;
}

//converts integer number to binary 7=>binary
void convert_binary_int()
{
    int lower = lower_number,sum=0;
    while(lower)
    {
        get_mod[i] = lower%2;
        lower /=2;
        i++;
    }

    //get_mod_reverse stores the real binary of the int
    for(;;)
    {
        get_mod_reverse[index] = get_mod[i-1];
        i--;
        index++;
        if(i==0)
        {
            break;
        }        
    }
}

//this is a simple binary search 
int bin_search(int frac)
{
    sort(store_frac,store_frac+siz);

    int start=0,end =siz-1,mid,flag=0;
    while (start<=end &&store_frac [start]<=store_frac[end])
    {
        mid = (start+end)/2;
        if(store_frac[mid]==frac)
        {
            flag =1;
            break;
        }
        else if(store_frac[mid]>frac)
        {
            end = mid;
        }
        else if(store_frac[mid]<frac)
        {
             start = mid;
        }
        else
        {
            flag=0;
        }
    }
    return flag;
}


//converts fraction number to binary 0.01 =>binary
void convert_binary_frac()
{
    float frac= frac_number;
    while(frac!=0)
    {
        //stores the fractional number
        store_frac [siz]=frac;

        //method to convert binary
        frac = frac *2;
        get_frac[siz] = floor(frac);
        frac = fabs(frac-get_frac[siz]);
        siz++;
        //end
    
        //checks the repeatation of the frac number by using binary search
        if(bin_search(frac)) 
        {
            break;
        }
    }
}




//driver fucntion
int main()
{
    turn_off();
    input();
    get_frac_int();



    cout<<"hello world"<<endl;
    return 0;
}