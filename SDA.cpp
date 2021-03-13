#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

//-----Afisare-----
void afisare(int lungime, int vector)
{
    for (int i = 0; i < lungime; i++)
    {
        cout << vector[i];
    }
}

//-----Maxim-----
int maxim(int lungime, int vector[])
{
    int i, maxim =  vector[0];
    for (i = 1; i < lungime; i++)
    {
        if (vector[i] > maxim)
        {
            maxim = vector[i];
        }
    }
    return maxim;
}

//-----Swap-----

void swap(int vector[], int a, int b)
{
    int aux;
    aux = vector[a];
    vector[a] = vector[b];
    vector[b] = aux;
}

//-----Generare-----

void generareVector(int lungime, int maxim, int v[])
{
    int i;

    srand((unsigned) time (NULL));
    for (i = 0; i < lungime; i++)
    {
        v[i] = rand() % maxim;
    }
}

//-----Bubble Sort-----O(n^2)

void bubbleSort(int lungime, int v[])
{
    int ok, i, aux;
    do
    {
        ok = 0;
        for (i = 0; i < lungime - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                ok = 1;
            }
        }
    } while (ok == 1);
}

//-----CountingSort-----O(n)

void countingSort(int lungime, int vector[]) 
{
    int max = maxim(lungime, vector);
    int *frecventa = new int[max + 1];
    int i, aux;
    for (i = 0; i <=  max + 1; i++)
    {
        frecventa[i] = 0;
    }
    for (i = 0; i < lungime; i++)
    {
        frecventa[vector[i]] += 1;
    }
    for (i = 0, aux = 0; i < lungime; )
    {
        if (frecventa[aux] == 0)
        {
            aux++;
        }
        else
        {
            vector[i] = aux;
            frecventa[aux]--;
            i++;
        }
    }
}

//-----InsertionSort-----O(n^2)

void insertionSort(int lungime, int vector[])
{
    int i, index_minim;
    for (i = 0; i < lungime; i++)
    {
        index_minim = i;
        for (int j = i; j < lungime; j++)
        {
            if (vector[j] < vector[index_minim])
            {
                index_minim = j;
            }
        }
        swap(vector, i, index_minim);
    } 
}

//-----QuickSort-----O(nlogn)

int partitie(int vector[], int stanga, int dreapta)
{
    int pivot = vector[dreapta];
    int i = stanga - 1, j;
    for (j = stanga; j <= dreapta; j++)
    {
        if (vector[j] < pivot)
        {
            i++;
            swap(vector, vector[i], vector[j]);
        }
        swap(vector[i + 1], vector[dreapta]);
    }
    return (i + 1);
}

void quickSort(int vector[], int stanga, int dreapta)
{
    if (stanga < dreapta)
    {
        int index = partitie(vector, stanga, dreapta);
        quickSort(vector, stanga, index - 1);
        quickSort(vector, index + 1, dreapta);
    }
}

//-----SelectionSort-----O(n^2)

void selectionSort(int lungime, int vector[])
{
    int i, j, aux, minim, pozitie_minima;
    for (i = 0; i < lungime - 1; i++)
    {
        pozitie_minima = i;
        minim = vector[i];
        for (j = i + 1; j < lungime; j++) 
        {
            if (minim > vector[j]) 
            {
                pozitie_minima = j;
                minim = vector[j];
            }
        }
        swap(vector, vector[i], vector[pozitie_minima]);
    }
}

//-----stalinSort-----

/*int* stalinSort(int lungime, int vector[], int& l)
{
    int k = 0, bigger = 0, i;
    int* vector2 = new int[lungime];
    for (i = 0; i < lungime; i++)
    {
        
        if (vector[i] >= bigger)
        {
            bigger = vector[i];
            vector2[k++] = vector[i];
        }
    }
    l = k;
    return vector2;
}
*/


//-----Main-----

int main()
{
    //to be updated...
    
    /*cout << "n = ";
    cin >> n;
    cout << "\n";
    for (i = 0; i < n; i++)
    {
        cout << "elementul " << i << " = ";
        cin >> v[i];
        cout << "\n";
    }
    bubbleSort(n, v);
    cout << "Vectorul sortat este: ";
    for (i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    /*
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> v[i];
    }
   /* insertionSort(n, v);
    cout << "Vectorul sortat este: ";
    for (i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    */
  /*  int l = 0;
    int* w = stalinSort(n, v, l);
    for (i = 1; i < l; i++)
    {
        cout << w[i]<<" ";
    }
    */
    return 0;
}
