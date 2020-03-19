#include<stdio.h>
int main()
{
    int threeD_array[2][3][4]=
    {
            { {1, 2, 3, 4},
              {5, 6, 7, 8}, 
              {9,10,11,12},
            },

            { {13, 14, 15, 16},
              {17, 18, 19, 20}, 
              {21, 22, 23, 24},
            },
    };
    int (*P_first_begin)[3][4] = threeD_array; //threeD_array 在這裡被隱式轉型成 &(threeD_array[0])
    int (*P_first_end)  [3][4] = *(&threeD_array+1); //threeD_array 在這裡被隱式轉型成 &(threeD_array[0])

    //[2]
    for(int (*fir)[3][4]=P_first_begin; fir < P_first_end; ++fir)
    {
        int (*P_second_begin) [4] = * fir;
        int (*P_second_end)[4] = *(fir+1);
        //[3]
        for(int (*sec)[4]=P_second_begin; sec < P_second_end; ++sec)
        {
            int * P_thir_begin = *sec;
            int * P_thir_end   = *(sec+1);
            //[4]
            for(int * thir=P_thir_begin; thir<P_thir_end; ++thir)
                printf("%2d ",*thir);
            printf("\n");
        }
        printf("\n");
    }
}