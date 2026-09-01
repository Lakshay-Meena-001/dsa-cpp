#include <bits/stdc++.h>
using namespace std;

// Checks whether 'abbr' is a valid abbreviation of 'word'.
bool validWordAbbreviation(const string &word, const string &abbr)
{   
    //dono k start se start karenge 
    int wordIndex = 0;
    int abbrIndex = 0;

    // traverese karne k liy edono ki length nikal li 
    const int wordLength = word.size();
    const int abbrLength = abbr.size();

    //abbrevation index se start kyuki abbr me number aa skta hai aur word me letter aa skta hai
    while (abbrIndex < abbrLength)
    {

        // Case 1: Current abbreviation character is a letter.
        if (isalpha(abbr[abbrIndex]))
        {

            // word index ko check karna hoga ki wo word ke length se bada na ho jaye
            if (wordIndex >= wordLength)
            {
                return false;
            }

            // agar wordindex aur abbrindex ke character same nahi hai to false return kar do
            if (word[wordIndex] != abbr[abbrIndex])
            {
                return false;
            }

            // dono index ko increment kar do
            ++wordIndex;
            ++abbrIndex;
        }

        // Case 2: Current abbreviation character is a digit.
        else if (isdigit(abbr[abbrIndex]))
        {

            // agar start me 0 aa jaye to false return kar do kyuki leading zero nahi ho skta
            if (abbr[abbrIndex] == '0')
            {
                return false;
            }

            //hn to abbr me number aa rha hai to usko parse karna hoga aur word me skip karna hoga
            int skipCount = 0;

            // Parse the complete number.
            while (abbrIndex < abbrLength && isdigit(abbr[abbrIndex]))
            {

                skipCount = skipCount * 10 + (abbr[abbrIndex] - '0');

                ++abbrIndex;
            }

            // so jitna skipcount hai utna wordindex ko increment kar do
            wordIndex += skipCount;

            // Abbreviation cannot skip beyond the word.
            if (wordIndex > wordLength)
            {
                return false;
            }
        }

        // Any other character is invalid.
        else
        {
            return false;
        }
    }

    // Both representations must consume the entire word.
    return wordIndex == wordLength;
}

int main()
{
    vector<pair<string, string>> testCases = {
        {"internationalization", "i18n"},
        {"apple", "a3e"},
        {"apple", "a2e"},
        {"apple", "5"},
        {"substitution", "s10n"},
        {"apple", "a03e"},
        {"apple", "a0ple"},
        {"apple", "a2"}};

    for (const auto &[word, abbreviation] : testCases)
    {
        cout << "Word: " << word << '\n';
        cout << "Abbreviation: " << abbreviation << '\n';
        cout << "Valid: "
             << boolalpha
             << validWordAbbreviation(word, abbreviation)
             << "\n\n";
    }

    return 0;
}