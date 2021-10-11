/*****************************************
Template written by Kazumi Slott
CS311

Your name: Jorge Ezequiel Garcia Lopez
Your programmer number: 08
Any difficulties?: ?????????
*******************************************/
#include <iostream>
using namespace std;

//print an integer array of size n
void print(int ar[], int n)
{
  for(int i = 0; i < n; i++)
    cout << ar[i] << " ";
  cout << endl;
}

//called from max_heapify and heapSort
/**
 * This function is swaps two values.
 */
void exchange(int &a, int &b)
{
  //I have 3 lines of code here.
  int temp = a;
  a = b;
  b = temp;
}

//turn a heap into a max-heap rooted at i, assuming the left and right subtrees are already max-heaps.
//n is the size of the heap
void max_heapify(int ar[], int n, int i)
{
  int l = (i*2)+1; //the index of the left child of i
  int r = (i*2)+2; //the index of the right child of i
  int largest;


  /* Left and Right subtrees must already be max-heaps */

  //look for the largest among 3 elements at i, l and r. largest gets the index of the largest value.
  //Make sure l and r don't go over the heap's range. 
  //Recall how you found the largest value among 3 values in CS111.
  //I have 6 lines of code here. You can have more or less.

  int lastNodeIndex = n-1;
  if (l <= lastNodeIndex && r <= lastNodeIndex)
  {
      if (ar[i] > ar[l] && ar[i] > ar[r])
      {
          largest = i;
      }
      else if (ar[l] > ar[r])
      {
          largest = l;
      }
      else
      {
          largest = r;
      }
      //largest = max(ar[i], max(ar[l],ar[r]));

      //The largest is either the right or left child. In other words, it is not the root at i.
      //if(ar[largest] != ar[i] && (ar[largest] == ar[l] || ar[largest] == ar[r]))
      if(largest != i)
      {
          //exchange the 2 values
          exchange(ar[largest], ar[i]);
          //There might be a violation at the position that was exchanged. Call max_heapify to fix it.
          max_heapify(ar, n, largest);
      }
  }
}


//turn the entire array/tree into a max heap rooted at 0
//n is the size of the array
void build_max_heap(int ar[], int n)
{
  //2 lines of code in this function
  /*
  for each non-leaf node
     call max_heapify (turn the smallest subtrees into max-heaps and work your way up)
  */
    for (int i = n/2 - 1; i >= 0; --i)
        max_heapify(ar, n, i);
}

//a is an unordered list to start with
//use max_heapify to sort a
//n is the size of the array
void heapSort(int a[], int n)
{
  //I have 6 lines of code in this function. You can have more or less.

  //build max heap from an unordered list
  //call build_max_heap
  build_max_heap(a, n);

  int size = n-1; //size of the unsorted portion of the array

  // while heap is least to greatest therefore stop when heap is a[i] < 0
    //while(size > 0) //repeat until heap is empty
    while(a[size] < a[0])
    {
      //swap max element with last element - max element is at the end of the array
      //Use exchange()
        exchange(a[size], a[0]);
     
      //discard the last node from heap
      --size;
     
      //root may violate max-heap property, but children are max heaps. run max_heapify to fix it.
        max_heapify(a, size, 0);

    }
}

//this function corrects a violation of max heap by bubbling up an element at i
// a is a heap
void bubbleUp(int a[], int i)
{
    //Write this function after you made insert() and while you are making remove.
}

//a is a max heap
//cap is the capacity of the heap
//n is the number of elements the heap currently has before insertion
//el is the new element to be inserted
void insert(int a[], int cap, int& n, int el)
{
    //refer to lecture notes
    // write this function without calling bubbleUp first. When you work on remove, you will see you will
    // have to have the same code there. Move the code into bubbleUp and call it.
}

//a is a max heap
//n is the number of elements the heap currently has before deletion, then decremented after deletion
// el is the element to be removed. Assume all elements are unique
void remove(int a[], int& n, int el)
{
    //refer to lecture notes
    //Call bubbleUp and max_heapify instead of coding the same things.
}

int main()
{
  int ar[10] = {11, 3, 4, 5, 7, 19, 20, 2, 8, 1};
  int ar2[10] = {5, 3, 10, 4, 7, 9, 11, 2, 8, 1};
  int ar3[2] = {2,1};

  cout << "testing max_heap rooted at index 3" << endl;
  max_heapify(ar, 10, 3); //max-heapify rooted at index 3                                                                                      
  print(ar, 10);//11 3 4 8 7 19 20 2 5 1  --> the tree rooted at 3 is now a max-heap (8 is at root. 2 and 5 are its children)

  cout << endl << "testing max_heap rooted at index 1" << endl;
  max_heapify(ar, 10, 1); //max-heapify rooted at index 1                                                                                      
  print(ar, 10);//11 8 4 5 7 19 20 2 3 1  --> the tree rooted at 1 is now a max-heap (8 is at root. 5 and 7 are its children. 5's children are 2 and 3)                                                                                                                                      

    cout << endl << "testing build_max_heap" << endl;
    build_max_heap(ar, 10);
    print(ar, 10);//20 8 19 5 7 11 4 2 3 1

  cout << endl << "testing heapSort" << endl;
  heapSort(ar2, 10);
  print(ar2, 10);//1 2 3 4 5 7 8 9 10 11                                                                                                       

    cout << endl << "testing heapSort" << endl;
    heapSort(ar3, 2);
    print(ar3, 2);//1 2

    cout << "testing insert" << endl;
    int ar4[15] = {20, 8, 19, 5, 7, 11, 4, 2, 3, 1, -1, -1, -1, -1, -1}; //max heap with 10 elements already
    int n = 10; //n is the number of elements in the heap
    insert(ar4, 15, n, 15); //trying to remove 15
    print(ar4, n); //20 15 19 5 8 11 4 2 3 1 7

    cout << "testing remove" << endl;
    remove(ar4, n, 15); //trying to remove 15
    print(ar4, n);//20 8 19 5 7 11 4 2 3 1

  return 0;
}

