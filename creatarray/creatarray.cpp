// creatarray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class Array {
    // private attribute in this class will be the length and the size of our  array
private:
    int length;
    int size;
    int* items;
public:
    // make constractor for the array to take the array size from the user
    Array(int arrsize)
    {
        size = arrsize;
        length = 0;
        items = new int[arrsize]; // using new keyword here to make daynamic allocation
    }
    // using fill method to fill the arry items
    void fill()
    {
        int no_of_items;
        cout << "How Many Items Do You Need to Fill? \n";
        cin >> no_of_items;
        if (no_of_items > size)
        {
            cout << "Number of items more than size! /n";
            return;
        }
        else
        {
            for (int i = 0; i < no_of_items; i++)

            {
                cout << "Enter No Of Items" << i << endl;
                cin >> items[i];
                length++;
            }
        }
    }
    // display method to display the array items
    void display()
    {
        cout << "Display Array Content \n";
        for (int i = 0; i < length; i++)
        {
            cout << items[i] << "\t";
            cout << endl;

        }
    }
    int getsize()
    {
        return size;
    }
    int getlength()
    {
        return length;
    }
    // search method will back the item which we search about
    int search(int key)
    {
        int index = -1;
        for (int i = 0; i < length; i++)
        {

            if (items[i] == key)
            {
                index = i;
                break;
            }
            return index;
        }
    }
    // using append to add item for the end of our array 
    void append(int newitem)
    {
        if (length < size)
        {
            items[length] = newitem;
            length++;
        }
        else
            cout << "array is full \n";
    }
    // start insert method

    void insert(int index, int newitem)
    {
        
        if (index >= 0 && index < size)
        {
           
            for (int i = length; i > index; i--)
            {
                items[i] = items[i - 1];
                items[i] = newitem;

            }
        }
        else
            cout << "index out of range \n";
    }
    // end insert method

    //start delete method
    void Delete(int index)
    {
        if (index >= 0 && index < size)
        {
            for (int i = index; i < length - 1; i++)
            {
                items[i] = items[i + 1];
                length--;
            }
        }
        else
            cout << "index out of the array range \n";

    }
    // end delete method

    // start enlarge method
    void enlarge(int newsize)
    {
        if (newsize < size)
        {
            cout << "new size must be larger than the old size \n";
        }
        else
        {
            size = newsize;
            int* old = items;
            items = new int[newsize];
            for (int i = 0; i < length; i++)
            {
                items[i] = old[i];
            }
            delete[]old;
        }
    }
    //end enlargr method
};


int main()
{
    // start fill method 
    cout << "Hello This Is ADT \n";
    int arraysize;
    cout << "enter the arry size \n";
    cin >> arraysize;
    Array myarray(arraysize);
    myarray.fill();
    cout << "arrya size is = " << myarray.getsize() << "while my length is = " << myarray.getlength() << "\n";
    myarray.display();
    // end fill method 

    // start search method
    cout << "enter the word search : \n";
    int key;
    cin >> key;
    int index = myarray.search(key);
    if (index == -1)
        cout << "the word not found \n";
    else
        cout << "index found at " << index << endl;
    // end serch method 

    // start append method 
    int newitem;
    cout << "enter new item to add to the array \n";
    cin >> newitem;
    myarray.append(newitem);
    myarray.display();
    // end append method 

    // start insert method 

    cout << "enter index and item \n";
    cin >> index;
    cin >> newitem;
    myarray.insert(index, newitem);
    myarray.display();
    cout << "arrya size is = " << myarray.getsize() << "while my length is = " << myarray.getlength() << "\n";

    // end insert method 

    // start  delete method 

    cout << "enter the index to delete its item \n";
    cin >> index;
    myarray.Delete(index);
    myarray.display();
    cout << "arrya size is = " << myarray.getsize() << "while my length is = " << myarray.getlength() << "\n";

    // end delete method

    // start enlarge array
    
    cout << "enter  new size array \n";
    int newsize;
    cin >> newsize;
    myarray.enlarge(newsize);
    cout << "arrya size is = " << myarray.getsize() << "while my length is = " << myarray.getlength() << "\n";
    myarray.display();
}


