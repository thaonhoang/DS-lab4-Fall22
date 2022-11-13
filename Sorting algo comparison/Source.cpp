#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <string>
#include <iomanip>
#include <sstream>
#include <algorithm>
#define MaxMNumber 100000000

using namespace std;
typedef chrono::high_resolution_clock Clock;

//std::string str = "11011";
//size_t n = 8;
//
//int precision = n - std::min(n, str.size());
//std::string s = std::string(precision, '0').append(str);





// Task 1
template<class T>
class OrderedLinkedList
{
private:
    struct ListNode
    {
        T value;
        ListNode* next;
    };//struct for linked list

    ListNode* head; //head of linked list
    ListNode* location; //location of the list(used specifically for SeeAt, SeeNext and Reset.

public:
    OrderedLinkedList() //constructor
    {
        head = nullptr;
    }


    ~OrderedLinkedList() //destructor
    {
        if (!isEmpty())
        {
            ListNode* currentPtr = head;
            ListNode* tempPtr = currentPtr;

            while (currentPtr != 0)
            {
                tempPtr = currentPtr;
                currentPtr = currentPtr->next;
                delete tempPtr;
            }
        }
    }

    void AddItem(T);//appends item to end of linked list
    T Getitem(T); //gets item and deletes from list
    bool isInList(T); //Checks if element is in the list
    bool isEmpty(); // bool to check list is empty
    int Size(); //returns size of list
    T SeeAt(int); //finds an item at a location and returns item without removing it
    T SeeNext(); //returns the item without removing it from given list at a given location in the list
    void Reset(); //Resets location that the SeeNext function uses to point at first item in the list

    void Print(); //Prints out data elements of linked list
};

template<class T>
void OrderedLinkedList<T>::AddItem(T data)
{
    ListNode* newNode;
    ListNode* nodePtr;

    newNode = new ListNode;
    newNode->value = data;
    newNode->next = nullptr;

    if (!head)
    {
        head = newNode;
    }
    else
    {
        nodePtr = head;
        while (nodePtr->next)
        {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}

template<class T>
T OrderedLinkedList<T>::Getitem(T data)
{
    ListNode* nodePtr = new ListNode;
    ListNode* previousNode = new ListNode;
    T t;
    if (head->value == data)
    {
        t = head->value;
        nodePtr = head->next;
        delete head;
        head = nodePtr;

    }
    else
    {
        nodePtr = head;
        /*while (nodePtr->next != nullptr && nodePtr->value != data)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }*/
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
        if (nodePtr)
        {
            t = nodePtr->value;
            previousNode->next = nodePtr->next;
            delete nodePtr;

        }


    }
    return t;
}

template<class T>
bool OrderedLinkedList<T>::isInList(T data)
{
    ListNode* nodePtr;


    if (head->value == data)
    {
        return true;
    }
    else
    {
        nodePtr = head;
        while (nodePtr != NULL)
        {
            if (nodePtr->value == data)
            {
                return true;
            }
            nodePtr = nodePtr->next;
        }
        return false;
    }
}

template<class T>
int OrderedLinkedList<T>::Size()
{
    int count = 0;
    ListNode* current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;

    }
    return count;
}

template<class T>
bool OrderedLinkedList<T>::isEmpty()
{
    if (head == nullptr)
        return true;

    else
        return false;
}

template<class T>
T OrderedLinkedList<T>::SeeAt(int loc)
{
    ListNode* nodePtr;
    int count = 0;
    nodePtr = head;
    while (count < loc)
    {
        if (nodePtr->next == nullptr)
        {
            throw "empty list!";
        }
        nodePtr = nodePtr->next;
        count++;
    }

    location = nodePtr->next;
    return nodePtr->value;
}

template<class T>
T OrderedLinkedList<T>::SeeNext()
{
    ListNode* nodePtr = location;
    /*if (nodeptr->next == nullptr)
    {
        throw exception();
    }*/
    nodePtr = location;
    location = nodePtr->next;
    return nodePtr->value;
}

template<class T>
void OrderedLinkedList<T>::Reset()
{
    location = head;
}

template <class T>
void OrderedLinkedList<T>::Print()
{
    ListNode* tempPtr = head;
    cout << R"(
      _________ .__           .___             __    .____    .__          __
     /   _____/ | |_ __ __  __| _/____   _____/  |_  |    |   |__| _______/  |_  
     \_____  \\   __\  |  \/ __ |/ __ \ /    \   __\ |    |   |  |/  ___/\   __\  
     /        \|  | |  |  / /_/ \  ___/|   |  \  |   |    |___|  |\___ \  |  | 
    /_______  /|__| |____/\____ |\___  >___|  /__|   |_______ \__/____  > |__| 
            \/                 \/    \/     \/               \/       \/         )";

    int n = 0;
    string output = "";
    for (int i = 0; i < 100; i++) {
        output += "-";
    }
    cout << output << endl;
    while (tempPtr != nullptr)
    {

        cout << "Student number " << n + 1 << ": ";
        cout << tempPtr->value << endl;
        tempPtr = tempPtr->next;
        n++;
    }
    cout << output << endl;
}

//Task 2: create a class to represesnt a part that will be used as the
// item stores in the list

class Student
{
private:

    string FirstName;
    string LastName;
    string MNumber;
    float GPA;
    string Birthday;
    int year = 2022;

public:
    Student()
    {
        FirstName = " ";
        LastName = " ";
        MNumber = " ";
        GPA = 0.0;
        Birthday = " ";

    }
    Student(string FName, string LName, string MNum, float gpa, string bday)
    { //Constructor
        FirstName = FName;
        LastName = LName;
        MNumber = MNum;
        GPA = gpa;
        Birthday = bday;
    }
    void SetFirstName(string s)
    {
        FirstName = s;
    }
    string getFirstName()
    {
        return FirstName;
    }
    void SetLastName(string p)
    {
        LastName = p;
    }
    string getLastName()
    {
        return LastName;
    }
    void SetMNumber(string m)
    {
        MNumber = m;
    }
    int GetMNumber()
    {
        return stoi(MNumber.substr(1, 8));
    }
    void SetBirthday(string b)
    {
        Birthday = b;
    }
    string getBirthday()
    {
        return Birthday;
    }
    void SetGPA(float g)
    {
        GPA = g;
    }
    float GetGPA()
    {
        return GPA;
    }
    int GetAge() {
        int Age = year - stoi(Birthday.substr(5, 4));
        return Age;
    }


    string getName()
    {
        return FirstName + " " + LastName;
    }

    bool operator> (Student AStudent) {
        int A;
        int B;
        A = this->GetMNumber();
        B = AStudent.GetMNumber();
        if (A > B) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator< (Student AStudent) {
        int A;
        int B;
        A = this->GetMNumber();
        B = AStudent.GetMNumber();
        if (A < B) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator== (Student AStudent) {
        int A;
        int B;
        A = this->GetMNumber();
        B = AStudent.GetMNumber();
        if (A == B) {
            return true;
        }
        else {
            return false;
        }
    }




    void Print()
    {
        cout << R"(
      _________ .__           .___             __    .____    .__          __
     /   _____/ | |_ __ __  __| _/____   _____/  |_  |    |   |__| _______/  |_  
     \_____  \\   __\  |  \/ __ |/ __ \ /    \   __\ |    |   |  |/  ___/\   __\  
     /        \|  | |  |  / /_/ \  ___/|   |  \  |   |    |___|  |\___ \  |  | 
    /_______  /|__| |____/\____ |\___  >___|  /__|   |_______ \__/____  > |__|  
            \/                 \/    \/     \/               \/       \/        )";

        string output = "";
        for (int i = 0; i < 100; i++) {
            output += "-";
        }
        cout << output << endl;
        cout << "Name: " << this->getName()
            << '\t' << "MNumber: " << this->MNumber
            << '\t' << "Birth Date: " << this->Birthday
            << '\t' << endl;
        cout << output << endl;
    }

    friend ostream& operator<<(ostream& output, const Student& student)
    {
        output << "Name: " << student.FirstName << " " << student.LastName
            << '\t' << "MNumber: " << student.MNumber
            << '\t' << "Birth Date: " << student.Birthday
            << '\t' << endl;
        return output;
    }


    ostream& operator<<(ostream& output)
    {
        output << "Name: " << this->getName()
            << '\t' << "MNumber: M" << this->MNumber
            << '\t' << "Birth Date: " << this->Birthday
            << '\t' << endl;
        return output;
    }

};





string FirstList[]{ "Liam","Emma","Amelia","Ava","Sophia","Isabella","Luna","Mia","Charlotte","Evelyn","Harper","Nova","Scarlett","Aurora","Ella","Mila","Aria","Ellie","Gianna","Sofia","Violet","Layla","Willow","Lily","Hazel","Olivia","Noah","Oliver","Elijah","Mateo","Lucas","Levi","Asher","James","Leo","Grayson","Luca","Ezra","Ethan","Aiden","Wyatt","Sebastian","Benjamin","Mason","Henry","Hudson","Jack","Jackson","Daniel","Owen",
};
string LastList[]{ "Smith","Johnson","Williams","Brown","Jones","Garcia","Miller","Davis","Rodriguez","Martinez","Hernandez","Lopez","Gonzalez","Wilson","Anderson","Thomas","Taylor","Moore","Jackson","Martin","Lee","Perez","Thompson","White","Harris","Sanchez","Clark","Ramirez","Lewis","Robinson","Walker","Young","Allen","King","Wright","Scott","Torres","Nguyen","Hill","Flores","Green","Adams","Nelson","Baker","Hall","Rivera","Campbell","Mitchell","Carter","Roberts",
};
int MNumberList[50];
void MNumber_Generator() {
    srand((unsigned)time(NULL));
    for (int i = 0; i < 50; i++)
    {
        int Mnum = rand() % (MaxMNumber);
        MNumberList[i] = Mnum;
    }
}


void ArrGenerator(int arr[], int n_ele)
{	
	srand((unsigned) time(NULL));
	for (int i = 0; i < n_ele; i++)
	{
		int num = rand() % (2*n_ele + 1);
		arr[i] = num;
	}
	/*for (int i = 0; i < n_ele; i++)
		cout << curr_arr[i] << " ";
	cout << endl;*/
}

//create pointer to point at two element next to each other
//and temp variable to store temporary 
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// An optimized version of Bubble Sort

void BubbleSort(int arr[], int n_ele)

{
	int i, j;
	bool swapped;
	for (i = 0; i < n_ele - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n_ele - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}

		}

		// IF no two elements were swapped by inner loop, then break

		if (swapped == false)

			break;

	}

}

void merge(int array[], int const left, int const mid,
    int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne
        = 0, // Initial index of first sub-array
        indexOfSubArrayTwo
        = 0; // Initial index of second sub-array
    int indexOfMergedArray
        = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
        && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void Mergesort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    Mergesort(array, begin, mid);
    Mergesort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

void Insertionsort()
{
    int q =1;
}
void Quicksort()
{
    int w =2;
}
void Heapsort()
{
    int e=3;
}
void Countingsort() {
    int r=4;
}
void Radixsort()
{
    int t = 5;
}
//void Mergesort(int arr[], int n_ele)
//{
//	int middle = n_ele / 2;
//	int f_arr = 
//}

/* Function to print an array */

//void printArray(int arr[], int size)
//
//{
//
//	int i;
//
//	for (i = 0; i < size; i++)
//
//		printf("%d ", arr[i]);
//
//	printf("n");
//
//}
//void print_timer(int t1, int t2, int t3, int t4, int t5, int t6, int t7, int t8)
//{
//   
//}
// Driver program to test above functions

int main()

{   
    int size = 0;
    const int size_list[]{ 10, 100, 500, 5000, 25000 };
	/*const int size1{ 10 };
	const int size2{ 100 };
	const int size3{ 500 };
	const int size4{ 5000 };
	const int size5{ 25000 };*/
    /*int arr1[size1];
	int arr2[size2];
	int arr3[size3];
	int arr4[size4];
	int arr5[size5];*/
    string type_of_sort[] = { "BubbleSort", "Insertionsort", "Mergesort","Quicksort", "Heapsort", "Countingsort", "Radixsort" };
	/*ArrGenerator(arr1, size1);
	ArrGenerator(arr2, size2);
	ArrGenerator(arr3, size3);
	ArrGenerator(arr4, size4);
	ArrGenerator(arr5, size5);*/
    /*cout << "Given array is \n";*/
    
    int z = 0;
    while (z != 1) //while loop for the menu
    {
        cout << "Which type of array?" << endl;
        cout << "(1) Size = 10\n";
        cout << "(2) Size = 100\n";
        cout << "(3) Size = 500\n";
        cout << "(4) Size = 5000\n";
        cout << "(5) Size = 25000\n";
        cout << "Or press any key to quit the program\n";
        cout << "Enter here:\n";
        int choice = 0;
        cin >> choice;
        if (choice > 5 || choice < 1) 
        {
            cout << "Exiting..." << endl;
            z = 1;
            return 0;
        }
        else
        {
            size = size_list[choice - 1];

        }
        int* arr = new int[size];
        ArrGenerator(arr, size);
        //printArray(arr, size);
        auto t0 = Clock::now();
        BubbleSort(arr, size);
        auto t1 = Clock::now();
        Insertionsort();
        auto t2 = Clock::now();
        Mergesort(arr, 0, size - 1);
        auto t3 = Clock::now();
        Quicksort();
        auto t4 = Clock::now();
        Heapsort();
        auto t5 = Clock::now();
        Countingsort();
        auto t6 = Clock::now();
        Radixsort();
        auto t7 = Clock::now();
        std::chrono::steady_clock::time_point time_list[] = { t0,t1,t2,t3,t4,t5,t6,t7 };
        for (int i = 0; i < 7; i++)
        {
            std::cout
                << type_of_sort[i] << ": "
                << std::chrono::duration_cast<std::chrono::nanoseconds>(time_list[i + 1] - time_list[i]).count()
                << " nanoseconds" << std::endl;
        }
        delete[] arr;
        MNumber_Generator();
        cout << MNumberList;
    }
    
    return 0;
}
    /*std::cout
    << "merge sort: "
    << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count()
    << " nanoseconds" << std::endl;*/
    

    /*cout << "\nSorted array is \n";
    printArray(arr1, size1);*/
   

