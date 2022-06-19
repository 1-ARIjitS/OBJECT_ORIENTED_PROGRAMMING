#include <bits/stdc++.h>

using namespace std;

class house
{
    public:
    int bhk;

    private:
    double plot_size;
    string address;

    public:
    char *name;
    static int timeforsale;

    public:
    //simple constructor
    house()
    {
       cout<<"parametrized constructor created and called"<<endl;
       cout<<"address of this is- "<<this<<endl;
       name= new char[100];
    }

    //parameterized constructor
    house(int bhk, double plotsize, string addrress)
    {
        cout<<"parametrized constructor created and called"<<endl;
        cout<<"address of this is- "<<this<<endl;
        this->bhk=bhk;
        this->plot_size=plotsize;
        this->address=addrress;
        name=new char[100];
    }

    //constructor overloading
    house(int bhk, double plotsize, string addrress, char ch[])
    {
        cout<<"overloaded parametrized constructor created and called"<<endl;
        cout<<"address of this is- "<<this<<endl;
        this->bhk=bhk;
        this->plot_size=plotsize;
        this->address=addrress;
        name= new char[100];
        strcpy(this->name,ch);
    }

    //custom copy constructor

    // you need to pass the house object h as pass by reference because
    //if you pass it by pass by value then it will get stuck in an infinite loop
    //due to the fact that call by value always creates a copy of object and as we call the copy constructor
    //it repeatedly takes in copies as input and get stuck in an infinite loop

    house(house &h)
    {
        cout<<"custom made copy constructor created and called"<<endl;
        this->bhk=h.bhk;
        this->plot_size=h.plot_size;
        this->address=h.address;

        //deep copy implemented here

        char *ch= new char[100];
        strcpy(ch,h.name);
        this->name=ch;
    }

    //getters
    int getbhk()
    {
        return bhk;
    }
    double getplotsize()
    {
        return plot_size;
    }
    string getaddress()
    {
        return address;
    }


    //setters
    void setbhk(int bhk)
    {
        this->bhk=bhk;
    }
    void setplotsize(double plot_size)
    {
        this->plot_size=plot_size;
    }
    void setaddess(string address)
    {
        this->address=address;
    }
    void setname(char name[])
    {
        strcpy(this->name, name);
    }

    // Destructor
    ~house()
    {
       cout<<"destructor created and called"<<endl;
    }

    //static function
    static int random()
    {
        return timeforsale;
    }

    //methods
    void isgood();
    void print();
};

void house::isgood()
{
        int bhk=this->bhk;
        double plotsize=this->plot_size;
        if(bhk>=5 && plotsize>2000)
        {
            cout<<"it is an outstanding house to buy"<<endl;
        }
        else if((bhk>3 && bhk<5) && (plotsize>1000 && plotsize<2000))
        {
            cout<<"it is a good house to buy"<<endl;
        }
        else
        {
            cout<<"it is not a great house to buy"<<endl;
        }
}

void house::print()
{
    cout<<"name- "<<this->name<<endl;
    cout<<"bhk- "<<this->bhk<<endl;
    cout<<"plot size- "<<this->plot_size<<endl;
    cout<<"address- "<<this->address<<endl;
}

//accessing the static data member
int house::timeforsale=10;

int main()
{
    /*house h1;
    cout<<"size of house object h1- "<<sizeof(h1)<<endl;
    h1.setplotsize(2000.54);
    h1.setbhk(7);
    h1.setaddess("bbsr");
    cout<<"plot size- "<<h1.getplotsize()<<endl;
    cout<<"address- "<<h1.getaddress()<<endl;
    cout<<"bhk- "<<h1.getbhk()<<endl;
    h1.isgood(h1.getbhk(),h1.getplotsize());*/

    //new object created dynamic allocation in heap
    /*house *h2= new house(10,5000.56,"airport,bbsr");
    cout<<"address of pointer h2 storing the address of object h2- "<<&h2<<endl;
    cout<<"address of new object h2 created is- "<<&(*h2)<<endl;
    cout<<"plot size- "<<(*h2).getplotsize()<<endl;
    cout<<"address- "<<h2->getaddress()<<endl;
    cout<<"bhk- "<<h2->getbhk()<<endl;
    h2->isgood(h2->getbhk(),(*h2).getplotsize());
    cout<<endl;*/

    //new object created static allocation
    /*house h2(10,5000.56,"airport,bbsr");
    char name[15]="sunshine villa";
    h2.setname(name);
    cout<<"address of new object h2 created is- "<<&h2<<endl;
    cout<<"plot size- "<<h2.getplotsize()<<endl;
    cout<<"address- "<<h2.getaddress()<<endl;
    cout<<"bhk- "<<h2.getbhk()<<endl;
    h2.isgood(h2.getbhk(),h2.getplotsize());
    cout<<endl;
    cout<<endl;*/

    //using the copy constructor to create a similar house object h3
    /*house h3(h2);
    cout<<"address of new object h3 created is- "<<&h3<<endl;
    cout<<"plot size- "<<h3.getplotsize()<<endl;
    cout<<"address- "<<h3.getaddress()<<endl;
    cout<<"bhk- "<<h3.getbhk()<<endl;
    h2.isgood(h3.getbhk(),h2.getplotsize());
    cout<<endl;*/

    //deep and shallow copy
    //default constructor always uses shallow copy
    //so string value changes when address string of copied object changes
    //this can be removed or tackled using a deep copy user made in the custom copy constructor

    //shallow copy- stores reference of objects
    /*house h3(h2);
    h2.name[0]='g';
    cout<<"h2 name- "<<h2.name<<endl;
    cout<<"h3 name- "<<h3.name<<endl;*/

    //deep copy- stores copies of objects made by custom constructor
    /*house h3(h2);
    h2.name[0]='g';
    cout<<"h2 name- "<<h2.name<<endl;
    cout<<"h3 name- "<<h3.name<<endl;*/

    //copy assignment operator
    /*cout<<"before copy assignment"<<endl;
    cout<<"------------------------"<<endl;
    char ch1[15]="sunshine villa";
    house h1(10,5000.56,"airport,bbsr",ch1);
    h1.isgood();
    h1.print();
    cout<<endl;
    char ch2[20]="majestic heights";
    house h2(3,1000.56,"bhopal bypass",ch2);
    h2.isgood();
    h2.print();
    cout<<endl;
    cout<<endl;

    //copy assignment operator called
    cout<<"after copy assignment"<<endl;
    cout<<"------------------------"<<endl;
    h2=h1;
    cout<<"address of h1 object- "<<&h1<<endl;
    h1.isgood();
    h1.print();
    cout<<endl;
    cout<<"address of h2 object- "<<&h2<<endl;
    h2.isgood();
    h2.print();*/

    //destructor- to deallocate the memory
    //destructor automatically called for static allocation
    /*house h1(5,2000.56,"bbsr");
    //destructor not automatically called for dynamic allocation
    house *h2= new house(10,3000.56,"bhadrak");
    //manually calling destructor using delete keyword
    delete h2;*/

    //static keyword
    //it can be accessed without creating an object
    /*cout<<house::timeforsale<<endl;
    //it can also be accessed after creating the object
    house h1(10,2000.36,"bbsr");
    cout<<h1.timeforsale<<endl;
    //its value can also be changed for an object
    h1.timeforsale=15;
    cout<<h1.timeforsale<<endl;*/

    //static functions
    //can only access the static data members
    cout<<"accessing the static function and time for sale is- "<<house::random()<<endl;
}
