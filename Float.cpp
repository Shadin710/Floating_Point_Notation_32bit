#include<bits/stdc++.h>
using namespace std;

//12.2  = 12 => lower = lower_number
//0.2  = 0.2= >frac
//convert  lower_number => binary
//convert frac =>binary (run the loop 24 times)
//check the sign bit
//for 1 <=number there will be 1 at first index
//normalize the number 1.01111010101....*2^10
//10 =>expo +127 =>convert to binary
//plug everything in this array
//IEEE [SIGN BIT(1)] [EXPO BIT(8)] [FRACTIONAL BIT(23)]





vector<int> make_frac,bin_int,expo_bin,IEEE;
float frac,number,frac_temp;
int lower_number,get_int_frac,check=0,get_1,expo,i,j,sign;
int get_bin,lower,expo_size;





//turns_off the sync
void turn_off()
{
    cin.tie(0);
    cout.tie(0);
}
void input()
{
    cin>>number;
}
void check_sign()
{
    if(number<0)
    {
        number = fabs(number);
        sign = 1;
    }
    else
    {
        sign = 0;
    }
}
void get_in_fr()
{
    //taking the integer part
     lower_number = number;
     lower = number;
    //taking fractional part
    frac = number-lower_number;
}

//converts integer to binary
void convert_int_binary()
{
    while(lower!=0)
    {
        get_bin = lower%2;
        bin_int.push_back(get_bin);
        lower/=2;
    }
    reverse(bin_int.begin(),bin_int.end());
}
//converts_fraction to binary
void convert_frac_binary()
{
    frac_temp = frac;
    //for(i = 0;i<24;i++)
     while(i<50)
    {
        frac_temp = frac_temp*2;
        get_int_frac = frac_temp;

        //don't never ever check a fractional number is equal to zero -_-
        if(lower_number!=0 || check==1)
        {
            make_frac.push_back(get_int_frac);
        }
        else if(get_int_frac==1&&check==0)
        {
            get_1 = i+1;
            check =1;
        }
//        else if (check==1)
//        {
//            make_frac.push_back(get_int_frac);
//        }
        frac_temp = frac_temp - get_int_frac;
        i++;
    }
    //every integer number has 1 at first place so we don't need to calculate it
     if(lower_number!=0)
     {
         get_1 = 1;
     }
}
void get_expo()
{
    expo_size = bin_int.size()-get_1;
    expo = expo_size+127;
}
void convert_expo_binary()
{
     while(expo!=0)
     {
         //ex= expo %2;
         IEEE.push_back(expo%2);
         expo = expo/2;
     }
}
void make_valid()
{
    //to make it 8 bit exponential  if in put is 0.0/0.111......
     if(lower_number==0)
     {
         IEEE.push_back(0);
     }
     //pushing the sign bit
     IEEE.push_back(sign);

     reverse(IEEE.begin(),IEEE.end());
}
void ieee_format()
{
     //no need to make it reverse
     for(i=1;i<bin_int.size();i++)
     {
         IEEE.push_back(bin_int[i]);
     }

     for(i=0;i<make_frac.size();i++)
     {
         IEEE.push_back(make_frac[i]);
     }
}
void display()
{
     cout<<"IEEE754(32 bit): ";
     for(i=0;i<32;i++)
     {
         cout<<IEEE[i]<<"";
     }
     cout<<endl;
}
//driver function
int main()
{
    turn_off();

    input();
    check_sign();

    get_in_fr();
    convert_int_binary();

    //cout<<"hello int binary works ";
    //need to fix this bug
    convert_frac_binary();
  //  cout<<"hello ";


    get_expo();
    convert_expo_binary();

    make_valid();

    ieee_format();
  //  cout<<"hello 2";

    display();

    return 0;

}
