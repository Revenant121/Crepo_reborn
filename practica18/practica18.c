#include <stdio.h>
#include <wchar.h>
#include <wctype.h>

int main() {
    wchar_t sentence[1000];
    int count = 0;


    wprintf(L"Enter a sentence: ");
    fgetws(sentence, 1000, stdin);


    for (int i = 0; sentence[i] != L'\0'; i++) {
        if ((i == 0 || iswspace(sentence[i - 1])) && iswalpha(sentence[i]) && (sentence[i] == L'a' || sentence[i] == L'e' || sentence[i] == L'i' || sentence[i] == L'o' || sentence[i] == L'u' ||
                                                                               sentence[i] == L'A' || sentence[i] == L'E' || sentence[i] == L'I' || sentence[i] == L'O' || sentence[i] == L'U')) {
            count++;
        }
    }


    wprintf(L"Number of words starting with a vowel: %d\n", count);


    FILE *file = fopen("output.txt", "w");
    if (file == NULL) {
        wprintf(L"Error opening the file.");
        return 1;
    }

    fwprintf(file, L"Number of words starting with a vowel: %d\n", count);

    fclose(file);

    return 0;
}
