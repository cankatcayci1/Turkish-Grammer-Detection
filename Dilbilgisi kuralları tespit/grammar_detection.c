#include <stdio.h>
#include <stdlib.h>
#include <string.h> // library where we call custom string functions.
#include <ctype.h>
#include <locale.h> // The library we called for the Turkish character.
#define MAX 5000    // the number we use as a constant in our array length.

// The functions:

void _1d_to_2dArray(unsigned char data[MAX], unsigned char data1[200][MAX]);      // Function that converts the entered text from a 1-dimensional array to a 2-dimensional array.
int letters(unsigned char data[MAX]);                                             // Function to find the number of letters
int words(unsigned char data[MAX]);                                               // Function to find the number of words.
int sentences(unsigned char data[MAX]);                                           // Function to find the number of sentences.
int numberConnexion(unsigned char data[MAX]);                                     // Function to find the number connexions
int printConnexion(unsigned char data[MAX], unsigned char data1[200][MAX]);       // Function that prints words
int numberPluralWords(unsigned char data[MAX]);                                   // Function to find the number plural words
int printPluralWords(unsigned char data[MAX], unsigned char data1[200][MAX]);     // Function that prints words
int numberPalatalHarmony(unsigned char data[MAX], unsigned char data1[200][MAX]); // Function to find the number palatal harmony
int printPalatalHarmony(unsigned char data[MAX], unsigned char data1[200][MAX]);  // Function that prints words
int labialHarmony(unsigned char data[MAX]);
int numberStrongVowel(unsigned char data[MAX], unsigned char data1[200][MAX]);                 // Function to find the number strong vowel
int numberSoftVowel(unsigned char data[MAX], unsigned char data1[200][MAX]);                   // Function to find the number soft vowel
int numberStrongConsonant(unsigned char data[MAX], unsigned char data1[200][MAX]);             // Function to find the number strong consonant
int numberSoftConsonant(unsigned char data[MAX], unsigned char data1[200][MAX]);               // Function to find the number soft consonant
void menu(unsigned char choice1[MAX], unsigned char data[MAX], unsigned char data1[200][MAX]); // Function to make user inputs

int main()
{
    setlocale(LC_ALL, "Turkish.turkish.1254"); // calling Turkish character and function.

    unsigned char text[MAX];       // 1 dimensional array
    unsigned char text1[200][MAX]; // 2 dimensional array
    unsigned char choice[MAX];

    printf("                             --------------------Enter A Text----------------------                                   ");
    printf("\n\n");
    gets(text); // The user is prompted to enter text.

    _1d_to_2dArray(text, text1); // The function that converts the entered 1-dimensional array to a 2-dimensional array is called.

    printf("\n                             ---------------------RULES----------------------------                                  ");
    printf("\n"); // İn this area, all rules are printed.
    printf("\n The First Rule Was Applied    : The number of letters in the text is %d", letters(text));
    printf("\n--------------------------------------------------------------------------------------------");
    printf("\n The Second Rule Was Applied   : The number of words in the text is %d", words(text));
    printf("\n--------------------------------------------------------------------------------------------");
    printf("\n The Third Rule Was Applied    : The number of sentences in the text is %d", sentences(text));
    printf("\n--------------------------------------------------------------------------------------------");
    printf("\n The Fourth Rule Was Applied   : The number of connexion (ulama) in the text is %d\n", numberConnexion(text));
    printf(" These words are: ");
    printConnexion(text, text1);
    printf("\n--------------------------------------------------------------------------------------------");
    printf("\n The Fifth Rule Was Applied    : The number of plural words in the text is %d\n", numberPluralWords(text));
    printf(" These words are: ");
    printPluralWords(text, text1);
    printf("\n--------------------------------------------------------------------------------------------");
    printf("\n The Sixth Rule Was Applied    : The number of words in the text that comply with this rule(palatal harmony) is = %d \n", numberPalatalHarmony(text, text1));
    printf(" These words are: ");
    printPalatalHarmony(text, text1);
    printf("\n--------------------------------------------------------------------------------------------");
    printf("\n The Seventh Rule Was Applied    : The number of bold vowels in the text %d", numberBoldVowel(text, text1));
    printf("\n--------------------------------------------------------------------------------------------");
    printf("\n The Eighth Rule Was Applied    : The number of thin vowels in the text %d", numberThinVowel(text, text1));
    printf("\n--------------------------------------------------------------------------------------------");
    printf("\n The Ninth Rule Was Applied : The number of strong consonants in the text %d", numberStrongConsonant(text, text1));
    printf("\n--------------------------------------------------------------------------------------------");
    printf("\n The Tenth Rule Was Applied  : The number of soft consonants in the text %d", numberSoftConsonant(text, text1));
    printf("\n--------------------------------------------------------------------------------------------");

    menu(choice, text, text1);
}

unsigned char alphabet[58] = {'a', 'b', 'c', (char)135, 'd', 'e', 'f', 'g', (char)167, 'h', (char)141, 'i', 'j', 'k', 'l', 'm', 'n', 'o', (char)148, 'p', 'r', 's', (char)159, 't', 'u', (char)129, 'v', 'y', 'z', 'A', 'B', 'C', (char)128, 'D', 'E', 'F', 'G', (char)166, 'H', 'I', (char)152, 'J', 'K', 'L', 'M', 'N', 'O', (char)153, 'P', 'R', 'S', (char)158, 'T', 'U', (char)154, 'V', 'Y', 'Z'};
unsigned char vowel[16] = {'a', 'e', (char)141, 'i', 'o', (char)148, 'u', (char)129, 'A', 'E', 'I', (char)152, 'O', (char)153, 'U', (char)154};
unsigned char consonant[42] = {'b', 'c', (char)135, 'd', 'f', 'g', (char)167, 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'r', 's', (char)159, 't', 'v', 'y', 'z', 'B', 'C', (char)128, 'D', 'F', 'G', (char)166, 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'R', 'S', (char)158, 'T', 'V', 'Y', 'Z'};
unsigned char boldVowel[8] = {'a', (char)141, 'o', 'u', 'A', 'I', 'O', 'U'};
unsigned char thinVowel[8] = {'e', 'i', (char)148, (char)129, 'E', (char)152, (char)153, (char)154};
unsigned char strongConsonant[16] = {'f', 's', 't', 'k', (char)135, (char)159, 'h', 'p', 'F', 'S', 'T', 'K', (char)128, (char)158, 'H', 'P'};
unsigned char softConsonant[26] = {'b', 'c', 'd', 'g', (char)167, 'j', 'l', 'm', 'n', 'r', 'v', 'y', 'z', 'B', 'C', 'D', 'G', (char)166, 'J', 'L', 'M', 'N', 'R', 'V', 'Y', 'Z'};
unsigned char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// In the above functions, I handled the Turkish characters by calling asci codes. Since I use unsigned char because the asci code is negative, I converted it to unsigned.

void _1d_to_2dArray(unsigned char data[MAX], unsigned char data1[200][MAX])
{
    int num = 0, num1 = 0;

    for (int i = 0; i < strlen(data); i++)
    {
        if (data[i] == ' ' || data[i] == '\0') // İf the first dimensional array is space and when it comes to the end it increases the number of rows by increasing the number. So it converts words into 2D array.
        {
            data1[num][num1] = '\0';
            num++;
            num1 = 0;
        }
        else
        {
            data1[num][num1] = data[i]; // Continues to write the rest of the letters in normal columns.
            num1++;
        }
    }
}

int letters(unsigned char data[MAX])
{
    int flag = strlen(data); // Flag here is equal to the length of the array.

    for (int i = 0; i < strlen(data); i++)
    {
        if (data[i] == ' ')
        {
            flag--; // Decrements the flag whenever there is a space character.
        }

        if (isdigit(data[i]))
        {
            flag--; // Decreases the flag every time it sees a digit.
        }

        if (ispunct(data[i]))
        {
            flag--; // Decreases the flag each time it sees a punctuation mark.
        }
    }
    return flag; // Finally prints the letter count correctly.
}

int words(unsigned char data[MAX])
{
    int flag = 0;

    for (int i = 0; i < strlen(data); i++)
    {
        if (data[i] == ' ')
        {
            flag++; // The reason for increasing the number of words when you see a space is to leave a space after each word and punctuation mark.
        }

        for (int j = 0; j < strlen(numbers); j++)
        {
            if ((data[i] == ' ' || data[i] == '\0') && data[i - 1] == numbers[j])
            {
                flag--; // Where historical and or times (eg 9. and 06.04.2022) are written so that words are not counted.
            }
        }
    }
    return flag + 1; // The reason why there is more than 1 is because the end of the string ends with null, which will give the word 1 less.
}

int sentences(unsigned char data[MAX])
{
    int flag = 0;
    for (int i = 0; i < strlen(data); i++)
    {
        if (data[i] == '.' || data[i] == '?' || data[i] == '!' || data[i] == ':' || data[i] == ';')
        {
            flag++; // The reason why we do not use the ispunct function here is that it will increase the number of sentences in commas or other punctuation marks.
        }
        if (data[i] == '.' && data[i + 1] == '.' && data[i + 2] == '.')
        {
            flag -= 2; // If three dots coincide, we reduce it by 2 since it will count 3 sentences.
        }

        for (int j = 0; j < strlen(numbers); j++)
        {
            for (int k = 0; k < strlen(numbers); k++)
            {
                if (data[i] == '.' && data[i - 1] == numbers[j] && data[i + 1] == numbers[k])
                {
                    flag--; // Here it is for not counting sentences when it sees the date or numeric (eg 9. or 12.08.2020) signs.
                }
            }
        }
    }
    return flag;
}

int numberConnexion(unsigned char data[MAX])
{
    int flag = 0;

    for (int i = 0; i < strlen(data); i++)
    {
        for (int j = 0; j < strlen(vowel); j++)
        {
            for (int k = 0; k < strlen(consonant); k++)
            {
                if (data[i] == ' ' && data[i - 1] == consonant[k] && data[i + 1] == vowel[j])
                {
                    flag++; // The middle element is a space and if the previous element is in the consonant set and the next element is in the vowel set, it is connexion.
                }
            }
        }
    }
    return flag;
}

int printConnexion(unsigned char data[MAX], unsigned char data1[200][MAX])
{
    for (int i = 0; i < words(data); i++)
    {
        int num2 = strlen(data1[i]), num3 = 0;
        for (int j = 0; j < strlen(vowel); j++)
        {
            for (int k = 0; k < strlen(consonant); k++)
            {
                if (data1[i][num2] == '\0' && data1[i][num2 - 1] == consonant[k] && data1[i + 1][num3] == vowel[j])
                {
                    printf("%s %s, ", data1[i], data1[i + 1]); // In a 2-dimensional array, the end-of-line element will be null and prints those 2 lines if the element before it is from the consonant set and the element of the first index of the next line is a vowel.
                }
            }
        }
    }
}

int numberPluralWords(unsigned char data[MAX])
{
    int flag = 0;

    for (int i = 0; i < strlen(data); i++)
    {

        if (data[i] == 'l' && data[i + 1] == 'a' && data[i + 2] == 'r')
        {
            flag++;
        }

        if (data[i] == 'l' && data[i + 1] == 'e' && data[i + 2] == 'r')
        {
            flag++;
        }

        if (data[i] == 'L' && data[i + 1] == 'A' && data[i + 2] == 'R')
        {
            flag++;
        }

        if (data[i] == 'L' && data[i + 1] == 'E' && data[i + 2] == 'R')
        {
            flag++;
        }
    }
    return flag; // When it sees 'lar-ler', it increases the flag.
}

int printPluralWords(unsigned char data[MAX], unsigned char data1[200][MAX])
{
    for (int i = 0; i < words(data); i++)
    {
        int num2 = strlen(data1[i]);
        for (int j = 0; j <= num2; j++)
        {
            if (data1[i][j] == 'l' && data1[i][j + 1] == 'a' && data1[i][j + 2] == 'r')
            {
                printf("%s, ", data1[i]);
            }

            if (data1[i][j] == 'l' && data1[i][j + 1] == 'e' && data1[i][j + 2] == 'r')
            {
                printf("%s, ", data1[i]);
            }
            if (data1[i][j] == 'L' && data1[i][j + 1] == 'A' && data1[i][j + 2] == 'R')
            {
                printf("%s, ", data1[i]);
            }
            if (data1[i][j] == 'L' && data1[i][j + 1] == 'E' && data1[i][j + 2] == 'R')
            {
                printf("%s, ", data1[i]); // It suppresses the word in the line where it sees the 'ler-lar'.
            }
        }
    }
}

int numberPalatalHarmony(unsigned char data[MAX], unsigned char data1[200][MAX])
{
    int flag = 0;
    for (int i = 0; i < words(data); i++)
    {
        int num2 = strlen(data1[i]);

        int bold = 0, thin = 0; // Since we will be processing each word one by one, we need to reset the number of bold and vowels in each loop.

        for (int j = 0; j < num2; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (data1[i][j] == boldVowel[k])
                {
                    bold++; // Increases the number of bold vowels.
                }
                if (data1[i][j] == thinVowel[k])
                {
                    thin++; // Increases the number of thin vowels.
                }
            }
        }
        if ((bold != 0 && thin == 0) || (bold == 0 && thin != 0))
        {
            flag++; // If one of the bold and vowel letters is zero and the other is different from zero, that word fits the  palatal harmony and prints as many numbers as the matching word.
        }
    }
    return flag;
}

int printPalatalHarmony(unsigned char data[MAX], unsigned char data1[200][MAX])
{
    for (int i = 0; i < words(data); i++)
    {
        int num2 = strlen(data1[i]);

        int bold = 0, thin = 0; // Since we will be processing each word one by one, we need to reset the number of bold and vowels in each loop.

        for (int j = 0; j < num2; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (data1[i][j] == boldVowel[k])
                {
                    bold++; // Increases the number of bold vowels.
                }
                if (data1[i][j] == thinVowel[k])
                {
                    thin++; // Increases the number of thin vowels.
                }
            }
        }
        if ((bold != 0 && thin == 0) || (bold == 0 && thin != 0))
        {
            printf("%s, ", data1[i]); // If one of the bold and vowel letters is zero and the other is different from zero, that word fits the  palatal harmony and prints as many numbers as the matching word.
        }
    }
}

int labialHarmony(unsigned char data[MAX])
{
}

int numberBoldVowel(unsigned char data[MAX], unsigned char data1[200][MAX])
{
    int flag = 0;
    for (int i = 0; i < words(data); i++)
    {
        int num2 = strlen(data1[i]);
        for (int j = 0; j < num2; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (data1[i][j] == boldVowel[k])
                {
                    flag++; // Prints the number of bold vowels.
                }
            }
        }
    }
    return flag;
}

int numberThinVowel(unsigned char data[MAX], unsigned char data1[200][MAX])
{
    int flag = 0;

    for (int i = 0; i < words(data); i++)
    {
        int num2 = strlen(data1[i]);
        for (int j = 0; j < num2; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if (data1[i][j] == thinVowel[k])
                {
                    flag++; // Prints the number of thin vowels.
                }
            }
        }
    }
    return flag;
}

int numberStrongConsonant(unsigned char data[MAX], unsigned char data1[200][MAX])
{
    int flag = 0;
    for (int i = 0; i < words(data); i++)
    {
        int num2 = strlen(data1[i]);
        for (int j = 0; j < num2; j++)
        {
            for (int k = 0; k < 16; k++)
            {
                if (data1[i][j] == strongConsonant[k])
                {
                    flag++; // sert ünsüz harf sayısını yazdırır.
                }
            }
        }
    }
    return flag;
}

int numberSoftConsonant(unsigned char data[MAX], unsigned char data1[200][MAX])
{
    int flag = 0;
    for (int i = 0; i < words(data); i++)
    {
        int num2 = strlen(data1[i]);
        for (int j = 0; j < num2; j++)
        {
            for (int k = 0; k < 26; k++)
            {
                if (data1[i][j] == softConsonant[k])
                {
                    flag++; // yumuşak ünsüz harf sayısını yazdırır.
                }
            }
        }
    }
    return flag;
}

void menu(unsigned char choice1[MAX], unsigned char data[MAX], unsigned char data1[200][MAX])
{
    while (choice1 != "Exit") // Kullanıcı çıkış yapana kadar menü döndürülür.
    {
        printf("\n\nI'M CHECKING FOR : number of letters, number of words, number of sentences, connexions, palatal-labial harmony, plural words, bold vowels, thin vowels, strong consonants and soft consonants\n");
        printf("\n Is there a rule you want checked?\n");
        printf("\n -letters\n -words\n -sentences\n -connexions\n -palatal harmony\n -labial harmony\n -plural words\n -bold vowels\n -thin vowels\n -strong consonants\n -soft consonants\n -word search\n\n --Exit\n\n");
        printf("Enter a command line :\n");
        printf("---------------------\n\n");
        gets(choice1); // kullanıcının seçimi girilmesi istenir.
        printf("\n ");

        if (strcmp(choice1, "letters") == 0) // strcmp ile kullanıcının girdiği kelime ile satır komutu karşılaştırılıp, eğer uyuyorsa işlem yaptırlır.
        {
            printf("CHECKED : \n");
            printf(" The number of letters in the text is %d", letters(data));
        }
        else if (strcmp(choice1, "words") == 0)
        {
            printf("CHECKED : \n");
            printf(" The number of words in the text is %d", words(data));
        }
        else if (strcmp(choice1, "sentences") == 0)
        {
            printf("CHECKED : \n");
            printf(" The number of sentences in the text is %d", sentences(data));
        }
        else if (strcmp(choice1, "connexions") == 0)
        {
            printf("CHECKED : \n");
            printf(" The number of connexion in the text is %d\n", numberConnexion(data));
            printf(" These words are: ");
            printConnexion(data, data1);
        }
        else if (strcmp(choice1, "palatal harmony") == 0)
        {
            printf("CHECKED : \n");
            printf(" The number of words in the text that comply with this rule(palatal harmony) is = %d \n", numberPalatalHarmony(data, data1));
            printf(" These words are: ");
            printPalatalHarmony(data, data1);
        }
        else if (strcmp(choice1, "labial harmony") == 0)
        {
        }

        else if (strcmp(choice1, "plural words") == 0)
        {
            printf("CHECKED : \n");
            printf(" The number of plural words in the text is %d\n", numberPluralWords(data));
            printf(" These words are: ");
            printPluralWords(data, data1);
        }
        else if (strcmp(choice1, "bold vowels") == 0)
        {
            printf("CHECKED : \n");
            printf(" The number of bold vowels in the text %d", numberBoldVowel(data, data1));
        }
        else if (strcmp(choice1, "thin vowels") == 0)
        {
            printf("CHECKED : \n");
            printf(" The number of thin vowels in the text %d", numberThinVowel(data, data1));
        }
        else if (strcmp(choice1, "strong consonants") == 0)
        {
            printf("CHECKED : \n");
            printf(" The number of strong consonants in the text %d", numberStrongConsonant(data, data1));
        }
        else if (strcmp(choice1, "soft consonants") == 0)
        {
            printf("CHECKED : \n");
            printf(" The number of soft consonants in the text %d", numberSoftConsonant(data, data1));
        }
        else if (strcmp(choice1, "word search") == 0)
        {
            char word[MAX]; // kullanıcının aratmak istediği kelimenin girilmesi sağlanır.
            printf("Enter the word you want to search :\n");
            gets(word);
            char *ptr = strstr(data, word);
            if (ptr)
            {
                printf("CHECKED : \n");
                printf(" The word has been found in text.");
            }
            else
            {
                printf("CHECKED : \n");
                printf(" The word has been not found in text.");
            }
        }
        else if (strcmp(choice1, "Exit") == 0)
        {
            printf(" You have successfully exited the program.\n\n");
            return 0;
        }
        else
        {
            printf("You entered the wrong command line. Please enter again.");
        }
    }
}