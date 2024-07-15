#define _WIN32_WINNT 0x0601
#include <windows.h>
#include <process.h>
#include <immintrin.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE 1024 * 32
#define TEST_DURATION_MS 1000  // 30 seconds test duration

typedef struct {
    DWORD thread_id;
    __m256i* array;
    volatile bool* should_exit;
} ThreadData;

void SetThreadAffinity(HANDLE thread, int core_id) {
    DWORD_PTR mask = 1ULL << core_id;
    SetThreadAffinityMask(thread, mask);
}

DWORD WINAPI WorkerThread(LPVOID lpParam) {
    ThreadData* data = (ThreadData*)lpParam;
    __m256i a, b, c, d, e, f, g, h, i, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y ,z;
    __m256i sum1 = _mm256_setzero_si256();
    __m256i sum2 = _mm256_setzero_si256();
    __m256i sum3 = _mm256_setzero_si256();
    __m256i sum4 = _mm256_setzero_si256();
    __m256i sum5 = _mm256_setzero_si256();
    __m256i sum6 = _mm256_setzero_si256();
    __m256i sum7 = _mm256_setzero_si256();
    __m256i sum8 = _mm256_setzero_si256();
    __m256i sum9 = _mm256_setzero_si256();
    __m256i sum10 = _mm256_setzero_si256();
    __m256i sum11 = _mm256_setzero_si256();
    __m256i sum12 = _mm256_setzero_si256();
    
    while (!*(data->should_exit)) {
        for (int j = 0; j < ARRAY_SIZE; j += 8) {
            a = _mm256_load_si256(&data->array[j]);
            b = _mm256_load_si256(&data->array[j+1]);
            c = _mm256_load_si256(&data->array[j+2]);
            d = _mm256_load_si256(&data->array[j+3]);
            e = _mm256_load_si256(&data->array[j+4]);
            f = _mm256_load_si256(&data->array[j+5]);
            g = _mm256_load_si256(&data->array[j+6]);
            h = _mm256_load_si256(&data->array[j+7]);
            i = _mm256_load_si256(&data->array[j+8]);
            k = _mm256_load_si256(&data->array[j+9]);
            l = _mm256_load_si256(&data->array[j+10]);
            m = _mm256_load_si256(&data->array[j+11]);
            n = _mm256_load_si256(&data->array[j+12]);
            o = _mm256_load_si256(&data->array[j+13]);
            p = _mm256_load_si256(&data->array[j+14]);
            q = _mm256_load_si256(&data->array[j+15]);
            r = _mm256_load_si256(&data->array[j+16]);
            s = _mm256_load_si256(&data->array[j+17]);
            t = _mm256_load_si256(&data->array[j+18]);
            u = _mm256_load_si256(&data->array[j+19]);
            v = _mm256_load_si256(&data->array[j+20]);
            w = _mm256_load_si256(&data->array[j+21]);
            x = _mm256_load_si256(&data->array[j+22]);
            y = _mm256_load_si256(&data->array[j+23]);
            z = _mm256_load_si256(&data->array[j+24]);
            

            
            

            // Mix of AVX2 operations
            a = _mm256_add_epi32(a, b);
            b = _mm256_sub_epi32(b, c);
            c = _mm256_mullo_epi32(c, d);
            d = _mm256_sllv_epi32(d, a);
            e = _mm256_xor_si256(e, f);
            f = _mm256_or_si256(f, g);
            g = _mm256_and_si256(g, h);
            h = _mm256_andnot_si256(h, i);
            i = _mm256_andnot_si256(i, k);
            k = _mm256_andnot_si256(k, l);
            l = _mm256_andnot_si256(l, m);
            m = _mm256_andnot_si256(m, n);
            n = _mm256_andnot_si256(n, o);
            o = _mm256_andnot_si256(o, p);
            p = _mm256_andnot_si256(p, q);
            q = _mm256_andnot_si256(q, r);
            r = _mm256_andnot_si256(r, s);
            s = _mm256_andnot_si256(s, t);
            t = _mm256_andnot_si256(t, u);
            u = _mm256_andnot_si256(u, v);
            v = _mm256_andnot_si256(v, w);
            w = _mm256_andnot_si256(w, x);
            x = _mm256_andnot_si256(x, y);
            y = _mm256_andnot_si256(y, z);
            z = _mm256_andnot_si256(z, a);


            
            sum1 = _mm256_add_epi32(sum1, _mm256_add_epi32(_mm256_add_epi32(a, b), _mm256_add_epi32(c, d)));
            sum2 = _mm256_add_epi32(sum2, _mm256_add_epi32(_mm256_add_epi32(e, f), _mm256_add_epi32(g, h)));
            sum3 = _mm256_add_epi32(sum3, _mm256_add_epi32(_mm256_add_epi32(i, k), _mm256_add_epi32(l, m)));
            sum4 = _mm256_add_epi32(sum4, _mm256_add_epi32(_mm256_add_epi32(n, o), _mm256_add_epi32(p, q)));
            sum5 = _mm256_add_epi32(sum5, _mm256_add_epi32(_mm256_add_epi32(r, s), _mm256_add_epi32(t, u)));            
            sum6 = _mm256_add_epi32(sum6, _mm256_add_epi32(_mm256_add_epi32(v, w), _mm256_add_epi32(x, y)));

            sum7 = _mm256_add_epi32(sum1, _mm256_add_epi32(_mm256_add_epi32(a, z), _mm256_add_epi32(b, y)));
            sum8 = _mm256_add_epi32(sum2, _mm256_add_epi32(_mm256_add_epi32(c, x), _mm256_add_epi32(d, w)));
            sum9 = _mm256_add_epi32(sum3, _mm256_add_epi32(_mm256_add_epi32(e, v), _mm256_add_epi32(f, u)));
            sum10 = _mm256_add_epi32(sum4, _mm256_add_epi32(_mm256_add_epi32(g, t), _mm256_add_epi32(h, s)));
            sum11 = _mm256_add_epi32(sum5, _mm256_add_epi32(_mm256_add_epi32(i, r), _mm256_add_epi32(k, q)));            
            sum12 = _mm256_add_epi32(sum6, _mm256_add_epi32(_mm256_add_epi32(l, p), _mm256_add_epi32(m, o)));

            sum1 = _mm256_add_epi32(sum1, _mm256_add_epi32(_mm256_add_epi32(a, z), _mm256_add_epi32(b, y)));
            sum2 = _mm256_add_epi32(sum2, _mm256_add_epi32(_mm256_add_epi32(c, x), _mm256_add_epi32(d, w)));
            sum3 = _mm256_add_epi32(sum3, _mm256_add_epi32(_mm256_add_epi32(e, v), _mm256_add_epi32(f, u)));
            sum4 = _mm256_add_epi32(sum4, _mm256_add_epi32(_mm256_add_epi32(g, t), _mm256_add_epi32(h, s)));
            sum5 = _mm256_add_epi32(sum5, _mm256_add_epi32(_mm256_add_epi32(i, r), _mm256_add_epi32(k, q)));            
            sum6 = _mm256_add_epi32(sum6, _mm256_add_epi32(_mm256_add_epi32(l, p), _mm256_add_epi32(m, o)));

            sum7 = _mm256_add_epi32(sum1, _mm256_add_epi32(_mm256_add_epi32(a, b), _mm256_add_epi32(c, d)));
            sum8 = _mm256_add_epi32(sum2, _mm256_add_epi32(_mm256_add_epi32(e, f), _mm256_add_epi32(g, h)));
            sum9 = _mm256_add_epi32(sum3, _mm256_add_epi32(_mm256_add_epi32(i, k), _mm256_add_epi32(l, m)));
            sum10 = _mm256_add_epi32(sum4, _mm256_add_epi32(_mm256_add_epi32(n, o), _mm256_add_epi32(p, q)));
            sum11 = _mm256_add_epi32(sum5, _mm256_add_epi32(_mm256_add_epi32(r, s), _mm256_add_epi32(t, u)));            
            sum12 = _mm256_add_epi32(sum6, _mm256_add_epi32(_mm256_add_epi32(v, w), _mm256_add_epi32(x, y)));

            sum1 = _mm256_add_epi32(sum1, _mm256_add_epi32(_mm256_add_epi32(a, b), _mm256_add_epi32(c, d)));
            sum2 = _mm256_add_epi32(sum2, _mm256_add_epi32(_mm256_add_epi32(e, f), _mm256_add_epi32(g, h)));
            sum3 = _mm256_add_epi32(sum3, _mm256_add_epi32(_mm256_add_epi32(i, k), _mm256_add_epi32(l, m)));
            sum4 = _mm256_add_epi32(sum4, _mm256_add_epi32(_mm256_add_epi32(n, o), _mm256_add_epi32(p, q)));
            sum5 = _mm256_add_epi32(sum5, _mm256_add_epi32(_mm256_add_epi32(r, s), _mm256_add_epi32(t, u)));            
            sum6 = _mm256_add_epi32(sum6, _mm256_add_epi32(_mm256_add_epi32(v, w), _mm256_add_epi32(x, y)));

            sum7 = _mm256_add_epi32(sum1, _mm256_add_epi32(_mm256_add_epi32(a, z), _mm256_add_epi32(b, y)));
            sum8 = _mm256_add_epi32(sum2, _mm256_add_epi32(_mm256_add_epi32(c, x), _mm256_add_epi32(d, w)));
            sum9 = _mm256_add_epi32(sum3, _mm256_add_epi32(_mm256_add_epi32(e, v), _mm256_add_epi32(f, u)));
            sum10 = _mm256_add_epi32(sum4, _mm256_add_epi32(_mm256_add_epi32(g, t), _mm256_add_epi32(h, s)));
            sum11 = _mm256_add_epi32(sum5, _mm256_add_epi32(_mm256_add_epi32(i, r), _mm256_add_epi32(k, q)));            
            sum12 = _mm256_add_epi32(sum6, _mm256_add_epi32(_mm256_add_epi32(l, p), _mm256_add_epi32(m, o)));

            sum1 = _mm256_add_epi32(sum1, _mm256_add_epi32(_mm256_add_epi32(a, z), _mm256_add_epi32(b, y)));
            sum2 = _mm256_add_epi32(sum2, _mm256_add_epi32(_mm256_add_epi32(c, x), _mm256_add_epi32(d, w)));
            sum3 = _mm256_add_epi32(sum3, _mm256_add_epi32(_mm256_add_epi32(e, v), _mm256_add_epi32(f, u)));
            sum4 = _mm256_add_epi32(sum4, _mm256_add_epi32(_mm256_add_epi32(g, t), _mm256_add_epi32(h, s)));
            sum5 = _mm256_add_epi32(sum5, _mm256_add_epi32(_mm256_add_epi32(i, r), _mm256_add_epi32(k, q)));            
            sum6 = _mm256_add_epi32(sum6, _mm256_add_epi32(_mm256_add_epi32(l, p), _mm256_add_epi32(m, o)));

            sum7 = _mm256_add_epi32(sum1, _mm256_add_epi32(_mm256_add_epi32(a, b), _mm256_add_epi32(c, d)));
            sum8 = _mm256_add_epi32(sum2, _mm256_add_epi32(_mm256_add_epi32(e, f), _mm256_add_epi32(g, h)));
            sum9 = _mm256_add_epi32(sum3, _mm256_add_epi32(_mm256_add_epi32(i, k), _mm256_add_epi32(l, m)));
            sum10 = _mm256_add_epi32(sum4, _mm256_add_epi32(_mm256_add_epi32(n, o), _mm256_add_epi32(p, q)));
            sum11 = _mm256_add_epi32(sum5, _mm256_add_epi32(_mm256_add_epi32(r, s), _mm256_add_epi32(t, u)));            
            sum12 = _mm256_add_epi32(sum6, _mm256_add_epi32(_mm256_add_epi32(v, w), _mm256_add_epi32(x, y)));

            sum1 = _mm256_add_epi32(sum1, _mm256_add_epi32(_mm256_add_epi32(a, b), _mm256_add_epi32(c, d)));
            sum2 = _mm256_add_epi32(sum2, _mm256_add_epi32(_mm256_add_epi32(e, f), _mm256_add_epi32(g, h)));
            sum3 = _mm256_add_epi32(sum3, _mm256_add_epi32(_mm256_add_epi32(i, k), _mm256_add_epi32(l, m)));
            sum4 = _mm256_add_epi32(sum4, _mm256_add_epi32(_mm256_add_epi32(n, o), _mm256_add_epi32(p, q)));
            sum5 = _mm256_add_epi32(sum5, _mm256_add_epi32(_mm256_add_epi32(r, s), _mm256_add_epi32(t, u)));            
            sum6 = _mm256_add_epi32(sum6, _mm256_add_epi32(_mm256_add_epi32(v, w), _mm256_add_epi32(x, y)));

            sum7 = _mm256_add_epi32(sum1, _mm256_add_epi32(_mm256_add_epi32(a, z), _mm256_add_epi32(b, y)));
            sum8 = _mm256_add_epi32(sum2, _mm256_add_epi32(_mm256_add_epi32(c, x), _mm256_add_epi32(d, w)));
            sum9 = _mm256_add_epi32(sum3, _mm256_add_epi32(_mm256_add_epi32(e, v), _mm256_add_epi32(f, u)));
            sum10 = _mm256_add_epi32(sum4, _mm256_add_epi32(_mm256_add_epi32(g, t), _mm256_add_epi32(h, s)));
            sum11 = _mm256_add_epi32(sum5, _mm256_add_epi32(_mm256_add_epi32(i, r), _mm256_add_epi32(k, q)));            
            sum12 = _mm256_add_epi32(sum6, _mm256_add_epi32(_mm256_add_epi32(l, p), _mm256_add_epi32(m, o)));

            sum1 = _mm256_add_epi32(sum1, _mm256_add_epi32(_mm256_add_epi32(a, z), _mm256_add_epi32(b, y)));
            sum2 = _mm256_add_epi32(sum2, _mm256_add_epi32(_mm256_add_epi32(c, x), _mm256_add_epi32(d, w)));
            sum3 = _mm256_add_epi32(sum3, _mm256_add_epi32(_mm256_add_epi32(e, v), _mm256_add_epi32(f, u)));
            sum4 = _mm256_add_epi32(sum4, _mm256_add_epi32(_mm256_add_epi32(g, t), _mm256_add_epi32(h, s)));
            sum5 = _mm256_add_epi32(sum5, _mm256_add_epi32(_mm256_add_epi32(i, r), _mm256_add_epi32(k, q)));            
            sum6 = _mm256_add_epi32(sum6, _mm256_add_epi32(_mm256_add_epi32(l, p), _mm256_add_epi32(m, o)));

            sum7 = _mm256_add_epi32(sum1, _mm256_add_epi32(_mm256_add_epi32(a, b), _mm256_add_epi32(c, d)));
            sum8 = _mm256_add_epi32(sum2, _mm256_add_epi32(_mm256_add_epi32(e, f), _mm256_add_epi32(g, h)));
            sum9 = _mm256_add_epi32(sum3, _mm256_add_epi32(_mm256_add_epi32(i, k), _mm256_add_epi32(l, m)));
            sum10 = _mm256_add_epi32(sum4, _mm256_add_epi32(_mm256_add_epi32(n, o), _mm256_add_epi32(p, q)));
            sum11 = _mm256_add_epi32(sum5, _mm256_add_epi32(_mm256_add_epi32(r, s), _mm256_add_epi32(t, u)));            
            sum12 = _mm256_add_epi32(sum6, _mm256_add_epi32(_mm256_add_epi32(v, w), _mm256_add_epi32(x, y)));
            
            
            _mm256_store_si256(&data->array[j], sum1);
            _mm256_store_si256(&data->array[j+1], sum2);
            _mm256_store_si256(&data->array[j+2], sum3);
            _mm256_store_si256(&data->array[j+3], sum4);
            _mm256_store_si256(&data->array[j+4], sum5);
            _mm256_store_si256(&data->array[j+5], sum6);
            _mm256_store_si256(&data->array[j+6], sum7);
            _mm256_store_si256(&data->array[j+7], sum8);
            _mm256_store_si256(&data->array[j+8], sum9);
            _mm256_store_si256(&data->array[j+9], sum10);
            _mm256_store_si256(&data->array[j+10], sum11);
            _mm256_store_si256(&data->array[j+11], sum12);

            // Additional operations to increase intensity
            sum1 = _mm256_mullo_epi32(sum1, sum2);
            sum2 = _mm256_srlv_epi32(sum2, sum3);
            sum3 = _mm256_srlv_epi32(sum3, sum4);
            sum4 = _mm256_srlv_epi32(sum4, sum5);
            sum5 = _mm256_srlv_epi32(sum5, sum6);
            sum6 = _mm256_srlv_epi32(sum6, sum7);
            sum7 = _mm256_mullo_epi32(sum7, sum8);
            sum8 = _mm256_srlv_epi32(sum8, sum9);
            sum9 = _mm256_srlv_epi32(sum9, sum10);
            sum10 = _mm256_srlv_epi32(sum10, sum11);
            sum11 = _mm256_srlv_epi32(sum11, sum12);
            sum12 = _mm256_mullo_epi32(sum12, sum1);

            
        }
    }
    
    

    // Prevent the loop from being optimized out
    _mm256_store_si256(data->array, _mm256_add_epi32(sum1, sum2));

    return 0;
}

int main() {
    int testCount;
    printf("Enter number of test runs (10+ for better accuracy)\n");

    scanf("%d", &testCount);
    int *testResults = malloc(testCount * sizeof(int));

    printf("Cpu Test Beginning Now!\n");
    Sleep(1000);

    for(int q = 0; q < testCount; q++){
    

    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    DWORD numCPU = sysInfo.dwNumberOfProcessors;

    HANDLE* hThreads = (HANDLE*)malloc(numCPU * sizeof(HANDLE));
    ThreadData* threadData = (ThreadData*)malloc(numCPU * sizeof(ThreadData));
    volatile bool should_exit = false;

    LARGE_INTEGER frequency, start, end;

    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);
    
    // Allocate and initialize arrays
    for (DWORD i = 0; i < numCPU; i++) {
        threadData[i].array = (__m256i*)_aligned_malloc(ARRAY_SIZE * sizeof(__m256i), 32);
        threadData[i].should_exit = &should_exit;
        for (int j = 0; j < ARRAY_SIZE; j++) {
            threadData[i].array[j] = _mm256_set1_epi32(j);
        }
    }

    

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    
    
        for (DWORD i = 0; i < numCPU; i++) {
            threadData[i].thread_id = i;
            
            hThreads[i] = (HANDLE)_beginthreadex(NULL, 0, (unsigned int (__stdcall *)(void *))WorkerThread, &threadData[i], 0, NULL);
            SetThreadAffinity(hThreads[i], i);
            SetThreadPriority(hThreads[i], THREAD_PRIORITY_TIME_CRITICAL);
        }
    
    

    Sleep(TEST_DURATION_MS);
    should_exit = true;

    for (DWORD i = 0; i < numCPU; i++) {
        WaitForSingleObject(hThreads[i], INFINITE);
        CloseHandle(hThreads[i]);
    }

    QueryPerformanceCounter(&end);

    double elapsed = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
    printf("\nRun %d: Gflops: %.2f", q, numCPU * 1000/elapsed);
    testResults[q] = numCPU * 1000/elapsed;
    

    for (DWORD i = 0; i < numCPU; i++) {
        _aligned_free(threadData[i].array);
    }
    free(hThreads);
    free(threadData);

    }
    printf("\n\nTesting Complete!\n");

    int sum = 0;
    for (int i = 0; i < testCount; ++i) {
        sum += testResults[i];
    }
    float average = (float)sum / testCount;

    printf("\n Average Gflops: %.2f\n", average);

    scanf(" ");
    free(testResults);
    return 0;
}