/** Jacob Hampton
 *  CSC412
 *  2/12/21
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>

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

int checkDup(int * nums, int len,int input){
	for (size_t j = 0; j < len; j++)
	{
		if(nums[j] == input){
			return 1;
		}
	}
	return 0;
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
//validates that input is not a duplicate and adds it too the array given
int checkAndAdd(int input, int index, int* comboNums,int len){
    int validInput = 0;
    validInput = checkDup(comboNums,len,input);
    if(validInput == 0){
        comboNums[index] = input;
    }
    return validInput;
}
//takes in two arrays and combines them removing the duplicates and printing the resulting array
void printFinalArray(int* nums1,int lenNums1, int* nums2,int lenNums2){
    int lenComboNums = lenNums1+lenNums2;
    int len = 0;
    int* comboNums = (int* )malloc(lenComboNums*sizeof(int));
    int nums2Index = 0;
    int index = 0;
    for (size_t i = 0; i < lenComboNums; i++)
    {
        if(i<lenNums1){
            len++;
            int valid = checkAndAdd(nums1[i],index,comboNums,len);
            len -= valid;
            index += 1 - valid;
        }
        else{
            len++;
            int valid = checkAndAdd(nums2[nums2Index],index,comboNums,len);
            len -= valid;
            index += 1 - valid;
            nums2Index++;
        }

    }
    
    int* comboNumsFinal = (int* )malloc(len*sizeof(int));
    for (size_t i = 0; i < len; i++)
    {
        comboNumsFinal[i] = comboNums[i];
    }
    free(comboNums);
    printf("Merged List\n");
	printArr(comboNumsFinal, len);
    free(comboNumsFinal);
}

int main(int argc, char* argv[])
{
	int len = argc-1;                               //total number of inputs
	int* nums1 = (int*)malloc(len*sizeof(int));     //first array of input
    int* nums2;                                     //second array of input
    int arrb = 0;                                   //boolean to recognize a second array
    int nums2Index = -1;                            //initialized at negetive one to account for '/'
    int nums1Index = 0;                             //idex only for valid entries of array 1                   
    int validInput = 0;                             //bool for valid input 0=true 1=false

    for(unsigned i=0 ;i<len;i++){
        char* inputc = argv[i+1];                   //input at a char ptr
        int input = atoi(argv[i+1]);	            //input as a int
        float inputf = atof(argv[i+1]);             //input as a float

        if(strcmp(argv[i+1],"/")==0){arrb =1;}      //check for the initial slash divider
    
        if(arrb == 1){
            if (nums2Index == -1)                                   //initialize nums2               
            {   
                nums2 = (int*)malloc((len - i+1)*sizeof(int));
                nums2Index++;
            }else{                                                  //in nums2
                validInput = validateData(input,*inputc,inputf);
                if(validInput == 0){
                    nums2[nums2Index] = input;
                    nums2Index++;
                }
            }
        }else{                                                      //in nums1
            validInput = validateData(input,*inputc,inputf);
            if(validInput == 0){
                nums1[nums1Index] = input;
                nums1Index++;
            }
        }
        validInput = 0;                             //reset input to true
    }

    printf("First list:\n");
	printArr(nums1, nums1Index);                    //print the first list
    printf("Second list:\n");
	printArr(nums2, nums2Index);                    //print the second list
    //print the combined list
    printFinalArray(nums1,nums1Index,nums2,nums2Index);
	free(nums1);
	free(nums2);

	return 0;
}
