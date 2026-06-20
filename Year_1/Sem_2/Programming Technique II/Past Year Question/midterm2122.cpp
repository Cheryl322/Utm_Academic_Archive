#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class Line{
    private:
        int m;
        int c;
    public:
        Line(int n=1, int d=0){
            m=n;
            c=d;
        }
        void read(){
            cout<<"Enter the slope(m) and y-intercept of a line(c) =>";
            cin>>m>>c;
        }
        Line operator-(Line right){
            Line line;
            line.m = m- right.m;
            line.c = c- right.c;
            return line;//return Line(m-right.m,c-right.c)
        }
        bool operator !=(Line right){
            if((m*right.m)!=-1)
                return true;
            else
                return false;    
        }
        string toString(){
            string equation ="y=";
            if(m==1)
                equation += "x";
            else if (m==-1)
                equation +="-x";
            else
                equation += to_string(m) +"x";
            if (c>0)
                equation += "+"+ to_string(c);
            else if(c==0)
                equation ;
            else
                equation += to_string(c);   
            return equation;          
        }
        friend void printlines(Line line[]);

};

void printlines(Line line[]){
    cout<<endl;
    for(int i=0 ; i<3 ; i++){
        cout<<"Line"<<i+1;
        cout<<" slope(m) = ";
        cout<<line[i].m <<", y-intercept(c) = "<<line[i].c<<", equation: "<<line[i].toString()<<endl;
    }
}

int main(){
    Line line[3] = {{1,5}};
    cout<<"ORIGINAL LINES"<<endl;
    printlines(line);
    cout<<endl;
    cout<<"Set the second line from user input"<<endl;
    line[1].read();
    line[2]=line[0]-line[1];
    cout<<"UPDATED LINES"<<endl;
    printlines(line);

    if(line[0]!=line[2])
        cout<<"The first line is not perpendicular to the last line"<<endl;
    else
       cout<<"The first line is perpendicular to the last line"<<endl; 

    system("pause");
    return 0;
}



