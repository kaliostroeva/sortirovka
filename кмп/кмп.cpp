#include <iostream>
#include <string>
using namespace std;
void computeLPS(string pat, int* lps)
{
    int j = 0;

    lps[0] = 0; // lps[0] is always 0 

    int i = 1;
    while (i < pat.size()) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else
        {
            if (j != 0) {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMPSearch(const string& pat, const string& txt)
{
    int* lps = new int[pat.size()];

    computeLPS(pat, lps);

    int i = 0;
    int j = 0;
    while (i < txt.size()) {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == pat.size()) {
            cout << "Found pattern at index" << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < txt.size() && pat[j] != txt[i]) {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
            
        }
       
    }

}

int main()
{
    setlocale(LC_ALL, "Russian");
    string txt = "я хочу чтобы ты нашел это слово ";
    string pat = "слово";
    KMPSearch(pat, txt);
    if(txt.find(pat) == string::npos){
        cout << "ошибка";
    }

    return 0;
}