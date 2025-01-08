using namespace std;
#include <bits/stdc++.h>

struct heap
{
    vector<int> values = {0};
    int size = 0;

    void push(int newValue)
    {
        size++;
        values.push_back(newValue);
        int j = size;
        j/=2;
        while(j > 0)
        {
            if(2*j+1 <= size && values[j] < values[2*j+1])
                swap(values[j], values[2*j+1]);
            else if(values[j] < values[2*j])
                swap(values[j], values[2*j]);
            else
                return;         
            j /= 2;
        }
    }

    int findMax()
    {
        if(size == 0)
        {
            throw invalid_argument( "Heap is empty but findMax was invoked." );
        }
        return values[1];
    }

    int extractMax()
    {
        if(size == 0)
        {
            throw invalid_argument( "Heap is empty but extractMax was invoked." );
        }
        int m = values[1];
        values[1] = values[size];
        values.pop_back();
        size--;

        int j = 1;

        while(j <= size)
        {
            int indMax = j;
            for(int k = 2*j; k <= 2*j+1; k++)
                if(k <= size && values[k] > values[indMax])
                    indMax = k;
            
            if(indMax != j)
            {
                swap(values[j], values[indMax]);
                j = indMax;
            }
            else
                return m;
        }
        return m;
    }

    void print()
    {
        for(int i =1; i < values.size(); i++)
            cout << values[i] << " ";
        cout << endl;
    }
};


int main()
{
    heap a;
    a.print();
    a.push(42);
    a.print();
    a.push(3);
    a.print();
    a.push(50);
    a.print();
    a.push(2);
    a.print();
    a.push(7);
    a.print();
    a.extractMax();
    a.print();
    a.extractMax();
    a.print();
    cout << a.findMax();

}
