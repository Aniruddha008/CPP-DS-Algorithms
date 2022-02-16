#include<iostream>
#include<vector>
using namespace std; 

//declaration
void Initialization();
void PrintVector(const vector<int> &array);
void CapacityInfo();
void ElementAccess();
void Modifiers();
void MultiDimensionalVectors();
void Print2DVectors(const vector<vector<int>> &array);
void VectorPairs();
void PrintVectorPairs();

//methods
void PrintVector(const vector<int> &array)
{
    cout << "\n";
    for(auto x: array)
    {
        cout << x << " ";
    }
    cout << "\n";
}

void Print2DVectors(const vector<vector<int>> &array)
{
    cout << "\n";
    for(int i = 0; i < array.size(); i++)
    {
        for(int j = 0; j < array[i].size(); j++)
        {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
}

void PrintVectorPairs(const vector<pair<int, int>> array)
{
    cout << "\n";
    for(auto x : array)
    {
        cout << "number1 = " << x.first << ", number2 = " << x.second << "\n";
    }
}

void Initialization()
{
    //1. push values one by one
    vector<int> array1;
    array1.push_back(1);
    array1.push_back(2);
    array1.push_back(3);

    PrintVector(array1);

    //2. specify size = 5 and elements to be inserted = 0
    vector<int> array2(5, 0);

    PrintVector(array2);

    //3. initialize like arrays
    vector<int> array3 {1, 2, 3};

    PrintVector(array3);

    //4. initialize from another array
    vector<int> array4 {3, 2, 1, 0};
    vector<int> test (array4.begin(), array4.end()); 

    PrintVector(test);

    //5. initialize with indices from another vector
    //print from 2nd index till end
    vector<int> array5 {10, 20, 30, 40, 50};
    vector<int> test2(array5.begin() + 2, array5.end());

    PrintVector(test2);
}

void CapacityInfo()
{
    vector<int> array1;

    cout << "\nIs the vector empty?: " << array1.empty() ; 

    for(int i = 0; i < 4; i++)
    {
        array1.push_back(i);
    }

    cout << "\nIs the vector empty?: after push_back() " << array1.empty();
    cout << "\nSize = " << array1.size();
    cout << "\nCapacity at 4 elements is 4 => " << array1.capacity();
    //capacity doubles up 4, 8, 16...
    array1.push_back(4);
    array1.push_back(5);
    cout << "\nSize after 2 pushback's = " << array1.size();
    cout << "\nCapacity at 6 elements is 8 => " << array1.capacity();

    array1.pop_back();
    array1.pop_back();
    cout << "\nSize after 2 popback's = " << array1.size();
    cout << "\nCapacity after popping does'nt change => " << array1.capacity();

    array1.shrink_to_fit();
    cout << "\nWith shrink_to_fit(), capacity reduces to fit the array size";
    cout << "\nSize = " << array1.size();
    cout << "\nCapcity after shrink_to_fit() = " << array1.capacity();


}

void ElementAccess()
{
    vector<int> array = {11, 24, 56, 72, 109, 123};
    PrintVector(array);

    cout << "\nwith array[0] = " << array[0];
    cout << "\nwith array.at(0) = " << array.at(0);
    cout << "\nfront() element = " << array.front();
    cout << "\nback() element = " << array.back();
    int *pos = array.data();
    cout << "\npointer to the first element, data() = " << *pos; 
}

void Modifiers()
{
    vector<int> array {1, 2, 4};
    PrintVector(array);

    cout<< "\ninsert 3 at 2 index .insert(array.begin() + 2, 3)";
    array.insert(array.begin() + 2, 3);
    PrintVector(array);

    cout << "\nerase the element at 2nd index with .erase(array.begin() + 2)";
    array.erase(array.begin() + 2);
    PrintVector(array);

    cout << "\nclear the array";
    array.clear();
}

void MultiDimensionalVectors()
{
    vector<vector<int>> array;
    cout << "\nInitialize like 2d Arrays ";
    array = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    };

    Print2DVectors(array);

    cout << "\nInitialize it directly : vector<vector<int>> array2(m, vector<int>(n, 0)) ";
    vector<vector<int>> array2(3, vector<int>(3, 0));

    Print2DVectors(array2);

}

void VectorPairs()
{
    vector<pair<int, int>> array;

    cout << "\nInitialize like arrays";
    array = 
    {
        {1, 1},
        {2, 4},
        {3, 9},
        {4, 16},
        {5, 25}
    };

    PrintVectorPairs(array);

    cout << "\nInitialize with make_pair: array2(n, make_pair(0, 0))";
    vector<pair<int, int>> array2(3, make_pair(0, 0));

    PrintVectorPairs(array2);
}

int main()
{
   //Initialization();

    //CapacityInfo();

    //ElementAccess();

    //Modifiers();

    //MultiDimensionalVectors();

    //VectorPairs();

    return 0;
}