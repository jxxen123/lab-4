//
//  main.cpp
//  lab4 uber driver
//
//  Created by icaza  jennifer on 11/11/22.
//

#include <iostream>
#include <iomanip>

#define FEDERAL_TAX 15.3

using namespace std;

float riderPays(float lengthM, float distanceM, char vehicle,float multi, char surge );

float driversShare( float fare, float tip);
void output(float fare, float drivers);



int main() {
    // declare variables
    
    float lengthM;
    float distanceM;
    char vehicle, surge;
    float tip;
    float fare, multi;
    float drivers;
    
    
    //user input
    cout << "Length of ride in minutes: ";
    cin >> lengthM;
    if(lengthM<0){
        
        cout<<"time can not be negative"<<endl;
        exit(0);
    }
    cout << "Distance of ride in miles: ";
    cin >> distanceM;
    if(distanceM<0){
        cout<<"distance can not be negative"<<endl;
        exit(0);
    }
        
        cout << "Enter 'X' for uberX or 'S' for SUV or ‘L for luxury: ";
        cin >> vehicle;
        vehicle = toupper(vehicle);
   // if((vehicle!='X')||(vehicle!='S')||(vehicle!='L')){
        
      //  cout<<"Wrong Car Type"<<endl;
       // exit(0);
            cout << "Enter 'Y' if surge or 'N' if not: ";
            cin >> surge;
            surge = toupper(surge);
    if(surge == 'Y'){
        
        cout << "Enter surge multiplier: ";
        cin >> multi;
        if(multi<0){
            
            cout<<"Surge can not be negative"<<endl;
            exit(0);
        }
        cout << "Amount of tip: ";
        cin >> tip;
    }
                // calling functions
                fare = riderPays(lengthM, distanceM, vehicle, multi,surge);
                
               //  output(fare, drivers);
     output(fare, drivers);
    
                cout << "Email: icazajennifer.college@gmail.com " << endl;
                cout << "Name: Jennifer Icaza" << endl;
                cout << "Lab #4 UBer" << endl;
                
                
                return 0;
                
                
                
                // function for calculationg toal ride fare
            }

void output(float fare, float drivers ){
    cout << "Fare:            $                     " <<fare << endl;
    
    cout << "Drivers Earnings: $                    " << fixed << setprecision(2) << drivers << endl;
 }

float driversShare( float fare, float tip ){
    float drivers = fare *.75;
    
  //  drivers = (fare * .75 + tip) - FEDERAL_TAX;
    
    return drivers;
}

float riderPays(float lengthM, float distanceM, char vehicle,float multi, char surge ){
    float baseF, fare;
    
    if (surge == 'N'){ // rides NOT including surge
        
        if(vehicle == 'X'){
            
            fare = 2 + (lengthM * .22)+(distanceM *1.15);
            if(fare < 6.55){
                
                fare = 6.55; // min fare needed
            }
        }
        if(vehicle == 'S'){
            
            fare = 15 +( lengthM * .90) + (distanceM * 3.75);
            if(fare < 25.00)
            {
                fare  = 25.00; // min fare needed
            }
        }
        else if (vehicle == 'L'){
            
            fare = 5 + (lengthM * .5) + (distanceM *2.75);
            if(fare < 10.55){
                
                fare = 10.55;// min fare needed
            }
            
        }
    }
    
    if(surge == 'Y'){// rides including surge
        
        if(vehicle =='X'){
            baseF = 2 * multi;
            fare = baseF + ( lengthM * .22) + (distanceM * 1.15);
            if(fare < 6.55){
                fare = 6.55; // min fare needed
            }
        }
        if(vehicle == 'S'){
            baseF = 15 * multi;
            fare = baseF +(lengthM * .90) +(distanceM * 3.75);
            if(fare < 25.00){
                fare =25.00; //min fare needed
            }
        }
        if(vehicle == 'L'){
            baseF = 5 * multi;
            fare = baseF + (lengthM * .50) + (distanceM + 2.75);
            if(fare< 10.55){
                fare = 10.55; //min fare needed
            }
        }
    }
    return fare;
}
    
 //

/*
float driversShare( float fare, float tip ){
    float drivers = fare *.75;
    
   drivers = (fare * .75 + tip) - FEDERAL_TAX;
    
    return drivers;
}

// function that returns output
void output(float fare, float drivers ){
    cout << "Fare:            $                     " <<fare << endl;
    
    cout << "Drivers Earnings: $                    " << fixed << setprecision(2) << drivers << endl;
 }
//

    
}

double riderPays( double length, double distance){
double total = length + 2;

return total;
    
    
}
                 
void output(double total){
    cout << "Total: " << total << endl;
}
*/
