#include <stdio.h>
#include <string.h>
#define maxLineCharsNum 50
#define englishLettersNum 26
void printHistogram (int [],char[],int);//function prototype.
int main()
{
    char wordsFP[maxLineCharsNum],Letter[englishLettersNum],j='a';//Putting variables and Definition the arrays.
    int cLetter[englishLettersNum]={0},c,m,l,k;
    FILE *in;//pointer to input file.
    in = fopen("story.txt","r");//Reading from the file.
    for(l=0;l<englishLettersNum;l++)//For Loop to fill the letters in the array.
        {
        Letter[l]=j;//The letter inside j has been placed in the array numbered by the index l;
        j++;//Increase of j one.
        }
   while(fscanf(in,"%s",&wordsFP[0])!=EOF)//Loob reads the string from the file and checks the string
    {

        m=0;
        while(wordsFP[m] != '\0')//Loob checks if the letter is not equal to the character NULL('\0')
            {                    //then it checks the string characters counts the number of characters.
        for(c=0;c<englishLettersNum;c++)//For Loop checks the letters and increases the counter for each letter.
        {
        if(wordsFP[m] == Letter[c])//Check the letters and when the comparison is achieved
        {
            cLetter[c]++;//the counter increments one and
            break;//then exits the loop.
        }
        }
         m++;//The variable m is incremented by one in order to check the remaining letters in the loop.
            }
    }
    for(k=0;k<englishLettersNum;k++)//Loop to print the number of times the letters are in a word.
        printf("%c was used - %d times\n",Letter[k],cLetter[k]);//Sentence printing
    printHistogram(cLetter,Letter,englishLettersNum);//call function.
    fclose(in);//Close the file.
    return 0;//Exit program.
}
void printHistogram (int counters[],char Letter[] ,int s)//function definition.
{
    char H=254;//The character of a histogram.
    int k,l;//Putting variables.
    printf("\nHistogram of Characters:\n");
    for(k=0;k<s;k++)//loop of Print the chart
        {
        printf("%c: ",Letter[k]);//Sentence printing
        for(l=0;l<counters[k];l++)//Loop of Print the graph character by the number of times the character appears
            printf("%c",H);//Sentence printing
        printf("\n");//Print a new line
        }
}
