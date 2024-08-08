#define _WIN32_WINNT 0x0601
#include <windows.h>
#include <process.h>
#include <immintrin.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


#define ARRAY_SIZE 1024 * 32
#define GRAPH_WIDTH 100
#define GRAPH_HEIGHT 20

int perf = 0;

typedef struct {
    DWORD thread_id;
    __m256i* array;
    volatile LONG64* loop_counter;
    volatile bool* should_exit;
} ThreadData;

// New structure to hold group information
typedef struct {
    WORD groupId;
    DWORD processorCount;
} ProcessorGroupInfo;

// Function to get processor group information
void GetProcessorGroupInfo(ProcessorGroupInfo** groupInfo, DWORD* groupCount) {
    *groupCount = GetActiveProcessorGroupCount();
    *groupInfo = (ProcessorGroupInfo*)malloc(*groupCount * sizeof(ProcessorGroupInfo));

    for (WORD i = 0; i < *groupCount; i++) {
        (*groupInfo)[i].groupId = i;
        (*groupInfo)[i].processorCount = GetActiveProcessorCount(i);
    }
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

        ++perf;
    }
    
    

    // Prevent the loop from being optimized out
    _mm256_store_si256(data->array, _mm256_add_epi32(sum1, sum2));

    return 0;
}

// Modified SetThreadAffinity function
void SetThreadAffinity(HANDLE thread, WORD groupId, DWORD processorIndex) {
    GROUP_AFFINITY groupAffinity = {0};
    groupAffinity.Group = groupId;
    groupAffinity.Mask = 1ULL << processorIndex;
    SetThreadGroupAffinity(thread, &groupAffinity, NULL);
}

float log2_float(float x) {
    return log(x) / log(2);
}

void printASCIILogPointGraph(float* results, int count) {
    float min = results[0], max = results[0];
    for (int i = 0; i < count; i++) {
        if (results[i] < min) min = results[i];
        if (results[i] > max) max = results[i];
    }

    float log_min = log2_float(min);
    float log_max = log2_float(max);

    // Clear the console
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    printf("MFLOPS Performance Graph (Log2 Scale)\n");
    printf("Range: %.2f (2^%.2f) - %.2f (2^%.2f) MFLOPS\n", min, log_min, max, log_max);

    char graph[GRAPH_HEIGHT][GRAPH_WIDTH];
    for (int y = 0; y < GRAPH_HEIGHT; y++) {
        for (int x = 0; x < GRAPH_WIDTH; x++) {
            graph[y][x] = ' ';
        }
    }

    for (int x = 0; x < count && x < GRAPH_WIDTH; x++) {
        float log_current = log2_float(results[x]);
        float normalizedCurrent = (log_current - log_min) / (log_max - log_min);
        int y = (int)((1 - normalizedCurrent) * (GRAPH_HEIGHT - 1));
        
        // Only plot the point, not the line
        if (y >= 0 && y < GRAPH_HEIGHT) {
            graph[y][x] = '*';
        }
    }

    // Print the graph
    for (int y = 0; y < GRAPH_HEIGHT; y++) {
        // Print y-axis labels (in powers of 2)
        float label_value = pow(2, log_max - y * (log_max - log_min) / (GRAPH_HEIGHT - 1));
        printf("%6.2f |", label_value);
        
        for (int x = 0; x < GRAPH_WIDTH; x++) {
            printf("%c", graph[y][x]);
        }
        printf("\n");
    }

    // Print x-axis
    printf("       ");
    for (int x = 0; x < GRAPH_WIDTH; x++) {
        printf("-");
    }
    printf("\n");

    // Print run numbers
    printf("       ");
    for (int x = 0; x < count && x < GRAPH_WIDTH; x++) {
        printf("%d", x % 10);
    }
    printf("\n");
}

int main() {
    int testCount;
    printf("Enter number of test runs (20+ for stability verification)\n");
    scanf("%d", &testCount);
    float *testResults = malloc(testCount * sizeof(float));
    float *perfData = malloc(testCount * sizeof(float));

    printf("CPU Test Beginning Now!\n");
    Sleep(1000);

    // Get processor group information
    ProcessorGroupInfo* groupInfo;
    DWORD groupCount;
    GetProcessorGroupInfo(&groupInfo, &groupCount);

    // Calculate total number of processors across all groups
    DWORD totalProcessors = 0;
    for (DWORD i = 0; i < groupCount; i++) {
        totalProcessors += groupInfo[i].processorCount;
    }

    HANDLE* hThreads = (HANDLE*)malloc(totalProcessors * sizeof(HANDLE));
    ThreadData* threadData = (ThreadData*)malloc(totalProcessors * sizeof(ThreadData));
    volatile bool should_exit = false;
    volatile LONG64 loop_counter = 0;

    LARGE_INTEGER frequency, start, end;

    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_NORMAL);
    
    // Allocate and initialize arrays
    for (DWORD i = 0; i < totalProcessors; i++) {
        threadData[i].array = (__m256i*)_aligned_malloc(ARRAY_SIZE * sizeof(__m256i), 32);
        threadData[i].should_exit = &should_exit;
        threadData[i].loop_counter = &loop_counter;
        for (int j = 0; j < ARRAY_SIZE; j++) {
            threadData[i].array[j] = _mm256_set1_epi32(j);
        }
    }

    for (int q = 0; q < testCount; q++) {
        should_exit = false;

        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&start);

        DWORD threadIndex = 0;
        for (DWORD g = 0; g < groupCount; g++) {
            for (DWORD i = 0; i < groupInfo[g].processorCount; i++) {
                threadData[threadIndex].thread_id = threadIndex;
                hThreads[threadIndex] = (HANDLE)_beginthreadex(NULL, 0, (unsigned int (__stdcall *)(void *))WorkerThread, &threadData[threadIndex], 0, NULL);
                SetThreadAffinity(hThreads[threadIndex], groupInfo[g].groupId, i);
                SetThreadPriority(hThreads[threadIndex], THREAD_PRIORITY_NORMAL);
                threadIndex++;
            }
        }

        Sleep(5000);
        perfData[q] = perf / 1000;
        perf = 0;
        should_exit = true;

        // Wait for all threads to finish
        WaitForMultipleObjects(totalProcessors, hThreads, TRUE, INFINITE);
        
        QueryPerformanceCounter(&end);

        for (DWORD i = 0; i < totalProcessors; i++) {
            CloseHandle(hThreads[i]);
        }
        
        testResults[q] = perfData[q];
        
        if (q > 0) {
            printASCIILogPointGraph(testResults, q);
            Sleep(1000);
        }

        should_exit = false;  // Reset for next run
    }

    printf("\nTesting Complete!\n");

    // Adjust the calculation to account for the skipped run
    float sum = 0, sumSq = 0;
    int effectiveCount = testCount - 1;  // We're effectively using one less run
    for (int i = 0; i < effectiveCount; i++) {  
        sum += testResults[i];
        sumSq += testResults[i] * testResults[i];
    }

    float average = sum / effectiveCount;
    float variance = (sumSq - sum * sum / effectiveCount) / (effectiveCount - 1);
    float stdev = sqrt(variance);
    float stdevPercent = (stdev / average) * 100;


    printf("\nAverage MFLOPS: %.2f\n", average);
    printf("Standard Deviation: %.2f MFLOPS (%.2f%%)\n", stdev, stdevPercent);

    if(testCount <= 19) {  // Adjusted for the skipped run
        printf("\nStability unverified, 20 runs minimum to verify stability!");
    } else if (stdevPercent <= 1) {
        printf("\nCongratulations! Your cpu overclock is officially stable!");
    } else {
        printf("\nWomp Womp, your cpu overclock is UNSTABLE!");
    }

     // Clean up
    free(groupInfo);
    free(hThreads);
    for (DWORD i = 0; i < totalProcessors; i++) {
        _aligned_free(threadData[i].array);
    }
    free(threadData);
    free(testResults);
    free(perfData);

    scanf("\n ");  // Wait for user input before closing
    return 0;
}