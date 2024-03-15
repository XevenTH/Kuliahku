#include <iostream>

using namespace std;

int binarySearch(int arr[], int l, int r, int key)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            l = mid + 1;

        else
            r = mid - 1;
    }

    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;
    int result = binarySearch(arr, 0, n - 1, key);
    if (result != -1)
        cout << "Berhasil: " << result << endl;
    else
        cout << "Tidak berhasil" << endl;
    return 0;
}
