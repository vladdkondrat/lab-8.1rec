#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Рекурсивна функція для перевірки, чи містить рядок групу з трьох знаків оклику "!!!"
bool ContainsTripleExclamationRec(char* str, int index = 0) {
    if (strlen(str) < 3 || index > strlen(str) - 3)
        return false;
    if (str[index] == '!' && str[index + 1] == '!' && str[index + 2] == '!')
        return true;
    return ContainsTripleExclamationRec(str, index + 1);
}

// Рекурсивна функція для заміни трійок знаків оклику "!!!" на "**"
char* ReplaceTripleExclamationRec(char* dest, const char* str, char* t, int index = 0) {
    if (str[index + 2] == '\0') {
        while (str[index] != '\0') {
            *t++ = str[index++];
        }
        *t = '\0';
        return dest;
    }
    if (str[index] == '!' && str[index + 1] == '!' && str[index + 2] == '!') {
        strcat(t, "**");
        t += 2;
        return ReplaceTripleExclamationRec(dest, str, t, index + 3);
    }
    else {
        *t++ = str[index++];
        *t = '\0';
        return ReplaceTripleExclamationRec(dest, str, t, index);
    }
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // Перевірка, чи містить рядок групу з трьох знаків оклику "!!!"
    bool containsTripleExclamation = ContainsTripleExclamationRec(str);
    cout << "Contains triple exclamation: " << (containsTripleExclamation ? "Yes" : "No") << endl;

    // Заміна трійок знаків оклику "!!!" на "**"
    char* dest1 = new char[151];
    dest1[0] = '\0';
    char* dest2 = ReplaceTripleExclamationRec(dest1, str, dest1);
    cout << "Modified string (param): " << str << endl;
    cout << "Modified string (result): " << dest2 << endl;

    delete[] dest1;
    return 0;
}
