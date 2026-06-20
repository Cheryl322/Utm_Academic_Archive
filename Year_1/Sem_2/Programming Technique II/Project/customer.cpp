#include"admin.hpp"
#include"customer.hpp"

#include <iostream>
#include <iomanip>
//#include <string>

using namespace std;

Customer::Customer(): guests(0), roomType(0), numberOfRooms(0), totalCost(0.0) {}

int Customer::calcDays(string &checkInDate, string &checkOutDate){
   
    int day1 = stoi(checkInDate.substr(0, 2));
    int month1 = stoi(checkInDate.substr(3, 2));
    int year1 = stoi(checkInDate.substr(6, 4));

    int day2 = stoi(checkOutDate.substr(0, 2));
    int month2 = stoi(checkOutDate.substr(3, 2));
    int year2 = stoi(checkOutDate.substr(6, 4));

    const int days_per_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    int days1 = day1; 
    for (int y = 2020; y < year1; ++y) {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
            days1 += 366; // Leap year
        } else {
            days1 += 365;
        }
    }
    for (int i = 0; i < month1 -1; ++i) {
        days1 += days_per_month[i];
    }
    if (month1 > 2 && ((year1 % 4 == 0 && year1 % 100 != 0) || (year1 % 400 == 0))) {
        days1 += 1; // Leap year
    }
    

    int days2 =day2; 
    for (int y = 2020; y < year2; ++y) {
        if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
            days2 += 366; // Leap year
        } else {
            days2 += 365;
        }
    }
    for (int i = 0; i < month2 - 1; ++i) {
        days2 += days_per_month[i];
    }
    if (month2 > 2 && ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0))) {
        days2 += 1; // Leap year
    }

   
    return days2 - days1;
}

void Customer::enterInformation() {
   cout << "Enter your personal information\n";
    cout << "Name: ";
    cin.ignore();
    getline(cin,name,'\n');

    cout << "Email Address: ";
    //cin.ignore();
    getline(cin,email,'\n');
    
    cout << "Phone Number(without '-'): ";
    //cin.ignore();
    getline(cin, phone,'\n');
    cout << "Number of guests: ";
    cin >> guests;
   
    cout << "Check-in date(DD-MM-YYYY): ";
    cin >> checkInDate;
    cout << "Check-out date(DD-MM-YYYY): ";
    cin >> checkOutDate;
}


void Customer::availability(int &numPremium, int &numTwin, int &numTriple, int &numFamily)
{
    cout<<"\n--------------------------------------------------------------------------------------------------------"<<endl;
    cout << left << setw(50) << "Room Type " <<setw(13) << "Availability" <<right<< setw(27) << "Price Per Night(RM)" << endl;
    cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
    cout << left << setw(50) << "1. Premium Queen (1 queen bed)" << right << setw(7) << numPremium<< setw(26) << "RM200" <<endl;
    cout << left << setw(50) << "2. Standard Twin (2 single beds)" << right << setw(7) << numTwin <<setw(26) << "RM200" <<endl;
    cout << left << setw(50) << "3. Family Triple Room (1 queen bed, 1 single bed)" << right << setw(7) << numTriple <<setw(26) << "RM350" << endl;
    cout << left << setw(50) << "4. Family Suite (2 queen beds)" << right << setw(7) << numFamily <<setw(26) << "RM450" << endl;
    
    do
    {
        cout << "\nPlease select the room type (1-4):";
        cin >> roomType;

        if(roomType<1||roomType>4)
        {
            cout << "Your selection is invalid. Please select again: ";
            cin >> roomType;
        }    
    } while (roomType<1||roomType>4); //Enter Room Type
    
    cout << "Please enter the number of rooms: ";
    cin >> numberOfRooms;   //Enter Number of Rooms

    do
    {
        if(roomType==1)
        {
            if(numberOfRooms>numPremium) //Out of Range for Room Type 1
            {
                cout<<"\nSorry, Premium Queen Rooms are fully booked.\n";
                cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
                loop=true; //For loop again

            }
            else
            {
                numPremium-=numberOfRooms;  //Deduct the number of rooms booked
                loop=false;//End Loop
            }
        }
        else if(roomType==2)
        {
            if(numberOfRooms>numTwin)//Out of Range for Room Type 2
            {
                cout<<"\nSorry, Standard Twin Rooms are fully booked.\n";
                cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
                loop=true; //For loop again
            }
            else
            {
                numTwin-=numberOfRooms;
                loop=false; //End Loop
            }
        }
        else if(roomType==3)
        {
            if(numberOfRooms>numTriple)//Out of Range for Room Type 3
            {
                cout<<"\nSorry, Family Triple Rooms are fully booked.\n";
                cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
                loop=true; //For loop again
            }
            else
            {
                numTriple-=numberOfRooms;
                loop=false; //End Loop
            }
        }
        else
        {
            if(numberOfRooms>numFamily)//Out of Range for Room Type 4
            {
                cout<<"\nSorry, Family Suite Rooms are fully booked.\n";
                cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
                loop=true; //For loop again
            }
            else
            {
                numFamily-=numberOfRooms;
                loop=false; //End Loop
            }
        }

        int choice;

        if(loop==true) //For New Input as the room is out of range
        {
            cout<<"\n\nPlease enter: "<<endl;
            cout<<"1 Another room type if you still wanna remain the same number of rooms"<<endl;
            cout<<"2 Reduce number of rooms"<<endl;
            cout<<"Enter: ";
            cin>>choice;

            if(choice==1)
            {
                do
                {
                    cout << "\nPlease select the room type (1-4):";
                    cin >> roomType;

                    if(roomType<1||roomType>4)
                    {
                        cout << "Your selection is invalid. Please select again: ";
                        cin >> roomType;
                    }    

                    if(roomType==1)
                    {
                        if(numberOfRooms>numPremium)
                        {
                            loop=true; 
                        }
                        else
                        {
                            numPremium-=numberOfRooms;
                            loop=false;
                        }
                    }

                    else if(roomType==2)
                    {
                        if(numberOfRooms>numTwin)
                        {
                            loop=true; 
                        }
                        else
                        {
                            numTwin-=numberOfRooms;
                            loop=false;
                        }
                    }

                    else if(roomType==3)
                    {
                        if(numberOfRooms>numTriple)
                        {
                            loop=true; 

                        }
                        else
                        {
                            numTriple-=numberOfRooms;
                            loop=false;
                        }
                    }

                    else
                    {
                        if(numberOfRooms>numFamily)
                        {
                            loop=true; 
                        }
                        else
                        {
                            numFamily-=numberOfRooms;
                            loop=false;
                        }
                    }

                } while (roomType<1||roomType>4);    
            }

            else if(choice==2)
            {
                cout << "Please enter the number of rooms: ";
                cin >> numberOfRooms;

                if(roomType==1)
                {
                    if(numberOfRooms>numPremium)
                    {
                        cout<<"\nSorry, Premium Queen Rooms are fully booked.\n"<<endl;
                        cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
                        loop=true; 

                    }
                    else
                    {
                        numPremium-=numberOfRooms;
                        loop=false;
                    }
                }

                else if(roomType==2)
                {
                    if(numberOfRooms>numTwin)
                    {
                        cout<<"\nSorry, Standard Twin Rooms are fully booked.\n"<<endl;
                        cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
                        loop=true; 

                    }
                    else
                    {
                        numTwin-=numberOfRooms;
                        loop=false;
                    }
                }

                else if(roomType==3)
                {
                    if(numberOfRooms>numTriple)
                    {
                        cout<<"\nSorry, Family Triple Rooms are fully booked.\n"<<endl;
                        cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
                        loop=true; 

                    }
                    else
                    {
                        numTriple-=numberOfRooms;
                        loop=false;
                    }
                }

                else
                {
                    if(numberOfRooms>numFamily)
                    {
                        cout<<"\nSorry, Family Suite Rooms are fully booked."<<endl;
                        cout<<"\n--------------------------------------------------------------------------------------------------------"<<endl;
                        loop=true; 

                    }
                    else
                    {
                        numFamily-=numberOfRooms;
                        loop=false;
                    }
                }

            }
        }
    }while(loop);
}


void Customer::selectPaymentMethod() 
{
    cout << "\nPayment Method:\n1. Debit card\n2. Credit card\n3. FPX online banking\n4. E-wallet\n5. Pay at the hotel\n";
    cout << "Please select your payment method (1-5): ";
    cin >> paymentMethod;
    if(paymentMethod<1||paymentMethod>5)
    {
        cout << "Your selection is invalid. Please select again: ";
        cin >> paymentMethod;
    }    
    
}
    
void Customer::printReceipt(double &totalSales) 
{
    cout << "\n------------\nReceipt\n------------\n";
    cout << "You have successfully book your room." <<endl;
    cout << "Name: " << name << "\n";
    cout << "Email Address: " << email << "\n";
    cout << "Phone Number: " << phone << "\n";
    cout << "Number of guests: " << guests << "\n";
    cout << "Check-in date: " << checkInDate << "\n";
    cout << "Check-out date: " << checkOutDate << "\n";

    cout << "\n\n-------------------------------------------------------------------------------------------------\n";
    cout << left <<setw(50) << "Room Type " <<setw(13) << "Amount" <<setw(7) <<   "Price Per Night(RM) \n";
    cout << "-------------------------------------------------------------------------------------------------\n";

    nights=calcDays(checkInDate, checkOutDate);
    switch (roomType)
    {
        case 1:
                cout << left <<setw(50) << "Premium Queen" <<setw(13) << numberOfRooms << setw(10) <<  200*numberOfRooms;
                totalCost= 200*numberOfRooms*nights;
                totalSales += totalCost;
                break;
        case 2:
                cout << left <<setw(50) << "Standard Twin" <<setw(13) << numberOfRooms << setw(10) <<  200*numberOfRooms;
                totalCost= 200*numberOfRooms*nights;
                totalSales += totalCost;
                break;
        case 3:
                cout << left <<setw(50) << "Family Triple Room " <<setw(13) << numberOfRooms << setw(10) <<  350*numberOfRooms;
                totalCost= 350*numberOfRooms*nights;
                totalSales += totalCost;
                break;
        case 4:
                cout << left <<setw(50) << "Family Suite " <<setw(13) << numberOfRooms << setw(10) <<  450*numberOfRooms;
                totalCost= 450*numberOfRooms*nights;
                totalSales += totalCost;
                break;

        default:
                cout << "Invalid room type." << endl;
                break;
    }

    
    cout << "\n\nTotal cost for " <<nights<< " nights: RM " << totalCost <<endl;  
    cout << "Payment method: ";
    
    if(paymentMethod==1)
        cout << "Debit Card" <<endl;
    else if (paymentMethod==2)
        cout << "Credit Card" <<endl;
    else if (paymentMethod==3)
        cout << "FPX online banking" <<endl;
    else if (paymentMethod==4)
        cout << "E-wallet" <<endl;
    else 
        cout << "Pay at the Hotel" <<endl;
}
