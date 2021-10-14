//No entiendo los templates pero para nada


#include <iostream>
#include <algorithm>

using namespace std;


string x;
string y;
string z;
string d;

class Template
{
    public:
        void ordenar();
};

void Template:: ordenar(){
    d = x+y+z;
    sort(d.begin(), d.end());
    cout << d;
    
}

int main() 
{
    Template t;

    cout << "Dame el primer valor: \n";
    cin >> x;

    cout << "Dame el segundo valor: \n";
    cin >> y;

    cout << "Dame el tercer valor: \n";
    cin >> z;


    t.ordenar();

// No lo entiendo

    // int a[5] = {10, 50, 30, 40, 20};// aqui estas diciendo que va a ser un tipo int
    // int n = sizeof(a) / sizeof(a[0]);
  
    // bubbleSort<int>(a, n);
  
    // cout << " Sorted array : ";
    // for (int i = 0; i < n; i++)
    //     cout << a[i] << " ";
    // cout << endl;

    return 0;
}

// template <class T>
// void bubbleSort(T a[], int n) { entonces para que pones aqui el template si ya has dicho que es un tipo int
//     for (int i = 0; i < n - 1; i++)
//         for (int j = n - 1; i < j; j--)
//             if (a[j] < a[j - 1])
//               swap(a[j], a[j - 1]);
// }

