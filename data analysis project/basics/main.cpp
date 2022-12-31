#include <bits/stdc++.h>
#include <iostream>
using namespace std;

double mean(vector<double>&vec);
double median (vector<double>&vec);
int mode(vector<double>&vec);
int range(vector<double>&vec);
double first_quartile (vector<double>&vec);
double third_quartile (vector<double>&vec);
double interquartile_range (vector<double>&vec);
double variance (vector<double>&vec);
double standard_deviation (vector<double>&vec);
void measures_center (vector<double>&vec);
void measures_spread (vector<double>&vec);
void solve(vector<double>&vec);

int main()
{
    string setOfnumbers,temp="";

    vector <double>elements;

    cout<<"Enter set of numbers in a single line:"<<"\n";
    getline(cin,setOfnumbers);

    // to insert numbers into the array
    for(int i=0; i<setOfnumbers.size(); i++)
    {
        if(isdigit(setOfnumbers[i]))
        {
            temp += setOfnumbers[i];

        }
        else if(temp !="")
        {

            double t= stod(temp);
            elements.push_back((t));
            temp="";
        }
    }
    // to insert the last element into the array
    if(temp!="")
    {
        double t=stod(temp);
        elements.push_back((t));
    }

    sort(elements.begin(),elements.end());



     solve(elements);



    return 0;
}

double mean(vector<double>&vec)
{
    double mean;
    mean=accumulate(vec.begin(),vec.end(),0)/ vec.size();
    return mean;

}

double median (vector<double>&vec)
{

    double  sizeOfVec=vec.size(),mid_index=sizeOfVec/2,median;

    if((int)sizeOfVec%2==0)
    {
        median= (vec[mid_index-1] + vec[mid_index])/2;
    }

    else
    {
        median=vec[mid_index];

    }

    return median;

}

int mode(vector<double>&vec)
{

    int number= vec[0], mode= number, counter= 1, countMode= 1;

    for (int i=1; i<vec.size(); i++)
    {

        if (vec[i] == number)
        {
            counter++;
        }

        else
        {
            if (counter > countMode)
            {
                countMode = counter;
                mode = number;
            }
            counter = 1;
            number = vec[i];
        }
    }
    if(countMode>1)
    {
        return mode;
    }

    else
        return -1;

}

int range(vector<double>&vec)
{
    return vec[vec.size()-1]-vec[0];

}
double first_quartile (vector<double>&vec)
{
    int mid_index=vec.size()/2;
    vector<double>sub_vec(mid_index);

    for(int i=0; i<mid_index; i++)
        sub_vec[i]=vec[i];

    double first_quartile = median(sub_vec);

    return first_quartile;


}
double third_quartile (vector<double>&vec)
{
    int mid_index=vec.size()/2, j=0;
    vector<double>sub_vec(mid_index);
    if(vec.size()%2==0)
    {
        for(int i=mid_index; i<vec.size(); i++)
        {
            sub_vec[j]=vec[i];
            j++;
        }
    }
    else
    {
        for(int i=mid_index+1; i<vec.size(); i++)
        {
            sub_vec[j]=vec[i];
            j++;
        }

    }
    double third_quartile = median(sub_vec);

    return third_quartile;

}
double interquartile_range (vector<double>&vec)
{

    return third_quartile(vec)-first_quartile(vec);

}
double variance (vector<double>&vec)
{

    double variance=0, m=mean(vec);


    for(int i=0; i<vec.size(); i++)
    {
        variance +=  pow(vec[i]-m,2)/ (vec.size()-1);

    }

    return variance;

}
double standard_deviation (vector<double>&vec)
{
    return sqrt(variance(vec));
}
void measures_center (vector<double>&vec)
{
    char c;
    cout<<"Please, choose a measure to calculate:"<<"\n";
    cout<<"\n";
    cout<<"N:Mean"<<"\n";
    cout<<"I:Median"<<"\n";
    cout<<"D:Mode"<<"\n";
    cout<<"A:All"<<"\n";

    cin>>c;
    if(c=='N')
    {
        cout<<"Mean= "<<mean(vec)<<"\n";
    }
   else if(c=='I')
    {
        cout<<"Median= "<<median(vec)<<"\n";
    }

   else if(c=='D')
    {
        if(mode(vec) == -1)
        {
             cout<<"No mode"<<"\n";

        }

        else
        {
            cout<<"Mode= "<<mode(vec)<<"\n";
        }

    }
   else if(c=='A')
    {
        cout<<"Mean= "<<mean(vec)<<"\n";
        cout<<"Median= "<<median(vec)<<"\n";
        if(mode(vec) == -1)
        {
             cout<<"No mode"<<"\n";

        }

        else
        {
            cout<<"Mode= "<<mode(vec)<<"\n";
        }
    }
    else
    {
        cout<<"Wrong input"<<"\n";

        measures_center(vec);
    }

}
void measures_spread (vector<double>&vec)
{
    char s;
    cout<<"Please, choose a measure to calculate:"<<"\n";
    cout<<"\n";
    cout<<"R:Range"<<"\n";
    cout<<"Q:Quartiles"<<"\n";
    cout<<"S:Standard deviation"<<"\n";
    cout<<"V:Variance"<<"\n";
    cout<<"A:All"<<"\n";
    cin>>s;

    if(s=='R')
    {
        cout<<"Range= "<<range(vec)<<"\n";
    }
   else if(s=='Q')
    {
        cout<<"First quartile= "<<first_quartile(vec)<<"\n";
        cout<<"Second quartile= "<<mean(vec)<<"\n";
        cout<<"Third quartile= "<<third_quartile(vec)<<"\n";
        cout<<"Interquartile range= "<<interquartile_range(vec)<<"\n";
    }
    else if(s=='S')
    {
        cout<<"Standard deviation= "<<standard_deviation(vec)<<"\n";
    }
    else if(s=='V')
    {
        cout<<"Variance= "<<variance(vec)<<"\n";
    }
    else if(s=='A')
    {
        cout<<"Range= "<<range(vec)<<"\n";
        cout<<"First quartile= "<<first_quartile(vec)<<"\n";
        cout<<"Second quartile= "<<mean(vec)<<"\n";
        cout<<"Third quartile= "<<third_quartile(vec)<<"\n";
        cout<<"Interquartile range= "<<interquartile_range(vec)<<"\n";
        cout<<"Standard deviation= "<<standard_deviation(vec)<<"\n";
        cout<<"Variance= "<<variance(vec)<<"\n";

    }
    else
    {
        cout<<"Wrong input !"<<"\n";
        measures_spread(vec);

    }



}
void solve(vector<double>&vec)
{
    int num;
    char yn;
    cout<<"Choose type of measures to calculate:"<<"\n";
    cout<<"\n";
    cout<<"1:Measures of center"<<"\n";
    cout<<"2:Measures of spread"<<"\n";
    cin>>num;
    if(num==1)
    {
        measures_center(vec);
    }
    else if(num==2)
    {
        measures_spread(vec);
    }
    else
    {
        cout<<"Wrong input"<<"\n";
        solve(vec);
    }
    cout<<"\n";
    cout<<"DO you want to do other calculations?"<<"\n";
    cout<<"Y:Yes"<<"\n";
    cout<<"N:No"<<"\n";
    cin>>yn;
    if(yn=='Y')
    {
        solve(vec);
    }

}

