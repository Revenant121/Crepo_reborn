#include <stdio.h>
#include <wchar.h>
#include <wctype.h>

int main() {
    wchar_t sentence[] = L"The quick brown fox jumps over the lazy dog";
    int count = 0;

    for (int i = 0; sentence[i] != L'\0'; i++) {
        if (i == 0 && iswalpha(sentence[i]) && (sentence[i] == L'a' || sentence[i] == L'e' || sentence[i] == L'i' || sentence[i] == L'o' || sentence[i] == L'u' ||
                                                sentence[i] == L'A' || sentence[i] == L'E' || sentence[i] == L'I' || sentence[i] == L'O' || sentence[i] == L'U')) {
            count++;
        } else if (iswspace(sentence[i]) && iswalpha(sentence[i + 1]) && (sentence[i + 1] == L'a' || sentence[i + 1] == L'e' || sentence[i + 1] == L'i' ||
                                                                          sentence[i + 1] == L'o' || sentence[i + 1] == L'u' || sentence[i + 1] == L'A' ||
                                                                          sentence[i + 1] == L'E' || sentence[i + 1] == L'I' || sentence[i + 1] == L'O' ||
                                                                          sentence[i + 1] == L'U')) {
            count++;
        }
    }

    printf("Number of words starting with a vowel: %d", count);

    return 0;
}
