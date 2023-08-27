#include <iostream>

using namespace std;

class Publication
{
private:
    string title;
    float price;

public:
    Publication()
    {
        title = "";
        price = 0;
    }

    virtual void setdata()
    {
        cout << "Enter a Title of publication : ";
        cin >> title;
        cout << "Enter a Price of publication : ";
        cin >> price;
    }

    virtual void displayData()
    {
        try
 		{
 			if(title.length()<3)
 				throw title;
 				
 			if(price<=0.0)
 				throw price;
 		}
 		catch(string)
 		{
 			cout<<"\nError: Title below 3 characters is not allowed";
 			title="";
 		}
 		
 		catch(float f)
 		{
 			cout<<"\nError: Price not valid: \t"<<f;
			price=0.0;
 		}	
 		cout<<"\nTitle is :"<<title;
 		cout<<"\nPrice is :"<<price;
    }

    ~Publication() {}
};



class Book : public Publication
{
private:
    int pagecount;

public:
    book()
    {
        pagecount = 0;
    }

    void setdata()
    {
        Publication::setdata();
        cout << "Enter Book Page Count : ";
        cin >> pagecount;
    }

    void displayData()
    {
        Publication::displayData();
        try
	 	{
	 		if(pagecount<0)
	 			throw pagecount ;
            else if(pagecount!=int)
                throw 'x';
	 	}
	 	catch(int f)
	 	{
	 		cout<<"\nError: Pages not valid: \t"<<f;
	 		pagecount=0;
 		}
        catch(char a){
            cout<<"character not allowed"<<endl;
            pagecount=0;
        }
        cout << "\nBook page count : " << pagecount << endl;
    }

    ~Book() {}
};



class Tape : public Publication
{
private:
    float playtime;

public:
    Tape()
    {
        playtime = 0;
    }

    void setdata()
    {
        Publication::setdata();
        cout << "Enter tape playing time: ";
        cin >> playtime;
    }

    void displayData()
    {
        Publication::displayData();
        try
		{
	 		if(playtime<0.0)
	 			throw playtime;
	 	}
	 	catch(float f)
	 	{
	 		cout<<"\nError: Playtime not valid: \t"<<f;
	 		playtime=0.0;
	 	}
        cout << "\nTape's playing time: " << playtime << endl;
    }

    ~Tape() {}
};



int main()
{
    Book b1;
    Tape t1;

    b1.setdata();
    t1.setdata();

    b1.displayData();
    t1.displayData();

    return 0;
}