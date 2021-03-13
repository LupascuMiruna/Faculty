#include <iostream>
#include<fstream>
#include<chrono>
#include<vector>
#include<queue>
#include<algorithm>



using namespace std;
using namespace std::chrono;


ifstream fin("input.in");
ofstream fout("output.out");





///BUBBLESORT

vector<int> BubbleSort(vector<int> v, int n)
{
    int i;
    bool ordo = false;
    while(!ordo)
    {
        ordo = true;
        for (i = 0; i < n-1 ; ++i)
            if (v[i] > v[i+1])
                {
                    swap(v[i], v[i+1]);
                    ordo = false;
                }
    }
    return v;

}

///COUNT SORT

vector<int> CountSort(vector<int> v, int n,int maxi)
{
    int f[maxi + 1] = {0};
    vector <int> aux;
    int i, j;
    for(i = 0; i < n; ++i)
        f[v[i]]++;
    for(i = 0; i <= maxi; ++i)
        for(j = 1; j <= f[i]; ++j)
            aux.push_back(i);
    return aux;
}

///MERGE SORT
void interclasare(vector<int> &v, int s, int m, int d)
{
    int i = s, j = m + 1;
    vector <int > aux;
    while (i <= m && j<= d)
        if (v[i] < v[j])
            aux.push_back(v[i++]);
        else
            aux.push_back(v[j++]);
    while (i <= m)
       aux.push_back(v[i++]);
    while (j <= d)
        aux.push_back(v[j++]);
    for(i = s; i <= d; ++i)
        v[i] = aux[i-s];
}


void MergeSort(vector <int> &v, int s, int d)
{

    if (s < d)
    {
        int m = (s+d)/2;
        MergeSort(v, s, m);
        MergeSort(v, m + 1, d);
        interclasare(v, s, m, d);
    }
}

///QUICK SORT

int pivot(vector<int> &v, int st, int dr)
{
    return v[rand()% (dr-st+1) + st];
}
void QuickSort(vector<int> &v, int st, int dr)
{
    int i = st, j = dr;
    int x = pivot(v, st, dr);
    while(i < j)
    {
        while(v[i] < x) i++;
        while(v[j] > x) j--;
        if(i <= j) swap(v[i++], v[j--]);
    }
    if(j > st) QuickSort(v, st, j);
    if(i < dr) QuickSort(v, i, dr);
}


///RADIX SORT
void RadixSort16(vector<int> &v, int n)
{
    queue<int> q[16];
    int k;
    for(int i = 0; i <= 24; i += 4)
    {
        for(int j = 0; j < n; ++j)
            q[(v[j]>>i)&15].push(v[j]);
        k = 0;
        for(int j = 0; j <= 15 && k < n; ++j)
            while(!q[j].empty())
            {
                v[k++] = q[j].front();
                q[j].pop();
            }
    }
}


void RadixSort256(vector<int> &v, int n)
{
    queue<int> q[256];
    int k;
    for(int i = 0; i <= 24; i += 8)
    {
        for(int j = 0; j < n; ++j)
            q[(v[j]>>i)&255].push(v[j]);
        k = 0;
        for(int j = 0; j <= 255 && k < n; ++j)
            while(!q[j].empty())
            {
                v[k++] = q[j].front();
                q[j].pop();
            }
    }
}



bool sorted(vector<int> v, int n)
{
    int i;
    for (i = 0; i < n-1; ++i)
        if (v[i] > v[i+1])
            return false;
    return true;
}
void afiseaza(vector<int>v, int n)
{
    int i;
    for (i = 0; i <= n-1; ++i)
        fout << v[i] <<"\n";
}



int main()
{

   int T;
   vector <int> v;
   vector <int> aux;
   vector <int> sortat;

   int n, maxi, i, j;
   fin >> T;
   for (j = 1; j <= T; ++j)
   {
       v.clear(); //golim spatiul de memorie
       fin >> n >> maxi;
       for(i = 1; i <= n; ++i)
            v.push_back(rand()%maxi + 1);
       fout <<"Test " << j <<" n = " << n <<", maximum value = "<<maxi <<"\n";

       ///STL: Native
       if(n >= 100000000) fout << "STL Sort: FAILED, n too large!\n";
        else
        {
            aux = v;
            auto start = high_resolution_clock::now();
            sort(aux.begin(), aux.end());
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop-start);
            fout << "Native(STL) Sort: SUCCEEDED " << duration.count() << " ms\n";

            sortat = aux;
        }




       ///BUBBLE SORT
        if(n > 10000)
        fout << "Bubble Sort FAILED, n too large\n";
       else
        {
            auto start = high_resolution_clock::now();
            aux = BubbleSort(v,n);
            auto stop = high_resolution_clock::now();
            if(sorted(aux, n) == true && aux == sortat)
                {
                    auto duration = duration_cast<milliseconds>(stop-start);
                    fout << "Bubble Sort SUCCEEDED "<<duration.count() << " ms\n";
                }
            else  fout << "Bubble Sort FAILED \n";
        }


        ///COUNT SORT

        if(maxi >= 1000000) fout << "Count Sort FAILED, maximum value too large.\n";
        else if(n >= 100000000)fout << "Count Sort FAILED, n too large.\n";
        else
        {
            auto start = high_resolution_clock::now();
            aux = CountSort(v, n, maxi);
            auto stop = high_resolution_clock::now();
            if(sorted(aux, n) == true && aux == sortat)
                {
                    auto duration = duration_cast<milliseconds>(stop-start);
                    fout << "Count Sort SUCCEEDED "<<duration.count() << " ms\n";
                }
            else  fout << "Count Sort FAILED \n";
        }

        ///MERGE SORT

        if(n >= 10000000)
            fout << "Merge Sort FAILED, n too large\n";
        else
        {
            aux = v;
            auto start = high_resolution_clock::now();
            MergeSort(aux, 0, n-1);
            auto stop = high_resolution_clock::now();
            if(sorted(aux, n) == true && aux == sortat)
                {
                    auto duration = duration_cast<milliseconds>(stop-start);
                    fout << "Merge Sort SUCCEEDED "<<duration.count() << " ms\n";
                }
            else  fout << "Merge Sort FAILED \n";
        }

        ///QUICK SORT

        if(n >= 100000000)
            fout << "Quick Sort FAILED, n too large\n";
        else
        {
            aux = v;
            auto start = high_resolution_clock::now();
            QuickSort(aux, 0, n-1);
            auto stop = high_resolution_clock::now();
            if(sorted(aux, n) == true && aux == sortat)
                {
                    auto duration = duration_cast<milliseconds>(stop-start);
                    fout << "Quick Sort SUCCEEDED "<<duration.count() << " ms\n";
                }
            else  fout << "Quick Sort FAILED \n";
        }

        ///RADIX SORT

         if(n >= 100000000) fout << "Radix Sort FAILED, n too large\n";
         else
            {

                /// Radix Sort in baza 256
                aux = v;
                auto start = high_resolution_clock::now();
                RadixSort256(aux, n);
                auto stop = high_resolution_clock::now();
                if(sorted(aux, n) == true && aux == sortat)
                {
                    auto duration = duration_cast<milliseconds>(stop-start);
                    fout << "Radix Sort base 256 SUCCEEDED " << duration.count() << " ms\n";
                }
                else fout << "Radix Sort base 256 FAILED\n";

                /// Radix Sort in baza 16
                aux = v;
                start = high_resolution_clock::now();
                RadixSort16(aux, n);
                stop = high_resolution_clock::now();
                if(sorted(aux, n) == true && aux == sortat)
                {
                auto duration = duration_cast<milliseconds>(stop-start);
                fout << "Radix Sort base 16 SUCCEEDED " << duration.count() << " ms\n";
                }
                else fout << "Radix Sort base 16 FAILED\n";



            }



        fout << "\n";

   }
}






