/** Jacob Hampton
 *  CSC412
 *  2/12/21
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>

//takes in an arry and prints it to look like an array
void printArr(int* array, int len){
    printf("    {");
	for (size_t i = 0; i < len; i++)
	{
        if(i != len-1){
            printf("%d, ",array[i]);
        }
        else{
            printf("%d",array[i]);
        }
		
	}
    printf("}\n");
}

//checks if the input is a float by checking if it has held its value after atoi() and atof()
int checkFloat(float inputf, int input){
    return (!(inputf ==input));
}

//validates the input as an int, not float or string
int validateData(int input,char inputc,float inputf){
    if(!isdigit(inputc)){
        if(input < 0){
            return 0;
        }
        return 1;
    }else if(checkFloat(inputf,input)){
        return 1;
    }else{
        return 0;
    }
}


int main(int argc, char* argv[])
{
	int len = argc-1;                               //total number of inputs
	int* nums = (int*)malloc(len*sizeof(int));
	int arrTwoLen=0;                                //counter of valid imputr
	int b;                                          //boolean for the program
	for(unsigned i = 0; i<len; i++){

		int input = atoi(argv[i+1]);	            //input as a int
		char* inputc = argv[i+1];                   //input as a char
        float inputf = atof(argv[i+1]);				//input as a float
		b = validateData(input,*inputc,inputf);
                       
		if (b==0){
			nums[arrTwoLen] = input;
			arrTwoLen++;				
		}
		b=0;                                        //reset the boolean
	}

    //this block copies the valid input to a properly sized array
	int* nums2 = (int*)malloc(arrTwoLen*sizeof(int));
	for (size_t k = 0; k < arrTwoLen; k++)
	{
		nums2[k] = nums[k];
	}

	free(nums);
    printf("You entered %d valid integer values:\n",arrTwoLen);
	printArr(nums2, arrTwoLen);
	free(nums2);

	return 0;
}
