#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
#define N 300
int mat[N * N * 3], mat_gray[N * N], mat_yiq[3 * N * N];
int main()
{
    freopen("KittenRGB.txt", "r", stdin);

    // Storing pixel values in a 300*300 matrix 
    for (int i = 0; i < 3 * N * N; i++)
    {
        cin >> mat[i];
    }
    // sequential code
    double start, end;
    
    // rgb to gray scale
    start = omp_get_wtime();
    for (int i = 0; i < 300 * 300 * 3; i += 3)
    {
        int R = mat[i];
        int G = mat[i + 1];
        int B = mat[i + 2];
        mat_gray[i] = (R * 0.21) + (G * 0.72) + (B * 0.07);
        mat_yiq[i] = (0.299 * R) + (0.587 * G) + (0.114 * B);
        mat_yiq[i + 1] = (0.596 * R) - (0.275 * G) - (0.321 * B);
        mat_yiq[i + 2] = (0.212 * R) - (0.523 * G) + (0.311 * B);
    }
    end = omp_get_wtime();
    cout << "Time taken by sequential code = " << (end - start) << "s\n";
    
    // parallel
    // num_threads=2
    start = omp_get_wtime();
#pragma omp parallel num_threads(2)
    {
#pragma omp for
        for (int i = 0; i < N * N * 3; i += 3)
        {
            int R = mat[i];
            int G = mat[i + 1];
            int B = mat[i + 2];
            mat_gray[i] = (R * 0.21) + (G * 0.72) + (B * 0.07);
            mat_yiq[i] = (0.299 * R) + (0.587 * G) + (0.114 * B);
            mat_yiq[i + 1] = (0.596 * R) - (0.275 * G) - (0.321 * B);
            mat_yiq[i + 2] = (0.212 * R) - (0.523 * G) + (0.311 * B);
        }
    }
    end = omp_get_wtime();
    cout << "Time taken by 2 threads in parallel = " << (end - start) << "s\n";
    
    // num_threads=4
    start = omp_get_wtime();
#pragma omp parallel num_threads(4)
    {
#pragma omp for
        for (int i = 0; i < N * N * 3; i += 3)
        {
            int R = mat[i];
            int G = mat[i + 1];
            int B = mat[i + 2];
            mat_gray[i] = (R * 0.21) + (G * 0.72) + (B * 0.07);
            mat_yiq[i] = (0.299 * R) + (0.587 * G) + (0.114 * B);
            mat_yiq[i + 1] = (0.596 * R) - (0.275 * G) - (0.321 * B);
            mat_yiq[i + 2] = (0.212 * R) - (0.523 * G) + (0.311 * B);
        }
    }
    end = omp_get_wtime();
    cout << "Time taken by 4 threads in parallel = " << (end - start) << "s\n";
    
    // num_threads=8
    start = omp_get_wtime();
#pragma omp parallel num_threads(8)
    {
#pragma omp for
        for (int i = 0; i < N * N * 3; i += 3)
        {
            int R = mat[i];
            int G = mat[i + 1];
            int B = mat[i + 2];
            mat_gray[i] = (R * 0.21) + (G * 0.72) + (B * 0.07);
            mat_yiq[i] = (0.299 * R) + (0.587 * G) + (0.114 * B);
            mat_yiq[i + 1] = (0.596 * R) - (0.275 * G) - (0.321 * B);
            mat_yiq[i + 2] = (0.212 * R) - (0.523 * G) + (0.311 * B);
        }
    }
    end = omp_get_wtime();
    cout << "Time taken by 8 threads in parallel = " << (end - start) << "s\n";
    
    // num_threads=16
    start = omp_get_wtime();
#pragma omp parallel num_threads(16)
    {
#pragma omp for
        for (int i = 0; i < N * N * 3; i += 3)
        {
            int R = mat[i];
            int G = mat[i + 1];
            int B = mat[i + 2];
            mat_gray[i] = (R * 0.21) + (G * 0.72) + (B * 0.07);
            mat_yiq[i] = (0.299 * R) + (0.587 * G) + (0.114 * B);
            mat_yiq[i + 1] = (0.596 * R) - (0.275 * G) - (0.321 * B);
            mat_yiq[i + 2] = (0.212 * R) - (0.523 * G) + (0.311 * B);
        }
    }
    end = omp_get_wtime();
    cout << "Time taken by 16 threads in parallel = " << (end - start) << "s\n";
    
    // write grayscale to file
    freopen("GrayScale.txt", "w", stdout);
    cout << "Gray Scale format\n";
    cout<<"-------------------------------\n";
    for (int i = 0; i < N * N; i++)
        cout << mat_gray[i] << " ";
    
    // write yiq to file
    freopen("YIQ format.txt", "w", stdout);
    cout << "YIC format\n";
    cout<<"-------------------------------\n";
    for (int i = 0; i < N * N * 3; i++)
        cout << mat_yiq[i] << " ";
}