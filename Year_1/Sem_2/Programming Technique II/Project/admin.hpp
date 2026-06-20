#ifndef ADMIN_HPP
#define ADMIN_HPP

#include <string>
using std::string;

class Customer;
class Admin{
    private:
        string username;
        string password;

    public:
        Admin();
        ~Admin();
        bool checkusername(string uname);
        bool checkpw(string pw);
        void selection(int &numPremium, int &numTwin, int &numTriple, int &numFamily,double &totalSales);
        void updateavailable(int &numpremiun, int &numtwin, int &numtriple, int &numfamily);
        void Sales( double &totalSales);
        
};

#endif